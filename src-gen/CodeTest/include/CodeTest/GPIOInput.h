#ifndef _gpioinput_H
#define _gpioinput_H
#ifndef _GPIOINPUT_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_1206678562_H
#define TOP_LEVEL_PREAMBLE_1206678562_H
/*Correspondence: Range: [(40, 2), (40, 26)) -> Range: [(0, 0), (0, 24)) (verbatim=true; src=/home/lambrian/149-selfparking-car/src/CodeTest.lf)*/#include <pico/stdlib.h>
#endif // TOP_LEVEL_PREAMBLE_1206678562_H
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct gpioinput_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    bool initialized;
    int last_spot;
    int end[0]; // placeholder; MSVC does not compile empty structs
} gpioinput_self_t;
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
} gpioinput_spot_t;
#endif
#endif
