#include <lvgl.h>
#include <TFT_eSPI.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "images/images.h"
#include "styles/styles.h"

// Replace with your network credentials
const char *ssid = "honest salsas food and wine";
const char *password = "choo choo";
unsigned long fetchTime;

// Store date and time
String temperature;
String temperatureDescription;
String current_date;

static int32_t hour;
static int32_t minute;
static int32_t second;
static int32_t wmo_code;

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

#define BUTTON_PIN 5 // GIOP21 pin connected to button

// Variables will change:
int nextButtonPrevState = LOW; // the previous state from the input pin
int nextButtonCurrentState;    // the current reading from the input pin

// current_screen
static int current_screen = 0; // 0 for clock, 1 for weather, 2 for calendar

// Colors
static lv_color_t red = lv_color_hex(0xFE0301);
static lv_color_t green = lv_color_hex(0x02FF04);
static lv_color_t yellow = lv_color_hex(0xFEFF02);
static lv_color_t blue = lv_color_hex(0x1800FF);
static lv_color_t magenta = lv_color_hex(0xFF00FF);
static lv_color_t cyan = lv_color_hex(0x18FFFF);
static lv_color_t white = lv_color_hex(0xFFFFFF);
static lv_color_t black = lv_color_hex(0x000000);

// clock screen
static lv_obj_t *hour_1;
static lv_obj_t *hour_2;
static lv_obj_t *minute_1;
static lv_obj_t *minute_2;
static lv_obj_t *second_1;
static lv_obj_t *second_2;
static lv_obj_t *date_label;

// weather screen
static lv_obj_t *weather_icon;
static lv_obj_t *temperature_label;
static lv_obj_t *description_label;

struct Event
{
  String title;
  String description;
  String published;
};
std::vector<Event> events;

LV_FONT_DECLARE(teletext_24);
LV_FONT_DECLARE(teletext_22);
LV_FONT_DECLARE(teletext_40);

// screens
static lv_obj_t *clock_screen;
static lv_obj_t *weather_screen;
static lv_obj_t *news_screen;

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
  clear_paddings(lv_scr_act());
}

void get_current_time_and_weather()
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
          temperature = (const char *)doc["weather"]["temperature"];
          temperatureDescription = (const char *)doc["weather"]["description"];
          current_date = (const char *)doc["current"]["date"];
          hour = doc["current"]["hour"];
          minute = doc["current"]["minute"];
          second = doc["current"]["second"];
          std::transform(current_date.begin(), current_date.end(), current_date.begin(), ::toupper);
          const char *date = current_date.c_str();
          String final_time_str = String(hour) + ":" + String(minute) + ":" + String(second);
          const char *time = final_time_str.c_str();
          wmo_code = doc["weather"]["code"];
          screen_1_hour_1 = doc["current"]["separated"]["eu"]["hour"]["first"];
          screen_1_hour_2 = doc["current"]["separated"]["eu"]["hour"]["second"];
          screen_1_minute_1 = doc["current"]["separated"]["eu"]["minute"]["first"];
          screen_1_minute_2 = doc["current"]["separated"]["eu"]["minute"]["second"];
          screen_1_second_1 = doc["current"]["separated"]["eu"]["second"]["first"];
          screen_1_second_2 = doc["current"]["separated"]["eu"]["second"]["second"];
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
    http.end(); // Close connection
  }
  else
  {
    Serial.println("Not connected to Wi-Fi");
  }
}

void get_news()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;
    http.setConnectTimeout(50000000);
    http.setTimeout(50000);
    // Construct the API endpoint
    String url = String("https://deskbuddy.deploy.iamsaravieira.com/news");
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
          for (JsonObject newsItem : doc["news"].as<JsonArray>())
          {
            String title = newsItem["summary"];
            String description = newsItem["description"];
            String published = newsItem["published"];
            events.push_back({title, description, published});
          }

          for (const auto &article : events)
          {
            Serial.println(article.title);
            lv_obj_t *article_label = lv_label_create(news_screen);
            lv_label_set_text(article_label, article.title.c_str());
            lv_obj_set_style_text_color(article_label, white, LV_PART_MAIN);
          }
        }
      }
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
  align_center_x_y(container);
  clear_paddings(container);
  lv_obj_add_style(container, &no_border_style, 0);
  lv_obj_set_style_bg_color(container, black, LV_PART_MAIN);

  // create a flex row container that holds the time images
  lv_obj_t *time_container = lv_obj_create(container);
  lv_obj_set_size(time_container, lv_pct(100), 80);
  lv_obj_set_flex_flow(time_container, LV_FLEX_FLOW_ROW);

  align_center_x_y(time_container);
  clear_paddings(time_container);
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
  align_center_x_y(date_container);
  clear_paddings(date_container);
  lv_obj_add_style(date_container, &no_border_style, 0);
  lv_obj_set_style_bg_color(date_container, blue, LV_PART_MAIN);

  date_label = lv_label_create(date_container);
  lv_obj_set_style_text_color(date_label, black, LV_PART_MAIN);
}

void create_weather_screen(void)
{
  static lv_style_t no_border_style;
  lv_style_init(&no_border_style);
  lv_style_set_border_width(&no_border_style, 0);
  lv_style_set_text_font(&no_border_style, &teletext_24);
  // create a container that is flex and aligns. everything to the center on the x and y axes
  weather_screen = lv_obj_create(NULL);
  lv_obj_set_size(weather_screen, lv_pct(100), lv_pct(100));
  lv_obj_align(weather_screen, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_flex_flow(weather_screen, LV_FLEX_FLOW_COLUMN);
  align_center_x_y(weather_screen);
  clear_paddings(weather_screen);
  lv_obj_add_style(weather_screen, &no_border_style, 0);
  lv_obj_set_style_bg_color(weather_screen, black, LV_PART_MAIN);

  lv_obj_t *icon_and_temp = lv_obj_create(weather_screen);
  lv_obj_set_flex_flow(icon_and_temp, LV_FLEX_FLOW_ROW);
  align_center_x_y(icon_and_temp);
  clear_paddings(icon_and_temp);
  lv_obj_set_size(icon_and_temp, lv_pct(100), 100);
  lv_obj_add_style(icon_and_temp, &no_border_style, 0);
  lv_obj_set_style_bg_color(icon_and_temp, black, LV_PART_MAIN);

  weather_icon = lv_image_create(icon_and_temp);
  temperature_label = lv_label_create(icon_and_temp);
  lv_obj_set_style_text_color(temperature_label, white, LV_PART_MAIN);
  lv_obj_set_style_text_font(temperature_label, &teletext_40, LV_PART_MAIN);

  description_label = lv_label_create(weather_screen);
  lv_obj_set_style_text_color(description_label, magenta, LV_PART_MAIN);
}

void create_news_screen(void)
{
  static lv_style_t no_border_style;
  lv_style_init(&no_border_style);
  lv_style_set_border_width(&no_border_style, 0);
  lv_style_set_text_font(&no_border_style, &teletext_24);
  // create a container that is flex and aligns. everything to the center on the x and y axes
  news_screen = lv_obj_create(NULL);
  lv_obj_set_size(news_screen, lv_pct(100), lv_pct(100));
  lv_obj_align(news_screen, LV_ALIGN_LEFT_MID, 0, 0);
  lv_obj_set_flex_flow(news_screen, LV_FLEX_FLOW_COLUMN);
  align_center_x_y(news_screen);
  clear_paddings(news_screen);
  lv_obj_add_style(news_screen, &no_border_style, 0);
  lv_obj_set_style_bg_color(news_screen, black, LV_PART_MAIN);
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
  disp = lv_tft_espi_create(SCREEN_WIDTH, SCREEN_HEIGHT, draw_buf, sizeof(draw_buf));
  lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_90);
  lv_theme_t *theme = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
  lv_disp_set_theme(disp, theme);
  lv_timer_t *timer = lv_timer_create(timer_cb, 1000, NULL);
  lv_timer_ready(timer);

  lv_create_global_styles();
  create_weather_screen();
  create_screen_clock();
  create_news_screen();
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  lv_scr_load(clock_screen);
}

void change_screens()
{
  current_screen++;
  if (current_screen > 2)
  {
    current_screen = 0;
  }

  switch (current_screen)
  {
  case 0:
    lv_scr_load(clock_screen);
    break;
  case 1:
    lv_scr_load(weather_screen);
    break;
  case 2:
    lv_scr_load(news_screen);
    break;
  }
}

void loop()
{
  unsigned long msec = millis();
  if (msec >= fetchTime)
  {
    fetchTime += 15 * 60 * 1000L; // 15 minutes
    get_current_time_and_weather();
    get_news();
    Serial.println("Getting updated information");
  }
  lv_task_handler(); // let the GUI do its work
  lv_tick_inc(5);    // tell LVGL how much time has passed
  delay(5);          // let this time pass

  nextButtonCurrentState = digitalRead(BUTTON_PIN);

  if (nextButtonPrevState == HIGH && nextButtonCurrentState == LOW)
    change_screens();
  // save the the last state
  nextButtonPrevState = nextButtonCurrentState;
}
