#include <lvgl.h>
#include <TFT_eSPI.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "images/images.h"
#include "styles/styles.h"
#include "http/calendar.h"
#include "http/weather_time.h"

// Replace with your network credentials
const char *ssid = "honest salsas food and wine";
const char *password = "choo choo";
unsigned long fetchTime;
static bool isFirstBoot = true;

static lv_obj_t *weather_icon;
static lv_obj_t *temperature_label;
static lv_obj_t *description_label;

static int32_t hour;
static int32_t minute;
static int32_t second;
static int32_t wmo_code;

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

#define DRAW_BUF_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT / 10 * (LV_COLOR_DEPTH / 8))
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

#define BUTTON_PIN 5 // GIOP21 pin connected to button

// Variables will change:
int nextButtonPrevState = LOW;
int nextButtonCurrentState;

// current_screen
static int current_screen = 0; // 0 for clock, 1 for weather, 2 for calendar

// clock screen
static lv_obj_t *hour_1;
static lv_obj_t *hour_2;
static lv_obj_t *minute_1;
static lv_obj_t *minute_2;
static lv_obj_t *second_1;
static lv_obj_t *second_2;
static lv_obj_t *date_label;

// screens
static lv_obj_t *clock_screen;
static lv_obj_t *weather_screen;
static lv_obj_t *loading_screen;
static lv_obj_t *calendar_screen;

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
  hour_2 = lv_image_create(time_container);
  lv_obj_t *colon_hour = lv_image_create(time_container);
  lv_image_set_src(colon_hour, &colon);
  minute_1 = lv_image_create(time_container);
  minute_2 = lv_image_create(time_container);
  lv_obj_t *colon_minute = lv_image_create(time_container);
  lv_image_set_src(colon_minute, &colon);
  second_1 = lv_image_create(time_container);
  second_2 = lv_image_create(time_container);

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

void create_calendar_screen(void)
{
  static lv_style_t no_border_style;
  lv_style_init(&no_border_style);
  lv_style_set_border_width(&no_border_style, 0);
  lv_style_set_text_font(&no_border_style, &teletext_14);
  calendar_screen = lv_obj_create(NULL);
  lv_obj_set_size(calendar_screen, lv_pct(100), lv_pct(100));
  lv_obj_align(calendar_screen, LV_ALIGN_LEFT_MID, 0, 0);
  lv_obj_set_flex_flow(calendar_screen, LV_FLEX_FLOW_COLUMN);
  align_center_x_y(calendar_screen);
  clear_paddings(calendar_screen);
  lv_obj_add_style(calendar_screen, &no_border_style, 0);
  lv_obj_set_style_bg_color(calendar_screen, black, LV_PART_MAIN);
}

void create_loading_screen()
{
  static lv_style_t no_border_style;
  lv_style_init(&no_border_style);
  lv_style_set_border_width(&no_border_style, 0);
  lv_style_set_text_font(&no_border_style, &teletext_14);
  loading_screen = lv_obj_create(NULL);
  lv_obj_set_size(loading_screen, lv_pct(100), lv_pct(100));
  lv_obj_align(loading_screen, LV_ALIGN_LEFT_MID, 0, 0);
  lv_obj_set_flex_flow(loading_screen, LV_FLEX_FLOW_COLUMN);
  align_center_x_y(loading_screen);
  clear_paddings(loading_screen);
  lv_obj_add_style(loading_screen, &no_border_style, 0);
  lv_obj_set_style_bg_color(loading_screen, black, LV_PART_MAIN);

  lv_obj_t *loading_label = lv_label_create(loading_screen);
  lv_label_set_text(loading_label, "Loading...");
  lv_obj_set_style_text_color(loading_label, white, LV_PART_MAIN);
  lv_obj_set_style_text_font(loading_label, &teletext_24, LV_PART_MAIN);
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
  init_colors();
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
  create_calendar_screen();
  create_loading_screen();
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  lv_scr_load(loading_screen);
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
    lv_scr_load(calendar_screen);
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
    fetchTime += 15 * 60 * 1000L; // 15 minutes
    get_current_time_and_weather(weather_icon, temperature_label, description_label, date_label, hour, minute, second);
    get_calendar(calendar_screen);
    if (isFirstBoot)
    {
      lv_scr_load(calendar_screen);
      isFirstBoot = false;
    }

    Serial.println("Getting updated information");
  }

  nextButtonCurrentState = digitalRead(BUTTON_PIN);

  if (nextButtonPrevState == HIGH && nextButtonCurrentState == LOW)
    change_screens();
  // save the the last state
  nextButtonPrevState = nextButtonCurrentState;
}
