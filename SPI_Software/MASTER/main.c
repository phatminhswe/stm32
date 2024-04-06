#include "stm32f10x.h"
#include "delay.h"
#include "spi.h"
int main(void) {
	SPI_Config();
	SPI_INIT();
	DelayInit();
	char a[] ={'p','h','a','t'};
	uint8_t i=0;
  while(1){
		for(i=0; i< 4;i++){
		SPI_Transmit(a[i]);
		
		}
	}
}

