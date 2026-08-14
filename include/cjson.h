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
struct addInboundSettingsClientsArrayPostStruct {
    const char* id;
    const char* email;

};

struct addInboundSettingsFallbacksArrayPostStruct {
    // TODO: its now known how the fallback works

};

struct addInboundSettingsObjPostStruct {
    struct addInboundSettingsClientsArrayPostStruct* addInSettingsCliArrPostStruct;
    const char* decryption;
    struct addInboundSettingsFallbacksArrayPostStruct* addInSettingsFalbackArrPostStruct;

};

struct addInboundStreamSettingsRealitySettingsObjectPostStruct {
    unsigned char show;
    const char* dest;

};

struct addInboundStreamSettingsObjPostStruct {
    const char* network;
    const char* security;
    struct addInboundStreamSettingsRealitySettingsObjectPostStruct* addInStreamSettignsRealitySettingsObjPostStruct;

};

struct addInboundSniffingObjectPostStruct {
    unsigned char enabled;
    struct addInboundSniffingObjectDestOverrideArrStruct* addInSniffingObjDestOverrideArrStruct;

};

struct addInboundPostStruct {
    unsigned char enable;
    const char* remark;
    const char* listen;
    int port;
    const char* protocol;
    int64_t expiryTime;
    const char* total;
    struct addInboundSettingsObjPostStruct* addInSettingsObjPostStruct;
    struct addInboundStreamSettingsObjPostStruct* addInStreamSettingsObjPostStruct;
    struct addInboundSniffingObjectPostStruct* addInSniffingObjPostStruct;

};

struct addInboundResponseStruct {
    unsigned char success;
    const char* msg;
    unsigned char obj;

};

#endif

