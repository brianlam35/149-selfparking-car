#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/Bump/Bump.h"
#include "_bump.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _bumpreaction_function_0(void* instance_args) {
    _bump_self_t* self = (_bump_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _bump_calibrate_t* calibrate = self->_lf_calibrate;
    int calibrate_width = self->_lf_calibrate_width; SUPPRESS_UNUSED_WARNING(calibrate_width);
    #line 34 "/home/lambrian/149-selfparking-car/src/lib/Bump.lf"
    bump_sensors_calibrate();
#line 16 "/home/lambrian/149-selfparking-car/src-gen/BumpDisplay/_bump.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _bumpreaction_function_1(void* instance_args) {
    _bump_self_t* self = (_bump_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _bump_left_t* left = &self->_lf_left;
    _bump_right_t* right = &self->_lf_right;
    #line 38 "/home/lambrian/149-selfparking-car/src/lib/Bump.lf"
    bump_sensors_read();
    // only is_present when pressed
    if (bump_sensor_left_is_pressed()) {
        lf_set(left, true);
    }
    if (bump_sensor_right_is_pressed()) {
        lf_set(right, true);
    }
#line 33 "/home/lambrian/149-selfparking-car/src-gen/BumpDisplay/_bump.c"
}
#include "include/api/reaction_macros_undef.h"
_bump_self_t* new__bump() {
    _bump_self_t* self = (_bump_self_t*)lf_new_reactor(sizeof(_bump_self_t));
    // Set input by default to an always absent default input.
    self->_lf_calibrate = &self->_lf_default__calibrate;
    // Set the default source reactor pointer
    self->_lf_default__calibrate._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _bumpreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _bumpreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__t1.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t1.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__t1_reactions[0] = &self->_lf__reaction_1;
    self->_lf__t1.reactions = &self->_lf__t1_reactions[0];
    self->_lf__t1.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__t1.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__t1.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t1.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    self->_lf__calibrate.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__calibrate.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__calibrate_reactions[0] = &self->_lf__reaction_0;
    self->_lf__calibrate.reactions = &self->_lf__calibrate_reactions[0];
    self->_lf__calibrate.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__calibrate.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__calibrate.tmplt.type.element_size = sizeof(bool);
    return self;
}
