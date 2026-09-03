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
    int64_t                     totalGB;
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
    int64_t                     totalGB;
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
struct jsonFilterClientsPostStruct {
    int                         page;
    int                         pageSize;
    char*                       search;
    char*                       filter;
    char*                       protocol;
    char*                       sort;
    char*                       order;

};

struct jsonFilterClientsObjectResponseStruct {
    struct jsonFilterClientsObjectItemsArrayResponseStruct* filterCliObjItemsArrStruct;
    int64_t                     total;
    int64_t                     filtered;
    int page;
    unsigned short              pageSize;
    struct jsonFilterClientsObjectSummaryObjectResponseStruct* filterCliObjSummaryObjRStruct; // Summary
    struct jsonFilterClientsObjectDepletedArrayResponseStruct* filterCliObjDepletedArrRStruct; // Depleted
    struct jsonFilterClientsObjectExpiringArrayResponseStruct* filterCliObjExpiringArrRStruct; // Expiring
    struct jsonFilterClientsObjectDeactiveArrayResponseStruct* filterCliObjDeactiveArrRStruct; // Deactive

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
    int                         totalGB;
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
    // what this returns is unknwon

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
    int                         totalGB;
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
    struct jsonImportClientsObjectSkippedArrayResponseStruct* importClisObjSkippedArrRStruct; // skipped array

};

struct jsonImportClientsResponseStruct {
    unsigned char success;
    const char* msg;
    struct jsonImportClientsObjectResponseStruct* importClisObjRStruct;

};

#endif

