#ifndef STYLES_H
#define STYLES_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <lvgl.h>

    void clear_paddings(lv_obj_t *container);
    void align_center_x_y(lv_obj_t *obj);

#ifdef __cplusplus
}
#endif

#endif // STYLES_H
