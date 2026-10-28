#include "../../include/bot/helper.hpp"
#include "../../include/log.h"

template<typename... Args>
TgBot::Message::Ptr botHelper::sendMessage(Args&&... args) {
    TgBot::Message::Ptr message;
    try {
        message =  bot->getApi().sendMessage(std::forward<Args>(args)...);

    } catch (const TgBot::TgException& e) {
        char b[516];
        snprintf(b, sizeof(b), "Failed to send message: %s", e.what());

        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, b);

        return nullptr;

    }

    return message;

}

template<typename... Args>
TgBot::Message::Ptr botHelper::forwardMessage(Args&&... args) {
    TgBot::Message::Ptr message;
    try {
        message =  bot->getApi().forwardMessage(std::forward<Args>(args)...);

    } catch (const TgBot::TgException& e) {
        char b[516];
        snprintf(b, sizeof(b), "Failed to forward message: %s", e.what());

        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, b);

        return nullptr;

    }

    return message;

}

unsigned char botHelper::deleteMessage(int64_t chatId, int32_t messageId) {
    try {
        bot->getApi().deleteMessage(chatId, messageId);

    } catch (const TgBot::TgException& e) {
        char b[516];
        snprintf(b, sizeof(b), "Failed to delete message: %s", e.what());

        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, b);

        return 1;

    }

    return 0;

}

