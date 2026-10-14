#ifndef CJSON_TELEGRAM_XUI_BOT_NODES_H
#define CJSON_TELEGRAM_XUI_BOT_NODES_H

// nodes section - https://docs.sanaei.dev/docs/reference/api/nodes/

#include <stddef.h>
#include <stdint.h>


// =====================================================
// Nodes : remote 3x-ui panels managed by this central
// panel. Each node carries connection details, health
// metrics, and sync state. The panel can proxy inbound
// assignments, certificates, and client traffic across
// the node cluster. NOTE: you must check each field on
// its own and then parse or assign a NULL to it, dont
// check them all at once
// =====================================================

struct jsonNodeObjectStruct {
    int                         activeCount;
    const char*                 address;
    unsigned char               allowPrivateAddress;
    const char*                 basePath;
    int                         clientCount;
    unsigned char               configDirty;
    int64_t                     configDirtyAt;
    double                      cpuPct;
    int64_t                     createdAt; // creation time in unix milliseconds
    int                         depletedCount;
    int                         disabledCount;
    unsigned char               enable;
    const char*                 guid;
    unsigned char               hasApiToken; // token itself is never returned
    int                         id;
    int                         inboundCount;
    const char*                 inboundSyncMode;
    const char**                inboundTags; // every pointer presented is an element of
                                             // the array
    const char*                 lastError;
    int64_t                     lastHeartbeat; // unix milliseconds
    int64_t                     latencyMs;
    double                      memPct;
    const char*                 name;
    int64_t                     netDown;
    int64_t                     netUp;
    int                         onlineCount;
    const char*                 outboundTag;
    const char*                 panelVersion;
    const char*                 parentGuid;
    const char*                 pinnedCertSha256;
    int                         port;
    const char*                 remark;
    const char*                 scheme; // "http" or "https"
    const char*                 status; // e.g. "online", "offline", "error"
    const char*                 tlsVerifyMode;
    unsigned char               transitive;
    int64_t                     updatedAt; // last update time in unix milliseconds
    int64_t                     uptimeSecs;
    const char*                 xrayError;
    const char*                 xrayState;
    const char*                 xrayVersion;

};




struct jsonNodeConnectionDetailsObjectStruct {
    const char*                 address;
    const char*                 apiToken;
    const char*                 basePath;
    int                         port;
    const char*                 scheme;

};




struct jsonNodeMtlsCaObjectStruct {
    const char*                 caCert;

};




struct jsonNodeGetWebCertFilesObjectStruct {
    const char*                 webCertFile;
    const char*                 webKeyFile;

};




struct jsonNodeCertFingerprintObjectStruct {
    const char*                 sha256;

};




struct jsonNodeListInboundsObjectArrayStruct {
    int                         port;
    const char*                 protocol;
    const char*                 remark;
    const char*                 tag;

};




struct jsonNodeUpdatePanelObjectArrayStruct {
    const char*                 error; // omitted when ok is true
    int                         id;
    const char*                 name;
    unsigned char               ok;

};




struct jsonNodeHistoryObjectArrayStruct {
    int64_t                     t;
    double                      v;

};




// =====================================================
// List every configured node with its connection
// details, health, and last heartbeat
// =====================================================

struct jsonListNodesResponseStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      jsonNodeObjectStructSize;
    struct jsonNodeObjectStruct* listNodesObjArrStruct; // array

};




// =====================================================
// Fetch a single node by id
// =====================================================

struct jsonGetNodeResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonNodeObjectStruct* getNodeObjStruct;

};




// =====================================================
// Fetch a node's own web TLS certificate/key file paths
// =====================================================

struct jsonGetNodeWebCertFilesResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonNodeGetWebCertFilesObjectStruct* getNodeWebCertFilesObjStruct;

};




// =====================================================
// Register a new remote node
// =====================================================

struct jsonAddNodePostStruct {
    const char*                 name; // display name ( required )
    const char*                 address; // host or ip ( required )
    int                         port; // api port ( required )
    const char*                 scheme; // "http" or "https", defaults to "https"
    const char*                 remark; // optional description
    const char*                 basePath; // api base path, defaults to "/"
    unsigned char               enable; // defaults to true on create
    unsigned char               allowPrivateAddress;
    const char*                 inboundSyncMode;
    const char*                 outboundTag;
    const char*                 pinnedCertSha256;
    const char*                 tlsVerifyMode;
    unsigned char               transitive;

};




struct jsonAddNodeResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonNodeObjectStruct* addNodeObjStruct;

};




// =====================================================
// Replace a node's connection details ( full-row update )
// =====================================================

struct jsonUpdateNodePostStruct {
    const char*                 name;
    const char*                 address;
    int                         port;
    const char*                 scheme;
    const char*                 remark;
    const char*                 basePath;
    unsigned char               enable;
    unsigned char               allowPrivateAddress;
    const char*                 inboundSyncMode;
    const char*                 outboundTag;
    const char*                 pinnedCertSha256;
    const char*                 tlsVerifyMode;
    unsigned char               transitive;

};




struct jsonUpdateNodeResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // null on success

};




// =====================================================
// Delete a node; inbounds bound to it are not
// auto-migrated
// =====================================================

struct jsonDeleteNodeResponseStruct {
    unsigned char               success;
    const char*                 msg;

};




// =====================================================
// Pause or resume traffic sync with this node
// =====================================================

struct jsonSetEnableNodePostStruct {
    unsigned char               enable;

};




struct jsonSetEnableNodeResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // null on success

};




// =====================================================
// Probe a node without saving it; returns the same
// heartbeat snapshot a registered node would have
// =====================================================

struct jsonTestNodePostStruct {
    struct jsonNodeConnectionDetailsObjectStruct* testNodeConnDetailsObjStruct;

};




struct jsonTestNodeResponseStruct {
    unsigned char               success;
    const char*                 msg;

};




// =====================================================
// Return the leaf certificate's SHA-256 fingerprint
// =====================================================

struct jsonNodeCertFingerprintPostStruct {
    const char*                 scheme;
    const char*                 address;
    int                         port;
    const char*                 basePath;

};




struct jsonNodeCertFingerprintResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonNodeCertFingerprintObjectStruct* nodeCertFingerprintObjStruct;

};




// =====================================================
// Return this panel's node-auth CA certificate ( public,
// PEM ) to paste into a node's mTLS trust setting
// =====================================================

struct jsonNodeMtlsCaResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonNodeMtlsCaObjectStruct* mtlsCaObjStruct;

};




// =====================================================
// Set the CA certificate this panel trusts for incoming
// node-API client certificates
// =====================================================

struct jsonNodeMtlsTrustCaPostStruct {
    const char*                 caCert;

};




struct jsonNodeMtlsTrustCaResponseStruct {
    unsigned char               success;
    const char*                 msg;

};




// =====================================================
// Validate the stored master mTLS client credential and
// invalidate cached transports
// =====================================================

struct jsonNodeMtlsReloadClientResponseStruct {
    unsigned char               success;
    const char*                 msg;

};




// =====================================================
// Use unsaved node connection details to list the
// remote inbounds available for selective import
// =====================================================

struct jsonListNodeInboundsPostStruct {
    struct jsonNodeConnectionDetailsObjectStruct* listNodeInboundsConnDetailsObjStruct;

};




struct jsonListNodeInboundsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      jsonNodeListInboundsObjectArrayStructSize;
    struct jsonNodeListInboundsObjectArrayStruct* listNodeInboundsObjArrStruct; // array

};




// =====================================================
// Probe an existing node, updating its cached health
// state
// =====================================================

struct jsonProbeNodeResponseStruct {
    unsigned char               success;
    const char*                 msg;

};




// =====================================================
// Trigger the official panel self-updater on each given
// node; only enabled, online nodes are updated
// =====================================================

struct jsonUpdateNodePanelPostStruct {
    int*                        ids; // node ids to update; every pointer presented is
                                     // an element of the array
    unsigned char               dev; // use dev channel instead of stable

};




struct jsonUpdateNodePanelResponseStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      jsonNodeUpdatePanelObjectArrayStructSize;
    struct jsonNodeUpdatePanelObjectArrayStruct* updateNodePanelObjArrStruct; // array

};




// =====================================================
// Aggregated metric history for a node; id, metric and
// bucket are also path components
// =====================================================

struct jsonNodeHistoryQueryStruct {
    int                         id; // node id, also a path component
    const char*                 metric; // "cpu" or "mem", also a path component
    int                         bucket; // bucket size in seconds, also a path component

};




struct jsonGetNodeHistoryResponseStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      jsonNodeHistoryObjectArrayStructSize;
    struct jsonNodeHistoryObjectArrayStruct* getNodeHistoryObjArrStruct; // array

};

void        jsonNodeObjectStructDelete(struct jsonNodeObjectStruct* nodeObjStruct, size_t arraySize);

void        jsonNodeConnectionDetailsObjectStructDelete(struct jsonNodeConnectionDetailsObjectStruct* connectionDetailsObjStruct);

void        jsonNodeMtlsCaObjectStructDelete(struct jsonNodeMtlsCaObjectStruct* mtlsCaObjStruct);

void        jsonNodeGetWebCertFilesObjectStructDelete(struct jsonNodeGetWebCertFilesObjectStruct* getNodeWebCertFilesObjStruct);

void        jsonNodeCertFingerprintObjectStructDelete(struct jsonNodeCertFingerprintObjectStruct* nodeCertFingerprintObjStruct);

void        jsonNodeListInboundsObjectArrayStructDelete(struct jsonNodeListInboundsObjectArrayStruct* listNodeInboundsObjArrStruct, size_t arraySize);

void        jsonNodeUpdatePanelObjectArrayStructDelete(struct jsonNodeUpdatePanelObjectArrayStruct* updateNodePanelObjArrStruct, size_t arraySize);

void        jsonNodeHistoryObjectArrayStructDelete(struct jsonNodeHistoryObjectArrayStruct* getNodeHistoryObjArrStruct, size_t arraySize);

void        jsonListNodesResponseStructDelete(struct jsonListNodesResponseStruct* listNodesRStruct);

void        jsonGetNodeResponseStructDelete(struct jsonGetNodeResponseStruct* getNodeRStruct);

void        jsonGetNodeWebCertFilesResponseStructDelete(struct jsonGetNodeWebCertFilesResponseStruct* getNodeWebCertFilesRStruct);

void        jsonAddNodePostStructDelete(struct jsonAddNodePostStruct* addNodePostStruct);

void        jsonAddNodeResponseStructDelete(struct jsonAddNodeResponseStruct* addNodeRStruct);

void        jsonUpdateNodePostStructDelete(struct jsonUpdateNodePostStruct* updateNodePostStruct);

void        jsonUpdateNodeResponseStructDelete(struct jsonUpdateNodeResponseStruct* updateNodeRStruct);

void        jsonDeleteNodeResponseStructDelete(struct jsonDeleteNodeResponseStruct* deleteNodeRStruct);

void        jsonSetEnableNodePostStructDelete(struct jsonSetEnableNodePostStruct* setEnableNodePostStruct);

void        jsonSetEnableNodeResponseStructDelete(struct jsonSetEnableNodeResponseStruct* setEnableNodeRStruct);

void        jsonTestNodePostStructDelete(struct jsonTestNodePostStruct* testNodePostStruct);

void        jsonTestNodeResponseStructDelete(struct jsonTestNodeResponseStruct* testNodeRStruct);

void        jsonNodeCertFingerprintPostStructDelete(struct jsonNodeCertFingerprintPostStruct* nodeCertFingerprintPostStruct);

void        jsonNodeCertFingerprintResponseStructDelete(struct jsonNodeCertFingerprintResponseStruct* nodeCertFingerprintRStruct);

void        jsonNodeMtlsCaResponseStructDelete(struct jsonNodeMtlsCaResponseStruct* nodeMtlsCaRStruct);

void        jsonNodeMtlsTrustCaPostStructDelete(struct jsonNodeMtlsTrustCaPostStruct* nodeMtlsTrustCaPostStruct);

void        jsonNodeMtlsTrustCaResponseStructDelete(struct jsonNodeMtlsTrustCaResponseStruct* nodeMtlsTrustCaRStruct);

void        jsonNodeMtlsReloadClientResponseStructDelete(struct jsonNodeMtlsReloadClientResponseStruct* nodeMtlsReloadClientRStruct);

void        jsonListNodeInboundsPostStructDelete(struct jsonListNodeInboundsPostStruct* listNodeInboundsPostStruct);

void        jsonListNodeInboundsResponseStructDelete(struct jsonListNodeInboundsResponseStruct* listNodeInboundsRStruct);

void        jsonProbeNodeResponseStructDelete(struct jsonProbeNodeResponseStruct* probeNodeRStruct);

void        jsonUpdateNodePanelPostStructDelete(struct jsonUpdateNodePanelPostStruct* updateNodePanelPostStruct);

void        jsonUpdateNodePanelResponseStructDelete(struct jsonUpdateNodePanelResponseStruct* updateNodePanelRStruct);

void        jsonNodeHistoryQueryStructDelete(struct jsonNodeHistoryQueryStruct* nodeHistoryQueryStruct);

void        jsonGetNodeHistoryResponseStructDelete(struct jsonGetNodeHistoryResponseStruct* getNodeHistoryRStruct);

struct jsonListNodesResponseStruct*                jsonListNodesResponse(const char* json);

struct jsonGetNodeResponseStruct*                  jsonGetNodeResponse(const char* json);

struct jsonGetNodeWebCertFilesResponseStruct*      jsonGetNodeWebCertFilesResponse(const char* json);

const char*                                        jsonAddNodePost(struct jsonAddNodePostStruct* addNodePostStruct);

struct jsonAddNodeResponseStruct*                  jsonAddNodeResponse(const char* json);

const char*                                        jsonUpdateNodePost(struct jsonUpdateNodePostStruct* updateNodePostStruct);

struct jsonUpdateNodeResponseStruct*               jsonUpdateNodeResponse(const char* json);

struct jsonDeleteNodeResponseStruct*               jsonDeleteNodeResponse(const char* json);

const char*                                        jsonSetEnableNodePost(struct jsonSetEnableNodePostStruct* setEnableNodePostStruct);

struct jsonSetEnableNodeResponseStruct*            jsonSetEnableNodeResponse(const char* json);

const char*                                        jsonTestNodePost(struct jsonTestNodePostStruct* testNodePostStruct);

struct jsonTestNodeResponseStruct*                 jsonTestNodeResponse(const char* json);

const char*                                        jsonNodeCertFingerprintPost(struct jsonNodeCertFingerprintPostStruct* nodeCertFingerprintPostStruct);

struct jsonNodeCertFingerprintResponseStruct*      jsonNodeCertFingerprintResponse(const char* json);

struct jsonNodeMtlsCaResponseStruct*               jsonNodeMtlsCaResponse(const char* json);

const char*                                        jsonNodeMtlsTrustCaPost(struct jsonNodeMtlsTrustCaPostStruct* nodeMtlsTrustCaPostStruct);

struct jsonNodeMtlsTrustCaResponseStruct*          jsonNodeMtlsTrustCaResponse(const char* json);

struct jsonNodeMtlsReloadClientResponseStruct*     jsonNodeMtlsReloadClientResponse(const char* json);

const char*                                        jsonListNodeInboundsPost(struct jsonListNodeInboundsPostStruct* listNodeInboundsPostStruct);

struct jsonListNodeInboundsResponseStruct*         jsonListNodeInboundsResponse(const char* json);

struct jsonProbeNodeResponseStruct*                jsonProbeNodeResponse(const char* json);

const char*                                        jsonUpdateNodePanelPost(struct jsonUpdateNodePanelPostStruct* updateNodePanelPostStruct);

struct jsonUpdateNodePanelResponseStruct*          jsonUpdateNodePanelResponse(const char* json);

const char*                                        jsonNodeHistoryQuery(struct jsonNodeHistoryQueryStruct* nodeHistoryQueryStruct);

struct jsonGetNodeHistoryResponseStruct*           jsonGetNodeHistoryResponse(const char* json);

#endif /* CJSON_TELEGRAM_XUI_BOT_NODES_H */
