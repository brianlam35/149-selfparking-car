#ifndef _linefollower_H
#define _linefollower_H
#ifndef _LINEFOLLOWER_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_1206678562_H
#define TOP_LEVEL_PREAMBLE_1206678562_H
/*Correspondence: Range: [(24, 2), (26, 24)) -> Range: [(0, 0), (2, 24)) (verbatim=true; src=/home/lambrian/149-selfparking-car/src/CodeTest.lf)*/#include <math.h>
#include <stdlib.h>
#include <pico/stdlib.h>
#endif // TOP_LEVEL_PREAMBLE_1206678562_H
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct linefollower_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    float kp;
    float ki;
    float kd;
    float base_speed;
    float max_speed;
    int threshold;
    float last_error;
    float integral;
    bool enabled;
    int end[0]; // placeholder; MSVC does not compile empty structs
} linefollower_self_t;
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
} linefollower_reflect_t;
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
} linefollower_enable_t;
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
} linefollower_lp_t;
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
} linefollower_rp_t;
#endif
#endif
