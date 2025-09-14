#include "weather_time.h"
#include "../images/images.h"
#include "../styles/styles.h"
#include "secrets.h"

JsonDocument get_spotify_status()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;
        http.setConnectTimeout(50000000);
        http.setTimeout(50000);
        String url = String(API_URL_SPOTIFY_STATUS);
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

                    return doc;
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

JsonDocument spotify_next()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;
        http.setConnectTimeout(50000000);
        http.setTimeout(50000);
        String url = String(API_URL_SPOTIFY_NEXT);
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

                    return doc;
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

JsonDocument spotify_play()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;
        http.setConnectTimeout(50000000);
        http.setTimeout(50000);
        String url = String(API_URL_SPOTIFY_PLAY);
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

                    return doc;
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

JsonDocument spotify_pause()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;
        http.setConnectTimeout(50000000);
        http.setTimeout(50000);
        String url = String(API_URL_SPOTIFY_PAUSE);
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

                    return doc;
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

JsonDocument spotify_previous()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;
        http.setConnectTimeout(50000000);
        http.setTimeout(50000);
        String url = String(API_URL_SPOTIFY_PREVIOUS);
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

                    return doc;
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