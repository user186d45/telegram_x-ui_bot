#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cjson/cJSON.h>
#include "cjson/inbounds.h"

static int check(const char* name, int ok) {
    printf("%s %s\n", ok ? "OK" : "FAILED", name);

    return ok ? 0 : 1;

}

int main(void) {
    int failures = 0;

    int64_t ids[] = {3, 7};
    struct jsonDeleteMultipleInboundsPostStruct nonEmpty = { .idsCount = 2, .ids = ids };
    const char* out = jsonDeleteMultipleInboundsPost(&nonEmpty);
    failures += check("non-empty ids serialize", out != NULL);
    if (out) {
        cJSON* parsed = cJSON_Parse(out);
        cJSON* arr = cJSON_GetObjectItemCaseSensitive(parsed, "ids");
        int ok = cJSON_IsArray(arr) && cJSON_GetArraySize(arr) == 2
              && cJSON_GetArrayItem(arr, 0)->valuedouble == 3
              && cJSON_GetArrayItem(arr, 1)->valuedouble == 7;
        failures += check("ids round-trip as [3, 7]", ok);
        cJSON_Delete(parsed);
        free((void*)out);

    }

    struct jsonDeleteMultipleInboundsPostStruct empty = { .idsCount = 0, .ids = NULL };
    failures += check("empty ids rejected with NULL", jsonDeleteMultipleInboundsPost(&empty) == NULL);
    failures += check("NULL struct rejected with NULL", jsonDeleteMultipleInboundsPost(NULL) == NULL);

    if (failures) {
        printf("DELETE MULTI TESTS FAILED: %d\n", failures);

        return 1;

    }

    printf("DELETE MULTI TESTS PASSED\n");

    return 0;

}
