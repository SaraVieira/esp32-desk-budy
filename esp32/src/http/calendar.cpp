#include "calendar.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include "styles/styles.h"

extern lv_obj_t *calendar_screen;
void get_calendar()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;
        http.setConnectTimeout(50000000);
        http.setTimeout(50000);
        String url = String("https://deskbuddy.deploy.iamsaravieira.com/events");
        http.begin(url);
        int httpCode = http.GET();

        if (httpCode > 0)
        {
            if (httpCode == HTTP_CODE_OK)
            {
                String payload = http.getString();
                JsonDocument doc;
                DeserializationError error = deserializeJson(doc, payload);
                if (!error)
                {
                    static lv_style_t no_border_style;
                    lv_style_init(&no_border_style);
                    lv_style_set_border_width(&no_border_style, 0);
                    lv_obj_set_style_pad_row(calendar_screen, 0, LV_PART_MAIN);
                    lv_style_set_text_font(&no_border_style, &teletext_14);
                    lv_obj_set_style_pad_column(calendar_screen, 0, LV_PART_MAIN);
                    lv_obj_t *calendar_label;
                    lv_obj_t *time_label;
                    lv_obj_t *container;
                    lv_obj_clean(lv_scr_act());
                    for (JsonObject event : doc["events"].as<JsonArray>())
                    {
                        String summary = event["summary"];
                        String start = event["start"];
                        String end = event["end"];
                        bool confirmed = event["confirmed"];
                        String startTime = event["startTime"];
                        String endTime = event["endTime"];
                        bool allDay = event["allDay"];
                        String duration = event["duration"];
                        String type = event["calendar_type"];
                        container = lv_obj_create(calendar_screen);
                        clear_paddings(container);
                        align_center_x_y(container);
                        lv_obj_set_size(container, lv_pct(100), 40);
                        lv_obj_set_style_radius(container, 0, LV_PART_MAIN);
                        lv_obj_set_style_bg_color(container, type == "work" ? blue : (type == "personal" ? magenta : red), LV_PART_MAIN);
                        lv_obj_add_style(container, &no_border_style, 0);
                        calendar_label = lv_label_create(container);
                        lv_label_set_text(calendar_label, summary.c_str());
                        lv_obj_set_flex_flow(container, LV_FLEX_FLOW_ROW);
                        lv_obj_set_flex_align(container, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
                        lv_obj_set_style_pad_left(container, 10, LV_PART_MAIN);
                        lv_obj_set_style_pad_right(container, 10, LV_PART_MAIN);
                        lv_obj_set_style_text_color(calendar_label, type == "work" ? white : (type == "personal" ? black : white), LV_PART_MAIN);
                        lv_obj_add_style(calendar_label, &no_border_style, 0);

                        if (allDay)
                        {
                            time_label = lv_label_create(container);
                            lv_label_set_text(time_label, duration.c_str());
                            lv_obj_set_style_text_color(time_label, type == "work" ? white : (type == "personal" ? black : white), LV_PART_MAIN);

                            lv_obj_add_style(time_label, &no_border_style, 0);
                        }
                        else
                        {
                            time_label = lv_label_create(container);
                            lv_label_set_text(time_label, (startTime + "-" + endTime).c_str());
                            lv_obj_set_style_text_color(time_label, type == "work" ? white : (type == "personal" ? black : white), LV_PART_MAIN);
                            lv_obj_add_style(time_label, &no_border_style, 0);
                        }
                    }
                }
            }
        }
        http.end();
    }
    else
    {
        Serial.println("Not connected to Wi-Fi");
    }
}
