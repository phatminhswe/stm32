#include "stm32f10x.h"
#include "uart.h"
#include "delay.h"
uint8_t data;


int main(){
	
	UART_Config();
	Delay_Init();
	UART_BaudRate();
	UART_init();
	Delay_Ms(5000);
	USART_SendString((uint8_t*)"Minh Phat");
}

