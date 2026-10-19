#include "../../include/cjson/settings.h"
#include "../../include/cjson/jsonValidation.h"
#include "../../include/log.h"

#include <cjson/cJSON.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

static char* jsonCopyText(const char* value) {
    size_t valueLen = strlen(value);
    char* valueCopy = (char*)malloc((valueLen + 1) * sizeof(char));
    if (!valueCopy) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "valueCopy is a null pointer, failed to allocate memory");
        return NULL;
    }
    strncpy(valueCopy, value, valueLen);
    valueCopy[valueLen] = '\0';
    return valueCopy;
}

static int jsonCopyStringItem(cJSON* parent, const char* key, const char** dest) {
    if (!cJSON_HasObjectItem(parent, key) || !cJSON_IsString(cJSON_GetObjectItem(parent, key))) {
        return 1;
    }
    const char* value = cJSON_GetObjectItem(parent, key)->valuestring;
    char* valueCopy = jsonCopyText(value);
    if (!valueCopy) {
        return 0;
    }
    *dest = valueCopy;
    return 1;
}

static int jsonCopyNumberItem(cJSON* parent, const char* key, int64_t* dest) {
    if (!cJSON_HasObjectItem(parent, key) || !cJSON_IsNumber(cJSON_GetObjectItem(parent, key))) {
        return 1;
    }
    *dest = (int64_t)cJSON_GetObjectItem(parent, key)->valuedouble;
    return 1;
}

static int jsonCopyBoolItem(cJSON* parent, const char* key, unsigned char* dest) {
    if (!cJSON_HasObjectItem(parent, key) || !cJSON_IsBool(cJSON_GetObjectItem(parent, key))) {
        return 1;
    }
    *dest = cJSON_IsTrue(cJSON_GetObjectItem(parent, key)) ? 1 : 0;
    return 1;
}

static const char* jsonCopyMsg(cJSON* jsonParser) {
    const char* msg = NULL;
    jsonCopyStringItem(jsonParser, "msg", &msg);
    return msg;
}


void jsonSettingAllWebObjectStructDelete(struct jsonSettingAllWebObjectStruct* setAllObjWebObjStruct) {
    if (!setAllObjWebObjStruct) {
        return;
    }
    free((char*)setAllObjWebObjStruct->webBasePath);
    free((char*)setAllObjWebObjStruct->webCertFile);
    free((char*)setAllObjWebObjStruct->webDomain);
    free((char*)setAllObjWebObjStruct->webKeyFile);
    free((char*)setAllObjWebObjStruct->webListen);
    free(setAllObjWebObjStruct);
}

void jsonSettingAllTgObjectStructDelete(struct jsonSettingAllTgObjectStruct* setAllObjTgObjStruct) {
    if (!setAllObjTgObjStruct) {
        return;
    }
    free((char*)setAllObjTgObjStruct->tgBotAPIServer);
    free((char*)setAllObjTgObjStruct->tgBotChatId);
    free((char*)setAllObjTgObjStruct->tgBotProxy);
    free((char*)setAllObjTgObjStruct->tgBotToken);
    free((char*)setAllObjTgObjStruct->tgEnabledEvents);
    free((char*)setAllObjTgObjStruct->tgLang);
    free((char*)setAllObjTgObjStruct->tgRunTime);
    free(setAllObjTgObjStruct);
}

void jsonSettingAllSmtpObjectStructDelete(struct jsonSettingAllSmtpObjectStruct* setAllObjSmtpObjStruct) {
    if (!setAllObjSmtpObjStruct) {
        return;
    }
    free((char*)setAllObjSmtpObjStruct->smtpEncryptionType);
    free((char*)setAllObjSmtpObjStruct->smtpFrom);
    free((char*)setAllObjSmtpObjStruct->smtpFromName);
    free((char*)setAllObjSmtpObjStruct->smtpHost);
    free((char*)setAllObjSmtpObjStruct->smtpPassword);
    free((char*)setAllObjSmtpObjStruct->smtpTo);
    free((char*)setAllObjSmtpObjStruct->smtpUsername);
    free(setAllObjSmtpObjStruct);
}

void jsonSettingAllLdapObjectStructDelete(struct jsonSettingAllLdapObjectStruct* setAllObjLdapObjStruct) {
    if (!setAllObjLdapObjStruct) {
        return;
    }
    free((char*)setAllObjLdapObjStruct->ldapBaseDN);
    free((char*)setAllObjLdapObjStruct->ldapBindDN);
    free((char*)setAllObjLdapObjStruct->ldapFlagField);
    free((char*)setAllObjLdapObjStruct->ldapHost);
    free((char*)setAllObjLdapObjStruct->ldapInboundTags);
    free((char*)setAllObjLdapObjStruct->ldapPassword);
    free((char*)setAllObjLdapObjStruct->ldapSyncCron);
    free((char*)setAllObjLdapObjStruct->ldapTruthyValues);
    free((char*)setAllObjLdapObjStruct->ldapUserAttr);
    free((char*)setAllObjLdapObjStruct->ldapUserFilter);
    free((char*)setAllObjLdapObjStruct->ldapVlessField);
    free(setAllObjLdapObjStruct);
}

void jsonSettingAllSubObjectStructDelete(struct jsonSettingAllSubObjectStruct* setAllObjSubObjStruct) {
    if (!setAllObjSubObjStruct) {
        return;
    }
    free((char*)setAllObjSubObjStruct->subAnnounce);
    free((char*)setAllObjSubObjStruct->subCertFile);
    free((char*)setAllObjSubObjStruct->subClashPath);
    free((char*)setAllObjSubObjStruct->subClashRules);
    free((char*)setAllObjSubObjStruct->subClashURI);
    free((char*)setAllObjSubObjStruct->subClashUserAgentRegex);
    free((char*)setAllObjSubObjStruct->subDomain);
    free((char*)setAllObjSubObjStruct->subIncyRoutingRules);
    free((char*)setAllObjSubObjStruct->subJsonFinalMask);
    free((char*)setAllObjSubObjStruct->subJsonMux);
    free((char*)setAllObjSubObjStruct->subJsonPath);
    free((char*)setAllObjSubObjStruct->subJsonRules);
    free((char*)setAllObjSubObjStruct->subJsonURI);
    free((char*)setAllObjSubObjStruct->subJsonUserAgentRegex);
    free((char*)setAllObjSubObjStruct->subKeyFile);
    free((char*)setAllObjSubObjStruct->subListen);
    free((char*)setAllObjSubObjStruct->subPath);
    free((char*)setAllObjSubObjStruct->subProfileUrl);
    free((char*)setAllObjSubObjStruct->subRoutingRules);
    free((char*)setAllObjSubObjStruct->subSupportUrl);
    free((char*)setAllObjSubObjStruct->subThemeDir);
    free((char*)setAllObjSubObjStruct->subTitle);
    free((char*)setAllObjSubObjStruct->subURI);
    free(setAllObjSubObjStruct);
}

void jsonSettingAllHasFlagsObjectStructDelete(struct jsonSettingAllHasFlagsObjectStruct* setAllObjHasFlagsObjStruct) {
    if (!setAllObjHasFlagsObjStruct) {
        return;
    }
    free(setAllObjHasFlagsObjStruct);
}

void jsonSettingAllGeneralObjectStructDelete(struct jsonSettingAllGeneralObjectStruct* setAllObjGeneralObjStruct) {
    if (!setAllObjGeneralObjStruct) {
        return;
    }
    free((char*)setAllObjGeneralObjStruct->datepicker);
    free((char*)setAllObjGeneralObjStruct->externalTrafficInformURI);
    free((char*)setAllObjGeneralObjStruct->panelOutbound);
    free((char*)setAllObjGeneralObjStruct->remarkTemplate);
    free((char*)setAllObjGeneralObjStruct->timeLocation);
    free((char*)setAllObjGeneralObjStruct->trustedProxyCIDRs);
    free((char*)setAllObjGeneralObjStruct->twoFactorToken);
    free(setAllObjGeneralObjStruct);
}

void jsonSettingAllObjectStructDelete(struct jsonSettingAllObjectStruct* setAllObjStruct) {
    if (!setAllObjStruct) {
        return;
    }
    if (setAllObjStruct->setAllObjWebObjStruct) {
        jsonSettingAllWebObjectStructDelete(setAllObjStruct->setAllObjWebObjStruct);
        setAllObjStruct->setAllObjWebObjStruct = NULL;
    }
    if (setAllObjStruct->setAllObjTgObjStruct) {
        jsonSettingAllTgObjectStructDelete(setAllObjStruct->setAllObjTgObjStruct);
        setAllObjStruct->setAllObjTgObjStruct = NULL;
    }
    if (setAllObjStruct->setAllObjSmtpObjStruct) {
        jsonSettingAllSmtpObjectStructDelete(setAllObjStruct->setAllObjSmtpObjStruct);
        setAllObjStruct->setAllObjSmtpObjStruct = NULL;
    }
    if (setAllObjStruct->setAllObjLdapObjStruct) {
        jsonSettingAllLdapObjectStructDelete(setAllObjStruct->setAllObjLdapObjStruct);
        setAllObjStruct->setAllObjLdapObjStruct = NULL;
    }
    if (setAllObjStruct->setAllObjSubObjStruct) {
        jsonSettingAllSubObjectStructDelete(setAllObjStruct->setAllObjSubObjStruct);
        setAllObjStruct->setAllObjSubObjStruct = NULL;
    }
    if (setAllObjStruct->setAllObjHasFlagsObjStruct) {
        jsonSettingAllHasFlagsObjectStructDelete(setAllObjStruct->setAllObjHasFlagsObjStruct);
        setAllObjStruct->setAllObjHasFlagsObjStruct = NULL;
    }
    if (setAllObjStruct->setAllObjGeneralObjStruct) {
        jsonSettingAllGeneralObjectStructDelete(setAllObjStruct->setAllObjGeneralObjStruct);
        setAllObjStruct->setAllObjGeneralObjStruct = NULL;
    }
    free(setAllObjStruct);
}

void jsonSettingAllResponseStructDelete(struct jsonSettingAllResponseStruct* settingAllRStruct) {
    if (!settingAllRStruct) {
        return;
    }
    free((char*)settingAllRStruct->msg);
    if (settingAllRStruct->setAllObjStruct) {
        jsonSettingAllObjectStructDelete(settingAllRStruct->setAllObjStruct);
        settingAllRStruct->setAllObjStruct = NULL;
    }
    free(settingAllRStruct);
}


void jsonSettingDefaultSettingsObjectStructDelete(struct jsonSettingDefaultSettingsObjectStruct* defSettingsObjStruct) {
    if (!defSettingsObjStruct) {
        return;
    }
    free((char*)defSettingsObjStruct->datepicker);
    free((char*)defSettingsObjStruct->defaultCert);
    free((char*)defSettingsObjStruct->defaultKey);
    free((char*)defSettingsObjStruct->subClashURI);
    free((char*)defSettingsObjStruct->subDomain);
    free((char*)defSettingsObjStruct->subJsonURI);
    free((char*)defSettingsObjStruct->subThemeDir);
    free((char*)defSettingsObjStruct->subTitle);
    free((char*)defSettingsObjStruct->subURI);
    free((char*)defSettingsObjStruct->webDomain);
    free(defSettingsObjStruct);
}

void jsonSettingDefaultSettingsResponseStructDelete(struct jsonSettingDefaultSettingsResponseStruct* settingDefaultSettingsRStruct) {
    if (!settingDefaultSettingsRStruct) {
        return;
    }
    free((char*)settingDefaultSettingsRStruct->msg);
    if (settingDefaultSettingsRStruct->defSettingsObjStruct) {
        jsonSettingDefaultSettingsObjectStructDelete(settingDefaultSettingsRStruct->defSettingsObjStruct);
        settingDefaultSettingsRStruct->defSettingsObjStruct = NULL;
    }
    free(settingDefaultSettingsRStruct);
}

void jsonSettingFactoryDefaultsObjectStructDelete(struct jsonSettingFactoryDefaultsObjectStruct* factoryDefaultsObjStruct) {
    if (!factoryDefaultsObjStruct) {
        return;
    }
    free((char*)factoryDefaultsObjStruct->datepicker);
    free((char*)factoryDefaultsObjStruct->expireDiff);
    free((char*)factoryDefaultsObjStruct->externalTrafficInformEnable);
    free((char*)factoryDefaultsObjStruct->externalTrafficInformURI);
    free((char*)factoryDefaultsObjStruct->ldapAutoCreate);
    free((char*)factoryDefaultsObjStruct->ldapAutoDelete);
    free((char*)factoryDefaultsObjStruct->ldapBaseDN);
    free((char*)factoryDefaultsObjStruct->ldapBindDN);
    free((char*)factoryDefaultsObjStruct->ldapDefaultExpiryDays);
    free((char*)factoryDefaultsObjStruct->ldapDefaultLimitIP);
    free((char*)factoryDefaultsObjStruct->ldapDefaultTotalGB);
    free((char*)factoryDefaultsObjStruct->ldapEnable);
    free((char*)factoryDefaultsObjStruct->ldapFlagField);
    free((char*)factoryDefaultsObjStruct->ldapHost);
    free((char*)factoryDefaultsObjStruct->ldapInboundTags);
    free((char*)factoryDefaultsObjStruct->ldapInsecureSkipVerify);
    free((char*)factoryDefaultsObjStruct->ldapInvertFlag);
    free((char*)factoryDefaultsObjStruct->ldapPort);
    free((char*)factoryDefaultsObjStruct->ldapSyncCron);
    free((char*)factoryDefaultsObjStruct->ldapTruthyValues);
    free((char*)factoryDefaultsObjStruct->ldapUseTLS);
    free((char*)factoryDefaultsObjStruct->ldapUserAttr);
    free((char*)factoryDefaultsObjStruct->ldapUserFilter);
    free((char*)factoryDefaultsObjStruct->ldapVlessField);
    free((char*)factoryDefaultsObjStruct->outboundDownThreshold);
    free((char*)factoryDefaultsObjStruct->pageSize);
    free((char*)factoryDefaultsObjStruct->panelOutbound);
    free((char*)factoryDefaultsObjStruct->remarkTemplate);
    free((char*)factoryDefaultsObjStruct->restartXrayOnClientDisable);
    free((char*)factoryDefaultsObjStruct->sessionMaxAge);
    free((char*)factoryDefaultsObjStruct->smtpCpu);
    free((char*)factoryDefaultsObjStruct->smtpEnable);
    free((char*)factoryDefaultsObjStruct->smtpEnabledEvents);
    free((char*)factoryDefaultsObjStruct->smtpEncryptionType);
    free((char*)factoryDefaultsObjStruct->smtpFrom);
    free((char*)factoryDefaultsObjStruct->smtpFromName);
    free((char*)factoryDefaultsObjStruct->smtpHost);
    free((char*)factoryDefaultsObjStruct->smtpMemory);
    free((char*)factoryDefaultsObjStruct->smtpPort);
    free((char*)factoryDefaultsObjStruct->smtpTo);
    free((char*)factoryDefaultsObjStruct->smtpUsername);
    free((char*)factoryDefaultsObjStruct->subAnnounce);
    free((char*)factoryDefaultsObjStruct->subCertFile);
    free((char*)factoryDefaultsObjStruct->subClashAutoDetect);
    free((char*)factoryDefaultsObjStruct->subClashEnable);
    free((char*)factoryDefaultsObjStruct->subClashEnableRouting);
    free((char*)factoryDefaultsObjStruct->subClashPath);
    free((char*)factoryDefaultsObjStruct->subClashRules);
    free((char*)factoryDefaultsObjStruct->subClashURI);
    free((char*)factoryDefaultsObjStruct->subClashUserAgentRegex);
    free((char*)factoryDefaultsObjStruct->subDomain);
    free((char*)factoryDefaultsObjStruct->subEnable);
    free((char*)factoryDefaultsObjStruct->subEnableRouting);
    free((char*)factoryDefaultsObjStruct->subEncrypt);
    free((char*)factoryDefaultsObjStruct->subHideSettings);
    free((char*)factoryDefaultsObjStruct->subIncyEnableRouting);
    free((char*)factoryDefaultsObjStruct->subIncyRoutingRules);
    free((char*)factoryDefaultsObjStruct->subJsonAlwaysArray);
    free((char*)factoryDefaultsObjStruct->subJsonAutoDetect);
    free((char*)factoryDefaultsObjStruct->subJsonEnable);
    free((char*)factoryDefaultsObjStruct->subJsonFinalMask);
    free((char*)factoryDefaultsObjStruct->subJsonMux);
    free((char*)factoryDefaultsObjStruct->subJsonPath);
    free((char*)factoryDefaultsObjStruct->subJsonRules);
    free((char*)factoryDefaultsObjStruct->subJsonURI);
    free((char*)factoryDefaultsObjStruct->subJsonUserAgentRegex);
    free((char*)factoryDefaultsObjStruct->subKeyFile);
    free((char*)factoryDefaultsObjStruct->subListen);
    free((char*)factoryDefaultsObjStruct->subPath);
    free((char*)factoryDefaultsObjStruct->subPort);
    free((char*)factoryDefaultsObjStruct->subProfileUrl);
    free((char*)factoryDefaultsObjStruct->subRoutingRules);
    free((char*)factoryDefaultsObjStruct->subShowIdentityOnAllLinks);
    free((char*)factoryDefaultsObjStruct->subSupportUrl);
    free((char*)factoryDefaultsObjStruct->subThemeDir);
    free((char*)factoryDefaultsObjStruct->subTitle);
    free((char*)factoryDefaultsObjStruct->subURI);
    free((char*)factoryDefaultsObjStruct->subUpdates);
    free((char*)factoryDefaultsObjStruct->tgBotAPIServer);
    free((char*)factoryDefaultsObjStruct->tgBotBackup);
    free((char*)factoryDefaultsObjStruct->tgBotChatId);
    free((char*)factoryDefaultsObjStruct->tgBotEnable);
    free((char*)factoryDefaultsObjStruct->tgBotProxy);
    free((char*)factoryDefaultsObjStruct->tgCpu);
    free((char*)factoryDefaultsObjStruct->tgEnabledEvents);
    free((char*)factoryDefaultsObjStruct->tgLang);
    free((char*)factoryDefaultsObjStruct->tgMemory);
    free((char*)factoryDefaultsObjStruct->tgRunTime);
    free((char*)factoryDefaultsObjStruct->timeLocation);
    free((char*)factoryDefaultsObjStruct->trafficDiff);
    free((char*)factoryDefaultsObjStruct->trustedProxyCIDRs);
    free((char*)factoryDefaultsObjStruct->twoFactorEnable);
    free((char*)factoryDefaultsObjStruct->warpUpdateInterval);
    free((char*)factoryDefaultsObjStruct->webBasePath);
    free((char*)factoryDefaultsObjStruct->webCertFile);
    free((char*)factoryDefaultsObjStruct->webDomain);
    free((char*)factoryDefaultsObjStruct->webKeyFile);
    free((char*)factoryDefaultsObjStruct->webListen);
    free((char*)factoryDefaultsObjStruct->webPort);
    free(factoryDefaultsObjStruct);
}

void jsonSettingFactoryDefaultsResponseStructDelete(struct jsonSettingFactoryDefaultsResponseStruct* settingFactoryDefaultsRStruct) {
    if (!settingFactoryDefaultsRStruct) {
        return;
    }
    free((char*)settingFactoryDefaultsRStruct->msg);
    if (settingFactoryDefaultsRStruct->factoryDefaultsObjStruct) {
        jsonSettingFactoryDefaultsObjectStructDelete(settingFactoryDefaultsRStruct->factoryDefaultsObjStruct);
        settingFactoryDefaultsRStruct->factoryDefaultsObjStruct = NULL;
    }
    free(settingFactoryDefaultsRStruct);
}

void jsonSettingUpdatePostStructDelete(struct jsonSettingUpdatePostStruct* settingUpdatePostStruct) {
    if (!settingUpdatePostStruct) {
        return;
    }
    free(settingUpdatePostStruct);
}

void jsonSettingUpdateResponseStructDelete(struct jsonSettingUpdateResponseStruct* settingUpdateRStruct) {
    if (!settingUpdateRStruct) {
        return;
    }
    free((char*)settingUpdateRStruct->msg);
    free(settingUpdateRStruct);
}

void jsonSettingValidateRegexPostStructDelete(struct jsonSettingValidateRegexPostStruct* settingValidateRegexPostStruct) {
    if (!settingValidateRegexPostStruct) {
        return;
    }
    free((char*)settingValidateRegexPostStruct->regex);
    free(settingValidateRegexPostStruct);
}

void jsonSettingValidateRegexResponseStructDelete(struct jsonSettingValidateRegexResponseStruct* settingValidateRegexRStruct) {
    if (!settingValidateRegexRStruct) {
        return;
    }
    free((char*)settingValidateRegexRStruct->msg);
    free(settingValidateRegexRStruct);
}

void jsonSettingApiTokensObjectStructDelete(struct jsonSettingApiTokensObjectStruct* objArrays, size_t arraySize) {
    if (!objArrays) {
        return;
    }
    for (size_t i = 0; i < arraySize; i++) {
        free((char*)objArrays[i].name);
    }
    free(objArrays);
}

void jsonSettingApiTokensListPostStructDelete(struct jsonSettingApiTokensListPostStruct* settingApiTokensListPostStruct) {
    if (!settingApiTokensListPostStruct) {
        return;
    }
    free(settingApiTokensListPostStruct);
}

void jsonSettingApiTokenNewPostStructDelete(struct jsonSettingApiTokenNewPostStruct* settingApiTokenNewPostStruct) {
    if (!settingApiTokenNewPostStruct) {
        return;
    }
    free((char*)settingApiTokenNewPostStruct->name);
    free(settingApiTokenNewPostStruct);
}

void jsonSettingApiTokenNewResponseStructDelete(struct jsonSettingApiTokenNewResponseStruct* settingApiTokenNewRStruct) {
    if (!settingApiTokenNewRStruct) {
        return;
    }
    free((char*)settingApiTokenNewRStruct->msg);
    free(settingApiTokenNewRStruct);
}

void jsonSettingApiTokenDeletePostStructDelete(struct jsonSettingApiTokenDeletePostStruct* settingApiTokenDeletePostStruct) {
    if (!settingApiTokenDeletePostStruct) {
        return;
    }
    free(settingApiTokenDeletePostStruct);
}

void jsonSettingApiTokenDeleteResponseStructDelete(struct jsonSettingApiTokenDeleteResponseStruct* settingApiTokenDeleteRStruct) {
    if (!settingApiTokenDeleteRStruct) {
        return;
    }
    free((char*)settingApiTokenDeleteRStruct->msg);
    free(settingApiTokenDeleteRStruct);
}

void jsonSettingApiTokenSetDBPostStructDelete(struct jsonSettingApiTokenSetDBPostStruct* settingApiTokenSetDBPostStruct) {
    if (!settingApiTokenSetDBPostStruct) {
        return;
    }
    free((char*)settingApiTokenSetDBPostStruct->name);
    free(settingApiTokenSetDBPostStruct);
}

void jsonSettingApiTokenSetDBResponseStructDelete(struct jsonSettingApiTokenSetDBResponseStruct* settingApiTokenSetDBRStruct) {
    if (!settingApiTokenSetDBRStruct) {
        return;
    }
    free((char*)settingApiTokenSetDBRStruct->msg);
    free(settingApiTokenSetDBRStruct);
}

void jsonSettingUpdateUserPostStructDelete(struct jsonSettingUpdateUserPostStruct* settingUpdateUserPostStruct) {
    if (!settingUpdateUserPostStruct) {
        return;
    }
    free((char*)settingUpdateUserPostStruct->oldUsername);
    free((char*)settingUpdateUserPostStruct->oldPassword);
    free((char*)settingUpdateUserPostStruct->newUsername);
    free((char*)settingUpdateUserPostStruct->newPassword);
    free(settingUpdateUserPostStruct);
}

void jsonSettingUpdateUserResponseStructDelete(struct jsonSettingUpdateUserResponseStruct* settingUpdateUserRStruct) {
    if (!settingUpdateUserRStruct) {
        return;
    }
    free((char*)settingUpdateUserRStruct->msg);
    free(settingUpdateUserRStruct);
}

void jsonSettingRestartPanelResponseStructDelete(struct jsonSettingRestartPanelResponseStruct* settingRestartPanelRStruct) {
    if (!settingRestartPanelRStruct) {
        return;
    }
    free((char*)settingRestartPanelRStruct->msg);
    free(settingRestartPanelRStruct);
}

void jsonSettingTestSmtpResponseStructDelete(struct jsonSettingTestSmtpResponseStruct* settingTestSmtpRStruct) {
    if (!settingTestSmtpRStruct) {
        return;
    }
    free((char*)settingTestSmtpRStruct->stage);
    free((char*)settingTestSmtpRStruct->msg);
    free(settingTestSmtpRStruct);
}

void jsonSettingTestTgBotResponseStructDelete(struct jsonSettingTestTgBotResponseStruct* settingTestTgBotRStruct) {
    if (!settingTestTgBotRStruct) {
        return;
    }
    free((char*)settingTestTgBotRStruct->msg);
    free(settingTestTgBotRStruct);
}

void jsonSettingGetDefaultJsonConfigResponseStructDelete(struct jsonSettingGetDefaultJsonConfigResponseStruct* settingGetDefaultJsonConfigRStruct) {
    if (!settingGetDefaultJsonConfigRStruct) {
        return;
    }
    free((char*)settingGetDefaultJsonConfigRStruct->msg);
    free(settingGetDefaultJsonConfigRStruct);
}


static int jsonSettingAllWebObjectStructParse(cJSON* obj, struct jsonSettingAllWebObjectStruct* webStruct) {
    if (!obj) return 0;
    jsonCopyStringItem(obj, "webBasePath", &webStruct->webBasePath);
    jsonCopyStringItem(obj, "webCertFile", &webStruct->webCertFile);
    jsonCopyStringItem(obj, "webDomain", &webStruct->webDomain);
    jsonCopyStringItem(obj, "webKeyFile", &webStruct->webKeyFile);
    jsonCopyStringItem(obj, "webListen", &webStruct->webListen);
    jsonCopyNumberItem(obj, "webPort", &webStruct->webPort);
    return 1;
}

static int jsonSettingAllTgObjectStructParse(cJSON* obj, struct jsonSettingAllTgObjectStruct* tgStruct) {
    if (!obj) return 0;
    jsonCopyStringItem(obj, "tgBotAPIServer", &tgStruct->tgBotAPIServer);
    jsonCopyBoolItem(obj, "tgBotBackup", &tgStruct->tgBotBackup);
    jsonCopyStringItem(obj, "tgBotChatId", &tgStruct->tgBotChatId);
    jsonCopyBoolItem(obj, "tgBotEnable", &tgStruct->tgBotEnable);
    jsonCopyStringItem(obj, "tgBotProxy", &tgStruct->tgBotProxy);
    jsonCopyStringItem(obj, "tgBotToken", &tgStruct->tgBotToken);
    jsonCopyNumberItem(obj, "tgCpu", &tgStruct->tgCpu);
    jsonCopyStringItem(obj, "tgEnabledEvents", &tgStruct->tgEnabledEvents);
    jsonCopyStringItem(obj, "tgLang", &tgStruct->tgLang);
    jsonCopyNumberItem(obj, "tgMemory", &tgStruct->tgMemory);
    jsonCopyStringItem(obj, "tgRunTime", &tgStruct->tgRunTime);
    return 1;
}

static int jsonSettingAllSmtpObjectStructParse(cJSON* obj, struct jsonSettingAllSmtpObjectStruct* smtpStruct) {
    if (!obj) return 0;
    jsonCopyNumberItem(obj, "smtpCpu", &smtpStruct->smtpCpu);
    jsonCopyBoolItem(obj, "smtpEnable", &smtpStruct->smtpEnable);
    jsonCopyStringItem(obj, "smtpEnabledEvents", &smtpStruct->smtpEnabledEvents);
    jsonCopyStringItem(obj, "smtpEncryptionType", &smtpStruct->smtpEncryptionType);
    jsonCopyStringItem(obj, "smtpFrom", &smtpStruct->smtpFrom);
    jsonCopyStringItem(obj, "smtpFromName", &smtpStruct->smtpFromName);
    jsonCopyStringItem(obj, "smtpHost", &smtpStruct->smtpHost);
    jsonCopyNumberItem(obj, "smtpMemory", &smtpStruct->smtpMemory);
    jsonCopyStringItem(obj, "smtpPassword", &smtpStruct->smtpPassword);
    jsonCopyNumberItem(obj, "smtpPort", &smtpStruct->smtpPort);
    jsonCopyStringItem(obj, "smtpTo", &smtpStruct->smtpTo);
    jsonCopyStringItem(obj, "smtpUsername", &smtpStruct->smtpUsername);
    return 1;
}

static int jsonSettingAllLdapObjectStructParse(cJSON* obj, struct jsonSettingAllLdapObjectStruct* ldapStruct) {
    if (!obj) return 0;
    jsonCopyBoolItem(obj, "ldapAutoCreate", &ldapStruct->ldapAutoCreate);
    jsonCopyBoolItem(obj, "ldapAutoDelete", &ldapStruct->ldapAutoDelete);
    jsonCopyStringItem(obj, "ldapBaseDN", &ldapStruct->ldapBaseDN);
    jsonCopyStringItem(obj, "ldapBindDN", &ldapStruct->ldapBindDN);
    jsonCopyNumberItem(obj, "ldapDefaultExpiryDays", &ldapStruct->ldapDefaultExpiryDays);
    jsonCopyNumberItem(obj, "ldapDefaultLimitIP", &ldapStruct->ldapDefaultLimitIP);
    jsonCopyNumberItem(obj, "ldapDefaultTotalGB", &ldapStruct->ldapDefaultTotalGB);
    jsonCopyBoolItem(obj, "ldapEnable", &ldapStruct->ldapEnable);
    jsonCopyStringItem(obj, "ldapFlagField", &ldapStruct->ldapFlagField);
    jsonCopyStringItem(obj, "ldapHost", &ldapStruct->ldapHost);
    jsonCopyStringItem(obj, "ldapInboundTags", &ldapStruct->ldapInboundTags);
    jsonCopyBoolItem(obj, "ldapInsecureSkipVerify", &ldapStruct->ldapInsecureSkipVerify);
    jsonCopyBoolItem(obj, "ldapInvertFlag", &ldapStruct->ldapInvertFlag);
    jsonCopyStringItem(obj, "ldapPassword", &ldapStruct->ldapPassword);
    jsonCopyNumberItem(obj, "ldapPort", &ldapStruct->ldapPort);
    jsonCopyStringItem(obj, "ldapSyncCron", &ldapStruct->ldapSyncCron);
    jsonCopyStringItem(obj, "ldapTruthyValues", &ldapStruct->ldapTruthyValues);
    jsonCopyBoolItem(obj, "ldapUseTLS", &ldapStruct->ldapUseTLS);
    jsonCopyStringItem(obj, "ldapUserAttr", &ldapStruct->ldapUserAttr);
    jsonCopyStringItem(obj, "ldapUserFilter", &ldapStruct->ldapUserFilter);
    jsonCopyStringItem(obj, "ldapVlessField", &ldapStruct->ldapVlessField);
    return 1;
}

static int jsonSettingAllSubObjectStructParse(cJSON* obj, struct jsonSettingAllSubObjectStruct* subStruct) {
    if (!obj) return 0;
    jsonCopyStringItem(obj, "subAnnounce", &subStruct->subAnnounce);
    jsonCopyStringItem(obj, "subCertFile", &subStruct->subCertFile);
    jsonCopyBoolItem(obj, "subClashAutoDetect", &subStruct->subClashAutoDetect);
    jsonCopyBoolItem(obj, "subClashEnable", &subStruct->subClashEnable);
    jsonCopyBoolItem(obj, "subClashEnableRouting", &subStruct->subClashEnableRouting);
    jsonCopyStringItem(obj, "subClashPath", &subStruct->subClashPath);
    jsonCopyStringItem(obj, "subClashRules", &subStruct->subClashRules);
    jsonCopyStringItem(obj, "subClashURI", &subStruct->subClashURI);
    jsonCopyStringItem(obj, "subClashUserAgentRegex", &subStruct->subClashUserAgentRegex);
    jsonCopyStringItem(obj, "subDomain", &subStruct->subDomain);
    jsonCopyBoolItem(obj, "subEnable", &subStruct->subEnable);
    jsonCopyBoolItem(obj, "subEnableRouting", &subStruct->subEnableRouting);
    jsonCopyBoolItem(obj, "subEncrypt", &subStruct->subEncrypt);
    jsonCopyBoolItem(obj, "subHideSettings", &subStruct->subHideSettings);
    jsonCopyBoolItem(obj, "subIncyEnableRouting", &subStruct->subIncyEnableRouting);
    jsonCopyStringItem(obj, "subIncyRoutingRules", &subStruct->subIncyRoutingRules);
    jsonCopyBoolItem(obj, "subJsonAlwaysArray", &subStruct->subJsonAlwaysArray);
    jsonCopyBoolItem(obj, "subJsonAutoDetect", &subStruct->subJsonAutoDetect);
    jsonCopyBoolItem(obj, "subJsonEnable", &subStruct->subJsonEnable);
    jsonCopyStringItem(obj, "subJsonFinalMask", &subStruct->subJsonFinalMask);
    jsonCopyStringItem(obj, "subJsonMux", &subStruct->subJsonMux);
    jsonCopyStringItem(obj, "subJsonPath", &subStruct->subJsonPath);
    jsonCopyStringItem(obj, "subJsonRules", &subStruct->subJsonRules);
    jsonCopyStringItem(obj, "subJsonURI", &subStruct->subJsonURI);
    jsonCopyStringItem(obj, "subJsonUserAgentRegex", &subStruct->subJsonUserAgentRegex);
    jsonCopyStringItem(obj, "subKeyFile", &subStruct->subKeyFile);
    jsonCopyStringItem(obj, "subListen", &subStruct->subListen);
    jsonCopyStringItem(obj, "subPath", &subStruct->subPath);
    jsonCopyNumberItem(obj, "subPort", &subStruct->subPort);
    jsonCopyStringItem(obj, "subProfileUrl", &subStruct->subProfileUrl);
    jsonCopyStringItem(obj, "subRoutingRules", &subStruct->subRoutingRules);
    jsonCopyBoolItem(obj, "subShowIdentityOnAllLinks", &subStruct->subShowIdentityOnAllLinks);
    jsonCopyStringItem(obj, "subSupportUrl", &subStruct->subSupportUrl);
    jsonCopyStringItem(obj, "subThemeDir", &subStruct->subThemeDir);
    jsonCopyStringItem(obj, "subTitle", &subStruct->subTitle);
    jsonCopyStringItem(obj, "subURI", &subStruct->subURI);
    jsonCopyNumberItem(obj, "subUpdates", &subStruct->subUpdates);
    return 1;
}

static int jsonSettingAllHasFlagsObjectStructParse(cJSON* obj, struct jsonSettingAllHasFlagsObjectStruct* flagsStruct) {
    if (!obj) return 0;
    jsonCopyBoolItem(obj, "hasApiToken", &flagsStruct->hasApiToken);
    jsonCopyBoolItem(obj, "hasLdapPassword", &flagsStruct->hasLdapPassword);
    jsonCopyBoolItem(obj, "hasNordSecret", &flagsStruct->hasNordSecret);
    jsonCopyBoolItem(obj, "hasSmtpPassword", &flagsStruct->hasSmtpPassword);
    jsonCopyBoolItem(obj, "hasTgBotToken", &flagsStruct->hasTgBotToken);
    jsonCopyBoolItem(obj, "hasTwoFactorToken", &flagsStruct->hasTwoFactorToken);
    jsonCopyBoolItem(obj, "hasWarpSecret", &flagsStruct->hasWarpSecret);
    return 1;
}

static int jsonSettingAllGeneralObjectStructParse(cJSON* obj, struct jsonSettingAllGeneralObjectStruct* generalStruct) {
    if (!obj) return 0;
    jsonCopyStringItem(obj, "datepicker", &generalStruct->datepicker);
    jsonCopyNumberItem(obj, "expireDiff", &generalStruct->expireDiff);
    jsonCopyBoolItem(obj, "externalTrafficInformEnable", &generalStruct->externalTrafficInformEnable);
    jsonCopyStringItem(obj, "externalTrafficInformURI", &generalStruct->externalTrafficInformURI);
    jsonCopyNumberItem(obj, "outboundDownThreshold", &generalStruct->outboundDownThreshold);
    jsonCopyNumberItem(obj, "pageSize", &generalStruct->pageSize);
    jsonCopyStringItem(obj, "panelOutbound", &generalStruct->panelOutbound);
    jsonCopyStringItem(obj, "remarkTemplate", &generalStruct->remarkTemplate);
    jsonCopyBoolItem(obj, "restartXrayOnClientDisable", &generalStruct->restartXrayOnClientDisable);
    jsonCopyNumberItem(obj, "sessionMaxAge", &generalStruct->sessionMaxAge);
    jsonCopyStringItem(obj, "timeLocation", &generalStruct->timeLocation);
    jsonCopyNumberItem(obj, "trafficDiff", &generalStruct->trafficDiff);
    jsonCopyStringItem(obj, "trustedProxyCIDRs", &generalStruct->trustedProxyCIDRs);
    jsonCopyBoolItem(obj, "twoFactorEnable", &generalStruct->twoFactorEnable);
    jsonCopyStringItem(obj, "twoFactorToken", &generalStruct->twoFactorToken);
    jsonCopyNumberItem(obj, "warpUpdateInterval", &generalStruct->warpUpdateInterval);
    return 1;
}

static int jsonSettingAllObjectStructParse(cJSON* obj, struct jsonSettingAllObjectStruct* allStruct) {
    if (!obj) return 0;
    
    if (cJSON_HasObjectItem(obj, "web") && cJSON_IsObject(cJSON_GetObjectItem(obj, "web"))) {
        allStruct->setAllObjWebObjStruct = (struct jsonSettingAllWebObjectStruct*)calloc(1, sizeof(struct jsonSettingAllWebObjectStruct));
        if (!allStruct->setAllObjWebObjStruct) return 0;
        jsonSettingAllWebObjectStructParse(cJSON_GetObjectItem(obj, "web"), allStruct->setAllObjWebObjStruct);
    }
    if (cJSON_HasObjectItem(obj, "tg") && cJSON_IsObject(cJSON_GetObjectItem(obj, "tg"))) {
        allStruct->setAllObjTgObjStruct = (struct jsonSettingAllTgObjectStruct*)calloc(1, sizeof(struct jsonSettingAllTgObjectStruct));
        if (!allStruct->setAllObjTgObjStruct) return 0;
        jsonSettingAllTgObjectStructParse(cJSON_GetObjectItem(obj, "tg"), allStruct->setAllObjTgObjStruct);
    }
    if (cJSON_HasObjectItem(obj, "smtp") && cJSON_IsObject(cJSON_GetObjectItem(obj, "smtp"))) {
        allStruct->setAllObjSmtpObjStruct = (struct jsonSettingAllSmtpObjectStruct*)calloc(1, sizeof(struct jsonSettingAllSmtpObjectStruct));
        if (!allStruct->setAllObjSmtpObjStruct) return 0;
        jsonSettingAllSmtpObjectStructParse(cJSON_GetObjectItem(obj, "smtp"), allStruct->setAllObjSmtpObjStruct);
    }
    if (cJSON_HasObjectItem(obj, "ldap") && cJSON_IsObject(cJSON_GetObjectItem(obj, "ldap"))) {
        allStruct->setAllObjLdapObjStruct = (struct jsonSettingAllLdapObjectStruct*)calloc(1, sizeof(struct jsonSettingAllLdapObjectStruct));
        if (!allStruct->setAllObjLdapObjStruct) return 0;
        jsonSettingAllLdapObjectStructParse(cJSON_GetObjectItem(obj, "ldap"), allStruct->setAllObjLdapObjStruct);
    }
    if (cJSON_HasObjectItem(obj, "sub") && cJSON_IsObject(cJSON_GetObjectItem(obj, "sub"))) {
        allStruct->setAllObjSubObjStruct = (struct jsonSettingAllSubObjectStruct*)calloc(1, sizeof(struct jsonSettingAllSubObjectStruct));
        if (!allStruct->setAllObjSubObjStruct) return 0;
        jsonSettingAllSubObjectStructParse(cJSON_GetObjectItem(obj, "sub"), allStruct->setAllObjSubObjStruct);
    }
    if (cJSON_HasObjectItem(obj, "hasFlags") && cJSON_IsObject(cJSON_GetObjectItem(obj, "hasFlags"))) {
        allStruct->setAllObjHasFlagsObjStruct = (struct jsonSettingAllHasFlagsObjectStruct*)calloc(1, sizeof(struct jsonSettingAllHasFlagsObjectStruct));
        if (!allStruct->setAllObjHasFlagsObjStruct) return 0;
        jsonSettingAllHasFlagsObjectStructParse(cJSON_GetObjectItem(obj, "hasFlags"), allStruct->setAllObjHasFlagsObjStruct);
    }
    if (cJSON_HasObjectItem(obj, "general") && cJSON_IsObject(cJSON_GetObjectItem(obj, "general"))) {
        allStruct->setAllObjGeneralObjStruct = (struct jsonSettingAllGeneralObjectStruct*)calloc(1, sizeof(struct jsonSettingAllGeneralObjectStruct));
        if (!allStruct->setAllObjGeneralObjStruct) return 0;
        jsonSettingAllGeneralObjectStructParse(cJSON_GetObjectItem(obj, "general"), allStruct->setAllObjGeneralObjStruct);
    }
    return 1;
}

struct jsonSettingAllResponseStruct* jsonSettingAllResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsObject(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* obj = cJSON_GetObjectItem(jsonParser, "obj");

        struct jsonSettingAllObjectStruct* setAllObjStruct = (struct jsonSettingAllObjectStruct*)calloc(1, sizeof(struct jsonSettingAllObjectStruct));
        if (!setAllObjStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "setAllObjStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        if (!jsonSettingAllObjectStructParse(obj, setAllObjStruct)) {
            jsonSettingAllObjectStructDelete(setAllObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        struct jsonSettingAllResponseStruct* settingAllRStruct = (struct jsonSettingAllResponseStruct*)calloc(1, sizeof(struct jsonSettingAllResponseStruct));
        if (!settingAllRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingAllRStruct is a null pointer");
            jsonSettingAllObjectStructDelete(setAllObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingAllRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &settingAllRStruct->msg)) {
            jsonSettingAllResponseStructDelete(settingAllRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingAllRStruct->setAllObjStruct = setAllObjStruct;

        cJSON_Delete(jsonParser);
        return settingAllRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonSettingAllResponseStruct* failRStruct = (struct jsonSettingAllResponseStruct*)calloc(1, sizeof(struct jsonSettingAllResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}


static int jsonSettingDefaultSettingsObjectStructParse(cJSON* obj, struct jsonSettingDefaultSettingsObjectStruct* defStruct) {
    if (!obj) return 0;
    jsonCopyBoolItem(obj, "accessLogEnable", &defStruct->accessLogEnable);
    jsonCopyStringItem(obj, "datepicker", &defStruct->datepicker);
    jsonCopyStringItem(obj, "defaultCert", &defStruct->defaultCert);
    jsonCopyStringItem(obj, "defaultKey", &defStruct->defaultKey);
    jsonCopyBoolItem(obj, "devChannelEnable", &defStruct->devChannelEnable);
    jsonCopyNumberItem(obj, "expireDiff", &defStruct->expireDiff);
    jsonCopyBoolItem(obj, "ipLimitEnable", &defStruct->ipLimitEnable);
    jsonCopyBoolItem(obj, "isDevBuild", &defStruct->isDevBuild);
    jsonCopyNumberItem(obj, "pageSize", &defStruct->pageSize);
    jsonCopyBoolItem(obj, "subClashEnable", &defStruct->subClashEnable);
    jsonCopyStringItem(obj, "subClashURI", &defStruct->subClashURI);
    jsonCopyStringItem(obj, "subDomain", &defStruct->subDomain);
    jsonCopyBoolItem(obj, "subEnable", &defStruct->subEnable);
    jsonCopyBoolItem(obj, "subJsonEnable", &defStruct->subJsonEnable);
    jsonCopyStringItem(obj, "subJsonURI", &defStruct->subJsonURI);
    jsonCopyStringItem(obj, "subThemeDir", &defStruct->subThemeDir);
    jsonCopyStringItem(obj, "subTitle", &defStruct->subTitle);
    jsonCopyStringItem(obj, "subURI", &defStruct->subURI);
    jsonCopyBoolItem(obj, "tgBotEnable", &defStruct->tgBotEnable);
    jsonCopyNumberItem(obj, "trafficDiff", &defStruct->trafficDiff);
    jsonCopyStringItem(obj, "webDomain", &defStruct->webDomain);
    return 1;
}

struct jsonSettingDefaultSettingsResponseStruct* jsonSettingDefaultSettingsResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsObject(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* obj = cJSON_GetObjectItem(jsonParser, "obj");

        struct jsonSettingDefaultSettingsObjectStruct* defSettingsObjStruct = (struct jsonSettingDefaultSettingsObjectStruct*)calloc(1, sizeof(struct jsonSettingDefaultSettingsObjectStruct));
        if (!defSettingsObjStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "defSettingsObjStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        if (!jsonSettingDefaultSettingsObjectStructParse(obj, defSettingsObjStruct)) {
            jsonSettingDefaultSettingsObjectStructDelete(defSettingsObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        struct jsonSettingDefaultSettingsResponseStruct* settingDefaultSettingsRStruct = (struct jsonSettingDefaultSettingsResponseStruct*)calloc(1, sizeof(struct jsonSettingDefaultSettingsResponseStruct));
        if (!settingDefaultSettingsRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingDefaultSettingsRStruct is a null pointer");
            jsonSettingDefaultSettingsObjectStructDelete(defSettingsObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingDefaultSettingsRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &settingDefaultSettingsRStruct->msg)) {
            jsonSettingDefaultSettingsResponseStructDelete(settingDefaultSettingsRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingDefaultSettingsRStruct->defSettingsObjStruct = defSettingsObjStruct;

        cJSON_Delete(jsonParser);
        return settingDefaultSettingsRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonSettingDefaultSettingsResponseStruct* failRStruct = (struct jsonSettingDefaultSettingsResponseStruct*)calloc(1, sizeof(struct jsonSettingDefaultSettingsResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

static int jsonSettingFactoryDefaultsObjectStructParse(cJSON* obj, struct jsonSettingFactoryDefaultsObjectStruct* factoryStruct) {
    if (!obj) return 0;
    jsonCopyStringItem(obj, "datepicker", &factoryStruct->datepicker);
    jsonCopyStringItem(obj, "expireDiff", &factoryStruct->expireDiff);
    jsonCopyStringItem(obj, "externalTrafficInformEnable", &factoryStruct->externalTrafficInformEnable);
    jsonCopyStringItem(obj, "externalTrafficInformURI", &factoryStruct->externalTrafficInformURI);
    jsonCopyStringItem(obj, "ldapAutoCreate", &factoryStruct->ldapAutoCreate);
    jsonCopyStringItem(obj, "ldapAutoDelete", &factoryStruct->ldapAutoDelete);
    jsonCopyStringItem(obj, "ldapBaseDN", &factoryStruct->ldapBaseDN);
    jsonCopyStringItem(obj, "ldapBindDN", &factoryStruct->ldapBindDN);
    jsonCopyStringItem(obj, "ldapDefaultExpiryDays", &factoryStruct->ldapDefaultExpiryDays);
    jsonCopyStringItem(obj, "ldapDefaultLimitIP", &factoryStruct->ldapDefaultLimitIP);
    jsonCopyStringItem(obj, "ldapDefaultTotalGB", &factoryStruct->ldapDefaultTotalGB);
    jsonCopyStringItem(obj, "ldapEnable", &factoryStruct->ldapEnable);
    jsonCopyStringItem(obj, "ldapFlagField", &factoryStruct->ldapFlagField);
    jsonCopyStringItem(obj, "ldapHost", &factoryStruct->ldapHost);
    jsonCopyStringItem(obj, "ldapInboundTags", &factoryStruct->ldapInboundTags);
    jsonCopyStringItem(obj, "ldapInsecureSkipVerify", &factoryStruct->ldapInsecureSkipVerify);
    jsonCopyStringItem(obj, "ldapInvertFlag", &factoryStruct->ldapInvertFlag);
    jsonCopyStringItem(obj, "ldapPort", &factoryStruct->ldapPort);
    jsonCopyStringItem(obj, "ldapSyncCron", &factoryStruct->ldapSyncCron);
    jsonCopyStringItem(obj, "ldapTruthyValues", &factoryStruct->ldapTruthyValues);
    jsonCopyStringItem(obj, "ldapUseTLS", &factoryStruct->ldapUseTLS);
    jsonCopyStringItem(obj, "ldapUserAttr", &factoryStruct->ldapUserAttr);
    jsonCopyStringItem(obj, "ldapUserFilter", &factoryStruct->ldapUserFilter);
    jsonCopyStringItem(obj, "ldapVlessField", &factoryStruct->ldapVlessField);
    jsonCopyStringItem(obj, "outboundDownThreshold", &factoryStruct->outboundDownThreshold);
    jsonCopyStringItem(obj, "pageSize", &factoryStruct->pageSize);
    jsonCopyStringItem(obj, "panelOutbound", &factoryStruct->panelOutbound);
    jsonCopyStringItem(obj, "remarkTemplate", &factoryStruct->remarkTemplate);
    jsonCopyStringItem(obj, "restartXrayOnClientDisable", &factoryStruct->restartXrayOnClientDisable);
    jsonCopyStringItem(obj, "sessionMaxAge", &factoryStruct->sessionMaxAge);
    jsonCopyStringItem(obj, "smtpCpu", &factoryStruct->smtpCpu);
    jsonCopyStringItem(obj, "smtpEnable", &factoryStruct->smtpEnable);
    jsonCopyStringItem(obj, "smtpEnabledEvents", &factoryStruct->smtpEnabledEvents);
    jsonCopyStringItem(obj, "smtpEncryptionType", &factoryStruct->smtpEncryptionType);
    jsonCopyStringItem(obj, "smtpFrom", &factoryStruct->smtpFrom);
    jsonCopyStringItem(obj, "smtpFromName", &factoryStruct->smtpFromName);
    jsonCopyStringItem(obj, "smtpHost", &factoryStruct->smtpHost);
    jsonCopyStringItem(obj, "smtpMemory", &factoryStruct->smtpMemory);
    jsonCopyStringItem(obj, "smtpPort", &factoryStruct->smtpPort);
    jsonCopyStringItem(obj, "smtpTo", &factoryStruct->smtpTo);
    jsonCopyStringItem(obj, "smtpUsername", &factoryStruct->smtpUsername);
    jsonCopyStringItem(obj, "subAnnounce", &factoryStruct->subAnnounce);
    jsonCopyStringItem(obj, "subCertFile", &factoryStruct->subCertFile);
    jsonCopyStringItem(obj, "subClashAutoDetect", &factoryStruct->subClashAutoDetect);
    jsonCopyStringItem(obj, "subClashEnable", &factoryStruct->subClashEnable);
    jsonCopyStringItem(obj, "subClashEnableRouting", &factoryStruct->subClashEnableRouting);
    jsonCopyStringItem(obj, "subClashPath", &factoryStruct->subClashPath);
    jsonCopyStringItem(obj, "subClashRules", &factoryStruct->subClashRules);
    jsonCopyStringItem(obj, "subClashURI", &factoryStruct->subClashURI);
    jsonCopyStringItem(obj, "subClashUserAgentRegex", &factoryStruct->subClashUserAgentRegex);
    jsonCopyStringItem(obj, "subDomain", &factoryStruct->subDomain);
    jsonCopyStringItem(obj, "subEnable", &factoryStruct->subEnable);
    jsonCopyStringItem(obj, "subEnableRouting", &factoryStruct->subEnableRouting);
    jsonCopyStringItem(obj, "subEncrypt", &factoryStruct->subEncrypt);
    jsonCopyStringItem(obj, "subHideSettings", &factoryStruct->subHideSettings);
    jsonCopyStringItem(obj, "subIncyEnableRouting", &factoryStruct->subIncyEnableRouting);
    jsonCopyStringItem(obj, "subIncyRoutingRules", &factoryStruct->subIncyRoutingRules);
    jsonCopyStringItem(obj, "subJsonAlwaysArray", &factoryStruct->subJsonAlwaysArray);
    jsonCopyStringItem(obj, "subJsonAutoDetect", &factoryStruct->subJsonAutoDetect);
    jsonCopyStringItem(obj, "subJsonEnable", &factoryStruct->subJsonEnable);
    jsonCopyStringItem(obj, "subJsonFinalMask", &factoryStruct->subJsonFinalMask);
    jsonCopyStringItem(obj, "subJsonMux", &factoryStruct->subJsonMux);
    jsonCopyStringItem(obj, "subJsonPath", &factoryStruct->subJsonPath);
    jsonCopyStringItem(obj, "subJsonRules", &factoryStruct->subJsonRules);
    jsonCopyStringItem(obj, "subJsonURI", &factoryStruct->subJsonURI);
    jsonCopyStringItem(obj, "subJsonUserAgentRegex", &factoryStruct->subJsonUserAgentRegex);
    jsonCopyStringItem(obj, "subKeyFile", &factoryStruct->subKeyFile);
    jsonCopyStringItem(obj, "subListen", &factoryStruct->subListen);
    jsonCopyStringItem(obj, "subPath", &factoryStruct->subPath);
    jsonCopyStringItem(obj, "subPort", &factoryStruct->subPort);
    jsonCopyStringItem(obj, "subProfileUrl", &factoryStruct->subProfileUrl);
    jsonCopyStringItem(obj, "subRoutingRules", &factoryStruct->subRoutingRules);
    jsonCopyStringItem(obj, "subShowIdentityOnAllLinks", &factoryStruct->subShowIdentityOnAllLinks);
    jsonCopyStringItem(obj, "subSupportUrl", &factoryStruct->subSupportUrl);
    jsonCopyStringItem(obj, "subThemeDir", &factoryStruct->subThemeDir);
    jsonCopyStringItem(obj, "subTitle", &factoryStruct->subTitle);
    jsonCopyStringItem(obj, "subURI", &factoryStruct->subURI);
    jsonCopyStringItem(obj, "subUpdates", &factoryStruct->subUpdates);
    jsonCopyStringItem(obj, "tgBotAPIServer", &factoryStruct->tgBotAPIServer);
    jsonCopyStringItem(obj, "tgBotBackup", &factoryStruct->tgBotBackup);
    jsonCopyStringItem(obj, "tgBotChatId", &factoryStruct->tgBotChatId);
    jsonCopyStringItem(obj, "tgBotEnable", &factoryStruct->tgBotEnable);
    jsonCopyStringItem(obj, "tgBotProxy", &factoryStruct->tgBotProxy);
    jsonCopyStringItem(obj, "tgCpu", &factoryStruct->tgCpu);
    jsonCopyStringItem(obj, "tgEnabledEvents", &factoryStruct->tgEnabledEvents);
    jsonCopyStringItem(obj, "tgLang", &factoryStruct->tgLang);
    jsonCopyStringItem(obj, "tgMemory", &factoryStruct->tgMemory);
    jsonCopyStringItem(obj, "tgRunTime", &factoryStruct->tgRunTime);
    jsonCopyStringItem(obj, "timeLocation", &factoryStruct->timeLocation);
    jsonCopyStringItem(obj, "trafficDiff", &factoryStruct->trafficDiff);
    jsonCopyStringItem(obj, "trustedProxyCIDRs", &factoryStruct->trustedProxyCIDRs);
    jsonCopyStringItem(obj, "twoFactorEnable", &factoryStruct->twoFactorEnable);
    jsonCopyStringItem(obj, "warpUpdateInterval", &factoryStruct->warpUpdateInterval);
    jsonCopyStringItem(obj, "webBasePath", &factoryStruct->webBasePath);
    jsonCopyStringItem(obj, "webCertFile", &factoryStruct->webCertFile);
    jsonCopyStringItem(obj, "webDomain", &factoryStruct->webDomain);
    jsonCopyStringItem(obj, "webKeyFile", &factoryStruct->webKeyFile);
    jsonCopyStringItem(obj, "webListen", &factoryStruct->webListen);
    jsonCopyStringItem(obj, "webPort", &factoryStruct->webPort);
    return 1;
}

struct jsonSettingFactoryDefaultsResponseStruct* jsonSettingFactoryDefaultsResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsObject(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* obj = cJSON_GetObjectItem(jsonParser, "obj");

        struct jsonSettingFactoryDefaultsObjectStruct* factoryDefaultsObjStruct = (struct jsonSettingFactoryDefaultsObjectStruct*)calloc(1, sizeof(struct jsonSettingFactoryDefaultsObjectStruct));
        if (!factoryDefaultsObjStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "factoryDefaultsObjStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        if (!jsonSettingFactoryDefaultsObjectStructParse(obj, factoryDefaultsObjStruct)) {
            jsonSettingFactoryDefaultsObjectStructDelete(factoryDefaultsObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        struct jsonSettingFactoryDefaultsResponseStruct* settingFactoryDefaultsRStruct = (struct jsonSettingFactoryDefaultsResponseStruct*)calloc(1, sizeof(struct jsonSettingFactoryDefaultsResponseStruct));
        if (!settingFactoryDefaultsRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingFactoryDefaultsRStruct is a null pointer");
            jsonSettingFactoryDefaultsObjectStructDelete(factoryDefaultsObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingFactoryDefaultsRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &settingFactoryDefaultsRStruct->msg)) {
            jsonSettingFactoryDefaultsResponseStructDelete(settingFactoryDefaultsRStruct);
            jsonSettingFactoryDefaultsObjectStructDelete(factoryDefaultsObjStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingFactoryDefaultsRStruct->factoryDefaultsObjStruct = factoryDefaultsObjStruct;

        cJSON_Delete(jsonParser);
        return settingFactoryDefaultsRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonSettingFactoryDefaultsResponseStruct* failRStruct = (struct jsonSettingFactoryDefaultsResponseStruct*)calloc(1, sizeof(struct jsonSettingFactoryDefaultsResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

const char* jsonSettingUpdatePost(struct jsonSettingUpdatePostStruct* settingUpdatePostStruct) {
    if (!settingUpdatePostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingUpdatePostStruct is a null pointer");
        return NULL;
    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");
        return NULL;
    }

    // The body mirrors the shape of jsonSettingAllObjectStruct
    // This is a placeholder - the actual implementation would serialize all the fields
    // For now, return empty object as the update structure mirrors /all
    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");
        return NULL;
    }

    return jsonString;
}

struct jsonSettingUpdateResponseStruct* jsonSettingUpdateResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonSettingUpdateResponseStruct* settingUpdateRStruct = (struct jsonSettingUpdateResponseStruct*)calloc(1, sizeof(struct jsonSettingUpdateResponseStruct));
        if (!settingUpdateRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingUpdateRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingUpdateRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &settingUpdateRStruct->msg)) {
            jsonSettingUpdateResponseStructDelete(settingUpdateRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingUpdateRStruct->obj = NULL;

        cJSON_Delete(jsonParser);
        return settingUpdateRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonSettingUpdateResponseStruct* failRStruct = (struct jsonSettingUpdateResponseStruct*)calloc(1, sizeof(struct jsonSettingUpdateResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

const char* jsonSettingValidateRegexPost(struct jsonSettingValidateRegexPostStruct* settingValidateRegexPostStruct) {
    if (!settingValidateRegexPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingValidateRegexPostStruct is a null pointer");
        return NULL;
    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");
        return NULL;
    }

    if (settingValidateRegexPostStruct->regex) {
        cJSON_AddStringToObject(json, "regex", settingValidateRegexPostStruct->regex);
    }

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");
        return NULL;
    }

    return jsonString;
}

struct jsonSettingValidateRegexResponseStruct* jsonSettingValidateRegexResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonSettingValidateRegexResponseStruct* settingValidateRegexRStruct = (struct jsonSettingValidateRegexResponseStruct*)calloc(1, sizeof(struct jsonSettingValidateRegexResponseStruct));
        if (!settingValidateRegexRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingValidateRegexRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingValidateRegexRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &settingValidateRegexRStruct->msg)) {
            jsonSettingValidateRegexResponseStructDelete(settingValidateRegexRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        cJSON_Delete(jsonParser);
        return settingValidateRegexRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonSettingValidateRegexResponseStruct* failRStruct = (struct jsonSettingValidateRegexResponseStruct*)calloc(1, sizeof(struct jsonSettingValidateRegexResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}


static int jsonSettingApiTokensObjectStructParse(cJSON* obj, struct jsonSettingApiTokensObjectStruct* tokenStruct) {
    if (!obj) return 0;
    jsonCopyNumberItem(obj, "id", &tokenStruct->id);
    jsonCopyStringItem(obj, "name", &tokenStruct->name);
    jsonCopyBoolItem(obj, "enabled", &tokenStruct->enabled);
    jsonCopyNumberItem(obj, "createdAt", &tokenStruct->createdAt);
    return 1;
}

const char* jsonSettingApiTokensListPost(struct jsonSettingApiTokensListPostStruct* settingApiTokensListPostStruct) {
    if (!settingApiTokensListPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingApiTokensListPostStruct is a null pointer");
        return NULL;
    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");
        return NULL;
    }

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");
        return NULL;
    }

    return jsonString;
}

struct jsonSettingApiTokensListPostStruct* jsonSettingApiTokensListPostStructParse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsArray(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        cJSON* objArray = cJSON_GetObjectItem(jsonParser, "obj");

        size_t arraySize = cJSON_GetArraySize(objArray);
        struct jsonSettingApiTokensObjectStruct* objArrays = NULL;
        if (arraySize) {
            objArrays = (struct jsonSettingApiTokensObjectStruct*)calloc(arraySize, sizeof(struct jsonSettingApiTokensObjectStruct));
            if (!objArrays) {
                applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "objArrays is a null pointer");
                cJSON_Delete(jsonParser);
                return NULL;
            }
            for (size_t i = 0; i < arraySize; i++) {
                cJSON* arrItem = cJSON_GetArrayItem(objArray, i);
                if (!jsonSettingApiTokensObjectStructParse(arrItem, &objArrays[i])) {
                    applicationLog(LOG_WARNING, __PRETTY_FUNCTION__, "Array element is not parsed correctly, skipping...");
                    continue;
                }
            }
        }

        struct jsonSettingApiTokensListPostStruct* settingApiTokensListPostStruct = (struct jsonSettingApiTokensListPostStruct*)calloc(1, sizeof(struct jsonSettingApiTokensListPostStruct));
        if (!settingApiTokensListPostStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingApiTokensListPostStruct is a null pointer");
            jsonSettingApiTokensObjectStructDelete(objArrays, arraySize);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingApiTokensListPostStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &settingApiTokensListPostStruct->msg)) {
            jsonSettingApiTokensListPostStructDelete(settingApiTokensListPostStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingApiTokensListPostStruct->jsonSettingApiTokensObjectStructSize = arraySize;
        settingApiTokensListPostStruct->objArrays = objArrays;

        cJSON_Delete(jsonParser);
        return settingApiTokensListPostStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}





const char* jsonSettingApiTokenNewPost(struct jsonSettingApiTokenNewPostStruct* settingApiTokenNewPostStruct) {
    if (!settingApiTokenNewPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingApiTokenNewPostStruct is a null pointer");
        return NULL;
    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");
        return NULL;
    }

    if (settingApiTokenNewPostStruct->name) {
        cJSON_AddStringToObject(json, "name", settingApiTokenNewPostStruct->name);
    }

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");
        return NULL;
    }

    return jsonString;
}

struct jsonSettingApiTokenNewResponseStruct* jsonSettingApiTokenNewResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success")) &&
        cJSON_HasObjectItem(jsonParser, "obj") &&
        cJSON_IsString(cJSON_GetObjectItem(jsonParser, "obj"))
    ) {
        struct jsonSettingApiTokenNewResponseStruct* settingApiTokenNewRStruct = (struct jsonSettingApiTokenNewResponseStruct*)calloc(1, sizeof(struct jsonSettingApiTokenNewResponseStruct));
        if (!settingApiTokenNewRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingApiTokenNewRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingApiTokenNewRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &settingApiTokenNewRStruct->msg)) {
            jsonSettingApiTokenNewResponseStructDelete(settingApiTokenNewRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        jsonCopyStringItem(jsonParser, "obj", (const char**)&settingApiTokenNewRStruct->obj);

        cJSON_Delete(jsonParser);
        return settingApiTokenNewRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonSettingApiTokenNewResponseStruct* failRStruct = (struct jsonSettingApiTokenNewResponseStruct*)calloc(1, sizeof(struct jsonSettingApiTokenNewResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

const char* jsonSettingApiTokenDeletePost(struct jsonSettingApiTokenDeletePostStruct* settingApiTokenDeletePostStruct) {
    if (!settingApiTokenDeletePostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingApiTokenDeletePostStruct is a null pointer");
        return NULL;
    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");
        return NULL;
    }

    cJSON_AddNumberToObject(json, "id", (double)settingApiTokenDeletePostStruct->id);

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");
        return NULL;
    }

    return jsonString;
}

struct jsonSettingApiTokenDeleteResponseStruct* jsonSettingApiTokenDeleteResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonSettingApiTokenDeleteResponseStruct* settingApiTokenDeleteRStruct = (struct jsonSettingApiTokenDeleteResponseStruct*)calloc(1, sizeof(struct jsonSettingApiTokenDeleteResponseStruct));
        if (!settingApiTokenDeleteRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingApiTokenDeleteRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingApiTokenDeleteRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &settingApiTokenDeleteRStruct->msg)) {
            jsonSettingApiTokenDeleteResponseStructDelete(settingApiTokenDeleteRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        cJSON_Delete(jsonParser);
        return settingApiTokenDeleteRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonSettingApiTokenDeleteResponseStruct* failRStruct = (struct jsonSettingApiTokenDeleteResponseStruct*)calloc(1, sizeof(struct jsonSettingApiTokenDeleteResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

const char* jsonSettingApiTokenSetDBPost(struct jsonSettingApiTokenSetDBPostStruct* settingApiTokenSetDBPostStruct) {
    if (!settingApiTokenSetDBPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingApiTokenSetDBPostStruct is a null pointer");
        return NULL;
    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");
        return NULL;
    }

    cJSON_AddNumberToObject(json, "id", (double)settingApiTokenSetDBPostStruct->id);
    if (settingApiTokenSetDBPostStruct->name) {
        cJSON_AddStringToObject(json, "name", settingApiTokenSetDBPostStruct->name);
    }
    cJSON_AddBoolToObject(json, "enabled", settingApiTokenSetDBPostStruct->enabled);

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");
        return NULL;
    }

    return jsonString;
}

struct jsonSettingApiTokenSetDBResponseStruct* jsonSettingApiTokenSetDBResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonSettingApiTokenSetDBResponseStruct* settingApiTokenSetDBRStruct = (struct jsonSettingApiTokenSetDBResponseStruct*)calloc(1, sizeof(struct jsonSettingApiTokenSetDBResponseStruct));
        if (!settingApiTokenSetDBRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingApiTokenSetDBRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingApiTokenSetDBRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &settingApiTokenSetDBRStruct->msg)) {
            jsonSettingApiTokenSetDBResponseStructDelete(settingApiTokenSetDBRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        cJSON_Delete(jsonParser);
        return settingApiTokenSetDBRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonSettingApiTokenSetDBResponseStruct* failRStruct = (struct jsonSettingApiTokenSetDBResponseStruct*)calloc(1, sizeof(struct jsonSettingApiTokenSetDBResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

const char* jsonSettingUpdateUserPost(struct jsonSettingUpdateUserPostStruct* settingUpdateUserPostStruct) {
    if (!settingUpdateUserPostStruct) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingUpdateUserPostStruct is a null pointer");
        return NULL;
    }

    cJSON* json = cJSON_CreateObject();
    if (!json) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to create json object");
        return NULL;
    }

    if (settingUpdateUserPostStruct->oldUsername) {
        cJSON_AddStringToObject(json, "oldUsername", settingUpdateUserPostStruct->oldUsername);
    }
    if (settingUpdateUserPostStruct->oldPassword) {
        cJSON_AddStringToObject(json, "oldPassword", settingUpdateUserPostStruct->oldPassword);
    }
    if (settingUpdateUserPostStruct->newUsername) {
        cJSON_AddStringToObject(json, "newUsername", settingUpdateUserPostStruct->newUsername);
    }
    if (settingUpdateUserPostStruct->newPassword) {
        cJSON_AddStringToObject(json, "newPassword", settingUpdateUserPostStruct->newPassword);
    }

    char* jsonString = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (!jsonString) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failed to print json");
        return NULL;
    }

    return jsonString;
}

struct jsonSettingUpdateUserResponseStruct* jsonSettingUpdateUserResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonSettingUpdateUserResponseStruct* settingUpdateUserRStruct = (struct jsonSettingUpdateUserResponseStruct*)calloc(1, sizeof(struct jsonSettingUpdateUserResponseStruct));
        if (!settingUpdateUserRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingUpdateUserRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingUpdateUserRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &settingUpdateUserRStruct->msg)) {
            jsonSettingUpdateUserResponseStructDelete(settingUpdateUserRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingUpdateUserRStruct->obj = NULL;

        cJSON_Delete(jsonParser);
        return settingUpdateUserRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonSettingUpdateUserResponseStruct* failRStruct = (struct jsonSettingUpdateUserResponseStruct*)calloc(1, sizeof(struct jsonSettingUpdateUserResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

struct jsonSettingRestartPanelResponseStruct* jsonSettingRestartPanelResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonSettingRestartPanelResponseStruct* settingRestartPanelRStruct = (struct jsonSettingRestartPanelResponseStruct*)calloc(1, sizeof(struct jsonSettingRestartPanelResponseStruct));
        if (!settingRestartPanelRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingRestartPanelRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingRestartPanelRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &settingRestartPanelRStruct->msg)) {
            jsonSettingRestartPanelResponseStructDelete(settingRestartPanelRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingRestartPanelRStruct->obj = NULL;

        cJSON_Delete(jsonParser);
        return settingRestartPanelRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonSettingRestartPanelResponseStruct* failRStruct = (struct jsonSettingRestartPanelResponseStruct*)calloc(1, sizeof(struct jsonSettingRestartPanelResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

struct jsonSettingTestSmtpResponseStruct* jsonSettingTestSmtpResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonSettingTestSmtpResponseStruct* settingTestSmtpRStruct = (struct jsonSettingTestSmtpResponseStruct*)calloc(1, sizeof(struct jsonSettingTestSmtpResponseStruct));
        if (!settingTestSmtpRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingTestSmtpRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingTestSmtpRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &settingTestSmtpRStruct->msg)) {
            jsonSettingTestSmtpResponseStructDelete(settingTestSmtpRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        jsonCopyStringItem(jsonParser, "stage", &settingTestSmtpRStruct->stage);

        cJSON_Delete(jsonParser);
        return settingTestSmtpRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonSettingTestSmtpResponseStruct* failRStruct = (struct jsonSettingTestSmtpResponseStruct*)calloc(1, sizeof(struct jsonSettingTestSmtpResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        failRStruct->stage = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

struct jsonSettingTestTgBotResponseStruct* jsonSettingTestTgBotResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonSettingTestTgBotResponseStruct* settingTestTgBotRStruct = (struct jsonSettingTestTgBotResponseStruct*)calloc(1, sizeof(struct jsonSettingTestTgBotResponseStruct));
        if (!settingTestTgBotRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingTestTgBotRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingTestTgBotRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &settingTestTgBotRStruct->msg)) {
            jsonSettingTestTgBotResponseStructDelete(settingTestTgBotRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        cJSON_Delete(jsonParser);
        return settingTestTgBotRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonSettingTestTgBotResponseStruct* failRStruct = (struct jsonSettingTestTgBotResponseStruct*)calloc(1, sizeof(struct jsonSettingTestTgBotResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

struct jsonSettingGetDefaultJsonConfigResponseStruct* jsonSettingGetDefaultJsonConfigResponse(const char* json) {
    DBG(LOG_INFO, "Function called");

    if (!__isJsonValid(json)) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Provided json is not valid, returning...");
        return NULL;
    }

    cJSON* jsonParser = cJSON_Parse(json);
    if (!jsonParser) {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "jsonParser is a null pointer");
        return NULL;
    }

    if (
        cJSON_HasObjectItem(jsonParser, "success") &&
        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, "success"))
    ) {
        struct jsonSettingGetDefaultJsonConfigResponseStruct* settingGetDefaultJsonConfigRStruct = (struct jsonSettingGetDefaultJsonConfigResponseStruct*)calloc(1, sizeof(struct jsonSettingGetDefaultJsonConfigResponseStruct));
        if (!settingGetDefaultJsonConfigRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "settingGetDefaultJsonConfigRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingGetDefaultJsonConfigRStruct->success = 1;

        if (!jsonCopyStringItem(jsonParser, "msg", &settingGetDefaultJsonConfigRStruct->msg)) {
            jsonSettingGetDefaultJsonConfigResponseStructDelete(settingGetDefaultJsonConfigRStruct);
            cJSON_Delete(jsonParser);
            return NULL;
        }

        settingGetDefaultJsonConfigRStruct->obj = NULL;

        cJSON_Delete(jsonParser);
        return settingGetDefaultJsonConfigRStruct;
    } else if (cJSON_HasObjectItem(jsonParser, "success") && cJSON_IsFalse(cJSON_GetObjectItem(jsonParser, "success"))) {
        struct jsonSettingGetDefaultJsonConfigResponseStruct* failRStruct = (struct jsonSettingGetDefaultJsonConfigResponseStruct*)calloc(1, sizeof(struct jsonSettingGetDefaultJsonConfigResponseStruct));
        if (!failRStruct) {
            applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "failRStruct is a null pointer");
            cJSON_Delete(jsonParser);
            return NULL;
        }
        failRStruct->success = 0;
        failRStruct->msg = jsonCopyMsg(jsonParser);
        cJSON_Delete(jsonParser);
        return failRStruct;
    } else {
        applicationLog(LOG_ERROR, __PRETTY_FUNCTION__, "Some elements are missing from the server response");
        cJSON_Delete(jsonParser);
        return NULL;
    }
}

