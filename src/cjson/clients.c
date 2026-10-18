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

    if (cJSON_HasObjectItem(arrItem, "allowedIps") && cJSON_IsString(cJSON_GetObjectItem(arrItem, "allowedIps"))) {
        size_t allowedIpsLen = strlen(cJSON_GetObjectItem(arrItem, "allowedIps")->valuestring);
        char* allowedIpsCopy = (char*)malloc((allowedIpsLen + 1) * sizeof(char));
        if (!allowedIpsCopy) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "allowedIps is a null pointer, failed to allocate memory");

            return 0;

        }
        strncpy(allowedIpsCopy, cJSON_GetObjectItem(arrItem, "allowedIps")->valuestring, allowedIpsLen);
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
