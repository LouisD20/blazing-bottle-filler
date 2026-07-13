#include <Arduino.h>
#include "RPC.h"

//#include "pins_map.h"
#include "pump.h"

// initialize pump on startup
int init_pump() {
  pinMode(DIR_PIN, OUTPUT); 
  pinMode(STEP_PIN, OUTPUT);
  pinMode(RELEASE_PIN, OUTPUT);
  return 0; // init successful
}

// set pump's motor spin direction
void set_pump_dir(int spinDir) {
  digitalWrite(DIR_PIN, spinDir);
}

// complete REVS motor revolutions over MICROSECS microseconds
void revs_over_time(float revs, int microsecs) {
  int stepsPerRev = MOTOR_STEPS * DRIVER_SUBDIVISIONS;
  int stepsNeeded = int(revs * stepsPerRev);
  int delayPerStep = microsecs / stepsNeeded;

  for(int i=0; i < stepsNeeded; i++) {
    digitalWrite(STEP_PIN, HIGH); 
    delayMicroseconds(delayPerStep / 2);
    digitalWrite(STEP_PIN, LOW); 
    delayMicroseconds(delayPerStep / 2); 
  }
}