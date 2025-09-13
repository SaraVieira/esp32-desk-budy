
#include <SpotifyArduino.h>

#ifndef TYPES_H
#define TYPES_H

#include <lvgl.h>
extern SpotifyArduino spotify;
void change_screens(int value);

enum class Screen : int
{
    CLOCK = 0,
    WEATHER = 1,
    CALENDAR = 2,
    SPOTIFY = 3,
    COUNT = 4 // Useful for bounds checking
};
extern Screen current_screen;
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
    int32_t wmo_code;
};

// Global instances (defined in main.cpp)
extern TimeDisplay time_display;
extern WeatherDisplay weather_display;

#define ROTARY_ENCODER_A_PIN 23
#define ROTARY_ENCODER_B_PIN 22
#define ROTARY_ENCODER_BUTTON_PIN 26
#define ROTARY_ENCODER_VCC_PIN -1
#define ROTARY_ENCODER_STEPS 4

#endif // TYPES_H

