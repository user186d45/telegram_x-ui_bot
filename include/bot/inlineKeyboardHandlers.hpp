#ifndef INLINE_KEYBOARD_HANDLERS_BOT_TELEGRAM_XUI_BOT
#define INLINE_KEYBOARD_HANDLERS_BOT_TELEGRAM_XUI_BOT

#include "./handlers.hpp"

class multiLocationServiceListIKHandler : private inlineKeyboardHandler {
public:
    void handle(TgBot::CallbackQuery::Ptr cBQueryPtr) override;

};

class tunnelServiceListIKHandler : private inlineKeyboardHandler {
public:
    void handle(TgBot::CallbackQuery::Ptr cBQueryPtr) override;

};

class singleLocationServiceListIKHandler : private inlineKeyboardHandler {
public:
    void handle(TgBot::CallbackQuery::Ptr cBQueryPtr) override;

};

class buyServiceIKHandler : private inlineKeyboardHandler {
public:
    void handle(TgBot::CallbackQuery::Ptr cBQueryPtr) override;

};

#endif /* INLINE_KEYBOARD_HANDLERS_BOT_TELEGRAM_XUI_BOT */

