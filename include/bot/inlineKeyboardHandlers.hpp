#ifndef INLINE_KEYBOARD_HANDLERS_BOT_TELEGRAM_XUI_BOT
#define INLINE_KEYBOARD_HANDLERS_BOT_TELEGRAM_XUI_BOT

#include "./handlers.hpp"

class multiLocationServiceListIKHandler : inlineKeyboardHandler {
public:
    void handle(TgBot::CallbackQuery::Ptr cBQueryPtr) override;

};

class tunnelServiceListIKHandler : inlineKeyboardHandler {
public:
    void handle(TgBot::CallbackQuery::Ptr cBQueryPtr) override;

};

class singleLocationServiceListIKHandler : inlineKeyboardHandler {
public:
    void handle(TgBot::CallbackQuery::Ptr cBQueryPtr) override;

};

#endif /* INLINE_KEYBOARD_HANDLERS_BOT_TELEGRAM_XUI_BOT */

