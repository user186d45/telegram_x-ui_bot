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
    int64_t                     limitHwid;
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
    int page;
    int pageSize;
    char* search;
    char* filter;
    char* protocol;
    char* sort;
    char* order;

};

struct jsonFilterClientsObjectResponseStruct {
    struct jsonFilterClientsObjectItemsArrayResponseStruct* filterCliObjItemsArrStruct;
    int64_t total;
    int64_t filtered;
    int page;
    unsigned short pageSize;
    struct jsonFilterClientsObjectSummaryObjectResponseStruct* filterCliObjSummaryObjRStruct; // Summary
    struct jsonFilterClientsObjectDepletedArrayResponseStruct* filterCliObjDepletedArrRStruct; // Depleted
    struct jsonFilterClientsObjectExpiringArrayResponseStruct* filterCliObjExpiringArrRStruct; // Expiring
    struct jsonFilterClientsObjectDeactiveArrayResponseStruct* filterCliObjDeactiveArrRStruct; // Deactive

};

struct jsonFilterClientsGroupObjectResponseStruct {
    // Functionality unknown

};

struct jsonFilterClientsResponseStruct {
    unsigned char success;
    const char* msg;
    struct jsonFilterClientsObjectResponseStruct* filterCliObjRStruct;
    struct jsonFilterClientsGroupObjectResponseStruct* filterCliGroupObjRStruct;

};

// =====================================================
// Fetch details of one client by email
// =====================================================

/*
 * The response of the server to fetching by email request is not accurately
 * provided at the original documentaion thus it will be introduced here:
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
    int64_t id;
    const char* email;
    const char* subId;
    const char* uuid;
    const char* password;
    const char* auth;
    const char* flow;
    const char* security;
    const char* privateKey;
    const char* publicKey;
    const char* allowedIPs;
    const char* preSharedKey;
    int keepAlive;
    const char* forwardedPorts;
    const char* secret;
    const char* adTag;
    int limitIp;
    int limitHwid;
    int totalGB;
    int64_t expiryTime;
    unsigned char enable;
    int64_t tgId;
    const char* group;
    const char* comment;
    int reset;
    int resetDay;
    int resetMax;
    const char* trafficReset;
    int trafficResetDay;
    int64_t createdAt;
    int64_t updatedAt;
    void* reverse; // This shall be null on normal ( not customized  ) setup

};

struct jsonFetchClientByEmailObjectExternalLinksArrayStruct {
    // what this returns is unknwon

};

struct jsonFetchClientByEmailObjectStruct {
    struct jsonFetchClientByEmailObjectClientObjectStruct* fetchCliByEmailObjCliObjStruct;
    struct jsonFetchClientByEmailObjectExternalLinksArrayStruct* fetchCliByEmailObjExternalLinksArrStruct;
    int* inboundIds;
    const char* tunnelAllowedIPs;
    int64_t usedTraffic;

};

struct jsonFetchClientByEmailStruct {
    unsigned char success;
    const char* msg;
    struct jsonFetchClientByEmailObjectStruct* fetchCliByEmailObjStruct;

};

// =====================================================
// Fetch details of one client by telegram id
// =====================================================

// TODO: complete this on writing ( and testing  ) the add client post structure

#endif

