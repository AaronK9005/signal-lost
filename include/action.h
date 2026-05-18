#pragma once

#include "effect.h"

#define MAX_RES_AFFECTED 4

enum {
    ACTION_NONE = -1,
    ACTION_GEN_REPAIR,
    ACTION_OXY_FIX,
    ACTION_HEAT_FIX,
    ACTION_SIGNAL_FIX,

    ACTION_IDLE,
    ACTION_COUNT
};

typedef struct action_t {
    const char* name;
    const effect_t effects[MAX_RES_AFFECTED];
} action_t;

extern _Bool print_action_values;
extern const action_t actions[ACTION_COUNT];

void action_print(int action_id);