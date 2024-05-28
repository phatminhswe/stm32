#include "stm32f10x.h"


#ifndef KT_SPI_H_
#define KT_SPI_H_
typedef enum{
	SPI_CHANNEL_SP1,
	SPI_CHANNEL_SP2,
	
}SPI_channel;
void SPI_init(SPI_channel SPIx);

uint8_t SPI_transfer(uint8_t data, SPI_TypeDef* SPIx);

#endif

