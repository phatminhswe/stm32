#ifndef __DIGITAL_H
#define __DIGITAL_H
#include <stdint.h>
#include "stm32f10x.h"
#define byte uint8_t

typedef enum : byte{
	PA0,
	PA1,
	PA2,
	PA3,
	PA4,
	PA5,
	PA6,
	PA7,
	PA8,
	PA9,
	PA10,
	PA11,
	PA12,
	PA13,
	PA14,
	PA15,
	PB0,
	PB1,
	PB2,
	PB3,
	PB4,
	PB5,
	PB6,
	PB7,
	PB8,
	PB9,
	PB10,
	PB11,
	PB12,
	PB13,
	PB14,
	PB15,
	PC13,
	PC14,
	PC15
}IO_port;

typedef enum{
	LOW,
	HIGH
}IO_state;

typedef enum{
	OUTPUT,
	INPUT
}I0_mode;

#define CHANNEL(PORT,PIN)   \
case P##PORT##PIN:    			\
gpioport = GPIO##PORT;      \
gpiopin =	GPIO_Pin_##PIN;		\
break;
	
void digitalWrite(byte _chipSelectPin, IO_state state);	

void pinMode(byte pin, I0_mode mode);

IO_state digitalRead(byte pin);
#endif


