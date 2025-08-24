#include <lvgl.h>

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