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
        listInStreamSettingsTcpSettingsObjStruct->listInStreamSettingsTcpSettingsObjHeaderObjStruct = NULL;

    }

    free(listInStreamSettingsTcpSettingsObjStruct);

}

void jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersArrayStructDelete(struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersStruct* listInStreamSettingsTcpSettingsObjHeaderObjHeadersStruct, size_t arraySize) {
    for (size_t i = 0; i < arraySize; i++) {
        struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersStruct* headersItem = &listInStreamSettingsTcpSettingsObjHeaderObjHeadersStruct[i];
        free((char*)headersItem->name);

        for (size_t j = 0; j < (size_t)headersItem->valueCount; j++) {
            free((char*)headersItem->value[j]);

        }

        free((char*)headersItem->value);

    }

    free(listInStreamSettingsTcpSettingsObjHeaderObjHeadersStruct);

}

void jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectRequestObjectStructDelete(struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectRequestObjectStruct* listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct) {
    free((char*)listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct->version);
    free((char*)listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct->method);

    for (size_t i = 0; i < (size_t)listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct->pathCount; i++) {
        free((char*)listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct->path[i]);

    }

    free((char*)listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct->path);

    if (listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct->listInStreamSettingsTcpSettingsObjHeaderObjReqHeadersStruct) {
        jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersArrayStructDelete(listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct->listInStreamSettingsTcpSettingsObjHeaderObjReqHeadersStruct, listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct->jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersStructSize);

        listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct->listInStreamSettingsTcpSettingsObjHeaderObjReqHeadersStruct = NULL;

    }

    free(listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct);

}

void jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectResponseObjectStructDelete(struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectResponseObjectStruct* listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct) {
    free((char*)listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct->version);
    free((char*)listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct->status);
    free((char*)listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct->reason);

    if (listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct->listInStreamSettingsTcpSettingsObjHeaderObjResHeadersStruct) {
        jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersArrayStructDelete(listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct->listInStreamSettingsTcpSettingsObjHeaderObjResHeadersStruct, listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct->jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersStructSize);

        listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct->listInStreamSettingsTcpSettingsObjHeaderObjResHeadersStruct = NULL;

    }

    free(listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct);

}

void jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectStructDelete(struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectStruct* listInStreamSettingsTcpSettingsObjHeaderObjStruct) {
    free((char*)listInStreamSettingsTcpSettingsObjHeaderObjStruct->type);

    if (listInStreamSettingsTcpSettingsObjHeaderObjStruct->listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct) {
        jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectRequestObjectStructDelete(listInStreamSettingsTcpSettingsObjHeaderObjStruct->listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct);
        listInStreamSettingsTcpSettingsObjHeaderObjStruct->listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct = NULL;

    }

    if (listInStreamSettingsTcpSettingsObjHeaderObjStruct->listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct) {
        jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectResponseObjectStructDelete(listInStreamSettingsTcpSettingsObjHeaderObjStruct->listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct);
        listInStreamSettingsTcpSettingsObjHeaderObjStruct->listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct = NULL;

    }

    free(listInStreamSettingsTcpSettingsObjHeaderObjStruct);

}

void jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersArrayStructDelete(struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersStruct* listInStreamSettingsWSSettingsObjHeaderObjHeadersStruct, size_t arraySize) {
    for (size_t i = 0; i < arraySize; i++) {
        struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersStruct* headersItem = &listInStreamSettingsWSSettingsObjHeaderObjHeadersStruct[i];
        free((char*)headersItem->name);

        for (size_t j = 0; j < (size_t)headersItem->valueCount; j++) {
            free((char*)headersItem->value[j]);

        }

        free((char*)headersItem->value);

    }

    free(listInStreamSettingsWSSettingsObjHeaderObjHeadersStruct);

}

void jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectRequestObjectStructDelete(struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectRequestObjectStruct* listInStreamSettingsWSSettingsObjHeaderObjReqObjStruct) {
    free((char*)listInStreamSettingsWSSettingsObjHeaderObjReqObjStruct->version);
    free((char*)listInStreamSettingsWSSettingsObjHeaderObjReqObjStruct->method);

    for (size_t i = 0; i < (size_t)listInStreamSettingsWSSettingsObjHeaderObjReqObjStruct->pathCount; i++) {
        free((char*)listInStreamSettingsWSSettingsObjHeaderObjReqObjStruct->path[i]);

    }

    free((char*)listInStreamSettingsWSSettingsObjHeaderObjReqObjStruct->path);

    if (listInStreamSettingsWSSettingsObjHeaderObjReqObjStruct->listInStreamSettingsWSSettingsObjHeaderObjReqHeadersStruct) {
        jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersArrayStructDelete(listInStreamSettingsWSSettingsObjHeaderObjReqObjStruct->listInStreamSettingsWSSettingsObjHeaderObjReqHeadersStruct, listInStreamSettingsWSSettingsObjHeaderObjReqObjStruct->jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersStructSize);

        listInStreamSettingsWSSettingsObjHeaderObjReqObjStruct->listInStreamSettingsWSSettingsObjHeaderObjReqHeadersStruct = NULL;

    }

    free(listInStreamSettingsWSSettingsObjHeaderObjReqObjStruct);

}

void jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectResponseObjectStructDelete(struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectResponseObjectStruct* listInStreamSettingsWSSettingsObjHeaderObjResObjStruct) {
    free((char*)listInStreamSettingsWSSettingsObjHeaderObjResObjStruct->version);
    free((char*)listInStreamSettingsWSSettingsObjHeaderObjResObjStruct->status);
    free((char*)listInStreamSettingsWSSettingsObjHeaderObjResObjStruct->reason);

    if (listInStreamSettingsWSSettingsObjHeaderObjResObjStruct->listInStreamSettingsWSSettingsObjHeaderObjResHeadersStruct) {
        jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersArrayStructDelete(listInStreamSettingsWSSettingsObjHeaderObjResObjStruct->listInStreamSettingsWSSettingsObjHeaderObjResHeadersStruct, listInStreamSettingsWSSettingsObjHeaderObjResObjStruct->jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersStructSize);

        listInStreamSettingsWSSettingsObjHeaderObjResObjStruct->listInStreamSettingsWSSettingsObjHeaderObjResHeadersStruct = NULL;

    }

    free(listInStreamSettingsWSSettingsObjHeaderObjResObjStruct);

}

void jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectStructDelete(struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectStruct* listInStreamSettingsWSSettingsObjHeaderObjStruct) {
    free((char*)listInStreamSettingsWSSettingsObjHeaderObjStruct->type);

    if (listInStreamSettingsWSSettingsObjHeaderObjStruct->listInStreamSettingsWSSettingsObjHeaderObjReqObjStruct) {
        jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectRequestObjectStructDelete(listInStreamSettingsWSSettingsObjHeaderObjStruct->listInStreamSettingsWSSettingsObjHeaderObjReqObjStruct);
        listInStreamSettingsWSSettingsObjHeaderObjStruct->listInStreamSettingsWSSettingsObjHeaderObjReqObjStruct = NULL;

    }

    if (listInStreamSettingsWSSettingsObjHeaderObjStruct->listInStreamSettingsWSSettingsObjHeaderObjResObjStruct) {
        jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectResponseObjectStructDelete(listInStreamSettingsWSSettingsObjHeaderObjStruct->listInStreamSettingsWSSettingsObjHeaderObjResObjStruct);
        listInStreamSettingsWSSettingsObjHeaderObjStruct->listInStreamSettingsWSSettingsObjHeaderObjResObjStruct = NULL;

    }

    free(listInStreamSettingsWSSettingsObjHeaderObjStruct);

}

void jsonListInboundStreamSettingsWSSettingsObjectStructDelete(struct jsonListInboundStreamSettingsWSSettingsObjectStruct* listInStreamSettingsWSSettingsObjStruct) {
    if (listInStreamSettingsWSSettingsObjStruct->listInStreamSettingsWSSettingsObjHeaderObjStruct) {
        jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectStructDelete(listInStreamSettingsWSSettingsObjStruct->listInStreamSettingsWSSettingsObjHeaderObjStruct);
        listInStreamSettingsWSSettingsObjStruct->listInStreamSettingsWSSettingsObjHeaderObjStruct = NULL;

    }

    free(listInStreamSettingsWSSettingsObjStruct);

}

void jsonListInboundStreamSettingsMKcpSettingsObjectStructDelete(struct jsonListInboundStreamSettingsMKcpSettingsObjectStruct* listInStreamSettingsMKcpSettingsObjStruct) {
    free(listInStreamSettingsMKcpSettingsObjStruct);

}

void jsonListInboundStreamSettingsFinalMaskUdpMkcpLegacyObjectStructDelete(struct jsonListInboundStreamSettingsFinalMaskUdpMkcpLegacyObjectStruct* listInStreamSettingsFinalMaskUdpMkcpLegacyObjStruct) {
    free((char*)listInStreamSettingsFinalMaskUdpMkcpLegacyObjStruct->header);
    free((char*)listInStreamSettingsFinalMaskUdpMkcpLegacyObjStruct->value);

    free(listInStreamSettingsFinalMaskUdpMkcpLegacyObjStruct);

}

void jsonListInboundStreamSettingsFinalMaskUdpXdnsObjectStructDelete(struct jsonListInboundStreamSettingsFinalMaskUdpXdnsObjectStruct* listInStreamSettingsFinalMaskUdpXdnsObjStruct) {
    for (size_t i = 0; i < (size_t)listInStreamSettingsFinalMaskUdpXdnsObjStruct->domainsCount; i++) {
        free((char*)listInStreamSettingsFinalMaskUdpXdnsObjStruct->domains[i]);

    }

    free((char*)listInStreamSettingsFinalMaskUdpXdnsObjStruct->domains);

    free(listInStreamSettingsFinalMaskUdpXdnsObjStruct);

}

void jsonListInboundStreamSettingsFinalMaskUdpXicmpObjectStructDelete(struct jsonListInboundStreamSettingsFinalMaskUdpXicmpObjectStruct* listInStreamSettingsFinalMaskUdpXicmpObjStruct) {
    for (size_t i = 0; i < (size_t)listInStreamSettingsFinalMaskUdpXicmpObjStruct->ipsCount; i++) {
        free((char*)listInStreamSettingsFinalMaskUdpXicmpObjStruct->ips[i]);

    }

    free((char*)listInStreamSettingsFinalMaskUdpXicmpObjStruct->ips);

    free(listInStreamSettingsFinalMaskUdpXicmpObjStruct);

}

void jsonListInboundStreamSettingsFinalMaskUdpRealmTlsConfigObjectStructDelete(struct jsonListInboundStreamSettingsFinalMaskUdpRealmTlsConfigObjectStruct* listInStreamSettingsFinalMaskUdpRealmTlsConfigObjStruct) {
    free((char*)listInStreamSettingsFinalMaskUdpRealmTlsConfigObjStruct->serverName);
    free((char*)listInStreamSettingsFinalMaskUdpRealmTlsConfigObjStruct->fingerprint);

    for (size_t i = 0; i < (size_t)listInStreamSettingsFinalMaskUdpRealmTlsConfigObjStruct->alpnCount; i++) {
        free((char*)listInStreamSettingsFinalMaskUdpRealmTlsConfigObjStruct->alpn[i]);

    }

    free((char*)listInStreamSettingsFinalMaskUdpRealmTlsConfigObjStruct->alpn);

    free(listInStreamSettingsFinalMaskUdpRealmTlsConfigObjStruct);

}

void jsonListInboundStreamSettingsFinalMaskUdpRealmObjectStructDelete(struct jsonListInboundStreamSettingsFinalMaskUdpRealmObjectStruct* listInStreamSettingsFinalMaskUdpRealmObjStruct) {
    free((char*)listInStreamSettingsFinalMaskUdpRealmObjStruct->url);

    for (size_t i = 0; i < (size_t)listInStreamSettingsFinalMaskUdpRealmObjStruct->stunServersCount; i++) {
        free((char*)listInStreamSettingsFinalMaskUdpRealmObjStruct->stunServers[i]);

    }

    free((char*)listInStreamSettingsFinalMaskUdpRealmObjStruct->stunServers);

    if (listInStreamSettingsFinalMaskUdpRealmObjStruct->listInStreamSettingsFinalMaskUdpRealmTlsConfigObjStruct) {
        jsonListInboundStreamSettingsFinalMaskUdpRealmTlsConfigObjectStructDelete(listInStreamSettingsFinalMaskUdpRealmObjStruct->listInStreamSettingsFinalMaskUdpRealmTlsConfigObjStruct);
        listInStreamSettingsFinalMaskUdpRealmObjStruct->listInStreamSettingsFinalMaskUdpRealmTlsConfigObjStruct = NULL;

    }

    free(listInStreamSettingsFinalMaskUdpRealmObjStruct);

}

void jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomPacketObjectStructDelete(struct jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomPacketObjectStruct* listInStreamSettingsFinalMaskUdpHeaderCustomPacketObjStruct, size_t arraySize) {
    for (size_t i = 0; i < arraySize; i++) {
        struct jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomPacketObjectStruct* headerCustomPacket = &listInStreamSettingsFinalMaskUdpHeaderCustomPacketObjStruct[i];
        free((char*)headerCustomPacket->type);
        free((char*)headerCustomPacket->randRange);
        free((char*)headerCustomPacket->packet);

    }

    free(listInStreamSettingsFinalMaskUdpHeaderCustomPacketObjStruct);

}

void jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomObjectStructDelete(struct jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomObjectStruct* listInStreamSettingsFinalMaskUdpHeaderCustomObjStruct) {
    if (listInStreamSettingsFinalMaskUdpHeaderCustomObjStruct->listInStreamSettingsFinalMaskUdpHeaderCustomClientPacketStruct) {
        jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomPacketObjectStructDelete(listInStreamSettingsFinalMaskUdpHeaderCustomObjStruct->listInStreamSettingsFinalMaskUdpHeaderCustomClientPacketStruct, listInStreamSettingsFinalMaskUdpHeaderCustomObjStruct->jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomClientPacketStructSize);
        listInStreamSettingsFinalMaskUdpHeaderCustomObjStruct->listInStreamSettingsFinalMaskUdpHeaderCustomClientPacketStruct = NULL;

    }

    if (listInStreamSettingsFinalMaskUdpHeaderCustomObjStruct->listInStreamSettingsFinalMaskUdpHeaderCustomServerPacketStruct) {
        jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomPacketObjectStructDelete(listInStreamSettingsFinalMaskUdpHeaderCustomObjStruct->listInStreamSettingsFinalMaskUdpHeaderCustomServerPacketStruct, listInStreamSettingsFinalMaskUdpHeaderCustomObjStruct->jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomServerPacketStructSize);
        listInStreamSettingsFinalMaskUdpHeaderCustomObjStruct->listInStreamSettingsFinalMaskUdpHeaderCustomServerPacketStruct = NULL;

    }

    free(listInStreamSettingsFinalMaskUdpHeaderCustomObjStruct);

}

void jsonListInboundStreamSettingsFinalMaskUdpNoisePacketObjectStructDelete(struct jsonListInboundStreamSettingsFinalMaskUdpNoisePacketObjectStruct* listInStreamSettingsFinalMaskUdpNoisePacketObjStruct, size_t arraySize) {
    for (size_t i = 0; i < arraySize; i++) {
        struct jsonListInboundStreamSettingsFinalMaskUdpNoisePacketObjectStruct* noisePacket = &listInStreamSettingsFinalMaskUdpNoisePacketObjStruct[i];
        free((char*)noisePacket->type);
        free((char*)noisePacket->delay);
        free((char*)noisePacket->rand);
        free((char*)noisePacket->randRange);
        free((char*)noisePacket->packet);

    }

    free(listInStreamSettingsFinalMaskUdpNoisePacketObjStruct);

}

void jsonListInboundStreamSettingsFinalMaskUdpNoiseObjectStructDelete(struct jsonListInboundStreamSettingsFinalMaskUdpNoiseObjectStruct* listInStreamSettingsFinalMaskUdpNoiseObjStruct) {
    if (listInStreamSettingsFinalMaskUdpNoiseObjStruct->listInStreamSettingsFinalMaskUdpNoisePacketStruct) {
        jsonListInboundStreamSettingsFinalMaskUdpNoisePacketObjectStructDelete(listInStreamSettingsFinalMaskUdpNoiseObjStruct->listInStreamSettingsFinalMaskUdpNoisePacketStruct, listInStreamSettingsFinalMaskUdpNoiseObjStruct->jsonListInboundStreamSettingsFinalMaskUdpNoisePacketStructSize);
        listInStreamSettingsFinalMaskUdpNoiseObjStruct->listInStreamSettingsFinalMaskUdpNoisePacketStruct = NULL;

    }

    free(listInStreamSettingsFinalMaskUdpNoiseObjStruct);

}

void jsonListInboundStreamSettingsFinalMaskUdpObjectStructDelete(struct jsonListInboundStreamSettingsFinalMaskUdpObjectStruct* listInStreamSettingsFinalMaskUdpObjStruct) {
    free((char*)listInStreamSettingsFinalMaskUdpObjStruct->type);

    if (listInStreamSettingsFinalMaskUdpObjStruct->listInStreamSettingsFinalMaskUdpMkcpLegacyObjStruct) {
        jsonListInboundStreamSettingsFinalMaskUdpMkcpLegacyObjectStructDelete(listInStreamSettingsFinalMaskUdpObjStruct->listInStreamSettingsFinalMaskUdpMkcpLegacyObjStruct);
        listInStreamSettingsFinalMaskUdpObjStruct->listInStreamSettingsFinalMaskUdpMkcpLegacyObjStruct = NULL;

    }

    if (listInStreamSettingsFinalMaskUdpObjStruct->listInStreamSettingsFinalMaskUdpXdnsObjStruct) {
        jsonListInboundStreamSettingsFinalMaskUdpXdnsObjectStructDelete(listInStreamSettingsFinalMaskUdpObjStruct->listInStreamSettingsFinalMaskUdpXdnsObjStruct);
        listInStreamSettingsFinalMaskUdpObjStruct->listInStreamSettingsFinalMaskUdpXdnsObjStruct = NULL;

    }

    if (listInStreamSettingsFinalMaskUdpObjStruct->listInStreamSettingsFinalMaskUdpXicmpObjStruct) {
        jsonListInboundStreamSettingsFinalMaskUdpXicmpObjectStructDelete(listInStreamSettingsFinalMaskUdpObjStruct->listInStreamSettingsFinalMaskUdpXicmpObjStruct);
        listInStreamSettingsFinalMaskUdpObjStruct->listInStreamSettingsFinalMaskUdpXicmpObjStruct = NULL;

    }

    if (listInStreamSettingsFinalMaskUdpObjStruct->listInStreamSettingsFinalMaskUdpRealmObjStruct) {
        jsonListInboundStreamSettingsFinalMaskUdpRealmObjectStructDelete(listInStreamSettingsFinalMaskUdpObjStruct->listInStreamSettingsFinalMaskUdpRealmObjStruct);
        listInStreamSettingsFinalMaskUdpObjStruct->listInStreamSettingsFinalMaskUdpRealmObjStruct = NULL;

    }

    if (listInStreamSettingsFinalMaskUdpObjStruct->listInStreamSettingsFinalMaskUdpHeaderCustomObjStruct) {
        jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomObjectStructDelete(listInStreamSettingsFinalMaskUdpObjStruct->listInStreamSettingsFinalMaskUdpHeaderCustomObjStruct);
        listInStreamSettingsFinalMaskUdpObjStruct->listInStreamSettingsFinalMaskUdpHeaderCustomObjStruct = NULL;

    }

    if (listInStreamSettingsFinalMaskUdpObjStruct->listInStreamSettingsFinalMaskUdpNoiseObjStruct) {
        jsonListInboundStreamSettingsFinalMaskUdpNoiseObjectStructDelete(listInStreamSettingsFinalMaskUdpObjStruct->listInStreamSettingsFinalMaskUdpNoiseObjStruct);
        listInStreamSettingsFinalMaskUdpObjStruct->listInStreamSettingsFinalMaskUdpNoiseObjStruct = NULL;

    }

    }

void jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(struct jsonListInboundStreamSettingsMKcpFinalMaskObjectStruct* listInStreamSettingsMKcpFinalMaskObjStruct) {
    for (size_t i = 0; i < listInStreamSettingsMKcpFinalMaskObjStruct->jsonListInboundStreamSettingsFinalMaskUdpStructSize; i++) {
        struct jsonListInboundStreamSettingsFinalMaskUdpObjectStruct* finalMaskUdp = &listInStreamSettingsMKcpFinalMaskObjStruct->listInStreamSettingsFinalMaskUdpStruct[i];
        jsonListInboundStreamSettingsFinalMaskUdpObjectStructDelete(finalMaskUdp);

    }

    free(listInStreamSettingsMKcpFinalMaskObjStruct->listInStreamSettingsFinalMaskUdpStruct);

    free(listInStreamSettingsMKcpFinalMaskObjStruct);

}

void jsonListInboundStreamSettingsTcpFinalMaskFragmentObjectStructDelete(struct jsonListInboundStreamSettingsTcpFinalMaskFragmentObjectStruct* listInStreamSettingsTcpFinalMaskFragmentObjStruct) {
    free((char*)listInStreamSettingsTcpFinalMaskFragmentObjStruct->packets);
    for (size_t i = 0; i < (size_t)listInStreamSettingsTcpFinalMaskFragmentObjStruct->lengthsCount; i++) {
        free((char*)listInStreamSettingsTcpFinalMaskFragmentObjStruct->lengths[i]);

    }

    free((char**)listInStreamSettingsTcpFinalMaskFragmentObjStruct->lengths);
    free((char*)listInStreamSettingsTcpFinalMaskFragmentObjStruct->maxSplit);
    for (size_t i = 0; i < (size_t)listInStreamSettingsTcpFinalMaskFragmentObjStruct->delaysCount; i++) {
        free((char*)listInStreamSettingsTcpFinalMaskFragmentObjStruct->delays[i]);

    }

    free((char**)listInStreamSettingsTcpFinalMaskFragmentObjStruct->delays);
    free(listInStreamSettingsTcpFinalMaskFragmentObjStruct);

}

void jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomPacketObjectStructDelete(struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomPacketObjectStruct* listInStreamSettingsTcpFinalMaskHeaderCustomPacketObjStruct, size_t arraySize) {
    for (size_t i = 0; i < arraySize; i++) {
        struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomPacketObjectStruct* headerCustomPacket = &listInStreamSettingsTcpFinalMaskHeaderCustomPacketObjStruct[i];
        free((char*)headerCustomPacket->type);
        free((char*)headerCustomPacket->delay);
        free((char*)headerCustomPacket->rand);
        free((char*)headerCustomPacket->randRange);
        free((char*)headerCustomPacket->packet);

    }

    free(listInStreamSettingsTcpFinalMaskHeaderCustomPacketObjStruct);

}

void jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomGroupObjectStructDelete(struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomGroupObjectStruct* listInStreamSettingsTcpFinalMaskHeaderCustomGroupObjStruct, size_t arraySize) {
    for (size_t i = 0; i < arraySize; i++) {
        struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomGroupObjectStruct* headerCustomGroup = &listInStreamSettingsTcpFinalMaskHeaderCustomGroupObjStruct[i];
        if (headerCustomGroup->listInStreamSettingsTcpFinalMaskHeaderCustomPacketStruct) {
            jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomPacketObjectStructDelete(headerCustomGroup->listInStreamSettingsTcpFinalMaskHeaderCustomPacketStruct, headerCustomGroup->jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomPacketStructSize);
            headerCustomGroup->listInStreamSettingsTcpFinalMaskHeaderCustomPacketStruct = NULL;

        }

    }

    free(listInStreamSettingsTcpFinalMaskHeaderCustomGroupObjStruct);

}

void jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomObjectStructDelete(struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomObjectStruct* listInStreamSettingsTcpFinalMaskHeaderCustomObjStruct) {
    if (listInStreamSettingsTcpFinalMaskHeaderCustomObjStruct->listInStreamSettingsTcpFinalMaskHeaderCustomClientGroupStruct) {
        jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomGroupObjectStructDelete(listInStreamSettingsTcpFinalMaskHeaderCustomObjStruct->listInStreamSettingsTcpFinalMaskHeaderCustomClientGroupStruct, listInStreamSettingsTcpFinalMaskHeaderCustomObjStruct->jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomClientGroupStructSize);
        listInStreamSettingsTcpFinalMaskHeaderCustomObjStruct->listInStreamSettingsTcpFinalMaskHeaderCustomClientGroupStruct = NULL;

    }

    if (listInStreamSettingsTcpFinalMaskHeaderCustomObjStruct->listInStreamSettingsTcpFinalMaskHeaderCustomServerGroupStruct) {
        jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomGroupObjectStructDelete(listInStreamSettingsTcpFinalMaskHeaderCustomObjStruct->listInStreamSettingsTcpFinalMaskHeaderCustomServerGroupStruct, listInStreamSettingsTcpFinalMaskHeaderCustomObjStruct->jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomServerGroupStructSize);
        listInStreamSettingsTcpFinalMaskHeaderCustomObjStruct->listInStreamSettingsTcpFinalMaskHeaderCustomServerGroupStruct = NULL;

    }

    free(listInStreamSettingsTcpFinalMaskHeaderCustomObjStruct);

}

void jsonListInboundStreamSettingsTcpFinalMaskSudokuObjectStructDelete(struct jsonListInboundStreamSettingsTcpFinalMaskSudokuObjectStruct* listInStreamSettingsTcpFinalMaskSudokuObjStruct) {
    free((char*)listInStreamSettingsTcpFinalMaskSudokuObjStruct->password);
    for (size_t i = 0; i < (size_t)listInStreamSettingsTcpFinalMaskSudokuObjStruct->customTablesCount; i++) {
        free((char*)listInStreamSettingsTcpFinalMaskSudokuObjStruct->customTables[i]);

    }

    free((char**)listInStreamSettingsTcpFinalMaskSudokuObjStruct->customTables);
    free((char*)listInStreamSettingsTcpFinalMaskSudokuObjStruct->ascii);
    free((char*)listInStreamSettingsTcpFinalMaskSudokuObjStruct->customTable);
    free(listInStreamSettingsTcpFinalMaskSudokuObjStruct);

}

void jsonListInboundStreamSettingsTcpFinalMaskXmcProfileObjectStructDelete(struct jsonListInboundStreamSettingsTcpFinalMaskXmcProfileObjectStruct* listInStreamSettingsTcpFinalMaskXmcProfileObjStruct, size_t arraySize) {
    for (size_t i = 0; i < arraySize; i++) {
        struct jsonListInboundStreamSettingsTcpFinalMaskXmcProfileObjectStruct* xmcProfile = &listInStreamSettingsTcpFinalMaskXmcProfileObjStruct[i];
        free((char*)xmcProfile->username);
        free((char*)xmcProfile->uuid);
        free((char*)xmcProfile->texturesValue);
        free((char*)xmcProfile->texturesSignature);

    }

    free(listInStreamSettingsTcpFinalMaskXmcProfileObjStruct);

}

void jsonListInboundStreamSettingsTcpFinalMaskXmcObjectStructDelete(struct jsonListInboundStreamSettingsTcpFinalMaskXmcObjectStruct* listInStreamSettingsTcpFinalMaskXmcObjStruct) {
    free((char*)listInStreamSettingsTcpFinalMaskXmcObjStruct->hostname);
    if (listInStreamSettingsTcpFinalMaskXmcObjStruct->listInStreamSettingsTcpFinalMaskXmcProfileStruct) {
        jsonListInboundStreamSettingsTcpFinalMaskXmcProfileObjectStructDelete(listInStreamSettingsTcpFinalMaskXmcObjStruct->listInStreamSettingsTcpFinalMaskXmcProfileStruct, (size_t)listInStreamSettingsTcpFinalMaskXmcObjStruct->jsonListInboundStreamSettingsTcpFinalMaskXmcProfileStructSize);
        listInStreamSettingsTcpFinalMaskXmcObjStruct->listInStreamSettingsTcpFinalMaskXmcProfileStruct = NULL;

    }

    free((char*)listInStreamSettingsTcpFinalMaskXmcObjStruct->password);
    free(listInStreamSettingsTcpFinalMaskXmcObjStruct);

}

void jsonListInboundStreamSettingsTcpFinalMaskTcpObjectStructDelete(struct jsonListInboundStreamSettingsTcpFinalMaskTcpObjectStruct* listInStreamSettingsTcpFinalMaskTcpObjStruct) {
    free((char*)listInStreamSettingsTcpFinalMaskTcpObjStruct->type);

    if (listInStreamSettingsTcpFinalMaskTcpObjStruct->listInStreamSettingsTcpFinalMaskFragmentObjStruct) {
        jsonListInboundStreamSettingsTcpFinalMaskFragmentObjectStructDelete(listInStreamSettingsTcpFinalMaskTcpObjStruct->listInStreamSettingsTcpFinalMaskFragmentObjStruct);
        listInStreamSettingsTcpFinalMaskTcpObjStruct->listInStreamSettingsTcpFinalMaskFragmentObjStruct = NULL;

    }

    if (listInStreamSettingsTcpFinalMaskTcpObjStruct->listInStreamSettingsTcpFinalMaskHeaderCustomObjStruct) {
        jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomObjectStructDelete(listInStreamSettingsTcpFinalMaskTcpObjStruct->listInStreamSettingsTcpFinalMaskHeaderCustomObjStruct);
        listInStreamSettingsTcpFinalMaskTcpObjStruct->listInStreamSettingsTcpFinalMaskHeaderCustomObjStruct = NULL;

    }

    if (listInStreamSettingsTcpFinalMaskTcpObjStruct->listInStreamSettingsTcpFinalMaskSudokuObjStruct) {
        jsonListInboundStreamSettingsTcpFinalMaskSudokuObjectStructDelete(listInStreamSettingsTcpFinalMaskTcpObjStruct->listInStreamSettingsTcpFinalMaskSudokuObjStruct);
        listInStreamSettingsTcpFinalMaskTcpObjStruct->listInStreamSettingsTcpFinalMaskSudokuObjStruct = NULL;

    }

    if (listInStreamSettingsTcpFinalMaskTcpObjStruct->listInStreamSettingsTcpFinalMaskXmcObjStruct) {
        jsonListInboundStreamSettingsTcpFinalMaskXmcObjectStructDelete(listInStreamSettingsTcpFinalMaskTcpObjStruct->listInStreamSettingsTcpFinalMaskXmcObjStruct);
        listInStreamSettingsTcpFinalMaskTcpObjStruct->listInStreamSettingsTcpFinalMaskXmcObjStruct = NULL;

    }

    }

void jsonListInboundStreamSettingsTcpFinalMaskObjectStructDelete(struct jsonListInboundStreamSettingsTcpFinalMaskObjectStruct* listInStreamSettingsTcpFinalMaskObjStruct) {
    for (size_t i = 0; i < listInStreamSettingsTcpFinalMaskObjStruct->jsonListInboundStreamSettingsTcpFinalMaskTcpStructSize; i++) {
        struct jsonListInboundStreamSettingsTcpFinalMaskTcpObjectStruct* finalMaskTcp = &listInStreamSettingsTcpFinalMaskObjStruct->listInStreamSettingsTcpFinalMaskTcpStruct[i];
        jsonListInboundStreamSettingsTcpFinalMaskTcpObjectStructDelete(finalMaskTcp);

    }

    free(listInStreamSettingsTcpFinalMaskObjStruct->listInStreamSettingsTcpFinalMaskTcpStruct);

    free(listInStreamSettingsTcpFinalMaskObjStruct);

}

void jsonListInboundStreamSettingsWSFinalMaskFragmentObjectStructDelete(struct jsonListInboundStreamSettingsWSFinalMaskFragmentObjectStruct* listInStreamSettingsWSFinalMaskFragmentObjStruct) {
    free((char*)listInStreamSettingsWSFinalMaskFragmentObjStruct->packets);
    for (size_t i = 0; i < (size_t)listInStreamSettingsWSFinalMaskFragmentObjStruct->lengthsCount; i++) {
        free((char*)listInStreamSettingsWSFinalMaskFragmentObjStruct->lengths[i]);

    }

    free((char**)listInStreamSettingsWSFinalMaskFragmentObjStruct->lengths);
    free((char*)listInStreamSettingsWSFinalMaskFragmentObjStruct->maxSplit);
    for (size_t i = 0; i < (size_t)listInStreamSettingsWSFinalMaskFragmentObjStruct->delaysCount; i++) {
        free((char*)listInStreamSettingsWSFinalMaskFragmentObjStruct->delays[i]);

    }

    free((char**)listInStreamSettingsWSFinalMaskFragmentObjStruct->delays);
    free(listInStreamSettingsWSFinalMaskFragmentObjStruct);

}

void jsonListInboundStreamSettingsWSFinalMaskHeaderCustomPacketObjectStructDelete(struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomPacketObjectStruct* listInStreamSettingsWSFinalMaskHeaderCustomPacketObjStruct, size_t arraySize) {
    for (size_t i = 0; i < arraySize; i++) {
        struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomPacketObjectStruct* headerCustomPacket = &listInStreamSettingsWSFinalMaskHeaderCustomPacketObjStruct[i];
        free((char*)headerCustomPacket->type);
        free((char*)headerCustomPacket->delay);
        free((char*)headerCustomPacket->rand);
        free((char*)headerCustomPacket->randRange);
        free((char*)headerCustomPacket->packet);

    }

    free(listInStreamSettingsWSFinalMaskHeaderCustomPacketObjStruct);

}

void jsonListInboundStreamSettingsWSFinalMaskHeaderCustomGroupObjectStructDelete(struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomGroupObjectStruct* listInStreamSettingsWSFinalMaskHeaderCustomGroupObjStruct, size_t arraySize) {
    for (size_t i = 0; i < arraySize; i++) {
        struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomGroupObjectStruct* headerCustomGroup = &listInStreamSettingsWSFinalMaskHeaderCustomGroupObjStruct[i];
        if (headerCustomGroup->listInStreamSettingsWSFinalMaskHeaderCustomPacketStruct) {
            jsonListInboundStreamSettingsWSFinalMaskHeaderCustomPacketObjectStructDelete(headerCustomGroup->listInStreamSettingsWSFinalMaskHeaderCustomPacketStruct, headerCustomGroup->jsonListInboundStreamSettingsWSFinalMaskHeaderCustomPacketStructSize);
            headerCustomGroup->listInStreamSettingsWSFinalMaskHeaderCustomPacketStruct = NULL;

        }

    }

    free(listInStreamSettingsWSFinalMaskHeaderCustomGroupObjStruct);

}

void jsonListInboundStreamSettingsWSFinalMaskHeaderCustomObjectStructDelete(struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomObjectStruct* listInStreamSettingsWSFinalMaskHeaderCustomObjStruct) {
    if (listInStreamSettingsWSFinalMaskHeaderCustomObjStruct->listInStreamSettingsWSFinalMaskHeaderCustomClientGroupStruct) {
        jsonListInboundStreamSettingsWSFinalMaskHeaderCustomGroupObjectStructDelete(listInStreamSettingsWSFinalMaskHeaderCustomObjStruct->listInStreamSettingsWSFinalMaskHeaderCustomClientGroupStruct, listInStreamSettingsWSFinalMaskHeaderCustomObjStruct->jsonListInboundStreamSettingsWSFinalMaskHeaderCustomClientGroupStructSize);
        listInStreamSettingsWSFinalMaskHeaderCustomObjStruct->listInStreamSettingsWSFinalMaskHeaderCustomClientGroupStruct = NULL;

    }

    if (listInStreamSettingsWSFinalMaskHeaderCustomObjStruct->listInStreamSettingsWSFinalMaskHeaderCustomServerGroupStruct) {
        jsonListInboundStreamSettingsWSFinalMaskHeaderCustomGroupObjectStructDelete(listInStreamSettingsWSFinalMaskHeaderCustomObjStruct->listInStreamSettingsWSFinalMaskHeaderCustomServerGroupStruct, listInStreamSettingsWSFinalMaskHeaderCustomObjStruct->jsonListInboundStreamSettingsWSFinalMaskHeaderCustomServerGroupStructSize);
        listInStreamSettingsWSFinalMaskHeaderCustomObjStruct->listInStreamSettingsWSFinalMaskHeaderCustomServerGroupStruct = NULL;

    }

    free(listInStreamSettingsWSFinalMaskHeaderCustomObjStruct);

}

void jsonListInboundStreamSettingsWSFinalMaskSudokuObjectStructDelete(struct jsonListInboundStreamSettingsWSFinalMaskSudokuObjectStruct* listInStreamSettingsWSFinalMaskSudokuObjStruct) {
    free((char*)listInStreamSettingsWSFinalMaskSudokuObjStruct->password);
    for (size_t i = 0; i < (size_t)listInStreamSettingsWSFinalMaskSudokuObjStruct->customTablesCount; i++) {
        free((char*)listInStreamSettingsWSFinalMaskSudokuObjStruct->customTables[i]);

    }

    free((char**)listInStreamSettingsWSFinalMaskSudokuObjStruct->customTables);
    free((char*)listInStreamSettingsWSFinalMaskSudokuObjStruct->ascii);
    free((char*)listInStreamSettingsWSFinalMaskSudokuObjStruct->customTable);
    free(listInStreamSettingsWSFinalMaskSudokuObjStruct);

}

void jsonListInboundStreamSettingsWSFinalMaskXmcProfileObjectStructDelete(struct jsonListInboundStreamSettingsWSFinalMaskXmcProfileObjectStruct* listInStreamSettingsWSFinalMaskXmcProfileObjStruct, size_t arraySize) {
    for (size_t i = 0; i < arraySize; i++) {
        struct jsonListInboundStreamSettingsWSFinalMaskXmcProfileObjectStruct* xmcProfile = &listInStreamSettingsWSFinalMaskXmcProfileObjStruct[i];
        free((char*)xmcProfile->username);
        free((char*)xmcProfile->uuid);
        free((char*)xmcProfile->texturesValue);
        free((char*)xmcProfile->texturesSignature);

    }

    free(listInStreamSettingsWSFinalMaskXmcProfileObjStruct);

}

void jsonListInboundStreamSettingsWSFinalMaskXmcObjectStructDelete(struct jsonListInboundStreamSettingsWSFinalMaskXmcObjectStruct* listInStreamSettingsWSFinalMaskXmcObjStruct) {
    free((char*)listInStreamSettingsWSFinalMaskXmcObjStruct->hostname);
    if (listInStreamSettingsWSFinalMaskXmcObjStruct->listInStreamSettingsWSFinalMaskXmcProfileStruct) {
        jsonListInboundStreamSettingsWSFinalMaskXmcProfileObjectStructDelete(listInStreamSettingsWSFinalMaskXmcObjStruct->listInStreamSettingsWSFinalMaskXmcProfileStruct, (size_t)listInStreamSettingsWSFinalMaskXmcObjStruct->jsonListInboundStreamSettingsWSFinalMaskXmcProfileStructSize);
        listInStreamSettingsWSFinalMaskXmcObjStruct->listInStreamSettingsWSFinalMaskXmcProfileStruct = NULL;

    }

    free((char*)listInStreamSettingsWSFinalMaskXmcObjStruct->password);
    free(listInStreamSettingsWSFinalMaskXmcObjStruct);

}

void jsonListInboundStreamSettingsWSFinalMaskTcpObjectStructDelete(struct jsonListInboundStreamSettingsWSFinalMaskTcpObjectStruct* listInStreamSettingsWSFinalMaskTcpObjStruct) {
    free((char*)listInStreamSettingsWSFinalMaskTcpObjStruct->type);

    if (listInStreamSettingsWSFinalMaskTcpObjStruct->listInStreamSettingsWSFinalMaskFragmentObjStruct) {
        jsonListInboundStreamSettingsWSFinalMaskFragmentObjectStructDelete(listInStreamSettingsWSFinalMaskTcpObjStruct->listInStreamSettingsWSFinalMaskFragmentObjStruct);
        listInStreamSettingsWSFinalMaskTcpObjStruct->listInStreamSettingsWSFinalMaskFragmentObjStruct = NULL;

    }

    if (listInStreamSettingsWSFinalMaskTcpObjStruct->listInStreamSettingsWSFinalMaskHeaderCustomObjStruct) {
        jsonListInboundStreamSettingsWSFinalMaskHeaderCustomObjectStructDelete(listInStreamSettingsWSFinalMaskTcpObjStruct->listInStreamSettingsWSFinalMaskHeaderCustomObjStruct);
        listInStreamSettingsWSFinalMaskTcpObjStruct->listInStreamSettingsWSFinalMaskHeaderCustomObjStruct = NULL;

    }

    if (listInStreamSettingsWSFinalMaskTcpObjStruct->listInStreamSettingsWSFinalMaskSudokuObjStruct) {
        jsonListInboundStreamSettingsWSFinalMaskSudokuObjectStructDelete(listInStreamSettingsWSFinalMaskTcpObjStruct->listInStreamSettingsWSFinalMaskSudokuObjStruct);
        listInStreamSettingsWSFinalMaskTcpObjStruct->listInStreamSettingsWSFinalMaskSudokuObjStruct = NULL;

    }

    if (listInStreamSettingsWSFinalMaskTcpObjStruct->listInStreamSettingsWSFinalMaskXmcObjStruct) {
        jsonListInboundStreamSettingsWSFinalMaskXmcObjectStructDelete(listInStreamSettingsWSFinalMaskTcpObjStruct->listInStreamSettingsWSFinalMaskXmcObjStruct);
        listInStreamSettingsWSFinalMaskTcpObjStruct->listInStreamSettingsWSFinalMaskXmcObjStruct = NULL;

    }

    }

void jsonListInboundStreamSettingsWSFinalMaskObjectStructDelete(struct jsonListInboundStreamSettingsWSFinalMaskObjectStruct* listInStreamSettingsWSFinalMaskObjStruct) {
    for (size_t i = 0; i < listInStreamSettingsWSFinalMaskObjStruct->jsonListInboundStreamSettingsWSFinalMaskTcpStructSize; i++) {
        struct jsonListInboundStreamSettingsWSFinalMaskTcpObjectStruct* finalMaskTcp = &listInStreamSettingsWSFinalMaskObjStruct->listInStreamSettingsWSFinalMaskTcpStruct[i];
        jsonListInboundStreamSettingsWSFinalMaskTcpObjectStructDelete(finalMaskTcp);

    }

    free(listInStreamSettingsWSFinalMaskObjStruct->listInStreamSettingsWSFinalMaskTcpStruct);

    free(listInStreamSettingsWSFinalMaskObjStruct);

}

void jsonListInboundStreamSettingsTcpSockoptObjectStructDelete(struct jsonListInboundStreamSettingsTcpSockoptObjectStruct* listInStreamSettingsTcpSockoptObjStruct) {
    if (listInStreamSettingsTcpSockoptObjStruct->tproxyEnabled) {
        free((char*)listInStreamSettingsTcpSockoptObjStruct->tproxy);

    }

    if (listInStreamSettingsTcpSockoptObjStruct->tcpcongestionEnabled) {
        free((char*)listInStreamSettingsTcpSockoptObjStruct->tcpcongestion);

    }

    if (listInStreamSettingsTcpSockoptObjStruct->listInStreamSettingsTcpSockoptObjCustomScokArrStructEnabled) {
        for (size_t i = 0; i < listInStreamSettingsTcpSockoptObjStruct->jsonListInboundStreamSettingsTcpSockoptCustomSockOptArrayStructSize; i++) {
            struct jsonListInboundStreamSettingsTcpSockoptObjectCustomSockOptArrayStruct* customSockopt = &listInStreamSettingsTcpSockoptObjStruct->listInStreamSettingsTcpSockoptObjCustomScokArrStruct[i];
            free((char*)customSockopt->system);
            free((char*)customSockopt->type);
            free((char*)customSockopt->level);
            free((char*)customSockopt->opt);
            free((char*)customSockopt->value);

        }

        free(listInStreamSettingsTcpSockoptObjStruct->listInStreamSettingsTcpSockoptObjCustomScokArrStruct);

        listInStreamSettingsTcpSockoptObjStruct->listInStreamSettingsTcpSockoptObjCustomScokArrStruct = NULL;

    }

    free(listInStreamSettingsTcpSockoptObjStruct);

}

void jsonListInboundStreamSettingsMKcpSockoptObjectStructDelete(struct jsonListInboundStreamSettingsMKcpSockoptObjectStruct* listInStreamSettingsMKcpSockoptObjStruct) {
    if (listInStreamSettingsMKcpSockoptObjStruct->tproxyEnabled) {
        free((char*)listInStreamSettingsMKcpSockoptObjStruct->tproxy);

    }

    if (listInStreamSettingsMKcpSockoptObjStruct->tcpcongestionEnabled) {
        free((char*)listInStreamSettingsMKcpSockoptObjStruct->tcpcongestion);

    }

    if (listInStreamSettingsMKcpSockoptObjStruct->listInStreamSettingsMKcpSockoptObjCustomScokArrStructEnabled) {
        for (size_t i = 0; i < listInStreamSettingsMKcpSockoptObjStruct->jsonListInboundStreamSettingsMKcpSockoptCustomSockOptArrayStructSize; i++) {
            struct jsonListInboundStreamSettingsMKcpSockoptObjectCustomSockOptArrayStruct* customSockopt = &listInStreamSettingsMKcpSockoptObjStruct->listInStreamSettingsMKcpSockoptObjCustomScokArrStruct[i];
            free((char*)customSockopt->system);
            free((char*)customSockopt->type);
            free((char*)customSockopt->level);
            free((char*)customSockopt->opt);
            free((char*)customSockopt->value);

        }

        free(listInStreamSettingsMKcpSockoptObjStruct->listInStreamSettingsMKcpSockoptObjCustomScokArrStruct);

        listInStreamSettingsMKcpSockoptObjStruct->listInStreamSettingsMKcpSockoptObjCustomScokArrStruct = NULL;

    }

    free(listInStreamSettingsMKcpSockoptObjStruct);

}

void jsonListInboundStreamSettingsWSSockoptObjectStructDelete(struct jsonListInboundStreamSettingsWSSockoptObjectStruct* listInStreamSettingsWSSockoptObjStruct) {
    if (listInStreamSettingsWSSockoptObjStruct->tproxyEnabled) {
        free((char*)listInStreamSettingsWSSockoptObjStruct->tproxy);

    }

    if (listInStreamSettingsWSSockoptObjStruct->tcpcongestionEnabled) {
        free((char*)listInStreamSettingsWSSockoptObjStruct->tcpcongestion);

    }

    if (listInStreamSettingsWSSockoptObjStruct->listInStreamSettingsWSSockoptObjCustomScokArrStructEnabled) {
        for (size_t i = 0; i < listInStreamSettingsWSSockoptObjStruct->jsonListInboundStreamSettingsWSSockoptCustomSockOptArrayStructSize; i++) {
            struct jsonListInboundStreamSettingsWSSockoptObjectCustomSockOptArrayStruct* customSockopt = &listInStreamSettingsWSSockoptObjStruct->listInStreamSettingsWSSockoptObjCustomScokArrStruct[i];
            free((char*)customSockopt->system);
            free((char*)customSockopt->type);
            free((char*)customSockopt->level);
            free((char*)customSockopt->opt);
            free((char*)customSockopt->value);

        }

        free(listInStreamSettingsWSSockoptObjStruct->listInStreamSettingsWSSockoptObjCustomScokArrStruct);

    }

    for (size_t i = 0; i < (size_t)listInStreamSettingsWSSockoptObjStruct->trustedXForwardedForCount; i++) {
        free((char*)listInStreamSettingsWSSockoptObjStruct->trustedXForwardedFor[i]);

    }

    free((char**)listInStreamSettingsWSSockoptObjStruct->trustedXForwardedFor);
    free(listInStreamSettingsWSSockoptObjStruct);

}

void jsonListInboundSettingsClientsArrayStructDelete(struct jsonListInboundSettingsClientsArrayStruct* listInSettingsCliArrStruct, size_t arraySize) {
    for (size_t i = 0; i < arraySize; i++) {
        struct jsonListInboundSettingsClientsArrayStruct* settingsClients = &listInSettingsCliArrStruct[i];
        free((char*)settingsClients->auth);
        free((char*)settingsClients->comment);
        free((char*)settingsClients->email);
        free((char*)settingsClients->id);
        free((char*)settingsClients->password);
        free((char*)settingsClients->security);
        free((char*)settingsClients->subId);

    }

    free(listInSettingsCliArrStruct);

}

void jsonListInboundClientStatsArrayStructDelete(struct jsonListInboundClientStatsArrayStruct* listInCliStatsStruct, size_t arraySize) {
    for (size_t i = 0; i < arraySize; i++) {
        struct jsonListInboundClientStatsArrayStruct* cliStats = &listInCliStatsStruct[i];
        free((char*)cliStats->email);
        free((char*)cliStats->uuid);
        free((char*)cliStats->subId);

    }

    free(listInCliStatsStruct);

}

void jsonListInboundSettingsObjectStructDelete(struct jsonListInboundSettingsObjectStruct* listInSettingsObjStruct) {
    if (listInSettingsObjStruct->listInSettingsCliArrStruct) {
        jsonListInboundSettingsClientsArrayStructDelete(listInSettingsObjStruct->listInSettingsCliArrStruct, listInSettingsObjStruct->jsonListInboundSettingsClientsArrayStructSize);

        listInSettingsObjStruct->listInSettingsCliArrStruct = NULL;

    }

    free((char*)listInSettingsObjStruct->decryption);
    free((char*)listInSettingsObjStruct->encryption);

    free(listInSettingsObjStruct);

}

void jsonListInboundStreamSettingsObjectStructDelete(struct jsonListInboundStreamSettingsObjectStruct* listInStreamSettingsObjStruct) {
    free((char*)listInStreamSettingsObjStruct->network);
    free((char*)listInStreamSettingsObjStruct->security);

    if (listInStreamSettingsObjStruct->listInStreamSettingsTcpSettingsObjStruct) {
        jsonListInboundStreamSettingsTcpSettingsObjectStructDelete(listInStreamSettingsObjStruct->listInStreamSettingsTcpSettingsObjStruct);
        listInStreamSettingsObjStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;

    }

    if (listInStreamSettingsObjStruct->listInStreamSettingsMKcpSettingsObjStruct) {
        jsonListInboundStreamSettingsMKcpSettingsObjectStructDelete(listInStreamSettingsObjStruct->listInStreamSettingsMKcpSettingsObjStruct);
        listInStreamSettingsObjStruct->listInStreamSettingsMKcpSettingsObjStruct = NULL;

    }

    if (listInStreamSettingsObjStruct->listInStreamSettingsWSSettingsObjStruct) {
        jsonListInboundStreamSettingsWSSettingsObjectStructDelete(listInStreamSettingsObjStruct->listInStreamSettingsWSSettingsObjStruct);
        listInStreamSettingsObjStruct->listInStreamSettingsWSSettingsObjStruct = NULL;

    }

    if (listInStreamSettingsObjStruct->listInStreamSettingsTcpFinalMaskObjStruct) {
        jsonListInboundStreamSettingsTcpFinalMaskObjectStructDelete(listInStreamSettingsObjStruct->listInStreamSettingsTcpFinalMaskObjStruct);

        listInStreamSettingsObjStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;

    }

    if (listInStreamSettingsObjStruct->listInStreamSettingsMKcpFinalMaskObjStruct) {
        jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(listInStreamSettingsObjStruct->listInStreamSettingsMKcpFinalMaskObjStruct);
        listInStreamSettingsObjStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;

    }

    if (listInStreamSettingsObjStruct->listInStreamSettingsWSFinalMaskObjStruct) {
        jsonListInboundStreamSettingsWSFinalMaskObjectStructDelete(listInStreamSettingsObjStruct->listInStreamSettingsWSFinalMaskObjStruct);

        listInStreamSettingsObjStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;

    }

    if (listInStreamSettingsObjStruct->listInStreamSettingsGRPCFinalMaskObjStruct) {
        free(listInStreamSettingsObjStruct->listInStreamSettingsGRPCFinalMaskObjStruct);

        listInStreamSettingsObjStruct->listInStreamSettingsGRPCFinalMaskObjStruct = NULL;

    }

    if (listInStreamSettingsObjStruct->listInStreamSettingsHTTPUpgradeFinalMaskObjStruct) {
        free(listInStreamSettingsObjStruct->listInStreamSettingsHTTPUpgradeFinalMaskObjStruct);

        listInStreamSettingsObjStruct->listInStreamSettingsHTTPUpgradeFinalMaskObjStruct = NULL;

    }

    if (listInStreamSettingsObjStruct->listInStreamSettingsXHTTPFinalMaskObjStruct) {
        free(listInStreamSettingsObjStruct->listInStreamSettingsXHTTPFinalMaskObjStruct);

        listInStreamSettingsObjStruct->listInStreamSettingsXHTTPFinalMaskObjStruct = NULL;

    }

    if (listInStreamSettingsObjStruct->listInStreamSettingsTcpSockoptObjStruct) {
        jsonListInboundStreamSettingsTcpSockoptObjectStructDelete(listInStreamSettingsObjStruct->listInStreamSettingsTcpSockoptObjStruct);
        listInStreamSettingsObjStruct->listInStreamSettingsTcpSockoptObjStruct = NULL;

    }

    if (listInStreamSettingsObjStruct->listInStreamSettingsMKcpSockoptObjStruct) {
        jsonListInboundStreamSettingsMKcpSockoptObjectStructDelete(listInStreamSettingsObjStruct->listInStreamSettingsMKcpSockoptObjStruct);
        listInStreamSettingsObjStruct->listInStreamSettingsMKcpSockoptObjStruct = NULL;

    }

    if (listInStreamSettingsObjStruct->listInStreamSettingsWSSockoptObjStruct) {
        jsonListInboundStreamSettingsWSSockoptObjectStructDelete(listInStreamSettingsObjStruct->listInStreamSettingsWSSockoptObjStruct);

        listInStreamSettingsObjStruct->listInStreamSettingsWSSockoptObjStruct = NULL;

    }

    if (listInStreamSettingsObjStruct->listInStreamSettingsGRPCSockoptObjStruct) {
        free(listInStreamSettingsObjStruct->listInStreamSettingsGRPCSockoptObjStruct);

        listInStreamSettingsObjStruct->listInStreamSettingsGRPCSockoptObjStruct = NULL;

    }

    if (listInStreamSettingsObjStruct->listInStreamSettingsHTTPUpgradeSockoptObjStruct) {
        free(listInStreamSettingsObjStruct->listInStreamSettingsHTTPUpgradeSockoptObjStruct);

        listInStreamSettingsObjStruct->listInStreamSettingsHTTPUpgradeSockoptObjStruct = NULL;

    }

    if (listInStreamSettingsObjStruct->listInStreamSettingsXHTTPSockoptObjStruct) {
        free(listInStreamSettingsObjStruct->listInStreamSettingsXHTTPSockoptObjStruct);

        listInStreamSettingsObjStruct->listInStreamSettingsXHTTPSockoptObjStruct = NULL;

    }

    free(listInStreamSettingsObjStruct);

}

void jsonListInboundSniffingObjectStructDelete(struct jsonListInboundSniffingObjectStruct* listInSniffingObjStruct) {
    free((char*)listInSniffingObjStruct->enabled);

    free(listInSniffingObjStruct);

}

void jsonListInboundObjectStructDeleteElement(struct jsonListInboundObjectStruct* listInObj) {
    free((char*)listInObj->remark);
    free((char*)listInObj->trafficReset);

    if (listInObj->listInCliStatsStruct) {
        jsonListInboundClientStatsArrayStructDelete(listInObj->listInCliStatsStruct, listInObj->jsonListInboundClientStatsArrayStructSize);
        listInObj->listInCliStatsStruct = NULL;

    }

    free((char*)listInObj->listen);
    free((char*)listInObj->protocol);
    free((char*)listInObj->tag);
    free((char*)listInObj->shareAddrStrategy);
    free((char*)listInObj->shareAddr);
    free((char*)listInObj->originNodeGuid);
    
    if (listInObj->listInSettingsObjStruct) {
        jsonListInboundSettingsObjectStructDelete(listInObj->listInSettingsObjStruct);
        listInObj->listInSettingsObjStruct = NULL;

    }

    if (listInObj->listInStreamSettingsObjStruct) {
        jsonListInboundStreamSettingsObjectStructDelete(listInObj->listInStreamSettingsObjStruct);
        listInObj->listInStreamSettingsObjStruct = NULL;

    }

    if (listInObj->listInSniffingObjStruct) {
        jsonListInboundSniffingObjectStructDelete(listInObj->listInSniffingObjStruct);
        listInObj->listInSniffingObjStruct = NULL;

    }

}

void jsonListInboundObjectStructDelete(struct jsonListInboundObjectStruct* listInObjStruct, size_t arraySize) {
    for (size_t i = 0; i < arraySize; i++) {
        jsonListInboundObjectStructDeleteElement(&listInObjStruct[i]);

    }

    free(listInObjStruct);

}

void jsonListInboundStructDelete(struct jsonListInboundStruct* listInStruct) {
    free((char*)listInStruct->msg);

    if (listInStruct->listInObjStruct) {
        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, listInStruct->jsonListInboundObjectStructSize);
        listInStruct->listInObjStruct = NULL;

    }

    free(listInStruct);

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
            struct jsonListInboundClientStatsArrayStruct* cliStats = &listInCliStatsArrStruct[i];
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
                cliStats->id = (int64_t)cJSON_GetObjectItem(arrItem, "id")->valuedouble;
                cliStats->inboundId = (int64_t)cJSON_GetObjectItem(arrItem, "inboundId")->valuedouble;
                cliStats->enable = (unsigned char)cJSON_GetObjectItem(arrItem, "enable")->valueint;

                char* email = cJSON_GetObjectItem(arrItem, "email")->valuestring;
                size_t emailLen = strlen(email);
                char* emailCopy = (char*)malloc((emailLen + 1) * sizeof(char));
                strncpy(emailCopy, email, emailLen);
                emailCopy[emailLen] = '\0';
                cliStats->email = emailCopy;

                char* uuid = cJSON_GetObjectItem(arrItem, "uuid")->valuestring;
                size_t uuidLen = strlen(uuid);
                char* uuidCopy = (char*)malloc((uuidLen + 1) * sizeof(char));
                strncpy(uuidCopy, uuid, uuidLen);
                uuidCopy[uuidLen] = '\0';
                cliStats->uuid = uuidCopy;

                char* subId = cJSON_GetObjectItem(arrItem, "subId")->valuestring;
                size_t subIdLen = strlen(subId);
                char* subIdCopy = (char*)malloc((subIdLen + 1) * sizeof(char));
                strncpy(subIdCopy, subId, subIdLen);
                subIdCopy[subIdLen] = '\0';
                cliStats->subId = subIdCopy;

                cliStats->up = (int64_t)cJSON_GetObjectItem(arrItem, "up")->valuedouble;
                cliStats->down = (int64_t)cJSON_GetObjectItem(arrItem, "down")->valuedouble;
                cliStats->expiryTime = (int64_t)cJSON_GetObjectItem(arrItem, "expiryTime")->valuedouble;

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

enum networkTypesEnum {
    NETWORKTYPE_TCP,
    NETWORKTYPE_KCP,
    NETWORKTYPE_WS,
    NETWORKTYPE_GRPC,
    NETWORKTYPE_HTTPUPGRADE,
    NETWORKTYPE_XHTTP,
    NETWORKTYPE_COUNT

};

static int jsonListInboundStreamSettingsSockoptParse(cJSON* sockOptObj, struct jsonListInboundStreamSettingsObjectStruct* streamSettingsStruct, enum networkTypesEnum nType) {
    // sockopt holds the socket options, the real client ip itself is a 3-x-ui
    // panel option and is not present verbatim in the json, the availability of
    // other objects at the json indicates whether the user has set it to which
    // value at the panel, on the cjson header and src we just ignore it, also
    // the trusted X-Forwarded-For field is always empty here

    // this json has too many dynamic fields therefore object / array availability is checked after allocating the struct, and on parsing them
    switch (nType) {
        case NETWORKTYPE_TCP:
        {
            streamSettingsStruct->listInStreamSettingsTcpSockoptObjStruct = (struct jsonListInboundStreamSettingsTcpSockoptObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsTcpSockoptObjectStruct));
            if (!streamSettingsStruct->listInStreamSettingsTcpSockoptObjStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsTcpSockoptObjStruct is a null pointer, failed to allocate memory");

                return 0;

            }

            struct jsonListInboundStreamSettingsTcpSockoptObjectStruct* tcpSocketStruct = streamSettingsStruct->listInStreamSettingsTcpSockoptObjStruct;

            tcpSocketStruct->listInStreamSettingsTcpSockoptObjCustomScokArrStruct = NULL;
            tcpSocketStruct->listInStreamSettingsTcpSockoptObjCustomScokArrStructEnabled = 0;
            tcpSocketStruct->jsonListInboundStreamSettingsTcpSockoptCustomSockOptArrayStructSize = 0;

            if (cJSON_HasObjectItem(sockOptObj, "acceptProxyProtocol")) {
                tcpSocketStruct->acceptProxyProtocolEnabled = 1;

                tcpSocketStruct->acceptProxyProtocol = cJSON_IsTrue(cJSON_GetObjectItem(sockOptObj, "acceptProxyProtocol"));

            } else {
                tcpSocketStruct->acceptProxyProtocolEnabled = 0;

            }

            if (cJSON_HasObjectItem(sockOptObj, "tcpFastOpen")) {
                tcpSocketStruct->tcpFastOpenEnabled = 1;

                tcpSocketStruct->tcpFastOpen = cJSON_IsTrue(cJSON_GetObjectItem(sockOptObj, "tcpFastOpen"));

            } else {
                tcpSocketStruct->tcpFastOpenEnabled = 0;

            }

            if (cJSON_HasObjectItem(sockOptObj, "tproxy")) {
                tcpSocketStruct->tproxyEnabled = 1;

                char* tproxy = cJSON_GetObjectItem(sockOptObj, "tproxy")->valuestring;
                size_t tproxyLen = strlen(tproxy);
                char* tproxyCopy = (char*)malloc((tproxyLen + 1) * sizeof(char));
                strncpy(tproxyCopy, tproxy, tproxyLen);
                tproxyCopy[tproxyLen] = '\0';
                tcpSocketStruct->tproxy = tproxyCopy;

            } else {
                tcpSocketStruct->tproxyEnabled = 0;

            }

            if (cJSON_HasObjectItem(sockOptObj, "penetrate")) {
                tcpSocketStruct->penetrateEnabled = 1;

                tcpSocketStruct->penetrate = cJSON_IsTrue(cJSON_GetObjectItem(sockOptObj, "penetrate"));

            } else {
                tcpSocketStruct->penetrateEnabled = 0;

            }

            if (cJSON_HasObjectItem(sockOptObj, "tcpcongestion")) {
                tcpSocketStruct->tcpcongestionEnabled = 1;

                char* tcpcongestion = cJSON_GetObjectItem(sockOptObj, "tcpcongestion")->valuestring;
                size_t tcpcongestionLen = strlen(tcpcongestion);
                char* tcpcongestionCopy = (char*)malloc((tcpcongestionLen + 1) * sizeof(char));
                strncpy(tcpcongestionCopy, tcpcongestion, tcpcongestionLen);
                tcpcongestionCopy[tcpcongestionLen] = '\0';
                tcpSocketStruct->tcpcongestion = tcpcongestionCopy;

            } else {
                tcpSocketStruct->tcpcongestionEnabled = 0;

            }

            if (cJSON_HasObjectItem(sockOptObj, "V6Only")) {
                tcpSocketStruct->V6OnlyEnabled = 1;
                
                tcpSocketStruct->V6Only = cJSON_IsTrue(cJSON_GetObjectItem(sockOptObj, "V6Only"));

            } else {
                tcpSocketStruct->V6OnlyEnabled = 0;

            }

            if (
                cJSON_HasObjectItem(sockOptObj, "customSockopt") &&
                cJSON_IsArray(cJSON_GetObjectItem(sockOptObj, "customSockopt"))
               ) {
                cJSON* customSockoptArr = cJSON_GetObjectItem(sockOptObj, "customSockopt");
                size_t customSockoptArrLen = cJSON_GetArraySize(customSockoptArr);
                if (customSockoptArrLen) {
                    tcpSocketStruct->listInStreamSettingsTcpSockoptObjCustomScokArrStruct = (struct jsonListInboundStreamSettingsTcpSockoptObjectCustomSockOptArrayStruct*)malloc(customSockoptArrLen * sizeof(struct jsonListInboundStreamSettingsTcpSockoptObjectCustomSockOptArrayStruct));
                    if (!tcpSocketStruct->listInStreamSettingsTcpSockoptObjCustomScokArrStruct) {
                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsTcpSockoptObjCustomScokArrStruct is a null pointer, failed to allocate memory");

                        return 0;

                    }

                    tcpSocketStruct->listInStreamSettingsTcpSockoptObjCustomScokArrStructEnabled = 1;

                    tcpSocketStruct->jsonListInboundStreamSettingsTcpSockoptCustomSockOptArrayStructSize = customSockoptArrLen;

                    for (size_t i = 0; i < customSockoptArrLen; i++) {
                        struct jsonListInboundStreamSettingsTcpSockoptObjectCustomSockOptArrayStruct* customSockOptArrStruct = tcpSocketStruct->listInStreamSettingsTcpSockoptObjCustomScokArrStruct;

                        customSockOptArrStruct[i].system = NULL;
                        customSockOptArrStruct[i].type = NULL;
                        customSockOptArrStruct[i].level = NULL;
                        customSockOptArrStruct[i].opt = NULL;
                        customSockOptArrStruct[i].value = NULL;

                        cJSON* customSockoptArrItem = cJSON_GetArrayItem(customSockoptArr, i);
                        if (
                            // also has the "system" field if set
                            cJSON_HasObjectItem(customSockoptArrItem, "type") &&
                            cJSON_HasObjectItem(customSockoptArrItem, "level") &&
                            cJSON_HasObjectItem(customSockoptArrItem, "opt") &&
                            cJSON_HasObjectItem(customSockoptArrItem, "value")
                           ) {

                            if (cJSON_HasObjectItem(customSockoptArrItem, "system")) {
                                char* system = cJSON_GetObjectItem(customSockoptArrItem, "system")->valuestring;
                                size_t systemLen = strlen(system);
                                char* systemCopy = (char*)malloc((systemLen + 1) * sizeof(char));
                                strncpy(systemCopy, system, systemLen);
                                systemCopy[systemLen] = '\0';
                                customSockOptArrStruct[i].system = systemCopy;

                            } else {
                                customSockOptArrStruct[i].system = NULL;

                            }

                            char* type = cJSON_GetObjectItem(customSockoptArrItem, "type")->valuestring;
                            size_t typeLen = strlen(type);
                            char* typeCopy = (char*)malloc((typeLen + 1) * sizeof(char));
                            strncpy(typeCopy, type, typeLen);
                            typeCopy[typeLen] = '\0';
                            customSockOptArrStruct[i].type = typeCopy;

                            char* level = cJSON_GetObjectItem(customSockoptArrItem, "level")->valuestring;
                            size_t levelLen = strlen(level);
                            char* levelCopy = (char*)malloc((levelLen + 1) * sizeof(char));
                            strncpy(levelCopy, level, levelLen);
                            levelCopy[levelLen] = '\0';
                            customSockOptArrStruct[i].level = levelCopy;

                            char* opt = cJSON_GetObjectItem(customSockoptArrItem, "opt")->valuestring;
                            size_t optLen = strlen(opt);
                            char* optCopy = (char*)malloc((optLen + 1) * sizeof(char));
                            strncpy(optCopy, opt, optLen);
                            optCopy[optLen] = '\0';
                            customSockOptArrStruct[i].opt = optCopy;

                            char* value = cJSON_GetObjectItem(customSockoptArrItem, "value")->valuestring;
                            size_t valueLen = strlen(value);
                            char* valueCopy = (char*)malloc((valueLen + 1) * sizeof(char));
                            strncpy(valueCopy, value, valueLen);
                            valueCopy[valueLen] = '\0';
                            customSockOptArrStruct[i].value = valueCopy;

                        } else {
                            // TODO
                        }

                    }

                } else {
                    // empty array, the custom sockopt fields stay at their default null / zero values

                }

            } else {
                // the object is absent or not an array, the custom sockopt fields stay at their default null / zero values

            }

            // tcp masks remaining

            break;

        }
        case NETWORKTYPE_WS:
        {
            streamSettingsStruct->listInStreamSettingsWSSockoptObjStruct = (struct jsonListInboundStreamSettingsWSSockoptObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsWSSockoptObjectStruct));
            if (!streamSettingsStruct->listInStreamSettingsWSSockoptObjStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsWSSockoptObjStruct is a null pointer, failed to allocate memory");

                return 0;

            }

            struct jsonListInboundStreamSettingsWSSockoptObjectStruct* wsSocketStruct = streamSettingsStruct->listInStreamSettingsWSSockoptObjStruct;

            wsSocketStruct->listInStreamSettingsWSSockoptObjCustomScokArrStruct = NULL;
            wsSocketStruct->listInStreamSettingsWSSockoptObjCustomScokArrStructEnabled = 0;
            wsSocketStruct->jsonListInboundStreamSettingsWSSockoptCustomSockOptArrayStructSize = 0;

            if (cJSON_HasObjectItem(sockOptObj, "acceptProxyProtocol")) {
                wsSocketStruct->acceptProxyProtocolEnabled = 1;

                wsSocketStruct->acceptProxyProtocol = cJSON_IsTrue(cJSON_GetObjectItem(sockOptObj, "acceptProxyProtocol"));

            } else {
                wsSocketStruct->acceptProxyProtocolEnabled = 0;

            }

            if (cJSON_HasObjectItem(sockOptObj, "tcpFastOpen")) {
                wsSocketStruct->tcpFastOpenEnabled = 1;

                wsSocketStruct->tcpFastOpen = cJSON_IsTrue(cJSON_GetObjectItem(sockOptObj, "tcpFastOpen"));

            } else {
                wsSocketStruct->tcpFastOpenEnabled = 0;

            }

            if (cJSON_HasObjectItem(sockOptObj, "tproxy")) {
                wsSocketStruct->tproxyEnabled = 1;

                char* tproxy = cJSON_GetObjectItem(sockOptObj, "tproxy")->valuestring;
                size_t tproxyLen = strlen(tproxy);
                char* tproxyCopy = (char*)malloc((tproxyLen + 1) * sizeof(char));
                strncpy(tproxyCopy, tproxy, tproxyLen);
                tproxyCopy[tproxyLen] = '\0';
                wsSocketStruct->tproxy = tproxyCopy;

            } else {
                wsSocketStruct->tproxyEnabled = 0;

            }

            if (cJSON_HasObjectItem(sockOptObj, "penetrate")) {
                wsSocketStruct->penetrateEnabled = 1;

                wsSocketStruct->penetrate = cJSON_IsTrue(cJSON_GetObjectItem(sockOptObj, "penetrate"));

            } else {
                wsSocketStruct->penetrateEnabled = 0;

            }

            if (cJSON_HasObjectItem(sockOptObj, "tcpcongestion")) {
                wsSocketStruct->tcpcongestionEnabled = 1;

                char* tcpcongestion = cJSON_GetObjectItem(sockOptObj, "tcpcongestion")->valuestring;
                size_t tcpcongestionLen = strlen(tcpcongestion);
                char* tcpcongestionCopy = (char*)malloc((tcpcongestionLen + 1) * sizeof(char));
                strncpy(tcpcongestionCopy, tcpcongestion, tcpcongestionLen);
                tcpcongestionCopy[tcpcongestionLen] = '\0';
                wsSocketStruct->tcpcongestion = tcpcongestionCopy;

            } else {
                wsSocketStruct->tcpcongestionEnabled = 0;

            }

            if (cJSON_HasObjectItem(sockOptObj, "V6Only")) {
                wsSocketStruct->V6OnlyEnabled = 1;

                wsSocketStruct->V6Only = cJSON_IsTrue(cJSON_GetObjectItem(sockOptObj, "V6Only"));

            } else {
                wsSocketStruct->V6OnlyEnabled = 0;

            }

            if (
                cJSON_HasObjectItem(sockOptObj, "customSockopt") &&
                cJSON_IsArray(cJSON_GetObjectItem(sockOptObj, "customSockopt"))
               ) {
                cJSON* customSockoptArr = cJSON_GetObjectItem(sockOptObj, "customSockopt");
                size_t customSockoptArrLen = cJSON_GetArraySize(customSockoptArr);
                if (customSockoptArrLen) {
                    wsSocketStruct->listInStreamSettingsWSSockoptObjCustomScokArrStruct = (struct jsonListInboundStreamSettingsWSSockoptObjectCustomSockOptArrayStruct*)malloc(customSockoptArrLen * sizeof(struct jsonListInboundStreamSettingsWSSockoptObjectCustomSockOptArrayStruct));
                    if (!wsSocketStruct->listInStreamSettingsWSSockoptObjCustomScokArrStruct) {
                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsWSSockoptObjCustomScokArrStruct is a null pointer, failed to allocate memory");

                        return 0;

                    }

                    wsSocketStruct->listInStreamSettingsWSSockoptObjCustomScokArrStructEnabled = 1;

                    wsSocketStruct->jsonListInboundStreamSettingsWSSockoptCustomSockOptArrayStructSize = customSockoptArrLen;

                    for (size_t i = 0; i < customSockoptArrLen; i++) {
                        struct jsonListInboundStreamSettingsWSSockoptObjectCustomSockOptArrayStruct* customSockOptArrStruct = wsSocketStruct->listInStreamSettingsWSSockoptObjCustomScokArrStruct;

                        customSockOptArrStruct[i].system = NULL;
                        customSockOptArrStruct[i].type = NULL;
                        customSockOptArrStruct[i].level = NULL;
                        customSockOptArrStruct[i].opt = NULL;
                        customSockOptArrStruct[i].value = NULL;

                        cJSON* customSockoptArrItem = cJSON_GetArrayItem(customSockoptArr, i);
                        if (
                            // also has the "system" field if set
                            cJSON_HasObjectItem(customSockoptArrItem, "type") &&
                            cJSON_HasObjectItem(customSockoptArrItem, "level") &&
                            cJSON_HasObjectItem(customSockoptArrItem, "opt") &&
                            cJSON_HasObjectItem(customSockoptArrItem, "value")
                           ) {

                            if (cJSON_HasObjectItem(customSockoptArrItem, "system")) {
                                char* system = cJSON_GetObjectItem(customSockoptArrItem, "system")->valuestring;
                                size_t systemLen = strlen(system);
                                char* systemCopy = (char*)malloc((systemLen + 1) * sizeof(char));
                                strncpy(systemCopy, system, systemLen);
                                systemCopy[systemLen] = '\0';
                                customSockOptArrStruct[i].system = systemCopy;

                            } else {
                                customSockOptArrStruct[i].system = NULL;

                            }

                            char* type = cJSON_GetObjectItem(customSockoptArrItem, "type")->valuestring;
                            size_t typeLen = strlen(type);
                            char* typeCopy = (char*)malloc((typeLen + 1) * sizeof(char));
                            strncpy(typeCopy, type, typeLen);
                            typeCopy[typeLen] = '\0';
                            customSockOptArrStruct[i].type = typeCopy;

                            char* level = cJSON_GetObjectItem(customSockoptArrItem, "level")->valuestring;
                            size_t levelLen = strlen(level);
                            char* levelCopy = (char*)malloc((levelLen + 1) * sizeof(char));
                            strncpy(levelCopy, level, levelLen);
                            levelCopy[levelLen] = '\0';
                            customSockOptArrStruct[i].level = levelCopy;

                            char* opt = cJSON_GetObjectItem(customSockoptArrItem, "opt")->valuestring;
                            size_t optLen = strlen(opt);
                            char* optCopy = (char*)malloc((optLen + 1) * sizeof(char));
                            strncpy(optCopy, opt, optLen);
                            optCopy[optLen] = '\0';
                            customSockOptArrStruct[i].opt = optCopy;

                            char* value = cJSON_GetObjectItem(customSockoptArrItem, "value")->valuestring;
                            size_t valueLen = strlen(value);
                            char* valueCopy = (char*)malloc((valueLen + 1) * sizeof(char));
                            strncpy(valueCopy, value, valueLen);
                            valueCopy[valueLen] = '\0';
                            customSockOptArrStruct[i].value = valueCopy;

                        } else {
                            // TODO
                        }

                    }

                } else {
                    // empty array, the custom sockopt fields stay at their default null / zero values

                }

            } else {
                // the object is absent or not an array, the custom sockopt fields stay at their default null / zero values

            }

            wsSocketStruct->trustedXForwardedFor = NULL;
            wsSocketStruct->trustedXForwardedForCount = 0;
            if (cJSON_HasObjectItem(sockOptObj, "trustedXForwardedFor") && cJSON_IsArray(cJSON_GetObjectItem(sockOptObj, "trustedXForwardedFor"))) {
                cJSON* trustedArr = cJSON_GetObjectItem(sockOptObj, "trustedXForwardedFor");
                size_t trustedCount = cJSON_GetArraySize(trustedArr);
                if (trustedCount) {
                    wsSocketStruct->trustedXForwardedFor = (const char**)malloc(trustedCount * sizeof(char*));
                    if (!wsSocketStruct->trustedXForwardedFor) {
                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "trustedXForwardedFor is a null pointer, failed to allocate memory");
                        return 0;
                    }
                    for (size_t i = 0; i < trustedCount; i++) {
                        cJSON* trustedItem = cJSON_GetArrayItem(trustedArr, i);
                        wsSocketStruct->trustedXForwardedFor[i] = NULL;
                        if (cJSON_IsString(trustedItem)) {
                            size_t trustedLen = strlen(trustedItem->valuestring);
                            char* trustedCopy = (char*)malloc((trustedLen + 1) * sizeof(char));
                            if (!trustedCopy) {
                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "trustedXForwardedFor item is a null pointer, failed to allocate memory");
                                return 0;
                            }
                            strncpy(trustedCopy, trustedItem->valuestring, trustedLen);
                            trustedCopy[trustedLen] = '\0';
                            wsSocketStruct->trustedXForwardedFor[i] = trustedCopy;
                        }
                    }
                    wsSocketStruct->trustedXForwardedForCount = (int64_t)trustedCount;
                }
            }

            break;

        }
        case NETWORKTYPE_KCP:
        {
            streamSettingsStruct->listInStreamSettingsMKcpSockoptObjStruct = (struct jsonListInboundStreamSettingsMKcpSockoptObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsMKcpSockoptObjectStruct));
            if (!streamSettingsStruct->listInStreamSettingsMKcpSockoptObjStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsMKcpSockoptObjStruct is a null pointer, failed to allocate memory");

                return 0;

            }

            struct jsonListInboundStreamSettingsMKcpSockoptObjectStruct* mKcpSocketStruct = streamSettingsStruct->listInStreamSettingsMKcpSockoptObjStruct;

            mKcpSocketStruct->listInStreamSettingsMKcpSockoptObjCustomScokArrStruct = NULL;
            mKcpSocketStruct->listInStreamSettingsMKcpSockoptObjCustomScokArrStructEnabled = 0;
            mKcpSocketStruct->jsonListInboundStreamSettingsMKcpSockoptCustomSockOptArrayStructSize = 0;

            if (cJSON_HasObjectItem(sockOptObj, "tcpFastOpen")) {
                mKcpSocketStruct->tcpFastOpenEnabled = 1;

                mKcpSocketStruct->tcpFastOpen = cJSON_IsTrue(cJSON_GetObjectItem(sockOptObj, "tcpFastOpen"));

            } else {
                mKcpSocketStruct->tcpFastOpenEnabled = 0;

            }

            if (cJSON_HasObjectItem(sockOptObj, "tproxy")) {
                mKcpSocketStruct->tproxyEnabled = 1;

                char* tproxy = cJSON_GetObjectItem(sockOptObj, "tproxy")->valuestring;
                size_t tproxyLen = strlen(tproxy);
                char* tproxyCopy = (char*)malloc((tproxyLen + 1) * sizeof(char));
                strncpy(tproxyCopy, tproxy, tproxyLen);
                tproxyCopy[tproxyLen] = '\0';
                mKcpSocketStruct->tproxy = tproxyCopy;

            } else {
                mKcpSocketStruct->tproxyEnabled = 0;

            }

            if (cJSON_HasObjectItem(sockOptObj, "penetrate")) {
                mKcpSocketStruct->penetrateEnabled = 1;

                mKcpSocketStruct->penetrate = cJSON_IsTrue(cJSON_GetObjectItem(sockOptObj, "penetrate"));

            } else {
                mKcpSocketStruct->penetrateEnabled = 0;

            }

            if (cJSON_HasObjectItem(sockOptObj, "tcpcongestion")) {
                mKcpSocketStruct->tcpcongestionEnabled = 1;

                char* tcpcongestion = cJSON_GetObjectItem(sockOptObj, "tcpcongestion")->valuestring;
                size_t tcpcongestionLen = strlen(tcpcongestion);
                char* tcpcongestionCopy = (char*)malloc((tcpcongestionLen + 1) * sizeof(char));
                strncpy(tcpcongestionCopy, tcpcongestion, tcpcongestionLen);
                tcpcongestionCopy[tcpcongestionLen] = '\0';
                mKcpSocketStruct->tcpcongestion = tcpcongestionCopy;

            } else {
                mKcpSocketStruct->tcpcongestionEnabled = 0;

            }

            if (cJSON_HasObjectItem(sockOptObj, "V6Only")) {
                mKcpSocketStruct->V6OnlyEnabled = 1;

                mKcpSocketStruct->V6Only = cJSON_IsTrue(cJSON_GetObjectItem(sockOptObj, "V6Only"));

            } else {
                mKcpSocketStruct->V6OnlyEnabled = 0;

            }

            if (
                cJSON_HasObjectItem(sockOptObj, "customSockopt") &&
                cJSON_IsArray(cJSON_GetObjectItem(sockOptObj, "customSockopt"))
               ) {
                cJSON* customSockoptArr = cJSON_GetObjectItem(sockOptObj, "customSockopt");
                size_t customSockoptArrLen = cJSON_GetArraySize(customSockoptArr);
                if (customSockoptArrLen) {
                    mKcpSocketStruct->listInStreamSettingsMKcpSockoptObjCustomScokArrStruct = (struct jsonListInboundStreamSettingsMKcpSockoptObjectCustomSockOptArrayStruct*)malloc(customSockoptArrLen * sizeof(struct jsonListInboundStreamSettingsMKcpSockoptObjectCustomSockOptArrayStruct));
                    if (!mKcpSocketStruct->listInStreamSettingsMKcpSockoptObjCustomScokArrStruct) {
                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsMKcpSockoptObjCustomScokArrStruct is a null pointer, failed to allocate memory");

                        return 0;

                    }

                    mKcpSocketStruct->listInStreamSettingsMKcpSockoptObjCustomScokArrStructEnabled = 1;

                    mKcpSocketStruct->jsonListInboundStreamSettingsMKcpSockoptCustomSockOptArrayStructSize = customSockoptArrLen;

                    for (size_t i = 0; i < customSockoptArrLen; i++) {
                        struct jsonListInboundStreamSettingsMKcpSockoptObjectCustomSockOptArrayStruct* customSockOptArrStruct = mKcpSocketStruct->listInStreamSettingsMKcpSockoptObjCustomScokArrStruct;

                        customSockOptArrStruct[i].system = NULL;
                        customSockOptArrStruct[i].type = NULL;
                        customSockOptArrStruct[i].level = NULL;
                        customSockOptArrStruct[i].opt = NULL;
                        customSockOptArrStruct[i].value = NULL;

                        cJSON* customSockoptArrItem = cJSON_GetArrayItem(customSockoptArr, i);
                        if (
                            // also has the "system" field if set
                            cJSON_HasObjectItem(customSockoptArrItem, "type") &&
                            cJSON_HasObjectItem(customSockoptArrItem, "level") &&
                            cJSON_HasObjectItem(customSockoptArrItem, "opt") &&
                            cJSON_HasObjectItem(customSockoptArrItem, "value")
                           ) {

                            if (cJSON_HasObjectItem(customSockoptArrItem, "system")) {
                                char* system = cJSON_GetObjectItem(customSockoptArrItem, "system")->valuestring;
                                size_t systemLen = strlen(system);
                                char* systemCopy = (char*)malloc((systemLen + 1) * sizeof(char));
                                strncpy(systemCopy, system, systemLen);
                                systemCopy[systemLen] = '\0';
                                customSockOptArrStruct[i].system = systemCopy;

                            } else {
                                customSockOptArrStruct[i].system = NULL;

                            }

                            char* type = cJSON_GetObjectItem(customSockoptArrItem, "type")->valuestring;
                            size_t typeLen = strlen(type);
                            char* typeCopy = (char*)malloc((typeLen + 1) * sizeof(char));
                            strncpy(typeCopy, type, typeLen);
                            typeCopy[typeLen] = '\0';
                            customSockOptArrStruct[i].type = typeCopy;

                            char* level = cJSON_GetObjectItem(customSockoptArrItem, "level")->valuestring;
                            size_t levelLen = strlen(level);
                            char* levelCopy = (char*)malloc((levelLen + 1) * sizeof(char));
                            strncpy(levelCopy, level, levelLen);
                            levelCopy[levelLen] = '\0';
                            customSockOptArrStruct[i].level = levelCopy;

                            char* opt = cJSON_GetObjectItem(customSockoptArrItem, "opt")->valuestring;
                            size_t optLen = strlen(opt);
                            char* optCopy = (char*)malloc((optLen + 1) * sizeof(char));
                            strncpy(optCopy, opt, optLen);
                            optCopy[optLen] = '\0';
                            customSockOptArrStruct[i].opt = optCopy;

                            char* value = cJSON_GetObjectItem(customSockoptArrItem, "value")->valuestring;
                            size_t valueLen = strlen(value);
                            char* valueCopy = (char*)malloc((valueLen + 1) * sizeof(char));
                            strncpy(valueCopy, value, valueLen);
                            valueCopy[valueLen] = '\0';
                            customSockOptArrStruct[i].value = valueCopy;

                        } else {
                            // TODO
                        }

                    }

                } else {
                    // empty array, the custom sockopt fields stay at their default null / zero values

                }

            } else {
                // the object is absent or not an array, the custom sockopt fields stay at their default null / zero values

            }

            break;

        }
        case NETWORKTYPE_GRPC:
        case NETWORKTYPE_HTTPUPGRADE:
        case NETWORKTYPE_XHTTP:
        default:

    }


    return 1;

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
            struct jsonListInboundObjectStruct* inboundObj = &listInStruct->listInObjStruct[i];
            inboundObj->remark = NULL;
            inboundObj->trafficReset = NULL;
            inboundObj->listInCliStatsStruct = NULL;
            inboundObj->jsonListInboundClientStatsArrayStructSize = 0;
            inboundObj->listen = NULL;
            inboundObj->protocol = NULL;
            inboundObj->tag = NULL;
            inboundObj->shareAddrStrategy = NULL;
            inboundObj->shareAddr = NULL;
            inboundObj->originNodeGuid = NULL;
            inboundObj->listInSettingsObjStruct = NULL;
            inboundObj->listInStreamSettingsObjStruct = NULL;
            inboundObj->listInSniffingObjStruct = NULL;
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
                cJSON_HasObjectItem(arrItem, "clientStats") &&
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
                inboundObj->id = (int64_t)cJSON_GetObjectItem(arrItem, "id")->valuedouble;
                inboundObj->up = (int64_t)cJSON_GetObjectItem(arrItem, "up")->valuedouble;
                inboundObj->down = (int64_t)cJSON_GetObjectItem(arrItem, "down")->valuedouble;
                inboundObj->total = (int64_t)cJSON_GetObjectItem(arrItem, "total")->valuedouble;

                char* remark = cJSON_GetObjectItem(arrItem, "remark")->valuestring;
                size_t remarkLen = strlen(remark);
                char* remarkCopy = (char*)malloc((remarkLen + 1) * sizeof(char));
                strncpy(remarkCopy, remark, remarkLen);
                remarkCopy[remarkLen] = '\0';
                inboundObj->remark = remarkCopy;

                inboundObj->subSortIndex = cJSON_GetObjectItem(arrItem, "subSortIndex")->valueint;
                inboundObj->enable = (unsigned char)cJSON_GetObjectItem(arrItem, "enable")->valueint;
                inboundObj->expiryTime = (int64_t)cJSON_GetObjectItem(arrItem, "expiryTime")->valuedouble;

                char* trafficReset = cJSON_GetObjectItem(arrItem, "trafficReset")->valuestring;
                size_t trafficResetLen = strlen(trafficReset);
                char* trafficResetCopy = (char*)malloc((trafficResetLen + 1) * sizeof(char));
                strncpy(trafficResetCopy, trafficReset, trafficResetLen);
                trafficResetCopy[trafficResetLen] = '\0';
                inboundObj->trafficReset = trafficResetCopy;

                inboundObj->trafficResetDay = cJSON_GetObjectItem(arrItem, "trafficResetDay")->valueint;
                inboundObj->lastTrafficResetTime = (int64_t)cJSON_GetObjectItem(arrItem, "lastTrafficResetTime")->valuedouble;

                cJSON* clientStatsArray = cJSON_GetObjectItem(arrItem, "clientStats");
                inboundObj->jsonListInboundClientStatsArrayStructSize = cJSON_GetArraySize(clientStatsArray);
                if (!inboundObj->jsonListInboundClientStatsArrayStructSize) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "clientStatsArray is empty"); // TODO: make this message consistent across this file

                    inboundObj->listInCliStatsStruct = NULL;

                } else {
                    inboundObj->listInCliStatsStruct = (struct jsonListInboundClientStatsArrayStruct*)malloc(inboundObj->jsonListInboundClientStatsArrayStructSize * sizeof(struct jsonListInboundClientStatsArrayStruct));
                    if (!inboundObj->listInCliStatsStruct) {
                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInCliStatsStruct is a null pointer, failed to allocate space"); // TODO: make this message consistent across this file

                        inboundObj->listInCliStatsStruct = NULL;
                        inboundObj->listen = NULL;
                        inboundObj->protocol = NULL;
                        inboundObj->tag = NULL;
                        inboundObj->shareAddrStrategy = NULL;
                        inboundObj->shareAddr = NULL;
                        inboundObj->originNodeGuid = NULL;
                        inboundObj->listInSettingsObjStruct = NULL;
                        inboundObj->listInStreamSettingsObjStruct = NULL;
                        inboundObj->listInSniffingObjStruct = NULL;
                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                        listInStruct->listInObjStruct = NULL;
                        jsonListInboundStructDelete(listInStruct);

                        cJSON_Delete(jsonParser);

                        return NULL;

                    }

                    for (size_t j = 0; j < inboundObj->jsonListInboundClientStatsArrayStructSize; j++) {
                        struct jsonListInboundClientStatsArrayStruct* cliStats = inboundObj->listInCliStatsStruct;
                        cJSON* clientStatsItem = cJSON_GetArrayItem(clientStatsArray, j);
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
                            cliStats[j].id = (int64_t)cJSON_GetObjectItem(clientStatsItem, "id")->valuedouble;
                            cliStats[j].inboundId = (int64_t)cJSON_GetObjectItem(clientStatsItem, "inboundId")->valuedouble;
                            cliStats[j].enable = (unsigned char)cJSON_GetObjectItem(clientStatsItem, "enable")->valueint;

                            char* email = cJSON_GetObjectItem(clientStatsItem, "email")->valuestring;
                            size_t emailLen = strlen(email);
                            char* emailCopy = (char*)malloc((emailLen + 1) * sizeof(char));
                            strncpy(emailCopy, email, emailLen);
                            emailCopy[emailLen] = '\0';
                            cliStats[j].email = emailCopy;

                            char* uuid = cJSON_GetObjectItem(clientStatsItem, "uuid")->valuestring;
                            size_t uuidLen = strlen(uuid);
                            char* uuidCopy = (char*)malloc((uuidLen + 1) * sizeof(char));
                            strncpy(uuidCopy, uuid, uuidLen);
                            uuidCopy[uuidLen] = '\0';
                            cliStats[j].uuid = uuidCopy;

                            char* subId = cJSON_GetObjectItem(clientStatsItem, "subId")->valuestring;
                            size_t subIdLen = strlen(subId);
                            char* subIdCopy = (char*)malloc((subIdLen + 1) * sizeof(char));
                            strncpy(subIdCopy, subId, subIdLen);
                            subIdCopy[subIdLen] = '\0';
                            cliStats[j].subId = subIdCopy;

                            cliStats[j].up = (int64_t)cJSON_GetObjectItem(clientStatsItem, "up")->valuedouble;
                            cliStats[j].down = (int64_t)cJSON_GetObjectItem(clientStatsItem, "down")->valuedouble;
                            cliStats[j].expiryTime = (int64_t)cJSON_GetObjectItem(clientStatsItem, "expiryTime")->valuedouble;
                            cliStats[j].total = (int64_t)cJSON_GetObjectItem(clientStatsItem, "total")->valuedouble;
                            cliStats[j].reset = cJSON_GetObjectItem(clientStatsItem, "reset")->valueint;
                            cliStats[j].lastOnline = (int64_t)cJSON_GetObjectItem(clientStatsItem, "lastOnline")->valuedouble;


                        } else {
                            applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Some item is not present in the client stats array element, skipping the element...");

                            cliStats[j].email = NULL;
                            cliStats[j].uuid = NULL;
                            cliStats[j].subId = NULL;

                        }

                    }

                }

                char* listen = cJSON_GetObjectItem(arrItem, "listen")->valuestring;
                size_t listenLen = strlen(listen);
                char* listenCopy = (char*)malloc((listenLen + 1) * sizeof(char));
                strncpy(listenCopy, listen, listenLen);
                listenCopy[listenLen] = '\0';
                inboundObj->listen = listenCopy;

                inboundObj->port = cJSON_GetObjectItem(arrItem, "port")->valueint;

                char* protocol = cJSON_GetObjectItem(arrItem, "protocol")->valuestring;
                size_t protocolLen = strlen(protocol);
                char* protocolCopy = (char*)malloc((protocolLen + 1) * sizeof(char));
                strncpy(protocolCopy, protocol, protocolLen);
                protocolCopy[protocolLen] = '\0';
                inboundObj->protocol = protocolCopy;

                char* tag = cJSON_GetObjectItem(arrItem, "tag")->valuestring;
                size_t tagLen = strlen(tag);
                char* tagCopy = (char*)malloc((tagLen + 1) * sizeof(char));
                strncpy(tagCopy, tag, tagLen);
                tagCopy[tagLen] = '\0';
                inboundObj->tag = tagCopy;

                char* shareAddrStrategy = cJSON_GetObjectItem(arrItem, "shareAddrStrategy")->valuestring;
                size_t shareAddrStrategyLen = strlen(shareAddrStrategy);
                char* shareAddrStrategyCopy = (char*)malloc((shareAddrStrategyLen + 1) * sizeof(char));
                strncpy(shareAddrStrategyCopy, shareAddrStrategy, shareAddrStrategyLen);
                shareAddrStrategyCopy[shareAddrStrategyLen] = '\0';
                inboundObj->shareAddrStrategy = shareAddrStrategyCopy;

                char* shareAddr = cJSON_GetObjectItem(arrItem, "shareAddr")->valuestring;
                size_t shareAddrLen = strlen(shareAddr);
                char* shareAddrCopy = (char*)malloc((shareAddrLen + 1) * sizeof(char));
                strncpy(shareAddrCopy, shareAddr, shareAddrLen);
                shareAddrCopy[shareAddrLen] = '\0';
                inboundObj->shareAddr = shareAddrCopy;

                char* originNodeGuid = cJSON_GetObjectItem(arrItem, "originNodeGuid")->valuestring;
                size_t originNodeGuidLen = strlen(originNodeGuid);
                char* originNodeGuidCopy = (char*)malloc((originNodeGuidLen + 1) * sizeof(char));
                strncpy(originNodeGuidCopy, originNodeGuid, originNodeGuidLen);
                originNodeGuidCopy[originNodeGuidLen] = '\0';
                inboundObj->originNodeGuid = originNodeGuidCopy;

                inboundObj->listInSettingsObjStruct = (struct jsonListInboundSettingsObjectStruct*)malloc(sizeof(struct jsonListInboundSettingsObjectStruct));
                if (!inboundObj->listInSettingsObjStruct) {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInSettingsObjStruct is a null pointer, failed to allocate space");

                    inboundObj->listInSettingsObjStruct = NULL;
                    inboundObj->listInStreamSettingsObjStruct = NULL;
                    inboundObj->listInSniffingObjStruct = NULL;
                    jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                    listInStruct->listInObjStruct = NULL;
                    jsonListInboundStructDelete(listInStruct);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }

                inboundObj->listInSettingsObjStruct->listInSettingsCliArrStruct = NULL;
                inboundObj->listInSettingsObjStruct->decryption = NULL;
                inboundObj->listInSettingsObjStruct->encryption = NULL;

                struct jsonListInboundSettingsObjectStruct* settingsStruct = inboundObj->listInSettingsObjStruct;
                cJSON* settingsObj = cJSON_GetObjectItem(arrItem, "settings");
                if (!settingsObj) {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingsObj is a null pointer");

                    jsonListInboundSettingsObjectStructDelete(inboundObj->listInSettingsObjStruct);
                    inboundObj->listInSettingsObjStruct = NULL;
                    inboundObj->listInStreamSettingsObjStruct = NULL;
                    inboundObj->listInSniffingObjStruct = NULL;
                    jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);
                    listInStruct->listInObjStruct = NULL;
                    jsonListInboundStructDelete(listInStruct);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }

                if (
                    cJSON_HasObjectItem(settingsObj, "clients") &&
                    cJSON_IsArray(cJSON_GetObjectItem(settingsObj, "clients")) &&
                    cJSON_HasObjectItem(settingsObj, "decryption") &&
                    cJSON_HasObjectItem(settingsObj, "encryption")
                   ) {

                } else {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some item is not present in the settings object, returning...");

                    jsonListInboundSettingsObjectStructDelete(inboundObj->listInSettingsObjStruct);
                    inboundObj->listInSettingsObjStruct = NULL;
                    inboundObj->listInStreamSettingsObjStruct = NULL;
                    inboundObj->listInSniffingObjStruct = NULL;
                    jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);
                    listInStruct->listInObjStruct = NULL;
                    jsonListInboundStructDelete(listInStruct);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }

                cJSON* settingsObjClientsArray = cJSON_GetObjectItem(settingsObj, "clients");
                if (!settingsObjClientsArray) {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingsObjClientsArray is a null pointer");

                    jsonListInboundSettingsObjectStructDelete(inboundObj->listInSettingsObjStruct);
                    inboundObj->listInSettingsObjStruct = NULL;
                    inboundObj->listInStreamSettingsObjStruct = NULL;
                    inboundObj->listInSniffingObjStruct = NULL;
                    jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);
                    listInStruct->listInObjStruct = NULL;
                    jsonListInboundStructDelete(listInStruct);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }

                settingsStruct->jsonListInboundSettingsClientsArrayStructSize = cJSON_GetArraySize(settingsObjClientsArray);
                if (!settingsStruct->jsonListInboundSettingsClientsArrayStructSize) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "settingsObjClientsArray is empty");

                    settingsStruct->listInSettingsCliArrStruct = NULL;

                } else {
                    settingsStruct->listInSettingsCliArrStruct = (struct jsonListInboundSettingsClientsArrayStruct*)malloc(settingsStruct->jsonListInboundSettingsClientsArrayStructSize * sizeof(struct jsonListInboundSettingsClientsArrayStruct));
                    if (!settingsStruct->listInSettingsCliArrStruct) {
                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInSettingsCliArrStruct is a null pointer, failed to allocate space");

                        settingsStruct->listInSettingsCliArrStruct = NULL;
                        settingsStruct->decryption = NULL;
                        settingsStruct->encryption = NULL;
                        jsonListInboundSettingsObjectStructDelete(settingsStruct);

                        inboundObj->listInSettingsObjStruct = NULL;
                        inboundObj->listInStreamSettingsObjStruct = NULL;
                        inboundObj->listInSniffingObjStruct = NULL;
                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                        listInStruct->listInObjStruct = NULL;
                        jsonListInboundStructDelete(listInStruct);

                        cJSON_Delete(jsonParser);

                        return NULL;

                    }

                    for (size_t j = 0; j < settingsStruct->jsonListInboundSettingsClientsArrayStructSize; j++) {
                        struct jsonListInboundSettingsClientsArrayStruct* settingsClients = settingsStruct->listInSettingsCliArrStruct;
                        cJSON* settingsObjClientsItem = cJSON_GetArrayItem(settingsObjClientsArray, j);
                        if (
                            cJSON_HasObjectItem(settingsObjClientsItem, "auth") &&
                            cJSON_HasObjectItem(settingsObjClientsItem, "comment") &&
                            cJSON_HasObjectItem(settingsObjClientsItem, "created_at") &&
                            cJSON_HasObjectItem(settingsObjClientsItem, "email") &&
                            cJSON_HasObjectItem(settingsObjClientsItem, "enable") &&
                            cJSON_HasObjectItem(settingsObjClientsItem, "expiryTime") &&
                            cJSON_HasObjectItem(settingsObjClientsItem, "id") &&
                            cJSON_HasObjectItem(settingsObjClientsItem, "limitIp") &&
                            cJSON_HasObjectItem(settingsObjClientsItem, "password") &&
                            cJSON_HasObjectItem(settingsObjClientsItem, "reset") &&
                            cJSON_HasObjectItem(settingsObjClientsItem, "security") &&
                            cJSON_HasObjectItem(settingsObjClientsItem, "subId") &&
                            cJSON_HasObjectItem(settingsObjClientsItem, "tgId") &&
                            cJSON_HasObjectItem(settingsObjClientsItem, "totalGB") &&
                            cJSON_HasObjectItem(settingsObjClientsItem, "updated_at")
                           ) {
                            char* auth = cJSON_GetObjectItem(settingsObjClientsItem, "auth")->valuestring;
                            size_t authLen = strlen(auth);
                            char* authCopy = (char*)malloc((authLen + 1) * sizeof(char));
                            strncpy(authCopy, auth, authLen);
                            authCopy[authLen] = '\0';
                            settingsClients[j].auth = authCopy;

                            char* comment = cJSON_GetObjectItem(settingsObjClientsItem, "comment")->valuestring;
                            size_t commentLen = strlen(comment);
                            char* commentCopy = (char*)malloc((commentLen + 1) * sizeof(char));
                            strncpy(commentCopy, comment, commentLen);
                            commentCopy[commentLen] = '\0';
                            settingsClients[j].comment = commentCopy;

                            settingsClients[j].createdAt = (int64_t)cJSON_GetObjectItem(settingsObjClientsItem, "created_at")->valuedouble;

                            char* email = cJSON_GetObjectItem(settingsObjClientsItem, "email")->valuestring;
                            size_t emailLen = strlen(email);
                            char* emailCopy = (char*)malloc((emailLen + 1) * sizeof(char));
                            strncpy(emailCopy, email, emailLen);
                            emailCopy[emailLen] = '\0';
                            settingsClients[j].email = emailCopy;

                            settingsClients[j].enable = cJSON_IsTrue(cJSON_GetObjectItem(settingsObjClientsItem, "enable"));
                            settingsClients[j].expiryTime = (int64_t)cJSON_GetObjectItem(settingsObjClientsItem, "expiryTime")->valuedouble;

                            char* id = cJSON_GetObjectItem(settingsObjClientsItem, "id")->valuestring;
                            size_t idLen = strlen(id);
                            char* idCopy = (char*)malloc((idLen + 1) * sizeof(char));
                            strncpy(idCopy, id, idLen);
                            idCopy[idLen] = '\0';
                            settingsClients[j].id = idCopy;

                            settingsClients[j].limitIp = cJSON_GetObjectItem(settingsObjClientsItem, "limitIp")->valueint;

                            char* password = cJSON_GetObjectItem(settingsObjClientsItem, "password")->valuestring;
                            size_t passwordLen = strlen(password);
                            char* passwordCopy = (char*)malloc((passwordLen + 1) * sizeof(char));
                            strncpy(passwordCopy, password, passwordLen);
                            passwordCopy[passwordLen] = '\0';
                            settingsClients[j].password = passwordCopy;

                            settingsClients[j].reset = cJSON_GetObjectItem(settingsObjClientsItem, "reset")->valueint;

                            char* security = cJSON_GetObjectItem(settingsObjClientsItem, "security")->valuestring;
                            size_t securityLen = strlen(security);
                            char* securityCopy = (char*)malloc((securityLen + 1) * sizeof(char));
                            strncpy(securityCopy, security, securityLen);
                            securityCopy[securityLen] = '\0';
                            settingsClients[j].security = securityCopy;

                            char* subId = cJSON_GetObjectItem(settingsObjClientsItem, "subId")->valuestring;
                            size_t subIdLen = strlen(subId);
                            char* subIdCopy = (char*)malloc((subIdLen + 1) * sizeof(char));
                            strncpy(subIdCopy, subId, subIdLen);
                            subIdCopy[subIdLen] = '\0';
                            settingsClients[j].subId = subIdCopy;

                            settingsClients[j].tgId = (int64_t)cJSON_GetObjectItem(settingsObjClientsItem, "tgId")->valuedouble;
                            settingsClients[j].totalGB = (int64_t)cJSON_GetObjectItem(settingsObjClientsItem, "totalGB")->valuedouble;
                            settingsClients[j].updatedAt = (int64_t)cJSON_GetObjectItem(settingsObjClientsItem, "updated_at")->valuedouble;

                        } else {
                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "some element is not present in the array, skipping...");

                            settingsClients[j].auth = NULL;
                            settingsClients[j].comment = NULL;
                            settingsClients[j].email = NULL;
                            settingsClients[j].id = NULL;
                            settingsClients[j].password = NULL;
                            settingsClients[j].security = NULL;
                            settingsClients[j].subId = NULL;

                        }

                    }

                }

                if (
                    cJSON_HasObjectItem(settingsObj, "decryption") &&
                    cJSON_IsString(cJSON_GetObjectItem(settingsObj, "decryption")) &&
                    cJSON_HasObjectItem(settingsObj, "encryption") &&
                    cJSON_IsString(cJSON_GetObjectItem(settingsObj, "encryption"))
                   ) {
                    char* decryption = cJSON_GetObjectItem(settingsObj, "decryption")->valuestring;
                    size_t decryptionLen = strlen(decryption);
                    char* decryptionCopy = (char*)malloc((decryptionLen + 1) * sizeof(char));
                    strncpy(decryptionCopy, decryption, decryptionLen);
                    decryptionCopy[decryptionLen] = '\0';
                    settingsStruct->decryption = decryptionCopy;

                    char* encryption = cJSON_GetObjectItem(settingsObj, "encryption")->valuestring;
                    size_t encryptionLen = strlen(encryption);
                    char* encryptionCopy = (char*)malloc((encryptionLen + 1) * sizeof(char));
                    strncpy(encryptionCopy, encryption, encryptionLen);
                    encryptionCopy[encryptionLen] = '\0';
                    settingsStruct->encryption = encryptionCopy;

                } else {
                    settingsStruct->decryption = NULL;
                    settingsStruct->encryption = NULL;

                }

                // TODO: first check the cJSON pointer then malloc the struct, check the entire code to ensure consistency
                cJSON* streamSettingsObj = cJSON_GetObjectItem(arrItem, "streamSettings");
                if (!streamSettingsObj) {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "streamSettings is a null pointer");

                    inboundObj->listInStreamSettingsObjStruct = NULL;
                    inboundObj->listInSniffingObjStruct = NULL;
                    jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                    listInStruct->listInObjStruct = NULL;
                    jsonListInboundStructDelete(listInStruct);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }

                inboundObj->listInStreamSettingsObjStruct = (struct jsonListInboundStreamSettingsObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsObjectStruct));
                if (!inboundObj->listInStreamSettingsObjStruct) {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsObjStruct is a null pointer, failed to allocate space");

                    inboundObj->listInStreamSettingsObjStruct = NULL;
                    inboundObj->listInSniffingObjStruct = NULL;
                    jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                    listInStruct->listInObjStruct = NULL;
                    jsonListInboundStructDelete(listInStruct);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }

                struct jsonListInboundStreamSettingsObjectStruct* streamSettingsStruct = inboundObj->listInStreamSettingsObjStruct;

                streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;
                streamSettingsStruct->listInStreamSettingsMKcpSettingsObjStruct = NULL;
                streamSettingsStruct->listInStreamSettingsWSSettingsObjStruct = NULL;
                streamSettingsStruct->listInStreamSettingsGRPCSettingsObjStruct = NULL;
                streamSettingsStruct->listInStreamSettingsHTTPUpgradeSettingsObjStruct = NULL;
                streamSettingsStruct->listInStreamSettingsXHTTPSettingsObjStruct = NULL;
                streamSettingsStruct->security = NULL;

                streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                streamSettingsStruct->listInStreamSettingsGRPCFinalMaskObjStruct = NULL;
                streamSettingsStruct->listInStreamSettingsHTTPUpgradeFinalMaskObjStruct = NULL;
                streamSettingsStruct->listInStreamSettingsXHTTPFinalMaskObjStruct = NULL;

                streamSettingsStruct->listInStreamSettingsTcpSockoptObjStruct = NULL;
                streamSettingsStruct->listInStreamSettingsMKcpSockoptObjStruct = NULL;
                streamSettingsStruct->listInStreamSettingsWSSockoptObjStruct = NULL;
                streamSettingsStruct->listInStreamSettingsGRPCSockoptObjStruct = NULL;
                streamSettingsStruct->listInStreamSettingsHTTPUpgradeSockoptObjStruct = NULL;
                streamSettingsStruct->listInStreamSettingsXHTTPSockoptObjStruct = NULL;

                char* network = cJSON_GetObjectItem(streamSettingsObj, "network")->valuestring;
                size_t networkLen = strlen(network);
                char* networkCopy = (char*)malloc((networkLen + 1) * sizeof(char));
                strncpy(networkCopy, network, networkLen);
                networkCopy[networkLen] = '\0';
                streamSettingsStruct->network = networkCopy;

                const char* networkTypes[] = {
                    "tcp", // raw
                    "kcp", // mKCP
                    "ws", // websocket
                    "grpc",
                    "httpupgrade",
                    "xhttp"

                };

                enum networkTypesEnum nType = NETWORKTYPE_COUNT;
                for (int n = 0; n < NETWORKTYPE_COUNT; n++) {
                    if (strncmp(networkTypes[n], streamSettingsStruct->network, strlen(networkTypes[n])) == 0) {
                        nType = (enum networkTypesEnum)n;

                        break;

                    } else if (n == NETWORKTYPE_COUNT - 1) {
                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Unable to detect network type");

                        streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;
                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                        inboundObj->listInStreamSettingsObjStruct = NULL;
                        inboundObj->listInSniffingObjStruct = NULL;
                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                        listInStruct->listInObjStruct = NULL;
                        jsonListInboundStructDelete(listInStruct);

                        cJSON_Delete(jsonParser);

                        return NULL;
                        
                    }

                }

                switch (nType) {
                    case NETWORKTYPE_TCP:
                        streamSettingsStruct->listInStreamSettingsMKcpSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsWSSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsGRPCSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsHTTPUpgradeSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsXHTTPSettingsObjStruct = NULL;

                        streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsGRPCFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsHTTPUpgradeFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsXHTTPFinalMaskObjStruct = NULL;

                        streamSettingsStruct->listInStreamSettingsMKcpSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsWSSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsGRPCSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsHTTPUpgradeSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsXHTTPSockoptObjStruct = NULL;

                        break;

                    case NETWORKTYPE_KCP:
                        streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsWSSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsGRPCSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsHTTPUpgradeSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsXHTTPSettingsObjStruct = NULL;

                        streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsGRPCFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsHTTPUpgradeFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsXHTTPFinalMaskObjStruct = NULL;

                        streamSettingsStruct->listInStreamSettingsTcpSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsWSSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsGRPCSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsHTTPUpgradeSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsXHTTPSockoptObjStruct = NULL;

                        break;

                    case NETWORKTYPE_WS:
                        streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsMKcpSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsGRPCSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsHTTPUpgradeSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsXHTTPSettingsObjStruct = NULL;

                        streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsGRPCFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsHTTPUpgradeFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsXHTTPFinalMaskObjStruct = NULL;

                        streamSettingsStruct->listInStreamSettingsTcpSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsMKcpSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsGRPCSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsHTTPUpgradeSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsXHTTPSockoptObjStruct = NULL;

                        break;

                    case NETWORKTYPE_GRPC:
                        streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsMKcpSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsWSSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsHTTPUpgradeSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsXHTTPSettingsObjStruct = NULL;

                        streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsHTTPUpgradeFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsXHTTPFinalMaskObjStruct = NULL;

                        streamSettingsStruct->listInStreamSettingsTcpSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsMKcpSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsWSSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsHTTPUpgradeSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsXHTTPSockoptObjStruct = NULL;

                        break;

                    case NETWORKTYPE_HTTPUPGRADE:
                        streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsMKcpSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsWSSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsGRPCSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsXHTTPSettingsObjStruct = NULL;

                        streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsGRPCFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsXHTTPFinalMaskObjStruct = NULL;

                        streamSettingsStruct->listInStreamSettingsTcpSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsMKcpSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsWSSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsGRPCSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsXHTTPSockoptObjStruct = NULL;

                        break;

                    case NETWORKTYPE_XHTTP:
                        streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsMKcpSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsWSSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsGRPCSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsHTTPUpgradeSettingsObjStruct = NULL;

                        streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsGRPCFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsHTTPUpgradeFinalMaskObjStruct = NULL;

                        streamSettingsStruct->listInStreamSettingsTcpSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsMKcpSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsWSSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsGRPCSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsHTTPUpgradeSockoptObjStruct = NULL;

                        break;

                    case NETWORKTYPE_COUNT:
                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Invalid network type");

                        streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsMKcpSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsWSSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsGRPCSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsHTTPUpgradeSettingsObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsXHTTPSettingsObjStruct = NULL;

                        streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsGRPCFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsHTTPUpgradeFinalMaskObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsXHTTPFinalMaskObjStruct = NULL;

                        streamSettingsStruct->listInStreamSettingsTcpSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsMKcpSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsWSSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsGRPCSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsHTTPUpgradeSockoptObjStruct = NULL;
                        streamSettingsStruct->listInStreamSettingsXHTTPSockoptObjStruct = NULL;

                        break;

                }

                switch (nType) {
                    case NETWORKTYPE_TCP:
                        if (
                            cJSON_HasObjectItem(streamSettingsObj, "tcpSettings") &&
                            cJSON_IsObject(cJSON_GetObjectItem(streamSettingsObj, "tcpSettings"))
                           ) {
                            cJSON* tcpSettingsObj = cJSON_GetObjectItem(streamSettingsObj, "tcpSettings");
                            if (!tcpSettingsObj) {
                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "tcpSettingsObj is a null pointer");

                                streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;
                                jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                inboundObj->listInStreamSettingsObjStruct = NULL;
                                inboundObj->listInSniffingObjStruct = NULL;
                                jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                listInStruct->listInObjStruct = NULL;
                                jsonListInboundStructDelete(listInStruct);

                                cJSON_Delete(jsonParser);

                                return NULL;

                            }

                            if (
                                cJSON_HasObjectItem(tcpSettingsObj, "acceptProxyProtocol") &&
                                cJSON_HasObjectItem(tcpSettingsObj, "header") &&
                                cJSON_IsObject(cJSON_GetObjectItem(tcpSettingsObj, "header"))
                               ) {
                                streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = (struct jsonListInboundStreamSettingsTcpSettingsObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsTcpSettingsObjectStruct));
                                if (!streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct) {
                                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsTcpSettingsObjStruct is a null pointer, failed to allocate space");

                                    streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;
                                    jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                    inboundObj->listInStreamSettingsObjStruct = NULL;
                                    inboundObj->listInSniffingObjStruct = NULL;
                                    jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                    listInStruct->listInObjStruct = NULL;
                                    jsonListInboundStructDelete(listInStruct);

                                    cJSON_Delete(jsonParser);

                                    return NULL;

                                }

                                struct jsonListInboundStreamSettingsTcpSettingsObjectStruct* tcpSettingsStruct = streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct;

                                tcpSettingsStruct->acceptProxyProtocol = cJSON_IsTrue(cJSON_GetObjectItem(tcpSettingsObj, "acceptProxyProtocol"));

                                cJSON* tcpHeaderObj = cJSON_GetObjectItem(tcpSettingsObj, "header");
                                if (!tcpHeaderObj) {
                                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "tcpHeaderObj is a null pointer");

                                    tcpSettingsStruct->listInStreamSettingsTcpSettingsObjHeaderObjStruct = NULL;
                                    jsonListInboundStreamSettingsTcpSettingsObjectStructDelete(tcpSettingsStruct);


                                    streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;
                                    jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                    inboundObj->listInStreamSettingsObjStruct = NULL;
                                    inboundObj->listInSniffingObjStruct = NULL;
                                    jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                    listInStruct->listInObjStruct = NULL;
                                    jsonListInboundStructDelete(listInStruct);

                                    cJSON_Delete(jsonParser);

                                    return NULL;

                                }

                                if (
                                    cJSON_HasObjectItem(tcpHeaderObj, "type") &&
                                    cJSON_IsString(cJSON_GetObjectItem(tcpHeaderObj, "type")) &&
                                    cJSON_HasObjectItem(tcpHeaderObj, "request") &&
                                    cJSON_IsObject(cJSON_GetObjectItem(tcpHeaderObj, "request")) &&
                                    cJSON_HasObjectItem(tcpHeaderObj, "response") &&
                                    cJSON_IsObject(cJSON_GetObjectItem(tcpHeaderObj, "response"))
                                   ) {
                                    tcpSettingsStruct->listInStreamSettingsTcpSettingsObjHeaderObjStruct = (struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectStruct));
                                    if (!tcpSettingsStruct->listInStreamSettingsTcpSettingsObjHeaderObjStruct) {
                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsTcpSettingsObjHeaderObjStruct is a null pointer, failed to allocate space");

                                        tcpSettingsStruct->listInStreamSettingsTcpSettingsObjHeaderObjStruct = NULL;
                                        jsonListInboundStreamSettingsTcpSettingsObjectStructDelete(tcpSettingsStruct);

                                        streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;
                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                        inboundObj->listInSniffingObjStruct = NULL;
                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                        listInStruct->listInObjStruct = NULL;
                                        jsonListInboundStructDelete(listInStruct);

                                        cJSON_Delete(jsonParser);

                                        return NULL;

                                    }

                                    struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectStruct* headerStruct = tcpSettingsStruct->listInStreamSettingsTcpSettingsObjHeaderObjStruct;

                                    char* type = cJSON_GetObjectItem(tcpHeaderObj, "type")->valuestring;
                                    size_t typeLen = strlen(type);
                                    char* typeCopy = (char*)malloc((typeLen + 1) * sizeof(char));
                                    strncpy(typeCopy, type, typeLen);
                                    typeCopy[typeLen] = '\0';
                                    headerStruct->type = typeCopy;

                                    headerStruct->listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct = (struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectRequestObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectRequestObjectStruct));
                                    if (!headerStruct->listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct) {
                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct is a null pointer, failed to allocate space");

                                        headerStruct->listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct = NULL;
                                        headerStruct->listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct = NULL;
                                        jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectStructDelete(headerStruct);

                                        tcpSettingsStruct->listInStreamSettingsTcpSettingsObjHeaderObjStruct = NULL;
                                        jsonListInboundStreamSettingsTcpSettingsObjectStructDelete(tcpSettingsStruct);

                                        streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;
                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                        inboundObj->listInSniffingObjStruct = NULL;
                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                        listInStruct->listInObjStruct = NULL;
                                        jsonListInboundStructDelete(listInStruct);

                                        cJSON_Delete(jsonParser);

                                        return NULL;

                                    }

                                    struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectRequestObjectStruct* headerReqStruct = headerStruct->listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct;

                                    headerReqStruct->listInStreamSettingsTcpSettingsObjHeaderObjReqHeadersStruct = NULL; // FIX: not necessary, this is only needed on something failing, the clear path will handle these nullification, check the entire code for it

                                    cJSON* requestHeaderObj = cJSON_GetObjectItem(tcpHeaderObj, "request");
                                    if (!requestHeaderObj) {
                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "requestHeaderObj is a null pointer");

                                        headerReqStruct->listInStreamSettingsTcpSettingsObjHeaderObjReqHeadersStruct = NULL;
                                        headerStruct->listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct = NULL;
                                        jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectStructDelete(headerStruct);

                                        tcpSettingsStruct->listInStreamSettingsTcpSettingsObjHeaderObjStruct = NULL;
                                        jsonListInboundStreamSettingsTcpSettingsObjectStructDelete(tcpSettingsStruct);

                                        streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;
                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                        inboundObj->listInSniffingObjStruct = NULL;
                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                        listInStruct->listInObjStruct = NULL;
                                        jsonListInboundStructDelete(listInStruct);

                                        cJSON_Delete(jsonParser);

                                        return NULL;

                                    }

                                    char* requestVersion = cJSON_GetObjectItem(requestHeaderObj, "version")->valuestring;
                                    size_t requestVersionLen = strlen(requestVersion);
                                    char* requestVersionCopy = (char*)malloc((requestVersionLen + 1) * sizeof(char));
                                    strncpy(requestVersionCopy, requestVersion, requestVersionLen);
                                    requestVersionCopy[requestVersionLen] = '\0';
                                    headerReqStruct->version = requestVersionCopy;

                                    char* requestMethod = cJSON_GetObjectItem(requestHeaderObj, "method")->valuestring;
                                    size_t requestMethodLen = strlen(requestMethod);
                                    char* requestMethodCopy = (char*)malloc((requestMethodLen + 1) * sizeof(char));
                                    strncpy(requestMethodCopy, requestMethod, requestMethodLen);
                                    requestMethodCopy[requestMethodLen] = '\0';
                                    headerReqStruct->method = requestMethodCopy;

                                    cJSON* requestPathObj = cJSON_GetObjectItem(requestHeaderObj, "path");
                                    size_t requestPathCount = cJSON_GetArraySize(requestPathObj);
                                    const char** requestPathCopy = (const char**)malloc((requestPathCount ? requestPathCount : 1) * sizeof(char*));
                                    for (size_t requestPathIdx = 0; requestPathIdx < requestPathCount; requestPathIdx++) {
                                        char* requestPathItem = cJSON_GetArrayItem(requestPathObj, requestPathIdx)->valuestring;
                                        size_t requestPathItemLen = strlen(requestPathItem);
                                        char* requestPathItemCopy = (char*)malloc((requestPathItemLen + 1) * sizeof(char));
                                        strncpy(requestPathItemCopy, requestPathItem, requestPathItemLen);
                                        requestPathItemCopy[requestPathItemLen] = '\0';
                                        requestPathCopy[requestPathIdx] = requestPathItemCopy;
                                    }
                                    headerReqStruct->path = requestPathCopy;
                                    headerReqStruct->pathCount = requestPathCount;

                                    if (
                                        cJSON_HasObjectItem(requestHeaderObj, "headers") &&
                                        cJSON_IsObject(cJSON_GetObjectItem(requestHeaderObj, "headers"))
                                       ) {
                                        cJSON* requestHeadersObj = cJSON_GetObjectItem(requestHeaderObj, "headers");
                                        size_t requestHeadersCount = cJSON_GetArraySize(requestHeadersObj);
                                        struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersStruct* requestHeadersCopy = (struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersStruct*)malloc((requestHeadersCount ? requestHeadersCount : 1) * sizeof(struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersStruct));
                                        for (size_t headerIdx = 0; headerIdx < requestHeadersCount; headerIdx++) {
                                            cJSON* requestHeadersItem = cJSON_GetArrayItem(requestHeadersObj, headerIdx);

                                            char* headerName = requestHeadersItem->string;
                                            size_t headerNameLen = strlen(headerName);
                                            char* headerNameCopy = (char*)malloc((headerNameLen + 1) * sizeof(char));
                                            strncpy(headerNameCopy, headerName, headerNameLen);
                                            headerNameCopy[headerNameLen] = '\0';
                                            requestHeadersCopy[headerIdx].name = headerNameCopy;

                                            size_t headerValueCount = cJSON_GetArraySize(requestHeadersItem);
                                            const char** headerValueCopy = (const char**)malloc((headerValueCount ? headerValueCount : 1) * sizeof(char*));
                                            for (size_t valueIdx = 0; valueIdx < headerValueCount; valueIdx++) {
                                                char* headerValueItem = cJSON_GetArrayItem(requestHeadersItem, valueIdx)->valuestring;
                                                size_t headerValueItemLen = strlen(headerValueItem);
                                                char* headerValueItemCopy = (char*)malloc((headerValueItemLen + 1) * sizeof(char));
                                                strncpy(headerValueItemCopy, headerValueItem, headerValueItemLen);
                                                headerValueItemCopy[headerValueItemLen] = '\0';
                                                headerValueCopy[valueIdx] = headerValueItemCopy;
                                            }
                                            requestHeadersCopy[headerIdx].value = headerValueCopy;
                                            requestHeadersCopy[headerIdx].valueCount = headerValueCount;

                                        }
                                        headerReqStruct->listInStreamSettingsTcpSettingsObjHeaderObjReqHeadersStruct = requestHeadersCopy;
                                        headerReqStruct->jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersStructSize = requestHeadersCount;
                                    }

                                    headerStruct->listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct = (struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectResponseObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectResponseObjectStruct));
                                    if (!headerStruct->listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct) {
                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct is a null pointer, failed to allocate space");

                                        headerStruct->listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct = NULL;
                                        jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectStructDelete(headerStruct);

                                        tcpSettingsStruct->listInStreamSettingsTcpSettingsObjHeaderObjStruct = NULL;
                                        jsonListInboundStreamSettingsTcpSettingsObjectStructDelete(tcpSettingsStruct);

                                        streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;
                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                        inboundObj->listInSniffingObjStruct = NULL;
                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                        listInStruct->listInObjStruct = NULL;
                                        jsonListInboundStructDelete(listInStruct);

                                        cJSON_Delete(jsonParser);

                                        return NULL;

                                    }

                                    struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectResponseObjectStruct* headerResStruct = headerStruct->listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct;

                                    headerResStruct->listInStreamSettingsTcpSettingsObjHeaderObjResHeadersStruct = NULL;

                                    cJSON* responseHeaderObj = cJSON_GetObjectItem(tcpHeaderObj, "response");
                                    if (!responseHeaderObj) {
                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "responseHeaderObj is a null pointer");

                                        headerResStruct->listInStreamSettingsTcpSettingsObjHeaderObjResHeadersStruct = NULL;
                                        jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectStructDelete(headerStruct);

                                        tcpSettingsStruct->listInStreamSettingsTcpSettingsObjHeaderObjStruct = NULL;
                                        jsonListInboundStreamSettingsTcpSettingsObjectStructDelete(tcpSettingsStruct);

                                        streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;
                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                        inboundObj->listInSniffingObjStruct = NULL;
                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                        listInStruct->listInObjStruct = NULL;
                                        jsonListInboundStructDelete(listInStruct);

                                        cJSON_Delete(jsonParser);

                                        return NULL;

                                    }

                                    char* responseVersion = cJSON_GetObjectItem(responseHeaderObj, "version")->valuestring;
                                    size_t responseVersionLen = strlen(responseVersion);
                                    char* responseVersionCopy = (char*)malloc((responseVersionLen + 1) * sizeof(char));
                                    strncpy(responseVersionCopy, responseVersion, responseVersionLen);
                                    responseVersionCopy[responseVersionLen] = '\0';
                                    headerResStruct->version = responseVersionCopy;

                                    char* responseStatus = cJSON_GetObjectItem(responseHeaderObj, "status")->valuestring;
                                    size_t responseStatusLen = strlen(responseStatus);
                                    char* responseStatusCopy = (char*)malloc((responseStatusLen + 1) * sizeof(char));
                                    strncpy(responseStatusCopy, responseStatus, responseStatusLen);
                                    responseStatusCopy[responseStatusLen] = '\0';
                                    headerResStruct->status = responseStatusCopy;

                                    char* responseReason = cJSON_GetObjectItem(responseHeaderObj, "reason")->valuestring;
                                    size_t responseReasonLen = strlen(responseReason);
                                    char* responseReasonCopy = (char*)malloc((responseReasonLen + 1) * sizeof(char));
                                    strncpy(responseReasonCopy, responseReason, responseReasonLen);
                                    responseReasonCopy[responseReasonLen] = '\0';
                                    headerResStruct->reason = responseReasonCopy;

                                    if (
                                        cJSON_HasObjectItem(responseHeaderObj, "headers") &&
                                        cJSON_IsObject(cJSON_GetObjectItem(responseHeaderObj, "headers"))
                                       ) {
                                        cJSON* responseHeadersObj = cJSON_GetObjectItem(responseHeaderObj, "headers");
                                        size_t responseHeadersCount = cJSON_GetArraySize(responseHeadersObj);
                                        struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersStruct* responseHeadersCopy = (struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersStruct*)malloc((responseHeadersCount ? responseHeadersCount : 1) * sizeof(struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersStruct));
                                        for (size_t headerIdx = 0; headerIdx < responseHeadersCount; headerIdx++) {
                                            cJSON* responseHeadersItem = cJSON_GetArrayItem(responseHeadersObj, headerIdx);

                                            char* headerName = responseHeadersItem->string;
                                            size_t headerNameLen = strlen(headerName);
                                            char* headerNameCopy = (char*)malloc((headerNameLen + 1) * sizeof(char));
                                            strncpy(headerNameCopy, headerName, headerNameLen);
                                            headerNameCopy[headerNameLen] = '\0';
                                            responseHeadersCopy[headerIdx].name = headerNameCopy;

                                            size_t headerValueCount = cJSON_GetArraySize(responseHeadersItem);
                                            const char** headerValueCopy = (const char**)malloc((headerValueCount ? headerValueCount : 1) * sizeof(char*));
                                            for (size_t valueIdx = 0; valueIdx < headerValueCount; valueIdx++) {
                                                char* headerValueItem = cJSON_GetArrayItem(responseHeadersItem, valueIdx)->valuestring;
                                                size_t headerValueItemLen = strlen(headerValueItem);
                                                char* headerValueItemCopy = (char*)malloc((headerValueItemLen + 1) * sizeof(char));
                                                strncpy(headerValueItemCopy, headerValueItem, headerValueItemLen);
                                                headerValueItemCopy[headerValueItemLen] = '\0';
                                                headerValueCopy[valueIdx] = headerValueItemCopy;
                                            }
                                            responseHeadersCopy[headerIdx].value = headerValueCopy;
                                            responseHeadersCopy[headerIdx].valueCount = headerValueCount;
                                        }
                                        headerResStruct->listInStreamSettingsTcpSettingsObjHeaderObjResHeadersStruct = responseHeadersCopy;
                                        headerResStruct->jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersStructSize = responseHeadersCount;
                                    }

                                    } else {
                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the tcpSettings header object, type/request/response are not present");

                                        tcpSettingsStruct->listInStreamSettingsTcpSettingsObjHeaderObjStruct = NULL;
                                        jsonListInboundStreamSettingsTcpSettingsObjectStructDelete(tcpSettingsStruct);

                                        streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;
                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                        inboundObj->listInSniffingObjStruct = NULL;
                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                        listInStruct->listInObjStruct = NULL;
                                        jsonListInboundStructDelete(listInStruct);

                                        cJSON_Delete(jsonParser);

                                        return NULL;

                                    }

                            } else {
                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the tcpSettings object, acceptProxyProtocol/header are not present");

                                streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;
                                jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                inboundObj->listInStreamSettingsObjStruct = NULL;
                                inboundObj->listInSniffingObjStruct = NULL;
                                jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                listInStruct->listInObjStruct = NULL;
                                jsonListInboundStructDelete(listInStruct);

                                cJSON_Delete(jsonParser);

                                return NULL;

                            }

                        } else {
                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the streamSettings object, tcpSettings is not present");

                            streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;
                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                            inboundObj->listInStreamSettingsObjStruct = NULL;
                            inboundObj->listInSniffingObjStruct = NULL;
                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                            listInStruct->listInObjStruct = NULL;
                            jsonListInboundStructDelete(listInStruct);

                            cJSON_Delete(jsonParser);

                            return NULL;

                        }

                        // The security field is a plain string and currently "none" for every tcp variant.
                        // TODO: when the security field shows a different value, it may carry extra
                        // settings ( e.g. a tls configuration ), take care of them at the settings field
                        if (
                            cJSON_HasObjectItem(streamSettingsObj, "security") &&
                            cJSON_IsString(cJSON_GetObjectItem(streamSettingsObj, "security"))
                           ) {
                            char* security = cJSON_GetObjectItem(streamSettingsObj, "security")->valuestring;
                            size_t securityLen = strlen(security);
                            char* securityCopy = (char*)malloc((securityLen + 1) * sizeof(char));
                            strncpy(securityCopy, security, securityLen);
                            securityCopy[securityLen] = '\0';
                            streamSettingsStruct->security = securityCopy;

                        }

                        // The tcp mask ( finalmask ) is an optional field, it holds a "tcp" array
                        // whose elements carry a "type" ( fragment, header-custom, sudoku, xmc )
                        // and a "settings" object shaped by that type
                        if (
                            cJSON_HasObjectItem(streamSettingsObj, "finalmask") &&
                            cJSON_IsObject(cJSON_GetObjectItem(streamSettingsObj, "finalmask"))
                           ) {
                            cJSON* tcpFinalMaskObj = cJSON_GetObjectItem(streamSettingsObj, "finalmask");
                            if (!tcpFinalMaskObj) {
                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "tcpFinalMaskObj is a null pointer");

                                jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                inboundObj->listInStreamSettingsObjStruct = NULL;
                                inboundObj->listInSniffingObjStruct = NULL;
                                jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                listInStruct->listInObjStruct = NULL;
                                jsonListInboundStructDelete(listInStruct);

                                cJSON_Delete(jsonParser);

                                return NULL;

                            }

                            streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = (struct jsonListInboundStreamSettingsTcpFinalMaskObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsTcpFinalMaskObjectStruct));
                            if (!streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct) {
                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsTcpFinalMaskObjStruct is a null pointer, failed to allocate space");

                                streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                                jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                inboundObj->listInStreamSettingsObjStruct = NULL;
                                inboundObj->listInSniffingObjStruct = NULL;
                                jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                listInStruct->listInObjStruct = NULL;
                                jsonListInboundStructDelete(listInStruct);

                                cJSON_Delete(jsonParser);

                                return NULL;

                            }

                            struct jsonListInboundStreamSettingsTcpFinalMaskObjectStruct* tcpFinalMaskStruct = streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct;
                            tcpFinalMaskStruct->listInStreamSettingsTcpFinalMaskTcpStruct = NULL;
                            tcpFinalMaskStruct->jsonListInboundStreamSettingsTcpFinalMaskTcpStructSize = 0;

                            const char* tcpMaskTypes[] = {
                                "fragment", // Fragment
                                "header-custom", // Header Custom
                                "sudoku", // Sudoku
                                "xmc" // XMC

                            };

                            enum tcpMaskTypesEnum {
                                TCPMASKTYPE_FRAGMENT,
                                TCPMASKTYPE_HEADERCUSTOM,
                                TCPMASKTYPE_SUDOKU,
                                TCPMASKTYPE_XMC,
                                TCPMASKTYPE_COUNT

                            };

                            if (
                                cJSON_HasObjectItem(tcpFinalMaskObj, "tcp") &&
                                cJSON_IsArray(cJSON_GetObjectItem(tcpFinalMaskObj, "tcp"))
                               ) {
                                cJSON* tcpObj = cJSON_GetObjectItem(tcpFinalMaskObj, "tcp");
                                if (!tcpObj) {
                                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "tcpObj is a null pointer");

                                    jsonListInboundStreamSettingsTcpFinalMaskObjectStructDelete(tcpFinalMaskStruct);

                                    streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                                    jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                    inboundObj->listInStreamSettingsObjStruct = NULL;
                                    inboundObj->listInSniffingObjStruct = NULL;
                                    jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                    listInStruct->listInObjStruct = NULL;
                                    jsonListInboundStructDelete(listInStruct);

                                    cJSON_Delete(jsonParser);

                                    return NULL;

                                }

                                size_t tcpCount = cJSON_GetArraySize(tcpObj);
                                struct jsonListInboundStreamSettingsTcpFinalMaskTcpObjectStruct* tcpCopy = (struct jsonListInboundStreamSettingsTcpFinalMaskTcpObjectStruct*)malloc((tcpCount ? tcpCount : 1) * sizeof(struct jsonListInboundStreamSettingsTcpFinalMaskTcpObjectStruct));
                                if (!tcpCopy) {
                                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "tcpCopy is a null pointer, failed to allocate space");

                                    jsonListInboundStreamSettingsTcpFinalMaskObjectStructDelete(tcpFinalMaskStruct);

                                    streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                                    jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                    inboundObj->listInStreamSettingsObjStruct = NULL;
                                    inboundObj->listInSniffingObjStruct = NULL;
                                    jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                    listInStruct->listInObjStruct = NULL;
                                    jsonListInboundStructDelete(listInStruct);

                                    cJSON_Delete(jsonParser);

                                    return NULL;

                                }

                                tcpFinalMaskStruct->listInStreamSettingsTcpFinalMaskTcpStruct = tcpCopy;
                                tcpFinalMaskStruct->jsonListInboundStreamSettingsTcpFinalMaskTcpStructSize = tcpCount;

                                for (size_t t = 0; t < tcpCount; t++) {
                                    tcpCopy[t].type = NULL;
                                    tcpCopy[t].listInStreamSettingsTcpFinalMaskFragmentObjStruct = NULL;
                                    tcpCopy[t].listInStreamSettingsTcpFinalMaskHeaderCustomObjStruct = NULL;
                                    tcpCopy[t].listInStreamSettingsTcpFinalMaskSudokuObjStruct = NULL;
                                    tcpCopy[t].listInStreamSettingsTcpFinalMaskXmcObjStruct = NULL;

                                }

                                for (size_t t = 0; t < tcpCount; t++) {
                                    cJSON* tcpItem = cJSON_GetArrayItem(tcpObj, t);
                                    struct jsonListInboundStreamSettingsTcpFinalMaskTcpObjectStruct* tcpStruct = &tcpCopy[t];

                                    if (
                                        cJSON_HasObjectItem(tcpItem, "type") &&
                                        cJSON_IsString(cJSON_GetObjectItem(tcpItem, "type"))
                                       ) {
                                        char* tcpType = cJSON_GetObjectItem(tcpItem, "type")->valuestring;
                                        size_t tcpTypeLen = strlen(tcpType);
                                        char* tcpTypeCopy = (char*)malloc((tcpTypeLen + 1) * sizeof(char));
                                        strncpy(tcpTypeCopy, tcpType, tcpTypeLen);
                                        tcpTypeCopy[tcpTypeLen] = '\0';
                                        tcpStruct->type = tcpTypeCopy;

                                        enum tcpMaskTypesEnum tType = TCPMASKTYPE_COUNT;
                                        for (int t2 = 0; t2 < TCPMASKTYPE_COUNT; t2++) {
                                            if (strncmp(tcpMaskTypes[t2], tcpStruct->type, strlen(tcpMaskTypes[t2])) == 0) {
                                                tType = (enum tcpMaskTypesEnum)t2;
                                                break;

                                            }

                                        }
                                        if (tType == TCPMASKTYPE_COUNT) {
                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Unable to detect tcp mask type");

                                            jsonListInboundStreamSettingsTcpFinalMaskObjectStructDelete(tcpFinalMaskStruct);

                                            streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                            inboundObj->listInSniffingObjStruct = NULL;
                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                            listInStruct->listInObjStruct = NULL;
                                            jsonListInboundStructDelete(listInStruct);

                                            cJSON_Delete(jsonParser);

                                            return NULL;

                                        }

                                        if (
                                            cJSON_HasObjectItem(tcpItem, "settings") &&
                                            cJSON_IsObject(cJSON_GetObjectItem(tcpItem, "settings"))
                                           ) {
                                            cJSON* tcpMaskSettingsObj = cJSON_GetObjectItem(tcpItem, "settings");
                                            if (!tcpMaskSettingsObj) {
                                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "tcpMaskSettingsObj is a null pointer");

                                                jsonListInboundStreamSettingsTcpFinalMaskObjectStructDelete(tcpFinalMaskStruct);

                                                streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                                                jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                inboundObj->listInStreamSettingsObjStruct = NULL;
                                                inboundObj->listInSniffingObjStruct = NULL;
                                                jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                listInStruct->listInObjStruct = NULL;
                                                jsonListInboundStructDelete(listInStruct);

                                                cJSON_Delete(jsonParser);

                                                return NULL;

                                            }

                                            switch (tType) {
                                                case TCPMASKTYPE_FRAGMENT:
                                                    tcpStruct->listInStreamSettingsTcpFinalMaskFragmentObjStruct = (struct jsonListInboundStreamSettingsTcpFinalMaskFragmentObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsTcpFinalMaskFragmentObjectStruct));
                                                    if (!tcpStruct->listInStreamSettingsTcpFinalMaskFragmentObjStruct) {
                                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsTcpFinalMaskFragmentObjStruct is a null pointer, failed to allocate space");

                                                        jsonListInboundStreamSettingsTcpFinalMaskObjectStructDelete(tcpFinalMaskStruct);

                                                        streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                                        inboundObj->listInSniffingObjStruct = NULL;
                                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                        listInStruct->listInObjStruct = NULL;
                                                        jsonListInboundStructDelete(listInStruct);

                                                        cJSON_Delete(jsonParser);

                                                        return NULL;

                                                    }

                                                    struct jsonListInboundStreamSettingsTcpFinalMaskFragmentObjectStruct* fragmentStruct = tcpStruct->listInStreamSettingsTcpFinalMaskFragmentObjStruct;
                                                    fragmentStruct->packets = NULL;
                                                    fragmentStruct->lengths = NULL;
                                                    fragmentStruct->lengthsCount = 0;
                                                    fragmentStruct->maxSplit = NULL;
                                                    fragmentStruct->delays = NULL;
                                                    fragmentStruct->delaysCount = 0;

                                                    if (
                                                        cJSON_HasObjectItem(tcpMaskSettingsObj, "packets") &&
                                                        cJSON_IsString(cJSON_GetObjectItem(tcpMaskSettingsObj, "packets"))
                                                       ) {
                                                        char* fragmentPackets = cJSON_GetObjectItem(tcpMaskSettingsObj, "packets")->valuestring;
                                                        size_t fragmentPacketsLen = strlen(fragmentPackets);
                                                        char* fragmentPacketsCopy = (char*)malloc((fragmentPacketsLen + 1) * sizeof(char));
                                                        strncpy(fragmentPacketsCopy, fragmentPackets, fragmentPacketsLen);
                                                        fragmentPacketsCopy[fragmentPacketsLen] = '\0';
                                                        fragmentStruct->packets = fragmentPacketsCopy;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(tcpMaskSettingsObj, "lengths") &&
                                                        cJSON_IsArray(cJSON_GetObjectItem(tcpMaskSettingsObj, "lengths"))
                                                       ) {
                                                        cJSON* fragmentLengthsObj = cJSON_GetObjectItem(tcpMaskSettingsObj, "lengths");
                                                        size_t fragmentLengthsCount = cJSON_GetArraySize(fragmentLengthsObj);
                                                        const char** fragmentLengthsCopy = (const char**)malloc((fragmentLengthsCount ? fragmentLengthsCount : 1) * sizeof(char*));
                                                        if (!fragmentLengthsCopy) {
                                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "fragmentLengthsCopy is a null pointer, failed to allocate space");

                                                            jsonListInboundStreamSettingsTcpFinalMaskObjectStructDelete(tcpFinalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                                            inboundObj->listInSniffingObjStruct = NULL;
                                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                            listInStruct->listInObjStruct = NULL;
                                                            jsonListInboundStructDelete(listInStruct);

                                                            cJSON_Delete(jsonParser);

                                                            return NULL;

                                                        }

                                                        for (size_t lenIdx = 0; lenIdx < fragmentLengthsCount; lenIdx++) {
                                                            char* fragmentLengthItem = cJSON_GetArrayItem(fragmentLengthsObj, lenIdx)->valuestring;
                                                            size_t fragmentLengthItemLen = strlen(fragmentLengthItem);
                                                            char* fragmentLengthItemCopy = (char*)malloc((fragmentLengthItemLen + 1) * sizeof(char));
                                                            strncpy(fragmentLengthItemCopy, fragmentLengthItem, fragmentLengthItemLen);
                                                            fragmentLengthItemCopy[fragmentLengthItemLen] = '\0';
                                                            fragmentLengthsCopy[lenIdx] = fragmentLengthItemCopy;

                                                        }
                                                        fragmentStruct->lengths = fragmentLengthsCopy;
                                                        fragmentStruct->lengthsCount = (int64_t)fragmentLengthsCount;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(tcpMaskSettingsObj, "maxSplit") &&
                                                        cJSON_IsString(cJSON_GetObjectItem(tcpMaskSettingsObj, "maxSplit"))
                                                       ) {
                                                        char* fragmentMaxSplit = cJSON_GetObjectItem(tcpMaskSettingsObj, "maxSplit")->valuestring;
                                                        size_t fragmentMaxSplitLen = strlen(fragmentMaxSplit);
                                                        char* fragmentMaxSplitCopy = (char*)malloc((fragmentMaxSplitLen + 1) * sizeof(char));
                                                        strncpy(fragmentMaxSplitCopy, fragmentMaxSplit, fragmentMaxSplitLen);
                                                        fragmentMaxSplitCopy[fragmentMaxSplitLen] = '\0';
                                                        fragmentStruct->maxSplit = fragmentMaxSplitCopy;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(tcpMaskSettingsObj, "delays") &&
                                                        cJSON_IsArray(cJSON_GetObjectItem(tcpMaskSettingsObj, "delays"))
                                                       ) {
                                                        cJSON* fragmentDelaysObj = cJSON_GetObjectItem(tcpMaskSettingsObj, "delays");
                                                        size_t fragmentDelaysCount = cJSON_GetArraySize(fragmentDelaysObj);
                                                        const char** fragmentDelaysCopy = (const char**)malloc((fragmentDelaysCount ? fragmentDelaysCount : 1) * sizeof(char*));
                                                        if (!fragmentDelaysCopy) {
                                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "fragmentDelaysCopy is a null pointer, failed to allocate space");

                                                            jsonListInboundStreamSettingsTcpFinalMaskObjectStructDelete(tcpFinalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                                            inboundObj->listInSniffingObjStruct = NULL;
                                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                            listInStruct->listInObjStruct = NULL;
                                                            jsonListInboundStructDelete(listInStruct);

                                                            cJSON_Delete(jsonParser);

                                                            return NULL;

                                                        }

                                                        for (size_t delayIdx = 0; delayIdx < fragmentDelaysCount; delayIdx++) {
                                                            char* fragmentDelayItem = cJSON_GetArrayItem(fragmentDelaysObj, delayIdx)->valuestring;
                                                            size_t fragmentDelayItemLen = strlen(fragmentDelayItem);
                                                            char* fragmentDelayItemCopy = (char*)malloc((fragmentDelayItemLen + 1) * sizeof(char));
                                                            strncpy(fragmentDelayItemCopy, fragmentDelayItem, fragmentDelayItemLen);
                                                            fragmentDelayItemCopy[fragmentDelayItemLen] = '\0';
                                                            fragmentDelaysCopy[delayIdx] = fragmentDelayItemCopy;

                                                        }
                                                        fragmentStruct->delays = fragmentDelaysCopy;
                                                        fragmentStruct->delaysCount = (int64_t)fragmentDelaysCount;

                                                    }

                                                    break;

                                                case TCPMASKTYPE_HEADERCUSTOM:
                                                    tcpStruct->listInStreamSettingsTcpFinalMaskHeaderCustomObjStruct = (struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomObjectStruct));
                                                    if (!tcpStruct->listInStreamSettingsTcpFinalMaskHeaderCustomObjStruct) {
                                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsTcpFinalMaskHeaderCustomObjStruct is a null pointer, failed to allocate space");

                                                        jsonListInboundStreamSettingsTcpFinalMaskObjectStructDelete(tcpFinalMaskStruct);

                                                        streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                                        inboundObj->listInSniffingObjStruct = NULL;
                                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                        listInStruct->listInObjStruct = NULL;
                                                        jsonListInboundStructDelete(listInStruct);

                                                        cJSON_Delete(jsonParser);

                                                        return NULL;

                                                    }

                                                    struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomObjectStruct* tcpHeaderCustomStruct = tcpStruct->listInStreamSettingsTcpFinalMaskHeaderCustomObjStruct;
                                                    tcpHeaderCustomStruct->listInStreamSettingsTcpFinalMaskHeaderCustomClientGroupStruct = NULL;
                                                    tcpHeaderCustomStruct->jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomClientGroupStructSize = 0;
                                                    tcpHeaderCustomStruct->listInStreamSettingsTcpFinalMaskHeaderCustomServerGroupStruct = NULL;
                                                    tcpHeaderCustomStruct->jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomServerGroupStructSize = 0;

                                                    // the client and server fields hold arrays of packet groups, each
                                                    // group is an array of packet objects
                                                    if (
                                                        cJSON_HasObjectItem(tcpMaskSettingsObj, "clients") &&
                                                        cJSON_IsArray(cJSON_GetObjectItem(tcpMaskSettingsObj, "clients"))
                                                       ) {
                                                        cJSON* clientsGroupArr = cJSON_GetObjectItem(tcpMaskSettingsObj, "clients");
                                                        size_t clientsGroupCount = cJSON_GetArraySize(clientsGroupArr);
                                                        struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomGroupObjectStruct* headerCustomClientGroupCopy = (struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomGroupObjectStruct*)malloc((clientsGroupCount ? clientsGroupCount : 1) * sizeof(struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomGroupObjectStruct));
                                                        if (!headerCustomClientGroupCopy) {
                                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "headerCustomClientGroupCopy is a null pointer, failed to allocate space");

                                                            jsonListInboundStreamSettingsTcpFinalMaskObjectStructDelete(tcpFinalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                                            inboundObj->listInSniffingObjStruct = NULL;
                                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                            listInStruct->listInObjStruct = NULL;
                                                            jsonListInboundStructDelete(listInStruct);

                                                            cJSON_Delete(jsonParser);

                                                            return NULL;

                                                        }

                                                        for (size_t g = 0; g < clientsGroupCount; g++) {
                                                            headerCustomClientGroupCopy[g].listInStreamSettingsTcpFinalMaskHeaderCustomPacketStruct = NULL;
                                                            headerCustomClientGroupCopy[g].jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomPacketStructSize = 0;

                                                        }

                                                        for (size_t g = 0; g < clientsGroupCount; g++) {
                                                            cJSON* clientGroupItem = cJSON_GetArrayItem(clientsGroupArr, g);
                                                            size_t clientPacketCount = cJSON_GetArraySize(clientGroupItem);
                                                            struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomPacketObjectStruct* headerCustomClientPacketCopy = (struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomPacketObjectStruct*)malloc((clientPacketCount ? clientPacketCount : 1) * sizeof(struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomPacketObjectStruct));
                                                            if (!headerCustomClientPacketCopy) {
                                                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "headerCustomClientPacketCopy is a null pointer, failed to allocate space");

                                                                jsonListInboundStreamSettingsTcpFinalMaskObjectStructDelete(tcpFinalMaskStruct);

                                                                streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                                                                jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                                inboundObj->listInStreamSettingsObjStruct = NULL;
                                                                inboundObj->listInSniffingObjStruct = NULL;
                                                                jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                                jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                                listInStruct->listInObjStruct = NULL;
                                                                jsonListInboundStructDelete(listInStruct);

                                                                cJSON_Delete(jsonParser);

                                                                return NULL;

                                                            }

                                                            for (size_t c = 0; c < clientPacketCount; c++) {
                                                                headerCustomClientPacketCopy[c].type = NULL;
                                                                headerCustomClientPacketCopy[c].delay = NULL;
                                                                headerCustomClientPacketCopy[c].rand = NULL;
                                                                headerCustomClientPacketCopy[c].randRange = NULL;
                                                                headerCustomClientPacketCopy[c].packet = NULL;

                                                            }

                                                            for (size_t c = 0; c < clientPacketCount; c++) {
                                                                cJSON* clientPacketItem = cJSON_GetArrayItem(clientGroupItem, c);

                                                                if (
                                                                    cJSON_HasObjectItem(clientPacketItem, "type") &&
                                                                    cJSON_IsString(cJSON_GetObjectItem(clientPacketItem, "type"))
                                                                   ) {
                                                                    char* clientPacketType = cJSON_GetObjectItem(clientPacketItem, "type")->valuestring;
                                                                    size_t clientPacketTypeLen = strlen(clientPacketType);
                                                                    char* clientPacketTypeCopy = (char*)malloc((clientPacketTypeLen + 1) * sizeof(char));
                                                                    strncpy(clientPacketTypeCopy, clientPacketType, clientPacketTypeLen);
                                                                    clientPacketTypeCopy[clientPacketTypeLen] = '\0';
                                                                    headerCustomClientPacketCopy[c].type = clientPacketTypeCopy;

                                                                }

                                                                if (
                                                                    cJSON_HasObjectItem(clientPacketItem, "delay") &&
                                                                    cJSON_IsString(cJSON_GetObjectItem(clientPacketItem, "delay"))
                                                                   ) {
                                                                    char* clientPacketDelay = cJSON_GetObjectItem(clientPacketItem, "delay")->valuestring;
                                                                    size_t clientPacketDelayLen = strlen(clientPacketDelay);
                                                                    char* clientPacketDelayCopy = (char*)malloc((clientPacketDelayLen + 1) * sizeof(char));
                                                                    strncpy(clientPacketDelayCopy, clientPacketDelay, clientPacketDelayLen);
                                                                    clientPacketDelayCopy[clientPacketDelayLen] = '\0';
                                                                    headerCustomClientPacketCopy[c].delay = clientPacketDelayCopy;

                                                                }

                                                                if (
                                                                    cJSON_HasObjectItem(clientPacketItem, "rand") &&
                                                                    cJSON_IsString(cJSON_GetObjectItem(clientPacketItem, "rand"))
                                                                   ) {
                                                                    char* clientPacketRand = cJSON_GetObjectItem(clientPacketItem, "rand")->valuestring;
                                                                    size_t clientPacketRandLen = strlen(clientPacketRand);
                                                                    char* clientPacketRandCopy = (char*)malloc((clientPacketRandLen + 1) * sizeof(char));
                                                                    strncpy(clientPacketRandCopy, clientPacketRand, clientPacketRandLen);
                                                                    clientPacketRandCopy[clientPacketRandLen] = '\0';
                                                                    headerCustomClientPacketCopy[c].rand = clientPacketRandCopy;

                                                                }

                                                                if (
                                                                    cJSON_HasObjectItem(clientPacketItem, "randRange") &&
                                                                    cJSON_IsString(cJSON_GetObjectItem(clientPacketItem, "randRange"))
                                                                   ) {
                                                                    char* clientPacketRandRange = cJSON_GetObjectItem(clientPacketItem, "randRange")->valuestring;
                                                                    size_t clientPacketRandRangeLen = strlen(clientPacketRandRange);
                                                                    char* clientPacketRandRangeCopy = (char*)malloc((clientPacketRandRangeLen + 1) * sizeof(char));
                                                                    strncpy(clientPacketRandRangeCopy, clientPacketRandRange, clientPacketRandRangeLen);
                                                                    clientPacketRandRangeCopy[clientPacketRandRangeLen] = '\0';
                                                                    headerCustomClientPacketCopy[c].randRange = clientPacketRandRangeCopy;

                                                                }

                                                                if (
                                                                    cJSON_HasObjectItem(clientPacketItem, "packet") &&
                                                                    cJSON_IsString(cJSON_GetObjectItem(clientPacketItem, "packet"))
                                                                   ) {
                                                                    char* clientPacketVal = cJSON_GetObjectItem(clientPacketItem, "packet")->valuestring;
                                                                    size_t clientPacketLen = strlen(clientPacketVal);
                                                                    char* clientPacketCopy = (char*)malloc((clientPacketLen + 1) * sizeof(char));
                                                                    strncpy(clientPacketCopy, clientPacketVal, clientPacketLen);
                                                                    clientPacketCopy[clientPacketLen] = '\0';
                                                                    headerCustomClientPacketCopy[c].packet = clientPacketCopy;

                                                                }

                                                            }

                                                            headerCustomClientGroupCopy[g].listInStreamSettingsTcpFinalMaskHeaderCustomPacketStruct = headerCustomClientPacketCopy;
                                                            headerCustomClientGroupCopy[g].jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomPacketStructSize = clientPacketCount;

                                                        }

                                                        tcpHeaderCustomStruct->listInStreamSettingsTcpFinalMaskHeaderCustomClientGroupStruct = headerCustomClientGroupCopy;
                                                        tcpHeaderCustomStruct->jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomClientGroupStructSize = clientsGroupCount;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(tcpMaskSettingsObj, "servers") &&
                                                        cJSON_IsArray(cJSON_GetObjectItem(tcpMaskSettingsObj, "servers"))
                                                       ) {
                                                        cJSON* serversGroupArr = cJSON_GetObjectItem(tcpMaskSettingsObj, "servers");
                                                        size_t serversGroupCount = cJSON_GetArraySize(serversGroupArr);
                                                        struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomGroupObjectStruct* headerCustomServerGroupCopy = (struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomGroupObjectStruct*)malloc((serversGroupCount ? serversGroupCount : 1) * sizeof(struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomGroupObjectStruct));
                                                        if (!headerCustomServerGroupCopy) {
                                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "headerCustomServerGroupCopy is a null pointer, failed to allocate space");

                                                            jsonListInboundStreamSettingsTcpFinalMaskObjectStructDelete(tcpFinalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                                            inboundObj->listInSniffingObjStruct = NULL;
                                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                            listInStruct->listInObjStruct = NULL;
                                                            jsonListInboundStructDelete(listInStruct);

                                                            cJSON_Delete(jsonParser);

                                                            return NULL;

                                                        }

                                                        for (size_t g = 0; g < serversGroupCount; g++) {
                                                            headerCustomServerGroupCopy[g].listInStreamSettingsTcpFinalMaskHeaderCustomPacketStruct = NULL;
                                                            headerCustomServerGroupCopy[g].jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomPacketStructSize = 0;

                                                        }

                                                        for (size_t g = 0; g < serversGroupCount; g++) {
                                                            cJSON* serverGroupItem = cJSON_GetArrayItem(serversGroupArr, g);
                                                            size_t serverPacketCount = cJSON_GetArraySize(serverGroupItem);
                                                            struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomPacketObjectStruct* headerCustomServerPacketCopy = (struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomPacketObjectStruct*)malloc((serverPacketCount ? serverPacketCount : 1) * sizeof(struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomPacketObjectStruct));
                                                            if (!headerCustomServerPacketCopy) {
                                                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "headerCustomServerPacketCopy is a null pointer, failed to allocate space");

                                                                jsonListInboundStreamSettingsTcpFinalMaskObjectStructDelete(tcpFinalMaskStruct);

                                                                streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                                                                jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                                inboundObj->listInStreamSettingsObjStruct = NULL;
                                                                inboundObj->listInSniffingObjStruct = NULL;
                                                                jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                                jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                                listInStruct->listInObjStruct = NULL;
                                                                jsonListInboundStructDelete(listInStruct);

                                                                cJSON_Delete(jsonParser);

                                                                return NULL;

                                                            }

                                                            for (size_t c = 0; c < serverPacketCount; c++) {
                                                                headerCustomServerPacketCopy[c].type = NULL;
                                                                headerCustomServerPacketCopy[c].delay = NULL;
                                                                headerCustomServerPacketCopy[c].rand = NULL;
                                                                headerCustomServerPacketCopy[c].randRange = NULL;
                                                                headerCustomServerPacketCopy[c].packet = NULL;

                                                            }

                                                            for (size_t c = 0; c < serverPacketCount; c++) {
                                                                cJSON* serverPacketItem = cJSON_GetArrayItem(serverGroupItem, c);

                                                                if (
                                                                    cJSON_HasObjectItem(serverPacketItem, "type") &&
                                                                    cJSON_IsString(cJSON_GetObjectItem(serverPacketItem, "type"))
                                                                   ) {
                                                                    char* serverPacketType = cJSON_GetObjectItem(serverPacketItem, "type")->valuestring;
                                                                    size_t serverPacketTypeLen = strlen(serverPacketType);
                                                                    char* serverPacketTypeCopy = (char*)malloc((serverPacketTypeLen + 1) * sizeof(char));
                                                                    strncpy(serverPacketTypeCopy, serverPacketType, serverPacketTypeLen);
                                                                    serverPacketTypeCopy[serverPacketTypeLen] = '\0';
                                                                    headerCustomServerPacketCopy[c].type = serverPacketTypeCopy;

                                                                }

                                                                if (
                                                                    cJSON_HasObjectItem(serverPacketItem, "delay") &&
                                                                    cJSON_IsString(cJSON_GetObjectItem(serverPacketItem, "delay"))
                                                                   ) {
                                                                    char* serverPacketDelay = cJSON_GetObjectItem(serverPacketItem, "delay")->valuestring;
                                                                    size_t serverPacketDelayLen = strlen(serverPacketDelay);
                                                                    char* serverPacketDelayCopy = (char*)malloc((serverPacketDelayLen + 1) * sizeof(char));
                                                                    strncpy(serverPacketDelayCopy, serverPacketDelay, serverPacketDelayLen);
                                                                    serverPacketDelayCopy[serverPacketDelayLen] = '\0';
                                                                    headerCustomServerPacketCopy[c].delay = serverPacketDelayCopy;

                                                                }

                                                                if (
                                                                    cJSON_HasObjectItem(serverPacketItem, "rand") &&
                                                                    cJSON_IsString(cJSON_GetObjectItem(serverPacketItem, "rand"))
                                                                   ) {
                                                                    char* serverPacketRand = cJSON_GetObjectItem(serverPacketItem, "rand")->valuestring;
                                                                    size_t serverPacketRandLen = strlen(serverPacketRand);
                                                                    char* serverPacketRandCopy = (char*)malloc((serverPacketRandLen + 1) * sizeof(char));
                                                                    strncpy(serverPacketRandCopy, serverPacketRand, serverPacketRandLen);
                                                                    serverPacketRandCopy[serverPacketRandLen] = '\0';
                                                                    headerCustomServerPacketCopy[c].rand = serverPacketRandCopy;

                                                                }

                                                                if (
                                                                    cJSON_HasObjectItem(serverPacketItem, "randRange") &&
                                                                    cJSON_IsString(cJSON_GetObjectItem(serverPacketItem, "randRange"))
                                                                   ) {
                                                                    char* serverPacketRandRange = cJSON_GetObjectItem(serverPacketItem, "randRange")->valuestring;
                                                                    size_t serverPacketRandRangeLen = strlen(serverPacketRandRange);
                                                                    char* serverPacketRandRangeCopy = (char*)malloc((serverPacketRandRangeLen + 1) * sizeof(char));
                                                                    strncpy(serverPacketRandRangeCopy, serverPacketRandRange, serverPacketRandRangeLen);
                                                                    serverPacketRandRangeCopy[serverPacketRandRangeLen] = '\0';
                                                                    headerCustomServerPacketCopy[c].randRange = serverPacketRandRangeCopy;

                                                                }

                                                                if (
                                                                    cJSON_HasObjectItem(serverPacketItem, "packet") &&
                                                                    cJSON_IsString(cJSON_GetObjectItem(serverPacketItem, "packet"))
                                                                   ) {
                                                                    char* serverPacketVal = cJSON_GetObjectItem(serverPacketItem, "packet")->valuestring;
                                                                    size_t serverPacketLen = strlen(serverPacketVal);
                                                                    char* serverPacketCopy = (char*)malloc((serverPacketLen + 1) * sizeof(char));
                                                                    strncpy(serverPacketCopy, serverPacketVal, serverPacketLen);
                                                                    serverPacketCopy[serverPacketLen] = '\0';
                                                                    headerCustomServerPacketCopy[c].packet = serverPacketCopy;

                                                                }

                                                            }

                                                            headerCustomServerGroupCopy[g].listInStreamSettingsTcpFinalMaskHeaderCustomPacketStruct = headerCustomServerPacketCopy;
                                                            headerCustomServerGroupCopy[g].jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomPacketStructSize = serverPacketCount;

                                                        }

                                                        tcpHeaderCustomStruct->listInStreamSettingsTcpFinalMaskHeaderCustomServerGroupStruct = headerCustomServerGroupCopy;
                                                        tcpHeaderCustomStruct->jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomServerGroupStructSize = serversGroupCount;

                                                    }

                                                    break;

                                                case TCPMASKTYPE_SUDOKU:
                                                    tcpStruct->listInStreamSettingsTcpFinalMaskSudokuObjStruct = (struct jsonListInboundStreamSettingsTcpFinalMaskSudokuObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsTcpFinalMaskSudokuObjectStruct));
                                                    if (!tcpStruct->listInStreamSettingsTcpFinalMaskSudokuObjStruct) {
                                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsTcpFinalMaskSudokuObjStruct is a null pointer, failed to allocate space");

                                                        jsonListInboundStreamSettingsTcpFinalMaskObjectStructDelete(tcpFinalMaskStruct);

                                                        streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                                        inboundObj->listInSniffingObjStruct = NULL;
                                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                        listInStruct->listInObjStruct = NULL;
                                                        jsonListInboundStructDelete(listInStruct);

                                                        cJSON_Delete(jsonParser);

                                                        return NULL;

                                                    }

                                                    struct jsonListInboundStreamSettingsTcpFinalMaskSudokuObjectStruct* sudokuStruct = tcpStruct->listInStreamSettingsTcpFinalMaskSudokuObjStruct;
                                                    sudokuStruct->password = NULL;
                                                    sudokuStruct->customTables = NULL;
                                                    sudokuStruct->customTablesCount = 0;
                                                    sudokuStruct->ascii = NULL;
                                                    sudokuStruct->customTable = NULL;
                                                    sudokuStruct->paddingMin = 0;
                                                    sudokuStruct->paddingMax = 0;

                                                    if (
                                                        cJSON_HasObjectItem(tcpMaskSettingsObj, "password") &&
                                                        cJSON_IsString(cJSON_GetObjectItem(tcpMaskSettingsObj, "password"))
                                                       ) {
                                                        char* sudokuPassword = cJSON_GetObjectItem(tcpMaskSettingsObj, "password")->valuestring;
                                                        size_t sudokuPasswordLen = strlen(sudokuPassword);
                                                        char* sudokuPasswordCopy = (char*)malloc((sudokuPasswordLen + 1) * sizeof(char));
                                                        strncpy(sudokuPasswordCopy, sudokuPassword, sudokuPasswordLen);
                                                        sudokuPasswordCopy[sudokuPasswordLen] = '\0';
                                                        sudokuStruct->password = sudokuPasswordCopy;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(tcpMaskSettingsObj, "customTables") &&
                                                        cJSON_IsArray(cJSON_GetObjectItem(tcpMaskSettingsObj, "customTables"))
                                                       ) {
                                                        cJSON* sudokuCustomTablesObj = cJSON_GetObjectItem(tcpMaskSettingsObj, "customTables");
                                                        size_t sudokuCustomTablesCount = cJSON_GetArraySize(sudokuCustomTablesObj);
                                                        const char** sudokuCustomTablesCopy = (const char**)malloc((sudokuCustomTablesCount ? sudokuCustomTablesCount : 1) * sizeof(char*));
                                                        if (!sudokuCustomTablesCopy) {
                                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "sudokuCustomTablesCopy is a null pointer, failed to allocate space");

                                                            jsonListInboundStreamSettingsTcpFinalMaskObjectStructDelete(tcpFinalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                                            inboundObj->listInSniffingObjStruct = NULL;
                                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                            listInStruct->listInObjStruct = NULL;
                                                            jsonListInboundStructDelete(listInStruct);

                                                            cJSON_Delete(jsonParser);

                                                            return NULL;

                                                        }

                                                        for (size_t customTableIdx = 0; customTableIdx < sudokuCustomTablesCount; customTableIdx++) {
                                                            char* sudokuCustomTableItem = cJSON_GetArrayItem(sudokuCustomTablesObj, customTableIdx)->valuestring;
                                                            size_t sudokuCustomTableItemLen = strlen(sudokuCustomTableItem);
                                                            char* sudokuCustomTableItemCopy = (char*)malloc((sudokuCustomTableItemLen + 1) * sizeof(char));
                                                            strncpy(sudokuCustomTableItemCopy, sudokuCustomTableItem, sudokuCustomTableItemLen);
                                                            sudokuCustomTableItemCopy[sudokuCustomTableItemLen] = '\0';
                                                            sudokuCustomTablesCopy[customTableIdx] = sudokuCustomTableItemCopy;

                                                        }
                                                        sudokuStruct->customTables = sudokuCustomTablesCopy;
                                                        sudokuStruct->customTablesCount = (int64_t)sudokuCustomTablesCount;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(tcpMaskSettingsObj, "ascii") &&
                                                        cJSON_IsString(cJSON_GetObjectItem(tcpMaskSettingsObj, "ascii"))
                                                       ) {
                                                        char* sudokuAscii = cJSON_GetObjectItem(tcpMaskSettingsObj, "ascii")->valuestring;
                                                        size_t sudokuAsciiLen = strlen(sudokuAscii);
                                                        char* sudokuAsciiCopy = (char*)malloc((sudokuAsciiLen + 1) * sizeof(char));
                                                        strncpy(sudokuAsciiCopy, sudokuAscii, sudokuAsciiLen);
                                                        sudokuAsciiCopy[sudokuAsciiLen] = '\0';
                                                        sudokuStruct->ascii = sudokuAsciiCopy;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(tcpMaskSettingsObj, "customTable") &&
                                                        cJSON_IsString(cJSON_GetObjectItem(tcpMaskSettingsObj, "customTable"))
                                                       ) {
                                                        char* sudokuCustomTable = cJSON_GetObjectItem(tcpMaskSettingsObj, "customTable")->valuestring;
                                                        size_t sudokuCustomTableLen = strlen(sudokuCustomTable);
                                                        char* sudokuCustomTableCopy = (char*)malloc((sudokuCustomTableLen + 1) * sizeof(char));
                                                        strncpy(sudokuCustomTableCopy, sudokuCustomTable, sudokuCustomTableLen);
                                                        sudokuCustomTableCopy[sudokuCustomTableLen] = '\0';
                                                        sudokuStruct->customTable = sudokuCustomTableCopy;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(tcpMaskSettingsObj, "paddingMin") &&
                                                        cJSON_IsNumber(cJSON_GetObjectItem(tcpMaskSettingsObj, "paddingMin"))
                                                       ) {
                                                        sudokuStruct->paddingMin = (int64_t)cJSON_GetObjectItem(tcpMaskSettingsObj, "paddingMin")->valuedouble;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(tcpMaskSettingsObj, "paddingMax") &&
                                                        cJSON_IsNumber(cJSON_GetObjectItem(tcpMaskSettingsObj, "paddingMax"))
                                                       ) {
                                                        sudokuStruct->paddingMax = (int64_t)cJSON_GetObjectItem(tcpMaskSettingsObj, "paddingMax")->valuedouble;

                                                    }

                                                    break;

                                                case TCPMASKTYPE_XMC:
                                                    tcpStruct->listInStreamSettingsTcpFinalMaskXmcObjStruct = (struct jsonListInboundStreamSettingsTcpFinalMaskXmcObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsTcpFinalMaskXmcObjectStruct));
                                                    if (!tcpStruct->listInStreamSettingsTcpFinalMaskXmcObjStruct) {
                                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsTcpFinalMaskXmcObjStruct is a null pointer, failed to allocate space");

                                                        jsonListInboundStreamSettingsTcpFinalMaskObjectStructDelete(tcpFinalMaskStruct);

                                                        streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                                        inboundObj->listInSniffingObjStruct = NULL;
                                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                        listInStruct->listInObjStruct = NULL;
                                                        jsonListInboundStructDelete(listInStruct);

                                                        cJSON_Delete(jsonParser);

                                                        return NULL;

                                                    }

                                                    struct jsonListInboundStreamSettingsTcpFinalMaskXmcObjectStruct* xmcStruct = tcpStruct->listInStreamSettingsTcpFinalMaskXmcObjStruct;
                                                    xmcStruct->hostname = NULL;
                                                    xmcStruct->listInStreamSettingsTcpFinalMaskXmcProfileStruct = NULL;
                                                    xmcStruct->jsonListInboundStreamSettingsTcpFinalMaskXmcProfileStructSize = 0;
                                                    xmcStruct->password = NULL;

                                                    if (
                                                        cJSON_HasObjectItem(tcpMaskSettingsObj, "hostname") &&
                                                        cJSON_IsString(cJSON_GetObjectItem(tcpMaskSettingsObj, "hostname"))
                                                       ) {
                                                        char* xmcHostname = cJSON_GetObjectItem(tcpMaskSettingsObj, "hostname")->valuestring;
                                                        size_t xmcHostnameLen = strlen(xmcHostname);
                                                        char* xmcHostnameCopy = (char*)malloc((xmcHostnameLen + 1) * sizeof(char));
                                                        strncpy(xmcHostnameCopy, xmcHostname, xmcHostnameLen);
                                                        xmcHostnameCopy[xmcHostnameLen] = '\0';
                                                        xmcStruct->hostname = xmcHostnameCopy;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(tcpMaskSettingsObj, "profiles") &&
                                                        cJSON_IsArray(cJSON_GetObjectItem(tcpMaskSettingsObj, "profiles"))
                                                       ) {
                                                        cJSON* xmcProfilesObj = cJSON_GetObjectItem(tcpMaskSettingsObj, "profiles");
                                                        size_t xmcProfilesCount = cJSON_GetArraySize(xmcProfilesObj);
                                                        struct jsonListInboundStreamSettingsTcpFinalMaskXmcProfileObjectStruct* xmcProfilesCopy = (struct jsonListInboundStreamSettingsTcpFinalMaskXmcProfileObjectStruct*)malloc((xmcProfilesCount ? xmcProfilesCount : 1) * sizeof(struct jsonListInboundStreamSettingsTcpFinalMaskXmcProfileObjectStruct));
                                                        if (!xmcProfilesCopy) {
                                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xmcProfilesCopy is a null pointer, failed to allocate space");

                                                            jsonListInboundStreamSettingsTcpFinalMaskObjectStructDelete(tcpFinalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsTcpFinalMaskObjStruct = NULL;
                                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                                            inboundObj->listInSniffingObjStruct = NULL;
                                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                            listInStruct->listInObjStruct = NULL;
                                                            jsonListInboundStructDelete(listInStruct);

                                                            cJSON_Delete(jsonParser);

                                                            return NULL;

                                                        }

                                                        for (size_t profileIdx = 0; profileIdx < xmcProfilesCount; profileIdx++) {
                                                            xmcProfilesCopy[profileIdx].username = NULL;
                                                            xmcProfilesCopy[profileIdx].uuid = NULL;
                                                            xmcProfilesCopy[profileIdx].texturesValue = NULL;
                                                            xmcProfilesCopy[profileIdx].texturesSignature = NULL;

                                                        }

                                                        for (size_t profileIdx = 0; profileIdx < xmcProfilesCount; profileIdx++) {
                                                            cJSON* xmcProfileItem = cJSON_GetArrayItem(xmcProfilesObj, profileIdx);
                                                            struct jsonListInboundStreamSettingsTcpFinalMaskXmcProfileObjectStruct* xmcProfile = &xmcProfilesCopy[profileIdx];

                                                            if (
                                                                cJSON_HasObjectItem(xmcProfileItem, "username") &&
                                                                cJSON_IsString(cJSON_GetObjectItem(xmcProfileItem, "username"))
                                                               ) {
                                                                char* xmcProfileUsername = cJSON_GetObjectItem(xmcProfileItem, "username")->valuestring;
                                                                size_t xmcProfileUsernameLen = strlen(xmcProfileUsername);
                                                                char* xmcProfileUsernameCopy = (char*)malloc((xmcProfileUsernameLen + 1) * sizeof(char));
                                                                strncpy(xmcProfileUsernameCopy, xmcProfileUsername, xmcProfileUsernameLen);
                                                                xmcProfileUsernameCopy[xmcProfileUsernameLen] = '\0';
                                                                xmcProfile->username = xmcProfileUsernameCopy;

                                                            }

                                                            if (
                                                                cJSON_HasObjectItem(xmcProfileItem, "uuid") &&
                                                                cJSON_IsString(cJSON_GetObjectItem(xmcProfileItem, "uuid"))
                                                               ) {
                                                                char* xmcProfileUuid = cJSON_GetObjectItem(xmcProfileItem, "uuid")->valuestring;
                                                                size_t xmcProfileUuidLen = strlen(xmcProfileUuid);
                                                                char* xmcProfileUuidCopy = (char*)malloc((xmcProfileUuidLen + 1) * sizeof(char));
                                                                strncpy(xmcProfileUuidCopy, xmcProfileUuid, xmcProfileUuidLen);
                                                                xmcProfileUuidCopy[xmcProfileUuidLen] = '\0';
                                                                xmcProfile->uuid = xmcProfileUuidCopy;

                                                            }

                                                            if (
                                                                cJSON_HasObjectItem(xmcProfileItem, "texturesValue") &&
                                                                cJSON_IsString(cJSON_GetObjectItem(xmcProfileItem, "texturesValue"))
                                                               ) {
                                                                char* xmcProfileTexturesValue = cJSON_GetObjectItem(xmcProfileItem, "texturesValue")->valuestring;
                                                                size_t xmcProfileTexturesValueLen = strlen(xmcProfileTexturesValue);
                                                                char* xmcProfileTexturesValueCopy = (char*)malloc((xmcProfileTexturesValueLen + 1) * sizeof(char));
                                                                strncpy(xmcProfileTexturesValueCopy, xmcProfileTexturesValue, xmcProfileTexturesValueLen);
                                                                xmcProfileTexturesValueCopy[xmcProfileTexturesValueLen] = '\0';
                                                                xmcProfile->texturesValue = xmcProfileTexturesValueCopy;

                                                            }

                                                            if (
                                                                cJSON_HasObjectItem(xmcProfileItem, "texturesSignature") &&
                                                                cJSON_IsString(cJSON_GetObjectItem(xmcProfileItem, "texturesSignature"))
                                                               ) {
                                                                char* xmcProfileTexturesSignature = cJSON_GetObjectItem(xmcProfileItem, "texturesSignature")->valuestring;
                                                                size_t xmcProfileTexturesSignatureLen = strlen(xmcProfileTexturesSignature);
                                                                char* xmcProfileTexturesSignatureCopy = (char*)malloc((xmcProfileTexturesSignatureLen + 1) * sizeof(char));
                                                                strncpy(xmcProfileTexturesSignatureCopy, xmcProfileTexturesSignature, xmcProfileTexturesSignatureLen);
                                                                xmcProfileTexturesSignatureCopy[xmcProfileTexturesSignatureLen] = '\0';
                                                                xmcProfile->texturesSignature = xmcProfileTexturesSignatureCopy;

                                                            }

                                                        }

                                                        xmcStruct->listInStreamSettingsTcpFinalMaskXmcProfileStruct = xmcProfilesCopy;
                                                        xmcStruct->jsonListInboundStreamSettingsTcpFinalMaskXmcProfileStructSize = (int64_t)xmcProfilesCount;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(tcpMaskSettingsObj, "password") &&
                                                        cJSON_IsString(cJSON_GetObjectItem(tcpMaskSettingsObj, "password"))
                                                       ) {
                                                        char* xmcPassword = cJSON_GetObjectItem(tcpMaskSettingsObj, "password")->valuestring;
                                                        size_t xmcPasswordLen = strlen(xmcPassword);
                                                        char* xmcPasswordCopy = (char*)malloc((xmcPasswordLen + 1) * sizeof(char));
                                                        strncpy(xmcPasswordCopy, xmcPassword, xmcPasswordLen);
                                                        xmcPasswordCopy[xmcPasswordLen] = '\0';
                                                        xmcStruct->password = xmcPasswordCopy;

                                                    }

                                                    break;

                                                default:
                                                    break;

                                            }

                                        }

                                    }

                                }

                            }

                        }

                        break;

                    case NETWORKTYPE_KCP:
                        if (
                            cJSON_HasObjectItem(streamSettingsObj, "kcpSettings") &&
                            cJSON_IsObject(cJSON_GetObjectItem(streamSettingsObj, "kcpSettings"))
                           ) {
                            cJSON* kcpSettingsObj = cJSON_GetObjectItem(streamSettingsObj, "kcpSettings");
                            if (!kcpSettingsObj) {
                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "kcpSettingsObj is a null pointer");

                                jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                inboundObj->listInStreamSettingsObjStruct = NULL;
                                inboundObj->listInSniffingObjStruct = NULL;
                                jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                listInStruct->listInObjStruct = NULL;
                                jsonListInboundStructDelete(listInStruct);

                                cJSON_Delete(jsonParser);

                                return NULL;

                            }

                            streamSettingsStruct->listInStreamSettingsMKcpSettingsObjStruct = (struct jsonListInboundStreamSettingsMKcpSettingsObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsMKcpSettingsObjectStruct));
                            if (!streamSettingsStruct->listInStreamSettingsMKcpSettingsObjStruct) {
                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsMKcpSettingsObjStruct is a null pointer, failed to allocate space");

                                streamSettingsStruct->listInStreamSettingsMKcpSettingsObjStruct = NULL;
                                jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                inboundObj->listInStreamSettingsObjStruct = NULL;
                                inboundObj->listInSniffingObjStruct = NULL;
                                jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                listInStruct->listInObjStruct = NULL;
                                jsonListInboundStructDelete(listInStruct);

                                cJSON_Delete(jsonParser);

                                return NULL;

                            }

                            struct jsonListInboundStreamSettingsMKcpSettingsObjectStruct* kcpSettingsStruct = streamSettingsStruct->listInStreamSettingsMKcpSettingsObjStruct;

                            if (
                                cJSON_HasObjectItem(kcpSettingsObj, "mtu") &&
                                cJSON_HasObjectItem(kcpSettingsObj, "tti") &&
                                cJSON_HasObjectItem(kcpSettingsObj, "uplinkCapacity") &&
                                cJSON_HasObjectItem(kcpSettingsObj, "downlinkCapacity") &&
                                cJSON_HasObjectItem(kcpSettingsObj, "cwndMultiplier") &&
                                cJSON_HasObjectItem(kcpSettingsObj, "maxSendingWindow")
                               ) {
                                kcpSettingsStruct->mtu = (int64_t)cJSON_GetObjectItem(kcpSettingsObj, "mtu")->valuedouble;
                                kcpSettingsStruct->tti = (int64_t)cJSON_GetObjectItem(kcpSettingsObj, "tti")->valuedouble;
                                kcpSettingsStruct->uplinkCapacity = (int64_t)cJSON_GetObjectItem(kcpSettingsObj, "uplinkCapacity")->valuedouble;
                                kcpSettingsStruct->downlinkCapacity = (int64_t)cJSON_GetObjectItem(kcpSettingsObj, "downlinkCapacity")->valuedouble;
                                kcpSettingsStruct->cwndMultiplier = (int64_t)cJSON_GetObjectItem(kcpSettingsObj, "cwndMultiplier")->valuedouble;
                                kcpSettingsStruct->maxSendingWindow = (int64_t)cJSON_GetObjectItem(kcpSettingsObj, "maxSendingWindow")->valuedouble;

                            } else {
                                applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Some item is not present in the kcpSettings object, leaving the kcp settings fields unset");

                                kcpSettingsStruct->mtu = 0;
                                kcpSettingsStruct->tti = 0;
                                kcpSettingsStruct->uplinkCapacity = 0;
                                kcpSettingsStruct->downlinkCapacity = 0;
                                kcpSettingsStruct->cwndMultiplier = 0;
                                kcpSettingsStruct->maxSendingWindow = 0;

                            }

                        }

                        // The security field is a plain string and currently "none" for every kcp variant.
                        // TODO: when the security field shows a different value, it may carry extra
                        // settings ( e.g. a tls configuration ), take care of them at the settings field
                        if (
                            cJSON_HasObjectItem(streamSettingsObj, "security") &&
                            cJSON_IsString(cJSON_GetObjectItem(streamSettingsObj, "security"))
                           ) {
                            char* security = cJSON_GetObjectItem(streamSettingsObj, "security")->valuestring;
                            size_t securityLen = strlen(security);
                            char* securityCopy = (char*)malloc((securityLen + 1) * sizeof(char));
                            strncpy(securityCopy, security, securityLen);
                            securityCopy[securityLen] = '\0';
                            streamSettingsStruct->security = securityCopy;

                        }

                        // The udp mask ( finalmask ) is an optional field, it holds a "udp" array
                        // whose elements carry a "type" ( mkcp-legacy, xdns, xicmp, realm,
                        // header-custom, noise ) and a "settings" object shaped by that type
                        if (
                            cJSON_HasObjectItem(streamSettingsObj, "finalmask") &&
                            cJSON_IsObject(cJSON_GetObjectItem(streamSettingsObj, "finalmask"))
                           ) {
                            cJSON* finalMaskObj = cJSON_GetObjectItem(streamSettingsObj, "finalmask");
                            if (!finalMaskObj) {
                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "finalMaskObj is a null pointer");

                                jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                inboundObj->listInStreamSettingsObjStruct = NULL;
                                inboundObj->listInSniffingObjStruct = NULL;
                                jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                listInStruct->listInObjStruct = NULL;
                                jsonListInboundStructDelete(listInStruct);

                                cJSON_Delete(jsonParser);

                                return NULL;

                            }

                            streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = (struct jsonListInboundStreamSettingsMKcpFinalMaskObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsMKcpFinalMaskObjectStruct));
                            if (!streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct) {
                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsMKcpFinalMaskObjStruct is a null pointer, failed to allocate space");

                                streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                                jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                inboundObj->listInStreamSettingsObjStruct = NULL;
                                inboundObj->listInSniffingObjStruct = NULL;
                                jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                listInStruct->listInObjStruct = NULL;
                                jsonListInboundStructDelete(listInStruct);

                                cJSON_Delete(jsonParser);

                                return NULL;

                            }

                            struct jsonListInboundStreamSettingsMKcpFinalMaskObjectStruct* finalMaskStruct = streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct;
                            finalMaskStruct->listInStreamSettingsFinalMaskUdpStruct = NULL;
                            finalMaskStruct->jsonListInboundStreamSettingsFinalMaskUdpStructSize = 0;

                            const char* udpMaskTypes[] = {
                                "mkcp-legacy", // mKCP Legacy
                                "xdns", // xDNS
                                "xicmp", // xICMP
                                "realm", // Realm
                                "header-custom", // Header Custom
                                "noise" // Noise

                            };

                            enum udpMaskTypesEnum {
                                UDPMASKTYPE_MKCPLEGACY,
                                UDPMASKTYPE_XDNS,
                                UDPMASKTYPE_XICMP,
                                UDPMASKTYPE_REALM,
                                UDPMASKTYPE_HEADERCUSTOM,
                                UDPMASKTYPE_NOISE,
                                UDPMASKTYPE_COUNT

                            };

                            if (
                                cJSON_HasObjectItem(finalMaskObj, "udp") &&
                                cJSON_IsArray(cJSON_GetObjectItem(finalMaskObj, "udp"))
                               ) {
                                cJSON* udpObj = cJSON_GetObjectItem(finalMaskObj, "udp");
                                if (!udpObj) {
                                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "udpObj is a null pointer");

                                    jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(finalMaskStruct);

                                    streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                                    jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                    inboundObj->listInStreamSettingsObjStruct = NULL;
                                    inboundObj->listInSniffingObjStruct = NULL;
                                    jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                    listInStruct->listInObjStruct = NULL;
                                    jsonListInboundStructDelete(listInStruct);

                                    cJSON_Delete(jsonParser);

                                    return NULL;

                                }

                                size_t udpCount = cJSON_GetArraySize(udpObj);
                                struct jsonListInboundStreamSettingsFinalMaskUdpObjectStruct* udpCopy = (struct jsonListInboundStreamSettingsFinalMaskUdpObjectStruct*)malloc((udpCount ? udpCount : 1) * sizeof(struct jsonListInboundStreamSettingsFinalMaskUdpObjectStruct));
                                if (!udpCopy) {
                                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "udpCopy is a null pointer, failed to allocate space");

                                    jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(finalMaskStruct);

                                    streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                                    jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                    inboundObj->listInStreamSettingsObjStruct = NULL;
                                    inboundObj->listInSniffingObjStruct = NULL;
                                    jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                    listInStruct->listInObjStruct = NULL;
                                    jsonListInboundStructDelete(listInStruct);

                                    cJSON_Delete(jsonParser);

                                    return NULL;

                                }

                                finalMaskStruct->listInStreamSettingsFinalMaskUdpStruct = udpCopy;
                                finalMaskStruct->jsonListInboundStreamSettingsFinalMaskUdpStructSize = udpCount;

                                for (size_t u = 0; u < udpCount; u++) {
                                    udpCopy[u].type = NULL;
                                    udpCopy[u].listInStreamSettingsFinalMaskUdpMkcpLegacyObjStruct = NULL;
                                    udpCopy[u].listInStreamSettingsFinalMaskUdpXdnsObjStruct = NULL;
                                    udpCopy[u].listInStreamSettingsFinalMaskUdpXicmpObjStruct = NULL;
                                    udpCopy[u].listInStreamSettingsFinalMaskUdpRealmObjStruct = NULL;
                                    udpCopy[u].listInStreamSettingsFinalMaskUdpHeaderCustomObjStruct = NULL;
                                    udpCopy[u].listInStreamSettingsFinalMaskUdpNoiseObjStruct = NULL;

                                }

                                for (size_t u = 0; u < udpCount; u++) {
                                    cJSON* udpItem = cJSON_GetArrayItem(udpObj, u);
                                    struct jsonListInboundStreamSettingsFinalMaskUdpObjectStruct* udpStruct = &udpCopy[u];

                                    if (
                                        cJSON_HasObjectItem(udpItem, "type") &&
                                        cJSON_IsString(cJSON_GetObjectItem(udpItem, "type"))
                                       ) {
                                        char* udpType = cJSON_GetObjectItem(udpItem, "type")->valuestring;
                                        size_t udpTypeLen = strlen(udpType);
                                        char* udpTypeCopy = (char*)malloc((udpTypeLen + 1) * sizeof(char));
                                        strncpy(udpTypeCopy, udpType, udpTypeLen);
                                        udpTypeCopy[udpTypeLen] = '\0';
                                        udpStruct->type = udpTypeCopy;

                                        enum udpMaskTypesEnum uType = UDPMASKTYPE_COUNT;
                                        for (int u2 = 0; u2 < UDPMASKTYPE_COUNT; u2++) {
                                            if (strncmp(udpMaskTypes[u2], udpStruct->type, strlen(udpMaskTypes[u2])) == 0) {
                                                uType = (enum udpMaskTypesEnum)u2;
                                                break;

                                            }

                                        }
                                        if (uType == UDPMASKTYPE_COUNT) {
                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Unable to detect udp mask type");

                                            jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(finalMaskStruct);

                                            streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                            inboundObj->listInSniffingObjStruct = NULL;
                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                            listInStruct->listInObjStruct = NULL;
                                            jsonListInboundStructDelete(listInStruct);

                                            cJSON_Delete(jsonParser);

                                            return NULL;

                                        }

                                        if (
                                            cJSON_HasObjectItem(udpItem, "settings") &&
                                            cJSON_IsObject(cJSON_GetObjectItem(udpItem, "settings"))
                                           ) {
                                            cJSON* udpSettingsObj = cJSON_GetObjectItem(udpItem, "settings");
                                            if (!udpSettingsObj) {
                                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "udpSettingsObj is a null pointer");

                                                jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(finalMaskStruct);

                                                streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                                                jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                inboundObj->listInStreamSettingsObjStruct = NULL;
                                                inboundObj->listInSniffingObjStruct = NULL;
                                                jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                listInStruct->listInObjStruct = NULL;
                                                jsonListInboundStructDelete(listInStruct);

                                                cJSON_Delete(jsonParser);

                                                return NULL;

                                            }

                                            switch (uType) {
                                                case UDPMASKTYPE_MKCPLEGACY:
                                                    udpStruct->listInStreamSettingsFinalMaskUdpMkcpLegacyObjStruct = (struct jsonListInboundStreamSettingsFinalMaskUdpMkcpLegacyObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsFinalMaskUdpMkcpLegacyObjectStruct));
                                                    if (!udpStruct->listInStreamSettingsFinalMaskUdpMkcpLegacyObjStruct) {
                                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsFinalMaskUdpMkcpLegacyObjStruct is a null pointer, failed to allocate space");

                                                        jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(finalMaskStruct);

                                                        streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                                        inboundObj->listInSniffingObjStruct = NULL;
                                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                        listInStruct->listInObjStruct = NULL;
                                                        jsonListInboundStructDelete(listInStruct);

                                                        cJSON_Delete(jsonParser);

                                                        return NULL;

                                                    }

                                                    struct jsonListInboundStreamSettingsFinalMaskUdpMkcpLegacyObjectStruct* mkcpLegacyStruct = udpStruct->listInStreamSettingsFinalMaskUdpMkcpLegacyObjStruct;
                                                    mkcpLegacyStruct->header = NULL;
                                                    mkcpLegacyStruct->value = NULL;

                                                    if (
                                                        cJSON_HasObjectItem(udpSettingsObj, "header") &&
                                                        cJSON_IsString(cJSON_GetObjectItem(udpSettingsObj, "header"))
                                                       ) {
                                                        char* mkcpHeader = cJSON_GetObjectItem(udpSettingsObj, "header")->valuestring;
                                                        size_t mkcpHeaderLen = strlen(mkcpHeader);
                                                        char* mkcpHeaderCopy = (char*)malloc((mkcpHeaderLen + 1) * sizeof(char));
                                                        strncpy(mkcpHeaderCopy, mkcpHeader, mkcpHeaderLen);
                                                        mkcpHeaderCopy[mkcpHeaderLen] = '\0';
                                                        mkcpLegacyStruct->header = mkcpHeaderCopy;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(udpSettingsObj, "value") &&
                                                        cJSON_IsString(cJSON_GetObjectItem(udpSettingsObj, "value"))
                                                       ) {
                                                        char* mkcpValue = cJSON_GetObjectItem(udpSettingsObj, "value")->valuestring;
                                                        size_t mkcpValueLen = strlen(mkcpValue);
                                                        char* mkcpValueCopy = (char*)malloc((mkcpValueLen + 1) * sizeof(char));
                                                        strncpy(mkcpValueCopy, mkcpValue, mkcpValueLen);
                                                        mkcpValueCopy[mkcpValueLen] = '\0';
                                                        mkcpLegacyStruct->value = mkcpValueCopy;

                                                    }

                                                    break;

                                                case UDPMASKTYPE_XDNS:
                                                    udpStruct->listInStreamSettingsFinalMaskUdpXdnsObjStruct = (struct jsonListInboundStreamSettingsFinalMaskUdpXdnsObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsFinalMaskUdpXdnsObjectStruct));
                                                    if (!udpStruct->listInStreamSettingsFinalMaskUdpXdnsObjStruct) {
                                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsFinalMaskUdpXdnsObjStruct is a null pointer, failed to allocate space");

                                                        jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(finalMaskStruct);

                                                        streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                                        inboundObj->listInSniffingObjStruct = NULL;
                                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                        listInStruct->listInObjStruct = NULL;
                                                        jsonListInboundStructDelete(listInStruct);

                                                        cJSON_Delete(jsonParser);

                                                        return NULL;

                                                    }

                                                    struct jsonListInboundStreamSettingsFinalMaskUdpXdnsObjectStruct* xdnsStruct = udpStruct->listInStreamSettingsFinalMaskUdpXdnsObjStruct;
                                                    xdnsStruct->domains = NULL;
                                                    xdnsStruct->domainsCount = 0;

                                                    if (
                                                        cJSON_HasObjectItem(udpSettingsObj, "domains") &&
                                                        cJSON_IsArray(cJSON_GetObjectItem(udpSettingsObj, "domains"))
                                                       ) {
                                                        cJSON* domainsObj = cJSON_GetObjectItem(udpSettingsObj, "domains");
                                                        size_t domainsCount = cJSON_GetArraySize(domainsObj);
                                                        const char** domainsCopy = (const char**)malloc((domainsCount ? domainsCount : 1) * sizeof(char*));
                                                        if (!domainsCopy) {
                                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "domainsCopy is a null pointer, failed to allocate space");

                                                            jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(finalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                                            inboundObj->listInSniffingObjStruct = NULL;
                                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                            listInStruct->listInObjStruct = NULL;
                                                            jsonListInboundStructDelete(listInStruct);

                                                            cJSON_Delete(jsonParser);

                                                            return NULL;

                                                        }

                                                        for (size_t d = 0; d < domainsCount; d++) {
                                                            domainsCopy[d] = NULL;

                                                        }

                                                        for (size_t d = 0; d < domainsCount; d++) {
                                                            cJSON* domainsItem = cJSON_GetArrayItem(domainsObj, d);
                                                            if (cJSON_IsString(domainsItem)) {
                                                                char* domain = domainsItem->valuestring;
                                                                size_t domainLen = strlen(domain);
                                                                char* domainCopy = (char*)malloc((domainLen + 1) * sizeof(char));
                                                                strncpy(domainCopy, domain, domainLen);
                                                                domainCopy[domainLen] = '\0';
                                                                domainsCopy[d] = domainCopy;

                                                            }

                                                        }

                                                        xdnsStruct->domains = domainsCopy;
                                                        xdnsStruct->domainsCount = domainsCount;

                                                    }

                                                    break;

                                                case UDPMASKTYPE_XICMP:
                                                    udpStruct->listInStreamSettingsFinalMaskUdpXicmpObjStruct = (struct jsonListInboundStreamSettingsFinalMaskUdpXicmpObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsFinalMaskUdpXicmpObjectStruct));
                                                    if (!udpStruct->listInStreamSettingsFinalMaskUdpXicmpObjStruct) {
                                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsFinalMaskUdpXicmpObjStruct is a null pointer, failed to allocate space");

                                                        jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(finalMaskStruct);

                                                        streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                                        inboundObj->listInSniffingObjStruct = NULL;
                                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                        listInStruct->listInObjStruct = NULL;
                                                        jsonListInboundStructDelete(listInStruct);

                                                        cJSON_Delete(jsonParser);

                                                        return NULL;

                                                    }

                                                    struct jsonListInboundStreamSettingsFinalMaskUdpXicmpObjectStruct* xicmpStruct = udpStruct->listInStreamSettingsFinalMaskUdpXicmpObjStruct;
                                                    xicmpStruct->ips = NULL;
                                                    xicmpStruct->ipsCount = 0;

                                                    if (
                                                        cJSON_HasObjectItem(udpSettingsObj, "dgram") &&
                                                        (
                                                            cJSON_IsBool(cJSON_GetObjectItem(udpSettingsObj, "dgram")) ||
                                                            cJSON_IsNumber(cJSON_GetObjectItem(udpSettingsObj, "dgram"))
                                                        )
                                                       ) {
                                                        cJSON* dgramObj = cJSON_GetObjectItem(udpSettingsObj, "dgram");
                                                        xicmpStruct->dgram = cJSON_IsBool(dgramObj) ? (unsigned char)cJSON_IsTrue(dgramObj) : (unsigned char)dgramObj->valuedouble;

                                                    } else {
                                                        xicmpStruct->dgram = 0;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(udpSettingsObj, "ips") &&
                                                        cJSON_IsArray(cJSON_GetObjectItem(udpSettingsObj, "ips"))
                                                       ) {
                                                        cJSON* ipsObj = cJSON_GetObjectItem(udpSettingsObj, "ips");
                                                        size_t ipsCount = cJSON_GetArraySize(ipsObj);
                                                        const char** ipsCopy = (const char**)malloc((ipsCount ? ipsCount : 1) * sizeof(char*));
                                                        if (!ipsCopy) {
                                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "ipsCopy is a null pointer, failed to allocate space");

                                                            jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(finalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                                            inboundObj->listInSniffingObjStruct = NULL;
                                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                            listInStruct->listInObjStruct = NULL;
                                                            jsonListInboundStructDelete(listInStruct);

                                                            cJSON_Delete(jsonParser);

                                                            return NULL;

                                                        }

                                                        for (size_t ip = 0; ip < ipsCount; ip++) {
                                                            ipsCopy[ip] = NULL;

                                                        }

                                                        for (size_t ip = 0; ip < ipsCount; ip++) {
                                                            cJSON* ipsItem = cJSON_GetArrayItem(ipsObj, ip);
                                                            if (cJSON_IsString(ipsItem)) {
                                                                char* ipAddr = ipsItem->valuestring;
                                                                size_t ipAddrLen = strlen(ipAddr);
                                                                char* ipAddrCopy = (char*)malloc((ipAddrLen + 1) * sizeof(char));
                                                                strncpy(ipAddrCopy, ipAddr, ipAddrLen);
                                                                ipAddrCopy[ipAddrLen] = '\0';
                                                                ipsCopy[ip] = ipAddrCopy;

                                                            }

                                                        }

                                                        xicmpStruct->ips = ipsCopy;
                                                        xicmpStruct->ipsCount = ipsCount;

                                                    }

                                                    break;

                                                case UDPMASKTYPE_REALM:
                                                    udpStruct->listInStreamSettingsFinalMaskUdpRealmObjStruct = (struct jsonListInboundStreamSettingsFinalMaskUdpRealmObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsFinalMaskUdpRealmObjectStruct));
                                                    if (!udpStruct->listInStreamSettingsFinalMaskUdpRealmObjStruct) {
                                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsFinalMaskUdpRealmObjStruct is a null pointer, failed to allocate space");

                                                        jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(finalMaskStruct);

                                                        streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                                        inboundObj->listInSniffingObjStruct = NULL;
                                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                        listInStruct->listInObjStruct = NULL;
                                                        jsonListInboundStructDelete(listInStruct);

                                                        cJSON_Delete(jsonParser);

                                                        return NULL;

                                                    }

                                                    struct jsonListInboundStreamSettingsFinalMaskUdpRealmObjectStruct* realmStruct = udpStruct->listInStreamSettingsFinalMaskUdpRealmObjStruct;
                                                    realmStruct->url = NULL;
                                                    realmStruct->stunServers = NULL;
                                                    realmStruct->stunServersCount = 0;
                                                    realmStruct->listInStreamSettingsFinalMaskUdpRealmTlsConfigObjStruct = NULL;

                                                    // the url is always of the form realm://token@host:port/id
                                                    if (
                                                        cJSON_HasObjectItem(udpSettingsObj, "url") &&
                                                        cJSON_IsString(cJSON_GetObjectItem(udpSettingsObj, "url"))
                                                       ) {
                                                        char* realmUrl = cJSON_GetObjectItem(udpSettingsObj, "url")->valuestring;
                                                        size_t realmUrlLen = strlen(realmUrl);
                                                        char* realmUrlCopy = (char*)malloc((realmUrlLen + 1) * sizeof(char));
                                                        strncpy(realmUrlCopy, realmUrl, realmUrlLen);
                                                        realmUrlCopy[realmUrlLen] = '\0';
                                                        realmStruct->url = realmUrlCopy;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(udpSettingsObj, "stunServers") &&
                                                        cJSON_IsArray(cJSON_GetObjectItem(udpSettingsObj, "stunServers"))
                                                       ) {
                                                        cJSON* stunServersObj = cJSON_GetObjectItem(udpSettingsObj, "stunServers");
                                                        size_t stunServersCount = cJSON_GetArraySize(stunServersObj);
                                                        const char** stunServersCopy = (const char**)malloc((stunServersCount ? stunServersCount : 1) * sizeof(char*));
                                                        if (!stunServersCopy) {
                                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "stunServersCopy is a null pointer, failed to allocate space");

                                                            jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(finalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                                            inboundObj->listInSniffingObjStruct = NULL;
                                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                            listInStruct->listInObjStruct = NULL;
                                                            jsonListInboundStructDelete(listInStruct);

                                                            cJSON_Delete(jsonParser);

                                                            return NULL;

                                                        }

                                                        for (size_t s = 0; s < stunServersCount; s++) {
                                                            stunServersCopy[s] = NULL;

                                                        }

                                                        for (size_t s = 0; s < stunServersCount; s++) {
                                                            cJSON* stunServerItem = cJSON_GetArrayItem(stunServersObj, s);
                                                            if (cJSON_IsString(stunServerItem)) {
                                                                char* stunServer = stunServerItem->valuestring;
                                                                size_t stunServerLen = strlen(stunServer);
                                                                char* stunServerCopy = (char*)malloc((stunServerLen + 1) * sizeof(char));
                                                                strncpy(stunServerCopy, stunServer, stunServerLen);
                                                                stunServerCopy[stunServerLen] = '\0';
                                                                stunServersCopy[s] = stunServerCopy;

                                                            }

                                                        }

                                                        realmStruct->stunServers = stunServersCopy;
                                                        realmStruct->stunServersCount = stunServersCount;

                                                    }

                                                    // the realm tls field is optional
                                                    if (
                                                        cJSON_HasObjectItem(udpSettingsObj, "tlsConfig") &&
                                                        cJSON_IsObject(cJSON_GetObjectItem(udpSettingsObj, "tlsConfig"))
                                                       ) {
                                                        cJSON* tlsConfigObj = cJSON_GetObjectItem(udpSettingsObj, "tlsConfig");
                                                        if (!tlsConfigObj) {
                                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "tlsConfigObj is a null pointer");

                                                            jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(finalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                                            inboundObj->listInSniffingObjStruct = NULL;
                                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                            listInStruct->listInObjStruct = NULL;
                                                            jsonListInboundStructDelete(listInStruct);

                                                            cJSON_Delete(jsonParser);

                                                            return NULL;

                                                        }

                                                        realmStruct->listInStreamSettingsFinalMaskUdpRealmTlsConfigObjStruct = (struct jsonListInboundStreamSettingsFinalMaskUdpRealmTlsConfigObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsFinalMaskUdpRealmTlsConfigObjectStruct));
                                                        if (!realmStruct->listInStreamSettingsFinalMaskUdpRealmTlsConfigObjStruct) {
                                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsFinalMaskUdpRealmTlsConfigObjStruct is a null pointer, failed to allocate space");

                                                            jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(finalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                                            inboundObj->listInSniffingObjStruct = NULL;
                                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                            listInStruct->listInObjStruct = NULL;
                                                            jsonListInboundStructDelete(listInStruct);

                                                            cJSON_Delete(jsonParser);

                                                            return NULL;

                                                        }

                                                        struct jsonListInboundStreamSettingsFinalMaskUdpRealmTlsConfigObjectStruct* realmTlsConfigStruct = realmStruct->listInStreamSettingsFinalMaskUdpRealmTlsConfigObjStruct;
                                                        realmTlsConfigStruct->serverName = NULL;
                                                        realmTlsConfigStruct->alpn = NULL;
                                                        realmTlsConfigStruct->alpnCount = 0;
                                                        realmTlsConfigStruct->fingerprint = NULL;
                                                        realmTlsConfigStruct->allowInsecure = 0;

                                                        if (
                                                            cJSON_HasObjectItem(tlsConfigObj, "serverName") &&
                                                            cJSON_IsString(cJSON_GetObjectItem(tlsConfigObj, "serverName"))
                                                           ) {
                                                            char* serverName = cJSON_GetObjectItem(tlsConfigObj, "serverName")->valuestring;
                                                            size_t serverNameLen = strlen(serverName);
                                                            char* serverNameCopy = (char*)malloc((serverNameLen + 1) * sizeof(char));
                                                            strncpy(serverNameCopy, serverName, serverNameLen);
                                                            serverNameCopy[serverNameLen] = '\0';
                                                            realmTlsConfigStruct->serverName = serverNameCopy;

                                                        }

                                                        // the alpn field has 3 options: h3, h2, http/1.1
                                                        if (
                                                            cJSON_HasObjectItem(tlsConfigObj, "alpn") &&
                                                            cJSON_IsArray(cJSON_GetObjectItem(tlsConfigObj, "alpn"))
                                                           ) {
                                                            cJSON* alpnObj = cJSON_GetObjectItem(tlsConfigObj, "alpn");
                                                            size_t alpnCount = cJSON_GetArraySize(alpnObj);
                                                            const char** alpnCopy = (const char**)malloc((alpnCount ? alpnCount : 1) * sizeof(char*));
                                                            if (!alpnCopy) {
                                                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "alpnCopy is a null pointer, failed to allocate space");

                                                                jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(finalMaskStruct);

                                                                streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                                                                jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                                inboundObj->listInStreamSettingsObjStruct = NULL;
                                                                inboundObj->listInSniffingObjStruct = NULL;
                                                                jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                                jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                                listInStruct->listInObjStruct = NULL;
                                                                jsonListInboundStructDelete(listInStruct);

                                                                cJSON_Delete(jsonParser);

                                                                return NULL;

                                                            }

                                                            for (size_t a = 0; a < alpnCount; a++) {
                                                                alpnCopy[a] = NULL;

                                                            }

                                                            for (size_t a = 0; a < alpnCount; a++) {
                                                                cJSON* alpnItem = cJSON_GetArrayItem(alpnObj, a);
                                                                if (cJSON_IsString(alpnItem)) {
                                                                    char* alpnValue = alpnItem->valuestring;
                                                                    size_t alpnValueLen = strlen(alpnValue);
                                                                    char* alpnValueCopy = (char*)malloc((alpnValueLen + 1) * sizeof(char));
                                                                    strncpy(alpnValueCopy, alpnValue, alpnValueLen);
                                                                    alpnValueCopy[alpnValueLen] = '\0';
                                                                    alpnCopy[a] = alpnValueCopy;

                                                                }

                                                            }

                                                            realmTlsConfigStruct->alpn = alpnCopy;
                                                            realmTlsConfigStruct->alpnCount = alpnCount;

                                                        }

                                                        // the fingerprint options are: chrome, firefox, safari, ios,
                                                        // android, edge, 360, qq, random, randomizednoalpn, unsafe
                                                        if (
                                                            cJSON_HasObjectItem(tlsConfigObj, "fingerprint") &&
                                                            cJSON_IsString(cJSON_GetObjectItem(tlsConfigObj, "fingerprint"))
                                                           ) {
                                                            char* fingerprint = cJSON_GetObjectItem(tlsConfigObj, "fingerprint")->valuestring;
                                                            size_t fingerprintLen = strlen(fingerprint);
                                                            char* fingerprintCopy = (char*)malloc((fingerprintLen + 1) * sizeof(char));
                                                            strncpy(fingerprintCopy, fingerprint, fingerprintLen);
                                                            fingerprintCopy[fingerprintLen] = '\0';
                                                            realmTlsConfigStruct->fingerprint = fingerprintCopy;

                                                        }

                                                        if (
                                                            cJSON_HasObjectItem(tlsConfigObj, "allowInsecure") &&
                                                            cJSON_IsBool(cJSON_GetObjectItem(tlsConfigObj, "allowInsecure"))
                                                           ) {
                                                            realmTlsConfigStruct->allowInsecure = (unsigned char)cJSON_IsTrue(cJSON_GetObjectItem(tlsConfigObj, "allowInsecure"));

                                                        }

                                                    }

                                                    break;

                                                case UDPMASKTYPE_HEADERCUSTOM:
                                                    udpStruct->listInStreamSettingsFinalMaskUdpHeaderCustomObjStruct = (struct jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomObjectStruct));
                                                    if (!udpStruct->listInStreamSettingsFinalMaskUdpHeaderCustomObjStruct) {
                                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsFinalMaskUdpHeaderCustomObjStruct is a null pointer, failed to allocate space");

                                                        jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(finalMaskStruct);

                                                        streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                                        inboundObj->listInSniffingObjStruct = NULL;
                                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                        listInStruct->listInObjStruct = NULL;
                                                        jsonListInboundStructDelete(listInStruct);

                                                        cJSON_Delete(jsonParser);

                                                        return NULL;

                                                    }

                                                    struct jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomObjectStruct* headerCustomStruct = udpStruct->listInStreamSettingsFinalMaskUdpHeaderCustomObjStruct;
                                                    headerCustomStruct->listInStreamSettingsFinalMaskUdpHeaderCustomClientPacketStruct = NULL;
                                                    headerCustomStruct->jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomClientPacketStructSize = 0;
                                                    headerCustomStruct->listInStreamSettingsFinalMaskUdpHeaderCustomServerPacketStruct = NULL;
                                                    headerCustomStruct->jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomServerPacketStructSize = 0;

                                                    // the client and server fields have the same fields, the packet
                                                    // objects differ by their type field ( array / str / hex / base64 )
                                                    if (
                                                        cJSON_HasObjectItem(udpSettingsObj, "client") &&
                                                        cJSON_IsArray(cJSON_GetObjectItem(udpSettingsObj, "client"))
                                                       ) {
                                                        cJSON* clientArr = cJSON_GetObjectItem(udpSettingsObj, "client");
                                                        size_t clientCount = cJSON_GetArraySize(clientArr);
                                                        struct jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomPacketObjectStruct* headerCustomClientCopy = (struct jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomPacketObjectStruct*)malloc((clientCount ? clientCount : 1) * sizeof(struct jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomPacketObjectStruct));
                                                        if (!headerCustomClientCopy) {
                                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "headerCustomClientCopy is a null pointer, failed to allocate space");

                                                            jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(finalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                                            inboundObj->listInSniffingObjStruct = NULL;
                                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                            listInStruct->listInObjStruct = NULL;
                                                            jsonListInboundStructDelete(listInStruct);

                                                            cJSON_Delete(jsonParser);

                                                            return NULL;

                                                        }

                                                        for (size_t c = 0; c < clientCount; c++) {
                                                            headerCustomClientCopy[c].type = NULL;
                                                            headerCustomClientCopy[c].rand = 0;
                                                            headerCustomClientCopy[c].randRange = NULL;
                                                            headerCustomClientCopy[c].packet = NULL;

                                                        }

                                                        for (size_t c = 0; c < clientCount; c++) {
                                                            cJSON* clientPacketItem = cJSON_GetArrayItem(clientArr, c);
                                                            struct jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomPacketObjectStruct* clientPacket = &headerCustomClientCopy[c];

                                                            if (
                                                                cJSON_HasObjectItem(clientPacketItem, "type") &&
                                                                cJSON_IsString(cJSON_GetObjectItem(clientPacketItem, "type"))
                                                               ) {
                                                                char* clientPacketType = cJSON_GetObjectItem(clientPacketItem, "type")->valuestring;
                                                                size_t clientPacketTypeLen = strlen(clientPacketType);
                                                                char* clientPacketTypeCopy = (char*)malloc((clientPacketTypeLen + 1) * sizeof(char));
                                                                strncpy(clientPacketTypeCopy, clientPacketType, clientPacketTypeLen);
                                                                clientPacketTypeCopy[clientPacketTypeLen] = '\0';
                                                                clientPacket->type = clientPacketTypeCopy;

                                                            }

                                                            // rand / randRange are only present when type is "array"
                                                            if (
                                                                cJSON_HasObjectItem(clientPacketItem, "rand") &&
                                                                cJSON_IsNumber(cJSON_GetObjectItem(clientPacketItem, "rand"))
                                                               ) {
                                                                clientPacket->rand = (int64_t)cJSON_GetObjectItem(clientPacketItem, "rand")->valuedouble;

                                                            }

                                                            if (
                                                                cJSON_HasObjectItem(clientPacketItem, "randRange") &&
                                                                cJSON_IsString(cJSON_GetObjectItem(clientPacketItem, "randRange"))
                                                               ) {
                                                                char* clientRandRange = cJSON_GetObjectItem(clientPacketItem, "randRange")->valuestring;
                                                                size_t clientRandRangeLen = strlen(clientRandRange);
                                                                char* clientRandRangeCopy = (char*)malloc((clientRandRangeLen + 1) * sizeof(char));
                                                                strncpy(clientRandRangeCopy, clientRandRange, clientRandRangeLen);
                                                                clientRandRangeCopy[clientRandRangeLen] = '\0';
                                                                clientPacket->randRange = clientRandRangeCopy;

                                                            }

                                                            // packet is only present when type is "str" / "hex" / "base64"
                                                            if (
                                                                cJSON_HasObjectItem(clientPacketItem, "packet") &&
                                                                cJSON_IsString(cJSON_GetObjectItem(clientPacketItem, "packet"))
                                                               ) {
                                                                char* clientPacketVal = cJSON_GetObjectItem(clientPacketItem, "packet")->valuestring;
                                                                size_t clientPacketLen = strlen(clientPacketVal);
                                                                char* clientPacketCopy = (char*)malloc((clientPacketLen + 1) * sizeof(char));
                                                                strncpy(clientPacketCopy, clientPacketVal, clientPacketLen);
                                                                clientPacketCopy[clientPacketLen] = '\0';
                                                                clientPacket->packet = clientPacketCopy;

                                                            }

                                                        }

                                                        headerCustomStruct->listInStreamSettingsFinalMaskUdpHeaderCustomClientPacketStruct = headerCustomClientCopy;
                                                        headerCustomStruct->jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomClientPacketStructSize = clientCount;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(udpSettingsObj, "server") &&
                                                        cJSON_IsArray(cJSON_GetObjectItem(udpSettingsObj, "server"))
                                                       ) {
                                                        cJSON* serverArr = cJSON_GetObjectItem(udpSettingsObj, "server");
                                                        size_t serverCount = cJSON_GetArraySize(serverArr);
                                                        struct jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomPacketObjectStruct* headerCustomServerCopy = (struct jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomPacketObjectStruct*)malloc((serverCount ? serverCount : 1) * sizeof(struct jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomPacketObjectStruct));
                                                        if (!headerCustomServerCopy) {
                                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "headerCustomServerCopy is a null pointer, failed to allocate space");

                                                            jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(finalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                                            inboundObj->listInSniffingObjStruct = NULL;
                                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                            listInStruct->listInObjStruct = NULL;
                                                            jsonListInboundStructDelete(listInStruct);

                                                            cJSON_Delete(jsonParser);

                                                            return NULL;

                                                        }

                                                        for (size_t s2 = 0; s2 < serverCount; s2++) {
                                                            headerCustomServerCopy[s2].type = NULL;
                                                            headerCustomServerCopy[s2].rand = 0;
                                                            headerCustomServerCopy[s2].randRange = NULL;
                                                            headerCustomServerCopy[s2].packet = NULL;

                                                        }

                                                        for (size_t s2 = 0; s2 < serverCount; s2++) {
                                                            cJSON* serverPacketItem = cJSON_GetArrayItem(serverArr, s2);
                                                            struct jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomPacketObjectStruct* serverPacket = &headerCustomServerCopy[s2];

                                                            if (
                                                                cJSON_HasObjectItem(serverPacketItem, "type") &&
                                                                cJSON_IsString(cJSON_GetObjectItem(serverPacketItem, "type"))
                                                               ) {
                                                                char* serverPacketType = cJSON_GetObjectItem(serverPacketItem, "type")->valuestring;
                                                                size_t serverPacketTypeLen = strlen(serverPacketType);
                                                                char* serverPacketTypeCopy = (char*)malloc((serverPacketTypeLen + 1) * sizeof(char));
                                                                strncpy(serverPacketTypeCopy, serverPacketType, serverPacketTypeLen);
                                                                serverPacketTypeCopy[serverPacketTypeLen] = '\0';
                                                                serverPacket->type = serverPacketTypeCopy;

                                                            }

                                                            if (
                                                                cJSON_HasObjectItem(serverPacketItem, "rand") &&
                                                                cJSON_IsNumber(cJSON_GetObjectItem(serverPacketItem, "rand"))
                                                               ) {
                                                                serverPacket->rand = (int64_t)cJSON_GetObjectItem(serverPacketItem, "rand")->valuedouble;

                                                            }

                                                            if (
                                                                cJSON_HasObjectItem(serverPacketItem, "randRange") &&
                                                                cJSON_IsString(cJSON_GetObjectItem(serverPacketItem, "randRange"))
                                                               ) {
                                                                char* serverRandRange = cJSON_GetObjectItem(serverPacketItem, "randRange")->valuestring;
                                                                size_t serverRandRangeLen = strlen(serverRandRange);
                                                                char* serverRandRangeCopy = (char*)malloc((serverRandRangeLen + 1) * sizeof(char));
                                                                strncpy(serverRandRangeCopy, serverRandRange, serverRandRangeLen);
                                                                serverRandRangeCopy[serverRandRangeLen] = '\0';
                                                                serverPacket->randRange = serverRandRangeCopy;

                                                            }

                                                            if (
                                                                cJSON_HasObjectItem(serverPacketItem, "packet") &&
                                                                cJSON_IsString(cJSON_GetObjectItem(serverPacketItem, "packet"))
                                                               ) {
                                                                char* serverPacketVal = cJSON_GetObjectItem(serverPacketItem, "packet")->valuestring;
                                                                size_t serverPacketLen = strlen(serverPacketVal);
                                                                char* serverPacketCopy = (char*)malloc((serverPacketLen + 1) * sizeof(char));
                                                                strncpy(serverPacketCopy, serverPacketVal, serverPacketLen);
                                                                serverPacketCopy[serverPacketLen] = '\0';
                                                                serverPacket->packet = serverPacketCopy;

                                                            }

                                                        }

                                                        headerCustomStruct->listInStreamSettingsFinalMaskUdpHeaderCustomServerPacketStruct = headerCustomServerCopy;
                                                        headerCustomStruct->jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomServerPacketStructSize = serverCount;

                                                    }

                                                    break;

                                                case UDPMASKTYPE_NOISE:
                                                    udpStruct->listInStreamSettingsFinalMaskUdpNoiseObjStruct = (struct jsonListInboundStreamSettingsFinalMaskUdpNoiseObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsFinalMaskUdpNoiseObjectStruct));
                                                    if (!udpStruct->listInStreamSettingsFinalMaskUdpNoiseObjStruct) {
                                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsFinalMaskUdpNoiseObjStruct is a null pointer, failed to allocate space");

                                                        jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(finalMaskStruct);

                                                        streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                                        inboundObj->listInSniffingObjStruct = NULL;
                                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                        listInStruct->listInObjStruct = NULL;
                                                        jsonListInboundStructDelete(listInStruct);

                                                        cJSON_Delete(jsonParser);

                                                        return NULL;

                                                    }

                                                    struct jsonListInboundStreamSettingsFinalMaskUdpNoiseObjectStruct* noiseStruct = udpStruct->listInStreamSettingsFinalMaskUdpNoiseObjStruct;
                                                    noiseStruct->reset = 0;
                                                    noiseStruct->listInStreamSettingsFinalMaskUdpNoisePacketStruct = NULL;
                                                    noiseStruct->jsonListInboundStreamSettingsFinalMaskUdpNoisePacketStructSize = 0;

                                                    if (
                                                        cJSON_HasObjectItem(udpSettingsObj, "reset") &&
                                                        cJSON_IsNumber(cJSON_GetObjectItem(udpSettingsObj, "reset"))
                                                       ) {
                                                        noiseStruct->reset = (int64_t)cJSON_GetObjectItem(udpSettingsObj, "reset")->valuedouble;

                                                    }

                                                    // the noise packet types ( array, str, hex, base64 ) and all of
                                                    // their fields ( delay, rand, randRange, packet ) are optional
                                                    if (
                                                        cJSON_HasObjectItem(udpSettingsObj, "noise") &&
                                                        cJSON_IsArray(cJSON_GetObjectItem(udpSettingsObj, "noise"))
                                                       ) {
                                                        cJSON* noiseArr = cJSON_GetObjectItem(udpSettingsObj, "noise");
                                                        size_t noiseCount = cJSON_GetArraySize(noiseArr);
                                                        struct jsonListInboundStreamSettingsFinalMaskUdpNoisePacketObjectStruct* noiseCopy = (struct jsonListInboundStreamSettingsFinalMaskUdpNoisePacketObjectStruct*)malloc((noiseCount ? noiseCount : 1) * sizeof(struct jsonListInboundStreamSettingsFinalMaskUdpNoisePacketObjectStruct));
                                                        if (!noiseCopy) {
                                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "noiseCopy is a null pointer, failed to allocate space");

                                                            jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(finalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsMKcpFinalMaskObjStruct = NULL;
                                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                                            inboundObj->listInSniffingObjStruct = NULL;
                                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                            listInStruct->listInObjStruct = NULL;
                                                            jsonListInboundStructDelete(listInStruct);

                                                            cJSON_Delete(jsonParser);

                                                            return NULL;

                                                        }

                                                        for (size_t n = 0; n < noiseCount; n++) {
                                                            noiseCopy[n].type = NULL;
                                                            noiseCopy[n].delay = NULL;
                                                            noiseCopy[n].rand = NULL;
                                                            noiseCopy[n].randRange = NULL;
                                                            noiseCopy[n].packet = NULL;

                                                        }

                                                        for (size_t n = 0; n < noiseCount; n++) {
                                                            cJSON* noisePacketItem = cJSON_GetArrayItem(noiseArr, n);
                                                            struct jsonListInboundStreamSettingsFinalMaskUdpNoisePacketObjectStruct* noisePacket = &noiseCopy[n];

                                                            if (
                                                                cJSON_HasObjectItem(noisePacketItem, "type") &&
                                                                cJSON_IsString(cJSON_GetObjectItem(noisePacketItem, "type"))
                                                               ) {
                                                                char* noisePacketType = cJSON_GetObjectItem(noisePacketItem, "type")->valuestring;
                                                                size_t noisePacketTypeLen = strlen(noisePacketType);
                                                                char* noisePacketTypeCopy = (char*)malloc((noisePacketTypeLen + 1) * sizeof(char));
                                                                strncpy(noisePacketTypeCopy, noisePacketType, noisePacketTypeLen);
                                                                noisePacketTypeCopy[noisePacketTypeLen] = '\0';
                                                                noisePacket->type = noisePacketTypeCopy;

                                                            }

                                                            if (
                                                                cJSON_HasObjectItem(noisePacketItem, "delay") &&
                                                                cJSON_IsString(cJSON_GetObjectItem(noisePacketItem, "delay"))
                                                               ) {
                                                                char* noiseDelay = cJSON_GetObjectItem(noisePacketItem, "delay")->valuestring;
                                                                size_t noiseDelayLen = strlen(noiseDelay);
                                                                char* noiseDelayCopy = (char*)malloc((noiseDelayLen + 1) * sizeof(char));
                                                                strncpy(noiseDelayCopy, noiseDelay, noiseDelayLen);
                                                                noiseDelayCopy[noiseDelayLen] = '\0';
                                                                noisePacket->delay = noiseDelayCopy;

                                                            }

                                                            // rand / randRange are only present when type is "array"
                                                            if (
                                                                cJSON_HasObjectItem(noisePacketItem, "rand") &&
                                                                cJSON_IsString(cJSON_GetObjectItem(noisePacketItem, "rand"))
                                                               ) {
                                                                char* noiseRand = cJSON_GetObjectItem(noisePacketItem, "rand")->valuestring;
                                                                size_t noiseRandLen = strlen(noiseRand);
                                                                char* noiseRandCopy = (char*)malloc((noiseRandLen + 1) * sizeof(char));
                                                                strncpy(noiseRandCopy, noiseRand, noiseRandLen);
                                                                noiseRandCopy[noiseRandLen] = '\0';
                                                                noisePacket->rand = noiseRandCopy;

                                                            }

                                                            if (
                                                                cJSON_HasObjectItem(noisePacketItem, "randRange") &&
                                                                cJSON_IsString(cJSON_GetObjectItem(noisePacketItem, "randRange"))
                                                               ) {
                                                                char* noiseRandRange = cJSON_GetObjectItem(noisePacketItem, "randRange")->valuestring;
                                                                size_t noiseRandRangeLen = strlen(noiseRandRange);
                                                                char* noiseRandRangeCopy = (char*)malloc((noiseRandRangeLen + 1) * sizeof(char));
                                                                strncpy(noiseRandRangeCopy, noiseRandRange, noiseRandRangeLen);
                                                                noiseRandRangeCopy[noiseRandRangeLen] = '\0';
                                                                noisePacket->randRange = noiseRandRangeCopy;

                                                            }

                                                            // packet is only present when type is "str" / "hex" / "base64"
                                                            if (
                                                                cJSON_HasObjectItem(noisePacketItem, "packet") &&
                                                                cJSON_IsString(cJSON_GetObjectItem(noisePacketItem, "packet"))
                                                               ) {
                                                                char* noisePacketVal = cJSON_GetObjectItem(noisePacketItem, "packet")->valuestring;
                                                                size_t noisePacketLen = strlen(noisePacketVal);
                                                                char* noisePacketCopy = (char*)malloc((noisePacketLen + 1) * sizeof(char));
                                                                strncpy(noisePacketCopy, noisePacketVal, noisePacketLen);
                                                                noisePacketCopy[noisePacketLen] = '\0';
                                                                noisePacket->packet = noisePacketCopy;

                                                            }

                                                        }

                                                        noiseStruct->listInStreamSettingsFinalMaskUdpNoisePacketStruct = noiseCopy;
                                                        noiseStruct->jsonListInboundStreamSettingsFinalMaskUdpNoisePacketStructSize = noiseCount;

                                                    }

                                                    break;

                                                default:
                                                    break;

                                            }

                                        } else {
                                            applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "The settings field is not present in the udp mask element, skipping the element...");

                                        }

                                    } else {
                                        applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "The type field is not present in the udp mask element, skipping the element...");

                                    }

                                }

                            }

                        }

                        break;

                    case NETWORKTYPE_WS:
                        if (
                            cJSON_HasObjectItem(streamSettingsObj, "wsSettings") &&
                            cJSON_IsObject(cJSON_GetObjectItem(streamSettingsObj, "wsSettings"))
                           ) {
                            cJSON* wsSettingsObj = cJSON_GetObjectItem(streamSettingsObj, "wsSettings");
                            if (!wsSettingsObj) {
                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "wsSettingsObj is a null pointer");

                                streamSettingsStruct->listInStreamSettingsWSSettingsObjStruct = NULL;
                                jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                inboundObj->listInStreamSettingsObjStruct = NULL;
                                inboundObj->listInSniffingObjStruct = NULL;
                                jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                listInStruct->listInObjStruct = NULL;
                                jsonListInboundStructDelete(listInStruct);

                                cJSON_Delete(jsonParser);

                                return NULL;

                            }

                            if (
                                cJSON_HasObjectItem(wsSettingsObj, "acceptProxyProtocol") &&
                                cJSON_HasObjectItem(wsSettingsObj, "header") &&
                                cJSON_IsObject(cJSON_GetObjectItem(wsSettingsObj, "header"))
                               ) {
                                streamSettingsStruct->listInStreamSettingsWSSettingsObjStruct = (struct jsonListInboundStreamSettingsWSSettingsObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsWSSettingsObjectStruct));
                                if (!streamSettingsStruct->listInStreamSettingsWSSettingsObjStruct) {
                                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsWSSettingsObjStruct is a null pointer, failed to allocate space");

                                    streamSettingsStruct->listInStreamSettingsWSSettingsObjStruct = NULL;
                                    jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                    inboundObj->listInStreamSettingsObjStruct = NULL;
                                    inboundObj->listInSniffingObjStruct = NULL;
                                    jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                    listInStruct->listInObjStruct = NULL;
                                    jsonListInboundStructDelete(listInStruct);

                                    cJSON_Delete(jsonParser);

                                    return NULL;

                                }

                                struct jsonListInboundStreamSettingsWSSettingsObjectStruct* wsSettingsStruct = streamSettingsStruct->listInStreamSettingsWSSettingsObjStruct;

                                wsSettingsStruct->acceptProxyProtocol = cJSON_IsTrue(cJSON_GetObjectItem(wsSettingsObj, "acceptProxyProtocol"));

                                cJSON* wsHeaderObj = cJSON_GetObjectItem(wsSettingsObj, "header");
                                if (!wsHeaderObj) {
                                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "wsHeaderObj is a null pointer");

                                    wsSettingsStruct->listInStreamSettingsWSSettingsObjHeaderObjStruct = NULL;
                                    jsonListInboundStreamSettingsWSSettingsObjectStructDelete(wsSettingsStruct);

                                    streamSettingsStruct->listInStreamSettingsWSSettingsObjStruct = NULL;
                                    jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                    inboundObj->listInStreamSettingsObjStruct = NULL;
                                    inboundObj->listInSniffingObjStruct = NULL;
                                    jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                    listInStruct->listInObjStruct = NULL;
                                    jsonListInboundStructDelete(listInStruct);

                                    cJSON_Delete(jsonParser);

                                    return NULL;

                                }

                                if (
                                    cJSON_HasObjectItem(wsHeaderObj, "type") &&
                                    cJSON_IsString(cJSON_GetObjectItem(wsHeaderObj, "type")) &&
                                    cJSON_HasObjectItem(wsHeaderObj, "request") &&
                                    cJSON_IsObject(cJSON_GetObjectItem(wsHeaderObj, "request")) &&
                                    cJSON_HasObjectItem(wsHeaderObj, "response") &&
                                    cJSON_IsObject(cJSON_GetObjectItem(wsHeaderObj, "response"))
                                   ) {
                                    wsSettingsStruct->listInStreamSettingsWSSettingsObjHeaderObjStruct = (struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectStruct));
                                    if (!wsSettingsStruct->listInStreamSettingsWSSettingsObjHeaderObjStruct) {
                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsWSSettingsObjHeaderObjStruct is a null pointer, failed to allocate space");

                                        wsSettingsStruct->listInStreamSettingsWSSettingsObjHeaderObjStruct = NULL;
                                        jsonListInboundStreamSettingsWSSettingsObjectStructDelete(wsSettingsStruct);

                                        streamSettingsStruct->listInStreamSettingsWSSettingsObjStruct = NULL;
                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                        inboundObj->listInSniffingObjStruct = NULL;
                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                        listInStruct->listInObjStruct = NULL;
                                        jsonListInboundStructDelete(listInStruct);

                                        cJSON_Delete(jsonParser);

                                        return NULL;

                                    }

                                    struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectStruct* headerStruct = wsSettingsStruct->listInStreamSettingsWSSettingsObjHeaderObjStruct;

                                    char* type = cJSON_GetObjectItem(wsHeaderObj, "type")->valuestring;
                                    size_t typeLen = strlen(type);
                                    char* typeCopy = (char*)malloc((typeLen + 1) * sizeof(char));
                                    strncpy(typeCopy, type, typeLen);
                                    typeCopy[typeLen] = '\0';
                                    headerStruct->type = typeCopy;

                                    headerStruct->listInStreamSettingsWSSettingsObjHeaderObjReqObjStruct = (struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectRequestObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectRequestObjectStruct));
                                    if (!headerStruct->listInStreamSettingsWSSettingsObjHeaderObjReqObjStruct) {
                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsWSSettingsObjHeaderObjReqObjStruct is a null pointer, failed to allocate space");

                                        headerStruct->listInStreamSettingsWSSettingsObjHeaderObjReqObjStruct = NULL;
                                        headerStruct->listInStreamSettingsWSSettingsObjHeaderObjResObjStruct = NULL;
                                        jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectStructDelete(headerStruct);

                                        wsSettingsStruct->listInStreamSettingsWSSettingsObjHeaderObjStruct = NULL;
                                        jsonListInboundStreamSettingsWSSettingsObjectStructDelete(wsSettingsStruct);

                                        streamSettingsStruct->listInStreamSettingsWSSettingsObjStruct = NULL;
                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                        inboundObj->listInSniffingObjStruct = NULL;
                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                        listInStruct->listInObjStruct = NULL;
                                        jsonListInboundStructDelete(listInStruct);

                                        cJSON_Delete(jsonParser);

                                        return NULL;

                                    }

                                    struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectRequestObjectStruct* headerReqStruct = headerStruct->listInStreamSettingsWSSettingsObjHeaderObjReqObjStruct;

                                    headerReqStruct->listInStreamSettingsWSSettingsObjHeaderObjReqHeadersStruct = NULL;

                                    cJSON* requestHeaderObj = cJSON_GetObjectItem(wsHeaderObj, "request");
                                    if (!requestHeaderObj) {
                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "requestHeaderObj is a null pointer");

                                        headerReqStruct->listInStreamSettingsWSSettingsObjHeaderObjReqHeadersStruct = NULL;
                                        headerStruct->listInStreamSettingsWSSettingsObjHeaderObjResObjStruct = NULL;
                                        jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectStructDelete(headerStruct);

                                        wsSettingsStruct->listInStreamSettingsWSSettingsObjHeaderObjStruct = NULL;
                                        jsonListInboundStreamSettingsWSSettingsObjectStructDelete(wsSettingsStruct);

                                        streamSettingsStruct->listInStreamSettingsWSSettingsObjStruct = NULL;
                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                        inboundObj->listInSniffingObjStruct = NULL;
                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                        listInStruct->listInObjStruct = NULL;
                                        jsonListInboundStructDelete(listInStruct);

                                        cJSON_Delete(jsonParser);

                                        return NULL;

                                    }

                                    char* requestVersion = cJSON_GetObjectItem(requestHeaderObj, "version")->valuestring;
                                    size_t requestVersionLen = strlen(requestVersion);
                                    char* requestVersionCopy = (char*)malloc((requestVersionLen + 1) * sizeof(char));
                                    strncpy(requestVersionCopy, requestVersion, requestVersionLen);
                                    requestVersionCopy[requestVersionLen] = '\0';
                                    headerReqStruct->version = requestVersionCopy;

                                    char* requestMethod = cJSON_GetObjectItem(requestHeaderObj, "method")->valuestring;
                                    size_t requestMethodLen = strlen(requestMethod);
                                    char* requestMethodCopy = (char*)malloc((requestMethodLen + 1) * sizeof(char));
                                    strncpy(requestMethodCopy, requestMethod, requestMethodLen);
                                    requestMethodCopy[requestMethodLen] = '\0';
                                    headerReqStruct->method = requestMethodCopy;

                                    cJSON* requestPathObj = cJSON_GetObjectItem(requestHeaderObj, "path");
                                    size_t requestPathCount = cJSON_GetArraySize(requestPathObj);
                                    const char** requestPathCopy = (const char**)malloc((requestPathCount ? requestPathCount : 1) * sizeof(char*));
                                    for (size_t requestPathIdx = 0; requestPathIdx < requestPathCount; requestPathIdx++) {
                                        char* requestPathItem = cJSON_GetArrayItem(requestPathObj, requestPathIdx)->valuestring;
                                        size_t requestPathItemLen = strlen(requestPathItem);
                                        char* requestPathItemCopy = (char*)malloc((requestPathItemLen + 1) * sizeof(char));
                                        strncpy(requestPathItemCopy, requestPathItem, requestPathItemLen);
                                        requestPathItemCopy[requestPathItemLen] = '\0';
                                        requestPathCopy[requestPathIdx] = requestPathItemCopy;
                                    }
                                    headerReqStruct->path = requestPathCopy;
                                    headerReqStruct->pathCount = requestPathCount;

                                    if (
                                        cJSON_HasObjectItem(requestHeaderObj, "headers") &&
                                        cJSON_IsObject(cJSON_GetObjectItem(requestHeaderObj, "headers"))
                                       ) {
                                        cJSON* requestHeadersObj = cJSON_GetObjectItem(requestHeaderObj, "headers");
                                        size_t requestHeadersCount = cJSON_GetArraySize(requestHeadersObj);
                                        struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersStruct* requestHeadersCopy = (struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersStruct*)malloc((requestHeadersCount ? requestHeadersCount : 1) * sizeof(struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersStruct));
                                        for (size_t headerIdx = 0; headerIdx < requestHeadersCount; headerIdx++) {
                                            cJSON* requestHeadersItem = cJSON_GetArrayItem(requestHeadersObj, headerIdx);

                                            char* headerName = requestHeadersItem->string;
                                            size_t headerNameLen = strlen(headerName);
                                            char* headerNameCopy = (char*)malloc((headerNameLen + 1) * sizeof(char));
                                            strncpy(headerNameCopy, headerName, headerNameLen);
                                            headerNameCopy[headerNameLen] = '\0';
                                            requestHeadersCopy[headerIdx].name = headerNameCopy;

                                            size_t headerValueCount = cJSON_GetArraySize(requestHeadersItem);
                                            const char** headerValueCopy = (const char**)malloc((headerValueCount ? headerValueCount : 1) * sizeof(char*));
                                            for (size_t valueIdx = 0; valueIdx < headerValueCount; valueIdx++) {
                                                char* headerValueItem = cJSON_GetArrayItem(requestHeadersItem, valueIdx)->valuestring;
                                                size_t headerValueItemLen = strlen(headerValueItem);
                                                char* headerValueItemCopy = (char*)malloc((headerValueItemLen + 1) * sizeof(char));
                                                strncpy(headerValueItemCopy, headerValueItem, headerValueItemLen);
                                                headerValueItemCopy[headerValueItemLen] = '\0';
                                                headerValueCopy[valueIdx] = headerValueItemCopy;
                                            }
                                            requestHeadersCopy[headerIdx].value = headerValueCopy;
                                            requestHeadersCopy[headerIdx].valueCount = headerValueCount;

                                        }
                                        headerReqStruct->listInStreamSettingsWSSettingsObjHeaderObjReqHeadersStruct = requestHeadersCopy;
                                        headerReqStruct->jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersStructSize = requestHeadersCount;
                                    }

                                    headerStruct->listInStreamSettingsWSSettingsObjHeaderObjResObjStruct = (struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectResponseObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectResponseObjectStruct));
                                    if (!headerStruct->listInStreamSettingsWSSettingsObjHeaderObjResObjStruct) {
                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsWSSettingsObjHeaderObjResObjStruct is a null pointer, failed to allocate space");

                                        headerStruct->listInStreamSettingsWSSettingsObjHeaderObjResObjStruct = NULL;
                                        jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectStructDelete(headerStruct);

                                        wsSettingsStruct->listInStreamSettingsWSSettingsObjHeaderObjStruct = NULL;
                                        jsonListInboundStreamSettingsWSSettingsObjectStructDelete(wsSettingsStruct);

                                        streamSettingsStruct->listInStreamSettingsWSSettingsObjStruct = NULL;
                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                        inboundObj->listInSniffingObjStruct = NULL;
                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                        listInStruct->listInObjStruct = NULL;
                                        jsonListInboundStructDelete(listInStruct);

                                        cJSON_Delete(jsonParser);

                                        return NULL;

                                    }

                                    struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectResponseObjectStruct* headerResStruct = headerStruct->listInStreamSettingsWSSettingsObjHeaderObjResObjStruct;

                                    headerResStruct->listInStreamSettingsWSSettingsObjHeaderObjResHeadersStruct = NULL;

                                    cJSON* responseHeaderObj = cJSON_GetObjectItem(wsHeaderObj, "response");
                                    if (!responseHeaderObj) {
                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "responseHeaderObj is a null pointer");

                                        headerResStruct->listInStreamSettingsWSSettingsObjHeaderObjResHeadersStruct = NULL;
                                        jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectStructDelete(headerStruct);

                                        wsSettingsStruct->listInStreamSettingsWSSettingsObjHeaderObjStruct = NULL;
                                        jsonListInboundStreamSettingsWSSettingsObjectStructDelete(wsSettingsStruct);

                                        streamSettingsStruct->listInStreamSettingsWSSettingsObjStruct = NULL;
                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                        inboundObj->listInSniffingObjStruct = NULL;
                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                        listInStruct->listInObjStruct = NULL;
                                        jsonListInboundStructDelete(listInStruct);

                                        cJSON_Delete(jsonParser);

                                        return NULL;

                                    }

                                    char* responseVersion = cJSON_GetObjectItem(responseHeaderObj, "version")->valuestring;
                                    size_t responseVersionLen = strlen(responseVersion);
                                    char* responseVersionCopy = (char*)malloc((responseVersionLen + 1) * sizeof(char));
                                    strncpy(responseVersionCopy, responseVersion, responseVersionLen);
                                    responseVersionCopy[responseVersionLen] = '\0';
                                    headerResStruct->version = responseVersionCopy;

                                    char* responseStatus = cJSON_GetObjectItem(responseHeaderObj, "status")->valuestring;
                                    size_t responseStatusLen = strlen(responseStatus);
                                    char* responseStatusCopy = (char*)malloc((responseStatusLen + 1) * sizeof(char));
                                    strncpy(responseStatusCopy, responseStatus, responseStatusLen);
                                    responseStatusCopy[responseStatusLen] = '\0';
                                    headerResStruct->status = responseStatusCopy;

                                    char* responseReason = cJSON_GetObjectItem(responseHeaderObj, "reason")->valuestring;
                                    size_t responseReasonLen = strlen(responseReason);
                                    char* responseReasonCopy = (char*)malloc((responseReasonLen + 1) * sizeof(char));
                                    strncpy(responseReasonCopy, responseReason, responseReasonLen);
                                    responseReasonCopy[responseReasonLen] = '\0';
                                    headerResStruct->reason = responseReasonCopy;

                                    if (
                                        cJSON_HasObjectItem(responseHeaderObj, "headers") &&
                                        cJSON_IsObject(cJSON_GetObjectItem(responseHeaderObj, "headers"))
                                       ) {
                                        cJSON* responseHeadersObj = cJSON_GetObjectItem(responseHeaderObj, "headers");
                                        size_t responseHeadersCount = cJSON_GetArraySize(responseHeadersObj);
                                        struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersStruct* responseHeadersCopy = (struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersStruct*)malloc((responseHeadersCount ? responseHeadersCount : 1) * sizeof(struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersStruct));
                                        for (size_t headerIdx = 0; headerIdx < responseHeadersCount; headerIdx++) {
                                            cJSON* responseHeadersItem = cJSON_GetArrayItem(responseHeadersObj, headerIdx);

                                            char* headerName = responseHeadersItem->string;
                                            size_t headerNameLen = strlen(headerName);
                                            char* headerNameCopy = (char*)malloc((headerNameLen + 1) * sizeof(char));
                                            strncpy(headerNameCopy, headerName, headerNameLen);
                                            headerNameCopy[headerNameLen] = '\0';
                                            responseHeadersCopy[headerIdx].name = headerNameCopy;

                                            size_t headerValueCount = cJSON_GetArraySize(responseHeadersItem);
                                            const char** headerValueCopy = (const char**)malloc((headerValueCount ? headerValueCount : 1) * sizeof(char*));
                                            for (size_t valueIdx = 0; valueIdx < headerValueCount; valueIdx++) {
                                                char* headerValueItem = cJSON_GetArrayItem(responseHeadersItem, valueIdx)->valuestring;
                                                size_t headerValueItemLen = strlen(headerValueItem);
                                                char* headerValueItemCopy = (char*)malloc((headerValueItemLen + 1) * sizeof(char));
                                                strncpy(headerValueItemCopy, headerValueItem, headerValueItemLen);
                                                headerValueItemCopy[headerValueItemLen] = '\0';
                                                headerValueCopy[valueIdx] = headerValueItemCopy;
                                            }
                                            responseHeadersCopy[headerIdx].value = headerValueCopy;
                                            responseHeadersCopy[headerIdx].valueCount = headerValueCount;
                                        }
                                        headerResStruct->listInStreamSettingsWSSettingsObjHeaderObjResHeadersStruct = responseHeadersCopy;
                                        headerResStruct->jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersStructSize = responseHeadersCount;
                                    }

                                    } else {
                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the wsSettings header object, type/request/response are not present");

                                        wsSettingsStruct->listInStreamSettingsWSSettingsObjHeaderObjStruct = NULL;
                                        jsonListInboundStreamSettingsWSSettingsObjectStructDelete(wsSettingsStruct);

                                        streamSettingsStruct->listInStreamSettingsWSSettingsObjStruct = NULL;
                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                        inboundObj->listInSniffingObjStruct = NULL;
                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                        listInStruct->listInObjStruct = NULL;
                                        jsonListInboundStructDelete(listInStruct);

                                        cJSON_Delete(jsonParser);

                                        return NULL;

                                    }

                            } else {
                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the wsSettings object, acceptProxyProtocol/header are not present");

                                streamSettingsStruct->listInStreamSettingsWSSettingsObjStruct = NULL;
                                jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                inboundObj->listInStreamSettingsObjStruct = NULL;
                                inboundObj->listInSniffingObjStruct = NULL;
                                jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                listInStruct->listInObjStruct = NULL;
                                jsonListInboundStructDelete(listInStruct);

                                cJSON_Delete(jsonParser);

                                return NULL;

                            }

                        } else {
                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the streamSettings object, wsSettings is not present");

                            streamSettingsStruct->listInStreamSettingsWSSettingsObjStruct = NULL;
                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                            inboundObj->listInStreamSettingsObjStruct = NULL;
                            inboundObj->listInSniffingObjStruct = NULL;
                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                            listInStruct->listInObjStruct = NULL;
                            jsonListInboundStructDelete(listInStruct);

                            cJSON_Delete(jsonParser);

                            return NULL;

                        }

                        // The security field is a plain string and currently "none" for every ws variant.
                        // TODO: when the security field shows a different value, it may carry extra
                        // settings ( e.g. a tls configuration ), take care of them at the settings field
                        if (
                            cJSON_HasObjectItem(streamSettingsObj, "security") &&
                            cJSON_IsString(cJSON_GetObjectItem(streamSettingsObj, "security"))
                           ) {
                            char* security = cJSON_GetObjectItem(streamSettingsObj, "security")->valuestring;
                            size_t securityLen = strlen(security);
                            char* securityCopy = (char*)malloc((securityLen + 1) * sizeof(char));
                            strncpy(securityCopy, security, securityLen);
                            securityCopy[securityLen] = '\0';
                            streamSettingsStruct->security = securityCopy;

                        }

                        // The ws mask ( finalmask ) is an optional field, it holds a "ws" array
                        // whose elements carry a "type" ( fragment, header-custom, sudoku, xmc )
                        // and a "settings" object shaped by that type
                        if (
                            cJSON_HasObjectItem(streamSettingsObj, "finalmask") &&
                            cJSON_IsObject(cJSON_GetObjectItem(streamSettingsObj, "finalmask"))
                           ) {
                            cJSON* wsFinalMaskObj = cJSON_GetObjectItem(streamSettingsObj, "finalmask");
                            if (!wsFinalMaskObj) {
                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "wsFinalMaskObj is a null pointer");

                                jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                inboundObj->listInStreamSettingsObjStruct = NULL;
                                inboundObj->listInSniffingObjStruct = NULL;
                                jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                listInStruct->listInObjStruct = NULL;
                                jsonListInboundStructDelete(listInStruct);

                                cJSON_Delete(jsonParser);

                                return NULL;

                            }

                            streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = (struct jsonListInboundStreamSettingsWSFinalMaskObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsWSFinalMaskObjectStruct));
                            if (!streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct) {
                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsWSFinalMaskObjStruct is a null pointer, failed to allocate space");

                                streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                                jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                inboundObj->listInStreamSettingsObjStruct = NULL;
                                inboundObj->listInSniffingObjStruct = NULL;
                                jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                listInStruct->listInObjStruct = NULL;
                                jsonListInboundStructDelete(listInStruct);

                                cJSON_Delete(jsonParser);

                                return NULL;

                            }

                            struct jsonListInboundStreamSettingsWSFinalMaskObjectStruct* wsFinalMaskStruct = streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct;
                            wsFinalMaskStruct->listInStreamSettingsWSFinalMaskTcpStruct = NULL;
                            wsFinalMaskStruct->jsonListInboundStreamSettingsWSFinalMaskTcpStructSize = 0;

                            const char* wsMaskTypes[] = {
                                "fragment", // Fragment
                                "header-custom", // Header Custom
                                "sudoku", // Sudoku
                                "xmc" // XMC

                            };

                            enum wsMaskTypesEnum {
                                TCPMASKTYPE_FRAGMENT,
                                TCPMASKTYPE_HEADERCUSTOM,
                                TCPMASKTYPE_SUDOKU,
                                TCPMASKTYPE_XMC,
                                TCPMASKTYPE_COUNT

                            };

                            if (
                                cJSON_HasObjectItem(wsFinalMaskObj, "ws") &&
                                cJSON_IsArray(cJSON_GetObjectItem(wsFinalMaskObj, "ws"))
                               ) {
                                cJSON* tcpObj = cJSON_GetObjectItem(wsFinalMaskObj, "ws");
                                if (!tcpObj) {
                                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "tcpObj is a null pointer");

                                    jsonListInboundStreamSettingsWSFinalMaskObjectStructDelete(wsFinalMaskStruct);

                                    streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                                    jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                    inboundObj->listInStreamSettingsObjStruct = NULL;
                                    inboundObj->listInSniffingObjStruct = NULL;
                                    jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                    listInStruct->listInObjStruct = NULL;
                                    jsonListInboundStructDelete(listInStruct);

                                    cJSON_Delete(jsonParser);

                                    return NULL;

                                }

                                size_t tcpCount = cJSON_GetArraySize(tcpObj);
                                struct jsonListInboundStreamSettingsWSFinalMaskTcpObjectStruct* tcpCopy = (struct jsonListInboundStreamSettingsWSFinalMaskTcpObjectStruct*)malloc((tcpCount ? tcpCount : 1) * sizeof(struct jsonListInboundStreamSettingsWSFinalMaskTcpObjectStruct));
                                if (!tcpCopy) {
                                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "tcpCopy is a null pointer, failed to allocate space");

                                    jsonListInboundStreamSettingsWSFinalMaskObjectStructDelete(wsFinalMaskStruct);

                                    streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                                    jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                    inboundObj->listInStreamSettingsObjStruct = NULL;
                                    inboundObj->listInSniffingObjStruct = NULL;
                                    jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                    listInStruct->listInObjStruct = NULL;
                                    jsonListInboundStructDelete(listInStruct);

                                    cJSON_Delete(jsonParser);

                                    return NULL;

                                }

                                wsFinalMaskStruct->listInStreamSettingsWSFinalMaskTcpStruct = tcpCopy;
                                wsFinalMaskStruct->jsonListInboundStreamSettingsWSFinalMaskTcpStructSize = tcpCount;

                                for (size_t t = 0; t < tcpCount; t++) {
                                    tcpCopy[t].type = NULL;
                                    tcpCopy[t].listInStreamSettingsWSFinalMaskFragmentObjStruct = NULL;
                                    tcpCopy[t].listInStreamSettingsWSFinalMaskHeaderCustomObjStruct = NULL;
                                    tcpCopy[t].listInStreamSettingsWSFinalMaskSudokuObjStruct = NULL;
                                    tcpCopy[t].listInStreamSettingsWSFinalMaskXmcObjStruct = NULL;

                                }

                                for (size_t t = 0; t < tcpCount; t++) {
                                    cJSON* tcpItem = cJSON_GetArrayItem(tcpObj, t);
                                    struct jsonListInboundStreamSettingsWSFinalMaskTcpObjectStruct* wsStruct = &tcpCopy[t];

                                    if (
                                        cJSON_HasObjectItem(tcpItem, "type") &&
                                        cJSON_IsString(cJSON_GetObjectItem(tcpItem, "type"))
                                       ) {
                                        char* tcpType = cJSON_GetObjectItem(tcpItem, "type")->valuestring;
                                        size_t tcpTypeLen = strlen(tcpType);
                                        char* tcpTypeCopy = (char*)malloc((tcpTypeLen + 1) * sizeof(char));
                                        strncpy(tcpTypeCopy, tcpType, tcpTypeLen);
                                        tcpTypeCopy[tcpTypeLen] = '\0';
                                        wsStruct->type = tcpTypeCopy;

                                        enum wsMaskTypesEnum tType = TCPMASKTYPE_COUNT;
                                        for (int t2 = 0; t2 < TCPMASKTYPE_COUNT; t2++) {
                                            if (strncmp(wsMaskTypes[t2], wsStruct->type, strlen(wsMaskTypes[t2])) == 0) {
                                                tType = (enum wsMaskTypesEnum)t2;
                                                break;

                                            }

                                        }
                                        if (tType == TCPMASKTYPE_COUNT) {
                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Unable to detect tcp mask type");

                                            jsonListInboundStreamSettingsWSFinalMaskObjectStructDelete(wsFinalMaskStruct);

                                            streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                            inboundObj->listInSniffingObjStruct = NULL;
                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                            listInStruct->listInObjStruct = NULL;
                                            jsonListInboundStructDelete(listInStruct);

                                            cJSON_Delete(jsonParser);

                                            return NULL;

                                        }

                                        if (
                                            cJSON_HasObjectItem(tcpItem, "settings") &&
                                            cJSON_IsObject(cJSON_GetObjectItem(tcpItem, "settings"))
                                           ) {
                                            cJSON* wsMaskSettingsObj = cJSON_GetObjectItem(tcpItem, "settings");
                                            if (!wsMaskSettingsObj) {
                                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "wsMaskSettingsObj is a null pointer");

                                                jsonListInboundStreamSettingsWSFinalMaskObjectStructDelete(wsFinalMaskStruct);

                                                streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                                                jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                inboundObj->listInStreamSettingsObjStruct = NULL;
                                                inboundObj->listInSniffingObjStruct = NULL;
                                                jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                listInStruct->listInObjStruct = NULL;
                                                jsonListInboundStructDelete(listInStruct);

                                                cJSON_Delete(jsonParser);

                                                return NULL;

                                            }

                                            switch (tType) {
                                                case TCPMASKTYPE_FRAGMENT:
                                                    wsStruct->listInStreamSettingsWSFinalMaskFragmentObjStruct = (struct jsonListInboundStreamSettingsWSFinalMaskFragmentObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsWSFinalMaskFragmentObjectStruct));
                                                    if (!wsStruct->listInStreamSettingsWSFinalMaskFragmentObjStruct) {
                                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsWSFinalMaskFragmentObjStruct is a null pointer, failed to allocate space");

                                                        jsonListInboundStreamSettingsWSFinalMaskObjectStructDelete(wsFinalMaskStruct);

                                                        streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                                        inboundObj->listInSniffingObjStruct = NULL;
                                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                        listInStruct->listInObjStruct = NULL;
                                                        jsonListInboundStructDelete(listInStruct);

                                                        cJSON_Delete(jsonParser);

                                                        return NULL;

                                                    }

                                                    struct jsonListInboundStreamSettingsWSFinalMaskFragmentObjectStruct* fragmentStruct = wsStruct->listInStreamSettingsWSFinalMaskFragmentObjStruct;
                                                    fragmentStruct->packets = NULL;
                                                    fragmentStruct->lengths = NULL;
                                                    fragmentStruct->lengthsCount = 0;
                                                    fragmentStruct->maxSplit = NULL;
                                                    fragmentStruct->delays = NULL;
                                                    fragmentStruct->delaysCount = 0;

                                                    if (
                                                        cJSON_HasObjectItem(wsMaskSettingsObj, "packets") &&
                                                        cJSON_IsString(cJSON_GetObjectItem(wsMaskSettingsObj, "packets"))
                                                       ) {
                                                        char* fragmentPackets = cJSON_GetObjectItem(wsMaskSettingsObj, "packets")->valuestring;
                                                        size_t fragmentPacketsLen = strlen(fragmentPackets);
                                                        char* fragmentPacketsCopy = (char*)malloc((fragmentPacketsLen + 1) * sizeof(char));
                                                        strncpy(fragmentPacketsCopy, fragmentPackets, fragmentPacketsLen);
                                                        fragmentPacketsCopy[fragmentPacketsLen] = '\0';
                                                        fragmentStruct->packets = fragmentPacketsCopy;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(wsMaskSettingsObj, "lengths") &&
                                                        cJSON_IsArray(cJSON_GetObjectItem(wsMaskSettingsObj, "lengths"))
                                                       ) {
                                                        cJSON* fragmentLengthsObj = cJSON_GetObjectItem(wsMaskSettingsObj, "lengths");
                                                        size_t fragmentLengthsCount = cJSON_GetArraySize(fragmentLengthsObj);
                                                        const char** fragmentLengthsCopy = (const char**)malloc((fragmentLengthsCount ? fragmentLengthsCount : 1) * sizeof(char*));
                                                        if (!fragmentLengthsCopy) {
                                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "fragmentLengthsCopy is a null pointer, failed to allocate space");

                                                            jsonListInboundStreamSettingsWSFinalMaskObjectStructDelete(wsFinalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                                            inboundObj->listInSniffingObjStruct = NULL;
                                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                            listInStruct->listInObjStruct = NULL;
                                                            jsonListInboundStructDelete(listInStruct);

                                                            cJSON_Delete(jsonParser);

                                                            return NULL;

                                                        }

                                                        for (size_t lenIdx = 0; lenIdx < fragmentLengthsCount; lenIdx++) {
                                                            char* fragmentLengthItem = cJSON_GetArrayItem(fragmentLengthsObj, lenIdx)->valuestring;
                                                            size_t fragmentLengthItemLen = strlen(fragmentLengthItem);
                                                            char* fragmentLengthItemCopy = (char*)malloc((fragmentLengthItemLen + 1) * sizeof(char));
                                                            strncpy(fragmentLengthItemCopy, fragmentLengthItem, fragmentLengthItemLen);
                                                            fragmentLengthItemCopy[fragmentLengthItemLen] = '\0';
                                                            fragmentLengthsCopy[lenIdx] = fragmentLengthItemCopy;

                                                        }
                                                        fragmentStruct->lengths = fragmentLengthsCopy;
                                                        fragmentStruct->lengthsCount = (int64_t)fragmentLengthsCount;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(wsMaskSettingsObj, "maxSplit") &&
                                                        cJSON_IsString(cJSON_GetObjectItem(wsMaskSettingsObj, "maxSplit"))
                                                       ) {
                                                        char* fragmentMaxSplit = cJSON_GetObjectItem(wsMaskSettingsObj, "maxSplit")->valuestring;
                                                        size_t fragmentMaxSplitLen = strlen(fragmentMaxSplit);
                                                        char* fragmentMaxSplitCopy = (char*)malloc((fragmentMaxSplitLen + 1) * sizeof(char));
                                                        strncpy(fragmentMaxSplitCopy, fragmentMaxSplit, fragmentMaxSplitLen);
                                                        fragmentMaxSplitCopy[fragmentMaxSplitLen] = '\0';
                                                        fragmentStruct->maxSplit = fragmentMaxSplitCopy;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(wsMaskSettingsObj, "delays") &&
                                                        cJSON_IsArray(cJSON_GetObjectItem(wsMaskSettingsObj, "delays"))
                                                       ) {
                                                        cJSON* fragmentDelaysObj = cJSON_GetObjectItem(wsMaskSettingsObj, "delays");
                                                        size_t fragmentDelaysCount = cJSON_GetArraySize(fragmentDelaysObj);
                                                        const char** fragmentDelaysCopy = (const char**)malloc((fragmentDelaysCount ? fragmentDelaysCount : 1) * sizeof(char*));
                                                        if (!fragmentDelaysCopy) {
                                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "fragmentDelaysCopy is a null pointer, failed to allocate space");

                                                            jsonListInboundStreamSettingsWSFinalMaskObjectStructDelete(wsFinalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                                            inboundObj->listInSniffingObjStruct = NULL;
                                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                            listInStruct->listInObjStruct = NULL;
                                                            jsonListInboundStructDelete(listInStruct);

                                                            cJSON_Delete(jsonParser);

                                                            return NULL;

                                                        }

                                                        for (size_t delayIdx = 0; delayIdx < fragmentDelaysCount; delayIdx++) {
                                                            char* fragmentDelayItem = cJSON_GetArrayItem(fragmentDelaysObj, delayIdx)->valuestring;
                                                            size_t fragmentDelayItemLen = strlen(fragmentDelayItem);
                                                            char* fragmentDelayItemCopy = (char*)malloc((fragmentDelayItemLen + 1) * sizeof(char));
                                                            strncpy(fragmentDelayItemCopy, fragmentDelayItem, fragmentDelayItemLen);
                                                            fragmentDelayItemCopy[fragmentDelayItemLen] = '\0';
                                                            fragmentDelaysCopy[delayIdx] = fragmentDelayItemCopy;

                                                        }
                                                        fragmentStruct->delays = fragmentDelaysCopy;
                                                        fragmentStruct->delaysCount = (int64_t)fragmentDelaysCount;

                                                    }

                                                    break;

                                                case TCPMASKTYPE_HEADERCUSTOM:
                                                    wsStruct->listInStreamSettingsWSFinalMaskHeaderCustomObjStruct = (struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomObjectStruct));
                                                    if (!wsStruct->listInStreamSettingsWSFinalMaskHeaderCustomObjStruct) {
                                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsWSFinalMaskHeaderCustomObjStruct is a null pointer, failed to allocate space");

                                                        jsonListInboundStreamSettingsWSFinalMaskObjectStructDelete(wsFinalMaskStruct);

                                                        streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                                        inboundObj->listInSniffingObjStruct = NULL;
                                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                        listInStruct->listInObjStruct = NULL;
                                                        jsonListInboundStructDelete(listInStruct);

                                                        cJSON_Delete(jsonParser);

                                                        return NULL;

                                                    }

                                                    struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomObjectStruct* tcpHeaderCustomStruct = wsStruct->listInStreamSettingsWSFinalMaskHeaderCustomObjStruct;
                                                    tcpHeaderCustomStruct->listInStreamSettingsWSFinalMaskHeaderCustomClientGroupStruct = NULL;
                                                    tcpHeaderCustomStruct->jsonListInboundStreamSettingsWSFinalMaskHeaderCustomClientGroupStructSize = 0;
                                                    tcpHeaderCustomStruct->listInStreamSettingsWSFinalMaskHeaderCustomServerGroupStruct = NULL;
                                                    tcpHeaderCustomStruct->jsonListInboundStreamSettingsWSFinalMaskHeaderCustomServerGroupStructSize = 0;

                                                    // the client and server fields hold arrays of packet groups, each
                                                    // group is an array of packet objects
                                                    if (
                                                        cJSON_HasObjectItem(wsMaskSettingsObj, "clients") &&
                                                        cJSON_IsArray(cJSON_GetObjectItem(wsMaskSettingsObj, "clients"))
                                                       ) {
                                                        cJSON* clientsGroupArr = cJSON_GetObjectItem(wsMaskSettingsObj, "clients");
                                                        size_t clientsGroupCount = cJSON_GetArraySize(clientsGroupArr);
                                                        struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomGroupObjectStruct* headerCustomClientGroupCopy = (struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomGroupObjectStruct*)malloc((clientsGroupCount ? clientsGroupCount : 1) * sizeof(struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomGroupObjectStruct));
                                                        if (!headerCustomClientGroupCopy) {
                                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "headerCustomClientGroupCopy is a null pointer, failed to allocate space");

                                                            jsonListInboundStreamSettingsWSFinalMaskObjectStructDelete(wsFinalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                                            inboundObj->listInSniffingObjStruct = NULL;
                                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                            listInStruct->listInObjStruct = NULL;
                                                            jsonListInboundStructDelete(listInStruct);

                                                            cJSON_Delete(jsonParser);

                                                            return NULL;

                                                        }

                                                        for (size_t g = 0; g < clientsGroupCount; g++) {
                                                            headerCustomClientGroupCopy[g].listInStreamSettingsWSFinalMaskHeaderCustomPacketStruct = NULL;
                                                            headerCustomClientGroupCopy[g].jsonListInboundStreamSettingsWSFinalMaskHeaderCustomPacketStructSize = 0;

                                                        }

                                                        for (size_t g = 0; g < clientsGroupCount; g++) {
                                                            cJSON* clientGroupItem = cJSON_GetArrayItem(clientsGroupArr, g);
                                                            size_t clientPacketCount = cJSON_GetArraySize(clientGroupItem);
                                                            struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomPacketObjectStruct* headerCustomClientPacketCopy = (struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomPacketObjectStruct*)malloc((clientPacketCount ? clientPacketCount : 1) * sizeof(struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomPacketObjectStruct));
                                                            if (!headerCustomClientPacketCopy) {
                                                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "headerCustomClientPacketCopy is a null pointer, failed to allocate space");

                                                                jsonListInboundStreamSettingsWSFinalMaskObjectStructDelete(wsFinalMaskStruct);

                                                                streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                                                                jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                                inboundObj->listInStreamSettingsObjStruct = NULL;
                                                                inboundObj->listInSniffingObjStruct = NULL;
                                                                jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                                jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                                listInStruct->listInObjStruct = NULL;
                                                                jsonListInboundStructDelete(listInStruct);

                                                                cJSON_Delete(jsonParser);

                                                                return NULL;

                                                            }

                                                            for (size_t c = 0; c < clientPacketCount; c++) {
                                                                headerCustomClientPacketCopy[c].type = NULL;
                                                                headerCustomClientPacketCopy[c].delay = NULL;
                                                                headerCustomClientPacketCopy[c].rand = NULL;
                                                                headerCustomClientPacketCopy[c].randRange = NULL;
                                                                headerCustomClientPacketCopy[c].packet = NULL;

                                                            }

                                                            for (size_t c = 0; c < clientPacketCount; c++) {
                                                                cJSON* clientPacketItem = cJSON_GetArrayItem(clientGroupItem, c);

                                                                if (
                                                                    cJSON_HasObjectItem(clientPacketItem, "type") &&
                                                                    cJSON_IsString(cJSON_GetObjectItem(clientPacketItem, "type"))
                                                                   ) {
                                                                    char* clientPacketType = cJSON_GetObjectItem(clientPacketItem, "type")->valuestring;
                                                                    size_t clientPacketTypeLen = strlen(clientPacketType);
                                                                    char* clientPacketTypeCopy = (char*)malloc((clientPacketTypeLen + 1) * sizeof(char));
                                                                    strncpy(clientPacketTypeCopy, clientPacketType, clientPacketTypeLen);
                                                                    clientPacketTypeCopy[clientPacketTypeLen] = '\0';
                                                                    headerCustomClientPacketCopy[c].type = clientPacketTypeCopy;

                                                                }

                                                                if (
                                                                    cJSON_HasObjectItem(clientPacketItem, "delay") &&
                                                                    cJSON_IsString(cJSON_GetObjectItem(clientPacketItem, "delay"))
                                                                   ) {
                                                                    char* clientPacketDelay = cJSON_GetObjectItem(clientPacketItem, "delay")->valuestring;
                                                                    size_t clientPacketDelayLen = strlen(clientPacketDelay);
                                                                    char* clientPacketDelayCopy = (char*)malloc((clientPacketDelayLen + 1) * sizeof(char));
                                                                    strncpy(clientPacketDelayCopy, clientPacketDelay, clientPacketDelayLen);
                                                                    clientPacketDelayCopy[clientPacketDelayLen] = '\0';
                                                                    headerCustomClientPacketCopy[c].delay = clientPacketDelayCopy;

                                                                }

                                                                if (
                                                                    cJSON_HasObjectItem(clientPacketItem, "rand") &&
                                                                    cJSON_IsString(cJSON_GetObjectItem(clientPacketItem, "rand"))
                                                                   ) {
                                                                    char* clientPacketRand = cJSON_GetObjectItem(clientPacketItem, "rand")->valuestring;
                                                                    size_t clientPacketRandLen = strlen(clientPacketRand);
                                                                    char* clientPacketRandCopy = (char*)malloc((clientPacketRandLen + 1) * sizeof(char));
                                                                    strncpy(clientPacketRandCopy, clientPacketRand, clientPacketRandLen);
                                                                    clientPacketRandCopy[clientPacketRandLen] = '\0';
                                                                    headerCustomClientPacketCopy[c].rand = clientPacketRandCopy;

                                                                }

                                                                if (
                                                                    cJSON_HasObjectItem(clientPacketItem, "randRange") &&
                                                                    cJSON_IsString(cJSON_GetObjectItem(clientPacketItem, "randRange"))
                                                                   ) {
                                                                    char* clientPacketRandRange = cJSON_GetObjectItem(clientPacketItem, "randRange")->valuestring;
                                                                    size_t clientPacketRandRangeLen = strlen(clientPacketRandRange);
                                                                    char* clientPacketRandRangeCopy = (char*)malloc((clientPacketRandRangeLen + 1) * sizeof(char));
                                                                    strncpy(clientPacketRandRangeCopy, clientPacketRandRange, clientPacketRandRangeLen);
                                                                    clientPacketRandRangeCopy[clientPacketRandRangeLen] = '\0';
                                                                    headerCustomClientPacketCopy[c].randRange = clientPacketRandRangeCopy;

                                                                }

                                                                if (
                                                                    cJSON_HasObjectItem(clientPacketItem, "packet") &&
                                                                    cJSON_IsString(cJSON_GetObjectItem(clientPacketItem, "packet"))
                                                                   ) {
                                                                    char* clientPacketVal = cJSON_GetObjectItem(clientPacketItem, "packet")->valuestring;
                                                                    size_t clientPacketLen = strlen(clientPacketVal);
                                                                    char* clientPacketCopy = (char*)malloc((clientPacketLen + 1) * sizeof(char));
                                                                    strncpy(clientPacketCopy, clientPacketVal, clientPacketLen);
                                                                    clientPacketCopy[clientPacketLen] = '\0';
                                                                    headerCustomClientPacketCopy[c].packet = clientPacketCopy;

                                                                }

                                                            }

                                                            headerCustomClientGroupCopy[g].listInStreamSettingsWSFinalMaskHeaderCustomPacketStruct = headerCustomClientPacketCopy;
                                                            headerCustomClientGroupCopy[g].jsonListInboundStreamSettingsWSFinalMaskHeaderCustomPacketStructSize = clientPacketCount;

                                                        }

                                                        tcpHeaderCustomStruct->listInStreamSettingsWSFinalMaskHeaderCustomClientGroupStruct = headerCustomClientGroupCopy;
                                                        tcpHeaderCustomStruct->jsonListInboundStreamSettingsWSFinalMaskHeaderCustomClientGroupStructSize = clientsGroupCount;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(wsMaskSettingsObj, "servers") &&
                                                        cJSON_IsArray(cJSON_GetObjectItem(wsMaskSettingsObj, "servers"))
                                                       ) {
                                                        cJSON* serversGroupArr = cJSON_GetObjectItem(wsMaskSettingsObj, "servers");
                                                        size_t serversGroupCount = cJSON_GetArraySize(serversGroupArr);
                                                        struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomGroupObjectStruct* headerCustomServerGroupCopy = (struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomGroupObjectStruct*)malloc((serversGroupCount ? serversGroupCount : 1) * sizeof(struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomGroupObjectStruct));
                                                        if (!headerCustomServerGroupCopy) {
                                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "headerCustomServerGroupCopy is a null pointer, failed to allocate space");

                                                            jsonListInboundStreamSettingsWSFinalMaskObjectStructDelete(wsFinalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                                            inboundObj->listInSniffingObjStruct = NULL;
                                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                            listInStruct->listInObjStruct = NULL;
                                                            jsonListInboundStructDelete(listInStruct);

                                                            cJSON_Delete(jsonParser);

                                                            return NULL;

                                                        }

                                                        for (size_t g = 0; g < serversGroupCount; g++) {
                                                            headerCustomServerGroupCopy[g].listInStreamSettingsWSFinalMaskHeaderCustomPacketStruct = NULL;
                                                            headerCustomServerGroupCopy[g].jsonListInboundStreamSettingsWSFinalMaskHeaderCustomPacketStructSize = 0;

                                                        }

                                                        for (size_t g = 0; g < serversGroupCount; g++) {
                                                            cJSON* serverGroupItem = cJSON_GetArrayItem(serversGroupArr, g);
                                                            size_t serverPacketCount = cJSON_GetArraySize(serverGroupItem);
                                                            struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomPacketObjectStruct* headerCustomServerPacketCopy = (struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomPacketObjectStruct*)malloc((serverPacketCount ? serverPacketCount : 1) * sizeof(struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomPacketObjectStruct));
                                                            if (!headerCustomServerPacketCopy) {
                                                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "headerCustomServerPacketCopy is a null pointer, failed to allocate space");

                                                                jsonListInboundStreamSettingsWSFinalMaskObjectStructDelete(wsFinalMaskStruct);

                                                                streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                                                                jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                                inboundObj->listInStreamSettingsObjStruct = NULL;
                                                                inboundObj->listInSniffingObjStruct = NULL;
                                                                jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                                jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                                listInStruct->listInObjStruct = NULL;
                                                                jsonListInboundStructDelete(listInStruct);

                                                                cJSON_Delete(jsonParser);

                                                                return NULL;

                                                            }

                                                            for (size_t c = 0; c < serverPacketCount; c++) {
                                                                headerCustomServerPacketCopy[c].type = NULL;
                                                                headerCustomServerPacketCopy[c].delay = NULL;
                                                                headerCustomServerPacketCopy[c].rand = NULL;
                                                                headerCustomServerPacketCopy[c].randRange = NULL;
                                                                headerCustomServerPacketCopy[c].packet = NULL;

                                                            }

                                                            for (size_t c = 0; c < serverPacketCount; c++) {
                                                                cJSON* serverPacketItem = cJSON_GetArrayItem(serverGroupItem, c);

                                                                if (
                                                                    cJSON_HasObjectItem(serverPacketItem, "type") &&
                                                                    cJSON_IsString(cJSON_GetObjectItem(serverPacketItem, "type"))
                                                                   ) {
                                                                    char* serverPacketType = cJSON_GetObjectItem(serverPacketItem, "type")->valuestring;
                                                                    size_t serverPacketTypeLen = strlen(serverPacketType);
                                                                    char* serverPacketTypeCopy = (char*)malloc((serverPacketTypeLen + 1) * sizeof(char));
                                                                    strncpy(serverPacketTypeCopy, serverPacketType, serverPacketTypeLen);
                                                                    serverPacketTypeCopy[serverPacketTypeLen] = '\0';
                                                                    headerCustomServerPacketCopy[c].type = serverPacketTypeCopy;

                                                                }

                                                                if (
                                                                    cJSON_HasObjectItem(serverPacketItem, "delay") &&
                                                                    cJSON_IsString(cJSON_GetObjectItem(serverPacketItem, "delay"))
                                                                   ) {
                                                                    char* serverPacketDelay = cJSON_GetObjectItem(serverPacketItem, "delay")->valuestring;
                                                                    size_t serverPacketDelayLen = strlen(serverPacketDelay);
                                                                    char* serverPacketDelayCopy = (char*)malloc((serverPacketDelayLen + 1) * sizeof(char));
                                                                    strncpy(serverPacketDelayCopy, serverPacketDelay, serverPacketDelayLen);
                                                                    serverPacketDelayCopy[serverPacketDelayLen] = '\0';
                                                                    headerCustomServerPacketCopy[c].delay = serverPacketDelayCopy;

                                                                }

                                                                if (
                                                                    cJSON_HasObjectItem(serverPacketItem, "rand") &&
                                                                    cJSON_IsString(cJSON_GetObjectItem(serverPacketItem, "rand"))
                                                                   ) {
                                                                    char* serverPacketRand = cJSON_GetObjectItem(serverPacketItem, "rand")->valuestring;
                                                                    size_t serverPacketRandLen = strlen(serverPacketRand);
                                                                    char* serverPacketRandCopy = (char*)malloc((serverPacketRandLen + 1) * sizeof(char));
                                                                    strncpy(serverPacketRandCopy, serverPacketRand, serverPacketRandLen);
                                                                    serverPacketRandCopy[serverPacketRandLen] = '\0';
                                                                    headerCustomServerPacketCopy[c].rand = serverPacketRandCopy;

                                                                }

                                                                if (
                                                                    cJSON_HasObjectItem(serverPacketItem, "randRange") &&
                                                                    cJSON_IsString(cJSON_GetObjectItem(serverPacketItem, "randRange"))
                                                                   ) {
                                                                    char* serverPacketRandRange = cJSON_GetObjectItem(serverPacketItem, "randRange")->valuestring;
                                                                    size_t serverPacketRandRangeLen = strlen(serverPacketRandRange);
                                                                    char* serverPacketRandRangeCopy = (char*)malloc((serverPacketRandRangeLen + 1) * sizeof(char));
                                                                    strncpy(serverPacketRandRangeCopy, serverPacketRandRange, serverPacketRandRangeLen);
                                                                    serverPacketRandRangeCopy[serverPacketRandRangeLen] = '\0';
                                                                    headerCustomServerPacketCopy[c].randRange = serverPacketRandRangeCopy;

                                                                }

                                                                if (
                                                                    cJSON_HasObjectItem(serverPacketItem, "packet") &&
                                                                    cJSON_IsString(cJSON_GetObjectItem(serverPacketItem, "packet"))
                                                                   ) {
                                                                    char* serverPacketVal = cJSON_GetObjectItem(serverPacketItem, "packet")->valuestring;
                                                                    size_t serverPacketLen = strlen(serverPacketVal);
                                                                    char* serverPacketCopy = (char*)malloc((serverPacketLen + 1) * sizeof(char));
                                                                    strncpy(serverPacketCopy, serverPacketVal, serverPacketLen);
                                                                    serverPacketCopy[serverPacketLen] = '\0';
                                                                    headerCustomServerPacketCopy[c].packet = serverPacketCopy;

                                                                }

                                                            }

                                                            headerCustomServerGroupCopy[g].listInStreamSettingsWSFinalMaskHeaderCustomPacketStruct = headerCustomServerPacketCopy;
                                                            headerCustomServerGroupCopy[g].jsonListInboundStreamSettingsWSFinalMaskHeaderCustomPacketStructSize = serverPacketCount;

                                                        }

                                                        tcpHeaderCustomStruct->listInStreamSettingsWSFinalMaskHeaderCustomServerGroupStruct = headerCustomServerGroupCopy;
                                                        tcpHeaderCustomStruct->jsonListInboundStreamSettingsWSFinalMaskHeaderCustomServerGroupStructSize = serversGroupCount;

                                                    }

                                                    break;

                                                case TCPMASKTYPE_SUDOKU:
                                                    wsStruct->listInStreamSettingsWSFinalMaskSudokuObjStruct = (struct jsonListInboundStreamSettingsWSFinalMaskSudokuObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsWSFinalMaskSudokuObjectStruct));
                                                    if (!wsStruct->listInStreamSettingsWSFinalMaskSudokuObjStruct) {
                                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsWSFinalMaskSudokuObjStruct is a null pointer, failed to allocate space");

                                                        jsonListInboundStreamSettingsWSFinalMaskObjectStructDelete(wsFinalMaskStruct);

                                                        streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                                        inboundObj->listInSniffingObjStruct = NULL;
                                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                        listInStruct->listInObjStruct = NULL;
                                                        jsonListInboundStructDelete(listInStruct);

                                                        cJSON_Delete(jsonParser);

                                                        return NULL;

                                                    }

                                                    struct jsonListInboundStreamSettingsWSFinalMaskSudokuObjectStruct* sudokuStruct = wsStruct->listInStreamSettingsWSFinalMaskSudokuObjStruct;
                                                    sudokuStruct->password = NULL;
                                                    sudokuStruct->customTables = NULL;
                                                    sudokuStruct->customTablesCount = 0;
                                                    sudokuStruct->ascii = NULL;
                                                    sudokuStruct->customTable = NULL;
                                                    sudokuStruct->paddingMin = 0;
                                                    sudokuStruct->paddingMax = 0;

                                                    if (
                                                        cJSON_HasObjectItem(wsMaskSettingsObj, "password") &&
                                                        cJSON_IsString(cJSON_GetObjectItem(wsMaskSettingsObj, "password"))
                                                       ) {
                                                        char* sudokuPassword = cJSON_GetObjectItem(wsMaskSettingsObj, "password")->valuestring;
                                                        size_t sudokuPasswordLen = strlen(sudokuPassword);
                                                        char* sudokuPasswordCopy = (char*)malloc((sudokuPasswordLen + 1) * sizeof(char));
                                                        strncpy(sudokuPasswordCopy, sudokuPassword, sudokuPasswordLen);
                                                        sudokuPasswordCopy[sudokuPasswordLen] = '\0';
                                                        sudokuStruct->password = sudokuPasswordCopy;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(wsMaskSettingsObj, "customTables") &&
                                                        cJSON_IsArray(cJSON_GetObjectItem(wsMaskSettingsObj, "customTables"))
                                                       ) {
                                                        cJSON* sudokuCustomTablesObj = cJSON_GetObjectItem(wsMaskSettingsObj, "customTables");
                                                        size_t sudokuCustomTablesCount = cJSON_GetArraySize(sudokuCustomTablesObj);
                                                        const char** sudokuCustomTablesCopy = (const char**)malloc((sudokuCustomTablesCount ? sudokuCustomTablesCount : 1) * sizeof(char*));
                                                        if (!sudokuCustomTablesCopy) {
                                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "sudokuCustomTablesCopy is a null pointer, failed to allocate space");

                                                            jsonListInboundStreamSettingsWSFinalMaskObjectStructDelete(wsFinalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                                            inboundObj->listInSniffingObjStruct = NULL;
                                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                            listInStruct->listInObjStruct = NULL;
                                                            jsonListInboundStructDelete(listInStruct);

                                                            cJSON_Delete(jsonParser);

                                                            return NULL;

                                                        }

                                                        for (size_t customTableIdx = 0; customTableIdx < sudokuCustomTablesCount; customTableIdx++) {
                                                            char* sudokuCustomTableItem = cJSON_GetArrayItem(sudokuCustomTablesObj, customTableIdx)->valuestring;
                                                            size_t sudokuCustomTableItemLen = strlen(sudokuCustomTableItem);
                                                            char* sudokuCustomTableItemCopy = (char*)malloc((sudokuCustomTableItemLen + 1) * sizeof(char));
                                                            strncpy(sudokuCustomTableItemCopy, sudokuCustomTableItem, sudokuCustomTableItemLen);
                                                            sudokuCustomTableItemCopy[sudokuCustomTableItemLen] = '\0';
                                                            sudokuCustomTablesCopy[customTableIdx] = sudokuCustomTableItemCopy;

                                                        }
                                                        sudokuStruct->customTables = sudokuCustomTablesCopy;
                                                        sudokuStruct->customTablesCount = (int64_t)sudokuCustomTablesCount;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(wsMaskSettingsObj, "ascii") &&
                                                        cJSON_IsString(cJSON_GetObjectItem(wsMaskSettingsObj, "ascii"))
                                                       ) {
                                                        char* sudokuAscii = cJSON_GetObjectItem(wsMaskSettingsObj, "ascii")->valuestring;
                                                        size_t sudokuAsciiLen = strlen(sudokuAscii);
                                                        char* sudokuAsciiCopy = (char*)malloc((sudokuAsciiLen + 1) * sizeof(char));
                                                        strncpy(sudokuAsciiCopy, sudokuAscii, sudokuAsciiLen);
                                                        sudokuAsciiCopy[sudokuAsciiLen] = '\0';
                                                        sudokuStruct->ascii = sudokuAsciiCopy;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(wsMaskSettingsObj, "customTable") &&
                                                        cJSON_IsString(cJSON_GetObjectItem(wsMaskSettingsObj, "customTable"))
                                                       ) {
                                                        char* sudokuCustomTable = cJSON_GetObjectItem(wsMaskSettingsObj, "customTable")->valuestring;
                                                        size_t sudokuCustomTableLen = strlen(sudokuCustomTable);
                                                        char* sudokuCustomTableCopy = (char*)malloc((sudokuCustomTableLen + 1) * sizeof(char));
                                                        strncpy(sudokuCustomTableCopy, sudokuCustomTable, sudokuCustomTableLen);
                                                        sudokuCustomTableCopy[sudokuCustomTableLen] = '\0';
                                                        sudokuStruct->customTable = sudokuCustomTableCopy;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(wsMaskSettingsObj, "paddingMin") &&
                                                        cJSON_IsNumber(cJSON_GetObjectItem(wsMaskSettingsObj, "paddingMin"))
                                                       ) {
                                                        sudokuStruct->paddingMin = (int64_t)cJSON_GetObjectItem(wsMaskSettingsObj, "paddingMin")->valuedouble;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(wsMaskSettingsObj, "paddingMax") &&
                                                        cJSON_IsNumber(cJSON_GetObjectItem(wsMaskSettingsObj, "paddingMax"))
                                                       ) {
                                                        sudokuStruct->paddingMax = (int64_t)cJSON_GetObjectItem(wsMaskSettingsObj, "paddingMax")->valuedouble;

                                                    }

                                                    break;

                                                case TCPMASKTYPE_XMC:
                                                    wsStruct->listInStreamSettingsWSFinalMaskXmcObjStruct = (struct jsonListInboundStreamSettingsWSFinalMaskXmcObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsWSFinalMaskXmcObjectStruct));
                                                    if (!wsStruct->listInStreamSettingsWSFinalMaskXmcObjStruct) {
                                                        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsWSFinalMaskXmcObjStruct is a null pointer, failed to allocate space");

                                                        jsonListInboundStreamSettingsWSFinalMaskObjectStructDelete(wsFinalMaskStruct);

                                                        streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                                                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                        inboundObj->listInStreamSettingsObjStruct = NULL;
                                                        inboundObj->listInSniffingObjStruct = NULL;
                                                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                        listInStruct->listInObjStruct = NULL;
                                                        jsonListInboundStructDelete(listInStruct);

                                                        cJSON_Delete(jsonParser);

                                                        return NULL;

                                                    }

                                                    struct jsonListInboundStreamSettingsWSFinalMaskXmcObjectStruct* xmcStruct = wsStruct->listInStreamSettingsWSFinalMaskXmcObjStruct;
                                                    xmcStruct->hostname = NULL;
                                                    xmcStruct->listInStreamSettingsWSFinalMaskXmcProfileStruct = NULL;
                                                    xmcStruct->jsonListInboundStreamSettingsWSFinalMaskXmcProfileStructSize = 0;
                                                    xmcStruct->password = NULL;

                                                    if (
                                                        cJSON_HasObjectItem(wsMaskSettingsObj, "hostname") &&
                                                        cJSON_IsString(cJSON_GetObjectItem(wsMaskSettingsObj, "hostname"))
                                                       ) {
                                                        char* xmcHostname = cJSON_GetObjectItem(wsMaskSettingsObj, "hostname")->valuestring;
                                                        size_t xmcHostnameLen = strlen(xmcHostname);
                                                        char* xmcHostnameCopy = (char*)malloc((xmcHostnameLen + 1) * sizeof(char));
                                                        strncpy(xmcHostnameCopy, xmcHostname, xmcHostnameLen);
                                                        xmcHostnameCopy[xmcHostnameLen] = '\0';
                                                        xmcStruct->hostname = xmcHostnameCopy;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(wsMaskSettingsObj, "profiles") &&
                                                        cJSON_IsArray(cJSON_GetObjectItem(wsMaskSettingsObj, "profiles"))
                                                       ) {
                                                        cJSON* xmcProfilesObj = cJSON_GetObjectItem(wsMaskSettingsObj, "profiles");
                                                        size_t xmcProfilesCount = cJSON_GetArraySize(xmcProfilesObj);
                                                        struct jsonListInboundStreamSettingsWSFinalMaskXmcProfileObjectStruct* xmcProfilesCopy = (struct jsonListInboundStreamSettingsWSFinalMaskXmcProfileObjectStruct*)malloc((xmcProfilesCount ? xmcProfilesCount : 1) * sizeof(struct jsonListInboundStreamSettingsWSFinalMaskXmcProfileObjectStruct));
                                                        if (!xmcProfilesCopy) {
                                                            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "xmcProfilesCopy is a null pointer, failed to allocate space");

                                                            jsonListInboundStreamSettingsWSFinalMaskObjectStructDelete(wsFinalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsWSFinalMaskObjStruct = NULL;
                                                            jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                                                            inboundObj->listInStreamSettingsObjStruct = NULL;
                                                            inboundObj->listInSniffingObjStruct = NULL;
                                                            jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                                                            jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                                                            listInStruct->listInObjStruct = NULL;
                                                            jsonListInboundStructDelete(listInStruct);

                                                            cJSON_Delete(jsonParser);

                                                            return NULL;

                                                        }

                                                        for (size_t profileIdx = 0; profileIdx < xmcProfilesCount; profileIdx++) {
                                                            xmcProfilesCopy[profileIdx].username = NULL;
                                                            xmcProfilesCopy[profileIdx].uuid = NULL;
                                                            xmcProfilesCopy[profileIdx].texturesValue = NULL;
                                                            xmcProfilesCopy[profileIdx].texturesSignature = NULL;

                                                        }

                                                        for (size_t profileIdx = 0; profileIdx < xmcProfilesCount; profileIdx++) {
                                                            cJSON* xmcProfileItem = cJSON_GetArrayItem(xmcProfilesObj, profileIdx);
                                                            struct jsonListInboundStreamSettingsWSFinalMaskXmcProfileObjectStruct* xmcProfile = &xmcProfilesCopy[profileIdx];

                                                            if (
                                                                cJSON_HasObjectItem(xmcProfileItem, "username") &&
                                                                cJSON_IsString(cJSON_GetObjectItem(xmcProfileItem, "username"))
                                                               ) {
                                                                char* xmcProfileUsername = cJSON_GetObjectItem(xmcProfileItem, "username")->valuestring;
                                                                size_t xmcProfileUsernameLen = strlen(xmcProfileUsername);
                                                                char* xmcProfileUsernameCopy = (char*)malloc((xmcProfileUsernameLen + 1) * sizeof(char));
                                                                strncpy(xmcProfileUsernameCopy, xmcProfileUsername, xmcProfileUsernameLen);
                                                                xmcProfileUsernameCopy[xmcProfileUsernameLen] = '\0';
                                                                xmcProfile->username = xmcProfileUsernameCopy;

                                                            }

                                                            if (
                                                                cJSON_HasObjectItem(xmcProfileItem, "uuid") &&
                                                                cJSON_IsString(cJSON_GetObjectItem(xmcProfileItem, "uuid"))
                                                               ) {
                                                                char* xmcProfileUuid = cJSON_GetObjectItem(xmcProfileItem, "uuid")->valuestring;
                                                                size_t xmcProfileUuidLen = strlen(xmcProfileUuid);
                                                                char* xmcProfileUuidCopy = (char*)malloc((xmcProfileUuidLen + 1) * sizeof(char));
                                                                strncpy(xmcProfileUuidCopy, xmcProfileUuid, xmcProfileUuidLen);
                                                                xmcProfileUuidCopy[xmcProfileUuidLen] = '\0';
                                                                xmcProfile->uuid = xmcProfileUuidCopy;

                                                            }

                                                            if (
                                                                cJSON_HasObjectItem(xmcProfileItem, "texturesValue") &&
                                                                cJSON_IsString(cJSON_GetObjectItem(xmcProfileItem, "texturesValue"))
                                                               ) {
                                                                char* xmcProfileTexturesValue = cJSON_GetObjectItem(xmcProfileItem, "texturesValue")->valuestring;
                                                                size_t xmcProfileTexturesValueLen = strlen(xmcProfileTexturesValue);
                                                                char* xmcProfileTexturesValueCopy = (char*)malloc((xmcProfileTexturesValueLen + 1) * sizeof(char));
                                                                strncpy(xmcProfileTexturesValueCopy, xmcProfileTexturesValue, xmcProfileTexturesValueLen);
                                                                xmcProfileTexturesValueCopy[xmcProfileTexturesValueLen] = '\0';
                                                                xmcProfile->texturesValue = xmcProfileTexturesValueCopy;

                                                            }

                                                            if (
                                                                cJSON_HasObjectItem(xmcProfileItem, "texturesSignature") &&
                                                                cJSON_IsString(cJSON_GetObjectItem(xmcProfileItem, "texturesSignature"))
                                                               ) {
                                                                char* xmcProfileTexturesSignature = cJSON_GetObjectItem(xmcProfileItem, "texturesSignature")->valuestring;
                                                                size_t xmcProfileTexturesSignatureLen = strlen(xmcProfileTexturesSignature);
                                                                char* xmcProfileTexturesSignatureCopy = (char*)malloc((xmcProfileTexturesSignatureLen + 1) * sizeof(char));
                                                                strncpy(xmcProfileTexturesSignatureCopy, xmcProfileTexturesSignature, xmcProfileTexturesSignatureLen);
                                                                xmcProfileTexturesSignatureCopy[xmcProfileTexturesSignatureLen] = '\0';
                                                                xmcProfile->texturesSignature = xmcProfileTexturesSignatureCopy;

                                                            }

                                                        }

                                                        xmcStruct->listInStreamSettingsWSFinalMaskXmcProfileStruct = xmcProfilesCopy;
                                                        xmcStruct->jsonListInboundStreamSettingsWSFinalMaskXmcProfileStructSize = (int64_t)xmcProfilesCount;

                                                    }

                                                    if (
                                                        cJSON_HasObjectItem(wsMaskSettingsObj, "password") &&
                                                        cJSON_IsString(cJSON_GetObjectItem(wsMaskSettingsObj, "password"))
                                                       ) {
                                                        char* xmcPassword = cJSON_GetObjectItem(wsMaskSettingsObj, "password")->valuestring;
                                                        size_t xmcPasswordLen = strlen(xmcPassword);
                                                        char* xmcPasswordCopy = (char*)malloc((xmcPasswordLen + 1) * sizeof(char));
                                                        strncpy(xmcPasswordCopy, xmcPassword, xmcPasswordLen);
                                                        xmcPasswordCopy[xmcPasswordLen] = '\0';
                                                        xmcStruct->password = xmcPasswordCopy;

                                                    }

                                                    break;

                                                default:
                                                    break;

                                            }

                                        }

                                    }

                                }

                            }

                        }

                        break;

                    case NETWORKTYPE_GRPC:

                    case NETWORKTYPE_HTTPUPGRADE:

                    case NETWORKTYPE_XHTTP:

                    default:

                        streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;

                }

                cJSON* sockOptObj = cJSON_GetObjectItem(streamSettingsObj, "sockopt");
                if (
                    sockOptObj &&
                    cJSON_IsObject(sockOptObj)
                   ) {
                    if (jsonListInboundStreamSettingsSockoptParse(sockOptObj, streamSettingsStruct, nType) == 0) {
                        jsonListInboundStreamSettingsObjectStructDelete(streamSettingsStruct);

                        inboundObj->listInStreamSettingsObjStruct = NULL;
                        inboundObj->listInSniffingObjStruct = NULL;
                        jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                        jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                        listInStruct->listInObjStruct = NULL;
                        jsonListInboundStructDelete(listInStruct);

                        cJSON_Delete(jsonParser);

                        return NULL;

                    }

                }

                inboundObj->listInSniffingObjStruct = (struct jsonListInboundSniffingObjectStruct*)malloc(sizeof(struct jsonListInboundSniffingObjectStruct));
                if (!inboundObj->listInSniffingObjStruct) {
                    applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInSniffingObjStruct is a null pointer, failed to allocate space");

                    inboundObj->listInSniffingObjStruct = NULL;
                    jsonListInboundObjectStructDeleteElement(&listInStruct->listInObjStruct[i]);

                    jsonListInboundObjectStructDelete(listInStruct->listInObjStruct, i);

                    listInStruct->listInObjStruct = NULL;
                    jsonListInboundStructDelete(listInStruct);

                    cJSON_Delete(jsonParser);

                    return NULL;

                }

                struct jsonListInboundSniffingObjectStruct* sniffingStruct = inboundObj->listInSniffingObjStruct;
                cJSON* sniffingObj = cJSON_GetObjectItem(arrItem, "sniffing");
                cJSON* sniffingEnabledObj = sniffingObj ? cJSON_GetObjectItem(sniffingObj, "enabled") : NULL;
                if (sniffingEnabledObj && cJSON_IsBool(sniffingEnabledObj)) {
                    const char* enabledValue = cJSON_IsTrue(sniffingEnabledObj) ? "true" : "false";
                    size_t enabledLen = strlen(enabledValue);
                    char* enabledCopy = (char*)malloc((enabledLen + 1) * sizeof(char));
                    strncpy(enabledCopy, enabledValue, enabledLen);
                    enabledCopy[enabledLen] = '\0';
                    sniffingStruct->enabled = enabledCopy;

                } else if (sniffingEnabledObj && cJSON_IsString(sniffingEnabledObj) && cJSON_GetObjectItem(sniffingObj, "enabled")->valuestring) {
                    char* enabledValue = cJSON_GetObjectItem(sniffingObj, "enabled")->valuestring;
                    size_t enabledLen = strlen(enabledValue);
                    char* enabledCopy = (char*)malloc((enabledLen + 1) * sizeof(char));
                    strncpy(enabledCopy, enabledValue, enabledLen);
                    enabledCopy[enabledLen] = '\0';
                    sniffingStruct->enabled = enabledCopy;

                } else {
                    sniffingStruct->enabled = NULL;

                }

            } else {
                applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Some item is not present in the array elelement, skipping the element...");

                inboundObj->remark = NULL;
                inboundObj->trafficReset = NULL;
                inboundObj->listInCliStatsStruct = NULL;
                inboundObj->listen = NULL;
                inboundObj->protocol = NULL;
                inboundObj->tag = NULL;
                inboundObj->shareAddrStrategy = NULL;
                inboundObj->shareAddr = NULL;
                inboundObj->originNodeGuid = NULL;
                inboundObj->listInSettingsObjStruct = NULL;
                inboundObj->listInStreamSettingsObjStruct = NULL;
                inboundObj->listInSniffingObjStruct = NULL;

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
