#ifndef _GPIOINPUT_H
#define _GPIOINPUT_H
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
    int value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _gpioinput_spot_t;
typedef struct {
    struct self_base_t base;
#line 25 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_gpioinput.h"
    #line 705 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    bool initialized;
    #line 706 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    int last_spot;
#line 30 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_gpioinput.h"
    _gpioinput_spot_t _lf_spot;
    int _lf_spot_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__poll;
    reaction_t* _lf__poll_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _gpioinput_self_t;
_gpioinput_self_t* new__gpioinput();
#endif // _GPIOINPUT_H
