#ifndef _CODETEST_MAIN_H
#define _CODETEST_MAIN_H
#include "include/core/reactor.h"
#include "_motorarbiter.h"
#include "_encoders.h"
#include "_parkingcontroller.h"
#include "_display.h"
#include "_linefollower.h"
#include "_motorswithfeedback.h"
#include "_line.h"
#ifndef TOP_LEVEL_PREAMBLE_1206678562_H
#define TOP_LEVEL_PREAMBLE_1206678562_H
#include <math.h>
#include <stdlib.h>
#include <pico/stdlib.h>
#endif // TOP_LEVEL_PREAMBLE_1206678562_H



#ifndef TOP_LEVEL_PREAMBLE_1553646796_H
#define TOP_LEVEL_PREAMBLE_1553646796_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_1553646796_H
#ifndef TOP_LEVEL_PREAMBLE_161938368_H
#define TOP_LEVEL_PREAMBLE_161938368_H
#include <math.h>
#define WHEEL_DIAMETER 0.032 // meters
#define COUNTS_PER_REV 360 //CPR
#define TICKS_PER_METER (WHEEL_DIAMETER * M_PI) / COUNTS_PER_REV
#endif // TOP_LEVEL_PREAMBLE_161938368_H
#ifndef TOP_LEVEL_PREAMBLE_854640632_H
#define TOP_LEVEL_PREAMBLE_854640632_H
#include <motors.h>
#include <math.h>
#endif // TOP_LEVEL_PREAMBLE_854640632_H


#ifndef TOP_LEVEL_PREAMBLE_1449664175_H
#define TOP_LEVEL_PREAMBLE_1449664175_H
#include <math.h>
#include <hardware/pio.h>
#include <quadrature_encoder.pio.h>

// pin defines
#define RIGHT_ENCODER_AB 8
#define LEFT_ENCODER_AB 12
#define RIGHT_SM 0
#define LEFT_SM 1
#endif // TOP_LEVEL_PREAMBLE_1449664175_H
#ifndef TOP_LEVEL_PREAMBLE_956337311_H
#define TOP_LEVEL_PREAMBLE_956337311_H
#include <ir_sensors.h>
#endif // TOP_LEVEL_PREAMBLE_956337311_H
typedef struct {
    struct self_base_t base;
#line 58 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_codetest_main.h"
#line 59 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_codetest_main.h"
    struct {
        _parkingcontroller_target_spot_t target_spot;
    } _lf_controller;
    int _lf_controller_width;
    struct {
        _encoders_trigger_t trigger;
    } _lf_encoder;
    int _lf_encoder_width;
    struct {
        _line_trigger_t trigger;
    } _lf_line;
    int _lf_line_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    trigger_t _lf__t;
    reaction_t* _lf__t_reactions[2];
    trigger_t _lf__send_target;
    reaction_t* _lf__send_target_reactions[1];
} _codetest_main_main_self_t;
_codetest_main_main_self_t* new__codetest_main();
#endif // _CODETEST_MAIN_H
