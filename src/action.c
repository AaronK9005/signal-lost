#include "../include/action.h"
#include "../include/resources.h"

const action_t actions[ACTION_COUNT] = {
    {
        "repair generator", 
        {
            [0] = { RESOURCE_ENERGY, 20, 30 },
            [1] = { -1 },
            [2] = { -1 },
            [3] = { -1 }
        }
    }
};