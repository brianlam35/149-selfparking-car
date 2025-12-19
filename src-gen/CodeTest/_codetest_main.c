#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/CodeTest/CodeTest.h"
#include "_codetest_main.h"
// *********** From the preamble, verbatim:
#line 694 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
#include "pico/time.h"
#line 10 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_codetest_main.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _codetest_mainreaction_function_0(void* instance_args) {
    _codetest_main_main_self_t* self = (_codetest_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct controller {
        _parkingcontroller_target_spot_t* target_spot;
    
    } controller;
    controller.target_spot = &(self->_lf_controller.target_spot);
    #line 709 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    // Fixed list of spots
    static const int spot_list[] = {9, 4, 6, 3, 2, 1, 8};
    static const int list_size = 7;
    gpio_set_function(29, GPIO_FUNC_UART);
    uart_init(uart0, 115200);
    uart_set_format(uart0, 8, 1, UART_PARITY_NONE);
    uart_set_fifo_enabled(uart0, true);
    uint8_t last;
    bool got = false;
    while (uart_is_readable(uart0)){
      last = (uint8_t) uart_getc(uart0);
      got = true;
    }
    
    // Use microsecond timer to pick index - different each reset
    
    
    if (got){
      lf_set(controller.target_spot, last);
    }
#line 44 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_codetest_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _codetest_mainreaction_function_1(void* instance_args) {
    _codetest_main_main_self_t* self = (_codetest_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct encoder {
        _encoders_trigger_t* trigger;
    
    } encoder;
    encoder.trigger = &(self->_lf_encoder.trigger);
    #line 750 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    lf_set(encoder.trigger, true);
#line 57 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_codetest_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _codetest_mainreaction_function_2(void* instance_args) {
    _codetest_main_main_self_t* self = (_codetest_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_trigger_t* trigger;
    
    } line;
    line.trigger = &(self->_lf_line.trigger);
    #line 754 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    lf_set(line.trigger, true);
#line 70 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_codetest_main.c"
}
#include "include/api/reaction_macros_undef.h"
_codetest_main_main_self_t* new__codetest_main() {
    _codetest_main_main_self_t* self = (_codetest_main_main_self_t*)lf_new_reactor(sizeof(_codetest_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_controller_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_encoder_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_line_width = -2;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _codetest_mainreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _codetest_mainreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _codetest_mainreaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = NULL;
    self->_lf__t.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    self->_lf__t_reactions[1] = &self->_lf__reaction_2;
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    self->_lf__t.number_of_reactions = 2;
    #ifdef FEDERATED
    self->_lf__t.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__receive_target.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__receive_target.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__receive_target_reactions[0] = &self->_lf__reaction_0;
    self->_lf__receive_target.reactions = &self->_lf__receive_target_reactions[0];
    self->_lf__receive_target.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__receive_target.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__receive_target.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__receive_target.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    return self;
}
