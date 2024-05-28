#ifndef UART_H_
#define UART_H_
#include "stm32f10x.h"
#include "delay.h"
#define BAUDRATE 9600

void UART_init(void);
void UART_SendChar(uint8_t data);
void USART_SendString(uint8_t *str);
char UART_ReceiveChar(void);
void USART_ReceiveString(uint8_t * str);

#endif