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

    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");

        cJSON_Delete(jsonParser);

        return NULL;

    }

}

