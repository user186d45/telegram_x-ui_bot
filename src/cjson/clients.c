#include "../../include/cjson/clients.h"
#include "../../include/cjson/jsonValidation.h"
#include "../../include/log.h"

#include <cjson/cJSON.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

static int jsonCopyStringItem(cJSON* parent, const char* key, const char** dest) {
    if (!cJSON_HasObjectItem(parent, key) || !cJSON_IsString(cJSON_GetObjectItem(parent, key))) {
        return 1;

    }

    const char* value = cJSON_GetObjectItem(parent, key)->valuestring;
    size_t valueLen = strlen(value);
    char* valueCopy = (char*)malloc((valueLen + 1) * sizeof(char));
    if (!valueCopy) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "valueCopy is a null pointer, failed to allocate memory");

        return 0;

    }
    strncpy(valueCopy, value, valueLen);
    valueCopy[valueLen] = '\0';
    *dest = valueCopy;

    return 1;

}

static const char* jsonCopyMsg(cJSON* jsonParser) {
    const char* msg = NULL;
    jsonCopyStringItem(jsonParser, "msg", &msg);

    return msg;

}

static int jsonListEveryClientObjectTrafficObjectStructParse(cJSON* trafficObj, struct jsonListEveryClientObjectTrafficObjectStruct* trafficStruct) {
    if (!trafficObj) {
        return 0;

    }

    if (cJSON_HasObjectItem(trafficObj, "id") && cJSON_IsNumber(cJSON_GetObjectItem(trafficObj, "id"))) {
        trafficStruct->id = (int64_t)cJSON_GetObjectItem(trafficObj, "id")->valuedouble;

    }

    if (cJSON_HasObjectItem(trafficObj, "inboundId") && cJSON_IsNumber(cJSON_GetObjectItem(trafficObj, "inboundId"))) {
        trafficStruct->inboundId = (int64_t)cJSON_GetObjectItem(trafficObj, "inboundId")->valuedouble;

    }

    if (cJSON_HasObjectItem(trafficObj, "enable") && cJSON_IsBool(cJSON_GetObjectItem(trafficObj, "enable"))) {
        trafficStruct->enable = cJSON_IsTrue(cJSON_GetObjectItem(trafficObj, "enable")) ? 1 : 0;

    }

    if (cJSON_HasObjectItem(trafficObj, "email") && cJSON_IsString(cJSON_GetObjectItem(trafficObj, "email"))) {
        size_t emailLen = strlen(cJSON_GetObjectItem(trafficObj, "email")->valuestring);
        char* emailCopy = (char*)malloc((emailLen + 1) * sizeof(char));
        if (!emailCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "email is a null pointer, failed to allocate memory");

            return 0;

        }
        strncpy(emailCopy, cJSON_GetObjectItem(trafficObj, "email")->valuestring, emailLen);
        emailCopy[emailLen] = '\0';
        trafficStruct->email = emailCopy;

    }

    if (cJSON_HasObjectItem(trafficObj, "uuid") && cJSON_IsString(cJSON_GetObjectItem(trafficObj, "uuid"))) {
        size_t uuidLen = strlen(cJSON_GetObjectItem(trafficObj, "uuid")->valuestring);
        char* uuidCopy = (char*)malloc((uuidLen + 1) * sizeof(char));
        if (!uuidCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "uuid is a null pointer, failed to allocate memory");

            return 0;

        }
        strncpy(uuidCopy, cJSON_GetObjectItem(trafficObj, "uuid")->valuestring, uuidLen);
        uuidCopy[uuidLen] = '\0';
        trafficStruct->uuid = uuidCopy;

    }

    if (cJSON_HasObjectItem(trafficObj, "subId") && cJSON_IsString(cJSON_GetObjectItem(trafficObj, "subId"))) {
        size_t subIdLen = strlen(cJSON_GetObjectItem(trafficObj, "subId")->valuestring);
        char* subIdCopy = (char*)malloc((subIdLen + 1) * sizeof(char));
        if (!subIdCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "subId is a null pointer, failed to allocate memory");

            return 0;

        }
        strncpy(subIdCopy, cJSON_GetObjectItem(trafficObj, "subId")->valuestring, subIdLen);
        subIdCopy[subIdLen] = '\0';
        trafficStruct->subId = subIdCopy;

    }

    if (cJSON_HasObjectItem(trafficObj, "up") && cJSON_IsNumber(cJSON_GetObjectItem(trafficObj, "up"))) {
        trafficStruct->up = (int64_t)cJSON_GetObjectItem(trafficObj, "up")->valuedouble;

    }

    if (cJSON_HasObjectItem(trafficObj, "down") && cJSON_IsNumber(cJSON_GetObjectItem(trafficObj, "down"))) {
        trafficStruct->down = (int64_t)cJSON_GetObjectItem(trafficObj, "down")->valuedouble;

    }

    if (cJSON_HasObjectItem(trafficObj, "expiryTime") && cJSON_IsNumber(cJSON_GetObjectItem(trafficObj, "expiryTime"))) {
        trafficStruct->expiryTime = (int64_t)cJSON_GetObjectItem(trafficObj, "expiryTime")->valuedouble;

    }

    if (cJSON_HasObjectItem(trafficObj, "total") && cJSON_IsNumber(cJSON_GetObjectItem(trafficObj, "total"))) {
        trafficStruct->total = (int64_t)cJSON_GetObjectItem(trafficObj, "total")->valuedouble;

    }

    if (cJSON_HasObjectItem(trafficObj, "reset") && cJSON_IsNumber(cJSON_GetObjectItem(trafficObj, "reset"))) {
        trafficStruct->reset = (int)cJSON_GetObjectItem(trafficObj, "reset")->valuedouble;

    }

    if (cJSON_HasObjectItem(trafficObj, "resetDay") && cJSON_IsNumber(cJSON_GetObjectItem(trafficObj, "resetDay"))) {
        trafficStruct->resetDay = (int64_t)cJSON_GetObjectItem(trafficObj, "resetDay")->valuedouble;

    }

    if (cJSON_HasObjectItem(trafficObj, "resetMax") && cJSON_IsNumber(cJSON_GetObjectItem(trafficObj, "resetMax"))) {
        trafficStruct->resetMax = (int64_t)cJSON_GetObjectItem(trafficObj, "resetMax")->valuedouble;

    }

    if (cJSON_HasObjectItem(trafficObj, "resetWeekday") && cJSON_IsNumber(cJSON_GetObjectItem(trafficObj, "resetWeekday"))) {
        trafficStruct->resetWeekday = (int64_t)cJSON_GetObjectItem(trafficObj, "resetWeekday")->valuedouble;

    }

    if (cJSON_HasObjectItem(trafficObj, "resetCount") && cJSON_IsNumber(cJSON_GetObjectItem(trafficObj, "resetCount"))) {
        trafficStruct->resetCount = (int64_t)cJSON_GetObjectItem(trafficObj, "resetCount")->valuedouble;

    }

    if (cJSON_HasObjectItem(trafficObj, "lastOnline") && cJSON_IsNumber(cJSON_GetObjectItem(trafficObj, "lastOnline"))) {
        trafficStruct->lastOnline = (int64_t)cJSON_GetObjectItem(trafficObj, "lastOnline")->valuedouble;

    }

    if (cJSON_HasObjectItem(trafficObj, "lastSubFetch") && cJSON_IsNumber(cJSON_GetObjectItem(trafficObj, "lastSubFetch"))) {
        trafficStruct->lastSubFetch = (int64_t)cJSON_GetObjectItem(trafficObj, "lastSubFetch")->valuedouble;

    }

    return 1;

}

static int jsonListEveryClientArrayStructParse(cJSON* arrItem, struct jsonListEveryClientArrayStruct* cliStruct) {
    if (cJSON_HasObjectItem(arrItem, "id") && cJSON_IsNumber(cJSON_GetObjectItem(arrItem, "id"))) {
        cliStruct->id = (int64_t)cJSON_GetObjectItem(arrItem, "id")->valuedouble;

    }

    if (cJSON_HasObjectItem(arrItem, "email") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "email"))) {
        size_t emailLen = strlen(cJSON_GetObjectItem(arrItem, "email")->valuestring);
        char* emailCopy = (char*)malloc((emailLen + 1) * sizeof(char));
        if (!emailCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "email is a null pointer, failed to allocate memory");

            return 0;

        }
        strncpy(emailCopy, cJSON_GetObjectItem(arrItem, "email")->valuestring, emailLen);
        emailCopy[emailLen] = '\0';
        cliStruct->email = emailCopy;

    }

    if (cJSON_HasObjectItem(arrItem, "subId") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "subId"))) {
        size_t subIdLen = strlen(cJSON_GetObjectItem(arrItem, "subId")->valuestring);
        char* subIdCopy = (char*)malloc((subIdLen + 1) * sizeof(char));
        if (!subIdCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "subId is a null pointer, failed to allocate memory");

            return 0;

        }
        strncpy(subIdCopy, cJSON_GetObjectItem(arrItem, "subId")->valuestring, subIdLen);
        subIdCopy[subIdLen] = '\0';
        cliStruct->subId = subIdCopy;

    }

    if (cJSON_HasObjectItem(arrItem, "uuid") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "uuid"))) {
        size_t uuidLen = strlen(cJSON_GetObjectItem(arrItem, "uuid")->valuestring);
        char* uuidCopy = (char*)malloc((uuidLen + 1) * sizeof(char));
        if (!uuidCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "uuid is a null pointer, failed to allocate memory");

            return 0;

        }
        strncpy(uuidCopy, cJSON_GetObjectItem(arrItem, "uuid")->valuestring, uuidLen);
        uuidCopy[uuidLen] = '\0';
        cliStruct->uuid = uuidCopy;

    }

    if (cJSON_HasObjectItem(arrItem, "password") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "password"))) {
        size_t passwordLen = strlen(cJSON_GetObjectItem(arrItem, "password")->valuestring);
        char* passwordCopy = (char*)malloc((passwordLen + 1) * sizeof(char));
        if (!passwordCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "password is a null pointer, failed to allocate memory");

            return 0;

        }
        strncpy(passwordCopy, cJSON_GetObjectItem(arrItem, "password")->valuestring, passwordLen);
        passwordCopy[passwordLen] = '\0';
        cliStruct->password = passwordCopy;

    }

    if (cJSON_HasObjectItem(arrItem, "auth") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "auth"))) {
        size_t authLen = strlen(cJSON_GetObjectItem(arrItem, "auth")->valuestring);
        char* authCopy = (char*)malloc((authLen + 1) * sizeof(char));
        if (!authCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "auth is a null pointer, failed to allocate memory");

            return 0;

        }
        strncpy(authCopy, cJSON_GetObjectItem(arrItem, "auth")->valuestring, authLen);
        authCopy[authLen] = '\0';
        cliStruct->auth = authCopy;

    }

    if (cJSON_HasObjectItem(arrItem, "flow") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "flow"))) {
        size_t flowLen = strlen(cJSON_GetObjectItem(arrItem, "flow")->valuestring);
        char* flowCopy = (char*)malloc((flowLen + 1) * sizeof(char));
        if (!flowCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "flow is a null pointer, failed to allocate memory");

            return 0;

        }
        strncpy(flowCopy, cJSON_GetObjectItem(arrItem, "flow")->valuestring, flowLen);
        flowCopy[flowLen] = '\0';
        cliStruct->flow = flowCopy;

    }

    if (cJSON_HasObjectItem(arrItem, "security") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "security"))) {
        size_t securityLen = strlen(cJSON_GetObjectItem(arrItem, "security")->valuestring);
        char* securityCopy = (char*)malloc((securityLen + 1) * sizeof(char));
        if (!securityCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "security is a null pointer, failed to allocate memory");

            return 0;

        }
        strncpy(securityCopy, cJSON_GetObjectItem(arrItem, "security")->valuestring, securityLen);
        securityCopy[securityLen] = '\0';
        cliStruct->security = securityCopy;

    }

    if (cJSON_HasObjectItem(arrItem, "privateKey") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "privateKey"))) {
        size_t privateKeyLen = strlen(cJSON_GetObjectItem(arrItem, "privateKey")->valuestring);
        char* privateKeyCopy = (char*)malloc((privateKeyLen + 1) * sizeof(char));
        if (!privateKeyCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "privateKey is a null pointer, failed to allocate memory");

            return 0;

        }
        strncpy(privateKeyCopy, cJSON_GetObjectItem(arrItem, "privateKey")->valuestring, privateKeyLen);
        privateKeyCopy[privateKeyLen] = '\0';
        cliStruct->privateKey = privateKeyCopy;

    }

    if (cJSON_HasObjectItem(arrItem, "publicKey") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "publicKey"))) {
        size_t publicKeyLen = strlen(cJSON_GetObjectItem(arrItem, "publicKey")->valuestring);
        char* publicKeyCopy = (char*)malloc((publicKeyLen + 1) * sizeof(char));
        if (!publicKeyCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "publicKey is a null pointer, failed to allocate memory");

            return 0;

        }
        strncpy(publicKeyCopy, cJSON_GetObjectItem(arrItem, "publicKey")->valuestring, publicKeyLen);
        publicKeyCopy[publicKeyLen] = '\0';
        cliStruct->publicKey = publicKeyCopy;

    }

    if (cJSON_HasObjectItem(arrItem, "allowedIPs") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "allowedIPs"))) {
        size_t allowedIpsLen = strlen(cJSON_GetObjectItem(arrItem, "allowedIPs")->valuestring);
        char* allowedIpsCopy = (char*)malloc((allowedIpsLen + 1) * sizeof(char));
        if (!allowedIpsCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "allowedIps is a null pointer, failed to allocate memory");

            return 0;

        }
        strncpy(allowedIpsCopy, cJSON_GetObjectItem(arrItem, "allowedIPs")->valuestring, allowedIpsLen);
        allowedIpsCopy[allowedIpsLen] = '\0';
        cliStruct->allowedIps = allowedIpsCopy;

    }

    if (cJSON_HasObjectItem(arrItem, "preSharedKey") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "preSharedKey"))) {
        size_t preSharedKeyLen = strlen(cJSON_GetObjectItem(arrItem, "preSharedKey")->valuestring);
        char* preSharedKeyCopy = (char*)malloc((preSharedKeyLen + 1) * sizeof(char));
        if (!preSharedKeyCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "preSharedKey is a null pointer, failed to allocate memory");

            return 0;

        }
        strncpy(preSharedKeyCopy, cJSON_GetObjectItem(arrItem, "preSharedKey")->valuestring, preSharedKeyLen);
        preSharedKeyCopy[preSharedKeyLen] = '\0';
        cliStruct->preSharedKey = preSharedKeyCopy;

    }

    if (cJSON_HasObjectItem(arrItem, "keepAlive") && cJSON_IsNumber(cJSON_GetObjectItem(arrItem, "keepAlive"))) {
        cliStruct->keepAlive = (unsigned char)cJSON_GetObjectItem(arrItem, "keepAlive")->valuedouble;

    }

    if (cJSON_HasObjectItem(arrItem, "forwardedPorts") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "forwardedPorts"))) {
        size_t forwardedPortsLen = strlen(cJSON_GetObjectItem(arrItem, "forwardedPorts")->valuestring);
        char* forwardedPortsCopy = (char*)malloc((forwardedPortsLen + 1) * sizeof(char));
        if (!forwardedPortsCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "forwardedPorts is a null pointer, failed to allocate memory");

            return 0;

        }
        strncpy(forwardedPortsCopy, cJSON_GetObjectItem(arrItem, "forwardedPorts")->valuestring, forwardedPortsLen);
        forwardedPortsCopy[forwardedPortsLen] = '\0';
        cliStruct->forwardedPorts = forwardedPortsCopy;

    }

    if (cJSON_HasObjectItem(arrItem, "secret") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "secret"))) {
        size_t secretLen = strlen(cJSON_GetObjectItem(arrItem, "secret")->valuestring);
        char* secretCopy = (char*)malloc((secretLen + 1) * sizeof(char));
        if (!secretCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "secret is a null pointer, failed to allocate memory");

            return 0;

        }
        strncpy(secretCopy, cJSON_GetObjectItem(arrItem, "secret")->valuestring, secretLen);
        secretCopy[secretLen] = '\0';
        cliStruct->secret = secretCopy;

    }

    if (cJSON_HasObjectItem(arrItem, "adTag") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "adTag"))) {
        size_t adTagLen = strlen(cJSON_GetObjectItem(arrItem, "adTag")->valuestring);
        char* adTagCopy = (char*)malloc((adTagLen + 1) * sizeof(char));
        if (!adTagCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "secret is a null pointer, failed to allocate memory");

            return 0;

        }
        strncpy(adTagCopy, cJSON_GetObjectItem(arrItem, "adTag")->valuestring, adTagLen);
        adTagCopy[adTagLen] = '\0';
        cliStruct->adTag = adTagCopy;

    }

    if (cJSON_HasObjectItem(arrItem, "limitIp") && cJSON_IsNumber(cJSON_GetObjectItem(arrItem, "limitIp"))) {
        cliStruct->limitIp = (int64_t)cJSON_GetObjectItem(arrItem, "limitIp")->valuedouble;

    }

    if (cJSON_HasObjectItem(arrItem, "limitHwid") && cJSON_IsNumber(cJSON_GetObjectItem(arrItem, "limitHwid"))) {
        cliStruct->limitHwid = (int)cJSON_GetObjectItem(arrItem, "limitHwid")->valuedouble;

    }

    if (cJSON_HasObjectItem(arrItem, "totalGB") && cJSON_IsNumber(cJSON_GetObjectItem(arrItem, "totalGB"))) {
        cliStruct->totalGB = (int64_t)cJSON_GetObjectItem(arrItem, "totalGB")->valuedouble;

    }

    if (cJSON_HasObjectItem(arrItem, "expiryTime") && cJSON_IsNumber(cJSON_GetObjectItem(arrItem, "expiryTime"))) {
        cliStruct->expiryTime = (int64_t)cJSON_GetObjectItem(arrItem, "expiryTime")->valuedouble;

    }

    if (cJSON_HasObjectItem(arrItem, "enable") && cJSON_IsBool(cJSON_GetObjectItem(arrItem, "enable"))) {
        cliStruct->enable = cJSON_IsTrue(cJSON_GetObjectItem(arrItem, "enable")) ? 1 : 0;

    }

    if (cJSON_HasObjectItem(arrItem, "group") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "group"))) {
        size_t groupLen = strlen(cJSON_GetObjectItem(arrItem, "group")->valuestring);
        char* groupCopy = (char*)malloc((groupLen + 1) * sizeof(char));
        if (!groupCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "group is a null pointer, failed to allocate memory");

            return 0;

        }
        strncpy(groupCopy, cJSON_GetObjectItem(arrItem, "group")->valuestring, groupLen);
        groupCopy[groupLen] = '\0';
        cliStruct->group = groupCopy;

    }

    if (cJSON_HasObjectItem(arrItem, "comment") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "comment"))) {
        size_t commentLen = strlen(cJSON_GetObjectItem(arrItem, "comment")->valuestring);
        char* commentCopy = (char*)malloc((commentLen + 1) * sizeof(char));
        if (!commentCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "comment is a null pointer, failed to allocate memory");

            return 0;

        }
        strncpy(commentCopy, cJSON_GetObjectItem(arrItem, "comment")->valuestring, commentLen);
        commentCopy[commentLen] = '\0';
        cliStruct->comment = commentCopy;

    }

    if (cJSON_HasObjectItem(arrItem, "reset") && cJSON_IsNumber(cJSON_GetObjectItem(arrItem, "reset"))) {
        cliStruct->reset = (int)cJSON_GetObjectItem(arrItem, "reset")->valuedouble;

    }

    if (cJSON_HasObjectItem(arrItem, "resetDay") && cJSON_IsNumber(cJSON_GetObjectItem(arrItem, "resetDay"))) {
        cliStruct->resetDay = (int64_t)cJSON_GetObjectItem(arrItem, "resetDay")->valuedouble;

    }

    if (cJSON_HasObjectItem(arrItem, "resetMax") && cJSON_IsNumber(cJSON_GetObjectItem(arrItem, "resetMax"))) {
        cliStruct->resetMax = (int64_t)cJSON_GetObjectItem(arrItem, "resetMax")->valuedouble;

    }

    if (cJSON_HasObjectItem(arrItem, "trafficReset") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "trafficReset"))) {
        size_t trafficResetLen = strlen(cJSON_GetObjectItem(arrItem, "trafficReset")->valuestring);
        char* trafficResetCopy = (char*)malloc((trafficResetLen + 1) * sizeof(char));
        if (!trafficResetCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "trafficReset is a null pointer, failed to allocate memory");

            return 0;

        }
        strncpy(trafficResetCopy, cJSON_GetObjectItem(arrItem, "trafficReset")->valuestring, trafficResetLen);
        trafficResetCopy[trafficResetLen] = '\0';
        cliStruct->trafficReset = trafficResetCopy;

    }

    if (cJSON_HasObjectItem(arrItem, "trafficResetDay") && cJSON_IsNumber(cJSON_GetObjectItem(arrItem, "trafficResetDay"))) {
        cliStruct->trafficResetDay = (int)cJSON_GetObjectItem(arrItem, "trafficResetDay")->valuedouble;

    }

    if (cJSON_HasObjectItem(arrItem, "createdAt") && cJSON_IsNumber(cJSON_GetObjectItem(arrItem, "createdAt"))) {
        cliStruct->createdAt = (int64_t)cJSON_GetObjectItem(arrItem, "createdAt")->valuedouble;

    }

    if (cJSON_HasObjectItem(arrItem, "updatedAt") && cJSON_IsNumber(cJSON_GetObjectItem(arrItem, "updatedAt"))) {
        cliStruct->updatedAt = (int64_t)cJSON_GetObjectItem(arrItem, "updatedAt")->valuedouble;

    }

    if (cJSON_HasObjectItem(arrItem, "reverse") && !cJSON_IsNull(cJSON_GetObjectItem(arrItem, "reverse"))) {
        applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "reverse is not null, skipping");

    }

    if (cJSON_HasObjectItem(arrItem, "tgId") && cJSON_IsNumber(cJSON_GetObjectItem(arrItem, "tgId"))) {
        cliStruct->tgId = (int64_t)cJSON_GetObjectItem(arrItem, "tgId")->valuedouble;

    }

    if (cJSON_HasObjectItem(arrItem, "inboundIds") && cJSON_IsArray(cJSON_GetObjectItem(arrItem, "inboundIds"))) {
        cJSON* inboundIdsArr = cJSON_GetObjectItem(arrItem, "inboundIds");
        size_t inboundIdsCount = cJSON_GetArraySize(inboundIdsArr);
        if (inboundIdsCount) {
            cliStruct->inboundIds = (int*)malloc(inboundIdsCount * sizeof(int));
            if (!cliStruct->inboundIds) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "inboundIds is a null pointer, failed to allocate memory");

                return 0;

            }
            cliStruct->inboundIdsCount = (int64_t)inboundIdsCount;
            for (size_t i = 0; i < inboundIdsCount; i++) {
                cJSON* inboundIdsItem = cJSON_GetArrayItem(inboundIdsArr, i);
                if (cJSON_IsNumber(inboundIdsItem)) {
                    cliStruct->inboundIds[i] = (int)inboundIdsItem->valuedouble;

                }

            }

        }

    }

    if (cJSON_HasObjectItem(arrItem, "traffic") && cJSON_IsObject(cJSON_GetObjectItem(arrItem, "traffic"))) {
        cJSON* trafficObj = cJSON_GetObjectItem(arrItem, "traffic");
        struct jsonListEveryClientObjectTrafficObjectStruct* trafficStruct = (struct jsonListEveryClientObjectTrafficObjectStruct*)calloc(1, sizeof(struct jsonListEveryClientObjectTrafficObjectStruct));
        if (!trafficStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "trafficStruct is a null pointer, failed to allocate memory");

            return 0;

        }
        if (jsonListEveryClientObjectTrafficObjectStructParse(trafficObj, trafficStruct) == 0) {
            free(trafficStruct);

            return 0;

        }
        cliStruct->listEveryCliObjTrafficObjStruct = trafficStruct;

    }

    return 1;

}

struct jsonListEveryClientStruct* jsonListEveryClient(const char* json) {
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
        cJSON_HasObjectItem(jsonParser, "msg") &&
        cJSON_IsString(cJSON_GetObjectItem(jsonParser, "msg")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsArray(cJSON_GetObjectItem(jsonParser, "obj"))
        ) {
        cJSON* objArray = cJSON_GetObjectItem(jsonParser, "obj");
        if (!objArray) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "objArray is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        size_t arraySize = cJSON_GetArraySize(objArray);
        struct jsonListEveryClientArrayStruct* listEveryCliArrStruct = NULL;
        if (arraySize) {
            listEveryCliArrStruct = (struct jsonListEveryClientArrayStruct*)calloc(arraySize, sizeof(struct jsonListEveryClientArrayStruct));
            if (!listEveryCliArrStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listEveryCliArrStruct is a null pointer");

                cJSON_Delete(jsonParser);

                return NULL;

            }
            for (size_t i = 0; i < arraySize; i++) {
                cJSON* arrItem = cJSON_GetArrayItem(objArray, i);
                if (jsonListEveryClientArrayStructParse(arrItem, &listEveryCliArrStruct[i]) == 0) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Some item is not present in the array element, skipping the element...");

                }

            }
        }

        struct jsonListEveryClientStruct* listEveryCliStruct = (struct jsonListEveryClientStruct*)malloc(sizeof(struct jsonListEveryClientStruct));
        if (!listEveryCliStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listEveryCliStruct is a null pointer");

            free(listEveryCliArrStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        listEveryCliStruct->success = 1;

        char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
        size_t msgLen = strlen(msg);
        char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
        if (!msgCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "msgCopy is a null pointer");

            free(listEveryCliStruct);

            free(listEveryCliArrStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }
        strncpy(msgCopy, msg, msgLen);
        msgCopy[msgLen] = '\0';
        listEveryCliStruct->msg = msgCopy;

        listEveryCliStruct->jsonListEveryClientArrayStructSize = arraySize;
        listEveryCliStruct->listEveryCliArrStruct = listEveryCliArrStruct;

        cJSON_Delete(jsonParser);

        return listEveryCliStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonListEveryClientStruct* failRStruct = (struct jsonListEveryClientStruct*)calloc(1, sizeof(struct jsonListEveryClientStruct));
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

void jsonListEveryClientObjectTrafficObjectStructDelete(struct jsonListEveryClientObjectTrafficObjectStruct* listEveryCliObjTrafficObjStruct) {
    if (!listEveryCliObjTrafficObjStruct) {
        return;

    }

    free((char*)listEveryCliObjTrafficObjStruct->email);
    free((char*)listEveryCliObjTrafficObjStruct->uuid);
    free((char*)listEveryCliObjTrafficObjStruct->subId);

    free(listEveryCliObjTrafficObjStruct);

}

void jsonListEveryClientArrayStructDelete(struct jsonListEveryClientArrayStruct* listEveryCliArrStruct, size_t arraySize) {
    if (!listEveryCliArrStruct) {
        return;

    }

    for (size_t i = 0; i < arraySize; i++) {
        free((char*)listEveryCliArrStruct[i].email);
        free((char*)listEveryCliArrStruct[i].subId);
        free((char*)listEveryCliArrStruct[i].uuid);
        free((char*)listEveryCliArrStruct[i].password);
        free((char*)listEveryCliArrStruct[i].auth);
        free((char*)listEveryCliArrStruct[i].flow);
        free((char*)listEveryCliArrStruct[i].security);
        free((char*)listEveryCliArrStruct[i].privateKey);
        free((char*)listEveryCliArrStruct[i].publicKey);
        free((char*)listEveryCliArrStruct[i].allowedIps);
        free((char*)listEveryCliArrStruct[i].preSharedKey);
        free((char*)listEveryCliArrStruct[i].forwardedPorts);
        free((char*)listEveryCliArrStruct[i].secret);
        free((char*)listEveryCliArrStruct[i].adTag);
        free((char*)listEveryCliArrStruct[i].group);
        free((char*)listEveryCliArrStruct[i].comment);
        free((char*)listEveryCliArrStruct[i].trafficReset);

        if (listEveryCliArrStruct[i].createdAt) {
            // createdAt was parsed into an integer, no string allocation to free.

        }

        free(listEveryCliArrStruct[i].inboundIds);

        if (listEveryCliArrStruct[i].listEveryCliObjTrafficObjStruct) {
            jsonListEveryClientObjectTrafficObjectStructDelete(listEveryCliArrStruct[i].listEveryCliObjTrafficObjStruct);
            listEveryCliArrStruct[i].listEveryCliObjTrafficObjStruct = NULL;

        }

    }

    free(listEveryCliArrStruct);

}

void jsonListEveryClientStructDelete(struct jsonListEveryClientStruct* listEveryCliStruct) {
    if (!listEveryCliStruct) {
        return;

    }

    free((char*)listEveryCliStruct->msg);

    if (listEveryCliStruct->listEveryCliArrStruct) {
        jsonListEveryClientArrayStructDelete(listEveryCliStruct->listEveryCliArrStruct, listEveryCliStruct->jsonListEveryClientArrayStructSize);

        listEveryCliStruct->listEveryCliArrStruct = NULL;

    }

    free(listEveryCliStruct);

}

static int jsonFetchClientByEmailObjectClientObjectStructParse(cJSON* clientObj, struct jsonFetchClientByEmailObjectClientObjectStruct* cliStruct) {
    if (!clientObj) {
        return 0;
    }

    if (cJSON_HasObjectItem(clientObj, "id") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "id"))) {
        cliStruct->id = (int64_t)cJSON_GetObjectItem(clientObj, "id")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "email") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "email"))) {
        size_t emailLen = strlen(cJSON_GetObjectItem(clientObj, "email")->valuestring);
        char* emailCopy = (char*)malloc((emailLen + 1) * sizeof(char));
        if (!emailCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "email is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(emailCopy, cJSON_GetObjectItem(clientObj, "email")->valuestring, emailLen);
        emailCopy[emailLen] = '\0';
        cliStruct->email = emailCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "subId") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "subId"))) {
        size_t subIdLen = strlen(cJSON_GetObjectItem(clientObj, "subId")->valuestring);
        char* subIdCopy = (char*)malloc((subIdLen + 1) * sizeof(char));
        if (!subIdCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "subId is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(subIdCopy, cJSON_GetObjectItem(clientObj, "subId")->valuestring, subIdLen);
        subIdCopy[subIdLen] = '\0';
        cliStruct->subId = subIdCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "uuid") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "uuid"))) {
        size_t uuidLen = strlen(cJSON_GetObjectItem(clientObj, "uuid")->valuestring);
        char* uuidCopy = (char*)malloc((uuidLen + 1) * sizeof(char));
        if (!uuidCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "uuid is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(uuidCopy, cJSON_GetObjectItem(clientObj, "uuid")->valuestring, uuidLen);
        uuidCopy[uuidLen] = '\0';
        cliStruct->uuid = uuidCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "password") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "password"))) {
        size_t passwordLen = strlen(cJSON_GetObjectItem(clientObj, "password")->valuestring);
        char* passwordCopy = (char*)malloc((passwordLen + 1) * sizeof(char));
        if (!passwordCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "password is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(passwordCopy, cJSON_GetObjectItem(clientObj, "password")->valuestring, passwordLen);
        passwordCopy[passwordLen] = '\0';
        cliStruct->password = passwordCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "auth") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "auth"))) {
        size_t authLen = strlen(cJSON_GetObjectItem(clientObj, "auth")->valuestring);
        char* authCopy = (char*)malloc((authLen + 1) * sizeof(char));
        if (!authCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "auth is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(authCopy, cJSON_GetObjectItem(clientObj, "auth")->valuestring, authLen);
        authCopy[authLen] = '\0';
        cliStruct->auth = authCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "flow") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "flow"))) {
        size_t flowLen = strlen(cJSON_GetObjectItem(clientObj, "flow")->valuestring);
        char* flowCopy = (char*)malloc((flowLen + 1) * sizeof(char));
        if (!flowCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "flow is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(flowCopy, cJSON_GetObjectItem(clientObj, "flow")->valuestring, flowLen);
        flowCopy[flowLen] = '\0';
        cliStruct->flow = flowCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "security") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "security"))) {
        size_t securityLen = strlen(cJSON_GetObjectItem(clientObj, "security")->valuestring);
        char* securityCopy = (char*)malloc((securityLen + 1) * sizeof(char));
        if (!securityCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "security is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(securityCopy, cJSON_GetObjectItem(clientObj, "security")->valuestring, securityLen);
        securityCopy[securityLen] = '\0';
        cliStruct->security = securityCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "privateKey") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "privateKey"))) {
        size_t privateKeyLen = strlen(cJSON_GetObjectItem(clientObj, "privateKey")->valuestring);
        char* privateKeyCopy = (char*)malloc((privateKeyLen + 1) * sizeof(char));
        if (!privateKeyCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "privateKey is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(privateKeyCopy, cJSON_GetObjectItem(clientObj, "privateKey")->valuestring, privateKeyLen);
        privateKeyCopy[privateKeyLen] = '\0';
        cliStruct->privateKey = privateKeyCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "publicKey") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "publicKey"))) {
        size_t publicKeyLen = strlen(cJSON_GetObjectItem(clientObj, "publicKey")->valuestring);
        char* publicKeyCopy = (char*)malloc((publicKeyLen + 1) * sizeof(char));
        if (!publicKeyCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "publicKey is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(publicKeyCopy, cJSON_GetObjectItem(clientObj, "publicKey")->valuestring, publicKeyLen);
        publicKeyCopy[publicKeyLen] = '\0';
        cliStruct->publicKey = publicKeyCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "allowedIPs") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "allowedIPs"))) {
        size_t allowedIPsLen = strlen(cJSON_GetObjectItem(clientObj, "allowedIPs")->valuestring);
        char* allowedIPsCopy = (char*)malloc((allowedIPsLen + 1) * sizeof(char));
        if (!allowedIPsCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "allowedIPs is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(allowedIPsCopy, cJSON_GetObjectItem(clientObj, "allowedIPs")->valuestring, allowedIPsLen);
        allowedIPsCopy[allowedIPsLen] = '\0';
        cliStruct->allowedIPs = allowedIPsCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "preSharedKey") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "preSharedKey"))) {
        size_t preSharedKeyLen = strlen(cJSON_GetObjectItem(clientObj, "preSharedKey")->valuestring);
        char* preSharedKeyCopy = (char*)malloc((preSharedKeyLen + 1) * sizeof(char));
        if (!preSharedKeyCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "preSharedKey is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(preSharedKeyCopy, cJSON_GetObjectItem(clientObj, "preSharedKey")->valuestring, preSharedKeyLen);
        preSharedKeyCopy[preSharedKeyLen] = '\0';
        cliStruct->preSharedKey = preSharedKeyCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "keepAlive") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "keepAlive"))) {
        cliStruct->keepAlive = (int)cJSON_GetObjectItem(clientObj, "keepAlive")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "forwardedPorts") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "forwardedPorts"))) {
        size_t forwardedPortsLen = strlen(cJSON_GetObjectItem(clientObj, "forwardedPorts")->valuestring);
        char* forwardedPortsCopy = (char*)malloc((forwardedPortsLen + 1) * sizeof(char));
        if (!forwardedPortsCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "forwardedPorts is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(forwardedPortsCopy, cJSON_GetObjectItem(clientObj, "forwardedPorts")->valuestring, forwardedPortsLen);
        forwardedPortsCopy[forwardedPortsLen] = '\0';
        cliStruct->forwardedPorts = forwardedPortsCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "secret") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "secret"))) {
        size_t secretLen = strlen(cJSON_GetObjectItem(clientObj, "secret")->valuestring);
        char* secretCopy = (char*)malloc((secretLen + 1) * sizeof(char));
        if (!secretCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "secret is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(secretCopy, cJSON_GetObjectItem(clientObj, "secret")->valuestring, secretLen);
        secretCopy[secretLen] = '\0';
        cliStruct->secret = secretCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "adTag") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "adTag"))) {
        size_t adTagLen = strlen(cJSON_GetObjectItem(clientObj, "adTag")->valuestring);
        char* adTagCopy = (char*)malloc((adTagLen + 1) * sizeof(char));
        if (!adTagCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "adTag is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(adTagCopy, cJSON_GetObjectItem(clientObj, "adTag")->valuestring, adTagLen);
        adTagCopy[adTagLen] = '\0';
        cliStruct->adTag = adTagCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "limitIp") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "limitIp"))) {
        cliStruct->limitIp = (int)cJSON_GetObjectItem(clientObj, "limitIp")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "limitHwid") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "limitHwid"))) {
        cliStruct->limitHwid = (int)cJSON_GetObjectItem(clientObj, "limitHwid")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "totalGB") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "totalGB"))) {
        cliStruct->totalGB = (int64_t)cJSON_GetObjectItem(clientObj, "totalGB")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "expiryTime") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "expiryTime"))) {
        cliStruct->expiryTime = (int64_t)cJSON_GetObjectItem(clientObj, "expiryTime")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "enable") && cJSON_IsBool(cJSON_GetObjectItem(clientObj, "enable"))) {
        cliStruct->enable = cJSON_IsTrue(cJSON_GetObjectItem(clientObj, "enable")) ? 1 : 0;
    }

    if (cJSON_HasObjectItem(clientObj, "tgId") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "tgId"))) {
        cliStruct->tgId = (int64_t)cJSON_GetObjectItem(clientObj, "tgId")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "group") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "group"))) {
        size_t groupLen = strlen(cJSON_GetObjectItem(clientObj, "group")->valuestring);
        char* groupCopy = (char*)malloc((groupLen + 1) * sizeof(char));
        if (!groupCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "group is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(groupCopy, cJSON_GetObjectItem(clientObj, "group")->valuestring, groupLen);
        groupCopy[groupLen] = '\0';
        cliStruct->group = groupCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "comment") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "comment"))) {
        size_t commentLen = strlen(cJSON_GetObjectItem(clientObj, "comment")->valuestring);
        char* commentCopy = (char*)malloc((commentLen + 1) * sizeof(char));
        if (!commentCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "comment is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(commentCopy, cJSON_GetObjectItem(clientObj, "comment")->valuestring, commentLen);
        commentCopy[commentLen] = '\0';
        cliStruct->comment = commentCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "reset") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "reset"))) {
        cliStruct->reset = (int)cJSON_GetObjectItem(clientObj, "reset")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "resetDay") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "resetDay"))) {
        cliStruct->resetDay = (int)cJSON_GetObjectItem(clientObj, "resetDay")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "resetMax") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "resetMax"))) {
        cliStruct->resetMax = (int)cJSON_GetObjectItem(clientObj, "resetMax")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "trafficReset") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "trafficReset"))) {
        size_t trafficResetLen = strlen(cJSON_GetObjectItem(clientObj, "trafficReset")->valuestring);
        char* trafficResetCopy = (char*)malloc((trafficResetLen + 1) * sizeof(char));
        if (!trafficResetCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "trafficReset is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(trafficResetCopy, cJSON_GetObjectItem(clientObj, "trafficReset")->valuestring, trafficResetLen);
        trafficResetCopy[trafficResetLen] = '\0';
        cliStruct->trafficReset = trafficResetCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "trafficResetDay") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "trafficResetDay"))) {
        cliStruct->trafficResetDay = (int)cJSON_GetObjectItem(clientObj, "trafficResetDay")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "createdAt") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "createdAt"))) {
        cliStruct->createdAt = (int64_t)cJSON_GetObjectItem(clientObj, "createdAt")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "updatedAt") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "updatedAt"))) {
        cliStruct->updatedAt = (int64_t)cJSON_GetObjectItem(clientObj, "updatedAt")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "reverse") && !cJSON_IsNull(cJSON_GetObjectItem(clientObj, "reverse"))) {
        applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "reverse is not null, skipping");
    }

    return 1;
}

static int jsonFetchClientByEmailObjectExternalLinksArrayStructParse(cJSON* arrItem, struct jsonFetchClientByEmailObjectExternalLinksArrayStruct* linkStruct) {
    if (cJSON_HasObjectItem(arrItem, "kind") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "kind"))) {
        size_t kindLen = strlen(cJSON_GetObjectItem(arrItem, "kind")->valuestring);
        char* kindCopy = (char*)malloc((kindLen + 1) * sizeof(char));
        if (!kindCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "kind is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(kindCopy, cJSON_GetObjectItem(arrItem, "kind")->valuestring, kindLen);
        kindCopy[kindLen] = '\0';
        linkStruct->kind = kindCopy;
    }

    if (cJSON_HasObjectItem(arrItem, "value") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "value"))) {
        size_t valueLen = strlen(cJSON_GetObjectItem(arrItem, "value")->valuestring);
        char* valueCopy = (char*)malloc((valueLen + 1) * sizeof(char));
        if (!valueCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "value is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(valueCopy, cJSON_GetObjectItem(arrItem, "value")->valuestring, valueLen);
        valueCopy[valueLen] = '\0';
        linkStruct->value = valueCopy;
    }

    if (cJSON_HasObjectItem(arrItem, "remark") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "remark"))) {
        size_t remarkLen = strlen(cJSON_GetObjectItem(arrItem, "remark")->valuestring);
        char* remarkCopy = (char*)malloc((remarkLen + 1) * sizeof(char));
        if (!remarkCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "remark is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(remarkCopy, cJSON_GetObjectItem(arrItem, "remark")->valuestring, remarkLen);
        remarkCopy[remarkLen] = '\0';
        linkStruct->remark = remarkCopy;
    }

    if (cJSON_HasObjectItem(arrItem, "enable") && cJSON_IsBool(cJSON_GetObjectItem(arrItem, "enable"))) {
        linkStruct->enable = cJSON_IsTrue(cJSON_GetObjectItem(arrItem, "enable")) ? 1 : 0;
    }

    if (cJSON_HasObjectItem(arrItem, "expiryTime") && cJSON_IsNumber(cJSON_GetObjectItem(arrItem, "expiryTime"))) {
        linkStruct->expiryTime = (int64_t)cJSON_GetObjectItem(arrItem, "expiryTime")->valuedouble;
    }

    if (cJSON_HasObjectItem(arrItem, "namePrefix") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "namePrefix"))) {
        size_t namePrefixLen = strlen(cJSON_GetObjectItem(arrItem, "namePrefix")->valuestring);
        char* namePrefixCopy = (char*)malloc((namePrefixLen + 1) * sizeof(char));
        if (!namePrefixCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "namePrefix is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(namePrefixCopy, cJSON_GetObjectItem(arrItem, "namePrefix")->valuestring, namePrefixLen);
        namePrefixCopy[namePrefixLen] = '\0';
        linkStruct->namePrefix = namePrefixCopy;
    }

    return 1;
}

struct jsonFetchClientByEmailStruct* jsonFetchClientByEmail(const char* json) {
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
        cJSON_HasObjectItem(jsonParser, "msg") &&
        cJSON_IsString(cJSON_GetObjectItem(jsonParser, "msg")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsObject(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* obj = cJSON_GetObjectItem(jsonParser, "obj");
        if (!obj) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "obj is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        struct jsonFetchClientByEmailObjectStruct* fetchCliByEmailObjStruct = (struct jsonFetchClientByEmailObjectStruct*)calloc(1, sizeof(struct jsonFetchClientByEmailObjectStruct));
        if (!fetchCliByEmailObjStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "fetchCliByEmailObjStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        // Parse client object
        if (cJSON_HasObjectItem(obj, "client") && cJSON_IsObject(cJSON_GetObjectItem(obj, "client"))) {
            cJSON* clientObj = cJSON_GetObjectItem(obj, "client");
            struct jsonFetchClientByEmailObjectClientObjectStruct* cliStruct = (struct jsonFetchClientByEmailObjectClientObjectStruct*)calloc(1, sizeof(struct jsonFetchClientByEmailObjectClientObjectStruct));
            if (!cliStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "cliStruct is a null pointer");
                free(fetchCliByEmailObjStruct);
                cJSON_Delete(jsonParser);
                return NULL;
            }
            if (jsonFetchClientByEmailObjectClientObjectStructParse(clientObj, cliStruct) == 0) {
                applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Failed to parse client object");
            }
            fetchCliByEmailObjStruct->fetchCliByEmailObjCliObjStruct = cliStruct;
        }

        // Parse externalLinks array
        if (cJSON_HasObjectItem(obj, "externalLinks") && cJSON_IsArray(cJSON_GetObjectItem(obj, "externalLinks"))) {
            cJSON* externalLinksArr = cJSON_GetObjectItem(obj, "externalLinks");
            size_t arraySize = cJSON_GetArraySize(externalLinksArr);
            if (arraySize) {
                fetchCliByEmailObjStruct->fetchCliByEmailObjExternalLinksArrStruct = (struct jsonFetchClientByEmailObjectExternalLinksArrayStruct*)calloc(arraySize, sizeof(struct jsonFetchClientByEmailObjectExternalLinksArrayStruct));
                if (!fetchCliByEmailObjStruct->fetchCliByEmailObjExternalLinksArrStruct) {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "fetchCliByEmailObjExternalLinksArrStruct is a null pointer");
                    free(fetchCliByEmailObjStruct);
                    cJSON_Delete(jsonParser);
                    return NULL;
                }
                fetchCliByEmailObjStruct->jsonFetchClientByEmailObjectExternalLinksArrayStructSize = arraySize;
                for (size_t i = 0; i < arraySize; i++) {
                    cJSON* arrItem = cJSON_GetArrayItem(externalLinksArr, i);
                    if (jsonFetchClientByEmailObjectExternalLinksArrayStructParse(arrItem, &fetchCliByEmailObjStruct->fetchCliByEmailObjExternalLinksArrStruct[i]) == 0) {
                        applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Some item is not present in the externalLinks array element, skipping...");
                    }
                }
            }
        }

        // Parse inboundIds array
        if (cJSON_HasObjectItem(obj, "inboundIds") && cJSON_IsArray(cJSON_GetObjectItem(obj, "inboundIds"))) {
            cJSON* inboundIdsArr = cJSON_GetObjectItem(obj, "inboundIds");
            size_t inboundIdsCount = cJSON_GetArraySize(inboundIdsArr);
            if (inboundIdsCount) {
                fetchCliByEmailObjStruct->inboundIds = (int*)malloc(inboundIdsCount * sizeof(int));
                if (!fetchCliByEmailObjStruct->inboundIds) {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "inboundIds is a null pointer, failed to allocate memory");
                    free(fetchCliByEmailObjStruct);
                    cJSON_Delete(jsonParser);
                    return NULL;
                }
                fetchCliByEmailObjStruct->inboundIdsCount = (int64_t)inboundIdsCount;
                for (size_t i = 0; i < inboundIdsCount; i++) {
                    cJSON* inboundIdsItem = cJSON_GetArrayItem(inboundIdsArr, i);
                    if (cJSON_IsNumber(inboundIdsItem)) {
                        fetchCliByEmailObjStruct->inboundIds[i] = (int)inboundIdsItem->valuedouble;
                    }
                }
            }
        }

        // Parse tunnelAllowedIPs (object, but empty in sample)
        if (cJSON_HasObjectItem(obj, "tunnelAllowedIPs") && cJSON_IsObject(cJSON_GetObjectItem(obj, "tunnelAllowedIPs"))) {
            cJSON* tunnelAllowedIPsObj = cJSON_GetObjectItem(obj, "tunnelAllowedIPs");
            char* tunnelAllowedIPsStr = cJSON_Print(tunnelAllowedIPsObj);
            if (tunnelAllowedIPsStr) {
                size_t tunnelAllowedIPsLen = strlen(tunnelAllowedIPsStr);
                char* tunnelAllowedIPsCopy = (char*)malloc((tunnelAllowedIPsLen + 1) * sizeof(char));
                if (tunnelAllowedIPsCopy) {
                    strncpy(tunnelAllowedIPsCopy, tunnelAllowedIPsStr, tunnelAllowedIPsLen);
                    tunnelAllowedIPsCopy[tunnelAllowedIPsLen] = '\0';
                    fetchCliByEmailObjStruct->tunnelAllowedIPs = tunnelAllowedIPsCopy;
                }
                free(tunnelAllowedIPsStr);
            }
        }

        // Parse usedTraffic
        if (cJSON_HasObjectItem(obj, "usedTraffic") && cJSON_IsNumber(cJSON_GetObjectItem(obj, "usedTraffic"))) {
            fetchCliByEmailObjStruct->usedTraffic = (int64_t)cJSON_GetObjectItem(obj, "usedTraffic")->valuedouble;
        }

        struct jsonFetchClientByEmailStruct* fetchCliByEmailStruct = (struct jsonFetchClientByEmailStruct*)malloc(sizeof(struct jsonFetchClientByEmailStruct));
        if (!fetchCliByEmailStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "fetchCliByEmailStruct is a null pointer");
            free(fetchCliByEmailObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        fetchCliByEmailStruct->success = 1;

        char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
        size_t msgLen = strlen(msg);
        char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
        if (!msgCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "msgCopy is a null pointer");
            free(fetchCliByEmailStruct);
            free(fetchCliByEmailObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }
        strncpy(msgCopy, msg, msgLen);
        msgCopy[msgLen] = '\0';
        fetchCliByEmailStruct->msg = msgCopy;

        fetchCliByEmailStruct->fetchCliByEmailObjStruct = fetchCliByEmailObjStruct;

        cJSON_Delete(jsonParser);
        return fetchCliByEmailStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonFetchClientByEmailStruct* failRStruct = (struct jsonFetchClientByEmailStruct*)calloc(1, sizeof(struct jsonFetchClientByEmailStruct));
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

void jsonFetchClientByEmailObjectClientObjectStructDelete(struct jsonFetchClientByEmailObjectClientObjectStruct* fetchCliByEmailObjCliObjStruct) {
    if (!fetchCliByEmailObjCliObjStruct) {
        return;
    }

    free((char*)fetchCliByEmailObjCliObjStruct->email);
    free((char*)fetchCliByEmailObjCliObjStruct->subId);
    free((char*)fetchCliByEmailObjCliObjStruct->uuid);
    free((char*)fetchCliByEmailObjCliObjStruct->password);
    free((char*)fetchCliByEmailObjCliObjStruct->auth);
    free((char*)fetchCliByEmailObjCliObjStruct->flow);
    free((char*)fetchCliByEmailObjCliObjStruct->security);
    free((char*)fetchCliByEmailObjCliObjStruct->privateKey);
    free((char*)fetchCliByEmailObjCliObjStruct->publicKey);
    free((char*)fetchCliByEmailObjCliObjStruct->allowedIPs);
    free((char*)fetchCliByEmailObjCliObjStruct->preSharedKey);
    free((char*)fetchCliByEmailObjCliObjStruct->forwardedPorts);
    free((char*)fetchCliByEmailObjCliObjStruct->secret);
    free((char*)fetchCliByEmailObjCliObjStruct->adTag);
    free((char*)fetchCliByEmailObjCliObjStruct->group);
    free((char*)fetchCliByEmailObjCliObjStruct->comment);
    free((char*)fetchCliByEmailObjCliObjStruct->trafficReset);

    free(fetchCliByEmailObjCliObjStruct);
}

void jsonFetchClientByEmailObjectExternalLinksArrayStructDelete(struct jsonFetchClientByEmailObjectExternalLinksArrayStruct* fetchCliByEmailObjExternalLinksArrStruct, size_t arraySize) {
    if (!fetchCliByEmailObjExternalLinksArrStruct) {
        return;
    }

    for (size_t i = 0; i < arraySize; i++) {
        free((char*)fetchCliByEmailObjExternalLinksArrStruct[i].kind);
        free((char*)fetchCliByEmailObjExternalLinksArrStruct[i].value);
        free((char*)fetchCliByEmailObjExternalLinksArrStruct[i].remark);
        free((char*)fetchCliByEmailObjExternalLinksArrStruct[i].namePrefix);
    }

    free(fetchCliByEmailObjExternalLinksArrStruct);
}

void jsonFetchClientByEmailObjectStructDelete(struct jsonFetchClientByEmailObjectStruct* fetchCliByEmailObjStruct) {
    if (!fetchCliByEmailObjStruct) {
        return;
    }

    if (fetchCliByEmailObjStruct->fetchCliByEmailObjCliObjStruct) {
        jsonFetchClientByEmailObjectClientObjectStructDelete(fetchCliByEmailObjStruct->fetchCliByEmailObjCliObjStruct);
        fetchCliByEmailObjStruct->fetchCliByEmailObjCliObjStruct = NULL;
    }

    if (fetchCliByEmailObjStruct->fetchCliByEmailObjExternalLinksArrStruct) {
        jsonFetchClientByEmailObjectExternalLinksArrayStructDelete(fetchCliByEmailObjStruct->fetchCliByEmailObjExternalLinksArrStruct, fetchCliByEmailObjStruct->jsonFetchClientByEmailObjectExternalLinksArrayStructSize);
        fetchCliByEmailObjStruct->fetchCliByEmailObjExternalLinksArrStruct = NULL;
    }

    free(fetchCliByEmailObjStruct->inboundIds);
    free((char*)fetchCliByEmailObjStruct->tunnelAllowedIPs);

    free(fetchCliByEmailObjStruct);
}

void jsonFetchClientByEmailStructDelete(struct jsonFetchClientByEmailStruct* fetchCliByEmailStruct) {
    if (!fetchCliByEmailStruct) {
        return;
    }

    free((char*)fetchCliByEmailStruct->msg);

    if (fetchCliByEmailStruct->fetchCliByEmailObjStruct) {
        jsonFetchClientByEmailObjectStructDelete(fetchCliByEmailStruct->fetchCliByEmailObjStruct);
        fetchCliByEmailStruct->fetchCliByEmailObjStruct = NULL;
    }

    free(fetchCliByEmailStruct);
}

static int jsonFetchClientByTelegramIdObjectArrayClientObjectStructParse(cJSON* clientObj, struct jsonFetchClientByTelegramIdObjectArrayClientObjectStruct* cliStruct) {
    if (!clientObj) {
        return 0;
    }

    if (cJSON_HasObjectItem(clientObj, "id") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "id"))) {
        cliStruct->id = (int64_t)cJSON_GetObjectItem(clientObj, "id")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "email") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "email"))) {
        size_t emailLen = strlen(cJSON_GetObjectItem(clientObj, "email")->valuestring);
        char* emailCopy = (char*)malloc((emailLen + 1) * sizeof(char));
        if (!emailCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "email is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(emailCopy, cJSON_GetObjectItem(clientObj, "email")->valuestring, emailLen);
        emailCopy[emailLen] = '\0';
        cliStruct->email = emailCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "subId") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "subId"))) {
        size_t subIdLen = strlen(cJSON_GetObjectItem(clientObj, "subId")->valuestring);
        char* subIdCopy = (char*)malloc((subIdLen + 1) * sizeof(char));
        if (!subIdCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "subId is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(subIdCopy, cJSON_GetObjectItem(clientObj, "subId")->valuestring, subIdLen);
        subIdCopy[subIdLen] = '\0';
        cliStruct->subId = subIdCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "uuid") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "uuid"))) {
        size_t uuidLen = strlen(cJSON_GetObjectItem(clientObj, "uuid")->valuestring);
        char* uuidCopy = (char*)malloc((uuidLen + 1) * sizeof(char));
        if (!uuidCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "uuid is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(uuidCopy, cJSON_GetObjectItem(clientObj, "uuid")->valuestring, uuidLen);
        uuidCopy[uuidLen] = '\0';
        cliStruct->uuid = uuidCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "password") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "password"))) {
        size_t passwordLen = strlen(cJSON_GetObjectItem(clientObj, "password")->valuestring);
        char* passwordCopy = (char*)malloc((passwordLen + 1) * sizeof(char));
        if (!passwordCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "password is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(passwordCopy, cJSON_GetObjectItem(clientObj, "password")->valuestring, passwordLen);
        passwordCopy[passwordLen] = '\0';
        cliStruct->password = passwordCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "auth") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "auth"))) {
        size_t authLen = strlen(cJSON_GetObjectItem(clientObj, "auth")->valuestring);
        char* authCopy = (char*)malloc((authLen + 1) * sizeof(char));
        if (!authCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "auth is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(authCopy, cJSON_GetObjectItem(clientObj, "auth")->valuestring, authLen);
        authCopy[authLen] = '\0';
        cliStruct->auth = authCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "flow") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "flow"))) {
        size_t flowLen = strlen(cJSON_GetObjectItem(clientObj, "flow")->valuestring);
        char* flowCopy = (char*)malloc((flowLen + 1) * sizeof(char));
        if (!flowCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "flow is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(flowCopy, cJSON_GetObjectItem(clientObj, "flow")->valuestring, flowLen);
        flowCopy[flowLen] = '\0';
        cliStruct->flow = flowCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "security") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "security"))) {
        size_t securityLen = strlen(cJSON_GetObjectItem(clientObj, "security")->valuestring);
        char* securityCopy = (char*)malloc((securityLen + 1) * sizeof(char));
        if (!securityCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "security is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(securityCopy, cJSON_GetObjectItem(clientObj, "security")->valuestring, securityLen);
        securityCopy[securityLen] = '\0';
        cliStruct->security = securityCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "privateKey") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "privateKey"))) {
        size_t privateKeyLen = strlen(cJSON_GetObjectItem(clientObj, "privateKey")->valuestring);
        char* privateKeyCopy = (char*)malloc((privateKeyLen + 1) * sizeof(char));
        if (!privateKeyCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "privateKey is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(privateKeyCopy, cJSON_GetObjectItem(clientObj, "privateKey")->valuestring, privateKeyLen);
        privateKeyCopy[privateKeyLen] = '\0';
        cliStruct->privateKey = privateKeyCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "publicKey") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "publicKey"))) {
        size_t publicKeyLen = strlen(cJSON_GetObjectItem(clientObj, "publicKey")->valuestring);
        char* publicKeyCopy = (char*)malloc((publicKeyLen + 1) * sizeof(char));
        if (!publicKeyCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "publicKey is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(publicKeyCopy, cJSON_GetObjectItem(clientObj, "publicKey")->valuestring, publicKeyLen);
        publicKeyCopy[publicKeyLen] = '\0';
        cliStruct->publicKey = publicKeyCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "allowedIPs") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "allowedIPs"))) {
        size_t allowedIPsLen = strlen(cJSON_GetObjectItem(clientObj, "allowedIPs")->valuestring);
        char* allowedIPsCopy = (char*)malloc((allowedIPsLen + 1) * sizeof(char));
        if (!allowedIPsCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "allowedIPs is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(allowedIPsCopy, cJSON_GetObjectItem(clientObj, "allowedIPs")->valuestring, allowedIPsLen);
        allowedIPsCopy[allowedIPsLen] = '\0';
        cliStruct->allowedIPs = allowedIPsCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "preSharedKey") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "preSharedKey"))) {
        size_t preSharedKeyLen = strlen(cJSON_GetObjectItem(clientObj, "preSharedKey")->valuestring);
        char* preSharedKeyCopy = (char*)malloc((preSharedKeyLen + 1) * sizeof(char));
        if (!preSharedKeyCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "preSharedKey is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(preSharedKeyCopy, cJSON_GetObjectItem(clientObj, "preSharedKey")->valuestring, preSharedKeyLen);
        preSharedKeyCopy[preSharedKeyLen] = '\0';
        cliStruct->preSharedKey = preSharedKeyCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "keepAlive") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "keepAlive"))) {
        cliStruct->keepAlive = (int)cJSON_GetObjectItem(clientObj, "keepAlive")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "forwardedPorts") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "forwardedPorts"))) {
        size_t forwardedPortsLen = strlen(cJSON_GetObjectItem(clientObj, "forwardedPorts")->valuestring);
        char* forwardedPortsCopy = (char*)malloc((forwardedPortsLen + 1) * sizeof(char));
        if (!forwardedPortsCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "forwardedPorts is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(forwardedPortsCopy, cJSON_GetObjectItem(clientObj, "forwardedPorts")->valuestring, forwardedPortsLen);
        forwardedPortsCopy[forwardedPortsLen] = '\0';
        cliStruct->forwardedPorts = forwardedPortsCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "secret") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "secret"))) {
        size_t secretLen = strlen(cJSON_GetObjectItem(clientObj, "secret")->valuestring);
        char* secretCopy = (char*)malloc((secretLen + 1) * sizeof(char));
        if (!secretCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "secret is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(secretCopy, cJSON_GetObjectItem(clientObj, "secret")->valuestring, secretLen);
        secretCopy[secretLen] = '\0';
        cliStruct->secret = secretCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "adTag") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "adTag"))) {
        size_t adTagLen = strlen(cJSON_GetObjectItem(clientObj, "adTag")->valuestring);
        char* adTagCopy = (char*)malloc((adTagLen + 1) * sizeof(char));
        if (!adTagCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "adTag is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(adTagCopy, cJSON_GetObjectItem(clientObj, "adTag")->valuestring, adTagLen);
        adTagCopy[adTagLen] = '\0';
        cliStruct->adTag = adTagCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "limitIp") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "limitIp"))) {
        cliStruct->limitIp = (int)cJSON_GetObjectItem(clientObj, "limitIp")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "limitHwid") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "limitHwid"))) {
        cliStruct->limitHwid = (int)cJSON_GetObjectItem(clientObj, "limitHwid")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "totalGB") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "totalGB"))) {
        cliStruct->totalGB = (int64_t)cJSON_GetObjectItem(clientObj, "totalGB")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "expiryTime") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "expiryTime"))) {
        cliStruct->expiryTime = (int64_t)cJSON_GetObjectItem(clientObj, "expiryTime")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "enable") && cJSON_IsBool(cJSON_GetObjectItem(clientObj, "enable"))) {
        cliStruct->enable = cJSON_IsTrue(cJSON_GetObjectItem(clientObj, "enable")) ? 1 : 0;
    }

    if (cJSON_HasObjectItem(clientObj, "tgId") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "tgId"))) {
        cliStruct->tgId = (int64_t)cJSON_GetObjectItem(clientObj, "tgId")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "group") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "group"))) {
        size_t groupLen = strlen(cJSON_GetObjectItem(clientObj, "group")->valuestring);
        char* groupCopy = (char*)malloc((groupLen + 1) * sizeof(char));
        if (!groupCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "group is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(groupCopy, cJSON_GetObjectItem(clientObj, "group")->valuestring, groupLen);
        groupCopy[groupLen] = '\0';
        cliStruct->group = groupCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "comment") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "comment"))) {
        size_t commentLen = strlen(cJSON_GetObjectItem(clientObj, "comment")->valuestring);
        char* commentCopy = (char*)malloc((commentLen + 1) * sizeof(char));
        if (!commentCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "comment is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(commentCopy, cJSON_GetObjectItem(clientObj, "comment")->valuestring, commentLen);
        commentCopy[commentLen] = '\0';
        cliStruct->comment = commentCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "reset") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "reset"))) {
        cliStruct->reset = (int)cJSON_GetObjectItem(clientObj, "reset")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "resetDay") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "resetDay"))) {
        cliStruct->resetDay = (int)cJSON_GetObjectItem(clientObj, "resetDay")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "resetMax") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "resetMax"))) {
        cliStruct->resetMax = (int)cJSON_GetObjectItem(clientObj, "resetMax")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "trafficReset") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "trafficReset"))) {
        size_t trafficResetLen = strlen(cJSON_GetObjectItem(clientObj, "trafficReset")->valuestring);
        char* trafficResetCopy = (char*)malloc((trafficResetLen + 1) * sizeof(char));
        if (!trafficResetCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "trafficReset is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(trafficResetCopy, cJSON_GetObjectItem(clientObj, "trafficReset")->valuestring, trafficResetLen);
        trafficResetCopy[trafficResetLen] = '\0';
        cliStruct->trafficReset = trafficResetCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "trafficResetDay") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "trafficResetDay"))) {
        cliStruct->trafficResetDay = (int)cJSON_GetObjectItem(clientObj, "trafficResetDay")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "createdAt") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "createdAt"))) {
        cliStruct->createdAt = (int64_t)cJSON_GetObjectItem(clientObj, "createdAt")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "updatedAt") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "updatedAt"))) {
        cliStruct->updatedAt = (int64_t)cJSON_GetObjectItem(clientObj, "updatedAt")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "reverse") && !cJSON_IsNull(cJSON_GetObjectItem(clientObj, "reverse"))) {
        applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "reverse is not null, skipping");
    }

    return 1;
}

static int jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStructParse(cJSON* arrItem, struct jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStruct* linkStruct) {
    if (cJSON_HasObjectItem(arrItem, "kind") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "kind"))) {
        size_t kindLen = strlen(cJSON_GetObjectItem(arrItem, "kind")->valuestring);
        char* kindCopy = (char*)malloc((kindLen + 1) * sizeof(char));
        if (!kindCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "kind is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(kindCopy, cJSON_GetObjectItem(arrItem, "kind")->valuestring, kindLen);
        kindCopy[kindLen] = '\0';
        linkStruct->kind = kindCopy;
    }

    if (cJSON_HasObjectItem(arrItem, "value") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "value"))) {
        size_t valueLen = strlen(cJSON_GetObjectItem(arrItem, "value")->valuestring);
        char* valueCopy = (char*)malloc((valueLen + 1) * sizeof(char));
        if (!valueCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "value is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(valueCopy, cJSON_GetObjectItem(arrItem, "value")->valuestring, valueLen);
        valueCopy[valueLen] = '\0';
        linkStruct->value = valueCopy;
    }

    if (cJSON_HasObjectItem(arrItem, "remark") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "remark"))) {
        size_t remarkLen = strlen(cJSON_GetObjectItem(arrItem, "remark")->valuestring);
        char* remarkCopy = (char*)malloc((remarkLen + 1) * sizeof(char));
        if (!remarkCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "remark is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(remarkCopy, cJSON_GetObjectItem(arrItem, "remark")->valuestring, remarkLen);
        remarkCopy[remarkLen] = '\0';
        linkStruct->remark = remarkCopy;
    }

    if (cJSON_HasObjectItem(arrItem, "enable") && cJSON_IsBool(cJSON_GetObjectItem(arrItem, "enable"))) {
        linkStruct->enable = cJSON_IsTrue(cJSON_GetObjectItem(arrItem, "enable")) ? 1 : 0;
    }

    if (cJSON_HasObjectItem(arrItem, "expiryTime") && cJSON_IsNumber(cJSON_GetObjectItem(arrItem, "expiryTime"))) {
        linkStruct->expiryTime = (int64_t)cJSON_GetObjectItem(arrItem, "expiryTime")->valuedouble;
    }

    if (cJSON_HasObjectItem(arrItem, "namePrefix") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "namePrefix"))) {
        size_t namePrefixLen = strlen(cJSON_GetObjectItem(arrItem, "namePrefix")->valuestring);
        char* namePrefixCopy = (char*)malloc((namePrefixLen + 1) * sizeof(char));
        if (!namePrefixCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "namePrefix is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(namePrefixCopy, cJSON_GetObjectItem(arrItem, "namePrefix")->valuestring, namePrefixLen);
        namePrefixCopy[namePrefixLen] = '\0';
        linkStruct->namePrefix = namePrefixCopy;
    }

    return 1;
}

struct jsonFetchClientByTelegramIdStruct* jsonFetchClientByTelegramId(const char* json) {
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
        cJSON_HasObjectItem(jsonParser, "msg") &&
        cJSON_IsString(cJSON_GetObjectItem(jsonParser, "msg")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsArray(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* objArray = cJSON_GetObjectItem(jsonParser, "obj");
        if (!objArray) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "objArray is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        size_t arraySize = cJSON_GetArraySize(objArray);
        struct jsonFetchClientByTelegramIdObjectArrayStruct* fetchCliByTgIdObjArrStruct = NULL;
        if (arraySize) {
            fetchCliByTgIdObjArrStruct = (struct jsonFetchClientByTelegramIdObjectArrayStruct*)calloc(arraySize, sizeof(struct jsonFetchClientByTelegramIdObjectArrayStruct));
            if (!fetchCliByTgIdObjArrStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "fetchCliByTgIdObjArrStruct is a null pointer");
                cJSON_Delete(jsonParser);
                return NULL;
            }
            for (size_t i = 0; i < arraySize; i++) {
                cJSON* arrItem = cJSON_GetArrayItem(objArray, i);
                if (!cJSON_IsObject(arrItem)) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Array element is not an object, skipping...");
                    continue;
                }

                // Parse client object
                if (cJSON_HasObjectItem(arrItem, "client") && cJSON_IsObject(cJSON_GetObjectItem(arrItem, "client"))) {
                    cJSON* clientObj = cJSON_GetObjectItem(arrItem, "client");
                    struct jsonFetchClientByTelegramIdObjectArrayClientObjectStruct* cliStruct = (struct jsonFetchClientByTelegramIdObjectArrayClientObjectStruct*)calloc(1, sizeof(struct jsonFetchClientByTelegramIdObjectArrayClientObjectStruct));
                    if (!cliStruct) {
                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "cliStruct is a null pointer");
                        // Clean up already allocated items
                        for (size_t j = 0; j < i; j++) {
                            if (fetchCliByTgIdObjArrStruct[j].fetchCliByTgIdObjArrCliObjStruct) {
                                jsonFetchClientByTelegramIdObjectArrayClientObjectStructDelete(fetchCliByTgIdObjArrStruct[j].fetchCliByTgIdObjArrCliObjStruct);
                            }
                            if (fetchCliByTgIdObjArrStruct[j].fetchCliByTgIArrdObjExternalLinksArrStruct) {
                                jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStructDelete(fetchCliByTgIdObjArrStruct[j].fetchCliByTgIArrdObjExternalLinksArrStruct, fetchCliByTgIdObjArrStruct[j].jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStructSize);
                            }
                            free(fetchCliByTgIdObjArrStruct[j].inboundIds);
                            free((char*)fetchCliByTgIdObjArrStruct[j].tunnelAllowedIPs);
                        }
                        free(fetchCliByTgIdObjArrStruct);
                        cJSON_Delete(jsonParser);
                        return NULL;
                    }
                    if (jsonFetchClientByTelegramIdObjectArrayClientObjectStructParse(clientObj, cliStruct) == 0) {
                        applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Failed to parse client object");
                    }
                    fetchCliByTgIdObjArrStruct[i].fetchCliByTgIdObjArrCliObjStruct = cliStruct;
                }

                // Parse externalLinks array
                if (cJSON_HasObjectItem(arrItem, "externalLinks") && cJSON_IsArray(cJSON_GetObjectItem(arrItem, "externalLinks"))) {
                    cJSON* externalLinksArr = cJSON_GetObjectItem(arrItem, "externalLinks");
                    size_t extLinksArraySize = cJSON_GetArraySize(externalLinksArr);
                    if (extLinksArraySize) {
                        fetchCliByTgIdObjArrStruct[i].fetchCliByTgIArrdObjExternalLinksArrStruct = (struct jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStruct*)calloc(extLinksArraySize, sizeof(struct jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStruct));
                        if (!fetchCliByTgIdObjArrStruct[i].fetchCliByTgIArrdObjExternalLinksArrStruct) {
                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "fetchCliByTgIArrdObjExternalLinksArrStruct is a null pointer");
                            // Clean up
                            for (size_t j = 0; j <= i; j++) {
                                if (fetchCliByTgIdObjArrStruct[j].fetchCliByTgIdObjArrCliObjStruct) {
                                    jsonFetchClientByTelegramIdObjectArrayClientObjectStructDelete(fetchCliByTgIdObjArrStruct[j].fetchCliByTgIdObjArrCliObjStruct);
                                }
                                if (fetchCliByTgIdObjArrStruct[j].fetchCliByTgIArrdObjExternalLinksArrStruct) {
                                    jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStructDelete(fetchCliByTgIdObjArrStruct[j].fetchCliByTgIArrdObjExternalLinksArrStruct, fetchCliByTgIdObjArrStruct[j].jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStructSize);
                                }
                                free(fetchCliByTgIdObjArrStruct[j].inboundIds);
                                free((char*)fetchCliByTgIdObjArrStruct[j].tunnelAllowedIPs);
                            }
                            free(fetchCliByTgIdObjArrStruct);
                            cJSON_Delete(jsonParser);
                            return NULL;
                        }
                        fetchCliByTgIdObjArrStruct[i].jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStructSize = extLinksArraySize;
                        for (size_t j = 0; j < extLinksArraySize; j++) {
                            cJSON* extLinkItem = cJSON_GetArrayItem(externalLinksArr, j);
                            if (jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStructParse(extLinkItem, &fetchCliByTgIdObjArrStruct[i].fetchCliByTgIArrdObjExternalLinksArrStruct[j]) == 0) {
                                applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Some item is not present in the externalLinks array element, skipping...");
                            }
                        }
                    }
                }

                // Parse inboundIds array
                if (cJSON_HasObjectItem(arrItem, "inboundIds") && cJSON_IsArray(cJSON_GetObjectItem(arrItem, "inboundIds"))) {
                    cJSON* inboundIdsArr = cJSON_GetObjectItem(arrItem, "inboundIds");
                    size_t inboundIdsCount = cJSON_GetArraySize(inboundIdsArr);
                    if (inboundIdsCount) {
                        fetchCliByTgIdObjArrStruct[i].inboundIds = (int*)malloc(inboundIdsCount * sizeof(int));
                        if (!fetchCliByTgIdObjArrStruct[i].inboundIds) {
                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "inboundIds is a null pointer, failed to allocate memory");
                            // Clean up
                            for (size_t j = 0; j <= i; j++) {
                                if (fetchCliByTgIdObjArrStruct[j].fetchCliByTgIdObjArrCliObjStruct) {
                                    jsonFetchClientByTelegramIdObjectArrayClientObjectStructDelete(fetchCliByTgIdObjArrStruct[j].fetchCliByTgIdObjArrCliObjStruct);
                                }
                                if (fetchCliByTgIdObjArrStruct[j].fetchCliByTgIArrdObjExternalLinksArrStruct) {
                                    jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStructDelete(fetchCliByTgIdObjArrStruct[j].fetchCliByTgIArrdObjExternalLinksArrStruct, fetchCliByTgIdObjArrStruct[j].jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStructSize);
                                }
                                free(fetchCliByTgIdObjArrStruct[j].inboundIds);
                                free((char*)fetchCliByTgIdObjArrStruct[j].tunnelAllowedIPs);
                            }
                            free(fetchCliByTgIdObjArrStruct);
                            cJSON_Delete(jsonParser);
                            return NULL;
                        }
                        fetchCliByTgIdObjArrStruct[i].inboundIdsCount = (int64_t)inboundIdsCount;
                        for (size_t j = 0; j < inboundIdsCount; j++) {
                            cJSON* inboundIdsItem = cJSON_GetArrayItem(inboundIdsArr, j);
                            if (cJSON_IsNumber(inboundIdsItem)) {
                                fetchCliByTgIdObjArrStruct[i].inboundIds[j] = (int)inboundIdsItem->valuedouble;
                            }
                        }
                    }
                }

                // Parse tunnelAllowedIPs (object, but empty in sample)
                if (cJSON_HasObjectItem(arrItem, "tunnelAllowedIPs") && cJSON_IsObject(cJSON_GetObjectItem(arrItem, "tunnelAllowedIPs"))) {
                    cJSON* tunnelAllowedIPsObj = cJSON_GetObjectItem(arrItem, "tunnelAllowedIPs");
                    char* tunnelAllowedIPsStr = cJSON_Print(tunnelAllowedIPsObj);
                    if (tunnelAllowedIPsStr) {
                        size_t tunnelAllowedIPsLen = strlen(tunnelAllowedIPsStr);
                        char* tunnelAllowedIPsCopy = (char*)malloc((tunnelAllowedIPsLen + 1) * sizeof(char));
                        if (tunnelAllowedIPsCopy) {
                            strncpy(tunnelAllowedIPsCopy, tunnelAllowedIPsStr, tunnelAllowedIPsLen);
                            tunnelAllowedIPsCopy[tunnelAllowedIPsLen] = '\0';
                            fetchCliByTgIdObjArrStruct[i].tunnelAllowedIPs = tunnelAllowedIPsCopy;
                        }
                        free(tunnelAllowedIPsStr);
                    }
                }

                // Parse usedTraffic
                if (cJSON_HasObjectItem(arrItem, "usedTraffic") && cJSON_IsNumber(cJSON_GetObjectItem(arrItem, "usedTraffic"))) {
                    fetchCliByTgIdObjArrStruct[i].usedTraffic = (int64_t)cJSON_GetObjectItem(arrItem, "usedTraffic")->valuedouble;
                }
            }
        }

        struct jsonFetchClientByTelegramIdStruct* fetchCliByTelegramIdStruct = (struct jsonFetchClientByTelegramIdStruct*)malloc(sizeof(struct jsonFetchClientByTelegramIdStruct));
        if (!fetchCliByTelegramIdStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "fetchCliByTelegramIdStruct is a null pointer");
            if (fetchCliByTgIdObjArrStruct) {
                for (size_t i = 0; i < arraySize; i++) {
                    if (fetchCliByTgIdObjArrStruct[i].fetchCliByTgIdObjArrCliObjStruct) {
                        jsonFetchClientByTelegramIdObjectArrayClientObjectStructDelete(fetchCliByTgIdObjArrStruct[i].fetchCliByTgIdObjArrCliObjStruct);
                    }
                    if (fetchCliByTgIdObjArrStruct[i].fetchCliByTgIArrdObjExternalLinksArrStruct) {
                        jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStructDelete(fetchCliByTgIdObjArrStruct[i].fetchCliByTgIArrdObjExternalLinksArrStruct, fetchCliByTgIdObjArrStruct[i].jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStructSize);
                    }
                    free(fetchCliByTgIdObjArrStruct[i].inboundIds);
                    free((char*)fetchCliByTgIdObjArrStruct[i].tunnelAllowedIPs);
                }
                free(fetchCliByTgIdObjArrStruct);
            }
            cJSON_Delete(jsonParser);
            return NULL;
        }

        fetchCliByTelegramIdStruct->success = 1;

        char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
        size_t msgLen = strlen(msg);
        char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
        if (!msgCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "msgCopy is a null pointer");
            free(fetchCliByTelegramIdStruct);
            if (fetchCliByTgIdObjArrStruct) {
                for (size_t i = 0; i < arraySize; i++) {
                    if (fetchCliByTgIdObjArrStruct[i].fetchCliByTgIdObjArrCliObjStruct) {
                        jsonFetchClientByTelegramIdObjectArrayClientObjectStructDelete(fetchCliByTgIdObjArrStruct[i].fetchCliByTgIdObjArrCliObjStruct);
                    }
                    if (fetchCliByTgIdObjArrStruct[i].fetchCliByTgIArrdObjExternalLinksArrStruct) {
                        jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStructDelete(fetchCliByTgIdObjArrStruct[i].fetchCliByTgIArrdObjExternalLinksArrStruct, fetchCliByTgIdObjArrStruct[i].jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStructSize);
                    }
                    free(fetchCliByTgIdObjArrStruct[i].inboundIds);
                    free((char*)fetchCliByTgIdObjArrStruct[i].tunnelAllowedIPs);
                }
                free(fetchCliByTgIdObjArrStruct);
            }
            cJSON_Delete(jsonParser);
            return NULL;
        }
        strncpy(msgCopy, msg, msgLen);
        msgCopy[msgLen] = '\0';
        fetchCliByTelegramIdStruct->msg = msgCopy;

        fetchCliByTelegramIdStruct->jsonFetchClientByTelegramIdObjectArrayStructSize = arraySize;
        fetchCliByTelegramIdStruct->fetchCliByTgIdObjArrStruct = fetchCliByTgIdObjArrStruct;

        cJSON_Delete(jsonParser);
        return fetchCliByTelegramIdStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonFetchClientByTelegramIdStruct* failRStruct = (struct jsonFetchClientByTelegramIdStruct*)calloc(1, sizeof(struct jsonFetchClientByTelegramIdStruct));
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

void jsonFetchClientByTelegramIdObjectArrayClientObjectStructDelete(struct jsonFetchClientByTelegramIdObjectArrayClientObjectStruct* fetchCliByTgIdObjArrCliObjStruct) {
    if (!fetchCliByTgIdObjArrCliObjStruct) {
        return;
    }

    free((char*)fetchCliByTgIdObjArrCliObjStruct->email);
    free((char*)fetchCliByTgIdObjArrCliObjStruct->subId);
    free((char*)fetchCliByTgIdObjArrCliObjStruct->uuid);
    free((char*)fetchCliByTgIdObjArrCliObjStruct->password);
    free((char*)fetchCliByTgIdObjArrCliObjStruct->auth);
    free((char*)fetchCliByTgIdObjArrCliObjStruct->flow);
    free((char*)fetchCliByTgIdObjArrCliObjStruct->security);
    free((char*)fetchCliByTgIdObjArrCliObjStruct->privateKey);
    free((char*)fetchCliByTgIdObjArrCliObjStruct->publicKey);
    free((char*)fetchCliByTgIdObjArrCliObjStruct->allowedIPs);
    free((char*)fetchCliByTgIdObjArrCliObjStruct->preSharedKey);
    free((char*)fetchCliByTgIdObjArrCliObjStruct->forwardedPorts);
    free((char*)fetchCliByTgIdObjArrCliObjStruct->secret);
    free((char*)fetchCliByTgIdObjArrCliObjStruct->adTag);
    free((char*)fetchCliByTgIdObjArrCliObjStruct->group);
    free((char*)fetchCliByTgIdObjArrCliObjStruct->comment);
    free((char*)fetchCliByTgIdObjArrCliObjStruct->trafficReset);

    free(fetchCliByTgIdObjArrCliObjStruct);
}

void jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStructDelete(struct jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStruct* fetchCliByTgIArrdObjExternalLinksArrStruct, size_t arraySize) {
    if (!fetchCliByTgIArrdObjExternalLinksArrStruct) {
        return;
    }

    for (size_t i = 0; i < arraySize; i++) {
        free((char*)fetchCliByTgIArrdObjExternalLinksArrStruct[i].kind);
        free((char*)fetchCliByTgIArrdObjExternalLinksArrStruct[i].value);
        free((char*)fetchCliByTgIArrdObjExternalLinksArrStruct[i].remark);
        free((char*)fetchCliByTgIArrdObjExternalLinksArrStruct[i].namePrefix);
    }

    free(fetchCliByTgIArrdObjExternalLinksArrStruct);
}

void jsonFetchClientByTelegramIdObjectArrayStructDelete(struct jsonFetchClientByTelegramIdObjectArrayStruct* fetchCliByTgIdObjArrStruct, size_t arraySize) {
    if (!fetchCliByTgIdObjArrStruct) {
        return;
    }

    for (size_t i = 0; i < arraySize; i++) {
        if (fetchCliByTgIdObjArrStruct[i].fetchCliByTgIdObjArrCliObjStruct) {
            jsonFetchClientByTelegramIdObjectArrayClientObjectStructDelete(fetchCliByTgIdObjArrStruct[i].fetchCliByTgIdObjArrCliObjStruct);
            fetchCliByTgIdObjArrStruct[i].fetchCliByTgIdObjArrCliObjStruct = NULL;
        }

        if (fetchCliByTgIdObjArrStruct[i].fetchCliByTgIArrdObjExternalLinksArrStruct) {
            jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStructDelete(fetchCliByTgIdObjArrStruct[i].fetchCliByTgIArrdObjExternalLinksArrStruct, fetchCliByTgIdObjArrStruct[i].jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStructSize);
            fetchCliByTgIdObjArrStruct[i].fetchCliByTgIArrdObjExternalLinksArrStruct = NULL;
        }

        free(fetchCliByTgIdObjArrStruct[i].inboundIds);
        free((char*)fetchCliByTgIdObjArrStruct[i].tunnelAllowedIPs);
    }

    free(fetchCliByTgIdObjArrStruct);
}

void jsonFetchClientByTelegramIdStructDelete(struct jsonFetchClientByTelegramIdStruct* fetchCliByTelegramIdStruct) {
    if (!fetchCliByTelegramIdStruct) {
        return;
    }

    free((char*)fetchCliByTelegramIdStruct->msg);

    if (fetchCliByTelegramIdStruct->fetchCliByTgIdObjArrStruct) {
        jsonFetchClientByTelegramIdObjectArrayStructDelete(fetchCliByTelegramIdStruct->fetchCliByTgIdObjArrStruct, fetchCliByTelegramIdStruct->jsonFetchClientByTelegramIdObjectArrayStructSize);
        fetchCliByTelegramIdStruct->fetchCliByTgIdObjArrStruct = NULL;
    }

    free(fetchCliByTelegramIdStruct);
}

void jsonCreateNewClientPostStructDelete(struct jsonCreateNewClientPostStruct* createNewClientPostStruct) {
    if (!createNewClientPostStruct) {
        return;
    }

    free((char*)createNewClientPostStruct->emaill);
    free(createNewClientPostStruct->inboundIds);

    free(createNewClientPostStruct);
}

const char* jsonCreateNewClientPost(struct jsonCreateNewClientPostStruct* createNewClientPostStruct) {
    if (!createNewClientPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "createNewClientPostStruct is a null pointer");
        return NULL;
    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");
        return NULL;
    }

    // Create client object
    cJSON* clientObj = cJSON_CreateObject();
    if (!clientObj) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create client object");
        cJSON_Delete(json);
        return NULL;
    }
    cJSON_AddItemToObject(json, "client", clientObj);

    if (createNewClientPostStruct->emaill) {
        cJSON_AddStringToObject(clientObj, "email", createNewClientPostStruct->emaill);
    }
    cJSON_AddNumberToObject(clientObj, "totalGB", (double)createNewClientPostStruct->totalGB);
    cJSON_AddNumberToObject(clientObj, "expiryTime", (double)createNewClientPostStruct->expiryTime);
    cJSON_AddNumberToObject(clientObj, "tgId", (double)createNewClientPostStruct->tgId);
    cJSON_AddNumberToObject(clientObj, "limitIp", createNewClientPostStruct->limitIp);
    cJSON_AddNumberToObject(clientObj, "limitHwid", createNewClientPostStruct->limitHwid);
    cJSON_AddBoolToObject(clientObj, "enable", createNewClientPostStruct->enable);

    // Create inboundIds array
    if (createNewClientPostStruct->inboundIdsCount > 0 && createNewClientPostStruct->inboundIds) {
        cJSON* inboundIdsArray = cJSON_CreateArray();
        if (!inboundIdsArray) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create inboundIds array");
            cJSON_Delete(json);
            return NULL;
        }
        cJSON_AddItemToObject(json, "inboundIds", inboundIdsArray);

        for (int64_t i = 0; i < createNewClientPostStruct->inboundIdsCount; i++) {
            cJSON_AddItemToArray(inboundIdsArray, cJSON_CreateNumber(createNewClientPostStruct->inboundIds[i]));
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

struct jsonCreateNewClientResponseStruct* jsonCreateNewClientResponse(const char* json) {
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
        cJSON_HasObjectItem(jsonParser, "msg")
    ) {
        struct jsonCreateNewClientResponseStruct* createNewCliRStruct = (struct jsonCreateNewClientResponseStruct*)malloc(sizeof(struct jsonCreateNewClientResponseStruct));
        if (!createNewCliRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "createNewCliRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        createNewCliRStruct->success = 1;

        char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
        size_t msgLen = strlen(msg);
        char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
        if (!msgCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "msgCopy is a null pointer");
            free(createNewCliRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }
        strncpy(msgCopy, msg, msgLen);
        msgCopy[msgLen] = '\0';
        createNewCliRStruct->msg = msgCopy;

        createNewCliRStruct->obj = NULL; // This shall be null on success

        cJSON_Delete(jsonParser);
        return createNewCliRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonCreateNewClientResponseStruct* failRStruct = (struct jsonCreateNewClientResponseStruct*)calloc(1, sizeof(struct jsonCreateNewClientResponseStruct));
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

void jsonCreateNewClientResponseStructDelete(struct jsonCreateNewClientResponseStruct* createNewCliRStruct) {
    if (!createNewCliRStruct) {
        return;
    }

    free((char*)createNewCliRStruct->msg);
    free(createNewCliRStruct);
}

void jsonUpdateClientByEmailPostStructDelete(struct jsonUpdateClientByEmailPostStruct* updateClientByEmailPostStruct) {
    if (!updateClientByEmailPostStruct) {
        return;
    }

    free((char*)updateClientByEmailPostStruct->emaill);
    free(updateClientByEmailPostStruct->inboundIds);

    free(updateClientByEmailPostStruct);
}

const char* jsonUpdateClientByEmailPost(struct jsonUpdateClientByEmailPostStruct* updateClientByEmailPostStruct) {
    if (!updateClientByEmailPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "updateClientByEmailPostStruct is a null pointer");
        return NULL;
    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");
        return NULL;
    }

    if (updateClientByEmailPostStruct->emaill) {
        cJSON_AddStringToObject(json, "email", updateClientByEmailPostStruct->emaill);
    }
    cJSON_AddNumberToObject(json, "totalGB", (double)updateClientByEmailPostStruct->totalGB);
    cJSON_AddNumberToObject(json, "expiryTime", (double)updateClientByEmailPostStruct->expiryTime);
    cJSON_AddNumberToObject(json, "tgId", (double)updateClientByEmailPostStruct->tgId);
    cJSON_AddNumberToObject(json, "limitIp", updateClientByEmailPostStruct->limitIp);
    cJSON_AddNumberToObject(json, "limitHwid", updateClientByEmailPostStruct->limitHwid);
    cJSON_AddBoolToObject(json, "enable", updateClientByEmailPostStruct->enable);

    // Create inboundIds array
    if (updateClientByEmailPostStruct->inboundIdsCount > 0 && updateClientByEmailPostStruct->inboundIds) {
        cJSON* inboundIdsArray = cJSON_CreateArray();
        if (!inboundIdsArray) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create inboundIds array");
            cJSON_Delete(json);
            return NULL;
        }
        cJSON_AddItemToObject(json, "inboundIds", inboundIdsArray);

        for (int64_t i = 0; i < updateClientByEmailPostStruct->inboundIdsCount; i++) {
            cJSON_AddItemToArray(inboundIdsArray, cJSON_CreateNumber(updateClientByEmailPostStruct->inboundIds[i]));
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

struct jsonUpdateClientByEmailResponseStruct* jsonUpdateClientByEmailResponse(const char* json) {
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
        cJSON_HasObjectItem(jsonParser, "msg")
    ) {
        struct jsonUpdateClientByEmailResponseStruct* updateCliByEmailRStruct = (struct jsonUpdateClientByEmailResponseStruct*)malloc(sizeof(struct jsonUpdateClientByEmailResponseStruct));
        if (!updateCliByEmailRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "updateCliByEmailRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        updateCliByEmailRStruct->success = 1;

        char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
        size_t msgLen = strlen(msg);
        char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
        if (!msgCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "msgCopy is a null pointer");
            free(updateCliByEmailRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }
        strncpy(msgCopy, msg, msgLen);
        msgCopy[msgLen] = '\0';
        updateCliByEmailRStruct->msg = msgCopy;

        updateCliByEmailRStruct->obj = NULL; // This shall be null on success

        cJSON_Delete(jsonParser);
        return updateCliByEmailRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonUpdateClientByEmailResponseStruct* failRStruct = (struct jsonUpdateClientByEmailResponseStruct*)calloc(1, sizeof(struct jsonUpdateClientByEmailResponseStruct));
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

void jsonUpdateClientByEmailResponseStructDelete(struct jsonUpdateClientByEmailResponseStruct* updateCliByEmailRStruct) {
    if (!updateCliByEmailRStruct) {
        return;
    }

    free((char*)updateCliByEmailRStruct->msg);
    free(updateCliByEmailRStruct);
}

void jsonDeleteClientByEmailResponseStructDelete(struct jsonDeleteClientByEmailResponseStruct* deleteCliByEmailRStruct) {
    if (!deleteCliByEmailRStruct) {
        return;
    }

    free((char*)deleteCliByEmailRStruct->msg);
    free(deleteCliByEmailRStruct);
}

struct jsonDeleteClientByEmailResponseStruct* jsonDeleteClientByEmailResponse(const char* json) {
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
        cJSON_HasObjectItem(jsonParser, "msg") &&
        cJSON_IsString(cJSON_GetObjectItem(jsonParser, "msg"))
    ) {
        struct jsonDeleteClientByEmailResponseStruct* deleteCliByEmailRStruct = (struct jsonDeleteClientByEmailResponseStruct*)malloc(sizeof(struct jsonDeleteClientByEmailResponseStruct));
        if (!deleteCliByEmailRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "deleteCliByEmailRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        deleteCliByEmailRStruct->success = 1;

        char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
        size_t msgLen = strlen(msg);
        char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
        if (!msgCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "msgCopy is a null pointer");
            free(deleteCliByEmailRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }
        strncpy(msgCopy, msg, msgLen);
        msgCopy[msgLen] = '\0';
        deleteCliByEmailRStruct->msg = msgCopy;

        deleteCliByEmailRStruct->obj = NULL; // This shall be null on success

        cJSON_Delete(jsonParser);
        return deleteCliByEmailRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonDeleteClientByEmailResponseStruct* failRStruct = (struct jsonDeleteClientByEmailResponseStruct*)calloc(1, sizeof(struct jsonDeleteClientByEmailResponseStruct));
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

void jsonExternalLinksObjectArrayPostStructDelete(struct jsonExternalLinksObjectArrayPostStruct* rplExtLinksObjArrPStruct, size_t arraySize) {
    if (!rplExtLinksObjArrPStruct) {
        return;
    }

    for (size_t i = 0; i < arraySize; i++) {
        free((char*)rplExtLinksObjArrPStruct[i].kind);
        free((char*)rplExtLinksObjArrPStruct[i].value);
        free((char*)rplExtLinksObjArrPStruct[i].remark);
        free((char*)rplExtLinksObjArrPStruct[i].namePrefix);
    }

    free(rplExtLinksObjArrPStruct);
}

void jsonReplaceClientExternalLinksPostStructDelete(struct jsonReplaceClientExternalLinksPostStruct* replaceClientExternalLinksPostStruct) {
    if (!replaceClientExternalLinksPostStruct) {
        return;
    }

    if (replaceClientExternalLinksPostStruct->rplExtLinksObjArrPStruct) {
        jsonExternalLinksObjectArrayPostStructDelete(replaceClientExternalLinksPostStruct->rplExtLinksObjArrPStruct, replaceClientExternalLinksPostStruct->jsonExternalLinksObjectArrayPostStructSize);
        replaceClientExternalLinksPostStruct->rplExtLinksObjArrPStruct = NULL;
    }

    free(replaceClientExternalLinksPostStruct);
}

const char* jsonReplaceClientExternalLinksPost(struct jsonReplaceClientExternalLinksPostStruct* replaceClientExternalLinksPostStruct) {
    if (!replaceClientExternalLinksPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "replaceClientExternalLinksPostStruct is a null pointer");
        return NULL;
    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");
        return NULL;
    }

    if (replaceClientExternalLinksPostStruct->jsonExternalLinksObjectArrayPostStructSize > 0 && replaceClientExternalLinksPostStruct->rplExtLinksObjArrPStruct) {
        cJSON* externalLinksArray = cJSON_CreateArray();
        if (!externalLinksArray) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create externalLinks array");
            cJSON_Delete(json);
            return NULL;
        }
        cJSON_AddItemToObject(json, "externalLinks", externalLinksArray);

        for (size_t i = 0; i < replaceClientExternalLinksPostStruct->jsonExternalLinksObjectArrayPostStructSize; i++) {
            struct jsonExternalLinksObjectArrayPostStruct* link = &replaceClientExternalLinksPostStruct->rplExtLinksObjArrPStruct[i];
            cJSON* linkObj = cJSON_CreateObject();
            if (!linkObj) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "linkObj is a null pointer, failed to create json object");
                cJSON_Delete(json);
                return NULL;
            }
            cJSON_AddItemToArray(externalLinksArray, linkObj);

            if (link->kind) {
                cJSON_AddStringToObject(linkObj, "kind", link->kind);
            }
            if (link->value) {
                cJSON_AddStringToObject(linkObj, "value", link->value);
            }
            if (link->remark) {
                cJSON_AddStringToObject(linkObj, "remark", link->remark);
            }
            cJSON_AddBoolToObject(linkObj, "enable", link->enable);
            if (link->expiryTime) {
                cJSON_AddNumberToObject(linkObj, "expiryTime", (double)link->expiryTime);
            }
            if (link->namePrefix) {
                cJSON_AddStringToObject(linkObj, "namePrefix", link->namePrefix);
            }
        }
    } else {
        // Send empty array to clear all rows
        cJSON* externalLinksArray = cJSON_CreateArray();
        if (!externalLinksArray) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create externalLinks array");
            cJSON_Delete(json);
            return NULL;
        }
        cJSON_AddItemToObject(json, "externalLinks", externalLinksArray);
    }

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");
        return NULL;
    }

    return jsonString;
}

void jsonReplaceClientExternalLinksResponseStructDelete(struct jsonReplaceClientExternalLinksResponseStruct* replaceCliExternalLinksRStruct) {
    if (!replaceCliExternalLinksRStruct) {
        return;
    }

    free((char*)replaceCliExternalLinksRStruct->msg);
    free(replaceCliExternalLinksRStruct);
}

struct jsonReplaceClientExternalLinksResponseStruct* jsonReplaceClientExternalLinksResponse(const char* json) {
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
        struct jsonReplaceClientExternalLinksResponseStruct* replaceCliExternalLinksRStruct = (struct jsonReplaceClientExternalLinksResponseStruct*)malloc(sizeof(struct jsonReplaceClientExternalLinksResponseStruct));
        if (!replaceCliExternalLinksRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "replaceCliExternalLinksRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        replaceCliExternalLinksRStruct->success = 1;

        if (cJSON_HasObjectItem(jsonParser, "msg") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "msg"))) {
            char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
            size_t msgLen = strlen(msg);
            char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
            if (!msgCopy) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "msgCopy is a null pointer");
                free(replaceCliExternalLinksRStruct);
                cJSON_Delete(jsonParser);
                return NULL;
            }
            strncpy(msgCopy, msg, msgLen);
            msgCopy[msgLen] = '\0';
            replaceCliExternalLinksRStruct->msg = msgCopy;
        } else {
            replaceCliExternalLinksRStruct->msg = NULL;
        }

        replaceCliExternalLinksRStruct->obj = NULL; // This shall be null on success

        cJSON_Delete(jsonParser);
        return replaceCliExternalLinksRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonReplaceClientExternalLinksResponseStruct* failRStruct = (struct jsonReplaceClientExternalLinksResponseStruct*)calloc(1, sizeof(struct jsonReplaceClientExternalLinksResponseStruct));
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

void jsonResetAllClientsTrafficsResponseStructDelete(struct jsonResetAllClientsTrafficsResponseStruct* resetAllCliTrafficsRStruct) {
    if (!resetAllCliTrafficsRStruct) {
        return;
    }

    free((char*)resetAllCliTrafficsRStruct->msg);
    free(resetAllCliTrafficsRStruct);
}

struct jsonResetAllClientsTrafficsResponseStruct* jsonResetAllClientsTrafficsResponse(const char* json) {
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
        struct jsonResetAllClientsTrafficsResponseStruct* resetAllCliTrafficsRStruct = (struct jsonResetAllClientsTrafficsResponseStruct*)malloc(sizeof(struct jsonResetAllClientsTrafficsResponseStruct));
        if (!resetAllCliTrafficsRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "resetAllCliTrafficsRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        resetAllCliTrafficsRStruct->success = 1;

        if (cJSON_HasObjectItem(jsonParser, "msg") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "msg"))) {
            char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
            size_t msgLen = strlen(msg);
            char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
            if (!msgCopy) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "msgCopy is a null pointer");
                free(resetAllCliTrafficsRStruct);
                cJSON_Delete(jsonParser);
                return NULL;
            }
            strncpy(msgCopy, msg, msgLen);
            msgCopy[msgLen] = '\0';
            resetAllCliTrafficsRStruct->msg = msgCopy;
        } else {
            resetAllCliTrafficsRStruct->msg = NULL;
        }

        resetAllCliTrafficsRStruct->obj = NULL; // This shall be null on success

        cJSON_Delete(jsonParser);
        return resetAllCliTrafficsRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonResetAllClientsTrafficsResponseStruct* failRStruct = (struct jsonResetAllClientsTrafficsResponseStruct*)calloc(1, sizeof(struct jsonResetAllClientsTrafficsResponseStruct));
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

void jsonDeleteAllDepletedClientsResponseStructDelete(struct jsonDeleteAllDepletedClientsResponseStruct* deleteAllDepletedCliRStruct) {
    if (!deleteAllDepletedCliRStruct) {
        return;

    }

    free(deleteAllDepletedCliRStruct->success);
    free((char*)deleteAllDepletedCliRStruct->msg);
    free(deleteAllDepletedCliRStruct);

}

struct jsonDeleteAllDepletedClientsResponseStruct* jsonDeleteAllDepletedClientsResponse(const char* json) {
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

        struct jsonDeleteAllDepletedClientsResponseStruct* deleteAllDepletedCliRStruct = (struct jsonDeleteAllDepletedClientsResponseStruct*)calloc(1, sizeof(struct jsonDeleteAllDepletedClientsResponseStruct));
        if (!deleteAllDepletedCliRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "deleteAllDepletedCliRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        deleteAllDepletedCliRStruct->success = (unsigned char*)calloc(1, sizeof(unsigned char));
        if (!deleteAllDepletedCliRStruct->success) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "success is a null pointer, failed to allocate memory");

            free(deleteAllDepletedCliRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }
        *deleteAllDepletedCliRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &deleteAllDepletedCliRStruct->msg)) {
            jsonDeleteAllDepletedClientsResponseStructDelete(deleteAllDepletedCliRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (cJSON_HasObjectItem(obj, "deleted") && cJSON_IsNumber(cJSON_GetObjectItem(obj, "deleted"))) {
            deleteAllDepletedCliRStruct->deleted = (int64_t)cJSON_GetObjectItem(obj, "deleted")->valuedouble;

        }

        cJSON_Delete(jsonParser);

        return deleteAllDepletedCliRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonDeleteAllDepletedClientsResponseStruct* failRStruct = (struct jsonDeleteAllDepletedClientsResponseStruct*)calloc(1, sizeof(struct jsonDeleteAllDepletedClientsResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        failRStruct->success = (unsigned char*)calloc(1, sizeof(unsigned char));
        failRStruct->msg = jsonCopyMsg(jsonParser);

        cJSON_Delete(jsonParser);

        return failRStruct;

    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");

        cJSON_Delete(jsonParser);

        return NULL;

    }

}

void jsonDeleteAllOrphanClientsResponseStructDelete(struct jsonDeleteAllOrphanClientsResponseStruct* deleteAllOrphanCliRStruct) {
    if (!deleteAllOrphanCliRStruct) {
        return;

    }

    free(deleteAllOrphanCliRStruct->success);
    free((char*)deleteAllOrphanCliRStruct->msg);
    free(deleteAllOrphanCliRStruct);

}

struct jsonDeleteAllOrphanClientsResponseStruct* jsonDeleteAllOrphanClientsResponse(const char* json) {
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

        struct jsonDeleteAllOrphanClientsResponseStruct* deleteAllOrphanCliRStruct = (struct jsonDeleteAllOrphanClientsResponseStruct*)calloc(1, sizeof(struct jsonDeleteAllOrphanClientsResponseStruct));
        if (!deleteAllOrphanCliRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "deleteAllOrphanCliRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        deleteAllOrphanCliRStruct->success = (unsigned char*)calloc(1, sizeof(unsigned char));
        if (!deleteAllOrphanCliRStruct->success) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "success is a null pointer, failed to allocate memory");

            free(deleteAllOrphanCliRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }
        *deleteAllOrphanCliRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &deleteAllOrphanCliRStruct->msg)) {
            jsonDeleteAllOrphanClientsResponseStructDelete(deleteAllOrphanCliRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (cJSON_HasObjectItem(obj, "deleted") && cJSON_IsNumber(cJSON_GetObjectItem(obj, "deleted"))) {
            deleteAllOrphanCliRStruct->deleted = (int64_t)cJSON_GetObjectItem(obj, "deleted")->valuedouble;

        }

        cJSON_Delete(jsonParser);

        return deleteAllOrphanCliRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonDeleteAllOrphanClientsResponseStruct* failRStruct = (struct jsonDeleteAllOrphanClientsResponseStruct*)calloc(1, sizeof(struct jsonDeleteAllOrphanClientsResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        failRStruct->success = (unsigned char*)calloc(1, sizeof(unsigned char));
        failRStruct->msg = jsonCopyMsg(jsonParser);

        cJSON_Delete(jsonParser);

        return failRStruct;

    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");

        cJSON_Delete(jsonParser);

        return NULL;

    }

}

void jsonExportAllClientsObjectArrayClientObjectResponseStructDelete(struct jsonExportAllClientsObjectArrayClientObjectResponseStruct* exportAllCliObjArrCliObjRStruct) {
    if (!exportAllCliObjArrCliObjRStruct) {
        return;
    }

    free((char*)exportAllCliObjArrCliObjRStruct->id);
    free((char*)exportAllCliObjArrCliObjRStruct->security);
    free((char*)exportAllCliObjArrCliObjRStruct->password);
    free((char*)exportAllCliObjArrCliObjRStruct->auth);
    free((char*)exportAllCliObjArrCliObjRStruct->email);
    free((char*)exportAllCliObjArrCliObjRStruct->subId);
    free((char*)exportAllCliObjArrCliObjRStruct->group);
    free((char*)exportAllCliObjArrCliObjRStruct->comment);
    free((char*)exportAllCliObjArrCliObjRStruct->trafficReset);

    free(exportAllCliObjArrCliObjRStruct);
}

void jsonExportAllClientsObjectArrayResponseStructDelete(struct jsonExportAllClientsObjectArrayResponseStruct* exportAllClisObjArrRStruct, size_t arraySize) {
    if (!exportAllClisObjArrRStruct) {
        return;
    }

    for (size_t i = 0; i < arraySize; i++) {
        if (exportAllClisObjArrRStruct[i].exportAllCliObjArrCliObjRStruct) {
            jsonExportAllClientsObjectArrayClientObjectResponseStructDelete(exportAllClisObjArrRStruct[i].exportAllCliObjArrCliObjRStruct);
            exportAllClisObjArrRStruct[i].exportAllCliObjArrCliObjRStruct = NULL;
        }
        free(exportAllClisObjArrRStruct[i].inboundIds);
        free(exportAllClisObjArrRStruct[i].trafficObjRStruct);
    }

    free(exportAllClisObjArrRStruct);
}

void jsonExportAllClientsResponseStructDelete(struct jsonExportAllClientsResponseStruct* exportAllCliRStruct) {
    if (!exportAllCliRStruct) {
        return;
    }

    free((char*)exportAllCliRStruct->msg);

    if (exportAllCliRStruct->exportAllClisObjArrRStruct) {
        jsonExportAllClientsObjectArrayResponseStructDelete(exportAllCliRStruct->exportAllClisObjArrRStruct, exportAllCliRStruct->jsonExportAllClientsObjectArrayResponseStructSize);
        exportAllCliRStruct->exportAllClisObjArrRStruct = NULL;
    }

    free(exportAllCliRStruct);
}

static int jsonExportAllClientsObjectArrayClientObjectResponseStructParse(cJSON* clientObj, struct jsonExportAllClientsObjectArrayClientObjectResponseStruct* clientStruct) {
    if (!clientObj) {
        return 0;
    }

    if (cJSON_HasObjectItem(clientObj, "id") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "id"))) {
        size_t idLen = strlen(cJSON_GetObjectItem(clientObj, "id")->valuestring);
        char* idCopy = (char*)malloc((idLen + 1) * sizeof(char));
        if (!idCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "id is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(idCopy, cJSON_GetObjectItem(clientObj, "id")->valuestring, idLen);
        idCopy[idLen] = '\0';
        clientStruct->id = idCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "security") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "security"))) {
        size_t securityLen = strlen(cJSON_GetObjectItem(clientObj, "security")->valuestring);
        char* securityCopy = (char*)malloc((securityLen + 1) * sizeof(char));
        if (!securityCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "security is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(securityCopy, cJSON_GetObjectItem(clientObj, "security")->valuestring, securityLen);
        securityCopy[securityLen] = '\0';
        clientStruct->security = securityCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "password") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "password"))) {
        size_t passwordLen = strlen(cJSON_GetObjectItem(clientObj, "password")->valuestring);
        char* passwordCopy = (char*)malloc((passwordLen + 1) * sizeof(char));
        if (!passwordCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "password is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(passwordCopy, cJSON_GetObjectItem(clientObj, "password")->valuestring, passwordLen);
        passwordCopy[passwordLen] = '\0';
        clientStruct->password = passwordCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "auth") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "auth"))) {
        size_t authLen = strlen(cJSON_GetObjectItem(clientObj, "auth")->valuestring);
        char* authCopy = (char*)malloc((authLen + 1) * sizeof(char));
        if (!authCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "auth is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(authCopy, cJSON_GetObjectItem(clientObj, "auth")->valuestring, authLen);
        authCopy[authLen] = '\0';
        clientStruct->auth = authCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "email") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "email"))) {
        size_t emailLen = strlen(cJSON_GetObjectItem(clientObj, "email")->valuestring);
        char* emailCopy = (char*)malloc((emailLen + 1) * sizeof(char));
        if (!emailCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "email is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(emailCopy, cJSON_GetObjectItem(clientObj, "email")->valuestring, emailLen);
        emailCopy[emailLen] = '\0';
        clientStruct->email = emailCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "limitIp") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "limitIp"))) {
        clientStruct->limitIp = (int)cJSON_GetObjectItem(clientObj, "limitIp")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "totalGB") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "totalGB"))) {
        clientStruct->totalGB = (int)cJSON_GetObjectItem(clientObj, "totalGB")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "expiryTime") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "expiryTime"))) {
        clientStruct->expiryTime = (int64_t)cJSON_GetObjectItem(clientObj, "expiryTime")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "enable") && cJSON_IsBool(cJSON_GetObjectItem(clientObj, "enable"))) {
        clientStruct->enable = cJSON_IsTrue(cJSON_GetObjectItem(clientObj, "enable")) ? 1 : 0;
    }

    if (cJSON_HasObjectItem(clientObj, "tgId") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "tgId"))) {
        clientStruct->tgId = (int64_t)cJSON_GetObjectItem(clientObj, "tgId")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "subId") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "subId"))) {
        size_t subIdLen = strlen(cJSON_GetObjectItem(clientObj, "subId")->valuestring);
        char* subIdCopy = (char*)malloc((subIdLen + 1) * sizeof(char));
        if (!subIdCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "subId is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(subIdCopy, cJSON_GetObjectItem(clientObj, "subId")->valuestring, subIdLen);
        subIdCopy[subIdLen] = '\0';
        clientStruct->subId = subIdCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "group") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "group"))) {
        size_t groupLen = strlen(cJSON_GetObjectItem(clientObj, "group")->valuestring);
        char* groupCopy = (char*)malloc((groupLen + 1) * sizeof(char));
        if (!groupCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "group is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(groupCopy, cJSON_GetObjectItem(clientObj, "group")->valuestring, groupLen);
        groupCopy[groupLen] = '\0';
        clientStruct->group = groupCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "comment") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "comment"))) {
        size_t commentLen = strlen(cJSON_GetObjectItem(clientObj, "comment")->valuestring);
        char* commentCopy = (char*)malloc((commentLen + 1) * sizeof(char));
        if (!commentCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "comment is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(commentCopy, cJSON_GetObjectItem(clientObj, "comment")->valuestring, commentLen);
        commentCopy[commentLen] = '\0';
        clientStruct->comment = commentCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "reset") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "reset"))) {
        clientStruct->reset = (int)cJSON_GetObjectItem(clientObj, "reset")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "resetDay") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "resetDay"))) {
        clientStruct->resetDay = (int)cJSON_GetObjectItem(clientObj, "resetDay")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "resetMax") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "resetMax"))) {
        clientStruct->resetMax = (int)cJSON_GetObjectItem(clientObj, "resetMax")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "trafficReset") && cJSON_IsString(cJSON_GetObjectItem(clientObj, "trafficReset"))) {
        size_t trafficResetLen = strlen(cJSON_GetObjectItem(clientObj, "trafficReset")->valuestring);
        char* trafficResetCopy = (char*)malloc((trafficResetLen + 1) * sizeof(char));
        if (!trafficResetCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "trafficReset is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(trafficResetCopy, cJSON_GetObjectItem(clientObj, "trafficReset")->valuestring, trafficResetLen);
        trafficResetCopy[trafficResetLen] = '\0';
        clientStruct->trafficReset = trafficResetCopy;
    }

    if (cJSON_HasObjectItem(clientObj, "trafficResetDay") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "trafficResetDay"))) {
        clientStruct->trafficResetDay = (int)cJSON_GetObjectItem(clientObj, "trafficResetDay")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "created_at") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "created_at"))) {
        clientStruct->createdAt = (int64_t)cJSON_GetObjectItem(clientObj, "created_at")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "updated_at") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "updated_at"))) {
        clientStruct->updatedAt = (int64_t)cJSON_GetObjectItem(clientObj, "updated_at")->valuedouble;
    }

    if (cJSON_HasObjectItem(clientObj, "limitHwid") && cJSON_IsNumber(cJSON_GetObjectItem(clientObj, "limitHwid"))) {
        clientStruct->limitHwid = (int)cJSON_GetObjectItem(clientObj, "limitHwid")->valuedouble;
    }

    return 1;
}

static int jsonExportAllClientsTrafficObjectResponseStructParse(cJSON* trafficObj, struct jsonExportAllClientsTrafficObjectResponseStruct* trafficStruct) {
    if (!trafficObj) {
        return 0;

    }

    if (cJSON_HasObjectItem(trafficObj, "up") && cJSON_IsNumber(cJSON_GetObjectItem(trafficObj, "up"))) {
        trafficStruct->up = (int64_t)cJSON_GetObjectItem(trafficObj, "up")->valuedouble;

    }

    if (cJSON_HasObjectItem(trafficObj, "down") && cJSON_IsNumber(cJSON_GetObjectItem(trafficObj, "down"))) {
        trafficStruct->down = (int64_t)cJSON_GetObjectItem(trafficObj, "down")->valuedouble;

    }

    if (cJSON_HasObjectItem(trafficObj, "resetCount") && cJSON_IsNumber(cJSON_GetObjectItem(trafficObj, "resetCount"))) {
        trafficStruct->resetCount = (int)cJSON_GetObjectItem(trafficObj, "resetCount")->valuedouble;

    }

    if (cJSON_HasObjectItem(trafficObj, "lastOnline") && cJSON_IsNumber(cJSON_GetObjectItem(trafficObj, "lastOnline"))) {
        trafficStruct->lastOnline = (int64_t)cJSON_GetObjectItem(trafficObj, "lastOnline")->valuedouble;

    }

    return 1;

}

struct jsonExportAllClientsResponseStruct* jsonExportAllClientsResponse(const char* json) {
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
        if (!objArray) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "objArray is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        size_t arraySize = cJSON_GetArraySize(objArray);
        struct jsonExportAllClientsObjectArrayResponseStruct* exportAllClisObjArrRStruct = NULL;
        if (arraySize) {
            exportAllClisObjArrRStruct = (struct jsonExportAllClientsObjectArrayResponseStruct*)calloc(arraySize, sizeof(struct jsonExportAllClientsObjectArrayResponseStruct));
            if (!exportAllClisObjArrRStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "exportAllClisObjArrRStruct is a null pointer");
                cJSON_Delete(jsonParser);
                return NULL;
            }
            for (size_t i = 0; i < arraySize; i++) {
                cJSON* arrItem = cJSON_GetArrayItem(objArray, i);
                if (!cJSON_IsObject(arrItem)) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Array element is not an object, skipping...");
                    continue;
                }

                // Parse client object
                if (cJSON_HasObjectItem(arrItem, "client") && cJSON_IsObject(cJSON_GetObjectItem(arrItem, "client"))) {
                    cJSON* clientObj = cJSON_GetObjectItem(arrItem, "client");
                    struct jsonExportAllClientsObjectArrayClientObjectResponseStruct* clientStruct = (struct jsonExportAllClientsObjectArrayClientObjectResponseStruct*)calloc(1, sizeof(struct jsonExportAllClientsObjectArrayClientObjectResponseStruct));
                    if (!clientStruct) {
                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "clientStruct is a null pointer");
                        // Clean up
                        for (size_t j = 0; j < i; j++) {
                            if (exportAllClisObjArrRStruct[j].exportAllCliObjArrCliObjRStruct) {
                                jsonExportAllClientsObjectArrayClientObjectResponseStructDelete(exportAllClisObjArrRStruct[j].exportAllCliObjArrCliObjRStruct);
                            }
                            free(exportAllClisObjArrRStruct[j].inboundIds);
                        }
                        free(exportAllClisObjArrRStruct);
                        cJSON_Delete(jsonParser);
                        return NULL;
                    }
                    if (jsonExportAllClientsObjectArrayClientObjectResponseStructParse(clientObj, clientStruct) == 0) {
                        applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Failed to parse client object");
                    }
                    exportAllClisObjArrRStruct[i].exportAllCliObjArrCliObjRStruct = clientStruct;
                }

                // Parse inboundIds array
                if (cJSON_HasObjectItem(arrItem, "inboundIds") && cJSON_IsArray(cJSON_GetObjectItem(arrItem, "inboundIds"))) {
                    cJSON* inboundIdsArr = cJSON_GetObjectItem(arrItem, "inboundIds");
                    size_t inboundIdsCount = cJSON_GetArraySize(inboundIdsArr);
                    if (inboundIdsCount) {
                        exportAllClisObjArrRStruct[i].inboundIds = (int*)malloc(inboundIdsCount * sizeof(int));
                        if (!exportAllClisObjArrRStruct[i].inboundIds) {
                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "inboundIds is a null pointer, failed to allocate memory");
                            // Clean up
                            for (size_t j = 0; j <= i; j++) {
                                if (exportAllClisObjArrRStruct[j].exportAllCliObjArrCliObjRStruct) {
                                    jsonExportAllClientsObjectArrayClientObjectResponseStructDelete(exportAllClisObjArrRStruct[j].exportAllCliObjArrCliObjRStruct);
                                }
                                free(exportAllClisObjArrRStruct[j].inboundIds);
                            }
                            free(exportAllClisObjArrRStruct);
                            cJSON_Delete(jsonParser);
                            return NULL;
                        }
                        exportAllClisObjArrRStruct[i].inboundIdsCount = (int64_t)inboundIdsCount;
                        for (size_t j = 0; j < inboundIdsCount; j++) {
                            cJSON* inboundIdsItem = cJSON_GetArrayItem(inboundIdsArr, j);
                            if (cJSON_IsNumber(inboundIdsItem)) {
                                exportAllClisObjArrRStruct[i].inboundIds[j] = (int)inboundIdsItem->valuedouble;
                            }
                        }
                    }
                }
            }
        }

        for (size_t i = 0; exportAllClisObjArrRStruct && i < arraySize; i++) {
            cJSON* arrItem = cJSON_GetArrayItem(objArray, i);
            if (!cJSON_IsObject(arrItem) || !cJSON_HasObjectItem(arrItem, "traffic") || !cJSON_IsObject(cJSON_GetObjectItem(arrItem, "traffic"))) {
                continue;

            }

            exportAllClisObjArrRStruct[i].trafficObjRStruct = (struct jsonExportAllClientsTrafficObjectResponseStruct*)calloc(1, sizeof(struct jsonExportAllClientsTrafficObjectResponseStruct));
            if (!exportAllClisObjArrRStruct[i].trafficObjRStruct) {
                applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "trafficObjRStruct is a null pointer, skipping the traffic object...");

                continue;

            }
            jsonExportAllClientsTrafficObjectResponseStructParse(cJSON_GetObjectItem(arrItem, "traffic"), exportAllClisObjArrRStruct[i].trafficObjRStruct);

        }

        struct jsonExportAllClientsResponseStruct* exportAllCliRStruct = (struct jsonExportAllClientsResponseStruct*)malloc(sizeof(struct jsonExportAllClientsResponseStruct));
        if (!exportAllCliRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "exportAllCliRStruct is a null pointer");
            if (exportAllClisObjArrRStruct) {
                for (size_t i = 0; i < arraySize; i++) {
                    if (exportAllClisObjArrRStruct[i].exportAllCliObjArrCliObjRStruct) {
                        jsonExportAllClientsObjectArrayClientObjectResponseStructDelete(exportAllClisObjArrRStruct[i].exportAllCliObjArrCliObjRStruct);
                    }
                    free(exportAllClisObjArrRStruct[i].inboundIds);
                }
                free(exportAllClisObjArrRStruct);
            }
            cJSON_Delete(jsonParser);
            return NULL;
        }

        exportAllCliRStruct->success = 1;

        if (cJSON_HasObjectItem(jsonParser, "msg") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "msg"))) {
            char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
            size_t msgLen = strlen(msg);
            char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
            if (!msgCopy) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "msgCopy is a null pointer");
                free(exportAllCliRStruct);
                if (exportAllClisObjArrRStruct) {
                    for (size_t i = 0; i < arraySize; i++) {
                        if (exportAllClisObjArrRStruct[i].exportAllCliObjArrCliObjRStruct) {
                            jsonExportAllClientsObjectArrayClientObjectResponseStructDelete(exportAllClisObjArrRStruct[i].exportAllCliObjArrCliObjRStruct);
                        }
                        free(exportAllClisObjArrRStruct[i].inboundIds);
                    }
                    free(exportAllClisObjArrRStruct);
                }
                cJSON_Delete(jsonParser);
                return NULL;
            }
            strncpy(msgCopy, msg, msgLen);
            msgCopy[msgLen] = '\0';
            exportAllCliRStruct->msg = msgCopy;
        } else {
            exportAllCliRStruct->msg = NULL;
        }

        exportAllCliRStruct->jsonExportAllClientsObjectArrayResponseStructSize = arraySize;
        exportAllCliRStruct->exportAllClisObjArrRStruct = exportAllClisObjArrRStruct;

        cJSON_Delete(jsonParser);
        return exportAllCliRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonExportAllClientsResponseStruct* failRStruct = (struct jsonExportAllClientsResponseStruct*)calloc(1, sizeof(struct jsonExportAllClientsResponseStruct));
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

void jsonImportClientsDataObjectPostStructDelete(struct jsonImportClientsDataObjectPostStruct* importClientsDataObjPStruct, size_t arraySize) {
    if (!importClientsDataObjPStruct) {
        return;
    }

    for (size_t i = 0; i < arraySize; i++) {
        free((char*)importClientsDataObjPStruct[i].id);
        free((char*)importClientsDataObjPStruct[i].security);
        free((char*)importClientsDataObjPStruct[i].password);
        free((char*)importClientsDataObjPStruct[i].auth);
        free((char*)importClientsDataObjPStruct[i].email);
        free((char*)importClientsDataObjPStruct[i].subId);
        free((char*)importClientsDataObjPStruct[i].group);
        free((char*)importClientsDataObjPStruct[i].comment);
        free(importClientsDataObjPStruct[i].inboundIds);
        free(importClientsDataObjPStruct[i].trafficObjPStruct);
        free((char*)importClientsDataObjPStruct[i].trafficReset);
    }

    free(importClientsDataObjPStruct);
}

void jsonImportClientsPostStructDelete(struct jsonImportClientsPostStruct* importClientsPostStruct) {
    if (!importClientsPostStruct) {
        return;
    }

    if (importClientsPostStruct->importClientsDataObjPStruct) {
        jsonImportClientsDataObjectPostStructDelete(importClientsPostStruct->importClientsDataObjPStruct, importClientsPostStruct->jsonImportClientsDataObjectPostStructSize);
        importClientsPostStruct->importClientsDataObjPStruct = NULL;
    }

    free(importClientsPostStruct);
}

const char* jsonImportClientsPost(struct jsonImportClientsPostStruct* importClientsPostStruct) {
    if (!importClientsPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "importClientsPostStruct is a null pointer");

        return NULL;

    }

    cJSON* importArray = cJSON_CreateArray();
    if (!importArray) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create import array");

        return NULL;

    }

    for (size_t i = 0; i < importClientsPostStruct->jsonImportClientsDataObjectPostStructSize; i++) {
        struct jsonImportClientsDataObjectPostStruct* client = &importClientsPostStruct->importClientsDataObjPStruct[i];

        cJSON* importItem = cJSON_CreateObject();
        if (!importItem) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "importItem is a null pointer, failed to create json object");

            cJSON_Delete(importArray);

            return NULL;

        }
        cJSON_AddItemToArray(importArray, importItem);

        cJSON* clientObj = cJSON_CreateObject();
        if (!clientObj) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "clientObj is a null pointer, failed to create json object");

            cJSON_Delete(importArray);

            return NULL;

        }
        cJSON_AddItemToObject(importItem, "client", clientObj);

        if (client->id) {
            cJSON_AddStringToObject(clientObj, "id", client->id);
        }
        if (client->security) {
            cJSON_AddStringToObject(clientObj, "security", client->security);
        }
        if (client->password) {
            cJSON_AddStringToObject(clientObj, "password", client->password);
        }
        if (client->auth) {
            cJSON_AddStringToObject(clientObj, "auth", client->auth);
        }
        if (client->email) {
            cJSON_AddStringToObject(clientObj, "email", client->email);
        }
        cJSON_AddNumberToObject(clientObj, "limitIp", client->limitIp);
        cJSON_AddNumberToObject(clientObj, "totalGB", (double)client->totalGB);
        cJSON_AddNumberToObject(clientObj, "expiryTime", (double)client->expiryTime);
        cJSON_AddBoolToObject(clientObj, "enable", client->enable);
        cJSON_AddNumberToObject(clientObj, "tgId", (double)client->tgId);
        if (client->subId) {
            cJSON_AddStringToObject(clientObj, "subId", client->subId);
        }
        if (client->group) {
            cJSON_AddStringToObject(clientObj, "group", client->group);
        }
        if (client->comment) {
            cJSON_AddStringToObject(clientObj, "comment", client->comment);
        }
        cJSON_AddNumberToObject(clientObj, "reset", client->reset);
        cJSON_AddNumberToObject(clientObj, "resetDay", client->resetDay);
        cJSON_AddNumberToObject(clientObj, "resetMax", client->resetMax);
        if (client->trafficReset) {
            cJSON_AddStringToObject(clientObj, "trafficReset", client->trafficReset);
        }
        cJSON_AddNumberToObject(clientObj, "trafficResetDay", client->trafficResetDay);
        cJSON_AddNumberToObject(clientObj, "created_at", (double)client->createdAt);
        cJSON_AddNumberToObject(clientObj, "updated_at", (double)client->updatedAt);
        cJSON_AddNumberToObject(clientObj, "limitHwid", client->limitHwid);

        if (client->trafficObjPStruct) {
            cJSON* trafficObj = cJSON_CreateObject();
            if (!trafficObj) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "trafficObj is a null pointer, failed to create json object");

                cJSON_Delete(importArray);

                return NULL;

            }
            cJSON_AddItemToObject(importItem, "traffic", trafficObj);

            cJSON_AddNumberToObject(trafficObj, "up", (double)client->trafficObjPStruct->up);
            cJSON_AddNumberToObject(trafficObj, "down", (double)client->trafficObjPStruct->down);
            cJSON_AddNumberToObject(trafficObj, "resetCount", client->trafficObjPStruct->resetCount);
            cJSON_AddNumberToObject(trafficObj, "lastOnline", (double)client->trafficObjPStruct->lastOnline);

        }

        cJSON* inboundIdsArray = cJSON_CreateArray();
        if (!inboundIdsArray) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create inboundIds array");

            cJSON_Delete(importArray);

            return NULL;

        }
        cJSON_AddItemToObject(importItem, "inboundIds", inboundIdsArray);

        for (int64_t j = 0; j < client->inboundIdsCount; j++) {
            cJSON_AddItemToArray(inboundIdsArray, cJSON_CreateNumber(client->inboundIds[j]));
        }

    }

    char* importString = cJSON_PrintUnformatted(importArray);
    cJSON_Delete(importArray);

    if (!importString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print import array");

        return NULL;

    }

    cJSON* dataObj = cJSON_CreateObject();
    if (!dataObj) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "dataObj is a null pointer, failed to create json object");

        free(importString);

        return NULL;

    }
    cJSON_AddStringToObject(dataObj, "data", importString);
    free(importString);

    char* jsonString = cJSON_PrintUnformatted(dataObj);
    cJSON_Delete(dataObj);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");

        return NULL;

    }

    return jsonString;

}

void jsonImportClientsObjectSkippedArrayResponseStructDelete(struct jsonImportClientsObjectSkippedArrayResponseStruct* importClisObjSkippedArrRStruct, size_t arraySize) {
    if (!importClisObjSkippedArrRStruct) {
        return;
    }

    for (size_t i = 0; i < arraySize; i++) {
        free((char*)importClisObjSkippedArrRStruct[i].email);
        free((char*)importClisObjSkippedArrRStruct[i].reason);
    }

    free(importClisObjSkippedArrRStruct);
}

void jsonImportClientsObjectResponseStructDelete(struct jsonImportClientsObjectResponseStruct* importClisObjRStruct) {
    if (!importClisObjRStruct) {
        return;
    }

    if (importClisObjRStruct->importClisObjSkippedArrRStruct) {
        jsonImportClientsObjectSkippedArrayResponseStructDelete(importClisObjRStruct->importClisObjSkippedArrRStruct, importClisObjRStruct->jsonImportClientsObjectSkippedArrayResponseStructSize);
        importClisObjRStruct->importClisObjSkippedArrRStruct = NULL;
    }

    free(importClisObjRStruct);
}

void jsonImportClientsResponseStructDelete(struct jsonImportClientsResponseStruct* importCliRStruct) {
    if (!importCliRStruct) {
        return;
    }

    free((char*)importCliRStruct->msg);

    if (importCliRStruct->importClisObjRStruct) {
        jsonImportClientsObjectResponseStructDelete(importCliRStruct->importClisObjRStruct);
        importCliRStruct->importClisObjRStruct = NULL;
    }

    free(importCliRStruct);
}

static int jsonImportClientsObjectSkippedArrayResponseStructParse(cJSON* skippedObj, struct jsonImportClientsObjectSkippedArrayResponseStruct* skippedStruct) {
    if (!skippedObj) {
        return 0;
    }

    if (cJSON_HasObjectItem(skippedObj, "email") && cJSON_IsString(cJSON_GetObjectItem(skippedObj, "email"))) {
        size_t emailLen = strlen(cJSON_GetObjectItem(skippedObj, "email")->valuestring);
        char* emailCopy = (char*)malloc((emailLen + 1) * sizeof(char));
        if (!emailCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "email is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(emailCopy, cJSON_GetObjectItem(skippedObj, "email")->valuestring, emailLen);
        emailCopy[emailLen] = '\0';
        skippedStruct->email = emailCopy;
    }

    if (cJSON_HasObjectItem(skippedObj, "reason") && cJSON_IsString(cJSON_GetObjectItem(skippedObj, "reason"))) {
        size_t reasonLen = strlen(cJSON_GetObjectItem(skippedObj, "reason")->valuestring);
        char* reasonCopy = (char*)malloc((reasonLen + 1) * sizeof(char));
        if (!reasonCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "reason is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(reasonCopy, cJSON_GetObjectItem(skippedObj, "reason")->valuestring, reasonLen);
        reasonCopy[reasonLen] = '\0';
        skippedStruct->reason = reasonCopy;
    }

    return 1;
}

struct jsonImportClientsResponseStruct* jsonImportClientsResponse(const char* json) {
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
        if (!obj) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "obj is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        struct jsonImportClientsObjectResponseStruct* importClisObjRStruct = (struct jsonImportClientsObjectResponseStruct*)calloc(1, sizeof(struct jsonImportClientsObjectResponseStruct));
        if (!importClisObjRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "importClisObjRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        if (cJSON_HasObjectItem(obj, "created") && cJSON_IsNumber(cJSON_GetObjectItem(obj, "created"))) {
            importClisObjRStruct->created = (int64_t)cJSON_GetObjectItem(obj, "created")->valuedouble;
        }

        // Parse skipped array
        if (cJSON_HasObjectItem(obj, "skipped") && cJSON_IsArray(cJSON_GetObjectItem(obj, "skipped"))) {
            cJSON* skippedArr = cJSON_GetObjectItem(obj, "skipped");
            size_t skippedArraySize = cJSON_GetArraySize(skippedArr);
            if (skippedArraySize) {
                importClisObjRStruct->importClisObjSkippedArrRStruct = (struct jsonImportClientsObjectSkippedArrayResponseStruct*)calloc(skippedArraySize, sizeof(struct jsonImportClientsObjectSkippedArrayResponseStruct));
                if (!importClisObjRStruct->importClisObjSkippedArrRStruct) {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "importClisObjSkippedArrRStruct is a null pointer");
                    free(importClisObjRStruct);
                    cJSON_Delete(jsonParser);
                    return NULL;
                }
                importClisObjRStruct->jsonImportClientsObjectSkippedArrayResponseStructSize = skippedArraySize;
                for (size_t i = 0; i < skippedArraySize; i++) {
                    cJSON* skippedItem = cJSON_GetArrayItem(skippedArr, i);
                    if (jsonImportClientsObjectSkippedArrayResponseStructParse(skippedItem, &importClisObjRStruct->importClisObjSkippedArrRStruct[i]) == 0) {
                        applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Some item is not present in the skipped array element, skipping...");
                    }
                }
            }
        }

        struct jsonImportClientsResponseStruct* importCliRStruct = (struct jsonImportClientsResponseStruct*)malloc(sizeof(struct jsonImportClientsResponseStruct));
        if (!importCliRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "importCliRStruct is a null pointer");
            free(importClisObjRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        importCliRStruct->success = 1;

        if (cJSON_HasObjectItem(jsonParser, "msg") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "msg"))) {
            char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
            size_t msgLen = strlen(msg);
            char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
            if (!msgCopy) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "msgCopy is a null pointer");
                free(importCliRStruct);
                free(importClisObjRStruct);
                cJSON_Delete(jsonParser);
                return NULL;
            }
            strncpy(msgCopy, msg, msgLen);
            msgCopy[msgLen] = '\0';
            importCliRStruct->msg = msgCopy;
        } else {
            importCliRStruct->msg = NULL;
        }

        importCliRStruct->importClisObjRStruct = importClisObjRStruct;

        cJSON_Delete(jsonParser);
        return importCliRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonImportClientsResponseStruct* failRStruct = (struct jsonImportClientsResponseStruct*)calloc(1, sizeof(struct jsonImportClientsResponseStruct));
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

static int jsonBulkSkippedItemParse(cJSON* skippedItem, const char** email, const char** reason) {
    if (!skippedItem) {
        return 0;
    }

    if (cJSON_HasObjectItem(skippedItem, "email") && cJSON_IsString(cJSON_GetObjectItem(skippedItem, "email"))) {
        size_t emailLen = strlen(cJSON_GetObjectItem(skippedItem, "email")->valuestring);
        char* emailCopy = (char*)malloc((emailLen + 1) * sizeof(char));
        if (!emailCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "email is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(emailCopy, cJSON_GetObjectItem(skippedItem, "email")->valuestring, emailLen);
        emailCopy[emailLen] = '\0';
        *email = emailCopy;
    }

    if (cJSON_HasObjectItem(skippedItem, "reason") && cJSON_IsString(cJSON_GetObjectItem(skippedItem, "reason"))) {
        size_t reasonLen = strlen(cJSON_GetObjectItem(skippedItem, "reason")->valuestring);
        char* reasonCopy = (char*)malloc((reasonLen + 1) * sizeof(char));
        if (!reasonCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "reason is a null pointer, failed to allocate memory");
            return 0;
        }
        strncpy(reasonCopy, cJSON_GetObjectItem(skippedItem, "reason")->valuestring, reasonLen);
        reasonCopy[reasonLen] = '\0';
        *reason = reasonCopy;
    }

    return 1;
}

void jsonBulkAdjustClientsObjectSkippedArrayResponseStructDelete(struct jsonBulkAdjustClientsObjectSkippedArrayResponseStruct* bulkAdjClisObjSkippedArrRStruct, size_t arraySize) {
    if (!bulkAdjClisObjSkippedArrRStruct) {
        return;
    }

    for (size_t i = 0; i < arraySize; i++) {
        free((char*)bulkAdjClisObjSkippedArrRStruct[i].email);
        free((char*)bulkAdjClisObjSkippedArrRStruct[i].reason);
    }

    free(bulkAdjClisObjSkippedArrRStruct);
}

void jsonBulkAdjustClientsObjectResponseStructDelete(struct jsonBulkAdjustClientsObjectResponseStruct* bulkAdjClisObjRStruct) {
    if (!bulkAdjClisObjRStruct) {
        return;
    }

    if (bulkAdjClisObjRStruct->bulkAdjClisObjSkippedArrRStruct) {
        jsonBulkAdjustClientsObjectSkippedArrayResponseStructDelete(bulkAdjClisObjRStruct->bulkAdjClisObjSkippedArrRStruct, bulkAdjClisObjRStruct->jsonBulkAdjustClientsObjectSkippedArrayResponseStructSize);
        bulkAdjClisObjRStruct->bulkAdjClisObjSkippedArrRStruct = NULL;

    }

    free(bulkAdjClisObjRStruct);

}

void jsonBulkAdjustClientsResponseStructDelete(struct jsonBulkAdjustClientsResponseStruct* bulkAdjustCliRStruct) {
    if (!bulkAdjustCliRStruct) {
        return;
    }

    free((char*)bulkAdjustCliRStruct->msg);

    if (bulkAdjustCliRStruct->bulkAdjClisObjRStruct) {
        jsonBulkAdjustClientsObjectResponseStructDelete(bulkAdjustCliRStruct->bulkAdjClisObjRStruct);
        bulkAdjustCliRStruct->bulkAdjClisObjRStruct = NULL;

    }

    free(bulkAdjustCliRStruct);

}

struct jsonBulkAdjustClientsResponseStruct* jsonBulkAdjustClientsResponse(const char* json) {
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

        struct jsonBulkAdjustClientsObjectResponseStruct* bulkAdjClisObjRStruct = (struct jsonBulkAdjustClientsObjectResponseStruct*)calloc(1, sizeof(struct jsonBulkAdjustClientsObjectResponseStruct));
        if (!bulkAdjClisObjRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkAdjClisObjRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (cJSON_HasObjectItem(obj, "adjusted") && cJSON_IsNumber(cJSON_GetObjectItem(obj, "adjusted"))) {
            bulkAdjClisObjRStruct->adjusted = (int64_t)cJSON_GetObjectItem(obj, "adjusted")->valuedouble;

        }

        if (cJSON_HasObjectItem(obj, "skipped") && cJSON_IsArray(cJSON_GetObjectItem(obj, "skipped"))) {
            cJSON* skippedArr = cJSON_GetObjectItem(obj, "skipped");
            size_t skippedArraySize = cJSON_GetArraySize(skippedArr);
            if (skippedArraySize) {
                bulkAdjClisObjRStruct->bulkAdjClisObjSkippedArrRStruct = (struct jsonBulkAdjustClientsObjectSkippedArrayResponseStruct*)calloc(skippedArraySize, sizeof(struct jsonBulkAdjustClientsObjectSkippedArrayResponseStruct));
                if (!bulkAdjClisObjRStruct->bulkAdjClisObjSkippedArrRStruct) {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkAdjClisObjSkippedArrRStruct is a null pointer");

                    free(bulkAdjClisObjRStruct);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }
                bulkAdjClisObjRStruct->jsonBulkAdjustClientsObjectSkippedArrayResponseStructSize = skippedArraySize;
                for (size_t i = 0; i < skippedArraySize; i++) {
                    cJSON* skippedItem = cJSON_GetArrayItem(skippedArr, i);
                    if (jsonBulkSkippedItemParse(skippedItem, &bulkAdjClisObjRStruct->bulkAdjClisObjSkippedArrRStruct[i].email, &bulkAdjClisObjRStruct->bulkAdjClisObjSkippedArrRStruct[i].reason) == 0) {
                        applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Some item is not present in the skipped array element, skipping...");

                    }

                }

            }

        }

        struct jsonBulkAdjustClientsResponseStruct* bulkAdjustCliRStruct = (struct jsonBulkAdjustClientsResponseStruct*)malloc(sizeof(struct jsonBulkAdjustClientsResponseStruct));
        if (!bulkAdjustCliRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkAdjustCliRStruct is a null pointer");

            jsonBulkAdjustClientsObjectResponseStructDelete(bulkAdjClisObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        bulkAdjustCliRStruct->success = 1;

        if (cJSON_HasObjectItem(jsonParser, "msg") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "msg"))) {
            char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
            size_t msgLen = strlen(msg);
            char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
            if (!msgCopy) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "msgCopy is a null pointer");

                free(bulkAdjustCliRStruct);

                jsonBulkAdjustClientsObjectResponseStructDelete(bulkAdjClisObjRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }
            strncpy(msgCopy, msg, msgLen);
            msgCopy[msgLen] = '\0';
            bulkAdjustCliRStruct->msg = msgCopy;

        } else {
            bulkAdjustCliRStruct->msg = NULL;

        }

        bulkAdjustCliRStruct->bulkAdjClisObjRStruct = bulkAdjClisObjRStruct;

        cJSON_Delete(jsonParser);

        return bulkAdjustCliRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonBulkAdjustClientsResponseStruct* failRStruct = (struct jsonBulkAdjustClientsResponseStruct*)calloc(1, sizeof(struct jsonBulkAdjustClientsResponseStruct));
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

void jsonBulkEnableClientsObjectSkippedArrayResponseStructDelete(struct jsonBulkEnableClientsObjectSkippedArrayResponseStruct* bulkEnableClisObjSkippedArrRStruct, size_t arraySize) {
    if (!bulkEnableClisObjSkippedArrRStruct) {
        return;
    }

    for (size_t i = 0; i < arraySize; i++) {
        free((char*)bulkEnableClisObjSkippedArrRStruct[i].email);
        free((char*)bulkEnableClisObjSkippedArrRStruct[i].reason);
    }

    free(bulkEnableClisObjSkippedArrRStruct);

}

void jsonBulkEnableClientsObjectResponseStructDelete(struct jsonBulkEnableClientsObjectResponseStruct* bulkEnableClisObjRStruct) {
    if (!bulkEnableClisObjRStruct) {
        return;
    }

    if (bulkEnableClisObjRStruct->bulkEnableClisObjSkippedArrRStruct) {
        jsonBulkEnableClientsObjectSkippedArrayResponseStructDelete(bulkEnableClisObjRStruct->bulkEnableClisObjSkippedArrRStruct, bulkEnableClisObjRStruct->jsonBulkEnableClientsObjectSkippedArrayResponseStructSize);
        bulkEnableClisObjRStruct->bulkEnableClisObjSkippedArrRStruct = NULL;

    }

    free(bulkEnableClisObjRStruct);

}

void jsonBulkEnableClientsResponseStructDelete(struct jsonBulkEnableClientsResponseStruct* bulkEnableCliRStruct) {
    if (!bulkEnableCliRStruct) {
        return;
    }

    free((char*)bulkEnableCliRStruct->msg);

    if (bulkEnableCliRStruct->bulkEnableClisObjRStruct) {
        jsonBulkEnableClientsObjectResponseStructDelete(bulkEnableCliRStruct->bulkEnableClisObjRStruct);
        bulkEnableCliRStruct->bulkEnableClisObjRStruct = NULL;

    }

    free(bulkEnableCliRStruct);

}

struct jsonBulkEnableClientsResponseStruct* jsonBulkEnableClientsResponse(const char* json) {
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

        struct jsonBulkEnableClientsObjectResponseStruct* bulkEnableClisObjRStruct = (struct jsonBulkEnableClientsObjectResponseStruct*)calloc(1, sizeof(struct jsonBulkEnableClientsObjectResponseStruct));
        if (!bulkEnableClisObjRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkEnableClisObjRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (cJSON_HasObjectItem(obj, "changed") && cJSON_IsNumber(cJSON_GetObjectItem(obj, "changed"))) {
            bulkEnableClisObjRStruct->changed = (int64_t)cJSON_GetObjectItem(obj, "changed")->valuedouble;

        }

        if (cJSON_HasObjectItem(obj, "skipped") && cJSON_IsArray(cJSON_GetObjectItem(obj, "skipped"))) {
            cJSON* skippedArr = cJSON_GetObjectItem(obj, "skipped");
            size_t skippedArraySize = cJSON_GetArraySize(skippedArr);
            if (skippedArraySize) {
                bulkEnableClisObjRStruct->bulkEnableClisObjSkippedArrRStruct = (struct jsonBulkEnableClientsObjectSkippedArrayResponseStruct*)calloc(skippedArraySize, sizeof(struct jsonBulkEnableClientsObjectSkippedArrayResponseStruct));
                if (!bulkEnableClisObjRStruct->bulkEnableClisObjSkippedArrRStruct) {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkEnableClisObjSkippedArrRStruct is a null pointer");

                    free(bulkEnableClisObjRStruct);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }
                bulkEnableClisObjRStruct->jsonBulkEnableClientsObjectSkippedArrayResponseStructSize = skippedArraySize;
                for (size_t i = 0; i < skippedArraySize; i++) {
                    cJSON* skippedItem = cJSON_GetArrayItem(skippedArr, i);
                    if (jsonBulkSkippedItemParse(skippedItem, &bulkEnableClisObjRStruct->bulkEnableClisObjSkippedArrRStruct[i].email, &bulkEnableClisObjRStruct->bulkEnableClisObjSkippedArrRStruct[i].reason) == 0) {
                        applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Some item is not present in the skipped array element, skipping...");

                    }

                }

            }

        }

        struct jsonBulkEnableClientsResponseStruct* bulkEnableCliRStruct = (struct jsonBulkEnableClientsResponseStruct*)malloc(sizeof(struct jsonBulkEnableClientsResponseStruct));
        if (!bulkEnableCliRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkEnableCliRStruct is a null pointer");

            jsonBulkEnableClientsObjectResponseStructDelete(bulkEnableClisObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        bulkEnableCliRStruct->success = 1;

        if (cJSON_HasObjectItem(jsonParser, "msg") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "msg"))) {
            char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
            size_t msgLen = strlen(msg);
            char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
            if (!msgCopy) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "msgCopy is a null pointer");

                free(bulkEnableCliRStruct);

                jsonBulkEnableClientsObjectResponseStructDelete(bulkEnableClisObjRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }
            strncpy(msgCopy, msg, msgLen);
            msgCopy[msgLen] = '\0';
            bulkEnableCliRStruct->msg = msgCopy;

        } else {
            bulkEnableCliRStruct->msg = NULL;

        }

        bulkEnableCliRStruct->bulkEnableClisObjRStruct = bulkEnableClisObjRStruct;

        cJSON_Delete(jsonParser);

        return bulkEnableCliRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonBulkEnableClientsResponseStruct* failRStruct = (struct jsonBulkEnableClientsResponseStruct*)calloc(1, sizeof(struct jsonBulkEnableClientsResponseStruct));
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

void jsonBulkDisableClientsObjectSkippedArrayResponseStructDelete(struct jsonBulkDisableClientsObjectSkippedArrayResponseStruct* bulkDisableClisObjSkippedArrRStruct, size_t arraySize) {
    if (!bulkDisableClisObjSkippedArrRStruct) {
        return;
    }

    for (size_t i = 0; i < arraySize; i++) {
        free((char*)bulkDisableClisObjSkippedArrRStruct[i].email);
        free((char*)bulkDisableClisObjSkippedArrRStruct[i].reason);
    }

    free(bulkDisableClisObjSkippedArrRStruct);

}

void jsonBulkDisableClientsObjectResponseStructDelete(struct jsonBulkDisableClientsObjectResponseStruct* bulkDisableClisObjRStruct) {
    if (!bulkDisableClisObjRStruct) {
        return;
    }

    if (bulkDisableClisObjRStruct->bulkDisableClisObjSkippedArrRStruct) {
        jsonBulkDisableClientsObjectSkippedArrayResponseStructDelete(bulkDisableClisObjRStruct->bulkDisableClisObjSkippedArrRStruct, bulkDisableClisObjRStruct->jsonBulkDisableClientsObjectSkippedArrayResponseStructSize);
        bulkDisableClisObjRStruct->bulkDisableClisObjSkippedArrRStruct = NULL;

    }

    free(bulkDisableClisObjRStruct);

}

void jsonBulkDisableClientsResponseStructDelete(struct jsonBulkDisableClientsResponseStruct* bulkDisableCliRStruct) {
    if (!bulkDisableCliRStruct) {
        return;
    }

    free((char*)bulkDisableCliRStruct->msg);

    if (bulkDisableCliRStruct->bulkDisableClisObjRStruct) {
        jsonBulkDisableClientsObjectResponseStructDelete(bulkDisableCliRStruct->bulkDisableClisObjRStruct);
        bulkDisableCliRStruct->bulkDisableClisObjRStruct = NULL;

    }

    free(bulkDisableCliRStruct);

}

struct jsonBulkDisableClientsResponseStruct* jsonBulkDisableClientsResponse(const char* json) {
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

        struct jsonBulkDisableClientsObjectResponseStruct* bulkDisableClisObjRStruct = (struct jsonBulkDisableClientsObjectResponseStruct*)calloc(1, sizeof(struct jsonBulkDisableClientsObjectResponseStruct));
        if (!bulkDisableClisObjRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkDisableClisObjRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (cJSON_HasObjectItem(obj, "changed") && cJSON_IsNumber(cJSON_GetObjectItem(obj, "changed"))) {
            bulkDisableClisObjRStruct->changed = (int64_t)cJSON_GetObjectItem(obj, "changed")->valuedouble;

        }

        if (cJSON_HasObjectItem(obj, "skipped") && cJSON_IsArray(cJSON_GetObjectItem(obj, "skipped"))) {
            cJSON* skippedArr = cJSON_GetObjectItem(obj, "skipped");
            size_t skippedArraySize = cJSON_GetArraySize(skippedArr);
            if (skippedArraySize) {
                bulkDisableClisObjRStruct->bulkDisableClisObjSkippedArrRStruct = (struct jsonBulkDisableClientsObjectSkippedArrayResponseStruct*)calloc(skippedArraySize, sizeof(struct jsonBulkDisableClientsObjectSkippedArrayResponseStruct));
                if (!bulkDisableClisObjRStruct->bulkDisableClisObjSkippedArrRStruct) {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkDisableClisObjSkippedArrRStruct is a null pointer");

                    free(bulkDisableClisObjRStruct);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }
                bulkDisableClisObjRStruct->jsonBulkDisableClientsObjectSkippedArrayResponseStructSize = skippedArraySize;
                for (size_t i = 0; i < skippedArraySize; i++) {
                    cJSON* skippedItem = cJSON_GetArrayItem(skippedArr, i);
                    if (jsonBulkSkippedItemParse(skippedItem, &bulkDisableClisObjRStruct->bulkDisableClisObjSkippedArrRStruct[i].email, &bulkDisableClisObjRStruct->bulkDisableClisObjSkippedArrRStruct[i].reason) == 0) {
                        applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Some item is not present in the skipped array element, skipping...");

                    }

                }

            }

        }

        struct jsonBulkDisableClientsResponseStruct* bulkDisableCliRStruct = (struct jsonBulkDisableClientsResponseStruct*)malloc(sizeof(struct jsonBulkDisableClientsResponseStruct));
        if (!bulkDisableCliRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkDisableCliRStruct is a null pointer");

            jsonBulkDisableClientsObjectResponseStructDelete(bulkDisableClisObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        bulkDisableCliRStruct->success = 1;

        if (cJSON_HasObjectItem(jsonParser, "msg") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "msg"))) {
            char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
            size_t msgLen = strlen(msg);
            char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
            if (!msgCopy) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "msgCopy is a null pointer");

                free(bulkDisableCliRStruct);

                jsonBulkDisableClientsObjectResponseStructDelete(bulkDisableClisObjRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }
            strncpy(msgCopy, msg, msgLen);
            msgCopy[msgLen] = '\0';
            bulkDisableCliRStruct->msg = msgCopy;

        } else {
            bulkDisableCliRStruct->msg = NULL;

        }

        bulkDisableCliRStruct->bulkDisableClisObjRStruct = bulkDisableClisObjRStruct;

        cJSON_Delete(jsonParser);

        return bulkDisableCliRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonBulkDisableClientsResponseStruct* failRStruct = (struct jsonBulkDisableClientsResponseStruct*)calloc(1, sizeof(struct jsonBulkDisableClientsResponseStruct));
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

void jsonBulkDeleteClientsObjectSkippedArrayResponseStructDelete(struct jsonBulkDeleteClientsObjectSkippedArrayResponseStruct* bulkDelClisObjSkippedArrRStruct, size_t arraySize) {
    if (!bulkDelClisObjSkippedArrRStruct) {
        return;
    }

    for (size_t i = 0; i < arraySize; i++) {
        free((char*)bulkDelClisObjSkippedArrRStruct[i].email);
        free((char*)bulkDelClisObjSkippedArrRStruct[i].reason);
    }

    free(bulkDelClisObjSkippedArrRStruct);

}

void jsonBulkDeleteClientsObjectResponseStructDelete(struct jsonBulkDeleteClientsObjectResponseStruct* bulkDelClisObjRStruct) {
    if (!bulkDelClisObjRStruct) {
        return;
    }

    if (bulkDelClisObjRStruct->bulkDelClisObjSkippedArrRStruct) {
        jsonBulkDeleteClientsObjectSkippedArrayResponseStructDelete(bulkDelClisObjRStruct->bulkDelClisObjSkippedArrRStruct, bulkDelClisObjRStruct->jsonBulkDeleteClientsObjectSkippedArrayResponseStructSize);
        bulkDelClisObjRStruct->bulkDelClisObjSkippedArrRStruct = NULL;

    }

    free(bulkDelClisObjRStruct);

}

void jsonBulkDeleteClientsResponseStructDelete(struct jsonBulkDeleteClientsResponseStruct* bulkDeleteCliRStruct) {
    if (!bulkDeleteCliRStruct) {
        return;
    }

    free((char*)bulkDeleteCliRStruct->msg);

    if (bulkDeleteCliRStruct->bulkDelClisObjRStruct) {
        jsonBulkDeleteClientsObjectResponseStructDelete(bulkDeleteCliRStruct->bulkDelClisObjRStruct);
        bulkDeleteCliRStruct->bulkDelClisObjRStruct = NULL;

    }

    free(bulkDeleteCliRStruct);

}

struct jsonBulkDeleteClientsResponseStruct* jsonBulkDeleteClientsResponse(const char* json) {
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

        struct jsonBulkDeleteClientsObjectResponseStruct* bulkDelClisObjRStruct = (struct jsonBulkDeleteClientsObjectResponseStruct*)calloc(1, sizeof(struct jsonBulkDeleteClientsObjectResponseStruct));
        if (!bulkDelClisObjRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkDelClisObjRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (cJSON_HasObjectItem(obj, "deleted") && cJSON_IsNumber(cJSON_GetObjectItem(obj, "deleted"))) {
            bulkDelClisObjRStruct->deleted = (int64_t)cJSON_GetObjectItem(obj, "deleted")->valuedouble;

        }

        if (cJSON_HasObjectItem(obj, "skipped") && cJSON_IsArray(cJSON_GetObjectItem(obj, "skipped"))) {
            cJSON* skippedArr = cJSON_GetObjectItem(obj, "skipped");
            size_t skippedArraySize = cJSON_GetArraySize(skippedArr);
            if (skippedArraySize) {
                bulkDelClisObjRStruct->bulkDelClisObjSkippedArrRStruct = (struct jsonBulkDeleteClientsObjectSkippedArrayResponseStruct*)calloc(skippedArraySize, sizeof(struct jsonBulkDeleteClientsObjectSkippedArrayResponseStruct));
                if (!bulkDelClisObjRStruct->bulkDelClisObjSkippedArrRStruct) {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkDelClisObjSkippedArrRStruct is a null pointer");

                    free(bulkDelClisObjRStruct);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }
                bulkDelClisObjRStruct->jsonBulkDeleteClientsObjectSkippedArrayResponseStructSize = skippedArraySize;
                for (size_t i = 0; i < skippedArraySize; i++) {
                    cJSON* skippedItem = cJSON_GetArrayItem(skippedArr, i);
                    if (jsonBulkSkippedItemParse(skippedItem, &bulkDelClisObjRStruct->bulkDelClisObjSkippedArrRStruct[i].email, &bulkDelClisObjRStruct->bulkDelClisObjSkippedArrRStruct[i].reason) == 0) {
                        applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Some item is not present in the skipped array element, skipping...");

                    }

                }

            }

        }

        struct jsonBulkDeleteClientsResponseStruct* bulkDeleteCliRStruct = (struct jsonBulkDeleteClientsResponseStruct*)malloc(sizeof(struct jsonBulkDeleteClientsResponseStruct));
        if (!bulkDeleteCliRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkDeleteCliRStruct is a null pointer");

            jsonBulkDeleteClientsObjectResponseStructDelete(bulkDelClisObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        bulkDeleteCliRStruct->success = 1;

        if (cJSON_HasObjectItem(jsonParser, "msg") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "msg"))) {
            char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
            size_t msgLen = strlen(msg);
            char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
            if (!msgCopy) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "msgCopy is a null pointer");

                free(bulkDeleteCliRStruct);

                jsonBulkDeleteClientsObjectResponseStructDelete(bulkDelClisObjRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }
            strncpy(msgCopy, msg, msgLen);
            msgCopy[msgLen] = '\0';
            bulkDeleteCliRStruct->msg = msgCopy;

        } else {
            bulkDeleteCliRStruct->msg = NULL;

        }

        bulkDeleteCliRStruct->bulkDelClisObjRStruct = bulkDelClisObjRStruct;

        cJSON_Delete(jsonParser);

        return bulkDeleteCliRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonBulkDeleteClientsResponseStruct* failRStruct = (struct jsonBulkDeleteClientsResponseStruct*)calloc(1, sizeof(struct jsonBulkDeleteClientsResponseStruct));
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

void jsonBulkCreateClientsObjectSkippedArrayResponseStructDelete(struct jsonBulkCreateClientsObjectSkippedArrayResponseStruct* bulkCreateClisObjSkippedArrRStruct, size_t arraySize) {
    if (!bulkCreateClisObjSkippedArrRStruct) {
        return;
    }

    for (size_t i = 0; i < arraySize; i++) {
        free((char*)bulkCreateClisObjSkippedArrRStruct[i].email);
        free((char*)bulkCreateClisObjSkippedArrRStruct[i].reason);
    }

    free(bulkCreateClisObjSkippedArrRStruct);

}

void jsonBulkCreateClientsObjectResponseStructDelete(struct jsonBulkCreateClientsObjectResponseStruct* bulkCreateClisObjRStruct) {
    if (!bulkCreateClisObjRStruct) {
        return;
    }

    if (bulkCreateClisObjRStruct->bulkCreateClisObjSkippedArrRStruct) {
        jsonBulkCreateClientsObjectSkippedArrayResponseStructDelete(bulkCreateClisObjRStruct->bulkCreateClisObjSkippedArrRStruct, bulkCreateClisObjRStruct->jsonBulkCreateClientsObjectSkippedArrayResponseStructSize);
        bulkCreateClisObjRStruct->bulkCreateClisObjSkippedArrRStruct = NULL;

    }

    free(bulkCreateClisObjRStruct);

}

void jsonBulkCreateClientsResponseStructDelete(struct jsonBulkCreateClientsResponseStruct* bulkCreateCliRStruct) {
    if (!bulkCreateCliRStruct) {
        return;
    }

    free((char*)bulkCreateCliRStruct->msg);

    if (bulkCreateCliRStruct->bulkCreateClisObjRStruct) {
        jsonBulkCreateClientsObjectResponseStructDelete(bulkCreateCliRStruct->bulkCreateClisObjRStruct);
        bulkCreateCliRStruct->bulkCreateClisObjRStruct = NULL;

    }

    free(bulkCreateCliRStruct);

}

struct jsonBulkCreateClientsResponseStruct* jsonBulkCreateClientsResponse(const char* json) {
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

        struct jsonBulkCreateClientsObjectResponseStruct* bulkCreateClisObjRStruct = (struct jsonBulkCreateClientsObjectResponseStruct*)calloc(1, sizeof(struct jsonBulkCreateClientsObjectResponseStruct));
        if (!bulkCreateClisObjRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkCreateClisObjRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (cJSON_HasObjectItem(obj, "created") && cJSON_IsNumber(cJSON_GetObjectItem(obj, "created"))) {
            bulkCreateClisObjRStruct->created = (int64_t)cJSON_GetObjectItem(obj, "created")->valuedouble;

        }

        if (cJSON_HasObjectItem(obj, "skipped") && cJSON_IsArray(cJSON_GetObjectItem(obj, "skipped"))) {
            cJSON* skippedArr = cJSON_GetObjectItem(obj, "skipped");
            size_t skippedArraySize = cJSON_GetArraySize(skippedArr);
            if (skippedArraySize) {
                bulkCreateClisObjRStruct->bulkCreateClisObjSkippedArrRStruct = (struct jsonBulkCreateClientsObjectSkippedArrayResponseStruct*)calloc(skippedArraySize, sizeof(struct jsonBulkCreateClientsObjectSkippedArrayResponseStruct));
                if (!bulkCreateClisObjRStruct->bulkCreateClisObjSkippedArrRStruct) {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkCreateClisObjSkippedArrRStruct is a null pointer");

                    free(bulkCreateClisObjRStruct);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }
                bulkCreateClisObjRStruct->jsonBulkCreateClientsObjectSkippedArrayResponseStructSize = skippedArraySize;
                for (size_t i = 0; i < skippedArraySize; i++) {
                    cJSON* skippedItem = cJSON_GetArrayItem(skippedArr, i);
                    if (jsonBulkSkippedItemParse(skippedItem, &bulkCreateClisObjRStruct->bulkCreateClisObjSkippedArrRStruct[i].email, &bulkCreateClisObjRStruct->bulkCreateClisObjSkippedArrRStruct[i].reason) == 0) {
                        applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Some item is not present in the skipped array element, skipping...");

                    }

                }

            }

        }

        struct jsonBulkCreateClientsResponseStruct* bulkCreateCliRStruct = (struct jsonBulkCreateClientsResponseStruct*)malloc(sizeof(struct jsonBulkCreateClientsResponseStruct));
        if (!bulkCreateCliRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkCreateCliRStruct is a null pointer");

            jsonBulkCreateClientsObjectResponseStructDelete(bulkCreateClisObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        bulkCreateCliRStruct->success = 1;

        if (cJSON_HasObjectItem(jsonParser, "msg") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "msg"))) {
            char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
            size_t msgLen = strlen(msg);
            char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
            if (!msgCopy) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "msgCopy is a null pointer");

                free(bulkCreateCliRStruct);

                jsonBulkCreateClientsObjectResponseStructDelete(bulkCreateClisObjRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }
            strncpy(msgCopy, msg, msgLen);
            msgCopy[msgLen] = '\0';
            bulkCreateCliRStruct->msg = msgCopy;

        } else {
            bulkCreateCliRStruct->msg = NULL;

        }

        bulkCreateCliRStruct->bulkCreateClisObjRStruct = bulkCreateClisObjRStruct;

        cJSON_Delete(jsonParser);

        return bulkCreateCliRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonBulkCreateClientsResponseStruct* failRStruct = (struct jsonBulkCreateClientsResponseStruct*)calloc(1, sizeof(struct jsonBulkCreateClientsResponseStruct));
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

void jsonBulkRemoveClientsGroupObjectResponseStructDelete(struct jsonBulkRemoveClientsGroupObjectResponseStruct* bulkRmCliGroupObjRStruct) {
    if (!bulkRmCliGroupObjRStruct) {
        return;
    }

    free(bulkRmCliGroupObjRStruct);

}

void jsonBulkRemoveClientsGroupResponseStructDelete(struct jsonBulkRemoveClientsGroupResponseStruct* bulkRmCliGroupRStruct) {
    if (!bulkRmCliGroupRStruct) {
        return;
    }

    free((char*)bulkRmCliGroupRStruct->msg);

    if (bulkRmCliGroupRStruct->bulkRmCliGroupObjRStruct) {
        jsonBulkRemoveClientsGroupObjectResponseStructDelete(bulkRmCliGroupRStruct->bulkRmCliGroupObjRStruct);
        bulkRmCliGroupRStruct->bulkRmCliGroupObjRStruct = NULL;

    }

    free(bulkRmCliGroupRStruct);

}

struct jsonBulkRemoveClientsGroupResponseStruct* jsonBulkRemoveClientsGroupResponse(const char* json) {
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

        struct jsonBulkRemoveClientsGroupObjectResponseStruct* bulkRmCliGroupObjRStruct = (struct jsonBulkRemoveClientsGroupObjectResponseStruct*)calloc(1, sizeof(struct jsonBulkRemoveClientsGroupObjectResponseStruct));
        if (!bulkRmCliGroupObjRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkRmCliGroupObjRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (cJSON_HasObjectItem(obj, "affected") && cJSON_IsNumber(cJSON_GetObjectItem(obj, "affected"))) {
            bulkRmCliGroupObjRStruct->affected = (int64_t)cJSON_GetObjectItem(obj, "affected")->valuedouble;

        }

        struct jsonBulkRemoveClientsGroupResponseStruct* bulkRmCliGroupRStruct = (struct jsonBulkRemoveClientsGroupResponseStruct*)malloc(sizeof(struct jsonBulkRemoveClientsGroupResponseStruct));
        if (!bulkRmCliGroupRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkRmCliGroupRStruct is a null pointer");

            jsonBulkRemoveClientsGroupObjectResponseStructDelete(bulkRmCliGroupObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        bulkRmCliGroupRStruct->success = 1;

        if (cJSON_HasObjectItem(jsonParser, "msg") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "msg"))) {
            char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
            size_t msgLen = strlen(msg);
            char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
            if (!msgCopy) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "msgCopy is a null pointer");

                free(bulkRmCliGroupRStruct);

                jsonBulkRemoveClientsGroupObjectResponseStructDelete(bulkRmCliGroupObjRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }
            strncpy(msgCopy, msg, msgLen);
            msgCopy[msgLen] = '\0';
            bulkRmCliGroupRStruct->msg = msgCopy;

        } else {
            bulkRmCliGroupRStruct->msg = NULL;

        }

        bulkRmCliGroupRStruct->bulkRmCliGroupObjRStruct = bulkRmCliGroupObjRStruct;

        cJSON_Delete(jsonParser);

        return bulkRmCliGroupRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonBulkRemoveClientsGroupResponseStruct* failRStruct = (struct jsonBulkRemoveClientsGroupResponseStruct*)calloc(1, sizeof(struct jsonBulkRemoveClientsGroupResponseStruct));
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

void jsonBulkCreateClientsMainObjectPostStructDelete(struct jsonBulkCreateClientsMainObjectPostStruct* bulkCreateClisMainObjPStruct, size_t arraySize) {
    if (!bulkCreateClisMainObjPStruct) {
        return;
    }

    for (size_t i = 0; i < arraySize; i++) {
        free((char*)bulkCreateClisMainObjPStruct[i].email);
        free(bulkCreateClisMainObjPStruct[i].inboundIds);
    }

    free(bulkCreateClisMainObjPStruct);

}

void jsonBulkCreateClientsPostStructDelete(struct jsonBulkCreateClientsPostStruct* bulkCreateClientsPostStruct) {
    if (!bulkCreateClientsPostStruct) {
        return;
    }

    if (bulkCreateClientsPostStruct->bulkCreateClisMainObjPStruct) {
        jsonBulkCreateClientsMainObjectPostStructDelete(bulkCreateClientsPostStruct->bulkCreateClisMainObjPStruct, bulkCreateClientsPostStruct->jsonBulkCreateClientsMainObjectPostStructSize);
        bulkCreateClientsPostStruct->bulkCreateClisMainObjPStruct = NULL;

    }

    free(bulkCreateClientsPostStruct);

}

const char* jsonBulkCreateClientsPost(struct jsonBulkCreateClientsPostStruct* bulkCreateClientsPostStruct) {
    if (!bulkCreateClientsPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkCreateClientsPostStruct is a null pointer");

        return NULL;

    }

    cJSON* postArray = cJSON_CreateArray();
    if (!postArray) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json array");

        return NULL;

    }

    for (size_t i = 0; i < bulkCreateClientsPostStruct->jsonBulkCreateClientsMainObjectPostStructSize; i++) {
        struct jsonBulkCreateClientsMainObjectPostStruct* mainObj = &bulkCreateClientsPostStruct->bulkCreateClisMainObjPStruct[i];

        cJSON* mainItem = cJSON_CreateObject();
        if (!mainItem) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "mainItem is a null pointer, failed to create json object");

            cJSON_Delete(postArray);

            return NULL;

        }
        cJSON_AddItemToArray(postArray, mainItem);

        cJSON* clientObj = cJSON_CreateObject();
        if (!clientObj) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "clientObj is a null pointer, failed to create json object");

            cJSON_Delete(postArray);

            return NULL;

        }
        cJSON_AddItemToObject(mainItem, "client", clientObj);

        if (mainObj->email) {
            cJSON_AddStringToObject(clientObj, "email", mainObj->email);
        }
        cJSON_AddNumberToObject(clientObj, "totalGB", (double)mainObj->totalGB);
        cJSON_AddNumberToObject(clientObj, "expiryTime", (double)mainObj->expiryTime);
        cJSON_AddNumberToObject(clientObj, "limitHwid", mainObj->limitHwid);
        cJSON_AddBoolToObject(clientObj, "enable", mainObj->enable);

        cJSON* inboundIdsArray = cJSON_CreateArray();
        if (!inboundIdsArray) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create inboundIds array");

            cJSON_Delete(postArray);

            return NULL;

        }
        cJSON_AddItemToObject(mainItem, "inboundIds", inboundIdsArray);

        for (int64_t j = 0; j < mainObj->inboundIdsCount; j++) {
            cJSON_AddItemToArray(inboundIdsArray, cJSON_CreateNumber(mainObj->inboundIds[j]));
        }

    }

    char* jsonString = cJSON_PrintUnformatted(postArray);
    cJSON_Delete(postArray);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");

        return NULL;

    }

    return jsonString;

}

static cJSON* jsonBulkEmailsArrayCreate(const char** emails, int64_t emailsCount) {
    cJSON* emailsArray = cJSON_CreateArray();
    if (!emailsArray) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create emails array");

        return NULL;

    }

    for (int64_t i = 0; emails && i < emailsCount; i++) {
        if (emails[i]) {
            cJSON_AddItemToArray(emailsArray, cJSON_CreateString(emails[i]));
        }

    }

    return emailsArray;

}

static int jsonBulkStringArrayParse(cJSON* arr, const char*** strArr, int64_t* strCount) {
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

static void jsonBulkStringArrayFree(const char** strArr, int64_t strCount) {
    if (!strArr) {
        return;

    }

    for (int64_t i = 0; i < strCount; i++) {
        free((char*)strArr[i]);

    }

    free((char**)strArr);

}

void jsonBulkAdjustClientsPostStructDelete(struct jsonBulkAdjustClientsPostStruct* bulkAdjustClientsPostStruct) {
    if (!bulkAdjustClientsPostStruct) {
        return;

    }

    jsonBulkStringArrayFree(bulkAdjustClientsPostStruct->emails, bulkAdjustClientsPostStruct->emailsCount);
    free((char*)bulkAdjustClientsPostStruct->flow);
    free((char*)bulkAdjustClientsPostStruct->adTag);

    free(bulkAdjustClientsPostStruct);

}

const char* jsonBulkAdjustClientsPost(struct jsonBulkAdjustClientsPostStruct* bulkAdjustClientsPostStruct) {
    if (!bulkAdjustClientsPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkAdjustClientsPostStruct is a null pointer");

        return NULL;

    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");

        return NULL;

    }

    cJSON* emailsArray = jsonBulkEmailsArrayCreate(bulkAdjustClientsPostStruct->emails, bulkAdjustClientsPostStruct->emailsCount);
    if (!emailsArray) {
        cJSON_Delete(json);

        return NULL;

    }
    cJSON_AddItemToObject(json, "emails", emailsArray);

    cJSON_AddNumberToObject(json, "addDays", bulkAdjustClientsPostStruct->addDays);
    cJSON_AddNumberToObject(json, "addBytes", (double)bulkAdjustClientsPostStruct->addBytes);

    if (bulkAdjustClientsPostStruct->flow && bulkAdjustClientsPostStruct->flow[0] != '\0') {
        cJSON_AddStringToObject(json, "flow", bulkAdjustClientsPostStruct->flow);

    }

    cJSON_AddNumberToObject(json, "limitHwid", bulkAdjustClientsPostStruct->limitHwid);

    if (bulkAdjustClientsPostStruct->adTag && bulkAdjustClientsPostStruct->adTag[0] != '\0') {
        cJSON_AddStringToObject(json, "adTag", bulkAdjustClientsPostStruct->adTag);

    }

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");

        return NULL;

    }

    return jsonString;

}

void jsonBulkEnableClientsPostStructDelete(struct jsonBulkEnableClientsPostStruct* bulkEnableClientsPostStruct) {
    if (!bulkEnableClientsPostStruct) {
        return;

    }

    jsonBulkStringArrayFree(bulkEnableClientsPostStruct->emails, bulkEnableClientsPostStruct->emailsCount);

    free(bulkEnableClientsPostStruct);

}

const char* jsonBulkEnableClientsPost(struct jsonBulkEnableClientsPostStruct* bulkEnableClientsPostStruct) {
    if (!bulkEnableClientsPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkEnableClientsPostStruct is a null pointer");

        return NULL;

    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");

        return NULL;

    }

    cJSON* emailsArray = jsonBulkEmailsArrayCreate(bulkEnableClientsPostStruct->emails, bulkEnableClientsPostStruct->emailsCount);
    if (!emailsArray) {
        cJSON_Delete(json);

        return NULL;

    }
    cJSON_AddItemToObject(json, "emails", emailsArray);

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");

        return NULL;

    }

    return jsonString;

}

void jsonBulkDisableClientsPostStructDelete(struct jsonBulkDisableClientsPostStruct* bulkDisableClientsPostStruct) {
    if (!bulkDisableClientsPostStruct) {
        return;

    }

    jsonBulkStringArrayFree(bulkDisableClientsPostStruct->emails, bulkDisableClientsPostStruct->emailsCount);

    free(bulkDisableClientsPostStruct);

}

const char* jsonBulkDisableClientsPost(struct jsonBulkDisableClientsPostStruct* bulkDisableClientsPostStruct) {
    if (!bulkDisableClientsPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkDisableClientsPostStruct is a null pointer");

        return NULL;

    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");

        return NULL;

    }

    cJSON* emailsArray = jsonBulkEmailsArrayCreate(bulkDisableClientsPostStruct->emails, bulkDisableClientsPostStruct->emailsCount);
    if (!emailsArray) {
        cJSON_Delete(json);

        return NULL;

    }
    cJSON_AddItemToObject(json, "emails", emailsArray);

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");

        return NULL;

    }

    return jsonString;

}

void jsonBulkDeleteClientsPostStructDelete(struct jsonBulkDeleteClientsPostStruct* bulkDeleteClientsPostStruct) {
    if (!bulkDeleteClientsPostStruct) {
        return;

    }

    jsonBulkStringArrayFree(bulkDeleteClientsPostStruct->emails, bulkDeleteClientsPostStruct->emailsCount);

    free(bulkDeleteClientsPostStruct);

}

const char* jsonBulkDeleteClientsPost(struct jsonBulkDeleteClientsPostStruct* bulkDeleteClientsPostStruct) {
    if (!bulkDeleteClientsPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkDeleteClientsPostStruct is a null pointer");

        return NULL;

    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");

        return NULL;

    }

    cJSON* emailsArray = jsonBulkEmailsArrayCreate(bulkDeleteClientsPostStruct->emails, bulkDeleteClientsPostStruct->emailsCount);
    if (!emailsArray) {
        cJSON_Delete(json);

        return NULL;

    }
    cJSON_AddItemToObject(json, "emails", emailsArray);

    cJSON_AddBoolToObject(json, "keepTraffic", bulkDeleteClientsPostStruct->keepTraffic);

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");

        return NULL;

    }

    return jsonString;

}

void jsonBulkRemoveClientsGroupPostStructDelete(struct jsonBulkRemoveClientsGroupPostStruct* bulkRemoveClientsGroupPostStruct) {
    if (!bulkRemoveClientsGroupPostStruct) {
        return;

    }

    jsonBulkStringArrayFree(bulkRemoveClientsGroupPostStruct->emails, bulkRemoveClientsGroupPostStruct->emailsCount);

    free(bulkRemoveClientsGroupPostStruct);

}

const char* jsonBulkRemoveClientsGroupPost(struct jsonBulkRemoveClientsGroupPostStruct* bulkRemoveClientsGroupPostStruct) {
    if (!bulkRemoveClientsGroupPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkRemoveClientsGroupPostStruct is a null pointer");

        return NULL;

    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");

        return NULL;

    }

    cJSON* emailsArray = jsonBulkEmailsArrayCreate(bulkRemoveClientsGroupPostStruct->emails, bulkRemoveClientsGroupPostStruct->emailsCount);
    if (!emailsArray) {
        cJSON_Delete(json);

        return NULL;

    }
    cJSON_AddItemToObject(json, "emails", emailsArray);

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");

        return NULL;

    }

    return jsonString;

}

void jsonBulkAttachClientsPostStructDelete(struct jsonBulkAttachClientsPostStruct* bulkAttachClientsPostStruct) {
    if (!bulkAttachClientsPostStruct) {
        return;

    }

    jsonBulkStringArrayFree(bulkAttachClientsPostStruct->emails, bulkAttachClientsPostStruct->emailsCount);
    free(bulkAttachClientsPostStruct->inboundIds);

    free(bulkAttachClientsPostStruct);

}

const char* jsonBulkAttachClientsPost(struct jsonBulkAttachClientsPostStruct* bulkAttachClientsPostStruct) {
    if (!bulkAttachClientsPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkAttachClientsPostStruct is a null pointer");

        return NULL;

    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");

        return NULL;

    }

    cJSON* emailsArray = jsonBulkEmailsArrayCreate(bulkAttachClientsPostStruct->emails, bulkAttachClientsPostStruct->emailsCount);
    if (!emailsArray) {
        cJSON_Delete(json);

        return NULL;

    }
    cJSON_AddItemToObject(json, "emails", emailsArray);

    cJSON* inboundIdsArray = cJSON_CreateArray();
    if (!inboundIdsArray) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create inboundIds array");

        cJSON_Delete(json);

        return NULL;

    }
    cJSON_AddItemToObject(json, "inboundIds", inboundIdsArray);

    for (int64_t i = 0; i < bulkAttachClientsPostStruct->inboundIdsCount; i++) {
        cJSON_AddItemToArray(inboundIdsArray, cJSON_CreateNumber(bulkAttachClientsPostStruct->inboundIds[i]));
    }

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");

        return NULL;

    }

    return jsonString;

}

void jsonBulkAttachClientsObjectResponseStructDelete(struct jsonBulkAttachClientsObjectResponseStruct* bulkAttachClisObjRStruct) {
    if (!bulkAttachClisObjRStruct) {
        return;

    }

    jsonBulkStringArrayFree(bulkAttachClisObjRStruct->attached, bulkAttachClisObjRStruct->attachedCount);
    jsonBulkStringArrayFree(bulkAttachClisObjRStruct->skipped, bulkAttachClisObjRStruct->skippedCount);
    jsonBulkStringArrayFree(bulkAttachClisObjRStruct->errors, bulkAttachClisObjRStruct->errorsCount);

    free(bulkAttachClisObjRStruct);

}

void jsonBulkAttachClientsResponseStructDelete(struct jsonBulkAttachClientsResponseStruct* bulkAttachCliRStruct) {
    if (!bulkAttachCliRStruct) {
        return;

    }

    free((char*)bulkAttachCliRStruct->msg);

    if (bulkAttachCliRStruct->bulkAttachClisObjRStruct) {
        jsonBulkAttachClientsObjectResponseStructDelete(bulkAttachCliRStruct->bulkAttachClisObjRStruct);
        bulkAttachCliRStruct->bulkAttachClisObjRStruct = NULL;

    }

    free(bulkAttachCliRStruct);

}

struct jsonBulkAttachClientsResponseStruct* jsonBulkAttachClientsResponse(const char* json) {
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

        struct jsonBulkAttachClientsObjectResponseStruct* bulkAttachClisObjRStruct = (struct jsonBulkAttachClientsObjectResponseStruct*)calloc(1, sizeof(struct jsonBulkAttachClientsObjectResponseStruct));
        if (!bulkAttachClisObjRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkAttachClisObjRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (cJSON_HasObjectItem(obj, "attached") && cJSON_IsArray(cJSON_GetObjectItem(obj, "attached"))) {
            if (!jsonBulkStringArrayParse(cJSON_GetObjectItem(obj, "attached"), &bulkAttachClisObjRStruct->attached, &bulkAttachClisObjRStruct->attachedCount)) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to parse attached array");

                jsonBulkAttachClientsObjectResponseStructDelete(bulkAttachClisObjRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }

        }

        if (cJSON_HasObjectItem(obj, "skipped") && cJSON_IsArray(cJSON_GetObjectItem(obj, "skipped"))) {
            if (!jsonBulkStringArrayParse(cJSON_GetObjectItem(obj, "skipped"), &bulkAttachClisObjRStruct->skipped, &bulkAttachClisObjRStruct->skippedCount)) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to parse skipped array");

                jsonBulkAttachClientsObjectResponseStructDelete(bulkAttachClisObjRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }

        }

        if (cJSON_HasObjectItem(obj, "errors") && cJSON_IsArray(cJSON_GetObjectItem(obj, "errors"))) {
            if (!jsonBulkStringArrayParse(cJSON_GetObjectItem(obj, "errors"), &bulkAttachClisObjRStruct->errors, &bulkAttachClisObjRStruct->errorsCount)) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to parse errors array");

                jsonBulkAttachClientsObjectResponseStructDelete(bulkAttachClisObjRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }

        }

        struct jsonBulkAttachClientsResponseStruct* bulkAttachCliRStruct = (struct jsonBulkAttachClientsResponseStruct*)malloc(sizeof(struct jsonBulkAttachClientsResponseStruct));
        if (!bulkAttachCliRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkAttachCliRStruct is a null pointer");

            jsonBulkAttachClientsObjectResponseStructDelete(bulkAttachClisObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        bulkAttachCliRStruct->success = 1;

        if (cJSON_HasObjectItem(jsonParser, "msg") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "msg"))) {
            char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
            size_t msgLen = strlen(msg);
            char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
            if (!msgCopy) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "msgCopy is a null pointer");

                free(bulkAttachCliRStruct);

                jsonBulkAttachClientsObjectResponseStructDelete(bulkAttachClisObjRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }
            strncpy(msgCopy, msg, msgLen);
            msgCopy[msgLen] = '\0';
            bulkAttachCliRStruct->msg = msgCopy;

        } else {
            bulkAttachCliRStruct->msg = NULL;

        }

        bulkAttachCliRStruct->bulkAttachClisObjRStruct = bulkAttachClisObjRStruct;

        cJSON_Delete(jsonParser);

        return bulkAttachCliRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonBulkAttachClientsResponseStruct* failRStruct = (struct jsonBulkAttachClientsResponseStruct*)calloc(1, sizeof(struct jsonBulkAttachClientsResponseStruct));
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

void jsonBulkDetachClientsPostStructDelete(struct jsonBulkDetachClientsPostStruct* bulkDetachClientsPostStruct) {
    if (!bulkDetachClientsPostStruct) {
        return;

    }

    jsonBulkStringArrayFree(bulkDetachClientsPostStruct->emails, bulkDetachClientsPostStruct->emailsCount);
    free(bulkDetachClientsPostStruct->inboundIds);

    free(bulkDetachClientsPostStruct);

}

const char* jsonBulkDetachClientsPost(struct jsonBulkDetachClientsPostStruct* bulkDetachClientsPostStruct) {
    if (!bulkDetachClientsPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkDetachClientsPostStruct is a null pointer");

        return NULL;

    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");

        return NULL;

    }

    cJSON* emailsArray = jsonBulkEmailsArrayCreate(bulkDetachClientsPostStruct->emails, bulkDetachClientsPostStruct->emailsCount);
    if (!emailsArray) {
        cJSON_Delete(json);

        return NULL;

    }
    cJSON_AddItemToObject(json, "emails", emailsArray);

    cJSON* inboundIdsArray = cJSON_CreateArray();
    if (!inboundIdsArray) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create inboundIds array");

        cJSON_Delete(json);

        return NULL;

    }
    cJSON_AddItemToObject(json, "inboundIds", inboundIdsArray);

    for (int64_t i = 0; i < bulkDetachClientsPostStruct->inboundIdsCount; i++) {
        cJSON_AddItemToArray(inboundIdsArray, cJSON_CreateNumber(bulkDetachClientsPostStruct->inboundIds[i]));
    }

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");

        return NULL;

    }

    return jsonString;

}

void jsonBulkDetachClientsObjectResponseStructDelete(struct jsonBulkDetachClientsObjectResponseStruct* bulkDetachClisObjRStruct) {
    if (!bulkDetachClisObjRStruct) {
        return;

    }

    jsonBulkStringArrayFree(bulkDetachClisObjRStruct->detached, bulkDetachClisObjRStruct->detachedCount);
    jsonBulkStringArrayFree(bulkDetachClisObjRStruct->skipped, bulkDetachClisObjRStruct->skippedCount);
    jsonBulkStringArrayFree(bulkDetachClisObjRStruct->errors, bulkDetachClisObjRStruct->errorsCount);

    free(bulkDetachClisObjRStruct);

}

void jsonBulkDetachClientsResponseStructDelete(struct jsonBulkDetachClientsResponseStruct* bulkDetachCliRStruct) {
    if (!bulkDetachCliRStruct) {
        return;

    }

    free((char*)bulkDetachCliRStruct->msg);

    if (bulkDetachCliRStruct->bulkDetachClisObjRStruct) {
        jsonBulkDetachClientsObjectResponseStructDelete(bulkDetachCliRStruct->bulkDetachClisObjRStruct);
        bulkDetachCliRStruct->bulkDetachClisObjRStruct = NULL;

    }

    free(bulkDetachCliRStruct);

}

struct jsonBulkDetachClientsResponseStruct* jsonBulkDetachClientsResponse(const char* json) {
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

        struct jsonBulkDetachClientsObjectResponseStruct* bulkDetachClisObjRStruct = (struct jsonBulkDetachClientsObjectResponseStruct*)calloc(1, sizeof(struct jsonBulkDetachClientsObjectResponseStruct));
        if (!bulkDetachClisObjRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkDetachClisObjRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (cJSON_HasObjectItem(obj, "detached") && cJSON_IsArray(cJSON_GetObjectItem(obj, "detached"))) {
            if (!jsonBulkStringArrayParse(cJSON_GetObjectItem(obj, "detached"), &bulkDetachClisObjRStruct->detached, &bulkDetachClisObjRStruct->detachedCount)) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to parse detached array");

                jsonBulkDetachClientsObjectResponseStructDelete(bulkDetachClisObjRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }

        }

        if (cJSON_HasObjectItem(obj, "skipped") && cJSON_IsArray(cJSON_GetObjectItem(obj, "skipped"))) {
            if (!jsonBulkStringArrayParse(cJSON_GetObjectItem(obj, "skipped"), &bulkDetachClisObjRStruct->skipped, &bulkDetachClisObjRStruct->skippedCount)) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to parse skipped array");

                jsonBulkDetachClientsObjectResponseStructDelete(bulkDetachClisObjRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }

        }

        if (cJSON_HasObjectItem(obj, "errors") && cJSON_IsArray(cJSON_GetObjectItem(obj, "errors"))) {
            if (!jsonBulkStringArrayParse(cJSON_GetObjectItem(obj, "errors"), &bulkDetachClisObjRStruct->errors, &bulkDetachClisObjRStruct->errorsCount)) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to parse errors array");

                jsonBulkDetachClientsObjectResponseStructDelete(bulkDetachClisObjRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }

        }

        struct jsonBulkDetachClientsResponseStruct* bulkDetachCliRStruct = (struct jsonBulkDetachClientsResponseStruct*)malloc(sizeof(struct jsonBulkDetachClientsResponseStruct));
        if (!bulkDetachCliRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkDetachCliRStruct is a null pointer");

            jsonBulkDetachClientsObjectResponseStructDelete(bulkDetachClisObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        bulkDetachCliRStruct->success = 1;

        if (cJSON_HasObjectItem(jsonParser, "msg") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "msg"))) {
            char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
            size_t msgLen = strlen(msg);
            char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
            if (!msgCopy) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "msgCopy is a null pointer");

                free(bulkDetachCliRStruct);

                jsonBulkDetachClientsObjectResponseStructDelete(bulkDetachClisObjRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }
            strncpy(msgCopy, msg, msgLen);
            msgCopy[msgLen] = '\0';
            bulkDetachCliRStruct->msg = msgCopy;

        } else {
            bulkDetachCliRStruct->msg = NULL;

        }

        bulkDetachCliRStruct->bulkDetachClisObjRStruct = bulkDetachClisObjRStruct;

        cJSON_Delete(jsonParser);

        return bulkDetachCliRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonBulkDetachClientsResponseStruct* failRStruct = (struct jsonBulkDetachClientsResponseStruct*)calloc(1, sizeof(struct jsonBulkDetachClientsResponseStruct));
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

void jsonAttachClient2AdditionalInboundsPostStructDelete(struct jsonAttachClient2AdditionalInboundsPostStruct* attachClient2AdditionalInboundsPostStruct) {
    if (!attachClient2AdditionalInboundsPostStruct) {
        return;

    }

    free(attachClient2AdditionalInboundsPostStruct->inboundIds);

    free(attachClient2AdditionalInboundsPostStruct);

}

const char* jsonAttachClient2AdditionalInboundsPost(struct jsonAttachClient2AdditionalInboundsPostStruct* attachClient2AdditionalInboundsPostStruct) {
    if (!attachClient2AdditionalInboundsPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "attachClient2AdditionalInboundsPostStruct is a null pointer");

        return NULL;

    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");

        return NULL;

    }

    cJSON* inboundIdsArray = cJSON_CreateArray();
    if (!inboundIdsArray) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create inboundIds array");

        cJSON_Delete(json);

        return NULL;

    }
    cJSON_AddItemToObject(json, "inboundIds", inboundIdsArray);

    for (int64_t i = 0; i < attachClient2AdditionalInboundsPostStruct->inboundIdsCount; i++) {
        cJSON_AddItemToArray(inboundIdsArray, cJSON_CreateNumber(attachClient2AdditionalInboundsPostStruct->inboundIds[i]));
    }

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");

        return NULL;

    }

    return jsonString;

}

void jsonAttachClient2AdditionalInboundsResponseStructDelete(struct jsonAttachClient2AdditionalInboundsResponseStruct* attachCli2AdditionalInboundsRStruct) {
    if (!attachCli2AdditionalInboundsRStruct) {
        return;

    }

    free((char*)attachCli2AdditionalInboundsRStruct->msg);
    free(attachCli2AdditionalInboundsRStruct);

}

struct jsonAttachClient2AdditionalInboundsResponseStruct* jsonAttachClient2AdditionalInboundsResponse(const char* json) {
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
        struct jsonAttachClient2AdditionalInboundsResponseStruct* attachCli2AdditionalInboundsRStruct = (struct jsonAttachClient2AdditionalInboundsResponseStruct*)malloc(sizeof(struct jsonAttachClient2AdditionalInboundsResponseStruct));
        if (!attachCli2AdditionalInboundsRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "attachCli2AdditionalInboundsRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        attachCli2AdditionalInboundsRStruct->success = 1;

        if (cJSON_HasObjectItem(jsonParser, "msg") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "msg"))) {
            char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
            size_t msgLen = strlen(msg);
            char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
            if (!msgCopy) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "msgCopy is a null pointer");

                free(attachCli2AdditionalInboundsRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }
            strncpy(msgCopy, msg, msgLen);
            msgCopy[msgLen] = '\0';
            attachCli2AdditionalInboundsRStruct->msg = msgCopy;

        } else {
            attachCli2AdditionalInboundsRStruct->msg = NULL;

        }

        attachCli2AdditionalInboundsRStruct->obj = NULL; // This shall be null on normal ( not customized  ) setup

        cJSON_Delete(jsonParser);

        return attachCli2AdditionalInboundsRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonAttachClient2AdditionalInboundsResponseStruct* failRStruct = (struct jsonAttachClient2AdditionalInboundsResponseStruct*)calloc(1, sizeof(struct jsonAttachClient2AdditionalInboundsResponseStruct));
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

void jsonDetachClient2AdditionalInboundsPostStructDelete(struct jsonDetachClient2AdditionalInboundsPostStruct* detachClient2AdditionalInboundsPostStruct) {
    if (!detachClient2AdditionalInboundsPostStruct) {
        return;

    }

    free(detachClient2AdditionalInboundsPostStruct->inboundIds);

    free(detachClient2AdditionalInboundsPostStruct);

}

const char* jsonDetachClient2AdditionalInboundsPost(struct jsonDetachClient2AdditionalInboundsPostStruct* detachClient2AdditionalInboundsPostStruct) {
    if (!detachClient2AdditionalInboundsPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "detachClient2AdditionalInboundsPostStruct is a null pointer");

        return NULL;

    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");

        return NULL;

    }

    cJSON* inboundIdsArray = cJSON_CreateArray();
    if (!inboundIdsArray) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create inboundIds array");

        cJSON_Delete(json);

        return NULL;

    }
    cJSON_AddItemToObject(json, "inboundIds", inboundIdsArray);

    for (int64_t i = 0; i < detachClient2AdditionalInboundsPostStruct->inboundIdsCount; i++) {
        cJSON_AddItemToArray(inboundIdsArray, cJSON_CreateNumber(detachClient2AdditionalInboundsPostStruct->inboundIds[i]));
    }

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");

        return NULL;

    }

    return jsonString;

}

void jsonDetachClient2AdditionalInboundsResponseStructDelete(struct jsonDetachClient2AdditionalInboundsResponseStruct* detachCli2AdditionalInboundsRStruct) {
    if (!detachCli2AdditionalInboundsRStruct) {
        return;

    }

    free((char*)detachCli2AdditionalInboundsRStruct->msg);
    free(detachCli2AdditionalInboundsRStruct);

}

struct jsonDetachClient2AdditionalInboundsResponseStruct* jsonDetachClient2AdditionalInboundsResponse(const char* json) {
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
        struct jsonDetachClient2AdditionalInboundsResponseStruct* detachCli2AdditionalInboundsRStruct = (struct jsonDetachClient2AdditionalInboundsResponseStruct*)malloc(sizeof(struct jsonDetachClient2AdditionalInboundsResponseStruct));
        if (!detachCli2AdditionalInboundsRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "detachCli2AdditionalInboundsRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        detachCli2AdditionalInboundsRStruct->success = 1;

        if (cJSON_HasObjectItem(jsonParser, "msg") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "msg"))) {
            char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
            size_t msgLen = strlen(msg);
            char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
            if (!msgCopy) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "msgCopy is a null pointer");

                free(detachCli2AdditionalInboundsRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }
            strncpy(msgCopy, msg, msgLen);
            msgCopy[msgLen] = '\0';
            detachCli2AdditionalInboundsRStruct->msg = msgCopy;

        } else {
            detachCli2AdditionalInboundsRStruct->msg = NULL;

        }

        detachCli2AdditionalInboundsRStruct->obj = NULL; // This shall be null on normal ( not customized  ) setup

        cJSON_Delete(jsonParser);

        return detachCli2AdditionalInboundsRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonDetachClient2AdditionalInboundsResponseStruct* failRStruct = (struct jsonDetachClient2AdditionalInboundsResponseStruct*)calloc(1, sizeof(struct jsonDetachClient2AdditionalInboundsResponseStruct));
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

void jsonBulkResetTrafficPostStructDelete(struct jsonBulkResetTrafficPostStruct* bulkResetTrafficPostStruct) {
    if (!bulkResetTrafficPostStruct) {
        return;

    }

    jsonBulkStringArrayFree(bulkResetTrafficPostStruct->emails, bulkResetTrafficPostStruct->emailsCount);

    free(bulkResetTrafficPostStruct);

}

const char* jsonBulkResetTrafficPost(struct jsonBulkResetTrafficPostStruct* bulkResetTrafficPostStruct) {
    if (!bulkResetTrafficPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkResetTrafficPostStruct is a null pointer");

        return NULL;

    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");

        return NULL;

    }

    cJSON* emailsArray = jsonBulkEmailsArrayCreate(bulkResetTrafficPostStruct->emails, bulkResetTrafficPostStruct->emailsCount);
    if (!emailsArray) {
        cJSON_Delete(json);

        return NULL;

    }
    cJSON_AddItemToObject(json, "emails", emailsArray);

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");

        return NULL;

    }

    return jsonString;

}

void jsonBulkResetTrafficObjectResponseStructDelete(struct jsonBulkResetTrafficObjectResponseStruct* bulkResetTrafficObjRStruct) {
    if (!bulkResetTrafficObjRStruct) {
        return;

    }

    free(bulkResetTrafficObjRStruct);

}

void jsonBulkResetTrafficResponseStructDelete(struct jsonBulkResetTrafficResponseStruct* bulkResetTrafficRStruct) {
    if (!bulkResetTrafficRStruct) {
        return;

    }

    free((char*)bulkResetTrafficRStruct->msg);

    if (bulkResetTrafficRStruct->bulkResetTrafficObjRStruct) {
        jsonBulkResetTrafficObjectResponseStructDelete(bulkResetTrafficRStruct->bulkResetTrafficObjRStruct);
        bulkResetTrafficRStruct->bulkResetTrafficObjRStruct = NULL;

    }

    free(bulkResetTrafficRStruct);

}

struct jsonBulkResetTrafficResponseStruct* jsonBulkResetTrafficResponse(const char* json) {
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

        struct jsonBulkResetTrafficObjectResponseStruct* bulkResetTrafficObjRStruct = (struct jsonBulkResetTrafficObjectResponseStruct*)calloc(1, sizeof(struct jsonBulkResetTrafficObjectResponseStruct));
        if (!bulkResetTrafficObjRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkResetTrafficObjRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (cJSON_HasObjectItem(obj, "affected") && cJSON_IsNumber(cJSON_GetObjectItem(obj, "affected"))) {
            bulkResetTrafficObjRStruct->affected = (int64_t)cJSON_GetObjectItem(obj, "affected")->valuedouble;

        }

        struct jsonBulkResetTrafficResponseStruct* bulkResetTrafficRStruct = (struct jsonBulkResetTrafficResponseStruct*)malloc(sizeof(struct jsonBulkResetTrafficResponseStruct));
        if (!bulkResetTrafficRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkResetTrafficRStruct is a null pointer");

            jsonBulkResetTrafficObjectResponseStructDelete(bulkResetTrafficObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        bulkResetTrafficRStruct->success = 1;

        if (cJSON_HasObjectItem(jsonParser, "msg") && cJSON_IsString(cJSON_GetObjectItem(jsonParser, "msg"))) {
            char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
            size_t msgLen = strlen(msg);
            char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
            if (!msgCopy) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "msgCopy is a null pointer");

                free(bulkResetTrafficRStruct);

                jsonBulkResetTrafficObjectResponseStructDelete(bulkResetTrafficObjRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }
            strncpy(msgCopy, msg, msgLen);
            msgCopy[msgLen] = '\0';
            bulkResetTrafficRStruct->msg = msgCopy;

        } else {
            bulkResetTrafficRStruct->msg = NULL;

        }

        bulkResetTrafficRStruct->bulkResetTrafficObjRStruct = bulkResetTrafficObjRStruct;

        cJSON_Delete(jsonParser);

        return bulkResetTrafficRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonBulkResetTrafficResponseStruct* failRStruct = (struct jsonBulkResetTrafficResponseStruct*)calloc(1, sizeof(struct jsonBulkResetTrafficResponseStruct));
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

void jsonListGroupsObjectArrayStructDelete(struct jsonListGroupsObjectArrayStruct* listGroupsObjArrStruct, size_t arraySize) {
    if (!listGroupsObjArrStruct) {
        return;

    }

    for (size_t i = 0; i < arraySize; i++) {
        free((char*)listGroupsObjArrStruct[i].name);

    }

    free(listGroupsObjArrStruct);

}

void jsonListGroupsResponseStructDelete(struct jsonListGroupsResponseStruct* listGroupsRStruct) {
    if (!listGroupsRStruct) {
        return;

    }

    free((char*)listGroupsRStruct->msg);

    if (listGroupsRStruct->listGroupsObjArrStruct) {
        jsonListGroupsObjectArrayStructDelete(listGroupsRStruct->listGroupsObjArrStruct, listGroupsRStruct->jsonListGroupsObjectArrayStructSize);
        listGroupsRStruct->listGroupsObjArrStruct = NULL;

    }

    free(listGroupsRStruct);

}

struct jsonListGroupsResponseStruct* jsonListGroupsResponse(const char* json) {
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
        struct jsonListGroupsObjectArrayStruct* listGroupsObjArrStruct = NULL;
        if (arraySize) {
            listGroupsObjArrStruct = (struct jsonListGroupsObjectArrayStruct*)calloc(arraySize, sizeof(struct jsonListGroupsObjectArrayStruct));
            if (!listGroupsObjArrStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listGroupsObjArrStruct is a null pointer");

                cJSON_Delete(jsonParser);

                return NULL;

            }
            for (size_t i = 0; i < arraySize; i++) {
                cJSON* arrItem = cJSON_GetArrayItem(objArray, i);
                if (!cJSON_IsObject(arrItem)) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Array element is not an object, skipping...");

                    continue;

                }
                if (!jsonCopyStringItem(arrItem, "name", &listGroupsObjArrStruct[i].name)) {
                    jsonListGroupsObjectArrayStructDelete(listGroupsObjArrStruct, arraySize);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }
                if (cJSON_HasObjectItem(arrItem, "clientCount") && cJSON_IsNumber(cJSON_GetObjectItem(arrItem, "clientCount"))) {
                    listGroupsObjArrStruct[i].clientCount = (int64_t)cJSON_GetObjectItem(arrItem, "clientCount")->valuedouble;

                }

            }

        }

        struct jsonListGroupsResponseStruct* listGroupsRStruct = (struct jsonListGroupsResponseStruct*)calloc(1, sizeof(struct jsonListGroupsResponseStruct));
        if (!listGroupsRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listGroupsRStruct is a null pointer");

            jsonListGroupsObjectArrayStructDelete(listGroupsObjArrStruct, arraySize);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        listGroupsRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &listGroupsRStruct->msg)) {
            jsonListGroupsResponseStructDelete(listGroupsRStruct);

            jsonListGroupsObjectArrayStructDelete(listGroupsObjArrStruct, arraySize);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        listGroupsRStruct->jsonListGroupsObjectArrayStructSize = arraySize;
        listGroupsRStruct->listGroupsObjArrStruct = listGroupsObjArrStruct;

        cJSON_Delete(jsonParser);

        return listGroupsRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonListGroupsResponseStruct* failRStruct = (struct jsonListGroupsResponseStruct*)calloc(1, sizeof(struct jsonListGroupsResponseStruct));
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

void jsonListGroupEmailsResponseStructDelete(struct jsonListGroupEmailsResponseStruct* listGroupEmailsRStruct) {
    if (!listGroupEmailsRStruct) {
        return;

    }

    free((char*)listGroupEmailsRStruct->msg);
    jsonBulkStringArrayFree(listGroupEmailsRStruct->obj, listGroupEmailsRStruct->objCount);
    free(listGroupEmailsRStruct);

}

struct jsonListGroupEmailsResponseStruct* jsonListGroupEmailsResponse(const char* json) {
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
        struct jsonListGroupEmailsResponseStruct* listGroupEmailsRStruct = (struct jsonListGroupEmailsResponseStruct*)calloc(1, sizeof(struct jsonListGroupEmailsResponseStruct));
        if (!listGroupEmailsRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listGroupEmailsRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        listGroupEmailsRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &listGroupEmailsRStruct->msg)) {
            jsonListGroupEmailsResponseStructDelete(listGroupEmailsRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsArray(cJSON_GetObjectItem(jsonParser, "obj"))) {
            if (!jsonBulkStringArrayParse(cJSON_GetObjectItem(jsonParser, "obj"), &listGroupEmailsRStruct->obj, &listGroupEmailsRStruct->objCount)) {
                jsonListGroupEmailsResponseStructDelete(listGroupEmailsRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }

        }

        cJSON_Delete(jsonParser);

        return listGroupEmailsRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonListGroupEmailsResponseStruct* failRStruct = (struct jsonListGroupEmailsResponseStruct*)calloc(1, sizeof(struct jsonListGroupEmailsResponseStruct));
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

void jsonCreateGroupPostStructDelete(struct jsonCreateGroupPostStruct* createGroupPostStruct) {
    if (!createGroupPostStruct) {
        return;

    }

    free((char*)createGroupPostStruct->name);
    free(createGroupPostStruct);

}

const char* jsonCreateGroupPost(struct jsonCreateGroupPostStruct* createGroupPostStruct) {
    if (!createGroupPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "createGroupPostStruct is a null pointer");

        return NULL;

    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");

        return NULL;

    }

    if (createGroupPostStruct->name) {
        cJSON_AddStringToObject(json, "name", createGroupPostStruct->name);

    }

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");

        return NULL;

    }

    return jsonString;

}

void jsonCreateGroupObjectResponseStructDelete(struct jsonCreateGroupObjectResponseStruct* createGroupObjRStruct) {
    if (!createGroupObjRStruct) {
        return;

    }

    free((char*)createGroupObjRStruct->name);
    free(createGroupObjRStruct);

}

void jsonCreateGroupResponseStructDelete(struct jsonCreateGroupResponseStruct* createGroupRStruct) {
    if (!createGroupRStruct) {
        return;

    }

    free((char*)createGroupRStruct->msg);

    if (createGroupRStruct->createGroupObjRStruct) {
        jsonCreateGroupObjectResponseStructDelete(createGroupRStruct->createGroupObjRStruct);
        createGroupRStruct->createGroupObjRStruct = NULL;

    }

    free(createGroupRStruct);

}

struct jsonCreateGroupResponseStruct* jsonCreateGroupResponse(const char* json) {
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

        struct jsonCreateGroupObjectResponseStruct* createGroupObjRStruct = (struct jsonCreateGroupObjectResponseStruct*)calloc(1, sizeof(struct jsonCreateGroupObjectResponseStruct));
        if (!createGroupObjRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "createGroupObjRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (!jsonCopyStringItem(obj, "name", &createGroupObjRStruct->name)) {
            jsonCreateGroupObjectResponseStructDelete(createGroupObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        struct jsonCreateGroupResponseStruct* createGroupRStruct = (struct jsonCreateGroupResponseStruct*)calloc(1, sizeof(struct jsonCreateGroupResponseStruct));
        if (!createGroupRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "createGroupRStruct is a null pointer");

            jsonCreateGroupObjectResponseStructDelete(createGroupObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        createGroupRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &createGroupRStruct->msg)) {
            jsonCreateGroupResponseStructDelete(createGroupRStruct);

            jsonCreateGroupObjectResponseStructDelete(createGroupObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        createGroupRStruct->createGroupObjRStruct = createGroupObjRStruct;

        cJSON_Delete(jsonParser);

        return createGroupRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonCreateGroupResponseStruct* failRStruct = (struct jsonCreateGroupResponseStruct*)calloc(1, sizeof(struct jsonCreateGroupResponseStruct));
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

void jsonRenameGroupPostStructDelete(struct jsonRenameGroupPostStruct* renameGroupPostStruct) {

    if (!renameGroupPostStruct) {
        return;

    }

    free((char*)renameGroupPostStruct->oldName);

    free((char*)renameGroupPostStruct->newName);

    free(renameGroupPostStruct);

}

const char* jsonRenameGroupPost(struct jsonRenameGroupPostStruct* renameGroupPostStruct) {

    if (!renameGroupPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "renameGroupPostStruct is a null pointer");

        return NULL;

    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");

        return NULL;

    }

    if (renameGroupPostStruct->oldName) {
        cJSON_AddStringToObject(json, "oldName", renameGroupPostStruct->oldName);
    }

    if (renameGroupPostStruct->newName) {
        cJSON_AddStringToObject(json, "newName", renameGroupPostStruct->newName);
    }

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");

        return NULL;

    }

    return jsonString;

}

void jsonRenameGroupObjectResponseStructDelete(struct jsonRenameGroupObjectResponseStruct* renameGroupObjRStruct) {

    if (!renameGroupObjRStruct) {
        return;

    }

    free(renameGroupObjRStruct);

}

void jsonRenameGroupResponseStructDelete(struct jsonRenameGroupResponseStruct* renameGroupRStruct) {

    if (!renameGroupRStruct) {
        return;

    }

    free((char*)renameGroupRStruct->msg);

    if (renameGroupRStruct->renameGroupObjRStruct) {
        jsonRenameGroupObjectResponseStructDelete(renameGroupRStruct->renameGroupObjRStruct);
        renameGroupRStruct->renameGroupObjRStruct = NULL;

    }

    free(renameGroupRStruct);

}

struct jsonRenameGroupResponseStruct* jsonRenameGroupResponse(const char* json) {
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

        struct jsonRenameGroupObjectResponseStruct* renameGroupObjRStruct = (struct jsonRenameGroupObjectResponseStruct*)calloc(1, sizeof(struct jsonRenameGroupObjectResponseStruct));
        if (!renameGroupObjRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "renameGroupObjRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (cJSON_HasObjectItem(obj, "affected") && cJSON_IsNumber(cJSON_GetObjectItem(obj, "affected"))) {
            renameGroupObjRStruct->affected = (int64_t)cJSON_GetObjectItem(obj, "affected")->valuedouble;

        }

        struct jsonRenameGroupResponseStruct* renameGroupRStruct = (struct jsonRenameGroupResponseStruct*)calloc(1, sizeof(struct jsonRenameGroupResponseStruct));
        if (!renameGroupRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "renameGroupRStruct is a null pointer");

            jsonRenameGroupObjectResponseStructDelete(renameGroupObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        renameGroupRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &renameGroupRStruct->msg)) {
            jsonRenameGroupResponseStructDelete(renameGroupRStruct);

            jsonRenameGroupObjectResponseStructDelete(renameGroupObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        renameGroupRStruct->renameGroupObjRStruct = renameGroupObjRStruct;

        cJSON_Delete(jsonParser);

        return renameGroupRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonRenameGroupResponseStruct* failRStruct = (struct jsonRenameGroupResponseStruct*)calloc(1, sizeof(struct jsonRenameGroupResponseStruct));
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

void jsonDeleteGroupPostStructDelete(struct jsonDeleteGroupPostStruct* deleteGroupPostStruct) {

    if (!deleteGroupPostStruct) {
        return;

    }

    free((char*)deleteGroupPostStruct->name);

    free(deleteGroupPostStruct);

}

const char* jsonDeleteGroupPost(struct jsonDeleteGroupPostStruct* deleteGroupPostStruct) {

    if (!deleteGroupPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "deleteGroupPostStruct is a null pointer");

        return NULL;

    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");

        return NULL;

    }

    if (deleteGroupPostStruct->name) {
        cJSON_AddStringToObject(json, "name", deleteGroupPostStruct->name);
    }

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");

        return NULL;

    }

    return jsonString;

}

void jsonDeleteGroupObjectResponseStructDelete(struct jsonDeleteGroupObjectResponseStruct* deleteGroupObjRStruct) {

    if (!deleteGroupObjRStruct) {
        return;

    }

    free(deleteGroupObjRStruct);

}

void jsonDeleteGroupResponseStructDelete(struct jsonDeleteGroupResponseStruct* deleteGroupRStruct) {

    if (!deleteGroupRStruct) {
        return;

    }

    free((char*)deleteGroupRStruct->msg);

    if (deleteGroupRStruct->deleteGroupObjRStruct) {
        jsonDeleteGroupObjectResponseStructDelete(deleteGroupRStruct->deleteGroupObjRStruct);
        deleteGroupRStruct->deleteGroupObjRStruct = NULL;

    }

    free(deleteGroupRStruct);

}

struct jsonDeleteGroupResponseStruct* jsonDeleteGroupResponse(const char* json) {
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

        struct jsonDeleteGroupObjectResponseStruct* deleteGroupObjRStruct = (struct jsonDeleteGroupObjectResponseStruct*)calloc(1, sizeof(struct jsonDeleteGroupObjectResponseStruct));
        if (!deleteGroupObjRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "deleteGroupObjRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (cJSON_HasObjectItem(obj, "affected") && cJSON_IsNumber(cJSON_GetObjectItem(obj, "affected"))) {
            deleteGroupObjRStruct->affected = (int64_t)cJSON_GetObjectItem(obj, "affected")->valuedouble;

        }

        struct jsonDeleteGroupResponseStruct* deleteGroupRStruct = (struct jsonDeleteGroupResponseStruct*)calloc(1, sizeof(struct jsonDeleteGroupResponseStruct));
        if (!deleteGroupRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "deleteGroupRStruct is a null pointer");

            jsonDeleteGroupObjectResponseStructDelete(deleteGroupObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        deleteGroupRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &deleteGroupRStruct->msg)) {
            jsonDeleteGroupResponseStructDelete(deleteGroupRStruct);

            jsonDeleteGroupObjectResponseStructDelete(deleteGroupObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        deleteGroupRStruct->deleteGroupObjRStruct = deleteGroupObjRStruct;

        cJSON_Delete(jsonParser);

        return deleteGroupRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonDeleteGroupResponseStruct* failRStruct = (struct jsonDeleteGroupResponseStruct*)calloc(1, sizeof(struct jsonDeleteGroupResponseStruct));
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

void jsonResetGroupTrafficPostStructDelete(struct jsonResetGroupTrafficPostStruct* resetGroupTrafficPostStruct) {

    if (!resetGroupTrafficPostStruct) {
        return;

    }

    free((char*)resetGroupTrafficPostStruct->name);

    free(resetGroupTrafficPostStruct);

}

const char* jsonResetGroupTrafficPost(struct jsonResetGroupTrafficPostStruct* resetGroupTrafficPostStruct) {

    if (!resetGroupTrafficPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "resetGroupTrafficPostStruct is a null pointer");

        return NULL;

    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");

        return NULL;

    }

    if (resetGroupTrafficPostStruct->name) {
        cJSON_AddStringToObject(json, "name", resetGroupTrafficPostStruct->name);
    }

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");

        return NULL;

    }

    return jsonString;

}

void jsonResetGroupTrafficObjectResponseStructDelete(struct jsonResetGroupTrafficObjectResponseStruct* resetGroupTrafficObjRStruct) {

    if (!resetGroupTrafficObjRStruct) {
        return;

    }

    free((char*)resetGroupTrafficObjRStruct->name);

    free(resetGroupTrafficObjRStruct);

}

void jsonResetGroupTrafficResponseStructDelete(struct jsonResetGroupTrafficResponseStruct* resetGroupTrafficRStruct) {

    if (!resetGroupTrafficRStruct) {
        return;

    }

    free((char*)resetGroupTrafficRStruct->msg);

    if (resetGroupTrafficRStruct->resetGroupTrafficObjRStruct) {
        jsonResetGroupTrafficObjectResponseStructDelete(resetGroupTrafficRStruct->resetGroupTrafficObjRStruct);
        resetGroupTrafficRStruct->resetGroupTrafficObjRStruct = NULL;

    }

    free(resetGroupTrafficRStruct);

}

struct jsonResetGroupTrafficResponseStruct* jsonResetGroupTrafficResponse(const char* json) {
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

        struct jsonResetGroupTrafficObjectResponseStruct* resetGroupTrafficObjRStruct = (struct jsonResetGroupTrafficObjectResponseStruct*)calloc(1, sizeof(struct jsonResetGroupTrafficObjectResponseStruct));
        if (!resetGroupTrafficObjRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "resetGroupTrafficObjRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (!jsonCopyStringItem(obj, "name", &resetGroupTrafficObjRStruct->name)) {
            jsonResetGroupTrafficObjectResponseStructDelete(resetGroupTrafficObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        struct jsonResetGroupTrafficResponseStruct* resetGroupTrafficRStruct = (struct jsonResetGroupTrafficResponseStruct*)calloc(1, sizeof(struct jsonResetGroupTrafficResponseStruct));
        if (!resetGroupTrafficRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "resetGroupTrafficRStruct is a null pointer");

            jsonResetGroupTrafficObjectResponseStructDelete(resetGroupTrafficObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        resetGroupTrafficRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &resetGroupTrafficRStruct->msg)) {
            jsonResetGroupTrafficResponseStructDelete(resetGroupTrafficRStruct);

            jsonResetGroupTrafficObjectResponseStructDelete(resetGroupTrafficObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        resetGroupTrafficRStruct->resetGroupTrafficObjRStruct = resetGroupTrafficObjRStruct;

        cJSON_Delete(jsonParser);

        return resetGroupTrafficRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonResetGroupTrafficResponseStruct* failRStruct = (struct jsonResetGroupTrafficResponseStruct*)calloc(1, sizeof(struct jsonResetGroupTrafficResponseStruct));
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

void jsonBulkAddClients2GroupPostStructDelete(struct jsonBulkAddClients2GroupPostStruct* bulkAddClients2GroupPostStruct) {

    if (!bulkAddClients2GroupPostStruct) {
        return;

    }

    jsonBulkStringArrayFree(bulkAddClients2GroupPostStruct->emails, bulkAddClients2GroupPostStruct->emailsCount);

    free((char*)bulkAddClients2GroupPostStruct->group);

    free(bulkAddClients2GroupPostStruct);

}

const char* jsonBulkAddClients2GroupPost(struct jsonBulkAddClients2GroupPostStruct* bulkAddClients2GroupPostStruct) {

    if (!bulkAddClients2GroupPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkAddClients2GroupPostStruct is a null pointer");

        return NULL;

    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");

        return NULL;

    }

    cJSON* emailsArray = jsonBulkEmailsArrayCreate(bulkAddClients2GroupPostStruct->emails, bulkAddClients2GroupPostStruct->emailsCount);
    if (!emailsArray) {
        cJSON_Delete(json);

        return NULL;

    }
    cJSON_AddItemToObject(json, "emails", emailsArray);

    if (bulkAddClients2GroupPostStruct->group) {
        cJSON_AddStringToObject(json, "group", bulkAddClients2GroupPostStruct->group);
    }

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");

        return NULL;

    }

    return jsonString;

}

void jsonBulkAddClients2GroupObjectResponseStructDelete(struct jsonBulkAddClients2GroupObjectResponseStruct* bulkAddClis2GroupObjRStruct) {

    if (!bulkAddClis2GroupObjRStruct) {
        return;

    }

    free(bulkAddClis2GroupObjRStruct);

}

void jsonBulkAddClients2GroupResponseStructDelete(struct jsonBulkAddClients2GroupResponseStruct* bulkAddClis2GroupRStruct) {

    if (!bulkAddClis2GroupRStruct) {
        return;

    }

    free((char*)bulkAddClis2GroupRStruct->msg);

    if (bulkAddClis2GroupRStruct->bulkAddClis2GroupObjRStruct) {
        jsonBulkAddClients2GroupObjectResponseStructDelete(bulkAddClis2GroupRStruct->bulkAddClis2GroupObjRStruct);
        bulkAddClis2GroupRStruct->bulkAddClis2GroupObjRStruct = NULL;

    }

    free(bulkAddClis2GroupRStruct);

}

struct jsonBulkAddClients2GroupResponseStruct* jsonBulkAddClients2GroupResponse(const char* json) {
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

        struct jsonBulkAddClients2GroupObjectResponseStruct* bulkAddClis2GroupObjRStruct = (struct jsonBulkAddClients2GroupObjectResponseStruct*)calloc(1, sizeof(struct jsonBulkAddClients2GroupObjectResponseStruct));
        if (!bulkAddClis2GroupObjRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkAddClis2GroupObjRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (cJSON_HasObjectItem(obj, "affected") && cJSON_IsNumber(cJSON_GetObjectItem(obj, "affected"))) {
            bulkAddClis2GroupObjRStruct->affected = (int64_t)cJSON_GetObjectItem(obj, "affected")->valuedouble;

        }

        struct jsonBulkAddClients2GroupResponseStruct* bulkAddClis2GroupRStruct = (struct jsonBulkAddClients2GroupResponseStruct*)calloc(1, sizeof(struct jsonBulkAddClients2GroupResponseStruct));
        if (!bulkAddClis2GroupRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "bulkAddClis2GroupRStruct is a null pointer");

            jsonBulkAddClients2GroupObjectResponseStructDelete(bulkAddClis2GroupObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        bulkAddClis2GroupRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &bulkAddClis2GroupRStruct->msg)) {
            jsonBulkAddClients2GroupResponseStructDelete(bulkAddClis2GroupRStruct);

            jsonBulkAddClients2GroupObjectResponseStructDelete(bulkAddClis2GroupObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        bulkAddClis2GroupRStruct->bulkAddClis2GroupObjRStruct = bulkAddClis2GroupObjRStruct;

        cJSON_Delete(jsonParser);

        return bulkAddClis2GroupRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonBulkAddClients2GroupResponseStruct* failRStruct = (struct jsonBulkAddClients2GroupResponseStruct*)calloc(1, sizeof(struct jsonBulkAddClients2GroupResponseStruct));
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

void jsonUpdateClientTrafficResponseStructDelete(struct jsonUpdateClientTrafficResponseStruct* updateCliTrafficRStruct) {

    if (!updateCliTrafficRStruct) {
        return;

    }

    free((char*)updateCliTrafficRStruct->msg);
    free(updateCliTrafficRStruct);

}

struct jsonUpdateClientTrafficResponseStruct* jsonUpdateClientTrafficResponse(const char* json) {
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

        struct jsonUpdateClientTrafficResponseStruct* updateCliTrafficRStruct = (struct jsonUpdateClientTrafficResponseStruct*)calloc(1, sizeof(struct jsonUpdateClientTrafficResponseStruct));
        if (!updateCliTrafficRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "updateCliTrafficRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        updateCliTrafficRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &updateCliTrafficRStruct->msg)) {
            jsonUpdateClientTrafficResponseStructDelete(updateCliTrafficRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        updateCliTrafficRStruct->obj = NULL; // This shall be null on normal ( not customized  ) setup

        cJSON_Delete(jsonParser);

        return updateCliTrafficRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonUpdateClientTrafficResponseStruct* failRStruct = (struct jsonUpdateClientTrafficResponseStruct*)calloc(1, sizeof(struct jsonUpdateClientTrafficResponseStruct));
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

void jsonResetClientTrafficResponseStructDelete(struct jsonResetClientTrafficResponseStruct* resetCliTrafficRStruct) {

    if (!resetCliTrafficRStruct) {
        return;

    }

    free((char*)resetCliTrafficRStruct->msg);
    free(resetCliTrafficRStruct);

}

struct jsonResetClientTrafficResponseStruct* jsonResetClientTrafficResponse(const char* json) {
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

        struct jsonResetClientTrafficResponseStruct* resetCliTrafficRStruct = (struct jsonResetClientTrafficResponseStruct*)calloc(1, sizeof(struct jsonResetClientTrafficResponseStruct));
        if (!resetCliTrafficRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "resetCliTrafficRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        resetCliTrafficRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &resetCliTrafficRStruct->msg)) {
            jsonResetClientTrafficResponseStructDelete(resetCliTrafficRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        resetCliTrafficRStruct->obj = NULL; // This shall be null on normal ( not customized  ) setup

        cJSON_Delete(jsonParser);

        return resetCliTrafficRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonResetClientTrafficResponseStruct* failRStruct = (struct jsonResetClientTrafficResponseStruct*)calloc(1, sizeof(struct jsonResetClientTrafficResponseStruct));
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

void jsonClearClientIpsResponseStructDelete(struct jsonClearClientIpsResponseStruct* clearCliIpsRStruct) {

    if (!clearCliIpsRStruct) {
        return;

    }

    free((char*)clearCliIpsRStruct->msg);
    free(clearCliIpsRStruct);

}

struct jsonClearClientIpsResponseStruct* jsonClearClientIpsResponse(const char* json) {
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

        struct jsonClearClientIpsResponseStruct* clearCliIpsRStruct = (struct jsonClearClientIpsResponseStruct*)calloc(1, sizeof(struct jsonClearClientIpsResponseStruct));
        if (!clearCliIpsRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "clearCliIpsRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        clearCliIpsRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &clearCliIpsRStruct->msg)) {
            jsonClearClientIpsResponseStructDelete(clearCliIpsRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        clearCliIpsRStruct->obj = NULL; // This shall be null on normal ( not customized  ) setup

        cJSON_Delete(jsonParser);

        return clearCliIpsRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonClearClientIpsResponseStruct* failRStruct = (struct jsonClearClientIpsResponseStruct*)calloc(1, sizeof(struct jsonClearClientIpsResponseStruct));
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

void jsonClearClientHwidsResponseStructDelete(struct jsonClearClientHwidsResponseStruct* clearCliHwidsRStruct) {

    if (!clearCliHwidsRStruct) {
        return;

    }

    free((char*)clearCliHwidsRStruct->msg);
    free(clearCliHwidsRStruct);

}

struct jsonClearClientHwidsResponseStruct* jsonClearClientHwidsResponse(const char* json) {
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

        struct jsonClearClientHwidsResponseStruct* clearCliHwidsRStruct = (struct jsonClearClientHwidsResponseStruct*)calloc(1, sizeof(struct jsonClearClientHwidsResponseStruct));
        if (!clearCliHwidsRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "clearCliHwidsRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        clearCliHwidsRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &clearCliHwidsRStruct->msg)) {
            jsonClearClientHwidsResponseStructDelete(clearCliHwidsRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        clearCliHwidsRStruct->obj = NULL; // This shall be null on normal ( not customized  ) setup

        cJSON_Delete(jsonParser);

        return clearCliHwidsRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonClearClientHwidsResponseStruct* failRStruct = (struct jsonClearClientHwidsResponseStruct*)calloc(1, sizeof(struct jsonClearClientHwidsResponseStruct));
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

void jsonDeleteClientHwidResponseStructDelete(struct jsonDeleteClientHwidResponseStruct* deleteCliHwidRStruct) {

    if (!deleteCliHwidRStruct) {
        return;

    }

    free((char*)deleteCliHwidRStruct->msg);
    free(deleteCliHwidRStruct);

}

struct jsonDeleteClientHwidResponseStruct* jsonDeleteClientHwidResponse(const char* json) {
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

        struct jsonDeleteClientHwidResponseStruct* deleteCliHwidRStruct = (struct jsonDeleteClientHwidResponseStruct*)calloc(1, sizeof(struct jsonDeleteClientHwidResponseStruct));
        if (!deleteCliHwidRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "deleteCliHwidRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        deleteCliHwidRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &deleteCliHwidRStruct->msg)) {
            jsonDeleteClientHwidResponseStructDelete(deleteCliHwidRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        deleteCliHwidRStruct->obj = NULL; // This shall be null on normal ( not customized  ) setup

        cJSON_Delete(jsonParser);

        return deleteCliHwidRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonDeleteClientHwidResponseStruct* failRStruct = (struct jsonDeleteClientHwidResponseStruct*)calloc(1, sizeof(struct jsonDeleteClientHwidResponseStruct));
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

void jsonListClientIpsResponseStructDelete(struct jsonListClientIpsResponseStruct* listCliIpsRStruct) {

    if (!listCliIpsRStruct) {
        return;

    }

    free((char*)listCliIpsRStruct->msg);
    jsonBulkStringArrayFree(listCliIpsRStruct->obj, listCliIpsRStruct->objCount);
    free(listCliIpsRStruct);

}

struct jsonListClientIpsResponseStruct* jsonListClientIpsResponse(const char* json) {
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

        struct jsonListClientIpsResponseStruct* listCliIpsRStruct = (struct jsonListClientIpsResponseStruct*)calloc(1, sizeof(struct jsonListClientIpsResponseStruct));
        if (!listCliIpsRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listCliIpsRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        listCliIpsRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &listCliIpsRStruct->msg)) {
            jsonListClientIpsResponseStructDelete(listCliIpsRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsArray(cJSON_GetObjectItem(jsonParser, "obj"))) {
            if (!jsonBulkStringArrayParse(cJSON_GetObjectItem(jsonParser, "obj"), &listCliIpsRStruct->obj, &listCliIpsRStruct->objCount)) {
                jsonListClientIpsResponseStructDelete(listCliIpsRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }

        }

        cJSON_Delete(jsonParser);

        return listCliIpsRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonListClientIpsResponseStruct* failRStruct = (struct jsonListClientIpsResponseStruct*)calloc(1, sizeof(struct jsonListClientIpsResponseStruct));
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

void jsonOnlinesResponseStructDelete(struct jsonOnlinesResponseStruct* onlinesRStruct) {

    if (!onlinesRStruct) {
        return;

    }

    free((char*)onlinesRStruct->msg);
    jsonBulkStringArrayFree(onlinesRStruct->obj, onlinesRStruct->objCount);
    free(onlinesRStruct);

}

struct jsonOnlinesResponseStruct* jsonOnlinesResponse(const char* json) {
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

        struct jsonOnlinesResponseStruct* onlinesRStruct = (struct jsonOnlinesResponseStruct*)calloc(1, sizeof(struct jsonOnlinesResponseStruct));
        if (!onlinesRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "onlinesRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        onlinesRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &onlinesRStruct->msg)) {
            jsonOnlinesResponseStructDelete(onlinesRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsArray(cJSON_GetObjectItem(jsonParser, "obj"))) {
            if (!jsonBulkStringArrayParse(cJSON_GetObjectItem(jsonParser, "obj"), &onlinesRStruct->obj, &onlinesRStruct->objCount)) {
                jsonOnlinesResponseStructDelete(onlinesRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }

        }

        cJSON_Delete(jsonParser);

        return onlinesRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonOnlinesResponseStruct* failRStruct = (struct jsonOnlinesResponseStruct*)calloc(1, sizeof(struct jsonOnlinesResponseStruct));
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

void jsonSubLinksResponseStructDelete(struct jsonSubLinksResponseStruct* subLinksRStruct) {

    if (!subLinksRStruct) {
        return;

    }

    free((char*)subLinksRStruct->msg);
    jsonBulkStringArrayFree(subLinksRStruct->obj, subLinksRStruct->objCount);
    free(subLinksRStruct);

}

struct jsonSubLinksResponseStruct* jsonSubLinksResponse(const char* json) {
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

        struct jsonSubLinksResponseStruct* subLinksRStruct = (struct jsonSubLinksResponseStruct*)calloc(1, sizeof(struct jsonSubLinksResponseStruct));
        if (!subLinksRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "subLinksRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        subLinksRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &subLinksRStruct->msg)) {
            jsonSubLinksResponseStructDelete(subLinksRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsArray(cJSON_GetObjectItem(jsonParser, "obj"))) {
            if (!jsonBulkStringArrayParse(cJSON_GetObjectItem(jsonParser, "obj"), &subLinksRStruct->obj, &subLinksRStruct->objCount)) {
                jsonSubLinksResponseStructDelete(subLinksRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }

        }

        cJSON_Delete(jsonParser);

        return subLinksRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonSubLinksResponseStruct* failRStruct = (struct jsonSubLinksResponseStruct*)calloc(1, sizeof(struct jsonSubLinksResponseStruct));
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

void jsonLinksResponseStructDelete(struct jsonLinksResponseStruct* linksRStruct) {

    if (!linksRStruct) {
        return;

    }

    free((char*)linksRStruct->msg);
    jsonBulkStringArrayFree(linksRStruct->obj, linksRStruct->objCount);
    free(linksRStruct);

}

struct jsonLinksResponseStruct* jsonLinksResponse(const char* json) {
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

        struct jsonLinksResponseStruct* linksRStruct = (struct jsonLinksResponseStruct*)calloc(1, sizeof(struct jsonLinksResponseStruct));
        if (!linksRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "linksRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        linksRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &linksRStruct->msg)) {
            jsonLinksResponseStructDelete(linksRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (cJSON_HasObjectItem(jsonParser, "obj") && cJSON_IsArray(cJSON_GetObjectItem(jsonParser, "obj"))) {
            if (!jsonBulkStringArrayParse(cJSON_GetObjectItem(jsonParser, "obj"), &linksRStruct->obj, &linksRStruct->objCount)) {
                jsonLinksResponseStructDelete(linksRStruct);

                cJSON_Delete(jsonParser);

                return NULL;

            }

        }

        cJSON_Delete(jsonParser);

        return linksRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonLinksResponseStruct* failRStruct = (struct jsonLinksResponseStruct*)calloc(1, sizeof(struct jsonLinksResponseStruct));
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

void jsonUpdateClientTrafficPostStructDelete(struct jsonUpdateClientTrafficPostStruct* updateClientTrafficPostStruct) {
    if (!updateClientTrafficPostStruct) {
        return;

    }

    free(updateClientTrafficPostStruct);

}

const char* jsonUpdateClientTrafficPost(struct jsonUpdateClientTrafficPostStruct* updateClientTrafficPostStruct) {
    if (!updateClientTrafficPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "updateClientTrafficPostStruct is a null pointer");

        return NULL;

    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");

        return NULL;

    }

    cJSON_AddNumberToObject(json, "upload", (double)updateClientTrafficPostStruct->upload);
    cJSON_AddNumberToObject(json, "download", (double)updateClientTrafficPostStruct->download);

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");

        return NULL;

    }

    return jsonString;

}

void jsonTrafficResponseStructDelete(struct jsonTrafficResponseStruct* trafficRStruct) {
    if (!trafficRStruct) {
        return;

    }

    free((char*)trafficRStruct->msg);

    if (trafficRStruct->trafficObjRStruct) {
        jsonListEveryClientObjectTrafficObjectStructDelete(trafficRStruct->trafficObjRStruct);
        trafficRStruct->trafficObjRStruct = NULL;

    }

    free(trafficRStruct);

}

struct jsonTrafficResponseStruct* jsonTrafficResponse(const char* json) {
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
        struct jsonListEveryClientObjectTrafficObjectStruct* trafficObjRStruct = (struct jsonListEveryClientObjectTrafficObjectStruct*)calloc(1, sizeof(struct jsonListEveryClientObjectTrafficObjectStruct));
        if (!trafficObjRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "trafficObjRStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }
        jsonListEveryClientObjectTrafficObjectStructParse(cJSON_GetObjectItem(jsonParser, "obj"), trafficObjRStruct);

        struct jsonTrafficResponseStruct* trafficRStruct = (struct jsonTrafficResponseStruct*)calloc(1, sizeof(struct jsonTrafficResponseStruct));
        if (!trafficRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "trafficRStruct is a null pointer");

            jsonListEveryClientObjectTrafficObjectStructDelete(trafficObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        trafficRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &trafficRStruct->msg)) {
            jsonTrafficResponseStructDelete(trafficRStruct);

            jsonListEveryClientObjectTrafficObjectStructDelete(trafficObjRStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        trafficRStruct->trafficObjRStruct = trafficObjRStruct;

        cJSON_Delete(jsonParser);

        return trafficRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonTrafficResponseStruct* failRStruct = (struct jsonTrafficResponseStruct*)calloc(1, sizeof(struct jsonTrafficResponseStruct));
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

void jsonListClientHwidsObjectArrayStructDelete(struct jsonListClientHwidsObjectArrayStruct* listClientHwidsObjArrStruct, size_t arraySize) {
    if (!listClientHwidsObjArrStruct) {
        return;

    }

    for (size_t i = 0; i < arraySize; i++) {
        free((char*)listClientHwidsObjArrStruct[i].userAgent);
        free((char*)listClientHwidsObjArrStruct[i].deviceOs);
        free((char*)listClientHwidsObjArrStruct[i].osVersion);
        free((char*)listClientHwidsObjArrStruct[i].deviceModel);
        free((char*)listClientHwidsObjArrStruct[i].fingerprint);

    }

    free(listClientHwidsObjArrStruct);

}

void jsonListClientHwidsResponseStructDelete(struct jsonListClientHwidsResponseStruct* listCliHwidsRStruct) {
    if (!listCliHwidsRStruct) {
        return;

    }

    free((char*)listCliHwidsRStruct->msg);

    if (listCliHwidsRStruct->listClientHwidsObjArrStruct) {
        jsonListClientHwidsObjectArrayStructDelete(listCliHwidsRStruct->listClientHwidsObjArrStruct, listCliHwidsRStruct->jsonListClientHwidsObjectArrayStructSize);
        listCliHwidsRStruct->listClientHwidsObjArrStruct = NULL;

    }

    free(listCliHwidsRStruct);

}

struct jsonListClientHwidsResponseStruct* jsonListClientHwidsResponse(const char* json) {
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
        struct jsonListClientHwidsObjectArrayStruct* listClientHwidsObjArrStruct = NULL;
        if (arraySize) {
            listClientHwidsObjArrStruct = (struct jsonListClientHwidsObjectArrayStruct*)calloc(arraySize, sizeof(struct jsonListClientHwidsObjectArrayStruct));
            if (!listClientHwidsObjArrStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listClientHwidsObjArrStruct is a null pointer");

                cJSON_Delete(jsonParser);

                return NULL;

            }
            for (size_t i = 0; i < arraySize; i++) {
                cJSON* arrItem = cJSON_GetArrayItem(objArray, i);
                if (!cJSON_IsObject(arrItem)) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Array element is not an object, skipping...");

                    continue;

                }
                if (cJSON_HasObjectItem(arrItem, "id") && cJSON_IsNumber(cJSON_GetObjectItem(arrItem, "id"))) {
                    listClientHwidsObjArrStruct[i].id = (int64_t)cJSON_GetObjectItem(arrItem, "id")->valuedouble;

                }
                if (cJSON_HasObjectItem(arrItem, "firstSeen") && cJSON_IsNumber(cJSON_GetObjectItem(arrItem, "firstSeen"))) {
                    listClientHwidsObjArrStruct[i].firstSeen = (int64_t)cJSON_GetObjectItem(arrItem, "firstSeen")->valuedouble;

                }
                if (cJSON_HasObjectItem(arrItem, "lastSeen") && cJSON_IsNumber(cJSON_GetObjectItem(arrItem, "lastSeen"))) {
                    listClientHwidsObjArrStruct[i].lastSeen = (int64_t)cJSON_GetObjectItem(arrItem, "lastSeen")->valuedouble;

                }
                if (
                    !jsonCopyStringItem(arrItem, "userAgent", &listClientHwidsObjArrStruct[i].userAgent) ||
                    !jsonCopyStringItem(arrItem, "deviceOs", &listClientHwidsObjArrStruct[i].deviceOs) ||
                    !jsonCopyStringItem(arrItem, "osVersion", &listClientHwidsObjArrStruct[i].osVersion) ||
                    !jsonCopyStringItem(arrItem, "deviceModel", &listClientHwidsObjArrStruct[i].deviceModel) ||
                    !jsonCopyStringItem(arrItem, "fingerprint", &listClientHwidsObjArrStruct[i].fingerprint)
                ) {
                    jsonListClientHwidsObjectArrayStructDelete(listClientHwidsObjArrStruct, arraySize);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }

            }

        }

        struct jsonListClientHwidsResponseStruct* listCliHwidsRStruct = (struct jsonListClientHwidsResponseStruct*)calloc(1, sizeof(struct jsonListClientHwidsResponseStruct));
        if (!listCliHwidsRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listCliHwidsRStruct is a null pointer");

            jsonListClientHwidsObjectArrayStructDelete(listClientHwidsObjArrStruct, arraySize);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        listCliHwidsRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &listCliHwidsRStruct->msg)) {
            jsonListClientHwidsResponseStructDelete(listCliHwidsRStruct);

            jsonListClientHwidsObjectArrayStructDelete(listClientHwidsObjArrStruct, arraySize);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        listCliHwidsRStruct->jsonListClientHwidsObjectArrayStructSize = arraySize;
        listCliHwidsRStruct->listClientHwidsObjArrStruct = listClientHwidsObjArrStruct;

        cJSON_Delete(jsonParser);

        return listCliHwidsRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonListClientHwidsResponseStruct* failRStruct = (struct jsonListClientHwidsResponseStruct*)calloc(1, sizeof(struct jsonListClientHwidsResponseStruct));
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

void jsonOnlinesByGuidObjectArrayStructDelete(struct jsonOnlinesByGuidObjectArrayStruct* onlinesByGuidObjArrStruct, size_t arraySize) {
    if (!onlinesByGuidObjArrStruct) {
        return;

    }

    for (size_t i = 0; i < arraySize; i++) {
        free((char*)onlinesByGuidObjArrStruct[i].panelGuid);
        jsonBulkStringArrayFree(onlinesByGuidObjArrStruct[i].emails, onlinesByGuidObjArrStruct[i].emailsCount);

    }

    free(onlinesByGuidObjArrStruct);

}

void jsonOnlinesByGuidResponseStructDelete(struct jsonOnlinesByGuidResponseStruct* onlinesByGuidRStruct) {
    if (!onlinesByGuidRStruct) {
        return;

    }

    free((char*)onlinesByGuidRStruct->msg);

    if (onlinesByGuidRStruct->onlinesByGuidObjArrStruct) {
        jsonOnlinesByGuidObjectArrayStructDelete(onlinesByGuidRStruct->onlinesByGuidObjArrStruct, onlinesByGuidRStruct->jsonOnlinesByGuidObjectArrayStructSize);
        onlinesByGuidRStruct->onlinesByGuidObjArrStruct = NULL;

    }

    free(onlinesByGuidRStruct);

}

struct jsonOnlinesByGuidResponseStruct* jsonOnlinesByGuidResponse(const char* json) {
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

        size_t arraySize = cJSON_GetArraySize(obj);
        struct jsonOnlinesByGuidObjectArrayStruct* onlinesByGuidObjArrStruct = NULL;
        if (arraySize) {
            onlinesByGuidObjArrStruct = (struct jsonOnlinesByGuidObjectArrayStruct*)calloc(arraySize, sizeof(struct jsonOnlinesByGuidObjectArrayStruct));
            if (!onlinesByGuidObjArrStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "onlinesByGuidObjArrStruct is a null pointer");

                cJSON_Delete(jsonParser);

                return NULL;

            }
            size_t i = 0;
            for (cJSON* child = obj->child; child; child = child->next, i++) {
                onlinesByGuidObjArrStruct[i].panelGuid = jsonCopyText(child->string);
                if (!onlinesByGuidObjArrStruct[i].panelGuid || (cJSON_IsArray(child) && !jsonBulkStringArrayParse(child, &onlinesByGuidObjArrStruct[i].emails, &onlinesByGuidObjArrStruct[i].emailsCount))) {
                    jsonOnlinesByGuidObjectArrayStructDelete(onlinesByGuidObjArrStruct, arraySize);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }

            }

        }

        struct jsonOnlinesByGuidResponseStruct* onlinesByGuidRStruct = (struct jsonOnlinesByGuidResponseStruct*)calloc(1, sizeof(struct jsonOnlinesByGuidResponseStruct));
        if (!onlinesByGuidRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "onlinesByGuidRStruct is a null pointer");

            jsonOnlinesByGuidObjectArrayStructDelete(onlinesByGuidObjArrStruct, arraySize);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        onlinesByGuidRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &onlinesByGuidRStruct->msg)) {
            jsonOnlinesByGuidResponseStructDelete(onlinesByGuidRStruct);

            jsonOnlinesByGuidObjectArrayStructDelete(onlinesByGuidObjArrStruct, arraySize);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        onlinesByGuidRStruct->jsonOnlinesByGuidObjectArrayStructSize = arraySize;
        onlinesByGuidRStruct->onlinesByGuidObjArrStruct = onlinesByGuidObjArrStruct;

        cJSON_Delete(jsonParser);

        return onlinesByGuidRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonOnlinesByGuidResponseStruct* failRStruct = (struct jsonOnlinesByGuidResponseStruct*)calloc(1, sizeof(struct jsonOnlinesByGuidResponseStruct));
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

void jsonClientIpsByGuidIpObjectArrayStructDelete(struct jsonClientIpsByGuidIpObjectArrayStruct* clientIpsByGuidIpObjArrStruct, size_t arraySize) {
    if (!clientIpsByGuidIpObjArrStruct) {
        return;

    }

    for (size_t i = 0; i < arraySize; i++) {
        free((char*)clientIpsByGuidIpObjArrStruct[i].ip);

    }

    free(clientIpsByGuidIpObjArrStruct);

}

void jsonClientIpsByGuidClientObjectArrayStructDelete(struct jsonClientIpsByGuidClientObjectArrayStruct* clientIpsByGuidCliObjArrStruct, size_t arraySize) {
    if (!clientIpsByGuidCliObjArrStruct) {
        return;

    }

    for (size_t i = 0; i < arraySize; i++) {
        free((char*)clientIpsByGuidCliObjArrStruct[i].email);
        jsonClientIpsByGuidIpObjectArrayStructDelete(clientIpsByGuidCliObjArrStruct[i].clientIpsByGuidIpObjArrStruct, clientIpsByGuidCliObjArrStruct[i].jsonClientIpsByGuidIpObjectArrayStructSize);

    }

    free(clientIpsByGuidCliObjArrStruct);

}

void jsonClientIpsByGuidObjectArrayStructDelete(struct jsonClientIpsByGuidObjectArrayStruct* clientIpsByGuidObjArrStruct, size_t arraySize) {
    if (!clientIpsByGuidObjArrStruct) {
        return;

    }

    for (size_t i = 0; i < arraySize; i++) {
        free((char*)clientIpsByGuidObjArrStruct[i].panelGuid);
        jsonClientIpsByGuidClientObjectArrayStructDelete(clientIpsByGuidObjArrStruct[i].clientIpsByGuidCliObjArrStruct, clientIpsByGuidObjArrStruct[i].jsonClientIpsByGuidClientObjectArrayStructSize);

    }

    free(clientIpsByGuidObjArrStruct);

}

void jsonClientIpsByGuidResponseStructDelete(struct jsonClientIpsByGuidResponseStruct* cliIpsByGuidRStruct) {
    if (!cliIpsByGuidRStruct) {
        return;

    }

    free((char*)cliIpsByGuidRStruct->msg);

    if (cliIpsByGuidRStruct->clientIpsByGuidObjArrStruct) {
        jsonClientIpsByGuidObjectArrayStructDelete(cliIpsByGuidRStruct->clientIpsByGuidObjArrStruct, cliIpsByGuidRStruct->jsonClientIpsByGuidObjectArrayStructSize);
        cliIpsByGuidRStruct->clientIpsByGuidObjArrStruct = NULL;

    }

    free(cliIpsByGuidRStruct);

}

static int jsonClientIpsByGuidIpParse(cJSON* clientItem, struct jsonClientIpsByGuidClientObjectArrayStruct* clientObjStruct) {
    clientObjStruct->jsonClientIpsByGuidIpObjectArrayStructSize = cJSON_GetArraySize(clientItem);
    if (!cJSON_IsArray(clientItem) || !clientObjStruct->jsonClientIpsByGuidIpObjectArrayStructSize) {
        return 1;

    }

    clientObjStruct->clientIpsByGuidIpObjArrStruct = (struct jsonClientIpsByGuidIpObjectArrayStruct*)calloc(clientObjStruct->jsonClientIpsByGuidIpObjectArrayStructSize, sizeof(struct jsonClientIpsByGuidIpObjectArrayStruct));
    if (!clientObjStruct->clientIpsByGuidIpObjArrStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "clientIpsByGuidIpObjArrStruct is a null pointer");

        return 0;

    }

    size_t i = 0;
    for (cJSON* ipItem = clientItem->child; ipItem; ipItem = ipItem->next, i++) {
        if (!cJSON_IsObject(ipItem)) {
            applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "IP element is not an object, skipping...");

            continue;

        }
        if (!jsonCopyStringItem(ipItem, "ip", &clientObjStruct->clientIpsByGuidIpObjArrStruct[i].ip)) {
            return 0;

        }
        if (cJSON_HasObjectItem(ipItem, "timestamp") && cJSON_IsNumber(cJSON_GetObjectItem(ipItem, "timestamp"))) {
            clientObjStruct->clientIpsByGuidIpObjArrStruct[i].timestamp = (int64_t)cJSON_GetObjectItem(ipItem, "timestamp")->valuedouble;

        }

    }

    return 1;

}

static int jsonClientIpsByGuidClientParse(cJSON* guidItem, struct jsonClientIpsByGuidObjectArrayStruct* guidObjStruct) {
    guidObjStruct->jsonClientIpsByGuidClientObjectArrayStructSize = cJSON_GetArraySize(guidItem);
    if (!guidObjStruct->jsonClientIpsByGuidClientObjectArrayStructSize) {
        return 1;

    }

    guidObjStruct->clientIpsByGuidCliObjArrStruct = (struct jsonClientIpsByGuidClientObjectArrayStruct*)calloc(guidObjStruct->jsonClientIpsByGuidClientObjectArrayStructSize, sizeof(struct jsonClientIpsByGuidClientObjectArrayStruct));
    if (!guidObjStruct->clientIpsByGuidCliObjArrStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "clientIpsByGuidCliObjArrStruct is a null pointer");

        return 0;

    }

    size_t i = 0;
    for (cJSON* clientItem = guidItem->child; clientItem; clientItem = clientItem->next, i++) {
        struct jsonClientIpsByGuidClientObjectArrayStruct* clientObjStruct = &guidObjStruct->clientIpsByGuidCliObjArrStruct[i];
        clientObjStruct->email = jsonCopyText(clientItem->string);
        if (!clientObjStruct->email || !jsonClientIpsByGuidIpParse(clientItem, clientObjStruct)) {
            return 0;

        }

    }

    return 1;

}

struct jsonClientIpsByGuidResponseStruct* jsonClientIpsByGuidResponse(const char* json) {
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

        size_t arraySize = cJSON_GetArraySize(obj);
        struct jsonClientIpsByGuidObjectArrayStruct* clientIpsByGuidObjArrStruct = NULL;
        if (arraySize) {
            clientIpsByGuidObjArrStruct = (struct jsonClientIpsByGuidObjectArrayStruct*)calloc(arraySize, sizeof(struct jsonClientIpsByGuidObjectArrayStruct));
            if (!clientIpsByGuidObjArrStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "clientIpsByGuidObjArrStruct is a null pointer");

                cJSON_Delete(jsonParser);

                return NULL;

            }
            size_t i = 0;
            for (cJSON* guidItem = obj->child; guidItem; guidItem = guidItem->next, i++) {
                clientIpsByGuidObjArrStruct[i].panelGuid = jsonCopyText(guidItem->string);
                if (!clientIpsByGuidObjArrStruct[i].panelGuid || !jsonClientIpsByGuidClientParse(guidItem, &clientIpsByGuidObjArrStruct[i])) {
                    jsonClientIpsByGuidObjectArrayStructDelete(clientIpsByGuidObjArrStruct, arraySize);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }

            }

        }

        struct jsonClientIpsByGuidResponseStruct* cliIpsByGuidRStruct = (struct jsonClientIpsByGuidResponseStruct*)calloc(1, sizeof(struct jsonClientIpsByGuidResponseStruct));
        if (!cliIpsByGuidRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "cliIpsByGuidRStruct is a null pointer");

            jsonClientIpsByGuidObjectArrayStructDelete(clientIpsByGuidObjArrStruct, arraySize);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        cliIpsByGuidRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &cliIpsByGuidRStruct->msg)) {
            jsonClientIpsByGuidResponseStructDelete(cliIpsByGuidRStruct);

            jsonClientIpsByGuidObjectArrayStructDelete(clientIpsByGuidObjArrStruct, arraySize);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        cliIpsByGuidRStruct->jsonClientIpsByGuidObjectArrayStructSize = arraySize;
        cliIpsByGuidRStruct->clientIpsByGuidObjArrStruct = clientIpsByGuidObjArrStruct;

        cJSON_Delete(jsonParser);

        return cliIpsByGuidRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonClientIpsByGuidResponseStruct* failRStruct = (struct jsonClientIpsByGuidResponseStruct*)calloc(1, sizeof(struct jsonClientIpsByGuidResponseStruct));
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

void jsonActiveInboundsObjectArrayStructDelete(struct jsonActiveInboundsObjectArrayStruct* activeInboundsObjArrStruct, size_t arraySize) {
    if (!activeInboundsObjArrStruct) {
        return;

    }

    for (size_t i = 0; i < arraySize; i++) {
        free((char*)activeInboundsObjArrStruct[i].panelGuid);
        jsonBulkStringArrayFree(activeInboundsObjArrStruct[i].tags, activeInboundsObjArrStruct[i].tagsCount);

    }

    free(activeInboundsObjArrStruct);

}

void jsonActiveInboundsResponseStructDelete(struct jsonActiveInboundsResponseStruct* activeInboundsRStruct) {
    if (!activeInboundsRStruct) {
        return;

    }

    free((char*)activeInboundsRStruct->msg);

    if (activeInboundsRStruct->activeInboundsObjArrStruct) {
        jsonActiveInboundsObjectArrayStructDelete(activeInboundsRStruct->activeInboundsObjArrStruct, activeInboundsRStruct->jsonActiveInboundsObjectArrayStructSize);
        activeInboundsRStruct->activeInboundsObjArrStruct = NULL;

    }

    free(activeInboundsRStruct);

}

struct jsonActiveInboundsResponseStruct* jsonActiveInboundsResponse(const char* json) {
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

        size_t arraySize = cJSON_GetArraySize(obj);
        struct jsonActiveInboundsObjectArrayStruct* activeInboundsObjArrStruct = NULL;
        if (arraySize) {
            activeInboundsObjArrStruct = (struct jsonActiveInboundsObjectArrayStruct*)calloc(arraySize, sizeof(struct jsonActiveInboundsObjectArrayStruct));
            if (!activeInboundsObjArrStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "activeInboundsObjArrStruct is a null pointer");

                cJSON_Delete(jsonParser);

                return NULL;

            }
            size_t i = 0;
            for (cJSON* child = obj->child; child; child = child->next, i++) {
                activeInboundsObjArrStruct[i].panelGuid = jsonCopyText(child->string);
                if (!activeInboundsObjArrStruct[i].panelGuid || (cJSON_IsArray(child) && !jsonBulkStringArrayParse(child, &activeInboundsObjArrStruct[i].tags, &activeInboundsObjArrStruct[i].tagsCount))) {
                    jsonActiveInboundsObjectArrayStructDelete(activeInboundsObjArrStruct, arraySize);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }

            }

        }

        struct jsonActiveInboundsResponseStruct* activeInboundsRStruct = (struct jsonActiveInboundsResponseStruct*)calloc(1, sizeof(struct jsonActiveInboundsResponseStruct));
        if (!activeInboundsRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "activeInboundsRStruct is a null pointer");

            jsonActiveInboundsObjectArrayStructDelete(activeInboundsObjArrStruct, arraySize);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        activeInboundsRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &activeInboundsRStruct->msg)) {
            jsonActiveInboundsResponseStructDelete(activeInboundsRStruct);

            jsonActiveInboundsObjectArrayStructDelete(activeInboundsObjArrStruct, arraySize);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        activeInboundsRStruct->jsonActiveInboundsObjectArrayStructSize = arraySize;
        activeInboundsRStruct->activeInboundsObjArrStruct = activeInboundsObjArrStruct;

        cJSON_Delete(jsonParser);

        return activeInboundsRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonActiveInboundsResponseStruct* failRStruct = (struct jsonActiveInboundsResponseStruct*)calloc(1, sizeof(struct jsonActiveInboundsResponseStruct));
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

void jsonLastOnlineObjectArrayStructDelete(struct jsonLastOnlineObjectArrayStruct* lastOnlineObjArrStruct, size_t arraySize) {
    if (!lastOnlineObjArrStruct) {
        return;

    }

    for (size_t i = 0; i < arraySize; i++) {
        free((char*)lastOnlineObjArrStruct[i].email);

    }

    free(lastOnlineObjArrStruct);

}

void jsonLastOnlineResponseStructDelete(struct jsonLastOnlineResponseStruct* lastOnlineRStruct) {
    if (!lastOnlineRStruct) {
        return;

    }

    free((char*)lastOnlineRStruct->msg);

    if (lastOnlineRStruct->lastOnlineObjArrStruct) {
        jsonLastOnlineObjectArrayStructDelete(lastOnlineRStruct->lastOnlineObjArrStruct, lastOnlineRStruct->jsonLastOnlineObjectArrayStructSize);
        lastOnlineRStruct->lastOnlineObjArrStruct = NULL;

    }

    free(lastOnlineRStruct);

}

struct jsonLastOnlineResponseStruct* jsonLastOnlineResponse(const char* json) {
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

        size_t arraySize = cJSON_GetArraySize(obj);
        struct jsonLastOnlineObjectArrayStruct* lastOnlineObjArrStruct = NULL;
        if (arraySize) {
            lastOnlineObjArrStruct = (struct jsonLastOnlineObjectArrayStruct*)calloc(arraySize, sizeof(struct jsonLastOnlineObjectArrayStruct));
            if (!lastOnlineObjArrStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "lastOnlineObjArrStruct is a null pointer");

                cJSON_Delete(jsonParser);

                return NULL;

            }
            size_t i = 0;
            for (cJSON* child = obj->child; child; child = child->next, i++) {
                lastOnlineObjArrStruct[i].email = jsonCopyText(child->string);
                if (!lastOnlineObjArrStruct[i].email) {
                    jsonLastOnlineObjectArrayStructDelete(lastOnlineObjArrStruct, arraySize);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }
                if (cJSON_IsNumber(child)) {
                    lastOnlineObjArrStruct[i].lastOnline = (int64_t)child->valuedouble;

                }

            }

        }

        struct jsonLastOnlineResponseStruct* lastOnlineRStruct = (struct jsonLastOnlineResponseStruct*)calloc(1, sizeof(struct jsonLastOnlineResponseStruct));
        if (!lastOnlineRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "lastOnlineRStruct is a null pointer");

            jsonLastOnlineObjectArrayStructDelete(lastOnlineObjArrStruct, arraySize);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        lastOnlineRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &lastOnlineRStruct->msg)) {
            jsonLastOnlineResponseStructDelete(lastOnlineRStruct);

            jsonLastOnlineObjectArrayStructDelete(lastOnlineObjArrStruct, arraySize);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        lastOnlineRStruct->jsonLastOnlineObjectArrayStructSize = arraySize;
        lastOnlineRStruct->lastOnlineObjArrStruct = lastOnlineObjArrStruct;

        cJSON_Delete(jsonParser);

        return lastOnlineRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonLastOnlineResponseStruct* failRStruct = (struct jsonLastOnlineResponseStruct*)calloc(1, sizeof(struct jsonLastOnlineResponseStruct));
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

void jsonHappLinkObjectStructDelete(struct jsonHappLinkObjectStruct* happLinkObjStruct) {
    if (!happLinkObjStruct) {
        return;

    }

    free((char*)happLinkObjStruct->encryptedLink);
    free(happLinkObjStruct);

}

void jsonHappLinkResponseStructDelete(struct jsonHappLinkResponseStruct* happLinkRStruct) {
    if (!happLinkRStruct) {
        return;

    }

    free((char*)happLinkRStruct->msg);

    if (happLinkRStruct->happLinkObjStruct) {
        jsonHappLinkObjectStructDelete(happLinkRStruct->happLinkObjStruct);
        happLinkRStruct->happLinkObjStruct = NULL;

    }

    free(happLinkRStruct);

}

struct jsonHappLinkResponseStruct* jsonHappLinkResponse(const char* json) {
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

        struct jsonHappLinkObjectStruct* happLinkObjStruct = (struct jsonHappLinkObjectStruct*)calloc(1, sizeof(struct jsonHappLinkObjectStruct));
        if (!happLinkObjStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "happLinkObjStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (!jsonCopyStringItem(obj, "encryptedLink", &happLinkObjStruct->encryptedLink)) {
            jsonHappLinkObjectStructDelete(happLinkObjStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        struct jsonHappLinkResponseStruct* happLinkRStruct = (struct jsonHappLinkResponseStruct*)calloc(1, sizeof(struct jsonHappLinkResponseStruct));
        if (!happLinkRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "happLinkRStruct is a null pointer");

            jsonHappLinkObjectStructDelete(happLinkObjStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        happLinkRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &happLinkRStruct->msg)) {
            jsonHappLinkResponseStructDelete(happLinkRStruct);

            jsonHappLinkObjectStructDelete(happLinkObjStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        happLinkRStruct->happLinkObjStruct = happLinkObjStruct;

        cJSON_Delete(jsonParser);

        return happLinkRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonHappLinkResponseStruct* failRStruct = (struct jsonHappLinkResponseStruct*)calloc(1, sizeof(struct jsonHappLinkResponseStruct));
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

void jsonRenewalPreviewPostStructDelete(struct jsonRenewalPreviewPostStruct* renewalPreviewPostStruct) {
    if (!renewalPreviewPostStruct) {
        return;

    }

    free(renewalPreviewPostStruct);

}

const char* jsonRenewalPreviewPost(struct jsonRenewalPreviewPostStruct* renewalPreviewPostStruct) {
    if (!renewalPreviewPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "renewalPreviewPostStruct is a null pointer");

        return NULL;

    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");

        return NULL;

    }

    cJSON_AddNumberToObject(json, "expiryTime", (double)renewalPreviewPostStruct->expiryTime);
    cJSON_AddNumberToObject(json, "reset", renewalPreviewPostStruct->reset);
    cJSON_AddNumberToObject(json, "resetDay", renewalPreviewPostStruct->resetDay);
    cJSON_AddNumberToObject(json, "resetWeekday", renewalPreviewPostStruct->resetWeekday);
    cJSON_AddNumberToObject(json, "resetMax", renewalPreviewPostStruct->resetMax);
    cJSON_AddNumberToObject(json, "resetCount", renewalPreviewPostStruct->resetCount);

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");

        return NULL;

    }

    return jsonString;

}

void jsonRenewalPreviewObjectStructDelete(struct jsonRenewalPreviewObjectStruct* renewalPreviewObjStruct) {
    if (!renewalPreviewObjStruct) {
        return;

    }

    free((char*)renewalPreviewObjStruct->nextExpiry);
    free((char*)renewalPreviewObjStruct->renewAt);
    free((char*)renewalPreviewObjStruct->suggestedExpiry);
    free((char*)renewalPreviewObjStruct->timeZone);
    free((char*)renewalPreviewObjStruct->validThrough);
    free(renewalPreviewObjStruct);

}

void jsonRenewalPreviewResponseStructDelete(struct jsonRenewalPreviewResponseStruct* renewalPreviewRStruct) {
    if (!renewalPreviewRStruct) {
        return;

    }

    free((char*)renewalPreviewRStruct->msg);

    if (renewalPreviewRStruct->renewalPreviewObjStruct) {
        jsonRenewalPreviewObjectStructDelete(renewalPreviewRStruct->renewalPreviewObjStruct);
        renewalPreviewRStruct->renewalPreviewObjStruct = NULL;

    }

    free(renewalPreviewRStruct);

}

struct jsonRenewalPreviewResponseStruct* jsonRenewalPreviewResponse(const char* json) {
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

        struct jsonRenewalPreviewObjectStruct* renewalPreviewObjStruct = (struct jsonRenewalPreviewObjectStruct*)calloc(1, sizeof(struct jsonRenewalPreviewObjectStruct));
        if (!renewalPreviewObjStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "renewalPreviewObjStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (cJSON_HasObjectItem(obj, "canRenew") && cJSON_IsBool(cJSON_GetObjectItem(obj, "canRenew"))) {
            renewalPreviewObjStruct->canRenew = cJSON_IsTrue(cJSON_GetObjectItem(obj, "canRenew")) ? 1 : 0;

        }

        if (cJSON_HasObjectItem(obj, "delayedStart") && cJSON_IsBool(cJSON_GetObjectItem(obj, "delayedStart"))) {
            renewalPreviewObjStruct->delayedStart = cJSON_IsTrue(cJSON_GetObjectItem(obj, "delayedStart")) ? 1 : 0;

        }

        if (
            !jsonCopyStringItem(obj, "nextExpiry", &renewalPreviewObjStruct->nextExpiry) ||
            !jsonCopyStringItem(obj, "renewAt", &renewalPreviewObjStruct->renewAt) ||
            !jsonCopyStringItem(obj, "suggestedExpiry", &renewalPreviewObjStruct->suggestedExpiry) ||
            !jsonCopyStringItem(obj, "timeZone", &renewalPreviewObjStruct->timeZone) ||
            !jsonCopyStringItem(obj, "validThrough", &renewalPreviewObjStruct->validThrough)
        ) {
            jsonRenewalPreviewObjectStructDelete(renewalPreviewObjStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        if (cJSON_HasObjectItem(obj, "renewals") && cJSON_IsNumber(cJSON_GetObjectItem(obj, "renewals"))) {
            renewalPreviewObjStruct->renewals = (int)cJSON_GetObjectItem(obj, "renewals")->valuedouble;

        }

        if (cJSON_HasObjectItem(obj, "suggestedExpiryTime") && cJSON_IsNumber(cJSON_GetObjectItem(obj, "suggestedExpiryTime"))) {
            renewalPreviewObjStruct->suggestedExpiryTime = (int64_t)cJSON_GetObjectItem(obj, "suggestedExpiryTime")->valuedouble;

        }

        struct jsonRenewalPreviewResponseStruct* renewalPreviewRStruct = (struct jsonRenewalPreviewResponseStruct*)calloc(1, sizeof(struct jsonRenewalPreviewResponseStruct));
        if (!renewalPreviewRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "renewalPreviewRStruct is a null pointer");

            jsonRenewalPreviewObjectStructDelete(renewalPreviewObjStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        renewalPreviewRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &renewalPreviewRStruct->msg)) {
            jsonRenewalPreviewResponseStructDelete(renewalPreviewRStruct);

            jsonRenewalPreviewObjectStructDelete(renewalPreviewObjStruct);

            cJSON_Delete(jsonParser);

            return NULL;

        }

        renewalPreviewRStruct->renewalPreviewObjStruct = renewalPreviewObjStruct;

        cJSON_Delete(jsonParser);

        return renewalPreviewRStruct;

    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonRenewalPreviewResponseStruct* failRStruct = (struct jsonRenewalPreviewResponseStruct*)calloc(1, sizeof(struct jsonRenewalPreviewResponseStruct));
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
