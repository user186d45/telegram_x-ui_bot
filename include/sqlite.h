#ifndef SQLITE_TELEGRAM_XUI_BOT
#define SQLITE_TELEGRAM_XUI_BOT

#include <stddef.h>
#include <stdint.h>

#include <sqlite3.h>

#include "./structs.h"

enum userDataRWSql : uint8_t {
    userDataRWSql_ALL,
    userDataRWSql_BALANCE,
    userDataRWSql_PHONE_NUMBER,
    userDataRWSql_JOIN_STATE,
    userDataRWSql_BANNED_STATE

};

unsigned char sqlCreateCheckDb();
unsigned char sqlWriteUserData(struct userInfoStruct* uInfo, enum userDataRWSql uDataRWSql);
unsigned char sqlReadUserData(struct userInfoStruct* uInfo, enum userDataRWSql uDataRWSql);

#endif /* SQLITE_TELEGRAM_XUI_BOT */

