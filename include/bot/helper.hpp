#ifndef HELPER_TELEGRAM_XUI_BOT
#define HELPER_TELEGRAM_XUI_BOT

#include "./interface.hpp"

class botHelper : private iBot {
public:
    template<typename... Args>
    TgBot::Message::Ptr sendMessage(Args&&... args);

    template<typename... Args>
    TgBot::Message::Ptr forwardMessage(Args&&... args);

};

#endif /* HELPER_TELEGRAM_XUI_BOT */

