#ifndef USER_INFO_LOADER_BOT_TELEGRAM_XUI_BOT
#define USER_INFO_LOADER_BOT_TELEGRAM_XUI_BOT

#include "./interface.hpp"
#include "../structs.h"

class userInfoLoader : private iBot {
public:
    static struct userInfoStruct* loadInfo(int64_t userId);

};

#endif /* USER_INFO_LOADER_BOT_TELEGRAM_XUI_BOT */

