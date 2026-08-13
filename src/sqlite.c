#include "../include/structs.h"
#include "../include/sqlite.h"
#include "../include/log.h"

#include <stdio.h>
#include <sqlite3.h>
#include <assert.h>

static sqlite3* userDb = NULL;

unsigned char createCheckDb() {
    DBG(INFO, "Function called");
    const char* tableCreate = "CREATE TABLE IF NOT EXISTS ( "
                              "userId INTEGER PRIMARY KEY, "
                              "balance INTEGER NOT NULL DEFAULT 0, "
                              "phoneNumber TEXT, "
                              "hasJoined BLOB NOT NULL DEFAULT 0 CHECK(length(hasJoined = 1)), "
                              "banned BLOB NOT NULL DEFAULT 0 CHECK(length(banned = 1)), "
                              "cState BLOB NOT NULL DEFAULT 0 CHECK(length(cState = 1))"
                              ");";

    int rc = sqlite3_open("user.db", &userDb);
    if (rc != SQLITE_OK) {
        sqlErrorMsg("Cannot open user database", userDb, rc);

        return 0;

    }
    DBG(INFO, "Open database success");

    char* errMsg = NULL;
    rc = sqlite3_exec(userDb, tableCreate, NULL, NULL, &errMsg);
    if (rc != SQLITE_OK) {
        sqlErrorMsg("Cannot execute tableCreate sql", userDb, rc);

        sqlite3_free(errMsg);
        sqlite3_close(userDb);

        return 0;

    }
    DBG(INFO, "Execute tableCreate sql success");

    sqlite3_free(errMsg);
    rc = sqlite3_close(userDb);
    if (rc != SQLITE_OK) {
        sqlErrorMsg("Cannot close the database", userDb, rc);

        return 0;

    }
    DBG(INFO, "Close databsae success");

    return 1;

}

unsigned char writeUserData(enum userDataRWSql uDataRWSql) {
    DBG(INFO, "Function called");

    int rc = sqlite3_open("user.db", &userDb);
    if (rc != SQLITE_OK) {
        sqlErrorMsg("Cannot open user database", userDb, rc);

        return 0;

    }
    DBG(INFO, "Open database success");

    const char* insertSql = NULL;
    switch (uDataRWSql) {
        case userDataRWSql_ALL:
        {
            const char* insertAllSql = "INSERT OR REPLACE INTO users SET (userId, balance, hasJoined, banned, cState) VALUES (?, ?, ?, ?, ?);";
            insertSql = insertAllSql;

            break;

        }

        case userDataRWSql_BALANCE:
        {
            const char* insertBalanceSql = "UPDATE users SET balance = ? WHERE userId = ?;";

            insertSql = insertBalanceSql;

            break;
        }

        case userDataRWSql_PHONE_NUMBER:
        {
            const char* insertPhoneSql = "UPDATE users SET phoneNumber = ? WHERE userId = ?;";

            insertSql = insertPhoneSql;

            break;

        }

        case userDataRWSql_JOIN_STATE:
        {
            const char* insertJoinStateSql = "UPDATE users SET hasJoined = ? WHERE userId = ?;";

            insertSql = insertJoinStateSql;

            break;

        }

        case userDataRWSql_CONVERSATION_STATE:
        {
            const char* insertCStateSql = "UPDATE users SET conversationState = ? where userId = ?;";

            insertSql = insertCStateSql;

            break;

        }

    }

    if (insertSql == NULL) {
        applicationLog(ERROR, __PRETTY_FUNCTION__, "Insert SQL is NULL");

        sqlite3_close(userDb);

        return 0;

    }

    sqlite3_stmt* stmt = NULL;
    rc = sqlite3_prepare_v2(userDb, insertSql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        sqlErrorMsg("Cannot prepare the statement", userDb, rc);
        sqlite3_close(userDb);
    }
    DBG(INFO, "Prepare statement success");

    switch (uDataRWSql) {
        case userDataRWSql_ALL:

            sqlite3_bind_int64(stmt, 1, uInfo->userId);
            sqlite3_bind_int(stmt, 2, uInfo->balance);
            sqlite3_bind_blob(stmt, 3, &uInfo->hasJoined, 1, SQLITE_STATIC);
            sqlite3_bind_blob(stmt, 4, &uInfo->banned, 1, SQLITE_STATIC);
            sqlite3_bind_blob(stmt, 5, &uInfo->cState, 1, SQLITE_STATIC);

            break;

        case userDataRWSql_BALANCE:
            sqlite3_bind_int(stmt, 1, uInfo->balance);
            sqlite3_bind_int64(stmt, 2, uInfo->userId);

            break;

        case userDataRWSql_PHONE_NUMBER:
            sqlite3_bind_text(stmt, 1, uInfo->phoneNumber, -1, SQLITE_STATIC);
            sqlite3_bind_int64(stmt, 2, uInfo->userId);

            break;

        case userDataRWSql_JOIN_STATE:
            sqlite3_bind_blob(stmt, 1, &uInfo->hasJoined, 1, SQLITE_STATIC);
            sqlite3_bind_int64(stmt, 2, uInfo->userId);

            break;

        case userDataRWSql_BANNED_STATE:
            sqlite3_bind_blob(stmt, 1, &uInfo->banned, 1, SQLITE_STATIC);
            sqlite3_bind_int64(stmt, 2, uInfo->userId);

            break;

        case userDataRWSql_CONVERSATION_STATE:
            sqlite3_bind_blob(stmt, 1, &uInfo->cState, 1, SQLITE_STATIC);
            sqlite3_bind_int64(stmt, 2, uInfo->userId);

            break;

    }

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_OK) {
        sqlErrorMsg("Statement execution failed", userDb, rc);

        sqlite3_finalize(stmt);
        sqlite3_close(userDb);

        return 0;

    }
    DBG(INFO, "Step statement success");

    sqlite3_finalize(stmt);
    rc = sqlite3_close(userDb);
    if (rc != SQLITE_OK) {
        sqlErrorMsg("Cannot close the database", userDb, rc);

        return 0;

    }
    DBG(INFO, "Close databsae success");

    return 1;

}

unsigned char readUserData(enum userDataRWSql uDataRWSql) {
    DBG(INFO, "Function called");

    int rc = sqlite3_open("user.db", &userDb);
    if (rc != SQLITE_OK) {
        sqlErrorMsg("Cannot open user database", userDb, rc);

        return 0;

    }
    DBG(INFO, "Open database success");

    const char* readSql = NULL;
    switch (uDataRWSql) {
        case userDataRWSql_ALL:
            readSql = "SELECT balance, phoneNumber, hasJoined, banned, cState FROM users WHERE userId = ?;";

            break;

        case userDataRWSql_BALANCE:
            readSql = "SELECT balance FROM users WHERE userId = ?;";

            break;

        case userDataRWSql_PHONE_NUMBER:
            readSql = "SELECT phoneNumber FROM users WHERE userId = ?;";

            break;

        case userDataRWSql_JOIN_STATE:
            readSql = "SELECT hasJoined FROM users WHERE userId = ?;";

            break;

        case userDataRWSql_BANNED_STATE:
            readSql = "SELECT banned FROM users WHERE userId = ?;";

            break;

        case userDataRWSql_CONVERSATION_STATE:
            readSql = "SELECT cState FROM users WHERE userId = ?;";

            break;

    }

    if (readSql == NULL) {
        applicationLog(ERROR, __PRETTY_FUNCTION__, "Read SQL is NULL");

        sqlite3_close(userDb);

        return 0;

    }

    sqlite3_stmt* stmt = NULL;
    rc = sqlite3_prepare_v2(userDb, readSql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        sqlErrorMsg("Cannot prepare the statement", userDb, rc);
        sqlite3_close(userDb);
    }
    DBG(INFO, "Prepare statement success");

    switch (uDataRWSql) {
        case userDataRWSql_ALL:
            while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
                // just log to the output
                DBG(INFO, "User data read: balance = %d, phoneNumber = %s, hasJoined = %d, banned = %d, cState = %d",
                    sqlite3_column_int(stmt, 0),
                    sqlite3_column_text(stmt, 1),
                    sqlite3_column_int(stmt, 2),
                    sqlite3_column_int(stmt, 3),
                    sqlite3_column_int(stmt, 4));
            }

            break;

        case userDataRWSql_BALANCE:
            sqlite3_bind_int64(stmt, 1, uInfo->userId);

            uInfo->balance = sqlite3_column_int(stmt, 0);

            break;

        case userDataRWSql_PHONE_NUMBER:
            sqlite3_bind_int64(stmt, 1, uInfo->userId);

            uInfo->phoneNumber = (const char*)sqlite3_column_text(stmt, 0);

            break;
        case userDataRWSql_JOIN_STATE:
            sqlite3_bind_int64(stmt, 1, uInfo->userId);

            uInfo->hasJoined = *(unsigned char*)sqlite3_column_blob(stmt, 0);

            break;
        case userDataRWSql_BANNED_STATE:
            sqlite3_bind_int64(stmt, 1, uInfo->userId);

            uInfo->banned = *(unsigned char*)sqlite3_column_blob(stmt, 0);

            break;

        case userDataRWSql_CONVERSATION_STATE:
            sqlite3_bind_int64(stmt, 1, uInfo->userId);

            uInfo->cState = *(unsigned char*)sqlite3_column_blob(stmt, 0);

            break;

    }

    sqlite3_finalize(stmt);
    rc = sqlite3_close(userDb);
    if (rc != SQLITE_OK) {
        sqlErrorMsg("Cannot close the database", userDb, rc);

        return 0;

    }
    DBG(INFO, "Close databsae success");

    return 1;

}

static void sqlErrorMsg(const char* msg, sqlite3* db, int rc) {
    const char* dbMessage = db ? sqlite3_errmsg(db) : "no db";

    char b[1024];
    snprintf(b, sizeof(b), "%s: rc = %i, sqlite3_errmsg = %s", msg, rc, dbMessage);
    applicationLog(ERROR, __PRETTY_FUNCTION__, (const char*)&b);

}

