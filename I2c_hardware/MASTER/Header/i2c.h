#ifndef __I2C_H
#define __I2C_H

#include "stm32f10x.h"
#define Address    0x30
#define I2C_Chanel      		I2C2
void I2C_write_byte(char data,char index);
uint8_t I2C_read_byte();
void I2C_config (void);
void I2C_write_string(char *str);
#endif
