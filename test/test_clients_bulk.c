#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cjson/clients.h"

static int failures = 0;

#define CHECK(cond, name) do { if (cond) { printf("OK %s\n", name); } else { printf("FAILED %s\n", name); failures++; } } while (0)

static const char** make_emails(int64_t count, const char** names) {
    const char** emails = calloc((size_t)count, sizeof(const char*));
    for (int64_t i = 0; i < count; i++) {
        emails[i] = strdup(names[i]);
    }
    return emails;
}

static void test_bulk_adjust(void) {
    const char* names[] = { "alice", "bob" };
    struct jsonBulkAdjustClientsPostStruct* post = calloc(1, sizeof(struct jsonBulkAdjustClientsPostStruct));
    post->emails = make_emails(2, names);
    post->emailsCount = 2;
    post->addDays = 30;
    post->addBytes = 53687091200;
    post->flow = strdup("xtls-rprx-vision");
    post->limitHwid = 2;
    post->adTag = strdup("0123456789abcdef0123456789abcdef");
    const char* s = jsonBulkAdjustClientsPost(post);
    CHECK(s && strcmp(s, "{\"emails\":[\"alice\",\"bob\"],\"addDays\":30,\"addBytes\":53687091200,\"flow\":\"xtls-rprx-vision\",\"limitHwid\":2,\"adTag\":\"0123456789abcdef0123456789abcdef\"}") == 0, "bulk adjust post matches sample");
    free((char*)s);
    jsonBulkAdjustClientsPostStructDelete(post);

    struct jsonBulkAdjustClientsResponseStruct* r = jsonBulkAdjustClientsResponse("{\"success\":true,\"obj\":{\"adjusted\":2,\"skipped\":[{\"email\":\"carol\",\"reason\":\"unlimited expiry\"}]}}");
    CHECK(r && r->bulkAdjClisObjRStruct->adjusted == 2 && r->msg == NULL, "bulk adjust response adjusted count");
    CHECK(r && r->bulkAdjClisObjRStruct->jsonBulkAdjustClientsObjectSkippedArrayResponseStructSize == 1 &&
          strcmp(r->bulkAdjClisObjRStruct->bulkAdjClisObjSkippedArrRStruct[0].reason, "unlimited expiry") == 0, "bulk adjust response skipped reason");
    jsonBulkAdjustClientsResponseStructDelete(r);
}

static void test_bulk_enable_disable(void) {
    const char* names[] = { "alice", "bob" };
    struct jsonBulkEnableClientsPostStruct* en = calloc(1, sizeof(struct jsonBulkEnableClientsPostStruct));
    en->emails = make_emails(2, names);
    en->emailsCount = 2;
    const char* s1 = jsonBulkEnableClientsPost(en);
    CHECK(s1 && strcmp(s1, "{\"emails\":[\"alice\",\"bob\"]}") == 0, "bulk enable post matches sample");
    free((char*)s1);
    jsonBulkEnableClientsPostStructDelete(en);

    struct jsonBulkEnableClientsResponseStruct* er = jsonBulkEnableClientsResponse("{\"success\":true,\"obj\":{\"changed\":2,\"skipped\":[{\"email\":\"carol\",\"reason\":\"client not found\"}]}}");
    CHECK(er && er->bulkEnableClisObjRStruct->changed == 2 && strcmp(er->bulkEnableClisObjRStruct->bulkEnableClisObjSkippedArrRStruct[0].email, "carol") == 0, "bulk enable response");
    jsonBulkEnableClientsResponseStructDelete(er);

    struct jsonBulkDisableClientsPostStruct* dis = calloc(1, sizeof(struct jsonBulkDisableClientsPostStruct));
    dis->emails = make_emails(2, names);
    dis->emailsCount = 2;
    const char* s2 = jsonBulkDisableClientsPost(dis);
    CHECK(s2 && strcmp(s2, "{\"emails\":[\"alice\",\"bob\"]}") == 0, "bulk disable post matches sample");
    free((char*)s2);
    jsonBulkDisableClientsPostStructDelete(dis);

    struct jsonBulkDisableClientsResponseStruct* dr = jsonBulkDisableClientsResponse("{\"success\":true,\"obj\":{\"changed\":2,\"skipped\":[{\"email\":\"carol\",\"reason\":\"client not found\"}]}}");
    CHECK(dr && dr->bulkDisableClisObjRStruct->changed == 2, "bulk disable response");
    jsonBulkDisableClientsResponseStructDelete(dr);
}

static void test_bulk_delete(void) {
    const char* names[] = { "alice", "bob" };
    struct jsonBulkDeleteClientsPostStruct* post = calloc(1, sizeof(struct jsonBulkDeleteClientsPostStruct));
    post->emails = make_emails(2, names);
    post->emailsCount = 2;
    post->keepTraffic = 0;
    const char* s = jsonBulkDeleteClientsPost(post);
    CHECK(s && strcmp(s, "{\"emails\":[\"alice\",\"bob\"],\"keepTraffic\":false}") == 0, "bulk delete post matches sample");
    free((char*)s);
    jsonBulkDeleteClientsPostStructDelete(post);

    struct jsonBulkDeleteClientsResponseStruct* r = jsonBulkDeleteClientsResponse("{\"success\":true,\"obj\":{\"deleted\":2,\"skipped\":[{\"email\":\"carol\",\"reason\":\"client not found\"}]}}");
    CHECK(r && r->bulkDelClisObjRStruct->deleted == 2 && r->bulkDelClisObjRStruct->jsonBulkDeleteClientsObjectSkippedArrayResponseStructSize == 1, "bulk delete response");
    jsonBulkDeleteClientsResponseStructDelete(r);
}

static void test_bulk_create(void) {
    struct jsonBulkCreateClientsMainObjectPostStruct* items = calloc(2, sizeof(struct jsonBulkCreateClientsMainObjectPostStruct));
    items[0].email = strdup("alice@example.com");
    items[0].totalGB = 53687091200;
    items[0].expiryTime = 0;
    items[0].limitHwid = 2;
    items[0].enable = 1;
    items[0].inboundIdsCount = 1;
    items[0].inboundIds = malloc(sizeof(int));
    items[0].inboundIds[0] = 7;
    items[1].email = strdup("bob@example.com");
    items[1].totalGB = 53687091200;
    items[1].expiryTime = 0;
    items[1].limitHwid = 0;
    items[1].enable = 1;
    items[1].inboundIdsCount = 2;
    items[1].inboundIds = malloc(2 * sizeof(int));
    items[1].inboundIds[0] = 7;
    items[1].inboundIds[1] = 9;

    struct jsonBulkCreateClientsPostStruct* post = calloc(1, sizeof(struct jsonBulkCreateClientsPostStruct));
    post->jsonBulkCreateClientsMainObjectPostStructSize = 2;
    post->bulkCreateClisMainObjPStruct = items;

    const char* s = jsonBulkCreateClientsPost(post);
    CHECK(s && strcmp(s, "[{\"client\":{\"email\":\"alice@example.com\",\"totalGB\":53687091200,\"expiryTime\":0,\"limitHwid\":2,\"enable\":true},\"inboundIds\":[7]},{\"client\":{\"email\":\"bob@example.com\",\"totalGB\":53687091200,\"expiryTime\":0,\"limitHwid\":0,\"enable\":true},\"inboundIds\":[7,9]}]") == 0, "bulk create post matches sample");
    free((char*)s);
    jsonBulkCreateClientsPostStructDelete(post);

    struct jsonBulkCreateClientsResponseStruct* r = jsonBulkCreateClientsResponse("{\"success\":true,\"obj\":{\"created\":2,\"skipped\":[{\"email\":\"alice@example.com\",\"reason\":\"email already in use\"}]}}");
    CHECK(r && r->bulkCreateClisObjRStruct->created == 2 && strcmp(r->bulkCreateClisObjRStruct->bulkCreateClisObjSkippedArrRStruct[0].reason, "email already in use") == 0, "bulk create response");
    jsonBulkCreateClientsResponseStructDelete(r);
}

static void test_bulk_remove_group(void) {
    const char* names[] = { "alice", "bob" };
    struct jsonBulkRemoveClientsGroupPostStruct* post = calloc(1, sizeof(struct jsonBulkRemoveClientsGroupPostStruct));
    post->emails = make_emails(2, names);
    post->emailsCount = 2;
    const char* s = jsonBulkRemoveClientsGroupPost(post);
    CHECK(s && strcmp(s, "{\"emails\":[\"alice\",\"bob\"]}") == 0, "bulk remove clients group post matches sample");
    free((char*)s);
    jsonBulkRemoveClientsGroupPostStructDelete(post);

    struct jsonBulkRemoveClientsGroupResponseStruct* r = jsonBulkRemoveClientsGroupResponse("{\"success\":true,\"obj\":{\"affected\":2}}");
    CHECK(r && r->bulkRmCliGroupObjRStruct->affected == 2, "bulk remove clients group response");
    jsonBulkRemoveClientsGroupResponseStructDelete(r);
}

static void test_bulk_attach(void) {
    const char* names[] = { "alice", "bob" };
    struct jsonBulkAttachClientsPostStruct* post = calloc(1, sizeof(struct jsonBulkAttachClientsPostStruct));
    post->emails = make_emails(2, names);
    post->emailsCount = 2;
    post->inboundIdsCount = 2;
    post->inboundIds = malloc(2 * sizeof(int));
    post->inboundIds[0] = 7;
    post->inboundIds[1] = 9;
    const char* s = jsonBulkAttachClientsPost(post);
    CHECK(s && strcmp(s, "{\"emails\":[\"alice\",\"bob\"],\"inboundIds\":[7,9]}") == 0, "bulk attach post matches sample");
    free((char*)s);
    jsonBulkAttachClientsPostStructDelete(post);

    struct jsonBulkAttachClientsResponseStruct* r = jsonBulkAttachClientsResponse("{\"success\":true,\"obj\":{\"attached\":[\"alice\",\"bob\"],\"skipped\":[\"bob\"],\"errors\":[]}}");
    CHECK(r && r->bulkAttachClisObjRStruct->attachedCount == 2 && strcmp(r->bulkAttachClisObjRStruct->attached[1], "bob") == 0, "bulk attach response attached list");
    CHECK(r && r->bulkAttachClisObjRStruct->skippedCount == 1 && strcmp(r->bulkAttachClisObjRStruct->skipped[0], "bob") == 0, "bulk attach response skipped list");
    CHECK(r && r->bulkAttachClisObjRStruct->errorsCount == 0 && r->bulkAttachClisObjRStruct->errors == NULL, "bulk attach response empty errors");
    jsonBulkAttachClientsResponseStructDelete(r);
}

static void test_bulk_adjust_omits_empty_optionals(void) {
    const char* names[] = { "alice", "bob" };
    struct jsonBulkAdjustClientsPostStruct* post = calloc(1, sizeof(struct jsonBulkAdjustClientsPostStruct));
    post->emails = make_emails(2, names);
    post->emailsCount = 2;
    post->addDays = 30;
    post->addBytes = 53687091200;
    post->flow = strdup("");
    post->limitHwid = 2;
    const char* s = jsonBulkAdjustClientsPost(post);
    CHECK(s && strcmp(s, "{\"emails\":[\"alice\",\"bob\"],\"addDays\":30,\"addBytes\":53687091200,\"limitHwid\":2}") == 0, "bulk adjust post omits empty flow and missing adTag");
    free((char*)s);
    jsonBulkAdjustClientsPostStructDelete(post);
}

static void test_bulk_detach(void) {
    const char* names[] = { "alice", "bob" };
    struct jsonBulkDetachClientsPostStruct* post = calloc(1, sizeof(struct jsonBulkDetachClientsPostStruct));
    post->emails = make_emails(2, names);
    post->emailsCount = 2;
    post->inboundIdsCount = 2;
    post->inboundIds = malloc(2 * sizeof(int));
    post->inboundIds[0] = 7;
    post->inboundIds[1] = 9;
    const char* s = jsonBulkDetachClientsPost(post);
    CHECK(s && strcmp(s, "{\"emails\":[\"alice\",\"bob\"],\"inboundIds\":[7,9]}") == 0, "bulk detach post matches sample");
    free((char*)s);
    jsonBulkDetachClientsPostStructDelete(post);

    struct jsonBulkDetachClientsResponseStruct* r = jsonBulkDetachClientsResponse("{\"success\":true,\"obj\":{\"detached\":[\"alice\",\"bob\"],\"skipped\":[],\"errors\":[]}}");
    CHECK(r && r->bulkDetachClisObjRStruct->detachedCount == 2 && strcmp(r->bulkDetachClisObjRStruct->detached[0], "alice") == 0, "bulk detach response detached list");
    CHECK(r && r->bulkDetachClisObjRStruct->skippedCount == 0 && r->bulkDetachClisObjRStruct->skipped == NULL, "bulk detach response empty skipped");
    CHECK(r && r->bulkDetachClisObjRStruct->errorsCount == 0 && r->msg == NULL, "bulk detach response empty errors and no msg");
    jsonBulkDetachClientsResponseStructDelete(r);
}

static void test_single_attach_detach(void) {
    int ids_attach[] = { 7, 9 };
    struct jsonAttachClient2AdditionalInboundsPostStruct* ap = calloc(1, sizeof(struct jsonAttachClient2AdditionalInboundsPostStruct));
    ap->inboundIdsCount = 2;
    ap->inboundIds = malloc(sizeof(ids_attach));
    memcpy(ap->inboundIds, ids_attach, sizeof(ids_attach));
    const char* s1 = jsonAttachClient2AdditionalInboundsPost(ap);
    CHECK(s1 && strcmp(s1, "{\"inboundIds\":[7,9]}") == 0, "single attach post matches sample");
    free((char*)s1);
    jsonAttachClient2AdditionalInboundsPostStructDelete(ap);

    struct jsonAttachClient2AdditionalInboundsResponseStruct* ar = jsonAttachClient2AdditionalInboundsResponse("{\"success\":true}");
    CHECK(ar && ar->success == 1 && ar->msg == NULL, "single attach response without msg");
    jsonAttachClient2AdditionalInboundsResponseStructDelete(ar);

    struct jsonAttachClient2AdditionalInboundsResponseStruct* arm = jsonAttachClient2AdditionalInboundsResponse("{\"success\":true,\"msg\":\"already attached\"}");
    CHECK(arm && arm->msg && strcmp(arm->msg, "already attached") == 0, "single attach response with optional msg");
    jsonAttachClient2AdditionalInboundsResponseStructDelete(arm);

    int ids_detach[] = { 5 };
    struct jsonDetachClient2AdditionalInboundsPostStruct* dp = calloc(1, sizeof(struct jsonDetachClient2AdditionalInboundsPostStruct));
    dp->inboundIdsCount = 1;
    dp->inboundIds = malloc(sizeof(ids_detach));
    memcpy(dp->inboundIds, ids_detach, sizeof(ids_detach));
    const char* s2 = jsonDetachClient2AdditionalInboundsPost(dp);
    CHECK(s2 && strcmp(s2, "{\"inboundIds\":[5]}") == 0, "single detach post matches sample");
    free((char*)s2);
    jsonDetachClient2AdditionalInboundsPostStructDelete(dp);

    struct jsonDetachClient2AdditionalInboundsResponseStruct* dr = jsonDetachClient2AdditionalInboundsResponse("{\"success\":true}");
    CHECK(dr && dr->success == 1 && dr->msg == NULL, "single detach response without msg");
    jsonDetachClient2AdditionalInboundsResponseStructDelete(dr);

    struct jsonDetachClient2AdditionalInboundsResponseStruct* drm = jsonDetachClient2AdditionalInboundsResponse("{\"success\":true,\"msg\":\"not attached\"}");
    CHECK(drm && drm->msg && strcmp(drm->msg, "not attached") == 0, "single detach response with optional msg");
    jsonDetachClient2AdditionalInboundsResponseStructDelete(drm);
}

static void test_bulk_reset_traffic(void) {
    const char* names[] = { "alice", "bob" };
    struct jsonBulkResetTrafficPostStruct* post = calloc(1, sizeof(struct jsonBulkResetTrafficPostStruct));
    post->emails = make_emails(2, names);
    post->emailsCount = 2;
    const char* s = jsonBulkResetTrafficPost(post);
    CHECK(s && strcmp(s, "{\"emails\":[\"alice\",\"bob\"]}") == 0, "bulk reset traffic post matches sample");
    free((char*)s);
    jsonBulkResetTrafficPostStructDelete(post);

    struct jsonBulkResetTrafficResponseStruct* r = jsonBulkResetTrafficResponse("{\"success\":true,\"obj\":{\"affected\":2}}");
    CHECK(r && r->bulkResetTrafficObjRStruct->affected == 2, "bulk reset traffic response affected");
    jsonBulkResetTrafficResponseStructDelete(r);
}

int main(void) {
    test_bulk_adjust();
    test_bulk_adjust_omits_empty_optionals();
    test_bulk_enable_disable();
    test_bulk_delete();
    test_bulk_create();
    test_bulk_remove_group();
    test_bulk_attach();
    test_bulk_detach();
    test_single_attach_detach();
    test_bulk_reset_traffic();

    if (failures) {
        printf("CLIENTS BULK TESTS FAILED: %d\n", failures);
        return 1;
    }

    printf("CLIENTS BULK TESTS PASSED\n");
    return 0;
}
