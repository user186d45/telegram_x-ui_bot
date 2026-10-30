#include "../../include/bot/inlineKeyboardHandlers.hpp"
#include "../../include/bot/userInfoLoader.hpp"
#include "../../include/bot/helper.hpp"
#include "../../include/structs.h"
#include "../../include/log.h"

#include <tgbot/tgbot.h>

void multiLocationServiceListIKHandler::handle(TgBot::CallbackQuery::Ptr cBQueryPtr) {
    struct userInfoStruct* uInfo = userInfoLoader::loadInfo(cBQueryPtr->from->id);
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

    char messageText[2048];
    snprintf(
        messageText,
        sizeof(messageText),
        "%s\n"
        "1GB = %i",
        aConfig->aMessages->multiLocationServicePriceText,
        aConfig->prices->multiLocationServicePrice
    );

    helper.sendMessage(uInfo->userId, messageText);

    uInfo->rUserInfo->cState = CS_GET_CUSTOM_TRAFFIC_MULTILOCATION_SERVICE;

    userInfoStructDelete(uInfo);

}

void tunnelServiceListIKHandler::handle(TgBot::CallbackQuery::Ptr cBQueryPtr) {
    struct userInfoStruct* uInfo = userInfoLoader::loadInfo(cBQueryPtr->from->id);
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

    char messageText[2048];
    snprintf(
        messageText,
        sizeof(messageText),
        "%s\n"
        "1GB = %i",
        aConfig->aMessages->tunnelServicePriceText,
        aConfig->prices->tunnelServicePrice
    );

    helper.sendMessage(uInfo->userId, messageText);

    uInfo->rUserInfo->cState = CS_GET_CUSTOM_TRAFFIC_TUNNEL_SERVICE;

    userInfoStructDelete(uInfo);

}

void singleLocationServiceListIKHandler::handle(TgBot::CallbackQuery::Ptr cBQueryPtr) {
    struct userInfoStruct* uInfo = userInfoLoader::loadInfo(cBQueryPtr->from->id);
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

    char messageText[2048];
    snprintf(
        messageText,
        sizeof(messageText),
        "%s\n"
        "1GB = %i",
        aConfig->aMessages->singleLocationServicePriceText,
        aConfig->prices->singleLocationServicePrice
    );

    helper.sendMessage(uInfo->userId, messageText);

    uInfo->rUserInfo->cState = CS_GET_CUSTOM_TRAFFIC_SINGLELOCATION_SERVICE;

    userInfoStructDelete(uInfo);

}

