#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cjson/subscription-server.h"

static int failures = 0;

#define CHECK(cond, name) do { if (cond) { printf("OK %s\n", name); } else { printf("FAILED %s\n", name); failures++; } } while (0)

static void test_sub_server_get_response(void) {
    const char* json = "{\"success\":true,\"msg\":\"\",\"obj\":\"{\\\"traffic\\\":100}\"}";

    struct jsonSubServerGetResponseStruct* r = jsonSubServerGetResponse(json);
    CHECK(r && r->success == 1, "sub server get response success");
    CHECK(r && r->msg && strcmp(r->msg, "") == 0, "sub server get response msg");
    CHECK(r && r->obj && strstr(r->obj, "traffic") != NULL, "sub server get response obj");
    jsonSubServerGetResponseStructDelete(r);

    struct jsonSubServerGetResponseStruct* fail = jsonSubServerGetResponse("{\"success\":false,\"msg\":\"not found\"}");
    CHECK(fail && fail->success == 0 && fail->msg && strcmp(fail->msg, "not found") == 0, "sub server get response failure");
    jsonSubServerGetResponseStructDelete(fail);
}

static void test_sub_server_json_response(void) {
    const char* json = "{\"success\":true,\"msg\":\"\",\"obj\":\"[{\\\"tag\\\":\\\"proxy1\\\"}]\"}";

    struct jsonSubServerJsonResponseStruct* r = jsonSubServerJsonResponse(json);
    CHECK(r && r->success == 1, "sub server json response success");
    CHECK(r && r->msg && strcmp(r->msg, "") == 0, "sub server json response msg");
    CHECK(r && r->obj && strstr(r->obj, "proxy1") != NULL, "sub server json response obj");
    jsonSubServerJsonResponseStructDelete(r);
}

static void test_sub_server_clash_response(void) {
    const char* json = "{\"success\":true,\"msg\":\"\",\"obj\":\"proxies:\\n  - name: proxy1\"}";

    struct jsonSubServerClashResponseStruct* r = jsonSubServerClashResponse(json);
    CHECK(r && r->success == 1, "sub server clash response success");
    CHECK(r && r->msg && strcmp(r->msg, "") == 0, "sub server clash response msg");
    CHECK(r && r->obj && strstr(r->obj, "proxies") != NULL, "sub server clash response obj");
    jsonSubServerClashResponseStructDelete(r);
}

static void test_sub_server_hwid_status_response(void) {
    const char* json = "{\"success\":true,\"msg\":\"\",\"obj\":\"{\\\"active\\\":true,\\\"full\\\":false,\\\"limit\\\":2,\\\"registered\\\":1,\\\"remaining\\\":1}\"}";

    struct jsonSubServerHwidStatusResponseStruct* r = jsonSubServerHwidStatusResponse(json);
    CHECK(r && r->success == 1, "sub server hwid status response success");
    CHECK(r && r->msg && strcmp(r->msg, "") == 0, "sub server hwid status response msg");
    CHECK(r && r->obj && strstr(r->obj, "active") != NULL, "sub server hwid status response obj");
    jsonSubServerHwidStatusResponseStructDelete(r);

    struct jsonSubServerHwidStatusResponseStruct* fail = jsonSubServerHwidStatusResponse("{\"success\":false,\"msg\":\"not found\"}");
    CHECK(fail && fail->success == 0 && fail->msg && strcmp(fail->msg, "not found") == 0, "sub server hwid status response failure");
    jsonSubServerHwidStatusResponseStructDelete(fail);
}

static void test_sub_server_get_query_string(void) {
    struct jsonSubServerGetQueryStruct* query = calloc(1, sizeof(struct jsonSubServerGetQueryStruct));
    query->format = strdup("info");
    const char* s = jsonSubServerGetQueryString(query);
    CHECK(s && strcmp(s, "format=info") == 0, "sub server get query string");
    free((char*)s);
    jsonSubServerGetQueryStructDelete(query);

    struct jsonSubServerGetQueryStruct* query2 = calloc(1, sizeof(struct jsonSubServerGetQueryStruct));
    const char* s2 = jsonSubServerGetQueryString(query2);
    CHECK(s2 == NULL || s2[0] == '\0', "sub server get query string empty");
    if (s2) free((char*)s2);
    jsonSubServerGetQueryStructDelete(query2);
}

int main(void) {
    test_sub_server_get_response();
    test_sub_server_json_response();
    test_sub_server_clash_response();
    test_sub_server_hwid_status_response();
    test_sub_server_get_query_string();

    if (failures) {
        printf("SUBSCRIPTION SERVER TESTS FAILED: %d\n", failures);
        return 1;
    }
    printf("SUBSCRIPTION SERVER TESTS PASSED\n");
    return 0;
}