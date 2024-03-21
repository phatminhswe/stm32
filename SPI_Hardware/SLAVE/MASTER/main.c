#include "stm32f10x.h"

SPI_InitTypeDef SPI_InitStructure;

void SPI1_Init(void) {
    GPIO_InitTypeDef GPIO_InitStructure;

    // Enable SPI1 and GPIOA clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1 | RCC_APB2Periph_GPIOA, ENABLE);

    // Configure SPI1 pins: SCK,MOSI
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
		
    // SPI1 configuration
    SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
    SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
    SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
    SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
    SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
    SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
    SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256; // Adjust according to your requirements
    SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
    SPI_InitStructure.SPI_CRCPolynomial = 7; // CRC polynomial value, not used in master mode
    SPI_Init(SPI1, &SPI_InitStructure);

    // Enable SPI1
    SPI_Cmd(SPI1, ENABLE);
}

uint8_t SPI1_SendByte(uint8_t byte) {
    // Wait for SPI1 Tx buffer empty
    while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);

    // Send byte through the SPI1 peripheral
    SPI_I2S_SendData(SPI1, byte);

    // Wait to receive a byte
    while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);

    // Return the byte read from the SPI bus
    return SPI_I2S_ReceiveData(SPI1);
}

int main(void) {
    // Initialize SPI1
    SPI1_Init();

    while (1) {
        // Example usage: sending and receiving data
        uint8_t tx_data = 0xAA;
        uint8_t rx_data;

        rx_data = SPI1_SendByte(tx_data);
        // Do something with received data

        // Add delay as necessary
        // Delay function
    }
}
