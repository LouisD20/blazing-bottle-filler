#include "RPC.h"

#include "pump.h"

void setup() {
  // put your setup code here, to run once:

  // connect to M7 main processor
  RPC.begin();

  // pump startup
  init_pump();

  // Bind the revs_over_time function to be called by M7
  RPC.bind("set_pump_dir", set_pump_dir);
  RPC.bind("revs_over_time", revs_over_time);

}

void loop() {
  // put your main code here, to run repeatedly:

}
