#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cjson/cJSON.h>
#include "cjson/inbounds.h"

static int check(const char* name, int ok) {
    printf("%s %s\n", ok ? "OK" : "FAILED", name);

    return ok ? 0 : 1;

}

static int hasKey(cJSON* obj, const char* key) {
    return cJSON_GetObjectItemCaseSensitive(obj, key) != NULL;

}

static int numIs(cJSON* obj, const char* key, double value) {
    cJSON* item = cJSON_GetObjectItemCaseSensitive(obj, key);

    return item && cJSON_IsNumber(item) && item->valuedouble == value;

}

static int strIs(cJSON* obj, const char* key, const char* value) {
    cJSON* item = cJSON_GetObjectItemCaseSensitive(obj, key);

    return item && cJSON_IsString(item) && strcmp(item->valuestring, value) == 0;

}

int main(void) {
    int failures = 0;

    // the panel sample request body: entry 0 has childId, path, xver; entry 1 has childId, alpn, dest
    struct jsonSetInboundFallbacksArrayPostStruct sampleEntries[2];
    memset(sampleEntries, 0, sizeof(sampleEntries));
    sampleEntries[0].childIdEnabled = 1;
    sampleEntries[0].childId = 11;
    sampleEntries[0].path = strdup("/vlws");
    sampleEntries[0].xverEnabled = 1;
    sampleEntries[0].xver = 2;
    sampleEntries[1].childIdEnabled = 1;
    sampleEntries[1].childId = 12;
    sampleEntries[1].alpn = strdup("h2");
    sampleEntries[1].dest = strdup("8443");

    struct jsonSetInboundFallbacksPostStruct sampleBody = { .id = 1, .jsonSetInboundFallbacksArrayPostStructSize = 2, .setInboundFallbacksArrPStruct = sampleEntries };
    const char* out = jsonSetInboundFallbacksPost(&sampleBody);
    failures += check("sample body serializes", out != NULL);
    if (out) {
        cJSON* parsed = cJSON_Parse(out);
        cJSON* fallbacks = cJSON_GetObjectItemCaseSensitive(parsed, "fallbacks");
        failures += check("body has a fallbacks array of 2", cJSON_IsArray(fallbacks) && cJSON_GetArraySize(fallbacks) == 2);
        failures += check("body has no id key", !hasKey(parsed, "id"));
        if (fallbacks && cJSON_GetArraySize(fallbacks) == 2) {
            cJSON* e0 = cJSON_GetArrayItem(fallbacks, 0);
            cJSON* e1 = cJSON_GetArrayItem(fallbacks, 1);
            failures += check("entry 0 has childId 11, path /vlws, xver 2", numIs(e0, "childId", 11) && strIs(e0, "path", "/vlws") && numIs(e0, "xver", 2));
            failures += check("entry 0 has no alpn, dest, name, sortOrder", !hasKey(e0, "alpn") && !hasKey(e0, "dest") && !hasKey(e0, "name") && !hasKey(e0, "sortOrder"));
            failures += check("entry 1 has childId 12, alpn h2, dest 8443", numIs(e1, "childId", 12) && strIs(e1, "alpn", "h2") && strIs(e1, "dest", "8443"));
            failures += check("entry 1 has no path, xver, name, sortOrder", !hasKey(e1, "path") && !hasKey(e1, "xver") && !hasKey(e1, "name") && !hasKey(e1, "sortOrder"));
        }
        cJSON_Delete(parsed);
        free((void*)out);

    }

    // a flagged zero is sent, an unflagged non-zero is not
    struct jsonSetInboundFallbacksArrayPostStruct flagEntries[1];
    memset(flagEntries, 0, sizeof(flagEntries));
    flagEntries[0].xverEnabled = 1;
    flagEntries[0].xver = 0;
    flagEntries[0].sortOrder = 9;
    struct jsonSetInboundFallbacksPostStruct flagBody = { .jsonSetInboundFallbacksArrayPostStructSize = 1, .setInboundFallbacksArrPStruct = flagEntries };
    const char* flagOut = jsonSetInboundFallbacksPost(&flagBody);
    failures += check("flagged xver 0 is sent", flagOut != NULL);
    if (flagOut) {
        cJSON* parsed = cJSON_Parse(flagOut);
        cJSON* e0 = cJSON_GetArrayItem(cJSON_GetObjectItemCaseSensitive(parsed, "fallbacks"), 0);
        failures += check("xver 0 emitted as 0", numIs(e0, "xver", 0));
        failures += check("unflagged sortOrder 9 is omitted", !hasKey(e0, "sortOrder"));
        cJSON_Delete(parsed);
        free((void*)flagOut);

    }

    // an empty list still sends the fallbacks key, so the panel can clear all rules
    struct jsonSetInboundFallbacksPostStruct emptyBody = { .jsonSetInboundFallbacksArrayPostStructSize = 0, .setInboundFallbacksArrPStruct = NULL };
    const char* emptyOut = jsonSetInboundFallbacksPost(&emptyBody);
    failures += check("empty list serializes", emptyOut != NULL);
    if (emptyOut) {
        cJSON* parsed = cJSON_Parse(emptyOut);
        cJSON* fallbacks = cJSON_GetObjectItemCaseSensitive(parsed, "fallbacks");
        failures += check("empty list sends an empty fallbacks array", cJSON_IsArray(fallbacks) && cJSON_GetArraySize(fallbacks) == 0);
        cJSON_Delete(parsed);
        free((void*)emptyOut);

    }

    failures += check("NULL struct is rejected", jsonSetInboundFallbacksPost(NULL) == NULL);

    free(sampleEntries[0].path);
    free(sampleEntries[1].alpn);
    free(sampleEntries[1].dest);

    if (failures) {
        printf("SET FALLBACKS POST TESTS FAILED: %d\n", failures);

        return 1;

    }

    printf("SET FALLBACKS POST TESTS PASSED\n");

    return 0;

}
