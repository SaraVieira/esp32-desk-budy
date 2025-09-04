#ifndef CONFIG_H
#define CONFIG_H

// Network Configuration
const char *const WIFI_SSID = "honest salsas food and wine";
const char *const WIFI_PASSWORD = "choo choo";

// Timing Configuration
const unsigned long WEATHER_UPDATE_INTERVAL = 15 * 60 * 1000L; // 15 minutes
const unsigned long LOADING_SCREEN_DURATION = 10000;           // 10 seconds

// Hardware Configuration
#define BUTTON_PIN_NEXT 5
#define BUTTON_PIN_PREV 18

// Display Configuration
struct ScreenConfig
{
    static constexpr int WIDTH = 240;
    static constexpr int HEIGHT = 320;
    static constexpr int BUFFER_DIVISOR = 10;
};

#define DRAW_BUF_SIZE (ScreenConfig::WIDTH * ScreenConfig::HEIGHT / ScreenConfig::BUFFER_DIVISOR * (LV_COLOR_DEPTH / 8))

#endif // CONFIG_H
