#pragma once

#include <stdbool.h>

#include "resources.h"

typedef struct station_t {
    resources_t resource;
    int turn;
    int dead_resource; // * which resouce was depleted (first)
    bool game_over;
    bool won;
} station_t;

void station_init(station_t* stat);

void station_print_fade_in(const station_t* stat);

void station_print(const station_t* stat);
void station_update(station_t* stat);
void station_action(station_t* stat);
void station_event(station_t* stat);

void station_win(station_t* stat);

void station_clamp_resources(station_t* stat);

void station_add_resource(station_t* s, int recource_id, int amount);
void station_remove_resource(station_t* s, int resource_id, int amount);

bool station_has_atleast(const station_t* s, int resource_id, int amount);

