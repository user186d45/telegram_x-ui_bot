#ifndef MEMORY_DB_TELEGRAM_XUI_BOT
#define MEMORY_DB_TELEGRAM_XUI_BOT

#define RUNTIME_ENTITIES_BUFFER_SIZE 1024 * 10

#include "./structs.h"

struct memoryDbStruct {
    size_t entryCount;

    struct runtimeUserInfoStruct* runtimeEntries[RUNTIME_ENTITIES_BUFFER_SIZE];

};

unsigned char memoryDbLoadUser(struct userInfoStruct* uInfo);
unsigned char memoryDbUpdateUser(struct runtimeUserInfoStruct* rUserInfo);
void memoryDbDeleteEntry(struct runtimeUserInfoStruct* rUserInfo);

#endif /* MEMORY_DB_TELEGRAM_XUI_BOT */

