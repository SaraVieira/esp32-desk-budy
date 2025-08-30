#include "calendar.h"
#include "../../styles/styles.h"
#include <Arduino.h>

// Global objects (defined in main.cpp)
extern lv_obj_t *calendar_screen;

void create_calendar_screen(void)
{
    static lv_style_t no_border_style;
    lv_style_init(&no_border_style);
    lv_style_set_border_width(&no_border_style, 0);
    lv_style_set_text_font(&no_border_style, &teletext_14);
    calendar_screen = lv_obj_create(NULL);
    lv_obj_set_size(calendar_screen, lv_pct(100), lv_pct(100));
    lv_obj_set_flex_flow(calendar_screen, LV_FLEX_FLOW_COLUMN);
    clear_paddings(calendar_screen);
    lv_obj_add_style(calendar_screen, &no_border_style, 0);
    lv_obj_set_style_bg_color(calendar_screen, black, LV_PART_MAIN);
}
