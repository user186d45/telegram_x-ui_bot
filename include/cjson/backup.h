#ifndef CJSON_TELEGRAM_XUI_BOT_BACKUP_H
#define CJSON_TELEGRAM_XUI_BOT_BACKUP_H

// backup section - https://docs.sanaei.dev/docs/reference/api/backup/

#include <stddef.h>
#include <stdint.h>


// =====================================================
// Backup : a single fire-and-forget endpoint which
// streams the panel database to the configured Telegram
// bot. Requires the bot credentials already present in
// panel Settings. Takes no request body and returns only
// the standard success/msg envelope.
// NOTE: you must check each field on its own and then
// parse or assign a NULL to it, dont check them all at
// once. The response carries no obj, so the parser must
// set the object to NULL rather than assuming one.
// =====================================================

// =====================================================
// Back up the panel database to the configured Telegram
// bot ( POST /panel/api/backuptotgbot ). No request
// body; response is the standard envelope.
// =====================================================

struct jsonBackupToTgBotResponseStruct {
    unsigned char               success;
    const char*                 msg;

};

void        jsonBackupToTgBotResponseStructDelete(struct jsonBackupToTgBotResponseStruct* backupToTgBotRStruct);

struct jsonBackupToTgBotResponseStruct*         jsonBackupToTgBotResponse(const char* json);

#endif /* CJSON_TELEGRAM_XUI_BOT_BACKUP_H */
