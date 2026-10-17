#ifndef CJSON_TELEGRAM_XUI_BOT_INBOUNDS_H
#define CJSON_TELEGRAM_XUI_BOT_INBOUNDS_H

// inbounds section - https://docs.sanaei.dev/docs/reference/api/inbounds/

#include <stddef.h>
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
    int64_t                     totalGB; // Albeit named totalGB, its the total traffic of the user in BYTES
    int64_t                     updatedAt; // "updated_at" on server side

};



struct jsonListInboundSettingsObjectStruct {
    size_t jsonListInboundSettingsClientsArrayStructSize;
    struct jsonListInboundSettingsClientsArrayStruct* listInSettingsCliArrStruct; // array
    const char*                 decryption;
    const char*                 encryption;

};



struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersStruct {
    const char*                 name; // header key, e.g. "sdfasdaf"
    const char**                value; // array of header values
    int64_t                     valueCount;

};



struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectRequestObjectStruct {
    const char*                 version;
    const char*                 method;
    const char**                path; // array of path entries
    int64_t                     pathCount;
    size_t                      jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersStructSize;
    struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersStruct* listInStreamSettingsTcpSettingsObjHeaderObjReqHeadersStruct; // array

};



struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectResponseObjectStruct {
    const char*                 version;
    const char*                 status;
    const char*                 reason;
    size_t                      jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersStructSize;
    struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersStruct* listInStreamSettingsTcpSettingsObjHeaderObjResHeadersStruct; // array

};



struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectStruct {
    const char*                 type;
    struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectRequestObjectStruct* listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct;
    struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectResponseObjectStruct* listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct;

};



struct jsonListInboundStreamSettingsTcpSettingsObjectStruct {
    unsigned char               acceptProxyProtocol;
    struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectStruct* listInStreamSettingsTcpSettingsObjHeaderObjStruct;

};



struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersStruct {
    const char*                 name; // header key, e.g. "sdfasdaf"
    const char**                value; // array of header values
    int64_t                     valueCount;

};



struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectRequestObjectStruct {
    const char*                 version;
    const char*                 method;
    const char**                path; // array of path entries
    int64_t                     pathCount;
    size_t                      jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersStructSize;
    struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersStruct* listInStreamSettingsWSSettingsObjHeaderObjReqHeadersStruct; // array

};



struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectResponseObjectStruct {
    const char*                 version;
    const char*                 status;
    const char*                 reason;
    size_t                      jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersStructSize;
    struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersStruct* listInStreamSettingsWSSettingsObjHeaderObjResHeadersStruct; // array

};



struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectStruct {
    const char*                 type;
    struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectRequestObjectStruct* listInStreamSettingsWSSettingsObjHeaderObjReqObjStruct;
    struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectResponseObjectStruct* listInStreamSettingsWSSettingsObjHeaderObjResObjStruct;

};



struct jsonListInboundStreamSettingsWSSettingsObjectStruct {
    unsigned char               acceptProxyProtocol;
    struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectStruct* listInStreamSettingsWSSettingsObjHeaderObjStruct;

};



struct jsonListInboundStreamSettingsGRPCSettingsObjectStruct {
    const char*                 serviceName;
    const char*                 authority;
    unsigned char               multiMode;

};



struct jsonListInboundStreamSettingsHTTPUpgradeSettingsObjectHeadersStruct {
    const char*                 name; // object key, e.g. "name01"
    const char*                 value;

};



struct jsonListInboundStreamSettingsHTTPUpgradeSettingsObjectStruct {
    unsigned char               acceptProxyProtocol;
    const char*                 path;
    const char*                 host;
    size_t                      jsonListInboundStreamSettingsHTTPUpgradeSettingsObjectHeadersStructSize;
    struct jsonListInboundStreamSettingsHTTPUpgradeSettingsObjectHeadersStruct* listInStreamSettingsHTTPUpgradeSettingsObjHeadersStruct; // array

};



struct jsonListInboundStreamSettingsXHTTPSettingsObjectXMuxObjectStruct {
    const char*                 maxConcurrency;
    int64_t                     maxConnections;
    int64_t                     cMaxReuseTimes;
    const char*                 hMaxRequestTimes;
    const char*                 hMaxReusableSecs;
    int64_t                     hKeepAlivePeriod;

};



struct jsonListInboundStreamSettingsXHTTPSettingsObjectHeadersStruct {
    const char*                 name; // object key, e.g. "name01"
    const char*                 value;

};



struct jsonListInboundStreamSettingsXHTTPSettingsObjectStruct {
    const char*                 path;
    const char*                 host;
    const char*                 mode;
    const char*                 xPaddingBytes;
    unsigned char               xPaddingObfsMode;
    const char*                 xPaddingKey;
    const char*                 xPaddingHeader;
    const char*                 xPaddingPlacement;
    const char*                 xPaddingMethod;
    const char*                 sessionIDPlacement;
    const char*                 sessionIDKey;
    const char*                 sessionIDTable;
    const char*                 sessionIDLength;
    const char*                 seqPlacement;
    const char*                 seqKey;
    const char*                 uplinkDataPlacement;
    const char*                 uplinkDataKey;
    const char*                 scMaxEachPostBytes;
    unsigned char               noSSEHeader;
    int64_t                     scMaxBufferedPosts;
    const char*                 scStreamUpServerSecs;
    int64_t                     serverMaxHeaderBytes;
    const char*                 uplinkHTTPMethod;
    size_t                      jsonListInboundStreamSettingsXHTTPSettingsObjectHeadersStructSize;
    struct jsonListInboundStreamSettingsXHTTPSettingsObjectHeadersStruct* listInStreamSettingsXHTTPSettingsObjHeadersStruct; // array
    const char*                 scMinPostsIntervalMs;
    int64_t                     uplinkChunkSize;
    unsigned char               noGRPCHeader;
    struct jsonListInboundStreamSettingsXHTTPSettingsObjectXMuxObjectStruct* listInStreamSettingsXHTTPSettingsObjXMuxObjStruct;

};



struct jsonListInboundStreamSettingsMKcpSettingsObjectStruct {
    int64_t                     mtu;
    int64_t                     tti;
    int64_t                     uplinkCapacity;
    int64_t                     downlinkCapacity;
    int64_t                     cwndMultiplier;
    int64_t                     maxSendingWindow;

};



struct jsonListInboundStreamSettingsFinalMaskUdpMkcpLegacyObjectStruct {
    const char*                 header; // e.g. ""
    const char*                 value; // e.g. "password1234"

};



struct jsonListInboundStreamSettingsFinalMaskUdpXdnsObjectStruct {
    const char**                domains; // array of domain names
    int64_t                     domainsCount;

};



struct jsonListInboundStreamSettingsFinalMaskUdpXicmpObjectStruct {
    unsigned char               dgram;
    const char**                ips; // array of ip addresses
    int64_t                     ipsCount;

};



struct jsonListInboundStreamSettingsFinalMaskUdpRealmTlsConfigObjectStruct {
    const char*                 serverName;
    const char**                alpn; // array of alpn options, h3 / h2 / http/1.1
    int64_t                     alpnCount;
    const char*                 fingerprint; // chrome / firefox / safari / ios / android / edge / 360 / qq / random / randomizednoalpn / unsafe
    unsigned char               allowInsecure;

};



struct jsonListInboundStreamSettingsFinalMaskUdpRealmObjectStruct {
    const char*                 url; // always of the form realm://token@host:port/id
    const char**                stunServers; // array of stun server addresses
    int64_t                     stunServersCount;
    struct jsonListInboundStreamSettingsFinalMaskUdpRealmTlsConfigObjectStruct* listInStreamSettingsFinalMaskUdpRealmTlsConfigObjStruct; // optional, NULL when not present

};



struct jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomPacketObjectStruct {
    const char*                 type; // array / str / hex / base64
    int64_t                     rand; // only present when type is "array"
    const char*                 randRange; // only present when type is "array", e.g. "0-255"
    const char*                 packet; // only present when type is "str" / "hex" / "base64"

};



struct jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomObjectStruct {
    size_t                      jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomClientPacketStructSize;
    struct jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomPacketObjectStruct* listInStreamSettingsFinalMaskUdpHeaderCustomClientPacketStruct; // array
    size_t                      jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomServerPacketStructSize;
    struct jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomPacketObjectStruct* listInStreamSettingsFinalMaskUdpHeaderCustomServerPacketStruct; // array

};



struct jsonListInboundStreamSettingsFinalMaskUdpNoisePacketObjectStruct {
    const char*                 type; // array / str / hex / base64
    const char*                 delay; // e.g. "10-20"
    const char*                 rand; // only present when type is "array", e.g. "1-8192"
    const char*                 randRange; // only present when type is "array", e.g. "0-255"
    const char*                 packet; // only present when type is "str" / "hex" / "base64"

};



struct jsonListInboundStreamSettingsFinalMaskUdpNoiseObjectStruct {
    int64_t                     reset;
    size_t                      jsonListInboundStreamSettingsFinalMaskUdpNoisePacketStructSize;
    struct jsonListInboundStreamSettingsFinalMaskUdpNoisePacketObjectStruct* listInStreamSettingsFinalMaskUdpNoisePacketStruct; // array

};



struct jsonListInboundStreamSettingsFinalMaskUdpObjectStruct {
    const char*                 type; // mkcp-legacy / xdns / xicmp / realm / header-custom / noise
    struct jsonListInboundStreamSettingsFinalMaskUdpMkcpLegacyObjectStruct* listInStreamSettingsFinalMaskUdpMkcpLegacyObjStruct;
    struct jsonListInboundStreamSettingsFinalMaskUdpXdnsObjectStruct* listInStreamSettingsFinalMaskUdpXdnsObjStruct;
    struct jsonListInboundStreamSettingsFinalMaskUdpXicmpObjectStruct* listInStreamSettingsFinalMaskUdpXicmpObjStruct;
    struct jsonListInboundStreamSettingsFinalMaskUdpRealmObjectStruct* listInStreamSettingsFinalMaskUdpRealmObjStruct;
    struct jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomObjectStruct* listInStreamSettingsFinalMaskUdpHeaderCustomObjStruct;
    struct jsonListInboundStreamSettingsFinalMaskUdpNoiseObjectStruct* listInStreamSettingsFinalMaskUdpNoiseObjStruct;

};



struct jsonListInboundStreamSettingsMKcpFinalMaskObjectStruct {
    size_t                      jsonListInboundStreamSettingsFinalMaskUdpStructSize;
    struct jsonListInboundStreamSettingsFinalMaskUdpObjectStruct* listInStreamSettingsFinalMaskUdpStruct; // array

};



struct jsonListInboundStreamSettingsTcpFinalMaskFragmentObjectStruct {
    const char*                 packets; // e.g. "1-3"
    const char**                lengths; // array of length ranges, e.g. ["100-200"]
    int64_t                     lengthsCount;
    const char*                 maxSplit; // e.g. "10"
    const char**                delays; // array of delay ranges, e.g. ["10-20"]
    int64_t                     delaysCount;

};



struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomPacketObjectStruct {
    const char*                 type; // array / str / hex / base64
    const char*                 delay; // e.g. "10-20"
    const char*                 rand; // only present when type is "array", e.g. "1-8192"
    const char*                 randRange; // only present when type is "array", e.g. "0-255"
    const char*                 packet; // only present when type is "str" / "hex" / "base64"

};



struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomGroupObjectStruct {
    size_t                      jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomPacketStructSize;
    struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomPacketObjectStruct* listInStreamSettingsTcpFinalMaskHeaderCustomPacketStruct; // array

};



struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomObjectStruct {
    size_t                      jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomClientGroupStructSize;
    struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomGroupObjectStruct* listInStreamSettingsTcpFinalMaskHeaderCustomClientGroupStruct; // array of packet groups
    size_t                      jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomServerGroupStructSize;
    struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomGroupObjectStruct* listInStreamSettingsTcpFinalMaskHeaderCustomServerGroupStruct; // array of packet groups

};



struct jsonListInboundStreamSettingsTcpFinalMaskSudokuObjectStruct {
    const char*                 password;
    const char**                customTables; // array of custom table names
    int64_t                     customTablesCount;
    const char*                 ascii;
    const char*                 customTable;
    int64_t                     paddingMin;
    int64_t                     paddingMax;

};



struct jsonListInboundStreamSettingsTcpFinalMaskXmcProfileObjectStruct {
    const char*                 username;
    const char*                 uuid;
    const char*                 texturesValue;
    const char*                 texturesSignature;

};



struct jsonListInboundStreamSettingsTcpFinalMaskXmcObjectStruct {
    const char*                 hostname;
    int64_t                     jsonListInboundStreamSettingsTcpFinalMaskXmcProfileStructSize;
    struct jsonListInboundStreamSettingsTcpFinalMaskXmcProfileObjectStruct* listInStreamSettingsTcpFinalMaskXmcProfileStruct; // array
    const char*                 password;

};



struct jsonListInboundStreamSettingsTcpFinalMaskTcpObjectStruct {
    const char*                 type; // fragment / header-custom / sudoku / xmc
    struct jsonListInboundStreamSettingsTcpFinalMaskFragmentObjectStruct* listInStreamSettingsTcpFinalMaskFragmentObjStruct;
    struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomObjectStruct* listInStreamSettingsTcpFinalMaskHeaderCustomObjStruct;
    struct jsonListInboundStreamSettingsTcpFinalMaskSudokuObjectStruct* listInStreamSettingsTcpFinalMaskSudokuObjStruct;
    struct jsonListInboundStreamSettingsTcpFinalMaskXmcObjectStruct* listInStreamSettingsTcpFinalMaskXmcObjStruct;

};



struct jsonListInboundStreamSettingsTcpFinalMaskObjectStruct {
    size_t                      jsonListInboundStreamSettingsTcpFinalMaskTcpStructSize;
    struct jsonListInboundStreamSettingsTcpFinalMaskTcpObjectStruct* listInStreamSettingsTcpFinalMaskTcpStruct; // array

};



struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskFragmentObjectStruct {
    const char*                 packets; // e.g. "1-3"
    const char**                lengths; // array of length ranges, e.g. ["100-200"]
    int64_t                     lengthsCount;
    const char*                 maxSplit; // e.g. "10"
    const char**                delays; // array of delay ranges, e.g. ["10-20"]
    int64_t                     delaysCount;

};



struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskHeaderCustomPacketObjectStruct {
    const char*                 type; // array / str / hex / base64
    const char*                 delay; // e.g. "10-20"
    const char*                 rand; // only present when type is "array", e.g. "1-8192"
    const char*                 randRange; // only present when type is "array", e.g. "0-255"
    const char*                 packet; // only present when type is "str" / "hex" / "base64"

};



struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskHeaderCustomGroupObjectStruct {
    size_t                      jsonListInboundStreamSettingsHTTPUpgradeFinalMaskHeaderCustomPacketStructSize;
    struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskHeaderCustomPacketObjectStruct* listInStreamSettingsHTTPUpgradeFinalMaskHeaderCustomPacketStruct; // array

};



struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskHeaderCustomObjectStruct {
    size_t                      jsonListInboundStreamSettingsHTTPUpgradeFinalMaskHeaderCustomClientGroupStructSize;
    struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskHeaderCustomGroupObjectStruct* listInStreamSettingsHTTPUpgradeFinalMaskHeaderCustomClientGroupStruct; // array of packet groups
    size_t                      jsonListInboundStreamSettingsHTTPUpgradeFinalMaskHeaderCustomServerGroupStructSize;
    struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskHeaderCustomGroupObjectStruct* listInStreamSettingsHTTPUpgradeFinalMaskHeaderCustomServerGroupStruct; // array of packet groups

};



struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskSudokuObjectStruct {
    const char*                 password;
    const char**                customTables; // array of custom table names
    int64_t                     customTablesCount;
    const char*                 ascii;
    const char*                 customTable;
    int64_t                     paddingMin;
    int64_t                     paddingMax;

};



struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskXmcProfileObjectStruct {
    const char*                 username;
    const char*                 uuid;
    const char*                 texturesValue;
    const char*                 texturesSignature;

};



struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskXmcObjectStruct {
    const char*                 hostname;
    int64_t                     jsonListInboundStreamSettingsHTTPUpgradeFinalMaskXmcProfileStructSize;
    struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskXmcProfileObjectStruct* listInStreamSettingsHTTPUpgradeFinalMaskXmcProfileStruct; // array
    const char*                 password;

};



struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskTcpObjectStruct {
    const char*                 type; // fragment / header-custom / sudoku / xmc
    struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskFragmentObjectStruct* listInStreamSettingsHTTPUpgradeFinalMaskFragmentObjStruct;
    struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskHeaderCustomObjectStruct* listInStreamSettingsHTTPUpgradeFinalMaskHeaderCustomObjStruct;
    struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskSudokuObjectStruct* listInStreamSettingsHTTPUpgradeFinalMaskSudokuObjStruct;
    struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskXmcObjectStruct* listInStreamSettingsHTTPUpgradeFinalMaskXmcObjStruct;

};



struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskObjectStruct {
    size_t                      jsonListInboundStreamSettingsHTTPUpgradeFinalMaskTcpStructSize;
    struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskTcpObjectStruct* listInStreamSettingsHTTPUpgradeFinalMaskTcpStruct; // array

};


struct jsonListInboundStreamSettingsXHTTPFinalMaskFragmentObjectStruct {
    const char*                 packets; // e.g. "1-3"
    const char**                lengths; // array of length ranges, e.g. ["100-200"]
    int64_t                     lengthsCount;
    const char*                 maxSplit; // e.g. "10"
    const char**                delays; // array of delay ranges, e.g. ["10-20"]
    int64_t                     delaysCount;

};



struct jsonListInboundStreamSettingsXHTTPFinalMaskHeaderCustomPacketObjectStruct {
    const char*                 type; // array / str / hex / base64
    const char*                 delay; // e.g. "10-20"
    const char*                 rand; // only present when type is "array", e.g. "1-8192"
    const char*                 randRange; // only present when type is "array", e.g. "0-255"
    const char*                 packet; // only present when type is "str" / "hex" / "base64"

};



struct jsonListInboundStreamSettingsXHTTPFinalMaskHeaderCustomGroupObjectStruct {
    size_t                      jsonListInboundStreamSettingsXHTTPFinalMaskHeaderCustomPacketStructSize;
    struct jsonListInboundStreamSettingsXHTTPFinalMaskHeaderCustomPacketObjectStruct* listInStreamSettingsXHTTPFinalMaskHeaderCustomPacketStruct; // array

};



struct jsonListInboundStreamSettingsXHTTPFinalMaskHeaderCustomObjectStruct {
    size_t                      jsonListInboundStreamSettingsXHTTPFinalMaskHeaderCustomClientGroupStructSize;
    struct jsonListInboundStreamSettingsXHTTPFinalMaskHeaderCustomGroupObjectStruct* listInStreamSettingsXHTTPFinalMaskHeaderCustomClientGroupStruct; // array of packet groups
    size_t                      jsonListInboundStreamSettingsXHTTPFinalMaskHeaderCustomServerGroupStructSize;
    struct jsonListInboundStreamSettingsXHTTPFinalMaskHeaderCustomGroupObjectStruct* listInStreamSettingsXHTTPFinalMaskHeaderCustomServerGroupStruct; // array of packet groups

};



struct jsonListInboundStreamSettingsXHTTPFinalMaskSudokuObjectStruct {
    const char*                 password;
    const char**                customTables; // array of custom table names
    int64_t                     customTablesCount;
    const char*                 ascii;
    const char*                 customTable;
    int64_t                     paddingMin;
    int64_t                     paddingMax;

};



struct jsonListInboundStreamSettingsXHTTPFinalMaskXmcProfileObjectStruct {
    const char*                 username;
    const char*                 uuid;
    const char*                 texturesValue;
    const char*                 texturesSignature;

};



struct jsonListInboundStreamSettingsXHTTPFinalMaskXmcObjectStruct {
    const char*                 hostname;
    int64_t                     jsonListInboundStreamSettingsXHTTPFinalMaskXmcProfileStructSize;
    struct jsonListInboundStreamSettingsXHTTPFinalMaskXmcProfileObjectStruct* listInStreamSettingsXHTTPFinalMaskXmcProfileStruct; // array
    const char*                 password;

};



struct jsonListInboundStreamSettingsXHTTPFinalMaskTcpObjectStruct {
    const char*                 type; // fragment / header-custom / sudoku / xmc
    struct jsonListInboundStreamSettingsXHTTPFinalMaskFragmentObjectStruct* listInStreamSettingsXHTTPFinalMaskFragmentObjStruct;
    struct jsonListInboundStreamSettingsXHTTPFinalMaskHeaderCustomObjectStruct* listInStreamSettingsXHTTPFinalMaskHeaderCustomObjStruct;
    struct jsonListInboundStreamSettingsXHTTPFinalMaskSudokuObjectStruct* listInStreamSettingsXHTTPFinalMaskSudokuObjStruct;
    struct jsonListInboundStreamSettingsXHTTPFinalMaskXmcObjectStruct* listInStreamSettingsXHTTPFinalMaskXmcObjStruct;

};



struct jsonListInboundStreamSettingsXHTTPFinalMaskQuicParamsUdpHopObjectStruct {
    const char*                 ports; // e.g. "20000-50000"
    const char*                 interval; // e.g. "5-10"

};



struct jsonListInboundStreamSettingsXHTTPFinalMaskQuicParamsObjectStruct {
    const char*                 congestion; // reno / bbr / brutal / force-brutal
    unsigned char               debug;
    const char*                 brutalUp; // optional, NULL when the congestion is not brutal or force-brutal
    const char*                 brutalDown; // optional, NULL when the congestion is not brutal or force-brutal
    struct jsonListInboundStreamSettingsXHTTPFinalMaskQuicParamsUdpHopObjectStruct* listInStreamSettingsXHTTPFinalMaskQuicParamsUdpHopObjStruct; // optional, NULL when the udpHop field is not present
    int64_t                     initStreamReceiveWindow;
    int64_t                     maxStreamReceiveWindow;
    int64_t                     initConnectionReceiveWindow;
    int64_t                     maxConnectionReceiveWindow;
    int64_t                     maxIdleTimeout;
    int64_t                     keepAlivePeriod;
    unsigned char               disablePathMTUDiscovery;
    int64_t                     maxIncomingStreams;

};



struct jsonListInboundStreamSettingsXHTTPFinalMaskObjectStruct {
    size_t                      jsonListInboundStreamSettingsXHTTPFinalMaskTcpStructSize;
    struct jsonListInboundStreamSettingsXHTTPFinalMaskTcpObjectStruct* listInStreamSettingsXHTTPFinalMaskTcpStruct; // array
    struct jsonListInboundStreamSettingsXHTTPFinalMaskQuicParamsObjectStruct* listInStreamSettingsXHTTPFinalMaskQuicParamsObjStruct; // optional, NULL when the quicParams field is not present

};



struct jsonListInboundStreamSettingsGRPCFinalMaskFragmentObjectStruct {
    const char*                 packets; // e.g. "1-3"
    const char**                lengths; // array of length ranges, e.g. ["100-200"]
    int64_t                     lengthsCount;
    const char*                 maxSplit; // e.g. "10"
    const char**                delays; // array of delay ranges, e.g. ["10-20"]
    int64_t                     delaysCount;

};



struct jsonListInboundStreamSettingsGRPCFinalMaskHeaderCustomPacketObjectStruct {
    const char*                 type; // array / str / hex / base64
    const char*                 delay; // e.g. "10-20"
    const char*                 rand; // only present when type is "array", e.g. "1-8192"
    const char*                 randRange; // only present when type is "array", e.g. "0-255"
    const char*                 packet; // only present when type is "str" / "hex" / "base64"

};



struct jsonListInboundStreamSettingsGRPCFinalMaskHeaderCustomGroupObjectStruct {
    size_t                      jsonListInboundStreamSettingsGRPCFinalMaskHeaderCustomPacketStructSize;
    struct jsonListInboundStreamSettingsGRPCFinalMaskHeaderCustomPacketObjectStruct* listInStreamSettingsGRPCFinalMaskHeaderCustomPacketStruct; // array

};



struct jsonListInboundStreamSettingsGRPCFinalMaskHeaderCustomObjectStruct {
    size_t                      jsonListInboundStreamSettingsGRPCFinalMaskHeaderCustomClientGroupStructSize;
    struct jsonListInboundStreamSettingsGRPCFinalMaskHeaderCustomGroupObjectStruct* listInStreamSettingsGRPCFinalMaskHeaderCustomClientGroupStruct; // array of packet groups
    size_t                      jsonListInboundStreamSettingsGRPCFinalMaskHeaderCustomServerGroupStructSize;
    struct jsonListInboundStreamSettingsGRPCFinalMaskHeaderCustomGroupObjectStruct* listInStreamSettingsGRPCFinalMaskHeaderCustomServerGroupStruct; // array of packet groups

};



struct jsonListInboundStreamSettingsGRPCFinalMaskSudokuObjectStruct {
    const char*                 password;
    const char**                customTables; // array of custom table names
    int64_t                     customTablesCount;
    const char*                 ascii;
    const char*                 customTable;
    int64_t                     paddingMin;
    int64_t                     paddingMax;

};



struct jsonListInboundStreamSettingsGRPCFinalMaskXmcProfileObjectStruct {
    const char*                 username;
    const char*                 uuid;
    const char*                 texturesValue;
    const char*                 texturesSignature;

};



struct jsonListInboundStreamSettingsGRPCFinalMaskXmcObjectStruct {
    const char*                 hostname;
    int64_t                     jsonListInboundStreamSettingsGRPCFinalMaskXmcProfileStructSize;
    struct jsonListInboundStreamSettingsGRPCFinalMaskXmcProfileObjectStruct* listInStreamSettingsGRPCFinalMaskXmcProfileStruct; // array
    const char*                 password;

};



struct jsonListInboundStreamSettingsGRPCFinalMaskTcpObjectStruct {
    const char*                 type; // fragment / header-custom / sudoku / xmc
    struct jsonListInboundStreamSettingsGRPCFinalMaskFragmentObjectStruct* listInStreamSettingsGRPCFinalMaskFragmentObjStruct;
    struct jsonListInboundStreamSettingsGRPCFinalMaskHeaderCustomObjectStruct* listInStreamSettingsGRPCFinalMaskHeaderCustomObjStruct;
    struct jsonListInboundStreamSettingsGRPCFinalMaskSudokuObjectStruct* listInStreamSettingsGRPCFinalMaskSudokuObjStruct;
    struct jsonListInboundStreamSettingsGRPCFinalMaskXmcObjectStruct* listInStreamSettingsGRPCFinalMaskXmcObjStruct;

};



struct jsonListInboundStreamSettingsGRPCFinalMaskObjectStruct {
    size_t                      jsonListInboundStreamSettingsGRPCFinalMaskTcpStructSize;
    struct jsonListInboundStreamSettingsGRPCFinalMaskTcpObjectStruct* listInStreamSettingsGRPCFinalMaskTcpStruct; // array

};



struct jsonListInboundStreamSettingsWSFinalMaskFragmentObjectStruct {
    const char*                 packets; // e.g. "1-3"
    const char**                lengths; // array of length ranges, e.g. ["100-200"]
    int64_t                     lengthsCount;
    const char*                 maxSplit; // e.g. "10"
    const char**                delays; // array of delay ranges, e.g. ["10-20"]
    int64_t                     delaysCount;

};



struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomPacketObjectStruct {
    const char*                 type; // array / str / hex / base64
    const char*                 delay; // e.g. "10-20"
    const char*                 rand; // only present when type is "array", e.g. "1-8192"
    const char*                 randRange; // only present when type is "array", e.g. "0-255"
    const char*                 packet; // only present when type is "str" / "hex" / "base64"

};



struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomGroupObjectStruct {
    size_t                      jsonListInboundStreamSettingsWSFinalMaskHeaderCustomPacketStructSize;
    struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomPacketObjectStruct* listInStreamSettingsWSFinalMaskHeaderCustomPacketStruct; // array

};



struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomObjectStruct {
    size_t                      jsonListInboundStreamSettingsWSFinalMaskHeaderCustomClientGroupStructSize;
    struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomGroupObjectStruct* listInStreamSettingsWSFinalMaskHeaderCustomClientGroupStruct; // array of packet groups
    size_t                      jsonListInboundStreamSettingsWSFinalMaskHeaderCustomServerGroupStructSize;
    struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomGroupObjectStruct* listInStreamSettingsWSFinalMaskHeaderCustomServerGroupStruct; // array of packet groups

};



struct jsonListInboundStreamSettingsWSFinalMaskSudokuObjectStruct {
    const char*                 password;
    const char**                customTables; // array of custom table names
    int64_t                     customTablesCount;
    const char*                 ascii;
    const char*                 customTable;
    int64_t                     paddingMin;
    int64_t                     paddingMax;

};



struct jsonListInboundStreamSettingsWSFinalMaskXmcProfileObjectStruct {
    const char*                 username;
    const char*                 uuid;
    const char*                 texturesValue;
    const char*                 texturesSignature;

};



struct jsonListInboundStreamSettingsWSFinalMaskXmcObjectStruct {
    const char*                 hostname;
    int64_t                     jsonListInboundStreamSettingsWSFinalMaskXmcProfileStructSize;
    struct jsonListInboundStreamSettingsWSFinalMaskXmcProfileObjectStruct* listInStreamSettingsWSFinalMaskXmcProfileStruct; // array
    const char*                 password;

};



struct jsonListInboundStreamSettingsWSFinalMaskTcpObjectStruct {
    const char*                 type; // fragment / header-custom / sudoku / xmc
    struct jsonListInboundStreamSettingsWSFinalMaskFragmentObjectStruct* listInStreamSettingsWSFinalMaskFragmentObjStruct;
    struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomObjectStruct* listInStreamSettingsWSFinalMaskHeaderCustomObjStruct;
    struct jsonListInboundStreamSettingsWSFinalMaskSudokuObjectStruct* listInStreamSettingsWSFinalMaskSudokuObjStruct;
    struct jsonListInboundStreamSettingsWSFinalMaskXmcObjectStruct* listInStreamSettingsWSFinalMaskXmcObjStruct;

};



struct jsonListInboundStreamSettingsWSFinalMaskObjectStruct {
    size_t                      jsonListInboundStreamSettingsWSFinalMaskTcpStructSize;
    struct jsonListInboundStreamSettingsWSFinalMaskTcpObjectStruct* listInStreamSettingsWSFinalMaskTcpStruct; // array

};



struct jsonListInboundStreamSettingsTcpSockoptObjectCustomSockOptArrayStruct {
    const char* system;
    const char* type;
    const char* level;
    const char* opt;
    const char* value;

};



struct jsonListInboundStreamSettingsTcpSockoptObjectStruct {
    unsigned char acceptProxyProtocolEnabled;
    unsigned char acceptProxyProtocol;
    unsigned char tcpFastOpenEnabled;
    unsigned char tcpFastOpen;
    unsigned char tproxyEnabled;
    const char* tproxy;
    unsigned char penetrateEnabled;
    unsigned char penetrate;
    unsigned char tcpcongestionEnabled;
    const char* tcpcongestion;
    unsigned char V6OnlyEnabled;
    unsigned char V6Only;
    unsigned char listInStreamSettingsTcpSockoptObjCustomScokArrStructEnabled;
    size_t                      jsonListInboundStreamSettingsTcpSockoptCustomSockOptArrayStructSize; // array length, 0 when the array is not present
    struct jsonListInboundStreamSettingsTcpSockoptObjectCustomSockOptArrayStruct* listInStreamSettingsTcpSockoptObjCustomScokArrStruct; // array

};




struct jsonListInboundStreamSettingsWSSockoptObjectCustomSockOptArrayStruct {
    const char* system;
    const char* type;
    const char* level;
    const char* opt;
    const char* value;

};



struct jsonListInboundStreamSettingsWSSockoptObjectStruct {
    unsigned char acceptProxyProtocolEnabled;
    unsigned char acceptProxyProtocol;
    unsigned char tcpFastOpenEnabled;
    unsigned char tcpFastOpen;
    unsigned char tproxyEnabled;
    const char* tproxy;
    unsigned char penetrateEnabled;
    unsigned char penetrate;
    unsigned char tcpcongestionEnabled;
    const char* tcpcongestion;
    unsigned char V6OnlyEnabled;
    unsigned char V6Only;
    unsigned char listInStreamSettingsWSSockoptObjCustomScokArrStructEnabled;
    size_t                      jsonListInboundStreamSettingsWSSockoptCustomSockOptArrayStructSize; // array length, 0 when the array is not present
    struct jsonListInboundStreamSettingsWSSockoptObjectCustomSockOptArrayStruct* listInStreamSettingsWSSockoptObjCustomScokArrStruct; // array

    const char**                trustedXForwardedFor;
    int64_t                     trustedXForwardedForCount;

};



struct jsonListInboundStreamSettingsGRPCSockoptObjectCustomSockOptArrayStruct {
    const char* system;
    const char* type;
    const char* level;
    const char* opt;
    const char* value;

};



struct jsonListInboundStreamSettingsGRPCSockoptObjectStruct {
    unsigned char acceptProxyProtocolEnabled;
    unsigned char acceptProxyProtocol;
    unsigned char tcpFastOpenEnabled;
    unsigned char tcpFastOpen;
    unsigned char markEnabled;
    int64_t      mark;
    unsigned char tproxyEnabled;
    const char* tproxy;
    unsigned char penetrateEnabled;
    unsigned char penetrate;
    unsigned char tcpMaxSegEnabled;
    int64_t      tcpMaxSeg;
    unsigned char tcpKeepAliveIntervalEnabled;
    int64_t      tcpKeepAliveInterval;
    unsigned char tcpKeepAliveIdleEnabled;
    int64_t      tcpKeepAliveIdle;
    unsigned char tcpUserTimeoutEnabled;
    int64_t      tcpUserTimeout;
    unsigned char tcpcongestionEnabled;
    const char* tcpcongestion;
    unsigned char V6OnlyEnabled;
    unsigned char V6Only;
    unsigned char tcpWindowClampEnabled;
    int64_t      tcpWindowClamp;
    unsigned char listInStreamSettingsGRPCSockoptObjCustomScokArrStructEnabled;
    size_t                      jsonListInboundStreamSettingsGRPCSockoptCustomSockOptArrayStructSize; // array length, 0 when the array is not present
    struct jsonListInboundStreamSettingsGRPCSockoptObjectCustomSockOptArrayStruct* listInStreamSettingsGRPCSockoptObjCustomScokArrStruct; // array

    const char**                trustedXForwardedFor;
    int64_t                     trustedXForwardedForCount;

};



struct jsonListInboundStreamSettingsHTTPUpgradeSockoptObjectCustomSockOptArrayStruct {
    const char* system;
    const char* type;
    const char* level;
    const char* opt;
    const char* value;

};



struct jsonListInboundStreamSettingsHTTPUpgradeSockoptObjectStruct {
    unsigned char acceptProxyProtocolEnabled;
    unsigned char acceptProxyProtocol;
    unsigned char tcpFastOpenEnabled;
    unsigned char tcpFastOpen;
    unsigned char markEnabled;
    int64_t      mark;
    unsigned char tproxyEnabled;
    const char* tproxy;
    unsigned char penetrateEnabled;
    unsigned char penetrate;
    unsigned char tcpMaxSegEnabled;
    int64_t      tcpMaxSeg;
    unsigned char tcpKeepAliveIntervalEnabled;
    int64_t      tcpKeepAliveInterval;
    unsigned char tcpKeepAliveIdleEnabled;
    int64_t      tcpKeepAliveIdle;
    unsigned char tcpUserTimeoutEnabled;
    int64_t      tcpUserTimeout;
    unsigned char tcpcongestionEnabled;
    const char* tcpcongestion;
    unsigned char V6OnlyEnabled;
    unsigned char V6Only;
    unsigned char tcpWindowClampEnabled;
    int64_t      tcpWindowClamp;
    unsigned char listInStreamSettingsHTTPUpgradeSockoptObjCustomScokArrStructEnabled;
    size_t                      jsonListInboundStreamSettingsHTTPUpgradeSockoptCustomSockOptArrayStructSize; // array length, 0 when the array is not present
    struct jsonListInboundStreamSettingsHTTPUpgradeSockoptObjectCustomSockOptArrayStruct* listInStreamSettingsHTTPUpgradeSockoptObjCustomScokArrStruct; // array

    const char**                trustedXForwardedFor;
    int64_t                     trustedXForwardedForCount;

};


struct jsonListInboundStreamSettingsXHTTPSockoptObjectCustomSockOptArrayStruct {
    const char* system;
    const char* type;
    const char* level;
    const char* opt;
    const char* value;

};



struct jsonListInboundStreamSettingsXHTTPSockoptObjectStruct {
    unsigned char acceptProxyProtocolEnabled;
    unsigned char acceptProxyProtocol;
    unsigned char tcpFastOpenEnabled;
    unsigned char tcpFastOpen;
    unsigned char markEnabled;
    int64_t      mark;
    unsigned char tproxyEnabled;
    const char* tproxy;
    unsigned char penetrateEnabled;
    unsigned char penetrate;
    unsigned char tcpMaxSegEnabled;
    int64_t      tcpMaxSeg;
    unsigned char tcpKeepAliveIntervalEnabled;
    int64_t      tcpKeepAliveInterval;
    unsigned char tcpKeepAliveIdleEnabled;
    int64_t      tcpKeepAliveIdle;
    unsigned char tcpUserTimeoutEnabled;
    int64_t      tcpUserTimeout;
    unsigned char tcpcongestionEnabled;
    const char* tcpcongestion;
    unsigned char V6OnlyEnabled;
    unsigned char V6Only;
    unsigned char tcpWindowClampEnabled;
    int64_t      tcpWindowClamp;
    unsigned char listInStreamSettingsXHTTPSockoptObjCustomScokArrStructEnabled;
    size_t                      jsonListInboundStreamSettingsXHTTPSockoptCustomSockOptArrayStructSize; // array length, 0 when the array is not present
    struct jsonListInboundStreamSettingsXHTTPSockoptObjectCustomSockOptArrayStruct* listInStreamSettingsXHTTPSockoptObjCustomScokArrStruct; // array

    const char**                trustedXForwardedFor;
    int64_t                     trustedXForwardedForCount;

};



struct jsonListInboundStreamSettingsMKcpSockoptObjectCustomSockOptArrayStruct {
    const char* system;
    const char* type;
    const char* level;
    const char* opt;
    const char* value;

};



struct jsonListInboundStreamSettingsMKcpSockoptObjectStruct {
    unsigned char tcpFastOpenEnabled;
    unsigned char tcpFastOpen;
    unsigned char tproxyEnabled;
    const char* tproxy;
    unsigned char penetrateEnabled;
    unsigned char penetrate;
    unsigned char tcpcongestionEnabled;
    const char* tcpcongestion;
    unsigned char V6OnlyEnabled;
    unsigned char V6Only;
    unsigned char listInStreamSettingsMKcpSockoptObjCustomScokArrStructEnabled;
    size_t                      jsonListInboundStreamSettingsMKcpSockoptCustomSockOptArrayStructSize; // array length, 0 when the array is not present
    struct jsonListInboundStreamSettingsMKcpSockoptObjectCustomSockOptArrayStruct* listInStreamSettingsMKcpSockoptObjCustomScokArrStruct; // array

};



struct jsonListInboundStreamSettingsTlsSettingsCertificateObjectStruct {
    const char*                 certificateFile;
    const char*                 keyFile;
    int64_t                     certificateCount;
    const char**                certificate; // array
    int64_t                     keyCount;
    const char**                key; // array
    int64_t                     ocspStapling;
    unsigned char               oneTimeLoading;
    const char*                 usage;
    unsigned char               buildChain;

};



struct jsonListInboundStreamSettingsTlsSettingsEchSockoptObjectStruct {
    unsigned char               tcpFastOpen;
    unsigned char               tcpMptcp;
    const char*                 domainStrategy;
    const char*                 dialerProxy;
    const char*                 tcpcongestion;

};



struct jsonListInboundStreamSettingsTlsSettingsSettingsObjectStruct {
    const char*                 fingerprint;
    const char*                 echConfigList;
    int64_t                     pinnedPeerCertSha256Count;
    const char**                pinnedPeerCertSha256; // array
    const char*                 verifyPeerCertByName;

};



struct jsonListInboundStreamSettingsTlsSettingsObjectStruct {
    const char*                 serverName;
    const char*                 minVersion;
    const char*                 maxVersion;
    const char*                 cipherSuites;
    unsigned char               rejectUnknownSni;
    unsigned char               disableSystemRoot;
    unsigned char               enableSessionResumption;
    size_t                      jsonListInboundStreamSettingsTlsSettingsCertificateArrStructSize;
    struct jsonListInboundStreamSettingsTlsSettingsCertificateObjectStruct* listInStreamSettingsTlsSettingsCertificateArrStruct; // array
    int64_t                     alpnCount;
    const char**                alpn; // array
    const char*                 echServerKeys;
    int64_t                     curvePreferencesCount;
    const char**                curvePreferences; // array
    const char*                 masterKeyLog;
    struct jsonListInboundStreamSettingsTlsSettingsEchSockoptObjectStruct* listInStreamSettingsTlsSettingsEchSockoptObjStruct;
    struct jsonListInboundStreamSettingsTlsSettingsSettingsObjectStruct* listInStreamSettingsTlsSettingsSettingsObjStruct;

};



struct jsonListInboundStreamSettingsRealitySettingsLimitFallbackObjectStruct {
    int64_t                     afterBytes;
    int64_t                     bytesPerSec;
    int64_t                     burstBytesPerSec;

};



struct jsonListInboundStreamSettingsRealitySettingsSettingsObjectStruct {
    const char*                 publicKey;
    const char*                 fingerprint;
    const char*                 serverName;
    const char*                 spiderX;
    const char*                 mldsa65Verify;

};



struct jsonListInboundStreamSettingsRealitySettingsObjectStruct {
    unsigned char               show;
    int64_t                     xver;
    const char*                 target;
    int64_t                     serverNamesCount;
    const char**                serverNames; // array
    const char*                 privateKey;
    const char*                 minClientVer;
    const char*                 maxClientVer;
    int64_t                     maxTimediff;
    int64_t                     shortIdsCount;
    const char**                shortIds; // array
    const char*                 mldsa65Seed;
    const char*                 masterKeyLog;
    struct jsonListInboundStreamSettingsRealitySettingsLimitFallbackObjectStruct* listInStreamSettingsRealitySettingsLimitFallbackUploadObjStruct;
    struct jsonListInboundStreamSettingsRealitySettingsLimitFallbackObjectStruct* listInStreamSettingsRealitySettingsLimitFallbackDownloadObjStruct;
    struct jsonListInboundStreamSettingsRealitySettingsSettingsObjectStruct* listInStreamSettingsRealitySettingsSettingsObjStruct;

};



struct jsonListInboundStreamSettingsObjectStruct {
    const char*                 network;
    struct jsonListInboundStreamSettingsTcpSettingsObjectStruct* listInStreamSettingsTcpSettingsObjStruct;
    struct jsonListInboundStreamSettingsMKcpSettingsObjectStruct* listInStreamSettingsMKcpSettingsObjStruct;
    struct jsonListInboundStreamSettingsWSSettingsObjectStruct* listInStreamSettingsWSSettingsObjStruct;
    struct jsonListInboundStreamSettingsGRPCSettingsObjectStruct* listInStreamSettingsGRPCSettingsObjStruct;
    struct jsonListInboundStreamSettingsHTTPUpgradeSettingsObjectStruct* listInStreamSettingsHTTPUpgradeSettingsObjStruct;
    struct jsonListInboundStreamSettingsXHTTPSettingsObjectStruct* listInStreamSettingsXHTTPSettingsObjStruct;
    const char*                 security; // for kcp: currently "none", TODO: different security values may carry extra settings, handle them at the settings field
    struct jsonListInboundStreamSettingsTcpFinalMaskObjectStruct* listInStreamSettingsTcpFinalMaskObjStruct; // optional, NULL when the finalmask field is not present
    struct jsonListInboundStreamSettingsMKcpFinalMaskObjectStruct* listInStreamSettingsMKcpFinalMaskObjStruct;
    struct jsonListInboundStreamSettingsWSFinalMaskObjectStruct* listInStreamSettingsWSFinalMaskObjStruct;
    struct jsonListInboundStreamSettingsGRPCFinalMaskObjectStruct* listInStreamSettingsGRPCFinalMaskObjStruct;
    struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskObjectStruct* listInStreamSettingsHTTPUpgradeFinalMaskObjStruct;
    struct jsonListInboundStreamSettingsXHTTPFinalMaskObjectStruct* listInStreamSettingsXHTTPFinalMaskObjStruct;

    struct jsonListInboundStreamSettingsTcpSockoptObjectStruct* listInStreamSettingsTcpSockoptObjStruct;
    struct jsonListInboundStreamSettingsMKcpSockoptObjectStruct* listInStreamSettingsMKcpSockoptObjStruct;
    struct jsonListInboundStreamSettingsWSSockoptObjectStruct* listInStreamSettingsWSSockoptObjStruct;
    struct jsonListInboundStreamSettingsGRPCSockoptObjectStruct* listInStreamSettingsGRPCSockoptObjStruct;
    struct jsonListInboundStreamSettingsHTTPUpgradeSockoptObjectStruct* listInStreamSettingsHTTPUpgradeSockoptObjStruct;
    struct jsonListInboundStreamSettingsXHTTPSockoptObjectStruct* listInStreamSettingsXHTTPSockoptObjStruct;

    struct jsonListInboundStreamSettingsTlsSettingsObjectStruct* listInStreamSettingsTlsSettingsObjStruct; // optional, NULL when the tlsSettings field is not present
    struct jsonListInboundStreamSettingsRealitySettingsObjectStruct* listInStreamSettingsRealitySettingsObjStruct; // optional, NULL when the realitySettings field is not present

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
    size_t                      jsonListInboundClientStatsArrayStructSize; 
    struct jsonListInboundClientStatsArrayStruct* listInCliStatsStruct; // array
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
    size_t                      jsonListInboundObjectStructSize;
    struct jsonListInboundObjectStruct* listInObjStruct; // array
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
    size_t                      jsonListInboundSettingsClientsArraySlimStructSize;
    struct jsonListInboundSettingsClientsArraySlimStruct* listInSettingsCliArrSlimStruct; // array
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
    size_t                      jsonListInboundClientStatsArrayStructSize;
    struct jsonListInboundClientStatsArrayStruct* listInCliStatsStruct; // array
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
    size_t                      jsonListInboundObjectSlimStructSize;
    struct jsonListInboundObjectSlimStruct* listInObjSlimStruct; // array

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
    size_t                      jsonListInboundObjectOptionsArrayStructSize;
    struct jsonListInboundObjectOptionsArrayStruct* listInObjOptionsArrStruct; // array

};


// =====================================================
// Adding an inbound post and response structs
// =====================================================

struct jsonAddInboundSettingsClientsArrayPostStruct {
    const char*                 id;
    const char*                 email;

};



struct jsonAddInboundSettingsFallbacksArrayPostStruct {
    const char*                 alpn;
    int64_t                     childId;
    const char*                 dest;
    int64_t                     id;
    int64_t                     masterId;
    const char*                 name;
    const char*                 path;
    int                         sortOrder;
    int                         xver;

};



struct jsonAddInboundSettingsObjPostStruct {
    size_t                      jsonAddInboundSettingsClientsArrayPostStructSize;
    struct jsonAddInboundSettingsClientsArrayPostStruct* addInSettingsCliArrPStruct; // array
    const char*                 decryption;
    size_t                      jsonAddInboundSettingsFallbacksArrayPostStructSize;
    struct jsonAddInboundSettingsFallbacksArrayPostStruct* addInSettingsFalbackArrPStruct; // array

};



struct jsonAddInboundStreamSettingsRealitySettingsObjectPostStruct {
    unsigned char               show;
    const char*                 dest;

};



struct jsonAddInboundStreamSettingsObjPostStruct {
    const char*                 network;
    const char*                 security;
    struct jsonAddInboundStreamSettingsRealitySettingsObjectPostStruct* addInStreamSettignsRealitySettingsObjPStruct;

};



struct jsonAddInboundSniffingObjectDestOverrideArrStruct {
    const char*                 destOverride;

};



struct jsonAddInboundSniffingObjectPostStruct {
    unsigned char               enabled;
    size_t                      jsonAddInboundSniffingObjectDestOverrideArrStructSize;
    struct jsonAddInboundSniffingObjectDestOverrideArrStruct* addInSniffingObjDestOverrideArrStruct; // array

};



struct jsonAddInboundResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on success

};


// =====================================================
// Deleting an inbound by id post and response structs
// =====================================================

struct jsonDeleteSingleInboundPostStruct {
    int64_t                     id;

};



struct jsonDeleteSingleInboundResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on success

};



struct jsonDeleteMultipleInboundsPostStruct {
    size_t                      idsCount;
    int64_t*                    ids; // array

};



struct jsonDeleteMultipleInboundResponseSkippedArrayStruct {
    int64_t                     id;
    const char*                 reason;

};



struct jsonDeleteMultipleInboundResponseStruct {
    unsigned char               success;
    const char*                 msg;
    int64_t                     obj; // the number of successfully deleted inbounds
    size_t                      jsonDeleteMultipleInboundResponseSkippedArrayStructSize;
    struct jsonDeleteMultipleInboundResponseSkippedArrayStruct* deleteMultiInResSkippedArrStruct; // array

};


// =====================================================
// Since the functionality of the panel's update path is
// unknown with due regard to the api documentation, this
// part is skipped for now
// =====================================================
/*
 *
 *
 *
 *
 * */

// =====================================================
// Toggle the enale flag of an inbound post and response structs ( Toggle only the
// enable flag without serialising the whole settings
// json )
// =====================================================

struct jsonSetEnableInboundResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on success

};


// =====================================================
// Reset upload and download counters for a single
// inbound post and response structs ( this does not
// touch the per-client counters )
// =====================================================

struct jsonResetInboundResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on success

};


// =====================================================
// Remove every client attached to a single inbound post
// and response structs
// =====================================================

struct jsonRemoveEveryClientFromInboundResponseObjectStruct {
    int                         deleted;

};



struct jsonRemoveEveryClientFromInboundResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonRemoveEveryClientFromInboundResponseObjectStruct* rmEveryCliFromInResObjStruct;

};


// =====================================================
// Reset upload and download of all inbounds response
// struct
// =====================================================

struct jsonResetAllInboundsUploadNDownloadStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on success

};


// =====================================================
// Import json-structured inbound(s) post and response
// structs
// The content shall be sent as follows, else it will not work:
// curl -X POST "http://127.0.0.1:25175/000000000000000/panel/api/inbounds/import"
// -H "Authorization: Bearer exampleBearerToken" \  --data-urlencode "data=$(jq -c . <<< '{
//  "id": 1,
//  "userId": 0,
//  "up": 0,
//  "down": 0,
//  "total": 0,
//  "remark": "exampleRemark",
//  "enable": true,
//  "expiryTime": 1787776200000,
//  "trafficReset": "never",
//  "trafficResetDay": 1,
//  "lastTrafficResetTime": 0,
//  "listen": "",
//  "port": 46682,
//  "protocol": "vless",
//  "settings": {
//    "clients": [],
//    "decryption": "none",
//    "encryption": "none"
//  },
//  "streamSettings": {
//    "network": "tcp",
//    "tcpSettings": {
//      "acceptProxyProtocol": false,
//      "header": {
//        "type": "none"
//      }
//    },
//    "security": "none"
//  },
//  "tag": "in-46682-tcp",
//  "sniffing": {
//    "enabled": false
//  },
//  "clientStats": [],
//  "nodeId": null,
//  "shareAddrStrategy": "listen",
//  "shareAddr": "",
//  "subSortIndex": 1,
//  "originNodeGuid": "",
//  "fallbackParent": null
//}
// =====================================================

struct jsonImportInboundsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      jsonListInboundObjectStructSize;
    struct jsonListInboundObjectStruct* listInObjStruct; // array

};



// =====================================================
// Export every protocol URL across all inbounds and all
// of their clients. obj is a plain array of link strings
// =====================================================

struct jsonListInboundAllLinksStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      listInAllLinksCount;
    const char**                listInAllLinksArrStruct; // array; every pointer presented is an element of the array

};



// =====================================================
// Fetch a single inbound by id. obj is a single inbound
// object using the same shape as an element of the /list
// response
// =====================================================

struct jsonGetInboundResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonListInboundObjectStruct* getInboundObjStruct;

};



// =====================================================
// Replace an inbound's configuration. The body shape
// mirrors /add, but the stored client list and enable
// flag are kept ( settings.clients and enable in the
// body are ignored )
// =====================================================

struct jsonUpdateInboundPostStruct {
    unsigned char               enable;
    const char*                 remark;
    const char*                 listen;
    int                         port;
    const char*                 protocol;
    int64_t                     expiryTime;
    const char*                 total;
    struct jsonAddInboundSettingsObjPostStruct* addInSettingsObjPStruct;
    struct jsonAddInboundStreamSettingsObjPostStruct* addInStreamSettingsObjPStruct;
    struct jsonAddInboundSniffingObjectPostStruct* addInSniffingObjPStruct;

};



struct jsonUpdateInboundResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on success

};



// =====================================================
// Set only the subscription sort order of an inbound post
// and response structs ( reads the stored inbound so a
// reorder cannot carry a stale client list over a
// concurrent edit )
// =====================================================

struct jsonSetInboundSubSortIndexPostStruct {
    int64_t                     id;
    int                         subSortIndex;

};



struct jsonSetInboundSubSortIndexResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on success

};



// =====================================================
// Receive a master panel's aggregated per-client usage,
// keyed by the master's GUID ( only email/up/down are
// read from each row )
// =====================================================

struct jsonPushClientTrafficsArrayStruct {
    const char*                 email;
    int64_t                     up;
    int64_t                     down;

};



struct jsonPushClientTrafficsPostStruct {
    const char*                 masterGuid;
    size_t                      jsonPushClientTrafficsArrayStructSize;
    struct jsonPushClientTrafficsArrayStruct* pushClientTrafficsArrStruct; // array

};



struct jsonPushClientTrafficsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on success

};



// =====================================================
// List the fallback rules attached to a master inbound
// =====================================================

struct jsonListInboundFallbacksArrayStruct {
    int64_t                     id;
    int64_t                     masterId;
    int64_t                     childId;
    const char*                 name;
    const char*                 alpn;
    const char*                 path;
    const char*                 dest;
    int                         xver;
    int                         sortOrder;

};



struct jsonListInboundFallbacksStruct {
    unsigned char               success;
    const char*                 msg;
    size_t                      jsonListInboundFallbacksArrayStructSize;
    struct jsonListInboundFallbacksArrayStruct* listInFallbacksArrStruct; // array

};



// =====================================================
// Replace the entire fallback list for a master inbound
// post and response structs
// =====================================================

struct jsonSetInboundFallbacksArrayPostStruct {
    unsigned char               childIdEnabled;
    int64_t                     childId;
    const char*                 name;
    const char*                 alpn;
    const char*                 path;
    const char*                 dest;
    unsigned char               xverEnabled;
    int                         xver;
    unsigned char               sortOrderEnabled;
    int                         sortOrder;

};



struct jsonSetInboundFallbacksPostStruct {
    int64_t                     id;
    size_t                      jsonSetInboundFallbacksArrayPostStructSize;
    struct jsonSetInboundFallbacksArrayPostStruct* setInboundFallbacksArrPStruct; // array

};



struct jsonSetInboundFallbacksResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on success

};



// =====================================================
// Parser / serializer declarations for the top-level
// structs above. Structs nested inside a parent ( a
// pointer declared in the parent's body ) have no
// declaration of their own: the parent's parser handles
// them. Post structs serialize to JSON; everything else
// parses from JSON
// =====================================================

void        jsonListInboundClientStatsArrayStructDelete(struct jsonListInboundClientStatsArrayStruct* listInCliStatsStruct, size_t arraySize);

void        jsonListInboundSettingsClientsArrayStructDelete(struct jsonListInboundSettingsClientsArrayStruct* listInSettingsCliArrStruct, size_t arraySize);

void        jsonListInboundSettingsObjectStructDelete(struct jsonListInboundSettingsObjectStruct* listInSettingsObjStruct);

void        jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectStructDelete(struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectStruct* listInStreamSettingsTcpSettingsObjHeaderObjStruct);

void        jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersArrayStructDelete(struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectHeadersStruct* listInStreamSettingsTcpSettingsObjHeaderObjHeadersStruct, size_t arraySize);

void        jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectRequestObjectStructDelete(struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectRequestObjectStruct* listInStreamSettingsTcpSettingsObjHeaderObjReqObjStruct);

void        jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectResponseObjectStructDelete(struct jsonListInboundStreamSettingsTcpSettingsObjectHeaderObjectResponseObjectStruct* listInStreamSettingsTcpSettingsObjHeaderObjResObjStruct);

void        jsonListInboundStreamSettingsTcpSettingsObjectStructDelete(struct jsonListInboundStreamSettingsTcpSettingsObjectStruct* listInStreamSettingsTcpSettingsObjStruct);

void        jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectStructDelete(struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectStruct* listInStreamSettingsWSSettingsObjHeaderObjStruct);

void        jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersArrayStructDelete(struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectHeadersStruct* listInStreamSettingsWSSettingsObjHeaderObjHeadersStruct, size_t arraySize);

void        jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectRequestObjectStructDelete(struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectRequestObjectStruct* listInStreamSettingsWSSettingsObjHeaderObjReqObjStruct);

void        jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectResponseObjectStructDelete(struct jsonListInboundStreamSettingsWSSettingsObjectHeaderObjectResponseObjectStruct* listInStreamSettingsWSSettingsObjHeaderObjResObjStruct);

void        jsonListInboundStreamSettingsWSSettingsObjectStructDelete(struct jsonListInboundStreamSettingsWSSettingsObjectStruct* listInStreamSettingsWSSettingsObjStruct);

void        jsonListInboundStreamSettingsMKcpSettingsObjectStructDelete(struct jsonListInboundStreamSettingsMKcpSettingsObjectStruct* listInStreamSettingsMKcpSettingsObjStruct);

void        jsonListInboundStreamSettingsHTTPUpgradeSettingsObjectHeadersArrayStructDelete(struct jsonListInboundStreamSettingsHTTPUpgradeSettingsObjectHeadersStruct* listInStreamSettingsHTTPUpgradeSettingsObjHeadersStruct, size_t arraySize);

void        jsonListInboundStreamSettingsHTTPUpgradeSettingsObjectStructDelete(struct jsonListInboundStreamSettingsHTTPUpgradeSettingsObjectStruct* listInStreamSettingsHTTPUpgradeSettingsObjStruct);

void        jsonListInboundStreamSettingsXHTTPSettingsObjectHeadersArrayStructDelete(struct jsonListInboundStreamSettingsXHTTPSettingsObjectHeadersStruct* listInStreamSettingsXHTTPSettingsObjHeadersStruct, size_t arraySize);

void        jsonListInboundStreamSettingsXHTTPXMuxObjectStructDelete(struct jsonListInboundStreamSettingsXHTTPSettingsObjectXMuxObjectStruct* listInStreamSettingsXHTTPXMuxObjStruct);

void        jsonListInboundStreamSettingsXHTTPSettingsObjectStructDelete(struct jsonListInboundStreamSettingsXHTTPSettingsObjectStruct* listInStreamSettingsXHTTPSettingsObjStruct);

void        jsonListInboundStreamSettingsFinalMaskUdpMkcpLegacyObjectStructDelete(struct jsonListInboundStreamSettingsFinalMaskUdpMkcpLegacyObjectStruct* listInStreamSettingsFinalMaskUdpMkcpLegacyObjStruct);

void        jsonListInboundStreamSettingsFinalMaskUdpXdnsObjectStructDelete(struct jsonListInboundStreamSettingsFinalMaskUdpXdnsObjectStruct* listInStreamSettingsFinalMaskUdpXdnsObjStruct);

void        jsonListInboundStreamSettingsFinalMaskUdpXicmpObjectStructDelete(struct jsonListInboundStreamSettingsFinalMaskUdpXicmpObjectStruct* listInStreamSettingsFinalMaskUdpXicmpObjStruct);

void        jsonListInboundStreamSettingsFinalMaskUdpRealmTlsConfigObjectStructDelete(struct jsonListInboundStreamSettingsFinalMaskUdpRealmTlsConfigObjectStruct* listInStreamSettingsFinalMaskUdpRealmTlsConfigObjStruct);

void        jsonListInboundStreamSettingsFinalMaskUdpRealmObjectStructDelete(struct jsonListInboundStreamSettingsFinalMaskUdpRealmObjectStruct* listInStreamSettingsFinalMaskUdpRealmObjStruct);

void        jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomPacketObjectStructDelete(struct jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomPacketObjectStruct* listInStreamSettingsFinalMaskUdpHeaderCustomPacketObjStruct, size_t arraySize);

void        jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomObjectStructDelete(struct jsonListInboundStreamSettingsFinalMaskUdpHeaderCustomObjectStruct* listInStreamSettingsFinalMaskUdpHeaderCustomObjStruct);

void        jsonListInboundStreamSettingsFinalMaskUdpNoisePacketObjectStructDelete(struct jsonListInboundStreamSettingsFinalMaskUdpNoisePacketObjectStruct* listInStreamSettingsFinalMaskUdpNoisePacketObjStruct, size_t arraySize);

void        jsonListInboundStreamSettingsFinalMaskUdpNoiseObjectStructDelete(struct jsonListInboundStreamSettingsFinalMaskUdpNoiseObjectStruct* listInStreamSettingsFinalMaskUdpNoiseObjStruct);

void        jsonListInboundStreamSettingsFinalMaskUdpObjectStructDelete(struct jsonListInboundStreamSettingsFinalMaskUdpObjectStruct* listInStreamSettingsFinalMaskUdpObjStruct);

void        jsonListInboundStreamSettingsMKcpFinalMaskObjectStructDelete(struct jsonListInboundStreamSettingsMKcpFinalMaskObjectStruct* listInStreamSettingsMKcpFinalMaskObjStruct);

void        jsonListInboundStreamSettingsTcpFinalMaskFragmentObjectStructDelete(struct jsonListInboundStreamSettingsTcpFinalMaskFragmentObjectStruct* listInStreamSettingsTcpFinalMaskFragmentObjStruct);

void        jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomPacketObjectStructDelete(struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomPacketObjectStruct* listInStreamSettingsTcpFinalMaskHeaderCustomPacketObjStruct, size_t arraySize);

void        jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomGroupObjectStructDelete(struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomGroupObjectStruct* listInStreamSettingsTcpFinalMaskHeaderCustomGroupObjStruct, size_t arraySize);

void        jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomObjectStructDelete(struct jsonListInboundStreamSettingsTcpFinalMaskHeaderCustomObjectStruct* listInStreamSettingsTcpFinalMaskHeaderCustomObjStruct);

void        jsonListInboundStreamSettingsTcpFinalMaskSudokuObjectStructDelete(struct jsonListInboundStreamSettingsTcpFinalMaskSudokuObjectStruct* listInStreamSettingsTcpFinalMaskSudokuObjStruct);

void        jsonListInboundStreamSettingsTcpFinalMaskXmcProfileObjectStructDelete(struct jsonListInboundStreamSettingsTcpFinalMaskXmcProfileObjectStruct* listInStreamSettingsTcpFinalMaskXmcProfileObjStruct, size_t arraySize);

void        jsonListInboundStreamSettingsTcpFinalMaskXmcObjectStructDelete(struct jsonListInboundStreamSettingsTcpFinalMaskXmcObjectStruct* listInStreamSettingsTcpFinalMaskXmcObjStruct);

void        jsonListInboundStreamSettingsTcpFinalMaskTcpObjectStructDelete(struct jsonListInboundStreamSettingsTcpFinalMaskTcpObjectStruct* listInStreamSettingsTcpFinalMaskTcpObjStruct);

void        jsonListInboundStreamSettingsTcpFinalMaskObjectStructDelete(struct jsonListInboundStreamSettingsTcpFinalMaskObjectStruct* listInStreamSettingsTcpFinalMaskObjStruct);

void        jsonListInboundStreamSettingsGRPCFinalMaskFragmentObjectStructDelete(struct jsonListInboundStreamSettingsGRPCFinalMaskFragmentObjectStruct* listInStreamSettingsGRPCFinalMaskFragmentObjStruct);

void        jsonListInboundStreamSettingsGRPCFinalMaskHeaderCustomPacketObjectStructDelete(struct jsonListInboundStreamSettingsGRPCFinalMaskHeaderCustomPacketObjectStruct* listInStreamSettingsGRPCFinalMaskHeaderCustomPacketObjStruct, size_t arraySize);

void        jsonListInboundStreamSettingsGRPCFinalMaskHeaderCustomGroupObjectStructDelete(struct jsonListInboundStreamSettingsGRPCFinalMaskHeaderCustomGroupObjectStruct* listInStreamSettingsGRPCFinalMaskHeaderCustomGroupObjStruct, size_t arraySize);

void        jsonListInboundStreamSettingsGRPCFinalMaskHeaderCustomObjectStructDelete(struct jsonListInboundStreamSettingsGRPCFinalMaskHeaderCustomObjectStruct* listInStreamSettingsGRPCFinalMaskHeaderCustomObjStruct);

void        jsonListInboundStreamSettingsGRPCFinalMaskSudokuObjectStructDelete(struct jsonListInboundStreamSettingsGRPCFinalMaskSudokuObjectStruct* listInStreamSettingsGRPCFinalMaskSudokuObjStruct);

void        jsonListInboundStreamSettingsGRPCFinalMaskXmcProfileObjectStructDelete(struct jsonListInboundStreamSettingsGRPCFinalMaskXmcProfileObjectStruct* listInStreamSettingsGRPCFinalMaskXmcProfileObjStruct, size_t arraySize);

void        jsonListInboundStreamSettingsGRPCFinalMaskXmcObjectStructDelete(struct jsonListInboundStreamSettingsGRPCFinalMaskXmcObjectStruct* listInStreamSettingsGRPCFinalMaskXmcObjStruct);

void        jsonListInboundStreamSettingsGRPCFinalMaskTcpObjectStructDelete(struct jsonListInboundStreamSettingsGRPCFinalMaskTcpObjectStruct* listInStreamSettingsGRPCFinalMaskTcpObjStruct);

void        jsonListInboundStreamSettingsGRPCFinalMaskObjectStructDelete(struct jsonListInboundStreamSettingsGRPCFinalMaskObjectStruct* listInStreamSettingsGRPCFinalMaskObjStruct);

void        jsonListInboundStreamSettingsWSFinalMaskFragmentObjectStructDelete(struct jsonListInboundStreamSettingsWSFinalMaskFragmentObjectStruct* listInStreamSettingsWSFinalMaskFragmentObjStruct);

void        jsonListInboundStreamSettingsWSFinalMaskHeaderCustomPacketObjectStructDelete(struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomPacketObjectStruct* listInStreamSettingsWSFinalMaskHeaderCustomPacketObjStruct, size_t arraySize);

void        jsonListInboundStreamSettingsWSFinalMaskHeaderCustomGroupObjectStructDelete(struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomGroupObjectStruct* listInStreamSettingsWSFinalMaskHeaderCustomGroupObjStruct, size_t arraySize);

void        jsonListInboundStreamSettingsWSFinalMaskHeaderCustomObjectStructDelete(struct jsonListInboundStreamSettingsWSFinalMaskHeaderCustomObjectStruct* listInStreamSettingsWSFinalMaskHeaderCustomObjStruct);

void        jsonListInboundStreamSettingsWSFinalMaskSudokuObjectStructDelete(struct jsonListInboundStreamSettingsWSFinalMaskSudokuObjectStruct* listInStreamSettingsWSFinalMaskSudokuObjStruct);

void        jsonListInboundStreamSettingsWSFinalMaskXmcProfileObjectStructDelete(struct jsonListInboundStreamSettingsWSFinalMaskXmcProfileObjectStruct* listInStreamSettingsWSFinalMaskXmcProfileObjStruct, size_t arraySize);

void        jsonListInboundStreamSettingsWSFinalMaskXmcObjectStructDelete(struct jsonListInboundStreamSettingsWSFinalMaskXmcObjectStruct* listInStreamSettingsWSFinalMaskXmcObjStruct);

void        jsonListInboundStreamSettingsWSFinalMaskTcpObjectStructDelete(struct jsonListInboundStreamSettingsWSFinalMaskTcpObjectStruct* listInStreamSettingsWSFinalMaskTcpObjStruct);

void        jsonListInboundStreamSettingsWSFinalMaskObjectStructDelete(struct jsonListInboundStreamSettingsWSFinalMaskObjectStruct* listInStreamSettingsWSFinalMaskObjStruct);

void        jsonListInboundStreamSettingsHTTPUpgradeFinalMaskFragmentObjectStructDelete(struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskFragmentObjectStruct* listInStreamSettingsHTTPUpgradeFinalMaskFragmentObjStruct);

void        jsonListInboundStreamSettingsHTTPUpgradeFinalMaskHeaderCustomPacketObjectStructDelete(struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskHeaderCustomPacketObjectStruct* listInStreamSettingsHTTPUpgradeFinalMaskHeaderCustomPacketObjStruct, size_t arraySize);

void        jsonListInboundStreamSettingsHTTPUpgradeFinalMaskHeaderCustomGroupObjectStructDelete(struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskHeaderCustomGroupObjectStruct* listInStreamSettingsHTTPUpgradeFinalMaskHeaderCustomGroupObjStruct, size_t arraySize);

void        jsonListInboundStreamSettingsHTTPUpgradeFinalMaskHeaderCustomObjectStructDelete(struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskHeaderCustomObjectStruct* listInStreamSettingsHTTPUpgradeFinalMaskHeaderCustomObjStruct);

void        jsonListInboundStreamSettingsHTTPUpgradeFinalMaskSudokuObjectStructDelete(struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskSudokuObjectStruct* listInStreamSettingsHTTPUpgradeFinalMaskSudokuObjStruct);

void        jsonListInboundStreamSettingsHTTPUpgradeFinalMaskXmcProfileObjectStructDelete(struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskXmcProfileObjectStruct* listInStreamSettingsHTTPUpgradeFinalMaskXmcProfileObjStruct, size_t arraySize);

void        jsonListInboundStreamSettingsHTTPUpgradeFinalMaskXmcObjectStructDelete(struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskXmcObjectStruct* listInStreamSettingsHTTPUpgradeFinalMaskXmcObjStruct);

void        jsonListInboundStreamSettingsHTTPUpgradeFinalMaskTcpObjectStructDelete(struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskTcpObjectStruct* listInStreamSettingsHTTPUpgradeFinalMaskTcpObjStruct);

void        jsonListInboundStreamSettingsHTTPUpgradeFinalMaskObjectStructDelete(struct jsonListInboundStreamSettingsHTTPUpgradeFinalMaskObjectStruct* listInStreamSettingsHTTPUpgradeFinalMaskObjStruct);

void        jsonListInboundStreamSettingsXHTTPFinalMaskFragmentObjectStructDelete(struct jsonListInboundStreamSettingsXHTTPFinalMaskFragmentObjectStruct* listInStreamSettingsXHTTPFinalMaskFragmentObjStruct);

void        jsonListInboundStreamSettingsXHTTPFinalMaskHeaderCustomPacketObjectStructDelete(struct jsonListInboundStreamSettingsXHTTPFinalMaskHeaderCustomPacketObjectStruct* listInStreamSettingsXHTTPFinalMaskHeaderCustomPacketObjStruct, size_t arraySize);

void        jsonListInboundStreamSettingsXHTTPFinalMaskHeaderCustomGroupObjectStructDelete(struct jsonListInboundStreamSettingsXHTTPFinalMaskHeaderCustomGroupObjectStruct* listInStreamSettingsXHTTPFinalMaskHeaderCustomGroupObjStruct, size_t arraySize);

void        jsonListInboundStreamSettingsXHTTPFinalMaskHeaderCustomObjectStructDelete(struct jsonListInboundStreamSettingsXHTTPFinalMaskHeaderCustomObjectStruct* listInStreamSettingsXHTTPFinalMaskHeaderCustomObjStruct);

void        jsonListInboundStreamSettingsXHTTPFinalMaskSudokuObjectStructDelete(struct jsonListInboundStreamSettingsXHTTPFinalMaskSudokuObjectStruct* listInStreamSettingsXHTTPFinalMaskSudokuObjStruct);

void        jsonListInboundStreamSettingsXHTTPFinalMaskXmcProfileObjectStructDelete(struct jsonListInboundStreamSettingsXHTTPFinalMaskXmcProfileObjectStruct* listInStreamSettingsXHTTPFinalMaskXmcProfileObjStruct, size_t arraySize);

void        jsonListInboundStreamSettingsXHTTPFinalMaskXmcObjectStructDelete(struct jsonListInboundStreamSettingsXHTTPFinalMaskXmcObjectStruct* listInStreamSettingsXHTTPFinalMaskXmcObjStruct);

void        jsonListInboundStreamSettingsXHTTPFinalMaskTcpObjectStructDelete(struct jsonListInboundStreamSettingsXHTTPFinalMaskTcpObjectStruct* listInStreamSettingsXHTTPFinalMaskTcpObjStruct);

void        jsonListInboundStreamSettingsXHTTPFinalMaskQuicParamsObjectStructDelete(struct jsonListInboundStreamSettingsXHTTPFinalMaskQuicParamsObjectStruct* listInStreamSettingsXHTTPFinalMaskQuicParamsObjStruct);

void        jsonListInboundStreamSettingsXHTTPFinalMaskObjectStructDelete(struct jsonListInboundStreamSettingsXHTTPFinalMaskObjectStruct* listInStreamSettingsXHTTPFinalMaskObjStruct);

void        jsonListInboundStreamSettingsTcpSockoptObjectStructDelete(struct jsonListInboundStreamSettingsTcpSockoptObjectStruct* listInStreamSettingsTcpSockoptObjStruct);

void        jsonListInboundStreamSettingsMKcpSockoptObjectStructDelete(struct jsonListInboundStreamSettingsMKcpSockoptObjectStruct* listInStreamSettingsMKcpSockoptObjStruct);

void        jsonListInboundStreamSettingsWSSockoptObjectStructDelete(struct jsonListInboundStreamSettingsWSSockoptObjectStruct* listInStreamSettingsWSSockoptObjStruct);

void        jsonListInboundStreamSettingsHTTPUpgradeSockoptObjectStructDelete(struct jsonListInboundStreamSettingsHTTPUpgradeSockoptObjectStruct* listInStreamSettingsHTTPUpgradeSockoptObjStruct);

void        jsonListInboundStreamSettingsXHTTPSockoptObjectStructDelete(struct jsonListInboundStreamSettingsXHTTPSockoptObjectStruct* listInStreamSettingsXHTTPSockoptObjStruct);
void        jsonListInboundStreamSettingsTlsSettingsCertificateObjectStructDelete(struct jsonListInboundStreamSettingsTlsSettingsCertificateObjectStruct* p);
void        jsonListInboundStreamSettingsTlsSettingsEchSockoptObjectStructDelete(struct jsonListInboundStreamSettingsTlsSettingsEchSockoptObjectStruct* p);
void        jsonListInboundStreamSettingsTlsSettingsSettingsObjectStructDelete(struct jsonListInboundStreamSettingsTlsSettingsSettingsObjectStruct* p);
void        jsonListInboundStreamSettingsTlsSettingsObjectStructDelete(struct jsonListInboundStreamSettingsTlsSettingsObjectStruct* p);
void        jsonListInboundStreamSettingsRealitySettingsLimitFallbackObjectStructDelete(struct jsonListInboundStreamSettingsRealitySettingsLimitFallbackObjectStruct* p);
void        jsonListInboundStreamSettingsRealitySettingsSettingsObjectStructDelete(struct jsonListInboundStreamSettingsRealitySettingsSettingsObjectStruct* p);
void        jsonListInboundStreamSettingsRealitySettingsObjectStructDelete(struct jsonListInboundStreamSettingsRealitySettingsObjectStruct* p);

void        jsonListInboundStreamSettingsGRPCSettingsObjectStructDelete(struct jsonListInboundStreamSettingsGRPCSettingsObjectStruct* listInStreamSettingsGRPCSettingsObjStruct);

void        jsonListInboundStreamSettingsGRPCSockoptObjectStructDelete(struct jsonListInboundStreamSettingsGRPCSockoptObjectStruct* listInStreamSettingsGRPCSockoptObjStruct);

void        jsonListInboundStreamSettingsObjectStructDelete(struct jsonListInboundStreamSettingsObjectStruct* listInStreamSettingsObjStruct);

void        jsonListInboundSniffingObjectStructDelete(struct jsonListInboundSniffingObjectStruct* listInSniffingObjStruct);

void        jsonListInboundObjectStructDeleteElement(struct jsonListInboundObjectStruct* listInObj);

void        jsonListInboundObjectStructDelete(struct jsonListInboundObjectStruct* listInObjStruct, size_t arraySize);

void        jsonListInboundStructDelete(struct jsonListInboundStruct* listInStruct);

void        jsonListInboundSettingsClientsArraySlimStructDelete(struct jsonListInboundSettingsClientsArraySlimStruct* listInSettingsCliArrSlimStruct, size_t arraySize);

void        jsonListInboundSettingsObjectSlimStructDelete(struct jsonListInboundSettingsObjectSlimStruct* listInSettingsObjSlimStruct);

void        jsonListInboundObjectSlimStructDeleteElement(struct jsonListInboundObjectSlimStruct* listInObj);

void        jsonListInboundObjectSlimStructDelete(struct jsonListInboundObjectSlimStruct* listInObjSlimStruct, size_t arraySize);

void        jsonListInboundSlimStructDelete(struct jsonListInboundSlimStruct* listInSlimStruct);

void        jsonListInboundObjectOptionsArrayStructDelete(struct jsonListInboundObjectOptionsArrayStruct* listInObjOptionsArrStruct, size_t arraySize);

void        jsonListInboundOptionsStructDelete(struct jsonListInboundOptionsStruct* listInOptionsStruct);

void        jsonAddInboundSettingsClientsArrayPostStructDelete(struct jsonAddInboundSettingsClientsArrayPostStruct* addInSettingsCliArrPStruct, size_t arraySize);

void        jsonAddInboundSettingsFallbacksArrayPostStructDelete(struct jsonAddInboundSettingsFallbacksArrayPostStruct* addInSettingsFalbackArrPStruct, size_t arraySize);

void        jsonAddInboundSettingsObjPostStructDelete(struct jsonAddInboundSettingsObjPostStruct* addInSettingsObjPStruct);

void        jsonAddInboundStreamSettingsRealitySettingsObjectPostStructDelete(struct jsonAddInboundStreamSettingsRealitySettingsObjectPostStruct* addInStreamSettignsRealitySettingsObjPStruct);

void        jsonAddInboundStreamSettingsObjPostStructDelete(struct jsonAddInboundStreamSettingsObjPostStruct* addInStreamSettingsObjPStruct);

void        jsonAddInboundSniffingObjectPostStructDelete(struct jsonAddInboundSniffingObjectPostStruct* addInSniffingObjPStruct);

void        jsonAddInboundResponseStructDelete(struct jsonAddInboundResponseStruct* addInRStruct);

void        jsonDeleteSingleInboundPostStructDelete(struct jsonDeleteSingleInboundPostStruct* deleteSingleInboundPostStruct);

void        jsonDeleteSingleInboundResponseStructDelete(struct jsonDeleteSingleInboundResponseStruct* deleteSingleInRStruct);

void        jsonDeleteMultipleInboundsPostStructDelete(struct jsonDeleteMultipleInboundsPostStruct* deleteMultipleInboundsPostStruct);

void        jsonDeleteMultipleInboundResponseSkippedArrayStructDelete(struct jsonDeleteMultipleInboundResponseSkippedArrayStruct* deleteMultiInResSkippedArrStruct, size_t arraySize);

void        jsonDeleteMultipleInboundResponseStructDelete(struct jsonDeleteMultipleInboundResponseStruct* deleteMultiInRStruct);

void        jsonSetEnableInboundResponseStructDelete(struct jsonSetEnableInboundResponseStruct* setEnableInRStruct);

void        jsonResetInboundResponseStructDelete(struct jsonResetInboundResponseStruct* resetInRStruct);

void        jsonRemoveEveryClientFromInboundResponseObjectStructDelete(struct jsonRemoveEveryClientFromInboundResponseObjectStruct* rmEveryCliFromInResObjStruct);

void        jsonRemoveEveryClientFromInboundResponseStructDelete(struct jsonRemoveEveryClientFromInboundResponseStruct* rmEveryCliFromInRStruct);

void        jsonResetAllInboundsUploadNDownloadStructDelete(struct jsonResetAllInboundsUploadNDownloadStruct* resetAllInboundsUploadNDownloadStruct);

void        jsonImportInboundsResponseStructDelete(struct jsonImportInboundsResponseStruct* importInboundsRStruct);

void        jsonListInboundAllLinksStructDelete(struct jsonListInboundAllLinksStruct* listInAllLinksStruct);

void        jsonGetInboundResponseStructDelete(struct jsonGetInboundResponseStruct* getInboundRStruct);

void        jsonUpdateInboundPostStructDelete(struct jsonUpdateInboundPostStruct* updateInboundPostStruct);

void        jsonUpdateInboundResponseStructDelete(struct jsonUpdateInboundResponseStruct* updateInRStruct);

void        jsonSetInboundSubSortIndexPostStructDelete(struct jsonSetInboundSubSortIndexPostStruct* setInboundSubSortIndexPostStruct);

void        jsonSetInboundSubSortIndexResponseStructDelete(struct jsonSetInboundSubSortIndexResponseStruct* setInSubSortIndexRStruct);

void        jsonPushClientTrafficsArrayStructDelete(struct jsonPushClientTrafficsArrayStruct* pushClientTrafficsArrStruct, size_t arraySize);

void        jsonPushClientTrafficsPostStructDelete(struct jsonPushClientTrafficsPostStruct* pushClientTrafficsPostStruct);

void        jsonPushClientTrafficsResponseStructDelete(struct jsonPushClientTrafficsResponseStruct* pushClientTrafficsRStruct);

void        jsonListInboundFallbacksArrayStructDelete(struct jsonListInboundFallbacksArrayStruct* listInFallbacksArrStruct, size_t arraySize);

void        jsonListInboundFallbacksStructDelete(struct jsonListInboundFallbacksStruct* listInFallbacksStruct);

void        jsonSetInboundFallbacksArrayPostStructDelete(struct jsonSetInboundFallbacksArrayPostStruct* setInboundFallbacksArrPStruct, size_t arraySize);

void        jsonSetInboundFallbacksPostStructDelete(struct jsonSetInboundFallbacksPostStruct* setInboundFallbacksPostStruct);

void        jsonSetInboundFallbacksResponseStructDelete(struct jsonSetInboundFallbacksResponseStruct* setInboundFallbacksRStruct);
struct jsonSetInboundFallbacksResponseStruct*    jsonSetInboundFallbacksResponse(const char* json);
const char*                             jsonSetInboundFallbacksPost(struct jsonSetInboundFallbacksPostStruct* setInboundFallbacksPostStruct);



struct jsonListInboundClientStatsArrayStruct*      jsonListInboundClientStatsArray(const char* json);

struct jsonListInboundStruct*                      jsonListInbound(const char* json);

struct jsonListInboundSlimStruct*                  jsonListInboundSlim(const char* json);

struct jsonListInboundOptionsStruct*               jsonListInboundOptions(const char* json);

const char*                                        jsonAddInboundPost(struct jsonListInboundObjectStruct* addInboundObjStruct);

struct jsonAddInboundResponseStruct*               jsonAddInboundResponse(const char* json);

const char*                                        jsonDeleteSingleInboundPost(struct jsonDeleteSingleInboundPostStruct* deleteSingleInboundPostStruct);

struct jsonDeleteSingleInboundResponseStruct*      jsonDeleteSingleInboundResponse(const char* json);

const char*                                        jsonDeleteMultipleInboundsPost(struct jsonDeleteMultipleInboundsPostStruct* deleteMultipleInboundsPostStruct);

struct jsonDeleteMultipleInboundResponseStruct*    jsonDeleteMultipleInboundResponse(const char* json);

struct jsonSetEnableInboundResponseStruct*         jsonSetEnableInboundResponse(const char* json);

struct jsonResetInboundResponseStruct*             jsonResetInboundResponse(const char* json);

struct jsonRemoveEveryClientFromInboundResponseStruct* jsonRemoveEveryClientFromInboundResponse(const char* json);

struct jsonResetAllInboundsUploadNDownloadStruct*  jsonResetAllInboundsUploadNDownload(const char* json);

const char*                                        jsonImportInboundsPost(struct jsonListInboundObjectStruct* importInboundsObjStruct);

struct jsonImportInboundsResponseStruct*           jsonImportInboundsResponse(const char* json);

#endif /* CJSON_TELEGRAM_XUI_BOT_INBOUNDS_H */
