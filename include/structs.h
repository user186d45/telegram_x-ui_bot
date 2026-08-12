#ifndef STRUCTS_TELEGRAM_XUI_BOT
#define STRUCTS_TELEGRAM_XUI_BOT

#include <stddef.h>
#include <stdint.h>
#include <time.h>

struct panelInfo {
    int                      id;
    const char*              domainAddress;
    const char*              authKey;

};

struct applicationConfig {
    const char*              botApiKey;
    const char**             admins;
    const char**             channels2Join;

};

enum conversationState {
    IDLE,
    GET_PHONE_NUMBER,
    GET_VERIFICATION,
    GET_AMOUNT,
    GET_RECEIPT_PHOTO,
    GET_TICKET

};

struct runtimeUserInfo {
    int32_t                  priceListMsgId;

    time_t                   lastActivity;
    time_t                   TicketTime;
    time_t                   ReceiptTime;

};

struct userInfo {
    int64_t                  userId;
    const char*              phoneNumber;
    int                      balance;
    unsigned char            hasJoined;
    unsigned char            banned;
    uint8_t                  cState;

    struct runtimeUserInfo* rUserInfo;

};

extern struct userInfo* uInfo;

#endif

