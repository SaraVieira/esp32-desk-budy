#include "loading.h"
#include "../images/images.h"
#include <Arduino.h>

// Global objects (defined in main.cpp)
extern lv_obj_t *loading_screen;
extern lv_obj_t *loading_animation;

static const lv_image_dsc_t *anim_imgs[4] = {
    &loading1,
    &loading2,
    &loading3,
    &loading4,
};

void create_loading_screen(void)
{
    static lv_style_t no_border_style;
    lv_style_init(&no_border_style);
    lv_style_set_border_width(&no_border_style, 0);
    loading_screen = lv_obj_create(NULL);

    lv_obj_set_style_bg_color(loading_screen, lv_color_hex(0x333333), LV_PART_MAIN);

    loading_animation = lv_animimg_create(loading_screen);
    lv_obj_center(loading_animation);
    lv_animimg_set_src(loading_animation, (const void **)anim_imgs, 4);
    lv_animimg_set_duration(loading_animation, 2400);
    lv_animimg_set_repeat_count(loading_animation, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(loading_animation);

    Serial.println("lv_animimg loading animation created and started");
}
