#include "../include/curl.h"
#include "../include/log.h"

#include <curl/curl.h>
#include <stdlib.h>
#include <memory.h>

#define BUFFER_SIZE 2048

struct writeCallBackStruct {
    char* contents;
    size_t size;

};

static size_t write_callback(void* contents, size_t size, size_t nmemb, void* arg) {
    DBG(LOG_INFO, "Function called");

    struct writeCallBackStruct* wCallbackStruct = (struct writeCallBackStruct*)arg;
    if (!wCallbackStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Failed to assing pointer");

        return 0;

    }

    size_t readSize = size * nmemb;
    if (readSize + wCallbackStruct->size >= BUFFER_SIZE) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Callback data is longer than the allocated buffer size");

        return 0;

    }

    memcpy(wCallbackStruct->contents + wCallbackStruct->size, contents, readSize);

    wCallbackStruct->size += readSize;

    return readSize;

}

const char* curlGetUrlWHeaders(const char* url, struct curl_slist* slist) {
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if (!curl) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Failed to initialize curl");

        return NULL;

    }

    struct writeCallBackStruct* wCallbackStruct = (struct writeCallBackStruct*)malloc(sizeof(struct writeCallBackStruct));
    if (!wCallbackStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "wCallbackStruct is a null pointer, failed to allocate space");

        curl_easy_cleanup(curl);

        return NULL;

    }

    wCallbackStruct->contents = (char*)malloc(BUFFER_SIZE * sizeof(char));
    if (!wCallbackStruct->contents) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "contents is a null pointer, failed to allocate memory");

        free(wCallbackStruct);

        curl_easy_cleanup(curl);

        return NULL;

    }

    wCallbackStruct->size = 0;

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, wCallbackStruct);

    if (slist) {
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist);

    }

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        char b[512];
        snprintf(b, sizeof(b), "Failed to perform curl: %s", curl_easy_strerror(res));
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, b);

        free(wCallbackStruct->contents);
        free(wCallbackStruct);

        curl_easy_cleanup(curl);

        return NULL;

    }

    wCallbackStruct->contents[wCallbackStruct->size] = '\0';
    const char* json = wCallbackStruct->contents;

    free(wCallbackStruct);

    curl_easy_cleanup(curl);

    return json;

}

const char* curlPostUrlWHeadersNPayload(const char* url, struct curl_slist* slist, const char* payload) {
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if (!curl) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Failed to initialize curl");

        return NULL;

    }

    struct writeCallBackStruct* wCallbackStruct = (struct writeCallBackStruct*)malloc(sizeof(struct writeCallBackStruct));
    if (!wCallbackStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "wCallbackStruct is a null pointer, failed to allocate space");

        curl_easy_cleanup(curl);

        return NULL;

    }

    wCallbackStruct->contents = (char*)malloc(BUFFER_SIZE * sizeof(char));
    if (!wCallbackStruct->contents) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "contents is a null pointer, failed to allocate memory");

        free(wCallbackStruct);

        curl_easy_cleanup(curl);

        return NULL;

    }

    wCallbackStruct->size = 0;

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, wCallbackStruct);

    if (slist) {
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist);

    }

    if (payload) {
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload);

    }

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        char b[512];
        snprintf(b, sizeof(b), "Failed to perform curl: %s", curl_easy_strerror(res));
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, b);

        free(wCallbackStruct->contents);
        free(wCallbackStruct);

        curl_easy_cleanup(curl);

        return NULL;

    }

    wCallbackStruct->contents[wCallbackStruct->size] = '\0';
    const char* json = wCallbackStruct->contents;

    free(wCallbackStruct);

    curl_easy_cleanup(curl);

    return json;

}

