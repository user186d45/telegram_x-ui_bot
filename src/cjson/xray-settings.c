// xray-settings section - https://docs.sanaei.dev/docs/reference/api/xray-settings/

#include "../../include/cjson/xray-settings.h"
#include "../../include/cjson/jsonValidation.h"
#include "../../include/log.h"

#include <cjson/cJSON.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

static char* jsonCopyText(const char* value) {
    if (!value) return NULL;
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

static int jsonCopyNumberItem(cJSON* parent, const char* key, int64_t* dest) {
    if (!cJSON_HasObjectItem(parent, key) || !cJSON_IsNumber(cJSON_GetObjectItem(parent, key))) {
        return 1;
    }
    *dest = (int64_t)cJSON_GetObjectItem(parent, key)->valuedouble;
    return 1;
}

static int jsonCopyBoolItem(cJSON* parent, const char* key, unsigned char* dest) {
    if (!cJSON_HasObjectItem(parent, key) || !cJSON_IsBool(cJSON_GetObjectItem(parent, key))) {
        return 1;
    }
    *dest = cJSON_IsTrue(cJSON_GetObjectItem(parent, key)) ? 1 : 0;
    return 1;
}

static const char* jsonCopyMsg(cJSON* jsonParser) {
    const char* msg = NULL;
    jsonCopyStringItem(jsonParser, "msg", &msg);
    return msg;
}

static int jsonXrayConfigObjectResponseStructParse(cJSON* obj, struct jsonXrayConfigObjectResponseStruct* xrayConfigObj) {
    if (!obj) return 0;
    jsonCopyStringItem(obj, "xraySetting", &xrayConfigObj->xraySetting);
    jsonCopyStringItem(obj, "inboundTags", &xrayConfigObj->inboundTags);
    jsonCopyStringItem(obj, "clientReverseTags", &xrayConfigObj->clientReverseTags);
    jsonCopyStringItem(obj, "outboundTestUrl", &xrayConfigObj->outboundTestUrl);
    return 1;
}

void jsonXrayConfigObjectResponseStructDelete(struct jsonXrayConfigObjectResponseStruct* xrayConfigObjRStruct) {
    if (!xrayConfigObjRStruct) {
        return;
    }
    free((char*)xrayConfigObjRStruct->xraySetting);
    free((char*)xrayConfigObjRStruct->inboundTags);
    free((char*)xrayConfigObjRStruct->clientReverseTags);
    free((char*)xrayConfigObjRStruct->outboundTestUrl);
    free(xrayConfigObjRStruct);
}

void jsonXrayConfigResponseStructDelete(struct jsonXrayConfigResponseStruct* xrayConfigRStruct) {
    if (!xrayConfigRStruct) {
        return;
    }
    free((char*)xrayConfigRStruct->msg);
    if (xrayConfigRStruct->xrayConfigObjRStruct) {
        jsonXrayConfigObjectResponseStructDelete(xrayConfigRStruct->xrayConfigObjRStruct);
        xrayConfigRStruct->xrayConfigObjRStruct = NULL;
    }
    free(xrayConfigRStruct);
}

struct jsonXrayConfigResponseStruct* jsonXrayConfigResponse(const char* json) {
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

        struct jsonXrayConfigObjectResponseStruct* xrayConfigObjRStruct = (struct jsonXrayConfigObjectResponseStruct*)calloc(1, sizeof(struct jsonXrayConfigObjectResponseStruct));
        if (!xrayConfigObjRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayConfigObjRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        if (!jsonXrayConfigObjectResponseStructParse(obj, xrayConfigObjRStruct)) {
            jsonXrayConfigObjectResponseStructDelete(xrayConfigObjRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        struct jsonXrayConfigResponseStruct* xrayConfigRStruct = (struct jsonXrayConfigResponseStruct*)calloc(1, sizeof(struct jsonXrayConfigResponseStruct));
        if (!xrayConfigRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayConfigRStruct is a null pointer");
            jsonXrayConfigObjectResponseStructDelete(xrayConfigObjRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayConfigRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayConfigRStruct->msg)) {
            jsonXrayConfigResponseStructDelete(xrayConfigRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayConfigRStruct->xrayConfigObjRStruct = xrayConfigObjRStruct;

        cJSON_Delete(jsonParser);
        return xrayConfigRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayConfigResponseStruct* failRStruct = (struct jsonXrayConfigResponseStruct*)calloc(1, sizeof(struct jsonXrayConfigResponseStruct));
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

void jsonXrayGetDefaultJsonConfigResponseStructDelete(struct jsonXrayGetDefaultJsonConfigResponseStruct* xrayGetDefaultJsonConfigRStruct) {
    if (!xrayGetDefaultJsonConfigRStruct) {
        return;
    }
    free((char*)xrayGetDefaultJsonConfigRStruct->msg);
    free((char*)xrayGetDefaultJsonConfigRStruct->obj);
    free(xrayGetDefaultJsonConfigRStruct);
}

struct jsonXrayGetDefaultJsonConfigResponseStruct* jsonXrayGetDefaultJsonConfigResponse(const char* json) {
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
        struct jsonXrayGetDefaultJsonConfigResponseStruct* xrayGetDefaultJsonConfigRStruct = (struct jsonXrayGetDefaultJsonConfigResponseStruct*)calloc(1, sizeof(struct jsonXrayGetDefaultJsonConfigResponseStruct));
        if (!xrayGetDefaultJsonConfigRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayGetDefaultJsonConfigRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayGetDefaultJsonConfigRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayGetDefaultJsonConfigRStruct->msg)) {
            jsonXrayGetDefaultJsonConfigResponseStructDelete(xrayGetDefaultJsonConfigRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))) {
            jsonCopyStringItem(jsonParser, "obj", &xrayGetDefaultJsonConfigRStruct->obj);
        }

        cJSON_Delete(jsonParser);
        return xrayGetDefaultJsonConfigRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayGetDefaultJsonConfigResponseStruct* failRStruct = (struct jsonXrayGetDefaultJsonConfigResponseStruct*)calloc(1, sizeof(struct jsonXrayGetDefaultJsonConfigResponseStruct));
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

void jsonXrayGetOutboundsTrafficResponseStructDelete(struct jsonXrayGetOutboundsTrafficResponseStruct* xrayGetOutboundsTrafficRStruct) {
    if (!xrayGetOutboundsTrafficRStruct) {
        return;
    }
    free((char*)xrayGetOutboundsTrafficRStruct->msg);
    free((char*)xrayGetOutboundsTrafficRStruct->obj);
    free(xrayGetOutboundsTrafficRStruct);
}

struct jsonXrayGetOutboundsTrafficResponseStruct* jsonXrayGetOutboundsTrafficResponse(const char* json) {
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
        struct jsonXrayGetOutboundsTrafficResponseStruct* xrayGetOutboundsTrafficRStruct = (struct jsonXrayGetOutboundsTrafficResponseStruct*)calloc(1, sizeof(struct jsonXrayGetOutboundsTrafficResponseStruct));
        if (!xrayGetOutboundsTrafficRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayGetOutboundsTrafficRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayGetOutboundsTrafficRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayGetOutboundsTrafficRStruct->msg)) {
            jsonXrayGetOutboundsTrafficResponseStructDelete(xrayGetOutboundsTrafficRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))) {
            jsonCopyStringItem(jsonParser, "obj", &xrayGetOutboundsTrafficRStruct->obj);
        }

        cJSON_Delete(jsonParser);
        return xrayGetOutboundsTrafficRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayGetOutboundsTrafficResponseStruct* failRStruct = (struct jsonXrayGetOutboundsTrafficResponseStruct*)calloc(1, sizeof(struct jsonXrayGetOutboundsTrafficResponseStruct));
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

void jsonXrayGetXrayResultResponseStructDelete(struct jsonXrayGetXrayResultResponseStruct* xrayGetXrayResultRStruct) {
    if (!xrayGetXrayResultRStruct) {
        return;
    }
    free((char*)xrayGetXrayResultRStruct->msg);
    free((char*)xrayGetXrayResultRStruct->obj);
    free(xrayGetXrayResultRStruct);
}

struct jsonXrayGetXrayResultResponseStruct* jsonXrayGetXrayResultResponse(const char* json) {
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
        struct jsonXrayGetXrayResultResponseStruct* xrayGetXrayResultRStruct = (struct jsonXrayGetXrayResultResponseStruct*)calloc(1, sizeof(struct jsonXrayGetXrayResultResponseStruct));
        if (!xrayGetXrayResultRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayGetXrayResultRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayGetXrayResultRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayGetXrayResultRStruct->msg)) {
            jsonXrayGetXrayResultResponseStructDelete(xrayGetXrayResultRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))) {
            jsonCopyStringItem(jsonParser, "obj", &xrayGetXrayResultRStruct->obj);
        }

        cJSON_Delete(jsonParser);
        return xrayGetXrayResultRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayGetXrayResultResponseStruct* failRStruct = (struct jsonXrayGetXrayResultResponseStruct*)calloc(1, sizeof(struct jsonXrayGetXrayResultResponseStruct));
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

void jsonXrayResetOutboundsTrafficResponseStructDelete(struct jsonXrayResetOutboundsTrafficResponseStruct* xrayResetOutboundsTrafficRStruct) {
    if (!xrayResetOutboundsTrafficRStruct) {
        return;
    }
    free((char*)xrayResetOutboundsTrafficRStruct->msg);
    free(xrayResetOutboundsTrafficRStruct);
}

struct jsonXrayResetOutboundsTrafficResponseStruct* jsonXrayResetOutboundsTrafficResponse(const char* json) {
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
        struct jsonXrayResetOutboundsTrafficResponseStruct* xrayResetOutboundsTrafficRStruct = (struct jsonXrayResetOutboundsTrafficResponseStruct*)calloc(1, sizeof(struct jsonXrayResetOutboundsTrafficResponseStruct));
        if (!xrayResetOutboundsTrafficRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayResetOutboundsTrafficRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayResetOutboundsTrafficRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayResetOutboundsTrafficRStruct->msg)) {
            jsonXrayResetOutboundsTrafficResponseStructDelete(xrayResetOutboundsTrafficRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        cJSON_Delete(jsonParser);
        return xrayResetOutboundsTrafficRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayResetOutboundsTrafficResponseStruct* failRStruct = (struct jsonXrayResetOutboundsTrafficResponseStruct*)calloc(1, sizeof(struct jsonXrayResetOutboundsTrafficResponseStruct));
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

void jsonXrayTestOutboundResponseStructDelete(struct jsonXrayTestOutboundResponseStruct* xrayTestOutboundRStruct) {
    if (!xrayTestOutboundRStruct) {
        return;
    }
    free((char*)xrayTestOutboundRStruct->msg);
    free((char*)xrayTestOutboundRStruct->obj);
    free(xrayTestOutboundRStruct);
}

struct jsonXrayTestOutboundResponseStruct* jsonXrayTestOutboundResponse(const char* json) {
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
        struct jsonXrayTestOutboundResponseStruct* xrayTestOutboundRStruct = (struct jsonXrayTestOutboundResponseStruct*)calloc(1, sizeof(struct jsonXrayTestOutboundResponseStruct));
        if (!xrayTestOutboundRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayTestOutboundRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayTestOutboundRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayTestOutboundRStruct->msg)) {
            jsonXrayTestOutboundResponseStructDelete(xrayTestOutboundRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))) {
            jsonCopyStringItem(jsonParser, "obj", &xrayTestOutboundRStruct->obj);
        }

        cJSON_Delete(jsonParser);
        return xrayTestOutboundRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayTestOutboundResponseStruct* failRStruct = (struct jsonXrayTestOutboundResponseStruct*)calloc(1, sizeof(struct jsonXrayTestOutboundResponseStruct));
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

void jsonXrayTestOutboundsResponseStructDelete(struct jsonXrayTestOutboundsResponseStruct* xrayTestOutboundsRStruct) {
    if (!xrayTestOutboundsRStruct) {
        return;
    }
    free((char*)xrayTestOutboundsRStruct->msg);
    free((char*)xrayTestOutboundsRStruct->obj);
    free(xrayTestOutboundsRStruct);
}

struct jsonXrayTestOutboundsResponseStruct* jsonXrayTestOutboundsResponse(const char* json) {
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
        struct jsonXrayTestOutboundsResponseStruct* xrayTestOutboundsRStruct = (struct jsonXrayTestOutboundsResponseStruct*)calloc(1, sizeof(struct jsonXrayTestOutboundsResponseStruct));
        if (!xrayTestOutboundsRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayTestOutboundsRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayTestOutboundsRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayTestOutboundsRStruct->msg)) {
            jsonXrayTestOutboundsResponseStructDelete(xrayTestOutboundsRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))) {
            jsonCopyStringItem(jsonParser, "obj", &xrayTestOutboundsRStruct->obj);
        }

        cJSON_Delete(jsonParser);
        return xrayTestOutboundsRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayTestOutboundsResponseStruct* failRStruct = (struct jsonXrayTestOutboundsResponseStruct*)calloc(1, sizeof(struct jsonXrayTestOutboundsResponseStruct));
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

void jsonXrayBalancerStatusResponseStructDelete(struct jsonXrayBalancerStatusResponseStruct* xrayBalancerStatusRStruct) {
    if (!xrayBalancerStatusRStruct) {
        return;
    }
    free((char*)xrayBalancerStatusRStruct->msg);
    free((char*)xrayBalancerStatusRStruct->obj);
    free(xrayBalancerStatusRStruct);
}

struct jsonXrayBalancerStatusResponseStruct* jsonXrayBalancerStatusResponse(const char* json) {
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
        struct jsonXrayBalancerStatusResponseStruct* xrayBalancerStatusRStruct = (struct jsonXrayBalancerStatusResponseStruct*)calloc(1, sizeof(struct jsonXrayBalancerStatusResponseStruct));
        if (!xrayBalancerStatusRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayBalancerStatusRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayBalancerStatusRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayBalancerStatusRStruct->msg)) {
            jsonXrayBalancerStatusResponseStructDelete(xrayBalancerStatusRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))) {
            jsonCopyStringItem(jsonParser, "obj", &xrayBalancerStatusRStruct->obj);
        }

        cJSON_Delete(jsonParser);
        return xrayBalancerStatusRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayBalancerStatusResponseStruct* failRStruct = (struct jsonXrayBalancerStatusResponseStruct*)calloc(1, sizeof(struct jsonXrayBalancerStatusResponseStruct));
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
void jsonXrayBalancerOverrideResponseStructDelete(struct jsonXrayBalancerOverrideResponseStruct* xrayBalancerOverrideRStruct) {
    if (!xrayBalancerOverrideRStruct) {
        return;
    }
    free((char*)xrayBalancerOverrideRStruct->msg);
    free(xrayBalancerOverrideRStruct);
}

struct jsonXrayBalancerOverrideResponseStruct* jsonXrayBalancerOverrideResponse(const char* json) {
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
        struct jsonXrayBalancerOverrideResponseStruct* xrayBalancerOverrideRStruct = (struct jsonXrayBalancerOverrideResponseStruct*)calloc(1, sizeof(struct jsonXrayBalancerOverrideResponseStruct));
        if (!xrayBalancerOverrideRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayBalancerOverrideRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayBalancerOverrideRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayBalancerOverrideRStruct->msg)) {
            jsonXrayBalancerOverrideResponseStructDelete(xrayBalancerOverrideRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        cJSON_Delete(jsonParser);
        return xrayBalancerOverrideRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayBalancerOverrideResponseStruct* failRStruct = (struct jsonXrayBalancerOverrideResponseStruct*)calloc(1, sizeof(struct jsonXrayBalancerOverrideResponseStruct));
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

void jsonXrayRouteTestResponseStructDelete(struct jsonXrayRouteTestResponseStruct* xrayRouteTestRStruct) {
    if (!xrayRouteTestRStruct) {
        return;
    }
    free((char*)xrayRouteTestRStruct->msg);
    free((char*)xrayRouteTestRStruct->obj);
    free(xrayRouteTestRStruct);
}

struct jsonXrayRouteTestResponseStruct* jsonXrayRouteTestResponse(const char* json) {
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
        struct jsonXrayRouteTestResponseStruct* xrayRouteTestRStruct = (struct jsonXrayRouteTestResponseStruct*)calloc(1, sizeof(struct jsonXrayRouteTestResponseStruct));
        if (!xrayRouteTestRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayRouteTestRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayRouteTestRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayRouteTestRStruct->msg)) {
            jsonXrayRouteTestResponseStructDelete(xrayRouteTestRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))) {
            jsonCopyStringItem(jsonParser, "obj", &xrayRouteTestRStruct->obj);
        }

        cJSON_Delete(jsonParser);
        return xrayRouteTestRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayRouteTestResponseStruct* failRStruct = (struct jsonXrayRouteTestResponseStruct*)calloc(1, sizeof(struct jsonXrayRouteTestResponseStruct));
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

void jsonXrayGeoDataFilesResponseStructDelete(struct jsonXrayGeoDataFilesResponseStruct* xrayGeoDataFilesRStruct) {
    if (!xrayGeoDataFilesRStruct) {
        return;
    }
    free((char*)xrayGeoDataFilesRStruct->msg);
    free((char*)xrayGeoDataFilesRStruct->obj);
    free(xrayGeoDataFilesRStruct);
}

struct jsonXrayGeoDataFilesResponseStruct* jsonXrayGeoDataFilesResponse(const char* json) {
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
        struct jsonXrayGeoDataFilesResponseStruct* xrayGeoDataFilesRStruct = (struct jsonXrayGeoDataFilesResponseStruct*)calloc(1, sizeof(struct jsonXrayGeoDataFilesResponseStruct));
        if (!xrayGeoDataFilesRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayGeoDataFilesRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayGeoDataFilesRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayGeoDataFilesRStruct->msg)) {
            jsonXrayGeoDataFilesResponseStructDelete(xrayGeoDataFilesRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))) {
            jsonCopyStringItem(jsonParser, "obj", &xrayGeoDataFilesRStruct->obj);
        }

        cJSON_Delete(jsonParser);
        return xrayGeoDataFilesRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayGeoDataFilesResponseStruct* failRStruct = (struct jsonXrayGeoDataFilesResponseStruct*)calloc(1, sizeof(struct jsonXrayGeoDataFilesResponseStruct));
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

void jsonXrayGeoDataCategoriesResponseStructDelete(struct jsonXrayGeoDataCategoriesResponseStruct* xrayGeoDataCategoriesRStruct) {
    if (!xrayGeoDataCategoriesRStruct) {
        return;
    }
    free((char*)xrayGeoDataCategoriesRStruct->msg);
    free((char*)xrayGeoDataCategoriesRStruct->obj);
    free(xrayGeoDataCategoriesRStruct);
}

struct jsonXrayGeoDataCategoriesResponseStruct* jsonXrayGeoDataCategoriesResponse(const char* json) {
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
        struct jsonXrayGeoDataCategoriesResponseStruct* xrayGeoDataCategoriesRStruct = (struct jsonXrayGeoDataCategoriesResponseStruct*)calloc(1, sizeof(struct jsonXrayGeoDataCategoriesResponseStruct));
        if (!xrayGeoDataCategoriesRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayGeoDataCategoriesRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayGeoDataCategoriesRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayGeoDataCategoriesRStruct->msg)) {
            jsonXrayGeoDataCategoriesResponseStructDelete(xrayGeoDataCategoriesRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))) {
            jsonCopyStringItem(jsonParser, "obj", &xrayGeoDataCategoriesRStruct->obj);
        }

        cJSON_Delete(jsonParser);
        return xrayGeoDataCategoriesRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayGeoDataCategoriesResponseStruct* failRStruct = (struct jsonXrayGeoDataCategoriesResponseStruct*)calloc(1, sizeof(struct jsonXrayGeoDataCategoriesResponseStruct));
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

void jsonXrayGeoDataEntriesResponseStructDelete(struct jsonXrayGeoDataEntriesResponseStruct* xrayGeoDataEntriesRStruct) {
    if (!xrayGeoDataEntriesRStruct) {
        return;
    }
    free((char*)xrayGeoDataEntriesRStruct->msg);
    free((char*)xrayGeoDataEntriesRStruct->obj);
    free(xrayGeoDataEntriesRStruct);
}

struct jsonXrayGeoDataEntriesResponseStruct* jsonXrayGeoDataEntriesResponse(const char* json) {
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
        struct jsonXrayGeoDataEntriesResponseStruct* xrayGeoDataEntriesRStruct = (struct jsonXrayGeoDataEntriesResponseStruct*)calloc(1, sizeof(struct jsonXrayGeoDataEntriesResponseStruct));
        if (!xrayGeoDataEntriesRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayGeoDataEntriesRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayGeoDataEntriesRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayGeoDataEntriesRStruct->msg)) {
            jsonXrayGeoDataEntriesResponseStructDelete(xrayGeoDataEntriesRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))) {
            jsonCopyStringItem(jsonParser, "obj", &xrayGeoDataEntriesRStruct->obj);
        }

        cJSON_Delete(jsonParser);
        return xrayGeoDataEntriesRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayGeoDataEntriesResponseStruct* failRStruct = (struct jsonXrayGeoDataEntriesResponseStruct*)calloc(1, sizeof(struct jsonXrayGeoDataEntriesResponseStruct));
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

void jsonXrayGeoDataValidateResponseStructDelete(struct jsonXrayGeoDataValidateResponseStruct* xrayGeoDataValidateRStruct) {
    if (!xrayGeoDataValidateRStruct) {
        return;
    }
    free((char*)xrayGeoDataValidateRStruct->msg);
    free((char*)xrayGeoDataValidateRStruct->obj);
    free(xrayGeoDataValidateRStruct);
}

struct jsonXrayGeoDataValidateResponseStruct* jsonXrayGeoDataValidateResponse(const char* json) {
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
        struct jsonXrayGeoDataValidateResponseStruct* xrayGeoDataValidateRStruct = (struct jsonXrayGeoDataValidateResponseStruct*)calloc(1, sizeof(struct jsonXrayGeoDataValidateResponseStruct));
        if (!xrayGeoDataValidateRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayGeoDataValidateRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayGeoDataValidateRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayGeoDataValidateRStruct->msg)) {
            jsonXrayGeoDataValidateResponseStructDelete(xrayGeoDataValidateRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))) {
            jsonCopyStringItem(jsonParser, "obj", &xrayGeoDataValidateRStruct->obj);
        }

        cJSON_Delete(jsonParser);
        return xrayGeoDataValidateRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayGeoDataValidateResponseStruct* failRStruct = (struct jsonXrayGeoDataValidateResponseStruct*)calloc(1, sizeof(struct jsonXrayGeoDataValidateResponseStruct));
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

void jsonXrayOutboundSubsListResponseStructDelete(struct jsonXrayOutboundSubsListResponseStruct* xrayOutboundSubsListRStruct) {
    if (!xrayOutboundSubsListRStruct) {
        return;
    }
    free((char*)xrayOutboundSubsListRStruct->msg);
    free((char*)xrayOutboundSubsListRStruct->obj);
    free(xrayOutboundSubsListRStruct);
}

struct jsonXrayOutboundSubsListResponseStruct* jsonXrayOutboundSubsListResponse(const char* json) {
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
        struct jsonXrayOutboundSubsListResponseStruct* xrayOutboundSubsListRStruct = (struct jsonXrayOutboundSubsListResponseStruct*)calloc(1, sizeof(struct jsonXrayOutboundSubsListResponseStruct));
        if (!xrayOutboundSubsListRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayOutboundSubsListRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayOutboundSubsListRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayOutboundSubsListRStruct->msg)) {
            jsonXrayOutboundSubsListResponseStructDelete(xrayOutboundSubsListRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))) {
            jsonCopyStringItem(jsonParser, "obj", &xrayOutboundSubsListRStruct->obj);
        }

        cJSON_Delete(jsonParser);
        return xrayOutboundSubsListRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayOutboundSubsListResponseStruct* failRStruct = (struct jsonXrayOutboundSubsListResponseStruct*)calloc(1, sizeof(struct jsonXrayOutboundSubsListResponseStruct));
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

void jsonXrayOutboundSubsCreateResponseStructDelete(struct jsonXrayOutboundSubsCreateResponseStruct* xrayOutboundSubsCreateRStruct) {
    if (!xrayOutboundSubsCreateRStruct) {
        return;
    }
    free((char*)xrayOutboundSubsCreateRStruct->msg);
    free(xrayOutboundSubsCreateRStruct);
}

struct jsonXrayOutboundSubsCreateResponseStruct* jsonXrayOutboundSubsCreateResponse(const char* json) {
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
        struct jsonXrayOutboundSubsCreateResponseStruct* xrayOutboundSubsCreateRStruct = (struct jsonXrayOutboundSubsCreateResponseStruct*)calloc(1, sizeof(struct jsonXrayOutboundSubsCreateResponseStruct));
        if (!xrayOutboundSubsCreateRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayOutboundSubsCreateRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayOutboundSubsCreateRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayOutboundSubsCreateRStruct->msg)) {
            jsonXrayOutboundSubsCreateResponseStructDelete(xrayOutboundSubsCreateRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        cJSON_Delete(jsonParser);
        return xrayOutboundSubsCreateRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayOutboundSubsCreateResponseStruct* failRStruct = (struct jsonXrayOutboundSubsCreateResponseStruct*)calloc(1, sizeof(struct jsonXrayOutboundSubsCreateResponseStruct));
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

void jsonXrayOutboundSubsUpdateResponseStructDelete(struct jsonXrayOutboundSubsUpdateResponseStruct* xrayOutboundSubsUpdateRStruct) {
    if (!xrayOutboundSubsUpdateRStruct) {
        return;
    }
    free((char*)xrayOutboundSubsUpdateRStruct->msg);
    free(xrayOutboundSubsUpdateRStruct);
}

struct jsonXrayOutboundSubsUpdateResponseStruct* jsonXrayOutboundSubsUpdateResponse(const char* json) {
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
        struct jsonXrayOutboundSubsUpdateResponseStruct* xrayOutboundSubsUpdateRStruct = (struct jsonXrayOutboundSubsUpdateResponseStruct*)calloc(1, sizeof(struct jsonXrayOutboundSubsUpdateResponseStruct));
        if (!xrayOutboundSubsUpdateRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayOutboundSubsUpdateRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayOutboundSubsUpdateRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayOutboundSubsUpdateRStruct->msg)) {
            jsonXrayOutboundSubsUpdateResponseStructDelete(xrayOutboundSubsUpdateRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        cJSON_Delete(jsonParser);
        return xrayOutboundSubsUpdateRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayOutboundSubsUpdateResponseStruct* failRStruct = (struct jsonXrayOutboundSubsUpdateResponseStruct*)calloc(1, sizeof(struct jsonXrayOutboundSubsUpdateResponseStruct));
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

void jsonXrayOutboundSubsDeleteResponseStructDelete(struct jsonXrayOutboundSubsDeleteResponseStruct* xrayOutboundSubsDeleteRStruct) {
    if (!xrayOutboundSubsDeleteRStruct) {
        return;
    }
    free((char*)xrayOutboundSubsDeleteRStruct->msg);
    free(xrayOutboundSubsDeleteRStruct);
}

struct jsonXrayOutboundSubsDeleteResponseStruct* jsonXrayOutboundSubsDeleteResponse(const char* json) {
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
        struct jsonXrayOutboundSubsDeleteResponseStruct* xrayOutboundSubsDeleteRStruct = (struct jsonXrayOutboundSubsDeleteResponseStruct*)calloc(1, sizeof(struct jsonXrayOutboundSubsDeleteResponseStruct));
        if (!xrayOutboundSubsDeleteRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayOutboundSubsDeleteRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayOutboundSubsDeleteRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayOutboundSubsDeleteRStruct->msg)) {
            jsonXrayOutboundSubsDeleteResponseStructDelete(xrayOutboundSubsDeleteRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        cJSON_Delete(jsonParser);
        return xrayOutboundSubsDeleteRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayOutboundSubsDeleteResponseStruct* failRStruct = (struct jsonXrayOutboundSubsDeleteResponseStruct*)calloc(1, sizeof(struct jsonXrayOutboundSubsDeleteResponseStruct));
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

void jsonXrayOutboundSubsRefreshResponseStructDelete(struct jsonXrayOutboundSubsRefreshResponseStruct* xrayOutboundSubsRefreshRStruct) {
    if (!xrayOutboundSubsRefreshRStruct) {
        return;
    }
    free((char*)xrayOutboundSubsRefreshRStruct->msg);
    free((char*)xrayOutboundSubsRefreshRStruct->obj);
    free(xrayOutboundSubsRefreshRStruct);
}

struct jsonXrayOutboundSubsRefreshResponseStruct* jsonXrayOutboundSubsRefreshResponse(const char* json) {
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
        struct jsonXrayOutboundSubsRefreshResponseStruct* xrayOutboundSubsRefreshRStruct = (struct jsonXrayOutboundSubsRefreshResponseStruct*)calloc(1, sizeof(struct jsonXrayOutboundSubsRefreshResponseStruct));
        if (!xrayOutboundSubsRefreshRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayOutboundSubsRefreshRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayOutboundSubsRefreshRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayOutboundSubsRefreshRStruct->msg)) {
            jsonXrayOutboundSubsRefreshResponseStructDelete(xrayOutboundSubsRefreshRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))) {
            jsonCopyStringItem(jsonParser, "obj", &xrayOutboundSubsRefreshRStruct->obj);
        }

        cJSON_Delete(jsonParser);
        return xrayOutboundSubsRefreshRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayOutboundSubsRefreshResponseStruct* failRStruct = (struct jsonXrayOutboundSubsRefreshResponseStruct*)calloc(1, sizeof(struct jsonXrayOutboundSubsRefreshResponseStruct));
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

void jsonXrayOutboundSubsMoveResponseStructDelete(struct jsonXrayOutboundSubsMoveResponseStruct* xrayOutboundSubsMoveRStruct) {
    if (!xrayOutboundSubsMoveRStruct) {
        return;
    }
    free((char*)xrayOutboundSubsMoveRStruct->msg);
    free(xrayOutboundSubsMoveRStruct);
}

struct jsonXrayOutboundSubsMoveResponseStruct* jsonXrayOutboundSubsMoveResponse(const char* json) {
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
        struct jsonXrayOutboundSubsMoveResponseStruct* xrayOutboundSubsMoveRStruct = (struct jsonXrayOutboundSubsMoveResponseStruct*)calloc(1, sizeof(struct jsonXrayOutboundSubsMoveResponseStruct));
        if (!xrayOutboundSubsMoveRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayOutboundSubsMoveRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayOutboundSubsMoveRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayOutboundSubsMoveRStruct->msg)) {
            jsonXrayOutboundSubsMoveResponseStructDelete(xrayOutboundSubsMoveRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        cJSON_Delete(jsonParser);
        return xrayOutboundSubsMoveRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayOutboundSubsMoveResponseStruct* failRStruct = (struct jsonXrayOutboundSubsMoveResponseStruct*)calloc(1, sizeof(struct jsonXrayOutboundSubsMoveResponseStruct));
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

void jsonXrayOutboundSubsParseResponseStructDelete(struct jsonXrayOutboundSubsParseResponseStruct* xrayOutboundSubsParseRStruct) {
    if (!xrayOutboundSubsParseRStruct) {
        return;
    }
    free((char*)xrayOutboundSubsParseRStruct->msg);
    free((char*)xrayOutboundSubsParseRStruct->obj);
    free(xrayOutboundSubsParseRStruct);
}

struct jsonXrayOutboundSubsParseResponseStruct* jsonXrayOutboundSubsParseResponse(const char* json) {
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
        struct jsonXrayOutboundSubsParseResponseStruct* xrayOutboundSubsParseRStruct = (struct jsonXrayOutboundSubsParseResponseStruct*)calloc(1, sizeof(struct jsonXrayOutboundSubsParseResponseStruct));
        if (!xrayOutboundSubsParseRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayOutboundSubsParseRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayOutboundSubsParseRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayOutboundSubsParseRStruct->msg)) {
            jsonXrayOutboundSubsParseResponseStructDelete(xrayOutboundSubsParseRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))) {
            jsonCopyStringItem(jsonParser, "obj", &xrayOutboundSubsParseRStruct->obj);
        }

        cJSON_Delete(jsonParser);
        return xrayOutboundSubsParseRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayOutboundSubsParseResponseStruct* failRStruct = (struct jsonXrayOutboundSubsParseResponseStruct*)calloc(1, sizeof(struct jsonXrayOutboundSubsParseResponseStruct));
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

static char* jsonUrlEncode(const char* str) {
    if (!str) return NULL;
    size_t len = strlen(str);
    char* encoded = (char*)malloc(len * 3 + 1);
    if (!encoded) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "encoded is a null pointer, failed to allocate memory");
        return NULL;
    }
    char* p = encoded;
    for (size_t i = 0; i < len; i++) {
        unsigned char c = str[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '-' || c == '_' || c == '.' || c == '~') {
            *p++ = c;
        } else {
            sprintf(p, "%%%02X", c);
            p += 3;
        }
    }
    *p = '\0';
    return encoded;
}

static char* jsonFormEncode(const char* key, const char* value) {
    char* keyEnc = jsonUrlEncode(key);
    char* valEnc = jsonUrlEncode(value);
    if (!keyEnc || !valEnc) {
        free(keyEnc);
        free(valEnc);
        return NULL;
    }
    size_t totalLen = strlen(keyEnc) + 1 + strlen(valEnc) + 1;
    char* result = (char*)malloc(totalLen);
    if (!result) {
        free(keyEnc);
        free(valEnc);
        return NULL;
    }
    sprintf(result, "%s=%s", keyEnc, valEnc);
    free(keyEnc);
    free(valEnc);
    return result;
}

static char* jsonFormEncodeAppend(char* existing, const char* key, const char* value) {
    char* pair = jsonFormEncode(key, value);
    if (!pair) return existing;
    if (!existing) return pair;
    size_t existingLen = strlen(existing);
    size_t pairLen = strlen(pair);
    char* result = (char*)realloc(existing, existingLen + 1 + pairLen + 1);
    if (!result) {
        free(pair);
        return existing;
    }
    result[existingLen] = '&';
    strcpy(result + existingLen + 1, pair);
    free(pair);
    return result;
}

const char* jsonXrayUpdatePost(struct jsonXrayUpdatePostStruct* xrayUpdatePostStruct) {
    DBG(LOG_INFO, "Function called");

    if (!xrayUpdatePostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayUpdatePostStruct is a null pointer");
        return NULL;
    }

    char* body = NULL;

    if (xrayUpdatePostStruct->xraySetting) {
        body = jsonFormEncode("xraySetting", xrayUpdatePostStruct->xraySetting);
        if (!body) return NULL;
    }

    if (xrayUpdatePostStruct->outboundTestUrl) {
        body = jsonFormEncodeAppend(body, "outboundTestUrl", xrayUpdatePostStruct->outboundTestUrl);
        if (!body) return NULL;
    }

    return body;
}

void jsonXrayUpdatePostStructDelete(struct jsonXrayUpdatePostStruct* xrayUpdatePostStruct) {
    if (!xrayUpdatePostStruct) {
        return;
    }
    free((char*)xrayUpdatePostStruct->xraySetting);
    free((char*)xrayUpdatePostStruct->outboundTestUrl);
    free(xrayUpdatePostStruct);
}

const char* jsonXrayWarpPost(struct jsonXrayWarpPostStruct* xrayWarpPostStruct) {
    DBG(LOG_INFO, "Function called");

    if (!xrayWarpPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayWarpPostStruct is a null pointer");
        return NULL;
    }

    char* body = NULL;

    if (xrayWarpPostStruct->privateKey) {
        body = jsonFormEncode("privateKey", xrayWarpPostStruct->privateKey);
        if (!body) return NULL;
    }
    if (xrayWarpPostStruct->publicKey) {
        body = jsonFormEncodeAppend(body, "publicKey", xrayWarpPostStruct->publicKey);
        if (!body) return NULL;
    }
    if (xrayWarpPostStruct->license) {
        body = jsonFormEncodeAppend(body, "license", xrayWarpPostStruct->license);
        if (!body) return NULL;
    }
    if (xrayWarpPostStruct->interval >= 0) {
        char intervalStr[32];
        sprintf(intervalStr, "%d", xrayWarpPostStruct->interval);
        body = jsonFormEncodeAppend(body, "interval", intervalStr);
        if (!body) return NULL;
    }

    return body;
}

void jsonXrayWarpPostStructDelete(struct jsonXrayWarpPostStruct* xrayWarpPostStruct) {
    if (!xrayWarpPostStruct) {
        return;
    }
    free((char*)xrayWarpPostStruct->privateKey);
    free((char*)xrayWarpPostStruct->publicKey);
    free((char*)xrayWarpPostStruct->license);
    free(xrayWarpPostStruct);
}

const char* jsonXrayNordPost(struct jsonXrayNordPostStruct* xrayNordPostStruct) {
    DBG(LOG_INFO, "Function called");

    if (!xrayNordPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayNordPostStruct is a null pointer");
        return NULL;
    }

    char* body = NULL;

    if (xrayNordPostStruct->countryId) {
        body = jsonFormEncode("countryId", xrayNordPostStruct->countryId);
        if (!body) return NULL;
    }
    if (xrayNordPostStruct->token) {
        body = jsonFormEncodeAppend(body, "token", xrayNordPostStruct->token);
        if (!body) return NULL;
    }
    if (xrayNordPostStruct->key) {
        body = jsonFormEncodeAppend(body, "key", xrayNordPostStruct->key);
        if (!body) return NULL;
    }

    return body;
}

void jsonXrayNordPostStructDelete(struct jsonXrayNordPostStruct* xrayNordPostStruct) {
    if (!xrayNordPostStruct) {
        return;
    }
    free((char*)xrayNordPostStruct->countryId);
    free((char*)xrayNordPostStruct->token);
    free((char*)xrayNordPostStruct->key);
    free(xrayNordPostStruct);
}

const char* jsonXrayPiaPost(struct jsonXrayPiaPostStruct* xrayPiaPostStruct) {
    DBG(LOG_INFO, "Function called");

    if (!xrayPiaPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayPiaPostStruct is a null pointer");
        return NULL;
    }

    char* body = NULL;

    if (xrayPiaPostStruct->countryCode) {
        body = jsonFormEncode("countryCode", xrayPiaPostStruct->countryCode);
        if (!body) return NULL;
    }
    if (xrayPiaPostStruct->username) {
        body = jsonFormEncodeAppend(body, "username", xrayPiaPostStruct->username);
        if (!body) return NULL;
    }
    if (xrayPiaPostStruct->password) {
        body = jsonFormEncodeAppend(body, "password", xrayPiaPostStruct->password);
        if (!body) return NULL;
    }
    if (xrayPiaPostStruct->hostname) {
        body = jsonFormEncodeAppend(body, "hostname", xrayPiaPostStruct->hostname);
        if (!body) return NULL;
    }

    return body;
}

void jsonXrayPiaPostStructDelete(struct jsonXrayPiaPostStruct* xrayPiaPostStruct) {
    if (!xrayPiaPostStruct) {
        return;
    }
    free((char*)xrayPiaPostStruct->countryCode);
    free((char*)xrayPiaPostStruct->username);
    free((char*)xrayPiaPostStruct->password);
    free((char*)xrayPiaPostStruct->hostname);
    free(xrayPiaPostStruct);
}

const char* jsonXrayResetOutboundsTrafficPost(struct jsonXrayResetOutboundsTrafficPostStruct* xrayResetOutboundsTrafficPostStruct) {
    DBG(LOG_INFO, "Function called");

    if (!xrayResetOutboundsTrafficPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayResetOutboundsTrafficPostStruct is a null pointer");
        return NULL;
    }

    char* body = NULL;

    if (xrayResetOutboundsTrafficPostStruct->tag) {
        body = jsonFormEncode("tag", xrayResetOutboundsTrafficPostStruct->tag);
        if (!body) return NULL;
    }

    return body;
}

void jsonXrayResetOutboundsTrafficPostStructDelete(struct jsonXrayResetOutboundsTrafficPostStruct* xrayResetOutboundsTrafficPostStruct) {
    if (!xrayResetOutboundsTrafficPostStruct) {
        return;
    }
    free((char*)xrayResetOutboundsTrafficPostStruct->tag);
    free(xrayResetOutboundsTrafficPostStruct);
}

const char* jsonXrayTestOutboundPost(struct jsonXrayTestOutboundPostStruct* xrayTestOutboundPostStruct) {
    DBG(LOG_INFO, "Function called");

    if (!xrayTestOutboundPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayTestOutboundPostStruct is a null pointer");
        return NULL;
    }

    char* body = NULL;

    if (xrayTestOutboundPostStruct->outbound) {
        body = jsonFormEncode("outbound", xrayTestOutboundPostStruct->outbound);
        if (!body) return NULL;
    }
    if (xrayTestOutboundPostStruct->allOutbounds) {
        body = jsonFormEncodeAppend(body, "allOutbounds", xrayTestOutboundPostStruct->allOutbounds);
        if (!body) return NULL;
    }
    if (xrayTestOutboundPostStruct->mode) {
        body = jsonFormEncodeAppend(body, "mode", xrayTestOutboundPostStruct->mode);
        if (!body) return NULL;
    }

    return body;
}

void jsonXrayTestOutboundPostStructDelete(struct jsonXrayTestOutboundPostStruct* xrayTestOutboundPostStruct) {
    if (!xrayTestOutboundPostStruct) {
        return;
    }
    free((char*)xrayTestOutboundPostStruct->outbound);
    free((char*)xrayTestOutboundPostStruct->allOutbounds);
    free((char*)xrayTestOutboundPostStruct->mode);
    free(xrayTestOutboundPostStruct);
}

const char* jsonXrayTestOutboundsPost(struct jsonXrayTestOutboundsPostStruct* xrayTestOutboundsPostStruct) {
    DBG(LOG_INFO, "Function called");

    if (!xrayTestOutboundsPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayTestOutboundsPostStruct is a null pointer");
        return NULL;
    }

    char* body = NULL;

    if (xrayTestOutboundsPostStruct->outbounds) {
        body = jsonFormEncode("outbounds", xrayTestOutboundsPostStruct->outbounds);
        if (!body) return NULL;
    }
    if (xrayTestOutboundsPostStruct->allOutbounds) {
        body = jsonFormEncodeAppend(body, "allOutbounds", xrayTestOutboundsPostStruct->allOutbounds);
        if (!body) return NULL;
    }
    if (xrayTestOutboundsPostStruct->mode) {
        body = jsonFormEncodeAppend(body, "mode", xrayTestOutboundsPostStruct->mode);
        if (!body) return NULL;
    }

    return body;
}

void jsonXrayTestOutboundsPostStructDelete(struct jsonXrayTestOutboundsPostStruct* xrayTestOutboundsPostStruct) {
    if (!xrayTestOutboundsPostStruct) {
        return;
    }
    free((char*)xrayTestOutboundsPostStruct->outbounds);
    free((char*)xrayTestOutboundsPostStruct->allOutbounds);
    free((char*)xrayTestOutboundsPostStruct->mode);
    free(xrayTestOutboundsPostStruct);
}

const char* jsonXrayBalancerStatusPost(struct jsonXrayBalancerStatusPostStruct* xrayBalancerStatusPostStruct) {
    DBG(LOG_INFO, "Function called");

    if (!xrayBalancerStatusPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayBalancerStatusPostStruct is a null pointer");
        return NULL;
    }

    char* body = NULL;

    if (xrayBalancerStatusPostStruct->tags) {
        body = jsonFormEncode("tags", xrayBalancerStatusPostStruct->tags);
        if (!body) return NULL;
    }

    return body;
}

void jsonXrayBalancerStatusPostStructDelete(struct jsonXrayBalancerStatusPostStruct* xrayBalancerStatusPostStruct) {
    if (!xrayBalancerStatusPostStruct) {
        return;
    }
    free((char*)xrayBalancerStatusPostStruct->tags);
    free(xrayBalancerStatusPostStruct);
}

const char* jsonXrayBalancerOverridePost(struct jsonXrayBalancerOverridePostStruct* xrayBalancerOverridePostStruct) {
    DBG(LOG_INFO, "Function called");

    if (!xrayBalancerOverridePostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayBalancerOverridePostStruct is a null pointer");
        return NULL;
    }

    char* body = NULL;

    if (xrayBalancerOverridePostStruct->tag) {
        body = jsonFormEncode("tag", xrayBalancerOverridePostStruct->tag);
        if (!body) return NULL;
    }
    if (xrayBalancerOverridePostStruct->target) {
        body = jsonFormEncodeAppend(body, "target", xrayBalancerOverridePostStruct->target);
        if (!body) return NULL;
    }

    return body;
}

void jsonXrayBalancerOverridePostStructDelete(struct jsonXrayBalancerOverridePostStruct* xrayBalancerOverridePostStruct) {
    if (!xrayBalancerOverridePostStruct) {
        return;
    }
    free((char*)xrayBalancerOverridePostStruct->tag);
    free((char*)xrayBalancerOverridePostStruct->target);
    free(xrayBalancerOverridePostStruct);
}

const char* jsonXrayRouteTestPost(struct jsonXrayRouteTestPostStruct* xrayRouteTestPostStruct) {
    DBG(LOG_INFO, "Function called");

    if (!xrayRouteTestPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayRouteTestPostStruct is a null pointer");
        return NULL;
    }

    char* body = NULL;

    if (xrayRouteTestPostStruct->domain) {
        body = jsonFormEncode("domain", xrayRouteTestPostStruct->domain);
        if (!body) return NULL;
    }
    if (xrayRouteTestPostStruct->ip) {
        body = jsonFormEncodeAppend(body, "ip", xrayRouteTestPostStruct->ip);
        if (!body) return NULL;
    }
    if (xrayRouteTestPostStruct->port > 0) {
        char portStr[16];
        sprintf(portStr, "%d", xrayRouteTestPostStruct->port);
        body = jsonFormEncodeAppend(body, "port", portStr);
        if (!body) return NULL;
    }
    if (xrayRouteTestPostStruct->network) {
        body = jsonFormEncodeAppend(body, "network", xrayRouteTestPostStruct->network);
        if (!body) return NULL;
    }
    if (xrayRouteTestPostStruct->inboundTag) {
        body = jsonFormEncodeAppend(body, "inboundTag", xrayRouteTestPostStruct->inboundTag);
        if (!body) return NULL;
    }
    if (xrayRouteTestPostStruct->protocol) {
        body = jsonFormEncodeAppend(body, "protocol", xrayRouteTestPostStruct->protocol);
        if (!body) return NULL;
    }
    if (xrayRouteTestPostStruct->email) {
        body = jsonFormEncodeAppend(body, "email", xrayRouteTestPostStruct->email);
        if (!body) return NULL;
    }

    return body;
}

void jsonXrayRouteTestPostStructDelete(struct jsonXrayRouteTestPostStruct* xrayRouteTestPostStruct) {
    if (!xrayRouteTestPostStruct) {
        return;
    }
    free((char*)xrayRouteTestPostStruct->domain);
    free((char*)xrayRouteTestPostStruct->ip);
    free((char*)xrayRouteTestPostStruct->network);
    free((char*)xrayRouteTestPostStruct->inboundTag);
    free((char*)xrayRouteTestPostStruct->protocol);
    free((char*)xrayRouteTestPostStruct->email);
    free(xrayRouteTestPostStruct);
}

const char* jsonXrayGeoDataValidatePost(struct jsonXrayGeoDataValidatePostStruct* xrayGeoDataValidatePostStruct) {
    DBG(LOG_INFO, "Function called");

    if (!xrayGeoDataValidatePostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayGeoDataValidatePostStruct is a null pointer");
        return NULL;
    }

    char* body = NULL;

    if (xrayGeoDataValidatePostStruct->tokens) {
        body = jsonFormEncode("tokens", xrayGeoDataValidatePostStruct->tokens);
        if (!body) return NULL;
    }
    if (xrayGeoDataValidatePostStruct->kind) {
        body = jsonFormEncodeAppend(body, "kind", xrayGeoDataValidatePostStruct->kind);
        if (!body) return NULL;
    }

    return body;
}

void jsonXrayGeoDataValidatePostStructDelete(struct jsonXrayGeoDataValidatePostStruct* xrayGeoDataValidatePostStruct) {
    if (!xrayGeoDataValidatePostStruct) {
        return;
    }
    free((char*)xrayGeoDataValidatePostStruct->tokens);
    free((char*)xrayGeoDataValidatePostStruct->kind);
    free(xrayGeoDataValidatePostStruct);
}

const char* jsonXrayOutboundSubsCreatePost(struct jsonXrayOutboundSubsCreatePostStruct* xrayOutboundSubsCreatePostStruct) {
    DBG(LOG_INFO, "Function called");

    if (!xrayOutboundSubsCreatePostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayOutboundSubsCreatePostStruct is a null pointer");
        return NULL;
    }

    char* body = NULL;

    if (xrayOutboundSubsCreatePostStruct->remark) {
        body = jsonFormEncode("remark", xrayOutboundSubsCreatePostStruct->remark);
        if (!body) return NULL;
    }
    if (xrayOutboundSubsCreatePostStruct->url) {
        body = jsonFormEncodeAppend(body, "url", xrayOutboundSubsCreatePostStruct->url);
        if (!body) return NULL;
    }
    if (xrayOutboundSubsCreatePostStruct->tagPrefix) {
        body = jsonFormEncodeAppend(body, "tagPrefix", xrayOutboundSubsCreatePostStruct->tagPrefix);
        if (!body) return NULL;
    }
    if (xrayOutboundSubsCreatePostStruct->updateInterval >= 0) {
        char intervalStr[32];
        sprintf(intervalStr, "%d", xrayOutboundSubsCreatePostStruct->updateInterval);
        body = jsonFormEncodeAppend(body, "updateInterval", intervalStr);
        if (!body) return NULL;
    }
    if (xrayOutboundSubsCreatePostStruct->enabled) {
        body = jsonFormEncodeAppend(body, "enabled", xrayOutboundSubsCreatePostStruct->enabled ? "true" : "false");
        if (!body) return NULL;
    }
    if (xrayOutboundSubsCreatePostStruct->allowPrivate) {
        body = jsonFormEncodeAppend(body, "allowPrivate", xrayOutboundSubsCreatePostStruct->allowPrivate ? "true" : "false");
        if (!body) return NULL;
    }
    if (xrayOutboundSubsCreatePostStruct->allowInsecure) {
        body = jsonFormEncodeAppend(body, "allowInsecure", xrayOutboundSubsCreatePostStruct->allowInsecure ? "true" : "false");
        if (!body) return NULL;
    }
    if (xrayOutboundSubsCreatePostStruct->prepend) {
        body = jsonFormEncodeAppend(body, "prepend", xrayOutboundSubsCreatePostStruct->prepend ? "true" : "false");
        if (!body) return NULL;
    }
    if (xrayOutboundSubsCreatePostStruct->userAgent) {
        body = jsonFormEncodeAppend(body, "userAgent", xrayOutboundSubsCreatePostStruct->userAgent);
        if (!body) return NULL;
    }

    return body;
}

void jsonXrayOutboundSubsCreatePostStructDelete(struct jsonXrayOutboundSubsCreatePostStruct* xrayOutboundSubsCreatePostStruct) {
    if (!xrayOutboundSubsCreatePostStruct) {
        return;
    }
    free((char*)xrayOutboundSubsCreatePostStruct->remark);
    free((char*)xrayOutboundSubsCreatePostStruct->url);
    free((char*)xrayOutboundSubsCreatePostStruct->tagPrefix);
    free((char*)xrayOutboundSubsCreatePostStruct->userAgent);
    free(xrayOutboundSubsCreatePostStruct);
}

const char* jsonXrayOutboundSubsUpdatePost(struct jsonXrayOutboundSubsUpdatePostStruct* xrayOutboundSubsUpdatePostStruct) {
    DBG(LOG_INFO, "Function called");

    if (!xrayOutboundSubsUpdatePostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayOutboundSubsUpdatePostStruct is a null pointer");
        return NULL;
    }

    char* body = NULL;

    if (xrayOutboundSubsUpdatePostStruct->remark) {
        body = jsonFormEncode("remark", xrayOutboundSubsUpdatePostStruct->remark);
        if (!body) return NULL;
    }
    if (xrayOutboundSubsUpdatePostStruct->url) {
        body = jsonFormEncodeAppend(body, "url", xrayOutboundSubsUpdatePostStruct->url);
        if (!body) return NULL;
    }
    if (xrayOutboundSubsUpdatePostStruct->tagPrefix) {
        body = jsonFormEncodeAppend(body, "tagPrefix", xrayOutboundSubsUpdatePostStruct->tagPrefix);
        if (!body) return NULL;
    }
    if (xrayOutboundSubsUpdatePostStruct->updateInterval >= 0) {
        char intervalStr[32];
        sprintf(intervalStr, "%d", xrayOutboundSubsUpdatePostStruct->updateInterval);
        body = jsonFormEncodeAppend(body, "updateInterval", intervalStr);
        if (!body) return NULL;
    }
    if (xrayOutboundSubsUpdatePostStruct->enabled) {
        body = jsonFormEncodeAppend(body, "enabled", xrayOutboundSubsUpdatePostStruct->enabled ? "true" : "false");
        if (!body) return NULL;
    }
    if (xrayOutboundSubsUpdatePostStruct->allowPrivate) {
        body = jsonFormEncodeAppend(body, "allowPrivate", xrayOutboundSubsUpdatePostStruct->allowPrivate ? "true" : "false");
        if (!body) return NULL;
    }
    if (xrayOutboundSubsUpdatePostStruct->allowInsecure) {
        body = jsonFormEncodeAppend(body, "allowInsecure", xrayOutboundSubsUpdatePostStruct->allowInsecure ? "true" : "false");
        if (!body) return NULL;
    }
    if (xrayOutboundSubsUpdatePostStruct->prepend) {
        body = jsonFormEncodeAppend(body, "prepend", xrayOutboundSubsUpdatePostStruct->prepend ? "true" : "false");
        if (!body) return NULL;
    }
    if (xrayOutboundSubsUpdatePostStruct->userAgent) {
        body = jsonFormEncodeAppend(body, "userAgent", xrayOutboundSubsUpdatePostStruct->userAgent);
        if (!body) return NULL;
    }

    return body;
}

void jsonXrayOutboundSubsUpdatePostStructDelete(struct jsonXrayOutboundSubsUpdatePostStruct* xrayOutboundSubsUpdatePostStruct) {
    if (!xrayOutboundSubsUpdatePostStruct) {
        return;
    }
    free((char*)xrayOutboundSubsUpdatePostStruct->remark);
    free((char*)xrayOutboundSubsUpdatePostStruct->url);
    free((char*)xrayOutboundSubsUpdatePostStruct->tagPrefix);
    free((char*)xrayOutboundSubsUpdatePostStruct->userAgent);
    free(xrayOutboundSubsUpdatePostStruct);
}

const char* jsonXrayOutboundSubsMovePost(struct jsonXrayOutboundSubsMovePostStruct* xrayOutboundSubsMovePostStruct) {
    DBG(LOG_INFO, "Function called");

    if (!xrayOutboundSubsMovePostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayOutboundSubsMovePostStruct is a null pointer");
        return NULL;
    }

    char* body = NULL;

    if (xrayOutboundSubsMovePostStruct->dir) {
        body = jsonFormEncode("dir", xrayOutboundSubsMovePostStruct->dir);
        if (!body) return NULL;
    }

    return body;
}

void jsonXrayOutboundSubsMovePostStructDelete(struct jsonXrayOutboundSubsMovePostStruct* xrayOutboundSubsMovePostStruct) {
    if (!xrayOutboundSubsMovePostStruct) {
        return;
    }
    free((char*)xrayOutboundSubsMovePostStruct->dir);
    free(xrayOutboundSubsMovePostStruct);
}

const char* jsonXrayOutboundSubsParsePost(struct jsonXrayOutboundSubsParsePostStruct* xrayOutboundSubsParsePostStruct) {
    DBG(LOG_INFO, "Function called");

    if (!xrayOutboundSubsParsePostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayOutboundSubsParsePostStruct is a null pointer");
        return NULL;
    }

    char* body = NULL;

    if (xrayOutboundSubsParsePostStruct->url) {
        body = jsonFormEncode("url", xrayOutboundSubsParsePostStruct->url);
        if (!body) return NULL;
    }
    if (xrayOutboundSubsParsePostStruct->allowPrivate) {
        body = jsonFormEncodeAppend(body, "allowPrivate", xrayOutboundSubsParsePostStruct->allowPrivate ? "true" : "false");
        if (!body) return NULL;
    }
    if (xrayOutboundSubsParsePostStruct->allowInsecure) {
        body = jsonFormEncodeAppend(body, "allowInsecure", xrayOutboundSubsParsePostStruct->allowInsecure ? "true" : "false");
        if (!body) return NULL;
    }
    if (xrayOutboundSubsParsePostStruct->userAgent) {
        body = jsonFormEncodeAppend(body, "userAgent", xrayOutboundSubsParsePostStruct->userAgent);
        if (!body) return NULL;
    }

    return body;
}

void jsonXrayOutboundSubsParsePostStructDelete(struct jsonXrayOutboundSubsParsePostStruct* xrayOutboundSubsParsePostStruct) {
    if (!xrayOutboundSubsParsePostStruct) {
        return;
    }
    free((char*)xrayOutboundSubsParsePostStruct->url);
    free((char*)xrayOutboundSubsParsePostStruct->userAgent);
    free(xrayOutboundSubsParsePostStruct);
}

const char* jsonXrayGeoDataCategoriesQueryString(struct jsonXrayGeoDataCategoriesQueryStruct* xrayGeoDataCategoriesQueryStruct) {
    DBG(LOG_INFO, "Function called");

    if (!xrayGeoDataCategoriesQueryStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayGeoDataCategoriesQueryStruct is a null pointer");
        return NULL;
    }

    char* query = NULL;

    if (xrayGeoDataCategoriesQueryStruct->file) {
        char* fileEnc = jsonUrlEncode(xrayGeoDataCategoriesQueryStruct->file);
        if (!fileEnc) return NULL;
        char* prefixed = (char*)malloc(strlen(fileEnc) + 6);
        if (!prefixed) {
            free(fileEnc);
            return NULL;
        }
        sprintf(prefixed, "file=%s", fileEnc);
        free(fileEnc);
        query = prefixed;
    }
    if (xrayGeoDataCategoriesQueryStruct->q) {
        char* qEnc = jsonUrlEncode(xrayGeoDataCategoriesQueryStruct->q);
        if (!qEnc) {
            free(query);
            return NULL;
        }
        if (!query) query = qEnc;
        else {
            char* tmp = (char*)realloc(query, strlen(query) + 3 + strlen(qEnc) + 1);
            if (!tmp) {
                free(query);
                free(qEnc);
                return NULL;
            }
            query = tmp;
            sprintf(query + strlen(query), "&q=%s", qEnc);
            free(qEnc);
        }
    }
    if (xrayGeoDataCategoriesQueryStruct->offset > 0) {
        char offsetStr[32];
        sprintf(offsetStr, "%d", xrayGeoDataCategoriesQueryStruct->offset);
        if (!query) query = strdup(offsetStr);
        else {
            char* tmp = (char*)realloc(query, strlen(query) + 8 + strlen(offsetStr) + 1);
            if (!tmp) {
                free(query);
                return NULL;
            }
            query = tmp;
            sprintf(query + strlen(query), "&offset=%s", offsetStr);
        }
    }
    if (xrayGeoDataCategoriesQueryStruct->limit > 0) {
        char limitStr[32];
        sprintf(limitStr, "%d", xrayGeoDataCategoriesQueryStruct->limit);
        if (!query) query = strdup(limitStr);
        else {
            char* tmp = (char*)realloc(query, strlen(query) + 7 + strlen(limitStr) + 1);
            if (!tmp) {
                free(query);
                return NULL;
            }
            query = tmp;
            sprintf(query + strlen(query), "&limit=%s", limitStr);
        }
    }

    return query;
}

void jsonXrayGeoDataCategoriesQueryStructDelete(struct jsonXrayGeoDataCategoriesQueryStruct* xrayGeoDataCategoriesQueryStruct) {
    if (!xrayGeoDataCategoriesQueryStruct) {
        return;
    }
    free((char*)xrayGeoDataCategoriesQueryStruct->file);
    free((char*)xrayGeoDataCategoriesQueryStruct->q);
    free(xrayGeoDataCategoriesQueryStruct);
}

const char* jsonXrayGeoDataEntriesQueryString(struct jsonXrayGeoDataEntriesQueryStruct* xrayGeoDataEntriesQueryStruct) {
    DBG(LOG_INFO, "Function called");

    if (!xrayGeoDataEntriesQueryStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayGeoDataEntriesQueryStruct is a null pointer");
        return NULL;
    }

    char* query = NULL;

    if (xrayGeoDataEntriesQueryStruct->file) {
        char* fileEnc = jsonUrlEncode(xrayGeoDataEntriesQueryStruct->file);
        if (!fileEnc) return NULL;
        char* prefixed = (char*)malloc(strlen(fileEnc) + 6);
        if (!prefixed) {
            free(fileEnc);
            return NULL;
        }
        sprintf(prefixed, "file=%s", fileEnc);
        free(fileEnc);
        query = prefixed;
    }
    if (xrayGeoDataEntriesQueryStruct->code) {
        char* codeEnc = jsonUrlEncode(xrayGeoDataEntriesQueryStruct->code);
        if (!codeEnc) {
            free(query);
            return NULL;
        }
        if (!query) query = codeEnc;
        else {
            char* tmp = (char*)realloc(query, strlen(query) + 6 + strlen(codeEnc) + 1);
            if (!tmp) {
                free(query);
                free(codeEnc);
                return NULL;
            }
            query = tmp;
            sprintf(query + strlen(query), "&code=%s", codeEnc);
            free(codeEnc);
        }
    }
    if (xrayGeoDataEntriesQueryStruct->q) {
        char* qEnc = jsonUrlEncode(xrayGeoDataEntriesQueryStruct->q);
        if (!qEnc) {
            free(query);
            return NULL;
        }
        if (!query) query = qEnc;
        else {
            char* tmp = (char*)realloc(query, strlen(query) + 3 + strlen(qEnc) + 1);
            if (!tmp) {
                free(query);
                free(qEnc);
                return NULL;
            }
            query = tmp;
            sprintf(query + strlen(query), "&q=%s", qEnc);
            free(qEnc);
        }
    }
    if (xrayGeoDataEntriesQueryStruct->offset > 0) {
        char offsetStr[32];
        sprintf(offsetStr, "%d", xrayGeoDataEntriesQueryStruct->offset);
        if (!query) query = strdup(offsetStr);
        else {
            char* tmp = (char*)realloc(query, strlen(query) + 8 + strlen(offsetStr) + 1);
            if (!tmp) {
                free(query);
                return NULL;
            }
            query = tmp;
            sprintf(query + strlen(query), "&offset=%s", offsetStr);
        }
    }
    if (xrayGeoDataEntriesQueryStruct->limit > 0) {
        char limitStr[32];
        sprintf(limitStr, "%d", xrayGeoDataEntriesQueryStruct->limit);
        if (!query) query = strdup(limitStr);
        else {
            char* tmp = (char*)realloc(query, strlen(query) + 7 + strlen(limitStr) + 1);
            if (!tmp) {
                free(query);
                return NULL;
            }
            query = tmp;
            sprintf(query + strlen(query), "&limit=%s", limitStr);
        }
    }

    return query;
}

void jsonXrayGeoDataEntriesQueryStructDelete(struct jsonXrayGeoDataEntriesQueryStruct* xrayGeoDataEntriesQueryStruct) {
    if (!xrayGeoDataEntriesQueryStruct) {
        return;
    }
    free((char*)xrayGeoDataEntriesQueryStruct->file);
    free((char*)xrayGeoDataEntriesQueryStruct->code);
    free((char*)xrayGeoDataEntriesQueryStruct->q);
    free(xrayGeoDataEntriesQueryStruct);
}

void jsonXrayUpdateResponseStructDelete(struct jsonXrayUpdateResponseStruct* xrayUpdateRStruct) {
    if (!xrayUpdateRStruct) {
        return;
    }
    free((char*)xrayUpdateRStruct->msg);
    free(xrayUpdateRStruct);
}

struct jsonXrayUpdateResponseStruct* jsonXrayUpdateResponse(const char* json) {
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
        struct jsonXrayUpdateResponseStruct* xrayUpdateRStruct = (struct jsonXrayUpdateResponseStruct*)calloc(1, sizeof(struct jsonXrayUpdateResponseStruct));
        if (!xrayUpdateRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayUpdateRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayUpdateRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayUpdateRStruct->msg)) {
            jsonXrayUpdateResponseStructDelete(xrayUpdateRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        cJSON_Delete(jsonParser);
        return xrayUpdateRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayUpdateResponseStruct* failRStruct = (struct jsonXrayUpdateResponseStruct*)calloc(1, sizeof(struct jsonXrayUpdateResponseStruct));
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

void jsonXrayWarpResponseStructDelete(struct jsonXrayWarpResponseStruct* xrayWarpRStruct) {
    if (!xrayWarpRStruct) {
        return;
    }
    free((char*)xrayWarpRStruct->msg);
    free((char*)xrayWarpRStruct->obj);
    free(xrayWarpRStruct);
}

struct jsonXrayWarpResponseStruct* jsonXrayWarpResponse(const char* json) {
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
        struct jsonXrayWarpResponseStruct* xrayWarpRStruct = (struct jsonXrayWarpResponseStruct*)calloc(1, sizeof(struct jsonXrayWarpResponseStruct));
        if (!xrayWarpRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayWarpRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayWarpRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayWarpRStruct->msg)) {
            jsonXrayWarpResponseStructDelete(xrayWarpRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))) {
            jsonCopyStringItem(jsonParser, "obj", &xrayWarpRStruct->obj);
        }

        cJSON_Delete(jsonParser);
        return xrayWarpRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayWarpResponseStruct* failRStruct = (struct jsonXrayWarpResponseStruct*)calloc(1, sizeof(struct jsonXrayWarpResponseStruct));
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

void jsonXrayNordResponseStructDelete(struct jsonXrayNordResponseStruct* xrayNordRStruct) {
    if (!xrayNordRStruct) {
        return;
    }
    free((char*)xrayNordRStruct->msg);
    free((char*)xrayNordRStruct->obj);
    free(xrayNordRStruct);
}

struct jsonXrayNordResponseStruct* jsonXrayNordResponse(const char* json) {
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
        struct jsonXrayNordResponseStruct* xrayNordRStruct = (struct jsonXrayNordResponseStruct*)calloc(1, sizeof(struct jsonXrayNordResponseStruct));
        if (!xrayNordRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayNordRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayNordRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayNordRStruct->msg)) {
            jsonXrayNordResponseStructDelete(xrayNordRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))) {
            jsonCopyStringItem(jsonParser, "obj", &xrayNordRStruct->obj);
        }

        cJSON_Delete(jsonParser);
        return xrayNordRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayNordResponseStruct* failRStruct = (struct jsonXrayNordResponseStruct*)calloc(1, sizeof(struct jsonXrayNordResponseStruct));
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

void jsonXrayPiaResponseStructDelete(struct jsonXrayPiaResponseStruct* xrayPiaRStruct) {
    if (!xrayPiaRStruct) {
        return;
    }
    free((char*)xrayPiaRStruct->msg);
    free((char*)xrayPiaRStruct->obj);
    free(xrayPiaRStruct);
}

struct jsonXrayPiaResponseStruct* jsonXrayPiaResponse(const char* json) {
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
        struct jsonXrayPiaResponseStruct* xrayPiaRStruct = (struct jsonXrayPiaResponseStruct*)calloc(1, sizeof(struct jsonXrayPiaResponseStruct));
        if (!xrayPiaRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xrayPiaRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        xrayPiaRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &xrayPiaRStruct->msg)) {
            jsonXrayPiaResponseStructDelete(xrayPiaRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))) {
            jsonCopyStringItem(jsonParser, "obj", &xrayPiaRStruct->obj);
        }

        cJSON_Delete(jsonParser);
        return xrayPiaRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonXrayPiaResponseStruct* failRStruct = (struct jsonXrayPiaResponseStruct*)calloc(1, sizeof(struct jsonXrayPiaResponseStruct));
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
