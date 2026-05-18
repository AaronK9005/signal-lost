#pragma once

#include "effect.h"

#define MAX_RES_AFFECTED 4

enum {
    ACTION_GEN_REPAIR,
    ACTION_COUNT
};

typedef struct action_t {
    const char* name;
    const effect_t effects[MAX_RES_AFFECTED];
} action_t;

extern const action_t actions[ACTION_COUNT];