#ifndef CJSON_TELEGRAM_XUI_BOT_HOSTS_H
#define CJSON_TELEGRAM_XUI_BOT_HOSTS_H

// hosts section - https://docs.sanaei.dev/docs/reference/api/hosts/

#include <stddef.h>
#include <stdint.h>


// =====================================================
// Host groups : per-inbound groups of hosts sharing port
// / security / TLS / transport settings. You must check
// each field on its own and then parse or assign a NULL
// to it, dont check them all at once. Every field of
// every struct here is optional on the wire; a future
// implementation must test each field's presence and
// type individually and assign NULL when absent
// =====================================================

// =====================================================
// Xray Mux config nested object ( enabled, concurrency,
// xudpConcurrency, xudpProxyUDP443, xmuxes[] )
// =====================================================

struct jsonHostGroupMuxXmuxObjectStruct {
    int                         maxConcurrency;
    int                         maxConnections;

};



struct jsonHostGroupMuxObjectStruct {
    int                         concurrency;
    unsigned char               enabled;
    int                         xudpConcurrency;
    const char*                 xudpProxyUDP443;
    size_t                      jsonHostGroupMuxXmuxObjectStructSize; // array length, 0 when the array is not present
    struct jsonHostGroupMuxXmuxObjectStruct* xmuxesArrStruct; // array

};



// =====================================================
// Xray sockopt config nested object. Mirrors the
// inbounds.h sockopt shape exactly ( Enabled-suffix
// flattening plus custom sockopt array )
// =====================================================

struct jsonHostGroupSockoptCustomSockOptArrayStruct {
    const char*                 system;
    const char*                 type;
    const char*                 level;
    const char*                 opt;
    const char*                 value;

};



struct jsonHostGroupSockoptObjectStruct {
    unsigned char               acceptProxyProtocolEnabled;
    unsigned char               acceptProxyProtocol;
    unsigned char               tcpFastOpenEnabled;
    unsigned char               tcpFastOpen;
    unsigned char               tproxyEnabled;
    const char*                 tproxy;
    unsigned char               penetrateEnabled;
    unsigned char               penetrate;
    unsigned char               tcpcongestionEnabled;
    const char*                 tcpcongestion;
    unsigned char               V6OnlyEnabled;
    unsigned char               V6Only;
    unsigned char               hostGroupSockoptObjCustomSockArrStructEnabled;
    size_t                      jsonHostGroupSockoptCustomSockOptArrayStructSize; // array length, 0 when the array is not present
    struct jsonHostGroupSockoptCustomSockOptArrayStruct* hostGroupSockoptObjCustomSockArrStruct; // array

};



// =====================================================
// Shared host group object struct ( fields are
// alphabetical )
// =====================================================

struct jsonHostGroupObjectStruct {
    unsigned char               allowInsecure;
    const char**                alpn; // every pointer presented is an element of the array
    const char*                 cipherSuites;
    int64_t                     createdAt; // creation time in unix milliseconds
    const char*                 echConfigList;
    const char**                excludeFromSubTypes; // every pointer presented is an element of the array
    unsigned char               finalMask;
    const char*                 fingerprint;
    int                         groupId;
    const char*                 hostHeader;
    const char**                hosts; // every pointer presented is an element of the array
    int*                        inboundIds; // every pointer presented is an element of the array
    int64_t                     inboundIdsCount;
    unsigned char               isDisabled;
    unsigned char               isHidden;
    unsigned char               keepSniBlank;
    const char*                 mihomoIpVersion;
    const char*                 mihomoX25519;
    struct jsonHostGroupMuxObjectStruct* muxObjStruct; // optional, NULL when the muxParams field is not present
    const char**                nodeGuids; // every pointer presented is an element of the array
    unsigned char               overrideSniFromAddress;
    const char*                 path;
    const char**                pinnedPeerCertSha256; // every pointer presented is an element of the array
    int                         port;
    const char*                 remark;
    const char*                 security; // "none", "tls" or "reality"
    const char*                 serverDescription;
    unsigned char               shuffleHost;
    const char*                 sni;
    struct jsonHostGroupSockoptObjectStruct* sockoptObjStruct; // optional, NULL when the sockoptParams field is not present
    int                         sortOrder;
    const char**                tags; // every pointer presented is an element of the array
    int64_t                     updatedAt; // last update time in unix milliseconds
    unsigned char               verifyPeerCertByName;
    const char*                 vlessRoute;

};



// =====================================================
// List all host groups, grouped by inbound then by
// sortOrder response structs
// =====================================================

struct jsonListHostsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      jsonHostGroupObjectStructSize; // array length, 0 when the array is not present
    struct jsonHostGroupObjectStruct* listHostsObjArrStruct; // array

};



// =====================================================
// Get a single host group by groupId response structs
// =====================================================

struct jsonGetHostResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonHostGroupObjectStruct* getHostObjRStruct;

};



// =====================================================
// List host groups by inboundId response structs
// =====================================================

struct jsonListHostsByInboundResponseStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      jsonHostGroupObjectStructSize; // array length, 0 when the array is not present
    struct jsonHostGroupObjectStruct* listHostsByInboundObjArrStruct; // array

};



// =====================================================
// List all tags in use across host groups response
// structs ( string[] )
// =====================================================

struct jsonListHostsTagsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      listHostsTagsObjArrSize; // array length, 0 when the array is not present
    const char**                listHostsTagsObjArrStruct; // array

};



// =====================================================
// Create a host group post and response structs
// =====================================================

struct jsonAddHostPostStruct {
    const char*                 remark;
    int*                        inboundIds; // every pointer presented is an element of the array
    int64_t                     inboundIdsCount;
    const char**                hosts; // every pointer presented is an element of the array
    int                         port;
    const char*                 security; // "none", "tls" or "reality"
    const char*                 sni;
    const char**                alpn; // every pointer presented is an element of the array
    const char*                 fingerprint;
    unsigned char               allowInsecure;
    const char*                 echConfigList;
    const char*                 path;
    const char*                 hostHeader;
    struct jsonHostGroupMuxObjectStruct* muxObjStruct; // optional, NULL when the muxParams field is not present
    struct jsonHostGroupSockoptObjectStruct* sockoptObjStruct; // optional, NULL when the sockoptParams field is not present
    const char*                 cipherSuites;
    const char**                pinnedPeerCertSha256; // every pointer presented is an element of the array
    const char**                excludeFromSubTypes; // every pointer presented is an element of the array
    unsigned char               isDisabled;
    unsigned char               isHidden;
    unsigned char               keepSniBlank;
    const char*                 mihomoIpVersion;
    const char*                 mihomoX25519;
    unsigned char               overrideSniFromAddress;
    unsigned char               shuffleHost;
    unsigned char               verifyPeerCertByName;
    const char*                 vlessRoute;
    const char*                 serverDescription;
    unsigned char               finalMask;
    int                         sortOrder;
    const char**                tags; // every pointer presented is an element of the array
    const char**                nodeGuids; // every pointer presented is an element of the array

};



struct jsonAddHostResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonHostGroupObjectStruct* addHostObjRStruct;

};



// =====================================================
// Update a host group by groupId ( full-row update )
// post and response structs
// =====================================================

struct jsonUpdateHostPostStruct {
    int                         groupId; // path param, also sent in the body
    const char*                 remark;
    int*                        inboundIds; // every pointer presented is an element of the array
    int64_t                     inboundIdsCount;
    const char**                hosts; // every pointer presented is an element of the array
    int                         port;
    const char*                 security; // "none", "tls" or "reality"
    const char*                 sni;
    const char**                alpn; // every pointer presented is an element of the array
    const char*                 fingerprint;
    unsigned char               allowInsecure;
    const char*                 echConfigList;
    const char*                 path;
    const char*                 hostHeader;
    struct jsonHostGroupMuxObjectStruct* muxObjStruct; // optional, NULL when the muxParams field is not present
    struct jsonHostGroupSockoptObjectStruct* sockoptObjStruct; // optional, NULL when the sockoptParams field is not present
    const char*                 cipherSuites;
    const char**                pinnedPeerCertSha256; // every pointer presented is an element of the array
    const char**                excludeFromSubTypes; // every pointer presented is an element of the array
    unsigned char               isDisabled;
    unsigned char               isHidden;
    unsigned char               keepSniBlank;
    const char*                 mihomoIpVersion;
    const char*                 mihomoX25519;
    unsigned char               overrideSniFromAddress;
    unsigned char               shuffleHost;
    unsigned char               verifyPeerCertByName;
    const char*                 vlessRoute;
    const char*                 serverDescription;
    unsigned char               finalMask;
    int                         sortOrder;
    const char**                tags; // every pointer presented is an element of the array
    const char**                nodeGuids; // every pointer presented is an element of the array

};



struct jsonUpdateHostResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonHostGroupObjectStruct* updateHostObjRStruct;

};



// =====================================================
// Delete a host group by groupId response struct ( no
// request body, no obj )
// =====================================================

struct jsonDeleteHostResponseStruct {
    unsigned char               success;
    const char*                 msg;

};



// =====================================================
// Enable or disable a host group by groupId post and
// response structs
// =====================================================

struct jsonSetEnableHostPostStruct {
    int                         groupId; // path param, also sent in the body
    unsigned char               enable;

};



struct jsonSetEnableHostResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonHostGroupObjectStruct* setEnableHostObjRStruct;

};



// =====================================================
// Reorder host groups post and response structs
// =====================================================

struct jsonReorderHostsPostStruct {
    int*                        ids; // every pointer presented is an element of the array
    int64_t                     idsCount;

};



struct jsonReorderHostsResponseStruct {
    unsigned char               success;
    const char*                 msg;

};



// =====================================================
// Bulk create host groups post and response structs.
// Body is a JSON array of host groups
// =====================================================

struct jsonBulkAddHostsPostStruct {
    struct jsonHostGroupObjectStruct* hostGroups; // array
    size_t                      hostGroupsSize; // array length, 0 when the array is not present

};



struct jsonBulkAddHostsResponseStruct {
    unsigned char               success;
    const char*                 msg;

};



// =====================================================
// Bulk enable / disable host groups post and response
// structs
// =====================================================

struct jsonBulkSetEnableHostsPostStruct {
    int*                        ids; // every pointer presented is an element of the array
    int64_t                     idsCount;
    unsigned char               enable;

};



struct jsonBulkSetEnableHostsResponseStruct {
    unsigned char               success;
    const char*                 msg;

};



// =====================================================
// Bulk delete host groups post and response structs
// =====================================================

struct jsonBulkDeleteHostsPostStruct {
    int*                        ids; // every pointer presented is an element of the array
    int64_t                     idsCount;

};



struct jsonBulkDeleteHostsResponseStruct {
    unsigned char               success;
    const char*                 msg;

};


void        jsonHostGroupMuxXmuxObjectStructDelete(struct jsonHostGroupMuxXmuxObjectStruct* xmuxesArrStruct, size_t arraySize);

void        jsonHostGroupMuxObjectStructDelete(struct jsonHostGroupMuxObjectStruct* muxObjStruct);

void        jsonHostGroupSockoptCustomSockOptArrayStructDelete(struct jsonHostGroupSockoptCustomSockOptArrayStruct* hostGroupSockoptObjCustomSockArrStruct, size_t arraySize);

void        jsonHostGroupSockoptObjectStructDelete(struct jsonHostGroupSockoptObjectStruct* sockoptObjStruct);

void        jsonHostGroupObjectStructDelete(struct jsonHostGroupObjectStruct* hostGroups, size_t arraySize);

void        jsonListHostsResponseStructDelete(struct jsonListHostsResponseStruct* listHostsRStruct);

void        jsonGetHostResponseStructDelete(struct jsonGetHostResponseStruct* getHostRStruct);

void        jsonListHostsByInboundResponseStructDelete(struct jsonListHostsByInboundResponseStruct* listHostsByInboundRStruct);

void        jsonListHostsTagsResponseStructDelete(struct jsonListHostsTagsResponseStruct* listHostsTagsRStruct);

void        jsonAddHostPostStructDelete(struct jsonAddHostPostStruct* addHostPostStruct);

void        jsonAddHostResponseStructDelete(struct jsonAddHostResponseStruct* addHostRStruct);

void        jsonUpdateHostPostStructDelete(struct jsonUpdateHostPostStruct* updateHostPostStruct);

void        jsonUpdateHostResponseStructDelete(struct jsonUpdateHostResponseStruct* updateHostRStruct);

void        jsonDeleteHostResponseStructDelete(struct jsonDeleteHostResponseStruct* deleteHostRStruct);

void        jsonSetEnableHostPostStructDelete(struct jsonSetEnableHostPostStruct* setEnableHostPostStruct);

void        jsonSetEnableHostResponseStructDelete(struct jsonSetEnableHostResponseStruct* setEnableHostRStruct);

void        jsonReorderHostsPostStructDelete(struct jsonReorderHostsPostStruct* reorderHostsPostStruct);

void        jsonReorderHostsResponseStructDelete(struct jsonReorderHostsResponseStruct* reorderHostsRStruct);

void        jsonBulkAddHostsPostStructDelete(struct jsonBulkAddHostsPostStruct* bulkAddHostsPostStruct);

void        jsonBulkAddHostsResponseStructDelete(struct jsonBulkAddHostsResponseStruct* bulkAddHostsRStruct);

void        jsonBulkSetEnableHostsPostStructDelete(struct jsonBulkSetEnableHostsPostStruct* bulkSetEnableHostsPostStruct);

void        jsonBulkSetEnableHostsResponseStructDelete(struct jsonBulkSetEnableHostsResponseStruct* bulkSetEnableHostsRStruct);

void        jsonBulkDeleteHostsPostStructDelete(struct jsonBulkDeleteHostsPostStruct* bulkDeleteHostsPostStruct);

void        jsonBulkDeleteHostsResponseStructDelete(struct jsonBulkDeleteHostsResponseStruct* bulkDeleteHostsRStruct);

struct jsonListHostsResponseStruct*                jsonListHostsResponse(const char* json);

struct jsonGetHostResponseStruct*                  jsonGetHostResponse(const char* json);

struct jsonListHostsByInboundResponseStruct*       jsonListHostsByInboundResponse(const char* json);

struct jsonListHostsTagsResponseStruct*            jsonListHostsTagsResponse(const char* json);

const char*                                        jsonAddHostPost(struct jsonAddHostPostStruct* addHostPostStruct);

struct jsonAddHostResponseStruct*                  jsonAddHostResponse(const char* json);

const char*                                        jsonUpdateHostPost(struct jsonUpdateHostPostStruct* updateHostPostStruct);

struct jsonUpdateHostResponseStruct*               jsonUpdateHostResponse(const char* json);

struct jsonDeleteHostResponseStruct*               jsonDeleteHostResponse(const char* json);

const char*                                        jsonSetEnableHostPost(struct jsonSetEnableHostPostStruct* setEnableHostPostStruct);

struct jsonSetEnableHostResponseStruct*            jsonSetEnableHostResponse(const char* json);

const char*                                        jsonReorderHostsPost(struct jsonReorderHostsPostStruct* reorderHostsPostStruct);

struct jsonReorderHostsResponseStruct*             jsonReorderHostsResponse(const char* json);

const char*                                        jsonBulkAddHostsPost(struct jsonBulkAddHostsPostStruct* bulkAddHostsPostStruct);

struct jsonBulkAddHostsResponseStruct*             jsonBulkAddHostsResponse(const char* json);

const char*                                        jsonBulkSetEnableHostsPost(struct jsonBulkSetEnableHostsPostStruct* bulkSetEnableHostsPostStruct);

struct jsonBulkSetEnableHostsResponseStruct*       jsonBulkSetEnableHostsResponse(const char* json);

const char*                                        jsonBulkDeleteHostsPost(struct jsonBulkDeleteHostsPostStruct* bulkDeleteHostsPostStruct);

struct jsonBulkDeleteHostsResponseStruct*          jsonBulkDeleteHostsResponse(const char* json);

#endif /* CJSON_TELEGRAM_XUI_BOT_HOSTS_H */
