#ifndef _I2C_TEST_MAIN_H
#define _I2C_TEST_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#ifndef TOP_LEVEL_PREAMBLE_208301085_H
#define TOP_LEVEL_PREAMBLE_208301085_H
#include <pico/stdlib.h>
#include <hardware/i2c.h>
#endif // TOP_LEVEL_PREAMBLE_208301085_H
#ifndef TOP_LEVEL_PREAMBLE_681564936_H
#define TOP_LEVEL_PREAMBLE_681564936_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_681564936_H
typedef struct {
    struct self_base_t base;
#line 18 "/home/lambrian/149-selfparking-car/src-gen/I2C_test/_i2c_test_main.h"
#line 19 "/home/lambrian/149-selfparking-car/src-gen/I2C_test/_i2c_test_main.h"
    struct {
        _display_line0_t line0;
        _display_line1_t line1;
    } _lf_disp;
    int _lf_disp_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__t;
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _i2c_test_main_main_self_t;
_i2c_test_main_main_self_t* new__i2c_test_main();
#endif // _I2C_TEST_MAIN_H
