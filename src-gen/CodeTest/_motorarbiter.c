#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/CodeTest/MotorArbiter.h"
#include "_motorarbiter.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _motorarbiterreaction_function_0(void* instance_args) {
    _motorarbiter_self_t* self = (_motorarbiter_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _motorarbiter_use_line_follower_t* use_line_follower = self->_lf_use_line_follower;
    int use_line_follower_width = self->_lf_use_line_follower_width; SUPPRESS_UNUSED_WARNING(use_line_follower_width);
    #line 384 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    self->use_follower = use_line_follower->value;
#line 16 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_motorarbiter.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _motorarbiterreaction_function_1(void* instance_args) {
    _motorarbiter_self_t* self = (_motorarbiter_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _motorarbiter_controller_lp_t* controller_lp = self->_lf_controller_lp;
    int controller_lp_width = self->_lf_controller_lp_width; SUPPRESS_UNUSED_WARNING(controller_lp_width);
    _motorarbiter_controller_rp_t* controller_rp = self->_lf_controller_rp;
    int controller_rp_width = self->_lf_controller_rp_width; SUPPRESS_UNUSED_WARNING(controller_rp_width);
    _motorarbiter_lp_t* lp = &self->_lf_lp;
    _motorarbiter_rp_t* rp = &self->_lf_rp;
    #line 388 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    if (!self->use_follower) {
      if (controller_lp->is_present) lf_set(lp, controller_lp->value);
      if (controller_rp->is_present) lf_set(rp, controller_rp->value);
    }
#line 33 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_motorarbiter.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _motorarbiterreaction_function_2(void* instance_args) {
    _motorarbiter_self_t* self = (_motorarbiter_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _motorarbiter_line_follower_lp_t* line_follower_lp = self->_lf_line_follower_lp;
    int line_follower_lp_width = self->_lf_line_follower_lp_width; SUPPRESS_UNUSED_WARNING(line_follower_lp_width);
    _motorarbiter_line_follower_rp_t* line_follower_rp = self->_lf_line_follower_rp;
    int line_follower_rp_width = self->_lf_line_follower_rp_width; SUPPRESS_UNUSED_WARNING(line_follower_rp_width);
    _motorarbiter_lp_t* lp = &self->_lf_lp;
    _motorarbiter_rp_t* rp = &self->_lf_rp;
    #line 395 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    if (self->use_follower) {
      if (line_follower_lp->is_present) lf_set(lp, line_follower_lp->value);
      if (line_follower_rp->is_present) lf_set(rp, line_follower_rp->value);
    }
#line 50 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_motorarbiter.c"
}
#include "include/api/reaction_macros_undef.h"
_motorarbiter_self_t* new__motorarbiter() {
    _motorarbiter_self_t* self = (_motorarbiter_self_t*)lf_new_reactor(sizeof(_motorarbiter_self_t));
    // Set input by default to an always absent default input.
    self->_lf_controller_lp = &self->_lf_default__controller_lp;
    // Set the default source reactor pointer
    self->_lf_default__controller_lp._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_controller_rp = &self->_lf_default__controller_rp;
    // Set the default source reactor pointer
    self->_lf_default__controller_rp._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_line_follower_lp = &self->_lf_default__line_follower_lp;
    // Set the default source reactor pointer
    self->_lf_default__line_follower_lp._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_line_follower_rp = &self->_lf_default__line_follower_rp;
    // Set the default source reactor pointer
    self->_lf_default__line_follower_rp._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_use_line_follower = &self->_lf_default__use_line_follower;
    // Set the default source reactor pointer
    self->_lf_default__use_line_follower._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _motorarbiterreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _motorarbiterreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _motorarbiterreaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = NULL;
    self->_lf__controller_lp.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__controller_lp.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__controller_lp_reactions[0] = &self->_lf__reaction_1;
    self->_lf__controller_lp.reactions = &self->_lf__controller_lp_reactions[0];
    self->_lf__controller_lp.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__controller_lp.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__controller_lp.tmplt.type.element_size = sizeof(float);
    self->_lf__controller_rp.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__controller_rp.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__controller_rp_reactions[0] = &self->_lf__reaction_1;
    self->_lf__controller_rp.reactions = &self->_lf__controller_rp_reactions[0];
    self->_lf__controller_rp.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__controller_rp.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__controller_rp.tmplt.type.element_size = sizeof(float);
    self->_lf__line_follower_lp.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__line_follower_lp.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__line_follower_lp_reactions[0] = &self->_lf__reaction_2;
    self->_lf__line_follower_lp.reactions = &self->_lf__line_follower_lp_reactions[0];
    self->_lf__line_follower_lp.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__line_follower_lp.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__line_follower_lp.tmplt.type.element_size = sizeof(float);
    self->_lf__line_follower_rp.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__line_follower_rp.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__line_follower_rp_reactions[0] = &self->_lf__reaction_2;
    self->_lf__line_follower_rp.reactions = &self->_lf__line_follower_rp_reactions[0];
    self->_lf__line_follower_rp.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__line_follower_rp.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__line_follower_rp.tmplt.type.element_size = sizeof(float);
    self->_lf__use_line_follower.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__use_line_follower.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__use_line_follower_reactions[0] = &self->_lf__reaction_0;
    self->_lf__use_line_follower.reactions = &self->_lf__use_line_follower_reactions[0];
    self->_lf__use_line_follower.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__use_line_follower.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__use_line_follower.tmplt.type.element_size = sizeof(bool);
    return self;
}
