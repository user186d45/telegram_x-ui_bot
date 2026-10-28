#include "../include/structs.h"
#include "../include/log.h"

#include <malloc.h>

struct panelsStruct* panels = NULL;
struct applicationConfigStruct* aConfig = NULL;

void userInfoStructDelete(struct userInfoStruct* uInfo) {
    DBG(LOG_INFO, "Function called");

    if (uInfo) {
        if (uInfo->phoneNumber) {
            free((char*)uInfo->phoneNumber);

        }

        if (uInfo->rUserInfo) {
            free(uInfo->rUserInfo);

        }

        free(uInfo);

    }

}
