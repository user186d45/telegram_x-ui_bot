#ifndef HANDLERS_BOT_TELEGRAM_XUI_BOT
#define HANDLERS_BOT_TELEGRAM_XUI_BOT

#include "./interface.hpp"

class commandHandler : protected iBot {
public:
    virtual void handle(TgBot::Message::Ptr messagePtr) = 0;

};

class messageHandler : protected iBot {
public:
    virtual void handle(TgBot::Message::Ptr messagePtr) = 0;

};

class inlineKeyboardHandler : protected iBot {
public:
    virtual void handle(TgBot::CallbackQuery::Ptr cBQueryPtr) = 0;

};

#endif /* HANDLERS_BOT_TELEGRAM_XUI_BOT */

