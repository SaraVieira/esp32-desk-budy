#include "mic.h"
#include "../styles/styles.h"
#include "../types.h"
#include <Arduino.h>

// Microphone configuration
const int sampleWindow = 50;
const int AMP_PIN = 34;
const int LOUD_THRESHOLD = 3500;
unsigned int sample;

// Global objects (defined in main.cpp)
extern Screen current_screen;
extern lv_obj_t *clock_screen;
extern lv_obj_t *weather_screen;
extern lv_obj_t *calendar_screen;

void read_mic()
{
    unsigned long startMillis = millis();
    unsigned int peakToPeak = 0;

    unsigned int signalMax = 0;
    unsigned int signalMin = 1024;

    while (millis() - startMillis < sampleWindow)
    {
        sample = analogRead(AMP_PIN);

        if (sample > signalMax)
        {
            signalMax = sample;
        }
        else if (sample < signalMin)
        {
            signalMin = sample;
        }
    }
    peakToPeak = (signalMax - signalMin);
    static lv_obj_t *loud_container = NULL;
    static Screen previous_screen; // Store the screen we were on

    if (peakToPeak > LOUD_THRESHOLD)
    {
        if (loud_container != NULL)
        {
            // Already showing loud warning
            return;
        }

        // Store current screen before switching
        previous_screen = current_screen;

        loud_container = lv_obj_create(NULL);
        static lv_style_t no_border_style;
        static bool style_initialized = false;

        if (!style_initialized)
        {
            lv_style_init(&no_border_style);
            lv_style_set_border_width(&no_border_style, 0);
            style_initialized = true;
        }

        clear_paddings(loud_container);
        lv_obj_set_flex_flow(loud_container, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_flex_align(loud_container, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_size(loud_container, 320, 240);
        lv_obj_set_style_radius(loud_container, 0, LV_PART_MAIN);
        align_center_x_y(loud_container);
        lv_obj_set_style_bg_color(loud_container, red, 0);
        lv_obj_set_style_text_color(loud_container, white, 0);
        lv_obj_set_style_text_font(loud_container, &teletext_40, 0);
        lv_label_set_text(lv_label_create(loud_container), "Loud!!!");
        lv_obj_add_style(loud_container, &no_border_style, 0);
        lv_scr_load(loud_container);
    }
    else
    {
        if (loud_container != NULL)
        {
            // Clean up the loud container
            lv_obj_del(loud_container);
            loud_container = NULL;

            // Return to the previous screen
            current_screen = previous_screen;
            switch (current_screen)
            {
            case Screen::CLOCK:
                lv_scr_load(clock_screen);
                break;
            case Screen::WEATHER:
                lv_scr_load(weather_screen);
                break;
            case Screen::CALENDAR:
                lv_scr_load(calendar_screen);
                break;
            }
        }
    }
}