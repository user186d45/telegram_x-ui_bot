#include "../include/cjson.h"
#include "../include/log.h"

#include <cjson/cJSON.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

static unsigned char isJsonValid(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (json == NULL) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is nullptr");

        return 0;

    }
    
    const char* ptrErr = NULL;
    cJSON* j = cJSON_ParseWithOpts(json, &ptrErr, 1);
    if (j == NULL) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Parsing failed, printing error location");

        size_t errOffset = ptrErr - json;

        size_t startOffset = (errOffset > 10) ? errOffset - 10 : 0;
        size_t offsetLen = (errOffset + 10ULL < strlen(json)) ? 10 : strlen(json) - startOffset;
        char errMsg[1024];
        sprintf(
            errMsg,
            "Error occurred on parsing the json configuration file, the error occurred on:\n%.*s\nexiting...\n",
            (int)offsetLen,
            json + startOffset
        );

        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, errMsg);

        return 0;

    }

    cJSON_Delete(j);

    return 1;

}

void jsonListInboundClientStatsArrayStructDelete(struct jsonListInboundClientStatsArrayStruct* listInCliStatsStruct, size_t arraySize) {
    for (size_t i = 0; i < arraySize; i++) {
        free((char*)listInCliStatsStruct[i].email);
        free((char*)listInCliStatsStruct[i].uuid);
        free((char*)listInCliStatsStruct[i].subId);

    }

}

void jsonListInboundSettingsObjectStructDelete(struct jsonListInboundSettingsObjectStruct* listInSettingsObjStruct) {
    if (listInSettingsObjStruct->listInSettingsCliArrStruct) {
        for (size_t i = 0; i < listInSettingsObjStruct->jsonListInboundSettingsClientsArrayStructSize; i++) {
            free((char*)listInSettingsObjStruct->listInSettingsCliArrStruct[i].auth);
            free((char*)listInSettingsObjStruct->listInSettingsCliArrStruct[i].comment);
            free((char*)listInSettingsObjStruct->listInSettingsCliArrStruct[i].email);
            free((char*)listInSettingsObjStruct->listInSettingsCliArrStruct[i].id);
            free((char*)listInSettingsObjStruct->listInSettingsCliArrStruct[i].password);
            free((char*)listInSettingsObjStruct->listInSettingsCliArrStruct[i].security);
            free((char*)listInSettingsObjStruct->listInSettingsCliArrStruct[i].subId);
    
        }

    }

    free((char*)listInSettingsObjStruct->decryption);
    free((char*)listInSettingsObjStruct->encryption);

}

void jsonListInboundStreamSettingsObjectStructDelete(struct jsonListInboundStreamSettingsObjectStruct* listInStreamSettingsObjStruct) {
    free((char*)listInStreamSettingsObjStruct->network);

    if (listInStreamSettingsObjStruct->listInStreamSettingsTcpSettingsObjStruct) {
        jsonListInboundStreamSettingsTcpSettingsObjectStructDelete(listInStreamSettingsObjStruct->listInStreamSettingsTcpSettingsObjStruct);

    }

}

void jsonListInboundSniffingObjectStructDelete(struct jsonListInboundSniffingObjectStruct* listInSniffingObjStruct) {
    free((char*)listInSniffingObjStruct->enabled);

}

void jsonListInboundObjectStructDelete(struct jsonListInboundObjectStruct* listInObjStruct, size_t arraySize) {
    for (size_t i = 0; i < arraySize; i++) {
        free((char*)listInObjStruct[i].remark);
        free((char*) listInObjStruct[i].trafficReset);

        if (listInObjStruct[i].listInCliStatsStruct) {
            jsonListInboundClientStatsArrayStructDelete(listInObjStruct[i].listInCliStatsStruct, listInObjStruct[i].jsonListInboundClientStatsArrayStructSize);

        }

        free((char*)listInObjStruct[i].listen);
        free((char*)listInObjStruct[i].protocol);
        free((char*)listInObjStruct[i].tag);
        free((char*)listInObjStruct[i].shareAddrStrategy);
        free((char*)listInObjStruct[i].shareAddr);
        free((char*)listInObjStruct[i].originNodeGuid);
        
        if (listInObjStruct[i].listInSettingsObjStruct) {
            jsonListInboundSettingsObjectStructDelete(listInObjStruct[i].listInSettingsObjStruct);

        }

        if (listInObjStruct[i].listInStreamSettingsObjStruct) {
            jsonListInboundStreamSettingsObjectStructDelete(listInObjStruct[i].listInStreamSettingsObjStruct);

        }

        if (listInObjStruct[i].listInSniffingObjStruct) {
            jsonListInboundSniffingObjectStructDelete(listInObjStruct[i].listInSniffingObjStruct);

        }

    }

}

void jsonListInboundStructDelete(struct jsonListInboundStruct* listInStruct) {
    free((char*)listInStruct->msg);

    if (listInStruct->listInObjStruct) {
        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, listInStruct->jsonListInboundObjectStructSize);

    }

}

struct jsonListInboundClientStatsArrayStruct* jsonListInboundClientStatsArray(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!isJsonValid(json)) {
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
        cJSON* arrayObj = cJSON_GetObjectItem(jsonParser, "obj");
        if (!arrayObj) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "arrayObj is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        size_t arraySize = cJSON_GetArraySize(arrayObj);
        if (!arraySize) {
            applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "arraySize is zero, returning");

            cJSON_Delete(jsonParser);

            return NULL;


        }

        struct jsonListInboundClientStatsArrayStruct* listInCliStatsArrStruct = (struct jsonListInboundClientStatsArrayStruct*)malloc(arraySize * sizeof(struct jsonListInboundClientStatsArrayStruct));
        if (!listInCliStatsArrStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInCliStatsArrStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        for (size_t i = 0; i < arraySize; i++) {
            cJSON* arrItem = cJSON_GetArrayItem(arrayObj, i);
            if (
                cJSON_HasObjectItem(arrItem, "id") &&
                cJSON_HasObjectItem(arrItem, "inboundId") &&
                cJSON_HasObjectItem(arrItem, "enable") &&
                cJSON_HasObjectItem(arrItem, "email") &&
                cJSON_HasObjectItem(arrItem, "uuid") &&
                cJSON_HasObjectItem(arrItem, "subId") &&
                cJSON_HasObjectItem(arrItem, "up") &&
                cJSON_HasObjectItem(arrItem, "down") &&
                cJSON_HasObjectItem(arrItem, "expiryTime") &&
                cJSON_HasObjectItem(arrItem, "total") &&
                cJSON_HasObjectItem(arrItem, "reset") &&
                cJSON_HasObjectItem(arrItem, "lastOnline")
               ) {
                listInCliStatsArrStruct[i].id = (int64_t)cJSON_GetObjectItem(arrItem, "id")->valuedouble;
                listInCliStatsArrStruct[i].inboundId = (int64_t)cJSON_GetObjectItem(arrItem, "inboundId")->valuedouble;
                listInCliStatsArrStruct[i].enable = (unsigned char)cJSON_GetObjectItem(arrItem, "enable")->valueint;

                char* email = cJSON_GetObjectItem(arrItem, "email")->valuestring;
                size_t emailLen = strlen(email);
                char* emailCopy = (char*)malloc((emailLen + 1) * sizeof(char));
                strncpy(emailCopy, email, emailLen);
                emailCopy[emailLen + 1] = '\0';
                listInCliStatsArrStruct[i].email = emailCopy;

                char* uuid = cJSON_GetObjectItem(arrItem, "uuid")->valuestring;
                size_t uuidLen = strlen(uuid);
                char* uuidCopy = (char*)malloc((uuidLen + 1) * sizeof(char));
                strncpy(uuidCopy, uuid, uuidLen);
                uuidCopy[uuidLen + 1] = '\0';
                listInCliStatsArrStruct[i].uuid = uuidCopy;

                char* subId = cJSON_GetObjectItem(arrItem, "subId")->valuestring;
                size_t subIdLen = strlen(subId);
                char* subIdCopy = (char*)malloc((subIdLen + 1) * sizeof(char));
                strncpy(subIdCopy, subId, subIdLen);
                subIdCopy[subIdLen + 1] = '\0';
                listInCliStatsArrStruct[i].subId = subIdCopy;

                listInCliStatsArrStruct[i].up = (int64_t)cJSON_GetObjectItem(arrItem, "up")->valuedouble;
                listInCliStatsArrStruct[i].down = (int64_t)cJSON_GetObjectItem(arrItem, "down")->valuedouble;
                listInCliStatsArrStruct[i].expiryTime = (int64_t)cJSON_GetObjectItem(arrItem, "expiryTime")->valuedouble;

            } else {
                applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Some item is not present in the array elelement, skipping the element...");


            }

        }

        cJSON_Delete(jsonParser);

        return listInCliStatsArrStruct;

    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");

        cJSON_Delete(jsonParser);

        return NULL;

    }

}

struct jsonListInboundStruct* jsonListInbound(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!isJsonValid(json)) {
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
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsArray(cJSON_GetObjectItem(jsonParser, "obj"))
       ) {
        struct jsonListInboundStruct* listInStruct = (struct jsonListInboundStruct*)malloc(sizeof(struct jsonListInboundStruct));
        if (!listInStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return NULL;

        }

        listInStruct->success = 1;

        char* msg = cJSON_GetObjectItem(jsonParser, "msg")->valuestring;
        size_t msgLen = strlen(msg);
        char* msgCopy = (char*)malloc((msgLen + 1) * sizeof(char));
        strncpy(msgCopy, msg, msgLen);
        msgCopy[msgLen + 1] = '\0';
        listInStruct->msg = msgCopy;

        cJSON* arrayObj = cJSON_GetObjectItem(jsonParser, "obj");
        if (!arrayObj) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "arrayObj is a null pointer");

            cJSON_Delete(jsonParser);

            return listInStruct;

        }

        listInStruct->jsonListInboundObjectStructSize = cJSON_GetArraySize(arrayObj);
        if (!listInStruct->jsonListInboundObjectStructSize) {
            applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "jsonListInboundObjectStructSize is zero, returning");

            cJSON_Delete(jsonParser);

            return listInStruct;


        }

        listInStruct->listInObjStruct = (struct jsonListInboundObjectStruct*)malloc(listInStruct->jsonListInboundObjectStructSize * sizeof(struct jsonListInboundObjectStruct));
        if (!listInStruct->listInObjStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStruct->listInObjStruct is a null pointer");

            cJSON_Delete(jsonParser);

            return listInStruct;

        }

        for (size_t i = 0; i < listInStruct->jsonListInboundObjectStructSize; i++) {
            cJSON* arrItem = cJSON_GetArrayItem(arrayObj, i);

            if (
                cJSON_HasObjectItem(arrItem, "id") &&
                cJSON_HasObjectItem(arrItem, "up") &&
                cJSON_HasObjectItem(arrItem, "down") &&
                cJSON_HasObjectItem(arrItem, "total") &&
                cJSON_HasObjectItem(arrItem, "remark") &&
                cJSON_HasObjectItem(arrItem, "subSortIndex") &&
                cJSON_HasObjectItem(arrItem, "enable") &&
                cJSON_HasObjectItem(arrItem, "expiryTime") &&
                cJSON_HasObjectItem(arrItem, "trafficReset") &&
                cJSON_HasObjectItem(arrItem, "trafficResetDay") &&
                cJSON_HasObjectItem(arrItem, "lastTrafficResetTime") &&
                cJSON_HasObjectItem(arrItem, "listInCliStatsStruct") &&
                cJSON_IsArray(cJSON_GetObjectItem(arrItem, "clientStats")) &&
                cJSON_HasObjectItem(arrItem, "listen") &&
                cJSON_HasObjectItem(arrItem, "port") &&
                cJSON_HasObjectItem(arrItem, "protocol") &&
                cJSON_HasObjectItem(arrItem, "tag") &&
                cJSON_HasObjectItem(arrItem, "shareAddrStrategy") &&
                cJSON_HasObjectItem(arrItem, "shareAddr") &&
                cJSON_HasObjectItem(arrItem, "originNodeGuid") &&
                cJSON_HasObjectItem(arrItem, "settings") &&
                cJSON_IsObject(cJSON_GetObjectItem(arrItem, "settings")) &&
                cJSON_HasObjectItem(arrItem, "streamSettings") &&
                cJSON_IsObject(cJSON_GetObjectItem(arrItem, "streamSettings")) &&
                cJSON_HasObjectItem(arrItem, "sniffing") &&
                cJSON_IsObject(cJSON_GetObjectItem(arrItem, "sniffing"))
               ) {
                listInStruct->listInObjStruct[i].id = (int64_t)cJSON_GetObjectItem(arrItem, "id")->valuedouble;
                listInStruct->listInObjStruct[i].up = (int64_t)cJSON_GetObjectItem(arrItem, "up")->valuedouble;
                listInStruct->listInObjStruct[i].down = (int64_t)cJSON_GetObjectItem(arrItem, "down")->valuedouble;
                listInStruct->listInObjStruct[i].total = (int64_t)cJSON_GetObjectItem(arrItem, "total")->valuedouble;

                char* remark = cJSON_GetObjectItem(arrItem, "remark")->valuestring;
                size_t remarkLen = strlen(remark);
                char* remarkCopy = (char*)malloc((remarkLen + 1) * sizeof(char));
                strncpy(remarkCopy, remark, remarkLen);
                remarkCopy[remarkLen + 1] = '\0';
                listInStruct->listInObjStruct[i].remark = remarkCopy;

                listInStruct->listInObjStruct[i].subSortIndex = cJSON_GetObjectItem(arrItem, "subSortIndex")->valueint;
                listInStruct->listInObjStruct[i].enable = (unsigned char)cJSON_GetObjectItem(arrItem, "enable")->valueint;
                listInStruct->listInObjStruct[i].expiryTime = (int64_t)cJSON_GetObjectItem(arrItem, "expiryTime")->valuedouble;

                char* trafficReset = cJSON_GetObjectItem(arrItem, "trafficReset")->valuestring;
                size_t trafficResetLen = strlen(trafficReset);
                char* trafficResetCopy = (char*)malloc((trafficResetLen + 1) * sizeof(char));
                strncpy(trafficResetCopy, trafficReset, trafficResetLen);
                trafficResetCopy[trafficResetLen + 1] = '\0';
                listInStruct->listInObjStruct[i].trafficReset = trafficResetCopy;

                listInStruct->listInObjStruct[i].trafficResetDay = cJSON_GetObjectItem(arrItem, "trafficResetDay")->valueint;
                listInStruct->listInObjStruct[i].lastTrafficResetTime = (int64_t)cJSON_GetObjectItem(arrItem, "lastTrafficResetTime")->valuedouble;

                cJSON* clientStatsArray = cJSON_GetObjectItem(jsonParser, "clientStats");
                listInStruct->listInObjStruct[i].jsonListInboundClientStatsArrayStructSize = cJSON_GetArraySize(clientStatsArray);
                if (!listInStruct->listInObjStruct[i].jsonListInboundClientStatsArrayStructSize) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "clientStatsArray is empty");

                } else {
                    listInStruct->listInObjStruct[i].listInCliStatsStruct = (struct jsonListInboundClientStatsArrayStruct*)malloc(listInStruct->listInObjStruct[i].jsonListInboundClientStatsArrayStructSize * sizeof(struct jsonListInboundClientStatsArrayStruct));
                    if (!listInStruct->listInObjStruct[i].listInCliStatsStruct) {
                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInCliStatsStruct is a null pointer, failed to allocate space");

                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);
                        listInStruct->jsonListInboundObjectStructSize = 0;

                        jsonListInboundStructDelete(listInStruct);

                        cJSON_Delete(jsonParser);

                        return NULL;

                    }

                    for (size_t i = 0; i < listInStruct->listInObjStruct[i].jsonListInboundClientStatsArrayStructSize; i++) {
                        cJSON* clientStatsItem = cJSON_GetArrayItem(clientStatsArray, i);

                        if (
                            cJSON_HasObjectItem(clientStatsItem, "id") &&
                            cJSON_HasObjectItem(clientStatsItem, "inboundId") &&
                            cJSON_HasObjectItem(clientStatsItem, "enable") &&
                            cJSON_HasObjectItem(clientStatsItem, "email") &&
                            cJSON_HasObjectItem(clientStatsItem, "uuid") &&
                            cJSON_HasObjectItem(clientStatsItem, "subId") &&
                            cJSON_HasObjectItem(clientStatsItem, "up") &&
                            cJSON_HasObjectItem(clientStatsItem, "down") &&
                            cJSON_HasObjectItem(clientStatsItem, "expiryTime") &&
                            cJSON_HasObjectItem(clientStatsItem, "total") &&
                            cJSON_HasObjectItem(clientStatsItem, "reset") &&
                            cJSON_HasObjectItem(clientStatsItem, "lastOnline")
                           ) {
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[i].id = (int64_t)cJSON_GetObjectItem(clientStatsItem, "id")->valuedouble;
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[i].inboundId = (int64_t)cJSON_GetObjectItem(clientStatsItem, "inboundId")->valuedouble;
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[i].enable = (unsigned char)cJSON_GetObjectItem(clientStatsItem, "enable")->valueint;

                            char* email = cJSON_GetObjectItem(clientStatsItem, "email")->valuestring;
                            size_t emailLen = strlen(email);
                            char* emailCopy = (char*)malloc((emailLen + 1) * sizeof(char));
                            strncpy(emailCopy, email, emailLen);
                            emailCopy[emailLen + 1] = '\0';
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[i].email = emailCopy;

                            char* uuid = cJSON_GetObjectItem(clientStatsItem, "uuid")->valuestring;
                            size_t uuidLen = strlen(uuid);
                            char* uuidCopy = (char*)malloc((uuidLen + 1) * sizeof(char));
                            strncpy(uuidCopy, uuid, uuidLen);
                            uuidCopy[uuidLen + 1] = '\0';
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[i].uuid = uuidCopy;

                            char* subId = cJSON_GetObjectItem(clientStatsItem, "subId")->valuestring;
                            size_t subIdLen = strlen(subId);
                            char* subIdCopy = (char*)malloc((subIdLen + 1) * sizeof(char));
                            strncpy(subIdCopy, subId, subIdLen);
                            subIdCopy[subIdLen + 1] = '\0';
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[i].subId = subIdCopy;

                            listInStruct->listInObjStruct[i].listInCliStatsStruct[i].up = (int64_t)cJSON_GetObjectItem(clientStatsItem, "up")->valuedouble;
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[i].down = (int64_t)cJSON_GetObjectItem(clientStatsItem, "down")->valuedouble;
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[i].expiryTime = (int64_t)cJSON_GetObjectItem(clientStatsItem, "expiryTime")->valuedouble;
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[i].total = (int64_t)cJSON_GetObjectItem(clientStatsItem, "total")->valuedouble;
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[i].reset = cJSON_GetObjectItem(clientStatsItem, "reset")->valueint;
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[i].lastOnline = (int64_t)cJSON_GetObjectItem(clientStatsItem, "lastOnline")->valuedouble;


                        } else {
                            applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Some item is not present in the client stats array element, skipping the element...");

                        }

                    }

                }

                char* listen = cJSON_GetObjectItem(arrItem, "listen")->valuestring;
                size_t listenLen = strlen(listen);
                char* listenCopy = (char*)malloc((listenLen + 1) * sizeof(char));
                strncpy(listenCopy, listen, listenLen);
                listenCopy[listenLen + 1] = '\0';
                listInStruct->listInObjStruct[i].listen = listenCopy;

                listInStruct->listInObjStruct[i].port = cJSON_GetObjectItem(arrItem, "port")->valueint;

                char* protocol = cJSON_GetObjectItem(arrItem, "protocol")->valuestring;
                size_t protocolLen = strlen(protocol);
                char* protocolCopy = (char*)malloc((protocolLen + 1) * sizeof(char));
                strncpy(protocolCopy, protocol, protocolLen);
                protocolCopy[protocolLen + 1] = '\0';
                listInStruct->listInObjStruct[i].protocol = protocolCopy;

                char* tag = cJSON_GetObjectItem(arrItem, "tag")->valuestring;
                size_t tagLen = strlen(tag);
                char* tagCopy = (char*)malloc((tagLen + 1) * sizeof(char));
                strncpy(tagCopy, tag, tagLen);
                tagCopy[tagLen + 1] = '\0';
                listInStruct->listInObjStruct[i].tag = tagCopy;

                char* shareAddrStrategy = cJSON_GetObjectItem(arrItem, "shareAddrStrategy")->valuestring;
                size_t shareAddrStrategyLen = strlen(shareAddrStrategy);
                char* shareAddrStrategyCopy = (char*)malloc((shareAddrStrategyLen + 1) * sizeof(char));
                strncpy(shareAddrStrategyCopy, shareAddrStrategy, shareAddrStrategyLen);
                shareAddrStrategyCopy[shareAddrStrategyLen + 1] = '\0';
                listInStruct->listInObjStruct[i].shareAddrStrategy = shareAddrStrategyCopy;

                char* shareAddr = cJSON_GetObjectItem(arrItem, "shareAddr")->valuestring;
                size_t shareAddrLen = strlen(shareAddr);
                char* shareAddrCopy = (char*)malloc((shareAddrLen + 1) * sizeof(char));
                strncpy(shareAddrCopy, shareAddr, shareAddrLen);
                shareAddrCopy[shareAddrLen + 1] = '\0';
                listInStruct->listInObjStruct[i].shareAddr = shareAddrCopy;

                char* originNodeGuid = cJSON_GetObjectItem(arrItem, "originNodeGuid")->valuestring;
                size_t originNodeGuidLen = strlen(originNodeGuid);
                char* originNodeGuidCopy = (char*)malloc((originNodeGuidLen + 1) * sizeof(char));
                strncpy(originNodeGuidCopy, originNodeGuid, originNodeGuidLen);
                originNodeGuidCopy[originNodeGuidLen + 1] = '\0';
                listInStruct->listInObjStruct[i].originNodeGuid = originNodeGuidCopy;

                listInStruct->listInObjStruct[i].listInSettingsObjStruct = (struct jsonListInboundSettingsObjectStruct*)malloc(sizeof(struct jsonListInboundSettingsObjectStruct));
                if (!listInStruct->listInObjStruct[i].listInSettingsObjStruct) {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInCliStatsStruct is a null pointer, failed to allocate space");

                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);
                    listInStruct->jsonListInboundObjectStructSize = 0;

                    jsonListInboundStructDelete(listInStruct);

                    cJSON_Delete(jsonParser);

                    return NULL;


                }

            } else {
                applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Some item is not present in the array elelement, skipping the element...");


            }

        }

        cJSON_Delete(jsonParser);

        return listInCliStatsArrStruct;


    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");

        cJSON_Delete(jsonParser);

        return NULL;

    }

}

