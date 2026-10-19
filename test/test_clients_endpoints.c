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

static void test_groups(void) {
    struct jsonListGroupsResponseStruct* l = jsonListGroupsResponse("{\"success\":true,\"obj\":[{\"name\":\"customer-a\",\"clientCount\":5},{\"name\":\"internal\",\"clientCount\":0}]}");
    CHECK(l && l->success == 1 && l->jsonListGroupsObjectArrayStructSize == 2, "groups list size");
    CHECK(l && strcmp(l->listGroupsObjArrStruct[0].name, "customer-a") == 0 && l->listGroupsObjArrStruct[0].clientCount == 5, "groups list first item");
    jsonListGroupsResponseStructDelete(l);

    struct jsonListGroupEmailsResponseStruct* e = jsonListGroupEmailsResponse("{\"success\":true,\"obj\":[\"alice\",\"bob\",\"carol\"]}");
    CHECK(e && e->objCount == 3 && strcmp(e->obj[2], "carol") == 0, "group emails list with count");
    jsonListGroupEmailsResponseStructDelete(e);

    struct jsonCreateGroupPostStruct* cp = calloc(1, sizeof(struct jsonCreateGroupPostStruct));
    cp->name = strdup("customer-a");
    const char* s1 = jsonCreateGroupPost(cp);
    CHECK(s1 && strcmp(s1, "{\"name\":\"customer-a\"}") == 0, "create group post matches sample");
    free((char*)s1);
    jsonCreateGroupPostStructDelete(cp);

    struct jsonCreateGroupResponseStruct* cr = jsonCreateGroupResponse("{\"success\":true,\"obj\":{\"name\":\"customer-a\"}}");
    CHECK(cr && strcmp(cr->createGroupObjRStruct->name, "customer-a") == 0, "create group response");
    jsonCreateGroupResponseStructDelete(cr);

    struct jsonRenameGroupPostStruct* rp = calloc(1, sizeof(struct jsonRenameGroupPostStruct));
    rp->oldName = strdup("customer-a");
    rp->newName = strdup("tier-1");
    const char* s2 = jsonRenameGroupPost(rp);
    CHECK(s2 && strcmp(s2, "{\"oldName\":\"customer-a\",\"newName\":\"tier-1\"}") == 0, "rename group post matches sample");
    free((char*)s2);
    jsonRenameGroupPostStructDelete(rp);

    struct jsonRenameGroupResponseStruct* rr = jsonRenameGroupResponse("{\"success\":true,\"obj\":{\"affected\":5}}");
    CHECK(rr && rr->renameGroupObjRStruct->affected == 5, "rename group response");
    jsonRenameGroupResponseStructDelete(rr);

    struct jsonDeleteGroupPostStruct* dp = calloc(1, sizeof(struct jsonDeleteGroupPostStruct));
    dp->name = strdup("customer-a");
    const char* s3 = jsonDeleteGroupPost(dp);
    CHECK(s3 && strcmp(s3, "{\"name\":\"customer-a\"}") == 0, "delete group post matches sample");
    free((char*)s3);
    jsonDeleteGroupPostStructDelete(dp);

    struct jsonDeleteGroupResponseStruct* dr = jsonDeleteGroupResponse("{\"success\":true,\"obj\":{\"affected\":5}}");
    CHECK(dr && dr->deleteGroupObjRStruct->affected == 5, "delete group response");
    jsonDeleteGroupResponseStructDelete(dr);

    struct jsonResetGroupTrafficPostStruct* tp = calloc(1, sizeof(struct jsonResetGroupTrafficPostStruct));
    tp->name = strdup("customer-a");
    const char* s4 = jsonResetGroupTrafficPost(tp);
    CHECK(s4 && strcmp(s4, "{\"name\":\"customer-a\"}") == 0, "reset group traffic post matches sample");
    free((char*)s4);
    jsonResetGroupTrafficPostStructDelete(tp);

    struct jsonResetGroupTrafficResponseStruct* tr = jsonResetGroupTrafficResponse("{\"success\":true,\"obj\":{\"name\":\"customer-a\"}}");
    CHECK(tr && strcmp(tr->resetGroupTrafficObjRStruct->name, "customer-a") == 0, "reset group traffic response");
    jsonResetGroupTrafficResponseStructDelete(tr);

    const char* names[] = { "alice", "bob" };
    struct jsonBulkAddClients2GroupPostStruct* ap = calloc(1, sizeof(struct jsonBulkAddClients2GroupPostStruct));
    ap->emails = make_emails(2, names);
    ap->emailsCount = 2;
    ap->group = strdup("customer-a");
    const char* s5 = jsonBulkAddClients2GroupPost(ap);
    CHECK(s5 && strcmp(s5, "{\"emails\":[\"alice\",\"bob\"],\"group\":\"customer-a\"}") == 0, "bulk add to group post matches sample");
    free((char*)s5);
    jsonBulkAddClients2GroupPostStructDelete(ap);

    struct jsonBulkAddClients2GroupResponseStruct* ar = jsonBulkAddClients2GroupResponse("{\"success\":true,\"obj\":{\"affected\":2}}");
    CHECK(ar && ar->bulkAddClis2GroupObjRStruct->affected == 2, "bulk add to group response");
    jsonBulkAddClients2GroupResponseStructDelete(ar);

}

static void test_traffic_and_ips(void) {
    struct jsonUpdateClientTrafficPostStruct* up = calloc(1, sizeof(struct jsonUpdateClientTrafficPostStruct));
    up->upload = 1073741824;
    up->download = 5368709120;
    const char* s = jsonUpdateClientTrafficPost(up);
    CHECK(s && strcmp(s, "{\"upload\":1073741824,\"download\":5368709120}") == 0, "update client traffic post matches sample");
    free((char*)s);
    jsonUpdateClientTrafficPostStructDelete(up);

    struct jsonUpdateClientTrafficResponseStruct* ur = jsonUpdateClientTrafficResponse("{\"success\":true,\"msg\":\"string\",\"obj\":null}");
    CHECK(ur && ur->success == 1 && strcmp(ur->msg, "string") == 0, "update client traffic response");
    jsonUpdateClientTrafficResponseStructDelete(ur);

    struct jsonResetClientTrafficResponseStruct* rr = jsonResetClientTrafficResponse("{\"success\":true}");
    CHECK(rr && rr->success == 1 && rr->msg == NULL, "reset client traffic response");
    jsonResetClientTrafficResponseStructDelete(rr);

    struct jsonTrafficResponseStruct* t = jsonTrafficResponse("{\"success\":true,\"obj\":{\"down\":2097152,\"email\":\"user1\",\"enable\":true,\"expiryTime\":1735689600000,\"id\":14825,\"inboundId\":1,\"lastOnline\":1735680000000,\"lastSubFetch\":1735680000000,\"reset\":0,\"resetCount\":0,\"resetDay\":0,\"resetMax\":0,\"resetWeekday\":3,\"subId\":\"i7tvdpeffi0hvvf1\",\"total\":10737418240,\"up\":1048576,\"uuid\":\"e18c9a96-71bf-48d4-933f-8b9a46d4290c\"}}");
    CHECK(t && t->trafficObjRStruct && strcmp(t->trafficObjRStruct->email, "user1") == 0 && t->trafficObjRStruct->resetWeekday == 3 && t->trafficObjRStruct->up == 1048576, "traffic response with resetWeekday");
    jsonTrafficResponseStructDelete(t);

    struct jsonListClientIpsResponseStruct* ipNull = jsonListClientIpsResponse("{\"success\":true,\"msg\":\"string\",\"obj\":null}");
    CHECK(ipNull && ipNull->objCount == 0 && ipNull->obj == NULL, "client ips response with null obj");
    jsonListClientIpsResponseStructDelete(ipNull);

    struct jsonListClientIpsResponseStruct* ip = jsonListClientIpsResponse("{\"success\":true,\"obj\":[\"1.2.3.4 (1700000000)\",\"5.6.7.8 (1700000100)\"]}");
    CHECK(ip && ip->objCount == 2 && strcmp(ip->obj[1], "5.6.7.8 (1700000100)") == 0, "client ips response string array with count");
    jsonListClientIpsResponseStructDelete(ip);

    struct jsonClearClientIpsResponseStruct* ci = jsonClearClientIpsResponse("{\"success\":true,\"msg\":\"string\",\"obj\":null}");
    CHECK(ci && ci->success == 1, "clear client ips response");
    jsonClearClientIpsResponseStructDelete(ci);
}

static void test_hwids(void) {
    struct jsonListClientHwidsResponseStruct* h = jsonListClientHwidsResponse("{\"success\":true,\"obj\":[{\"id\":1,\"firstSeen\":1735000000000,\"lastSeen\":1735100000000,\"userAgent\":\"Happ/1.0\",\"deviceOs\":\"android\",\"osVersion\":\"15\",\"deviceModel\":\"Pixel 9\",\"fingerprint\":\"6ad17c93e821\"}]}");
    CHECK(h && h->jsonListClientHwidsObjectArrayStructSize == 1 && strcmp(h->listClientHwidsObjArrStruct[0].fingerprint, "6ad17c93e821") == 0, "hwid list with fingerprint");
    jsonListClientHwidsResponseStructDelete(h);

    struct jsonClearClientHwidsResponseStruct* c = jsonClearClientHwidsResponse("{\"success\":true,\"msg\":\"string\",\"obj\":null}");
    CHECK(c && c->success == 1, "clear hwids response");
    jsonClearClientHwidsResponseStructDelete(c);

    struct jsonDeleteClientHwidResponseStruct* d = jsonDeleteClientHwidResponse("{\"success\":true,\"msg\":\"string\",\"obj\":null}");
    CHECK(d && d->success == 1, "delete hwid response");
    jsonDeleteClientHwidResponseStructDelete(d);
}

static void test_online_and_links(void) {
    struct jsonOnlinesResponseStruct* o = jsonOnlinesResponse("{\"success\":true,\"obj\":[\"user1\",\"user2\"]}");
    CHECK(o && o->objCount == 2 && strcmp(o->obj[0], "user1") == 0, "onlines response");
    jsonOnlinesResponseStructDelete(o);

    struct jsonOnlinesByGuidResponseStruct* og = jsonOnlinesByGuidResponse("{\"success\":true,\"obj\":{\"a1b2-x\":[\"user1\"],\"c3d4-y\":[\"user1\",\"user2\"]}}");
    CHECK(og && og->jsonOnlinesByGuidObjectArrayStructSize == 2 && strcmp(og->onlinesByGuidObjArrStruct[1].panelGuid, "c3d4-y") == 0 && og->onlinesByGuidObjArrStruct[1].emailsCount == 2, "onlines by guid");
    jsonOnlinesByGuidResponseStructDelete(og);

    struct jsonClientIpsByGuidResponseStruct* ig = jsonClientIpsByGuidResponse("{\"success\":true,\"obj\":{\"a1b2-x\":{\"user1\":[{\"ip\":\"1.2.3.4\",\"timestamp\":1700000000}]}}}");
    CHECK(ig && ig->jsonClientIpsByGuidObjectArrayStructSize == 1 && strcmp(ig->clientIpsByGuidObjArrStruct[0].clientIpsByGuidCliObjArrStruct[0].email, "user1") == 0 &&
          strcmp(ig->clientIpsByGuidObjArrStruct[0].clientIpsByGuidCliObjArrStruct[0].clientIpsByGuidIpObjArrStruct[0].ip, "1.2.3.4") == 0 &&
          ig->clientIpsByGuidObjArrStruct[0].clientIpsByGuidCliObjArrStruct[0].clientIpsByGuidIpObjArrStruct[0].timestamp == 1700000000, "client ips by guid");
    jsonClientIpsByGuidResponseStructDelete(ig);

    struct jsonActiveInboundsResponseStruct* ai = jsonActiveInboundsResponse("{\"success\":true,\"obj\":{\"a1b2-x\":[\"in-443-tcp\",\"in-8443-tcp\"]}}");
    CHECK(ai && ai->activeInboundsObjArrStruct[0].tagsCount == 2 && strcmp(ai->activeInboundsObjArrStruct[0].tags[1], "in-8443-tcp") == 0, "active inbounds");
    jsonActiveInboundsResponseStructDelete(ai);

    struct jsonLastOnlineResponseStruct* lo = jsonLastOnlineResponse("{\"success\":true,\"obj\":{\"user1\":1700000000,\"user2\":1699999000}}");
    CHECK(lo && lo->jsonLastOnlineObjectArrayStructSize == 2 && strcmp(lo->lastOnlineObjArrStruct[1].email, "user2") == 0 && lo->lastOnlineObjArrStruct[1].lastOnline == 1699999000, "last online map");
    jsonLastOnlineResponseStructDelete(lo);

    struct jsonSubLinksResponseStruct* sl = jsonSubLinksResponse("{\"success\":true,\"obj\":[\"vless://uuid@host:443?...#user1\",\"vmess://eyJ2IjoyLC...\"]}");
    CHECK(sl && sl->objCount == 2, "sub links");
    jsonSubLinksResponseStructDelete(sl);

    struct jsonLinksResponseStruct* li = jsonLinksResponse("{\"success\":true,\"obj\":[\"vless://uuid@host:443?...#user1\"]}");
    CHECK(li && li->objCount == 1, "links");
    jsonLinksResponseStructDelete(li);

    struct jsonHappLinkResponseStruct* hl = jsonHappLinkResponse("{\"success\":true,\"obj\":{\"encryptedLink\":\"happ://crypt5/example\"}}");
    CHECK(hl && hl->success == 1 && strcmp(hl->happLinkObjStruct->encryptedLink, "happ://crypt5/example") == 0, "happ link");
    jsonHappLinkResponseStructDelete(hl);

    struct jsonHappLinkResponseStruct* hf = jsonHappLinkResponse("{\"success\":false,\"msg\":\"happ_source_too_long\",\"obj\":null}");
    CHECK(hf && hf->success == 0 && strcmp(hf->msg, "happ_source_too_long") == 0 && hf->happLinkObjStruct == NULL, "happ link failure keeps msg");
    jsonHappLinkResponseStructDelete(hf);
}

static void test_renewal_preview(void) {
    struct jsonRenewalPreviewPostStruct* post = calloc(1, sizeof(struct jsonRenewalPreviewPostStruct));
    const char* s = jsonRenewalPreviewPost(post);
    CHECK(s && strcmp(s, "{\"expiryTime\":0,\"reset\":0,\"resetDay\":0,\"resetWeekday\":0,\"resetMax\":0,\"resetCount\":0}") == 0, "renewal preview post matches sample");
    free((char*)s);
    jsonRenewalPreviewPostStructDelete(post);

    struct jsonRenewalPreviewResponseStruct* r = jsonRenewalPreviewResponse("{\"success\":true,\"obj\":{\"canRenew\":true,\"delayedStart\":false,\"nextExpiry\":\"2030-02-01T00:00:00Z\",\"renewAt\":\"2030-01-01T00:00:00Z\",\"renewals\":1,\"suggestedExpiry\":\"2030-01-01T00:00:00Z\",\"suggestedExpiryTime\":1893456000000,\"timeZone\":\"UTC\",\"validThrough\":\"2029-12-31T23:59:59Z\"}}");
    CHECK(r && r->success == 1 && r->renewalPreviewObjStruct->canRenew == 1 && r->renewalPreviewObjStruct->renewals == 1, "renewal preview response flags and count");
    CHECK(r && strcmp(r->renewalPreviewObjStruct->renewAt, "2030-01-01T00:00:00Z") == 0 && r->renewalPreviewObjStruct->suggestedExpiryTime == 1893456000000, "renewal preview response dates");
    jsonRenewalPreviewResponseStructDelete(r);

    struct jsonRenewalPreviewResponseStruct* f = jsonRenewalPreviewResponse("{\"success\":false,\"msg\":\"bad cutoff\",\"obj\":null}");
    CHECK(f && f->success == 0 && strcmp(f->msg, "bad cutoff") == 0 && f->renewalPreviewObjStruct == NULL, "renewal preview failure keeps msg");
    jsonRenewalPreviewResponseStructDelete(f);
}

static void test_failure_keeps_msg(void) {
    struct jsonListGroupsResponseStruct* f = jsonListGroupsResponse("{\"success\":false,\"msg\":\"nope\"}");
    CHECK(f && f->success == 0 && strcmp(f->msg, "nope") == 0, "groups failure keeps msg");
    jsonListGroupsResponseStructDelete(f);

    struct jsonDeleteAllDepletedClientsResponseStruct* d = jsonDeleteAllDepletedClientsResponse("{\"success\":false,\"msg\":\"busy\"}");
    CHECK(d && *d->success == 0 && strcmp(d->msg, "busy") == 0, "delete depleted failure keeps msg");
    jsonDeleteAllDepletedClientsResponseStructDelete(d);
}

int main(void) {
    test_groups();
    test_traffic_and_ips();
    test_hwids();
    test_online_and_links();
    test_failure_keeps_msg();
    test_renewal_preview();

    if (failures) {
        printf("CLIENTS ENDPOINT TESTS FAILED: %d\n", failures);
        return 1;
    }

    printf("CLIENTS ENDPOINT TESTS PASSED\n");
    return 0;
}
