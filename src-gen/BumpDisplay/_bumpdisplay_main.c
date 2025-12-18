#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/BumpDisplay/BumpDisplay.h"
#include "_bumpdisplay_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _bumpdisplay_mainreaction_function_0(void* instance_args) {
    _bumpdisplay_main_main_self_t* self = (_bumpdisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct bump {
        _bump_left_t* left;
    
    } bump;
    struct disp {
        _display_line0_t* line0;
    
    } disp;
    bump.left = self->_lf_bump.left;
    disp.line0 = &(self->_lf_disp.line0);
    _bumpdisplay_main_clear_t* clear = &self->_lf_clear;
    #line 31 "/home/lambrian/149-selfparking-car/src/BumpDisplay.lf"
    lf_set(disp.line0, "Left Bumped!");
    lf_schedule(clear, SEC(2));
#line 26 "/home/lambrian/149-selfparking-car/src-gen/BumpDisplay/_bumpdisplay_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _bumpdisplay_mainreaction_function_1(void* instance_args) {
    _bumpdisplay_main_main_self_t* self = (_bumpdisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct bump {
        _bump_right_t* right;
    
    } bump;
    struct disp {
        _display_line1_t* line1;
    
    } disp;
    bump.right = self->_lf_bump.right;
    disp.line1 = &(self->_lf_disp.line1);
    _bumpdisplay_main_clear_t* clear = &self->_lf_clear;
    #line 36 "/home/lambrian/149-selfparking-car/src/BumpDisplay.lf"
    lf_set(disp.line1, "Right Bumped!");
    lf_schedule(clear, SEC(2));
#line 46 "/home/lambrian/149-selfparking-car/src-gen/BumpDisplay/_bumpdisplay_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _bumpdisplay_mainreaction_function_2(void* instance_args) {
    _bumpdisplay_main_main_self_t* self = (_bumpdisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    
    } disp;
    lf_critical_section_enter(self->base.environment);
    // Expose the action struct as a local variable whose name matches the action name.
    _bumpdisplay_main_clear_t* clear = &self->_lf_clear;
    // Set the fields of the action struct to match the current trigger.
    clear->is_present = (bool)self->_lf__clear.status;
    clear->has_value = ((self->_lf__clear.tmplt.token) != NULL && (self->_lf__clear.tmplt.token)->value != NULL);
    _lf_replace_template_token((token_template_t*)clear, (self->_lf__clear.tmplt.token));
    lf_critical_section_exit(self->base.environment);
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    #line 41 "/home/lambrian/149-selfparking-car/src/BumpDisplay.lf"
    lf_set(disp.line0, "");
    lf_set(disp.line1, "");
#line 70 "/home/lambrian/149-selfparking-car/src-gen/BumpDisplay/_bumpdisplay_main.c"
}
#include "include/api/reaction_macros_undef.h"
_bumpdisplay_main_main_self_t* new__bumpdisplay_main() {
    _bumpdisplay_main_main_self_t* self = (_bumpdisplay_main_main_self_t*)lf_new_reactor(sizeof(_bumpdisplay_main_main_self_t));
    self->_lf_clear._base.trigger = &self->_lf__clear;
    self->_lf_clear.parent = (self_base_t*)self;
    self->_lf_clear.source_id = -1;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_disp_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_bump_width = -2;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf_bump.left_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf_bump.left_reactions[0] = &self->_lf__reaction_0;
    self->_lf_bump.left_trigger.reactions = self->_lf_bump.left_reactions;
    self->_lf_bump.left_trigger.last_tag = NEVER_TAG;
    self->_lf_bump.left_trigger.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf_bump.left_trigger.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf_bump.right_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf_bump.right_reactions[0] = &self->_lf__reaction_1;
    self->_lf_bump.right_trigger.reactions = self->_lf_bump.right_reactions;
    self->_lf_bump.right_trigger.last_tag = NEVER_TAG;
    self->_lf_bump.right_trigger.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf_bump.right_trigger.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _bumpdisplay_mainreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _bumpdisplay_mainreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _bumpdisplay_mainreaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = NULL;
    self->_lf__clear.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__clear.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__clear_reactions[0] = &self->_lf__reaction_2;
    self->_lf__clear.reactions = &self->_lf__clear_reactions[0];
    self->_lf__clear.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__clear.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__clear.is_physical = false;
    
    self->_lf__clear.tmplt.type.element_size = 0;
    self->_lf_clear.type.element_size = 0;
    self->_lf__clear.tmplt.length = 1;
    self->_lf_clear.length = 1;
    return self;
}
