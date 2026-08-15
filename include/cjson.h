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
    int64_t                     updated_at;

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
    struct jsonAddInboundSettingsClientsArrayPostStruct* addInSettingsCliArrPostStruct;
    const char*                 decryption;
    struct jsonAddInboundSettingsFallbacksArrayPostStruct* addInSettingsFalbackArrPostStruct;

};

struct jsonAddInboundStreamSettingsRealitySettingsObjectPostStruct {
    unsigned char               show;
    const char*                 dest;

};

struct jsonAddInboundStreamSettingsObjPostStruct {
    const char*                 network;
    const char*                 security;
    struct jsonAddInboundStreamSettingsRealitySettingsObjectPostStruct* addInStreamSettignsRealitySettingsObjPostStruct;

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
    struct jsonAddInboundSettingsObjPostStruct* addInSettingsObjPostStruct;
    struct jsonAddInboundStreamSettingsObjPostStruct* addInStreamSettingsObjPostStruct;
    struct jsonAddInboundSniffingObjectPostStruct* addInSniffingObjPostStruct;

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
// -H "Authorization: Bearer UGoPnx7t78eMIX84r6xmIkoIDHburMj9NgYeYQMCmLS26HxW" \  --data-urlencode "data=$(jq -c . <<< '{
//  "id": 1,
//  "userId": 0,
//  "up": 0,
//  "down": 0,
//  "total": 0,
//  "remark": "fssdfasdfasfa",
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
    unsigned char               success;
    const char*                 msg;
    struct jsonListInboundObjectStruct* listInObjStruct;

};

#endif

