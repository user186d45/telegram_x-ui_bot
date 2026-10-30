#ifndef CJSON_TELEGRAM_XUI_BOT_JSON_VALIDATION_H
#define CJSON_TELEGRAM_XUI_BOT_JSON_VALIDATION_H

// Shared json validation guard used by every section parser.
// The double underscore marks this as internal: section code must call it,
// never reimplement it.

#include <cjson/cJSON.h>

#include <stdint.h>

unsigned char __isJsonValid(const char* json);

int  jsonBulkStringArrayParse(cJSON* arr, const char*** strArr, int64_t* strCount);
void jsonBulkStringArrayFree(const char** strArr, int64_t strCount);

#endif /* CJSON_TELEGRAM_XUI_BOT_JSON_VALIDATION_H */
