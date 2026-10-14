#ifndef CJSON_TELEGRAM_XUI_BOT_SETTINGS_H
#define CJSON_TELEGRAM_XUI_BOT_SETTINGS_H

// settings section - https://docs.sanaei.dev/docs/reference/api/settings/

#include <stddef.h>
#include <stdint.h>


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
    size_t                      jsonSettingApiTokensObjectStructSize;
    struct jsonSettingApiTokensObjectStruct* objArrays; // array

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

void        jsonSettingAllWebObjectStructDelete(struct jsonSettingAllWebObjectStruct* setAllObjWebObjStruct);

void        jsonSettingAllTgObjectStructDelete(struct jsonSettingAllTgObjectStruct* setAllObjTgObjStruct);

void        jsonSettingAllSmtpObjectStructDelete(struct jsonSettingAllSmtpObjectStruct* setAllObjSmtpObjStruct);

void        jsonSettingAllLdapObjectStructDelete(struct jsonSettingAllLdapObjectStruct* setAllObjLdapObjStruct);

void        jsonSettingAllSubObjectStructDelete(struct jsonSettingAllSubObjectStruct* setAllObjSubObjStruct);

void        jsonSettingAllHasFlagsObjectStructDelete(struct jsonSettingAllHasFlagsObjectStruct* setAllObjHasFlagsObjStruct);

void        jsonSettingAllGeneralObjectStructDelete(struct jsonSettingAllGeneralObjectStruct* setAllObjGeneralObjStruct);

void        jsonSettingAllObjectStructDelete(struct jsonSettingAllObjectStruct* setAllObjStruct);

void        jsonSettingAllResponseStructDelete(struct jsonSettingAllResponseStruct* settingAllRStruct);

void        jsonSettingDefaultSettingsObjectStructDelete(struct jsonSettingDefaultSettingsObjectStruct* defSettingsObjStruct);

void        jsonSettingDefaultSettingsResponseStructDelete(struct jsonSettingDefaultSettingsResponseStruct* settingDefaultSettingsRStruct);

void        jsonSettingFactoryDefaultsObjectStructDelete(struct jsonSettingFactoryDefaultsObjectStruct* factoryDefaultsObjStruct);

void        jsonSettingFactoryDefaultsResponseStructDelete(struct jsonSettingFactoryDefaultsResponseStruct* settingFactoryDefaultsRStruct);

void        jsonSettingUpdatePostStructDelete(struct jsonSettingUpdatePostStruct* settingUpdatePostStruct);

void        jsonSettingUpdateResponseStructDelete(struct jsonSettingUpdateResponseStruct* settingUpdateRStruct);

void        jsonSettingValidateRegexPostStructDelete(struct jsonSettingValidateRegexPostStruct* settingValidateRegexPostStruct);

void        jsonSettingValidateRegexResponseStructDelete(struct jsonSettingValidateRegexResponseStruct* settingValidateRegexRStruct);

void        jsonSettingApiTokensObjectStructDelete(struct jsonSettingApiTokensObjectStruct* objArrays, size_t arraySize);

void        jsonSettingApiTokensListPostStructDelete(struct jsonSettingApiTokensListPostStruct* settingApiTokensListPostStruct);

void        jsonSettingApiTokenNewPostStructDelete(struct jsonSettingApiTokenNewPostStruct* settingApiTokenNewPostStruct);

void        jsonSettingApiTokenNewResponseStructDelete(struct jsonSettingApiTokenNewResponseStruct* settingApiTokenNewRStruct);

void        jsonSettingApiTokenDeletePostStructDelete(struct jsonSettingApiTokenDeletePostStruct* settingApiTokenDeletePostStruct);

void        jsonSettingApiTokenDeleteResponseStructDelete(struct jsonSettingApiTokenDeleteResponseStruct* settingApiTokenDeleteRStruct);

void        jsonSettingApiTokenSetDBPostStructDelete(struct jsonSettingApiTokenSetDBPostStruct* settingApiTokenSetDBPostStruct);

void        jsonSettingApiTokenSetDBResponseStructDelete(struct jsonSettingApiTokenSetDBResponseStruct* settingApiTokenSetDBRStruct);

void        jsonSettingUpdateUserPostStructDelete(struct jsonSettingUpdateUserPostStruct* settingUpdateUserPostStruct);

void        jsonSettingUpdateUserResponseStructDelete(struct jsonSettingUpdateUserResponseStruct* settingUpdateUserRStruct);

void        jsonSettingRestartPanelResponseStructDelete(struct jsonSettingRestartPanelResponseStruct* settingRestartPanelRStruct);

void        jsonSettingTestSmtpResponseStructDelete(struct jsonSettingTestSmtpResponseStruct* settingTestSmtpRStruct);

void        jsonSettingTestTgBotResponseStructDelete(struct jsonSettingTestTgBotResponseStruct* settingTestTgBotRStruct);

void        jsonSettingGetDefaultJsonConfigResponseStructDelete(struct jsonSettingGetDefaultJsonConfigResponseStruct* settingGetDefaultJsonConfigRStruct);

struct jsonSettingAllResponseStruct*               jsonSettingAllResponse(const char* json);

struct jsonSettingDefaultSettingsResponseStruct*   jsonSettingDefaultSettingsResponse(const char* json);

struct jsonSettingFactoryDefaultsResponseStruct*   jsonSettingFactoryDefaultsResponse(const char* json);

const char*                                        jsonSettingUpdatePost(struct jsonSettingUpdatePostStruct* settingUpdatePostStruct);

struct jsonSettingUpdateResponseStruct*            jsonSettingUpdateResponse(const char* json);

const char*                                        jsonSettingValidateRegexPost(struct jsonSettingValidateRegexPostStruct* settingValidateRegexPostStruct);

struct jsonSettingValidateRegexResponseStruct*     jsonSettingValidateRegexResponse(const char* json);

const char*                                        jsonSettingApiTokensListPost(struct jsonSettingApiTokensListPostStruct* settingApiTokensListPostStruct);

const char*                                        jsonSettingApiTokenNewPost(struct jsonSettingApiTokenNewPostStruct* settingApiTokenNewPostStruct);

struct jsonSettingApiTokenNewResponseStruct*       jsonSettingApiTokenNewResponse(const char* json);

const char*                                        jsonSettingApiTokenDeletePost(struct jsonSettingApiTokenDeletePostStruct* settingApiTokenDeletePostStruct);

struct jsonSettingApiTokenDeleteResponseStruct*    jsonSettingApiTokenDeleteResponse(const char* json);

const char*                                        jsonSettingApiTokenSetDBPost(struct jsonSettingApiTokenSetDBPostStruct* settingApiTokenSetDBPostStruct);

struct jsonSettingApiTokenSetDBResponseStruct*     jsonSettingApiTokenSetDBResponse(const char* json);

const char*                                        jsonSettingUpdateUserPost(struct jsonSettingUpdateUserPostStruct* settingUpdateUserPostStruct);

struct jsonSettingUpdateUserResponseStruct*        jsonSettingUpdateUserResponse(const char* json);

struct jsonSettingRestartPanelResponseStruct*      jsonSettingRestartPanelResponse(const char* json);

struct jsonSettingTestSmtpResponseStruct*          jsonSettingTestSmtpResponse(const char* json);

struct jsonSettingTestTgBotResponseStruct*         jsonSettingTestTgBotResponse(const char* json);

struct jsonSettingGetDefaultJsonConfigResponseStruct* jsonSettingGetDefaultJsonConfigResponse(const char* json);

#endif /* CJSON_TELEGRAM_XUI_BOT_SETTINGS_H */
