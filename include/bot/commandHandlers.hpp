#ifndef COMMAND_HANDLERS_BOT_TELEGRAM_XUI_BOT
#define COMMAND_HANDLERS_BOT_TELEGRAM_XUI_BOT

#include "./handlers.hpp"

class startCommandHandler : private commandHandler {
public:
    void handle(TgBot::Message::Ptr messagePtr) override;

};

#endif /* COMMAND_HANDLERS_BOT_TELEGRAM_XUI_BOT */

