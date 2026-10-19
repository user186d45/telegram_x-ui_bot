#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cjson/cJSON.h>
#include "cjson/clients.h"

static int failures = 0;

#define CHECK(cond, name) do { if (cond) { printf("OK %s\n", name); } else { printf("FAILED %s\n", name); failures++; } } while (0)

static void test_delete_client_by_email_response(void) {
    struct jsonDeleteClientByEmailResponseStruct* r = jsonDeleteClientByEmailResponse("{\"success\":true,\"msg\":\"Client deleted\"}");
    CHECK(r && r->success == 1 && r->msg && strcmp(r->msg, "Client deleted") == 0, "delete client by email response");
    jsonDeleteClientByEmailResponseStructDelete(r);
}

static void test_replace_external_links_post(void) {
    struct jsonExternalLinksObjectArrayPostStruct* links = calloc(2, sizeof(struct jsonExternalLinksObjectArrayPostStruct));
    links[0].kind = strdup("link");
    links[0].value = strdup("vless://uuid@host:443?...#srv");
    links[0].remark = strdup("DE");
    links[0].enable = 1;
    links[1].kind = strdup("subscription");
    links[1].value = strdup("https://provider.example/sub/abc");
    links[1].remark = strdup("Provider");
    links[1].enable = 0;
    links[1].expiryTime = 1767225600000;
    links[1].namePrefix = strdup("[zjh] ");

    struct jsonReplaceClientExternalLinksPostStruct* post = calloc(1, sizeof(struct jsonReplaceClientExternalLinksPostStruct));
    post->jsonExternalLinksObjectArrayPostStructSize = 2;
    post->rplExtLinksObjArrPStruct = links;

    const char* s = jsonReplaceClientExternalLinksPost(post);
    const char* want = "{\"externalLinks\":[{\"kind\":\"link\",\"value\":\"vless://uuid@host:443?...#srv\",\"remark\":\"DE\",\"enable\":true},{\"kind\":\"subscription\",\"value\":\"https://provider.example/sub/abc\",\"remark\":\"Provider\",\"enable\":false,\"expiryTime\":1767225600000,\"namePrefix\":\"[zjh] \"}]}";
    CHECK(s && strcmp(s, want) == 0, "replace external links post");
    free((char*)s);
    jsonReplaceClientExternalLinksPostStructDelete(post);

    struct jsonReplaceClientExternalLinksPostStruct* empty = calloc(1, sizeof(struct jsonReplaceClientExternalLinksPostStruct));
    const char* e = jsonReplaceClientExternalLinksPost(empty);
    CHECK(e && strcmp(e, "{\"externalLinks\":[]}") == 0, "replace external links post empty clears rows");
    free((char*)e);
    jsonReplaceClientExternalLinksPostStructDelete(empty);
}

static void test_replace_and_reset_responses(void) {
    struct jsonReplaceClientExternalLinksResponseStruct* r1 = jsonReplaceClientExternalLinksResponse("{\"success\":true}");
    CHECK(r1 && r1->success == 1 && r1->msg == NULL, "replace external links response without msg");
    jsonReplaceClientExternalLinksResponseStructDelete(r1);

    struct jsonResetAllClientsTrafficsResponseStruct* r2 = jsonResetAllClientsTrafficsResponse("{\"success\":true,\"msg\":\"traffic reset\"}");
    CHECK(r2 && r2->success == 1 && strcmp(r2->msg, "traffic reset") == 0, "reset all traffics response with msg");
    jsonResetAllClientsTrafficsResponseStructDelete(r2);
}

static void test_delete_depleted_and_orphan(void) {
    struct jsonDeleteAllDepletedClientsResponseStruct* d = jsonDeleteAllDepletedClientsResponse("{\"success\":true,\"obj\":{\"deleted\":5}}");
    CHECK(d && d->success && *d->success == 1 && d->deleted == 5, "delete all depleted response");
    jsonDeleteAllDepletedClientsResponseStructDelete(d);

    struct jsonDeleteAllOrphanClientsResponseStruct* o = jsonDeleteAllOrphanClientsResponse("{\"success\":true,\"obj\":{\"deleted\":0}}");
    CHECK(o && o->success && *o->success == 1 && o->deleted == 0, "delete all orphan response");
    jsonDeleteAllOrphanClientsResponseStructDelete(o);
}

static void test_export_all_clients_response(void) {
    const char* json = "{\"success\":true,\"msg\":\"\",\"obj\":[{\"client\":{\"id\":\"254fcf67-5207-4b2e-94bc-e78d1b0fd28d\",\"security\":\"auto\",\"password\":\"tmyuhcj5jzdzkox7\",\"auth\":\"v0vzk7r37v9tkb7f\",\"email\":\"qbgu8qzpv9\",\"limitIp\":0,\"totalGB\":0,\"expiryTime\":1793133000000,\"enable\":true,\"tgId\":0,\"subId\":\"szs0o19sdv9z1ik1\",\"group\":\"exmapleGroup\",\"comment\":\"exampleComment\",\"reset\":30,\"created_at\":1792313382097,\"updated_at\":1792313382000},\"inboundIds\":[1]}]}";
    struct jsonExportAllClientsResponseStruct* r = jsonExportAllClientsResponse(json);
    CHECK(r && r->jsonExportAllClientsObjectArrayResponseStructSize == 1, "export all clients response size");
    if (r && r->jsonExportAllClientsObjectArrayResponseStructSize == 1) {
        struct jsonExportAllClientsObjectArrayClientObjectResponseStruct* c = r->exportAllClisObjArrRStruct[0].exportAllCliObjArrCliObjRStruct;
        CHECK(c && strcmp(c->email, "qbgu8qzpv9") == 0, "export all clients email");
        CHECK(c && c->group && strcmp(c->group, "exmapleGroup") == 0, "export all clients group");
        CHECK(c && c->createdAt == 1792313382097 && c->updatedAt == 1792313382000, "export all clients created_at/updated_at");
        CHECK(r->exportAllClisObjArrRStruct[0].inboundIdsCount == 1 && r->exportAllClisObjArrRStruct[0].inboundIds[0] == 1, "export all clients inboundIds");
    }
    jsonExportAllClientsResponseStructDelete(r);

    struct jsonExportAllClientsResponseStruct* empty = jsonExportAllClientsResponse("{\"success\":true,\"obj\":[]}");
    CHECK(empty && empty->jsonExportAllClientsObjectArrayResponseStructSize == 0 && empty->msg == NULL, "export all clients empty without msg");
    jsonExportAllClientsResponseStructDelete(empty);
}

static void test_import_clients_post_shape(void) {
    struct jsonImportClientsDataObjectPostStruct* clients = calloc(1, sizeof(struct jsonImportClientsDataObjectPostStruct));
    clients[0].id = strdup("254fcf67-5207-4b2e-94bc-e78d1b0fd28d");
    clients[0].security = strdup("auto");
    clients[0].password = strdup("tmyuhcj5jzdzkox7");
    clients[0].auth = strdup("v0vzk7r37v9tkb7f");
    clients[0].email = strdup("qbgu8qzpv9");
    clients[0].expiryTime = 1793133000000;
    clients[0].enable = 1;
    clients[0].subId = strdup("szs0o19sdv9z1ik1");
    clients[0].group = strdup("exmapleGroup");
    clients[0].comment = strdup("exampleComment");
    clients[0].reset = 30;
    clients[0].trafficReset = strdup("never");
    clients[0].trafficResetDay = 1;
    clients[0].createdAt = 1792313382097;
    clients[0].updatedAt = 1792313382000;
    clients[0].inboundIdsCount = 1;
    clients[0].inboundIds = malloc(sizeof(int));
    clients[0].inboundIds[0] = 1;
    clients[0].trafficObjPStruct = calloc(1, sizeof(struct jsonImportClientsTrafficObjectPostStruct));
    clients[0].trafficObjPStruct->up = 1048576;
    clients[0].trafficObjPStruct->down = 2097152;
    clients[0].trafficObjPStruct->resetCount = 0;
    clients[0].trafficObjPStruct->lastOnline = 1735680000000;

    struct jsonImportClientsPostStruct* post = calloc(1, sizeof(struct jsonImportClientsPostStruct));
    post->jsonImportClientsDataObjectPostStructSize = 1;
    post->importClientsDataObjPStruct = clients;

    const char* s = jsonImportClientsPost(post);
    cJSON* root = s ? cJSON_Parse(s) : NULL;
    cJSON* data = root ? cJSON_GetObjectItem(root, "data") : NULL;
    CHECK(data && cJSON_IsString(data), "import clients post wraps the array as a string in data");
    cJSON* items = data && cJSON_IsString(data) ? cJSON_Parse(data->valuestring) : NULL;
    cJSON* item = items ? cJSON_GetArrayItem(items, 0) : NULL;
    CHECK(item && cJSON_IsObject(cJSON_GetObjectItem(item, "client")), "import data item has a client object");
    CHECK(item && cJSON_GetObjectItem(item, "client") && strcmp(cJSON_GetObjectItem(cJSON_GetObjectItem(item, "client"), "group")->valuestring, "exmapleGroup") == 0, "import data client carries group");
    CHECK(item && cJSON_GetArraySize(cJSON_GetObjectItem(item, "inboundIds")) == 1, "import data item carries inboundIds next to client");
    CHECK(item && cJSON_GetObjectItem(item, "traffic") && cJSON_GetObjectItem(cJSON_GetObjectItem(item, "traffic"), "up")->valuedouble == 1048576, "import data item carries traffic");
    cJSON_Delete(items);
    cJSON_Delete(root);
    printf("import post: %s\n", s ? s : "NULL");
    free((char*)s);
    jsonImportClientsPostStructDelete(post);
}

static void test_import_clients_response(void) {
    struct jsonImportClientsResponseStruct* r = jsonImportClientsResponse("{\"success\":true,\"obj\":{\"created\":2,\"skipped\":[{\"email\":\"alice@example.com\",\"reason\":\"email already in use: alice@example.com\"}]}}");
    CHECK(r && r->msg == NULL && r->importClisObjRStruct->created == 2, "import clients response without msg");
    CHECK(r && r->importClisObjRStruct->jsonImportClientsObjectSkippedArrayResponseStructSize == 1 &&
          strcmp(r->importClisObjRStruct->importClisObjSkippedArrRStruct[0].email, "alice@example.com") == 0, "import clients response skipped email");
    jsonImportClientsResponseStructDelete(r);

    struct jsonImportClientsResponseStruct* r2 = jsonImportClientsResponse("{\"success\":true,\"obj\":{\"created\":1}}");
    CHECK(r2 && r2->importClisObjRStruct->created == 1 && r2->importClisObjRStruct->jsonImportClientsObjectSkippedArrayResponseStructSize == 0, "import clients response no skipped");
    jsonImportClientsResponseStructDelete(r2);
}

int main(void) {
    test_delete_client_by_email_response();
    test_replace_external_links_post();
    test_replace_and_reset_responses();
    test_delete_depleted_and_orphan();
    test_export_all_clients_response();
    test_import_clients_post_shape();
    test_import_clients_response();

    if (failures) {
        printf("CLIENTS SAMPLE TESTS FAILED: %d\n", failures);
        return 1;
    }

    printf("CLIENTS SAMPLE TESTS PASSED\n");
    return 0;
}
