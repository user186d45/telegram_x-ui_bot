#ifndef SQLITE_TELEGRAM_XUI_BOT
#define SQLITE_TELEGRAM_XUI_BOT

#include <stddef.h>
#include <stdint.h>

#include <sqlite3.h>

enum userDataRWSql : uint8_t {
    userDataRWSql_ALL,
    userDataRWSql_BALANCE,
    userDataRWSql_PHONE_NUMBER,
    userDataRWSql_JOIN_STATE,
    userDataRWSql_BANNED_STATE,
    userDataRWSql_CONVERSATION_STATE

};

unsigned char createCheckDb();
unsigned char writeUserData(enum userDataRWSql uDataRWSql);
unsigned char readUserData(enum userDataRWSql uDataRWSql);

static void sqlErrorMsg(const char* msg, sqlite3* db, int rc);

#endif

