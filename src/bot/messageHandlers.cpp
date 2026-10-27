#include "../../include/bot/messageHandlers.hpp"
#include "../../include/bot/userInfoLoader.hpp"
#include "../../include/bot/helper.hpp"
#include "../../include/structs.h"
#include "../../include/log.h"

#include "../../include/curl.h"
#include "../../include/cjson.h"

#include <tgbot/tgbot.h>

void listProductsMessageHandler::handle(TgBot::Message::Ptr messagePtr) {
    struct userInfoStruct* uInfo = userInfoLoader::loadInfo(messagePtr->chat->id);
    if (!uInfo) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Failed to load user info from database(s)");

        return;

    }

    uInfo->rUserInfo->cState = CS_IDLE;

    botHelper helper;

    for (int i = 0; i < panels->panelsCount; i++) {
        char b[216];
        snprintf(b, sizeof(b), "Authorization: Bearer %s", panels->pInfoStructs[i].apiKey);
        struct curl_slist headers;
        curl_slist_append(&headers, "Content-Type: application/json");
        curl_slist_append(&headers, b);

        const char* json = curlGetUrlWHeaders(panels->pInfoStructs[i].accessUrl, &headers);

        struct jsonServerStatusResponseStruct* serverStatusRStruct = jsonServerStatusResponse(json);
        if (!serverStatusRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverStatusRStruct is a null pointer");

            return;

        }



    }

}

