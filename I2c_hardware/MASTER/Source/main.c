#include "stm32f10x.h"
#include "delay.h"
#include "i2c.h" 
uint8_t data[10];
int main(void)

{
	Delay_Init();
	I2C_config();
	Delay_Us(10);
	
	data[0] = I2C_read_byte();
	data[1] = I2C_read_byte();
	data[2] = I2C_read_byte();
	data[3] = I2C_read_byte();
	
  while (1){}
		
	return 0;
}

