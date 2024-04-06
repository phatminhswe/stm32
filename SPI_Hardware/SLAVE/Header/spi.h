#ifndef SPI_H_
#define SPI_H_
#include "stm32f10x.h"
void SPI1_Init();
uint8_t SPI1_ReadByte();
void SPI_ReadString(uint8_t *data);
#endif