#include "../../include/bot/inlineKeyboardHandlers.hpp"
#include "../../include/bot/userInfoLoader.hpp"
#include "../../include/bot/helper.hpp"
#include "../../include/sqlite.h"
#include "../../include/structs.h"
#include "../../include/log.h"

#include <tgbot/tgbot.h>

#include <stdio.h>
#include <pcre2.h>

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

void buyServiceIKHandler::handle(TgBot::CallbackQuery::Ptr cBQueryPtr) {
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

    int errorNumber;
    PCRE2_SIZE errorOffset;
    const char* pattern = "/([0-9]) /([0-9]+)";
    pcre2_code* regex = pcre2_compile((PCRE2_SPTR)pattern, PCRE2_ZERO_TERMINATED, 0, &errorNumber, &errorOffset, NULL);
    if (!regex) {
        PCRE2_UCHAR b[256];
        char b2[1024];
        int l = pcre2_get_error_message(errorNumber, b, sizeof(b));
        if (!l) {
            snprintf(b2, sizeof(b2), "Failed compile regex pattern, unknown error: %i at offset %zu", errorNumber, errorOffset);
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, b2);

        } else {
            snprintf(b2, sizeof(b2), "Failed to compile regex pattern: %s, offset: %zu", (char*)b, errorOffset);
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, b2);

        }

        userInfoStructDelete(uInfo);

        return;

    }

    pcre2_match_data* matchData = pcre2_match_data_create_from_pattern(regex, NULL);
    if (!matchData) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "matchData is a null poiner, failed to allocate memory");

        pcre2_code_free(regex);
        userInfoStructDelete(uInfo);

        return;

    }

    int rc = pcre2_match(regex, (PCRE2_SPTR)cBQueryPtr->data.c_str(), cBQueryPtr->data.length(), 0, 0, matchData, NULL);
    if (rc == PCRE2_ERROR_NOMATCH) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "No mathes found in the provided string");

        pcre2_match_data_free(matchData);
        pcre2_code_free(regex);
        userInfoStructDelete(uInfo);

        return;

    } else if (rc < 0) {
        PCRE2_UCHAR b[256];
        char b2[1024];
        int l = pcre2_get_error_message(rc, b, sizeof(b));
        if (l < 0) {
            snprintf(b2, sizeof(b2), "Unknown match error: %i", rc);
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, b2);

            pcre2_match_data_free(matchData);
            pcre2_code_free(regex);
            userInfoStructDelete(uInfo);

            return;

        } else {
            snprintf(b2, sizeof(b2), "Match error: %s", (char*)b);
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, b2);

            pcre2_match_data_free(matchData);
            pcre2_code_free(regex);
            userInfoStructDelete(uInfo);

            return;

        }

    }

    PCRE2_SIZE* ovector = pcre2_get_ovector_pointer(matchData);
    if (!ovector) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "ovector is a null pointer, failed to get ovector pointer");

        pcre2_match_data_free(matchData);
        pcre2_code_free(regex);
        userInfoStructDelete(uInfo);

        return;

    }

    int amount = atoi(cBQueryPtr->data.substr(ovector[3], ovector[4] - ovector[3]).c_str());
    if (uInfo->balance < amount) {
        helper.sendMessage(
                uInfo->userId,
                aConfig->aMessages->insufficientBalanceText,
                nullptr,
                nullptr,
                nullptr
        );

        pcre2_match_data_free(matchData);
        pcre2_code_free(regex);
        userInfoStructDelete(uInfo);

        return;

    }

    uInfo->balance -= amount;
    sqlWriteUserData(uInfo, userDataRWSql_BALANCE);

    char messageText[1024];
    snprintf(messageText, sizeof(messageText), "%s:\n%i", aConfig->aMessages->balanceUpdateSuccessText, uInfo->balance);

    helper.sendMessage(
            uInfo->userId,
            messageText,
            nullptr,
            nullptr,
            nullptr
    );

    int serviceType = atoi(cBQueryPtr->data.substr(ovector[1], ovector[2] - ovector[1]).c_str());
    switch (serviceType) {
        case SERVICES_MULTILOCATION:
        {
            for (size_t i = 0; i < aConfig->mLocationPanles->panelsCount; i++) {

            }

        }
        case SERVICES_TUNNEL:
        case SERVICES_SINGLELOCATION:
        default:
    }

    pcre2_match_data_free(matchData);
    pcre2_code_free(regex);
    userInfoStructDelete(uInfo);

    return;

}

