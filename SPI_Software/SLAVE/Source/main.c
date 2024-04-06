#include "stm32f10x.h"
#include "delay.h"
#include "spi.h"

uint8_t data[4];

int main(void) {
	SPI_Config();
	//SPI_INIT();
	DelayInit();
	uint8_t i=0;
  while(1){
		for(i=0;i<4;i++){
		data[i]=SPI_Slave_Receive();
		}
	}
}

