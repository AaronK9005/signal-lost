#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/station.h"
#include "../include/loadbar.h"
#include "../include/event.h"

#define RNG (rand() % 100)

void station_print(station_t* stat) {
    if (!stat) return;

    loadbar_t lb = lb_create(100, stat->resource.energy, 50);

    printf("Station: day %d\n", stat->turn);
    bar_print("energy: ", &lb, stat->resource.energy);
    bar_print("oxygen: ", &lb, stat->resource.oxygen);
    bar_print("heat:   ", &lb, stat->resource.heat);
    bar_print("signal: ", &lb, stat->resource.signal);
    putchar('\n');
}

void station_update(station_t* stat) {
    if (!stat) return;

    for (int i = 0; i < RESOURCES_COUNT; i++) {
        stat->resource.iter[i] -= 5;
        if (stat->resource.iter[i] <= 0) {
            stat->game_over = true;
            stat->dead_resource = i;
        }
    }
    stat->turn++;
}

void station_action(station_t* stat) {
    if (!stat) return;

    
}

void station_event(station_t* stat) {
    if (RNG < EVENT_CHANCE) {
        int e_num = rand() % EVENT_COUNT;
        const event_t* e = &events[e_num];
        int severity = (rand() % (e->effect.max - e->effect.min +1)) + e->effect.min;

        stat->resource.iter[e->effect.r_num] -= severity;
        
        printf("event '%s' decreased resource '%s' by '%d\n\n", e->name, resource_names[e->effect.r_num], severity);
    }
    else {
        printf("no event occured\n");
    }
}
