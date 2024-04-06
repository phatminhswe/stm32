#ifndef SPI_H_
#define SPI_H_
#include "stm32f10x.h"
#include "delay.h"

#define SPI_SS_PIN GPIO_Pin_4
#define SPI_SCK_PIN GPIO_Pin_5
#define SPI_MISO_PIN GPIO_Pin_6
#define SPI_MOSI_PIN GPIO_Pin_7
#define SPI_PORT GPIOA

void SPI_Config();
void SPI_clock();
void SPI_INIT();
void SPI_Transmit(uint8_t dataTran);
uint8_t SPI_Slave_Receive();
#endif