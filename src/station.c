#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/station.h"
#include "../include/loadbar.h"

const char* resource_names[RESOURCES_COUNT] = {
    "energy",
    "oxygen",
    "heat",
    "signal"
};

const event_t events[RESOURCES_COUNT] = {
    {
        "generator breakdown", RESOURCE_ENERGY, 5, 20
    },
    {
        "oxygen leak", RESOURCE_OXY, 15, 30
    },
    {
        "heat shield meltdown", RESOURCE_HEAT, 10, 15
    },
    {
        "snapped anthena", RESOURCE_SIGNAL, 5, 10
    }
};

void station_print(station_t* stat) {
    if (!stat) return;

    loadbar_t lb = lb_create(100, stat->energy, 50);

    printf("Station: day %d\n", stat->turn);
    bar_print("energy: ", &lb, stat->energy);
    bar_print("oxygen: ", &lb, stat->oxygen);
    bar_print("heat:   ", &lb, stat->heat);
    bar_print("signal: ", &lb, stat->signal);
    putchar('\n');
}

void station_update(station_t* stat) {
    if (!stat) return;

    for (int i = 0; i < RESOURCES_COUNT; i++) {
        stat->resource[i] -= 5;
        if (stat->resource[i] <= 0) {
            stat->game_over = true;
            stat->dead_resource = i;
        }
    }
    stat->turn++;
}

void station_event(station_t* stat) {
    if (RNG < EVENT_CHANCE) {
        int e_num = rand() % EVENT_COUNT;
        const event_t* e = &events[e_num];
        int severity = (rand() % (e->max - e->min +1)) + e->min;

        stat->resource[e->r_num] -= severity;
        
        printf("event '%s' decreased resource '%s' by '%d\n\n", e->name, resource_names[e->r_num], severity);
    }
    else {
        printf("no event occured\n");
    }
}
