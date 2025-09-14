#pragma once
#include <lvgl.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "../types.h"

JsonDocument get_spotify_status();
JsonDocument spotify_next();
JsonDocument spotify_previous();
JsonDocument spotify_play();
JsonDocument spotify_pause();