#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/I2C_test/I2C_test.h"
#include "_i2c_test_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _i2c_test_mainreaction_function_0(void* instance_args) {
    _i2c_test_main_main_self_t* self = (_i2c_test_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line0_t* line0;
    
    } disp;
    disp.line0 = &(self->_lf_disp.line0);
    #line 20 "/home/lambrian/149-selfparking-car/src/I2C_test.lf"
    lf_set(disp.line0, "testing");
    i2c_init(i2c0, 100000);
    i2c_set_slave_mode(i2c0, true, 0x08);
    gpio_set_function(4, GPIO_FUNC_I2C);
    gpio_set_function(5, GPIO_FUNC_I2C);
    gpio_pull_up(4);
    gpio_pull_up(5);
#line 25 "/home/lambrian/149-selfparking-car/src-gen/I2C_test/_i2c_test_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _i2c_test_mainreaction_function_1(void* instance_args) {
    _i2c_test_main_main_self_t* self = (_i2c_test_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    
    } disp;
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    #line 30 "/home/lambrian/149-selfparking-car/src/I2C_test.lf"
    uint8_t buf[6]; 
    lf_set(disp.line0, buf);
    lf_set(disp.line1, "hello");
#line 42 "/home/lambrian/149-selfparking-car/src-gen/I2C_test/_i2c_test_main.c"
}
#include "include/api/reaction_macros_undef.h"
_i2c_test_main_main_self_t* new__i2c_test_main() {
    _i2c_test_main_main_self_t* self = (_i2c_test_main_main_self_t*)lf_new_reactor(sizeof(_i2c_test_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_disp_width = -2;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _i2c_test_mainreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _i2c_test_mainreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__t.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    self->_lf__t.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__t.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
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
