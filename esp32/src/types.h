#ifndef TYPES_H
#define TYPES_H

#include <lvgl.h>

// Structure to group time display elements
struct TimeDisplay
{
    // UI elements
    lv_obj_t *hour_1;
    lv_obj_t *hour_2;
    lv_obj_t *minute_1;
    lv_obj_t *minute_2;
    lv_obj_t *second_1;
    lv_obj_t *second_2;
    lv_obj_t *date_label;

    // Time values
    int32_t hour;
    int32_t minute;
    int32_t second;
};

// Structure for weather display elements
struct WeatherDisplay
{
    lv_obj_t *icon;
    lv_obj_t *temperature_label;
    lv_obj_t *description_label;
};

// Global instances (defined in main.cpp)
extern TimeDisplay time_display;
extern WeatherDisplay weather_display;

#endif // TYPES_H
