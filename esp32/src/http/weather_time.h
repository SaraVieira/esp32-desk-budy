#pragma once
#include <lvgl.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>

void get_current_time_and_weather(lv_obj_t *weather_icon, lv_obj_t *temperature_label, lv_obj_t *description_label, lv_obj_t *date_label, int32_t &hour, int32_t &minute, int32_t &second);
