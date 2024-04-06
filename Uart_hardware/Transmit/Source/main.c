#include "stm32f10x.h"
#include "delay.h"
#include "uart.h"

int main(void)
{
    char received_char;
    Delay_Init();
    UART_init();
	  Delay_Ms(6000);
    while (1)
    {
        USART_SendString( (uint8_t *)"minh phat");
    }
}

