#include "../../include/cjson/server.h"
#include "../../include/cjson/jsonValidation.h"
#include "../../include/log.h"

#include <cjson/cJSON.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

static char* jsonCopyText(const char* value) {
    size_t valueLen = strlen(value);
    char* valueCopy = (char*)malloc((valueLen + 1) * sizeof(char));
    if (!valueCopy) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "valueCopy is a null pointer, failed to allocate memory");
        return NULL;
    }
    strncpy(valueCopy, value, valueLen);
    valueCopy[valueLen] = '\0';
    return valueCopy;
}

static int jsonCopyStringItem(cJSON* parent, const char* key, const char** dest) {
    if (!cJSON_HasObjectItem(parent, key) || !cJSON_IsString(cJSON_GetObjectItem(parent, key))) {
        return 1;
    }
    const char* value = cJSON_GetObjectItem(parent, key)->valuestring;
    char* valueCopy = jsonCopyText(value);
    if (!valueCopy) {
        return 0;
    }
    *dest = valueCopy;
    return 1;
}

static const char* jsonCopyMsg(cJSON* jsonParser) {
    const char* msg = NULL;
    jsonCopyStringItem(jsonParser, "msg", &msg);
    return msg;
}

static int jsonCopyBoolItem(cJSON* parent, const char* key, unsigned char* dest) {
    if (!cJSON_HasObjectItem(parent, key) || !cJSON_IsBool(cJSON_GetObjectItem(parent, key))) {
        return 1;
    }
    *dest = cJSON_IsTrue(cJSON_GetObjectItem(parent, key)) ? 1 : 0;
    return 1;
}

static int jsonCopyNumberItem(cJSON* parent, const char* key, int64_t* dest) {
    if (!cJSON_HasObjectItem(parent, key) || !cJSON_IsNumber(cJSON_GetObjectItem(parent, key))) {
        return 1;
    }
    *dest = (int64_t)cJSON_GetObjectItem(parent, key)->valuedouble;
    return 1;
}

static int jsonCopyDoubleItem(cJSON* parent, const char* key, double* dest) {
    if (!cJSON_HasObjectItem(parent, key) || !cJSON_IsNumber(cJSON_GetObjectItem(parent, key))) {
        return 1;
    }
    *dest = cJSON_GetObjectItem(parent, key)->valuedouble;
    return 1;
}


void jsonOpenApiResponseStructDelete(struct jsonOpenApiResponseStruct* openApiRStruct) {
    if (!openApiRStruct) {
        return;
    }
    free((char*)openApiRStruct->msg);
    free(openApiRStruct);
}

struct jsonOpenApiResponseStruct* jsonOpenApiResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonOpenApiResponseStruct* openApiRStruct = (struct jsonOpenApiResponseStruct*)calloc(1, sizeof(struct jsonOpenApiResponseStruct));
        if (!openApiRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "openApiRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        openApiRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &openApiRStruct->msg)) {
            jsonOpenApiResponseStructDelete(openApiRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        openApiRStruct->obj = NULL;

        cJSON_Delete(jsonParser);
        return openApiRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonOpenApiResponseStruct* failRStruct = (struct jsonOpenApiResponseStruct*)calloc(1, sizeof(struct jsonOpenApiResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}


void jsonServerStatusMemObjectStructDelete(struct jsonServerStatusMemObjectStruct* srvStatusObjMemObjStruct) {
    if (!srvStatusObjMemObjStruct) {
        return;
    }
    free(srvStatusObjMemObjStruct);
}

void jsonServerStatusSwapObjectStructDelete(struct jsonServerStatusSwapObjectStruct* srvStatusObjSwapObjStruct) {
    if (!srvStatusObjSwapObjStruct) {
        return;
    }
    free(srvStatusObjSwapObjStruct);
}

void jsonServerStatusDiskObjectStructDelete(struct jsonServerStatusDiskObjectStruct* srvStatusObjDiskObjStruct) {
    if (!srvStatusObjDiskObjStruct) {
        return;
    }
    free(srvStatusObjDiskObjStruct);
}

void jsonServerStatusDiskIOObjectStructDelete(struct jsonServerStatusDiskIOObjectStruct* srvStatusObjDiskIOObjStruct) {
    if (!srvStatusObjDiskIOObjStruct) {
        return;
    }
    free(srvStatusObjDiskIOObjStruct);
}

void jsonServerStatusDiskTrafficObjectStructDelete(struct jsonServerStatusDiskTrafficObjectStruct* srvStatusObjDiskTrafficObjStruct) {
    if (!srvStatusObjDiskTrafficObjStruct) {
        return;
    }
    free(srvStatusObjDiskTrafficObjStruct);
}

void jsonServerStatusNetIOObjectStructDelete(struct jsonServerStatusNetIOObjectStruct* srvStatusObjNetIOObjStruct) {
    if (!srvStatusObjNetIOObjStruct) {
        return;
    }
    free(srvStatusObjNetIOObjStruct);
}

void jsonServerStatusNetTrafficObjectStructDelete(struct jsonServerStatusNetTrafficObjectStruct* srvStatusObjNetTrafficObjStruct) {
    if (!srvStatusObjNetTrafficObjStruct) {
        return;
    }
    free(srvStatusObjNetTrafficObjStruct);
}

void jsonServerStatusPublicIPObjectStructDelete(struct jsonServerStatusPublicIPObjectStruct* srvStatusObjPublicIPObjStruct) {
    if (!srvStatusObjPublicIPObjStruct) {
        return;
    }
    free((char*)srvStatusObjPublicIPObjStruct->ipv4);
    free((char*)srvStatusObjPublicIPObjStruct->ipv6);
    free(srvStatusObjPublicIPObjStruct);
}

void jsonServerStatusAppStatsObjectStructDelete(struct jsonServerStatusAppStatsObjectStruct* srvStatusObjAppStatsObjStruct) {
    if (!srvStatusObjAppStatsObjStruct) {
        return;
    }
    free(srvStatusObjAppStatsObjStruct);
}

void jsonServerStatusXrayObjectStructDelete(struct jsonServerStatusXrayObjectStruct* srvStatusObjXrayObjStruct) {
    if (!srvStatusObjXrayObjStruct) {
        return;
    }
    free((char*)srvStatusObjXrayObjStruct->state);
    free((char*)srvStatusObjXrayObjStruct->errorMsg);
    free((char*)srvStatusObjXrayObjStruct->version);
    free(srvStatusObjXrayObjStruct);
}

void jsonServerStatusLoadObjectStructDelete(struct jsonServerStatusLoadObjectStruct* srvStatusObjLoadObjStruct) {
    if (!srvStatusObjLoadObjStruct) {
        return;
    }
    free(srvStatusObjLoadObjStruct->loads);
    free(srvStatusObjLoadObjStruct);
}









void jsonServerStatusObjectStructDelete(struct jsonServerStatusObjectStruct* srvStatusObjStruct) {
    if (!srvStatusObjStruct) {
        return;
    }
    if (srvStatusObjStruct->srvStatusObjMemObjStruct) {
        jsonServerStatusMemObjectStructDelete(srvStatusObjStruct->srvStatusObjMemObjStruct);
        srvStatusObjStruct->srvStatusObjMemObjStruct = NULL;
    }
    if (srvStatusObjStruct->srvStatusObjSwapObjStruct) {
        jsonServerStatusSwapObjectStructDelete(srvStatusObjStruct->srvStatusObjSwapObjStruct);
        srvStatusObjStruct->srvStatusObjSwapObjStruct = NULL;
    }
    if (srvStatusObjStruct->srvStatusObjDiskObjStruct) {
        jsonServerStatusDiskObjectStructDelete(srvStatusObjStruct->srvStatusObjDiskObjStruct);
        srvStatusObjStruct->srvStatusObjDiskObjStruct = NULL;
    }
    if (srvStatusObjStruct->srvStatusObjDiskIOObjStruct) {
        jsonServerStatusDiskIOObjectStructDelete(srvStatusObjStruct->srvStatusObjDiskIOObjStruct);
        srvStatusObjStruct->srvStatusObjDiskIOObjStruct = NULL;
    }
    if (srvStatusObjStruct->srvStatusObjDiskTrafficObjStruct) {
        jsonServerStatusDiskTrafficObjectStructDelete(srvStatusObjStruct->srvStatusObjDiskTrafficObjStruct);
        srvStatusObjStruct->srvStatusObjDiskTrafficObjStruct = NULL;
    }
    if (srvStatusObjStruct->srvStatusObjNetIOObjStruct) {
        jsonServerStatusNetIOObjectStructDelete(srvStatusObjStruct->srvStatusObjNetIOObjStruct);
        srvStatusObjStruct->srvStatusObjNetIOObjStruct = NULL;
    }
    if (srvStatusObjStruct->srvStatusObjNetTrafficObjStruct) {
        jsonServerStatusNetTrafficObjectStructDelete(srvStatusObjStruct->srvStatusObjNetTrafficObjStruct);
        srvStatusObjStruct->srvStatusObjNetTrafficObjStruct = NULL;
    }
    if (srvStatusObjStruct->srvStatusObjXrayObjStruct) {
        jsonServerStatusXrayObjectStructDelete(srvStatusObjStruct->srvStatusObjXrayObjStruct);
        srvStatusObjStruct->srvStatusObjXrayObjStruct = NULL;
    }
    if (srvStatusObjStruct->srvStatusObjLoadObjStruct) {
        jsonServerStatusLoadObjectStructDelete(srvStatusObjStruct->srvStatusObjLoadObjStruct);
        srvStatusObjStruct->srvStatusObjLoadObjStruct = NULL;
    }
    if (srvStatusObjStruct->srvStatusObjPublicIPObjStruct) {
        jsonServerStatusPublicIPObjectStructDelete(srvStatusObjStruct->srvStatusObjPublicIPObjStruct);
        srvStatusObjStruct->srvStatusObjPublicIPObjStruct = NULL;
    }
    if (srvStatusObjStruct->srvStatusObjAppStatsObjStruct) {
        jsonServerStatusAppStatsObjectStructDelete(srvStatusObjStruct->srvStatusObjAppStatsObjStruct);
        srvStatusObjStruct->srvStatusObjAppStatsObjStruct = NULL;
    }
    if (srvStatusObjStruct->srvStatusObjXrayObjStruct) {
        jsonServerStatusXrayObjectStructDelete(srvStatusObjStruct->srvStatusObjXrayObjStruct);
        srvStatusObjStruct->srvStatusObjXrayObjStruct = NULL;
    }
    free((char*)srvStatusObjStruct->panelVersion);
    free((char*)srvStatusObjStruct->panelGuid);
    free((char*)srvStatusObjStruct->srvStatusObjLoadObjStruct);
    free(srvStatusObjStruct);
}

void jsonServerStatusResponseStructDelete(struct jsonServerStatusResponseStruct* serverStatusRStruct) {
    if (!serverStatusRStruct) {
        return;
    }
    free((char*)serverStatusRStruct->msg);
    if (serverStatusRStruct->srvStatusObjStruct) {
        jsonServerStatusObjectStructDelete(serverStatusRStruct->srvStatusObjStruct);
        serverStatusRStruct->srvStatusObjStruct = NULL;
    }
    free(serverStatusRStruct);
}

static int jsonServerStatusMemObjectStructParse(cJSON* obj, struct jsonServerStatusMemObjectStruct* memStruct) {
    if (!obj) return 0;
    jsonCopyNumberItem(obj, "current", &memStruct->current);
    jsonCopyNumberItem(obj, "total", &memStruct->total);
    return 1;
}

static int jsonServerStatusSwapObjectStructParse(cJSON* obj, struct jsonServerStatusSwapObjectStruct* swapStruct) {
    if (!obj) return 0;
    jsonCopyNumberItem(obj, "current", &swapStruct->current);
    jsonCopyNumberItem(obj, "total", &swapStruct->total);
    return 1;
}

static int jsonServerStatusDiskObjectStructParse(cJSON* obj, struct jsonServerStatusDiskObjectStruct* diskStruct) {
    if (!obj) return 0;
    jsonCopyNumberItem(obj, "current", &diskStruct->current);
    jsonCopyNumberItem(obj, "total", &diskStruct->total);
    return 1;
}

static int jsonServerStatusDiskIOObjectStructParse(cJSON* obj, struct jsonServerStatusDiskIOObjectStruct* diskIOStruct) {
    if (!obj) return 0;
    jsonCopyNumberItem(obj, "read", &diskIOStruct->read);
    jsonCopyNumberItem(obj, "write", &diskIOStruct->write);
    return 1;
}

static int jsonServerStatusDiskTrafficObjectStructParse(cJSON* obj, struct jsonServerStatusDiskTrafficObjectStruct* diskTrafficStruct) {
    if (!obj) return 0;
    jsonCopyNumberItem(obj, "read", &diskTrafficStruct->read);
    jsonCopyNumberItem(obj, "write", &diskTrafficStruct->write);
    return 1;
}

static int jsonServerStatusNetIOObjectStructParse(cJSON* obj, struct jsonServerStatusNetIOObjectStruct* netIOStruct) {
    if (!obj) return 0;
    jsonCopyNumberItem(obj, "up", &netIOStruct->up);
    jsonCopyNumberItem(obj, "down", &netIOStruct->down);
    jsonCopyNumberItem(obj, "pktUp", &netIOStruct->pktUp);
    jsonCopyNumberItem(obj, "pktDown", &netIOStruct->pktDown);
    return 1;
}

static int jsonServerStatusNetTrafficObjectStructParse(cJSON* obj, struct jsonServerStatusNetTrafficObjectStruct* netTrafficStruct) {
    if (!obj) return 0;
    jsonCopyNumberItem(obj, "sent", &netTrafficStruct->sent);
    jsonCopyNumberItem(obj, "recv", &netTrafficStruct->recv);
    jsonCopyNumberItem(obj, "pktSent", &netTrafficStruct->pktSent);
    jsonCopyNumberItem(obj, "pktRecv", &netTrafficStruct->pktRecv);
    return 1;
}

static int jsonServerStatusPublicIPObjectStructParse(cJSON* obj, struct jsonServerStatusPublicIPObjectStruct* publicIPStruct) {
    if (!obj) return 0;
    jsonCopyStringItem(obj, "ipv4", &publicIPStruct->ipv4);
    jsonCopyStringItem(obj, "ipv6", &publicIPStruct->ipv6);
    return 1;
}

static int jsonServerStatusAppStatsObjectStructParse(cJSON* obj, struct jsonServerStatusAppStatsObjectStruct* appStatsStruct) {
    if (!obj) return 0;
    jsonCopyNumberItem(obj, "threads", (int64_t*)&appStatsStruct->threads);
    jsonCopyNumberItem(obj, "mem", &appStatsStruct->mem);
    jsonCopyNumberItem(obj, "uptime", &appStatsStruct->uptime);
    return 1;
}

static int jsonServerStatusXrayObjectStructParse(cJSON* obj, struct jsonServerStatusXrayObjectStruct* xrayStruct) {
    if (!obj) return 0;
    jsonCopyStringItem(obj, "state", &xrayStruct->state);
    jsonCopyStringItem(obj, "errorMsg", &xrayStruct->errorMsg);
    jsonCopyStringItem(obj, "version", &xrayStruct->version);
    return 1;
}

static int jsonServerStatusLoadObjectStructParse(cJSON* obj, struct jsonServerStatusLoadObjectStruct* loadStruct) {
    if (!obj || !cJSON_IsArray(obj)) return 0;
    size_t arraySize = cJSON_GetArraySize(obj);
    if (arraySize != 3) return 0;
    loadStruct->loads = (double*)malloc(arraySize * sizeof(double));
    if (!loadStruct->loads) return 0;
    for (size_t i = 0; i < arraySize; i++) {
        cJSON* item = cJSON_GetArrayItem(obj, i);
        if (cJSON_IsNumber(item)) {
            loadStruct->loads[i] = item->valuedouble;
        }
    }
    return 1;
}









static int jsonServerStatusObjectStructParse(cJSON* obj, struct jsonServerStatusObjectStruct* statusStruct) {
    if (!obj) return 0;
    jsonCopyDoubleItem(obj, "cpu", &statusStruct->cpu);
    jsonCopyNumberItem(obj, "cpuCores", &statusStruct->cpuCores);
    jsonCopyNumberItem(obj, "logicalPro", &statusStruct->logicalPro);
    jsonCopyNumberItem(obj, "cpuSpeedMhz", &statusStruct->cpuSpeedMhz);
    jsonCopyStringItem(obj, "panelVersion", &statusStruct->panelVersion);
    jsonCopyStringItem(obj, "panelGuid", &statusStruct->panelGuid);
    jsonCopyNumberItem(obj, "uptime", &statusStruct->uptime);
    jsonCopyNumberItem(obj, "tcpCount", (int64_t*)&statusStruct->tcpCount);
    jsonCopyNumberItem(obj, "udpCount", (int64_t*)&statusStruct->udpCount);

    if (cJSON_HasObjectItem(obj, "mem") && cJSON_IsObject(cJSON_GetObjectItem(obj, "mem"))) {
        statusStruct->srvStatusObjMemObjStruct = (struct jsonServerStatusMemObjectStruct*)calloc(1, sizeof(struct jsonServerStatusMemObjectStruct));
        if (!statusStruct->srvStatusObjMemObjStruct) return 0;
        jsonServerStatusMemObjectStructParse(cJSON_GetObjectItem(obj, "mem"), statusStruct->srvStatusObjMemObjStruct);
    }
    if (cJSON_HasObjectItem(obj, "swap") && cJSON_IsObject(cJSON_GetObjectItem(obj, "swap"))) {
        statusStruct->srvStatusObjSwapObjStruct = (struct jsonServerStatusSwapObjectStruct*)calloc(1, sizeof(struct jsonServerStatusSwapObjectStruct));
        if (!statusStruct->srvStatusObjSwapObjStruct) return 0;
        jsonServerStatusSwapObjectStructParse(cJSON_GetObjectItem(obj, "swap"), statusStruct->srvStatusObjSwapObjStruct);
    }
    if (cJSON_HasObjectItem(obj, "disk") && cJSON_IsObject(cJSON_GetObjectItem(obj, "disk"))) {
        statusStruct->srvStatusObjDiskObjStruct = (struct jsonServerStatusDiskObjectStruct*)calloc(1, sizeof(struct jsonServerStatusDiskObjectStruct));
        if (!statusStruct->srvStatusObjDiskObjStruct) return 0;
        jsonServerStatusDiskObjectStructParse(cJSON_GetObjectItem(obj, "disk"), statusStruct->srvStatusObjDiskObjStruct);
    }
    if (cJSON_HasObjectItem(obj, "diskIO") && cJSON_IsObject(cJSON_GetObjectItem(obj, "diskIO"))) {
        statusStruct->srvStatusObjDiskIOObjStruct = (struct jsonServerStatusDiskIOObjectStruct*)calloc(1, sizeof(struct jsonServerStatusDiskIOObjectStruct));
        if (!statusStruct->srvStatusObjDiskIOObjStruct) return 0;
        jsonServerStatusDiskIOObjectStructParse(cJSON_GetObjectItem(obj, "diskIO"), statusStruct->srvStatusObjDiskIOObjStruct);
    }
    if (cJSON_HasObjectItem(obj, "diskTraffic") && cJSON_IsObject(cJSON_GetObjectItem(obj, "diskTraffic"))) {
        statusStruct->srvStatusObjDiskTrafficObjStruct = (struct jsonServerStatusDiskTrafficObjectStruct*)calloc(1, sizeof(struct jsonServerStatusDiskTrafficObjectStruct));
        if (!statusStruct->srvStatusObjDiskTrafficObjStruct) return 0;
        jsonServerStatusDiskTrafficObjectStructParse(cJSON_GetObjectItem(obj, "diskTraffic"), statusStruct->srvStatusObjDiskTrafficObjStruct);
    }
    if (cJSON_HasObjectItem(obj, "netIO") && cJSON_IsObject(cJSON_GetObjectItem(obj, "netIO"))) {
        statusStruct->srvStatusObjNetIOObjStruct = (struct jsonServerStatusNetIOObjectStruct*)calloc(1, sizeof(struct jsonServerStatusNetIOObjectStruct));
        if (!statusStruct->srvStatusObjNetIOObjStruct) return 0;
        jsonServerStatusNetIOObjectStructParse(cJSON_GetObjectItem(obj, "netIO"), statusStruct->srvStatusObjNetIOObjStruct);
    }
    if (cJSON_HasObjectItem(obj, "netTraffic") && cJSON_IsObject(cJSON_GetObjectItem(obj, "netTraffic"))) {
        statusStruct->srvStatusObjNetTrafficObjStruct = (struct jsonServerStatusNetTrafficObjectStruct*)calloc(1, sizeof(struct jsonServerStatusNetTrafficObjectStruct));
        if (!statusStruct->srvStatusObjNetTrafficObjStruct) return 0;
        jsonServerStatusNetTrafficObjectStructParse(cJSON_GetObjectItem(obj, "netTraffic"), statusStruct->srvStatusObjNetTrafficObjStruct);
    }
    if (cJSON_HasObjectItem(obj, "xray") && cJSON_IsObject(cJSON_GetObjectItem(obj, "xray"))) {
        statusStruct->srvStatusObjXrayObjStruct = (struct jsonServerStatusXrayObjectStruct*)calloc(1, sizeof(struct jsonServerStatusXrayObjectStruct));
        if (!statusStruct->srvStatusObjXrayObjStruct) return 0;
        jsonServerStatusXrayObjectStructParse(cJSON_GetObjectItem(obj, "xray"), statusStruct->srvStatusObjXrayObjStruct);
    }
    if (cJSON_HasObjectItem(obj, "load") && cJSON_IsArray(cJSON_GetObjectItem(obj, "load"))) {
        statusStruct->srvStatusObjLoadObjStruct = (struct jsonServerStatusLoadObjectStruct*)calloc(1, sizeof(struct jsonServerStatusLoadObjectStruct));
        if (!statusStruct->srvStatusObjLoadObjStruct) return 0;
        jsonServerStatusLoadObjectStructParse(cJSON_GetObjectItem(obj, "load"), statusStruct->srvStatusObjLoadObjStruct);
    }
    if (cJSON_HasObjectItem(obj, "publicIP") && cJSON_IsObject(cJSON_GetObjectItem(obj, "publicIP"))) {
        statusStruct->srvStatusObjPublicIPObjStruct = (struct jsonServerStatusPublicIPObjectStruct*)calloc(1, sizeof(struct jsonServerStatusPublicIPObjectStruct));
        if (!statusStruct->srvStatusObjPublicIPObjStruct) return 0;
        jsonServerStatusPublicIPObjectStructParse(cJSON_GetObjectItem(obj, "publicIP"), statusStruct->srvStatusObjPublicIPObjStruct);
    }
    if (cJSON_HasObjectItem(obj, "appStats") && cJSON_IsObject(cJSON_GetObjectItem(obj, "appStats"))) {
        statusStruct->srvStatusObjAppStatsObjStruct = (struct jsonServerStatusAppStatsObjectStruct*)calloc(1, sizeof(struct jsonServerStatusAppStatsObjectStruct));
        if (!statusStruct->srvStatusObjAppStatsObjStruct) return 0;
        jsonServerStatusAppStatsObjectStructParse(cJSON_GetObjectItem(obj, "appStats"), statusStruct->srvStatusObjAppStatsObjStruct);
    }
    return 1;
}

struct jsonServerStatusResponseStruct* jsonServerStatusResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsObject(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* obj = cJSON_GetObjectItem(jsonParser, "obj");

        struct jsonServerStatusObjectStruct* srvStatusObjStruct = (struct jsonServerStatusObjectStruct*)calloc(1, sizeof(struct jsonServerStatusObjectStruct));
        if (!srvStatusObjStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "srvStatusObjStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        if (!jsonServerStatusObjectStructParse(obj, srvStatusObjStruct)) {
            jsonServerStatusObjectStructDelete(srvStatusObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        struct jsonServerStatusResponseStruct* serverStatusRStruct = (struct jsonServerStatusResponseStruct*)calloc(1, sizeof(struct jsonServerStatusResponseStruct));
        if (!serverStatusRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverStatusRStruct is a null pointer");
            jsonServerStatusObjectStructDelete(srvStatusObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverStatusRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverStatusRStruct->msg)) {
            jsonServerStatusResponseStructDelete(serverStatusRStruct);
            jsonServerStatusObjectStructDelete(srvStatusObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverStatusRStruct->srvStatusObjStruct = srvStatusObjStruct;

        cJSON_Delete(jsonParser);
        return serverStatusRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerStatusResponseStruct* failRStruct = (struct jsonServerStatusResponseStruct*)calloc(1, sizeof(struct jsonServerStatusResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}


void jsonServerFail2banStatusObjectStructDelete(struct jsonServerFail2banStatusObjectStruct* fail2banStatusObjStruct) {
    if (!fail2banStatusObjStruct) {
        return;
    }
    free(fail2banStatusObjStruct);
}

void jsonServerFail2banStatusResponseStructDelete(struct jsonServerFail2banStatusResponseStruct* serverFail2banStatusRStruct) {
    if (!serverFail2banStatusRStruct) {
        return;
    }
    free((char*)serverFail2banStatusRStruct->msg);
    if (serverFail2banStatusRStruct->fail2banStatusObjStruct) {
        jsonServerFail2banStatusObjectStructDelete(serverFail2banStatusRStruct->fail2banStatusObjStruct);
        serverFail2banStatusRStruct->fail2banStatusObjStruct = NULL;
    }
    free(serverFail2banStatusRStruct);
}

struct jsonServerFail2banStatusResponseStruct* jsonServerFail2banStatusResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsObject(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* obj = cJSON_GetObjectItem(jsonParser, "obj");

        struct jsonServerFail2banStatusObjectStruct* fail2banStatusObjStruct = (struct jsonServerFail2banStatusObjectStruct*)calloc(1, sizeof(struct jsonServerFail2banStatusObjectStruct));
        if (!fail2banStatusObjStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "fail2banStatusObjStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        jsonCopyBoolItem(obj, "enabled", &fail2banStatusObjStruct->enabled);
        jsonCopyBoolItem(obj, "installed", &fail2banStatusObjStruct->installed);
        jsonCopyBoolItem(obj, "usable", &fail2banStatusObjStruct->usable);
        jsonCopyBoolItem(obj, "windows", &fail2banStatusObjStruct->windows);

        struct jsonServerFail2banStatusResponseStruct* serverFail2banStatusRStruct = (struct jsonServerFail2banStatusResponseStruct*)calloc(1, sizeof(struct jsonServerFail2banStatusResponseStruct));
        if (!serverFail2banStatusRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverFail2banStatusRStruct is a null pointer");
            jsonServerFail2banStatusObjectStructDelete(fail2banStatusObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverFail2banStatusRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverFail2banStatusRStruct->msg)) {
            jsonServerFail2banStatusResponseStructDelete(serverFail2banStatusRStruct);
            jsonServerFail2banStatusObjectStructDelete(fail2banStatusObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverFail2banStatusRStruct->fail2banStatusObjStruct = fail2banStatusObjStruct;

        cJSON_Delete(jsonParser);
        return serverFail2banStatusRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerFail2banStatusResponseStruct* failRStruct = (struct jsonServerFail2banStatusResponseStruct*)calloc(1, sizeof(struct jsonServerFail2banStatusResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}


void jsonServerCpuHistoryObjectArrayStructDelete(struct jsonServerCpuHistoryObjectArrayStruct* cpuHistoryObjArrStruct, size_t arraySize) {
    if (!cpuHistoryObjArrStruct) {
        return;
    }
    free(cpuHistoryObjArrStruct);
}

void jsonServerCpuHistoryResponseStructDelete(struct jsonServerCpuHistoryResponseStruct* serverCpuHistoryRStruct) {
    if (!serverCpuHistoryRStruct) {
        return;
    }
    free((char*)serverCpuHistoryRStruct->msg);
    if (serverCpuHistoryRStruct->cpuHistoryObjArrStruct) {
        jsonServerCpuHistoryObjectArrayStructDelete(serverCpuHistoryRStruct->cpuHistoryObjArrStruct, serverCpuHistoryRStruct->jsonServerCpuHistoryObjectArrayStructSize);
        serverCpuHistoryRStruct->cpuHistoryObjArrStruct = NULL;
    }
    free(serverCpuHistoryRStruct);
}

static int jsonServerCpuHistoryObjectArrayStructParse(cJSON* obj, struct jsonServerCpuHistoryObjectArrayStruct* cpuHistoryStruct) {
    if (!obj) return 0;
    jsonCopyDoubleItem(obj, "cpu", &cpuHistoryStruct->cpu);
    jsonCopyNumberItem(obj, "t", &cpuHistoryStruct->t);
    return 1;
}

struct jsonServerCpuHistoryResponseStruct* jsonServerCpuHistoryResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsArray(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* objArray = cJSON_GetObjectItem(jsonParser, "obj");

        size_t arraySize = cJSON_GetArraySize(objArray);
        struct jsonServerCpuHistoryObjectArrayStruct* cpuHistoryObjArrStruct = NULL;
        if (arraySize) {
            cpuHistoryObjArrStruct = (struct jsonServerCpuHistoryObjectArrayStruct*)calloc(arraySize, sizeof(struct jsonServerCpuHistoryObjectArrayStruct));
            if (!cpuHistoryObjArrStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "cpuHistoryObjArrStruct is a null pointer");
                cJSON_Delete(jsonParser);
                return NULL;
            }
            for (size_t i = 0; i < arraySize; i++) {
                cJSON* arrItem = cJSON_GetArrayItem(objArray, i);
                if (!jsonServerCpuHistoryObjectArrayStructParse(arrItem, &cpuHistoryObjArrStruct[i])) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Array element is not parsed correctly, skipping...");
                    continue;
                }
            }
        }

        struct jsonServerCpuHistoryResponseStruct* serverCpuHistoryRStruct = (struct jsonServerCpuHistoryResponseStruct*)calloc(1, sizeof(struct jsonServerCpuHistoryResponseStruct));
        if (!serverCpuHistoryRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverCpuHistoryRStruct is a null pointer");
            jsonServerCpuHistoryObjectArrayStructDelete(cpuHistoryObjArrStruct, arraySize);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverCpuHistoryRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverCpuHistoryRStruct->msg)) {
            jsonServerCpuHistoryResponseStructDelete(serverCpuHistoryRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverCpuHistoryRStruct->jsonServerCpuHistoryObjectArrayStructSize = arraySize;
        serverCpuHistoryRStruct->cpuHistoryObjArrStruct = cpuHistoryObjArrStruct;

        cJSON_Delete(jsonParser);
        return serverCpuHistoryRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerCpuHistoryResponseStruct* failRStruct = (struct jsonServerCpuHistoryResponseStruct*)calloc(1, sizeof(struct jsonServerCpuHistoryResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}


void jsonServerHistoryObjectArrayStructDelete(struct jsonServerHistoryObjectArrayStruct* srvHistoryObjArrStruct, size_t arraySize) {
    if (!srvHistoryObjArrStruct) {
        return;
    }
    free(srvHistoryObjArrStruct);
}

void jsonServerHistoryResponseStructDelete(struct jsonServerHistoryResponseStruct* serverHistoryRStruct) {
    if (!serverHistoryRStruct) {
        return;
    }
    free((char*)serverHistoryRStruct->msg);
    if (serverHistoryRStruct->srvHistoryObjArrStruct) {
        jsonServerHistoryObjectArrayStructDelete(serverHistoryRStruct->srvHistoryObjArrStruct, serverHistoryRStruct->jsonServerHistoryObjectArrayStructSize);
        serverHistoryRStruct->srvHistoryObjArrStruct = NULL;
    }
    free(serverHistoryRStruct);
}

static int jsonServerHistoryObjectArrayStructParse(cJSON* obj, struct jsonServerHistoryObjectArrayStruct* historyStruct) {
    if (!obj) return 0;
    jsonCopyNumberItem(obj, "t", &historyStruct->t);
    jsonCopyDoubleItem(obj, "v", &historyStruct->v);
    return 1;
}

struct jsonServerHistoryResponseStruct* jsonServerHistoryResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsArray(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* objArray = cJSON_GetObjectItem(jsonParser, "obj");

        size_t arraySize = cJSON_GetArraySize(objArray);
        struct jsonServerHistoryObjectArrayStruct* srvHistoryObjArrStruct = NULL;
        if (arraySize) {
            srvHistoryObjArrStruct = (struct jsonServerHistoryObjectArrayStruct*)calloc(arraySize, sizeof(struct jsonServerHistoryObjectArrayStruct));
            if (!srvHistoryObjArrStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "srvHistoryObjArrStruct is a null pointer");
                cJSON_Delete(jsonParser);
                return NULL;
            }
            for (size_t i = 0; i < arraySize; i++) {
                cJSON* arrItem = cJSON_GetArrayItem(objArray, i);
                if (!jsonServerHistoryObjectArrayStructParse(arrItem, &srvHistoryObjArrStruct[i])) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Array element is not parsed correctly, skipping...");
                    continue;
                }
            }
        }

        struct jsonServerHistoryResponseStruct* serverHistoryRStruct = (struct jsonServerHistoryResponseStruct*)calloc(1, sizeof(struct jsonServerHistoryResponseStruct));
        if (!serverHistoryRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverHistoryRStruct is a null pointer");
            jsonServerHistoryObjectArrayStructDelete(srvHistoryObjArrStruct, arraySize);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverHistoryRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverHistoryRStruct->msg)) {
            jsonServerHistoryResponseStructDelete(serverHistoryRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverHistoryRStruct->jsonServerHistoryObjectArrayStructSize = arraySize;
        serverHistoryRStruct->srvHistoryObjArrStruct = srvHistoryObjArrStruct;

        cJSON_Delete(jsonParser);
        return serverHistoryRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerHistoryResponseStruct* failRStruct = (struct jsonServerHistoryResponseStruct*)calloc(1, sizeof(struct jsonServerHistoryResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}


void jsonServerXrayMetricsStateResponseStructDelete(struct jsonServerXrayMetricsStateResponseStruct* serverXrayMetricsStateRStruct) {
    if (!serverXrayMetricsStateRStruct) {
        return;
    }
    free((char*)serverXrayMetricsStateRStruct->msg);
    free(serverXrayMetricsStateRStruct);
}

struct jsonServerXrayMetricsStateResponseStruct* jsonServerXrayMetricsStateResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonServerXrayMetricsStateResponseStruct* serverXrayMetricsStateRStruct = (struct jsonServerXrayMetricsStateResponseStruct*)calloc(1, sizeof(struct jsonServerXrayMetricsStateResponseStruct));
        if (!serverXrayMetricsStateRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverXrayMetricsStateRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverXrayMetricsStateRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverXrayMetricsStateRStruct->msg)) {
            jsonServerXrayMetricsStateResponseStructDelete(serverXrayMetricsStateRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverXrayMetricsStateRStruct->obj = NULL;

        cJSON_Delete(jsonParser);
        return serverXrayMetricsStateRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerXrayMetricsStateResponseStruct* failRStruct = (struct jsonServerXrayMetricsStateResponseStruct*)calloc(1, sizeof(struct jsonServerXrayMetricsStateResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

void jsonServerXrayMetricsHistoryResponseStructDelete(struct jsonServerXrayMetricsHistoryResponseStruct* serverXrayMetricsHistoryRStruct) {
    if (!serverXrayMetricsHistoryRStruct) {
        return;
    }
    free((char*)serverXrayMetricsHistoryRStruct->msg);
    free(serverXrayMetricsHistoryRStruct);
}

struct jsonServerXrayMetricsHistoryResponseStruct* jsonServerXrayMetricsHistoryResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonServerXrayMetricsHistoryResponseStruct* serverXrayMetricsHistoryRStruct = (struct jsonServerXrayMetricsHistoryResponseStruct*)calloc(1, sizeof(struct jsonServerXrayMetricsHistoryResponseStruct));
        if (!serverXrayMetricsHistoryRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverXrayMetricsHistoryRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverXrayMetricsHistoryRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverXrayMetricsHistoryRStruct->msg)) {
            jsonServerXrayMetricsHistoryResponseStructDelete(serverXrayMetricsHistoryRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverXrayMetricsHistoryRStruct->obj = NULL;

        cJSON_Delete(jsonParser);
        return serverXrayMetricsHistoryRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerXrayMetricsHistoryResponseStruct* failRStruct = (struct jsonServerXrayMetricsHistoryResponseStruct*)calloc(1, sizeof(struct jsonServerXrayMetricsHistoryResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

void jsonServerXrayObservatoryResponseStructDelete(struct jsonServerXrayObservatoryResponseStruct* serverXrayObservatoryRStruct) {
    if (!serverXrayObservatoryRStruct) {
        return;
    }
    free((char*)serverXrayObservatoryRStruct->msg);
    free(serverXrayObservatoryRStruct);
}

struct jsonServerXrayObservatoryResponseStruct* jsonServerXrayObservatoryResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonServerXrayObservatoryResponseStruct* serverXrayObservatoryRStruct = (struct jsonServerXrayObservatoryResponseStruct*)calloc(1, sizeof(struct jsonServerXrayObservatoryResponseStruct));
        if (!serverXrayObservatoryRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverXrayObservatoryRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverXrayObservatoryRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverXrayObservatoryRStruct->msg)) {
            jsonServerXrayObservatoryResponseStructDelete(serverXrayObservatoryRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverXrayObservatoryRStruct->obj = NULL;

        cJSON_Delete(jsonParser);
        return serverXrayObservatoryRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerXrayObservatoryResponseStruct* failRStruct = (struct jsonServerXrayObservatoryResponseStruct*)calloc(1, sizeof(struct jsonServerXrayObservatoryResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

void jsonServerXrayObservatoryHistoryResponseStructDelete(struct jsonServerXrayObservatoryHistoryResponseStruct* serverXrayObservatoryHistoryRStruct) {
    if (!serverXrayObservatoryHistoryRStruct) {
        return;
    }
    free((char*)serverXrayObservatoryHistoryRStruct->msg);
    free(serverXrayObservatoryHistoryRStruct);
}

struct jsonServerXrayObservatoryHistoryResponseStruct* jsonServerXrayObservatoryHistoryResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonServerXrayObservatoryHistoryResponseStruct* serverXrayObservatoryHistoryRStruct = (struct jsonServerXrayObservatoryHistoryResponseStruct*)calloc(1, sizeof(struct jsonServerXrayObservatoryHistoryResponseStruct));
        if (!serverXrayObservatoryHistoryRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverXrayObservatoryHistoryRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverXrayObservatoryHistoryRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverXrayObservatoryHistoryRStruct->msg)) {
            jsonServerXrayObservatoryHistoryResponseStructDelete(serverXrayObservatoryHistoryRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverXrayObservatoryHistoryRStruct->obj = NULL;

        cJSON_Delete(jsonParser);
        return serverXrayObservatoryHistoryRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerXrayObservatoryHistoryResponseStruct* failRStruct = (struct jsonServerXrayObservatoryHistoryResponseStruct*)calloc(1, sizeof(struct jsonServerXrayObservatoryHistoryResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}


void jsonServerGetXrayVersionResponseStructDelete(struct jsonServerGetXrayVersionResponseStruct* serverGetXrayVersionRStruct) {
    if (!serverGetXrayVersionRStruct) {
        return;
    }
    free((char*)serverGetXrayVersionRStruct->msg);
    if (serverGetXrayVersionRStruct->obj) {
        jsonBulkStringArrayFree(serverGetXrayVersionRStruct->obj, serverGetXrayVersionRStruct->objCount);
        serverGetXrayVersionRStruct->obj = NULL;
    }
    free(serverGetXrayVersionRStruct);
}

struct jsonServerGetXrayVersionResponseStruct* jsonServerGetXrayVersionResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonServerGetXrayVersionResponseStruct* serverGetXrayVersionRStruct = (struct jsonServerGetXrayVersionResponseStruct*)calloc(1, sizeof(struct jsonServerGetXrayVersionResponseStruct));
        if (!serverGetXrayVersionRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverGetXrayVersionRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetXrayVersionRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverGetXrayVersionRStruct->msg)) {
            jsonServerGetXrayVersionResponseStructDelete(serverGetXrayVersionRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsArray(cJSON_GetObjectItem(jsonParser, "obj"))) {
            if (!jsonBulkStringArrayParse(cJSON_GetObjectItem(jsonParser, "obj"), &serverGetXrayVersionRStruct->obj, &serverGetXrayVersionRStruct->objCount)) {
                jsonServerGetXrayVersionResponseStructDelete(serverGetXrayVersionRStruct);
                cJSON_Delete(jsonParser);
                return NULL;
            }
        }

        cJSON_Delete(jsonParser);
        return serverGetXrayVersionRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerGetXrayVersionResponseStruct* failRStruct = (struct jsonServerGetXrayVersionResponseStruct*)calloc(1, sizeof(struct jsonServerGetXrayVersionResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}


void jsonServerGetPanelUpdateInfoResponseStructDelete(struct jsonServerGetPanelUpdateInfoResponseStruct* serverGetPanelUpdateInfoRStruct) {
    if (!serverGetPanelUpdateInfoRStruct) {
        return;
    }
    free((char*)serverGetPanelUpdateInfoRStruct->msg);
    free(serverGetPanelUpdateInfoRStruct);
}

struct jsonServerGetPanelUpdateInfoResponseStruct* jsonServerGetPanelUpdateInfoResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonServerGetPanelUpdateInfoResponseStruct* serverGetPanelUpdateInfoRStruct = (struct jsonServerGetPanelUpdateInfoResponseStruct*)calloc(1, sizeof(struct jsonServerGetPanelUpdateInfoResponseStruct));
        if (!serverGetPanelUpdateInfoRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverGetPanelUpdateInfoRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetPanelUpdateInfoRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverGetPanelUpdateInfoRStruct->msg)) {
            jsonServerGetPanelUpdateInfoResponseStructDelete(serverGetPanelUpdateInfoRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetPanelUpdateInfoRStruct->obj = NULL;

        cJSON_Delete(jsonParser);
        return serverGetPanelUpdateInfoRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerGetPanelUpdateInfoResponseStruct* failRStruct = (struct jsonServerGetPanelUpdateInfoResponseStruct*)calloc(1, sizeof(struct jsonServerGetPanelUpdateInfoResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

void jsonServerGetUpdateStatusObjectStructDelete(struct jsonServerGetUpdateStatusObjectStruct* getUpdateStatusObjStruct) {
    if (!getUpdateStatusObjStruct) {
        return;
    }
    free((char*)getUpdateStatusObjStruct->runId);
    free((char*)getUpdateStatusObjStruct->state);
    free(getUpdateStatusObjStruct);
}

void jsonServerGetUpdateStatusResponseStructDelete(struct jsonServerGetUpdateStatusResponseStruct* serverGetUpdateStatusRStruct) {
    if (!serverGetUpdateStatusRStruct) {
        return;
    }
    free((char*)serverGetUpdateStatusRStruct->msg);
    if (serverGetUpdateStatusRStruct->getUpdateStatusObjStruct) {
        jsonServerGetUpdateStatusObjectStructDelete(serverGetUpdateStatusRStruct->getUpdateStatusObjStruct);
        serverGetUpdateStatusRStruct->getUpdateStatusObjStruct = NULL;
    }
    free(serverGetUpdateStatusRStruct);
}

struct jsonServerGetUpdateStatusResponseStruct* jsonServerGetUpdateStatusResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsObject(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* obj = cJSON_GetObjectItem(jsonParser, "obj");

        struct jsonServerGetUpdateStatusObjectStruct* getUpdateStatusObjStruct = (struct jsonServerGetUpdateStatusObjectStruct*)calloc(1, sizeof(struct jsonServerGetUpdateStatusObjectStruct));
        if (!getUpdateStatusObjStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "getUpdateStatusObjStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        jsonCopyNumberItem(obj, "exitCode", (int64_t*)&getUpdateStatusObjStruct->exitCode);
        jsonCopyNumberItem(obj, "finishedAt", &getUpdateStatusObjStruct->finishedAt);
        jsonCopyStringItem(obj, "runId", &getUpdateStatusObjStruct->runId);
        jsonCopyStringItem(obj, "state", &getUpdateStatusObjStruct->state);

        struct jsonServerGetUpdateStatusResponseStruct* serverGetUpdateStatusRStruct = (struct jsonServerGetUpdateStatusResponseStruct*)calloc(1, sizeof(struct jsonServerGetUpdateStatusResponseStruct));
        if (!serverGetUpdateStatusRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverGetUpdateStatusRStruct is a null pointer");
            jsonServerGetUpdateStatusObjectStructDelete(getUpdateStatusObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetUpdateStatusRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverGetUpdateStatusRStruct->msg)) {
            jsonServerGetUpdateStatusResponseStructDelete(serverGetUpdateStatusRStruct);
            jsonServerGetUpdateStatusObjectStructDelete(getUpdateStatusObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetUpdateStatusRStruct->getUpdateStatusObjStruct = getUpdateStatusObjStruct;

        cJSON_Delete(jsonParser);
        return serverGetUpdateStatusRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerGetUpdateStatusResponseStruct* failRStruct = (struct jsonServerGetUpdateStatusResponseStruct*)calloc(1, sizeof(struct jsonServerGetUpdateStatusResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}


void jsonServerGetConfigJsonResponseStructDelete(struct jsonServerGetConfigJsonResponseStruct* serverGetConfigJsonRStruct) {
    if (!serverGetConfigJsonRStruct) {
        return;
    }
    free((char*)serverGetConfigJsonRStruct->msg);
    free(serverGetConfigJsonRStruct);
}

struct jsonServerGetConfigJsonResponseStruct* jsonServerGetConfigJsonResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonServerGetConfigJsonResponseStruct* serverGetConfigJsonRStruct = (struct jsonServerGetConfigJsonResponseStruct*)calloc(1, sizeof(struct jsonServerGetConfigJsonResponseStruct));
        if (!serverGetConfigJsonRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverGetConfigJsonRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetConfigJsonRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverGetConfigJsonRStruct->msg)) {
            jsonServerGetConfigJsonResponseStructDelete(serverGetConfigJsonRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetConfigJsonRStruct->obj = NULL;

        cJSON_Delete(jsonParser);
        return serverGetConfigJsonRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerGetConfigJsonResponseStruct* failRStruct = (struct jsonServerGetConfigJsonResponseStruct*)calloc(1, sizeof(struct jsonServerGetConfigJsonResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

void jsonServerGetDbResponseStructDelete(struct jsonServerGetDbResponseStruct* serverGetDbRStruct) {
    if (!serverGetDbRStruct) {
        return;
    }
    free((char*)serverGetDbRStruct->msg);
    free(serverGetDbRStruct);
}

struct jsonServerGetDbResponseStruct* jsonServerGetDbResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonServerGetDbResponseStruct* serverGetDbRStruct = (struct jsonServerGetDbResponseStruct*)calloc(1, sizeof(struct jsonServerGetDbResponseStruct));
        if (!serverGetDbRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverGetDbRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetDbRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverGetDbRStruct->msg)) {
            jsonServerGetDbResponseStructDelete(serverGetDbRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetDbRStruct->obj = NULL;

        cJSON_Delete(jsonParser);
        return serverGetDbRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerGetDbResponseStruct* failRStruct = (struct jsonServerGetDbResponseStruct*)calloc(1, sizeof(struct jsonServerGetDbResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

void jsonServerGetMigrationResponseStructDelete(struct jsonServerGetMigrationResponseStruct* serverGetMigrationRStruct) {
    if (!serverGetMigrationRStruct) {
        return;
    }
    free((char*)serverGetMigrationRStruct->msg);
    free(serverGetMigrationRStruct);
}

struct jsonServerGetMigrationResponseStruct* jsonServerGetMigrationResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonServerGetMigrationResponseStruct* serverGetMigrationRStruct = (struct jsonServerGetMigrationResponseStruct*)calloc(1, sizeof(struct jsonServerGetMigrationResponseStruct));
        if (!serverGetMigrationRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverGetMigrationRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetMigrationRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverGetMigrationRStruct->msg)) {
            jsonServerGetMigrationResponseStructDelete(serverGetMigrationRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetMigrationRStruct->obj = NULL;

        cJSON_Delete(jsonParser);
        return serverGetMigrationRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerGetMigrationResponseStruct* failRStruct = (struct jsonServerGetMigrationResponseStruct*)calloc(1, sizeof(struct jsonServerGetMigrationResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

void jsonServerGetNewUUIDObjectStructDelete(struct jsonServerGetNewUUIDObjectStruct* getNewUUIDObjStruct) {
    if (!getNewUUIDObjStruct) {
        return;
    }
    free((char*)getNewUUIDObjStruct->uuid);
    free(getNewUUIDObjStruct);
}

void jsonServerGetNewUUIDResponseStructDelete(struct jsonServerGetNewUUIDResponseStruct* serverGetNewUUIDRStruct) {
    if (!serverGetNewUUIDRStruct) {
        return;
    }
    free((char*)serverGetNewUUIDRStruct->msg);
    if (serverGetNewUUIDRStruct->getNewUUIDObjStruct) {
        jsonServerGetNewUUIDObjectStructDelete(serverGetNewUUIDRStruct->getNewUUIDObjStruct);
        serverGetNewUUIDRStruct->getNewUUIDObjStruct = NULL;
    }
    free(serverGetNewUUIDRStruct);
}

struct jsonServerGetNewUUIDResponseStruct* jsonServerGetNewUUIDResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsObject(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* obj = cJSON_GetObjectItem(jsonParser, "obj");

        struct jsonServerGetNewUUIDObjectStruct* getNewUUIDObjStruct = (struct jsonServerGetNewUUIDObjectStruct*)calloc(1, sizeof(struct jsonServerGetNewUUIDObjectStruct));
        if (!getNewUUIDObjStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "getNewUUIDObjStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        jsonCopyStringItem(obj, "uuid", &getNewUUIDObjStruct->uuid);

        struct jsonServerGetNewUUIDResponseStruct* serverGetNewUUIDRStruct = (struct jsonServerGetNewUUIDResponseStruct*)calloc(1, sizeof(struct jsonServerGetNewUUIDResponseStruct));
        if (!serverGetNewUUIDRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverGetNewUUIDRStruct is a null pointer");
            jsonServerGetNewUUIDObjectStructDelete(getNewUUIDObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetNewUUIDRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverGetNewUUIDRStruct->msg)) {
            jsonServerGetNewUUIDResponseStructDelete(serverGetNewUUIDRStruct);
            jsonServerGetNewUUIDObjectStructDelete(getNewUUIDObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetNewUUIDRStruct->getNewUUIDObjStruct = getNewUUIDObjStruct;

        cJSON_Delete(jsonParser);
        return serverGetNewUUIDRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerGetNewUUIDResponseStruct* failRStruct = (struct jsonServerGetNewUUIDResponseStruct*)calloc(1, sizeof(struct jsonServerGetNewUUIDResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}


void jsonServerGetWebCertFilesObjectStructDelete(struct jsonServerGetWebCertFilesObjectStruct* getWebCertFilesObjStruct) {
    if (!getWebCertFilesObjStruct) {
        return;
    }
    free((char*)getWebCertFilesObjStruct->webCertFile);
    free((char*)getWebCertFilesObjStruct->webKeyFile);
    free(getWebCertFilesObjStruct);
}

void jsonServerGetWebCertFilesResponseStructDelete(struct jsonServerGetWebCertFilesResponseStruct* serverGetWebCertFilesRStruct) {
    if (!serverGetWebCertFilesRStruct) {
        return;
    }
    free((char*)serverGetWebCertFilesRStruct->msg);
    if (serverGetWebCertFilesRStruct->getWebCertFilesObjStruct) {
        jsonServerGetWebCertFilesObjectStructDelete(serverGetWebCertFilesRStruct->getWebCertFilesObjStruct);
        serverGetWebCertFilesRStruct->getWebCertFilesObjStruct = NULL;
    }
    free(serverGetWebCertFilesRStruct);
}

struct jsonServerGetWebCertFilesResponseStruct* jsonServerGetWebCertFilesResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsObject(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* obj = cJSON_GetObjectItem(jsonParser, "obj");

        struct jsonServerGetWebCertFilesObjectStruct* getWebCertFilesObjStruct = (struct jsonServerGetWebCertFilesObjectStruct*)calloc(1, sizeof(struct jsonServerGetWebCertFilesObjectStruct));
        if (!getWebCertFilesObjStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "getWebCertFilesObjStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        jsonCopyStringItem(obj, "webCertFile", &getWebCertFilesObjStruct->webCertFile);
        jsonCopyStringItem(obj, "webKeyFile", &getWebCertFilesObjStruct->webKeyFile);

        struct jsonServerGetWebCertFilesResponseStruct* serverGetWebCertFilesRStruct = (struct jsonServerGetWebCertFilesResponseStruct*)calloc(1, sizeof(struct jsonServerGetWebCertFilesResponseStruct));
        if (!serverGetWebCertFilesRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverGetWebCertFilesRStruct is a null pointer");
            jsonServerGetWebCertFilesObjectStructDelete(getWebCertFilesObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetWebCertFilesRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverGetWebCertFilesRStruct->msg)) {
            jsonServerGetWebCertFilesResponseStructDelete(serverGetWebCertFilesRStruct);
            jsonServerGetWebCertFilesObjectStructDelete(getWebCertFilesObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetWebCertFilesRStruct->getWebCertFilesObjStruct = getWebCertFilesObjStruct;

        cJSON_Delete(jsonParser);
        return serverGetWebCertFilesRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerGetWebCertFilesResponseStruct* failRStruct = (struct jsonServerGetWebCertFilesResponseStruct*)calloc(1, sizeof(struct jsonServerGetWebCertFilesResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

void jsonServerDescendantsObjectArrayStructDelete(struct jsonServerDescendantsObjectArrayStruct* descendantsObjArrStruct, size_t arraySize) {
    if (!descendantsObjArrStruct) {
        return;
    }
    for (size_t i = 0; i < arraySize; i++) {
        free((char*)descendantsObjArrStruct[i].guid);
        free((char*)descendantsObjArrStruct[i].parentGuid);
        free((char*)descendantsObjArrStruct[i].name);
        free((char*)descendantsObjArrStruct[i].address);
        free((char*)descendantsObjArrStruct[i].status);
        if (descendantsObjArrStruct[i].versions) {
            jsonBulkStringArrayFree(descendantsObjArrStruct[i].versions, descendantsObjArrStruct[i].versionsCount);
        }
    }
    free(descendantsObjArrStruct);
}

void jsonServerDescendantsResponseStructDelete(struct jsonServerDescendantsResponseStruct* serverDescendantsRStruct) {
    if (!serverDescendantsRStruct) {
        return;
    }
    free((char*)serverDescendantsRStruct->msg);
    if (serverDescendantsRStruct->descendantsObjArrStruct) {
        jsonServerDescendantsObjectArrayStructDelete(serverDescendantsRStruct->descendantsObjArrStruct, serverDescendantsRStruct->jsonServerDescendantsObjectArrayStructSize);
        serverDescendantsRStruct->descendantsObjArrStruct = NULL;
    }
    free(serverDescendantsRStruct);
}

static int jsonServerDescendantsObjectArrayStructParse(cJSON* arrItem, struct jsonServerDescendantsObjectArrayStruct* descStruct) {
    if (!arrItem) return 0;
    jsonCopyStringItem(arrItem, "guid", &descStruct->guid);
    jsonCopyStringItem(arrItem, "parentGuid", &descStruct->parentGuid);
    jsonCopyStringItem(arrItem, "name", &descStruct->name);
    jsonCopyStringItem(arrItem, "address", &descStruct->address);
    jsonCopyStringItem(arrItem, "status", &descStruct->status);
    if (cJSON_HasObjectItem(arrItem, "versions") && cJSON_IsArray(cJSON_GetObjectItem(arrItem, "versions"))) {
        cJSON* versionsArr = cJSON_GetObjectItem(arrItem, "versions");
        size_t versionsCount = cJSON_GetArraySize(versionsArr);
        if (versionsCount) {
            if (!jsonBulkStringArrayParse(versionsArr, &descStruct->versions, &descStruct->versionsCount)) {
                return 0;
            }
        }
    }
    return 1;
}

struct jsonServerDescendantsResponseStruct* jsonServerDescendantsResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsArray(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* objArray = cJSON_GetObjectItem(jsonParser, "obj");

        size_t arraySize = cJSON_GetArraySize(objArray);
        struct jsonServerDescendantsObjectArrayStruct* descendantsObjArrStruct = NULL;
        if (arraySize) {
            descendantsObjArrStruct = (struct jsonServerDescendantsObjectArrayStruct*)calloc(arraySize, sizeof(struct jsonServerDescendantsObjectArrayStruct));
            if (!descendantsObjArrStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "descendantsObjArrStruct is a null pointer");
                cJSON_Delete(jsonParser);
                return NULL;
            }
            for (size_t i = 0; i < arraySize; i++) {
                cJSON* arrItem = cJSON_GetArrayItem(objArray, i);
                if (!jsonServerDescendantsObjectArrayStructParse(arrItem, &descendantsObjArrStruct[i])) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Array element is not parsed correctly, skipping...");
                    continue;
                }
            }
        }

        struct jsonServerDescendantsResponseStruct* serverDescendantsRStruct = (struct jsonServerDescendantsResponseStruct*)calloc(1, sizeof(struct jsonServerDescendantsResponseStruct));
        if (!serverDescendantsRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverDescendantsRStruct is a null pointer");
            jsonServerDescendantsObjectArrayStructDelete(descendantsObjArrStruct, arraySize);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverDescendantsRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverDescendantsRStruct->msg)) {
            jsonServerDescendantsResponseStructDelete(serverDescendantsRStruct);
            jsonServerDescendantsObjectArrayStructDelete(descendantsObjArrStruct, arraySize);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverDescendantsRStruct->jsonServerDescendantsObjectArrayStructSize = arraySize;
        serverDescendantsRStruct->descendantsObjArrStruct = descendantsObjArrStruct;

        cJSON_Delete(jsonParser);
        return serverDescendantsRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerDescendantsResponseStruct* failRStruct = (struct jsonServerDescendantsResponseStruct*)calloc(1, sizeof(struct jsonServerDescendantsResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}


void jsonServerGetNewX25519CertObjectStructDelete(struct jsonServerGetNewX25519CertObjectStruct* getNewX25519ObjStruct) {
    if (!getNewX25519ObjStruct) {
        return;
    }
    free((char*)getNewX25519ObjStruct->privateKey);
    free((char*)getNewX25519ObjStruct->publicKey);
    free(getNewX25519ObjStruct);
}

void jsonServerGetNewX25519CertResponseStructDelete(struct jsonServerGetNewX25519CertResponseStruct* serverGetNewX25519CertRStruct) {
    if (!serverGetNewX25519CertRStruct) {
        return;
    }
    free((char*)serverGetNewX25519CertRStruct->msg);
    if (serverGetNewX25519CertRStruct->getNewX25519ObjStruct) {
        jsonServerGetNewX25519CertObjectStructDelete(serverGetNewX25519CertRStruct->getNewX25519ObjStruct);
        serverGetNewX25519CertRStruct->getNewX25519ObjStruct = NULL;
    }
    free(serverGetNewX25519CertRStruct);
}

struct jsonServerGetNewX25519CertResponseStruct* jsonServerGetNewX25519CertResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsObject(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* obj = cJSON_GetObjectItem(jsonParser, "obj");

        struct jsonServerGetNewX25519CertObjectStruct* getNewX25519ObjStruct = (struct jsonServerGetNewX25519CertObjectStruct*)calloc(1, sizeof(struct jsonServerGetNewX25519CertObjectStruct));
        if (!getNewX25519ObjStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "getNewX25519ObjStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        jsonCopyStringItem(obj, "privateKey", &getNewX25519ObjStruct->privateKey);
        jsonCopyStringItem(obj, "publicKey", &getNewX25519ObjStruct->publicKey);

        struct jsonServerGetNewX25519CertResponseStruct* serverGetNewX25519CertRStruct = (struct jsonServerGetNewX25519CertResponseStruct*)calloc(1, sizeof(struct jsonServerGetNewX25519CertResponseStruct));
        if (!serverGetNewX25519CertRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverGetNewX25519CertRStruct is a null pointer");
            jsonServerGetNewX25519CertObjectStructDelete(getNewX25519ObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetNewX25519CertRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverGetNewX25519CertRStruct->msg)) {
            jsonServerGetNewX25519CertResponseStructDelete(serverGetNewX25519CertRStruct);
            jsonServerGetNewX25519CertObjectStructDelete(getNewX25519ObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetNewX25519CertRStruct->getNewX25519ObjStruct = getNewX25519ObjStruct;

        cJSON_Delete(jsonParser);
        return serverGetNewX25519CertRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerGetNewX25519CertResponseStruct* failRStruct = (struct jsonServerGetNewX25519CertResponseStruct*)calloc(1, sizeof(struct jsonServerGetNewX25519CertResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

void jsonServerGetNewMldsa65ObjectStructDelete(struct jsonServerGetNewMldsa65ObjectStruct* getNewMldsa65ObjStruct) {
    if (!getNewMldsa65ObjStruct) {
        return;
    }
    free((char*)getNewMldsa65ObjStruct->seed);
    free((char*)getNewMldsa65ObjStruct->verify);
    free(getNewMldsa65ObjStruct);
}

void jsonServerGetNewMldsa65ResponseStructDelete(struct jsonServerGetNewMldsa65ResponseStruct* serverGetNewMldsa65RStruct) {
    if (!serverGetNewMldsa65RStruct) {
        return;
    }
    free((char*)serverGetNewMldsa65RStruct->msg);
    if (serverGetNewMldsa65RStruct->getNewMldsa65ObjStruct) {
        jsonServerGetNewMldsa65ObjectStructDelete(serverGetNewMldsa65RStruct->getNewMldsa65ObjStruct);
        serverGetNewMldsa65RStruct->getNewMldsa65ObjStruct = NULL;
    }
    free(serverGetNewMldsa65RStruct);
}

struct jsonServerGetNewMldsa65ResponseStruct* jsonServerGetNewMldsa65Response(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsObject(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* obj = cJSON_GetObjectItem(jsonParser, "obj");

        struct jsonServerGetNewMldsa65ObjectStruct* getNewMldsa65ObjStruct = (struct jsonServerGetNewMldsa65ObjectStruct*)calloc(1, sizeof(struct jsonServerGetNewMldsa65ObjectStruct));
        if (!getNewMldsa65ObjStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "getNewMldsa65ObjStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        jsonCopyStringItem(obj, "seed", &getNewMldsa65ObjStruct->seed);
        jsonCopyStringItem(obj, "verify", &getNewMldsa65ObjStruct->verify);

        struct jsonServerGetNewMldsa65ResponseStruct* serverGetNewMldsa65RStruct = (struct jsonServerGetNewMldsa65ResponseStruct*)calloc(1, sizeof(struct jsonServerGetNewMldsa65ResponseStruct));
        if (!serverGetNewMldsa65RStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverGetNewMldsa65RStruct is a null pointer");
            jsonServerGetNewMldsa65ObjectStructDelete(getNewMldsa65ObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetNewMldsa65RStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverGetNewMldsa65RStruct->msg)) {
            jsonServerGetNewMldsa65ResponseStructDelete(serverGetNewMldsa65RStruct);
            jsonServerGetNewMldsa65ObjectStructDelete(getNewMldsa65ObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetNewMldsa65RStruct->getNewMldsa65ObjStruct = getNewMldsa65ObjStruct;

        cJSON_Delete(jsonParser);
        return serverGetNewMldsa65RStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerGetNewMldsa65ResponseStruct* failRStruct = (struct jsonServerGetNewMldsa65ResponseStruct*)calloc(1, sizeof(struct jsonServerGetNewMldsa65ResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

void jsonServerGetNewMlkem768ObjectStructDelete(struct jsonServerGetNewMlkem768ObjectStruct* getNewMlkem768ObjStruct) {
    if (!getNewMlkem768ObjStruct) {
        return;
    }
    free((char*)getNewMlkem768ObjStruct->client);
    free((char*)getNewMlkem768ObjStruct->seed);
    free(getNewMlkem768ObjStruct);
}

void jsonServerGetNewMlkem768ResponseStructDelete(struct jsonServerGetNewMlkem768ResponseStruct* serverGetNewMlkem768RStruct) {
    if (!serverGetNewMlkem768RStruct) {
        return;
    }
    free((char*)serverGetNewMlkem768RStruct->msg);
    if (serverGetNewMlkem768RStruct->getNewMlkem768ObjStruct) {
        jsonServerGetNewMlkem768ObjectStructDelete(serverGetNewMlkem768RStruct->getNewMlkem768ObjStruct);
        serverGetNewMlkem768RStruct->getNewMlkem768ObjStruct = NULL;
    }
    free(serverGetNewMlkem768RStruct);
}

struct jsonServerGetNewMlkem768ResponseStruct* jsonServerGetNewMlkem768Response(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsObject(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* obj = cJSON_GetObjectItem(jsonParser, "obj");

        struct jsonServerGetNewMlkem768ObjectStruct* getNewMlkem768ObjStruct = (struct jsonServerGetNewMlkem768ObjectStruct*)calloc(1, sizeof(struct jsonServerGetNewMlkem768ObjectStruct));
        if (!getNewMlkem768ObjStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "getNewMlkem768ObjStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        jsonCopyStringItem(obj, "client", &getNewMlkem768ObjStruct->client);
        jsonCopyStringItem(obj, "seed", &getNewMlkem768ObjStruct->seed);

        struct jsonServerGetNewMlkem768ResponseStruct* serverGetNewMlkem768RStruct = (struct jsonServerGetNewMlkem768ResponseStruct*)calloc(1, sizeof(struct jsonServerGetNewMlkem768ResponseStruct));
        if (!serverGetNewMlkem768RStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverGetNewMlkem768RStruct is a null pointer");
            jsonServerGetNewMlkem768ObjectStructDelete(getNewMlkem768ObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetNewMlkem768RStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverGetNewMlkem768RStruct->msg)) {
            jsonServerGetNewMlkem768ResponseStructDelete(serverGetNewMlkem768RStruct);
            jsonServerGetNewMlkem768ObjectStructDelete(getNewMlkem768ObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetNewMlkem768RStruct->getNewMlkem768ObjStruct = getNewMlkem768ObjStruct;

        cJSON_Delete(jsonParser);
        return serverGetNewMlkem768RStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerGetNewMlkem768ResponseStruct* failRStruct = (struct jsonServerGetNewMlkem768ResponseStruct*)calloc(1, sizeof(struct jsonServerGetNewMlkem768ResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}


void jsonServerGetNewVlessEncAuthsArrayStructDelete(struct jsonServerGetNewVlessEncAuthsArrayStruct* getNewVlessEncObjAuthsArrStruct, size_t arraySize) {
    if (!getNewVlessEncObjAuthsArrStruct) {
        return;
    }
    for (size_t i = 0; i < arraySize; i++) {
        free((char*)getNewVlessEncObjAuthsArrStruct[i].id);
        free((char*)getNewVlessEncObjAuthsArrStruct[i].label);
        free((char*)getNewVlessEncObjAuthsArrStruct[i].encryption);
        free((char*)getNewVlessEncObjAuthsArrStruct[i].decryption);
    }
    free(getNewVlessEncObjAuthsArrStruct);
}

void jsonServerGetNewVlessEncObjectStructDelete(struct jsonServerGetNewVlessEncObjectStruct* getNewVlessEncObjStruct) {
    if (!getNewVlessEncObjStruct) {
        return;
    }
    if (getNewVlessEncObjStruct->getNewVlessEncObjAuthsArrStruct) {
        jsonServerGetNewVlessEncAuthsArrayStructDelete(getNewVlessEncObjStruct->getNewVlessEncObjAuthsArrStruct, getNewVlessEncObjStruct->jsonServerGetNewVlessEncAuthsArrayStructSize);
        getNewVlessEncObjStruct->getNewVlessEncObjAuthsArrStruct = NULL;
    }
    free(getNewVlessEncObjStruct);
}

void jsonServerGetNewVlessEncResponseStructDelete(struct jsonServerGetNewVlessEncResponseStruct* serverGetNewVlessEncRStruct) {
    if (!serverGetNewVlessEncRStruct) {
        return;
    }
    free((char*)serverGetNewVlessEncRStruct->msg);
    if (serverGetNewVlessEncRStruct->getNewVlessEncObjStruct) {
        jsonServerGetNewVlessEncObjectStructDelete(serverGetNewVlessEncRStruct->getNewVlessEncObjStruct);
        serverGetNewVlessEncRStruct->getNewVlessEncObjStruct = NULL;
    }
    free(serverGetNewVlessEncRStruct);
}

static int jsonServerGetNewVlessEncAuthsArrayStructParse(cJSON* arrItem, struct jsonServerGetNewVlessEncAuthsArrayStruct* authStruct) {
    if (!arrItem) return 0;
    jsonCopyStringItem(arrItem, "id", &authStruct->id);
    jsonCopyStringItem(arrItem, "label", &authStruct->label);
    jsonCopyStringItem(arrItem, "encryption", &authStruct->encryption);
    jsonCopyStringItem(arrItem, "decryption", &authStruct->decryption);
    return 1;
}

static int jsonServerGetNewVlessEncObjectStructParse(cJSON* obj, struct jsonServerGetNewVlessEncObjectStruct* vlessStruct) {
    if (!obj) return 0;
    if (cJSON_HasObjectItem(obj, "auths") && cJSON_IsArray(cJSON_GetObjectItem(obj, "auths"))) {
        cJSON* authsArr = cJSON_GetObjectItem(obj, "auths");
        size_t authsCount = cJSON_GetArraySize(authsArr);
        if (authsCount) {
            vlessStruct->getNewVlessEncObjAuthsArrStruct = (struct jsonServerGetNewVlessEncAuthsArrayStruct*)calloc(authsCount, sizeof(struct jsonServerGetNewVlessEncAuthsArrayStruct));
            if (!vlessStruct->getNewVlessEncObjAuthsArrStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "getNewVlessEncObjAuthsArrStruct is a null pointer");
                return 0;
            }
            vlessStruct->jsonServerGetNewVlessEncAuthsArrayStructSize = authsCount;
            for (size_t i = 0; i < authsCount; i++) {
                cJSON* authItem = cJSON_GetArrayItem(authsArr, i);
                if (!jsonServerGetNewVlessEncAuthsArrayStructParse(authItem, &vlessStruct->getNewVlessEncObjAuthsArrStruct[i])) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Auth array element is not parsed correctly, skipping...");
                    continue;
                }
            }
        }
    }
    return 1;
}

struct jsonServerGetNewVlessEncResponseStruct* jsonServerGetNewVlessEncResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsObject(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* obj = cJSON_GetObjectItem(jsonParser, "obj");

        struct jsonServerGetNewVlessEncObjectStruct* getNewVlessEncObjStruct = (struct jsonServerGetNewVlessEncObjectStruct*)calloc(1, sizeof(struct jsonServerGetNewVlessEncObjectStruct));
        if (!getNewVlessEncObjStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "getNewVlessEncObjStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (!jsonServerGetNewVlessEncObjectStructParse(obj, getNewVlessEncObjStruct)) {
            jsonServerGetNewVlessEncObjectStructDelete(getNewVlessEncObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        struct jsonServerGetNewVlessEncResponseStruct* serverGetNewVlessEncRStruct = (struct jsonServerGetNewVlessEncResponseStruct*)calloc(1, sizeof(struct jsonServerGetNewVlessEncResponseStruct));
        if (!serverGetNewVlessEncRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverGetNewVlessEncRStruct is a null pointer");
            jsonServerGetNewVlessEncObjectStructDelete(getNewVlessEncObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetNewVlessEncRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverGetNewVlessEncRStruct->msg)) {
            jsonServerGetNewVlessEncResponseStructDelete(serverGetNewVlessEncRStruct);
            jsonServerGetNewVlessEncObjectStructDelete(getNewVlessEncObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetNewVlessEncRStruct->getNewVlessEncObjStruct = getNewVlessEncObjStruct;

        cJSON_Delete(jsonParser);
        return serverGetNewVlessEncRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerGetNewVlessEncResponseStruct* failRStruct = (struct jsonServerGetNewVlessEncResponseStruct*)calloc(1, sizeof(struct jsonServerGetNewVlessEncResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

void jsonServerStopXrayServiceResponseStructDelete(struct jsonServerStopXrayServiceResponseStruct* serverStopXrayServiceRStruct) {
    if (!serverStopXrayServiceRStruct) {
        return;
    }
    free((char*)serverStopXrayServiceRStruct->msg);
    free(serverStopXrayServiceRStruct);
}

struct jsonServerStopXrayServiceResponseStruct* jsonServerStopXrayServiceResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonServerStopXrayServiceResponseStruct* serverStopXrayServiceRStruct = (struct jsonServerStopXrayServiceResponseStruct*)calloc(1, sizeof(struct jsonServerStopXrayServiceResponseStruct));
        if (!serverStopXrayServiceRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverStopXrayServiceRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverStopXrayServiceRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverStopXrayServiceRStruct->msg)) {
            jsonServerStopXrayServiceResponseStructDelete(serverStopXrayServiceRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverStopXrayServiceRStruct->obj = NULL;

        cJSON_Delete(jsonParser);
        return serverStopXrayServiceRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerStopXrayServiceResponseStruct* failRStruct = (struct jsonServerStopXrayServiceResponseStruct*)calloc(1, sizeof(struct jsonServerStopXrayServiceResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

void jsonServerRestartXrayServiceResponseStructDelete(struct jsonServerRestartXrayServiceResponseStruct* serverRestartXrayServiceRStruct) {
    if (!serverRestartXrayServiceRStruct) {
        return;
    }
    free((char*)serverRestartXrayServiceRStruct->msg);
    free(serverRestartXrayServiceRStruct);
}

struct jsonServerRestartXrayServiceResponseStruct* jsonServerRestartXrayServiceResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonServerRestartXrayServiceResponseStruct* serverRestartXrayServiceRStruct = (struct jsonServerRestartXrayServiceResponseStruct*)calloc(1, sizeof(struct jsonServerRestartXrayServiceResponseStruct));
        if (!serverRestartXrayServiceRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverRestartXrayServiceRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverRestartXrayServiceRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverRestartXrayServiceRStruct->msg)) {
            jsonServerRestartXrayServiceResponseStructDelete(serverRestartXrayServiceRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverRestartXrayServiceRStruct->obj = NULL;

        cJSON_Delete(jsonParser);
        return serverRestartXrayServiceRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerRestartXrayServiceResponseStruct* failRStruct = (struct jsonServerRestartXrayServiceResponseStruct*)calloc(1, sizeof(struct jsonServerRestartXrayServiceResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

void jsonServerInstallXrayResponseStructDelete(struct jsonServerInstallXrayResponseStruct* serverInstallXrayRStruct) {
    if (!serverInstallXrayRStruct) {
        return;
    }
    free((char*)serverInstallXrayRStruct->msg);
    free(serverInstallXrayRStruct);
}

struct jsonServerInstallXrayResponseStruct* jsonServerInstallXrayResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonServerInstallXrayResponseStruct* serverInstallXrayRStruct = (struct jsonServerInstallXrayResponseStruct*)calloc(1, sizeof(struct jsonServerInstallXrayResponseStruct));
        if (!serverInstallXrayRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverInstallXrayRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverInstallXrayRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverInstallXrayRStruct->msg)) {
            jsonServerInstallXrayResponseStructDelete(serverInstallXrayRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverInstallXrayRStruct->obj = NULL;

        cJSON_Delete(jsonParser);
        return serverInstallXrayRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerInstallXrayResponseStruct* failRStruct = (struct jsonServerInstallXrayResponseStruct*)calloc(1, sizeof(struct jsonServerInstallXrayResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}


void jsonServerUpdatePanelObjectStructDelete(struct jsonServerUpdatePanelObjectStruct* updatePanelObjStruct) {
    if (!updatePanelObjStruct) {
        return;
    }
    free((char*)updatePanelObjStruct->runId);
    free(updatePanelObjStruct);
}

void jsonServerUpdatePanelResponseStructDelete(struct jsonServerUpdatePanelResponseStruct* serverUpdatePanelRStruct) {
    if (!serverUpdatePanelRStruct) {
        return;
    }
    free((char*)serverUpdatePanelRStruct->msg);
    if (serverUpdatePanelRStruct->updatePanelObjStruct) {
        jsonServerUpdatePanelObjectStructDelete(serverUpdatePanelRStruct->updatePanelObjStruct);
        serverUpdatePanelRStruct->updatePanelObjStruct = NULL;
    }
    free(serverUpdatePanelRStruct);
}

struct jsonServerUpdatePanelResponseStruct* jsonServerUpdatePanelResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsObject(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* obj = cJSON_GetObjectItem(jsonParser, "obj");

        struct jsonServerUpdatePanelObjectStruct* updatePanelObjStruct = (struct jsonServerUpdatePanelObjectStruct*)calloc(1, sizeof(struct jsonServerUpdatePanelObjectStruct));
        if (!updatePanelObjStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "updatePanelObjStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        jsonCopyStringItem(obj, "runId", &updatePanelObjStruct->runId);

        struct jsonServerUpdatePanelResponseStruct* serverUpdatePanelRStruct = (struct jsonServerUpdatePanelResponseStruct*)calloc(1, sizeof(struct jsonServerUpdatePanelResponseStruct));
        if (!serverUpdatePanelRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverUpdatePanelRStruct is a null pointer");
            jsonServerUpdatePanelObjectStructDelete(updatePanelObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverUpdatePanelRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverUpdatePanelRStruct->msg)) {
            jsonServerUpdatePanelResponseStructDelete(serverUpdatePanelRStruct);
            jsonServerUpdatePanelObjectStructDelete(updatePanelObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverUpdatePanelRStruct->updatePanelObjStruct = updatePanelObjStruct;

        cJSON_Delete(jsonParser);
        return serverUpdatePanelRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerUpdatePanelResponseStruct* failRStruct = (struct jsonServerUpdatePanelResponseStruct*)calloc(1, sizeof(struct jsonServerUpdatePanelResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

void jsonServerSetUpdateChannelPostStructDelete(struct jsonServerSetUpdateChannelPostStruct* serverSetUpdateChannelPostStruct) {
    if (!serverSetUpdateChannelPostStruct) {
        return;
    }
    free(serverSetUpdateChannelPostStruct);
}

const char* jsonServerSetUpdateChannelPost(struct jsonServerSetUpdateChannelPostStruct* serverSetUpdateChannelPostStruct) {
    if (!serverSetUpdateChannelPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverSetUpdateChannelPostStruct is a null pointer");
        return NULL;
    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");
        return NULL;
    }

    cJSON_AddBoolToObject(json, "dev", serverSetUpdateChannelPostStruct->dev);

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");
        return NULL;
    }

    return jsonString;
}

void jsonServerSetUpdateChannelResponseStructDelete(struct jsonServerSetUpdateChannelResponseStruct* serverSetUpdateChannelRStruct) {
    if (!serverSetUpdateChannelRStruct) {
        return;
    }
    free((char*)serverSetUpdateChannelRStruct->msg);
    free(serverSetUpdateChannelRStruct);
}

struct jsonServerSetUpdateChannelResponseStruct* jsonServerSetUpdateChannelResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonServerSetUpdateChannelResponseStruct* serverSetUpdateChannelRStruct = (struct jsonServerSetUpdateChannelResponseStruct*)calloc(1, sizeof(struct jsonServerSetUpdateChannelResponseStruct));
        if (!serverSetUpdateChannelRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverSetUpdateChannelRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverSetUpdateChannelRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverSetUpdateChannelRStruct->msg)) {
            jsonServerSetUpdateChannelResponseStructDelete(serverSetUpdateChannelRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverSetUpdateChannelRStruct->obj = NULL;

        cJSON_Delete(jsonParser);
        return serverSetUpdateChannelRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerSetUpdateChannelResponseStruct* failRStruct = (struct jsonServerSetUpdateChannelResponseStruct*)calloc(1, sizeof(struct jsonServerSetUpdateChannelResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

void jsonServerUpdateGeofileResponseStructDelete(struct jsonServerUpdateGeofileResponseStruct* serverUpdateGeofileRStruct) {
    if (!serverUpdateGeofileRStruct) {
        return;
    }
    free((char*)serverUpdateGeofileRStruct->msg);
    free(serverUpdateGeofileRStruct);
}

struct jsonServerUpdateGeofileResponseStruct* jsonServerUpdateGeofileResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonServerUpdateGeofileResponseStruct* serverUpdateGeofileRStruct = (struct jsonServerUpdateGeofileResponseStruct*)calloc(1, sizeof(struct jsonServerUpdateGeofileResponseStruct));
        if (!serverUpdateGeofileRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverUpdateGeofileRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverUpdateGeofileRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverUpdateGeofileRStruct->msg)) {
            jsonServerUpdateGeofileResponseStructDelete(serverUpdateGeofileRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverUpdateGeofileRStruct->obj = NULL;

        cJSON_Delete(jsonParser);
        return serverUpdateGeofileRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerUpdateGeofileResponseStruct* failRStruct = (struct jsonServerUpdateGeofileResponseStruct*)calloc(1, sizeof(struct jsonServerUpdateGeofileResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}


void jsonServerLogsResponseStructDelete(struct jsonServerLogsResponseStruct* serverLogsRStruct) {
    if (!serverLogsRStruct) {
        return;
    }
    free((char*)serverLogsRStruct->msg);
    if (serverLogsRStruct->obj) {
        jsonBulkStringArrayFree(serverLogsRStruct->obj, serverLogsRStruct->objCount);
        serverLogsRStruct->obj = NULL;
    }
    free(serverLogsRStruct);
}

struct jsonServerLogsResponseStruct* jsonServerLogsResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonServerLogsResponseStruct* serverLogsRStruct = (struct jsonServerLogsResponseStruct*)calloc(1, sizeof(struct jsonServerLogsResponseStruct));
        if (!serverLogsRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverLogsRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverLogsRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverLogsRStruct->msg)) {
            jsonServerLogsResponseStructDelete(serverLogsRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsArray(cJSON_GetObjectItem(jsonParser, "obj"))) {
            if (!jsonBulkStringArrayParse(cJSON_GetObjectItem(jsonParser, "obj"), &serverLogsRStruct->obj, &serverLogsRStruct->objCount)) {
                jsonServerLogsResponseStructDelete(serverLogsRStruct);
                cJSON_Delete(jsonParser);
                return NULL;
            }
        }

        cJSON_Delete(jsonParser);
        return serverLogsRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerLogsResponseStruct* failRStruct = (struct jsonServerLogsResponseStruct*)calloc(1, sizeof(struct jsonServerLogsResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

void jsonServerXrayLogsObjectArrayStructDelete(struct jsonServerXrayLogsObjectArrayStruct* xrayLogsObjArrStruct, size_t arraySize) {
    if (!xrayLogsObjArrStruct) {
        return;
    }
    for (size_t i = 0; i < arraySize; i++) {
        free((char*)xrayLogsObjArrStruct[i].DateTime);
        free((char*)xrayLogsObjArrStruct[i].Email);
        free((char*)xrayLogsObjArrStruct[i].FromAddress);
        free((char*)xrayLogsObjArrStruct[i].Inbound);
        free((char*)xrayLogsObjArrStruct[i].Outbound);
        free((char*)xrayLogsObjArrStruct[i].ToAddress);
    }
    free(xrayLogsObjArrStruct);
}

void jsonServerXrayLogsResponseStructDelete(struct jsonServerXrayLogsResponseStruct* serverXrayLogsRStruct) {
    if (!serverXrayLogsRStruct) {
        return;
    }
    free((char*)serverXrayLogsRStruct->msg);
    if (serverXrayLogsRStruct->xrayLogsObjArrStruct) {
        jsonServerXrayLogsObjectArrayStructDelete(serverXrayLogsRStruct->xrayLogsObjArrStruct, serverXrayLogsRStruct->jsonServerXrayLogsObjectArrayStructSize);
        serverXrayLogsRStruct->xrayLogsObjArrStruct = NULL;
    }
    free(serverXrayLogsRStruct);
}

static int jsonServerXrayLogsObjectArrayStructParse(cJSON* arrItem, struct jsonServerXrayLogsObjectArrayStruct* logStruct) {
    if (!arrItem) return 0;
    jsonCopyStringItem(arrItem, "DateTime", &logStruct->DateTime);
    jsonCopyStringItem(arrItem, "Email", &logStruct->Email);
    jsonCopyNumberItem(arrItem, "Event", (int64_t*)&logStruct->Event);
    jsonCopyStringItem(arrItem, "FromAddress", &logStruct->FromAddress);
    jsonCopyStringItem(arrItem, "Inbound", &logStruct->Inbound);
    jsonCopyStringItem(arrItem, "Outbound", &logStruct->Outbound);
    jsonCopyStringItem(arrItem, "ToAddress", &logStruct->ToAddress);
    return 1;
}

struct jsonServerXrayLogsResponseStruct* jsonServerXrayLogsResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsArray(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* objArray = cJSON_GetObjectItem(jsonParser, "obj");

        size_t arraySize = cJSON_GetArraySize(objArray);
        struct jsonServerXrayLogsObjectArrayStruct* xrayLogsObjArrStruct = NULL;
        if (arraySize) {
            xrayLogsObjArrStruct = (struct jsonServerXrayLogsObjectArrayStruct*)calloc(arraySize, sizeof(struct jsonServerXrayLogsObjectArrayStruct));
            if (!xrayLogsObjArrStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayLogsObjArrStruct is a null pointer");
                cJSON_Delete(jsonParser);
                return NULL;
            }
            for (size_t i = 0; i < arraySize; i++) {
                cJSON* arrItem = cJSON_GetArrayItem(objArray, i);
                if (!jsonServerXrayLogsObjectArrayStructParse(arrItem, &xrayLogsObjArrStruct[i])) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Array element is not parsed correctly, skipping...");
                    continue;
                }
            }
        }

        struct jsonServerXrayLogsResponseStruct* serverXrayLogsRStruct = (struct jsonServerXrayLogsResponseStruct*)calloc(1, sizeof(struct jsonServerXrayLogsResponseStruct));
        if (!serverXrayLogsRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverXrayLogsRStruct is a null pointer");
            jsonServerXrayLogsObjectArrayStructDelete(xrayLogsObjArrStruct, arraySize);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverXrayLogsRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverXrayLogsRStruct->msg)) {
            jsonServerXrayLogsResponseStructDelete(serverXrayLogsRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverXrayLogsRStruct->jsonServerXrayLogsObjectArrayStructSize = arraySize;
        serverXrayLogsRStruct->xrayLogsObjArrStruct = xrayLogsObjArrStruct;

        cJSON_Delete(jsonParser);
        return serverXrayLogsRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerXrayLogsResponseStruct* failRStruct = (struct jsonServerXrayLogsResponseStruct*)calloc(1, sizeof(struct jsonServerXrayLogsResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}


void jsonServerAmneziawgLogsPeersArrayStructDelete(struct jsonServerAmneziawgLogsPeersArrayStruct* awgLogsObjPeersArrStruct, size_t arraySize) {
    if (!awgLogsObjPeersArrStruct) {
        return;
    }
    for (size_t i = 0; i < arraySize; i++) {
        free((char*)awgLogsObjPeersArrStruct[i].allowedIPs);
        free((char*)awgLogsObjPeersArrStruct[i].email);
        free((char*)awgLogsObjPeersArrStruct[i].endpoint);
        free((char*)awgLogsObjPeersArrStruct[i].interface);
        free((char*)awgLogsObjPeersArrStruct[i].tag);
    }
    free(awgLogsObjPeersArrStruct);
}

void jsonServerAmneziawgLogsObjectStructDelete(struct jsonServerAmneziawgLogsObjectStruct* awgLogsObjStruct) {
    if (!awgLogsObjStruct) {
        return;
    }
    if (awgLogsObjStruct->awgLogsObjPeersArrStruct) {
        jsonServerAmneziawgLogsPeersArrayStructDelete(awgLogsObjStruct->awgLogsObjPeersArrStruct, awgLogsObjStruct->jsonServerAmneziawgLogsPeersArrayStructSize);
        awgLogsObjStruct->awgLogsObjPeersArrStruct = NULL;
    }
    if (awgLogsObjStruct->events) {
        jsonBulkStringArrayFree(awgLogsObjStruct->events, awgLogsObjStruct->eventsCount);
    }
    free(awgLogsObjStruct);
}

void jsonServerAmneziawgLogsResponseStructDelete(struct jsonServerAmneziawgLogsResponseStruct* serverAmneziawgLogsRStruct) {
    if (!serverAmneziawgLogsRStruct) {
        return;
    }
    free((char*)serverAmneziawgLogsRStruct->msg);
    if (serverAmneziawgLogsRStruct->awgLogsObjStruct) {
        jsonServerAmneziawgLogsObjectStructDelete(serverAmneziawgLogsRStruct->awgLogsObjStruct);
        serverAmneziawgLogsRStruct->awgLogsObjStruct = NULL;
    }
    free(serverAmneziawgLogsRStruct);
}

static int jsonServerAmneziawgLogsPeersArrayStructParse(cJSON* arrItem, struct jsonServerAmneziawgLogsPeersArrayStruct* peerStruct) {
    if (!arrItem) return 0;
    jsonCopyStringItem(arrItem, "allowedIPs", &peerStruct->allowedIPs);
    jsonCopyNumberItem(arrItem, "down", &peerStruct->down);
    jsonCopyStringItem(arrItem, "email", &peerStruct->email);
    jsonCopyStringItem(arrItem, "endpoint", &peerStruct->endpoint);
    jsonCopyNumberItem(arrItem, "handshake", &peerStruct->handshake);
    jsonCopyNumberItem(arrItem, "inboundId", (int64_t*)&peerStruct->inboundId);
    jsonCopyStringItem(arrItem, "interface", &peerStruct->interface);
    jsonCopyBoolItem(arrItem, "online", &peerStruct->online);
    jsonCopyStringItem(arrItem, "tag", &peerStruct->tag);
    jsonCopyNumberItem(arrItem, "up", &peerStruct->up);
    return 1;
}

static int jsonServerAmneziawgLogsObjectStructParse(cJSON* obj, struct jsonServerAmneziawgLogsObjectStruct* awgStruct) {
    if (!obj) return 0;
    if (cJSON_HasObjectItem(obj, "peers") && cJSON_IsArray(cJSON_GetObjectItem(obj, "peers"))) {
        cJSON* peersArr = cJSON_GetObjectItem(obj, "peers");
        size_t peersCount = cJSON_GetArraySize(peersArr);
        if (peersCount) {
            awgStruct->awgLogsObjPeersArrStruct = (struct jsonServerAmneziawgLogsPeersArrayStruct*)calloc(peersCount, sizeof(struct jsonServerAmneziawgLogsPeersArrayStruct));
            if (!awgStruct->awgLogsObjPeersArrStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "awgLogsObjPeersArrStruct is a null pointer");
                return 0;
            }
            awgStruct->jsonServerAmneziawgLogsPeersArrayStructSize = peersCount;
            for (size_t i = 0; i < peersCount; i++) {
                cJSON* peerItem = cJSON_GetArrayItem(peersArr, i);
                if (!jsonServerAmneziawgLogsPeersArrayStructParse(peerItem, &awgStruct->awgLogsObjPeersArrStruct[i])) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Peer array element is not parsed correctly, skipping...");
                    continue;
                }
            }
        }
    }
    if (cJSON_HasObjectItem(obj, "events") && cJSON_IsArray(cJSON_GetObjectItem(obj, "events"))) {
        if (!jsonBulkStringArrayParse(cJSON_GetObjectItem(obj, "events"), &awgStruct->events, &awgStruct->eventsCount)) {
            return 0;
        }
    }
    jsonCopyBoolItem(obj, "running", &awgStruct->running);
    return 1;
}

struct jsonServerAmneziawgLogsResponseStruct* jsonServerAmneziawgLogsResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsObject(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* obj = cJSON_GetObjectItem(jsonParser, "obj");

        struct jsonServerAmneziawgLogsObjectStruct* awgLogsObjStruct = (struct jsonServerAmneziawgLogsObjectStruct*)calloc(1, sizeof(struct jsonServerAmneziawgLogsObjectStruct));
        if (!awgLogsObjStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "awgLogsObjStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (!jsonServerAmneziawgLogsObjectStructParse(obj, awgLogsObjStruct)) {
            jsonServerAmneziawgLogsObjectStructDelete(awgLogsObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        struct jsonServerAmneziawgLogsResponseStruct* serverAmneziawgLogsRStruct = (struct jsonServerAmneziawgLogsResponseStruct*)calloc(1, sizeof(struct jsonServerAmneziawgLogsResponseStruct));
        if (!serverAmneziawgLogsRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverAmneziawgLogsRStruct is a null pointer");
            jsonServerAmneziawgLogsObjectStructDelete(awgLogsObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverAmneziawgLogsRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverAmneziawgLogsRStruct->msg)) {
            jsonServerAmneziawgLogsResponseStructDelete(serverAmneziawgLogsRStruct);
            jsonServerAmneziawgLogsObjectStructDelete(awgLogsObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverAmneziawgLogsRStruct->awgLogsObjStruct = awgLogsObjStruct;

        cJSON_Delete(jsonParser);
        return serverAmneziawgLogsRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerAmneziawgLogsResponseStruct* failRStruct = (struct jsonServerAmneziawgLogsResponseStruct*)calloc(1, sizeof(struct jsonServerAmneziawgLogsResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}


void jsonServerImportDbResponseStructDelete(struct jsonServerImportDbResponseStruct* serverImportDbRStruct) {
    if (!serverImportDbRStruct) {
        return;
    }
    free((char*)serverImportDbRStruct->msg);
    free(serverImportDbRStruct);
}

struct jsonServerImportDbResponseStruct* jsonServerImportDbResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonServerImportDbResponseStruct* serverImportDbRStruct = (struct jsonServerImportDbResponseStruct*)calloc(1, sizeof(struct jsonServerImportDbResponseStruct));
        if (!serverImportDbRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverImportDbRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverImportDbRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverImportDbRStruct->msg)) {
            jsonServerImportDbResponseStructDelete(serverImportDbRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverImportDbRStruct->obj = NULL;

        cJSON_Delete(jsonParser);
        return serverImportDbRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerImportDbResponseStruct* failRStruct = (struct jsonServerImportDbResponseStruct*)calloc(1, sizeof(struct jsonServerImportDbResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

void jsonServerGetNewEchCertPostStructDelete(struct jsonServerGetNewEchCertPostStruct* serverGetNewEchCertPostStruct) {
    if (!serverGetNewEchCertPostStruct) {
        return;
    }
    free((char*)serverGetNewEchCertPostStruct->sni);
    free(serverGetNewEchCertPostStruct);
}

const char* jsonServerGetNewEchCertPost(struct jsonServerGetNewEchCertPostStruct* serverGetNewEchCertPostStruct) {
    if (!serverGetNewEchCertPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverGetNewEchCertPostStruct is a null pointer");
        return NULL;
    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");
        return NULL;
    }

    if (serverGetNewEchCertPostStruct->sni) {
        cJSON_AddStringToObject(json, "sni", serverGetNewEchCertPostStruct->sni);
    }

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");
        return NULL;
    }

    return jsonString;
}

void jsonServerGetNewEchCertResponseStructDelete(struct jsonServerGetNewEchCertResponseStruct* serverGetNewEchCertRStruct) {
    if (!serverGetNewEchCertRStruct) {
        return;
    }
    free((char*)serverGetNewEchCertRStruct->msg);
    free(serverGetNewEchCertRStruct);
}

struct jsonServerGetNewEchCertResponseStruct* jsonServerGetNewEchCertResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonServerGetNewEchCertResponseStruct* serverGetNewEchCertRStruct = (struct jsonServerGetNewEchCertResponseStruct*)calloc(1, sizeof(struct jsonServerGetNewEchCertResponseStruct));
        if (!serverGetNewEchCertRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverGetNewEchCertRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetNewEchCertRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverGetNewEchCertRStruct->msg)) {
            jsonServerGetNewEchCertResponseStructDelete(serverGetNewEchCertRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetNewEchCertRStruct->obj = NULL;

        cJSON_Delete(jsonParser);
        return serverGetNewEchCertRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerGetNewEchCertResponseStruct* failRStruct = (struct jsonServerGetNewEchCertResponseStruct*)calloc(1, sizeof(struct jsonServerGetNewEchCertResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

void jsonServerGetCertHashPostStructDelete(struct jsonServerGetCertHashPostStruct* serverGetCertHashPostStruct) {
    if (!serverGetCertHashPostStruct) {
        return;
    }
    free((char*)serverGetCertHashPostStruct->certFile);
    free((char*)serverGetCertHashPostStruct->certContent);
    free(serverGetCertHashPostStruct);
}

const char* jsonServerGetCertHashPost(struct jsonServerGetCertHashPostStruct* serverGetCertHashPostStruct) {
    if (!serverGetCertHashPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverGetCertHashPostStruct is a null pointer");
        return NULL;
    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");
        return NULL;
    }

    if (serverGetCertHashPostStruct->certFile) {
        cJSON_AddStringToObject(json, "certFile", serverGetCertHashPostStruct->certFile);
    }
    if (serverGetCertHashPostStruct->certContent) {
        cJSON_AddStringToObject(json, "certContent", serverGetCertHashPostStruct->certContent);
    }

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");
        return NULL;
    }

    return jsonString;
}

void jsonServerGetRemoteCertHashPostStructDelete(struct jsonServerGetRemoteCertHashPostStruct* serverGetRemoteCertHashPostStruct) {
    if (!serverGetRemoteCertHashPostStruct) {
        return;
    }
    free((char*)serverGetRemoteCertHashPostStruct->server);
    free(serverGetRemoteCertHashPostStruct);
}

const char* jsonServerGetRemoteCertHashPost(struct jsonServerGetRemoteCertHashPostStruct* serverGetRemoteCertHashPostStruct) {
    if (!serverGetRemoteCertHashPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverGetRemoteCertHashPostStruct is a null pointer");
        return NULL;
    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");
        return NULL;
    }

    if (serverGetRemoteCertHashPostStruct->server) {
        cJSON_AddStringToObject(json, "server", serverGetRemoteCertHashPostStruct->server);
    }

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");
        return NULL;
    }

    return jsonString;
}

void jsonServerCertHashObjectArrayStructDelete(struct jsonServerCertHashObjectArrayStruct* certHashObjArrStruct, size_t arraySize) {
    if (!certHashObjArrStruct) {
        return;
    }
    for (size_t i = 0; i < arraySize; i++) {
        free((char*)certHashObjArrStruct[i].sha256);
    }
    free(certHashObjArrStruct);
}

void jsonServerGetCertHashResponseStructDelete(struct jsonServerGetCertHashResponseStruct* serverGetCertHashRStruct) {
    if (!serverGetCertHashRStruct) {
        return;
    }
    free((char*)serverGetCertHashRStruct->msg);
    if (serverGetCertHashRStruct->certHashObjArrStruct) {
        jsonServerCertHashObjectArrayStructDelete(serverGetCertHashRStruct->certHashObjArrStruct, serverGetCertHashRStruct->jsonServerCertHashObjectArrayStructSize);
        serverGetCertHashRStruct->certHashObjArrStruct = NULL;
    }
    free(serverGetCertHashRStruct);
}

static int jsonServerCertHashObjectArrayStructParse(cJSON* arrItem, struct jsonServerCertHashObjectArrayStruct* certHashStruct) {
    if (!arrItem) return 0;
    jsonCopyStringItem(arrItem, "sha256", &certHashStruct->sha256);
    return 1;
}

struct jsonServerGetCertHashResponseStruct* jsonServerGetCertHashResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsArray(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* objArray = cJSON_GetObjectItem(jsonParser, "obj");

        size_t arraySize = cJSON_GetArraySize(objArray);
        struct jsonServerCertHashObjectArrayStruct* certHashObjArrStruct = NULL;
        if (arraySize) {
            certHashObjArrStruct = (struct jsonServerCertHashObjectArrayStruct*)calloc(arraySize, sizeof(struct jsonServerCertHashObjectArrayStruct));
            if (!certHashObjArrStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "certHashObjArrStruct is a null pointer");
                cJSON_Delete(jsonParser);
                return NULL;
            }
            for (size_t i = 0; i < arraySize; i++) {
                cJSON* arrItem = cJSON_GetArrayItem(objArray, i);
                if (!jsonServerCertHashObjectArrayStructParse(arrItem, &certHashObjArrStruct[i])) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Array element is not parsed correctly, skipping...");
                    continue;
                }
            }
        }

        struct jsonServerGetCertHashResponseStruct* serverGetCertHashRStruct = (struct jsonServerGetCertHashResponseStruct*)calloc(1, sizeof(struct jsonServerGetCertHashResponseStruct));
        if (!serverGetCertHashRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverGetCertHashRStruct is a null pointer");
            jsonServerCertHashObjectArrayStructDelete(certHashObjArrStruct, arraySize);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetCertHashRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverGetCertHashRStruct->msg)) {
            jsonServerGetCertHashResponseStructDelete(serverGetCertHashRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetCertHashRStruct->jsonServerCertHashObjectArrayStructSize = arraySize;
        serverGetCertHashRStruct->certHashObjArrStruct = certHashObjArrStruct;

        cJSON_Delete(jsonParser);
        return serverGetCertHashRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerGetCertHashResponseStruct* failRStruct = (struct jsonServerGetCertHashResponseStruct*)calloc(1, sizeof(struct jsonServerGetCertHashResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}


void jsonServerGetRemoteCertHashResponseStructDelete(struct jsonServerGetRemoteCertHashResponseStruct* serverGetRemoteCertHashRStruct) {
    if (!serverGetRemoteCertHashRStruct) {
        return;
    }
    free((char*)serverGetRemoteCertHashRStruct->msg);
    if (serverGetRemoteCertHashRStruct->certHashObjArrStruct) {
        jsonServerCertHashObjectArrayStructDelete(serverGetRemoteCertHashRStruct->certHashObjArrStruct, serverGetRemoteCertHashRStruct->jsonServerCertHashObjectArrayStructSize);
        serverGetRemoteCertHashRStruct->certHashObjArrStruct = NULL;
    }
    free(serverGetRemoteCertHashRStruct);
}

struct jsonServerGetRemoteCertHashResponseStruct* jsonServerGetRemoteCertHashResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsArray(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* objArray = cJSON_GetObjectItem(jsonParser, "obj");

        size_t arraySize = cJSON_GetArraySize(objArray);
        struct jsonServerCertHashObjectArrayStruct* certHashObjArrStruct = NULL;
        if (arraySize) {
            certHashObjArrStruct = (struct jsonServerCertHashObjectArrayStruct*)calloc(arraySize, sizeof(struct jsonServerCertHashObjectArrayStruct));
            if (!certHashObjArrStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "certHashObjArrStruct is a null pointer");
                cJSON_Delete(jsonParser);
                return NULL;
            }
            for (size_t i = 0; i < arraySize; i++) {
                cJSON* arrItem = cJSON_GetArrayItem(objArray, i);
                if (!jsonServerCertHashObjectArrayStructParse(arrItem, &certHashObjArrStruct[i])) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Array element is not parsed correctly, skipping...");
                    continue;
                }
            }
        }

        struct jsonServerGetRemoteCertHashResponseStruct* serverGetRemoteCertHashRStruct = (struct jsonServerGetRemoteCertHashResponseStruct*)calloc(1, sizeof(struct jsonServerGetRemoteCertHashResponseStruct));
        if (!serverGetRemoteCertHashRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverGetRemoteCertHashRStruct is a null pointer");
            jsonServerCertHashObjectArrayStructDelete(certHashObjArrStruct, arraySize);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetRemoteCertHashRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverGetRemoteCertHashRStruct->msg)) {
            jsonServerGetRemoteCertHashResponseStructDelete(serverGetRemoteCertHashRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverGetRemoteCertHashRStruct->jsonServerCertHashObjectArrayStructSize = arraySize;
        serverGetRemoteCertHashRStruct->certHashObjArrStruct = certHashObjArrStruct;

        cJSON_Delete(jsonParser);
        return serverGetRemoteCertHashRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerGetRemoteCertHashResponseStruct* failRStruct = (struct jsonServerGetRemoteCertHashResponseStruct*)calloc(1, sizeof(struct jsonServerGetRemoteCertHashResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

void jsonServerScanRealityTargetPostStructDelete(struct jsonServerScanRealityTargetPostStruct* serverScanRealityTargetPostStruct) {
    if (!serverScanRealityTargetPostStruct) {
        return;
    }
    free((char*)serverScanRealityTargetPostStruct->target);
    free((char*)serverScanRealityTargetPostStruct->sni);
    free(serverScanRealityTargetPostStruct);
}

const char* jsonServerScanRealityTargetPost(struct jsonServerScanRealityTargetPostStruct* serverScanRealityTargetPostStruct) {
    if (!serverScanRealityTargetPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverScanRealityTargetPostStruct is a null pointer");
        return NULL;
    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");
        return NULL;
    }

    if (serverScanRealityTargetPostStruct->target) {
        cJSON_AddStringToObject(json, "target", serverScanRealityTargetPostStruct->target);
    }
    if (serverScanRealityTargetPostStruct->sni) {
        cJSON_AddStringToObject(json, "sni", serverScanRealityTargetPostStruct->sni);
    }
    if (serverScanRealityTargetPostStruct->xver) {
        cJSON_AddNumberToObject(json, "xver", serverScanRealityTargetPostStruct->xver);
    }
    cJSON_AddBoolToObject(json, "allowPrivate", serverScanRealityTargetPostStruct->allowPrivate);

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");
        return NULL;
    }

    return jsonString;
}

void jsonServerScanRealityTargetObjectStructDelete(struct jsonServerScanRealityTargetObjectStruct* scanRealityTargetObjStruct, size_t arraySize) {
    if (!scanRealityTargetObjStruct) {
        return;
    }
    free((char*)scanRealityTargetObjStruct->alpn);
    free((char*)scanRealityTargetObjStruct->certIssuer);
    free((char*)scanRealityTargetObjStruct->certSubject);
    free((char*)scanRealityTargetObjStruct->curveID);
    free((char*)scanRealityTargetObjStruct->host);
    free((char*)scanRealityTargetObjStruct->ip);
    free((char*)scanRealityTargetObjStruct->notAfter);
    free((char*)scanRealityTargetObjStruct->reason);
    if (scanRealityTargetObjStruct->serverNames) {
        jsonBulkStringArrayFree(scanRealityTargetObjStruct->serverNames, scanRealityTargetObjStruct->serverNamesCount);
    }
    free((char*)scanRealityTargetObjStruct->target);
    free((char*)scanRealityTargetObjStruct->tlsVersion);
    free(scanRealityTargetObjStruct);
}

void jsonServerScanRealityTargetResponseStructDelete(struct jsonServerScanRealityTargetResponseStruct* serverScanRealityTargetRStruct) {
    if (!serverScanRealityTargetRStruct) {
        return;
    }
    free((char*)serverScanRealityTargetRStruct->msg);
    if (serverScanRealityTargetRStruct->scanRealityTargetObjStruct) {
        jsonServerScanRealityTargetObjectStructDelete(serverScanRealityTargetRStruct->scanRealityTargetObjStruct, 1);
        serverScanRealityTargetRStruct->scanRealityTargetObjStruct = NULL;
    }
    free(serverScanRealityTargetRStruct);
}

static int jsonServerScanRealityTargetObjectStructParse(cJSON* obj, struct jsonServerScanRealityTargetObjectStruct* scanStruct) {
    if (!obj) return 0;
    jsonCopyStringItem(obj, "alpn", &scanStruct->alpn);
    jsonCopyBoolItem(obj, "certChainValid", &scanStruct->certChainValid);
    jsonCopyStringItem(obj, "certIssuer", &scanStruct->certIssuer);
    jsonCopyStringItem(obj, "certSubject", &scanStruct->certSubject);
    jsonCopyBoolItem(obj, "certValid", &scanStruct->certValid);
    jsonCopyStringItem(obj, "curveID", &scanStruct->curveID);
    jsonCopyBoolItem(obj, "feasible", &scanStruct->feasible);
    jsonCopyBoolItem(obj, "h2", &scanStruct->h2);
    jsonCopyStringItem(obj, "host", &scanStruct->host);
    jsonCopyStringItem(obj, "ip", &scanStruct->ip);
    jsonCopyNumberItem(obj, "latencyMs", (int64_t*)&scanStruct->latencyMs);
    jsonCopyStringItem(obj, "notAfter", &scanStruct->notAfter);
    jsonCopyNumberItem(obj, "port", (int64_t*)&scanStruct->port);
    jsonCopyBoolItem(obj, "privateTarget", &scanStruct->privateTarget);
    jsonCopyStringItem(obj, "reason", &scanStruct->reason);
    if (cJSON_HasObjectItem(obj, "serverNames") && cJSON_IsArray(cJSON_GetObjectItem(obj, "serverNames"))) {
        if (!jsonBulkStringArrayParse(cJSON_GetObjectItem(obj, "serverNames"), &scanStruct->serverNames, &scanStruct->serverNamesCount)) {
            return 0;
        }
    }
    jsonCopyStringItem(obj, "target", &scanStruct->target);
    jsonCopyBoolItem(obj, "tls13", &scanStruct->tls13);
    jsonCopyStringItem(obj, "tlsVersion", &scanStruct->tlsVersion);
    jsonCopyBoolItem(obj, "x25519", &scanStruct->x25519);
    return 1;
}

struct jsonServerScanRealityTargetResponseStruct* jsonServerScanRealityTargetResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsObject(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* obj = cJSON_GetObjectItem(jsonParser, "obj");

        struct jsonServerScanRealityTargetObjectStruct* scanRealityTargetObjStruct = (struct jsonServerScanRealityTargetObjectStruct*)calloc(1, sizeof(struct jsonServerScanRealityTargetObjectStruct));
        if (!scanRealityTargetObjStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "scanRealityTargetObjStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (!jsonServerScanRealityTargetObjectStructParse(obj, scanRealityTargetObjStruct)) {
            jsonServerScanRealityTargetObjectStructDelete(scanRealityTargetObjStruct, 1);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        struct jsonServerScanRealityTargetResponseStruct* serverScanRealityTargetRStruct = (struct jsonServerScanRealityTargetResponseStruct*)calloc(1, sizeof(struct jsonServerScanRealityTargetResponseStruct));
        if (!serverScanRealityTargetRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverScanRealityTargetRStruct is a null pointer");
            jsonServerScanRealityTargetObjectStructDelete(scanRealityTargetObjStruct, 1);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverScanRealityTargetRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverScanRealityTargetRStruct->msg)) {
            jsonServerScanRealityTargetResponseStructDelete(serverScanRealityTargetRStruct);
            jsonServerScanRealityTargetObjectStructDelete(scanRealityTargetObjStruct, 1);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverScanRealityTargetRStruct->scanRealityTargetObjStruct = scanRealityTargetObjStruct;

        cJSON_Delete(jsonParser);
        return serverScanRealityTargetRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerScanRealityTargetResponseStruct* failRStruct = (struct jsonServerScanRealityTargetResponseStruct*)calloc(1, sizeof(struct jsonServerScanRealityTargetResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

void jsonServerScanRealityTargetsPostStructDelete(struct jsonServerScanRealityTargetsPostStruct* serverScanRealityTargetsPostStruct) {
    if (!serverScanRealityTargetsPostStruct) {
        return;
    }
    free((char*)serverScanRealityTargetsPostStruct->targets);
    free(serverScanRealityTargetsPostStruct);
}

const char* jsonServerScanRealityTargetsPost(struct jsonServerScanRealityTargetsPostStruct* serverScanRealityTargetsPostStruct) {
    if (!serverScanRealityTargetsPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverScanRealityTargetsPostStruct is a null pointer");
        return NULL;
    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");
        return NULL;
    }

    if (serverScanRealityTargetsPostStruct->targets) {
        cJSON_AddStringToObject(json, "targets", serverScanRealityTargetsPostStruct->targets);
    }

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");
        return NULL;
    }

    return jsonString;
}

void jsonServerScanRealityTargetsResponseStructDelete(struct jsonServerScanRealityTargetsResponseStruct* serverScanRealityTargetsRStruct) {
    if (!serverScanRealityTargetsRStruct) {
        return;
    }
    free((char*)serverScanRealityTargetsRStruct->msg);
    if (serverScanRealityTargetsRStruct->scanRealityTargetsObjArrStruct) {
        jsonServerScanRealityTargetObjectStructDelete(serverScanRealityTargetsRStruct->scanRealityTargetsObjArrStruct, serverScanRealityTargetsRStruct->jsonServerScanRealityTargetObjectStructSize);
        serverScanRealityTargetsRStruct->scanRealityTargetsObjArrStruct = NULL;
    }
    free(serverScanRealityTargetsRStruct);
}

struct jsonServerScanRealityTargetsResponseStruct* jsonServerScanRealityTargetsResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsArray(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* objArray = cJSON_GetObjectItem(jsonParser, "obj");

        size_t arraySize = cJSON_GetArraySize(objArray);
        struct jsonServerScanRealityTargetObjectStruct* scanRealityTargetsObjArrStruct = NULL;
        if (arraySize) {
            scanRealityTargetsObjArrStruct = (struct jsonServerScanRealityTargetObjectStruct*)calloc(arraySize, sizeof(struct jsonServerScanRealityTargetObjectStruct));
            if (!scanRealityTargetsObjArrStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "scanRealityTargetsObjArrStruct is a null pointer");
                cJSON_Delete(jsonParser);
                return NULL;
            }
            for (size_t i = 0; i < arraySize; i++) {
                cJSON* arrItem = cJSON_GetArrayItem(objArray, i);
                if (!jsonServerScanRealityTargetObjectStructParse(arrItem, &scanRealityTargetsObjArrStruct[i])) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Array element is not parsed correctly, skipping...");
                    continue;
                }
            }
        }

        struct jsonServerScanRealityTargetsResponseStruct* serverScanRealityTargetsRStruct = (struct jsonServerScanRealityTargetsResponseStruct*)calloc(1, sizeof(struct jsonServerScanRealityTargetsResponseStruct));
        if (!serverScanRealityTargetsRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverScanRealityTargetsRStruct is a null pointer");
            jsonServerScanRealityTargetObjectStructDelete(scanRealityTargetsObjArrStruct, arraySize);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverScanRealityTargetsRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverScanRealityTargetsRStruct->msg)) {
            jsonServerScanRealityTargetsResponseStructDelete(serverScanRealityTargetsRStruct);
            jsonServerScanRealityTargetObjectStructDelete(scanRealityTargetsObjArrStruct, arraySize);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverScanRealityTargetsRStruct->jsonServerScanRealityTargetObjectStructSize = arraySize;
        serverScanRealityTargetsRStruct->scanRealityTargetsObjArrStruct = scanRealityTargetsObjArrStruct;

        cJSON_Delete(jsonParser);
        return serverScanRealityTargetsRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerScanRealityTargetsResponseStruct* failRStruct = (struct jsonServerScanRealityTargetsResponseStruct*)calloc(1, sizeof(struct jsonServerScanRealityTargetsResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}


void jsonServerClientIpsIpsItemStructDelete(struct jsonServerClientIpsIpsItemStruct* clientIpsObjArrIpsArrStruct, size_t arraySize) {
    if (!clientIpsObjArrIpsArrStruct) {
        return;
    }
    for (size_t i = 0; i < arraySize; i++) {
        free((char*)clientIpsObjArrIpsArrStruct[i].ip);
    }
    free(clientIpsObjArrIpsArrStruct);
}

void jsonServerClientIpsObjectArrayStructDelete(struct jsonServerClientIpsObjectArrayStruct* clientIpsObjArrStruct, size_t arraySize) {
    if (!clientIpsObjArrStruct) {
        return;
    }
    for (size_t i = 0; i < arraySize; i++) {
        free((char*)clientIpsObjArrStruct[i].clientEmail);
        if (clientIpsObjArrStruct[i].clientIpsObjArrIpsArrStruct) {
            jsonServerClientIpsIpsItemStructDelete(clientIpsObjArrStruct[i].clientIpsObjArrIpsArrStruct, clientIpsObjArrStruct[i].jsonServerClientIpsIpsItemStructSize);
            clientIpsObjArrStruct[i].clientIpsObjArrIpsArrStruct = NULL;
        }
    }
    free(clientIpsObjArrStruct);
}

void jsonServerClientIpsResponseStructDelete(struct jsonServerClientIpsResponseStruct* serverCliIpsRStruct) {
    if (!serverCliIpsRStruct) {
        return;
    }
    free((char*)serverCliIpsRStruct->msg);
    if (serverCliIpsRStruct->clientIpsObjArrStruct) {
        jsonServerClientIpsObjectArrayStructDelete(serverCliIpsRStruct->clientIpsObjArrStruct, serverCliIpsRStruct->jsonServerClientIpsObjectArrayStructSize);
        serverCliIpsRStruct->clientIpsObjArrStruct = NULL;
    }
    free(serverCliIpsRStruct);
}

static int jsonServerClientIpsIpsItemStructParse(cJSON* arrItem, struct jsonServerClientIpsIpsItemStruct* ipStruct) {
    if (!arrItem) return 0;
    jsonCopyStringItem(arrItem, "ip", &ipStruct->ip);
    jsonCopyNumberItem(arrItem, "timestamp", &ipStruct->timestamp);
    return 1;
}

static int jsonServerClientIpsObjectArrayStructParse(cJSON* arrItem, struct jsonServerClientIpsObjectArrayStruct* clientStruct) {
    if (!arrItem) return 0;
    jsonCopyStringItem(arrItem, "clientEmail", &clientStruct->clientEmail);
    jsonCopyNumberItem(arrItem, "id", (int64_t*)&clientStruct->id);
    if (cJSON_HasObjectItem(arrItem, "ips") && cJSON_IsArray(cJSON_GetObjectItem(arrItem, "ips"))) {
        cJSON* ipsArr = cJSON_GetObjectItem(arrItem, "ips");
        size_t ipsCount = cJSON_GetArraySize(ipsArr);
        if (ipsCount) {
            clientStruct->clientIpsObjArrIpsArrStruct = (struct jsonServerClientIpsIpsItemStruct*)calloc(ipsCount, sizeof(struct jsonServerClientIpsIpsItemStruct));
            if (!clientStruct->clientIpsObjArrIpsArrStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "clientIpsObjArrIpsArrStruct is a null pointer");
                return 0;
            }
            clientStruct->jsonServerClientIpsIpsItemStructSize = ipsCount;
            for (size_t i = 0; i < ipsCount; i++) {
                cJSON* ipItem = cJSON_GetArrayItem(ipsArr, i);
                if (!jsonServerClientIpsIpsItemStructParse(ipItem, &clientStruct->clientIpsObjArrIpsArrStruct[i])) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "IP array element is not parsed correctly, skipping...");
                    continue;
                }
            }
        }
    }
    return 1;
}

struct jsonServerClientIpsResponseStruct* jsonServerClientIpsResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsArray(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* objArray = cJSON_GetObjectItem(jsonParser, "obj");

        size_t arraySize = cJSON_GetArraySize(objArray);
        struct jsonServerClientIpsObjectArrayStruct* clientIpsObjArrStruct = NULL;
        if (arraySize) {
            clientIpsObjArrStruct = (struct jsonServerClientIpsObjectArrayStruct*)calloc(arraySize, sizeof(struct jsonServerClientIpsObjectArrayStruct));
            if (!clientIpsObjArrStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "clientIpsObjArrStruct is a null pointer");
                cJSON_Delete(jsonParser);
                return NULL;
            }
            for (size_t i = 0; i < arraySize; i++) {
                cJSON* arrItem = cJSON_GetArrayItem(objArray, i);
                if (!jsonServerClientIpsObjectArrayStructParse(arrItem, &clientIpsObjArrStruct[i])) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Array element is not parsed correctly, skipping...");
                    continue;
                }
            }
        }

        struct jsonServerClientIpsResponseStruct* serverCliIpsRStruct = (struct jsonServerClientIpsResponseStruct*)calloc(1, sizeof(struct jsonServerClientIpsResponseStruct));
        if (!serverCliIpsRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverCliIpsRStruct is a null pointer");
            jsonServerClientIpsObjectArrayStructDelete(clientIpsObjArrStruct, arraySize);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverCliIpsRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverCliIpsRStruct->msg)) {
            jsonServerClientIpsResponseStructDelete(serverCliIpsRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverCliIpsRStruct->jsonServerClientIpsObjectArrayStructSize = arraySize;
        serverCliIpsRStruct->clientIpsObjArrStruct = clientIpsObjArrStruct;

        cJSON_Delete(jsonParser);
        return serverCliIpsRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerClientIpsResponseStruct* failRStruct = (struct jsonServerClientIpsResponseStruct*)calloc(1, sizeof(struct jsonServerClientIpsResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}


void jsonServerSubmitClientIpsObjectPostStructDelete(struct jsonServerSubmitClientIpsObjectPostStruct* submitClientIpsObjArrPStruct, size_t arraySize) {
    if (!submitClientIpsObjArrPStruct) {
        return;
    }
    for (size_t i = 0; i < arraySize; i++) {
        free((char*)submitClientIpsObjArrPStruct[i].clientEmail);
        if (submitClientIpsObjArrPStruct[i].submitClientIpsObjIpsArrPStruct) {
            jsonServerClientIpsIpsItemStructDelete(submitClientIpsObjArrPStruct[i].submitClientIpsObjIpsArrPStruct, submitClientIpsObjArrPStruct[i].jsonServerClientIpsIpsItemStructSize);
            submitClientIpsObjArrPStruct[i].submitClientIpsObjIpsArrPStruct = NULL;
        }
    }
    free(submitClientIpsObjArrPStruct);
}

void jsonServerSubmitClientIpsPostStructDelete(struct jsonServerSubmitClientIpsPostStruct* submitClientIpsPostStruct) {
    if (!submitClientIpsPostStruct) {
        return;
    }
    if (submitClientIpsPostStruct->submitClientIpsObjArrPStruct) {
        jsonServerSubmitClientIpsObjectPostStructDelete(submitClientIpsPostStruct->submitClientIpsObjArrPStruct, submitClientIpsPostStruct->jsonServerSubmitClientIpsObjectPostStructSize);
        submitClientIpsPostStruct->submitClientIpsObjArrPStruct = NULL;
    }
    free(submitClientIpsPostStruct);
}

const char* jsonServerSubmitClientIpsPost(struct jsonServerSubmitClientIpsPostStruct* submitClientIpsPostStruct) {
    if (!submitClientIpsPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "submitClientIpsPostStruct is a null pointer");
        return NULL;
    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");
        return NULL;
    }

    cJSON* dataArray = cJSON_CreateArray();
    if (!dataArray) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create data array");
        cJSON_Delete(json);
        return NULL;
    }
    cJSON_AddItemToObject(json, "data", dataArray);

    for (size_t i = 0; i < submitClientIpsPostStruct->jsonServerSubmitClientIpsObjectPostStructSize; i++) {
        struct jsonServerSubmitClientIpsObjectPostStruct* client = &submitClientIpsPostStruct->submitClientIpsObjArrPStruct[i];

        cJSON* clientObj = cJSON_CreateObject();
        if (!clientObj) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "clientObj is a null pointer, failed to create json object");
            cJSON_Delete(json);
            return NULL;
        }
        cJSON_AddItemToArray(dataArray, clientObj);

        if (client->clientEmail) {
            cJSON_AddStringToObject(clientObj, "clientEmail", client->clientEmail);
        }

        cJSON* ipsArray = cJSON_CreateArray();
        if (!ipsArray) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create ips array");
            cJSON_Delete(json);
            return NULL;
        }
        cJSON_AddItemToObject(clientObj, "ips", ipsArray);

        for (size_t j = 0; j < client->jsonServerClientIpsIpsItemStructSize; j++) {
            struct jsonServerClientIpsIpsItemStruct* ip = &client->submitClientIpsObjIpsArrPStruct[j];
            cJSON* ipObj = cJSON_CreateObject();
            if (!ipObj) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "ipObj is a null pointer, failed to create json object");
                cJSON_Delete(json);
                return NULL;
            }
            cJSON_AddItemToArray(ipsArray, ipObj);

            if (ip->ip) {
                cJSON_AddStringToObject(ipObj, "ip", ip->ip);
            }
            cJSON_AddNumberToObject(ipObj, "timestamp", (double)ip->timestamp);
        }
    }

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");
        return NULL;
    }

    return jsonString;
}

void jsonServerSubmitClientIpsResponseStructDelete(struct jsonServerSubmitClientIpsResponseStruct* serverSubmitCliIpsRStruct) {
    if (!serverSubmitCliIpsRStruct) {
        return;
    }
    free((char*)serverSubmitCliIpsRStruct->msg);
    free(serverSubmitCliIpsRStruct);
}

struct jsonServerSubmitClientIpsResponseStruct* jsonServerSubmitClientIpsResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonServerSubmitClientIpsResponseStruct* serverSubmitCliIpsRStruct = (struct jsonServerSubmitClientIpsResponseStruct*)calloc(1, sizeof(struct jsonServerSubmitClientIpsResponseStruct));
        if (!serverSubmitCliIpsRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverSubmitCliIpsRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverSubmitCliIpsRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &serverSubmitCliIpsRStruct->msg)) {
            jsonServerSubmitClientIpsResponseStructDelete(serverSubmitCliIpsRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        serverSubmitCliIpsRStruct->obj = NULL;

        cJSON_Delete(jsonParser);
        return serverSubmitCliIpsRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonServerSubmitClientIpsResponseStruct* failRStruct = (struct jsonServerSubmitClientIpsResponseStruct*)calloc(1, sizeof(struct jsonServerSubmitClientIpsResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

