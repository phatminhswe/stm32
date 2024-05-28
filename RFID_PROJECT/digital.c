#include "digital.h"
GPIO_InitTypeDef GPIO_InitStructure;

void digitalWrite(byte _chipSelectPin, IO_state state){
	uint16_t gpiopin;
	GPIO_TypeDef *gpioport;
	switch((int)_chipSelectPin){
		CHANNEL(A,0);
		CHANNEL(A,1);
		CHANNEL(A,2);
		CHANNEL(A,3);
		CHANNEL(A,4);
		CHANNEL(A,5);
		CHANNEL(A,6);
		CHANNEL(A,7);
		CHANNEL(A,8);
		CHANNEL(A,9);
		CHANNEL(A,10);
		CHANNEL(A,11);
		CHANNEL(A,12);
		CHANNEL(A,13);
		CHANNEL(A,14);
		CHANNEL(A,15);
		CHANNEL(B,0);
		CHANNEL(B,1);
		CHANNEL(B,2);
		CHANNEL(B,3);
		CHANNEL(B,4);
		CHANNEL(B,5);
		CHANNEL(B,6);
		CHANNEL(B,7);
		CHANNEL(B,8);
		CHANNEL(B,9);
		CHANNEL(B,10);
		CHANNEL(B,11);
		CHANNEL(B,12);
		CHANNEL(B,13);
		CHANNEL(B,14);
		CHANNEL(B,15);
		CHANNEL(C,13);
		CHANNEL(C,14);
		CHANNEL(C,15);
	}
	
	if(state==LOW){
		GPIO_ResetBits(gpioport,gpiopin);
	}
	else{
		GPIO_SetBits(gpioport,gpiopin);
	}
}
void pinMode(byte pin, I0_mode mode){
	uint16_t gpiopin;
	GPIO_TypeDef *gpioport;
	switch((int)pin){
		CHANNEL(A,0);
		CHANNEL(A,1);
		CHANNEL(A,2);
		CHANNEL(A,3);
		CHANNEL(A,4);
		CHANNEL(A,5);
		CHANNEL(A,6);
		CHANNEL(A,7);
		CHANNEL(A,8);
		CHANNEL(A,9);
		CHANNEL(A,10);
		CHANNEL(A,11);
		CHANNEL(A,12);
		CHANNEL(A,13);
		CHANNEL(A,14);
		CHANNEL(A,15);
		CHANNEL(B,0);
		CHANNEL(B,1);
		CHANNEL(B,2);
		CHANNEL(B,3);
		CHANNEL(B,4);
		CHANNEL(B,5);
		CHANNEL(B,6);
		CHANNEL(B,7);
		CHANNEL(B,8);
		CHANNEL(B,9);
		CHANNEL(B,10);
		CHANNEL(B,11);
		CHANNEL(B,12);
		CHANNEL(B,13);
		CHANNEL(B,14);
		CHANNEL(B,15);
		CHANNEL(C,13);
		CHANNEL(C,14);
		CHANNEL(C,15);
	}
	if(mode == OUTPUT){
		GPIO_InitStructure.GPIO_Mode= GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Pin = gpiopin;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(gpioport, &GPIO_InitStructure);
	}
	if(mode == INPUT){
		GPIO_InitStructure.GPIO_Mode= GPIO_Mode_IN_FLOATING;
		GPIO_InitStructure.GPIO_Pin = gpiopin;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
		GPIO_Init(gpioport, &GPIO_InitStructure);
	}
}

IO_state digitalRead(byte pin){
	uint16_t gpiopin;
	GPIO_TypeDef *gpioport;
	switch(pin){
		CHANNEL(A,0);
		CHANNEL(A,1);
		CHANNEL(A,2);
		CHANNEL(A,3);
		CHANNEL(A,4);
		CHANNEL(A,5);
		CHANNEL(A,6);
		CHANNEL(A,7);
		CHANNEL(A,8);
		CHANNEL(A,9);
		CHANNEL(A,10);
		CHANNEL(A,11);
		CHANNEL(A,12);
		CHANNEL(A,13);
		CHANNEL(A,14);
		CHANNEL(A,15);
		CHANNEL(B,0);
		CHANNEL(B,1);
		CHANNEL(B,2);
		CHANNEL(B,3);
		CHANNEL(B,4);
		CHANNEL(B,5);
		CHANNEL(B,6);
		CHANNEL(B,7);
		CHANNEL(B,8);
		CHANNEL(B,9);
		CHANNEL(B,10);
		CHANNEL(B,11);
		CHANNEL(B,12);
		CHANNEL(B,13);
		CHANNEL(B,14);
		CHANNEL(B,15);
		CHANNEL(C,13);
		CHANNEL(C,14);
		CHANNEL(C,15);
	}
	if(GPIO_ReadInputDataBit(gpioport,gpiopin)==Bit_SET){
		return HIGH;
	}else{
		return LOW;
	}
}