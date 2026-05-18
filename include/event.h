#pragma once

#include "effect.h"

#define EVENT_CHANCE 50

typedef struct event_t {
    const char* name;
    const effect_t effect;
} event_t;

typedef enum event_num {
    EVENT_GEN_BREAK,
    EVENT_OXY_LEAK,
    EVENT_HEAT_SHIELD_MELT,
    EVENT_SNAPPED_ANT,
    EVENT_COUNT
} event_num;

extern const event_t events[EVENT_COUNT];
