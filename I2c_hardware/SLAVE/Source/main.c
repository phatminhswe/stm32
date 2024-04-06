#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_adc.h"
#include "stm32f10x_dma.h"
#include "stm32f10x_i2c.h"
#include "misc.h"

#include "i2c_slave.h"

int main(void){	
	I2C1_Slave_init();
	while(1){
	
	
	}
	
}
