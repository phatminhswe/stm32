#ifndef __I2C_SLAVE_H
#define __I2C_SLAVE_H
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_i2c.h"
#include "misc.h"


#define I2CSLAVE_ADDR	0x30 

#define   I2C1_CLOCK_FRQ   100000       

void I2C1_ClearFlag(void);
void I2C1_Slave_init(void);

#endif
