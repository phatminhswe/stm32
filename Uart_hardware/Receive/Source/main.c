#include "stm32f10x.h"
#include "delay.h"
#include "uart.h"

uint8_t stringReceive[16];
int main(void)
{
    char received_char;
    Delay_Init();
    UART_init();
    while (1)
    {
        USART_ReceiveString(stringReceive);
    }
}

