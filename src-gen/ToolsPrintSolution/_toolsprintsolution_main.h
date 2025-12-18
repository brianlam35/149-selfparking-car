#ifndef _TOOLSPRINTSOLUTION_MAIN_H
#define _TOOLSPRINTSOLUTION_MAIN_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_523794808_H
#define TOP_LEVEL_PREAMBLE_523794808_H
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#endif // TOP_LEVEL_PREAMBLE_523794808_H
typedef struct {
    struct self_base_t base;
#line 13 "/home/lambrian/149-selfparking-car/src-gen/ToolsPrintSolution/_toolsprintsolution_main.h"
    #line 24 "/home/lambrian/149-selfparking-car/src/ToolsPrintSolution.lf"
    bool led_on;
#line 16 "/home/lambrian/149-selfparking-car/src-gen/ToolsPrintSolution/_toolsprintsolution_main.h"
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    trigger_t _lf__on;
    reaction_t* _lf__on_reactions[1];
    trigger_t _lf__off;
    reaction_t* _lf__off_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _toolsprintsolution_main_main_self_t;
_toolsprintsolution_main_main_self_t* new__toolsprintsolution_main();
#endif // _TOOLSPRINTSOLUTION_MAIN_H
