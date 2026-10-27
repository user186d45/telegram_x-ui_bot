#ifndef STRUCTS_TELEGRAM_XUI_BOT
#define STRUCTS_TELEGRAM_XUI_BOT

#include <stddef.h>
#include <stdint.h>
#include <time.h>

struct panelInfoStruct {
    int                      id;
    const char*              accessUrl;
    const char*              apiKey;

};

struct panelsStruct {
    size_t                   panelsCount;
    struct panelInfoStruct*  pInfoStructs;

};

struct applicationMessagesStruct {
    const char*              welcomeMessage;
    const char*              bannedMessage;

};

struct applicationButtonTextsStruct {
    const char*              productsListsText;
    const char*              profileText;
    const char*              depositText;
    const char*              supportText;
    const char*              adminPanelText;

};

struct applicationConfigStruct {
    const char*              botApiKey;
    size_t                   adminsCount;
    int64_t*                 admins;
    size_t                   channels2JoinCount;
    const char**             channels2Join;

    int                      conversationStateTimeOut;
    int                      ticketTimeOut;

    struct applicationMessagesStruct* aMessages;
    struct applicationButtonTextsStruct* aButtonTexts;

};

enum conversationState {
    CS_IDLE,
    CS_GET_PHONE_NUMBER,
    CS_GET_VERIFICATION,
    CS_GET_AMOUNT,
    CS_GET_RECEIPT_PHOTO,
    CS_GET_TICKET

};

struct runtimeUserInfoStruct {
    int64_t                  userId;
    size_t                   entryIndex;

    time_t                   lastActivity;
    uint8_t                  cState;
    int32_t                  priceListMsgId;
    time_t                   ticketTime;

};

struct userInfoStruct {
    int64_t                  userId;
    const char*              phoneNumber;
    int                      balance;
    unsigned char            hasJoined;
    unsigned char            banned;

    struct runtimeUserInfoStruct* rUserInfo;

};

extern struct panelsStruct* panels;
extern struct applicationConfigStruct* aConfig;

#endif /* STRUCTS_TELEGRAM_XUI_BOT */

