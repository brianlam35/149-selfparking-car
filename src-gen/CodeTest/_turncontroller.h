#ifndef _TURNCONTROLLER_H
#define _TURNCONTROLLER_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1206678562_H
#define TOP_LEVEL_PREAMBLE_1206678562_H
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
} _turncontroller_reflect_t;
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
} _turncontroller_calibrate_t;
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
} _turncontroller_lp_t;
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
} _turncontroller_rp_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _turncontroller_notify_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _turncontroller_state_display_t;
typedef struct {
    struct self_base_t base;
#line 95 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_turncontroller.h"
    #line 28 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    int threshold;
    #line 31 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    float forward_speed;
    #line 32 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    float turn_speed;
    #line 35 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    bool last_left_high;
    #line 38 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    int turn_count;
#line 106 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_turncontroller.h"
    _turncontroller_reflect_t* _lf_reflect;
    // width of -2 indicates that it is not a multiport.
    int _lf_reflect_width;
    // Default input (in case it does not get connected)
    _turncontroller_reflect_t _lf_default__reflect;
    _turncontroller_calibrate_t _lf_calibrate;
    int _lf_calibrate_width;
    _turncontroller_lp_t _lf_lp;
    int _lf_lp_width;
    _turncontroller_rp_t _lf_rp;
    int _lf_rp_width;
    _turncontroller_notify_t _lf_notify;
    int _lf_notify_width;
    _turncontroller_state_display_t _lf_state_display;
    int _lf_state_display_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    reaction_t _lf__reaction_3;
    reaction_t _lf__reaction_4;
    trigger_t _lf__end_calibration;
    reaction_t* _lf__end_calibration_reactions[1];
    trigger_t _lf__start_test;
    reaction_t* _lf__start_test_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__reflect;
    reaction_t* _lf__reflect_reactions[2];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    reactor_mode_t _lf__modes[3];
} _turncontroller_self_t;
_turncontroller_self_t* new__turncontroller();
#endif // _TURNCONTROLLER_H
