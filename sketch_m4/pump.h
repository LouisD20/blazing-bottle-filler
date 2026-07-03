#ifndef PUMP_H
#define PUMP_H

// IO pins used for pump's motor control
const int DIR_PIN = 8;
const int STEP_PIN = 9;
const int RELEASE_PIN = -1;

// directions for motor spinning (clockwise and counterclockwise)
typedef enum {
  CW  = 0,
  CCW = 1,
} SpinDirection;

// # of steps per 1 full revolution, determined by motor construction
const int MOTOR_STEPS = 200;
// step subdivision factor, set by physical switch on driver
const int DRIVER_SUBDIVISIONS = 8;

int init_pump();
void set_pump_dir(SpinDirection);
void revs_over_time(float, int);

#endif