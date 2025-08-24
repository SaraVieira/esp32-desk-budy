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
void create_image_from_wmo_code(lv_obj_t *parent, int32_t wmo_code, bool is_day)
{
  if (wmo_code == 0 || wmo_code == 1)
  {
    if (is_day)
    {
      lv_image_set_src(parent, &sun);
    }
    else
    {
      lv_image_set_src(parent, &moon);
    }
  }
  if (wmo_code == 2)
  {
    if (is_day)
    {
      lv_image_set_src(parent, &cloud_sun);
    }
    else
    {
      lv_image_set_src(parent, &cloud_moon);
    }
  }
  if (wmo_code == 3 || wmo_code == 45 || wmo_code == 48)
  {

    lv_image_set_src(parent, &clouds);
  }
  if (wmo_code == 65 || wmo_code == 81 || wmo_code == 82)
  {
    if (is_day)
    {
      lv_image_set_src(parent, &rain_sun);
    }
    else
    {
      lv_image_set_src(parent, &rain_moon);
    }
  }
  if (wmo_code == 73 || wmo_code == 75 || wmo_code == 77 || wmo_code == 85 || wmo_code == 86)
  {
    if (is_day)
    {
      lv_image_set_src(parent, &snow_sun);
    }
    else
    {
      lv_image_set_src(parent, &snow_moon);
    }
  }
  if (wmo_code == 95 || wmo_code == 96 || wmo_code == 99)
  {
    lv_image_set_src(parent, &lightning);
  }
  if (wmo_code == 51 || wmo_code == 53 || wmo_code == 55 || wmo_code == 56 || wmo_code == 57 || wmo_code == 61 || wmo_code == 63 || wmo_code == 66 || wmo_code == 67 || wmo_code == 80)
  {
    if (is_day)
    {
      lv_image_set_src(parent, &rain_sun);
    }
    else
    {
      lv_image_set_src(parent, &rain_moon);
    }
  }
}
