#include "stm32f10x.h"
#include "spi.h"

uint8_t rx_data[16];

int main(void) {
    SPI1_Init();
    while (1) {
        SPI_ReadString(rx_data);
    }
}
