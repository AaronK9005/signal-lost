#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "../include/station.h"

#include "../util/sleep.h"

int main()
{
    srand(time(NULL));

    bool should_close = false;
    station_t station;

    station_init(&station);

    station.resource.signal = 90;

    while (!should_close) {

        station_print_fade_in(&station);
        station_print(&station);
        station_update(&station);
        station_action(&station);
        station_event(&station);

        if (station.resource.signal == RESOURCE_CAP) {
            station.won = true;
            should_close = true;
            station_win(&station);
        }
        if (station.game_over || getchar() == 'q') should_close = true;
    }

    if (station.dead_resource != RESOURCE_NONE) {
        printf("station ran out of '%s'\n", resource_names[station.dead_resource]);
    }

    // printf("Game ended\n");

    return 0;
}