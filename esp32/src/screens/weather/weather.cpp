#include "weather.h"
#include "../../styles/styles.h"
#include <Arduino.h>

// Global objects (defined in main.cpp)
extern lv_obj_t *weather_screen;
extern WeatherDisplay weather_display;

void create_weather_screen(void)
{
    static lv_style_t no_border_style;
    lv_style_init(&no_border_style);
    lv_style_set_border_width(&no_border_style, 0);
    lv_style_set_text_font(&no_border_style, &teletext_24);
    // create a container that is flex and aligns. everything to the center on the x and y axes
    weather_screen = lv_obj_create(NULL);
    lv_obj_set_size(weather_screen, lv_pct(100), lv_pct(100));
    lv_obj_align(weather_screen, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_flex_flow(weather_screen, LV_FLEX_FLOW_COLUMN);
    align_center_x_y(weather_screen);
    clear_paddings(weather_screen);
    lv_obj_add_style(weather_screen, &no_border_style, 0);
    lv_obj_set_style_bg_color(weather_screen, black, LV_PART_MAIN);

    lv_obj_t *icon_and_temp = lv_obj_create(weather_screen);
    lv_obj_set_flex_flow(icon_and_temp, LV_FLEX_FLOW_ROW);
    align_center_x_y(icon_and_temp);
    clear_paddings(icon_and_temp);
    lv_obj_set_size(icon_and_temp, lv_pct(100), 100);
    lv_obj_add_style(icon_and_temp, &no_border_style, 0);
    lv_obj_set_style_bg_color(icon_and_temp, black, LV_PART_MAIN);

    weather_display.icon = lv_image_create(icon_and_temp);
    weather_display.temperature_label = lv_label_create(icon_and_temp);
    lv_obj_set_style_text_color(weather_display.temperature_label, white, LV_PART_MAIN);
    lv_obj_set_style_text_font(weather_display.temperature_label, &teletext_40, LV_PART_MAIN);

    weather_display.description_label = lv_label_create(weather_screen);
    lv_obj_set_style_text_color(weather_display.description_label, magenta, LV_PART_MAIN);
}
