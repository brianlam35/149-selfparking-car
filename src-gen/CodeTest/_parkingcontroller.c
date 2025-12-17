#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/CodeTest/ParkingController.h"
#include "_parkingcontroller.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_0(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_calibrate_t* calibrate = &self->_lf_calibrate;
    _parkingcontroller_line_enable_t* line_enable = &self->_lf_line_enable;
    _parkingcontroller_lp_t* lp = &self->_lf_lp;
    _parkingcontroller_rp_t* rp = &self->_lf_rp;
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    _parkingcontroller_state_display_t* state_display = &self->_lf_state_display;
    #line 136 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    lf_set(calibrate, true);
    lf_set(line_enable, false);
    lf_set(lp, 0.0f);
    lf_set(rp, 0.0f);
    lf_set(notify, "LEFT:0");
    lf_set(state_display, "CALIBRATE");
    printf("=== PARKING GARAGE SYSTEM ===\n");
#line 26 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_1(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_calibrate_t* calibrate = &self->_lf_calibrate;
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    _parkingcontroller_state_display_t* state_display = &self->_lf_state_display;
    #line 146 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    lf_set(calibrate, false);
    lf_set(notify, "LEFT:0");
    lf_set(state_display, "READY");
    printf("System ready\n");
#line 40 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_2(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_target_spot_t* target_spot = self->_lf_target_spot;
    int target_spot_width = self->_lf_target_spot_width; SUPPRESS_UNUSED_WARNING(target_spot_width);
    reactor_mode_t* LINE_FOLLOW_1 = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_LINE_FOLLOW_1_change_type = reset_transition;
    _parkingcontroller_line_enable_t* line_enable = &self->_lf_line_enable;
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    _parkingcontroller_state_display_t* state_display = &self->_lf_state_display;
    #line 157 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    self->parking_spot = target_spot->value;
    self->left_trigger_count = 0;
    self->last_left_high = false;
    self->last_right_high = false;
    
    printf("\n>>> TARGET: Spot %d <<<\n", self->parking_spot);
    
    lf_set(notify, "LEFT:0");
    lf_set(line_enable, true);
    lf_set_mode(LINE_FOLLOW_1);
    lf_set(state_display, "FOLLOW_1");
#line 65 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_3(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_reflect_t* reflect = self->_lf_reflect;
    int reflect_width = self->_lf_reflect_width; SUPPRESS_UNUSED_WARNING(reflect_width);
    _parkingcontroller_line_enable_t* line_enable = &self->_lf_line_enable;
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    _parkingcontroller_state_display_t* state_display = &self->_lf_state_display;
    reactor_mode_t* TURN_LEFT_1 = &self->_lf__modes[2];
    lf_mode_change_type_t _lf_TURN_LEFT_1_change_type = reset_transition;
    #line 177 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    int L0 = reflect->value[0];
    
    bool left_high = (L0 > self->threshold);
    bool left_rising = (left_high && !self->last_left_high);
    
    if (left_rising) {
      // Triggered! Increment count and go to turn state
      self->left_trigger_count++;
    
      char msg[20];
      snprintf(msg, sizeof(msg), "LEFT:%d", self->left_trigger_count);
      lf_set(notify, msg);
      printf("LEFT TRIGGERED #%d -> TURN_LEFT_1\n", self->left_trigger_count);
    
      // Disable line follower and go to turn state
      lf_set(line_enable, false);
      lf_set_mode(TURN_LEFT_1);
      lf_set(state_display, "TURN_L_1");
    }
    
    self->last_left_high = left_high;
#line 100 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_4(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_reflect_t* reflect = self->_lf_reflect;
    int reflect_width = self->_lf_reflect_width; SUPPRESS_UNUSED_WARNING(reflect_width);
    _parkingcontroller_lp_t* lp = &self->_lf_lp;
    _parkingcontroller_rp_t* rp = &self->_lf_rp;
    _parkingcontroller_line_enable_t* line_enable = &self->_lf_line_enable;
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    _parkingcontroller_state_display_t* state_display = &self->_lf_state_display;
    reactor_mode_t* LINE_FOLLOW_2 = &self->_lf__modes[3];
    lf_mode_change_type_t _lf_LINE_FOLLOW_2_change_type = reset_transition;
    #line 207 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    int L0 = reflect->value[0];
    int CL = reflect->value[1];
    int C  = reflect->value[2];
    int CR = reflect->value[3];
    
    bool left_high = (L0 > self->threshold);
    bool center_line = (CL > self->threshold || C > self->threshold || CR > self->threshold);
    
    // JUST TURN - no counting, no triggering
    lf_set(lp, -self->turn_speed);
    lf_set(rp, self->turn_speed);
    
    // Turn complete when: center sees line AND left sensor is OFF
    if (center_line && !left_high) {
      printf("TURN_LEFT_1 complete -> LINE_FOLLOW_2\n");
    
      // Reset sensor state for fresh detection
      self->last_left_high = false;
      self->last_right_high = false;
    
      lf_set(line_enable, true);
      lf_set_mode(LINE_FOLLOW_2);
    
      char msg[20];
      snprintf(msg, sizeof(msg), "LEFT:%d", self->left_trigger_count);
      lf_set(notify, msg);
      lf_set(state_display, "FOLLOW_2");
    }
#line 144 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_5(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_reflect_t* reflect = self->_lf_reflect;
    int reflect_width = self->_lf_reflect_width; SUPPRESS_UNUSED_WARNING(reflect_width);
    _parkingcontroller_line_enable_t* line_enable = &self->_lf_line_enable;
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    _parkingcontroller_state_display_t* state_display = &self->_lf_state_display;
    reactor_mode_t* TURN_RIGHT_1 = &self->_lf__modes[4];
    lf_mode_change_type_t _lf_TURN_RIGHT_1_change_type = reset_transition;
    #line 244 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    int L0 = reflect->value[0];
    int R4 = reflect->value[4];
    
    bool left_high = (L0 > self->threshold);
    bool right_high = (R4 > self->threshold);
    bool left_rising = (left_high && !self->last_left_high);
    bool right_rising = (right_high && !self->last_right_high);
    
    // For spot 3: wait for RIGHT sensor to trigger, then turn right
    // For now, let's test with left sensor triggering
    if (left_rising) {
      self->left_trigger_count++;
    
      char msg[20];
      snprintf(msg, sizeof(msg), "LEFT:%d", self->left_trigger_count);
      lf_set(notify, msg);
      printf("LEFT TRIGGERED #%d -> TURN_RIGHT_1\n", self->left_trigger_count);
    
      lf_set(line_enable, false);
      lf_set_mode(TURN_RIGHT_1);
      lf_set(state_display, "TURN_R_1");
    }
    
    self->last_left_high = left_high;
    self->last_right_high = right_high;
#line 183 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_6(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_reflect_t* reflect = self->_lf_reflect;
    int reflect_width = self->_lf_reflect_width; SUPPRESS_UNUSED_WARNING(reflect_width);
    _parkingcontroller_lp_t* lp = &self->_lf_lp;
    _parkingcontroller_rp_t* rp = &self->_lf_rp;
    _parkingcontroller_line_enable_t* line_enable = &self->_lf_line_enable;
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    _parkingcontroller_state_display_t* state_display = &self->_lf_state_display;
    reactor_mode_t* PARK_FORWARD = &self->_lf__modes[5];
    lf_mode_change_type_t _lf_PARK_FORWARD_change_type = reset_transition;
    #line 277 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    int L0 = reflect->value[0];
    int CL = reflect->value[1];
    int C  = reflect->value[2];
    int CR = reflect->value[3];
    int R4 = reflect->value[4];
    
    bool right_high = (R4 > self->threshold);
    bool center_line = (CL > self->threshold || C > self->threshold || CR > self->threshold);
    
    // JUST TURN RIGHT - no counting, no triggering
    lf_set(lp, self->turn_speed);
    lf_set(rp, -self->turn_speed);
    
    // Turn complete when: center sees line AND right sensor is OFF
    if (center_line && !right_high) {
      printf("TURN_RIGHT_1 complete -> PARK_FORWARD\n");
    
      self->last_left_high = false;
      self->last_right_high = false;
    
      lf_set(line_enable, true);
      lf_set_mode(PARK_FORWARD);
    
      char msg[20];
      snprintf(msg, sizeof(msg), "LEFT:%d", self->left_trigger_count);
      lf_set(notify, msg);
      lf_set(state_display, "PARK_FWD");
    }
#line 227 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_7(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_reflect_t* reflect = self->_lf_reflect;
    int reflect_width = self->_lf_reflect_width; SUPPRESS_UNUSED_WARNING(reflect_width);
    _parkingcontroller_line_enable_t* line_enable = &self->_lf_line_enable;
    _parkingcontroller_lp_t* lp = &self->_lf_lp;
    _parkingcontroller_rp_t* rp = &self->_lf_rp;
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    _parkingcontroller_state_display_t* state_display = &self->_lf_state_display;
    reactor_mode_t* PARKED = &self->_lf__modes[6];
    lf_mode_change_type_t _lf_PARKED_change_type = reset_transition;
    #line 313 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    int L0 = reflect->value[0];
    int CL = reflect->value[1];
    int C  = reflect->value[2];
    int CR = reflect->value[3];
    int R4 = reflect->value[4];
    
    bool all_white = (L0 < self->threshold && CL < self->threshold && 
                     C < self->threshold && CR < self->threshold && R4 < self->threshold);
    
    if (all_white) {
      lf_set(line_enable, false);
      lf_set(lp, 0.0f);
      lf_set(rp, 0.0f);
      lf_set_mode(PARKED);
    
      char msg[20];
      snprintf(msg, sizeof(msg), "LEFT:%d DONE", self->left_trigger_count);
      lf_set(notify, msg);
      lf_set(state_display, "PARKED");
      printf("=== PARKED ===\n");
    }
#line 264 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_8(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_target_spot_t* target_spot = self->_lf_target_spot;
    int target_spot_width = self->_lf_target_spot_width; SUPPRESS_UNUSED_WARNING(target_spot_width);
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    #line 342 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    printf("Parked. Send 0 to exit (not implemented)\n");
#line 275 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
_parkingcontroller_self_t* new__parkingcontroller() {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)lf_new_reactor(sizeof(_parkingcontroller_self_t));
    // Set input by default to an always absent default input.
    self->_lf_reflect = &self->_lf_default__reflect;
    // Set the default source reactor pointer
    self->_lf_default__reflect._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_target_spot = &self->_lf_default__target_spot;
    // Set the default source reactor pointer
    self->_lf_default__target_spot._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _parkingcontrollerreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _parkingcontrollerreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _parkingcontrollerreaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = &self->_lf__modes[0];
    self->_lf__reaction_3.number = 3;
    self->_lf__reaction_3.function = _parkingcontrollerreaction_function_3;
    self->_lf__reaction_3.self = self;
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    self->_lf__reaction_3.STP_handler = NULL;
    self->_lf__reaction_3.name = "?";
    self->_lf__reaction_3.mode = &self->_lf__modes[1];
    self->_lf__reaction_4.number = 4;
    self->_lf__reaction_4.function = _parkingcontrollerreaction_function_4;
    self->_lf__reaction_4.self = self;
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    self->_lf__reaction_4.STP_handler = NULL;
    self->_lf__reaction_4.name = "?";
    self->_lf__reaction_4.mode = &self->_lf__modes[2];
    self->_lf__reaction_5.number = 5;
    self->_lf__reaction_5.function = _parkingcontrollerreaction_function_5;
    self->_lf__reaction_5.self = self;
    self->_lf__reaction_5.deadline_violation_handler = NULL;
    self->_lf__reaction_5.STP_handler = NULL;
    self->_lf__reaction_5.name = "?";
    self->_lf__reaction_5.mode = &self->_lf__modes[3];
    self->_lf__reaction_6.number = 6;
    self->_lf__reaction_6.function = _parkingcontrollerreaction_function_6;
    self->_lf__reaction_6.self = self;
    self->_lf__reaction_6.deadline_violation_handler = NULL;
    self->_lf__reaction_6.STP_handler = NULL;
    self->_lf__reaction_6.name = "?";
    self->_lf__reaction_6.mode = &self->_lf__modes[4];
    self->_lf__reaction_7.number = 7;
    self->_lf__reaction_7.function = _parkingcontrollerreaction_function_7;
    self->_lf__reaction_7.self = self;
    self->_lf__reaction_7.deadline_violation_handler = NULL;
    self->_lf__reaction_7.STP_handler = NULL;
    self->_lf__reaction_7.name = "?";
    self->_lf__reaction_7.mode = &self->_lf__modes[5];
    self->_lf__reaction_8.number = 8;
    self->_lf__reaction_8.function = _parkingcontrollerreaction_function_8;
    self->_lf__reaction_8.self = self;
    self->_lf__reaction_8.deadline_violation_handler = NULL;
    self->_lf__reaction_8.STP_handler = NULL;
    self->_lf__reaction_8.name = "?";
    self->_lf__reaction_8.mode = &self->_lf__modes[6];
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
    self->_lf__reflect_reactions[2] = &self->_lf__reaction_5;
    self->_lf__reflect_reactions[3] = &self->_lf__reaction_6;
    self->_lf__reflect_reactions[4] = &self->_lf__reaction_7;
    self->_lf__reflect.reactions = &self->_lf__reflect_reactions[0];
    self->_lf__reflect.number_of_reactions = 5;
    #ifdef FEDERATED
    self->_lf__reflect.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__reflect.tmplt.type.element_size = sizeof(uint16_t);
    self->_lf__target_spot.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__target_spot.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__target_spot_reactions[0] = &self->_lf__reaction_2;
    self->_lf__target_spot_reactions[1] = &self->_lf__reaction_8;
    self->_lf__target_spot.reactions = &self->_lf__target_spot_reactions[0];
    self->_lf__target_spot.number_of_reactions = 2;
    #ifdef FEDERATED
    self->_lf__target_spot.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__target_spot.tmplt.type.element_size = sizeof(int);
    // Initialize modes
    self_base_t* _lf_self_base = (self_base_t*)self;
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[0].name = "WAITING";
    self->_lf__modes[0].deactivation_time = 0;
    self->_lf__modes[0].flags = 0;
    self->_lf__modes[1].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[1].name = "LINE_FOLLOW_1";
    self->_lf__modes[1].deactivation_time = 0;
    self->_lf__modes[1].flags = 0;
    self->_lf__modes[2].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[2].name = "TURN_LEFT_1";
    self->_lf__modes[2].deactivation_time = 0;
    self->_lf__modes[2].flags = 0;
    self->_lf__modes[3].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[3].name = "LINE_FOLLOW_2";
    self->_lf__modes[3].deactivation_time = 0;
    self->_lf__modes[3].flags = 0;
    self->_lf__modes[4].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[4].name = "TURN_RIGHT_1";
    self->_lf__modes[4].deactivation_time = 0;
    self->_lf__modes[4].flags = 0;
    self->_lf__modes[5].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[5].name = "PARK_FORWARD";
    self->_lf__modes[5].deactivation_time = 0;
    self->_lf__modes[5].flags = 0;
    self->_lf__modes[6].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[6].name = "PARKED";
    self->_lf__modes[6].deactivation_time = 0;
    self->_lf__modes[6].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}
