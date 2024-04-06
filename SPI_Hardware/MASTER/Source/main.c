#include "stm32f10x.h"
#include "delay.h"


int main(void) {
	
	DelayInit();
  SPI1_Init();
		uint8_t *tx_data = (uint8_t*)"minh phat";
    uint8_t rx_data;
		DelayMs(6000);
    while (1) {
     SPI1_SendString(tx_data);
			
			SPI1_SendString((uint8_t*)"spi connect");
    }
}

