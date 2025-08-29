#include "weather_time.h"
#include "../images/images.h"
#include "../styles/styles.h"

void get_current_time_and_weather(lv_obj_t *weather_icon, lv_obj_t *temperature_label, lv_obj_t *description_label, lv_obj_t *date_label, int &hour, int &minute, int &second)
{
    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;
        http.setConnectTimeout(50000000);
        http.setTimeout(50000);
        String url = String("https://deskbuddy.deploy.iamsaravieira.com/");
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

                    String temperature = (const char *)doc["weather"]["temperature"];
                    String temperatureDescription = (const char *)doc["weather"]["description"];
                    String current_date = (const char *)doc["current"]["date"];
                    hour = doc["current"]["hour"];
                    minute = doc["current"]["minute"];
                    second = doc["current"]["second"];

                    std::transform(current_date.begin(), current_date.end(), current_date.begin(), ::toupper);
                    const char *date = current_date.c_str();
                    String final_time_str = String(hour) + ":" + String(minute) + ":" + String(second);
                    const char *time = final_time_str.c_str();
                    int32_t wmo_code = doc["weather"]["code"];
                    std::transform(temperatureDescription.begin(), temperatureDescription.end(), temperatureDescription.begin(), ::toupper);
                    lv_label_set_text(temperature_label, temperature.c_str());
                    lv_label_set_text(description_label, temperatureDescription.c_str());
                    lv_label_set_text(date_label, date);
                    create_image_from_wmo_code(weather_icon, wmo_code, doc["weather"]["isDay"] == 1);
                }
                else
                {
                    Serial.print("deserializeJson() failed: ");
                    Serial.println(error.c_str());
                }
            }
        }
        else
        {
            Serial.printf("GET request failed for weather, error: %s\n", http.errorToString(httpCode).c_str());
        }
        http.end();
    }
    else
    {
        Serial.println("Not connected to Wi-Fi");
    }
}
