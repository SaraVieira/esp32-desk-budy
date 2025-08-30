#ifndef WEATHER_H
#define WEATHER_H

#include <lvgl.h>
#include "types.h"

// External references to global objects
extern lv_obj_t *weather_screen;
extern WeatherDisplay weather_display;

// Function declarations
void create_weather_screen(void);

#endif // WEATHER_H
