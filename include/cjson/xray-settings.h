#ifndef CJSON_TELEGRAM_XUI_BOT_XRAY_SETTINGS_H
#define CJSON_TELEGRAM_XUI_BOT_XRAY_SETTINGS_H

// xray-settings section - https://docs.sanaei.dev/docs/reference/api/xray-settings/

#include <stddef.h>
#include <stdint.h>


// =====================================================
// Xray settings : configuration template, outbound
// management, Warp / Nord / PIA integration and config
// testing. All endpoints live under /panel/api/xray.
// =====================================================

// =====================================================
// Return the Xray config template ( JSON string ),
// available inbound tags, client reverse tags and the
// configured outbound test URL in one response post
// response structs
// =====================================================

struct jsonXrayConfigObjectResponseStruct {
    const char*                 xraySetting; // raw Xray config template as a JSON string
    const char*                 inboundTags; // JSON-string-encoded array of inbound tags,
                                             // eg "[\"in-443-tcp\"]"
    const char*                 clientReverseTags; // JSON-string-encoded array of client
                                                   // reverse tags, eg "[]"
    const char*                 outboundTestUrl; // URL used for outbound reachability tests
                                                 // eg "https://www.google.com/generate_204"

};



struct jsonXrayConfigResponseStruct {
    unsigned char               success;
    const char*                 msg;
    struct jsonXrayConfigObjectResponseStruct* xrayConfigObjRStruct;

};


// =====================================================
// Return the built-in default Xray config shipped with
// the panel ( identical to
// /panel/api/setting/getDefaultJsonConfig )
// =====================================================

struct jsonXrayGetDefaultJsonConfigResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char*                 obj; // documented as the default JSON config but
                                     // the documented sample response shows null; exact shape
                                     // not provided ( undefined behavior )

};


// =====================================================
// Return traffic statistics for every outbound ( each
// outbound shows up/down/total counters )
// =====================================================

struct jsonXrayGetOutboundsTrafficResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char*                 obj; // documented as per-outbound up/down/total counters but
                                     // the documented sample response shows null; exact shape
                                     // not provided ( undefined behavior )

};


// =====================================================
// Return the most recent Xray process stdout/stderr
// output ( useful to check startup errors or runtime
// warnings )
// =====================================================

struct jsonXrayGetXrayResultResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char*                 obj; // documented as the process output text but the
                                     // documented sample response shows null
                                     // ( undefined behavior )

};


// =====================================================
// Save the Xray JSON config template and optionally the
// outbound test URL ( form fields )
// =====================================================

struct jsonXrayUpdatePostStruct {
    const char*                 xraySetting; // full Xray JSON config template
    const char*                 outboundTestUrl; // URL used for outbound reachability tests

};



struct jsonXrayUpdateResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Manage Cloudflare Warp integration; the action path
// parameter selects the operation ( data, del, config,
// reg, changeIp, license, interval )
// =====================================================

struct jsonXrayWarpPostStruct {
    const char*                 privateKey; // required when action=reg
    const char*                 publicKey; // required when action=reg
    const char*                 license; // required when action=license
    int                         interval; // automatic rotation in hours; required when
                                          // action=interval; 0 disables rotation

};



struct jsonXrayWarpResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char*                 obj; // documented as action-dependent data (config, stats,
                                     // keys, etc.) but the documented sample response
                                     // shows null ( undefined behavior )

};


// =====================================================
// Manage NordVPN integration; the action path parameter
// selects the operation ( countries, servers, reg,
// setKey, data, del )
// =====================================================

struct jsonXrayNordPostStruct {
    const char*                 countryId; // required when action=servers
    const char*                 token; // required when action=reg
    const char*                 key; // required when action=setKey

};



struct jsonXrayNordResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char*                 obj; // documented as action-dependent data (countries,
                                     // servers, credentials, etc.) but the documented
                                     // sample response shows null ( undefined behavior )

};


// =====================================================
// Manage PIA WireGuard integration; the action path
// parameter selects the operation ( countries, servers,
// reg, data, del, addKey )
// =====================================================

struct jsonXrayPiaPostStruct {
    const char*                 countryCode; // required when action=servers
    const char*                 username; // required when action=reg
    const char*                 password; // required when action=reg
    const char*                 hostname; // required when action=addKey

};



struct jsonXrayPiaResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char*                 obj; // documented as action-dependent data (countries,
                                     // servers, credentials, WireGuard keys, etc.) but
                                     // the documented sample response shows null
                                     // ( undefined behavior )

};


// =====================================================
// Reset traffic counters for a specific outbound by tag
// =====================================================

struct jsonXrayResetOutboundsTrafficPostStruct {
    const char*                 tag; // outbound tag to reset, eg "proxy", "direct"

};



struct jsonXrayResetOutboundsTrafficResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Test an outbound configuration; sends the outbound
// JSON ( required ), optionally all outbounds ( to
// resolve sockopt.dialerProxy dependencies ) and a mode
// flag
// =====================================================

struct jsonXrayTestOutboundPostStruct {
    const char*                 outbound; // JSON-encoded single outbound to test ( required )
    const char*                 allOutbounds; // JSON array of all outbounds ( dialerProxy
                                              // resolution )
    const char*                 mode; // "tcp" dial-only probe, "real" real-delay probe or
                                      // empty for a full HTTP probe

};



struct jsonXrayTestOutboundResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char*                 obj; // documented as the test result with tag, delay,
                                     // HTTP status and timing breakdown but the documented
                                     // sample response shows null ( undefined behavior )

};


// =====================================================
// Test a batch of outbounds ( max 50 ) through one
// shared temp xray instance; returns an array of results
// in input order
// =====================================================

struct jsonXrayTestOutboundsPostStruct {
    const char*                 outbounds; // JSON array of outbound configs to test
                                           // ( required )
    const char*                 allOutbounds; // JSON array of all outbounds ( dialerProxy
                                              // resolution )
    const char*                 mode; // "tcp" dial-only probes, "real" real-delay probes or
                                      // empty for full HTTP probes

};



struct jsonXrayTestOutboundsResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char*                 obj; // documented as an array of results with tag, delay,
                                     // HTTP status and connect/TLS/TTFB timing breakdown but
                                     // the documented sample response shows null
                                     // ( undefined behavior )

};


// =====================================================
// Live state of routing balancers in the running core
// ( current override and the targets the strategy
// prefers ); returns a map keyed by balancer tag
// =====================================================

struct jsonXrayBalancerStatusPostStruct {
    const char*                 tags; // comma-separated balancer tags to query, eg "b1,b2"

};



struct jsonXrayBalancerStatusResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char*                 obj; // map keyed by balancer tag; dynamic keys cannot be
                                     // modeled by a C struct and the documented sample
                                     // response shows null ( undefined behavior )

};


// =====================================================
// Force a balancer in the running core to always pick
// one outbound; applied live, cleared when Xray restarts
// =====================================================

struct jsonXrayBalancerOverridePostStruct {
    const char*                 tag; // balancer tag ( required )
    const char*                 target; // outbound tag to force; empty clears the override

};



struct jsonXrayBalancerOverrideResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Ask the running core which outbound its router would
// pick for a synthetic connection; no traffic is sent
// =====================================================

struct jsonXrayRouteTestPostStruct {
    const char*                 domain; // target domain; either domain or ip is required
    const char*                 ip; // target ip; either domain or ip is required
    int                         port; // target port ( optional )
    const char*                 network; // "tcp" ( default ) or "udp"
    const char*                 inboundTag; // simulate arrival on this inbound ( optional )
    const char*                 protocol; // sniffed protocol such as http, tls, bittorrent
    const char*                 email; // user attribution for user-based rules ( optional )

};



struct jsonXrayRouteTestResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char*                 obj; // documented as the route test result but the
                                     // documented sample response shows null
                                     // ( undefined behavior )

};


// =====================================================
// List the geo databases ( .dat files ) in the Xray
// asset folder with the layout detected from their
// contents, size, modification time and category count
// =====================================================

struct jsonXrayGeoDataFilesResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char*                 obj; // documented as per-database layout, size, mtime,
                                     // category count and parse error but the documented
                                     // sample response shows null ( undefined behavior )

};


// =====================================================
// One page of a database's categories, each with its
// entry count and the attributes its domains carry
// ( eg "ads", "cn" )
// =====================================================

struct jsonXrayGeoDataCategoriesQueryStruct {
    const char*                 file; // database file name inside the asset folder
                                      // ( required ), eg geosite.dat
    const char*                 q; // case-insensitive substring filter on the category code
    int                         offset; // rows to skip, defaults to 0; 0 means omitted
    int                         limit; // rows to return, capped at 500; 0 means omitted (return all)

};



struct jsonXrayGeoDataCategoriesResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char*                 obj; // documented as a page of categories with entry counts
                                     // and domain attributes but the documented sample
                                     // response shows null ( undefined behavior )

};


// =====================================================
// One page of the rules inside a category ( domain
// rules typed as domain/full/keyword/regexp for geosite
// databases, CIDRs for geoip ones )
// =====================================================

struct jsonXrayGeoDataEntriesQueryStruct {
    const char*                 file; // database file name inside the asset folder
                                      // ( required )
    const char*                 code; // category code, case-insensitive ( required ),
                                      // eg google
    const char*                 q; // case-insensitive substring filter on the rule value
    int                         offset; // rows to skip, defaults to 0; 0 means omitted
    int                         limit; // rows to return, capped at 500; 0 means omitted (defaults to cap)

};



struct jsonXrayGeoDataEntriesResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char*                 obj; // documented as a page of rules but the documented
                                     // sample response shows null ( undefined behavior )

};


// =====================================================
// Check routing tokens against the databases on disk
// and return only the ones that do not resolve; each
// issue carries a reason ( syntax, fileMissing or
// categoryMissing )
// =====================================================

struct jsonXrayGeoDataValidatePostStruct {
    const char*                 tokens; // comma-separated routing tokens, eg
                                        // "geosite:google,geosite:blabla", max 500
    const char*                 kind; // "ip" to parse tokens as IP rules; anything else
                                     // parses them as domain rules

};



struct jsonXrayGeoDataValidateResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char*                 obj; // documented as the non-resolving tokens with reasons
                                     // but the documented sample response shows null
                                     // ( undefined behavior )

};


// =====================================================
// List all outbound subscriptions ( remote URLs that
// supply additional outbounds ), newest first
// =====================================================

struct jsonXrayOutboundSubsListResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char*                 obj; // documented as the subscription rows ( remark, url,
                                     // tagPrefix, updateInterval, enabled, allowPrivate,
                                     // allowInsecure, prepend ) but the documented sample
                                     // response shows null; exact row shape not provided
                                     // ( undefined behavior )

};


// =====================================================
// Create an outbound subscription; the URL is fetched,
// parsed into outbounds with stable tags and merged
// additively into the running Xray config
// =====================================================

struct jsonXrayOutboundSubsCreatePostStruct {
    const char*                 remark; // optional display label
    const char*                 url; // subscription URL ( required ); must be public http(s),
                                     // private/internal targets blocked unless allowPrivate
    const char*                 tagPrefix; // prefix for generated outbound tags, defaults to
                                           // the lowest free "sub-" prefix
    int                         updateInterval; // seconds between auto-refreshes,
                                                // default 600
    unsigned char               enabled; // whether the subscription is active, default true
    unsigned char               allowPrivate; // allow private/internal/loopback addresses,
                                              // default false
    unsigned char               allowInsecure; // skip TLS certificate verification when
                                               // fetching the URL, default false
    unsigned char               prepend; // place this subscription's outbounds before the
                                          // manual template outbounds, default false
    const char*                 userAgent; // custom User-Agent sent when fetching this
                                           // subscription, defaults to "3x-ui-outbound-sub/1.0"

};



struct jsonXrayOutboundSubsCreateResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Update an existing outbound subscription by id;
// accepts the same form fields as create
// =====================================================

struct jsonXrayOutboundSubsUpdatePostStruct {
    const char*                 remark; // optional display label
    const char*                 url; // subscription URL ( required ); must be public http(s),
                                     // private/internal targets blocked unless allowPrivate
    const char*                 tagPrefix; // prefix for generated outbound tags, defaults to
                                           // the lowest free "sub-" prefix
    int                         updateInterval; // seconds between auto-refreshes,
                                                // default 600
    unsigned char               enabled; // whether the subscription is active, default true
    unsigned char               allowPrivate; // allow private/internal/loopback addresses,
                                              // default false
    unsigned char               allowInsecure; // skip TLS certificate verification when
                                               // fetching the URL, default false
    unsigned char               prepend; // place this subscription's outbounds before the
                                          // manual template outbounds, default false
    const char*                 userAgent; // custom User-Agent sent when fetching this
                                           // subscription, defaults to "3x-ui-outbound-sub/1.0"

};



struct jsonXrayOutboundSubsUpdateResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Delete an outbound subscription by id ( DELETE route
// and the POST /del alias for clients that cannot send
// DELETE )
// =====================================================

struct jsonXrayOutboundSubsDeleteResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Force an immediate re-fetch of the subscription and
// return the parsed outbounds; signals Xray to reload
// =====================================================

struct jsonXrayOutboundSubsRefreshResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char*                 obj; // documented as the parsed outbounds but the documented
                                     // sample response shows null ( undefined behavior )

};


// =====================================================
// Reorder a subscription one step up or down in
// priority ( controls its position in the merged
// outbounds )
// =====================================================

struct jsonXrayOutboundSubsMovePostStruct {
    const char*                 dir; // "up" to raise priority, anything else to lower it

};



struct jsonXrayOutboundSubsMoveResponseStruct {
    unsigned char               success;
    const char*                 msg;
    void*                       obj; // This shall be null on normal ( not customized  ) setup

};


// =====================================================
// Preview a subscription URL: fetch and parse it into
// outbounds without persisting anything
// =====================================================

struct jsonXrayOutboundSubsParsePostStruct {
    const char*                 url; // subscription URL to preview ( required )
    unsigned char               allowPrivate; // allow a private/internal/loopback URL,
                                              // default false
    unsigned char               allowInsecure; // skip TLS certificate verification,
                                               // default false
    const char*                 userAgent; // custom User-Agent sent while fetching the
                                           // preview, defaults to "3x-ui-outbound-sub/1.0"

};



struct jsonXrayOutboundSubsParseResponseStruct {
    unsigned char               success;
    const char*                 msg;
    const char*                 obj; // documented as the parsed outbounds but the documented
                                     // sample response shows null ( undefined behavior )

};

void        jsonXrayConfigObjectResponseStructDelete(struct jsonXrayConfigObjectResponseStruct* xrayConfigObjRStruct);

void        jsonXrayConfigResponseStructDelete(struct jsonXrayConfigResponseStruct* xrayConfigRStruct);

void        jsonXrayGetDefaultJsonConfigResponseStructDelete(struct jsonXrayGetDefaultJsonConfigResponseStruct* xrayGetDefaultJsonConfigRStruct);

void        jsonXrayGetOutboundsTrafficResponseStructDelete(struct jsonXrayGetOutboundsTrafficResponseStruct* xrayGetOutboundsTrafficRStruct);

void        jsonXrayGetXrayResultResponseStructDelete(struct jsonXrayGetXrayResultResponseStruct* xrayGetXrayResultRStruct);

void        jsonXrayUpdatePostStructDelete(struct jsonXrayUpdatePostStruct* xrayUpdatePostStruct);

void        jsonXrayUpdateResponseStructDelete(struct jsonXrayUpdateResponseStruct* xrayUpdateRStruct);

void        jsonXrayWarpPostStructDelete(struct jsonXrayWarpPostStruct* xrayWarpPostStruct);

void        jsonXrayWarpResponseStructDelete(struct jsonXrayWarpResponseStruct* xrayWarpRStruct);

void        jsonXrayNordPostStructDelete(struct jsonXrayNordPostStruct* xrayNordPostStruct);

void        jsonXrayNordResponseStructDelete(struct jsonXrayNordResponseStruct* xrayNordRStruct);

void        jsonXrayPiaPostStructDelete(struct jsonXrayPiaPostStruct* xrayPiaPostStruct);

void        jsonXrayPiaResponseStructDelete(struct jsonXrayPiaResponseStruct* xrayPiaRStruct);

void        jsonXrayResetOutboundsTrafficPostStructDelete(struct jsonXrayResetOutboundsTrafficPostStruct* xrayResetOutboundsTrafficPostStruct);

void        jsonXrayResetOutboundsTrafficResponseStructDelete(struct jsonXrayResetOutboundsTrafficResponseStruct* xrayResetOutboundsTrafficRStruct);

void        jsonXrayTestOutboundPostStructDelete(struct jsonXrayTestOutboundPostStruct* xrayTestOutboundPostStruct);

void        jsonXrayTestOutboundResponseStructDelete(struct jsonXrayTestOutboundResponseStruct* xrayTestOutboundRStruct);

void        jsonXrayTestOutboundsPostStructDelete(struct jsonXrayTestOutboundsPostStruct* xrayTestOutboundsPostStruct);

void        jsonXrayTestOutboundsResponseStructDelete(struct jsonXrayTestOutboundsResponseStruct* xrayTestOutboundsRStruct);

void        jsonXrayBalancerStatusPostStructDelete(struct jsonXrayBalancerStatusPostStruct* xrayBalancerStatusPostStruct);

void        jsonXrayBalancerStatusResponseStructDelete(struct jsonXrayBalancerStatusResponseStruct* xrayBalancerStatusRStruct);

void        jsonXrayBalancerOverridePostStructDelete(struct jsonXrayBalancerOverridePostStruct* xrayBalancerOverridePostStruct);

void        jsonXrayBalancerOverrideResponseStructDelete(struct jsonXrayBalancerOverrideResponseStruct* xrayBalancerOverrideRStruct);

void        jsonXrayRouteTestPostStructDelete(struct jsonXrayRouteTestPostStruct* xrayRouteTestPostStruct);

void        jsonXrayRouteTestResponseStructDelete(struct jsonXrayRouteTestResponseStruct* xrayRouteTestRStruct);

void        jsonXrayGeoDataFilesResponseStructDelete(struct jsonXrayGeoDataFilesResponseStruct* xrayGeoDataFilesRStruct);

void        jsonXrayGeoDataCategoriesQueryStructDelete(struct jsonXrayGeoDataCategoriesQueryStruct* xrayGeoDataCategoriesQueryStruct);

void        jsonXrayGeoDataCategoriesResponseStructDelete(struct jsonXrayGeoDataCategoriesResponseStruct* xrayGeoDataCategoriesRStruct);

void        jsonXrayGeoDataEntriesQueryStructDelete(struct jsonXrayGeoDataEntriesQueryStruct* xrayGeoDataEntriesQueryStruct);

void        jsonXrayGeoDataEntriesResponseStructDelete(struct jsonXrayGeoDataEntriesResponseStruct* xrayGeoDataEntriesRStruct);

void        jsonXrayGeoDataValidatePostStructDelete(struct jsonXrayGeoDataValidatePostStruct* xrayGeoDataValidatePostStruct);

void        jsonXrayGeoDataValidateResponseStructDelete(struct jsonXrayGeoDataValidateResponseStruct* xrayGeoDataValidateRStruct);

void        jsonXrayOutboundSubsListResponseStructDelete(struct jsonXrayOutboundSubsListResponseStruct* xrayOutboundSubsListRStruct);

void        jsonXrayOutboundSubsCreatePostStructDelete(struct jsonXrayOutboundSubsCreatePostStruct* xrayOutboundSubsCreatePostStruct);

void        jsonXrayOutboundSubsCreateResponseStructDelete(struct jsonXrayOutboundSubsCreateResponseStruct* xrayOutboundSubsCreateRStruct);

void        jsonXrayOutboundSubsUpdatePostStructDelete(struct jsonXrayOutboundSubsUpdatePostStruct* xrayOutboundSubsUpdatePostStruct);

void        jsonXrayOutboundSubsUpdateResponseStructDelete(struct jsonXrayOutboundSubsUpdateResponseStruct* xrayOutboundSubsUpdateRStruct);

void        jsonXrayOutboundSubsDeleteResponseStructDelete(struct jsonXrayOutboundSubsDeleteResponseStruct* xrayOutboundSubsDeleteRStruct);

void        jsonXrayOutboundSubsRefreshResponseStructDelete(struct jsonXrayOutboundSubsRefreshResponseStruct* xrayOutboundSubsRefreshRStruct);

void        jsonXrayOutboundSubsMovePostStructDelete(struct jsonXrayOutboundSubsMovePostStruct* xrayOutboundSubsMovePostStruct);

void        jsonXrayOutboundSubsMoveResponseStructDelete(struct jsonXrayOutboundSubsMoveResponseStruct* xrayOutboundSubsMoveRStruct);

void        jsonXrayOutboundSubsParsePostStructDelete(struct jsonXrayOutboundSubsParsePostStruct* xrayOutboundSubsParsePostStruct);

void        jsonXrayOutboundSubsParseResponseStructDelete(struct jsonXrayOutboundSubsParseResponseStruct* xrayOutboundSubsParseRStruct);

struct jsonXrayConfigResponseStruct*               jsonXrayConfigResponse(const char* json);

struct jsonXrayGetDefaultJsonConfigResponseStruct* jsonXrayGetDefaultJsonConfigResponse(const char* json);

struct jsonXrayGetOutboundsTrafficResponseStruct*  jsonXrayGetOutboundsTrafficResponse(const char* json);

struct jsonXrayGetXrayResultResponseStruct*        jsonXrayGetXrayResultResponse(const char* json);

const char*                                        jsonXrayUpdatePost(struct jsonXrayUpdatePostStruct* xrayUpdatePostStruct);

struct jsonXrayUpdateResponseStruct*               jsonXrayUpdateResponse(const char* json);

const char*                                        jsonXrayWarpPost(struct jsonXrayWarpPostStruct* xrayWarpPostStruct);

struct jsonXrayWarpResponseStruct*                 jsonXrayWarpResponse(const char* json);

const char*                                        jsonXrayNordPost(struct jsonXrayNordPostStruct* xrayNordPostStruct);

struct jsonXrayNordResponseStruct*                 jsonXrayNordResponse(const char* json);

const char*                                        jsonXrayPiaPost(struct jsonXrayPiaPostStruct* xrayPiaPostStruct);

struct jsonXrayPiaResponseStruct*                  jsonXrayPiaResponse(const char* json);

const char*                                        jsonXrayResetOutboundsTrafficPost(struct jsonXrayResetOutboundsTrafficPostStruct* xrayResetOutboundsTrafficPostStruct);

struct jsonXrayResetOutboundsTrafficResponseStruct* jsonXrayResetOutboundsTrafficResponse(const char* json);

const char*                                        jsonXrayTestOutboundPost(struct jsonXrayTestOutboundPostStruct* xrayTestOutboundPostStruct);

struct jsonXrayTestOutboundResponseStruct*         jsonXrayTestOutboundResponse(const char* json);

const char*                                        jsonXrayTestOutboundsPost(struct jsonXrayTestOutboundsPostStruct* xrayTestOutboundsPostStruct);

struct jsonXrayTestOutboundsResponseStruct*        jsonXrayTestOutboundsResponse(const char* json);

const char*                                        jsonXrayBalancerStatusPost(struct jsonXrayBalancerStatusPostStruct* xrayBalancerStatusPostStruct);

struct jsonXrayBalancerStatusResponseStruct*       jsonXrayBalancerStatusResponse(const char* json);

const char*                                        jsonXrayBalancerOverridePost(struct jsonXrayBalancerOverridePostStruct* xrayBalancerOverridePostStruct);

struct jsonXrayBalancerOverrideResponseStruct*     jsonXrayBalancerOverrideResponse(const char* json);

const char*                                        jsonXrayRouteTestPost(struct jsonXrayRouteTestPostStruct* xrayRouteTestPostStruct);

struct jsonXrayRouteTestResponseStruct*            jsonXrayRouteTestResponse(const char* json);

struct jsonXrayGeoDataFilesResponseStruct*         jsonXrayGeoDataFilesResponse(const char* json);

const char*                                        jsonXrayGeoDataCategoriesQueryString(struct jsonXrayGeoDataCategoriesQueryStruct* xrayGeoDataCategoriesQueryStruct);

struct jsonXrayGeoDataCategoriesResponseStruct*    jsonXrayGeoDataCategoriesResponse(const char* json);

const char*                                        jsonXrayGeoDataEntriesQueryString(struct jsonXrayGeoDataEntriesQueryStruct* xrayGeoDataEntriesQueryStruct);

struct jsonXrayGeoDataEntriesResponseStruct*       jsonXrayGeoDataEntriesResponse(const char* json);

const char*                                        jsonXrayGeoDataValidatePost(struct jsonXrayGeoDataValidatePostStruct* xrayGeoDataValidatePostStruct);

struct jsonXrayGeoDataValidateResponseStruct*      jsonXrayGeoDataValidateResponse(const char* json);

struct jsonXrayOutboundSubsListResponseStruct*     jsonXrayOutboundSubsListResponse(const char* json);

const char*                                        jsonXrayOutboundSubsCreatePost(struct jsonXrayOutboundSubsCreatePostStruct* xrayOutboundSubsCreatePostStruct);

struct jsonXrayOutboundSubsCreateResponseStruct*   jsonXrayOutboundSubsCreateResponse(const char* json);

const char*                                        jsonXrayOutboundSubsUpdatePost(struct jsonXrayOutboundSubsUpdatePostStruct* xrayOutboundSubsUpdatePostStruct);

struct jsonXrayOutboundSubsUpdateResponseStruct*   jsonXrayOutboundSubsUpdateResponse(const char* json);

struct jsonXrayOutboundSubsDeleteResponseStruct*   jsonXrayOutboundSubsDeleteResponse(const char* json);

struct jsonXrayOutboundSubsRefreshResponseStruct*  jsonXrayOutboundSubsRefreshResponse(const char* json);

const char*                                        jsonXrayOutboundSubsMovePost(struct jsonXrayOutboundSubsMovePostStruct* xrayOutboundSubsMovePostStruct);

struct jsonXrayOutboundSubsMoveResponseStruct*     jsonXrayOutboundSubsMoveResponse(const char* json);

const char*                                        jsonXrayOutboundSubsParsePost(struct jsonXrayOutboundSubsParsePostStruct* xrayOutboundSubsParsePostStruct);

struct jsonXrayOutboundSubsParseResponseStruct*    jsonXrayOutboundSubsParseResponse(const char* json);

#endif /* CJSON_TELEGRAM_XUI_BOT_XRAY_SETTINGS_H */
