#include "mic.h"
#include "../styles/styles.h"
#include <Arduino.h>

// Microphone configuration
const int sampleWindow = 50;
const int AMP_PIN = 34;
const int LOUD_THRESHOLD = 3500;
unsigned int sample;

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

    if (peakToPeak > LOUD_THRESHOLD)
    {
        if (loud_container != NULL && !lv_obj_has_flag(loud_container, LV_OBJ_FLAG_HIDDEN))
        {
            // Already showing loud warning
            return;
        }
        loud_container = lv_obj_create(lv_scr_act());
        lv_obj_remove_flag(loud_container, LV_OBJ_FLAG_HIDDEN);
        static lv_style_t no_border_style;
        lv_style_init(&no_border_style);
        lv_style_set_border_width(&no_border_style, 0);
        clear_paddings(loud_container);
        lv_obj_remove_flag(loud_container, LV_OBJ_FLAG_HIDDEN);
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
    }
    else
    {
        if (loud_container != NULL)
        {
            lv_obj_add_flag(loud_container, LV_OBJ_FLAG_HIDDEN);
        }
    }
}
