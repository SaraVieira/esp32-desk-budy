#include <lvgl.h>
#include <TFT_eSPI.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "images/images.h"
#include "styles/styles.h"
#include "http/calendar.h"
#include "http/weather_time.h"
#include "screens/loading/loading.h"
#include "screens/calendar/calendar.h"
#include "screens/weather/weather.h"
#include "screens/clock/clock.h"
#include "mic/mic.h"
#include "types.h"
#include "config.h"

unsigned long fetchTime;
static bool isFirstBoot = true;

// Create instances
TimeDisplay time_display = {0};
WeatherDisplay weather_display = {0};

uint32_t draw_buf[DRAW_BUF_SIZE / 4];

// Variables will change:
int nextButtonPrevState = LOW;
int nextButtonCurrentState;

enum class Screen : int
{
  CLOCK = 0,
  WEATHER = 1,
  CALENDAR = 2,
  COUNT = 3 // Useful for bounds checking
};
static Screen current_screen = Screen::CLOCK;

// screens
lv_obj_t *clock_screen;
lv_obj_t *weather_screen;
lv_obj_t *loading_screen;
lv_obj_t *calendar_screen;
lv_obj_t *loading_animation;

static void timer_cb(lv_timer_t *timer)
{
  LV_UNUSED(timer);
  time_display.second++;
  if (time_display.second > 59)
  {
    time_display.second = 0;
    time_display.minute++;
    if (time_display.minute > 59)
    {
      time_display.minute = 0;
      time_display.hour++;
      if (time_display.hour > 23)
      {
        time_display.hour = 0;
      }
    }
  }

  create_image_from_number(time_display.hour_1, time_display.hour / 10);
  create_image_from_number(time_display.hour_2, time_display.hour % 10);
  create_image_from_number(time_display.minute_1, time_display.minute / 10);
  create_image_from_number(time_display.minute_2, time_display.minute % 10);
  create_image_from_number(time_display.second_1, time_display.second / 10);
  create_image_from_number(time_display.second_2, time_display.second % 10);
}

void lv_create_global_styles()
{
  clear_paddings(lv_scr_act());
}

void setup()
{
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }

  // Start LVGL
  lv_init();
  init_colors();
  // Create a display object
  lv_display_t *disp;
  disp = lv_tft_espi_create(ScreenConfig::WIDTH, ScreenConfig::HEIGHT, draw_buf, sizeof(draw_buf));
  lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_90);
  lv_theme_t *theme = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
  lv_disp_set_theme(disp, theme);
  lv_timer_t *timer = lv_timer_create(timer_cb, 1000, NULL);
  lv_timer_ready(timer);
  lv_create_global_styles();

  create_weather_screen();
  create_screen_clock();
  create_calendar_screen();
  create_loading_screen();
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  lv_scr_load(loading_screen);

  // Initialize fetchTime so loading screen shows for a while
  fetchTime = millis() + LOADING_SCREEN_DURATION; // Show loading screen for 10 seconds
}
void change_screens()
{
  current_screen = static_cast<Screen>((static_cast<int>(current_screen) + 1) % static_cast<int>(Screen::COUNT));

  switch (current_screen)
  {
  case Screen::CLOCK:
    lv_scr_load(clock_screen);
    break;
  case Screen::WEATHER:
    lv_scr_load(weather_screen);
    break;
  case Screen::CALENDAR:
    lv_scr_load(calendar_screen);
    break;
  default:
    // Handle unexpected case
    current_screen = Screen::CLOCK;
    lv_scr_load(clock_screen);
    break;
  }
}

void loop()
{
  lv_task_handler(); // let the GUI do its work
  lv_tick_inc(5);    // tell LVGL how much time has passed
  delay(5);          // let this time pass

  unsigned long msec = millis();
  if (msec >= fetchTime)
  {
    fetchTime += WEATHER_UPDATE_INTERVAL;
    get_current_time_and_weather();
    get_calendar();
    if (isFirstBoot)
    {
      lv_scr_load(clock_screen);
      isFirstBoot = false;
    }

    Serial.println("Getting updated information");
  }

  nextButtonCurrentState = digitalRead(BUTTON_PIN);

  if (nextButtonPrevState == HIGH && nextButtonCurrentState == LOW)
    change_screens();
  // save the the last state
  nextButtonPrevState = nextButtonCurrentState;
  if (!isFirstBoot)
    read_mic();
}

