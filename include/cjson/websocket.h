#ifndef CJSON_TELEGRAM_XUI_BOT_WEBSOCKET_H
#define CJSON_TELEGRAM_XUI_BOT_WEBSOCKET_H

// websocket section - https://docs.sanaei.dev/docs/reference/api/websocket/

#include <stddef.h>
#include <stdint.h>


// =====================================================
// WebSocket upgrade endpoint. This section contains a
// single route, GET /ws, which performs an HTTP-to-
// WebSocket protocol upgrade. It is NOT a JSON endpoint
// and therefore this header intentionally declares no
// structs and no functions.
//
// The client must issue GET /ws with the standard
// WebSocket upgrade headers:
//   Connection: Upgrade
//   Upgrade: websocket
//   Sec-WebSocket-Key: <base64 nonce>
//   Sec-WebSocket-Version: 13
//
// Authentication is cookie-based only, using the panel
// session cookie. There is no bearer token, no
// Authorization header and no JSON credential exchange
// on this route.
//
// On success the panel replies 101 Switching Protocols
// and the connection becomes a raw WebSocket carrying
// framed messages. There is no {success, msg, obj}
// envelope to parse, no request body and no response
// body. The parsing contract used by the other sections
// does not apply here: "you must check each field on
// its own and then parse or assign a NULL to it, dont
// check them all at once" — here there are no JSON
// fields at all.
// =====================================================

// =====================================================
// GET /ws - Initiate a WebSocket connection. Requires
// the upgrade headers listed above and a valid session
// cookie. Returns 101 Switching Protocols on success;
// traffic afterwards is framed WebSocket messages, not
// JSON.
// =====================================================

#endif /* CJSON_TELEGRAM_XUI_BOT_WEBSOCKET_H */
