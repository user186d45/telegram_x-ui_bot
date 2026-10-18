#include "../../include/cjson/clients.h"
#include "../../include/cjson/jsonValidation.h"
#include "../../include/log.h"

#include <cjson/cJSON.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

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
        if (!obj) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "obj is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        struct jsonDeleteAllDepletedClientsResponseStruct* deleteAllDepletedCliRStruct = (struct jsonDeleteAllDepletedClientsResponseStruct*)malloc(sizeof(struct jsonDeleteAllDepletedClientsResponseStruct));
        if (!deleteAllDepletedCliRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "deleteAllDepletedCliRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        // Note: success is unsigned char* in the struct (pointer)
        deleteAllDepletedCliRStruct->success = (unsigned char*)malloc(sizeof(unsigned char));
        if (deleteAllDepletedCliRStruct->success) {
            *deleteAllDepletedCliRStruct->success = 1;
        }

        if (cJSON_HasObjectItem(obj, "deleted") && cJSON_IsNumber(cJSON_GetObjectItem(obj, "deleted"))) {
            deleteAllDepletedCliRStruct->deleted = (int64_t)cJSON_GetObjectItem(obj, "deleted")->valuedouble;
        }

        cJSON_Delete(jsonParser);
        return deleteAllDepletedCliRStruct;
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
        if (!obj) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "obj is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        struct jsonDeleteAllOrphanClientsResponseStruct* deleteAllOrphanCliRStruct = (struct jsonDeleteAllOrphanClientsResponseStruct*)malloc(sizeof(struct jsonDeleteAllOrphanClientsResponseStruct));
        if (!deleteAllOrphanCliRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "deleteAllOrphanCliRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        deleteAllOrphanCliRStruct->success = (unsigned char*)malloc(sizeof(unsigned char));
        if (deleteAllOrphanCliRStruct->success) {
            *deleteAllOrphanCliRStruct->success = 1;
        }

        if (cJSON_HasObjectItem(obj, "deleted") && cJSON_IsNumber(cJSON_GetObjectItem(obj, "deleted"))) {
            deleteAllOrphanCliRStruct->deleted = (int64_t)cJSON_GetObjectItem(obj, "deleted")->valuedouble;
        }

        cJSON_Delete(jsonParser);
        return deleteAllOrphanCliRStruct;
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

        exportAllCliRStruct->jsonExportAllClientsObjectArrayResponseStructSize = arraySize;
        exportAllCliRStruct->exportAllClisObjArrRStruct = exportAllClisObjArrRStruct;

        cJSON_Delete(jsonParser);
        return exportAllCliRStruct;
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
        free((char*)importClientsDataObjPStruct[i].comment);
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

    if (importClientsPostStruct->jsonImportClientsDataObjectPostStructSize > 0 && importClientsPostStruct->importClientsDataObjPStruct) {
        for (size_t i = 0; i < importClientsPostStruct->jsonImportClientsDataObjectPostStructSize; i++) {
            struct jsonImportClientsDataObjectPostStruct* client = &importClientsPostStruct->importClientsDataObjPStruct[i];
            cJSON* clientObj = cJSON_CreateObject();
            if (!clientObj) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "clientObj is a null pointer, failed to create json object");
                cJSON_Delete(json);
                return NULL;
            }
            cJSON_AddItemToArray(dataArray, clientObj);

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

        importCliRStruct->importClisObjRStruct = importClisObjRStruct;

        cJSON_Delete(jsonParser);
        return importCliRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}
