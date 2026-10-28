#ifndef HELPER_TELEGRAM_XUI_BOT
#define HELPER_TELEGRAM_XUI_BOT

#include "./interface.hpp"

#include <inttypes.h>

class botHelper : private iBot {
public:
    template<typename... Args>
    TgBot::Message::Ptr sendMessage(Args&&... args);

    template<typename... Args>
    TgBot::Message::Ptr forwardMessage(Args&&... args);

    unsigned char deleteMessage(int64_t chatId, int32_t messageId);

};

#endif /* HELPER_TELEGRAM_XUI_BOT */

