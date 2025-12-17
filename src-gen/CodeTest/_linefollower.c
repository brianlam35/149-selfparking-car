#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/CodeTest/LineFollower.h"
#include "_linefollower.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _linefollowerreaction_function_0(void* instance_args) {
    _linefollower_self_t* self = (_linefollower_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _linefollower_enable_t* enable = self->_lf_enable;
    int enable_width = self->_lf_enable_width; SUPPRESS_UNUSED_WARNING(enable_width);
    #line 53 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    self->enabled = enable->value;
    if (enable->value) {
      self->integral = 0.0f;
      self->last_error = 0.0f;
    }
#line 20 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_linefollower.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _linefollowerreaction_function_1(void* instance_args) {
    _linefollower_self_t* self = (_linefollower_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _linefollower_reflect_t* reflect = self->_lf_reflect;
    int reflect_width = self->_lf_reflect_width; SUPPRESS_UNUSED_WARNING(reflect_width);
    _linefollower_lp_t* lp = &self->_lf_lp;
    _linefollower_rp_t* rp = &self->_lf_rp;
    #line 61 "/home/lambrian/149-selfparking-car/src/CodeTest.lf"
    if (!self->enabled) {
      return;
    }
    
    int L0 = reflect->value[0];
    int CL = reflect->value[1];
    int C  = reflect->value[2];
    int CR = reflect->value[3];
    int R4 = reflect->value[4];
    
    float weighted_sum = 0.0f;
    float total_weight = 0.0f;
    
    if (L0 > self->threshold) { weighted_sum += -2.0f * L0; total_weight += L0; }
    if (CL > self->threshold) { weighted_sum += -1.0f * CL; total_weight += CL; }
    if (C  > self->threshold) { weighted_sum +=  0.0f * C;  total_weight += C;  }
    if (CR > self->threshold) { weighted_sum +=  1.0f * CR; total_weight += CR; }
    if (R4 > self->threshold) { weighted_sum +=  2.0f * R4; total_weight += R4; }
    
    if (total_weight < 1.0f) {
      lf_set(lp, 0.0f);
      lf_set(rp, 0.0f);
      return;
    }
    
    float error = weighted_sum / total_weight;
    
    self->integral += error;
    if (self->integral > 10.0f) self->integral = 10.0f;
    if (self->integral < -10.0f) self->integral = -10.0f;
    
    float derivative = error - self->last_error;
    float correction = self->kp * error + self->ki * self->integral + self->kd * derivative;
    self->last_error = error;
    
    float left_speed = self->base_speed + correction;
    float right_speed = self->base_speed - correction;
    
    if (left_speed > self->max_speed) left_speed = self->max_speed;
    if (left_speed < -self->max_speed) left_speed = -self->max_speed;
    if (right_speed > self->max_speed) right_speed = self->max_speed;
    if (right_speed < -self->max_speed) right_speed = -self->max_speed;
    
    lf_set(lp, left_speed);
    lf_set(rp, right_speed);
#line 76 "/home/lambrian/149-selfparking-car/src-gen/CodeTest/_linefollower.c"
}
#include "include/api/reaction_macros_undef.h"
_linefollower_self_t* new__linefollower() {
    _linefollower_self_t* self = (_linefollower_self_t*)lf_new_reactor(sizeof(_linefollower_self_t));
    // Set input by default to an always absent default input.
    self->_lf_reflect = &self->_lf_default__reflect;
    // Set the default source reactor pointer
    self->_lf_default__reflect._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_enable = &self->_lf_default__enable;
    // Set the default source reactor pointer
    self->_lf_default__enable._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _linefollowerreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _linefollowerreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reflect.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__reflect.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__reflect_reactions[0] = &self->_lf__reaction_1;
    self->_lf__reflect.reactions = &self->_lf__reflect_reactions[0];
    self->_lf__reflect.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__reflect.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__reflect.tmplt.type.element_size = sizeof(uint16_t);
    self->_lf__enable.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__enable.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__enable_reactions[0] = &self->_lf__reaction_0;
    self->_lf__enable.reactions = &self->_lf__enable_reactions[0];
    self->_lf__enable.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__enable.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__enable.tmplt.type.element_size = sizeof(bool);
    return self;
}
