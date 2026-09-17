#ifndef CJSON_TELEGRAM_XUI_BOT
#define CJSON_TELEGRAM_XUI_BOT

#include <stdint.h>

// =====================================================
// List every inbound owned by the authenticated user
// =====================================================
struct jsonListInboundClientStatsArrayStruct {
    int64_t                     id;
    int64_t                     inboundId;
    unsigned char               enable;
    const char*                 email;
    const char*                 uuid;
    const char*                 subId;
    int64_t                     up;
    int64_t                     down;
    int64_t                     expiryTime;
    int64_t                     total;
    int                         reset;
    int64_t                     lastOnline;

};

struct jsonListInboundSettingsClientsArrayStruct {
    const char*                 auth;
    const char*                 comment;
    int64_t                     createdAt; // "created_at" on server side
    const char*                 email;
    unsigned char               enable;
    int64_t                     expiryTime;
    const char*                 id;
    int                         limitIp;
    const char*                 password;
    int                         reset;
    const char*                 security;
    const char*                 subId;
    int64_t                     tgId;
    int64_t                     totalGB; // Albeit named totalGB, its the total traffic of the user in BYTES
    int64_t                     updatedAt; // "updated_at" on server side

};

struct jsonListInboundSettingsObjectStruct {
    struct jsonListInboundSettingsClientsArrayStruct** listInSettingsCliArrStruct;
    const char*                 decryption;
    const char*                 encryption;

};

struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectStruct {
    const char*                 type;

};

struct jsonListInboundStreamSettingsTcpSettingsObjectStruct {
    unsigned char               acceptProxyProtocol;
    struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectStruct* listInStreamSettingsTcpSettingsObjHeaderObjStruct;

};

struct jsonListInboundStreamSettingsObjectStruct {
    const char*                 network;
    struct jsonListInboundStreamSettingsTcpSettingsObjectStruct* listInStreamSettingsTcpSettingsObjStruct;

};

struct jsonListInboundSniffingObjectStruct {
    const char*                 enabled;

};

struct jsonListInboundObjectStruct {
    int64_t                     id;
    int64_t                     up;
    int64_t                     down;
    int64_t                     total;
    const char*                 remark;
    int                         subSortIndex;
    unsigned char               enable;
    int64_t                     expiryTime;
    const char*                 trafficReset;
    int                         trafficResetDay;
    int64_t                     lastTrafficResetTime;
    struct jsonListInboundClientStatsArrayStruct** listInCliStatsStruct;
    const char*                 listen;
    int                         port;
    const char*                 protocol;
    const char*                 tag;
    const char*                 shareAddrStrategy;
    const char*                 shareAddr;
    const char*                 originNodeGuid;
    struct jsonListInboundSettingsObjectStruct* listInSettingsObjStruct;
    struct jsonListInboundStreamSettingsObjectStruct* listInStreamSettingsObjStruct;
    struct jsonListInboundSniffingObjectStruct* listInSniffingObjStruct;

};

struct jsonListInboundStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonListInboundObjectStruct** listInObjStruct;

};

// =====================================================
// List every inbound owned by the authenticated user ( slim version, uses some of the structs defined above )
// =====================================================
struct jsonListInboundSettingsClientsArraySlimStruct {
    const char*                 comment;
    const char*                 email;
    unsigned char               enable;

};

struct jsonListInboundSettingsObjectSlimStruct {
    struct jsonListInboundSettingsClientsArraySlimStruct** listInSettingsCliArrSlimStruct;
    const char*                 decryption;
    const char*                 encryption;

};

struct jsonListInboundObjectSlimStruct {
    int64_t                     id;
    int64_t                     up;
    int64_t                     down;
    int64_t                     total;
    const char*                 remark;
    int                         subSortIndex;
    unsigned char               enable;
    int64_t                     expiryTime;
    const char*                 trafficReset;
    int                         trafficResetDay;
    int64_t                     lastTrafficResetTime;
    struct jsonListInboundClientStatsArrayStruct** listInCliStatsStruct;
    const char*                 listen;
    int                         port;
    const char*                 protocol;
    const char*                 tag;
    const char*                 shareAddrStrategy;
    const char*                 shareAddr;
    const char*                 originNodeGuid;
    struct jsonListInboundSettingsObjectSlimStruct* listInSettingsObjSlimStruct;
    struct jsonListInboundStreamSettingsObjectStruct* listInStreamSettingsObjStruct;
    struct jsonListInboundSniffingObjectStruct* listInSniffingObjStruct;

};

struct jsonListInboundSlimStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonListInboundObjectSlimStruct** listInObjSlimStruct;

};

// =====================================================
// List every inbound owned by the authenticated user ( options version )
// =====================================================
struct jsonListInboundObjectOptionsArrayStruct {
    int64_t                     id;
    const char*                 remark;
    const char*                 tag;
    const char*                 protocol;
    int                         port;
    unsigned char               enable;
    unsigned char               tlsFlowCapable;
    const char*                 ssMethod;
    const char*                 shareAddrStrategy;

};

struct jsonListInboundOptionsStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonListInboundObjectOptionsArrayStruct* listInObjOptionsArrStruct;

};

// =====================================================
// Adding an inbound post and response structs
// =====================================================
struct jsonAddInboundSettingsClientsArrayPostStruct {
    const char*                 id;
    const char*                 email;

};

struct jsonAddInboundSettingsFallbacksArrayPostStruct {
    // TODO: its now known how the fallback works

};

struct jsonAddInboundSettingsObjPostStruct {
    struct jsonAddInboundSettingsClientsArrayPostStruct* addInSettingsCliArrPStruct;
    const char*                 decryption;
    struct jsonAddInboundSettingsFallbacksArrayPostStruct* addInSettingsFalbackArrPStruct;

};

struct jsonAddInboundStreamSettingsRealitySettingsObjectPostStruct {
    unsigned char               show;
    const char*                 dest;

};

struct jsonAddInboundStreamSettingsObjPostStruct {
    const char*                 network;
    const char*                 security;
    struct jsonAddInboundStreamSettingsRealitySettingsObjectPostStruct* addInStreamSettignsRealitySettingsObjPStruct;

};

struct jsonAddInboundSniffingObjectPostStruct {
    unsigned char               enabled;
    struct jsonAddInboundSniffingObjectDestOverrideArrStruct* addInSniffingObjDestOverrideArrStruct;

};

struct jsonAddInboundPostStruct {
    unsigned char               enable;
    const char*                 remark;
    const char*                 listen;
    int                         port;
    const char*                 protocol;
    int64_t                     expiryTime;
    const char*                 total;
    struct jsonAddInboundSettingsObjPostStruct* addInSettingsObjPStruct;
    struct jsonAddInboundStreamSettingsObjPostStruct* addInStreamSettingsObjPStruct;
    struct jsonAddInboundSniffingObjectPostStruct* addInSniffingObjPStruct;

};

struct jsonAddInboundResponseStruct {
    unsigned char               success;
    const char*                 msg;
    unsigned char               obj;

};

// =====================================================
// Deleting an inbound by id post and response structs
// =====================================================
struct jsonDeleteSingleInboundPostStruct {
    int64_t                     id;

};

struct jsonDeleteSingleInboundResponseStruct {
    unsigned char*              success;
    const char*                 msg;
    int64_t                     obj;

};

struct jsonDeleteMultipleInboundsPostStruct {
    int64_t**                   ids;

};

struct jsonDeleteMultipleInboundResponseSkippedArrayStruct {
    int64_t                     id;
    const char*                 reason;

};

struct jsonDeleteMultipleInboundResponseStruct {
    unsigned char*              success;
    const char*                 msg;
    int64_t                     obj;
    struct jsonDeleteMultipleInboundResponseSkippedArrayStruct* deleteMultiInResSkippedArrStruct;

};

// =====================================================
// Since the functionality of the panel's update path is
// unknown with due regard to the api documentation, this
// part is skipped for now
// =====================================================
/*
 *
 *
 *
 *
 * */

// =====================================================
// Toggle the enale flag of an inbound post and response structs ( Toggle only the
// enable flag without serialising the whole settings
// json )
// =====================================================
struct jsonSetEnableInboundPostStruct {
    int64_t                     id;
    unsigned char               enabled;

};

struct jsonSetEnableInboundResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on success

};

// =====================================================
// Reset upload and download counters for a single
// inbound post and response structs ( this does not
// touch the per-client counters )
// =====================================================
struct jsonResetInboundPostStruct {
    int64_t id;

};

struct jsonResetInboundResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on success

};

// =====================================================
// Remove every client attached to a single inbound post
// and response structs
// =====================================================
struct jsonRemoveEveryClientFromInboundPostStruct {
    int64_t                     id;

};

struct jsonRemoveEveryClientFromInboundResponseObjectStruct {
    int                         deleted;

};

struct jsonRemoveEveryClientFromInboundResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonRemoveEveryClientFromInboundResponseObjectStruct* rmEveryCliFromInResObjStruct;

};

// =====================================================
// Reset upload and download of all inbounds response
// struct
// =====================================================
struct jsonResetAllInboundsUploadNDownload {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on success

};

// =====================================================
// Import json-structured inbound(s) post and response
// structs
// The content shall be sent as follows, else it will not work:
// curl -X POST "http://127.0.0.1:25175/000000000000000/panel/api/inbounds/import"
// -H "Authorization: Bearer exampleBearerToken" \  --data-urlencode "data=$(jq -c . <<< '{
//  "id": 1,
//  "userId": 0,
//  "up": 0,
//  "down": 0,
//  "total": 0,
//  "remark": "exampleRemark",
//  "enable": true,
//  "expiryTime": 1787776200000,
//  "trafficReset": "never",
//  "trafficResetDay": 1,
//  "lastTrafficResetTime": 0,
//  "listen": "",
//  "port": 46682,
//  "protocol": "vless",
//  "settings": {
//    "clients": [],
//    "decryption": "none",
//    "encryption": "none"
//  },
//  "streamSettings": {
//    "network": "tcp",
//    "tcpSettings": {
//      "acceptProxyProtocol": false,
//      "header": {
//        "type": "none"
//      }
//    },
//    "security": "none"
//  },
//  "tag": "in-46682-tcp",
//  "sniffing": {
//    "enabled": false
//  },
//  "clientStats": [],
//  "nodeId": null,
//  "shareAddrStrategy": "listen",
//  "shareAddr": "",
//  "subSortIndex": 1,
//  "originNodeGuid": "",
//  "fallbackParent": null
//}
// =====================================================
struct jsonImportInboundsPostStruct {
    const char*                 data;

};

struct jsonImportInboundsResponseStruct {
    const unsigned char         success;
    const char*                 msg;
    struct jsonListInboundObjectStruct* listInObjStruct;

};

// =====================================================
// List every client
// =====================================================
struct jsonListEveryClientObjectTrafficObjectStruct {
    int64_t                     id;
    int64_t                     inboundId;
    const unsigned char         enable;
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
    const unsigned char         keepAlive;
    const char*                 forwardedPorts;
    const char*                 secret;
    const char*                 adTag;
    int64_t                     limitIp;
    int                         limitHwid;
    int64_t                     totalGB; // Albeit named totalGB, its the total traffic of the user in BYTES
    int64_t                     expiryTime;
    const unsigned char         enable;
    int64_t                     tagId;
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
    struct jsonListEveryClientObjectTrafficObjectStruct* listEveryCliObjTrafficObjStruct;

};

struct jsonListEveryClientStruct {
    const unsigned char         success;
    const char*                 msg;
    struct jsonListEveryClientArrayStruct** listEveryCliArrStruct;

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
    struct jsonFilterClientsObjectItemsArrayResponseStruct** filterCliObjItemsArrStruct; // every
                                                                                          // pointer
                                                                                          // presented is an
                                                                                          // element of the array
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
    struct jsonFilterClientsGroupObjectResponseStruct* filterCliGroupObjRStruct;

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
    struct jsonFetchClientByEmailObjectExternalLinksArrayStruct* fetchCliByEmailObjExternalLinksArrStruct;
    int*                        inboundIds;
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
    struct jsonFetchClientByTelegramIdObjectArrayExternalLinksArrayStruct* fetchCliByTgIArrdObjExternalLinksArrStruct;
    int*                        inboundIds;
    const char*                 tunnelAllowedIPs;
    int64_t                     usedTraffic;

};

struct jsonFetchClientByTelegramIdStruct {
    unsigned char success;
    const char* msg;
    struct jsonFetchClientByTelegramIdObjectArrayStruct** fetchCliByTgIdObjArrStruct;

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
    struct jsonExternalLinksObjectArrayPostStruct* rplExtLinksObjArrPStruct; // send empty
                                                                             // array to clear
                                                                             // all rows

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

};

struct jsonExportAllClientsResponseStruct {
    unsigned char success;
    const char* msg;
    struct jsonExportAllClientsObjectArrayResponseStruct* exportAllClisObjArrRStruct;

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
    struct jsonImportClientsDataObjectPostStruct** importClientsDataObjPStruct;

};

struct jsonImportClientsObjectSkippedArrayResponseStruct {
    const char* email;
    const char* reason;

};

struct jsonImportClientsObjectResponseStruct {
    int64_t created;
    struct jsonImportClientsObjectSkippedArrayResponseStruct** importClisObjSkippedArrRStruct; // skipped array
                                                                                               // pointer presented is an
                                                                                               // element of the array

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
    struct jsonBulkAdjustClientsObjectSkippedArrayResponseStruct** bulkAdjClisObjSkippedArrRStruct; // skipped array, every
                                                                                                     // pointer presented is an
                                                                                                     // element of the array

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
    struct jsonBulkEnableClientsObjectSkippedArrayResponseStruct** bulkEnableClisObjSkippedArrRStruct; // skipped array, every
                                                                                                     // pointer presented is an
                                                                                                     // element of the array

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
    struct jsonBulkDisableClientsObjectSkippedArrayResponseStruct** bulkDisableClisObjSkippedArrRStruct; // skipped array, every
                                                                                                          // pointer presented is an
                                                                                                          // element of the array

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
    struct jsonBulkDeleteClientsObjectSkippedArrayResponseStruct** bulkDelClisObjSkippedArrRStruct; // skipped array, every
                                                                                                     // pointer presented is an
                                                                                                     // element of the array

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

};

struct jsonBulkCreateClientsPostStruct {
    struct jsonBulkCreateClientsMainObjectPostStruct** bulkCreateClisMainObjPStruct;

};

struct jsonBulkCreateClientsObjectSkippedArrayResponseStruct {
    const char*                 email;
    const char*                 reason;

};


struct jsonBulkCreateClientsObjectResponseStruct {
    int64_t                     created;
    struct jsonBulkCreateClientsObjectSkippedArrayResponseStruct** bulkCreateClisObjSkippedArrRStruct; // skipped array, every
                                                                                                       // pointer presented is an
                                                                                                       // element of the array

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
    struct jsonListGroupsObjectArrayStruct** listGroupsObjArrStruct; // every pointer
                                                                     // presented is an
                                                                     // element of the array

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
    struct jsonListClientHwidsObjectArrayStruct** listClientHwidsObjArrStruct; // every pointer
                                                                               // presented is an
                                                                               // element of the
                                                                               // array

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

// =====================================================
// Serve this API description as an OpenAPI 3 document
// ( the same file that powers the API Docs page )
// =====================================================
struct jsonOpenApiResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Real-time machine snapshot : CPU, memory, swap, disk,
// network IO, load averages, open connections, Xray
// state. Cached and refreshed every 2 seconds in the
// background
// =====================================================
struct jsonServerStatusMemObjectStruct {
    int64_t                     current;
    int64_t                     total;

};

struct jsonServerStatusSwapObjectStruct {
    int64_t                     current;
    int64_t                     total;

};

struct jsonServerStatusDiskObjectStruct {
    int64_t                     current;
    int64_t                     total;

};

struct jsonServerStatusDiskIOObjectStruct {
    int64_t                     read;
    int64_t                     write;

};

struct jsonServerStatusDiskTrafficObjectStruct {
    int64_t                     read;
    int64_t                     write;

};

struct jsonServerStatusNetIOObjectStruct {
    int64_t                     up;
    int64_t                     down;
    int64_t                     pktUp;
    int64_t                     pktDown;

};

struct jsonServerStatusNetTrafficObjectStruct {
    int64_t                     sent;
    int64_t                     recv;
    int64_t                     pktSent;
    int64_t                     pktRecv;

};

struct jsonServerStatusPublicIPObjectStruct {
    const char*                 ipv4; // e.g. "178.104.155.165"
    const char*                 ipv6; // e.g. "N/A"
};

struct jsonServerStatusAppStatsObjectStruct {
    int                         threads;
    int64_t                     mem;
    int64_t                     uptime;

};

struct jsonServerStatusXrayObjectStruct {
    const char*                 state; // e.g. "running"
    const char*                 errorMsg; // e.g. "" ( empty when running normally )
    const char*                 version; // e.g. "v25.10.31"

};

struct jsonServerStatusLoadObjectStruct {
    double*                     loads; // 3 elements : the 1m, 5m and 15m load averages

};

struct jsonServerStatusObjectStruct {
    double                      cpu;
    int64_t                     cpuCores;
    int64_t                     logicalPro;
    int64_t                     cpuSpeedMhz;
    struct jsonServerStatusMemObjectStruct* srvStatusObjMemObjStruct;
    struct jsonServerStatusSwapObjectStruct* srvStatusObjSwapObjStruct;
    struct jsonServerStatusDiskObjectStruct* srvStatusObjDiskObjStruct;
    struct jsonServerStatusDiskIOObjectStruct* srvStatusObjDiskIOObjStruct;
    struct jsonServerStatusDiskTrafficObjectStruct* srvStatusObjDiskTrafficObjStruct;
    struct jsonServerStatusNetIOObjectStruct* srvStatusObjNetIOObjStruct;
    struct jsonServerStatusNetTrafficObjectStruct* srvStatusObjNetTrafficObjStruct;
    struct jsonServerStatusXrayObjectStruct* srvStatusObjXrayObjStruct;
    const char*                 panelVersion; // e.g. "3.6.0"
    const char*                 panelGuid;
    int64_t                     uptime; // seconds
    int                         tcpCount;
    int                         udpCount;
    struct jsonServerStatusLoadObjectStruct* srvStatusObjLoadObjStruct;
    struct jsonServerStatusPublicIPObjectStruct* srvStatusObjPublicIPObjStruct;
    struct jsonServerStatusAppStatsObjectStruct* srvStatusObjAppStatsObjStruct;

};

struct jsonServerStatusResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerStatusObjectStruct* srvStatusObjStruct;

};

// =====================================================
// Reports whether per-client IP limits can be enforced
// on this host ( depends on fail2ban being installed )
// =====================================================
struct jsonServerFail2banStatusObjectStruct {
    unsigned char               enabled;
    unsigned char               installed;
    unsigned char               usable;
    unsigned char               windows;

};

struct jsonServerFail2banStatusResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerFail2banStatusObjectStruct* fail2banStatusObjStruct;

};

// =====================================================
// Legacy : aggregated CPU history response struct.
// Use /history/cpu/:bucket instead — same data with a
// uniform { t, v } shape. Real payload obj is an array
// of { cpu, t } samples
// =====================================================
struct jsonServerCpuHistoryObjectArrayStruct {
    double                      cpu;
    int64_t                     t;

};

struct jsonServerCpuHistoryResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerCpuHistoryObjectArrayStruct** cpuHistoryObjArrStruct; // every
                                                                           // pointer presented
                                                                           // is an element of
                                                                           // the array

};

// =====================================================
// Aggregated time-series for one metric response struct.
// Returns an array of { t, v } samples covering the
// last ~6 hours
// =====================================================
struct jsonServerHistoryObjectArrayStruct {
    int64_t                     t;
    double                      v;

};

struct jsonServerHistoryResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerHistoryObjectArrayStruct** srvHistoryObjArrStruct; // every pointer
                                                                        // presented is an
                                                                        // element of the array

};

// =====================================================
// Xray runtime metrics state response struct ( whether
// the xray config has a metrics block, which expvar
// keys are flowing, and the current snapshot values ).
// Returns an empty state when metrics are not configured
// =====================================================
struct jsonServerXrayMetricsStateResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Time-series history for one Xray runtime metric over
// the last ~6 hours response struct. Same { t, v } shape
// as /history/:metric/:bucket
// =====================================================
struct jsonServerXrayMetricsHistoryResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Latest snapshot from the Xray observatory response
// struct ( per-outbound latency, health status, and
// last-probe time ). Only populated when the Xray config
// has an observatory configured
// =====================================================
struct jsonServerXrayObservatoryResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Time-series of observatory probe results for one
// outbound tag response struct. Same { t, v } shape as
// the other history endpoints
// =====================================================
struct jsonServerXrayObservatoryHistoryResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// List Xray binary versions available for install on
// this host
// =====================================================
struct jsonServerGetXrayVersionResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char**                obj; // every pointer presented is an element of the array

};

// =====================================================
// Check whether a newer 3x-ui release is available on
// GitHub
// =====================================================
struct jsonServerGetPanelUpdateInfoResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Report the outcome of the most recently launched panel
// self-update. Compare the returned runId against the
// one updatePanel returned to tell this run apart from a
// stale result
// =====================================================
struct jsonServerGetUpdateStatusObjectStruct {
    int                         exitCode;
    int64_t                     finishedAt;
    const char*                 runId;
    const char*                 state; // e.g. "success"

};

struct jsonServerGetUpdateStatusResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerGetUpdateStatusObjectStruct* getUpdateStatusObjStruct;

};

// =====================================================
// Return the assembled Xray config that is currently
// running on this host
// =====================================================
struct jsonServerGetConfigJsonResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Stream a full database backup as an attachment ( the
// SQLite .db file on SQLite panels, or a pg_dump custom
// format archive ( .dump ) on PostgreSQL panels )
// =====================================================
struct jsonServerGetDbResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Stream a cross-engine migration file as an attachment
// ( a .dump ( SQL text ) on SQLite, or a .db SQLite
// database built from the live data on PostgreSQL )
// =====================================================
struct jsonServerGetMigrationResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Generate a fresh UUID v4. Convenience helper for
// client IDs
// =====================================================
struct jsonServerGetNewUUIDObjectStruct {
    const char*                 uuid;

};

struct jsonServerGetNewUUIDResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerGetNewUUIDObjectStruct* getNewUUIDObjStruct;

};

// =====================================================
// Return this panel's own web TLS certificate and key
// file paths ( the central panel calls it on a node via
// the node API token so "Set Cert from Panel" fills a
// node-assigned inbound with paths that exist on the
// node )
// =====================================================
struct jsonServerGetWebCertFilesObjectStruct {
    const char*                 webCertFile;
    const char*                 webKeyFile;

};

struct jsonServerGetWebCertFilesResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerGetWebCertFilesObjectStruct* getWebCertFilesObjStruct;

};

// =====================================================
// Read-only summaries of the nodes this panel manages
// ( a parent panel calls it on a node via the node API
// token to surface transitive sub-nodes in a chained
// topology. Counts are computed by the parent, not
// returned here )
// =====================================================
struct jsonServerDescendantsObjectArrayStruct {
    const char*                 guid;
    const char*                 parentGuid;
    const char*                 name;
    const char*                 address;
    const char*                 status; // e.g. "online"
    const char**                versions; // Omittable; not present at the documented sample

};

struct jsonServerDescendantsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerDescendantsObjectArrayStruct** descendantsObjArrStruct; // every
                                                                            // pointer
                                                                            // presented is
                                                                            // an element of
                                                                            // the array

};

// =====================================================
// Generate a new X25519 keypair for Reality
// =====================================================
struct jsonServerGetNewX25519CertObjectStruct {
    const char*                 privateKey;
    const char*                 publicKey;

};

struct jsonServerGetNewX25519CertResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerGetNewX25519CertObjectStruct* getNewX25519ObjStruct;

};

// =====================================================
// Generate a new ML-DSA-65 keypair. Returns { seed,
// verify }
// =====================================================
struct jsonServerGetNewMldsa65ObjectStruct {
    const char*                 seed;
    const char*                 verify;

};

struct jsonServerGetNewMldsa65ResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerGetNewMldsa65ObjectStruct* getNewMldsa65ObjStruct;

};

// =====================================================
// Generate a new ML-KEM-768 keypair. Returns { seed,
// client }
// =====================================================
struct jsonServerGetNewMlkem768ObjectStruct {
    const char*                 client;
    const char*                 seed;

};

struct jsonServerGetNewMlkem768ResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerGetNewMlkem768ObjectStruct* getNewMlkem768ObjStruct;

};

// =====================================================
// Generate VLESS encryption auth options. Returns an
// auths array each with id, label, encryption and
// decryption fields
// =====================================================
struct jsonServerGetNewVlessEncAuthsArrayStruct {
    const char*                 id; // e.g. "x25519", "mlkem768", "x25519_xorpub", ...
    const char*                 label;
    const char*                 encryption;
    const char*                 decryption;

};

struct jsonServerGetNewVlessEncObjectStruct {
    struct jsonServerGetNewVlessEncAuthsArrayStruct** getNewVlessEncObjAuthsArrStruct; // every
                                                                                      // pointer
                                                                                      // presented
                                                                                      // is an
                                                                                      // element of
                                                                                      // the array

};

struct jsonServerGetNewVlessEncResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerGetNewVlessEncObjectStruct* getNewVlessEncObjStruct;

};

// =====================================================
// Stop the Xray binary ( all proxies go offline
// immediately ) response struct
// =====================================================
struct jsonServerStopXrayServiceResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Reload Xray with the current config ( typically
// required after structural inbound or routing changes )
// response struct
// =====================================================
struct jsonServerRestartXrayServiceResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Download and install the specified Xray version ( pass
// "latest" for the newest release ) response struct
// =====================================================
struct jsonServerInstallXrayResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Self-update the panel to the latest version ( the
// server restarts on success )
// =====================================================
struct jsonServerUpdatePanelObjectStruct {
    const char*                 runId;

};

struct jsonServerUpdatePanelResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerUpdatePanelObjectStruct* updatePanelObjStruct;

};

// =====================================================
// Toggle the panel update channel between stable and
// the rolling per-commit dev release ( only effective on
// dev builds ) post and response structs
// =====================================================
struct jsonServerSetUpdateChannelPostStruct {
    unsigned char               dev; // true = dev channel, false = stable

};

struct jsonServerSetUpdateChannelResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Refresh the default GeoIP / GeoSite data files ( or a
// single Geo file by filename, e.g. geoip.dat,
// geosite.dat ) response struct
// =====================================================
struct jsonServerUpdateGeofileResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Return the last N lines of the panel's own log
// =====================================================
struct jsonServerLogsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char**                obj; // every pointer presented is an element of the array

};

// =====================================================
// Return the last N lines of the Xray process log
// =====================================================
struct jsonServerXrayLogsObjectArrayStruct {
    const char*                 DateTime; // e.g. "2025-01-01T12:00:00Z"
    const char*                 Email;
    int                         Event;
    const char*                 FromAddress;
    const char*                 Inbound;
    const char*                 Outbound;
    const char*                 ToAddress;

};

struct jsonServerXrayLogsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerXrayLogsObjectArrayStruct** xrayLogsObjArrStruct; // every pointer
                                                                       // presented is an
                                                                       // element of the array

};

// =====================================================
// Return live AmneziaWG peer activity ( handshake,
// endpoint, transfer ) plus the panel's own AmneziaWG
// event lines
// =====================================================
struct jsonServerAmneziawgLogsPeersArrayStruct {
    const char*                 allowedIPs;
    int64_t                     down;
    const char*                 email;
    const char*                 endpoint;
    int64_t                     handshake;
    int                         inboundId;
    const char*                 interface;
    unsigned char               online;
    const char*                 tag;
    int64_t                     up;

};

struct jsonServerAmneziawgLogsObjectStruct {
    const char**                events; // every pointer presented is an element of the array
    struct jsonServerAmneziawgLogsPeersArrayStruct** awgLogsObjPeersArrStruct; // every
                                                                               // pointer
                                                                               // presented is
                                                                               // an element of
                                                                               // the array
    unsigned char               running;

};

struct jsonServerAmneziawgLogsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerAmneziawgLogsObjectStruct* awgLogsObjStruct;

};

// =====================================================
// Restore the panel DB from an uploaded backup (
// multipart form, field name "db" ). The panel restarts
// after restore. Destructive
// =====================================================
struct jsonServerImportDbResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Generate a new ECH ( Encrypted Client Hello ) keypair
// and config list for the given SNI post and response
// structs
// =====================================================
struct jsonServerGetNewEchCertPostStruct {
    const char*                 sni;

};

struct jsonServerGetNewEchCertResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Compute the hex SHA-256 of a certificate ( DER ) for
// pinning ( pinnedPeerCertSha256 ). Provide either a
// server file path or inline PEM / DER content
// =====================================================
struct jsonServerGetCertHashPostStruct {
    const char*                 certFile; // takes precedence over certContent
    const char*                 certContent; // used when certFile is empty

};

struct jsonServerGetRemoteCertHashPostStruct {
    const char*                 server; // domain or domain:port ( default port 443 )

};

struct jsonServerCertHashObjectArrayStruct {
    const char*                 sha256; // e.g. "e8e2d3..."

};

struct jsonServerGetCertHashResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerCertHashObjectArrayStruct** certHashObjArrStruct; // every pointer
                                                                      // presented is an
                                                                      // element of the array

};

struct jsonServerGetRemoteCertHashResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerCertHashObjectArrayStruct** certHashObjArrStruct; // every pointer
                                                                      // presented is an
                                                                      // element of the array

};

// =====================================================
// Run a live TLS 1.3 probe against a candidate REALITY
// target and return a feasibility verdict plus the
// certificate SAN DNS names. A target on a private /
// loopback address is reported with privateTarget=true
// and probed only when allowPrivate is set
// =====================================================
struct jsonServerScanRealityTargetPostStruct {
    const char*                 target; // host or host:port ( default port 443 )
    const char*                 sni; // Omittable, defaults to the target host
    int                         xver; // Omittable, PROXY protocol version ( 0 = none )
    unsigned char               allowPrivate; // Omittable, default false

};

struct jsonServerScanRealityTargetObjectStruct {
    const char*                 alpn; // e.g. "h2"
    unsigned char               certChainValid;
    const char*                 certIssuer; // e.g. "Google Trust Services"
    const char*                 certSubject; // e.g. "cloudflare.com"
    unsigned char               certValid;
    const char*                 curveID; // e.g. "X25519"
    unsigned char               feasible;
    unsigned char               h2;
    const char*                 host;
    const char*                 ip;
    int                         latencyMs;
    const char*                 notAfter; // e.g. "2026-08-01T00:00:00Z"
    int                         port;
    unsigned char               privateTarget;
    const char*                 reason;
    const char**                serverNames; // every pointer presented is an element of the array
    const char*                 target;
    unsigned char               tls13;
    const char*                 tlsVersion; // e.g. "1.3"
    unsigned char               x25519;

};

struct jsonServerScanRealityTargetResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerScanRealityTargetObjectStruct* scanRealityTargetObjStruct;

};

// =====================================================
// Probe / discover REALITY targets and return each
// verdict ranked by feasibility then latency. Each
// comma-separated token may be a domain ( validated with
// SNI ), a bare IP, or a CIDR range. When empty, a
// built-in seed list is probed
// =====================================================
struct jsonServerScanRealityTargetsPostStruct {
    const char*                 targets; // Omittable, comma-separated tokens

};

struct jsonServerScanRealityTargetsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerScanRealityTargetObjectStruct** scanRealityTargetsObjArrStruct; // every
                                                                                    // pointer
                                                                                    // presented is
                                                                                    // an element of
                                                                                    // the array

};

// =====================================================
// Fetch the fully aggregated inbound_client_ips database
// table ( used by nodes to sync recently active IPs
// across the cluster )
// =====================================================
struct jsonServerClientIpsIpsItemStruct {
    const char*                 ip;
    int64_t                     timestamp;

};

struct jsonServerClientIpsObjectArrayStruct {
    const char*                 clientEmail;
    int                         id;
    struct jsonServerClientIpsIpsItemStruct** clientIpsObjArrIpsArrStruct; // may be null;
                                                                           // every pointer
                                                                           // presented is an
                                                                           // element of the
                                                                           // array

};

struct jsonServerClientIpsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerClientIpsObjectArrayStruct** clientIpsObjArrStruct; // every pointer
                                                                         // presented is an
                                                                         // element of the array

};

// =====================================================
// Submit a list of recently active IP timestamps ( the
// panel merges them with the existing database to
// maintain a unified global IP-limit view ) post and
// response structs
// =====================================================
struct jsonServerSubmitClientIpsObjectPostStruct {
    const char*                 clientEmail;
    struct jsonServerClientIpsIpsItemStruct** submitClientIpsObjIpsArrPStruct; // every
                                                                               // pointer
                                                                               // presented is
                                                                               // an element of
                                                                               // the array

};

struct jsonServerSubmitClientIpsPostStruct {
    struct jsonServerSubmitClientIpsObjectPostStruct** submitClientIpsObjArrPStruct; // every
                                                                                    // pointer
                                                                                    // presented is
                                                                                    // an element of
                                                                                    // the array

};

struct jsonServerSubmitClientIpsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Return every panel setting: web server, Telegram bot,
// subscription, security, LDAP. The full JSON blob that
// the Settings page edits. The wire shape is a flat
// 110-key object ( verified against 3.6.0 ); the structs
// below group the keys by their prefix for readability
// =====================================================
struct jsonSettingAllWebObjectStruct {
    const char*                 webBasePath;
    const char*                 webCertFile;
    const char*                 webDomain;
    const char*                 webKeyFile;
    const char*                 webListen;
    int64_t                     webPort;

};

struct jsonSettingAllTgObjectStruct {
    const char*                 tgBotAPIServer;
    unsigned char               tgBotBackup;
    const char*                 tgBotChatId;
    unsigned char               tgBotEnable;
    const char*                 tgBotProxy;
    const char*                 tgBotToken;
    int64_t                     tgCpu;
    const char*                 tgEnabledEvents; // e.g. "login.attempt,cpu.high"
    const char*                 tgLang;
    int64_t                     tgMemory;
    const char*                 tgRunTime; // e.g. "@daily"

};

struct jsonSettingAllSmtpObjectStruct {
    int64_t                     smtpCpu;
    unsigned char               smtpEnable;
    const char*                 smtpEnabledEvents; // e.g. "login.attempt,cpu.high"
    const char*                 smtpEncryptionType; // e.g. "starttls"
    const char*                 smtpFrom;
    const char*                 smtpFromName;
    const char*                 smtpHost;
    int64_t                     smtpMemory;
    const char*                 smtpPassword;
    int64_t                     smtpPort;
    const char*                 smtpTo;
    const char*                 smtpUsername;

};

struct jsonSettingAllLdapObjectStruct {
    unsigned char               ldapAutoCreate;
    unsigned char               ldapAutoDelete;
    const char*                 ldapBaseDN;
    const char*                 ldapBindDN;
    int64_t                     ldapDefaultExpiryDays;
    int64_t                     ldapDefaultLimitIP;
    int64_t                     ldapDefaultTotalGB;
    unsigned char               ldapEnable;
    const char*                 ldapFlagField;
    const char*                 ldapHost;
    const char*                 ldapInboundTags;
    unsigned char               ldapInsecureSkipVerify;
    unsigned char               ldapInvertFlag;
    const char*                 ldapPassword;
    int64_t                     ldapPort;
    const char*                 ldapSyncCron; // e.g. "@every 1m"
    const char*                 ldapTruthyValues; // e.g. "true,1,yes,on"
    unsigned char               ldapUseTLS;
    const char*                 ldapUserAttr;
    const char*                 ldapUserFilter;
    const char*                 ldapVlessField;

};

struct jsonSettingAllSubObjectStruct {
    const char*                 subAnnounce;
    const char*                 subCertFile;
    unsigned char               subClashAutoDetect;
    unsigned char               subClashEnable;
    unsigned char               subClashEnableRouting;
    const char*                 subClashPath;
    const char*                 subClashRules;
    const char*                 subClashURI;
    const char*                 subClashUserAgentRegex;
    const char*                 subDomain;
    unsigned char               subEnable;
    unsigned char               subEnableRouting;
    unsigned char               subEncrypt;
    unsigned char               subHideSettings;
    unsigned char               subIncyEnableRouting;
    const char*                 subIncyRoutingRules;
    unsigned char               subJsonAlwaysArray;
    unsigned char               subJsonAutoDetect;
    unsigned char               subJsonEnable;
    const char*                 subJsonFinalMask;
    const char*                 subJsonMux;
    const char*                 subJsonPath;
    const char*                 subJsonRules;
    const char*                 subJsonURI;
    const char*                 subJsonUserAgentRegex;
    const char*                 subKeyFile;
    const char*                 subListen;
    const char*                 subPath;
    int64_t                     subPort;
    const char*                 subProfileUrl;
    const char*                 subRoutingRules;
    unsigned char               subShowIdentityOnAllLinks;
    const char*                 subSupportUrl;
    const char*                 subThemeDir;
    const char*                 subTitle;
    const char*                 subURI;
    int64_t                     subUpdates;

};

struct jsonSettingAllHasFlagsObjectStruct {
    unsigned char               hasApiToken;
    unsigned char               hasLdapPassword;
    unsigned char               hasNordSecret;
    unsigned char               hasSmtpPassword;
    unsigned char               hasTgBotToken;
    unsigned char               hasTwoFactorToken;
    unsigned char               hasWarpSecret;

};

struct jsonSettingAllGeneralObjectStruct {
    const char*                 datepicker; // e.g. "gregorian"
    int64_t                     expireDiff;
    unsigned char               externalTrafficInformEnable;
    const char*                 externalTrafficInformURI;
    int64_t                     outboundDownThreshold;
    int64_t                     pageSize;
    const char*                 panelOutbound;
    const char*                 remarkTemplate;
    unsigned char               restartXrayOnClientDisable;
    int64_t                     sessionMaxAge;
    const char*                 timeLocation; // e.g. "Local"
    int64_t                     trafficDiff;
    const char*                 trustedProxyCIDRs; // e.g. "127.0.0.1/32,::1/128"
    unsigned char               twoFactorEnable;
    const char*                 twoFactorToken;
    int64_t                     warpUpdateInterval;

};

struct jsonSettingAllObjectStruct {
    struct jsonSettingAllWebObjectStruct* setAllObjWebObjStruct;
    struct jsonSettingAllTgObjectStruct* setAllObjTgObjStruct;
    struct jsonSettingAllSmtpObjectStruct* setAllObjSmtpObjStruct;
    struct jsonSettingAllLdapObjectStruct* setAllObjLdapObjStruct;
    struct jsonSettingAllSubObjectStruct* setAllObjSubObjStruct;
    struct jsonSettingAllHasFlagsObjectStruct* setAllObjHasFlagsObjStruct;
    struct jsonSettingAllGeneralObjectStruct* setAllObjGeneralObjStruct;

};

struct jsonSettingAllResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonSettingAllObjectStruct* setAllObjStruct;

};

// =====================================================
// Computed default settings ( 21 keys ) based on the
// request host ( useful to preview what a fresh install
// would use ) object struct
// =====================================================
struct jsonSettingDefaultSettingsObjectStruct {
    unsigned char               accessLogEnable;
    const char*                 datepicker;
    const char*                 defaultCert;
    const char*                 defaultKey;
    unsigned char               devChannelEnable;
    int64_t                     expireDiff;
    unsigned char               ipLimitEnable;
    unsigned char               isDevBuild;
    int64_t                     pageSize;
    unsigned char               subClashEnable;
    const char*                 subClashURI;
    const char*                 subDomain;
    unsigned char               subEnable;
    unsigned char               subJsonEnable;
    const char*                 subJsonURI;
    const char*                 subThemeDir;
    const char*                 subTitle;
    const char*                 subURI;
    unsigned char               tgBotEnable;
    int64_t                     trafficDiff;
    const char*                 webDomain;

};

// =====================================================
// Return the computed default settings based on the
// request host ( useful to preview what a fresh install
// would use )
// =====================================================
struct jsonSettingDefaultSettingsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonSettingDefaultSettingsObjectStruct* defSettingsObjStruct;

};

// =====================================================
// Shipped ( factory ) default value per browser-safe
// setting key ( 99 keys, every value is a string even
// for numeric/boolean defaults ) object struct.
// Per-install material and credential fields are never
// included
// =====================================================
struct jsonSettingFactoryDefaultsObjectStruct {
    const char*                 datepicker;
    const char*                 expireDiff;
    const char*                 externalTrafficInformEnable;
    const char*                 externalTrafficInformURI;
    const char*                 ldapAutoCreate;
    const char*                 ldapAutoDelete;
    const char*                 ldapBaseDN;
    const char*                 ldapBindDN;
    const char*                 ldapDefaultExpiryDays;
    const char*                 ldapDefaultLimitIP;
    const char*                 ldapDefaultTotalGB;
    const char*                 ldapEnable;
    const char*                 ldapFlagField;
    const char*                 ldapHost;
    const char*                 ldapInboundTags;
    const char*                 ldapInsecureSkipVerify;
    const char*                 ldapInvertFlag;
    const char*                 ldapPort;
    const char*                 ldapSyncCron;
    const char*                 ldapTruthyValues;
    const char*                 ldapUseTLS;
    const char*                 ldapUserAttr;
    const char*                 ldapUserFilter;
    const char*                 ldapVlessField;
    const char*                 outboundDownThreshold;
    const char*                 pageSize;
    const char*                 panelOutbound;
    const char*                 remarkTemplate;
    const char*                 restartXrayOnClientDisable;
    const char*                 sessionMaxAge;
    const char*                 smtpCpu;
    const char*                 smtpEnable;
    const char*                 smtpEnabledEvents;
    const char*                 smtpEncryptionType;
    const char*                 smtpFrom;
    const char*                 smtpFromName;
    const char*                 smtpHost;
    const char*                 smtpMemory;
    const char*                 smtpPort;
    const char*                 smtpTo;
    const char*                 smtpUsername;
    const char*                 subAnnounce;
    const char*                 subCertFile;
    const char*                 subClashAutoDetect;
    const char*                 subClashEnable;
    const char*                 subClashEnableRouting;
    const char*                 subClashPath;
    const char*                 subClashRules;
    const char*                 subClashURI;
    const char*                 subClashUserAgentRegex;
    const char*                 subDomain;
    const char*                 subEnable;
    const char*                 subEnableRouting;
    const char*                 subEncrypt;
    const char*                 subHideSettings;
    const char*                 subIncyEnableRouting;
    const char*                 subIncyRoutingRules;
    const char*                 subJsonAlwaysArray;
    const char*                 subJsonAutoDetect;
    const char*                 subJsonEnable;
    const char*                 subJsonFinalMask;
    const char*                 subJsonMux;
    const char*                 subJsonPath;
    const char*                 subJsonRules;
    const char*                 subJsonURI;
    const char*                 subJsonUserAgentRegex;
    const char*                 subKeyFile;
    const char*                 subListen;
    const char*                 subPath;
    const char*                 subPort;
    const char*                 subProfileUrl;
    const char*                 subRoutingRules;
    const char*                 subShowIdentityOnAllLinks;
    const char*                 subSupportUrl;
    const char*                 subThemeDir;
    const char*                 subTitle;
    const char*                 subURI;
    const char*                 subUpdates;
    const char*                 tgBotAPIServer;
    const char*                 tgBotBackup;
    const char*                 tgBotChatId;
    const char*                 tgBotEnable;
    const char*                 tgBotProxy;
    const char*                 tgCpu;
    const char*                 tgEnabledEvents;
    const char*                 tgLang;
    const char*                 tgMemory;
    const char*                 tgRunTime;
    const char*                 timeLocation;
    const char*                 trafficDiff;
    const char*                 trustedProxyCIDRs;
    const char*                 twoFactorEnable;
    const char*                 warpUpdateInterval;
    const char*                 webBasePath;
    const char*                 webCertFile;
    const char*                 webDomain;
    const char*                 webKeyFile;
    const char*                 webListen;
    const char*                 webPort;

};

// =====================================================
// Return the shipped ( factory ) default value per
// browser-safe setting key ( per-install material and
// credential fields are never included )
// =====================================================
struct jsonSettingFactoryDefaultsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonSettingFactoryDefaultsObjectStruct* factoryDefaultsObjStruct;

};

// =====================================================
// Persist every setting at once ( the body mirrors the
// shape returned by /all ) post and response structs.
// Invalid values ( bad ports, missing cert pairs, etc. )
// are rejected before write
// =====================================================
struct jsonSettingUpdatePostStruct {
    // body mirrors the shape of jsonSettingAllObjectStruct
    // ( see the /all response structs above )

};

struct jsonSettingUpdateResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Validate any regular expression with the backend Go
// RE2 compiler without saving it post and response
// structs
// =====================================================
struct jsonSettingValidateRegexPostStruct {
    const char*                 regex;

};

struct jsonSettingValidateRegexResponseStruct {
    unsigned char               success;
    const char*                 msg;

};

// =====================================================
// List and manage API tokens ( used for the x-api-key
// header authentication ) post and response structs.
// Array element object struct
// =====================================================
struct jsonSettingApiTokensObjectStruct {
    int64_t                     id;
    const char*                 name;
    unsigned char               enabled;
    int64_t                     createdAt;

};

struct jsonSettingApiTokensListPostStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonSettingApiTokensObjectStruct** objArrays;

};

// =====================================================
// Create a new API token with the requested name post
// and response structs
// =====================================================
struct jsonSettingApiTokenNewPostStruct {
    const char*                 name;

};

struct jsonSettingApiTokenNewResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // the secret API token value

};

// =====================================================
// Delete an API token by id post and response structs
// =====================================================
struct jsonSettingApiTokenDeletePostStruct {
    int64_t                     id;

};

struct jsonSettingApiTokenDeleteResponseStruct {
    unsigned char               success;
    const char*                 msg;

};

// =====================================================
// Enable or disable an API token the full body is
// required, a partial body fails post and response
// structs
// =====================================================
struct jsonSettingApiTokenSetDBPostStruct {
    int64_t                     id;
    const char*                 name;
    unsigned char               enabled;

};

struct jsonSettingApiTokenSetDBResponseStruct {
    unsigned char               success;
    const char*                 msg;

};

// =====================================================
// Change the panel admin username and password.
// Requires the current credentials for verification.
// The session is refreshed with the new values on
// success
// =====================================================
struct jsonSettingUpdateUserPostStruct {
    const char*                 oldUsername;
    const char*                 oldPassword;
    const char*                 newUsername;
    const char*                 newPassword;

};

struct jsonSettingUpdateUserResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Restart the entire 3x-ui process after a 3-second
// grace period ( the connection drops immediately; the
// panel comes back online ~5-10 seconds later ) response
// struct
// =====================================================
struct jsonSettingRestartPanelResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Test SMTP connection with stage-by-stage reporting
// ( connect, auth, send )
// =====================================================
struct jsonSettingTestSmtpResponseStruct {
    unsigned char               success;
    const char*                 stage; // e.g. "send"
    const char*                 msg;

};

// =====================================================
// Test Telegram bot connection by sending a test message
// to the configured chat
// =====================================================
struct jsonSettingTestTgBotResponseStruct {
    unsigned char               success;
    const char*                 msg;

};

// =====================================================
// Return the built-in default Xray JSON config template
// that ships with this panel version
// =====================================================
struct jsonSettingGetDefaultJsonConfigResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Xray settings : configuration template, outbound
// management, Warp / Nord / PIA integration and config
// testing. All endpoints live under /panel/api/xray.
// =====================================================

// =====================================================
// Return the Xray config template ( JSON string ),
// available inbound tags, client reverse tags and the
// configured outbound test URL in one response post
// response structs
// =====================================================
struct jsonXrayConfigObjectResponseStruct {
    const char*                 xraySetting; // raw Xray config template as a JSON string
    const char*                 inboundTags; // JSON-string-encoded array of inbound tags,
                                             // eg "[\"in-443-tcp\"]"
    const char*                 clientReverseTags; // JSON-string-encoded array of client
                                                   // reverse tags, eg "[]"
    const char*                 outboundTestUrl; // URL used for outbound reachability tests
                                                 // eg "https://www.google.com/generate_204"

};

struct jsonXrayConfigResponseStruct {
    unsigned char               success;
    struct jsonXrayConfigObjectResponseStruct* xrayConfigObjRStruct;

};

// =====================================================
// Return the built-in default Xray config shipped with
// the panel ( identical to
// /panel/api/setting/getDefaultJsonConfig )
// =====================================================
struct jsonXrayGetDefaultJsonConfigResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Return traffic statistics for every outbound ( each
// outbound shows up/down/total counters )
// =====================================================
struct jsonXrayGetOutboundsTrafficResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // documented as per-outbound up/down/total counters but
                                     // the documented sample response shows null; exact shape
                                     // not provided ( undefined behavior )

};

// =====================================================
// Return the most recent Xray process stdout/stderr
// output ( useful to check startup errors or runtime
// warnings )
// =====================================================
struct jsonXrayGetXrayResultResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char*                 obj; // documented as the process output text but the
                                     // documented sample response shows null
                                     // ( undefined behavior )

};

// =====================================================
// Save the Xray JSON config template and optionally the
// outbound test URL ( form fields )
// =====================================================
struct jsonXrayUpdatePostStruct {
    const char*                 xraySetting; // full Xray JSON config template
    const char*                 outboundTestUrl; // URL used for outbound reachability tests

};

struct jsonXrayUpdateResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Manage Cloudflare Warp integration; the action path
// parameter selects the operation ( data, del, config,
// reg, changeIp, license, interval )
// =====================================================
struct jsonXrayWarpPostStruct {
    const char*                 privateKey; // required when action=reg
    const char*                 publicKey; // required when action=reg
    const char*                 license; // required when action=license
    int                         interval; // automatic rotation in hours; required when
                                          // action=interval; 0 disables rotation

};

struct jsonXrayWarpResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Manage NordVPN integration; the action path parameter
// selects the operation ( countries, servers, reg,
// setKey, data, del )
// =====================================================
struct jsonXrayNordPostStruct {
    const char*                 countryId; // required when action=servers
    const char*                 token; // required when action=reg
    const char*                 key; // required when action=setKey

};

struct jsonXrayNordResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Manage PIA WireGuard integration; the action path
// parameter selects the operation ( countries, servers,
// reg, data, del, addKey )
// =====================================================
struct jsonXrayPiaPostStruct {
    const char*                 countryCode; // required when action=servers
    const char*                 username; // required when action=reg
    const char*                 password; // required when action=reg
    const char*                 hostname; // required when action=addKey

};

struct jsonXrayPiaResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Reset traffic counters for a specific outbound by tag
// =====================================================
struct jsonXrayResetOutboundsTrafficPostStruct {
    const char*                 tag; // outbound tag to reset, eg "proxy", "direct"

};

struct jsonXrayResetOutboundsTrafficResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Test an outbound configuration; sends the outbound
// JSON ( required ), optionally all outbounds ( to
// resolve sockopt.dialerProxy dependencies ) and a mode
// flag
// =====================================================
struct jsonXrayTestOutboundPostStruct {
    const char*                 outbound; // JSON-encoded single outbound to test ( required )
    const char*                 allOutbounds; // JSON array of all outbounds ( dialerProxy
                                              // resolution )
    const char*                 mode; // "tcp" dial-only probe, "real" real-delay probe or
                                      // empty for a full HTTP probe

};

struct jsonXrayTestOutboundResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Test a batch of outbounds ( max 50 ) through one
// shared temp xray instance; returns an array of results
// in input order
// =====================================================
struct jsonXrayTestOutboundsPostStruct {
    const char*                 outbounds; // JSON array of outbound configs to test
                                           // ( required )
    const char*                 allOutbounds; // JSON array of all outbounds ( dialerProxy
                                              // resolution )
    const char*                 mode; // "tcp" dial-only probes, "real" real-delay probes or
                                      // empty for full HTTP probes

};

struct jsonXrayTestOutboundsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // documented as an array of results with tag, delay,
                                     // HTTP status and connect/TLS/TTFB timing breakdown but
                                     // the documented sample response shows null
                                     // ( undefined behavior )

};

// =====================================================
// Live state of routing balancers in the running core
// ( current override and the targets the strategy
// prefers ); returns a map keyed by balancer tag
// =====================================================
struct jsonXrayBalancerStatusPostStruct {
    const char*                 tags; // comma-separated balancer tags to query, eg "b1,b2"

};

struct jsonXrayBalancerStatusResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // map keyed by balancer tag; dynamic keys cannot be
                                     // modeled by a C struct and the documented sample
                                     // response shows null ( undefined behavior )

};

// =====================================================
// Force a balancer in the running core to always pick
// one outbound; applied live, cleared when Xray restarts
// =====================================================
struct jsonXrayBalancerOverridePostStruct {
    const char*                 tag; // balancer tag ( required )
    const char*                 target; // outbound tag to force; empty clears the override

};

struct jsonXrayBalancerOverrideResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Ask the running core which outbound its router would
// pick for a synthetic connection; no traffic is sent
// =====================================================
struct jsonXrayRouteTestPostStruct {
    const char*                 domain; // target domain; either domain or ip is required
    const char*                 ip; // target ip; either domain or ip is required
    int                         port; // target port ( optional )
    const char*                 network; // "tcp" ( default ) or "udp"
    const char*                 inboundTag; // simulate arrival on this inbound ( optional )
    const char*                 protocol; // sniffed protocol such as http, tls, bittorrent
    const char*                 email; // user attribution for user-based rules ( optional )

};

struct jsonXrayRouteTestResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// List the geo databases ( .dat files ) in the Xray
// asset folder with the layout detected from their
// contents, size, modification time and category count
// =====================================================
struct jsonXrayGeoDataFilesResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // documented as per-database layout, size, mtime,
                                     // category count and parse error but the documented
                                     // sample response shows null ( undefined behavior )

};

// =====================================================
// One page of a database's categories, each with its
// entry count and the attributes its domains carry
// ( eg "ads", "cn" )
// =====================================================
struct jsonXrayGeoDataCategoriesQueryStruct {
    char*                       file; // database file name inside the asset folder
                                      // ( required ), eg geosite.dat
    char*                       q; // case-insensitive substring filter on the category code
    int                         offset; // rows to skip, defaults to 0
    int                         limit; // rows to return, capped at 500; omit to return every
                                       // category

};

struct jsonXrayGeoDataCategoriesResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // documented as a page of categories with entry counts
                                     // and domain attributes but the documented sample
                                     // response shows null ( undefined behavior )

};

// =====================================================
// One page of the rules inside a category ( domain
// rules typed as domain/full/keyword/regexp for geosite
// databases, CIDRs for geoip ones )
// =====================================================
struct jsonXrayGeoDataEntriesQueryStruct {
    char*                       file; // database file name inside the asset folder
                                      // ( required )
    char*                       code; // category code, case-insensitive ( required ),
                                      // eg google
    char*                       q; // case-insensitive substring filter on the rule value
    int                         offset; // rows to skip, defaults to 0
    int                         limit; // rows to return, capped at 500, defaults to the cap

};

struct jsonXrayGeoDataEntriesResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // documented as a page of rules but the documented
                                     // sample response shows null ( undefined behavior )

};

// =====================================================
// Check routing tokens against the databases on disk
// and return only the ones that do not resolve; each
// issue carries a reason ( syntax, fileMissing or
// categoryMissing )
// =====================================================
struct jsonXrayGeoDataValidatePostStruct {
    const char*                 tokens; // comma-separated routing tokens, eg
                                        // "geosite:google,geosite:blabla", max 500
    const char*                 kind; // "ip" to parse tokens as IP rules; anything else
                                     // parses them as domain rules

};

struct jsonXrayGeoDataValidateResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // documented as the non-resolving tokens with reasons
                                     // but the documented sample response shows null
                                     // ( undefined behavior )

};

// =====================================================
// List all outbound subscriptions ( remote URLs that
// supply additional outbounds ), newest first
// =====================================================
struct jsonXrayOutboundSubsListResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // documented as the subscription rows ( remark, url,
                                     // tagPrefix, updateInterval, enabled, allowPrivate,
                                     // allowInsecure, prepend ) but the documented sample
                                     // response shows null; exact row shape not provided
                                     // ( undefined behavior )

};

// =====================================================
// Create an outbound subscription; the URL is fetched,
// parsed into outbounds with stable tags and merged
// additively into the running Xray config
// =====================================================
struct jsonXrayOutboundSubsCreatePostStruct {
    const char*                 remark; // optional display label
    const char*                 url; // subscription URL ( required ); must be public http(s),
                                    // private/internal targets blocked unless allowPrivate
    const char*                 tagPrefix; // prefix for generated outbound tags, defaults to
                                           // the lowest free "sub-" prefix
    int                         updateInterval; // seconds between auto-refreshes,
                                                // default 600
    unsigned char               enabled; // whether the subscription is active, default true
    unsigned char               allowPrivate; // allow private/internal/loopback addresses,
                                              // default false
    unsigned char               allowInsecure; // skip TLS certificate verification when
                                               // fetching the URL, default false
    unsigned char               prepend; // place this subscription's outbounds before the
                                         // manual template outbounds, default false

};

struct jsonXrayOutboundSubsCreateResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Update an existing outbound subscription by id;
// accepts the same form fields as create
// =====================================================
struct jsonXrayOutboundSubsUpdatePostStruct {
    const char*                 remark; // optional display label
    const char*                 url; // subscription URL ( required ); must be public http(s),
                                    // private/internal targets blocked unless allowPrivate
    const char*                 tagPrefix; // prefix for generated outbound tags, defaults to
                                           // the lowest free "sub-" prefix
    int                         updateInterval; // seconds between auto-refreshes,
                                                // default 600
    unsigned char               enabled; // whether the subscription is active, default true
    unsigned char               allowPrivate; // allow private/internal/loopback addresses,
                                              // default false
    unsigned char               allowInsecure; // skip TLS certificate verification when
                                               // fetching the URL, default false
    unsigned char               prepend; // place this subscription's outbounds before the
                                         // manual template outbounds, default false

};

struct jsonXrayOutboundSubsUpdateResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Delete an outbound subscription by id ( DELETE route
// and the POST /del alias for clients that cannot send
// DELETE )
// =====================================================
struct jsonXrayOutboundSubsDeleteResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Force an immediate re-fetch of the subscription and
// return the parsed outbounds; signals Xray to reload
// =====================================================
struct jsonXrayOutboundSubsRefreshResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // documented as the parsed outbounds but the documented
                                     // sample response shows null ( undefined behavior )

};

// =====================================================
// Reorder a subscription one step up or down in
// priority ( controls its position in the merged
// outbounds )
// =====================================================
struct jsonXrayOutboundSubsMovePostStruct {
    const char*                 dir; // "up" to raise priority, anything else to lower it

};

struct jsonXrayOutboundSubsMoveResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

// =====================================================
// Preview a subscription URL: fetch and parse it into
// outbounds without persisting anything
// =====================================================
struct jsonXrayOutboundSubsParsePostStruct {
    const char*                 url; // subscription URL to preview ( required )
    unsigned char               allowPrivate; // allow a private/internal/loopback URL,
                                              // default false
    unsigned char               allowInsecure; // skip TLS certificate verification,
                                               // default false

};

struct jsonXrayOutboundSubsParseResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

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

// =====================================================
// Subscription balancers : client-side balancers for the
// JSON subscription; each enabled balancer is emitted as
// one extra config document whose members are the proxy
// outbounds of the selected inbounds
// ( routing.balancers + burstObservatory ). Managed in
// Settings → Sub Balancers.
// NOTE: absent from the 3.6.0 OpenAPI ( all endpoints
// 404 here ); requires a newer panel version
// =====================================================

// =====================================================
// List all subscription balancers in sort order
// ( sort_order asc, id asc ) response structs
// =====================================================
struct jsonSubBalancerObjectStruct {
    int64_t                     createdAt; // creation time in unix milliseconds
    unsigned char               enabled; // whether the balancer is emitted
    int                         id;
    int*                        inboundIds; // member inbound ids; every pointer presented is
                                            // an element of the array
    void*                       memberWeights; // leastLoad only: JSON object mapping inbound
                                               // id to a static weight > 0, eg {"3":0.2};
                                               // lower weight is picked more often; absent
                                               // ids weigh 1; dynamic keys cannot be modeled
                                               // by a C struct ( undefined behavior )
    const char*                 remark; // display label, used as the config remarks
    int                         sortOrder; // 1-based position in the subscription list
    const char*                 strategy; // "leastLoad", "leastPing", "roundRobin" or
                                          // "random"
    int64_t                     updatedAt; // last update time in unix milliseconds

};

struct jsonListSubBalancersResponseStruct {
    unsigned char               success;
    struct jsonSubBalancerObjectStruct** listSubBalancersObjArrStruct; // every
                                                                       // pointer
                                                                       // presented is
                                                                       // an element of
                                                                       // the array

};

// =====================================================
// Create a subscription balancer; it appears in the JSON
// subscription of every client that sits on at least one
// selected inbound post and response structs
// =====================================================
struct jsonCreateSubBalancerPostStruct {
    const char*                 remark; // display label, used as the config remarks
                                        // ( required )
    const char*                 strategy; // "leastLoad", "leastPing", "roundRobin" or
                                          // "random", defaults to "random"
    int*                        inboundIds; // repeated form keys selecting the member
                                            // inbounds ( required, at least one ); every
                                            // pointer presented is an element of the array
    void*                       memberWeights; // leastLoad only: JSON object mapping inbound
                                               // id to a static weight > 0; dynamic keys
                                               // cannot be modeled by a C struct; rejected
                                               // for other strategies
                                               // ( undefined behavior )
    int                         sortOrder; // 1-based position in the subscription list,
                                           // defaults to 1
    unsigned char               enabled; // whether the balancer is emitted; default true on
                                         // create

};

struct jsonCreateSubBalancerResponseStruct {
    unsigned char               success;
    struct jsonSubBalancerObjectStruct* createSubBalancerObjRStruct;

};

// =====================================================
// Update a balancer by id; accepts the same form fields
// as create ( full-row update ); omitting memberWeights
// clears stored weights while omitting enabled keeps its
// current value
// =====================================================
struct jsonUpdateSubBalancerPostStruct {
    const char*                 remark; // display label, used as the config remarks
                                        // ( required )
    const char*                 strategy; // "leastLoad", "leastPing", "roundRobin" or
                                          // "random", defaults to "random"
    int*                        inboundIds; // repeated form keys selecting the member
                                            // inbounds ( required, at least one ); every
                                            // pointer presented is an element of the array
    void*                       memberWeights; // leastLoad only: JSON object mapping inbound
                                               // id to a static weight > 0; dynamic keys
                                               // cannot be modeled by a C struct; rejected
                                               // for other strategies
                                               // ( undefined behavior )
    int                         sortOrder; // 1-based position in the subscription list,
                                           // defaults to 1
    unsigned char               enabled; // whether the balancer is emitted; unchanged when
                                         // omitted on update

};

struct jsonUpdateSubBalancerResponseStruct {
    unsigned char               success;
    struct jsonSubBalancerObjectStruct* updateSubBalancerObjRStruct;

};

// =====================================================
// Delete a balancer by id ( DELETE route and the POST
// /del alias for clients that cannot send DELETE )
// =====================================================
struct jsonDeleteSubBalancerResponseStruct {
    unsigned char               success;
    struct jsonSubBalancerObjectStruct* deleteSubBalancerObjRStruct;

};


#endif

