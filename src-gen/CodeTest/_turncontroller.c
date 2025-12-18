#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/CodeTest/TurnController.h"
#include "_turncontroller.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _turncontrollerreaction_function_0(void* instance_args) {
    _turncontroller_self_t* self = (_turncontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _turncontroller_calibrate_t* calibrate = &self->_lf_calibrate;
    _turncontroller_lp_t* lp = &self->_lf_lp;
    _turncontroller_rp_t* rp = &self->_lf_rp;
    _turncontroller_notify_t* notify = &self->_lf_notify;
    _turncontroller_state_display_t* state_display = &self->_lf_state_display;
    #line 44 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    lf_set(calibrate, true);
    lf_set(lp, 0.0f);
    lf_set(rp, 0.0f);
    lf_set(notify, "CALIBRATING");
    lf_set(state_display, "WAIT");
    printf("=== LEFT TURN TEST ===\n");
#line 24 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_turncontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _turncontrollerreaction_function_1(void* instance_args) {
    _turncontroller_self_t* self = (_turncontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _turncontroller_calibrate_t* calibrate = &self->_lf_calibrate;
    _turncontroller_notify_t* notify = &self->_lf_notify;
    _turncontroller_state_display_t* state_display = &self->_lf_state_display;
    #line 53 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    lf_set(calibrate, false);
    lf_set(notify, "READY");
    lf_set(state_display, "WAIT");
    printf("Calibration done, waiting...\n");
#line 38 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_turncontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _turncontrollerreaction_function_2(void* instance_args) {
    _turncontroller_self_t* self = (_turncontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    reactor_mode_t* FOLLOW = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_FOLLOW_change_type = reset_transition;
    _turncontroller_lp_t* lp = &self->_lf_lp;
    _turncontroller_rp_t* rp = &self->_lf_rp;
    _turncontroller_notify_t* notify = &self->_lf_notify;
    _turncontroller_state_display_t* state_display = &self->_lf_state_display;
    #line 64 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    printf("Starting FOLLOW mode\n");
    self->last_left_high = false;
    self->turn_count = 0;
    lf_set(notify, "FOLLOW T:0");
    lf_set(state_display, "FOLLOW");
    lf_set_mode(FOLLOW);
#line 57 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_turncontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _turncontrollerreaction_function_3(void* instance_args) {
    _turncontroller_self_t* self = (_turncontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _turncontroller_reflect_t* reflect = self->_lf_reflect;
    int reflect_width = self->_lf_reflect_width; SUPPRESS_UNUSED_WARNING(reflect_width);
    _turncontroller_lp_t* lp = &self->_lf_lp;
    _turncontroller_rp_t* rp = &self->_lf_rp;
    _turncontroller_notify_t* notify = &self->_lf_notify;
    _turncontroller_state_display_t* state_display = &self->_lf_state_display;
    reactor_mode_t* TURN_LEFT = &self->_lf__modes[2];
    lf_mode_change_type_t _lf_TURN_LEFT_change_type = reset_transition;
    #line 78 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    int L0 = reflect->value[0];
    
    bool left_high = (L0 > self->threshold);
    bool left_rising = (left_high && !self->last_left_high);
    
    // Hard-coded forward motion
    lf_set(lp, self->forward_speed);
    lf_set(rp, self->forward_speed);
    
    // Check for rising edge on sensor 0 ONLY
    if (left_rising) {
      self->turn_count++;
      printf("SENSOR 0 TRIGGERED #%d -> TURN_LEFT\n", self->turn_count);
    
      char msg[20];
      snprintf(msg, sizeof(msg), "TURN! T:%d", self->turn_count);
      lf_set(notify, msg);
      lf_set(state_display, "TURN_LEFT");
      lf_set_mode(TURN_LEFT);
    }
    
    // Update edge detection state
    self->last_left_high = left_high;
#line 95 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_turncontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _turncontrollerreaction_function_4(void* instance_args) {
    _turncontroller_self_t* self = (_turncontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _turncontroller_reflect_t* reflect = self->_lf_reflect;
    int reflect_width = self->_lf_reflect_width; SUPPRESS_UNUSED_WARNING(reflect_width);
    _turncontroller_lp_t* lp = &self->_lf_lp;
    _turncontroller_rp_t* rp = &self->_lf_rp;
    _turncontroller_notify_t* notify = &self->_lf_notify;
    _turncontroller_state_display_t* state_display = &self->_lf_state_display;
    reactor_mode_t* FOLLOW = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_FOLLOW_change_type = reset_transition;
    #line 111 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    int L0 = reflect->value[0];
    int CL = reflect->value[1];
    int C  = reflect->value[2];
    int CR = reflect->value[3];
    
    bool left_high = (L0 > self->threshold);
    bool cl_high = (CL > self->threshold);
    bool c_high  = (C  > self->threshold);
    bool cr_high = (CR > self->threshold);
    bool all_front_on_line = (cl_high && c_high && cr_high);
    
    // Hard-coded left turn: left wheel stopped, right wheel forward
    lf_set(lp, 0.0f);
    lf_set(rp, self->turn_speed);
    
    // Turn complete when:
    // 1. Sensor 0 is OFF (rotated past the black tape)
    // 2. AND all front sensors see the line
    if (!left_high && all_front_on_line) {
      printf("TURN COMPLETE (L0 white + front on line) -> FOLLOW\n");
    
      // Reset edge detection so sensor 0 can trigger again
      self->last_left_high = false;
    
      char msg[20];
      snprintf(msg, sizeof(msg), "FOLLOW T:%d", self->turn_count);
      lf_set(notify, msg);
      lf_set(state_display, "FOLLOW");
      lf_set_mode(FOLLOW);
    }
#line 140 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_turncontroller.c"
}
#include "include/api/reaction_macros_undef.h"
_turncontroller_self_t* new__turncontroller() {
    _turncontroller_self_t* self = (_turncontroller_self_t*)lf_new_reactor(sizeof(_turncontroller_self_t));
    // Set input by default to an always absent default input.
    self->_lf_reflect = &self->_lf_default__reflect;
    // Set the default source reactor pointer
    self->_lf_default__reflect._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _turncontrollerreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _turncontrollerreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _turncontrollerreaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = &self->_lf__modes[0];
    self->_lf__reaction_3.number = 3;
    self->_lf__reaction_3.function = _turncontrollerreaction_function_3;
    self->_lf__reaction_3.self = self;
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    self->_lf__reaction_3.STP_handler = NULL;
    self->_lf__reaction_3.name = "?";
    self->_lf__reaction_3.mode = &self->_lf__modes[1];
    self->_lf__reaction_4.number = 4;
    self->_lf__reaction_4.function = _turncontrollerreaction_function_4;
    self->_lf__reaction_4.self = self;
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    self->_lf__reaction_4.STP_handler = NULL;
    self->_lf__reaction_4.name = "?";
    self->_lf__reaction_4.mode = &self->_lf__modes[2];
    self->_lf__end_calibration.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__end_calibration.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__end_calibration_reactions[0] = &self->_lf__reaction_1;
    self->_lf__end_calibration.reactions = &self->_lf__end_calibration_reactions[0];
    self->_lf__end_calibration.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__end_calibration.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__end_calibration.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__end_calibration.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__start_test.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__start_test.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__start_test_reactions[0] = &self->_lf__reaction_2;
    self->_lf__start_test.reactions = &self->_lf__start_test_reactions[0];
    self->_lf__start_test.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__start_test.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__start_test.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__start_test.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    self->_lf__reflect.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__reflect.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__reflect_reactions[0] = &self->_lf__reaction_3;
    self->_lf__reflect_reactions[1] = &self->_lf__reaction_4;
    self->_lf__reflect.reactions = &self->_lf__reflect_reactions[0];
    self->_lf__reflect.number_of_reactions = 2;
    #ifdef FEDERATED
    self->_lf__reflect.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__reflect.tmplt.type.element_size = sizeof(uint16_t);
    // Initialize modes
    self_base_t* _lf_self_base = (self_base_t*)self;
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[0].name = "WAITING";
    self->_lf__modes[0].deactivation_time = 0;
    self->_lf__modes[0].flags = 0;
    self->_lf__modes[1].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[1].name = "FOLLOW";
    self->_lf__modes[1].deactivation_time = 0;
    self->_lf__modes[1].flags = 0;
    self->_lf__modes[2].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[2].name = "TURN_LEFT";
    self->_lf__modes[2].deactivation_time = 0;
    self->_lf__modes[2].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}
