#ifndef _UART_TEST_MAIN_H
#define _UART_TEST_MAIN_H
#include "include/core/reactor.h"

typedef struct {
    struct self_base_t base;
#line 8 "/home/lambrian/149-selfparking-car/src-gen/UART_Test/_uart_test_main.h"
#line 9 "/home/lambrian/149-selfparking-car/src-gen/UART_Test/_uart_test_main.h"
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__poll;
    reaction_t* _lf__poll_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _uart_test_main_main_self_t;
_uart_test_main_main_self_t* new__uart_test_main();
#endif // _UART_TEST_MAIN_H
