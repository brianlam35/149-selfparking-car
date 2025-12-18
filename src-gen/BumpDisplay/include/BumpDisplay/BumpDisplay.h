#ifndef _bumpdisplay_main_H
#define _bumpdisplay_main_H
#ifndef _BUMPDISPLAY_MAIN_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_1358169683_H
#define TOP_LEVEL_PREAMBLE_1358169683_H
/*Correspondence: Range: [(18, 2), (19, 16)) -> Range: [(0, 0), (1, 16)) (verbatim=true; src=/home/lambrian/149-selfparking-car/src/BumpDisplay.lf)*/#include "pico/stdlib.h"
#include "i2c.h"
#endif // TOP_LEVEL_PREAMBLE_1358169683_H
#ifndef TOP_LEVEL_PREAMBLE_660915526_H
#define TOP_LEVEL_PREAMBLE_660915526_H
/*Correspondence: Range: [(22, 2), (23, 9)) -> Range: [(0, 0), (1, 9)) (verbatim=true; src=/home/lambrian/149-selfparking-car/src/lib/Bump.lf)*/#include <ir_sensors.h>
// others
#endif // TOP_LEVEL_PREAMBLE_660915526_H
#ifndef TOP_LEVEL_PREAMBLE_223783590_H
#define TOP_LEVEL_PREAMBLE_223783590_H
/*Correspondence: Range: [(18, 2), (19, 68)) -> Range: [(0, 0), (1, 68)) (verbatim=true; src=/home/lambrian/149-selfparking-car/src/lib/Display.lf)*/#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_223783590_H
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct bumpdisplay_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    int end[0]; // placeholder; MSVC does not compile empty structs
} bumpdisplay_self_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_action_internal_t _base;
    self_base_t* parent;
    bool has_value;
    int source_id;

    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} bumpdisplay_clear_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} bump_calibrate_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} bump_left_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} bump_right_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line0_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line1_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line2_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line3_t;
#endif
#endif
