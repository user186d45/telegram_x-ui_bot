#ifndef SQLITE_TELEGRAM_XUI_BOT
#define SQLITE_TELEGRAM_XUI_BOT

#include <stddef.h>
#include <stdint.h>

enum userDataRWSql : uint8_t {
    ALL,
    BALANCE,
    PHONE_NUMBER,
    JOIN_STATE,
    CONVERSATION_STATE,
    PRICE_LIST_MESSAGE_ID,
    LAST_ACTIVITY_TIME,
    TICKET_TIME,
    RECEIPT_TIME

};

unsigned char createCheckDb();
unsigned char writeUserData(enum userDataRWSql);
unsigned char readUserData(enum userDataRWSql);

#endif

