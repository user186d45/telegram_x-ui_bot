#include "../../include/bot/commandHandlers.hpp"
#include "../../include/bot/userInfoLoader.hpp"
#include "../../include/bot/helper.hpp"
#include "../../include/structs.h"
#include "../../include/log.h"

#include <tgbot/tgbot.h>
#include <vector>

void startCommandHandler::handle(TgBot::Message::Ptr messagePtr) {
    DBG(LOG_INFO, "Function called");

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

        free((char*)uInfo->phoneNumber);
        free(uInfo);

        return;

    }

    TgBot::ReplyKeyboardMarkup::Ptr rKeyboardMarkup(new TgBot::ReplyKeyboardMarkup());

    std::vector<TgBot::KeyboardButton::Ptr> row0;

    TgBot::KeyboardButton::Ptr productsListButton(new TgBot::KeyboardButton);
    productsListButton->text = aConfig->aButtonTexts->productsListsText;
    row0.push_back(productsListButton);


    TgBot::KeyboardButton::Ptr profileButton(new TgBot::KeyboardButton);
    profileButton->text = aConfig->aButtonTexts->profileText;
    row0.push_back(profileButton);

    rKeyboardMarkup->keyboard.push_back(row0);

    std::vector<TgBot::KeyboardButton::Ptr> row1;

    TgBot::KeyboardButton::Ptr depositButton(new TgBot::KeyboardButton);
    depositButton->text = aConfig->aButtonTexts->depositText;
    row1.push_back(depositButton);


    TgBot::KeyboardButton::Ptr supportButton(new TgBot::KeyboardButton);
    supportButton->text = aConfig->aButtonTexts->supportText;
    row1.push_back(supportButton);

    rKeyboardMarkup->keyboard.push_back(row1);

    unsigned char isAdmin = 0;
    for (int i = 0; i < aConfig->adminsCount; i++) {
        if (aConfig->admins[i] == uInfo->userId) {
            isAdmin = 1;

        }

    }

    if (isAdmin) {
        std::vector<TgBot::KeyboardButton::Ptr> row2;

        TgBot::KeyboardButton::Ptr adminPanelButton(new TgBot::KeyboardButton);
        adminPanelButton->text = aConfig->aButtonTexts->adminPanelText;
        row2.push_back(adminPanelButton);

        rKeyboardMarkup->keyboard.push_back(row2);

    }

    helper.sendMessage(
            uInfo->userId,
            aConfig->aMessages->welcomeMessage,
            nullptr,
            nullptr,
            rKeyboardMarkup
    );

    free((char*)uInfo->phoneNumber);
    free(uInfo);

}

