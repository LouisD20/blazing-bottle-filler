#include <Wire.h>
#include "SparkFun_Qwiic_Scale_NAU7802_Arduino_Library.h"

//#include "pins_map.h"
#include "scale.h"

NAU7802 myScale; // scale object

// initialize scale on startup
int init_scale() {
  // initialize I2C (for scale readings)
  // uses pins 20 & 21
  Wire.begin();

  if (myScale.begin() == false)
  {
    return 1; // init failed
  }

  return 0; // init succeeded
}

// get raw scale reading
int32_t raw_reading() {
  if(myScale.available() == true)
    {
      // get raw scale input
      return myScale.getReading();
    }
}

// get current weight reading in grams
float weight() {
  if(myScale.available() == true)
    {
      // get raw scale input
      int32_t rawReading = myScale.getReading();

      // convert to measurement in grams

    }
}