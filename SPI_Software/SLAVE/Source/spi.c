#include "spi.h"

void SPI_Config(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	 
	 GPIO_InitStructure.GPIO_Pin = SPI_MOSI_PIN |SPI_SS_PIN | SPI_SCK_PIN;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
   GPIO_Init(SPI_PORT, &GPIO_InitStructure);
	
	 GPIO_InitStructure.GPIO_Pin = SPI_MISO_PIN;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
   GPIO_Init(SPI_PORT, &GPIO_InitStructure);
}

void SPI_clock(){
	GPIO_WriteBit(SPI_PORT,SPI_SCK_PIN,Bit_SET);
	DelayMs(5);
	GPIO_WriteBit(SPI_PORT,SPI_SCK_PIN,Bit_RESET);
	DelayMs(5);
}

void SPI_INIT(){
	GPIO_WriteBit(SPI_PORT,SPI_SS_PIN,Bit_SET);
	GPIO_WriteBit(SPI_PORT,SPI_SCK_PIN,Bit_RESET);
	GPIO_WriteBit(SPI_PORT,SPI_MISO_PIN,Bit_RESET);
	GPIO_WriteBit(SPI_PORT,SPI_MOSI_PIN,Bit_RESET);
}


void SPI_Transmit(uint8_t dataTran){
	uint8_t temp =0x00;
	GPIO_WriteBit(SPI_PORT,SPI_SS_PIN,Bit_RESET);
	DelayMs(1);
	uint8_t i;
	for(i=0;i<8;i++){
		temp = dataTran & 0x80;
		if(temp==1){
			GPIO_WriteBit(SPI_PORT,SPI_MOSI_PIN,Bit_SET);
			DelayUs(1);
		}else{
			GPIO_WriteBit(SPI_PORT,SPI_MOSI_PIN,Bit_RESET);
			DelayUs(1);
		}
		dataTran=dataTran<<1;
		SPI_clock();
	}
	GPIO_WriteBit(SPI_PORT,SPI_SS_PIN,Bit_SET);
	DelayMs(1);
}

uint8_t SPI_Slave_Receive(void){
	uint8_t u8Mask = 0x80;
	uint8_t dataReceive =0x00;
	uint8_t temp = 0x00, i=0;
	while(GPIO_ReadInputDataBit(SPI_PORT, SPI_SS_PIN));
	while(!GPIO_ReadInputDataBit(SPI_PORT, SPI_SCK_PIN));
	for(i=0; i<8;i++){ 
		if(GPIO_ReadInputDataBit(SPI_PORT, SPI_SCK_PIN)){
		while (GPIO_ReadInputDataBit(SPI_PORT, SPI_SCK_PIN)) 
			temp = GPIO_ReadInputDataBit(SPI_PORT, SPI_MOSI_PIN);
		dataReceive=dataReceive<<1;
		dataReceive=dataReceive|temp;
		}
	while(!GPIO_ReadInputDataBit(SPI_PORT, SPI_SCK_PIN));
	}
	return dataReceive;
}