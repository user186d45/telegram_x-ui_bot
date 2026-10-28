#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cjson/clients.h"

static int check(const char* name, int ok) {
    printf("%s %s\n", ok ? "OK" : "FAILED", name);

    return ok ? 0 : 1;

}

int main(void) {
    int failures = 0;

    const char* successSample = "{\"success\":true,\"msg\":\"\",\"obj\":[{\"id\":6,\"email\":\"qbgu8qzpv9\",\"subId\":\"szs0o19sdv9z1ik1\",\"uuid\":\"254fcf67-5207-4b2e-94bc-e78d1b0fd28d\",\"password\":\"tmyuhcj5jzdzkox7\",\"auth\":\"v0vzk7r37v9tkb7f\",\"flow\":\"\",\"security\":\"auto\",\"privateKey\":\"\",\"publicKey\":\"\",\"allowedIps\":\"\",\"preSharedKey\":\"\",\"keepAlive\":0,\"secret\":\"\",\"adTag\":\"\",\"limitIp\":0,\"totalGB\":0,\"expiryTime\":1793133000000,\"enable\":true,\"tgId\":0,\"group\":\"exmapleGroup\",\"comment\":\"exampleComment\",\"reset\":30,\"createdAt\":1792313382097,\"updatedAt\":1792313382000,\"reverse\":null,\"inboundIds\":[1],\"traffic\":{\"id\":9,\"inboundId\":1,\"enable\":true,\"email\":\"qbgu8qzpv9\",\"uuid\":\"\",\"subId\":\"\",\"up\":0,\"down\":0,\"expiryTime\":1793133000000,\"total\":0,\"reset\":30,\"lastOnline\":0}}]}";
    struct jsonListEveryClientStruct* r = jsonListEveryClient(successSample);
    failures += check("success response parses", r != NULL);
    if (r) {
        failures += check("success flag is set", r->success == 1);
        failures += check("msg is empty", r->msg != NULL && strcmp(r->msg, "") == 0);
        failures += check("array size is 1", r->jsonListEveryClientArrayStructSize == 1);
        if (r->jsonListEveryClientArrayStructSize && r->listEveryCliArrStruct) {
            failures += check("email is qbgu8qzpv9", r->listEveryCliArrStruct[0].email != NULL && strcmp(r->listEveryCliArrStruct[0].email, "qbgu8qzpv9") == 0);
            failures += check("inboundIdsCount is 1", r->listEveryCliArrStruct[0].inboundIdsCount == 1);
            failures += check("traffic obj present", r->listEveryCliArrStruct[0].listEveryCliObjTrafficObjStruct != NULL);
            if (r->listEveryCliArrStruct[0].listEveryCliObjTrafficObjStruct) {
                failures += check("traffic id is 9", r->listEveryCliArrStruct[0].listEveryCliObjTrafficObjStruct->id == 9);
            }
        }
        jsonListEveryClientStructDelete(r);

    }

    const char* emptySample = "{\"success\":true,\"msg\":\"\",\"obj\":[]}";
    struct jsonListEveryClientStruct* r2 = jsonListEveryClient(emptySample);
    failures += check("empty obj parses", r2 != NULL);
    if (r2) {
        failures += check("empty array size is 0", r2->jsonListEveryClientArrayStructSize == 0);
        failures += check("empty array ptr is null", r2->listEveryCliArrStruct == NULL);
        jsonListEveryClientStructDelete(r2);

    }

    const char* failSample = "{\"success\": false, \"msg\": \"error\"}";
    struct jsonListEveryClientStruct* rf = jsonListEveryClient(failSample);
    failures += check("success false keeps msg", rf != NULL && rf->success == 0 && rf->msg != NULL && strcmp(rf->msg, "error") == 0);
    jsonListEveryClientStructDelete(rf);

    if (failures) {
        printf("LIST EVERY CLIENT TESTS FAILED: %d\n", failures);

        return 1;

    }

    printf("LIST EVERY CLIENT TESTS PASSED\n");

    return 0;

}
