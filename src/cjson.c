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

void jsonListInboundStreamSettingsKcpSettingsObjectStructDelete(struct jsonListInboundStreamSettingsKcpSettingsObjectStruct* listInStreamSettingsKcpSettingsObjStruct) {
    free(listInStreamSettingsKcpSettingsObjStruct);

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

void jsonListInboundStreamSettingsFinalMaskObjectStructDelete(struct jsonListInboundStreamSettingsFinalMaskObjectStruct* listInStreamSettingsFinalMaskObjStruct) {
    for (size_t i = 0; i < listInStreamSettingsFinalMaskObjStruct->jsonListInboundStreamSettingsFinalMaskUdpStructSize; i++) {
        struct jsonListInboundStreamSettingsFinalMaskUdpObjectStruct* finalMaskUdp = &listInStreamSettingsFinalMaskObjStruct->listInStreamSettingsFinalMaskUdpStruct[i];
        jsonListInboundStreamSettingsFinalMaskUdpObjectStructDelete(finalMaskUdp);

    }

    free(listInStreamSettingsFinalMaskObjStruct->listInStreamSettingsFinalMaskUdpStruct);

    free(listInStreamSettingsFinalMaskObjStruct);

}

void jsonListInboundStreamSettingsSockoptCustomSockoptObjectStructDelete(struct jsonListInboundStreamSettingsSockoptCustomSockoptObjectStruct* listInStreamSettingsSockoptCustomSockoptObjStruct, size_t arraySize) {
    for (size_t i = 0; i < arraySize; i++) {
        struct jsonListInboundStreamSettingsSockoptCustomSockoptObjectStruct* customSockopt = &listInStreamSettingsSockoptCustomSockoptObjStruct[i];
        free((char*)customSockopt->system);
        free((char*)customSockopt->type);
        free((char*)customSockopt->level);
        free((char*)customSockopt->opt);
        free((char*)customSockopt->value);

    }

    free(listInStreamSettingsSockoptCustomSockoptObjStruct);

}

void jsonListInboundStreamSettingsSockoptObjectStructDelete(struct jsonListInboundStreamSettingsSockoptObjectStruct* listInStreamSettingsSockoptObjStruct) {
    free((char*)listInStreamSettingsSockoptObjStruct->tproxy);
    free((char*)listInStreamSettingsSockoptObjStruct->tcpcongestion);

    if (listInStreamSettingsSockoptObjStruct->listInStreamSettingsSockoptCustomSockoptStruct) {
        jsonListInboundStreamSettingsSockoptCustomSockoptObjectStructDelete(listInStreamSettingsSockoptObjStruct->listInStreamSettingsSockoptCustomSockoptStruct, listInStreamSettingsSockoptObjStruct->jsonListInboundStreamSettingsSockoptCustomSockoptStructSize);
        listInStreamSettingsSockoptObjStruct->listInStreamSettingsSockoptCustomSockoptStruct = NULL;

    }

    free(listInStreamSettingsSockoptObjStruct);

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

    if (listInStreamSettingsObjStruct->listInStreamSettingsKcpSettingsObjStruct) {
        jsonListInboundStreamSettingsKcpSettingsObjectStructDelete(listInStreamSettingsObjStruct->listInStreamSettingsKcpSettingsObjStruct);
        listInStreamSettingsObjStruct->listInStreamSettingsKcpSettingsObjStruct = NULL;

    }

    if (listInStreamSettingsObjStruct->listInStreamSettingsFinalMaskObjStruct) {
        jsonListInboundStreamSettingsFinalMaskObjectStructDelete(listInStreamSettingsObjStruct->listInStreamSettingsFinalMaskObjStruct);
        listInStreamSettingsObjStruct->listInStreamSettingsFinalMaskObjStruct = NULL;

    }

    if (listInStreamSettingsObjStruct->listInStreamSettingsSockoptObjStruct) {
        jsonListInboundStreamSettingsSockoptObjectStructDelete(listInStreamSettingsObjStruct->listInStreamSettingsSockoptObjStruct);
        listInStreamSettingsObjStruct->listInStreamSettingsSockoptObjStruct = NULL;

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
    // sockopt holds the socket options, when real client ip is off/direct the
    // trusted X-Forwarded-For field is always empty, the real client ip field
    // itself is not present in this variant
    // TODO: parse the real client ip field and the trusted X-Forwarded-For
    // field when the json for the other real client ip options gets provided,
    // the allowed options depend on the transmission: the cloudflare cdn
    // option only works with websocket, httpupgrade and xhttp, and the "l4 relay / spectrum ( PROXY )"
    // option only works with tcp, websocket, httpupgrade, grpc and xhttp

    // this json has too many dynamic fields therefore object / array availability is checked after allocating the struct, and on parsing them
    switch (nType) {
        case NETWORKTYPE_TCP:
        {
            streamSettingsStruct->listInStreamSettingsTcpSockoptObjStruct = (struct jsonListInboundStreamSettingsTcpSockoptObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsTcpSockoptObjectStruct));
            if (!streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsTcpSettingsObjStruct is a null pointer, failed to allocate memory");

                streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;

                return 1;

            }

            struct jsonListInboundStreamSettingsTcpSockoptObjectStruct* tcpSocketStruct = streamSettingsStruct->listInStreamSettingsTcpSockoptObjStruct;

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
                        // TODO: define and declare the missing cleaner functions and call them here

                    }

                    for (size_t i = 0; i < customSockoptArrLen; i++) {
                        struct jsonListInboundStreamSettingsTcpSockoptObjectCustomSockOptArrayStruct* customSockOptArrStruct = tcpSocketStruct->listInStreamSettingsTcpSockoptObjCustomScokArrStruct;

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
                    // TODO
                }

            } else {
                // TODO
            }

            // tcp masks remaining

            break;

        }
        case NETWORKTYPE_KCP:
        {
            streamSettingsStruct->listInStreamSettingsMKcpSockoptObjStruct = (struct jsonListInboundStreamSettingsMKcpSockoptObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsMKcpSockoptObjectStruct));
            if (!streamSettingsStruct->listInStreamSettingsMKcpSockoptObjStruct) {
                // TODO

            }

        }
        case NETWORKTYPE_WS:
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
                streamSettingsStruct->listInStreamSettingsKcpSettingsObjStruct = NULL;
                streamSettingsStruct->security = NULL;
                streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = NULL;
                streamSettingsStruct->listInStreamSettingsSockoptObjStruct = NULL;

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

                            streamSettingsStruct->listInStreamSettingsKcpSettingsObjStruct = (struct jsonListInboundStreamSettingsKcpSettingsObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsKcpSettingsObjectStruct));
                            if (!streamSettingsStruct->listInStreamSettingsKcpSettingsObjStruct) {
                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsKcpSettingsObjStruct is a null pointer, failed to allocate space");

                                streamSettingsStruct->listInStreamSettingsKcpSettingsObjStruct = NULL;
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

                            struct jsonListInboundStreamSettingsKcpSettingsObjectStruct* kcpSettingsStruct = streamSettingsStruct->listInStreamSettingsKcpSettingsObjStruct;

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

                            streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = (struct jsonListInboundStreamSettingsFinalMaskObjectStruct*)malloc(sizeof(struct jsonListInboundStreamSettingsFinalMaskObjectStruct));
                            if (!streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct) {
                                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "listInStreamSettingsFinalMaskObjStruct is a null pointer, failed to allocate space");

                                streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = NULL;
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

                            struct jsonListInboundStreamSettingsFinalMaskObjectStruct* finalMaskStruct = streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct;
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

                                    jsonListInboundStreamSettingsFinalMaskObjectStructDelete(finalMaskStruct);

                                    streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = NULL;
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

                                    jsonListInboundStreamSettingsFinalMaskObjectStructDelete(finalMaskStruct);

                                    streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = NULL;
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

                                            jsonListInboundStreamSettingsFinalMaskObjectStructDelete(finalMaskStruct);

                                            streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = NULL;
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

                                                jsonListInboundStreamSettingsFinalMaskObjectStructDelete(finalMaskStruct);

                                                streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = NULL;
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

                                                        jsonListInboundStreamSettingsFinalMaskObjectStructDelete(finalMaskStruct);

                                                        streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = NULL;
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

                                                        jsonListInboundStreamSettingsFinalMaskObjectStructDelete(finalMaskStruct);

                                                        streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = NULL;
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

                                                            jsonListInboundStreamSettingsFinalMaskObjectStructDelete(finalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = NULL;
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

                                                        jsonListInboundStreamSettingsFinalMaskObjectStructDelete(finalMaskStruct);

                                                        streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = NULL;
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
                                                        cJSON_IsNumber(cJSON_GetObjectItem(udpSettingsObj, "dgram"))
                                                       ) {
                                                        xicmpStruct->dgram = (unsigned char)cJSON_GetObjectItem(udpSettingsObj, "dgram")->valuedouble;

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

                                                            jsonListInboundStreamSettingsFinalMaskObjectStructDelete(finalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = NULL;
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

                                                        jsonListInboundStreamSettingsFinalMaskObjectStructDelete(finalMaskStruct);

                                                        streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = NULL;
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

                                                            jsonListInboundStreamSettingsFinalMaskObjectStructDelete(finalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = NULL;
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

                                                            jsonListInboundStreamSettingsFinalMaskObjectStructDelete(finalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = NULL;
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

                                                            jsonListInboundStreamSettingsFinalMaskObjectStructDelete(finalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = NULL;
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

                                                                jsonListInboundStreamSettingsFinalMaskObjectStructDelete(finalMaskStruct);

                                                                streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = NULL;
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

                                                        jsonListInboundStreamSettingsFinalMaskObjectStructDelete(finalMaskStruct);

                                                        streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = NULL;
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

                                                            jsonListInboundStreamSettingsFinalMaskObjectStructDelete(finalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = NULL;
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

                                                            jsonListInboundStreamSettingsFinalMaskObjectStructDelete(finalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = NULL;
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

                                                        jsonListInboundStreamSettingsFinalMaskObjectStructDelete(finalMaskStruct);

                                                        streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = NULL;
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

                                                            jsonListInboundStreamSettingsFinalMaskObjectStructDelete(finalMaskStruct);

                                                            streamSettingsStruct->listInStreamSettingsFinalMaskObjStruct = NULL;
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

                    case NETWORKTYPE_GRPC:

                    case NETWORKTYPE_HTTPUPGRADE:

                    case NETWORKTYPE_XHTTP:

                    default:

                        streamSettingsStruct->listInStreamSettingsTcpSettingsObjStruct = NULL;

                }

                if (jsonListInboundStreamSettingsSockoptParse(streamSettingsObj, streamSettingsStruct, inboundObj, i, listInStruct, jsonParser) == 0) {
                    return NULL;

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

