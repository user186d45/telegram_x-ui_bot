#ifndef CJSON_TELEGRAM_XUI_BOT_CLIENTS_H
#define CJSON_TELEGRAM_XUI_BOT_CLIENTS_H

// clients section - https://docs.sanaei.dev/docs/reference/api/clients/

#include <stddef.h>
#include <stdint.h>


// =====================================================
// List every client
// =====================================================

struct jsonListEveryClientObjectTrafficObjectStruct {
    int64_t                     id;
    int64_t                     inboundId;
    unsigned char         enable;
    const char*                 email;
    const char*                 uuid;
    const char*                 subId;
    int64_t                     up;
    int64_t                     down;
    int64_t                     expiryTime;
    int64_t                     total;
    int                         reset;
    int64_t                     resetDay;
    int64_t                     resetMax;
    int64_t                     resetCount;
    int64_t                     lastOnline;
    int64_t                     lastSubFetch;

};



struct jsonListEveryClientArrayStruct {
    int64_t                     id;
    const char*                 email;
    const char*                 subId;
    const char*                 uuid;
    const char*                 password;
    const char*                 auth;
    const char*                 flow;
    const char*                 security;
    const char*                 privateKey;
    const char*                 publicKey;
    const char*                 allowedIps;
    const char*                 preSharedKey;
    unsigned char         keepAlive;
    const char*                 forwardedPorts;
    const char*                 secret;
    const char*                 adTag;
    int64_t                     limitIp;
    int                         limitHwid;
    int64_t                     totalGB; // Albeit named totalGB, its the total traffic of the user in BYTES
    int64_t                     expiryTime;
    unsigned char         enable;
    int64_t                     tgId;
    const char*                 group;
    const char*                 comment;
    int                         reset;
    int64_t                     resetDay;
    int64_t                     resetMax;
    const char*                 trafficReset;
    int                         trafficResetDay;
    int64_t                     createdAt; // "created_at" on server side
    int64_t                     updatedAt; // "updated_at" on server side
    const void*                 reverse; // This shall be null on normal ( not customized  ) setup
    int*                        inboundIds;
    int64_t                     inboundIdsCount;
    struct jsonListEveryClientObjectTrafficObjectStruct* listEveryCliObjTrafficObjStruct;

};



struct jsonListEveryClientStruct {
    unsigned char                 success;
    const char*                 msg;
    size_t                      jsonListEveryClientArrayStructSize;
    struct jsonListEveryClientArrayStruct* listEveryCliArrStruct; // array

};


// =====================================================
// Filter, sort and paginate clients on the server post
// and response fields
// =====================================================

struct jsonFilterClientsQueryStruct {
    int                         page; // 1-indexed page number, defaults to 1
    int                         pageSize; // rows per page, defaults to 25, capped at 200
    char*                       search; // case-insensitive substring match on email, subId,
                                        // comment, UUID, password, auth or Telegram ID
    char*                       filter; // CSV status buckets: online, active, deactive,
                                        // depleted or expiring; values are ORed
    char*                       protocol; // CSV inbound protocols: vmess, vless, trojan,
                                          // shadowsocks, wireguard, hysteria, http, mixed,
                                          // tunnel, tun, mtproto or amneziawg; ORed
    char*                       inbound; // CSV positive inbound IDs; ORed
    char*                       sort; // "enable", "email", "inboundIds", "traffic",
                                      // "remaining", "expiryTime", "createdAt", "updatedAt"
                                      // or "lastOnline"
    char*                       order; // "ascend" or "descend"
    int64_t                     expiryFrom; // inclusive minimum expiry time in unix milliseconds;
                                            // zero or negative means unset
    int64_t                     expiryTo; // inclusive maximum expiry time in unix milliseconds;
                                          // zero or negative means unbounded
    int64_t                     usageFrom; // inclusive minimum combined up+down usage in bytes;
                                           // zero means unset
    int64_t                     usageTo; // inclusive maximum combined usage in bytes; zero means
                                         // unbounded
    char*                       autoRenew; // "on" selects clients with an interval or
                                           // calendar-day reset; "off" selects clients
                                           // without either
    char*                       hasTgId; // "yes" selects clients with a non-zero Telegram ID;
                                         // "no" selects clients without one
    char*                       hasComment; // "yes" selects clients with a non-blank comment;
                                            // "no" selects clients without one
    char*                       group; // CSV group names, matched case-insensitively after
                                       // trimming; values are ORed

};



struct jsonFilterClientsObjectItemsArrayResponseStruct {
    const char*                 comment;
    int64_t                     createdAt; // "created_at" on server side
    const char*                 email;
    unsigned char               enable;
    int64_t                     expiryTime;
    const char*                 group;
    int*                        inboundIds; // every pointer presented is an element of the array
    int64_t                     inboundIdsCount;
    int                         limitHwid;
    int                         limitIp;
    int                         reset;
    int                         resetDay;
    int                         resetMax;
    const char*                 subId;
    int64_t                     totalGB; // Albeit named totalGB, its the total traffic of the
                                         // user in BYTES
    void*                       traffic; // This shall be null in the documented sample
    int64_t                     updatedAt; // "updated_at" on server side

};



struct jsonFilterClientsObjectSummaryObjectResponseStruct {
    int64_t                     active;
    const char**                deactive; // email array capped at 200 entries; every pointer
                                          // presented is an element of the array
    int64_t                     deactiveCount;
    const char**                depleted; // email array capped at 200 entries; every pointer
                                          // presented is an element of the array
    int64_t                     depletedCount;
    const char**                expiring; // email array capped at 200 entries; every pointer
                                          // presented is an element of the array
    int64_t                     expiringCount;
    const char**                online; // email array capped at 200 entries; every pointer
                                        // presented is an element of the array
    int64_t                     onlineCount;
    int64_t                     total;

};



struct jsonFilterClientsObjectResponseStruct {
    int64_t                     filtered;
    const char**                groups; // every pointer presented is an element of the array
    size_t                      jsonFilterClientsObjectItemsArrayResponseStructSize;
    struct jsonFilterClientsObjectItemsArrayResponseStruct* filterCliObjItemsArrStruct; // array
    int                         page;
    unsigned short              pageSize;
    struct jsonFilterClientsObjectSummaryObjectResponseStruct* filterCliObjSummaryObjRStruct; // Summary
    int64_t                     total;

};



struct jsonFilterClientsGroupObjectResponseStruct {
    // Functionality unknown

};



struct jsonFilterClientsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonFilterClientsObjectResponseStruct* filterCliObjRStruct;
    size_t                      jsonFilterClientsGroupObjectResponseStructSize;
    struct jsonFilterClientsGroupObjectResponseStruct* filterCliGroupObjRStruct; // array

};


// =====================================================
// Fetch details of one client by email
// =====================================================

/*
 * The response of the server to fetching by email request is not accurately
 * provided at the original documentation thus it will be introduced here:
 * {
 *   "success": true,
 *   "msg": "",
 *   "obj": {
 *     "client": {
 *       "id": 8,
 *       "email": "8h8uc11km3",
 *       "subId": "bjkv8azacpmwjpvx",
 *       "uuid": "5df6c2f8-912f-4d56-a3d7-dfa984f79c47",
 *       "password": "pbh36tewkda4tkx6",
 *       "auth": "789huvsbv650n50t",
 *       "flow": "",
 *       "security": "auto",
 *       "privateKey": "",
 *       "publicKey": "",
 *       "allowedIPs": "",
 *       "preSharedKey": "",
 *       "keepAlive": 0,
 *       "forwardedPorts": "",
 *       "secret": "",
 *       "adTag": "",
 *       "limitIp": 0,
 *       "limitHwid": 0,
 *       "totalGB": 0,
 *       "expiryTime": 0,
 *       "enable": true,
 *       "tgId": 0,
 *       "group": "",
 *       "comment": "",
 *       "reset": 0,
 *       "resetDay": 0,
 *       "resetMax": 0,
 *       "trafficReset": "never",
 *       "trafficResetDay": 1,
 *       "createdAt": 1787759859421,
 *       "updatedAt": 1787759859000,
 *       "reverse": null
 *     },
 *     "externalLinks": [],
 *     "inboundIds": [
 *       2
 *     ],
 *     "tunnelAllowedIPs": {},
 *     "usedTraffic": 29476591186
 *   }
 * }
 *
 */


struct jsonFetchClientByEmailObjectClientObjectStruct {
    int64_t                     id;
    const char*                 email;
    const char*                 subId;
    const char*                 uuid;
    const char*                 password;
    const char*                 auth;
    const char*                 flow;
    const char*                 security;
    const char*                 privateKey;
    const char*                 publicKey;
    const char*                 allowedIPs;
    const char*                 preSharedKey;
    int                         keepAlive;
    const char*                 forwardedPorts;
    const char*                 secret;
    const char*                 adTag;
    int                         limitIp;
    int                         limitHwid;
    int64_t                     totalGB; // Albeit named totalGB, its the total traffic of the user in BYTES
    int64_t                     expiryTime;
    unsigned char               enable;
    int64_t                     tgId;
    const char*                 group;
    const char*                 comment;
    int                         reset;
    int                         resetDay;
    int                         resetMax;
    const char*                 trafficReset;
    int                         trafficResetDay;
    int64_t                     createdAt;
    int64_t                     updatedAt;
    void*                       reverse; // This shall be null on normal ( not customized  ) setup

};



struct jsonFetchClientByEmailObjectExternalLinksArrayStruct {
    const char*                 kind; // "link" or "subscription"
    const char*                 value;
    const char*                 remark;
    unsigned char               enable;
    int64_t                     expiryTime;
    const char*                 namePrefix; // Omittable, "subscription" kind only

};



struct jsonFetchClientByEmailObjectStruct {
    struct jsonFetchClientByEmailObjectClientObjectStruct* fetchCliByEmailObjCliObjStruct;
    size_t                      jsonFetchClientByEmailObjectExternalLinksArrayStructSize;
    struct jsonFetchClientByEmailObjectExternalLinksArrayStruct* fetchCliByEmailObjExternalLinksArrStruct; // array
    int*                        inboundIds;
    int64_t                     inboundIdsCount;
    const char*                 tunnelAllowedIPs;
    int64_t                     usedTraffic;

};



struct jsonFetchClientByEmailStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonFetchClientByEmailObjectStruct* fetchCliByEmailObjStruct;

};


// =====================================================
// Fetch details of one client by telegram id
// =====================================================

/*
 * The response of the server to fetching by telegram id request is not accurately
 * provided at the original documentation thus it will be introduced here:
 *
 * {
 *   "success": true,
 *   "msg": "",
 *   "obj": [
 *     {
 *       "client": {
 *         "id": 9,
 *         "email": "lsadfasdfsad",
 *         "subId": "fb6b5716-c72e-4be8-b6b6-ca6fe720ba1a",
 *         "uuid": "68160944-c655-4c0f-962b-4a967af345c3",
 *         "password": "",
 *         "auth": "",
 *         "flow": "",
 *         "security": "",
 *         "privateKey": "",
 *         "publicKey": "",
 *         "allowedIPs": "",
 *         "preSharedKey": "",
 *         "keepAlive": 0,
 *         "forwardedPorts": "",
 *         "secret": "",
 *         "adTag": "",
 *         "limitIp": 2,
 *         "limitHwid": 2,
 *         "totalGB": 1,
 *         "expiryTime": 0,
 *         "enable": true,
 *         "tgId": 113146749,
 *         "group": "",
 *         "comment": "",
 *         "reset": 0,
 *         "resetDay": 0,
 *         "resetMax": 0,
 *         "trafficReset": "never",
 *         "trafficResetDay": 1,
 *         "createdAt": 1788440886056,
 *         "updatedAt": 1788440886000,
 *         "reverse": null
 *       },
 *       "externalLinks": [],
 *       "inboundIds": [
 *         2
 *       ],
 *       "tunnelAllowedIPs": {},
 *       "usedTraffic": 0
 *     }
 *   ]
 * }
 *
 */


struct jsonFetchClientByTelegramIdObjectArrayClientObjectStruct {
    int64_t                     id;
    const char*                 email;
    const char*                 subId;
    const char*                 uuid;
    const char*                 password;
    const char*                 auth;
    const char*                 flow;
    const char*                 security;
    const char*                 privateKey;
    const char*                 publicKey;
    const char*                 allowedIPs;
    const char*                 preSharedKey;
    int                         keepAlive;
    const char*                 forwardedPorts;
    const char*                 secret;
    const char*                 adTag;
    int                         limitIp;
    int                         limitHwid;
    int64_t                     totalGB; // Albeit named totalGB, its the total traffic of the user in BYTES
    int64_t                     expiryTime;
    unsigned char               enable;
    int64_t                     tgId;
    const char*                 group;
    const char*                 comment;
    int                         reset;
    int                         resetDay;
    int                         resetMax;
    const char*                 trafficReset;
    int                         trafficResetDay;
    int64_t                     createdAt;
    int64_t                     updatedAt;
    void*                       reverse; // This shall be null on normal ( not customized  ) setup

};



struct jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStruct {
    const char*                 kind; // "link" or "subscription"
    const char*                 value;
    const char*                 remark;
    unsigned char               enable;
    int64_t                     expiryTime;
    const char*                 namePrefix; // Omittable, "subscription" kind only

};



struct jsonFetchClientByTelegramIdObjectArrayStruct {
    struct jsonFetchClientByTelegramIdObjectArrayClientObjectStruct* fetchCliByTgIdObjArrCliObjStruct;
    size_t                      jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStructSize;
    struct jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStruct* fetchCliByTgIArrdObjExternalLinksArrStruct; // array
    int*                        inboundIds;
    int64_t                     inboundIdsCount;
    const char*                 tunnelAllowedIPs;
    int64_t                     usedTraffic;

};



struct jsonFetchClientByTelegramIdStruct {
    unsigned char success;
    const char* msg;
    size_t                      jsonFetchClientByTelegramIdObjectArrayStructSize;
    struct jsonFetchClientByTelegramIdObjectArrayStruct* fetchCliByTgIdObjArrStruct; // array

};


// =====================================================
// Create new client and attach it to one or more 
// inbounds post and response structs
// =====================================================

struct jsonCreateNewClientPostStruct {
    const char*                 emaill;
    int64_t                     totalGB; // Albeit named totalGB, its the total traffic of the user in BYTES
    int64_t                     expiryTime;
    int64_t                     tgId;
    int                         limitIp;
    int                         limitHwid;
    unsigned char               enable;
    int*                        inboundIds;
    int64_t                     inboundIdsCount;

};



struct jsonCreateNewClientResponseStruct {
    unsigned char success;
    const char* msg;
    void* obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Update an existing client by email post and response
// structs
// =====================================================

// The sample provided by the official documentation, lacks
// some of the fields used at the client creation process,
// i have tested the server behavior on including those fields
// and it did just fine!


struct jsonUpdateClientByEmailPostStruct {
    const char*                 emaill;
    int64_t                     totalGB; // Albeit named totalGB, its the total traffic of the user in BYTES
    int64_t                     expiryTime;
    int64_t                     tgId;
    int                         limitIp;
    int                         limitHwid;
    unsigned char               enable;
    int*                        inboundIds;
    int64_t                     inboundIdsCount;

};



struct jsonUpdateClientByEmailResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Delete a client by email response struct
// =====================================================

struct jsonDeleteClientByEmailResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Attach existing client to one or more additional
// inbounds post and response structs
// =====================================================

struct jsonAttachClient2AdditionalInboundsPostStruct {
    int*                        inboundIds;
    int64_t                     inboundIdsCount;

};



struct jsonAttachClient2AdditionalInboundsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Detach existing client to one or more additional
// inbounds post and response structs
// =====================================================

struct jsonDetachClient2AdditionalInboundsPostStruct {
    int*                        inboundIds;
    int64_t                     inboundIdsCount;

};



struct jsonDetachClient2AdditionalInboundsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Replace a client's external links and external
// subscriptions post and response structs. Sends the
// full set; the server replaces all rows. Disabled rows
// stay saved for editing but are not emitted in
// generated subscriptions. The owning client's disabled
// or expired state also stops these rows from being
// emitted on future subscription fetches; credentials
// already imported by an app remain valid until the
// external provider revokes them
// =====================================================

struct jsonExternalLinksObjectArrayPostStruct {
    const char*                 kind; // "link" or "subscription"
    const char*                 value;
    const char*                 remark;
    unsigned char               enable;
    int64_t                     expiryTime;
    const char*                 namePrefix; // Omittable, "subscription" kind only

};



struct jsonReplaceClientExternalLinksPostStruct {
    // send empty array to clear all rows
    size_t                      jsonExternalLinksObjectArrayPostStructSize;
    struct jsonExternalLinksObjectArrayPostStruct* rplExtLinksObjArrPStruct; // array

};



struct jsonReplaceClientExternalLinksResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Reset the up / down counters for every client globally
// response struct ( quotas and expiry are not affected,
// triggers an Xray restart if any counter actually
// moved )
// =====================================================

struct jsonResetAllClientsTrafficsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Delete all clients whom have exhausted quotas or
// their configurations have passed their expiry dates
// response struct
// =====================================================

struct jsonDeleteAllDepletedClientsResponseStruct {
    unsigned char*              success;
    int64_t                     deleted;

};


// =====================================================
// Delete all orphan clients ( clients whom are not
// attached to any inbound )
// =====================================================

struct jsonDeleteAllOrphanClientsResponseStruct {
    unsigned char*              success;
    int64_t                     deleted;

};


// =====================================================
// Export all clients response struct
// =====================================================

/*
 * The response of the server to exporting request is not accurately
 * provided at the original documentation thus it will be introduced here:
 *
 * {
 *   "success": true,
 *   "msg": "",
 *   "obj": [
 *     {
 *       "client": {
 *         "id": "5df6c2f8-912f-4d56-a3d7-dfa984f79c47",
 *         "security": "auto",
 *         "password": "pbh36tewkda4tkx6",
 *         "auth": "789huvsbv650n50t",
 *         "email": "8h8uc11km3",
 *         "limitIp": 0,
 *         "totalGB": 0,
 *         "expiryTime": 0,
 *         "enable": true,
 *         "tgId": 0,
 *         "subId": "bjkv8azacpmwjpvx",
 *         "comment": "",
 *         "reset": 0,
 *         "resetDay": 0,
 *         "resetMax": 0,
 *         "trafficReset": "never",
 *         "trafficResetDay": 1,
 *         "created_at": 1787759859421,
 *         "updated_at": 1787759859000,
 *         "limitHwid": 0
 *       },
 *       "inboundIds": [
 *         2
 *       ]
 *     },
 *     {
 *       "client": {
 *         "id": "02664c02-078f-4e30-a770-1b27e2c14b7a",
 *         "security": "",
 *         "email": "lsadfasdfsad",
 *         "limitIp": 2,
 *         "totalGB": 1,
 *         "expiryTime": 0,
 *         "enable": true,
 *         "tgId": 113146749,
 *         "subId": "0f2a77b9-f38e-416d-867b-30552b374015",
 *         "comment": "",
 *         "reset": 0,
 *         "resetDay": 0,
 *         "resetMax": 0,
 *         "trafficReset": "never",
 *         "trafficResetDay": 1,
 *         "created_at": 1788464936550,
 *         "updated_at": 1788465104000,
 *         "limitHwid": 2
 *       },
 *       "inboundIds": [
 *         2,
 *         3
 *       ]
 *     }
 *   ]
 * }
 *
 */


struct jsonExportAllClientsObjectArrayClientObjectResponseStruct {
    const char*                 id;
    const char*                 security;
    const char*                 password;
    const char*                 auth;
    const char*                 email;
    int                         limitIp;
    int                         totalGB;
    int64_t                     expiryTime;
    unsigned char               enable;
    int64_t                     tgId;
    const char*                 subId;
    const char*                 comment;
    int                         reset;
    int                         resetDay;
    int                         resetMax;
    const char*                 trafficReset;
    int                         trafficResetDay;
    int64_t                     createdAt; // "created_at" on server side
    int64_t                     updatedAt; // "updated_at" on server side
    int                         limitHwid;

};



struct jsonExportAllClientsObjectArrayResponseStruct {
    struct jsonExportAllClientsObjectArrayClientObjectResponseStruct* exportAllCliObjArrCliObjRStruct;
    int* inboundIds;
    int64_t                     inboundIdsCount;

};



struct jsonExportAllClientsResponseStruct {
    unsigned char success;
    const char* msg;
    size_t                      jsonExportAllClientsObjectArrayResponseStructSize;
    struct jsonExportAllClientsObjectArrayResponseStruct* exportAllClisObjArrRStruct; // array

};


// =====================================================
// Import clients post and response structs
// =====================================================

struct jsonImportClientsDataObjectPostStruct {
    const char*                 id;
    const char*                 security;
    const char*                 password;
    const char*                 auth;
    const char*                 email;
    int                         limitIp;
    int                         totalGB;
    int64_t                     expiryTime;
    unsigned char               enable;
    int64_t                     tgId;
    const char*                 subId;
    const char*                 comment;
    int                         reset;
    int                         resetDay;
    int                         resetMax;
    const char*                 trafficReset;
    int                         trafficResetDay;
    int64_t                     createdAt; // "created_at" on server side
    int64_t                     updatedAt; // "updated_at" on server side
    int                         limitHwid;

};



struct jsonImportClientsPostStruct {
    size_t                      jsonImportClientsDataObjectPostStructSize;
    struct jsonImportClientsDataObjectPostStruct* importClientsDataObjPStruct; // array

};



struct jsonImportClientsObjectSkippedArrayResponseStruct {
    const char* email;
    const char* reason;

};



struct jsonImportClientsObjectResponseStruct {
    int64_t created;
    size_t                      jsonImportClientsObjectSkippedArrayResponseStructSize;
    struct jsonImportClientsObjectSkippedArrayResponseStruct* importClisObjSkippedArrRStruct; // array

};



struct jsonImportClientsResponseStruct {
    unsigned char success;
    const char* msg;
    struct jsonImportClientsObjectResponseStruct* importClisObjRStruct;

};


// =====================================================
// Bulk adjust clients' expiry times or their quota (
// allowed data to use ), works for clients whom have
// limited expiry dates or quotas post and response structs.
// Shift expiry and / or
// traffic quota for many clients in one call. addDays /
// addBytes may be negative. Clients with unlimited expiry
// ( expiryTime = 0 ) or unlimited traffic ( totalGB = 0 )
// are skipped for the corresponding field — bulk extend
// never converts unlimited to limited. A client that was
// auto-disabled solely because it was depleted ( expired
// or over quota ) is automatically re-enabled — locally
// and on its node — when the adjustment lifts it out of
// depletion; a manually-disabled or still-depleted client
// is left disabled. The optional flow directive sets the
// XTLS flow on every client: "none" clears it,
// "xtls-rprx-vision"/"xtls-rprx-vision-udp443" set it
// where the inbound supports it (omit or "" to leave it
// unchanged). Returns the adjusted count and per-email
// skip reasons.
// =====================================================

struct jsonBulkAdjustClientsPostStruct {
    const char**                emails;
    int                         addDays;
    int64_t                     addBytes;
    const char*                 flow; // Omittable

};



struct jsonBulkAdjustClientsObjectSkippedArrayResponseStruct {
    const char*                 email;
    const char*                 reason;

};



struct jsonBulkAdjustClientsObjectResponseStruct {
    int64_t                     adjusted;
    size_t                      jsonBulkAdjustClientsObjectSkippedArrayResponseStructSize;
    struct jsonBulkAdjustClientsObjectSkippedArrayResponseStruct* bulkAdjClisObjSkippedArrRStruct; // array

};



struct jsonBulkAdjustClientsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonBulkAdjustClientsObjectResponseStruct* bulkAdjClisObjRStruct;

};


// =====================================================
// Bulk enable clients post and response structs (
// Enable many clients in one call ).
// =====================================================

struct jsonBulkEnableClientsPostStruct {
    const char**                emails;

};



struct jsonBulkEnableClientsObjectSkippedArrayResponseStruct {
    const char*                 email;
    const char*                 reason;

};




struct jsonBulkEnableClientsObjectResponseStruct {
    int64_t                     changed;
    size_t                      jsonBulkEnableClientsObjectSkippedArrayResponseStructSize;
    struct jsonBulkEnableClientsObjectSkippedArrayResponseStruct* bulkEnableClisObjSkippedArrRStruct; // array

};



struct jsonBulkEnableClientsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonBulkEnableClientsObjectResponseStruct* bulkEnableClisObjRStruct;

};


// =====================================================
// Bulk disable clients post and response structs (
// Disable many clients in one call ).
// =====================================================

struct jsonBulkDisableClientsPostStruct {
    const char**                emails;

};



struct jsonBulkDisableClientsObjectSkippedArrayResponseStruct {
    const char*                 email;
    const char*                 reason;

};




struct jsonBulkDisableClientsObjectResponseStruct {
    int64_t                     changed;
    size_t                      jsonBulkDisableClientsObjectSkippedArrayResponseStructSize;
    struct jsonBulkDisableClientsObjectSkippedArrayResponseStruct* bulkDisableClisObjSkippedArrRStruct; // array

};



struct jsonBulkDisableClientsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonBulkDisableClientsObjectResponseStruct* bulkDisableClisObjRStruct;

};


// =====================================================
// Bulk delete clients post and response structs (
// Delete many clients in one call ).
// =====================================================

struct jsonBulkDeleteClientsPostStruct {
    const char**                emails;
    unsigned char               keepTraffic;

};



struct jsonBulkDeleteClientsObjectSkippedArrayResponseStruct {
    const char*                 email;
    const char*                 reason;

};




struct jsonBulkDeleteClientsObjectResponseStruct {
    int64_t                     deleted;
    size_t                      jsonBulkDeleteClientsObjectSkippedArrayResponseStructSize;
    struct jsonBulkDeleteClientsObjectSkippedArrayResponseStruct* bulkDelClisObjSkippedArrRStruct; // array

};



struct jsonBulkDeleteClientsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonBulkDeleteClientsObjectResponseStruct* bulkDelClisObjRStruct;

};


// =====================================================
// Bulk create clients post and response structs (
// Create many clients in one call ).
// =====================================================

struct jsonBulkCreateClientsMainObjectPostStruct {
    const char*                 email;
    int64_t                     totalGB; // Albeit named totalGB, its the total traffic of the user in BYTES
    int64_t                     expiryTime;
    int                         limitHwid;
    unsigned char               enable;
    int*                        inboundIds;
    int64_t                     inboundIdsCount;

};



struct jsonBulkCreateClientsPostStruct {
    size_t                      jsonBulkCreateClientsMainObjectPostStructSize;
    struct jsonBulkCreateClientsMainObjectPostStruct* bulkCreateClisMainObjPStruct; // array

};



struct jsonBulkCreateClientsObjectSkippedArrayResponseStruct {
    const char*                 email;
    const char*                 reason;

};




struct jsonBulkCreateClientsObjectResponseStruct {
    int64_t                     created;
    size_t                      jsonBulkCreateClientsObjectSkippedArrayResponseStructSize;
    struct jsonBulkCreateClientsObjectSkippedArrayResponseStruct* bulkCreateClisObjSkippedArrRStruct; // array

};



struct jsonBulkCreateClientsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonBulkCreateClientsObjectResponseStruct* bulkCreateClisObjRStruct;

};


// =====================================================
// Add many clients to a group in one call post and
// response structs. Updates clients.group_name and
// patches the matching client entry inside every owning
// inbound's settings JSON in a single transaction. If
// the group name does not yet exist ( in client_groups
// or as a derived label ), it is auto-created as a
// persistent group. To clear the group label, use
// /groups/bulkRemove instead
// =====================================================

struct jsonBulkAddClients2GroupPostStruct {
    const char**                emails;
    const char*                 group;

};



struct jsonBulkAddClients2GroupObjectResponseStruct {
    int64_t                     affected;

};



struct jsonBulkAddClients2GroupResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonBulkAddClients2GroupObjectResponseStruct* bulkAddClis2GroupObjRStruct;

};


// =====================================================
// Clear the group label on many clients in one call post
// and response structs ( inverse of /groups/bulkAdd ).
// Clients themselves are kept — only the group label is
// cleared from clients.group_name and from each owning
// inbound's settings JSON. Groups become empty if all
// their members are removed
// =====================================================

struct jsonBulkRemoveClientsGroupPostStruct {
    const char**                emails;

};



struct jsonBulkRemoveClientsGroupObjectResponseStruct {
    int64_t                     affected;

};



struct jsonBulkRemoveClientsGroupResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonBulkRemoveClientsGroupObjectResponseStruct* bulkRmCliGroupObjRStruct;

};


// =====================================================
// Attach many existing clients to many inbounds in one
// call post and response structs. Each client keeps its
// identity ( email / UUID / password / subId ) and a
// shared traffic row; all clients are added to a target
// inbound in a single AddInboundClient call. Clients
// already present on a target are reported under
// skipped. Returns per-email attached / skipped / errors
// lists and triggers a single Xray restart if any target
// inbound was running
// =====================================================

struct jsonBulkAttachClientsPostStruct {
    const char**                emails;
    int*                        inboundIds;
    int64_t                     inboundIdsCount;

};



struct jsonBulkAttachClientsObjectResponseStruct {
    const char**                attached;
    const char**                skipped;
    const char**                errors;

};



struct jsonBulkAttachClientsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonBulkAttachClientsObjectResponseStruct* bulkAttachClisObjRStruct;

};


// =====================================================
// Detach many existing clients from many inbounds in one
// call post and response structs. For each email,
// intersects the client's current inbounds with the
// requested set and detaches from those only; (
// email, inbound ) pairs where the client is not
// currently attached are silently no-ops. Emails not
// attached to any of the requested inbounds are reported
// under skipped. Client records are kept even if they
// become orphaned — use bulkDel for full removal.
// Returns per-email detached / skipped / errors lists
// and triggers a single Xray restart if any target
// inbound was running
// =====================================================

struct jsonBulkDetachClientsPostStruct {
    const char**                emails;
    int*                        inboundIds;
    int64_t                     inboundIdsCount;

};



struct jsonBulkDetachClientsObjectResponseStruct {
    const char**                detached;
    const char**                skipped;
    const char**                errors;

};



struct jsonBulkDetachClientsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonBulkDetachClientsObjectResponseStruct* bulkDetachClisObjRStruct;

};


// =====================================================
// Bulk reset the up/down counters of many clients at
// once ( each client is re-enabled across its attached
// inbounds and pushed to Xray/remote nodes ) post and
// response structs
// =====================================================

struct jsonBulkResetTrafficPostStruct {
    const char**                emails;

};



struct jsonBulkResetTrafficObjectResponseStruct {
    int64_t                     affected;

};



struct jsonBulkResetTrafficResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonBulkResetTrafficObjectResponseStruct* bulkResetTrafficObjRStruct;

};


// =====================================================
// Client groups : list, member emails, create, rename,
// delete and reset group traffic post and response
// structs
// =====================================================

struct jsonListGroupsObjectArrayStruct {
    const char*                 name;
    int64_t                     clientCount;

};



struct jsonListGroupsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      jsonListGroupsObjectArrayStructSize;
    struct jsonListGroupsObjectArrayStruct* listGroupsObjArrStruct; // array

};



struct jsonListGroupEmailsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char**                obj; // every pointer presented is an element of the array

};



struct jsonCreateGroupPostStruct {
    const char*                 name;

};



struct jsonCreateGroupObjectResponseStruct {
    const char*                 name;

};



struct jsonCreateGroupResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonCreateGroupObjectResponseStruct* createGroupObjRStruct;

};



struct jsonRenameGroupPostStruct {
    const char*                 oldName;
    const char*                 newName;

};



struct jsonRenameGroupObjectResponseStruct {
    int64_t                     affected;

};



struct jsonRenameGroupResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonRenameGroupObjectResponseStruct* renameGroupObjRStruct;

};



struct jsonDeleteGroupPostStruct {
    const char*                 name;

};



struct jsonDeleteGroupObjectResponseStruct {
    int64_t                     affected;

};



struct jsonDeleteGroupResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonDeleteGroupObjectResponseStruct* deleteGroupObjRStruct;

};



struct jsonResetGroupTrafficPostStruct {
    const char*                 name;

};



struct jsonResetGroupTrafficObjectResponseStruct {
    const char*                 name;

};



struct jsonResetGroupTrafficResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonResetGroupTrafficObjectResponseStruct* resetGroupTrafficObjRStruct;

};


// =====================================================
// Single-client traffic management : zero out the
// up/down counters, manually adjust them, list the
// recorded source IPs or clear them, and manage the
// registered HWID devices post and response structs
// =====================================================

struct jsonResetClientTrafficResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};



struct jsonUpdateClientTrafficPostStruct {
    int64_t                     upload;
    int64_t                     download;

};



struct jsonUpdateClientTrafficResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};



struct jsonListClientIpsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char**                obj; // The endpoint documentation describes the obj as an
                                     // array of "ip (timestamp)" strings, while its documented
                                     // sample response shows null ( undefined behavior )

};



struct jsonClearClientIpsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};



struct jsonListClientHwidsObjectArrayStruct {
    int64_t                     id;
    int64_t                     firstSeen;
    int64_t                     lastSeen;
    const char*                 userAgent;
    const char*                 deviceOs;
    const char*                 osVersion;
    const char*                 deviceModel;

};



struct jsonListClientHwidsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      jsonListClientHwidsObjectArrayStructSize;
    struct jsonListClientHwidsObjectArrayStruct* listClientHwidsObjArrStruct; // array

};



struct jsonClearClientHwidsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};



struct jsonDeleteClientHwidResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Online client detection and per-client status : list
// online clients ( flat, by node GUID, per-inbound
// activity ), last-seen map, traffic counters, subscription
// links and share links post and response structs
// =====================================================

struct jsonOnlinesResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char**                obj; // every pointer presented is an element of the array

};



struct jsonOnlinesByGuidResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // JSON object keyed by the panelGuid of the hosting node,
                                     // each value being the array of online client emails;
                                     // dynamic keys cannot be modeled by a C struct
                                     // ( undefined behavior )

};



struct jsonClientIpsByGuidResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // JSON object keyed by the panelGuid of the observing
                                     // node, each value mapping a client email to the array of
                                     // { ip, timestamp } items that node saw; dynamic keys
                                     // cannot be modeled by a C struct ( undefined behavior )

};



struct jsonActiveInboundsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // JSON object keyed by the panelGuid of the hosting node,
                                     // each value being the array of inbound tags that carried
                                     // traffic in the heartbeat window; dynamic keys cannot
                                     // be modeled by a C struct ( undefined behavior )

};



struct jsonLastOnlineResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // JSON object mapping each client email to its last-seen
                                     // unix timestamp; dynamic keys cannot be modeled by a C
                                     // struct ( undefined behavior )

};



struct jsonTrafficResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonListEveryClientObjectTrafficObjectStruct* trafficObjRStruct; // shape shared with
                                                                            // the traffic object
                                                                            // of /clients/list

};



struct jsonSubLinksResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char**                obj; // every pointer presented is an element of the array

};



struct jsonLinksResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char**                obj; // every pointer presented is an element of the array

};

void        jsonListEveryClientObjectTrafficObjectStructDelete(struct jsonListEveryClientObjectTrafficObjectStruct* listEveryCliObjTrafficObjStruct);

void        jsonListEveryClientArrayStructDelete(struct jsonListEveryClientArrayStruct* listEveryCliArrStruct, size_t arraySize);

void        jsonListEveryClientStructDelete(struct jsonListEveryClientStruct* listEveryCliStruct);

void        jsonFilterClientsQueryStructDelete(struct jsonFilterClientsQueryStruct* filterCliQueryStruct);

void        jsonFilterClientsObjectItemsArrayResponseStructDelete(struct jsonFilterClientsObjectItemsArrayResponseStruct* filterCliObjItemsArrStruct, size_t arraySize);

void        jsonFilterClientsObjectSummaryObjectResponseStructDelete(struct jsonFilterClientsObjectSummaryObjectResponseStruct* filterCliObjSummaryObjRStruct);

void        jsonFilterClientsObjectResponseStructDelete(struct jsonFilterClientsObjectResponseStruct* filterCliObjRStruct);

void        jsonFilterClientsGroupObjectResponseStructDelete(struct jsonFilterClientsGroupObjectResponseStruct* filterCliGroupObjRStruct, size_t arraySize);

void        jsonFilterClientsResponseStructDelete(struct jsonFilterClientsResponseStruct* filterCliRStruct);

void        jsonFetchClientByEmailObjectClientObjectStructDelete(struct jsonFetchClientByEmailObjectClientObjectStruct* fetchCliByEmailObjCliObjStruct);

void        jsonFetchClientByEmailObjectExternalLinksArrayStructDelete(struct jsonFetchClientByEmailObjectExternalLinksArrayStruct* fetchCliByEmailObjExternalLinksArrStruct, size_t arraySize);

void        jsonFetchClientByEmailObjectStructDelete(struct jsonFetchClientByEmailObjectStruct* fetchCliByEmailObjStruct);

void        jsonFetchClientByEmailStructDelete(struct jsonFetchClientByEmailStruct* fetchCliByEmailStruct);

void        jsonFetchClientByTelegramIdObjectArrayClientObjectStructDelete(struct jsonFetchClientByTelegramIdObjectArrayClientObjectStruct* fetchCliByTgIdObjArrCliObjStruct);

void        jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStructDelete(struct jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStruct* fetchCliByTgIArrdObjExternalLinksArrStruct, size_t arraySize);

void        jsonFetchClientByTelegramIdObjectArrayStructDelete(struct jsonFetchClientByTelegramIdObjectArrayStruct* fetchCliByTgIdObjArrStruct, size_t arraySize);

void        jsonFetchClientByTelegramIdStructDelete(struct jsonFetchClientByTelegramIdStruct* fetchCliByTelegramIdStruct);

void        jsonCreateNewClientPostStructDelete(struct jsonCreateNewClientPostStruct* createNewClientPostStruct);

void        jsonCreateNewClientResponseStructDelete(struct jsonCreateNewClientResponseStruct* createNewCliRStruct);

void        jsonUpdateClientByEmailPostStructDelete(struct jsonUpdateClientByEmailPostStruct* updateClientByEmailPostStruct);

void        jsonUpdateClientByEmailResponseStructDelete(struct jsonUpdateClientByEmailResponseStruct* updateCliByEmailRStruct);

void        jsonDeleteClientByEmailResponseStructDelete(struct jsonDeleteClientByEmailResponseStruct* deleteCliByEmailRStruct);

void        jsonAttachClient2AdditionalInboundsPostStructDelete(struct jsonAttachClient2AdditionalInboundsPostStruct* attachClient2AdditionalInboundsPostStruct);

void        jsonAttachClient2AdditionalInboundsResponseStructDelete(struct jsonAttachClient2AdditionalInboundsResponseStruct* attachCli2AdditionalInboundsRStruct);

void        jsonDetachClient2AdditionalInboundsPostStructDelete(struct jsonDetachClient2AdditionalInboundsPostStruct* detachClient2AdditionalInboundsPostStruct);

void        jsonDetachClient2AdditionalInboundsResponseStructDelete(struct jsonDetachClient2AdditionalInboundsResponseStruct* detachCli2AdditionalInboundsRStruct);

void        jsonExternalLinksObjectArrayPostStructDelete(struct jsonExternalLinksObjectArrayPostStruct* rplExtLinksObjArrPStruct, size_t arraySize);

void        jsonReplaceClientExternalLinksPostStructDelete(struct jsonReplaceClientExternalLinksPostStruct* replaceClientExternalLinksPostStruct);

void        jsonReplaceClientExternalLinksResponseStructDelete(struct jsonReplaceClientExternalLinksResponseStruct* replaceCliExternalLinksRStruct);

void        jsonResetAllClientsTrafficsResponseStructDelete(struct jsonResetAllClientsTrafficsResponseStruct* resetAllCliTrafficsRStruct);

void        jsonDeleteAllDepletedClientsResponseStructDelete(struct jsonDeleteAllDepletedClientsResponseStruct* deleteAllDepletedCliRStruct);

void        jsonDeleteAllOrphanClientsResponseStructDelete(struct jsonDeleteAllOrphanClientsResponseStruct* deleteAllOrphanCliRStruct);

void        jsonExportAllClientsObjectArrayClientObjectResponseStructDelete(struct jsonExportAllClientsObjectArrayClientObjectResponseStruct* exportAllCliObjArrCliObjRStruct);

void        jsonExportAllClientsObjectArrayResponseStructDelete(struct jsonExportAllClientsObjectArrayResponseStruct* exportAllClisObjArrRStruct, size_t arraySize);

void        jsonExportAllClientsResponseStructDelete(struct jsonExportAllClientsResponseStruct* exportAllCliRStruct);

void        jsonImportClientsDataObjectPostStructDelete(struct jsonImportClientsDataObjectPostStruct* importClientsDataObjPStruct, size_t arraySize);

void        jsonImportClientsPostStructDelete(struct jsonImportClientsPostStruct* importClientsPostStruct);

void        jsonImportClientsObjectSkippedArrayResponseStructDelete(struct jsonImportClientsObjectSkippedArrayResponseStruct* importClisObjSkippedArrRStruct, size_t arraySize);

void        jsonImportClientsObjectResponseStructDelete(struct jsonImportClientsObjectResponseStruct* importClisObjRStruct);

void        jsonImportClientsResponseStructDelete(struct jsonImportClientsResponseStruct* importCliRStruct);

void        jsonBulkAdjustClientsPostStructDelete(struct jsonBulkAdjustClientsPostStruct* bulkAdjustClientsPostStruct);

void        jsonBulkAdjustClientsObjectSkippedArrayResponseStructDelete(struct jsonBulkAdjustClientsObjectSkippedArrayResponseStruct* bulkAdjClisObjSkippedArrRStruct, size_t arraySize);

void        jsonBulkAdjustClientsObjectResponseStructDelete(struct jsonBulkAdjustClientsObjectResponseStruct* bulkAdjClisObjRStruct);

void        jsonBulkAdjustClientsResponseStructDelete(struct jsonBulkAdjustClientsResponseStruct* bulkAdjustCliRStruct);

void        jsonBulkEnableClientsPostStructDelete(struct jsonBulkEnableClientsPostStruct* bulkEnableClientsPostStruct);

void        jsonBulkEnableClientsObjectSkippedArrayResponseStructDelete(struct jsonBulkEnableClientsObjectSkippedArrayResponseStruct* bulkEnableClisObjSkippedArrRStruct, size_t arraySize);

void        jsonBulkEnableClientsObjectResponseStructDelete(struct jsonBulkEnableClientsObjectResponseStruct* bulkEnableClisObjRStruct);

void        jsonBulkEnableClientsResponseStructDelete(struct jsonBulkEnableClientsResponseStruct* bulkEnableCliRStruct);

void        jsonBulkDisableClientsPostStructDelete(struct jsonBulkDisableClientsPostStruct* bulkDisableClientsPostStruct);

void        jsonBulkDisableClientsObjectSkippedArrayResponseStructDelete(struct jsonBulkDisableClientsObjectSkippedArrayResponseStruct* bulkDisableClisObjSkippedArrRStruct, size_t arraySize);

void        jsonBulkDisableClientsObjectResponseStructDelete(struct jsonBulkDisableClientsObjectResponseStruct* bulkDisableClisObjRStruct);

void        jsonBulkDisableClientsResponseStructDelete(struct jsonBulkDisableClientsResponseStruct* bulkDisableCliRStruct);

void        jsonBulkDeleteClientsPostStructDelete(struct jsonBulkDeleteClientsPostStruct* bulkDeleteClientsPostStruct);

void        jsonBulkDeleteClientsObjectSkippedArrayResponseStructDelete(struct jsonBulkDeleteClientsObjectSkippedArrayResponseStruct* bulkDelClisObjSkippedArrRStruct, size_t arraySize);

void        jsonBulkDeleteClientsObjectResponseStructDelete(struct jsonBulkDeleteClientsObjectResponseStruct* bulkDelClisObjRStruct);

void        jsonBulkDeleteClientsResponseStructDelete(struct jsonBulkDeleteClientsResponseStruct* bulkDeleteCliRStruct);

void        jsonBulkCreateClientsMainObjectPostStructDelete(struct jsonBulkCreateClientsMainObjectPostStruct* bulkCreateClisMainObjPStruct, size_t arraySize);

void        jsonBulkCreateClientsPostStructDelete(struct jsonBulkCreateClientsPostStruct* bulkCreateClientsPostStruct);

void        jsonBulkCreateClientsObjectSkippedArrayResponseStructDelete(struct jsonBulkCreateClientsObjectSkippedArrayResponseStruct* bulkCreateClisObjSkippedArrRStruct, size_t arraySize);

void        jsonBulkCreateClientsObjectResponseStructDelete(struct jsonBulkCreateClientsObjectResponseStruct* bulkCreateClisObjRStruct);

void        jsonBulkCreateClientsResponseStructDelete(struct jsonBulkCreateClientsResponseStruct* bulkCreateCliRStruct);

void        jsonBulkAddClients2GroupPostStructDelete(struct jsonBulkAddClients2GroupPostStruct* bulkAddClients2GroupPostStruct);

void        jsonBulkAddClients2GroupObjectResponseStructDelete(struct jsonBulkAddClients2GroupObjectResponseStruct* bulkAddClis2GroupObjRStruct);

void        jsonBulkAddClients2GroupResponseStructDelete(struct jsonBulkAddClients2GroupResponseStruct* bulkAddCli2GroupRStruct);

void        jsonBulkRemoveClientsGroupPostStructDelete(struct jsonBulkRemoveClientsGroupPostStruct* bulkRemoveClientsGroupPostStruct);

void        jsonBulkRemoveClientsGroupObjectResponseStructDelete(struct jsonBulkRemoveClientsGroupObjectResponseStruct* bulkRmCliGroupObjRStruct);

void        jsonBulkRemoveClientsGroupResponseStructDelete(struct jsonBulkRemoveClientsGroupResponseStruct* bulkRmCliGroupRStruct);

void        jsonBulkAttachClientsPostStructDelete(struct jsonBulkAttachClientsPostStruct* bulkAttachClientsPostStruct);

void        jsonBulkAttachClientsObjectResponseStructDelete(struct jsonBulkAttachClientsObjectResponseStruct* bulkAttachClisObjRStruct);

void        jsonBulkAttachClientsResponseStructDelete(struct jsonBulkAttachClientsResponseStruct* bulkAttachCliRStruct);

void        jsonBulkDetachClientsPostStructDelete(struct jsonBulkDetachClientsPostStruct* bulkDetachClientsPostStruct);

void        jsonBulkDetachClientsObjectResponseStructDelete(struct jsonBulkDetachClientsObjectResponseStruct* bulkDetachClisObjRStruct);

void        jsonBulkDetachClientsResponseStructDelete(struct jsonBulkDetachClientsResponseStruct* bulkDetachCliRStruct);

void        jsonBulkResetTrafficPostStructDelete(struct jsonBulkResetTrafficPostStruct* bulkResetTrafficPostStruct);

void        jsonBulkResetTrafficObjectResponseStructDelete(struct jsonBulkResetTrafficObjectResponseStruct* bulkResetTrafficObjRStruct);

void        jsonBulkResetTrafficResponseStructDelete(struct jsonBulkResetTrafficResponseStruct* bulkResetTrafficRStruct);

void        jsonListGroupsObjectArrayStructDelete(struct jsonListGroupsObjectArrayStruct* listGroupsObjArrStruct, size_t arraySize);

void        jsonListGroupsResponseStructDelete(struct jsonListGroupsResponseStruct* listGroupsRStruct);

void        jsonListGroupEmailsResponseStructDelete(struct jsonListGroupEmailsResponseStruct* listGroupEmailsRStruct);

void        jsonCreateGroupPostStructDelete(struct jsonCreateGroupPostStruct* createGroupPostStruct);

void        jsonCreateGroupObjectResponseStructDelete(struct jsonCreateGroupObjectResponseStruct* createGroupObjRStruct);

void        jsonCreateGroupResponseStructDelete(struct jsonCreateGroupResponseStruct* createGroupRStruct);

void        jsonRenameGroupPostStructDelete(struct jsonRenameGroupPostStruct* renameGroupPostStruct);

void        jsonRenameGroupObjectResponseStructDelete(struct jsonRenameGroupObjectResponseStruct* renameGroupObjRStruct);

void        jsonRenameGroupResponseStructDelete(struct jsonRenameGroupResponseStruct* renameGroupRStruct);

void        jsonDeleteGroupPostStructDelete(struct jsonDeleteGroupPostStruct* deleteGroupPostStruct);

void        jsonDeleteGroupObjectResponseStructDelete(struct jsonDeleteGroupObjectResponseStruct* deleteGroupObjRStruct);

void        jsonDeleteGroupResponseStructDelete(struct jsonDeleteGroupResponseStruct* deleteGroupRStruct);

void        jsonResetGroupTrafficPostStructDelete(struct jsonResetGroupTrafficPostStruct* resetGroupTrafficPostStruct);

void        jsonResetGroupTrafficObjectResponseStructDelete(struct jsonResetGroupTrafficObjectResponseStruct* resetGroupTrafficObjRStruct);

void        jsonResetGroupTrafficResponseStructDelete(struct jsonResetGroupTrafficResponseStruct* resetGroupTrafficRStruct);

void        jsonResetClientTrafficResponseStructDelete(struct jsonResetClientTrafficResponseStruct* resetCliTrafficRStruct);

void        jsonUpdateClientTrafficPostStructDelete(struct jsonUpdateClientTrafficPostStruct* updateClientTrafficPostStruct);

void        jsonUpdateClientTrafficResponseStructDelete(struct jsonUpdateClientTrafficResponseStruct* updateCliTrafficRStruct);

void        jsonListClientIpsResponseStructDelete(struct jsonListClientIpsResponseStruct* listCliIpsRStruct);

void        jsonClearClientIpsResponseStructDelete(struct jsonClearClientIpsResponseStruct* clearCliIpsRStruct);

void        jsonListClientHwidsObjectArrayStructDelete(struct jsonListClientHwidsObjectArrayStruct* listClientHwidsObjArrStruct, size_t arraySize);

void        jsonListClientHwidsResponseStructDelete(struct jsonListClientHwidsResponseStruct* listCliHwidsRStruct);

void        jsonClearClientHwidsResponseStructDelete(struct jsonClearClientHwidsResponseStruct* clearCliHwidsRStruct);

void        jsonDeleteClientHwidResponseStructDelete(struct jsonDeleteClientHwidResponseStruct* deleteCliHwidRStruct);

void        jsonOnlinesResponseStructDelete(struct jsonOnlinesResponseStruct* onlinesRStruct);

void        jsonOnlinesByGuidResponseStructDelete(struct jsonOnlinesByGuidResponseStruct* onlinesByGuidRStruct);

void        jsonClientIpsByGuidResponseStructDelete(struct jsonClientIpsByGuidResponseStruct* cliIpsByGuidRStruct);

void        jsonActiveInboundsResponseStructDelete(struct jsonActiveInboundsResponseStruct* activeInboundsRStruct);

void        jsonLastOnlineResponseStructDelete(struct jsonLastOnlineResponseStruct* lastOnlineRStruct);

void        jsonTrafficResponseStructDelete(struct jsonTrafficResponseStruct* trafficRStruct);

void        jsonSubLinksResponseStructDelete(struct jsonSubLinksResponseStruct* subLinksRStruct);

void        jsonLinksResponseStructDelete(struct jsonLinksResponseStruct* linksRStruct);

struct jsonListEveryClientStruct*                  jsonListEveryClient(const char* json);

struct jsonFilterClientsQueryStruct*               jsonFilterClientsQuery(const char* json);

struct jsonFilterClientsResponseStruct*            jsonFilterClientsResponse(const char* json);

struct jsonFetchClientByEmailStruct*               jsonFetchClientByEmail(const char* json);

struct jsonFetchClientByTelegramIdStruct*          jsonFetchClientByTelegramId(const char* json);

const char*                                        jsonCreateNewClientPost(struct jsonCreateNewClientPostStruct* createNewClientPostStruct);

struct jsonCreateNewClientResponseStruct*          jsonCreateNewClientResponse(const char* json);

const char*                                        jsonUpdateClientByEmailPost(struct jsonUpdateClientByEmailPostStruct* updateClientByEmailPostStruct);

struct jsonUpdateClientByEmailResponseStruct*      jsonUpdateClientByEmailResponse(const char* json);

struct jsonDeleteClientByEmailResponseStruct*      jsonDeleteClientByEmailResponse(const char* json);

const char*                                        jsonAttachClient2AdditionalInboundsPost(struct jsonAttachClient2AdditionalInboundsPostStruct* attachClient2AdditionalInboundsPostStruct);

struct jsonAttachClient2AdditionalInboundsResponseStruct* jsonAttachClient2AdditionalInboundsResponse(const char* json);

const char*                                        jsonDetachClient2AdditionalInboundsPost(struct jsonDetachClient2AdditionalInboundsPostStruct* detachClient2AdditionalInboundsPostStruct);

struct jsonDetachClient2AdditionalInboundsResponseStruct* jsonDetachClient2AdditionalInboundsResponse(const char* json);

const char*                                        jsonReplaceClientExternalLinksPost(struct jsonReplaceClientExternalLinksPostStruct* replaceClientExternalLinksPostStruct);

struct jsonReplaceClientExternalLinksResponseStruct* jsonReplaceClientExternalLinksResponse(const char* json);

struct jsonResetAllClientsTrafficsResponseStruct*  jsonResetAllClientsTrafficsResponse(const char* json);

struct jsonDeleteAllDepletedClientsResponseStruct* jsonDeleteAllDepletedClientsResponse(const char* json);

struct jsonDeleteAllOrphanClientsResponseStruct*   jsonDeleteAllOrphanClientsResponse(const char* json);

struct jsonExportAllClientsResponseStruct*         jsonExportAllClientsResponse(const char* json);

const char*                                        jsonImportClientsPost(struct jsonImportClientsPostStruct* importClientsPostStruct);

struct jsonImportClientsResponseStruct*            jsonImportClientsResponse(const char* json);

const char*                                        jsonBulkAdjustClientsPost(struct jsonBulkAdjustClientsPostStruct* bulkAdjustClientsPostStruct);

struct jsonBulkAdjustClientsResponseStruct*        jsonBulkAdjustClientsResponse(const char* json);

const char*                                        jsonBulkEnableClientsPost(struct jsonBulkEnableClientsPostStruct* bulkEnableClientsPostStruct);

struct jsonBulkEnableClientsResponseStruct*        jsonBulkEnableClientsResponse(const char* json);

const char*                                        jsonBulkDisableClientsPost(struct jsonBulkDisableClientsPostStruct* bulkDisableClientsPostStruct);

struct jsonBulkDisableClientsResponseStruct*       jsonBulkDisableClientsResponse(const char* json);

const char*                                        jsonBulkDeleteClientsPost(struct jsonBulkDeleteClientsPostStruct* bulkDeleteClientsPostStruct);

struct jsonBulkDeleteClientsResponseStruct*        jsonBulkDeleteClientsResponse(const char* json);

const char*                                        jsonBulkCreateClientsPost(struct jsonBulkCreateClientsPostStruct* bulkCreateClientsPostStruct);

struct jsonBulkCreateClientsResponseStruct*        jsonBulkCreateClientsResponse(const char* json);

const char*                                        jsonBulkAddClients2GroupPost(struct jsonBulkAddClients2GroupPostStruct* bulkAddClients2GroupPostStruct);

struct jsonBulkAddClients2GroupResponseStruct*     jsonBulkAddClients2GroupResponse(const char* json);

const char*                                        jsonBulkRemoveClientsGroupPost(struct jsonBulkRemoveClientsGroupPostStruct* bulkRemoveClientsGroupPostStruct);

struct jsonBulkRemoveClientsGroupResponseStruct*   jsonBulkRemoveClientsGroupResponse(const char* json);

const char*                                        jsonBulkAttachClientsPost(struct jsonBulkAttachClientsPostStruct* bulkAttachClientsPostStruct);

struct jsonBulkAttachClientsResponseStruct*        jsonBulkAttachClientsResponse(const char* json);

const char*                                        jsonBulkDetachClientsPost(struct jsonBulkDetachClientsPostStruct* bulkDetachClientsPostStruct);

struct jsonBulkDetachClientsResponseStruct*        jsonBulkDetachClientsResponse(const char* json);

const char*                                        jsonBulkResetTrafficPost(struct jsonBulkResetTrafficPostStruct* bulkResetTrafficPostStruct);

struct jsonBulkResetTrafficResponseStruct*         jsonBulkResetTrafficResponse(const char* json);

struct jsonListGroupsResponseStruct*               jsonListGroupsResponse(const char* json);

struct jsonListGroupEmailsResponseStruct*          jsonListGroupEmailsResponse(const char* json);

const char*                                        jsonCreateGroupPost(struct jsonCreateGroupPostStruct* createGroupPostStruct);

struct jsonCreateGroupResponseStruct*              jsonCreateGroupResponse(const char* json);

const char*                                        jsonRenameGroupPost(struct jsonRenameGroupPostStruct* renameGroupPostStruct);

struct jsonRenameGroupResponseStruct*              jsonRenameGroupResponse(const char* json);

const char*                                        jsonDeleteGroupPost(struct jsonDeleteGroupPostStruct* deleteGroupPostStruct);

struct jsonDeleteGroupResponseStruct*              jsonDeleteGroupResponse(const char* json);

const char*                                        jsonResetGroupTrafficPost(struct jsonResetGroupTrafficPostStruct* resetGroupTrafficPostStruct);

struct jsonResetGroupTrafficResponseStruct*        jsonResetGroupTrafficResponse(const char* json);

struct jsonResetClientTrafficResponseStruct*       jsonResetClientTrafficResponse(const char* json);

const char*                                        jsonUpdateClientTrafficPost(struct jsonUpdateClientTrafficPostStruct* updateClientTrafficPostStruct);

struct jsonUpdateClientTrafficResponseStruct*      jsonUpdateClientTrafficResponse(const char* json);

struct jsonListClientIpsResponseStruct*            jsonListClientIpsResponse(const char* json);

struct jsonClearClientIpsResponseStruct*           jsonClearClientIpsResponse(const char* json);

struct jsonListClientHwidsResponseStruct*          jsonListClientHwidsResponse(const char* json);

struct jsonClearClientHwidsResponseStruct*         jsonClearClientHwidsResponse(const char* json);

struct jsonDeleteClientHwidResponseStruct*         jsonDeleteClientHwidResponse(const char* json);

struct jsonOnlinesResponseStruct*                  jsonOnlinesResponse(const char* json);

struct jsonOnlinesByGuidResponseStruct*            jsonOnlinesByGuidResponse(const char* json);

struct jsonClientIpsByGuidResponseStruct*          jsonClientIpsByGuidResponse(const char* json);

struct jsonActiveInboundsResponseStruct*           jsonActiveInboundsResponse(const char* json);

struct jsonLastOnlineResponseStruct*               jsonLastOnlineResponse(const char* json);

struct jsonTrafficResponseStruct*                  jsonTrafficResponse(const char* json);

struct jsonSubLinksResponseStruct*                 jsonSubLinksResponse(const char* json);

struct jsonLinksResponseStruct*                    jsonLinksResponse(const char* json);

#endif /* CJSON_TELEGRAM_XUI_BOT_CLIENTS_H */
