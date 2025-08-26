#include "calendar.h"
#include <WiFi.h>
#include <HTTPClient.h>
LV_FONT_DECLARE(teletext_14);

std::vector<Event> events;

void get_calendar(lv_obj_t *calendar_screen, lv_color_t black, lv_color_t white)
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
                        events.push_back({summary, start, end, confirmed, startTime, endTime, allDay, duration});
                    }

                    for (const auto &calendar : events)
                    {
                        static lv_obj_t *container;
                        static lv_style_t no_border_style;
                        lv_style_init(&no_border_style);
                        lv_style_set_border_width(&no_border_style, 0);
                        lv_style_set_text_font(&no_border_style, &teletext_14);

                        container = lv_obj_create(calendar_screen);
                        clear_paddings(container);
                        align_center_x_y(container);
                        lv_obj_set_size(container, lv_pct(100), lv_pct(20));
                        lv_obj_add_style(container, &no_border_style, 0);
                        lv_obj_t *calendar_label = lv_label_create(container);
                        lv_obj_set_style_bg_color(container, black, LV_PART_MAIN);
                        lv_label_set_text(calendar_label, calendar.summary.c_str());
                        lv_obj_set_style_text_color(calendar_label, white, LV_PART_MAIN);
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
