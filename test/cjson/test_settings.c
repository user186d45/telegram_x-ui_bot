#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cjson/settings.h"

static int failures = 0;

#define CHECK(cond, name) do { if (cond) { printf("OK %s\n", name); } else { printf("FAILED %s\n", name); failures++; } } while (0)

static void test_setting_all_response(void) {
    const char* json = "{\"success\":true,\"msg\":\"\",\"obj\":{\"web\":{\"webBasePath\":\"/panel/\",\"webCertFile\":\"\",\"webDomain\":\"example.com\",\"webKeyFile\":\"\",\"webListen\":\"\",\"webPort\":8080},\"tg\":{\"tgBotAPIServer\":\"api.telegram.org\",\"tgBotBackup\":false,\"tgBotChatId\":\"123456\",\"tgBotEnable\":true,\"tgBotProxy\":\"\",\"tgBotToken\":\"token123\",\"tgCpu\":10,\"tgEnabledEvents\":\"login.attempt,cpu.high\",\"tgLang\":\"en\",\"tgMemory\":512,\"tgRunTime\":\"@daily\"},\"smtp\":{\"smtpCpu\":10,\"smtpEnable\":false,\"smtpEnabledEvents\":\"login.attempt,cpu.high\",\"smtpEncryptionType\":\"starttls\",\"smtpFrom\":\"test@example.com\",\"smtpFromName\":\"Test\",\"smtpHost\":\"smtp.example.com\",\"smtpMemory\":10,\"smtpPassword\":\"pass\",\"smtpPort\":587,\"smtpTo\":\"admin@example.com\",\"smtpUsername\":\"user\"},\"ldap\":{\"ldapAutoCreate\":false,\"ldapAutoDelete\":false,\"ldapBaseDN\":\"dc=example,dc=com\",\"ldapBindDN\":\"cn=admin,dc=example,dc=com\",\"ldapDefaultExpiryDays\":30,\"ldapDefaultLimitIP\":0,\"ldapDefaultTotalGB\":0,\"ldapEnable\":false,\"ldapFlagField\":\"memberOf\",\"ldapHost\":\"ldap.example.com\",\"ldapInboundTags\":\"\",\"ldapInsecureSkipVerify\":false,\"ldapInvertFlag\":false,\"ldapPassword\":\"password\",\"ldapPort\":389,\"ldapSyncCron\":\"@every 1m\",\"ldapInsecureSkipVerify\":false,\"ldapInvertFlag\":false,\"ldapPassword\":\"password\",\"ldapPort\":389,\"ldapSyncCron\":\"@every 1m\",\"ldapTruthyValues\":\"true,1,yes,on\",\"ldapUseTLS\":false,\"ldapUserAttr\":\"uid\",\"ldapUserFilter\":\"(objectClass=person)\",\"ldapVlessField\":\"vless\"},\"sub\":{\"subAnnounce\":\"\",\"subCertFile\":\"\",\"subClashAutoDetect\":false,\"subClashEnable\":false,\"subClashEnableRouting\":false,\"subClashPath\":\"clash\",\"subClashRules\":\"\",\"subClashURI\":\"\",\"subClashUserAgentRegex\":\"\",\"subDomain\":\"sub.example.com\",\"subEnable\":true,\"subEnableRouting\":true,\"subEncrypt\":false,\"subHideSettings\":false,\"subIncyEnableRouting\":false,\"subIncyRoutingRules\":\"\",\"subJsonAlwaysArray\":false,\"subJsonAutoDetect\":false,\"subJsonEnable\":false,\"subJsonFinalMask\":\"\",\"subJsonMux\":\"\",\"subJsonPath\":\"json\",\"subJsonRules\":\"\",\"subJsonURI\":\"\",\"subJsonUserAgentRegex\":\"\",\"subKeyFile\":\"\",\"subListen\":\"\",\"subPath\":\"sub\",\"subPort\":8080,\"subProfileUrl\":\"\",\"subRoutingRules\":\"\",\"subShowIdentityOnAllLinks\":false,\"subSupportUrl\":\"\",\"subThemeDir\":\"\",\"subTitle\":\"My Sub\",\"subURI\":\"\",\"subUpdates\":86400},\"hasFlags\":{\"hasApiToken\":true,\"hasLdapPassword\":false,\"hasNordSecret\":false,\"hasSmtpPassword\":false,\"hasTgBotToken\":true,\"hasTwoFactorToken\":false,\"hasWarpSecret\":false},\"general\":{\"datepicker\":\"gregorian\",\"expireDiff\":0,\"externalTrafficInformEnable\":false,\"externalTrafficInformURI\":\"\",\"outboundDownThreshold\":0,\"pageSize\":25,\"panelOutbound\":\"\",\"remarkTemplate\":\"\",\"restartXrayOnClientDisable\":false,\"sessionMaxAge\":1440,\"timeLocation\":\"Local\",\"trafficDiff\":0,\"trustedProxyCIDRs\":\"127.0.0.1/32,::1/128\",\"twoFactorEnable\":false,\"twoFactorToken\":\"\",\"warpUpdateInterval\":86400}}}";

    struct jsonSettingAllResponseStruct* r = jsonSettingAllResponse(json);
    CHECK(r && r->success == 1, "setting all response success");
    CHECK(r && r->setAllObjStruct != NULL, "setting all response has obj");
    CHECK(r && r->setAllObjStruct->setAllObjWebObjStruct != NULL, "setting all response has web");
    CHECK(r && r->setAllObjStruct->setAllObjTgObjStruct != NULL, "setting all response has tg");
    CHECK(r && r->setAllObjStruct->setAllObjSmtpObjStruct != NULL, "setting all response has smtp");
    CHECK(r && r->setAllObjStruct->setAllObjLdapObjStruct != NULL, "setting all response has ldap");
    CHECK(r && r->setAllObjStruct->setAllObjSubObjStruct != NULL, "setting all response has sub");
    CHECK(r && r->setAllObjStruct->setAllObjHasFlagsObjStruct != NULL, "setting all response has hasFlags");
    CHECK(r && r->setAllObjStruct->setAllObjGeneralObjStruct != NULL, "setting all response has general");
    if (r && r->setAllObjStruct && r->setAllObjStruct->setAllObjWebObjStruct) {
        CHECK(r->setAllObjStruct->setAllObjWebObjStruct->webDomain && strcmp(r->setAllObjStruct->setAllObjWebObjStruct->webDomain, "example.com") == 0, "web domain parsed");
        CHECK(r->setAllObjStruct->setAllObjWebObjStruct->webPort == 8080, "web port parsed");
    }
    jsonSettingAllResponseStructDelete(r);
}

static void test_default_settings(void) {
    const char* json = "{\"success\":true,\"msg\":\"\",\"obj\":{\"accessLogEnable\":false,\"datepicker\":\"gregorian\",\"defaultCert\":\"\",\"defaultKey\":\"\",\"devChannelEnable\":false,\"expireDiff\":0,\"ipLimitEnable\":false,\"isDevBuild\":false,\"pageSize\":25,\"subClashEnable\":false,\"subClashURI\":\"\",\"subDomain\":\"\",\"subEnable\":true,\"subJsonEnable\":false,\"subJsonURI\":\"\",\"subThemeDir\":\"\",\"subTitle\":\"\",\"subURI\":\"\",\"tgBotEnable\":false,\"trafficDiff\":0,\"webDomain\":\"example.com\"}}";

    struct jsonSettingDefaultSettingsResponseStruct* r = jsonSettingDefaultSettingsResponse(json);
    CHECK(r && r->success == 1, "default settings response success");
    CHECK(r && r->defSettingsObjStruct != NULL, "default settings has obj");
    if (r && r->defSettingsObjStruct) {
        CHECK(r->defSettingsObjStruct->pageSize == 25, "default settings pageSize");
        CHECK(r->defSettingsObjStruct->webDomain && strcmp(r->defSettingsObjStruct->webDomain, "example.com") == 0, "default settings webDomain");
    }
    jsonSettingDefaultSettingsResponseStructDelete(r);
}

static void test_factory_defaults(void) {
    const char* json = "{\"success\":true,\"msg\":\"\",\"obj\":{\"datepicker\":\"gregorian\",\"expireDiff\":\"0\",\"externalTrafficInformEnable\":\"false\",\"externalTrafficInformURI\":\"\",\"ldapAutoCreate\":\"false\",\"ldapAutoDelete\":\"false\",\"ldapBaseDN\":\"\",\"ldapBindDN\":\"\",\"ldapDefaultExpiryDays\":\"30\",\"ldapDefaultLimitIP\":\"0\",\"ldapDefaultTotalGB\":\"0\",\"ldapEnable\":\"false\",\"ldapFlagField\":\"\",\"ldapHost\":\"\",\"ldapInboundTags\":\"\",\"ldapInsecureSkipVerify\":\"false\",\"ldapInvertFlag\":\"false\",\"ldapPort\":\"389\",\"ldapSyncCron\":\"@every 1m\",\"ldapTruthyValues\":\"true,1,yes,on\",\"ldapUseTLS\":\"false\",\"ldapUserAttr\":\"uid\",\"ldapUserFilter\":\"(objectClass=person)\",\"ldapVlessField\":\"vless\",\"outboundDownThreshold\":\"0\",\"pageSize\":\"25\",\"panelOutbound\":\"\",\"remarkTemplate\":\"\",\"restartXrayOnClientDisable\":\"false\",\"sessionMaxAge\":\"1440\",\"smtpCpu\":\"10\",\"smtpEnable\":\"false\",\"smtpEnabledEvents\":\"login.attempt,cpu.high\",\"smtpEncryptionType\":\"starttls\",\"smtpFrom\":\"\",\"smtpFromName\":\"\",\"smtpHost\":\"\",\"smtpMemory\":\"10\",\"smtpPort\":\"587\",\"smtpTo\":\"\",\"smtpUsername\":\"\",\"subAnnounce\":\"\",\"subCertFile\":\"\",\"subClashAutoDetect\":\"false\",\"subClashEnable\":\"false\",\"subClashEnableRouting\":\"false\",\"subClashPath\":\"clash\",\"subClashRules\":\"\",\"subClashURI\":\"\",\"subClashUserAgentRegex\":\"\",\"subDomain\":\"\",\"subEnable\":\"true\",\"subEnableRouting\":\"true\",\"subEncrypt\":\"false\",\"subHideSettings\":\"false\",\"subIncyEnableRouting\":\"false\",\"subIncyRoutingRules\":\"\",\"subJsonAlwaysArray\":\"false\",\"subJsonAutoDetect\":\"false\",\"subJsonEnable\":\"false\",\"subJsonFinalMask\":\"\",\"subJsonMux\":\"\",\"subJsonPath\":\"json\",\"subJsonRules\":\"\",\"subJsonURI\":\"\",\"subJsonUserAgentRegex\":\"\",\"subKeyFile\":\"\",\"subListen\":\"\",\"subPath\":\"sub\",\"subPort\":\"8080\",\"subProfileUrl\":\"\",\"subRoutingRules\":\"\",\"subShowIdentityOnAllLinks\":\"false\",\"subSupportUrl\":\"\",\"subThemeDir\":\"\",\"subTitle\":\"\",\"subURI\":\"\",\"subUpdates\":\"86400\",\"tgBotAPIServer\":\"api.telegram.org\",\"tgBotBackup\":\"false\",\"tgBotChatId\":\"\",\"tgBotEnable\":\"false\",\"tgBotProxy\":\"\",\"tgCpu\":\"10\",\"tgEnabledEvents\":\"login.attempt,cpu.high\",\"tgLang\":\"en\",\"tgMemory\":\"512\",\"tgRunTime\":\"@daily\",\"timeLocation\":\"Local\",\"trafficDiff\":\"0\",\"trustedProxyCIDRs\":\"127.0.0.1/32,::1/128\",\"twoFactorEnable\":\"false\",\"warpUpdateInterval\":\"86400\",\"webBasePath\":\"/panel/\",\"webCertFile\":\"\",\"webDomain\":\"\",\"webKeyFile\":\"\",\"webListen\":\"\",\"webPort\":\"8080\"}}";

    struct jsonSettingFactoryDefaultsResponseStruct* r = jsonSettingFactoryDefaultsResponse(json);
    CHECK(r && r->success == 1, "factory defaults response success");
    CHECK(r && r->factoryDefaultsObjStruct != NULL, "factory defaults has obj");
    jsonSettingFactoryDefaultsResponseStructDelete(r);
}

static void test_validate_regex(void) {
    const char* regex = "^[a-zA-Z0-9]+$";
    struct jsonSettingValidateRegexPostStruct* post = calloc(1, sizeof(struct jsonSettingValidateRegexPostStruct));
    post->regex = strdup(regex);
    const char* s = jsonSettingValidateRegexPost(post);
    CHECK(s && strstr(s, regex) != NULL, "validate regex post matches");
    free((char*)s);
    jsonSettingValidateRegexPostStructDelete(post);

    struct jsonSettingValidateRegexResponseStruct* r = jsonSettingValidateRegexResponse("{\"success\":true,\"msg\":\"valid\"}");
    CHECK(r && r->success == 1 && r->msg && strcmp(r->msg, "valid") == 0, "validate regex response");
    jsonSettingValidateRegexResponseStructDelete(r);
}

static void test_api_tokens(void) {
    const char* json = "{\"success\":true,\"msg\":\"\",\"obj\":[{\"id\":1,\"name\":\"test-token\",\"enabled\":true,\"createdAt\":1735689600000}]}";
    struct jsonSettingApiTokensListPostStruct* r = jsonSettingApiTokensListPostStructParse(json);
    CHECK(r && r->success == 1, "api tokens list parse success");
    CHECK(r && r->jsonSettingApiTokensObjectStructSize == 1, "api tokens list size");
    if (r && r->objArrays) {
        CHECK(r->objArrays[0].id == 1, "api token id");
        CHECK(r->objArrays[0].name && strcmp(r->objArrays[0].name, "test-token") == 0, "api token name");
        CHECK(r->objArrays[0].enabled == 1, "api token enabled");
        CHECK(r->objArrays[0].createdAt == 1735689600000, "api token createdAt");
    }
    jsonSettingApiTokensListPostStructDelete(r);
}

static void test_api_token_new(void) {
    struct jsonSettingApiTokenNewPostStruct* post = calloc(1, sizeof(struct jsonSettingApiTokenNewPostStruct));
    post->name = strdup("new-token");
    const char* s = jsonSettingApiTokenNewPost(post);
    CHECK(s && strstr(s, "\"name\":\"new-token\"") != NULL, "api token new post");
    free((char*)s);
    jsonSettingApiTokenNewPostStructDelete(post);

    struct jsonSettingApiTokenNewResponseStruct* r = jsonSettingApiTokenNewResponse("{\"success\":true,\"msg\":\"\",\"obj\":\"secret-token-value\"}");
    CHECK(r && r->success == 1, "api token new response");
    CHECK(r && r->obj && strcmp((char*)r->obj, "secret-token-value") == 0, "api token new response obj");
    jsonSettingApiTokenNewResponseStructDelete(r);
}

static void test_api_token_delete(void) {
    struct jsonSettingApiTokenDeletePostStruct* post = calloc(1, sizeof(struct jsonSettingApiTokenDeletePostStruct));
    post->id = 123;
    const char* s = jsonSettingApiTokenDeletePost(post);
    CHECK(s && strstr(s, "\"id\":123") != NULL, "api token delete post");
    free((char*)s);
    jsonSettingApiTokenDeletePostStructDelete(post);

    struct jsonSettingApiTokenDeleteResponseStruct* r = jsonSettingApiTokenDeleteResponse("{\"success\":true,\"msg\":\"deleted\"}");
    CHECK(r && r->success == 1, "api token delete response");
    jsonSettingApiTokenDeleteResponseStructDelete(r);
}

static void test_api_token_set_db(void) {
    struct jsonSettingApiTokenSetDBPostStruct* post = calloc(1, sizeof(struct jsonSettingApiTokenSetDBPostStruct));
    post->id = 123;
    post->name = strdup("updated-token");
    post->enabled = 0;
    const char* s = jsonSettingApiTokenSetDBPost(post);
    CHECK(s && strstr(s, "\"id\":123") != NULL && strstr(s, "\"name\":\"updated-token\"") != NULL && strstr(s, "\"enabled\":false") != NULL, "api token set db post");
    free((char*)s);
    jsonSettingApiTokenSetDBPostStructDelete(post);

    struct jsonSettingApiTokenSetDBResponseStruct* r = jsonSettingApiTokenSetDBResponse("{\"success\":true,\"msg\":\"updated\"}");
    CHECK(r && r->success == 1, "api token set db response");
    jsonSettingApiTokenSetDBResponseStructDelete(r);
}

static void test_update_user(void) {
    struct jsonSettingUpdateUserPostStruct* post = calloc(1, sizeof(struct jsonSettingUpdateUserPostStruct));
    post->oldUsername = strdup("admin");
    post->oldPassword = strdup("oldpass");
    post->newUsername = strdup("newadmin");
    post->newPassword = strdup("newpass");
    const char* s = jsonSettingUpdateUserPost(post);
    CHECK(s && strstr(s, "\"oldUsername\":\"admin\"") != NULL && strstr(s, "\"newUsername\":\"newadmin\"") != NULL, "update user post");
    free((char*)s);
    jsonSettingUpdateUserPostStructDelete(post);

    struct jsonSettingUpdateUserResponseStruct* r = jsonSettingUpdateUserResponse("{\"success\":true,\"msg\":\"updated\"}");
    CHECK(r && r->success == 1, "update user response");
    jsonSettingUpdateUserResponseStructDelete(r);
}

static void test_restart_panel(void) {
    struct jsonSettingRestartPanelResponseStruct* r = jsonSettingRestartPanelResponse("{\"success\":true,\"msg\":\"restarting\"}");
    CHECK(r && r->success == 1 && r->msg && strcmp(r->msg, "restarting") == 0, "restart panel response");
    jsonSettingRestartPanelResponseStructDelete(r);
}

static void test_test_smtp(void) {
    struct jsonSettingTestSmtpResponseStruct* r = jsonSettingTestSmtpResponse("{\"success\":true,\"msg\":\"sent\",\"stage\":\"send\"}");
    CHECK(r && r->success == 1 && r->msg && strcmp(r->msg, "sent") == 0 && r->stage && strcmp(r->stage, "send") == 0, "test smtp response");
    jsonSettingTestSmtpResponseStructDelete(r);
}

static void test_test_tgbot(void) {
    struct jsonSettingTestTgBotResponseStruct* r = jsonSettingTestTgBotResponse("{\"success\":true,\"msg\":\"test sent\"}");
    CHECK(r && r->success == 1 && r->msg && strcmp(r->msg, "test sent") == 0, "test tgbot response");
    jsonSettingTestTgBotResponseStructDelete(r);
}

static void test_get_default_json_config(void) {
    struct jsonSettingGetDefaultJsonConfigResponseStruct* r = jsonSettingGetDefaultJsonConfigResponse("{\"success\":true,\"msg\":\"\"}");
    CHECK(r && r->success == 1, "get default json config response");
    jsonSettingGetDefaultJsonConfigResponseStructDelete(r);
}

int main(void) {
    test_setting_all_response();
    test_default_settings();
    test_factory_defaults();
    test_validate_regex();
    test_api_tokens();
    test_api_token_new();
    test_api_token_delete();
    test_api_token_set_db();
    test_update_user();
    test_restart_panel();
    test_test_smtp();
    test_test_tgbot();
    test_get_default_json_config();

    if (failures) {
        printf("SETTINGS TESTS FAILED: %d\n", failures);
        return 1;
    }
    printf("SETTINGS TESTS PASSED\n");
    return 0;
}
