#include "clock.h"
#include "../../styles/styles.h"
#include "../../images/images.h"
#include <Arduino.h>

// Global objects (defined in main.cpp)
extern lv_obj_t *clock_screen;
extern TimeDisplay time_display;

void create_screen_clock(void)
{
    // init style
    static lv_style_t no_border_style;
    lv_style_init(&no_border_style);
    lv_style_set_border_width(&no_border_style, 0);
    lv_style_set_radius(&no_border_style, 0);
    lv_style_set_text_font(&no_border_style, &teletext_24);

    // container
    clock_screen = lv_obj_create(NULL);
    static lv_obj_t *container;
    container = lv_obj_create(clock_screen);
    lv_obj_set_size(container, lv_pct(100), lv_pct(100));
    lv_obj_align(container, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_flex_flow(container, LV_FLEX_FLOW_COLUMN);
    align_center_x_y(container);
    clear_paddings(container);
    lv_obj_add_style(container, &no_border_style, 0);
    lv_obj_set_style_bg_color(container, black, LV_PART_MAIN);

    // create a flex row container that holds the time images
    lv_obj_t *time_container = lv_obj_create(container);
    lv_obj_set_size(time_container, lv_pct(100), 80);
    lv_obj_set_flex_flow(time_container, LV_FLEX_FLOW_ROW);

    align_center_x_y(time_container);
    clear_paddings(time_container);
    lv_obj_add_style(time_container, &no_border_style, 0);
    lv_obj_set_style_bg_color(time_container, black, LV_PART_MAIN);

    time_display.hour_1 = lv_image_create(time_container);
    time_display.hour_2 = lv_image_create(time_container);
    lv_obj_t *colon_hour = lv_image_create(time_container);
    lv_image_set_src(colon_hour, &colon);
    time_display.minute_1 = lv_image_create(time_container);
    time_display.minute_2 = lv_image_create(time_container);
    lv_obj_t *colon_minute = lv_image_create(time_container);
    lv_image_set_src(colon_minute, &colon);
    time_display.second_1 = lv_image_create(time_container);
    time_display.second_2 = lv_image_create(time_container);

    lv_obj_t *date_container = lv_obj_create(container);
    lv_obj_set_size(date_container, lv_pct(100), lv_pct(25));
    lv_obj_set_style_translate_y(date_container, -28, LV_PART_MAIN);
    lv_obj_set_flex_flow(date_container, LV_FLEX_FLOW_ROW);
    align_center_x_y(date_container);
    clear_paddings(date_container);
    lv_obj_add_style(date_container, &no_border_style, 0);
    lv_obj_set_style_bg_color(date_container, blue, LV_PART_MAIN);

    time_display.date_label = lv_label_create(date_container);
    lv_obj_set_style_text_color(time_display.date_label, black, LV_PART_MAIN);
}
