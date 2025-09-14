
#include <lvgl.h>
#include <TFT_eSPI.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <SpotifyArduino.h>

#include "types.h"
#include "secrets.h"
#include "../../styles/styles.h"
#include "../../images/images.h"

// so we can store the song name and artist name
char *songName;
char *songArtist;

extern lv_obj_t *spotify_screen;
static lv_obj_t *container;
static lv_obj_t *img;
extern SpotifyArduino spotify;
static lv_obj_t *track_name;
static lv_obj_t *artist_label;
static lv_obj_t *progress_bar;
static lv_obj_t *play_img;
static lv_obj_t *pause_img;
static lv_obj_t *next_img;
static lv_obj_t *prev_img;

void create_spotify_screen()
{
    // init style
    static lv_style_t no_border_style;
    lv_style_init(&no_border_style);
    lv_style_set_border_width(&no_border_style, 0);
    lv_style_set_radius(&no_border_style, 0);
    lv_style_set_text_font(&no_border_style, &teletext_24);

    // container
    spotify_screen = lv_obj_create(NULL);

    container = lv_obj_create(spotify_screen);
    lv_obj_set_size(container, lv_pct(100), lv_pct(100));
    lv_obj_align(container, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_flex_flow(container, LV_FLEX_FLOW_COLUMN);
    align_center_x_y(container);
    clear_paddings(container);
    lv_obj_add_style(container, &no_border_style, 0);
    lv_obj_set_style_bg_color(container, black, LV_PART_MAIN);

    track_name = lv_label_create(container);
    lv_obj_set_style_text_color(track_name, white, LV_PART_MAIN);

    lv_obj_set_style_text_font(track_name, &teletext_14, LV_PART_MAIN);
    static lv_style_t style_bg;
    static lv_style_t style_indic;

    lv_style_init(&style_bg);
    lv_style_set_border_color(&style_bg, blue);
    lv_style_set_border_width(&style_bg, 2);
    lv_style_set_pad_all(&style_bg, 8); /*To make the indicator smaller*/
    lv_style_set_anim_duration(&style_bg, 1000);

    lv_style_init(&style_indic);
    lv_style_set_bg_opa(&style_indic, LV_OPA_COVER);
    lv_style_set_bg_color(&style_indic, white);

    progress_bar = lv_bar_create(container);
    lv_obj_remove_style_all(progress_bar);
    lv_obj_add_style(progress_bar, &style_bg, 0);
    lv_obj_add_style(progress_bar, &style_indic, LV_PART_INDICATOR);

    lv_obj_set_size(progress_bar, 300, 20);
    lv_obj_center(progress_bar);

    artist_label = lv_label_create(container);
    lv_obj_set_style_text_color(artist_label, white, LV_PART_MAIN);
    lv_obj_set_style_text_font(artist_label, &teletext_14, LV_PART_MAIN);

    lv_obj_t *controls = lv_obj_create(container);
    lv_obj_set_style_bg_color(controls, black, LV_PART_MAIN);
    lv_obj_set_flex_flow(controls, LV_FLEX_FLOW_ROW);
    align_center_x_y(controls);
    clear_paddings(controls);
    lv_obj_set_size(controls, lv_pct(100), 50);
    lv_obj_add_style(controls, &no_border_style, 0);

    prev_img = lv_image_create(controls);
    lv_obj_add_flag(prev_img, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(prev_img, &prev);
    lv_obj_set_size(prev_img, 32, 32);
    lv_obj_center(prev_img);

    play_img = lv_image_create(controls);
    lv_image_set_src(play_img, &play);
    lv_obj_add_flag(play_img, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_size(play_img, 32, 32);
    lv_obj_center(play_img);
    lv_obj_add_flag(play_img, LV_OBJ_FLAG_HIDDEN);

    pause_img = lv_image_create(controls);
    lv_image_set_src(pause_img, &pause_icon);
    lv_obj_add_flag(pause_img, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_size(pause_img, 32, 32);
    lv_obj_center(pause_img);
    lv_obj_add_flag(pause_img, LV_OBJ_FLAG_HIDDEN);

    next_img = lv_image_create(controls);
    lv_obj_add_flag(next_img, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(next_img, &next);
    lv_obj_set_size(next_img, 32, 32);
    lv_obj_center(next_img);
}

void handle_hidden_toggles(boolean isPlaying = true)
{
    if (lv_obj_has_flag(next_img, LV_OBJ_FLAG_HIDDEN))
        lv_obj_clear_flag(next_img, LV_OBJ_FLAG_HIDDEN);
    if (lv_obj_has_flag(prev_img, LV_OBJ_FLAG_HIDDEN))
        lv_obj_clear_flag(prev_img, LV_OBJ_FLAG_HIDDEN);

    if (lv_obj_has_flag(artist_label, LV_OBJ_FLAG_HIDDEN))
    {
        lv_obj_clear_flag(artist_label, LV_OBJ_FLAG_HIDDEN);
    }
    if (lv_obj_has_flag(progress_bar, LV_OBJ_FLAG_HIDDEN))
    {
        lv_obj_clear_flag(progress_bar, LV_OBJ_FLAG_HIDDEN);
    }

    if (isPlaying)
    {
        lv_obj_clear_flag(pause_img, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(play_img, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_clear_flag(play_img, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(pause_img, LV_OBJ_FLAG_HIDDEN);
    }
}

void show_empty_spotify_screen()
{
    lv_obj_add_flag(artist_label, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(progress_bar, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(next_img, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(prev_img, LV_OBJ_FLAG_HIDDEN);
    lv_label_set_text(track_name, "Nothing's playing");
    lv_obj_set_style_text_font(track_name, &teletext_22, LV_PART_MAIN);
}

void show_currently_playing(CurrentlyPlaying currentlyPlaying)
{
    handle_hidden_toggles(currentlyPlaying.isPlaying);

    lv_label_set_text(track_name, currentlyPlaying.trackName);
    for (int i = 0; i < currentlyPlaying.numArtists; i++)
    {

        lv_label_set_text(artist_label, currentlyPlaying.artists[i].artistName);
    }

    float percentage = ((float)currentlyPlaying.progressMs / (float)currentlyPlaying.durationMs) * 100;
    lv_bar_set_value(progress_bar, percentage, LV_ANIM_OFF);
}

void toggle_playback(PlayerDetails details)
{
    Serial.println("Toggling playback");
    if (details.isPlaying)
    {
        spotify.pause(details.device.id);
    }
    else
    {
        spotify.play(details.device.id);
    }
    // spotify.getCurrentlyPlaying(show_currently_playing);
}

void on_rotary_clicked()
{

    spotify.getPlayerDetails(toggle_playback);
}