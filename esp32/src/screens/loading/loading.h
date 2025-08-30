#ifndef LOADING_H
#define LOADING_H

#include <lvgl.h>

// External references to global objects
extern lv_obj_t *loading_screen;
extern lv_obj_t *loading_animation;

// Function declarations
void create_loading_screen(void);

#endif // LOADING_H
