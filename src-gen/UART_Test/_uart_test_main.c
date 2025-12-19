#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/UART_Test/UART_Test.h"
#include "_uart_test_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _uart_test_mainreaction_function_0(void* instance_args) {
    _uart_test_main_main_self_t* self = (_uart_test_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 14 "/home/lambrian/149-selfparking-car/src/UART_Test.lf"
    #include "pico/stdlib.h"
    #include "hardware/uart.h"
    #include "hardware/gpio.h"
    
    // UART0 on RP2040
    uart_init(uart0, 115200);
    
    // Default Pico UART0 pins:
    // TX = GP0, RX = GP1
    gpio_set_function(0, GPIO_FUNC_UART);
    gpio_set_function(1, GPIO_FUNC_UART);
    
    // Optional: make stdio go to USB/UART depending on your CMake/template setup
    // stdio_init_all();
#line 28 "/home/lambrian/149-selfparking-car/src-gen/UART_Test/_uart_test_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _uart_test_mainreaction_function_1(void* instance_args) {
    _uart_test_main_main_self_t* self = (_uart_test_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 31 "/home/lambrian/149-selfparking-car/src/UART_Test.lf"
    #include "hardware/uart.h"
    
    while (uart_is_readable(uart0)) {
      uint8_t b = uart_getc(uart0);
    
      // If your project/template has stdio enabled, printf works.
      // Otherwise, replace this with whatever logging you have set up.
      printf("RX: %u\n", (unsigned)b);
    }
#line 45 "/home/lambrian/149-selfparking-car/src-gen/UART_Test/_uart_test_main.c"
}
#include "include/api/reaction_macros_undef.h"
_uart_test_main_main_self_t* new__uart_test_main() {
    _uart_test_main_main_self_t* self = (_uart_test_main_main_self_t*)lf_new_reactor(sizeof(_uart_test_main_main_self_t));
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _uart_test_mainreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _uart_test_mainreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__poll.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__poll.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__poll_reactions[0] = &self->_lf__reaction_1;
    self->_lf__poll.reactions = &self->_lf__poll_reactions[0];
    self->_lf__poll.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__poll.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__poll.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__poll.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    return self;
}
