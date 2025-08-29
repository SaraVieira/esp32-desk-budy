#ifndef STYLES_H
#define STYLES_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <lvgl.h>

    void clear_paddings(lv_obj_t *container);
    void align_center_x_y(lv_obj_t *obj);
    void init_colors(void);

    extern lv_color_t red;
    extern lv_color_t green;
    extern lv_color_t yellow;
    extern lv_color_t blue;
    extern lv_color_t magenta;
    extern lv_color_t cyan;
    extern lv_color_t white;
    extern lv_color_t black;

    extern const lv_font_t teletext_24;
    extern const lv_font_t teletext_22;
    extern const lv_font_t teletext_14;
    extern const lv_font_t teletext_40;

#ifdef __cplusplus
}
#endif

#endif // STYLES_H
