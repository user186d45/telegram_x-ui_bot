#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cjson/inbounds.h"

static int check(const char* name, int ok) {
    printf("%s %s\n", ok ? "OK" : "FAILED", name);

    return ok ? 0 : 1;

}

int main(void) {
    int failures = 0;

    const char* sample = "{\n  \"success\": true,\n  \"msg\": \"Inbound updated\"\n}";
    struct jsonSetInboundFallbacksResponseStruct* rStruct = jsonSetInboundFallbacksResponse(sample);
    failures += check("success response parses", rStruct != NULL);
    if (rStruct) {
        failures += check("success flag is set", rStruct->success == 1);
        failures += check("msg is Inbound updated", rStruct->msg != NULL && strcmp(rStruct->msg, "Inbound updated") == 0);
        failures += check("obj is null on success", rStruct->obj == NULL);
        jsonSetInboundFallbacksResponseStructDelete(rStruct);

    }

    const char* notSuccess = "{\n  \"success\": false,\n  \"msg\": \"Inbound not found\"\n}";
    failures += check("success false is rejected", jsonSetInboundFallbacksResponse(notSuccess) == NULL);

    const char* noMsg = "{\n  \"success\": true\n}";
    failures += check("missing msg is rejected", jsonSetInboundFallbacksResponse(noMsg) == NULL);

    if (failures) {
        printf("SET FALLBACKS RESPONSE TESTS FAILED: %d\n", failures);

        return 1;

    }

    printf("SET FALLBACKS RESPONSE TESTS PASSED\n");

    return 0;

}
