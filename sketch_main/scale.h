#ifndef SCALE_H
#define SCALE_H

/* Expected average weights of EMPTY bottles */
const float S_EMPTY = 101.0 // small 100mL bottle
const float M_EMPTY = 237.0 // medium 250mL bottle
const float L_EMPTY = 361.0 // large 500mL bottle
const float LN_EMPTY = 389.0 // longneck 500mL bottle (will be deprecated)

/* Expected average weights of FULL BALSAMIC bottles */
const float S_BALSAMIC = 228.0 // small 100mL bottle
const float M_BALSAMIC = 556.0 // medium 250mL bottle
const float L_BALSAMIC = 997.5 // large 500mL bottle
const float LN_BALSAMIC = 1009.5 // longneck 500mL bottle (will be deprecated)

/* Expected average weights of FULL OIL bottles */
const float S_OIL = 191.0 // small 100mL bottle
const float M_OIL = 468.0 // medium 250mL bottle
const float L_OIL = 820.0 // large 500mL bottle
// longneck bottles are not used for oil


/* Weighing and size detection functions */

#endif