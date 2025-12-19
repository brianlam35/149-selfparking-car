#ifndef _PARKINGCONTROLLER_H
#define _PARKINGCONTROLLER_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1206678562_H
#define TOP_LEVEL_PREAMBLE_1206678562_H
#include <pico/stdlib.h>
#include <stdlib.h>
#include "pico/time.h"
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
} _parkingcontroller_reflect_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _parkingcontroller_target_spot_t;
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
} _parkingcontroller_calibrate_t;
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
} _parkingcontroller_lp_t;
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
} _parkingcontroller_rp_t;
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
} _parkingcontroller_notify_t;
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
} _parkingcontroller_state_display_t;
typedef struct {
    struct self_base_t base;
#line 111 "/home/lambrian/149-selfparking-car/src-gen/random/_parkingcontroller.h"
    #line 57 "/home/lambrian/149-selfparking-car/src/random.lf"
    int threshold;
    #line 58 "/home/lambrian/149-selfparking-car/src/random.lf"
    float forward_speed;
    #line 59 "/home/lambrian/149-selfparking-car/src/random.lf"
    float turn_speed;
    #line 60 "/home/lambrian/149-selfparking-car/src/random.lf"
    float backup_speed;
    #line 63 "/home/lambrian/149-selfparking-car/src/random.lf"
    int parking_spot;
    #line 64 "/home/lambrian/149-selfparking-car/src/random.lf"
    int spot_count;
    #line 65 "/home/lambrian/149-selfparking-car/src/random.lf"
    int turn_count;
    #line 66 "/home/lambrian/149-selfparking-car/src/random.lf"
    int exit_count;
    #line 67 "/home/lambrian/149-selfparking-car/src/random.lf"
    bool last_left_high;
    #line 68 "/home/lambrian/149-selfparking-car/src/random.lf"
    bool last_right_high;
#line 132 "/home/lambrian/149-selfparking-car/src-gen/random/_parkingcontroller.h"
    _parkingcontroller_reflect_t* _lf_reflect;
    // width of -2 indicates that it is not a multiport.
    int _lf_reflect_width;
    // Default input (in case it does not get connected)
    _parkingcontroller_reflect_t _lf_default__reflect;
    _parkingcontroller_target_spot_t* _lf_target_spot;
    // width of -2 indicates that it is not a multiport.
    int _lf_target_spot_width;
    // Default input (in case it does not get connected)
    _parkingcontroller_target_spot_t _lf_default__target_spot;
    _parkingcontroller_calibrate_t _lf_calibrate;
    int _lf_calibrate_width;
    _parkingcontroller_lp_t _lf_lp;
    int _lf_lp_width;
    _parkingcontroller_rp_t _lf_rp;
    int _lf_rp_width;
    _parkingcontroller_notify_t _lf_notify;
    int _lf_notify_width;
    _parkingcontroller_state_display_t _lf_state_display;
    int _lf_state_display_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    reaction_t _lf__reaction_3;
    reaction_t _lf__reaction_4;
    reaction_t _lf__reaction_5;
    reaction_t _lf__reaction_6;
    reaction_t _lf__reaction_7;
    reaction_t _lf__reaction_8;
    reaction_t _lf__reaction_9;
    reaction_t _lf__reaction_10;
    reaction_t _lf__reaction_11;
    reaction_t _lf__reaction_12;
    reaction_t _lf__reaction_13;
    trigger_t _lf__end_calibration;
    reaction_t* _lf__end_calibration_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__reflect;
    reaction_t* _lf__reflect_reactions[10];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__target_spot;
    reaction_t* _lf__target_spot_reactions[2];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    reactor_mode_t _lf__modes[12];
} _parkingcontroller_self_t;
_parkingcontroller_self_t* new__parkingcontroller();
#endif // _PARKINGCONTROLLER_H
