#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "../include/station.h"

int main()
{
    srand(time(NULL));
    bool should_close = false;

    station_t station = { 
        .resource = {
            .energy = 50,
            .oxygen = 50,
            .heat = 50,
            .signal = 50
        },
        .turn = 0,
        .dead_resource = RESOURCE_NONE,
        .game_over = false
    };

    while (!should_close) {

        station_print(&station);
        station_update(&station);
        station_event(&station);

        if (station.game_over || getchar() == 'q') should_close = true;
    }

    if (station.dead_resource != RESOURCE_NONE) {
        printf("station ran out of '%s'\n", resource_names[station.dead_resource]);
    }

    // printf("Game ended\n");

    return 0;
}