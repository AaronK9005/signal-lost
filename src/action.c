#include <stdbool.h>

#include "../include/action.h"
#include "../include/resources.h"

bool print_action_values = false;

const action_t actions[ACTION_COUNT] = {
    [ACTION_GEN_REPAIR] = {
        "repair generator", 
        {
            [0] = { RESOURCE_ENERGY, 30, 50 },
            [1] = EFFECT_NONE,
            [2] = EFFECT_NONE,
            [3] = EFFECT_NONE
        }
    },
    [ACTION_OXY_FIX] = {
        "secure oxygen supply",
        {
            [0] = { RESOURCE_OXYGEN, 60, 80 },
            [1] = EFFECT_NONE,
            [2] = EFFECT_NONE,
            [3] = EFFECT_NONE
        }
    },
    [ACTION_HEAT_FIX] = {
        "fortify heat shields",
        {
            [0] = { RESOURCE_HEAT, 30, 50 },
            [1] = EFFECT_NONE,
            [2] = EFFECT_NONE,
            [3] = EFFECT_NONE
        }
    },
    [ACTION_SIGNAL_FIX] = {
        "look for a signal",
        {
            [0] = { RESOURCE_SIGNAL, 10, 15 },
            [1] = EFFECT_NONE,
            [2] = EFFECT_NONE,
            [3] = EFFECT_NONE
        }
    },
    [ACTION_IDLE] = {
        "idle (risk)",
        {
            [0] = EFFECT_NONE,
            [1] = EFFECT_NONE,
            [2] = EFFECT_NONE,
            [3] = EFFECT_NONE
        }
    }
};

int printf(const char*, ...);
int putchar(int);

void action_print(int action_id) {
    if (action_id <= ACTION_NONE || action_id >= ACTION_COUNT) return;

    const action_t* a = &actions[action_id];

    printf("\t%d) %s", action_id + 1, a->name);

    if (print_action_values) {
        bool first = true;
        for (int i = 0; i < MAX_RES_AFFECTED; i++) {
            const effect_t* e = &a->effects[i];

            if (e->r_num == RESOURCE_NONE)
                break;

            if (!first)
                putchar(',');

            printf("\t%s (%d - %d)",
                resource_names[e->r_num],
                e->min,
                e->max);

            first = false;
        }
    }
    putchar('\n');
}