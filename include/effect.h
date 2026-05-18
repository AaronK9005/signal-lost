#pragma once

/**
 * @brief Simple struct to specify resource and range of change
 * 
 * @param r_num Id of resource affected
 * @param min Minimal value change
 * @param max Maximal value change
 */
typedef struct effect_t {
    int r_num; // resource_number: ID
    int min;
    int max;
} effect_t;

#define EFFECT_NONE { RESOURCE_NONE, 0, 0 }
