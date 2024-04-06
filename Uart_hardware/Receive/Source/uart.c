#include "uart.h"
void UART_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = BAUDRATE;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; 
    USART_Init(USART1, &USART_InitStructure);

    USART_Cmd(USART1, ENABLE);
}

void UART_SendChar(char c)
{
		while(!USART_GetFlagStatus(USART1, USART_FLAG_TXE))
			;
    USART_SendData(USART1, c);
}

char UART_ReceiveChar(void)
{
    while(!USART_GetFlagStatus(USART1, USART_FLAG_RXNE));
    return (char)USART_ReceiveData(USART1);
}

void USART_SendString( uint8_t *str) {
    while (*str) {
        UART_SendChar(*str++);
				Delay_Ms(1000);
    }
		UART_SendChar('\0');
}

void USART_ReceiveString(uint8_t * str){
	while(1){
		*str = UART_ReceiveChar();
		if(*str == '\0') break;
		str++;
	}
}