#include "spi.h"

uint8_t SPI_transfer(uint8_t data,SPI_TypeDef* SPIx)
{
	
	SPI_I2S_SendData(SPIx, data);
	while (SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_BSY) == SET) {
	}
	return SPI_I2S_ReceiveData(SPIx);
}

void SPI_init(SPI_channel SPIx)
{
	
	GPIO_InitTypeDef gpioInit;
	SPI_InitTypeDef   SPI_InitStructure;
	
	if(SPIx== SPI_CHANNEL_SP1){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	gpioInit.GPIO_Mode=GPIO_Mode_AF_PP;
	gpioInit.GPIO_Speed=GPIO_Speed_50MHz;
	gpioInit.GPIO_Pin=GPIO_Pin_5 | GPIO_Pin_7;
	GPIO_Init(GPIOA, &gpioInit);
	
	gpioInit.GPIO_Mode=GPIO_Mode_Out_PP;
	gpioInit.GPIO_Speed=GPIO_Speed_50MHz;
	gpioInit.GPIO_Pin=GPIO_Pin_4;
	GPIO_Init(GPIOA, &gpioInit);
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
	
	gpioInit.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	gpioInit.GPIO_Speed=GPIO_Speed_50MHz;
	gpioInit.GPIO_Pin=GPIO_Pin_6;
	GPIO_Init(GPIOA, &gpioInit);
	
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16;
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_CRCPolynomial = 7;
	SPI_Init(SPI1, &SPI_InitStructure);
	
  SPI_Cmd(SPI1, ENABLE);
	}else if(SPIx== SPI_CHANNEL_SP2){
		RCC_APB1PeriphClockCmd (RCC_APB1Periph_SPI2, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
		gpioInit.GPIO_Mode=GPIO_Mode_AF_PP;
		gpioInit.GPIO_Speed=GPIO_Speed_50MHz;
		gpioInit.GPIO_Pin=GPIO_Pin_13 | GPIO_Pin_15;
		GPIO_Init(GPIOB, &gpioInit);
	
		gpioInit.GPIO_Mode=GPIO_Mode_Out_PP;
		gpioInit.GPIO_Speed=GPIO_Speed_50MHz;
		gpioInit.GPIO_Pin=GPIO_Pin_12;
		GPIO_Init(GPIOB, &gpioInit);
		GPIO_SetBits(GPIOB, GPIO_Pin_12);
	
		gpioInit.GPIO_Mode=GPIO_Mode_IN_FLOATING;
		gpioInit.GPIO_Speed=GPIO_Speed_50MHz;
		gpioInit.GPIO_Pin=GPIO_Pin_14;
		GPIO_Init(GPIOB, &gpioInit);
	
		SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
		SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
		SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
		SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
		SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
		SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
		SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16;
		SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
		SPI_InitStructure.SPI_CRCPolynomial = 7;
		SPI_Init(SPI2, &SPI_InitStructure);
	
		SPI_Cmd(SPI2, ENABLE);
	}
	
}