#include <lvgl.h>
#include <TFT_eSPI.h>

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// Replace with your network credentials
const char* ssid = "honest salsas food and wine";
const char* password = "choo choo";
unsigned long fetchTime;

// Store date and time
String temperature;
String temperatureDescription;
String current_date;

// Store hour, minute, second
bool sync_time_date = false;
static bool is_day;
static int32_t hour;
static int32_t minute;
static int32_t second;

static lv_style_t flexStyle;
static lv_style_t flexRowStyle;
static lv_obj_t* weather_col;
static lv_obj_t* time_and_date_row;
lv_obj_t* dateLabel;
lv_obj_t* timeLabel;
lv_obj_t* tempLabel;
lv_obj_t* descLabel;
lv_obj_t* iconLabel;

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



#define DRAW_BUF_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT / 10 * (LV_COLOR_DEPTH / 8))
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

String format_time(int time) {
  return (time < 10) ? "0" + String(time) : String(time);
}


static void timer_cb(lv_timer_t* timer) {
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
  //Serial.println(final_time_str);
  lv_label_set_text(timeLabel, final_time_str.c_str());
  lv_label_set_text(dateLabel, current_date.c_str());
}

void lv_create_global_styles() {
  lv_style_init(&flexStyle);
  lv_style_init(&flexRowStyle);

  // time row
  time_and_date_row = lv_obj_create(lv_screen_active());
  lv_obj_set_size(time_and_date_row, lv_pct(100), lv_pct(20));
  lv_obj_align(time_and_date_row, LV_ALIGN_TOP_MID, 0, 2);
  lv_obj_set_flex_flow(time_and_date_row, LV_FLEX_FLOW_ROW);
  lv_style_set_flex_main_place(&flexRowStyle, LV_FLEX_ALIGN_SPACE_BETWEEN);


  // weather col
  weather_col = lv_obj_create(lv_screen_active());
  lv_obj_set_size(weather_col, lv_pct(100), lv_pct(75));
  lv_obj_align_to(weather_col, time_and_date_row, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
  lv_obj_set_flex_flow(weather_col, LV_FLEX_FLOW_COLUMN);


  // styles for both
  lv_obj_set_style_bg_color(weather_col, lv_color_hex(0x2E2E2E), LV_PART_MAIN);
  lv_obj_set_style_bg_color(time_and_date_row, lv_color_hex(0x2E2E2E), LV_PART_MAIN);
  lv_style_set_border_width(&flexStyle, 0);
  lv_style_set_border_width(&flexRowStyle, 0);
  lv_obj_add_style(weather_col, &flexStyle, 0);
  lv_obj_add_style(time_and_date_row, &flexRowStyle, 0);

  // global styles
  lv_obj_set_style_bg_color(lv_screen_active(), lv_color_hex(0x2E2E2E), LV_PART_MAIN);
}

void lv_create_main_gui(void) {
  lv_timer_t* timer = lv_timer_create(timer_cb, 1000, NULL);
  lv_timer_ready(timer);
  LV_FONT_DECLARE(inter_22);
  LV_FONT_DECLARE(font_awesome);
  LV_FONT_DECLARE(inter_16);

  static lv_style_t iconStyles;
  lv_style_init(&iconStyles);
  lv_style_set_text_font(&iconStyles, &font_awesome);
  lv_style_set_text_color(&iconStyles, lv_color_hex(0xFFFFFF));

  static lv_style_t labelsStyleBigPrimary;
  lv_style_init(&labelsStyleBigPrimary);
  lv_style_set_text_font(&labelsStyleBigPrimary, &inter_22);
  lv_style_set_text_color(&labelsStyleBigPrimary, lv_color_hex(0xFFFFFF));

  static lv_style_t labelsStyleSmallSecondary;
  lv_style_init(&labelsStyleSmallSecondary);
  lv_style_set_text_font(&labelsStyleSmallSecondary, &inter_16);
  lv_style_set_text_color(&labelsStyleSmallSecondary, lv_color_hex(0x8B8B8B));

  static lv_style_t labelTimeAndDate;
  lv_style_init(&labelTimeAndDate);
  lv_style_set_text_font(&labelTimeAndDate, &inter_16);
  lv_style_set_text_color(&labelTimeAndDate, lv_color_hex(0xFFFFFF));


  // date label
  dateLabel = lv_label_create(time_and_date_row);
  lv_obj_add_style(dateLabel, &labelTimeAndDate, 0);
  lv_obj_center(dateLabel);

  // time
  timeLabel = lv_label_create(time_and_date_row);
  lv_obj_add_style(timeLabel, &labelTimeAndDate, 0);
  lv_obj_center(timeLabel);

  // icon
  iconLabel = lv_label_create(weather_col);
  lv_obj_add_style(iconLabel, &iconStyles, 0);
  lv_obj_center(iconLabel);

  // temperature label
  tempLabel = lv_label_create(weather_col);
  lv_obj_add_style(tempLabel, &labelsStyleBigPrimary, 0);
  lv_obj_center(tempLabel);



  // weather description
  descLabel = lv_label_create(weather_col);
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
          temperature = (const char*)doc["weather"]["temperature"];
          temperatureDescription = (const char*)doc["weather"]["description"];
          current_date = (const char*)doc["current"]["date"];
          hour = doc["current"]["hour"];
          minute = doc["current"]["minute"];
          second = doc["current"]["second"];
          const char* temp = temperature.c_str();
          const char* desc = temperatureDescription.c_str();
          const char* date = current_date.c_str();
          String final_time_str = String(hour) + ":" + String(minute) + ":" + String(second);
          const char* time = final_time_str.c_str();
          lv_label_set_text(dateLabel, date);
          lv_label_set_text(timeLabel, time);
          lv_label_set_text(tempLabel, temp);
          lv_label_set_text(descLabel, desc);
          switch (var) {
            case 1:
                printf("Case 1 is Matched.");
                break;
            case 2:
                printf("Case 2 is Matched.");
                break;
            case 3:
                printf("Case 3 is Matched.");
                break;
            default:
                printf("Default case is Matched.");
                break;
            }
          lv_label_set_text(iconLabel, ICON_CLOUDS);

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
  lv_display_t* disp;
  // Initialize the TFT display using the TFT_eSPI library
  disp = lv_tft_espi_create(SCREEN_WIDTH, SCREEN_HEIGHT, draw_buf, sizeof(draw_buf));
  lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_270);
  // Function to draw the GUI
  lv_create_global_styles();
  lv_create_main_gui();
}





void loop() {
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