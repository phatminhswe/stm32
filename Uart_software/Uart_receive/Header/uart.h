#ifndef UART_H_
#define UART_H_
#include "stm32f10x.h"
#include "delay.h"
#define TX_Pin GPIO_Pin_9
#define RX_Pin GPIO_Pin_10
#define UART_GPIO GPIOA

void UART_Config();
void UART_BaudRate(void);
void delay(uint16_t divide);
void UART_init();
void UART_Transmit(const char DataValue);
unsigned char UART_Receive(void);
void USART_SendString( uint8_t *str);
void USART1_ReceiveString(uint8_t * str);
#endif