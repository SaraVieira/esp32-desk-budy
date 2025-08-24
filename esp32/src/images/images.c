#include <lvgl.h>

// Images for weather
LV_IMG_DECLARE(cloud_moon);
LV_IMG_DECLARE(cloud_sun);
LV_IMG_DECLARE(cloud_wind_moon);
LV_IMG_DECLARE(cloud_moon_wind_sun);
LV_IMG_DECLARE(cloud);
LV_IMG_DECLARE(clouds);
LV_IMG_DECLARE(lightning);
LV_IMG_DECLARE(moon);
LV_IMG_DECLARE(rain_lightning);
LV_IMG_DECLARE(rain_snow);
LV_IMG_DECLARE(rain);
LV_IMG_DECLARE(rain_moon);
LV_IMG_DECLARE(rain_sun);
LV_IMG_DECLARE(snow_moon);
LV_IMG_DECLARE(snow_sun);
LV_IMG_DECLARE(snow);
LV_IMG_DECLARE(sun);
LV_IMG_DECLARE(wind);

// Images for numbers
LV_IMG_DECLARE(zero);
LV_IMG_DECLARE(one);
LV_IMG_DECLARE(two);
LV_IMG_DECLARE(three);
LV_IMG_DECLARE(four);
LV_IMG_DECLARE(five);
LV_IMG_DECLARE(six);
LV_IMG_DECLARE(seven);
LV_IMG_DECLARE(eight);
LV_IMG_DECLARE(nine);
LV_IMG_DECLARE(colon);

void create_image_from_number(lv_obj_t *parent, int32_t number)
{
  switch (number)
  {
  case 0:
    lv_image_set_src(parent, &zero);
    break;
  case 1:
    lv_image_set_src(parent, &one);
    break;
  case 2:
    lv_image_set_src(parent, &two);
    break;
  case 3:
    lv_image_set_src(parent, &three);
    break;
  case 4:
    lv_image_set_src(parent, &four);
    break;
  case 5:
    lv_image_set_src(parent, &five);
    break;
  case 6:
    lv_image_set_src(parent, &six);
    break;
  case 7:
    lv_image_set_src(parent, &seven);
    break;
  case 8:
    lv_image_set_src(parent, &eight);
    break;
  case 9:
    lv_image_set_src(parent, &nine);
    break;
  }
}