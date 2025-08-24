#include <lvgl.h>
#include <TFT_eSPI.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "images/images.h"

// Replace with your network credentials
const char *ssid = "honest salsas food and wine";
const char *password = "choo choo";
unsigned long fetchTime;

// Store date and time
String temperature;
String temperatureDescription;
String current_date;

static bool is_day;
static int32_t hour;
static int32_t minute;
static int32_t second;

static int32_t screen_1_hour_1;
static int32_t screen_1_hour_2;
static int32_t screen_1_minute_1;
static int32_t screen_1_minute_2;
static int32_t screen_1_second_1;
static int32_t screen_1_second_2;

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

#define DRAW_BUF_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT / 10 * (LV_COLOR_DEPTH / 8))
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

// Colors
static lv_color_t red = lv_color_hex(0xFE0301);
static lv_color_t green = lv_color_hex(0x02FF04);
static lv_color_t yellow = lv_color_hex(0xFEFF02);
static lv_color_t blue = lv_color_hex(0x1800FF);
static lv_color_t magenta = lv_color_hex(0xFF00FF);
static lv_color_t cyan = lv_color_hex(0x18FFFF);
static lv_color_t white = lv_color_hex(0xFFFFFF);
static lv_color_t black = lv_color_hex(0x000000);

static lv_obj_t *hour_1;
static lv_obj_t *hour_2;
static lv_obj_t *minute_1;
static lv_obj_t *minute_2;
static lv_obj_t *second_1;
static lv_obj_t *second_2;
static lv_obj_t *date_label;
LV_FONT_DECLARE(teletext_24);
LV_FONT_DECLARE(teletext_24);

// screens
static lv_obj_t *clock_screen;
static lv_obj_t *weather_screen;

static void clearPaddings(lv_obj_t *container)
{
  lv_obj_set_style_pad_left(container, 0, 0);
  lv_obj_set_style_pad_right(container, 0, 0);
  lv_obj_set_style_pad_top(container, 0, 0);
  lv_obj_set_style_pad_bottom(container, 0, 0);
}

static void timer_cb(lv_timer_t *timer)
{
  LV_UNUSED(timer);
  second++;
  if (second > 59)
  {
    second = 0;
    minute++;
    if (minute > 59)
    {
      minute = 0;
      hour++;
      if (hour > 23)
      {
        hour = 0;
      }
    }
  }

  create_image_from_number(hour_1, hour / 10);
  create_image_from_number(hour_2, hour % 10);
  create_image_from_number(minute_1, minute / 10);
  create_image_from_number(minute_2, minute % 10);
  create_image_from_number(second_1, second / 10);
  create_image_from_number(second_2, second % 10);
}

void lv_create_global_styles()
{
  clearPaddings(lv_scr_act());
}

void create_weather_screen(void)
{
  // init style
  static lv_style_t no_border_style;
  lv_style_init(&no_border_style);
  lv_style_set_border_width(&no_border_style, 0);
  weather_screen = lv_obj_create(NULL);
}

void get_info()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;
    http.setConnectTimeout(50000000);
    http.setTimeout(50000);
    // Construct the API endpoint
    String url = String("https://deskbuddy.deploy.iamsaravieira.com/");
    http.begin(url);
    int httpCode = http.GET(); // Make the GET request

    if (httpCode > 0)
    {
      if (httpCode == HTTP_CODE_OK)
      {
        String payload = http.getString();
        JsonDocument doc;
        DeserializationError error = deserializeJson(doc, payload);
        // Parse the JSON
        if (!error)
        {
          int32_t code;
          temperature = (const char *)doc["weather"]["temperature"];
          temperatureDescription = (const char *)doc["weather"]["description"];
          current_date = (const char *)doc["current"]["date"];
          hour = doc["current"]["hour"];
          minute = doc["current"]["minute"];
          second = doc["current"]["second"];
          const char *temp = temperature.c_str();
          const char *desc = temperatureDescription.c_str();
          std::transform(current_date.begin(), current_date.end(), current_date.begin(), ::toupper);
          const char *date = current_date.c_str();
          String final_time_str = String(hour) + ":" + String(minute) + ":" + String(second);
          const char *time = final_time_str.c_str();
          code = doc["weather"]["code"];
          screen_1_hour_1 = doc["current"]["separated"]["eu"]["hour"]["first"];
          screen_1_hour_2 = doc["current"]["separated"]["eu"]["hour"]["second"];
          screen_1_minute_1 = doc["current"]["separated"]["eu"]["minute"]["first"];
          screen_1_minute_2 = doc["current"]["separated"]["eu"]["minute"]["second"];
          screen_1_second_1 = doc["current"]["separated"]["eu"]["second"]["first"];
          screen_1_second_2 = doc["current"]["separated"]["eu"]["second"]["second"];

          lv_label_set_text(date_label, date);
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
    http.end(); // Close connection
  }
  else
  {
    Serial.println("Not connected to Wi-Fi");
  }
}

void create_screen_clock()
{
  // init style
  static lv_style_t no_border_style;
  lv_style_init(&no_border_style);
  lv_style_set_border_width(&no_border_style, 0);
  lv_style_set_radius(&no_border_style, 0);
  lv_style_set_text_font(&no_border_style, &teletext_24);

  // container
  clock_screen = lv_obj_create(NULL);
  static lv_obj_t *container;
  container = lv_obj_create(clock_screen);
  lv_obj_set_size(container, lv_pct(100), lv_pct(100));
  lv_obj_align(container, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_flex_flow(container, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_flex_align(container, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  clearPaddings(container);
  lv_obj_add_style(container, &no_border_style, 0);
  lv_obj_set_style_bg_color(container, black, LV_PART_MAIN);

  // create a flex row container that holds the time images
  lv_obj_t *time_container = lv_obj_create(container);
  lv_obj_set_size(time_container, lv_pct(100), 80);
  lv_obj_set_flex_flow(time_container, LV_FLEX_FLOW_ROW);

  lv_obj_set_flex_align(time_container, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  clearPaddings(time_container);
  lv_obj_add_style(time_container, &no_border_style, 0);
  lv_obj_set_style_bg_color(time_container, black, LV_PART_MAIN);

  hour_1 = lv_image_create(time_container);
  create_image_from_number(hour_1, screen_1_hour_1);
  hour_2 = lv_image_create(time_container);
  create_image_from_number(hour_2, screen_1_hour_2);
  lv_obj_t *colon_hour = lv_image_create(time_container);
  lv_image_set_src(colon_hour, &colon);
  minute_1 = lv_image_create(time_container);
  create_image_from_number(minute_1, screen_1_minute_1);
  minute_2 = lv_image_create(time_container);
  create_image_from_number(minute_2, screen_1_minute_2);
  lv_obj_t *colon_minute = lv_image_create(time_container);
  lv_image_set_src(colon_minute, &colon);
  second_1 = lv_image_create(time_container);
  create_image_from_number(second_1, screen_1_second_1);
  second_2 = lv_image_create(time_container);
  create_image_from_number(second_2, screen_1_second_2);

  lv_obj_t *date_container = lv_obj_create(container);
  lv_obj_set_size(date_container, lv_pct(100), lv_pct(25));
  lv_obj_set_style_translate_y(date_container, -28, LV_PART_MAIN);
  lv_obj_set_flex_flow(date_container, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(date_container, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  clearPaddings(date_container);
  lv_obj_add_style(date_container, &no_border_style, 0);
  lv_obj_set_style_bg_color(date_container, blue, LV_PART_MAIN);

  date_label = lv_label_create(date_container);
  lv_obj_set_style_text_color(date_label, black, LV_PART_MAIN);
}

void setup()
{
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }

  // Start LVGL
  lv_init();

  // Create a display object
  lv_display_t *disp;
  // Initialize the TFT display using the TFT_eSPI library
  disp = lv_tft_espi_create(SCREEN_WIDTH, SCREEN_HEIGHT, draw_buf, sizeof(draw_buf));
  lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_90);
  // Function to draw the GUI
  lv_theme_t *theme = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
  lv_disp_set_theme(disp, theme);
  lv_timer_t *timer = lv_timer_create(timer_cb, 1000, NULL);
  lv_timer_ready(timer);
  lv_create_global_styles();
  create_weather_screen();
  create_screen_clock();

  lv_scr_load(clock_screen);
}

void loop()
{
  unsigned long msec = millis();
  if (msec >= fetchTime)
  {
    fetchTime += 15 * 60 * 1000L; // 15 minutes
    get_info();
    Serial.println("Getting weather");
  }
  lv_task_handler(); // let the GUI do its work
  lv_tick_inc(5);    // tell LVGL how much time has passed
  delay(5);          // let this time pass
}