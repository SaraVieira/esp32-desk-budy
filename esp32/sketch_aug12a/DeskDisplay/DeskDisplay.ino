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

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

#define DRAW_BUF_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT / 10 * (LV_COLOR_DEPTH / 8))
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

String format_time(int time) {
  return (time < 10) ? "0" + String(time) : String(time);
}

void lv_create_global_styles() {

  lv_style_init(&flexStyle);
  lv_style_init(&flexRowStyle);

  // time row
  time_and_date_row = lv_obj_create(lv_screen_active());
  lv_obj_set_size(time_and_date_row, lv_pct(100), 75);
  lv_obj_align(time_and_date_row, LV_ALIGN_TOP_MID, 0, 5);
  lv_obj_set_flex_flow(time_and_date_row, LV_FLEX_FLOW_ROW);
  lv_style_set_flex_main_place(&flexRowStyle, LV_FLEX_ALIGN_SPACE_BETWEEN);


  // weather col
  weather_col = lv_obj_create(lv_screen_active());
  lv_obj_set_size(weather_col, lv_pct(100), 160);
  lv_obj_align_to(weather_col, time_and_date_row, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
  lv_obj_set_flex_flow(weather_col, LV_FLEX_FLOW_COLUMN);


  // styles for both
  lv_obj_set_style_bg_color(weather_col, lv_color_hex(0x000000), LV_PART_MAIN);
  lv_obj_set_style_bg_color(time_and_date_row, lv_color_hex(0x000000), LV_PART_MAIN);
  lv_style_set_border_width(&flexStyle, 0);
   lv_style_set_border_width(&flexRowStyle, 0);
  lv_obj_add_style(weather_col, &flexStyle, 0);
  lv_obj_add_style(time_and_date_row, &flexRowStyle, 0);

  // global styles
  lv_obj_set_style_bg_color(lv_screen_active(), lv_color_hex(0x000000), LV_PART_MAIN);
}

void lv_create_main_gui(void) {
  static lv_style_t labelsStyle;
  lv_style_init(&labelsStyle);
  lv_style_set_text_font(&labelsStyle, &lv_font_montserrat_30);
  static lv_style_t labelsStyleSmall;
  lv_style_init(&labelsStyleSmall);
  lv_style_set_text_font(&labelsStyleSmall, &lv_font_montserrat_14);
  const char* temp = temperature.c_str();
  const char* desc = temperatureDescription.c_str();
  const char* date = current_date.c_str();
  String final_time_str = String(hour) + ":" + String(minute) + ":"  + String(second);
  const char* time = final_time_str.c_str();
  

  // date label
  lv_obj_t* dateLabel = lv_label_create(time_and_date_row);
  lv_label_set_text(dateLabel, date);
  lv_obj_set_style_text_color(time_and_date_row, lv_color_hex(0xffffff), LV_PART_MAIN);
  lv_obj_add_style(dateLabel, &labelsStyleSmall, 0);
  lv_obj_center(dateLabel);

  // time
  lv_obj_t* timeLabel = lv_label_create(time_and_date_row);
  lv_label_set_text(timeLabel, time);
  lv_obj_set_style_text_color(time_and_date_row, lv_color_hex(0xffffff), LV_PART_MAIN);
  lv_obj_add_style(timeLabel, &labelsStyleSmall, 0);
  lv_obj_center(timeLabel);


  // temperature label
  lv_obj_t* tempLabel = lv_label_create(weather_col);
  lv_label_set_text(tempLabel, temp);
  lv_obj_set_style_text_color(weather_col, lv_color_hex(0xffffff), LV_PART_MAIN);
  lv_obj_add_style(tempLabel, &labelsStyle, 0);
  lv_obj_center(tempLabel);


  // weather description
  lv_obj_t* descLabel = lv_label_create(weather_col);
  lv_label_set_text(descLabel, desc);
  lv_obj_set_style_text_color(weather_col, lv_color_hex(0xffffff), LV_PART_MAIN);
  lv_obj_add_style(tempLabel, &labelsStyle, 0);
  lv_obj_center(descLabel);
}

void get_weather() {
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
  get_weather();
  // Function to draw the GUI
  lv_create_global_styles();
  lv_create_main_gui();
}





void loop() {
  unsigned long msec = millis();
  if (msec >= fetchTime) {
    fetchTime += 15 * 60 * 1000L;  // 15 minutes
    get_weather();
    Serial.println("Getting weather");
  }
  lv_task_handler();  // let the GUI do its work
  lv_tick_inc(5);     // tell LVGL how much time has passed
  delay(5);           // let this time pass
}