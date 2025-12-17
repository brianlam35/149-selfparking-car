#ifndef _LINEFOLLOWER_H
#define _LINEFOLLOWER_H
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
    uint16_t value[5];
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _linefollower_reflect_t;
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
} _linefollower_enable_t;
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
} _linefollower_lp_t;
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
} _linefollower_rp_t;
typedef struct {
    struct self_base_t base;
#line 69 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_linefollower.h"
    #line 40 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    float kp;
    #line 41 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    float ki;
    #line 42 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    float kd;
    #line 44 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    float base_speed;
    #line 45 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    float max_speed;
    #line 46 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    int threshold;
    #line 48 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    float last_error;
    #line 49 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    float integral;
    #line 50 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    bool enabled;
#line 88 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_linefollower.h"
    _linefollower_reflect_t* _lf_reflect;
    // width of -2 indicates that it is not a multiport.
    int _lf_reflect_width;
    // Default input (in case it does not get connected)
    _linefollower_reflect_t _lf_default__reflect;
    _linefollower_enable_t* _lf_enable;
    // width of -2 indicates that it is not a multiport.
    int _lf_enable_width;
    // Default input (in case it does not get connected)
    _linefollower_enable_t _lf_default__enable;
    _linefollower_lp_t _lf_lp;
    int _lf_lp_width;
    _linefollower_rp_t _lf_rp;
    int _lf_rp_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__reflect;
    reaction_t* _lf__reflect_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__enable;
    reaction_t* _lf__enable_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _linefollower_self_t;
_linefollower_self_t* new__linefollower();
#endif // _LINEFOLLOWER_H
