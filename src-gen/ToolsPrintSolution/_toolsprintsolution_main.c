#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/ToolsPrintSolution/ToolsPrintSolution.h"
#include "_toolsprintsolution_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _toolsprintsolution_mainreaction_function_0(void* instance_args) {
    _toolsprintsolution_main_main_self_t* self = (_toolsprintsolution_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 27 "/home/lambrian/149-selfparking-car/src/ToolsPrintSolution.lf"
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
#line 16 "/home/lambrian/149-selfparking-car/src-gen/ToolsPrintSolution/_toolsprintsolution_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _toolsprintsolution_mainreaction_function_1(void* instance_args) {
    _toolsprintsolution_main_main_self_t* self = (_toolsprintsolution_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 32 "/home/lambrian/149-selfparking-car/src/ToolsPrintSolution.lf"
    self->led_on = true;
    printf("LED State: %b\n", self->led_on);
    gpio_put(PICO_DEFAULT_LED_PIN, true);
#line 27 "/home/lambrian/149-selfparking-car/src-gen/ToolsPrintSolution/_toolsprintsolution_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _toolsprintsolution_mainreaction_function_2(void* instance_args) {
    _toolsprintsolution_main_main_self_t* self = (_toolsprintsolution_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 38 "/home/lambrian/149-selfparking-car/src/ToolsPrintSolution.lf"
    self->led_on = false;
    printf("LED State: %b\n", self->led_on);
    gpio_put(PICO_DEFAULT_LED_PIN, false);
#line 38 "/home/lambrian/149-selfparking-car/src-gen/ToolsPrintSolution/_toolsprintsolution_main.c"
}
#include "include/api/reaction_macros_undef.h"
_toolsprintsolution_main_main_self_t* new__toolsprintsolution_main() {
    _toolsprintsolution_main_main_self_t* self = (_toolsprintsolution_main_main_self_t*)lf_new_reactor(sizeof(_toolsprintsolution_main_main_self_t));
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _toolsprintsolution_mainreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _toolsprintsolution_mainreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _toolsprintsolution_mainreaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = NULL;
    self->_lf__on.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__on.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__on_reactions[0] = &self->_lf__reaction_1;
    self->_lf__on.reactions = &self->_lf__on_reactions[0];
    self->_lf__on.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__on.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__on.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__on.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__off.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__off.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__off_reactions[0] = &self->_lf__reaction_2;
    self->_lf__off.reactions = &self->_lf__off_reactions[0];
    self->_lf__off.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__off.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__off.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__off.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
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
