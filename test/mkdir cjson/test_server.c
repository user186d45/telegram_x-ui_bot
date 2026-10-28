#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cjson/server.h"
#include <cjson/cJSON.h>
#include "../../include/log.h"

static int failures = 0;

#define CHECK(cond, name) do { if (cond) { printf("OK %s\n", name); } else { printf("FAILED %s\n", name); failures++; } } while (0)

// jsonBulkStringArray helpers (copied from clients.c since they're static there)
int jsonBulkStringArrayParse(cJSON* arr, const char*** strArr, int64_t* strCount) {
    size_t arraySize = cJSON_GetArraySize(arr);
    if (!arraySize) {
        return 1;
    }

    *strArr = (const char**)calloc(arraySize, sizeof(const char*));
    if (!*strArr) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "strArr is a null pointer, failed to allocate memory");
        return 0;
    }
    *strCount = (int64_t)arraySize;

    for (size_t i = 0; i < arraySize; i++) {
        cJSON* arrItem = cJSON_GetArrayItem(arr, i);
        if (!cJSON_IsString(arrItem)) {
            continue;
        }

        size_t itemLen = strlen(arrItem->valuestring);
        char* itemCopy = (char*)malloc((itemLen + 1) * sizeof(char));
        if (!itemCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "itemCopy is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(itemCopy, arrItem->valuestring, itemLen);
        itemCopy[itemLen] = '\0';
        (*strArr)[i] = itemCopy;
    }

    return 1;
}

void jsonBulkStringArrayFree(const char** strArr, int64_t strCount) {
    if (!strArr) {
        return;
    }

    for (int64_t i = 0; i < strCount; i++) {
        free((char*)strArr[i]);
    }

    free((char**)strArr);
}

static void test_openapi_response(void) {
    const char* json = "{\"success\":true,\"msg\":\"\",\"obj\":{\"openapi\":\"3.0.0\",\"info\":{\"title\":\"3x-ui API\",\"version\":\"1.0\"}}}";

    struct jsonOpenApiResponseStruct* r = jsonOpenApiResponse(json);
    CHECK(r && r->success == 1, "openapi response success");
    CHECK(r && r->msg && strcmp(r->msg, "") == 0, "openapi response msg");
    jsonOpenApiResponseStructDelete(r);
}

static void test_server_status_response(void) {
    const char* json = "{\"success\":true,\"msg\":\"\",\"obj\":{\"cpu\":10.5,\"cpuCores\":8,\"logicalPro\":16,\"cpuSpeedMhz\":3000,\"mem\":{\"current\":8000000000,\"total\":16000000000},\"swap\":{\"current\":500000500,\"total\":2000000000},\"disk\":{\"current\":200000000000,\"total\":500000000000},\"diskIO\":{\"read\":1000000,\"write\":2000000},\"diskTraffic\":{\"read\":500000,\"write\":1000000},\"netIO\":{\"up\":1000000,\"down\":2000000,\"pktUp\":1000,\"pktDown\":2000},\"netTraffic\":{\"sent\":500000,\"recv\":1000000,\"pktSent\":500,\"pktRecv\":1000},\"publicIP\":{\"ipv4\":\"1.2.3.4\",\"ipv6\":\"N/A\"},\"panelVersion\":\"3.6.0\",\"panelGuid\":\"guid-123\",\"uptime\":86400,\"tcpCount\":10,\"udpCount\":5,\"load\":[0.5,0.3,0.2],\"xray\":{\"state\":\"running\",\"errorMsg\":\"\",\"version\":\"v25.10.31\"},\"appStats\":{\"threads\":50,\"mem\":100000000,\"uptime\":86400}}}";

    struct jsonServerStatusResponseStruct* r = jsonServerStatusResponse(json);
    CHECK(r && r->success == 1, "server status response success");
    CHECK(r && r->msg && strcmp(r->msg, "") == 0, "server status response msg");
    CHECK(r && r->srvStatusObjStruct != NULL, "server status has obj");
    if (r && r->srvStatusObjStruct) {
        CHECK(r->srvStatusObjStruct->cpu == 10.5, "server status cpu");
        CHECK(r->srvStatusObjStruct->cpuCores == 8, "server status cpuCores");
        CHECK(r->srvStatusObjStruct->srvStatusObjMemObjStruct && r->srvStatusObjStruct->srvStatusObjMemObjStruct->total == 16000000000, "server status mem total");
        CHECK(r->srvStatusObjStruct->srvStatusObjMemObjStruct && r->srvStatusObjStruct->srvStatusObjMemObjStruct->current == 8000000000, "server status mem current");
        CHECK(r->srvStatusObjStruct->srvStatusObjSwapObjStruct && r->srvStatusObjStruct->srvStatusObjSwapObjStruct->total == 2000000000, "server status swap total");
        CHECK(r->srvStatusObjStruct->srvStatusObjSwapObjStruct && r->srvStatusObjStruct->srvStatusObjSwapObjStruct->current == 500000500, "server status swap current");
        CHECK(r->srvStatusObjStruct->srvStatusObjDiskObjStruct && r->srvStatusObjStruct->srvStatusObjDiskObjStruct->total == 500000000000, "server status disk total");
        CHECK(r->srvStatusObjStruct->srvStatusObjDiskObjStruct && r->srvStatusObjStruct->srvStatusObjDiskObjStruct->current == 200000000000, "server status disk current");
        CHECK(r->srvStatusObjStruct->srvStatusObjDiskIOObjStruct && r->srvStatusObjStruct->srvStatusObjDiskIOObjStruct->read == 1000000, "server status diskIO read");
        CHECK(r->srvStatusObjStruct->srvStatusObjDiskIOObjStruct && r->srvStatusObjStruct->srvStatusObjDiskIOObjStruct->write == 2000000, "server status diskIO write");
        CHECK(r->srvStatusObjStruct->srvStatusObjDiskTrafficObjStruct && r->srvStatusObjStruct->srvStatusObjDiskTrafficObjStruct->read == 500000, "server status diskTraffic read");
        CHECK(r->srvStatusObjStruct->srvStatusObjDiskTrafficObjStruct && r->srvStatusObjStruct->srvStatusObjDiskTrafficObjStruct->write == 1000000, "server status diskTraffic write");
        CHECK(r->srvStatusObjStruct->srvStatusObjNetIOObjStruct && r->srvStatusObjStruct->srvStatusObjNetIOObjStruct->up == 1000000, "server status netIO up");
        CHECK(r->srvStatusObjStruct->srvStatusObjNetIOObjStruct && r->srvStatusObjStruct->srvStatusObjNetIOObjStruct->down == 2000000, "server status netIO down");
        CHECK(r->srvStatusObjStruct->srvStatusObjNetIOObjStruct && r->srvStatusObjStruct->srvStatusObjNetIOObjStruct->pktUp == 1000, "server status netIO pktUp");
        CHECK(r->srvStatusObjStruct->srvStatusObjNetIOObjStruct && r->srvStatusObjStruct->srvStatusObjNetIOObjStruct->pktDown == 2000, "server status netIO pktDown");
        CHECK(r->srvStatusObjStruct->srvStatusObjNetTrafficObjStruct && r->srvStatusObjStruct->srvStatusObjNetTrafficObjStruct->sent == 500000, "server status netTraffic sent");
        CHECK(r->srvStatusObjStruct->srvStatusObjNetTrafficObjStruct && r->srvStatusObjStruct->srvStatusObjNetTrafficObjStruct->recv == 1000000, "server status netTraffic recv");
        CHECK(r->srvStatusObjStruct->srvStatusObjNetTrafficObjStruct && r->srvStatusObjStruct->srvStatusObjNetTrafficObjStruct->pktSent == 500, "server status netTraffic pktSent");
        CHECK(r->srvStatusObjStruct->srvStatusObjNetTrafficObjStruct && r->srvStatusObjStruct->srvStatusObjNetTrafficObjStruct->pktRecv == 1000, "server status netTraffic pktRecv");
        CHECK(r->srvStatusObjStruct->srvStatusObjPublicIPObjStruct && r->srvStatusObjStruct->srvStatusObjPublicIPObjStruct->ipv4 && strcmp(r->srvStatusObjStruct->srvStatusObjPublicIPObjStruct->ipv4, "1.2.3.4") == 0, "server status publicIP ipv4");
        CHECK(r->srvStatusObjStruct->srvStatusObjAppStatsObjStruct && r->srvStatusObjStruct->srvStatusObjAppStatsObjStruct->threads == 50, "server status appStats threads");
        CHECK(r->srvStatusObjStruct->srvStatusObjAppStatsObjStruct && r->srvStatusObjStruct->srvStatusObjAppStatsObjStruct->mem == 100000000, "server status appStats mem");
        CHECK(r->srvStatusObjStruct->srvStatusObjAppStatsObjStruct && r->srvStatusObjStruct->srvStatusObjAppStatsObjStruct->uptime == 86400, "server status appStats uptime");
        CHECK(r->srvStatusObjStruct->srvStatusObjXrayObjStruct && r->srvStatusObjStruct->srvStatusObjXrayObjStruct->state && strcmp(r->srvStatusObjStruct->srvStatusObjXrayObjStruct->state, "running") == 0, "server status xray state");
        CHECK(r->srvStatusObjStruct->srvStatusObjLoadObjStruct && r->srvStatusObjStruct->srvStatusObjLoadObjStruct->loads && r->srvStatusObjStruct->srvStatusObjLoadObjStruct->loads[0] == 0.5, "server status load loads[0]");
        CHECK(r->srvStatusObjStruct->panelVersion && strcmp(r->srvStatusObjStruct->panelVersion, "3.6.0") == 0, "server status panelVersion");
        CHECK(r->srvStatusObjStruct->uptime == 86400, "server status uptime");
    }
    jsonServerStatusResponseStructDelete(r);
}

static void test_server_fail2ban_status(void) {
    const char* json = "{\"success\":true,\"msg\":\"\",\"obj\":{\"enabled\":true,\"installed\":true,\"usable\":true,\"windows\":false}}";

    struct jsonServerFail2banStatusResponseStruct* r = jsonServerFail2banStatusResponse(json);
    CHECK(r && r->success == 1, "fail2ban status response success");
    CHECK(r && r->msg && strcmp(r->msg, "") == 0, "fail2ban status response msg");
    CHECK(r && r->fail2banStatusObjStruct && r->fail2banStatusObjStruct->enabled == 1, "fail2ban enabled");
    jsonServerFail2banStatusResponseStructDelete(r);
}

static void test_server_cpu_history(void) {
    const char* json = "{\"success\":true,\"msg\":\"\",\"obj\":[{\"cpu\":10.5,\"t\":1735689600000},{\"cpu\":12.3,\"t\":1735689660000}]}";

    struct jsonServerCpuHistoryResponseStruct* r = jsonServerCpuHistoryResponse(json);
    CHECK(r && r->success == 1, "cpu history response success");
    CHECK(r && r->msg && strcmp(r->msg, "") == 0, "cpu history response msg");
    CHECK(r && r->cpuHistoryObjArrStruct != NULL, "cpu history has obj array");
    CHECK(r && r->jsonServerCpuHistoryObjectArrayStructSize == 2, "cpu history array size");
    if (r && r->cpuHistoryObjArrStruct) {
        CHECK(r->cpuHistoryObjArrStruct[0].cpu == 10.5, "cpu history usage");
        CHECK(r->cpuHistoryObjArrStruct[0].t == 1735689600000, "cpu history timestamp");
        CHECK(r->cpuHistoryObjArrStruct[1].cpu == 12.3, "cpu history usage 2");
        CHECK(r->cpuHistoryObjArrStruct[1].t == 1735689660000, "cpu history timestamp 2");
    }
    jsonServerCpuHistoryResponseStructDelete(r);
}

static void test_server_history(void) {
    const char* json = "{\"success\":true,\"msg\":\"\",\"obj\":[{\"t\":1735689600000,\"v\":10.5},{\"t\":1735689660000,\"v\":12.3}]}";

    struct jsonServerHistoryResponseStruct* r = jsonServerHistoryResponse(json);
    CHECK(r && r->success == 1, "server history response success");
    CHECK(r && r->msg && strcmp(r->msg, "") == 0, "server history response msg");
    CHECK(r && r->srvHistoryObjArrStruct != NULL, "server history has obj array");
    CHECK(r && r->jsonServerHistoryObjectArrayStructSize == 2, "server history array size");
    if (r && r->srvHistoryObjArrStruct) {
        CHECK(r->srvHistoryObjArrStruct[0].v == 10.5, "server history value");
        CHECK(r->srvHistoryObjArrStruct[0].t == 1735689600000, "server history timestamp");
        CHECK(r->srvHistoryObjArrStruct[1].v == 12.3, "server history value 2");
        CHECK(r->srvHistoryObjArrStruct[1].t == 1735689660000, "server history timestamp 2");
    }
    jsonServerHistoryResponseStructDelete(r);
}

static void test_server_xray_metrics_state(void) {
    const char* json = "{\"success\":true,\"msg\":\"\",\"obj\":\"{\\\"metrics\\\":true}\"}";

    struct jsonServerXrayMetricsStateResponseStruct* r = jsonServerXrayMetricsStateResponse(json);
    CHECK(r && r->success == 1, "xray metrics state response success");
    CHECK(r && r->msg && strcmp(r->msg, "") == 0, "xray metrics state response msg");
    jsonServerXrayMetricsStateResponseStructDelete(r);
}

static void test_server_xray_metrics_history(void) {
    const char* json = "{\"success\":true,\"msg\":\"\",\"obj\":\"[{\\\"t\\\":1735689600000,\\\"v\\\":10.5}]\"}";

    struct jsonServerXrayMetricsHistoryResponseStruct* r = jsonServerXrayMetricsHistoryResponse(json);
    CHECK(r && r->success == 1, "xray metrics history response success");
    CHECK(r && r->msg && strcmp(r->msg, "") == 0, "xray metrics history response msg");
    CHECK(r && r->obj && strstr(r->obj, "1735689600000") != NULL, "xray metrics history obj");
    jsonServerXrayMetricsHistoryResponseStructDelete(r);
}

static void test_server_xray_observatory(void) {
    const char* json = "{\"success\":true,\"msg\":\"\",\"obj\":\"{\\\"outbounds\\\":[{\\\"tag\\\":\\\"proxy\\\",\\\"delay\\\":50}]}\"}";

    struct jsonServerXrayObservatoryResponseStruct* r = jsonServerXrayObservatoryResponse(json);
    CHECK(r && r->success == 1, "xray observatory response success");
    CHECK(r && r->msg && strcmp(r->msg, "") == 0, "xray observatory response msg");
    CHECK(r && r->obj && strstr(r->obj, "proxy") != NULL, "xray observatory obj");
    jsonServerXrayObservatoryResponseStructDelete(r);
}

int main(void) {
    test_openapi_response();
    test_server_status_response();
    test_server_fail2ban_status();
    test_server_cpu_history();
    test_server_history();
    test_server_xray_metrics_state();
    test_server_xray_metrics_history();
    test_server_xray_observatory();

    if (failures) {
        printf("SERVER TESTS FAILED: %d\n", failures);
        return 1;
    }
    printf("SERVER TESTS PASSED\n");
    return 0;
}
