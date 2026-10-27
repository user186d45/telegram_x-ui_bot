#ifndef MESSAGE_HANDLERS_BOT_TELEGRAM_XUI_BOT
#define MESSAGE_HANDLERS_BOT_TELEGRAM_XUI_BOT

#include "./handlers.hpp"

class listProductsMessageHandler : private messageHandler {
public:
    void handle(TgBot::Message::Ptr messagePtr) override;

};

#endif /* MESSAGE_HANDLERS_BOT_TELEGRAM_XUI_BOT */

