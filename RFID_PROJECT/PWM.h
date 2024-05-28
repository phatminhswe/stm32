#ifndef PWM_h
#define PWM_h

#include "stm32f10x.h"
#define MIN_ANGLE 0    // Minimum valid angle in degrees
#define MAX_ANGLE 180  // Maximum valid angle in degrees
#define MIN_PULSE_WIDTH 500  // Minimum pulse width in microseconds (us)
#define MAX_PULSE_WIDTH 2500
void PWM_Init(void);
void PWM_angle(uint8_t angle);

#endif