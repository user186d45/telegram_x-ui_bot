#ifndef BOT_TELEGRAM_XUI_BOT
#define BOT_TELEGRAM_XUI_BOT

#include <tgbot/tgbot.h>

class iBot {
public:
    virtual void updateUserInfoFromMessage(TgBot::Message::Ptr messagePtr) = 0;
    virtual void updateUserInfoFromCallback(TgBot::CallbackQuery::Ptr cBQueryPtr) = 0;

};

class commandHandler : public iBot {

};

class messageHandler : public iBot {

};

class inlineKeyboardHandler : public iBot {

};

#endif /* BOT_TELEGRAM_XUI_BOT */

