#pragma once

typedef enum resource_num {
    RESOURCE_NONE = -1,
    RESOURCE_ENERGY,
    RESOURCE_OXY,
    RESOURCE_HEAT,
    RESOURCE_SIGNAL,
    RESOURCES_COUNT
} resource_num;

typedef union resources_t {
    struct {
        int energy;
        int oxygen;
        int heat;
        int signal;
    };
    int iter[RESOURCES_COUNT];
} resources_t;

extern const char* resource_names[RESOURCES_COUNT];
