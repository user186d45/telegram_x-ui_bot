#include "../../include/bot/userInfoLoader.hpp"
#include "../../include/log.h"
#include "../../include/structs.h"
#include "../../include/sqlite.h"
#include "../../include/memoryDb.h"

#include <malloc.h>

struct userInfoStruct* userInfoLoader::loadInfo(int64_t userId) {
    DBG(LOG_INFO, "Function called");

    struct userInfoStruct* uInfo = (struct userInfoStruct*)malloc(sizeof(struct userInfoStruct));
    if (!uInfo) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "uInfo is a null pointer, failed to allocate space");

        return nullptr;

    }
    uInfo->userId = userId;

    if (!sqlReadUserData(uInfo, userDataRWSql_ALL)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Failed to read user data");

        free(uInfo);

        return nullptr;

    }
    uInfo->rUserInfo = NULL;

    if (!memoryDbLoadUser(uInfo)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Failed to load user runtime info");

        free(uInfo);

        return nullptr;

    }
    memoryDbUpdateUser(uInfo->rUserInfo);

    return uInfo;

}

