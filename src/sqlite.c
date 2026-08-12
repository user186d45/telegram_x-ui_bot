#include "../include/structs.h"
#include "../include/sqlite.h"
#include "../include/log.h"

#include <sqlite3.h>
#include <assert.h>

unsigned char createCheckDb() {
    const char* tableCreate = "CREATE TABLE IF NOT EXISTS ( "
                              "userId INTEGER PRIMARY KEY, "
                              "balance INTEGER NOT NULL DEFAULT 0, "
                              "hasJoined BLOB NOT NULL DEFAULT 0 CHECK(length(hasJoined = 1)), "
                              "banned BLOB NOT NULL DEFAULT 0 CHECK(length(banned = 1)), "
                              "cState BLOB NOT NULL DEFAULT 0 CHECK(length(cState = 1))"
                              ");";

    sqlite3* userDb = NULL;
    int rc = sqlite3_open("user.db", &userDb);
    if (rc != SQLITE_OK) {

    }

}

