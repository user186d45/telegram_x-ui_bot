#include "../../include/bot/interface.hpp"
#include "../../include/structs.h"
#include "../../include/log.h"

#include <stdio.h>
#include <malloc.h>

iBot::iBot() {
    try {
        bot = new TgBot::Bot(aConfig->botApiKey);

    } catch (std::bad_alloc& e) {
        char b[526];
        snprintf(b, sizeof(b), "Failed to allocate the bot instance: %s", e.what());

        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, b);

    }

}

