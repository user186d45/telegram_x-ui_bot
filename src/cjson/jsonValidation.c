#include "../../include/cjson/jsonValidation.h"
#include "../../include/log.h"

#include <cjson/cJSON.h>
#include <stdio.h>
#include <string.h>

unsigned char __isJsonValid(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (json == NULL) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is nullptr");

        return 0;

    }
    
    const char* ptrErr = NULL;
    cJSON* j = cJSON_ParseWithOpts(json, &ptrErr, 1);
    if (j == NULL) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Parsing failed, printing error location");

        size_t errOffset = ptrErr - json;

        size_t startOffset = (errOffset > 10) ? errOffset - 10 : 0;
        size_t offsetLen = (errOffset + 10ULL < strlen(json)) ? 10 : strlen(json) - startOffset;
        char errMsg[1024];
        sprintf(
            errMsg,
            "Error occurred on parsing the json configuration file, the error occurred on:\n%.*s\nexiting...\n",
            (int)offsetLen,
            json + startOffset
        );

        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, errMsg);

        return 0;

    }

    cJSON_Delete(j);

    return 1;

}
