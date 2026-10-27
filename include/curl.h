#ifndef CURL_TELEGRAM_XUI_BOT
#define CURL_TELEGRAM_XUI_BOT

#include <curl/curl.h>

const char* curlGetUrlWHeaders(const char* url, struct curl_slist* slist);
const char* curlPostUrlWHeadersNPayload(const char* url, struct curl_slist* slist, const char* payload);

#endif /* CURL_TELEGRAM_XUI_BOT */

