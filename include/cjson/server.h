#ifndef CJSON_TELEGRAM_XUI_BOT_SERVER_H
#define CJSON_TELEGRAM_XUI_BOT_SERVER_H

// server section - https://docs.sanaei.dev/docs/reference/api/server/

#include <stddef.h>
#include <stdint.h>


// =====================================================
// Serve this API description as an OpenAPI 3 document
// ( the same file that powers the API Docs page )
// =====================================================

struct jsonOpenApiResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Real-time machine snapshot : CPU, memory, swap, disk,
// network IO, load averages, open connections, Xray
// state. Cached and refreshed every 2 seconds in the
// background
// =====================================================

struct jsonServerStatusMemObjectStruct {
    int64_t                     current;
    int64_t                     total;

};



struct jsonServerStatusSwapObjectStruct {
    int64_t                     current;
    int64_t                     total;

};



struct jsonServerStatusDiskObjectStruct {
    int64_t                     current;
    int64_t                     total;

};



struct jsonServerStatusDiskIOObjectStruct {
    int64_t                     read;
    int64_t                     write;

};



struct jsonServerStatusDiskTrafficObjectStruct {
    int64_t                     read;
    int64_t                     write;

};



struct jsonServerStatusNetIOObjectStruct {
    int64_t                     up;
    int64_t                     down;
    int64_t                     pktUp;
    int64_t                     pktDown;

};



struct jsonServerStatusNetTrafficObjectStruct {
    int64_t                     sent;
    int64_t                     recv;
    int64_t                     pktSent;
    int64_t                     pktRecv;

};



struct jsonServerStatusPublicIPObjectStruct {
    const char*                 ipv4; // e.g. "178.104.155.165"
    const char*                 ipv6; // e.g. "N/A"
};



struct jsonServerStatusAppStatsObjectStruct {
    int                         threads;
    int64_t                     mem;
    int64_t                     uptime;

};



struct jsonServerStatusXrayObjectStruct {
    const char*                 state; // e.g. "running"
    const char*                 errorMsg; // e.g. "" ( empty when running normally )
    const char*                 version; // e.g. "v25.10.31"

};



struct jsonServerStatusLoadObjectStruct {
    double*                     loads; // 3 elements : the 1m, 5m and 15m load averages

};



struct jsonServerStatusObjectStruct {
    double                      cpu;
    int64_t                     cpuCores;
    int64_t                     logicalPro;
    int64_t                     cpuSpeedMhz;
    struct jsonServerStatusMemObjectStruct* srvStatusObjMemObjStruct;
    struct jsonServerStatusSwapObjectStruct* srvStatusObjSwapObjStruct;
    struct jsonServerStatusDiskObjectStruct* srvStatusObjDiskObjStruct;
    struct jsonServerStatusDiskIOObjectStruct* srvStatusObjDiskIOObjStruct;
    struct jsonServerStatusDiskTrafficObjectStruct* srvStatusObjDiskTrafficObjStruct;
    struct jsonServerStatusNetIOObjectStruct* srvStatusObjNetIOObjStruct;
    struct jsonServerStatusNetTrafficObjectStruct* srvStatusObjNetTrafficObjStruct;
    struct jsonServerStatusXrayObjectStruct* srvStatusObjXrayObjStruct;
    const char*                 panelVersion; // e.g. "3.6.0"
    const char*                 panelGuid;
    int64_t                     uptime; // seconds
    int                         tcpCount;
    int                         udpCount;
    struct jsonServerStatusLoadObjectStruct* srvStatusObjLoadObjStruct;
    struct jsonServerStatusPublicIPObjectStruct* srvStatusObjPublicIPObjStruct;
    struct jsonServerStatusAppStatsObjectStruct* srvStatusObjAppStatsObjStruct;

};



struct jsonServerStatusResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerStatusObjectStruct* srvStatusObjStruct;

};


// =====================================================
// Reports whether per-client IP limits can be enforced
// on this host ( depends on fail2ban being installed )
// =====================================================

struct jsonServerFail2banStatusObjectStruct {
    unsigned char               enabled;
    unsigned char               installed;
    unsigned char               usable;
    unsigned char               windows;

};



struct jsonServerFail2banStatusResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerFail2banStatusObjectStruct* fail2banStatusObjStruct;

};


// =====================================================
// Legacy : aggregated CPU history response struct.
// Use /history/cpu/:bucket instead — same data with a
// uniform { t, v } shape. Real payload obj is an array
// of { cpu, t } samples
// =====================================================

struct jsonServerCpuHistoryObjectArrayStruct {
    double                      cpu;
    int64_t                     t;

};



struct jsonServerCpuHistoryResponseStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      jsonServerCpuHistoryObjectArrayStructSize;
    struct jsonServerCpuHistoryObjectArrayStruct* cpuHistoryObjArrStruct; // array

};


// =====================================================
// Aggregated time-series for one metric response struct.
// Returns an array of { t, v } samples covering the
// last ~6 hours
// =====================================================

struct jsonServerHistoryObjectArrayStruct {
    int64_t                     t;
    double                      v;

};



struct jsonServerHistoryResponseStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      jsonServerHistoryObjectArrayStructSize;
    struct jsonServerHistoryObjectArrayStruct* srvHistoryObjArrStruct; // array

};


// =====================================================
// Xray runtime metrics state response struct ( whether
// the xray config has a metrics block, which expvar
// keys are flowing, and the current snapshot values ).
// Returns an empty state when metrics are not configured
// =====================================================

struct jsonServerXrayMetricsStateResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Time-series history for one Xray runtime metric over
// the last ~6 hours response struct. Same { t, v } shape
// as /history/:metric/:bucket
// =====================================================

struct jsonServerXrayMetricsHistoryResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Latest snapshot from the Xray observatory response
// struct ( per-outbound latency, health status, and
// last-probe time ). Only populated when the Xray config
// has an observatory configured
// =====================================================

struct jsonServerXrayObservatoryResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Time-series of observatory probe results for one
// outbound tag response struct. Same { t, v } shape as
// the other history endpoints
// =====================================================

struct jsonServerXrayObservatoryHistoryResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// List Xray binary versions available for install on
// this host
// =====================================================

struct jsonServerGetXrayVersionResponseStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      objCount;
    const char**                obj; // every pointer presented is an element of the array

};


// =====================================================
// Check whether a newer 3x-ui release is available on
// GitHub
// =====================================================

struct jsonServerGetPanelUpdateInfoResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Report the outcome of the most recently launched panel
// self-update. Compare the returned runId against the
// one updatePanel returned to tell this run apart from a
// stale result
// =====================================================

struct jsonServerGetUpdateStatusObjectStruct {
    int                         exitCode;
    int64_t                     finishedAt;
    const char*                 runId;
    const char*                 state; // e.g. "success"

};



struct jsonServerGetUpdateStatusResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerGetUpdateStatusObjectStruct* getUpdateStatusObjStruct;

};


// =====================================================
// Return the assembled Xray config that is currently
// running on this host
// =====================================================

struct jsonServerGetConfigJsonResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Stream a full database backup as an attachment ( the
// SQLite .db file on SQLite panels, or a pg_dump custom
// format archive ( .dump ) on PostgreSQL panels )
// =====================================================

struct jsonServerGetDbResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Stream a cross-engine migration file as an attachment
// ( a .dump ( SQL text ) on SQLite, or a .db SQLite
// database built from the live data on PostgreSQL )
// =====================================================

struct jsonServerGetMigrationResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Generate a fresh UUID v4. Convenience helper for
// client IDs
// =====================================================

struct jsonServerGetNewUUIDObjectStruct {
    const char*                 uuid;

};



struct jsonServerGetNewUUIDResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerGetNewUUIDObjectStruct* getNewUUIDObjStruct;

};


// =====================================================
// Return this panel's own web TLS certificate and key
// file paths ( the central panel calls it on a node via
// the node API token so "Set Cert from Panel" fills a
// node-assigned inbound with paths that exist on the
// node )
// =====================================================

struct jsonServerGetWebCertFilesObjectStruct {
    const char*                 webCertFile;
    const char*                 webKeyFile;

};



struct jsonServerGetWebCertFilesResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerGetWebCertFilesObjectStruct* getWebCertFilesObjStruct;

};


// =====================================================
// Read-only summaries of the nodes this panel manages
// ( a parent panel calls it on a node via the node API
// token to surface transitive sub-nodes in a chained
// topology. Counts are computed by the parent, not
// returned here )
// =====================================================

struct jsonServerDescendantsObjectArrayStruct {
    const char*                 guid;
    const char*                 parentGuid;
    const char*                 name;
    const char*                 address;
    const char*                 status; // e.g. "online"
    const char**                versions; // Omittable; not present at the documented sample
    size_t                      versionsCount;

};



struct jsonServerDescendantsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      jsonServerDescendantsObjectArrayStructSize;
    struct jsonServerDescendantsObjectArrayStruct* descendantsObjArrStruct; // array

};


// =====================================================
// Generate a new X25519 keypair for Reality
// =====================================================

struct jsonServerGetNewX25519CertObjectStruct {
    const char*                 privateKey;
    const char*                 publicKey;

};



struct jsonServerGetNewX25519CertResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerGetNewX25519CertObjectStruct* getNewX25519ObjStruct;

};


// =====================================================
// Generate a new ML-DSA-65 keypair. Returns { seed,
// verify }
// =====================================================

struct jsonServerGetNewMldsa65ObjectStruct {
    const char*                 seed;
    const char*                 verify;

};



struct jsonServerGetNewMldsa65ResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerGetNewMldsa65ObjectStruct* getNewMldsa65ObjStruct;

};


// =====================================================
// Generate a new ML-KEM-768 keypair. Returns { seed,
// client }
// =====================================================

struct jsonServerGetNewMlkem768ObjectStruct {
    const char*                 client;
    const char*                 seed;

};



struct jsonServerGetNewMlkem768ResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerGetNewMlkem768ObjectStruct* getNewMlkem768ObjStruct;

};


// =====================================================
// Generate VLESS encryption auth options. Returns an
// auths array each with id, label, encryption and
// decryption fields
// =====================================================

struct jsonServerGetNewVlessEncAuthsArrayStruct {
    const char*                 id; // e.g. "x25519", "mlkem768", "x25519_xorpub", ...
    const char*                 label;
    const char*                 encryption;
    const char*                 decryption;

};



struct jsonServerGetNewVlessEncObjectStruct {
    size_t                      jsonServerGetNewVlessEncAuthsArrayStructSize;
    struct jsonServerGetNewVlessEncAuthsArrayStruct* getNewVlessEncObjAuthsArrStruct; // array

};



struct jsonServerGetNewVlessEncResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerGetNewVlessEncObjectStruct* getNewVlessEncObjStruct;

};


// =====================================================
// Stop the Xray binary ( all proxies go offline
// immediately ) response struct
// =====================================================

struct jsonServerStopXrayServiceResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Reload Xray with the current config ( typically
// required after structural inbound or routing changes )
// response struct
// =====================================================

struct jsonServerRestartXrayServiceResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Download and install the specified Xray version ( pass
// "latest" for the newest release ) response struct
// =====================================================

struct jsonServerInstallXrayResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Self-update the panel to the latest version ( the
// server restarts on success )
// =====================================================

struct jsonServerUpdatePanelObjectStruct {
    const char*                 runId;

};



struct jsonServerUpdatePanelResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerUpdatePanelObjectStruct* updatePanelObjStruct;

};


// =====================================================
// Toggle the panel update channel between stable and
// the rolling per-commit dev release ( only effective on
// dev builds ) post and response structs
// =====================================================

struct jsonServerSetUpdateChannelPostStruct {
    unsigned char               dev; // true = dev channel, false = stable

};



struct jsonServerSetUpdateChannelResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Refresh the default GeoIP / GeoSite data files ( or a
// single Geo file by filename, e.g. geoip.dat,
// geosite.dat ) response struct
// =====================================================

struct jsonServerUpdateGeofileResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Return the last N lines of the panel's own log
// =====================================================

struct jsonServerLogsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      objCount;
    const char**                obj; // every pointer presented is an element of the array

};


// =====================================================
// Return the last N lines of the Xray process log
// =====================================================

struct jsonServerXrayLogsObjectArrayStruct {
    const char*                 DateTime; // e.g. "2025-01-01T12:00:00Z"
    const char*                 Email;
    int                         Event;
    const char*                 FromAddress;
    const char*                 Inbound;
    const char*                 Outbound;
    const char*                 ToAddress;

};



struct jsonServerXrayLogsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      jsonServerXrayLogsObjectArrayStructSize;
    struct jsonServerXrayLogsObjectArrayStruct* xrayLogsObjArrStruct; // array

};


// =====================================================
// Return live AmneziaWG peer activity ( handshake,
// endpoint, transfer ) plus the panel's own AmneziaWG
// event lines
// =====================================================

struct jsonServerAmneziawgLogsPeersArrayStruct {
    const char*                 allowedIPs;
    int64_t                     down;
    const char*                 email;
    const char*                 endpoint;
    int64_t                     handshake;
    int                         inboundId;
    const char*                 interface;
    unsigned char               online;
    const char*                 tag;
    int64_t                     up;

};



struct jsonServerAmneziawgLogsObjectStruct {
    const char**                events; // every pointer presented is an element of the array
    size_t                      eventsCount;
    size_t                      jsonServerAmneziawgLogsPeersArrayStructSize;
    struct jsonServerAmneziawgLogsPeersArrayStruct* awgLogsObjPeersArrStruct; // array
    unsigned char               running;

};



struct jsonServerAmneziawgLogsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerAmneziawgLogsObjectStruct* awgLogsObjStruct;

};


// =====================================================
// Restore the panel DB from an uploaded backup (
// multipart form, field name "db" ). The panel restarts
// after restore. Destructive
// =====================================================

struct jsonServerImportDbResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Generate a new ECH ( Encrypted Client Hello ) keypair
// and config list for the given SNI post and response
// structs
// =====================================================

struct jsonServerGetNewEchCertPostStruct {
    const char*                 sni;

};



struct jsonServerGetNewEchCertResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Compute the hex SHA-256 of a certificate ( DER ) for
// pinning ( pinnedPeerCertSha256 ). Provide either a
// server file path or inline PEM / DER content
// =====================================================

struct jsonServerGetCertHashPostStruct {
    const char*                 certFile; // takes precedence over certContent
    const char*                 certContent; // used when certFile is empty

};



struct jsonServerGetRemoteCertHashPostStruct {
    const char*                 server; // domain or domain:port ( default port 443 )

};



struct jsonServerCertHashObjectArrayStruct {
    const char*                 sha256; // e.g. "e8e2d3..."

};



struct jsonServerGetCertHashResponseStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      jsonServerCertHashObjectArrayStructSize;
    struct jsonServerCertHashObjectArrayStruct* certHashObjArrStruct; // array

};



struct jsonServerGetRemoteCertHashResponseStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      jsonServerCertHashObjectArrayStructSize;
    struct jsonServerCertHashObjectArrayStruct* certHashObjArrStruct; // array

};


// =====================================================
// Run a live TLS 1.3 probe against a candidate REALITY
// target and return a feasibility verdict plus the
// certificate SAN DNS names. A target on a private /
// loopback address is reported with privateTarget=true
// and probed only when allowPrivate is set
// =====================================================

struct jsonServerScanRealityTargetPostStruct {
    const char*                 target; // host or host:port ( default port 443 )
    const char*                 sni; // Omittable, defaults to the target host
    int                         xver; // Omittable, PROXY protocol version ( 0 = none )
    unsigned char               allowPrivate; // Omittable, default false

};



struct jsonServerScanRealityTargetObjectStruct {
    const char*                 alpn; // e.g. "h2"
    unsigned char               certChainValid;
    const char*                 certIssuer; // e.g. "Google Trust Services"
    const char*                 certSubject; // e.g. "cloudflare.com"
    unsigned char               certValid;
    const char*                 curveID; // e.g. "X25519"
    unsigned char               feasible;
    unsigned char               h2;
    const char*                 host;
    const char*                 ip;
    int                         latencyMs;
    const char*                 notAfter; // e.g. "2026-08-01T00:00:00Z"
    int                         port;
    unsigned char               privateTarget;
    const char*                 reason;
    const char**                serverNames; // every pointer presented is an element of the array
    size_t                      serverNamesCount;
    const char*                 target;
    unsigned char               tls13;
    const char*                 tlsVersion; // e.g. "1.3"
    unsigned char               x25519;

};



struct jsonServerScanRealityTargetResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonServerScanRealityTargetObjectStruct* scanRealityTargetObjStruct;

};


// =====================================================
// Probe / discover REALITY targets and return each
// verdict ranked by feasibility then latency. Each
// comma-separated token may be a domain ( validated with
// SNI ), a bare IP, or a CIDR range. When empty, a
// built-in seed list is probed
// =====================================================

struct jsonServerScanRealityTargetsPostStruct {
    const char*                 targets; // Omittable, comma-separated tokens

};



struct jsonServerScanRealityTargetsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      jsonServerScanRealityTargetObjectStructSize;
    struct jsonServerScanRealityTargetObjectStruct* scanRealityTargetsObjArrStruct; // array

};


// =====================================================
// Fetch the fully aggregated inbound_client_ips database
// table ( used by nodes to sync recently active IPs
// across the cluster )
// =====================================================

struct jsonServerClientIpsIpsItemStruct {
    const char*                 ip;
    int64_t                     timestamp;

};



struct jsonServerClientIpsObjectArrayStruct {
    const char*                 clientEmail;
    int                         id;
    // may be null
    size_t                      jsonServerClientIpsIpsItemStructSize;
    struct jsonServerClientIpsIpsItemStruct* clientIpsObjArrIpsArrStruct; // array

};



struct jsonServerClientIpsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      jsonServerClientIpsObjectArrayStructSize;
    struct jsonServerClientIpsObjectArrayStruct* clientIpsObjArrStruct; // array

};


// =====================================================
// Submit a list of recently active IP timestamps ( the
// panel merges them with the existing database to
// maintain a unified global IP-limit view ) post and
// response structs
// =====================================================

struct jsonServerSubmitClientIpsObjectPostStruct {
    const char*                 clientEmail;
    size_t                      jsonServerClientIpsIpsItemStructSize;
    struct jsonServerClientIpsIpsItemStruct* submitClientIpsObjIpsArrPStruct; // array

};



struct jsonServerSubmitClientIpsPostStruct {
    size_t                      jsonServerSubmitClientIpsObjectPostStructSize;
    struct jsonServerSubmitClientIpsObjectPostStruct* submitClientIpsObjArrPStruct; // array

};



struct jsonServerSubmitClientIpsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};

void        jsonOpenApiResponseStructDelete(struct jsonOpenApiResponseStruct* openApiRStruct);

void        jsonServerStatusMemObjectStructDelete(struct jsonServerStatusMemObjectStruct* srvStatusObjMemObjStruct);

void        jsonServerStatusSwapObjectStructDelete(struct jsonServerStatusSwapObjectStruct* srvStatusObjSwapObjStruct);

void        jsonServerStatusDiskObjectStructDelete(struct jsonServerStatusDiskObjectStruct* srvStatusObjDiskObjStruct);

void        jsonServerStatusDiskIOObjectStructDelete(struct jsonServerStatusDiskIOObjectStruct* srvStatusObjDiskIOObjStruct);

void        jsonServerStatusDiskTrafficObjectStructDelete(struct jsonServerStatusDiskTrafficObjectStruct* srvStatusObjDiskTrafficObjStruct);

void        jsonServerStatusNetIOObjectStructDelete(struct jsonServerStatusNetIOObjectStruct* srvStatusObjNetIOObjStruct);

void        jsonServerStatusNetTrafficObjectStructDelete(struct jsonServerStatusNetTrafficObjectStruct* srvStatusObjNetTrafficObjStruct);

void        jsonServerStatusPublicIPObjectStructDelete(struct jsonServerStatusPublicIPObjectStruct* srvStatusObjPublicIPObjStruct);

void        jsonServerStatusAppStatsObjectStructDelete(struct jsonServerStatusAppStatsObjectStruct* srvStatusObjAppStatsObjStruct);

void        jsonServerStatusXrayObjectStructDelete(struct jsonServerStatusXrayObjectStruct* srvStatusObjXrayObjStruct);

void        jsonServerStatusLoadObjectStructDelete(struct jsonServerStatusLoadObjectStruct* srvStatusObjLoadObjStruct);

void        jsonServerStatusObjectStructDelete(struct jsonServerStatusObjectStruct* srvStatusObjStruct);

void        jsonServerStatusResponseStructDelete(struct jsonServerStatusResponseStruct* serverStatusRStruct);

void        jsonServerFail2banStatusObjectStructDelete(struct jsonServerFail2banStatusObjectStruct* fail2banStatusObjStruct);

void        jsonServerFail2banStatusResponseStructDelete(struct jsonServerFail2banStatusResponseStruct* serverFail2banStatusRStruct);

void        jsonServerCpuHistoryObjectArrayStructDelete(struct jsonServerCpuHistoryObjectArrayStruct* cpuHistoryObjArrStruct, size_t arraySize);

void        jsonServerCpuHistoryResponseStructDelete(struct jsonServerCpuHistoryResponseStruct* serverCpuHistoryRStruct);

void        jsonServerHistoryObjectArrayStructDelete(struct jsonServerHistoryObjectArrayStruct* srvHistoryObjArrStruct, size_t arraySize);

void        jsonServerHistoryResponseStructDelete(struct jsonServerHistoryResponseStruct* serverHistoryRStruct);

void        jsonServerXrayMetricsStateResponseStructDelete(struct jsonServerXrayMetricsStateResponseStruct* serverXrayMetricsStateRStruct);

void        jsonServerXrayMetricsHistoryResponseStructDelete(struct jsonServerXrayMetricsHistoryResponseStruct* serverXrayMetricsHistoryRStruct);

void        jsonServerXrayObservatoryResponseStructDelete(struct jsonServerXrayObservatoryResponseStruct* serverXrayObservatoryRStruct);

void        jsonServerXrayObservatoryHistoryResponseStructDelete(struct jsonServerXrayObservatoryHistoryResponseStruct* serverXrayObservatoryHistoryRStruct);

void        jsonServerGetXrayVersionResponseStructDelete(struct jsonServerGetXrayVersionResponseStruct* serverGetXrayVersionRStruct);

void        jsonServerGetPanelUpdateInfoResponseStructDelete(struct jsonServerGetPanelUpdateInfoResponseStruct* serverGetPanelUpdateInfoRStruct);

void        jsonServerGetUpdateStatusObjectStructDelete(struct jsonServerGetUpdateStatusObjectStruct* getUpdateStatusObjStruct);

void        jsonServerGetUpdateStatusResponseStructDelete(struct jsonServerGetUpdateStatusResponseStruct* serverGetUpdateStatusRStruct);

void        jsonServerGetConfigJsonResponseStructDelete(struct jsonServerGetConfigJsonResponseStruct* serverGetConfigJsonRStruct);

void        jsonServerGetDbResponseStructDelete(struct jsonServerGetDbResponseStruct* serverGetDbRStruct);

void        jsonServerGetMigrationResponseStructDelete(struct jsonServerGetMigrationResponseStruct* serverGetMigrationRStruct);

void        jsonServerGetNewUUIDObjectStructDelete(struct jsonServerGetNewUUIDObjectStruct* getNewUUIDObjStruct);

void        jsonServerGetNewUUIDResponseStructDelete(struct jsonServerGetNewUUIDResponseStruct* serverGetNewUUIDRStruct);

void        jsonServerGetWebCertFilesObjectStructDelete(struct jsonServerGetWebCertFilesObjectStruct* getWebCertFilesObjStruct);

void        jsonServerGetWebCertFilesResponseStructDelete(struct jsonServerGetWebCertFilesResponseStruct* serverGetWebCertFilesRStruct);

void        jsonServerDescendantsObjectArrayStructDelete(struct jsonServerDescendantsObjectArrayStruct* descendantsObjArrStruct, size_t arraySize);

void        jsonServerDescendantsResponseStructDelete(struct jsonServerDescendantsResponseStruct* serverDescendantsRStruct);

void        jsonServerGetNewX25519CertObjectStructDelete(struct jsonServerGetNewX25519CertObjectStruct* getNewX25519ObjStruct);

void        jsonServerGetNewX25519CertResponseStructDelete(struct jsonServerGetNewX25519CertResponseStruct* serverGetNewX25519CertRStruct);

void        jsonServerGetNewMldsa65ObjectStructDelete(struct jsonServerGetNewMldsa65ObjectStruct* getNewMldsa65ObjStruct);

void        jsonServerGetNewMldsa65ResponseStructDelete(struct jsonServerGetNewMldsa65ResponseStruct* serverGetNewMldsa65RStruct);

void        jsonServerGetNewMlkem768ObjectStructDelete(struct jsonServerGetNewMlkem768ObjectStruct* getNewMlkem768ObjStruct);

void        jsonServerGetNewMlkem768ResponseStructDelete(struct jsonServerGetNewMlkem768ResponseStruct* serverGetNewMlkem768RStruct);

void        jsonServerGetNewVlessEncAuthsArrayStructDelete(struct jsonServerGetNewVlessEncAuthsArrayStruct* getNewVlessEncObjAuthsArrStruct, size_t arraySize);

void        jsonServerGetNewVlessEncObjectStructDelete(struct jsonServerGetNewVlessEncObjectStruct* getNewVlessEncObjStruct);

void        jsonServerGetNewVlessEncResponseStructDelete(struct jsonServerGetNewVlessEncResponseStruct* serverGetNewVlessEncRStruct);

void        jsonServerStopXrayServiceResponseStructDelete(struct jsonServerStopXrayServiceResponseStruct* serverStopXrayServiceRStruct);

void        jsonServerRestartXrayServiceResponseStructDelete(struct jsonServerRestartXrayServiceResponseStruct* serverRestartXrayServiceRStruct);

void        jsonServerInstallXrayResponseStructDelete(struct jsonServerInstallXrayResponseStruct* serverInstallXrayRStruct);

void        jsonServerUpdatePanelObjectStructDelete(struct jsonServerUpdatePanelObjectStruct* updatePanelObjStruct);

void        jsonServerUpdatePanelResponseStructDelete(struct jsonServerUpdatePanelResponseStruct* serverUpdatePanelRStruct);

void        jsonServerSetUpdateChannelPostStructDelete(struct jsonServerSetUpdateChannelPostStruct* serverSetUpdateChannelPostStruct);

void        jsonServerSetUpdateChannelResponseStructDelete(struct jsonServerSetUpdateChannelResponseStruct* serverSetUpdateChannelRStruct);

void        jsonServerUpdateGeofileResponseStructDelete(struct jsonServerUpdateGeofileResponseStruct* serverUpdateGeofileRStruct);

void        jsonServerLogsResponseStructDelete(struct jsonServerLogsResponseStruct* serverLogsRStruct);

void        jsonServerXrayLogsObjectArrayStructDelete(struct jsonServerXrayLogsObjectArrayStruct* xrayLogsObjArrStruct, size_t arraySize);

void        jsonServerXrayLogsResponseStructDelete(struct jsonServerXrayLogsResponseStruct* serverXrayLogsRStruct);

void        jsonServerAmneziawgLogsPeersArrayStructDelete(struct jsonServerAmneziawgLogsPeersArrayStruct* awgLogsObjPeersArrStruct, size_t arraySize);

void        jsonServerAmneziawgLogsObjectStructDelete(struct jsonServerAmneziawgLogsObjectStruct* awgLogsObjStruct);

void        jsonServerAmneziawgLogsResponseStructDelete(struct jsonServerAmneziawgLogsResponseStruct* serverAmneziawgLogsRStruct);

void        jsonServerImportDbResponseStructDelete(struct jsonServerImportDbResponseStruct* serverImportDbRStruct);

void        jsonServerGetNewEchCertPostStructDelete(struct jsonServerGetNewEchCertPostStruct* serverGetNewEchCertPostStruct);

void        jsonServerGetNewEchCertResponseStructDelete(struct jsonServerGetNewEchCertResponseStruct* serverGetNewEchCertRStruct);

void        jsonServerGetCertHashPostStructDelete(struct jsonServerGetCertHashPostStruct* serverGetCertHashPostStruct);

void        jsonServerGetRemoteCertHashPostStructDelete(struct jsonServerGetRemoteCertHashPostStruct* serverGetRemoteCertHashPostStruct);

void        jsonServerCertHashObjectArrayStructDelete(struct jsonServerCertHashObjectArrayStruct* certHashObjArrStruct, size_t arraySize);

void        jsonServerGetCertHashResponseStructDelete(struct jsonServerGetCertHashResponseStruct* serverGetCertHashRStruct);

void        jsonServerGetRemoteCertHashResponseStructDelete(struct jsonServerGetRemoteCertHashResponseStruct* serverGetRemoteCertHashRStruct);

void        jsonServerScanRealityTargetPostStructDelete(struct jsonServerScanRealityTargetPostStruct* serverScanRealityTargetPostStruct);

void        jsonServerScanRealityTargetObjectStructDelete(struct jsonServerScanRealityTargetObjectStruct* scanRealityTargetObjStruct, size_t arraySize);

void        jsonServerScanRealityTargetResponseStructDelete(struct jsonServerScanRealityTargetResponseStruct* serverScanRealityTargetRStruct);

void        jsonServerScanRealityTargetsPostStructDelete(struct jsonServerScanRealityTargetsPostStruct* serverScanRealityTargetsPostStruct);

void        jsonServerScanRealityTargetsResponseStructDelete(struct jsonServerScanRealityTargetsResponseStruct* serverScanRealityTargetsRStruct);

void        jsonServerClientIpsIpsItemStructDelete(struct jsonServerClientIpsIpsItemStruct* clientIpsObjArrIpsArrStruct, size_t arraySize);

void        jsonServerClientIpsObjectArrayStructDelete(struct jsonServerClientIpsObjectArrayStruct* clientIpsObjArrStruct, size_t arraySize);

void        jsonServerClientIpsResponseStructDelete(struct jsonServerClientIpsResponseStruct* serverCliIpsRStruct);

void        jsonServerSubmitClientIpsObjectPostStructDelete(struct jsonServerSubmitClientIpsObjectPostStruct* submitClientIpsObjArrPStruct, size_t arraySize);

void        jsonServerSubmitClientIpsPostStructDelete(struct jsonServerSubmitClientIpsPostStruct* serverSubmitClientIpsPostStruct);

void        jsonServerSubmitClientIpsResponseStructDelete(struct jsonServerSubmitClientIpsResponseStruct* serverSubmitCliIpsRStruct);

struct jsonOpenApiResponseStruct*                  jsonOpenApiResponse(const char* json);

struct jsonServerStatusResponseStruct*             jsonServerStatusResponse(const char* json);

struct jsonServerFail2banStatusResponseStruct*     jsonServerFail2banStatusResponse(const char* json);

struct jsonServerCpuHistoryResponseStruct*         jsonServerCpuHistoryResponse(const char* json);

struct jsonServerHistoryResponseStruct*            jsonServerHistoryResponse(const char* json);

struct jsonServerXrayMetricsStateResponseStruct*   jsonServerXrayMetricsStateResponse(const char* json);

struct jsonServerXrayMetricsHistoryResponseStruct* jsonServerXrayMetricsHistoryResponse(const char* json);

struct jsonServerXrayObservatoryResponseStruct*    jsonServerXrayObservatoryResponse(const char* json);

struct jsonServerXrayObservatoryHistoryResponseStruct* jsonServerXrayObservatoryHistoryResponse(const char* json);

struct jsonServerGetXrayVersionResponseStruct*     jsonServerGetXrayVersionResponse(const char* json);

struct jsonServerGetPanelUpdateInfoResponseStruct* jsonServerGetPanelUpdateInfoResponse(const char* json);

struct jsonServerGetUpdateStatusResponseStruct*    jsonServerGetUpdateStatusResponse(const char* json);

struct jsonServerGetConfigJsonResponseStruct*      jsonServerGetConfigJsonResponse(const char* json);

struct jsonServerGetDbResponseStruct*              jsonServerGetDbResponse(const char* json);

struct jsonServerGetMigrationResponseStruct*       jsonServerGetMigrationResponse(const char* json);

struct jsonServerGetNewUUIDResponseStruct*         jsonServerGetNewUUIDResponse(const char* json);

struct jsonServerGetWebCertFilesResponseStruct*    jsonServerGetWebCertFilesResponse(const char* json);

struct jsonServerDescendantsResponseStruct*        jsonServerDescendantsResponse(const char* json);

struct jsonServerGetNewX25519CertResponseStruct*   jsonServerGetNewX25519CertResponse(const char* json);

struct jsonServerGetNewMldsa65ResponseStruct*      jsonServerGetNewMldsa65Response(const char* json);

struct jsonServerGetNewMlkem768ResponseStruct*     jsonServerGetNewMlkem768Response(const char* json);

struct jsonServerGetNewVlessEncResponseStruct*     jsonServerGetNewVlessEncResponse(const char* json);

struct jsonServerStopXrayServiceResponseStruct*    jsonServerStopXrayServiceResponse(const char* json);

struct jsonServerRestartXrayServiceResponseStruct* jsonServerRestartXrayServiceResponse(const char* json);

struct jsonServerInstallXrayResponseStruct*        jsonServerInstallXrayResponse(const char* json);

struct jsonServerUpdatePanelResponseStruct*        jsonServerUpdatePanelResponse(const char* json);

const char*                                        jsonServerSetUpdateChannelPost(struct jsonServerSetUpdateChannelPostStruct* serverSetUpdateChannelPostStruct);

struct jsonServerSetUpdateChannelResponseStruct*   jsonServerSetUpdateChannelResponse(const char* json);

struct jsonServerUpdateGeofileResponseStruct*      jsonServerUpdateGeofileResponse(const char* json);

struct jsonServerLogsResponseStruct*               jsonServerLogsResponse(const char* json);

struct jsonServerXrayLogsResponseStruct*           jsonServerXrayLogsResponse(const char* json);

struct jsonServerAmneziawgLogsResponseStruct*      jsonServerAmneziawgLogsResponse(const char* json);

struct jsonServerImportDbResponseStruct*           jsonServerImportDbResponse(const char* json);

const char*                                        jsonServerGetNewEchCertPost(struct jsonServerGetNewEchCertPostStruct* serverGetNewEchCertPostStruct);

struct jsonServerGetNewEchCertResponseStruct*      jsonServerGetNewEchCertResponse(const char* json);

const char*                                        jsonServerGetCertHashPost(struct jsonServerGetCertHashPostStruct* serverGetCertHashPostStruct);

const char*                                        jsonServerGetRemoteCertHashPost(struct jsonServerGetRemoteCertHashPostStruct* serverGetRemoteCertHashPostStruct);

struct jsonServerGetCertHashResponseStruct*        jsonServerGetCertHashResponse(const char* json);

struct jsonServerGetRemoteCertHashResponseStruct*  jsonServerGetRemoteCertHashResponse(const char* json);

const char*                                        jsonServerScanRealityTargetPost(struct jsonServerScanRealityTargetPostStruct* serverScanRealityTargetPostStruct);

struct jsonServerScanRealityTargetResponseStruct*  jsonServerScanRealityTargetResponse(const char* json);

const char*                                        jsonServerScanRealityTargetsPost(struct jsonServerScanRealityTargetsPostStruct* serverScanRealityTargetsPostStruct);

struct jsonServerScanRealityTargetsResponseStruct* jsonServerScanRealityTargetsResponse(const char* json);

struct jsonServerClientIpsResponseStruct*          jsonServerClientIpsResponse(const char* json);

const char*                                        jsonServerSubmitClientIpsPost(struct jsonServerSubmitClientIpsPostStruct* serverSubmitClientIpsPostStruct);

struct jsonServerSubmitClientIpsResponseStruct*    jsonServerSubmitClientIpsResponse(const char* json);

#endif /* CJSON_TELEGRAM_XUI_BOT_SERVER_H */
