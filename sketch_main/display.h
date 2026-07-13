#ifndef DISPLAY_H
#define DISPLAY_H

#include "Arduino_H7_Video.h"
#include "Arduino_GigaDisplayTouch.h"
#include "lvgl.h"

int init_display();
void display_scale_reading(int32_t);
static void btn_event_cb(lv_event_t*);
static void label_observer_cb(lv_observer_t* observer, lv_subject_t* subject);

#endif