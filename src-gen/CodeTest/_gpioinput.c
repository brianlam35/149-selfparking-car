#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/CodeTest/GPIOInput.h"
#include "_gpioinput.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _gpioinputreaction_function_0(void* instance_args) {
    _gpioinput_self_t* self = (_gpioinput_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 709 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    // Initialize GPIO pins as inputs with pull-down resistors
    gpio_init(26);
    gpio_set_dir(26, GPIO_IN);
    gpio_pull_down(26);
    
    gpio_init(22);
    gpio_set_dir(22, GPIO_IN);
    gpio_pull_down(22);
    
    gpio_init(21);
    gpio_set_dir(21, GPIO_IN);
    gpio_pull_down(21);
    
    gpio_init(20);
    gpio_set_dir(20, GPIO_IN);
    gpio_pull_down(20);
    
    gpio_init(19);
    gpio_set_dir(19, GPIO_IN);
    gpio_pull_down(19);
    
    gpio_init(18);
    gpio_set_dir(18, GPIO_IN);
    gpio_pull_down(18);
    
    gpio_init(17);
    gpio_set_dir(17, GPIO_IN);
    gpio_pull_down(17);
    
    gpio_init(16);
    gpio_set_dir(16, GPIO_IN);
    gpio_pull_down(16);
    
    gpio_init(23);
    gpio_set_dir(23, GPIO_IN);
    gpio_pull_down(23);
    
    self->initialized = true;
    printf("GPIO input initialized\n");
#line 53 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_gpioinput.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _gpioinputreaction_function_1(void* instance_args) {
    _gpioinput_self_t* self = (_gpioinput_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _gpioinput_spot_t* spot = &self->_lf_spot;
    #line 751 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    if (!self->initialized) return;
    
    int detected_spot = 0;
    
    // Check each GPIO pin and map to spot number
    if (gpio_get(26)) detected_spot = 1;
    else if (gpio_get(22)) detected_spot = 2;
    else if (gpio_get(21)) detected_spot = 3;
    else if (gpio_get(20)) detected_spot = 4;
    else if (gpio_get(19)) detected_spot = 5;
    else if (gpio_get(18)) detected_spot = 6;
    else if (gpio_get(17)) detected_spot = 7;
    else if (gpio_get(16)) detected_spot = 8;
    else if (gpio_get(23)) detected_spot = 9;
    
    // Only send if a new spot is detected (rising edge)
    if (detected_spot != 0 && detected_spot != self->last_spot) {
      printf("GPIO detected: Spot %d\n", detected_spot);
      lf_set(spot, detected_spot);
    }
    
    self->last_spot = detected_spot;
#line 83 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_gpioinput.c"
}
#include "include/api/reaction_macros_undef.h"
_gpioinput_self_t* new__gpioinput() {
    _gpioinput_self_t* self = (_gpioinput_self_t*)lf_new_reactor(sizeof(_gpioinput_self_t));
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _gpioinputreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _gpioinputreaction_function_1;
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
