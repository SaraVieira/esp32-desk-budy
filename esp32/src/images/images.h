#ifdef __cplusplus
extern "C"
{
#endif

#ifndef IMAGES_H
#define IMAGES_H

#include <stdint.h>
#include "lvgl.h"
    extern const lv_img_dsc_t cloud_moon;
    extern const lv_img_dsc_t cloud_sun;
    extern const lv_img_dsc_t cloud_wind_moon;
    extern const lv_img_dsc_t cloud_moon_wind_sun;
    extern const lv_img_dsc_t cloud;
    extern const lv_img_dsc_t clouds;
    extern const lv_img_dsc_t lightning;
    extern const lv_img_dsc_t moon;
    extern const lv_img_dsc_t rain_lightning;
    extern const lv_img_dsc_t rain_snow;
    extern const lv_img_dsc_t rain_moon;
    extern const lv_img_dsc_t rain_sun;
    extern const lv_img_dsc_t snow_moon;
    extern const lv_img_dsc_t snow_sun;
    extern const lv_img_dsc_t snow;
    extern const lv_img_dsc_t sun;
    extern const lv_img_dsc_t wind;
    extern const lv_img_dsc_t zero;
    extern const lv_img_dsc_t one;
    extern const lv_img_dsc_t two;
    extern const lv_img_dsc_t three;
    extern const lv_img_dsc_t four;
    extern const lv_img_dsc_t five;
    extern const lv_img_dsc_t six;
    extern const lv_img_dsc_t seven;
    extern const lv_img_dsc_t eight;
    extern const lv_img_dsc_t nine;
    extern const lv_img_dsc_t colon;

    extern const lv_img_dsc_t loading1;
    extern const lv_img_dsc_t loading2;
    extern const lv_img_dsc_t loading3;
    extern const lv_img_dsc_t loading4;

    void create_image_from_number(lv_obj_t *parent, int32_t number);
    void create_image_from_wmo_code(lv_obj_t *parent, int32_t code, bool is_night);

#endif // IMAGES_H
#ifdef __cplusplus
}
#endif