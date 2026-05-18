#pragma once

#define RESOURCE_CAP 100
#define RESOURCE_START_AMOUNT 50

typedef enum resource_num {
    RESOURCE_NONE = -1,
    #define X(NAME, name) RESOURCE_##NAME,
    #include "resources.def"
    #undef X
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
