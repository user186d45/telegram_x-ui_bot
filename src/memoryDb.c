#include "../include/memoryDb.h"
#include "../include/structs.h"
#include "../include/log.h"

#include <stdlib.h>
#include <time.h>

struct memoryDbStruct* memoryDb = NULL;

unsigned char memoryDbLoadUser(struct userInfoStruct* uInfo) {
    if (!uInfo) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "uInfo is a null pointer");

        return 0;

    }

    if (!memoryDb) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "memoryDb is a null pointer");

        uInfo->rUserInfo = NULL;

        return 0;

    }

    for (size_t i = 0; i < memoryDb->entryCount; i++) {
        if (memoryDb->runtimeEntries[i]->userId == uInfo->userId) {
            uInfo->rUserInfo = memoryDb->runtimeEntries[i];

            return 1;

        }

    }

    if (memoryDb->entryCount == RUNTIME_ENTITIES_BUFFER_SIZE) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "runtimeEntries is full, cannot create another entry");

        uInfo->rUserInfo = NULL;

        return 0;

    }

    memoryDb->runtimeEntries[memoryDb->entryCount] = (struct runtimeUserInfoStruct*)malloc(sizeof(struct runtimeUserInfoStruct));
    if (!memoryDb->runtimeEntries[memoryDb->entryCount]) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "runtimeEntries last element is a null pointer, failed to allocate space");

        uInfo->rUserInfo = NULL;

        return 0;
    }

    struct runtimeUserInfoStruct* rUserInfo = memoryDb->runtimeEntries[memoryDb->entryCount];
    rUserInfo->userId = uInfo->userId;
    rUserInfo->entryIndex = memoryDb->entryCount;
    rUserInfo->lastActivity = time(NULL);
    rUserInfo->cState = CS_IDLE;
    rUserInfo->priceListMsgId = 0;
    rUserInfo->ticketTime = 0;

    uInfo->rUserInfo = rUserInfo;

    memoryDb->entryCount++;

    return 1;

}

unsigned char memoryDbUpdateUser(struct runtimeUserInfoStruct* rUserInfo) {
    if (!rUserInfo) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "rUserInfo is a null pointer");

        return 0;

    }

    time_t now = time(NULL);
    if (difftime(now, rUserInfo->lastActivity) > aConfig->conversationStateTimeOut) {
        rUserInfo->cState = CS_IDLE;
        rUserInfo->priceListMsgId = 0;

    }

    if (rUserInfo->ticketTime) {
        if (difftime(now, rUserInfo->ticketTime) > aConfig->ticketTimeOut) {
            rUserInfo->ticketTime = 0;

        }

    }

    return 1;

}

void memoryDbDeleteEntry(struct runtimeUserInfoStruct* rUserInfo) {
    if (!rUserInfo) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "rUserInfo is a null pointer");

        return;

    }

    size_t index = rUserInfo->entryIndex;
    
    free(rUserInfo);

    if (index + 1 != memoryDb->entryCount) {
        memoryDb->runtimeEntries[index] = memoryDb->runtimeEntries[memoryDb->entryCount - 1];

    }

    memoryDb->entryCount--;

}

