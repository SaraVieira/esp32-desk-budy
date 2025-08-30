#ifndef CLOCK_H
#define CLOCK_H

#include <lvgl.h>
#include "../../types.h"

// External references to global objects
extern lv_obj_t *clock_screen;
extern TimeDisplay time_display;

// Function declarations
void create_screen_clock(void);

#endif // CLOCK_H
