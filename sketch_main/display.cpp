#include "Arduino_H7_Video.h"
#include "Arduino_GigaDisplayTouch.h"
#include "lvgl.h"

#include "display.h"

// global variables (readings from external sources)
lv_subject_t scaleReading;

// objects for display visuals and touchscreen
Arduino_H7_Video Display(800, 480, GigaDisplayShield);
Arduino_GigaDisplayTouch TouchDetector;

// initialize display on startup
int init_display() {
  // set initial global var values
  lv_subject_init_int(&scaleReading, 0);
  
  // start connection to display and touchscreen devices
  Display.begin();
  TouchDetector.begin();

  // create screenspace object with dimensions matching physical display
  lv_obj_t* screen = lv_obj_create(lv_scr_act());
  lv_obj_set_size(screen, Display.width(), Display.height());

  // define layout grid
  static lv_coord_t col_dsc[] = {300, 300, LV_GRID_TEMPLATE_LAST};
  static lv_coord_t row_dsc[] = {200, 200, LV_GRID_TEMPLATE_LAST};
  // apply grid to screenspace
  lv_obj_t* grid = lv_obj_create(lv_scr_act());
  lv_obj_set_grid_dsc_array(grid, col_dsc, row_dsc);
  lv_obj_set_size(grid, Display.width(), Display.height());
  lv_obj_center(grid);

  /* objects on grid */

  lv_obj_t* obj;
  lv_obj_t* btn;
  lv_obj_t* label;
  lv_observer_t* observer;

  // button in top left
  obj = lv_obj_create(grid);
  lv_obj_set_grid_cell(obj, LV_GRID_ALIGN_STRETCH, 0, 1, // column
                        LV_GRID_ALIGN_STRETCH, 0, 1); // row
  //lv_obj_set_flex_flow(obj, LV_FLEX_FLOW_COLUMN);

  btn = lv_btn_create(obj);
  lv_obj_set_size(btn, 100, 40);
  lv_obj_center(btn);
  lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_CLICKED, NULL);

  label = lv_label_create(btn);
  lv_label_set_text(label, "Click me!");
  lv_obj_center(label);

  // text in bottom left
  obj = lv_obj_create(grid);
  lv_obj_set_grid_cell(obj, LV_GRID_ALIGN_STRETCH, 0, 1, // column
                        LV_GRID_ALIGN_STRETCH, 0, 1); // row

  label = lv_label_create(obj);
  lv_label_set_text(label, "Scale reading: ");
  lv_obj_center(label);

  // updating text with scale reading in bottom right
  obj = lv_obj_create(grid);
  lv_obj_set_grid_cell(obj, LV_GRID_ALIGN_STRETCH, 0, 1, // column
                        LV_GRID_ALIGN_STRETCH, 0, 1); // row

  label = lv_label_create(obj);
  lv_label_set_text(label, "Scale reading: ");
  lv_obj_center(label);

  observer = lv_subject_add_observer_obj(&scaleReading, label_observer_cb, obj, NULL);

}

// get updated raw scale reading
void display_scale_reading(int32_t rawReading) {
  lv_subject_set_int(&scaleReading, rawReading);
}

// button press handler
static void btn_event_cb(lv_event_t* e) {
  lv_obj_t* btn = (lv_obj_t*)lv_event_get_target(e);
  lv_obj_t* label = lv_obj_get_child(btn, 0);
  lv_label_set_text_fmt(label, "Clicked!");
}

// label update handler
static void label_observer_cb(lv_observer_t* observer, lv_subject_t* subject) {
  // updated input value
  int32_t value = lv_subject_get_int(subject);

  // get label from obj using observer
  lv_obj_t* obj = lv_observer_get_target_obj(observer);
  lv_obj_t* label = lv_obj_get_child(obj, 0);

  // update label to display new value
  lv_label_set_text_fmt(label, "%d", value);
}

