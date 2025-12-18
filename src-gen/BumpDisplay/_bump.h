#ifndef _BUMP_H
#define _BUMP_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_660915526_H
#define TOP_LEVEL_PREAMBLE_660915526_H
#include <ir_sensors.h>
// others
#endif // TOP_LEVEL_PREAMBLE_660915526_H
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
} _bump_calibrate_t;
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
} _bump_left_t;
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
} _bump_right_t;
typedef struct {
    struct self_base_t base;
    #line 27 "/home/lambrian/149-selfparking-car/src/lib/Bump.lf"
    interval_t sample_period;
#line 56 "/home/lambrian/149-selfparking-car/src-gen/BumpDisplay/_bump.h"
#line 57 "/home/lambrian/149-selfparking-car/src-gen/BumpDisplay/_bump.h"
    _bump_calibrate_t* _lf_calibrate;
    // width of -2 indicates that it is not a multiport.
    int _lf_calibrate_width;
    // Default input (in case it does not get connected)
    _bump_calibrate_t _lf_default__calibrate;
    _bump_left_t _lf_left;
    int _lf_left_width;
    _bump_right_t _lf_right;
    int _lf_right_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__t1;
    reaction_t* _lf__t1_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__calibrate;
    reaction_t* _lf__calibrate_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _bump_self_t;
_bump_self_t* new__bump();
#endif // _BUMP_H
