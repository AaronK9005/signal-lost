#pragma once

#include <stdbool.h>

#define RNG (rand() % 100)

typedef enum resource_num {
    RESOURCE_ENERGY,
    RESOURCE_OXY,
    RESOURCE_HEAT,
    RESOURCE_SIGNAL,
    RESOURCES_COUNT
} resource_num;

extern const char* resource_names[RESOURCES_COUNT];

typedef struct station_t {
    union {
        struct {
            int energy;
            int oxygen;
            int signal;
            int heat;
        };
        int resource[RESOURCES_COUNT];
    };
    int turn;
    int dead_resource; // * which resouce was depleted
    bool game_over;
} station_t;

#define EVENT_CHANCE 50

typedef struct event_t {
    const char* name;
    const resource_num r_num;
    int min, max;
} event_t;

typedef enum event_num {
    EVENT_COUNT = RESOURCES_COUNT
} event_num;

extern const event_t events[EVENT_COUNT];

void station_print(station_t* stat);
void station_update(station_t* stat);
void station_action(station_t* stat);
void station_event(station_t* stat);

