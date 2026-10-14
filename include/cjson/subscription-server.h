#ifndef CJSON_TELEGRAM_XUI_BOT_SUBSCRIPTION_SERVER_H
#define CJSON_TELEGRAM_XUI_BOT_SUBSCRIPTION_SERVER_H

// subscription-server section - https://docs.sanaei.dev/docs/reference/api/subscription-server/

#include <stddef.h>
#include <stdint.h>


// =====================================================
// Subscription server : a separate HTTP/HTTPS server
// that serves proxy subscription links ( standard, JSON
// and Clash ) to clients. It listens on its own port
// ( default 2096 ) and is configured in Settings →
// Subscription. Fresh panels generate random path
// prefixes for each format; all paths remain
// configurable. Every subscription endpoint sets
// response headers for client apps to read
// traffic/expiry info. These endpoints are NOT under
// /panel/api. Each GET below has a HEAD twin that
// returns the same status and metadata headers without a
// body
// =====================================================

// =====================================================
// Return base64-encoded subscription links for all
// enabled clients matching the subscription id. With an
// Accept: text/html header or ?html=1 a styled info page
// is rendered instead; with ?format=info the page
// view-model is returned as JSON ( traffic, expiry,
// online status; no links ) for live polling. The path
// prefix is configured by subPath
// =====================================================

struct jsonSubServerGetQueryStruct {
    char*                       format; // "info" to get the subscription status view-model
                                        // as JSON instead of the links

};



struct jsonSubServerGetResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // documented as the page view-model ( traffic, expiry,
                                     // online status ) for format=info but the documented
                                     // sample response shows null; exact shape not provided
                                     // ( undefined behavior )

};


// =====================================================
// Return subscription as a JSON array of proxy configs
// ( one per enabled client ); registered only when JSON
// subscription is enabled in settings, path prefix
// configured by subJsonPath
// =====================================================

struct jsonSubServerJsonResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // documented as a JSON array of proxy configs but the
                                     // documented sample response shows null; exact config
                                     // shape not provided ( undefined behavior )

};


// =====================================================
// Return subscription as a Clash/Mihomo-compatible YAML
// config, including configured global Clash routing
// rules; registered only when Clash subscription is
// enabled in settings, path prefix configured by
// subClashPath
// =====================================================

struct jsonSubServerClashResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // documented as a Clash YAML config but the documented
                                     // sample response shows null ( undefined behavior )

};

void        jsonSubServerGetQueryStructDelete(struct jsonSubServerGetQueryStruct* subServerGetQueryStruct);

void        jsonSubServerGetResponseStructDelete(struct jsonSubServerGetResponseStruct* subServerGetRStruct);

void        jsonSubServerJsonResponseStructDelete(struct jsonSubServerJsonResponseStruct* subServerJsonRStruct);

void        jsonSubServerClashResponseStructDelete(struct jsonSubServerClashResponseStruct* subServerClashRStruct);

struct jsonSubServerGetQueryStruct*                jsonSubServerGetQuery(const char* json);

struct jsonSubServerGetResponseStruct*             jsonSubServerGetResponse(const char* json);

struct jsonSubServerJsonResponseStruct*            jsonSubServerJsonResponse(const char* json);

struct jsonSubServerClashResponseStruct*           jsonSubServerClashResponse(const char* json);

#endif /* CJSON_TELEGRAM_XUI_BOT_SUBSCRIPTION_SERVER_H */
