#ifndef SPI_H_
#define SPI_H_
#include "stm32f10x.h"
#include "delay.h"
void SPI1_Init();
void SPI1_SendByte(uint8_t byte);
uint8_t SPI1_SendString(uint8_t *data);
#endif