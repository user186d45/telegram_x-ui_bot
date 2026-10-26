#ifndef INTERFACE_BOT_TELEGRAM_XUI_BOT
#define INTERFACE_BOT_TELEGRAM_XUI_BOT

#include <tgbot/tgbot.h>

class iBot {
public:
    iBot();

protected:
    TgBot::Bot* bot;

};

#endif /* INTERFACE_BOT_TELEGRAM_XUI_BOT */

