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
    _parkingcontroller_lp_t* lp = &self->_lf_lp;
    _parkingcontroller_rp_t* rp = &self->_lf_rp;
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    _parkingcontroller_state_display_t* state_display = &self->_lf_state_display;
    #line 73 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    lf_set(calibrate, true);
    lf_set(lp, 0.0f);
    lf_set(rp, 0.0f);
    lf_set(notify, "CALIBRATING");
    lf_set(state_display, "CALIB");
    printf("=== PARKING GARAGE ===\n");
#line 24 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_1(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_calibrate_t* calibrate = &self->_lf_calibrate;
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    _parkingcontroller_state_display_t* state_display = &self->_lf_state_display;
    #line 82 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    lf_set(calibrate, false);
    lf_set(notify, "READY");
    lf_set(state_display, "WAIT");
    printf("Ready - waiting for target\n");
#line 38 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_2(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_target_spot_t* target_spot = self->_lf_target_spot;
    int target_spot_width = self->_lf_target_spot_width; SUPPRESS_UNUSED_WARNING(target_spot_width);
    reactor_mode_t* FOLLOW_TO_SPOT_1 = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_FOLLOW_TO_SPOT_1_change_type = reset_transition;
    reactor_mode_t* FOLLOW_TO_CORRIDOR_2_5 = &self->_lf__modes[2];
    lf_mode_change_type_t _lf_FOLLOW_TO_CORRIDOR_2_5_change_type = reset_transition;
    reactor_mode_t* FOLLOW_TO_CORRIDOR_6_9 = &self->_lf__modes[3];
    lf_mode_change_type_t _lf_FOLLOW_TO_CORRIDOR_6_9_change_type = reset_transition;
    _parkingcontroller_lp_t* lp = &self->_lf_lp;
    _parkingcontroller_rp_t* rp = &self->_lf_rp;
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    _parkingcontroller_state_display_t* state_display = &self->_lf_state_display;
    #line 93 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    self->parking_spot = target_spot->value;
    self->spot_count = 0;
    self->turn_count = 0;
    self->last_left_high = false;
    self->last_right_high = false;
    
    printf("Target: Spot %d\n", self->parking_spot);
    
    char msg[20];
    snprintf(msg, sizeof(msg), "GO->%d", self->parking_spot);
    lf_set(notify, msg);
    
    if (self->parking_spot == 1) {
      // Spot 1: go straight
      lf_set(state_display, "TO S1");
      lf_set_mode(FOLLOW_TO_SPOT_1);
    } else if (self->parking_spot >= 2 && self->parking_spot <= 5) {
      // Spots 2-5: 1 left turn into corridor
      lf_set(state_display, "TO 2-5");
      lf_set_mode(FOLLOW_TO_CORRIDOR_2_5);
    } else if (self->parking_spot >= 6 && self->parking_spot <= 9) {
      // Spots 6-9: 3 left turns into corridor
      lf_set(state_display, "TO 6-9");
      lf_set_mode(FOLLOW_TO_CORRIDOR_6_9);
    }
#line 82 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_3(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_reflect_t* reflect = self->_lf_reflect;
    int reflect_width = self->_lf_reflect_width; SUPPRESS_UNUSED_WARNING(reflect_width);
    _parkingcontroller_lp_t* lp = &self->_lf_lp;
    _parkingcontroller_rp_t* rp = &self->_lf_rp;
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    _parkingcontroller_state_display_t* state_display = &self->_lf_state_display;
    reactor_mode_t* PARKED = &self->_lf__modes[11];
    lf_mode_change_type_t _lf_PARKED_change_type = reset_transition;
    #line 127 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    int L0 = reflect->value[0];
    int CL = reflect->value[1];
    int C  = reflect->value[2];
    int CR = reflect->value[3];
    int R4 = reflect->value[4];
    
    bool left_high = (L0 > self->threshold);
    bool left_rising = (left_high && !self->last_left_high);
    
    bool all_white = (L0 < self->threshold && CL < self->threshold && 
                     C < self->threshold && CR < self->threshold && R4 < self->threshold);
    
    // Line following using center 3 sensors
    bool cl_high = (CL > self->threshold);
    bool c_high  = (C  > self->threshold);
    bool cr_high = (CR > self->threshold);
    
    float left_power = self->forward_speed;
    float right_power = self->forward_speed;
    
    if (cl_high && !cr_high) {
      left_power = self->forward_speed * 0.5f;
      right_power = self->forward_speed;
    } else if (cr_high && !cl_high) {
      left_power = self->forward_speed;
      right_power = self->forward_speed * 0.5f;
    }
    
    lf_set(lp, left_power);
    lf_set(rp, right_power);
    
    // Count left triggers (to skip exit at count 1)
    if (left_rising) {
      self->spot_count++;
      char msg[20];
      snprintf(msg, sizeof(msg), "SKIP:%d", self->spot_count);
      lf_set(notify, msg);
      printf("Left trigger %d (skipping exit)\n", self->spot_count);
    }
    
    self->last_left_high = left_high;
    
    // Stop when line ends (spot 1 is at the end)
    if (all_white) {
      printf("=== PARKED IN SPOT 1 ===\n");
      lf_set(lp, 0.0f);
      lf_set(rp, 0.0f);
      lf_set(notify, "PARKED 1");
      lf_set(state_display, "DONE");
      lf_set_mode(PARKED);
    }
#line 148 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_4(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_reflect_t* reflect = self->_lf_reflect;
    int reflect_width = self->_lf_reflect_width; SUPPRESS_UNUSED_WARNING(reflect_width);
    _parkingcontroller_lp_t* lp = &self->_lf_lp;
    _parkingcontroller_rp_t* rp = &self->_lf_rp;
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    _parkingcontroller_state_display_t* state_display = &self->_lf_state_display;
    reactor_mode_t* TURN_LEFT = &self->_lf__modes[5];
    lf_mode_change_type_t _lf_TURN_LEFT_change_type = reset_transition;
    #line 188 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    int L0 = reflect->value[0];
    int CL = reflect->value[1];
    int C  = reflect->value[2];
    int CR = reflect->value[3];
    
    bool left_high = (L0 > self->threshold);
    bool left_rising = (left_high && !self->last_left_high);
    
    // Line following using center 3 sensors
    bool cl_high = (CL > self->threshold);
    bool c_high  = (C  > self->threshold);
    bool cr_high = (CR > self->threshold);
    
    float left_power = self->forward_speed;
    float right_power = self->forward_speed;
    
    if (cl_high && !cr_high) {
      left_power = self->forward_speed * 0.5f;
      right_power = self->forward_speed;
    } else if (cr_high && !cl_high) {
      left_power = self->forward_speed;
      right_power = self->forward_speed * 0.5f;
    }
    
    lf_set(lp, left_power);
    lf_set(rp, right_power);
    
    // Left sensor rising edge
    if (left_rising) {
      self->spot_count++;
    
      char msg[20];
      snprintf(msg, sizeof(msg), "CNT:%d", self->spot_count);
      lf_set(notify, msg);
      printf("Left trigger count=%d\n", self->spot_count);
    
      if (self->spot_count == 1) {
        // Skip exit
        printf("Skipping exit\n");
      } else if (self->spot_count == 2) {
        // Turn into corridor 2-5
        printf("Count 2 -> TURN_LEFT (into corridor 2-5)\n");
        lf_set(notify, "TURN->2-5");
        lf_set(state_display, "TURN_L");
        lf_set_mode(TURN_LEFT);
      }
    }
    
    self->last_left_high = left_high;
#line 212 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_5(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_reflect_t* reflect = self->_lf_reflect;
    int reflect_width = self->_lf_reflect_width; SUPPRESS_UNUSED_WARNING(reflect_width);
    _parkingcontroller_lp_t* lp = &self->_lf_lp;
    _parkingcontroller_rp_t* rp = &self->_lf_rp;
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    _parkingcontroller_state_display_t* state_display = &self->_lf_state_display;
    reactor_mode_t* TURN_LEFT_6_9 = &self->_lf__modes[4];
    lf_mode_change_type_t _lf_TURN_LEFT_6_9_change_type = reset_transition;
    #line 251 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    int L0 = reflect->value[0];
    int CL = reflect->value[1];
    int C  = reflect->value[2];
    int CR = reflect->value[3];
    
    bool left_high = (L0 > self->threshold);
    bool left_rising = (left_high && !self->last_left_high);
    
    // Line following using center 3 sensors
    bool cl_high = (CL > self->threshold);
    bool c_high  = (C  > self->threshold);
    bool cr_high = (CR > self->threshold);
    
    float left_power = self->forward_speed;
    float right_power = self->forward_speed;
    
    if (cl_high && !cr_high) {
      left_power = self->forward_speed * 0.5f;
      right_power = self->forward_speed;
    } else if (cr_high && !cl_high) {
      left_power = self->forward_speed;
      right_power = self->forward_speed * 0.5f;
    }
    
    lf_set(lp, left_power);
    lf_set(rp, right_power);
    
    // Count left sensor triggers
    if (left_rising) {
      self->spot_count++;
    
      char msg[20];
      snprintf(msg, sizeof(msg), "CNT:%d/6", self->spot_count);
      lf_set(notify, msg);
      printf("Left trigger count=%d\n", self->spot_count);
    
      if (self->spot_count == 1) {
        // Skip exit
        printf("Skipping exit\n");
      } else if (self->spot_count == 2 || self->spot_count == 5 || self->spot_count == 6) {
        // Turn at counts 2, 5, 6
        printf("Count %d -> TURN_LEFT_6_9\n", self->spot_count);
        lf_set(state_display, "TURN_L");
        lf_set_mode(TURN_LEFT_6_9);
      }
      // Counts 3, 4 just pass spots, keep following
    }
    
    self->last_left_high = left_high;
#line 276 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_6(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_reflect_t* reflect = self->_lf_reflect;
    int reflect_width = self->_lf_reflect_width; SUPPRESS_UNUSED_WARNING(reflect_width);
    _parkingcontroller_lp_t* lp = &self->_lf_lp;
    _parkingcontroller_rp_t* rp = &self->_lf_rp;
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    _parkingcontroller_state_display_t* state_display = &self->_lf_state_display;
    reactor_mode_t* FOLLOW_TO_CORRIDOR_6_9 = &self->_lf__modes[3];
    lf_mode_change_type_t _lf_FOLLOW_TO_CORRIDOR_6_9_change_type = reset_transition;
    reactor_mode_t* FOLLOW_IN_CORRIDOR_6_9 = &self->_lf__modes[7];
    lf_mode_change_type_t _lf_FOLLOW_IN_CORRIDOR_6_9_change_type = reset_transition;
    #line 309 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    int L0 = reflect->value[0];
    int CL = reflect->value[1];
    int C  = reflect->value[2];
    int CR = reflect->value[3];
    
    bool left_high = (L0 > self->threshold);
    bool cl_high = (CL > self->threshold);
    bool c_high  = (C  > self->threshold);
    bool cr_high = (CR > self->threshold);
    bool all_front_on_line = (cl_high && c_high && cr_high);
    
    // Turn left: stop left wheel, right wheel forward
    lf_set(lp, 0.0f);
    lf_set(rp, self->turn_speed);
    
    // Turn complete: sensor 0 sees white AND front sensors see line
    if (!left_high && all_front_on_line) {
      self->last_left_high = false;
      self->last_right_high = false;
    
      if (self->spot_count >= 6) {
        // All turns done, now in corridor for spots 6-9
        self->spot_count = 0;  // Reset for counting spots in corridor
        printf("Turn complete (count 6) -> FOLLOW_IN_CORRIDOR_6_9\n");
        lf_set(notify, "IN 6-9");
        lf_set(state_display, "CORR69");
        lf_set_mode(FOLLOW_IN_CORRIDOR_6_9);
      } else {
        // More to go, continue following
        printf("Turn complete (count %d) -> continue following\n", self->spot_count);
        char msg[20];
        snprintf(msg, sizeof(msg), "CNT:%d/6", self->spot_count);
        lf_set(notify, msg);
        lf_set(state_display, "TO 6-9");
        lf_set_mode(FOLLOW_TO_CORRIDOR_6_9);
      }
    }
#line 330 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_7(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_reflect_t* reflect = self->_lf_reflect;
    int reflect_width = self->_lf_reflect_width; SUPPRESS_UNUSED_WARNING(reflect_width);
    _parkingcontroller_lp_t* lp = &self->_lf_lp;
    _parkingcontroller_rp_t* rp = &self->_lf_rp;
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    _parkingcontroller_state_display_t* state_display = &self->_lf_state_display;
    reactor_mode_t* FOLLOW_IN_CORRIDOR_2_5 = &self->_lf__modes[6];
    lf_mode_change_type_t _lf_FOLLOW_IN_CORRIDOR_2_5_change_type = reset_transition;
    #line 354 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    int L0 = reflect->value[0];
    int CL = reflect->value[1];
    int C  = reflect->value[2];
    int CR = reflect->value[3];
    
    bool left_high = (L0 > self->threshold);
    bool cl_high = (CL > self->threshold);
    bool c_high  = (C  > self->threshold);
    bool cr_high = (CR > self->threshold);
    bool all_front_on_line = (cl_high && c_high && cr_high);
    
    // Turn left: stop left wheel, right wheel forward
    lf_set(lp, 0.0f);
    lf_set(rp, self->turn_speed);
    
    // Turn complete: sensor 0 sees white AND front sensors see line
    if (!left_high && all_front_on_line) {
      printf("Turn complete -> FOLLOW_IN_CORRIDOR_2_5\n");
    
      self->last_left_high = false;
      self->last_right_high = false;
      self->spot_count = 0;  // Reset for counting spots in corridor
    
      lf_set(notify, "IN 2-5");
      lf_set(state_display, "CORR25");
      lf_set_mode(FOLLOW_IN_CORRIDOR_2_5);
    }
#line 372 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_8(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_reflect_t* reflect = self->_lf_reflect;
    int reflect_width = self->_lf_reflect_width; SUPPRESS_UNUSED_WARNING(reflect_width);
    _parkingcontroller_lp_t* lp = &self->_lf_lp;
    _parkingcontroller_rp_t* rp = &self->_lf_rp;
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    _parkingcontroller_state_display_t* state_display = &self->_lf_state_display;
    reactor_mode_t* TURN_LEFT_INTO_SPOT = &self->_lf__modes[8];
    lf_mode_change_type_t _lf_TURN_LEFT_INTO_SPOT_change_type = reset_transition;
    reactor_mode_t* TURN_RIGHT_INTO_SPOT = &self->_lf__modes[9];
    lf_mode_change_type_t _lf_TURN_RIGHT_INTO_SPOT_change_type = reset_transition;
    #line 395 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    int L0 = reflect->value[0];
    int CL = reflect->value[1];
    int C  = reflect->value[2];
    int CR = reflect->value[3];
    int R4 = reflect->value[4];
    
    bool left_high = (L0 > self->threshold);
    bool right_high = (R4 > self->threshold);
    bool left_rising = (left_high && !self->last_left_high);
    bool right_rising = (right_high && !self->last_right_high);
    
    // Line following using center 3 sensors
    bool cl_high = (CL > self->threshold);
    bool c_high  = (C  > self->threshold);
    bool cr_high = (CR > self->threshold);
    
    float left_power = self->forward_speed;
    float right_power = self->forward_speed;
    
    if (cl_high && !cr_high) {
      left_power = self->forward_speed * 0.5f;
      right_power = self->forward_speed;
    } else if (cr_high && !cl_high) {
      left_power = self->forward_speed;
      right_power = self->forward_speed * 0.5f;
    }
    
    lf_set(lp, left_power);
    lf_set(rp, right_power);
    
    // Determine target count based on parking spot
    int target_count;
    if (self->parking_spot == 2 || self->parking_spot == 3) {
      target_count = 1;
    } else {
      target_count = 2;
    }
    
    bool is_even_spot = (self->parking_spot % 2 == 0);
    
    if (is_even_spot && left_rising) {
      self->spot_count++;
    
      char msg[20];
      snprintf(msg, sizeof(msg), "L:%d T:%d", self->spot_count, self->parking_spot);
      lf_set(notify, msg);
      printf("Left sensor: count=%d, target=%d\n", self->spot_count, self->parking_spot);
    
      if (self->spot_count == target_count) {
        printf("Turning LEFT into spot %d\n", self->parking_spot);
        lf_set(state_display, "TURN_L");
        lf_set_mode(TURN_LEFT_INTO_SPOT);
      }
    } 
    else if (!is_even_spot && right_rising) {
      self->spot_count++;
    
      char msg[20];
      snprintf(msg, sizeof(msg), "R:%d T:%d", self->spot_count, self->parking_spot);
      lf_set(notify, msg);
      printf("Right sensor: count=%d, target=%d\n", self->spot_count, self->parking_spot);
    
      if (self->spot_count == target_count) {
        printf("Turning RIGHT into spot %d\n", self->parking_spot);
        lf_set(state_display, "TURN_R");
        lf_set_mode(TURN_RIGHT_INTO_SPOT);
      }
    }
    
    self->last_left_high = left_high;
    self->last_right_high = right_high;
#line 460 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_9(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_reflect_t* reflect = self->_lf_reflect;
    int reflect_width = self->_lf_reflect_width; SUPPRESS_UNUSED_WARNING(reflect_width);
    _parkingcontroller_lp_t* lp = &self->_lf_lp;
    _parkingcontroller_rp_t* rp = &self->_lf_rp;
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    _parkingcontroller_state_display_t* state_display = &self->_lf_state_display;
    reactor_mode_t* TURN_LEFT_INTO_SPOT = &self->_lf__modes[8];
    lf_mode_change_type_t _lf_TURN_LEFT_INTO_SPOT_change_type = reset_transition;
    reactor_mode_t* TURN_RIGHT_INTO_SPOT = &self->_lf__modes[9];
    lf_mode_change_type_t _lf_TURN_RIGHT_INTO_SPOT_change_type = reset_transition;
    #line 480 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    int L0 = reflect->value[0];
    int CL = reflect->value[1];
    int C  = reflect->value[2];
    int CR = reflect->value[3];
    int R4 = reflect->value[4];
    
    bool left_high = (L0 > self->threshold);
    bool right_high = (R4 > self->threshold);
    bool left_rising = (left_high && !self->last_left_high);
    bool right_rising = (right_high && !self->last_right_high);
    
    // Line following using center 3 sensors
    bool cl_high = (CL > self->threshold);
    bool c_high  = (C  > self->threshold);
    bool cr_high = (CR > self->threshold);
    
    float left_power = self->forward_speed;
    float right_power = self->forward_speed;
    
    if (cl_high && !cr_high) {
      left_power = self->forward_speed * 0.5f;
      right_power = self->forward_speed;
    } else if (cr_high && !cl_high) {
      left_power = self->forward_speed;
      right_power = self->forward_speed * 0.5f;
    }
    
    lf_set(lp, left_power);
    lf_set(rp, right_power);
    
    // Determine target count based on parking spot
    // Spots 6,7 -> need count 1
    // Spots 8,9 -> need count 2
    int target_count;
    if (self->parking_spot == 6 || self->parking_spot == 7) {
      target_count = 1;
    } else {
      target_count = 2;
    }
    
    bool is_even_spot = (self->parking_spot % 2 == 0);
    
    if (is_even_spot && left_rising) {
      self->spot_count++;
    
      char msg[20];
      snprintf(msg, sizeof(msg), "L:%d T:%d", self->spot_count, self->parking_spot);
      lf_set(notify, msg);
      printf("Left sensor: count=%d, target=%d\n", self->spot_count, self->parking_spot);
    
      if (self->spot_count == target_count) {
        printf("Turning LEFT into spot %d\n", self->parking_spot);
        lf_set(state_display, "TURN_L");
        lf_set_mode(TURN_LEFT_INTO_SPOT);
      }
    } 
    else if (!is_even_spot && right_rising) {
      self->spot_count++;
    
      char msg[20];
      snprintf(msg, sizeof(msg), "R:%d T:%d", self->spot_count, self->parking_spot);
      lf_set(notify, msg);
      printf("Right sensor: count=%d, target=%d\n", self->spot_count, self->parking_spot);
    
      if (self->spot_count == target_count) {
        printf("Turning RIGHT into spot %d\n", self->parking_spot);
        lf_set(state_display, "TURN_R");
        lf_set_mode(TURN_RIGHT_INTO_SPOT);
      }
    }
    
    self->last_left_high = left_high;
    self->last_right_high = right_high;
#line 550 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_10(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_reflect_t* reflect = self->_lf_reflect;
    int reflect_width = self->_lf_reflect_width; SUPPRESS_UNUSED_WARNING(reflect_width);
    _parkingcontroller_lp_t* lp = &self->_lf_lp;
    _parkingcontroller_rp_t* rp = &self->_lf_rp;
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    _parkingcontroller_state_display_t* state_display = &self->_lf_state_display;
    reactor_mode_t* PARK_FORWARD = &self->_lf__modes[10];
    lf_mode_change_type_t _lf_PARK_FORWARD_change_type = reset_transition;
    #line 561 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    int L0 = reflect->value[0];
    int CL = reflect->value[1];
    int C  = reflect->value[2];
    int CR = reflect->value[3];
    
    bool left_high = (L0 > self->threshold);
    bool cl_high = (CL > self->threshold);
    bool c_high  = (C  > self->threshold);
    bool cr_high = (CR > self->threshold);
    bool all_front_on_line = (cl_high && c_high && cr_high);
    
    // Turn left: stop left wheel, right wheel forward
    lf_set(lp, 0.0f);
    lf_set(rp, self->turn_speed);
    
    // Turn complete: sensor 0 sees white AND front sensors see line
    if (!left_high && all_front_on_line) {
      printf("Turn into spot complete -> PARK_FORWARD\n");
    
      self->last_left_high = false;
      self->last_right_high = false;
    
      lf_set(notify, "PARKING");
      lf_set(state_display, "PARK");
      lf_set_mode(PARK_FORWARD);
    }
#line 591 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_11(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_reflect_t* reflect = self->_lf_reflect;
    int reflect_width = self->_lf_reflect_width; SUPPRESS_UNUSED_WARNING(reflect_width);
    _parkingcontroller_lp_t* lp = &self->_lf_lp;
    _parkingcontroller_rp_t* rp = &self->_lf_rp;
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    _parkingcontroller_state_display_t* state_display = &self->_lf_state_display;
    reactor_mode_t* PARK_FORWARD = &self->_lf__modes[10];
    lf_mode_change_type_t _lf_PARK_FORWARD_change_type = reset_transition;
    #line 595 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    int R4 = reflect->value[4];
    int CL = reflect->value[1];
    int C  = reflect->value[2];
    int CR = reflect->value[3];
    
    bool right_high = (R4 > self->threshold);
    bool cl_high = (CL > self->threshold);
    bool c_high  = (C  > self->threshold);
    bool cr_high = (CR > self->threshold);
    bool all_front_on_line = (cl_high && c_high && cr_high);
    
    // Turn right: left wheel forward, stop right wheel
    lf_set(lp, self->turn_speed);
    lf_set(rp, 0.0f);
    
    // Turn complete: sensor 4 sees white AND front sensors see line
    if (!right_high && all_front_on_line) {
      printf("Turn into spot complete -> PARK_FORWARD\n");
    
      self->last_left_high = false;
      self->last_right_high = false;
    
      lf_set(notify, "PARKING");
      lf_set(state_display, "PARK");
      lf_set_mode(PARK_FORWARD);
    }
#line 632 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_12(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_reflect_t* reflect = self->_lf_reflect;
    int reflect_width = self->_lf_reflect_width; SUPPRESS_UNUSED_WARNING(reflect_width);
    _parkingcontroller_lp_t* lp = &self->_lf_lp;
    _parkingcontroller_rp_t* rp = &self->_lf_rp;
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    _parkingcontroller_state_display_t* state_display = &self->_lf_state_display;
    reactor_mode_t* PARKED = &self->_lf__modes[11];
    lf_mode_change_type_t _lf_PARKED_change_type = reset_transition;
    #line 630 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    int L0 = reflect->value[0];
    int CL = reflect->value[1];
    int C  = reflect->value[2];
    int CR = reflect->value[3];
    int R4 = reflect->value[4];
    
    bool all_white = (L0 < self->threshold && CL < self->threshold && 
                     C < self->threshold && CR < self->threshold && R4 < self->threshold);
    
    // Line following using center 3 sensors
    bool cl_high = (CL > self->threshold);
    bool c_high  = (C  > self->threshold);
    bool cr_high = (CR > self->threshold);
    
    // Simple line following: adjust based on which sensors see the line
    float left_power = self->forward_speed;
    float right_power = self->forward_speed;
    
    if (cl_high && !cr_high) {
      // Line is to the left, turn left
      left_power = self->forward_speed * 0.5f;
      right_power = self->forward_speed;
    } else if (cr_high && !cl_high) {
      // Line is to the right, turn right
      left_power = self->forward_speed;
      right_power = self->forward_speed * 0.5f;
    }
    // If center or both sides see line, go straight
    
    lf_set(lp, left_power);
    lf_set(rp, right_power);
    
    // Stop when line ends
    if (all_white) {
      printf("=== PARKED IN SPOT %d ===\n", self->parking_spot);
    
      lf_set(lp, 0.0f);
      lf_set(rp, 0.0f);
    
      char msg[20];
      snprintf(msg, sizeof(msg), "PARKED %d", self->parking_spot);
      lf_set(notify, msg);
      lf_set(state_display, "DONE");
      lf_set_mode(PARKED);
    }
#line 692 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _parkingcontrollerreaction_function_13(void* instance_args) {
    _parkingcontroller_self_t* self = (_parkingcontroller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _parkingcontroller_target_spot_t* target_spot = self->_lf_target_spot;
    int target_spot_width = self->_lf_target_spot_width; SUPPRESS_UNUSED_WARNING(target_spot_width);
    _parkingcontroller_notify_t* notify = &self->_lf_notify;
    #line 683 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    // Could handle exit here later
    printf("Already parked. Exit not implemented.\n");
#line 704 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_parkingcontroller.c"
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
    self->_lf__reaction_9.number = 9;
    self->_lf__reaction_9.function = _parkingcontrollerreaction_function_9;
    self->_lf__reaction_9.self = self;
    self->_lf__reaction_9.deadline_violation_handler = NULL;
    self->_lf__reaction_9.STP_handler = NULL;
    self->_lf__reaction_9.name = "?";
    self->_lf__reaction_9.mode = &self->_lf__modes[7];
    self->_lf__reaction_10.number = 10;
    self->_lf__reaction_10.function = _parkingcontrollerreaction_function_10;
    self->_lf__reaction_10.self = self;
    self->_lf__reaction_10.deadline_violation_handler = NULL;
    self->_lf__reaction_10.STP_handler = NULL;
    self->_lf__reaction_10.name = "?";
    self->_lf__reaction_10.mode = &self->_lf__modes[8];
    self->_lf__reaction_11.number = 11;
    self->_lf__reaction_11.function = _parkingcontrollerreaction_function_11;
    self->_lf__reaction_11.self = self;
    self->_lf__reaction_11.deadline_violation_handler = NULL;
    self->_lf__reaction_11.STP_handler = NULL;
    self->_lf__reaction_11.name = "?";
    self->_lf__reaction_11.mode = &self->_lf__modes[9];
    self->_lf__reaction_12.number = 12;
    self->_lf__reaction_12.function = _parkingcontrollerreaction_function_12;
    self->_lf__reaction_12.self = self;
    self->_lf__reaction_12.deadline_violation_handler = NULL;
    self->_lf__reaction_12.STP_handler = NULL;
    self->_lf__reaction_12.name = "?";
    self->_lf__reaction_12.mode = &self->_lf__modes[10];
    self->_lf__reaction_13.number = 13;
    self->_lf__reaction_13.function = _parkingcontrollerreaction_function_13;
    self->_lf__reaction_13.self = self;
    self->_lf__reaction_13.deadline_violation_handler = NULL;
    self->_lf__reaction_13.STP_handler = NULL;
    self->_lf__reaction_13.name = "?";
    self->_lf__reaction_13.mode = &self->_lf__modes[11];
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
    self->_lf__reflect_reactions[5] = &self->_lf__reaction_8;
    self->_lf__reflect_reactions[6] = &self->_lf__reaction_9;
    self->_lf__reflect_reactions[7] = &self->_lf__reaction_10;
    self->_lf__reflect_reactions[8] = &self->_lf__reaction_11;
    self->_lf__reflect_reactions[9] = &self->_lf__reaction_12;
    self->_lf__reflect.reactions = &self->_lf__reflect_reactions[0];
    self->_lf__reflect.number_of_reactions = 10;
    #ifdef FEDERATED
    self->_lf__reflect.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__reflect.tmplt.type.element_size = sizeof(uint16_t);
    self->_lf__target_spot.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__target_spot.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__target_spot_reactions[0] = &self->_lf__reaction_2;
    self->_lf__target_spot_reactions[1] = &self->_lf__reaction_13;
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
    self->_lf__modes[1].name = "FOLLOW_TO_SPOT_1";
    self->_lf__modes[1].deactivation_time = 0;
    self->_lf__modes[1].flags = 0;
    self->_lf__modes[2].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[2].name = "FOLLOW_TO_CORRIDOR_2_5";
    self->_lf__modes[2].deactivation_time = 0;
    self->_lf__modes[2].flags = 0;
    self->_lf__modes[3].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[3].name = "FOLLOW_TO_CORRIDOR_6_9";
    self->_lf__modes[3].deactivation_time = 0;
    self->_lf__modes[3].flags = 0;
    self->_lf__modes[4].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[4].name = "TURN_LEFT_6_9";
    self->_lf__modes[4].deactivation_time = 0;
    self->_lf__modes[4].flags = 0;
    self->_lf__modes[5].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[5].name = "TURN_LEFT";
    self->_lf__modes[5].deactivation_time = 0;
    self->_lf__modes[5].flags = 0;
    self->_lf__modes[6].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[6].name = "FOLLOW_IN_CORRIDOR_2_5";
    self->_lf__modes[6].deactivation_time = 0;
    self->_lf__modes[6].flags = 0;
    self->_lf__modes[7].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[7].name = "FOLLOW_IN_CORRIDOR_6_9";
    self->_lf__modes[7].deactivation_time = 0;
    self->_lf__modes[7].flags = 0;
    self->_lf__modes[8].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[8].name = "TURN_LEFT_INTO_SPOT";
    self->_lf__modes[8].deactivation_time = 0;
    self->_lf__modes[8].flags = 0;
    self->_lf__modes[9].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[9].name = "TURN_RIGHT_INTO_SPOT";
    self->_lf__modes[9].deactivation_time = 0;
    self->_lf__modes[9].flags = 0;
    self->_lf__modes[10].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[10].name = "PARK_FORWARD";
    self->_lf__modes[10].deactivation_time = 0;
    self->_lf__modes[10].flags = 0;
    self->_lf__modes[11].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[11].name = "PARKED";
    self->_lf__modes[11].deactivation_time = 0;
    self->_lf__modes[11].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}
