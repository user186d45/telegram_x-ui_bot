#include "../../include/bot/helper.hpp"
#include "../../include/log.h"

template<typename... Args>
TgBot::Message::Ptr botHelper::sendMessage(Args&&... args) {
    try {
        return bot->getApi().sendMessage(std::forward<Args>(args)...);

    } catch (const TgBot::TgException& e) {
        char b[516];
        snprintf(b, sizeof(b), "Failed to send message: %s", e.what());

        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, b);

        return nullptr;

    }

}

