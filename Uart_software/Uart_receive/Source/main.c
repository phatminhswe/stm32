#include "stm32f10x.h"
#include "uart.h"
#include "delay.h"
uint8_t data[10];

int main(){
	
	UART_Config();
	UART_BaudRate();
	USART1_ReceiveString(data);
	
}

