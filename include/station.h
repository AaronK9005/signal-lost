#pragma once

#include <stdbool.h>

#include "resources.h"

typedef struct station_t {
    resources_t resource;
    int turn;
    int dead_resource; // * which resouce was depleted (first)
    bool game_over;
} station_t;


void station_print(station_t* stat);
void station_update(station_t* stat);
void station_action(station_t* stat);
void station_event(station_t* stat);

