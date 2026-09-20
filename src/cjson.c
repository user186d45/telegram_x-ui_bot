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

void jsonListInboundStreamSettingsTcpSettingsObjectStructDelete(struct jsonListInboundStreamSettingsTcpSettingsObjectStruct* listInStreamSettingsTcpSettingsObjStruct) {
    if (listInStreamSettingsTcpSettingsObjStruct->listInStreamSettingsTcpSettingsObjHeaderObjStruct) {
        jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectStructDelete(listInStreamSettingsTcpSettingsObjStruct->listInStreamSettingsTcpSettingsObjHeaderObjStruct);

    }

    listInStreamSettingsTcpSettingsObjStruct->listInStreamSettingsTcpSettingsObjHeaderObjStruct = NULL;

}

void jsonListInboundSettingsClientsArrayStructDelete(struct jsonListInboundSettingsClientsArrayStruct* listInSettingsCliArrStruct, size_t arraySize) {
    for (size_t i = 0; i < arraySize; i++) {
        free((char*)listInSettingsCliArrStruct[i].auth);
        free((char*)listInSettingsCliArrStruct[i].comment);
        free((char*)listInSettingsCliArrStruct[i].email);
        free((char*)listInSettingsCliArrStruct[i].id);
        free((char*)listInSettingsCliArrStruct[i].password);
        free((char*)listInSettingsCliArrStruct[i].security);
        free((char*)listInSettingsCliArrStruct[i].subId);

    }

    free(listInSettingsCliArrStruct);

}

void jsonListInboundClientStatsArrayStructDelete(struct jsonListInboundClientStatsArrayStruct* listInCliStatsStruct, size_t arraySize) {
    for (size_t i = 0; i < arraySize; i++) {
        free((char*)listInCliStatsStruct[i].email);
        free((char*)listInCliStatsStruct[i].uuid);
        free((char*)listInCliStatsStruct[i].subId);

    }

    free(listInCliStatsStruct);

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

        listInSettingsObjStruct->listInSettingsCliArrStruct = NULL;

    }

    free(listInSettingsObjStruct->listInSettingsCliArrStruct);

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
            listInObjStruct[i].listInCliStatsStruct = NULL;

        }

        free((char*)listInObjStruct[i].listen);
        free((char*)listInObjStruct[i].protocol);
        free((char*)listInObjStruct[i].tag);
        free((char*)listInObjStruct[i].shareAddrStrategy);
        free((char*)listInObjStruct[i].shareAddr);
        free((char*)listInObjStruct[i].originNodeGuid);
        
        if (listInObjStruct[i].listInSettingsObjStruct) {
            jsonListInboundSettingsObjectStructDelete(listInObjStruct[i].listInSettingsObjStruct);
            listInObjStruct[i].listInSettingsObjStruct = NULL;

        }

        if (listInObjStruct[i].listInStreamSettingsObjStruct) {
            jsonListInboundStreamSettingsObjectStructDelete(listInObjStruct[i].listInStreamSettingsObjStruct);
            listInObjStruct[i].listInStreamSettingsObjStruct = NULL;

        }

        if (listInObjStruct[i].listInSniffingObjStruct) {
            jsonListInboundSniffingObjectStructDelete(listInObjStruct[i].listInSniffingObjStruct);
            listInObjStruct[i].listInSniffingObjStruct = NULL;

        }

    }

    free(listInObjStruct);

}

void jsonListInboundStructDelete(struct jsonListInboundStruct* listInStruct) {
    free((char*)listInStruct->msg);

    if (listInStruct->listInObjStruct) {
        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, listInStruct->jsonListInboundObjectStructSize);
        listInStruct->listInObjStruct = NULL;

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

        if (
            !cJSON_HasObjectItem(arrayObj, "success") ||
            !cJSON_IsTrue(cJSON_GetObjectItem(arrayObj, "success"))
           ) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");

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
                emailCopy[emailLen] = '\0';
                listInCliStatsArrStruct[i].email = emailCopy;

                char* uuid = cJSON_GetObjectItem(arrItem, "uuid")->valuestring;
                size_t uuidLen = strlen(uuid);
                char* uuidCopy = (char*)malloc((uuidLen + 1) * sizeof(char));
                strncpy(uuidCopy, uuid, uuidLen);
                uuidCopy[uuidLen] = '\0';
                listInCliStatsArrStruct[i].uuid = uuidCopy;

                char* subId = cJSON_GetObjectItem(arrItem, "subId")->valuestring;
                size_t subIdLen = strlen(subId);
                char* subIdCopy = (char*)malloc((subIdLen + 1) * sizeof(char));
                strncpy(subIdCopy, subId, subIdLen);
                subIdCopy[subIdLen] = '\0';
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
        msgCopy[msgLen] = '\0';
        listInStruct->msg = msgCopy;

        cJSON* arrayObj = cJSON_GetObjectItem(jsonParser, "obj");
        if (!arrayObj) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "arrayObj is a null pointer");

            listInStruct->listInObjStruct = NULL;
            jsonListInboundStructDelete(listInStruct);

            cJSON_Delete(jsonParser);

            return listInStruct;

        }

        listInStruct->jsonListInboundObjectStructSize = cJSON_GetArraySize(arrayObj);
        if (!listInStruct->jsonListInboundObjectStructSize) {
            applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "jsonListInboundObjectStructSize is zero, returning");

            cJSON_Delete(jsonParser);

            listInStruct->listInObjStruct = NULL;

            return listInStruct;

        }

        listInStruct->listInObjStruct = (struct jsonListInboundObjectStruct*)malloc(listInStruct->jsonListInboundObjectStructSize * sizeof(struct jsonListInboundObjectStruct));
        if (!listInStruct->listInObjStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStruct->listInObjStruct is a null pointer");

            listInStruct->listInObjStruct = NULL;
            jsonListInboundStructDelete(listInStruct);

            cJSON_Delete(jsonParser);

            return NULL;

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
                remarkCopy[remarkLen] = '\0';
                listInStruct->listInObjStruct[i].remark = remarkCopy;

                listInStruct->listInObjStruct[i].subSortIndex = cJSON_GetObjectItem(arrItem, "subSortIndex")->valueint;
                listInStruct->listInObjStruct[i].enable = (unsigned char)cJSON_GetObjectItem(arrItem, "enable")->valueint;
                listInStruct->listInObjStruct[i].expiryTime = (int64_t)cJSON_GetObjectItem(arrItem, "expiryTime")->valuedouble;

                char* trafficReset = cJSON_GetObjectItem(arrItem, "trafficReset")->valuestring;
                size_t trafficResetLen = strlen(trafficReset);
                char* trafficResetCopy = (char*)malloc((trafficResetLen + 1) * sizeof(char));
                strncpy(trafficResetCopy, trafficReset, trafficResetLen);
                trafficResetCopy[trafficResetLen] = '\0';
                listInStruct->listInObjStruct[i].trafficReset = trafficResetCopy;

                listInStruct->listInObjStruct[i].trafficResetDay = cJSON_GetObjectItem(arrItem, "trafficResetDay")->valueint;
                listInStruct->listInObjStruct[i].lastTrafficResetTime = (int64_t)cJSON_GetObjectItem(arrItem, "lastTrafficResetTime")->valuedouble;

                cJSON* clientStatsArray = cJSON_GetObjectItem(jsonParser, "clientStats");
                listInStruct->listInObjStruct[i].jsonListInboundClientStatsArrayStructSize = cJSON_GetArraySize(clientStatsArray);
                if (!listInStruct->listInObjStruct[i].jsonListInboundClientStatsArrayStructSize) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "clientStatsArray is empty"); // TODO: make this message consistent across this file

                } else {
                    listInStruct->listInObjStruct[i].listInCliStatsStruct = (struct jsonListInboundClientStatsArrayStruct*)malloc(listInStruct->listInObjStruct[i].jsonListInboundClientStatsArrayStructSize * sizeof(struct jsonListInboundClientStatsArrayStruct));
                    if (!listInStruct->listInObjStruct[i].listInCliStatsStruct) {
                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInCliStatsStruct is a null pointer, failed to allocate space"); // TODO: make this messag econsistent across this file

                        listInStruct->listInObjStruct[i].listInCliStatsStruct = NULL;
                        listInStruct->listInObjStruct[i].listen = NULL;
                        listInStruct->listInObjStruct[i].protocol = NULL;
                        listInStruct->listInObjStruct[i].tag = NULL;
                        listInStruct->listInObjStruct[i].shareAddrStrategy = NULL;
                        listInStruct->listInObjStruct[i].shareAddr = NULL;
                        listInStruct->listInObjStruct[i].originNodeGuid = NULL;
                        listInStruct->listInObjStruct[i].listInSettingsObjStruct = NULL;
                        listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct = NULL;
                        listInStruct->listInObjStruct[i].listInSniffingObjStruct = NULL;
                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                        listInStruct->listInObjStruct = NULL;
                        jsonListInboundStructDelete(listInStruct);

                        cJSON_Delete(jsonParser);

                        return NULL;

                    }

                    for (size_t j = 0; j < listInStruct->listInObjStruct[i].jsonListInboundClientStatsArrayStructSize; j++) {
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
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[j].id = (int64_t)cJSON_GetObjectItem(clientStatsItem, "id")->valuedouble;
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[j].inboundId = (int64_t)cJSON_GetObjectItem(clientStatsItem, "inboundId")->valuedouble;
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[j].enable = (unsigned char)cJSON_GetObjectItem(clientStatsItem, "enable")->valueint;

                            char* email = cJSON_GetObjectItem(clientStatsItem, "email")->valuestring;
                            size_t emailLen = strlen(email);
                            char* emailCopy = (char*)malloc((emailLen + 1) * sizeof(char));
                            strncpy(emailCopy, email, emailLen);
                            emailCopy[emailLen] = '\0';
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[j].email = emailCopy;

                            char* uuid = cJSON_GetObjectItem(clientStatsItem, "uuid")->valuestring;
                            size_t uuidLen = strlen(uuid);
                            char* uuidCopy = (char*)malloc((uuidLen + 1) * sizeof(char));
                            strncpy(uuidCopy, uuid, uuidLen);
                            uuidCopy[uuidLen] = '\0';
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[j].uuid = uuidCopy;

                            char* subId = cJSON_GetObjectItem(clientStatsItem, "subId")->valuestring;
                            size_t subIdLen = strlen(subId);
                            char* subIdCopy = (char*)malloc((subIdLen + 1) * sizeof(char));
                            strncpy(subIdCopy, subId, subIdLen);
                            subIdCopy[subIdLen] = '\0';
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[j].subId = subIdCopy;

                            listInStruct->listInObjStruct[i].listInCliStatsStruct[j].up = (int64_t)cJSON_GetObjectItem(clientStatsItem, "up")->valuedouble;
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[j].down = (int64_t)cJSON_GetObjectItem(clientStatsItem, "down")->valuedouble;
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[j].expiryTime = (int64_t)cJSON_GetObjectItem(clientStatsItem, "expiryTime")->valuedouble;
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[j].total = (int64_t)cJSON_GetObjectItem(clientStatsItem, "total")->valuedouble;
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[j].reset = cJSON_GetObjectItem(clientStatsItem, "reset")->valueint;
                            listInStruct->listInObjStruct[i].listInCliStatsStruct[j].lastOnline = (int64_t)cJSON_GetObjectItem(clientStatsItem, "lastOnline")->valuedouble;


                        } else {
                            applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Some item is not present in the client stats array element, skipping the element...");

                        }

                    }

                }

                char* listen = cJSON_GetObjectItem(arrItem, "listen")->valuestring;
                size_t listenLen = strlen(listen);
                char* listenCopy = (char*)malloc((listenLen + 1) * sizeof(char));
                strncpy(listenCopy, listen, listenLen);
                listenCopy[listenLen] = '\0';
                listInStruct->listInObjStruct[i].listen = listenCopy;

                listInStruct->listInObjStruct[i].port = cJSON_GetObjectItem(arrItem, "port")->valueint;

                char* protocol = cJSON_GetObjectItem(arrItem, "protocol")->valuestring;
                size_t protocolLen = strlen(protocol);
                char* protocolCopy = (char*)malloc((protocolLen + 1) * sizeof(char));
                strncpy(protocolCopy, protocol, protocolLen);
                protocolCopy[protocolLen] = '\0';
                listInStruct->listInObjStruct[i].protocol = protocolCopy;

                char* tag = cJSON_GetObjectItem(arrItem, "tag")->valuestring;
                size_t tagLen = strlen(tag);
                char* tagCopy = (char*)malloc((tagLen + 1) * sizeof(char));
                strncpy(tagCopy, tag, tagLen);
                tagCopy[tagLen] = '\0';
                listInStruct->listInObjStruct[i].tag = tagCopy;

                char* shareAddrStrategy = cJSON_GetObjectItem(arrItem, "shareAddrStrategy")->valuestring;
                size_t shareAddrStrategyLen = strlen(shareAddrStrategy);
                char* shareAddrStrategyCopy = (char*)malloc((shareAddrStrategyLen + 1) * sizeof(char));
                strncpy(shareAddrStrategyCopy, shareAddrStrategy, shareAddrStrategyLen);
                shareAddrStrategyCopy[shareAddrStrategyLen] = '\0';
                listInStruct->listInObjStruct[i].shareAddrStrategy = shareAddrStrategyCopy;

                char* shareAddr = cJSON_GetObjectItem(arrItem, "shareAddr")->valuestring;
                size_t shareAddrLen = strlen(shareAddr);
                char* shareAddrCopy = (char*)malloc((shareAddrLen + 1) * sizeof(char));
                strncpy(shareAddrCopy, shareAddr, shareAddrLen);
                shareAddrCopy[shareAddrLen] = '\0';
                listInStruct->listInObjStruct[i].shareAddr = shareAddrCopy;

                char* originNodeGuid = cJSON_GetObjectItem(arrItem, "originNodeGuid")->valuestring;
                size_t originNodeGuidLen = strlen(originNodeGuid);
                char* originNodeGuidCopy = (char*)malloc((originNodeGuidLen + 1) * sizeof(char));
                strncpy(originNodeGuidCopy, originNodeGuid, originNodeGuidLen);
                originNodeGuidCopy[originNodeGuidLen] = '\0';
                listInStruct->listInObjStruct[i].originNodeGuid = originNodeGuidCopy;

                listInStruct->listInObjStruct[i].listInSettingsObjStruct = (struct jsonListInboundSettingsObjectStruct*)malloc(sizeof(struct jsonListInboundSettingsObjectStruct));
                if (!listInStruct->listInObjStruct[i].listInSettingsObjStruct) {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInSettingsObjStruct is a null pointer, failed to allocate space");

                    listInStruct->listInObjStruct[i].listInSettingsObjStruct = NULL;
                    listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct = NULL;
                    listInStruct->listInObjStruct[i].listInSniffingObjStruct = NULL;
                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                    listInStruct->listInObjStruct = NULL;
                    jsonListInboundStructDelete(listInStruct);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }

                cJSON* settingsObj = cJSON_GetObjectItem(arrItem, "settings");
                if (!settingsObj) {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingsObj is a null pointer");

                    listInStruct->listInObjStruct[i].listInSettingsObjStruct = NULL;
                    listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct = NULL;
                    listInStruct->listInObjStruct[i].listInSniffingObjStruct = NULL;
                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);
                    jsonListInboundStructDelete(listInStruct);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }

                cJSON* settingsObjClientsArray = cJSON_GetObjectItem(settingsObj, "clients");
                if (!settingsObjClientsArray) {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingsObjClientsArray is a null pointer");

                    listInStruct->listInObjStruct[i].listInSettingsObjStruct = NULL;
                    listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct = NULL;
                    listInStruct->listInObjStruct[i].listInSniffingObjStruct = NULL;
                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);
                    jsonListInboundStructDelete(listInStruct);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }

                listInStruct->listInObjStruct[i].listInSettingsObjStruct->jsonListInboundSettingsClientsArrayStructSize = cJSON_GetArraySize(settingsObjClientsArray);
                if (!listInStruct->listInObjStruct[i].listInSettingsObjStruct->jsonListInboundSettingsClientsArrayStructSize) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "settingsObjClientsArray is empty");

                } else {
                    listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct = (struct jsonListInboundSettingsClientsArrayStruct*)malloc(listInStruct->listInObjStruct[i].listInSettingsObjStruct->jsonListInboundSettingsClientsArrayStructSize * sizeof(struct jsonListInboundSettingsClientsArrayStruct));
                    if (listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct) {
                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInSettingsCliArrStruct is a null pointer, failed to allocate space");

                        jsonListInboundSettingsClientsArrayStructDelete(listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct, listInStruct->listInObjStruct[i].listInSettingsObjStruct->jsonListInboundSettingsClientsArrayStructSize);

                        listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct = NULL;
                        jsonListInboundSettingsObjectStructDelete(listInStruct->listInObjStruct[i].listInSettingsObjStruct);

                        listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct = NULL;
                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                        listInStruct->listInObjStruct = NULL;
                        jsonListInboundStructDelete(listInStruct);

                        cJSON_Delete(jsonParser);

                        return NULL;

                    }

                    for (size_t j = 0; j < listInStruct->listInObjStruct[i].listInSettingsObjStruct->jsonListInboundSettingsClientsArrayStructSize; j++) {
                        cJSON* settingsObjClientsItem = cJSON_GetArrayItem(settingsObjClientsArray, j);
                        if (
                            cJSON_HasObjectItem(settingsObjClientsArray, "auth") &&
                            cJSON_HasObjectItem(settingsObjClientsArray, "comment") &&
                            cJSON_HasObjectItem(settingsObjClientsArray, "created_at") &&
                            cJSON_HasObjectItem(settingsObjClientsArray, "email") &&
                            cJSON_HasObjectItem(settingsObjClientsArray, "enable") &&
                            cJSON_HasObjectItem(settingsObjClientsArray, "expiryTime") &&
                            cJSON_HasObjectItem(settingsObjClientsArray, "id") &&
                            cJSON_HasObjectItem(settingsObjClientsArray, "limitIp") &&
                            cJSON_HasObjectItem(settingsObjClientsArray, "password") &&
                            cJSON_HasObjectItem(settingsObjClientsArray, "reset") &&
                            cJSON_HasObjectItem(settingsObjClientsArray, "security") &&
                            cJSON_HasObjectItem(settingsObjClientsArray, "subId") &&
                            cJSON_HasObjectItem(settingsObjClientsArray, "tgId") &&
                            cJSON_HasObjectItem(settingsObjClientsArray, "totalGB") &&
                            cJSON_HasObjectItem(settingsObjClientsArray, "updated_at")
                           ) {
                            char* auth = cJSON_GetObjectItem(settingsObjClientsItem, "auth")->valuestring;
                            size_t authLen = strlen(auth);
                            char* authCopy = (char*)malloc((authLen + 1) * sizeof(char));
                            strncpy(authCopy, auth, authLen);
                            authCopy[authLen] = '\0';
                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].auth = authCopy;

                            char* comment = cJSON_GetObjectItem(settingsObjClientsItem, "comment")->valuestring;
                            size_t commentLen = strlen(comment);
                            char* commentCopy = (char*)malloc((commentLen + 1) * sizeof(char));
                            strncpy(commentCopy, comment, commentLen);
                            commentCopy[commentLen] = '\0';
                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].comment = commentCopy;

                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].createdAt = (int64_t)cJSON_GetObjectItem(settingsObjClientsItem, "created_at")->valuedouble;

                            char* email = cJSON_GetObjectItem(settingsObjClientsItem, "email")->valuestring;
                            size_t emailLen = strlen(email);
                            char* emailCopy = (char*)malloc((emailLen + 1) * sizeof(char));
                            strncpy(emailCopy, email, emailLen);
                            emailCopy[emailLen] = '\0';
                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].email = emailCopy;

                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].enable = cJSON_IsTrue(cJSON_GetObjectItem(settingsObjClientsItem, "enable"));
                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].expiryTime = (int64_t)cJSON_GetObjectItem(settingsObjClientsItem, "expiryTime")->valuedouble;

                            char* id = cJSON_GetObjectItem(settingsObjClientsItem, "id")->valuestring;
                            size_t idLen = strlen(id);
                            char* idCopy = (char*)malloc((idLen + 1) * sizeof(char));
                            strncpy(idCopy, id, idLen);
                            idCopy[idLen] = '\0';
                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].id = idCopy;

                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].limitIp = cJSON_GetObjectItem(settingsObjClientsItem, "limitIp")->valueint;

                            char* password = cJSON_GetObjectItem(settingsObjClientsItem, "password")->valuestring;
                            size_t passwordLen = strlen(password);
                            char* passwordCopy = (char*)malloc((passwordLen + 1) * sizeof(char));
                            strncpy(passwordCopy, password, passwordLen);
                            passwordCopy[passwordLen] = '\0';
                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].password = passwordCopy;

                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].reset = cJSON_GetObjectItem(settingsObjClientsItem, "reset")->valueint;

                            char* security = cJSON_GetObjectItem(settingsObjClientsItem, "security")->valuestring;
                            size_t securityLen = strlen(security);
                            char* securityCopy = (char*)malloc((securityLen + 1) * sizeof(char));
                            strncpy(securityCopy, security, securityLen);
                            securityCopy[securityLen] = '\0';
                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].security = securityCopy;

                            char* subId = cJSON_GetObjectItem(settingsObjClientsItem, "subId")->valuestring;
                            size_t subIdLen = strlen(subId);
                            char* subIdCopy = (char*)malloc((subIdLen + 1) * sizeof(char));
                            strncpy(subIdCopy, subId, subIdLen);
                            subIdCopy[subIdLen] = '\0';
                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].subId = subIdCopy;

                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].tgId = (int64_t)cJSON_GetObjectItem(settingsObjClientsItem, "tgId")->valuedouble;
                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].totalGB = (int64_t)cJSON_GetObjectItem(settingsObjClientsItem, "totalGB")->valuedouble;
                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].updatedAt = (int64_t)cJSON_GetObjectItem(settingsObjClientsItem, "updated_at")->valuedouble;

                        } else {
                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "some element is not present in the array, skipping...");

                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].auth = NULL;
                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].comment = NULL;
                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].email = NULL;
                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].id = NULL;
                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].password = NULL;
                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].security = NULL;
                            listInStruct->listInObjStruct[i].listInSettingsObjStruct->listInSettingsCliArrStruct[j].subId = NULL;

                        }

                    }

                    char* decryption = cJSON_GetObjectItem(settingsObj, "decryption")->valuestring;
                    size_t decryptionLen = strlen(decryption);
                    char* decryptionCopy = (char*)malloc((decryptionLen + 1) * sizeof(char));
                    strncpy(decryptionCopy, decryption, decryptionLen);
                    decryptionCopy[decryptionLen + 1] = '\0';

                    char* encryption = cJSON_GetObjectItem(settingsObj, "encryption")->valuestring;
                    size_t encryptionLen = strlen(encryption);
                    char* encryptionCopy = (char*)malloc((encryptionLen + 1) * sizeof(char));
                    strncpy(encryptionCopy, encryption, encryptionLen);
                    encryptionCopy[encryptionLen + 1] = '\0';

                }

                // TODO: first check the cJSON pointer then malloc the struct, check the entire code to ensure consistency
                cJSON* streamSettingsObj = cJSON_GetObjectItem(arrItem, "streamSettings");
                if (!streamSettingsObj) {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "streamSettings is a null pointer");

                    listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct = NULL;
                    listInStruct->listInObjStruct[i].listInSniffingObjStruct = NULL;
                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                    listInStruct->listInObjStruct = NULL;
                    jsonListInboundStructDelete(listInStruct);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }

                listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct = (struct jsonListInboundStreamSettingsObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsObjectStruct));
                if (!listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct) {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsObjStruct is a null pointer, failed to allocate space");

                    listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct = NULL;
                    listInStruct->listInObjStruct[i].listInSniffingObjStruct = NULL;
                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                    listInStruct->listInObjStruct = NULL;
                    jsonListInboundStructDelete(listInStruct);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }

                char* network = cJSON_GetObjectItem(streamSettingsObj, "network")->valuestring;
                size_t networkLen = strlen(network);
                char* networkCopy = (char*)malloc((networkLen + 1) * sizeof(char));
                strncpy(networkCopy, network, networkLen);
                networkCopy[networkLen] = '\0';
                listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct->network = networkCopy;

                const char* networkTypes[] = {
                    "tcp", // raw
                    "kcp", // mKCP
                    "ws", // websocket
                    "grpc",
                    "httpupgrade",
                    "xhttp"

                };

                enum networkTypesEnum {
                    NETWORKTYPE_TCP,
                    NETWORKTYPE_KCP,
                    NETWORKTYPE_WS,
                    NETWORKTYPE_GRPC,
                    NETWORKTYPE_HTTPUPGRADE,
                    NETWORKTYPE_XHTTP,
                    NETWORKTYPE_COUNT

                };

                enum networkTypesEnum nType;
                for (int i = 0; i < NETWORKTYPE_COUNT; i++) {
                    if (strncmp(networkTypes[i], listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct->network, strlen(networkTypes[i])) == 0) {
                        nType = i;

                    } else if (i == (NETWORKTYPE_COUNT - 1)) {
                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Unable to detect network type");

                        jsonListInboundStreamSettingsTcpSettingsObjectStructDelete(listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct->listInStreamSettingsTcpSettingsObjStruct);

                        listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct = NULL;
                        listInStruct->listInObjStruct[i].listInSniffingObjStruct = NULL;
                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                        listInStruct->listInObjStruct = NULL;
                        jsonListInboundStructDelete(listInStruct);

                        return NULL;

                    }

                }

                switch (nType) {
                    case NETWORKTYPE_TCP:
                        listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct->listInStreamSettingsTcpSettingsObjStruct = (struct jsonListInboundStreamSettingsTcpSettingsObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsTcpSettingsObjectStruct));
                        if (!listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct->listInStreamSettingsTcpSettingsObjStruct) {
                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsTcpSettingsObjStruct is a null pointer, failed to allocate space");

                            listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;
                            jsonListInboundStreamSettingsObjectStructDelete(listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct);

                            listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct = NULL;
                            listInStruct->listInObjStruct[i].listInSniffingObjStruct = NULL;
                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                            listInStruct->listInObjStruct = NULL;
                            jsonListInboundStructDelete(listInStruct);

                            cJSON_Delete(jsonParser);

                            return NULL;

                        }

//struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectStruct {
//    const char*                 type;
//    struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectRequestObjectStruct* listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct;
//    struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectResponseObjectStruct* listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct;
//
//};
//
//struct jsonListInboundStreamSettingsTcpSettingsObjectStruct {
//    unsigned char               acceptProxyProtocol;
//    struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectStruct* listInStreamSettingsTcpSettingsObjHeaderObjStruct;
//
//};
//"tcpSettings": {
//          "acceptProxyProtocol": false,
//          "header": {
//            "type": "http",
//            "request": {
//              "version": "1.1",
//              "method": "GET",
//              "path": [
//                "/"
//              ],
//              "headers": {
//                "safsdf": [
//                  "safsafsd"
//                ]
//              }
//            },
//            "response": {
//              "version": "1.1",
//              "status": "200",
//              "reason": "OK",
//              "headers": {}
//            }
//          }
//        }

                        if (
                            cJSON_HasObjectItem(streamSettingsObj, "acceptProxyProtocol") &&
                            cJSON_IsBool(cJSON_GetObjectItem(streamSettingsObj, "acceptProxyProtocol")) &&
                            cJSON_HasObjectItem(streamSettingsObj, "tcpSettings") &&
                            cJSON_IsObject(cJSON_GetObjectItem(streamSettingsObj, "tcpSettings"))
                           ) {
                            listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct->listInStreamSettingsTcpSettingsObjStruct->acceptProxyProtocol = cJSON_IsTrue(cJSON_GetObjectItem(streamSettingsObj, "acceptProxyProtocol"));

                            cJSON* tcpSettingsObj = cJSON_GetObjectItem(streamSettingsObj, "tcpSettings");
                            if (
                                cJSON_HasObjectItem(tcpSettingsObj, "header") &&
                                cJSON_IsObject(cJSON_GetObjectItem(tcpSettingsObj, "header"))
                               ) {
                                listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct->listInStreamSettingsTcpSettingsObjStruct->listInStreamSettingsTcpSettingsObjHeaderObjStruct = (struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectStruct));
                                if (!listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct->listInStreamSettingsTcpSettingsObjStruct->listInStreamSettingsTcpSettingsObjHeaderObjStruct) {
                                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsTcpSettingsObjHeaderObjStruct is a null pointer, failed to allocate space");

                                    listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct->listInStreamSettingsTcpSettingsObjStruct->listInStreamSettingsTcpSettingsObjHeaderObjStruct = NULL;
                                    jsonListInboundStreamSettingsTcpSettingsObjectStructDelete(listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct->listInStreamSettingsTcpSettingsObjStruct);

                                    listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct = NULL;
                                    listInStruct->listInObjStruct[i].listInSniffingObjStruct = NULL;
                                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                    listInStruct->listInObjStruct = NULL;
                                    jsonListInboundStructDelete(listInStruct);

                                    cJSON_Delete(jsonParser);

                                    return NULL;

                                }

                        }


                        break;

                    case NETWORKTYPE_KCP:

                    case NETWORKTYPE_WS:

                    case NETWORKTYPE_GRPC:

                    case NETWORKTYPE_HTTPUPGRADE:

                    case NETWORKTYPE_XHTTP:

                    default:

                }

                listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct = (struct jsonListInboundStreamSettingsObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsObjectStruct));
                if (!listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct) {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsObjStruct is a null pointer, failed to allocate space");

                    listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct = NULL;
                    listInStruct->listInObjStruct[i].listInSniffingObjStruct = NULL;
                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                    listInStruct->listInObjStruct = NULL;
                    jsonListInboundStructDelete(listInStruct);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }

            } else {
                applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Some item is not present in the array elelement, skipping the element...");

                listInStruct->listInObjStruct[i].remark = NULL;
                listInStruct->listInObjStruct[i].trafficReset = NULL;
                listInStruct->listInObjStruct[i].listInCliStatsStruct = NULL;
                listInStruct->listInObjStruct[i].listen = NULL;
                listInStruct->listInObjStruct[i].protocol = NULL;
                listInStruct->listInObjStruct[i].tag = NULL;
                listInStruct->listInObjStruct[i].shareAddrStrategy = NULL;
                listInStruct->listInObjStruct[i].shareAddr = NULL;
                listInStruct->listInObjStruct[i].originNodeGuid = NULL;
                listInStruct->listInObjStruct[i].listInSettingsObjStruct = NULL;
                listInStruct->listInObjStruct[i].listInStreamSettingsObjStruct = NULL;
                listInStruct->listInObjStruct[i].listInSniffingObjStruct = NULL;

            }

        }

        cJSON_Delete(jsonParser);

        return listInStruct;


    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");

        cJSON_Delete(jsonParser);

        return NULL;

    }

}

