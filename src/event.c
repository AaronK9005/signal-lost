#include "../include/event.h"
#include "../include/resources.h"

const event_t events[RESOURCES_COUNT] = {
    {
        "generator breakdown", RESOURCE_ENERGY, 5, 20
    },
    {
        "oxygen leak", RESOURCE_OXYGEN, 15, 30
    },
    {
        "heat shield meltdown", RESOURCE_HEAT, 10, 15
    },
    {
        "snapped anthena", RESOURCE_SIGNAL, 5, 10
    }
};
