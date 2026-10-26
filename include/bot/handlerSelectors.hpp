#ifndef HANDLER_SELECTORS_BOT_TELEGRAM_XUI_BOT
#define HANDLER_SELECTORS_BOT_TELEGRAM_XUI_BOT

#include "./interface.hpp"
#include "./handlers.hpp"

class commandHandlerSelector : private iBot {
public:
    commandHandler* selectHandler(TgBot::Message::Ptr messagePtr);

};

class messageHandlerSelector : private iBot {
public:
    messageHandler* selectHandler(TgBot::Message::Ptr messagePtr);

};

class inlineKeyboardHandlerSelector : private iBot {
public:
    inlineKeyboardHandler* selectHandler(TgBot::CallbackQuery::Ptr cBQueryPtr);

};

#endif

