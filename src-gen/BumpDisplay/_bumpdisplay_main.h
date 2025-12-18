#ifndef _BUMPDISPLAY_MAIN_H
#define _BUMPDISPLAY_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#include "_bump.h"
#ifndef TOP_LEVEL_PREAMBLE_1358169683_H
#define TOP_LEVEL_PREAMBLE_1358169683_H
#include "pico/stdlib.h"
#include "i2c.h"
#endif // TOP_LEVEL_PREAMBLE_1358169683_H
#ifndef TOP_LEVEL_PREAMBLE_660915526_H
#define TOP_LEVEL_PREAMBLE_660915526_H
#include <ir_sensors.h>
// others
#endif // TOP_LEVEL_PREAMBLE_660915526_H
#ifndef TOP_LEVEL_PREAMBLE_223783590_H
#define TOP_LEVEL_PREAMBLE_223783590_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_223783590_H
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
} _bumpdisplay_main_clear_t;
typedef struct {
    struct self_base_t base;
#line 41 "/home/lambrian/149-selfparking-car/src-gen/BumpDisplay/_bumpdisplay_main.h"
#line 42 "/home/lambrian/149-selfparking-car/src-gen/BumpDisplay/_bumpdisplay_main.h"
    _bumpdisplay_main_clear_t _lf_clear;
    struct {
        _display_line0_t line0;
        _display_line1_t line1;
    } _lf_disp;
    int _lf_disp_width;
    struct {
        _bump_left_t* left;
        trigger_t left_trigger;
        reaction_t* left_reactions[1];
        _bump_right_t* right;
        trigger_t right_trigger;
        reaction_t* right_reactions[1];
    } _lf_bump;
    int _lf_bump_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    trigger_t _lf__clear;
    reaction_t* _lf__clear_reactions[1];
} _bumpdisplay_main_main_self_t;
_bumpdisplay_main_main_self_t* new__bumpdisplay_main();
#endif // _BUMPDISPLAY_MAIN_H
