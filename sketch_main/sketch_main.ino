#include "RPC.h"

//#include "pins_map.h"
#include "scale.h"
#include "display.h"

// thread for sending pump control requests to M4
Thread pumpThread;

void setup() {
  // put your setup code here, to run once:

  // connect to M4 co-processor
  RPC.begin();

  // slight delay for all connected devices to power on
  delay(3000);

  // set initial states for connected devices
  init_scale();
  //init_pump();
  init_display();
}

void loop() {
  // put your main code here, to run repeatedly:

  // update display visuals
  lv_timer_handler();
  
  // MUST CHANGE this due to not allowing any other actions while motor is running
  RPC.call("set_pump_dir", 0);
  RPC.call("revs_over_time", 10, 2000000);
}
