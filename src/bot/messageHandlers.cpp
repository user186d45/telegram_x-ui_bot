#include "../../include/bot/messageHandlers.hpp"
#include "../../include/bot/userInfoLoader.hpp"
#include "../../include/bot/helper.hpp"
#include "../../include/structs.h"
#include "../../include/log.h"

#include "../../include/curl.h"
#include "../../include/cjson/server.h"

#include <tgbot/tgbot.h>
#include <inttypes.h>
#include <vector>

void listProductsMessageHandler::handle(TgBot::Message::Ptr messagePtr) {
    struct userInfoStruct* uInfo = userInfoLoader::loadInfo(messagePtr->chat->id);
    if (!uInfo) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Failed to load user info from database(s)");

        return;

    }

    uInfo->rUserInfo->cState = CS_IDLE;

    botHelper helper;

    if (uInfo->banned) {
        helper.sendMessage(
                uInfo->userId,
                aConfig->aMessages->bannedMessage
        );

        userInfoStructDelete(uInfo);

        return;

    }

    TgBot::Message::Ptr message = helper.sendMessage(
            uInfo->userId,
            aConfig->aMessages->loadingServersStatusMessage
    );

    char messageText[1024 * 1024];
    strncpy(messageText, aConfig->aMessages->priceListMessage, sizeof(messageText));
    struct jsonServerStatusResponseStruct* serverStatusRStruct;
    for (int i = 0; i < panels->panelsCount; i++) {
        char b[1024 * 10];
        snprintf(b, sizeof(b), "Authorization: Bearer %s", panels->pInfoStructs[i].apiKey);

        struct curl_slist headers;
        curl_slist_append(&headers, "Content-Type: application/json");
        curl_slist_append(&headers, b);

        snprintf(b, sizeof(b), "%s/api/server/status", panels->pInfoStructs[i].accessUrl);
        const char* json = curlGetUrlWHeaders(b, &headers);
        if (!json) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "json is a null pointer, curl failed");

            userInfoStructDelete(uInfo);

            return;

        }

        serverStatusRStruct = jsonServerStatusResponse(json);
        if (!serverStatusRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "serverStatusRStruct is a null pointer");

            free((char*)json);
            userInfoStructDelete(uInfo);

            return;

        }

        snprintf(
            b,
            sizeof(b),
            "\n"
            "Server: %i (%s)\n"
            "Cpu cores: %" PRId64 " || Ram: %" PRId64 " || Available ram: %" PRId64 " || "
            "Uptime since last restart: %" PRId64 " || Total traffic since last restart: %" PRId64 " || "
            "Cpu clock speed: %" PRId64 "Mhz\n",
            panels->pInfoStructs[i].id,
            panels->pInfoStructs[i].location,
            serverStatusRStruct->srvStatusObjStruct->cpuCores,
            serverStatusRStruct->srvStatusObjStruct->srvStatusObjMemObjStruct->total,
            serverStatusRStruct->srvStatusObjStruct->srvStatusObjMemObjStruct->current,
            serverStatusRStruct->srvStatusObjStruct->uptime,
            serverStatusRStruct->srvStatusObjStruct->srvStatusObjNetTrafficObjStruct->recv + serverStatusRStruct->srvStatusObjStruct->srvStatusObjNetTrafficObjStruct->sent,
            serverStatusRStruct->srvStatusObjStruct->cpuSpeedMhz
        );

        strncat(messageText, b, sizeof(messageText) - strlen(messageText) - 1);

        jsonServerStatusResponseStructDelete(serverStatusRStruct);
        free((char*)json);

    }

    TgBot::InlineKeyboardMarkup::Ptr iKeyboardM(new TgBot::InlineKeyboardMarkup);

    std::vector<TgBot::InlineKeyboardButton::Ptr> row0;

    TgBot::InlineKeyboardButton::Ptr multiLocationServiceButton(new TgBot::InlineKeyboardButton);
    multiLocationServiceButton->text = aConfig->aButtonTexts->multiLocationServiceText;
    multiLocationServiceButton->callbackData = "list multi location services";
    row0.push_back(multiLocationServiceButton);

    iKeyboardM->inlineKeyboard.push_back(row0);

    std::vector<TgBot::InlineKeyboardButton::Ptr> row1;

    TgBot::InlineKeyboardButton::Ptr tunnelServiceButton(new TgBot::InlineKeyboardButton);
    tunnelServiceButton->text = aConfig->aButtonTexts->tunnelServiceText;
    tunnelServiceButton->callbackData = "list tunnel services";
    row1.push_back(tunnelServiceButton);

    iKeyboardM->inlineKeyboard.push_back(row1);

    std::vector<TgBot::InlineKeyboardButton::Ptr> row2;

    TgBot::InlineKeyboardButton::Ptr singleLocationServiceButton(new TgBot::InlineKeyboardButton);
    singleLocationServiceButton->text = aConfig->aButtonTexts->singleLocationServiceText;
    singleLocationServiceButton->callbackData = "list single location services";
    row2.push_back(singleLocationServiceButton);

    iKeyboardM->inlineKeyboard.push_back(row2);

    helper.deleteMessage(uInfo->userId, message->messageId);

    helper.sendMessage(
            uInfo->userId,
            messageText,
            nullptr,
            nullptr,
            iKeyboardM
    );

    userInfoStructDelete(uInfo);

}

void getCustomMultilocationTrafficAmountMessageHandler::handle(TgBot::Message::Ptr messagePtr) {
    struct userInfoStruct* uInfo = userInfoLoader::loadInfo(messagePtr->chat->id);
    if (!uInfo) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Failed to load user info from database(s)");

        return;

    }

    botHelper helper;

    if (uInfo->banned) {
        helper.sendMessage(
                uInfo->userId,
                aConfig->aMessages->bannedMessage
        );

        userInfoStructDelete(uInfo);

        return;

    }

    int orderPrice = aConfig->prices->multiLocationServicePrice * atoi(messagePtr->text.c_str());

    char messageText[1024];
    snprintf(
            messageText,
            sizeof(messageText),
            "%s:\n\n"
            "%i",
            aConfig->aMessages->multiLocationServiceReceiptText,
            orderPrice
    );

    TgBot::InlineKeyboardMarkup::Ptr iKeyboardM(new TgBot::InlineKeyboardMarkup);

    std::vector<TgBot::InlineKeyboardButton::Ptr> row;

    TgBot::InlineKeyboardButton::Ptr buyConfirmButton(new TgBot::InlineKeyboardButton);
    buyConfirmButton->text = aConfig->aButtonTexts->buyConfirmButtonText;

    char b[64];
    if (uInfo->balance >= orderPrice) {
        snprintf(b, sizeof(b), "service buy %i", orderPrice);

    } else {
        snprintf(b, sizeof(b), "Insufficient balance");

    }
    buyConfirmButton->callbackData = b;
    row.push_back(buyConfirmButton);

    iKeyboardM->inlineKeyboard.push_back(row);

    helper.sendMessage(
        uInfo->userId,
        messageText,
        nullptr,
        nullptr,
        iKeyboardM
    );

    userInfoStructDelete(uInfo);

};

void getCustomTunnelTrafficAmountMessageHandler::handle(TgBot::Message::Ptr messagePtr) {
    struct userInfoStruct* uInfo = userInfoLoader::loadInfo(messagePtr->chat->id);
    if (!uInfo) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Failed to load user info from database(s)");

        return;

    }

    botHelper helper;

    if (uInfo->banned) {
        helper.sendMessage(
                uInfo->userId,
                aConfig->aMessages->bannedMessage
        );

        userInfoStructDelete(uInfo);

        return;

    }

    int orderPrice = aConfig->prices->tunnelServicePrice * atoi(messagePtr->text.c_str());

    char messageText[1024];
    snprintf(
            messageText,
            sizeof(messageText),
            "%s:\n\n"
            "%i",
            aConfig->aMessages->tunnelServiceReceiptText,
            orderPrice
    );

    TgBot::InlineKeyboardMarkup::Ptr iKeyboardM(new TgBot::InlineKeyboardMarkup);

    std::vector<TgBot::InlineKeyboardButton::Ptr> row;

    TgBot::InlineKeyboardButton::Ptr buyConfirmButton(new TgBot::InlineKeyboardButton);
    buyConfirmButton->text = aConfig->aButtonTexts->buyConfirmButtonText;

    char b[64];
    if (uInfo->balance >= orderPrice) {
        snprintf(b, sizeof(b), "service buy %i", orderPrice);

    } else {
        snprintf(b, sizeof(b), "Insufficient balance");

    }
    buyConfirmButton->callbackData = b;
    row.push_back(buyConfirmButton);

    iKeyboardM->inlineKeyboard.push_back(row);

    helper.sendMessage(
        uInfo->userId,
        messageText,
        nullptr,
        nullptr,
        iKeyboardM
    );

    userInfoStructDelete(uInfo);

};

void getCustomSingleLocationTrafficAmountMessageHandler::handle(TgBot::Message::Ptr messagePtr) {
    struct userInfoStruct* uInfo = userInfoLoader::loadInfo(messagePtr->chat->id);
    if (!uInfo) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Failed to load user info from database(s)");

        return;

    }

    botHelper helper;

    if (uInfo->banned) {
        helper.sendMessage(
                uInfo->userId,
                aConfig->aMessages->bannedMessage
        );

        userInfoStructDelete(uInfo);

        return;

    }

    int orderPrice = aConfig->prices->singleLocationServicePrice * atoi(messagePtr->text.c_str());

    char messageText[1024];
    snprintf(
            messageText,
            sizeof(messageText),
            "%s:\n\n"
            "%i",
            aConfig->aMessages->singleLocationServiceReceiptText,
            orderPrice
    );

    TgBot::InlineKeyboardMarkup::Ptr iKeyboardM(new TgBot::InlineKeyboardMarkup);

    std::vector<TgBot::InlineKeyboardButton::Ptr> row;

    TgBot::InlineKeyboardButton::Ptr buyConfirmButton(new TgBot::InlineKeyboardButton);
    buyConfirmButton->text = aConfig->aButtonTexts->buyConfirmButtonText;

    char b[64];
    if (uInfo->balance >= orderPrice) {
        snprintf(b, sizeof(b), "service buy %i", orderPrice);

    } else {
        snprintf(b, sizeof(b), "Insufficient balance");

    }
    buyConfirmButton->callbackData = b;
    row.push_back(buyConfirmButton);

    iKeyboardM->inlineKeyboard.push_back(row);

    helper.sendMessage(
        uInfo->userId,
        messageText,
        nullptr,
        nullptr,
        iKeyboardM
    );

    userInfoStructDelete(uInfo);

};

