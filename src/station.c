#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/station.h"
#include "../include/loadbar.h"
#include "../include/event.h"
#include "../include/action.h"
#include "../include/ansi_wrappers.h"
#include "../util/sleep.h"

#define RNG (rand() % 100)

void station_init(station_t* stat) {
    if (!stat) return;

    for (int i = 0; i < RESOURCES_COUNT; i++) {
        stat->resource.iter[i] = RESOURCE_START_AMOUNT;
    }
    stat->turn = 0;
    stat->dead_resource = RESOURCE_NONE;
    stat->game_over = false;
    stat->won = false;
}

void station_print_fade_in(const station_t* stat) {
    ansi_clear_screen();
    ansi_goto(40, 15);
    ansi_save_pos();
    ansi_hide_cursor();

    const int start_color = 232;
    const int end_color = 255;

    for (int i = start_color; i <= end_color; i++) {
        ansi_use_pos();
        ansi_clear_endl();
        ansi_256color_fg(i);
        printf("Starting day %d\n", stat->turn);
        fflush(stdout);
        SLEEP(20);
    }
    
    SLEEP(1000);

    for (int i = end_color; i >= start_color; i--) {
        ansi_use_pos();
        ansi_clear_endl();
        ansi_256color_fg(i);
        printf("Starting day %d\n", stat->turn);
        fflush(stdout);
        SLEEP(20);
    }

    ansi_reset();
    ansi_show_cursor();
}

void station_print(const station_t* stat) {
    if (!stat) return;

    loadbar_t lb = lb_create(100, stat->resource.energy, 50);

    ansi_clear_screen();
    ansi_goto_home();

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

    ansi_save_pos();
    bool action_valid = false;
    int a_idx = 0;

    // get valid action
    do {
        ansi_use_pos();

        for (int i = 0; i < ACTION_COUNT; i++) {
            action_print(i);
        }
        putchar('\n');
        printf("choice: ");

        a_idx = getchar() - '0';
        a_idx--;

        if (a_idx > ACTION_NONE && a_idx < ACTION_COUNT) action_valid = true;
        
        while (getchar() != '\n');

    } while (!action_valid);
    
    putchar('\n');

    const action_t* a = &actions[a_idx];

    // apply action
    for (int i = 0; i < MAX_RES_AFFECTED; i++) {
        const effect_t* e = &a->effects[i];

        if (e->r_num == RESOURCE_NONE) break;

        int diff = (rand() % (e->max - e->min + 1)) + e->min;

        stat->resource.iter[e->r_num] += diff;
    }

    station_clamp_resources(stat);
}

void station_event(station_t* stat) {
    if (RNG < EVENT_CHANCE) {
        int e_num = rand() % EVENT_COUNT;
        const event_t* e = &events[e_num];
        int severity = (rand() % (e->effect.max - e->effect.min +1)) + e->effect.min;

        stat->resource.iter[e->effect.r_num] -= severity;
        
        printf("event '%s' decreased resource '%s' by '%d'\n\n", e->name, resource_names[e->effect.r_num], severity);
    }
    else {
        printf("no event occured\n");
    }
}

void station_win(station_t* stat) {
    if (!stat) return;

    ansi_clear_screen();
    ansi_goto(40, 15);
    ansi_save_pos();
    ansi_yellow();
    printf("You won!");
    ansi_reset();
    ansi_use_pos();
    ansi_down(1);
    printf("Signal reached after '");
    ansi_blue();
    printf("%d", stat->turn);
    ansi_reset();
    printf("' days");
}

void station_clamp_resources(station_t* stat) {
    if (!stat) return;

    for (int i = 0; i < RESOURCES_COUNT; i++) {
        if (stat->resource.iter[i] > RESOURCE_CAP) stat->resource.iter[i] = RESOURCE_CAP;
        else if (stat->resource.iter[i] < 0) stat->resource.iter[i] = 0;
    }
}