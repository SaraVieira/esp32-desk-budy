#include <lvgl.h>

// Colors
lv_color_t red;
lv_color_t green;
lv_color_t yellow;
lv_color_t blue;
lv_color_t magenta;
lv_color_t cyan;
lv_color_t white;
lv_color_t black;

LV_FONT_DECLARE(teletext_24);
LV_FONT_DECLARE(teletext_22);
LV_FONT_DECLARE(teletext_14);
LV_FONT_DECLARE(teletext_40);

void init_colors(void)
{
  red = lv_color_hex(0xFE0301);
  green = lv_color_hex(0x02FF04);
  yellow = lv_color_hex(0xFEFF02);
  blue = lv_color_hex(0x1800FF);
  magenta = lv_color_hex(0xFF00FF);
  cyan = lv_color_hex(0x18FFFF);
  white = lv_color_hex(0xFFFFFF);
  black = lv_color_hex(0x000000);
}

void clear_paddings(lv_obj_t *container)
{
  lv_obj_set_style_pad_left(container, 0, 0);
  lv_obj_set_style_pad_right(container, 0, 0);
  lv_obj_set_style_pad_top(container, 0, 0);
  lv_obj_set_style_pad_bottom(container, 0, 0);
}

void align_center_x_y(lv_obj_t *obj)
{
  lv_obj_set_flex_align(obj, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
}