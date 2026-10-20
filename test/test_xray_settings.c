#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cjson/xray-settings.h"

static int failures = 0;

#define CHECK(cond, name) do { if (cond) { printf("OK %s\n", name); } else { printf("FAILED %s\n", name); failures++; } } while (0)

static void test_xray_config_response(void) {
    const char* json = "{\"success\":true,\"msg\":\"\",\"obj\":{\"xraySetting\":\"{\\\"inbounds\\\":[]}\",\"inboundTags\":\"[\\\"in-443-tcp\\\"]\",\"clientReverseTags\":\"[]\",\"outboundTestUrl\":\"https://www.google.com/generate_204\"}}";

    struct jsonXrayConfigResponseStruct* r = jsonXrayConfigResponse(json);
    CHECK(r && r->success == 1, "xray config response success");
    CHECK(r && r->msg && strcmp(r->msg, "") == 0, "xray config response msg");
    CHECK(r && r->xrayConfigObjRStruct != NULL, "xray config response has obj");
    if (r && r->xrayConfigObjRStruct) {
        CHECK(r->xrayConfigObjRStruct->xraySetting && strstr(r->xrayConfigObjRStruct->xraySetting, "inbounds") != NULL, "xray config xraySetting");
        CHECK(r->xrayConfigObjRStruct->inboundTags && strstr(r->xrayConfigObjRStruct->inboundTags, "in-443-tcp") != NULL, "xray config inboundTags");
        CHECK(r->xrayConfigObjRStruct->clientReverseTags && strcmp(r->xrayConfigObjRStruct->clientReverseTags, "[]") == 0, "xray config clientReverseTags");
        CHECK(r->xrayConfigObjRStruct->outboundTestUrl && strstr(r->xrayConfigObjRStruct->outboundTestUrl, "google.com") != NULL, "xray config outboundTestUrl");
    }
    jsonXrayConfigResponseStructDelete(r);

    struct jsonXrayConfigResponseStruct* fail = jsonXrayConfigResponse("{\"success\":false,\"msg\":\"error\"}");
    CHECK(fail && fail->success == 0 && fail->msg && strcmp(fail->msg, "error") == 0, "xray config response failure");
    jsonXrayConfigResponseStructDelete(fail);
}

static void test_xray_get_default_json_config(void) {
    const char* json = "{\"success\":true,\"msg\":\"\",\"obj\":\"{\\\"inbounds\\\":[]}\"}";

    struct jsonXrayGetDefaultJsonConfigResponseStruct* r = jsonXrayGetDefaultJsonConfigResponse(json);
    CHECK(r && r->success == 1, "xray get default json config success");
    CHECK(r && r->msg && strcmp(r->msg, "") == 0, "xray get default json config msg");
    CHECK(r && r->obj && strstr(r->obj, "inbounds") != NULL, "xray get default json config obj");
    jsonXrayGetDefaultJsonConfigResponseStructDelete(r);
}

static void test_xray_get_outbounds_traffic(void) {
    const char* json = "{\"success\":true,\"msg\":\"\",\"obj\":\"{\\\"proxy\\\":{\\\"up\\\":100,\\\"down\\\":200,\\\"total\\\":300}}\"}";

    struct jsonXrayGetOutboundsTrafficResponseStruct* r = jsonXrayGetOutboundsTrafficResponse(json);
    CHECK(r && r->success == 1, "xray get outbounds traffic success");
    CHECK(r && r->msg && strcmp(r->msg, "") == 0, "xray get outbounds traffic msg");
    CHECK(r && r->obj && strstr(r->obj, "proxy") != NULL, "xray get outbounds traffic obj");
    jsonXrayGetOutboundsTrafficResponseStructDelete(r);
}

static void test_xray_get_xray_result(void) {
    const char* json = "{\"success\":true,\"msg\":\"\",\"obj\":\"Xray started successfully\"}";

    struct jsonXrayGetXrayResultResponseStruct* r = jsonXrayGetXrayResultResponse(json);
    CHECK(r && r->success == 1, "xray get xray result success");
    CHECK(r && r->msg && strcmp(r->msg, "") == 0, "xray get xray result msg");
    CHECK(r && r->obj && strstr(r->obj, "started") != NULL, "xray get xray result obj");
    jsonXrayGetXrayResultResponseStructDelete(r);
}

static void test_xray_update_post(void) {
    struct jsonXrayUpdatePostStruct* post = calloc(1, sizeof(struct jsonXrayUpdatePostStruct));
    post->xraySetting = strdup("{\"inbounds\":[]}");
    post->outboundTestUrl = strdup("https://example.com/test");
    const char* s = jsonXrayUpdatePost(post);
    CHECK(s && strstr(s, "xraySetting=%7B%22inbounds%22%3A%5B%5D%7D") != NULL, "xray update post xraySetting");
    CHECK(s && strstr(s, "outboundTestUrl=https%3A%2F%2Fexample.com%2Ftest") != NULL, "xray update post outboundTestUrl");
    free((char*)s);
    jsonXrayUpdatePostStructDelete(post);

    struct jsonXrayUpdateResponseStruct* r = jsonXrayUpdateResponse("{\"success\":true,\"msg\":\"updated\"}");
    CHECK(r && r->success == 1 && r->msg && strcmp(r->msg, "updated") == 0, "xray update response");
    jsonXrayUpdateResponseStructDelete(r);
}

static void test_xray_warp_post(void) {
    struct jsonXrayWarpPostStruct* post = calloc(1, sizeof(struct jsonXrayWarpPostStruct));
    post->privateKey = strdup("private");
    post->publicKey = strdup("public");
    post->license = strdup("license-key");
    post->interval = 24;
    const char* s = jsonXrayWarpPost(post);
    CHECK(s && strstr(s, "privateKey=private") != NULL, "xray warp post privateKey");
    CHECK(s && strstr(s, "publicKey=public") != NULL, "xray warp post publicKey");
    CHECK(s && strstr(s, "license=license-key") != NULL, "xray warp post license");
    CHECK(s && strstr(s, "interval=24") != NULL, "xray warp post interval");
    free((char*)s);
    jsonXrayWarpPostStructDelete(post);

    struct jsonXrayWarpResponseStruct* r = jsonXrayWarpResponse("{\"success\":true,\"msg\":\"\",\"obj\":\"{\\\"status\\\":\\\"ok\\\"}\"}");
    CHECK(r && r->success == 1, "xray warp response success");
    CHECK(r && r->obj && strstr(r->obj, "status") != NULL, "xray warp response obj");
    jsonXrayWarpResponseStructDelete(r);
}

static void test_xray_nord_post(void) {
    struct jsonXrayNordPostStruct* post = calloc(1, sizeof(struct jsonXrayNordPostStruct));
    post->countryId = strdup("us");
    post->token = strdup("nord-token");
    post->key = strdup("nord-key");
    const char* s = jsonXrayNordPost(post);
    CHECK(s && strstr(s, "countryId=us") != NULL, "xray nord post countryId");
    CHECK(s && strstr(s, "token=nord-token") != NULL, "xray nord post token");
    CHECK(s && strstr(s, "key=nord-key") != NULL, "xray nord post key");
    free((char*)s);
    jsonXrayNordPostStructDelete(post);

    struct jsonXrayNordResponseStruct* r = jsonXrayNordResponse("{\"success\":true,\"msg\":\"\",\"obj\":\"{\\\"connected\\\":true}\"}");
    CHECK(r && r->success == 1, "xray nord response success");
    CHECK(r && r->obj && strstr(r->obj, "connected") != NULL, "xray nord response obj");
    jsonXrayNordResponseStructDelete(r);
}

static void test_xray_pia_post(void) {
    struct jsonXrayPiaPostStruct* post = calloc(1, sizeof(struct jsonXrayPiaPostStruct));
    post->countryCode = strdup("us");
    post->username = strdup("user");
    post->password = strdup("pass");
    post->hostname = strdup("us-pia.example.com");
    const char* s = jsonXrayPiaPost(post);
    CHECK(s && strstr(s, "countryCode=us") != NULL, "xray pia post countryCode");
    CHECK(s && strstr(s, "username=user") != NULL, "xray pia post username");
    CHECK(s && strstr(s, "password=pass") != NULL, "xray pia post password");
    CHECK(s && strstr(s, "hostname=us-pia.example.com") != NULL, "xray pia post hostname");
    free((char*)s);
    jsonXrayPiaPostStructDelete(post);

    struct jsonXrayPiaResponseStruct* r = jsonXrayPiaResponse("{\"success\":true,\"msg\":\"\",\"obj\":\"{\\\"connected\\\":true}\"}");
    CHECK(r && r->success == 1, "xray pia response success");
    CHECK(r && r->obj && strstr(r->obj, "connected") != NULL, "xray pia response obj");
    jsonXrayPiaResponseStructDelete(r);
}

static void test_xray_reset_outbounds_traffic(void) {
    struct jsonXrayResetOutboundsTrafficPostStruct* post = calloc(1, sizeof(struct jsonXrayResetOutboundsTrafficPostStruct));
    post->tag = strdup("proxy");
    const char* s = jsonXrayResetOutboundsTrafficPost(post);
    CHECK(s && strstr(s, "tag=proxy") != NULL, "xray reset outbounds traffic post");
    free((char*)s);
    jsonXrayResetOutboundsTrafficPostStructDelete(post);

    struct jsonXrayResetOutboundsTrafficResponseStruct* r = jsonXrayResetOutboundsTrafficResponse("{\"success\":true,\"msg\":\"reset\"}");
    CHECK(r && r->success == 1 && r->msg && strcmp(r->msg, "reset") == 0, "xray reset outbounds traffic response");
    jsonXrayResetOutboundsTrafficResponseStructDelete(r);
}

static void test_xray_test_outbound(void) {
    struct jsonXrayTestOutboundPostStruct* post = calloc(1, sizeof(struct jsonXrayTestOutboundPostStruct));
    post->outbound = strdup("{\"tag\":\"proxy\"}");
    post->allOutbounds = strdup("[{\"tag\":\"proxy\"}]");
    post->mode = strdup("tcp");
    const char* s = jsonXrayTestOutboundPost(post);
    CHECK(s && strstr(s, "outbound=%7B%22tag%22%3A%22proxy%22%7D") != NULL, "xray test outbound post outbound");
    CHECK(s && strstr(s, "allOutbounds=%5B%7B%22tag%22%3A%22proxy%22%7D%5D") != NULL, "xray test outbound post allOutbounds");
    CHECK(s && strstr(s, "mode=tcp") != NULL, "xray test outbound post mode");
    free((char*)s);
    jsonXrayTestOutboundPostStructDelete(post);

    struct jsonXrayTestOutboundResponseStruct* r = jsonXrayTestOutboundResponse("{\"success\":true,\"msg\":\"\",\"obj\":\"{\\\"delay\\\":50}\"}");
    CHECK(r && r->success == 1, "xray test outbound response success");
    CHECK(r && r->obj && strstr(r->obj, "delay") != NULL, "xray test outbound response obj");
    jsonXrayTestOutboundResponseStructDelete(r);
}

static void test_xray_test_outbounds(void) {
    struct jsonXrayTestOutboundsPostStruct* post = calloc(1, sizeof(struct jsonXrayTestOutboundsPostStruct));
    post->outbounds = strdup("[{\"tag\":\"proxy1\"},{\"tag\":\"proxy2\"}]");
    post->allOutbounds = strdup("[{\"tag\":\"proxy1\"},{\"tag\":\"proxy2\"}]");
    post->mode = strdup("real");
    const char* s = jsonXrayTestOutboundsPost(post);
    CHECK(s && strstr(s, "outbounds=") != NULL, "xray test outbounds post outbounds");
    CHECK(s && strstr(s, "mode=real") != NULL, "xray test outbounds post mode");
    free((char*)s);
    jsonXrayTestOutboundsPostStructDelete(post);

    struct jsonXrayTestOutboundsResponseStruct* r = jsonXrayTestOutboundsResponse("{\"success\":true,\"msg\":\"\",\"obj\":\"[{\\\"tag\\\":\\\"proxy1\\\",\\\"delay\\\":50}]\"}");
    CHECK(r && r->success == 1, "xray test outbounds response success");
    CHECK(r && r->obj && strstr(r->obj, "proxy1") != NULL, "xray test outbounds response obj");
    jsonXrayTestOutboundsResponseStructDelete(r);
}

static void test_xray_balancer_status(void) {
    struct jsonXrayBalancerStatusPostStruct* post = calloc(1, sizeof(struct jsonXrayBalancerStatusPostStruct));
    post->tags = strdup("b1,b2");
    const char* s = jsonXrayBalancerStatusPost(post);
    CHECK(s && strstr(s, "tags=b1%2Cb2") != NULL, "xray balancer status post");
    free((char*)s);
    jsonXrayBalancerStatusPostStructDelete(post);

    struct jsonXrayBalancerStatusResponseStruct* r = jsonXrayBalancerStatusResponse("{\"success\":true,\"msg\":\"\",\"obj\":\"{\\\"b1\\\":\\\"proxy1\\\"}\"}");
    CHECK(r && r->success == 1, "xray balancer status response success");
    CHECK(r && r->obj && strstr(r->obj, "b1") != NULL, "xray balancer status response obj");
    jsonXrayBalancerStatusResponseStructDelete(r);
}

static void test_xray_balancer_override(void) {
    struct jsonXrayBalancerOverridePostStruct* post = calloc(1, sizeof(struct jsonXrayBalancerOverridePostStruct));
    post->tag = strdup("b1");
    post->target = strdup("proxy1");
    const char* s = jsonXrayBalancerOverridePost(post);
    CHECK(s && strstr(s, "tag=b1") != NULL, "xray balancer override post tag");
    CHECK(s && strstr(s, "target=proxy1") != NULL, "xray balancer override post target");
    free((char*)s);
    jsonXrayBalancerOverridePostStructDelete(post);

    struct jsonXrayBalancerOverrideResponseStruct* r = jsonXrayBalancerOverrideResponse("{\"success\":true,\"msg\":\"overridden\"}");
    CHECK(r && r->success == 1 && r->msg && strcmp(r->msg, "overridden") == 0, "xray balancer override response");
    jsonXrayBalancerOverrideResponseStructDelete(r);
}

static void test_xray_route_test(void) {
    struct jsonXrayRouteTestPostStruct* post = calloc(1, sizeof(struct jsonXrayRouteTestPostStruct));
    post->domain = strdup("example.com");
    post->ip = strdup("1.2.3.4");
    post->port = 443;
    post->network = strdup("tcp");
    post->inboundTag = strdup("in-443");
    post->protocol = strdup("http");
    post->email = strdup("user@example.com");
    const char* s = jsonXrayRouteTestPost(post);
    CHECK(s && strstr(s, "domain=example.com") != NULL, "xray route test post domain");
    CHECK(s && strstr(s, "ip=1.2.3.4") != NULL, "xray route test post ip");
    CHECK(s && strstr(s, "port=443") != NULL, "xray route test post port");
    CHECK(s && strstr(s, "network=tcp") != NULL, "xray route test post network");
    CHECK(s && strstr(s, "inboundTag=in-443") != NULL, "xray route test post inboundTag");
    CHECK(s && strstr(s, "protocol=http") != NULL, "xray route test post protocol");
    CHECK(s && strstr(s, "email=user%40example.com") != NULL, "xray route test post email");
    free((char*)s);
    jsonXrayRouteTestPostStructDelete(post);

    struct jsonXrayRouteTestResponseStruct* r = jsonXrayRouteTestResponse("{\"success\":true,\"msg\":\"\",\"obj\":\"{\\\"tag\\\":\\\"proxy1\\\"}\"}");
    CHECK(r && r->success == 1, "xray route test response success");
    CHECK(r && r->obj && strstr(r->obj, "proxy1") != NULL, "xray route test response obj");
    jsonXrayRouteTestResponseStructDelete(r);
}

static void test_xray_geodata_categories_query(void) {
    struct jsonXrayGeoDataCategoriesQueryStruct* query = calloc(1, sizeof(struct jsonXrayGeoDataCategoriesQueryStruct));
    query->file = strdup("geosite.dat");
    query->q = strdup("google");
    query->offset = 10;
    query->limit = 100;
    const char* s = jsonXrayGeoDataCategoriesQueryString(query);
    CHECK(s && strstr(s, "file=geosite.dat") != NULL, "geodata categories query file");
    CHECK(s && strstr(s, "q=google") != NULL, "geodata categories query q");
    CHECK(s && strstr(s, "offset=10") != NULL, "geodata categories query offset");
    CHECK(s && strstr(s, "limit=100") != NULL, "geodata categories query limit");
    free((char*)s);
    jsonXrayGeoDataCategoriesQueryStructDelete(query);
}

static void test_xray_geodata_entries_query(void) {
    struct jsonXrayGeoDataEntriesQueryStruct* query = calloc(1, sizeof(struct jsonXrayGeoDataEntriesQueryStruct));
    query->file = strdup("geosite.dat");
    query->code = strdup("google");
    query->q = strdup("example");
    query->offset = 5;
    query->limit = 50;
    const char* s = jsonXrayGeoDataEntriesQueryString(query);
    CHECK(s && strstr(s, "file=geosite.dat") != NULL, "geodata entries query file");
    CHECK(s && strstr(s, "code=google") != NULL, "geodata entries query code");
    CHECK(s && strstr(s, "q=example") != NULL, "geodata entries query q");
    CHECK(s && strstr(s, "offset=5") != NULL, "geodata entries query offset");
    CHECK(s && strstr(s, "limit=50") != NULL, "geodata entries query limit");
    free((char*)s);
    jsonXrayGeoDataEntriesQueryStructDelete(query);
}

static void test_xray_geodata_validate(void) {
    struct jsonXrayGeoDataValidatePostStruct* post = calloc(1, sizeof(struct jsonXrayGeoDataValidatePostStruct));
    post->tokens = strdup("geosite:google,geosite:blabla");
    post->kind = strdup("domain");
    const char* s = jsonXrayGeoDataValidatePost(post);
    CHECK(s && strstr(s, "tokens=geosite%3Agoogle%2Cgeosite%3Ablabla") != NULL, "geodata validate post tokens");
    CHECK(s && strstr(s, "kind=domain") != NULL, "geodata validate post kind");
    free((char*)s);
    jsonXrayGeoDataValidatePostStructDelete(post);

    struct jsonXrayGeoDataValidateResponseStruct* r = jsonXrayGeoDataValidateResponse("{\"success\":true,\"msg\":\"\",\"obj\":\"[{\\\"token\\\":\\\"geosite:blabla\\\",\\\"reason\\\":\\\"categoryMissing\\\"}]\"}");
    CHECK(r && r->success == 1, "geodata validate response success");
    CHECK(r && r->obj && strstr(r->obj, "categoryMissing") != NULL, "geodata validate response obj");
    jsonXrayGeoDataValidateResponseStructDelete(r);
}

static void test_xray_outbound_subs_create(void) {
    struct jsonXrayOutboundSubsCreatePostStruct* post = calloc(1, sizeof(struct jsonXrayOutboundSubsCreatePostStruct));
    post->remark = strdup("My Subscription");
    post->url = strdup("https://example.com/sub");
    post->tagPrefix = strdup("sub-");
    post->updateInterval = 600;
    post->enabled = 1;
    post->allowPrivate = 0;
    post->allowInsecure = 0;
    post->prepend = 0;
    post->userAgent = strdup("custom-agent/1.0");
    const char* s = jsonXrayOutboundSubsCreatePost(post);
    CHECK(s && strstr(s, "remark=My%20Subscription") != NULL, "outbound subs create remark");
    CHECK(s && strstr(s, "url=https%3A%2F%2Fexample.com%2Fsub") != NULL, "outbound subs create url");
    CHECK(s && strstr(s, "tagPrefix=sub-") != NULL, "outbound subs create tagPrefix");
    CHECK(s && strstr(s, "updateInterval=600") != NULL, "outbound subs create updateInterval");
    CHECK(s && strstr(s, "enabled=true") != NULL, "outbound subs create enabled");
    CHECK(s && strstr(s, "userAgent=custom-agent%2F1.0") != NULL, "outbound subs create userAgent");
    free((char*)s);
    jsonXrayOutboundSubsCreatePostStructDelete(post);

    struct jsonXrayOutboundSubsCreateResponseStruct* r = jsonXrayOutboundSubsCreateResponse("{\"success\":true,\"msg\":\"created\"}");
    CHECK(r && r->success == 1 && r->msg && strcmp(r->msg, "created") == 0, "outbound subs create response");
    jsonXrayOutboundSubsCreateResponseStructDelete(r);
}

static void test_xray_outbound_subs_update(void) {
    struct jsonXrayOutboundSubsUpdatePostStruct* post = calloc(1, sizeof(struct jsonXrayOutboundSubsUpdatePostStruct));
    post->remark = strdup("Updated");
    post->url = strdup("https://example.com/sub2");
    post->tagPrefix = strdup("sub2-");
    post->updateInterval = 300;
    post->enabled = 1;
    post->allowPrivate = 1;
    post->allowInsecure = 1;
    post->prepend = 1;
    post->userAgent = strdup("custom-agent/2.0");
    const char* s = jsonXrayOutboundSubsUpdatePost(post);
    CHECK(s && strstr(s, "remark=Updated") != NULL, "outbound subs update remark");
    CHECK(s && strstr(s, "userAgent=custom-agent%2F2.0") != NULL, "outbound subs update userAgent");
    free((char*)s);
    jsonXrayOutboundSubsUpdatePostStructDelete(post);

    struct jsonXrayOutboundSubsUpdateResponseStruct* r = jsonXrayOutboundSubsUpdateResponse("{\"success\":true,\"msg\":\"updated\"}");
    CHECK(r && r->success == 1 && r->msg && strcmp(r->msg, "updated") == 0, "outbound subs update response");
    jsonXrayOutboundSubsUpdateResponseStructDelete(r);
}

static void test_xray_outbound_subs_list(void) {
    struct jsonXrayOutboundSubsListResponseStruct* r = jsonXrayOutboundSubsListResponse("{\"success\":true,\"msg\":\"\",\"obj\":\"[{\\\"remark\\\":\\\"sub1\\\",\\\"url\\\":\\\"https://example.com/1\\\"}]\"}");
    CHECK(r && r->success == 1, "outbound subs list success");
    CHECK(r && r->obj && strstr(r->obj, "sub1") != NULL, "outbound subs list obj");
    jsonXrayOutboundSubsListResponseStructDelete(r);
}

static void test_xray_outbound_subs_delete(void) {
    struct jsonXrayOutboundSubsDeleteResponseStruct* r = jsonXrayOutboundSubsDeleteResponse("{\"success\":true,\"msg\":\"deleted\"}");
    CHECK(r && r->success == 1 && r->msg && strcmp(r->msg, "deleted") == 0, "outbound subs delete response");
    jsonXrayOutboundSubsDeleteResponseStructDelete(r);
}

static void test_xray_outbound_subs_refresh(void) {
    struct jsonXrayOutboundSubsRefreshResponseStruct* r = jsonXrayOutboundSubsRefreshResponse("{\"success\":true,\"msg\":\"\",\"obj\":\"[{\\\"tag\\\":\\\"sub-1\\\"}]\"}");
    CHECK(r && r->success == 1, "outbound subs refresh success");
    CHECK(r && r->obj && strstr(r->obj, "sub-1") != NULL, "outbound subs refresh obj");
    jsonXrayOutboundSubsRefreshResponseStructDelete(r);
}

static void test_xray_outbound_subs_move(void) {
    struct jsonXrayOutboundSubsMovePostStruct* post = calloc(1, sizeof(struct jsonXrayOutboundSubsMovePostStruct));
    post->dir = strdup("up");
    const char* s = jsonXrayOutboundSubsMovePost(post);
    CHECK(s && strstr(s, "dir=up") != NULL, "outbound subs move post");
    free((char*)s);
    jsonXrayOutboundSubsMovePostStructDelete(post);

    struct jsonXrayOutboundSubsMoveResponseStruct* r = jsonXrayOutboundSubsMoveResponse("{\"success\":true,\"msg\":\"moved\"}");
    CHECK(r && r->success == 1 && r->msg && strcmp(r->msg, "moved") == 0, "outbound subs move response");
    jsonXrayOutboundSubsMoveResponseStructDelete(r);
}

static void test_xray_outbound_subs_parse(void) {
    struct jsonXrayOutboundSubsParsePostStruct* post = calloc(1, sizeof(struct jsonXrayOutboundSubsParsePostStruct));
    post->url = strdup("https://example.com/sub");
    post->allowPrivate = 1;
    post->allowInsecure = 1;
    post->userAgent = strdup("parser-agent/1.0");
    const char* s = jsonXrayOutboundSubsParsePost(post);
    CHECK(s && strstr(s, "url=https%3A%2F%2Fexample.com%2Fsub") != NULL, "outbound subs parse url");
    CHECK(s && strstr(s, "allowPrivate=true") != NULL, "outbound subs parse allowPrivate");
    CHECK(s && strstr(s, "userAgent=parser-agent%2F1.0") != NULL, "outbound subs parse userAgent");
    free((char*)s);
    jsonXrayOutboundSubsParsePostStructDelete(post);

    struct jsonXrayOutboundSubsParseResponseStruct* r = jsonXrayOutboundSubsParseResponse("{\"success\":true,\"msg\":\"\",\"obj\":\"[{\\\"tag\\\":\\\"sub-1\\\"}]\"}");
    CHECK(r && r->success == 1, "outbound subs parse success");
    CHECK(r && r->obj && strstr(r->obj, "sub-1") != NULL, "outbound subs parse obj");
    jsonXrayOutboundSubsParseResponseStructDelete(r);
}

int main(void) {
    test_xray_config_response();
    test_xray_get_default_json_config();
    test_xray_get_outbounds_traffic();
    test_xray_get_xray_result();
    test_xray_update_post();
    test_xray_warp_post();
    test_xray_nord_post();
    test_xray_pia_post();
    test_xray_reset_outbounds_traffic();
    test_xray_test_outbound();
    test_xray_test_outbounds();
    test_xray_balancer_status();
    test_xray_balancer_override();
    test_xray_route_test();
    test_xray_geodata_categories_query();
    test_xray_geodata_entries_query();
    test_xray_geodata_validate();
    test_xray_outbound_subs_create();
    test_xray_outbound_subs_update();
    test_xray_outbound_subs_list();
    test_xray_outbound_subs_delete();
    test_xray_outbound_subs_refresh();
    test_xray_outbound_subs_move();
    test_xray_outbound_subs_parse();

    if (failures) {
        printf("XRAY SETTINGS TESTS FAILED: %d\n", failures);
        return 1;
    }
    printf("XRAY SETTINGS TESTS PASSED\n");
    return 0;
}