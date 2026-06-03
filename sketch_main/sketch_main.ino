#include "pins_map.h"
#include "scale.h"
#include "pump.h"
#include "display.h"

void setup() {
  // put your setup code here, to run once:

  // slight delay for all connected devices to power on
  delay(3000);

  // set initial states for connected devices
  //init_scale();
  init_pump();
  //init_display();
}

void loop() {
  // put your main code here, to run repeatedly:

  // update display visuals
  //lv_timer_handler();

  set_pump_dir(CW);
  revs_over_time(10, 2000000);
  delay(1000);
  set_pump_dir(CCW);
  revs_over_time(10, 2000000);
  delay(1000);
}
