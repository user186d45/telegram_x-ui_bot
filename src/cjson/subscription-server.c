// subscription-server section - https://docs.sanaei.dev/docs/reference/api/subscription-server/

#include "../../include/cjson/subscription-server.h"
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

void jsonSubServerGetQueryStructDelete(struct jsonSubServerGetQueryStruct* subServerGetQueryStruct) {
    if (!subServerGetQueryStruct) {
        return;
    }
    free((char*)subServerGetQueryStruct->format);
    free(subServerGetQueryStruct);
}

void jsonSubServerGetResponseStructDelete(struct jsonSubServerGetResponseStruct* subServerGetRStruct) {
    if (!subServerGetRStruct) {
        return;
    }
    free((char*)subServerGetRStruct->msg);
    free((char*)subServerGetRStruct->obj);
    free(subServerGetRStruct);
}

void jsonSubServerJsonResponseStructDelete(struct jsonSubServerJsonResponseStruct* subServerJsonRStruct) {
    if (!subServerJsonRStruct) {
        return;
    }
    free((char*)subServerJsonRStruct->msg);
    free((char*)subServerJsonRStruct->obj);
    free(subServerJsonRStruct);
}

void jsonSubServerClashResponseStructDelete(struct jsonSubServerClashResponseStruct* subServerClashRStruct) {
    if (!subServerClashRStruct) {
        return;
    }
    free((char*)subServerClashRStruct->msg);
    free((char*)subServerClashRStruct->obj);
    free(subServerClashRStruct);
}

void jsonSubServerHwidStatusResponseStructDelete(struct jsonSubServerHwidStatusResponseStruct* subServerHwidStatusRStruct) {
    if (!subServerHwidStatusRStruct) {
        return;
    }
    free((char*)subServerHwidStatusRStruct->msg);
    free((char*)subServerHwidStatusRStruct->obj);
    free(subServerHwidStatusRStruct);
}

struct jsonSubServerGetResponseStruct* jsonSubServerGetResponse(const char* json) {
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
        struct jsonSubServerGetResponseStruct* subServerGetRStruct = (struct jsonSubServerGetResponseStruct*)calloc(1, sizeof(struct jsonSubServerGetResponseStruct));
        if (!subServerGetRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "subServerGetRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        subServerGetRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &subServerGetRStruct->msg)) {
            jsonSubServerGetResponseStructDelete(subServerGetRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))) {
            jsonCopyStringItem(jsonParser, "obj", &subServerGetRStruct->obj);
        }

        cJSON_Delete(jsonParser);
        return subServerGetRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonSubServerGetResponseStruct* failRStruct = (struct jsonSubServerGetResponseStruct*)calloc(1, sizeof(struct jsonSubServerGetResponseStruct));
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

struct jsonSubServerJsonResponseStruct* jsonSubServerJsonResponse(const char* json) {
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
        struct jsonSubServerJsonResponseStruct* subServerJsonRStruct = (struct jsonSubServerJsonResponseStruct*)calloc(1, sizeof(struct jsonSubServerJsonResponseStruct));
        if (!subServerJsonRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "subServerJsonRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        subServerJsonRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &subServerJsonRStruct->msg)) {
            jsonSubServerJsonResponseStructDelete(subServerJsonRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))) {
            jsonCopyStringItem(jsonParser, "obj", &subServerJsonRStruct->obj);
        }

        cJSON_Delete(jsonParser);
        return subServerJsonRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonSubServerJsonResponseStruct* failRStruct = (struct jsonSubServerJsonResponseStruct*)calloc(1, sizeof(struct jsonSubServerJsonResponseStruct));
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

struct jsonSubServerClashResponseStruct* jsonSubServerClashResponse(const char* json) {
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
        struct jsonSubServerClashResponseStruct* subServerClashRStruct = (struct jsonSubServerClashResponseStruct*)calloc(1, sizeof(struct jsonSubServerClashResponseStruct));
        if (!subServerClashRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "subServerClashRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        subServerClashRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &subServerClashRStruct->msg)) {
            jsonSubServerClashResponseStructDelete(subServerClashRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))) {
            jsonCopyStringItem(jsonParser, "obj", &subServerClashRStruct->obj);
        }

        cJSON_Delete(jsonParser);
        return subServerClashRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonSubServerClashResponseStruct* failRStruct = (struct jsonSubServerClashResponseStruct*)calloc(1, sizeof(struct jsonSubServerClashResponseStruct));
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

struct jsonSubServerHwidStatusResponseStruct* jsonSubServerHwidStatusResponse(const char* json) {
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
        struct jsonSubServerHwidStatusResponseStruct* subServerHwidStatusRStruct = (struct jsonSubServerHwidStatusResponseStruct*)calloc(1, sizeof(struct jsonSubServerHwidStatusResponseStruct));
        if (!subServerHwidStatusRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "subServerHwidStatusRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        subServerHwidStatusRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &subServerHwidStatusRStruct->msg)) {
            jsonSubServerHwidStatusResponseStructDelete(subServerHwidStatusRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))) {
            jsonCopyStringItem(jsonParser, "obj", &subServerHwidStatusRStruct->obj);
        }

        cJSON_Delete(jsonParser);
        return subServerHwidStatusRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonSubServerHwidStatusResponseStruct* failRStruct = (struct jsonSubServerHwidStatusResponseStruct*)calloc(1, sizeof(struct jsonSubServerHwidStatusResponseStruct));
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

const char* jsonSubServerGetQueryString(struct jsonSubServerGetQueryStruct* subServerGetQueryStruct) {
    DBG(LOG_INFO, "Function called");

    if (!subServerGetQueryStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "subServerGetQueryStruct is a null pointer");
        return NULL;
    }

    char* query = NULL;

    if (subServerGetQueryStruct->format) {
        char* formatEnc = jsonUrlEncode(subServerGetQueryStruct->format);
        if (!formatEnc) return NULL;
        size_t len = strlen("format=") + strlen(formatEnc) + 1;
        query = (char*)malloc(len);
        if (!query) {
            free(formatEnc);
            return NULL;
        }
        sprintf(query, "format=%s", formatEnc);
        free(formatEnc);
    }

    return query;
}