#ifndef _MOTORARBITER_H
#define _MOTORARBITER_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1206678562_H
#define TOP_LEVEL_PREAMBLE_1206678562_H
#include <math.h>
#include <stdlib.h>
#include <pico/stdlib.h>
#endif // TOP_LEVEL_PREAMBLE_1206678562_H
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _motorarbiter_controller_lp_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _motorarbiter_controller_rp_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _motorarbiter_line_follower_lp_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _motorarbiter_line_follower_rp_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _motorarbiter_use_line_follower_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _motorarbiter_lp_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _motorarbiter_rp_t;
typedef struct {
    struct self_base_t base;
#line 111 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_motorarbiter.h"
    #line 381 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    bool use_follower;
#line 114 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_motorarbiter.h"
    _motorarbiter_controller_lp_t* _lf_controller_lp;
    // width of -2 indicates that it is not a multiport.
    int _lf_controller_lp_width;
    // Default input (in case it does not get connected)
    _motorarbiter_controller_lp_t _lf_default__controller_lp;
    _motorarbiter_controller_rp_t* _lf_controller_rp;
    // width of -2 indicates that it is not a multiport.
    int _lf_controller_rp_width;
    // Default input (in case it does not get connected)
    _motorarbiter_controller_rp_t _lf_default__controller_rp;
    _motorarbiter_line_follower_lp_t* _lf_line_follower_lp;
    // width of -2 indicates that it is not a multiport.
    int _lf_line_follower_lp_width;
    // Default input (in case it does not get connected)
    _motorarbiter_line_follower_lp_t _lf_default__line_follower_lp;
    _motorarbiter_line_follower_rp_t* _lf_line_follower_rp;
    // width of -2 indicates that it is not a multiport.
    int _lf_line_follower_rp_width;
    // Default input (in case it does not get connected)
    _motorarbiter_line_follower_rp_t _lf_default__line_follower_rp;
    _motorarbiter_use_line_follower_t* _lf_use_line_follower;
    // width of -2 indicates that it is not a multiport.
    int _lf_use_line_follower_width;
    // Default input (in case it does not get connected)
    _motorarbiter_use_line_follower_t _lf_default__use_line_follower;
    _motorarbiter_lp_t _lf_lp;
    int _lf_lp_width;
    _motorarbiter_rp_t _lf_rp;
    int _lf_rp_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    trigger_t _lf__controller_lp;
    reaction_t* _lf__controller_lp_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__controller_rp;
    reaction_t* _lf__controller_rp_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__line_follower_lp;
    reaction_t* _lf__line_follower_lp_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__line_follower_rp;
    reaction_t* _lf__line_follower_rp_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__use_line_follower;
    reaction_t* _lf__use_line_follower_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _motorarbiter_self_t;
_motorarbiter_self_t* new__motorarbiter();
#endif // _MOTORARBITER_H
