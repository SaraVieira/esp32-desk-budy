#include <lvgl.h>
#include <TFT_eSPI.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "screens.h"

// Replace with your network credentials
const char *ssid = "honest salsas food and wine";
const char *password = "choo choo";
unsigned long fetchTime;

// Store date and time
String temperature;
String temperatureDescription;
String current_date;

// Store hour, minute, second
bool sync_time_date = false;
int32_t screen = 1;
static bool is_day;
static int32_t hour;
static int32_t minute;
static int32_t second;
objects_t objects;

static int32_t screen_1_hour_1;
static int32_t screen_1_hour_2;
static int32_t screen_1_minute_1;
static int32_t screen_1_minute_2;
static int32_t screen_1_second_1;
static int32_t screen_1_second_2;


lv_obj_t *dateLabel;
lv_obj_t *timeLabel;
lv_obj_t *tempLabel;
lv_obj_t *descLabel;
lv_obj_t *iconLabel;

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

// ICONS
#define ICON_CLOUDS "\xEF\x83\x82"
#define ICON_TREND_DOWN "\xEE\x82\x97"
#define ICON_TREND_UP "\xEE\x82\x98"
#define ICON_SUN "\xEF\x86\x85"
#define ICON_CLOUD_MOON "\xEF\x9B\x83"
#define ICON_CLOUD_SUN "\xEF\x9B\x84"
#define ICON_CLOUD_SUN_RAIN = "\xEF\x9D\x83"
#define ICON_RAIN "\xEF\x9C\xBD"
#define ICON_SHOWERS "\xEF\x9D\x80"
#define ICON_SNOW "\xEF\x8B\x9C"
#define ICON_THUNDER "\xEF\x9D\xAC"

#define DRAW_BUF_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT / 10 * (LV_COLOR_DEPTH / 8))
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

static lv_obj_t *container;
static lv_obj_t *leftCol;
static lv_obj_t *rightCol;
static lv_obj_t *timeAndDate;
static lv_obj_t *iconAndTempRow;

static lv_style_t flexStyle;
static lv_style_t flexRowStyle;
static lv_style_t flexRowNoPaddingStyle;
static lv_style_t iconAndTemperature;

// Colors
static lv_color_t red = lv_color_hex(0xFE0301);
static lv_color_t green = lv_color_hex(0x02FF04);
static lv_color_t yellow = lv_color_hex(0xFEFF02);
static lv_color_t blue = lv_color_hex(0x1800FF);
static lv_color_t magenta = lv_color_hex(0xFF00FF);
static lv_color_t cyan = lv_color_hex(0x18FFFF);
static lv_color_t white = lv_color_hex(0xFFFFFF);
static lv_color_t black = lv_color_hex(0x000000);

static lv_color_t mutedDark = lv_color_hex(0x8B8B8B);

// Images for numbers
// small
LV_IMG_DECLARE(one);
LV_IMG_DECLARE(two);
LV_IMG_DECLARE(three);
LV_IMG_DECLARE(four);
LV_IMG_DECLARE(five);
LV_IMG_DECLARE(six);
LV_IMG_DECLARE(seven);
LV_IMG_DECLARE(eight);
LV_IMG_DECLARE(nine);
LV_IMG_DECLARE(colon);

// big
LV_IMG_DECLARE(one_big);
LV_IMG_DECLARE(two_big);
LV_IMG_DECLARE(three_big);
LV_IMG_DECLARE(four_big);
LV_IMG_DECLARE(five_big);
LV_IMG_DECLARE(six_big);
LV_IMG_DECLARE(seven_big);
LV_IMG_DECLARE(eight_big);
LV_IMG_DECLARE(nine_big);
LV_IMG_DECLARE(colon_big);

static void clearPaddings(lv_obj_t *container) {
  lv_obj_set_style_pad_left(container, 0, 0);
  lv_obj_set_style_pad_right(container, 0, 0);
  lv_obj_set_style_pad_top(container, 0, 0);
  lv_obj_set_style_pad_bottom(container, 0, 0);
}

String format_time(int time) {
  return (time < 10) ? "0" + String(time) : String(time);
}

static void timer_cb(lv_timer_t *timer) {
  LV_UNUSED(timer);
  second++;
  if (second > 59) {
    second = 0;
    minute++;
    if (minute > 59) {
      minute = 0;
      hour++;
      sync_time_date = true;
      Serial.println(sync_time_date);
      Serial.println("\n\n\n\n\n\n\n\n");
      if (hour > 23) {
        hour = 0;
      }
    }
  }

  String hour_time_f = format_time(hour);
  String minute_time_f = format_time(minute);
  String second_time_f = format_time(second);

  String final_time_str = String(hour_time_f) + ":" + String(minute_time_f) + ":" + String(second_time_f);
  // Serial.println(final_time_str);
  lv_label_set_text(timeLabel, final_time_str.c_str());
  lv_label_set_text(dateLabel, current_date.c_str());
}


void lv_create_global_styles() {
  // lv_style_init(&flexStyle);
  // lv_style_init(&flexRowStyle);
  // lv_style_init(&flexRowNoPaddingStyle);
  lv_style_init(&iconAndTemperature);


  // // container
  // container = lv_obj_create(lv_screen_active());
  // lv_obj_set_size(container, lv_pct(100), lv_pct(100));
  // lv_obj_align(container, LV_ALIGN_TOP_MID, 0, 0);
  // lv_obj_set_flex_flow(container, LV_FLEX_FLOW_ROW);
  // clearPaddings(container);

  // // container
  // leftCol = lv_obj_create(lv_screen_active());
  // lv_obj_set_size(leftCol, lv_pct(50), lv_pct(100));
  // lv_obj_align(leftCol, LV_ALIGN_TOP_LEFT, 0, 0);

  // // container
  // rightCol = lv_obj_create(lv_screen_active());
  // lv_obj_set_size(rightCol, lv_pct(50), lv_pct(100));
  // lv_obj_align(rightCol, LV_ALIGN_TOP_RIGHT, 0, 0);

  // // LEFT CONTAINER CHILDREN

  // // Clock
  // leftCol = lv_obj_create(lv_screen_active());
  // lv_obj_set_size(leftCol, lv_pct(50), lv_pct(100));
  // lv_obj_align(leftCol, LV_ALIGN_TOP_LEFT, 0, 0);
  // lv_obj_set_flex_flow(leftCol, LV_FLEX_FLOW_COLUMN);

  // timeAndDate = lv_obj_create(leftCol);
  // lv_obj_set_size(timeAndDate, lv_pct(100), 100);
  // lv_obj_align_to(timeAndDate, leftCol, LV_ALIGN_TOP_MID, 0, 0);
  // lv_obj_set_flex_flow(timeAndDate, LV_FLEX_FLOW_COLUMN);
  // clearPaddings(timeAndDate);

  // // Temperature
  // iconAndTempRow = lv_obj_create(leftCol);
  // lv_obj_set_size(iconAndTempRow, lv_pct(100), 60);
  // lv_obj_align_to(iconAndTempRow, leftCol, LV_ALIGN_TOP_MID, 0, 0);
  // lv_obj_set_flex_flow(iconAndTempRow, LV_FLEX_FLOW_ROW);
  // lv_obj_set_flex_align(iconAndTempRow, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  // lv_style_set_border_width(&iconAndTemperature, 0);
  // lv_style_set_pad_column(&iconAndTemperature, 0);
  // lv_style_set_pad_row(&iconAndTemperature, 0);
  // clearPaddings(iconAndTempRow);

  // // // Icon and temp row

  // // styles for both
  // lv_obj_set_style_bg_color(leftCol, black, LV_PART_MAIN);
  // lv_obj_set_style_bg_color(rightCol, black, LV_PART_MAIN);
  // lv_obj_set_style_bg_color(container, black, LV_PART_MAIN);
  // lv_obj_set_style_bg_color(iconAndTempRow, black, LV_PART_MAIN);
  // lv_obj_set_style_bg_color(timeAndDate, black, LV_PART_MAIN);
  // // lv_style_set_border_width(&flexStyle, 0);
  // // lv_style_set_border_width(&flexRowStyle, 0);
  // // lv_style_set_border_width(&flexRowNoPaddingStyle, 0);
  // // lv_style_set_pad_column(&flexRowNoPaddingStyle, 0);
  // // lv_style_set_pad_row(&flexRowNoPaddingStyle, 0);
  // // lv_obj_add_style(time_and_date_row, &flexRowStyle, 0);
  // // lv_obj_add_style(iconAndTempRow, &flexRowNoPaddingStyle, 0);
  // lv_obj_add_style(iconAndTempRow, &iconAndTemperature, 0);

  // // global styles
  lv_obj_set_style_bg_color(lv_screen_active(), black, LV_PART_MAIN);
}

void lv_create_main_gui(void) {
  lv_timer_t *timer = lv_timer_create(timer_cb, 1000, NULL);
  lv_timer_ready(timer);
  LV_FONT_DECLARE(inter_22);
  LV_FONT_DECLARE(font_awesome);
  LV_FONT_DECLARE(inter_16);

  static lv_style_t iconStyles;
  lv_style_init(&iconStyles);
  lv_style_set_text_font(&iconStyles, &font_awesome);
  lv_style_set_text_color(&iconStyles, white);

  static lv_style_t labelsStyleBigPrimary;
  lv_style_init(&labelsStyleBigPrimary);
  lv_style_set_text_font(&labelsStyleBigPrimary, &inter_22);
  lv_style_set_text_color(&labelsStyleBigPrimary, white);

  static lv_style_t labelsStyleSmallSecondary;
  lv_style_init(&labelsStyleSmallSecondary);
  lv_style_set_text_font(&labelsStyleSmallSecondary, &inter_16);
  lv_style_set_text_color(&labelsStyleSmallSecondary, mutedDark);

  static lv_style_t labelTimeAndDate;
  lv_style_init(&labelTimeAndDate);
  lv_style_set_text_font(&labelTimeAndDate, &inter_16);
  lv_style_set_text_color(&labelTimeAndDate, white);

  // time
  timeLabel = lv_label_create(timeAndDate);
  lv_obj_add_style(timeLabel, &labelTimeAndDate, 0);
  lv_obj_center(timeLabel);

  // date label
  dateLabel = lv_label_create(timeAndDate);
  lv_obj_add_style(dateLabel, &labelTimeAndDate, 0);
  lv_obj_center(dateLabel);

  // icon
  iconLabel = lv_label_create(iconAndTempRow);
  lv_obj_add_style(iconLabel, &iconStyles, 0);
  lv_obj_center(iconLabel);

  // temperature label
  tempLabel = lv_label_create(iconAndTempRow);
  lv_obj_add_style(tempLabel, &labelsStyleBigPrimary, 0);
  lv_obj_center(tempLabel);

  // weather description
  descLabel = lv_label_create(leftCol);
  lv_obj_add_style(descLabel, &labelsStyleSmallSecondary, 0);
  lv_obj_center(descLabel);
}

void get_info() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.setConnectTimeout(50000000);
    http.setTimeout(50000);
    // Construct the API endpoint
    String url = String("https://deskbuddy.deploy.iamsaravieira.com/");
    http.begin(url);
    int httpCode = http.GET();  // Make the GET request

    if (httpCode > 0) {
      if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        JsonDocument doc;
        DeserializationError error = deserializeJson(doc, payload);
        // Parse the JSON
        if (!error) {
          int32_t code;
          temperature = (const char *)doc["weather"]["temperature"];
          temperatureDescription = (const char *)doc["weather"]["description"];
          current_date = (const char *)doc["current"]["date"];
          hour = doc["current"]["hour"];
          minute = doc["current"]["minute"];
          second = doc["current"]["second"];
          const char *temp = temperature.c_str();
          const char *desc = temperatureDescription.c_str();
          const char *date = current_date.c_str();
          String final_time_str = String(hour) + ":" + String(minute) + ":" + String(second);
          const char *time = final_time_str.c_str();
          code = doc["weather"]["code"];
          // screen_1_hour_1 = createImage(hour);
          // lv_label_set_text(dateLabel, date);
          // lv_label_set_text(timeLabel, time);
          // lv_label_set_text(tempLabel, temp);
          // lv_label_set_text(descLabel, desc);
          // if (code == 0 || code == 1)
          // {
          //   lv_label_set_text(iconLabel, ICON_SUN);
          // }
          // if (code == 2)
          // {
          //   lv_label_set_text(iconLabel, ICON_CLOUD_SUN);
          // }
          // if (code == 3 || code == 45 || code == 48)
          // {
          //   lv_label_set_text(iconLabel, ICON_CLOUDS);
          // }
          // if (code == 65 || code == 81 || code == 82)
          // {
          //   lv_label_set_text(iconLabel, ICON_SHOWERS);
          // }
          // if (code == 73 || code == 75 || code == 77 || code == 85 || code == 86)
          // {
          //   lv_label_set_text(iconLabel, ICON_SNOW);
          // }
          // if (code == 95 || code == 96 || code == 99)
          // {
          //   lv_label_set_text(iconLabel, ICON_THUNDER);
          // }
          // if (code == 51 || code == 53 || code == 55 || code == 56 || code == 57 || code == 61 || code == 63 || code == 66 || code == 67 || code == 80)
          // {
          //   lv_label_set_text(iconLabel, ICON_RAIN);
          // }
        } else {
          Serial.print("deserializeJson() failed: ");
          Serial.println(error.c_str());
        }
      }
    } else {
      Serial.printf("GET request failed for weather, error: %s\n", http.errorToString(httpCode).c_str());
      sync_time_date = true;
    }
    http.end();  // Close connection
  } else {
    Serial.println("Not connected to Wi-Fi");
  }
}

void create_screen_1() {

//   static int32_t screen_1_hour_1;
// static int32_t screen_1_hour_2;
// static int32_t screen_1_minute_1;
// static int32_t screen_1_minute_2;
// static int32_t screen_1_second_1;
// static int32_t screen_1_second_2;
  // container
  static lv_obj_t *container;
  container = lv_obj_create(lv_screen_active());
  lv_obj_set_size(container, lv_pct(100), lv_pct(100));
  lv_obj_align(container, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_flex_flow(container, LV_FLEX_FLOW_ROW);
  clearPaddings(container);

  lv_obj_t *img1 = lv_image_create(lv_screen_active());
  lv_image_set_src(img1, &nine_big);
  lv_obj_align(img1, LV_ALIGN_CENTER, 0, 0);
}

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  // Start LVGL
  lv_init();

  // Create a display object
  lv_display_t *disp;
  // Initialize the TFT display using the TFT_eSPI library
  disp = lv_tft_espi_create(SCREEN_WIDTH, SCREEN_HEIGHT, draw_buf, sizeof(draw_buf));
  lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_270);
  // Function to draw the GUI
  lv_theme_t *theme = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
  lv_disp_set_theme(disp, theme);
  lv_create_global_styles();
}

void loop() {

  if (screen == 1) {
    create_screen_1();
  } else {
    lv_create_main_gui();
  }

  unsigned long msec = millis();
  if (msec >= fetchTime) {
    fetchTime += 15 * 60 * 1000L;  // 15 minutes
    get_info();
    Serial.println("Getting weather");
  }
  lv_task_handler();  // let the GUI do its work
  lv_tick_inc(5);     // tell LVGL how much time has passed
  delay(5);           // let this time pass
}