#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cjson/cJSON.h>
#include "cjson/inbounds.h"

static char* readFile(const char* path) {
    FILE* f = fopen(path, "rb");
    if (!f) {
        return NULL;

    }
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    char* buf = (char*)malloc((size_t)size + 1);
    if (!buf) {
        fclose(f);
        return NULL;

    }
    size_t read = fread(buf, 1, (size_t)size, f);
    buf[read] = '\0';
    fclose(f);

    return buf;

}

static int sameTree(const cJSON* a, const cJSON* b) {
    if (!a || !b) {
        return a == b;

    }
    if (cJSON_IsNumber(a)) {
        return cJSON_IsNumber(b) && a->valuedouble == b->valuedouble;

    }
    if (cJSON_IsString(a)) {
        return cJSON_IsString(b) && strcmp(a->valuestring, b->valuestring) == 0;

    }
    if (cJSON_IsBool(a)) {
        return cJSON_IsBool(b) && cJSON_IsTrue(a) == cJSON_IsTrue(b);

    }
    if (cJSON_IsArray(a)) {
        if (!cJSON_IsArray(b) || cJSON_GetArraySize(a) != cJSON_GetArraySize(b)) {
            return 0;

        }
        for (int i = 0; i < cJSON_GetArraySize(a); i++) {
            if (!sameTree(cJSON_GetArrayItem(a, i), cJSON_GetArrayItem(b, i))) {
                return 0;

            }
        }

        return 1;

    }
    if (cJSON_IsObject(a)) {
        if (!cJSON_IsObject(b) || cJSON_GetArraySize(a) != cJSON_GetArraySize(b)) {
            return 0;

        }
        for (cJSON* child = a->child; child; child = child->next) {
            if (!sameTree(child, cJSON_GetObjectItemCaseSensitive(b, child->string))) {
                return 0;

            }
        }

        return 1;

    }

    return 0;

}

static int check(const char* name, int ok) {
    printf("%s %s\n", ok ? "OK" : "FAILED", name);

    return ok ? 0 : 1;

}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("usage: test_security_sample <sample_inbounds.json>\n");

        return 2;

    }

    int failures = 0;
    char* json = readFile(argv[1]);
    failures += check("sample file read", json != NULL);
    if (!json) {
        return 1;

    }

    cJSON* sample = cJSON_Parse(json);
    cJSON* sampleObjs = sample ? cJSON_GetObjectItemCaseSensitive(sample, "obj") : NULL;
    failures += check("sample parses as json", sampleObjs != NULL && cJSON_IsArray(sampleObjs));

    struct jsonListInboundStruct* list = jsonListInbound(json);
    failures += check("list parser accepts the sample", list != NULL && list->jsonListInboundObjectStructSize == 2);
    if (!list) {
        cJSON_Delete(sample);
        free(json);

        return 1;

    }

    struct jsonListInboundObjectStruct* tlsInbound = &list->listInObjStruct[0];
    struct jsonListInboundObjectStruct* realityInbound = &list->listInObjStruct[1];
    failures += check("inbound 1 holds a tls struct",
        tlsInbound->listInStreamSettingsObjStruct && tlsInbound->listInStreamSettingsObjStruct->listInStreamSettingsTlsSettingsObjStruct != NULL);
    failures += check("inbound 1 holds no reality struct",
        tlsInbound->listInStreamSettingsObjStruct && tlsInbound->listInStreamSettingsObjStruct->listInStreamSettingsRealitySettingsObjStruct == NULL);
    failures += check("inbound 2 holds a reality struct",
        realityInbound->listInStreamSettingsObjStruct && realityInbound->listInStreamSettingsObjStruct->listInStreamSettingsRealitySettingsObjStruct != NULL);
    failures += check("inbound 2 holds no tls struct",
        realityInbound->listInStreamSettingsObjStruct && realityInbound->listInStreamSettingsObjStruct->listInStreamSettingsTlsSettingsObjStruct == NULL);

    for (size_t i = 0; i < list->jsonListInboundObjectStructSize; i++) {
        struct jsonListInboundObjectStruct* inbound = &list->listInObjStruct[i];
        cJSON* sampleStream = cJSON_GetObjectItemCaseSensitive(cJSON_GetArrayItem(sampleObjs, (int)i), "streamSettings");

        const char* out = jsonImportInboundsPost(inbound);
        failures += check("serializer returns an inbound", out != NULL);
        if (!out) {
            continue;

        }
        cJSON* outJson = cJSON_Parse(out);
        cJSON* outStream = cJSON_GetObjectItemCaseSensitive(outJson, "streamSettings");

        cJSON* sampleTls = cJSON_GetObjectItemCaseSensitive(sampleStream, "tlsSettings");
        cJSON* outTls = cJSON_GetObjectItemCaseSensitive(outStream, "tlsSettings");
        failures += check(i == 0 ? "inbound 1 tlsSettings matches the sample" : "inbound 2 has no tlsSettings",
            sameTree(sampleTls, outTls));

        cJSON* sampleReality = cJSON_GetObjectItemCaseSensitive(sampleStream, "realitySettings");
        cJSON* outReality = cJSON_GetObjectItemCaseSensitive(outStream, "realitySettings");
        failures += check(i == 0 ? "inbound 1 has no realitySettings" : "inbound 2 realitySettings matches the sample",
            sameTree(sampleReality, outReality));

        cJSON_Delete(outJson);
        free((void*)out);

    }

    jsonListInboundStructDelete(list);
    cJSON_Delete(sample);
    free(json);

    if (failures) {
        printf("SECURITY SAMPLE TESTS FAILED: %d\n", failures);

        return 1;

    }

    printf("SECURITY SAMPLE TESTS PASSED\n");

    return 0;

}
