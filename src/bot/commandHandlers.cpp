#include "../../include/bot/commandHandlers.hpp"
#include "../../include/bot/userInfoLoader.hpp"
#include "../../include/structs.h"
#include "../../include/log.h"

#include <stdio.h>
#include <tgbot/tgbot.h>

void startCommandHandler::handle(TgBot::Message::Ptr messagePtr) {
    struct userInfoStruct* uInfo = userInfoLoader::loadInfo(messagePtr->chat->id);
    if (!uInfo) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Failed to load user info from database");

        return;

    }

    if (uInfo->banned) {
        try {
            bot->getApi().sendMessage(
                    uInfo->userId,
                    aConfig->aMessages->bannedMessage,
                    nullptr,
                    nullptr,
                    nullptr
            );

            return;

        } catch (const TgBot::TgException& e) {
            char b[516];
            snprintf(b, sizeof(b), "Failed to send message: %s", e.what());

            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, b);

            return;

        }

    }



}

