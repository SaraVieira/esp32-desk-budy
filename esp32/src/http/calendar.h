#pragma once
#include <vector>
#include <ArduinoJson.h>
#include <lvgl.h>
#include "../styles/styles.h"

struct Event
{
    String summary;
    String start;
    String end;
    bool confirmed;
    String startTime;
    String endTime;
    bool allDay;
    String duration;
};

void get_calendar(lv_obj_t *calendar_screen);
