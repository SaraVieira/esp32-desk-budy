#include <lvgl.h>
#include <TFT_eSPI.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <AiEsp32RotaryEncoder.h>
#include <ArduinoJson.h>
#include "images/images.h"
#include "styles/styles.h"
#include "http/calendar.h"
#include "http/weather_time.h"
#include "screens/loading/loading.h"
#include "screens/calendar/calendar.h"
#include "screens/weather/weather.h"
#include "screens/clock/clock.h"
#include "screens/spotify/spotify.h"
#include "mic/mic.h"
#include "secrets.h"
#include "types.h"
#include "config.h"
#include <map>

unsigned long fetchTime;
static bool isFirstBoot = true;

AiEsp32RotaryEncoder rotaryEncoder = AiEsp32RotaryEncoder(ROTARY_ENCODER_A_PIN, ROTARY_ENCODER_B_PIN, ROTARY_ENCODER_BUTTON_PIN, ROTARY_ENCODER_VCC_PIN, ROTARY_ENCODER_STEPS);

bool DIRECTION_CW_SELECTED = false; // true means clockwise increases values
bool DIRECTION_CCW_SELECTED = false;
int32_t lastEncoderValue = 0;

// Create instances
TimeDisplay time_display = {0};
WeatherDisplay weather_display = {0};
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

// Variables will change:
int nextButtonPrevState = LOW;
int nextButtonCurrentState;

int prevButtonPrevState = LOW;
int prevButtonCurrentState;

Screen current_screen = Screen::CLOCK;

// screens
lv_obj_t *clock_screen;
lv_obj_t *weather_screen;
lv_obj_t *loading_screen;
lv_obj_t *calendar_screen;
lv_obj_t *spotify_screen;
lv_obj_t *loading_animation;

std::map<Screen, lv_obj_t **> screen_map = {
    {Screen::CLOCK, &clock_screen},
    {Screen::WEATHER, &weather_screen},
    {Screen::CALENDAR, &calendar_screen},
    {Screen::SPOTIFY, &spotify_screen}};

static int64_t lastTime = 0;
unsigned long delayBetweenRequests = 20000; // Time between requests (20 seconds)
unsigned long requestDueTime;               // time when request due

static void timer_cb()
{
  float_t in_seconds = (esp_timer_get_time() - lastTime) / 1000000;
  if (in_seconds > 0.99)
  {
    lastTime = esp_timer_get_time();
    if (in_seconds > 1)
    {
      time_display.second += (int)in_seconds;
    }
    else
    {

      time_display.second++;
    }

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

       // Update the clock display only if the current screen is CLOCK
      create_image_from_number(time_display.hour_1, time_display.hour / 10);
      create_image_from_number(time_display.hour_2, time_display.hour % 10);
      create_image_from_number(time_display.minute_1, time_display.minute / 10);
      create_image_from_number(time_display.minute_2, time_display.minute % 10);
      create_image_from_number(time_display.second_1, time_display.second / 10);
      create_image_from_number(time_display.second_2, time_display.second % 10);
    }
}

void lv_create_global_styles()
{
  clear_paddings(lv_scr_act());
}

void IRAM_ATTR readEncoderISR()
{
  rotaryEncoder.readEncoder_ISR();
}

void change_screens(int value)
{
  rotaryEncoder.setEncoderValue(0);

  current_screen = static_cast<Screen>((static_cast<int>(current_screen) + value) % static_cast<int>(Screen::COUNT));

  if (static_cast<int>(current_screen) < 0)
  {
    current_screen = Screen::CALENDAR;
  }

  // Use the map to load the screen
  auto it = screen_map.find(current_screen);
  if (it != screen_map.end() && *(it->second) != nullptr)
  {
    lv_scr_load(*(it->second));
  }
  else
  {
    // Handle unexpected case
    current_screen = Screen::CLOCK;
    lv_scr_load(clock_screen);
  }
}
  void rotary_loop()
  {

    // dont print anything unless value changed
    if (rotaryEncoder.encoderChanged())
    {

      if (lastEncoderValue > rotaryEncoder.readEncoder())
      {
        if (current_screen == Screen::SPOTIFY)
        {
          on_clockwise();
        }
        // turned clockwise
        Serial.println("clockwise ");
        DIRECTION_CW_SELECTED = true;
        DIRECTION_CCW_SELECTED = false;
      }
      else
      {
        if (current_screen == Screen::SPOTIFY)
        {
          on_counter_clockwise();
        }
        Serial.println("counter clockwise ");
        // turned counter-clockwise
        DIRECTION_CW_SELECTED = false;
        DIRECTION_CCW_SELECTED = true;
      }
      lastEncoderValue = rotaryEncoder.readEncoder();
    }
    else
    {
      lastEncoderValue = rotaryEncoder.readEncoder();
    }
    if (rotaryEncoder.isEncoderButtonClicked())
    {
      static unsigned long lastTimePressed = 0; // Soft debouncing
      if (millis() - lastTimePressed < 500)
      {
        return;
      }
      if (current_screen == Screen::SPOTIFY)
      {
        on_rotary_clicked();
      }
    }
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
    lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_270);
    lv_theme_t *theme = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(disp, theme);
    lv_create_global_styles();

    create_weather_screen();
    create_screen_clock();
    create_calendar_screen();
    create_loading_screen();
    create_spotify_screen();
    pinMode(BUTTON_PIN_NEXT, INPUT_PULLUP);
    pinMode(BUTTON_PIN_PREV, INPUT_PULLUP);

    lv_scr_load(loading_screen);

    // Initialize fetchTime so loading screen shows for a while
    fetchTime = millis() + LOADING_SCREEN_DURATION; // Show loading screen for 10 seconds

    // we must initialize rotary encoder
    rotaryEncoder.begin();
    rotaryEncoder.setup(readEncoderISR);

    rotaryEncoder.setBoundaries(-5000000, 5000000, true);
    rotaryEncoder.setEncoderValue(lastEncoderValue);

    rotaryEncoder.disableAcceleration();
  }

  void loop()
  {
    lv_task_handler(); // let the GUI do its work
    lv_tick_inc(5);    // tell LVGL how much time has passed
    delay(5);          // let this time pass
    timer_cb();

    yield(); // Let system tasks run after LVGL operations

    if (current_screen == Screen::SPOTIFY)
    {
      delayBetweenRequests = 5000; // Update every 5 seconds when on Spotify screen
    }
    else
    {
      delayBetweenRequests = 500000; // Update every 500 seconds when not on Spotify screen
    }

    unsigned long msec = millis();
    if (msec >= fetchTime)
    {
      fetchTime += WEATHER_UPDATE_INTERVAL;

      get_current_time_and_weather();
      yield(); // Let system tasks run between HTTP requests

      get_calendar();
      yield(); // Let system tasks run after HTTP requests

      if (isFirstBoot)
      {
        lv_screen_load(*(screen_map.find(current_screen)->second));
        isFirstBoot = false;
      }

      Serial.println("Getting updated information");
    }

    nextButtonCurrentState = digitalRead(BUTTON_PIN_NEXT);
    prevButtonCurrentState = digitalRead(BUTTON_PIN_PREV);

    if (nextButtonPrevState == HIGH && nextButtonCurrentState == LOW)
      change_screens(1);
    if (prevButtonPrevState == HIGH && prevButtonCurrentState == LOW)
      change_screens(-1);

    nextButtonPrevState = nextButtonCurrentState;
    prevButtonPrevState = prevButtonCurrentState;

    if (!isFirstBoot)
    {
      yield(); // Let system tasks run before mic processing
      read_mic();
    }
    if (millis() > requestDueTime)
    {
      show_currently_playing();

      requestDueTime = millis() + delayBetweenRequests;
    }

    yield(); // Let system tasks run before reading rotary encoder
    rotary_loop();
    delay(50); // or do whatever you need to do...

    yield(); // Final yield at end of loop
  }