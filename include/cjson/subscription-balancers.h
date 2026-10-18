#ifndef CJSON_TELEGRAM_XUI_BOT_SUBSCRIPTION_BALANCERS_H
#define CJSON_TELEGRAM_XUI_BOT_SUBSCRIPTION_BALANCERS_H

// subscription-balancers section - https://docs.sanaei.dev/docs/reference/api/subscription-balancers/

#include <stddef.h>
#include <stdint.h>


// =====================================================
// Subscription balancers : client-side balancers for the
// JSON subscription; each enabled balancer is emitted as
// one extra config document whose members are the proxy
// outbounds of the selected inbounds
// ( routing.balancers + burstObservatory ). Managed in
// Settings → Sub Balancers.
// NOTE: absent from the 3.6.0 OpenAPI ( all endpoints
// 404 here ); requires a newer panel version
// =====================================================

// =====================================================
// List all subscription balancers in sort order
// ( sort_order asc, id asc ) response structs
// =====================================================

struct jsonSubBalancerObjectStruct {
    int64_t                     createdAt; // creation time in unix milliseconds
    unsigned char               enabled; // whether the balancer is emitted
    int                         id;
    int*                        inboundIds; // member inbound ids; every pointer presented is
    int64_t                     inboundIdsCount;
                                            // an element of the array
    void*                       memberWeights; // leastLoad only: JSON object mapping inbound
                                               // id to a static weight > 0, eg {"3":0.2};
                                               // lower weight is picked more often; absent
                                               // ids weigh 1; dynamic keys cannot be modeled
                                               // by a C struct ( undefined behavior )
    const char*                 remark; // display label, used as the config remarks
    int                         sortOrder; // 1-based position in the subscription list
    const char*                 strategy; // "leastLoad", "leastPing", "roundRobin" or
                                          // "random"
    int64_t                     updatedAt; // last update time in unix milliseconds

};



struct jsonListSubBalancersResponseStruct {
    unsigned char               success;
    size_t                      jsonSubBalancerObjectStructSize;
    struct jsonSubBalancerObjectStruct* listSubBalancersObjArrStruct; // array

};


// =====================================================
// Create a subscription balancer; it appears in the JSON
// subscription of every client that sits on at least one
// selected inbound post and response structs
// =====================================================

struct jsonCreateSubBalancerPostStruct {
    const char*                 remark; // display label, used as the config remarks
                                        // ( required )
    const char*                 strategy; // "leastLoad", "leastPing", "roundRobin" or
                                          // "random", defaults to "random"
    int*                        inboundIds; // repeated form keys selecting the member
    int64_t                     inboundIdsCount;
                                            // inbounds ( required, at least one ); every
                                            // pointer presented is an element of the array
    void*                       memberWeights; // leastLoad only: JSON object mapping inbound
                                               // id to a static weight > 0; dynamic keys
                                               // cannot be modeled by a C struct; rejected
                                               // for other strategies
                                               // ( undefined behavior )
    int                         sortOrder; // 1-based position in the subscription list,
                                           // defaults to 1
    unsigned char               enabled; // whether the balancer is emitted; default true on
                                         // create

};



struct jsonCreateSubBalancerResponseStruct {
    unsigned char               success;
    struct jsonSubBalancerObjectStruct* createSubBalancerObjRStruct;

};


// =====================================================
// Update a balancer by id; accepts the same form fields
// as create ( full-row update ); omitting memberWeights
// clears stored weights while omitting enabled keeps its
// current value
// =====================================================

struct jsonUpdateSubBalancerPostStruct {
    const char*                 remark; // display label, used as the config remarks
                                        // ( required )
    const char*                 strategy; // "leastLoad", "leastPing", "roundRobin" or
                                          // "random", defaults to "random"
    int*                        inboundIds; // repeated form keys selecting the member
    int64_t                     inboundIdsCount;
                                            // inbounds ( required, at least one ); every
                                            // pointer presented is an element of the array
    void*                       memberWeights; // leastLoad only: JSON object mapping inbound
                                               // id to a static weight > 0; dynamic keys
                                               // cannot be modeled by a C struct; rejected
                                               // for other strategies
                                               // ( undefined behavior )
    int                         sortOrder; // 1-based position in the subscription list,
                                           // defaults to 1
    unsigned char               enabled; // whether the balancer is emitted; unchanged when
                                         // omitted on update

};



struct jsonUpdateSubBalancerResponseStruct {
    unsigned char               success;
    struct jsonSubBalancerObjectStruct* updateSubBalancerObjRStruct;

};


// =====================================================
// Delete a balancer by id ( DELETE route and the POST
// /del alias for clients that cannot send DELETE )
// =====================================================

struct jsonDeleteSubBalancerResponseStruct {
    unsigned char               success;
    struct jsonSubBalancerObjectStruct* deleteSubBalancerObjRStruct;

};

void        jsonSubBalancerObjectStructDelete(struct jsonSubBalancerObjectStruct* listSubBalancersObjArrStruct, size_t arraySize);

void        jsonListSubBalancersResponseStructDelete(struct jsonListSubBalancersResponseStruct* listSubBalancersRStruct);

void        jsonCreateSubBalancerPostStructDelete(struct jsonCreateSubBalancerPostStruct* createSubBalancerPostStruct);

void        jsonCreateSubBalancerResponseStructDelete(struct jsonCreateSubBalancerResponseStruct* createSubBalancerRStruct);

void        jsonUpdateSubBalancerPostStructDelete(struct jsonUpdateSubBalancerPostStruct* updateSubBalancerPostStruct);

void        jsonUpdateSubBalancerResponseStructDelete(struct jsonUpdateSubBalancerResponseStruct* updateSubBalancerRStruct);

void        jsonDeleteSubBalancerResponseStructDelete(struct jsonDeleteSubBalancerResponseStruct* deleteSubBalancerRStruct);

struct jsonListSubBalancersResponseStruct*         jsonListSubBalancersResponse(const char* json);

const char*                                        jsonCreateSubBalancerPost(struct jsonCreateSubBalancerPostStruct* createSubBalancerPostStruct);

struct jsonCreateSubBalancerResponseStruct*        jsonCreateSubBalancerResponse(const char* json);

const char*                                        jsonUpdateSubBalancerPost(struct jsonUpdateSubBalancerPostStruct* updateSubBalancerPostStruct);

struct jsonUpdateSubBalancerResponseStruct*        jsonUpdateSubBalancerResponse(const char* json);

struct jsonDeleteSubBalancerResponseStruct*        jsonDeleteSubBalancerResponse(const char* json);

#endif /* CJSON_TELEGRAM_XUI_BOT_SUBSCRIPTION_BALANCERS_H */
