#include "uart.h"

void UART_Config(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  GPIO_InitTypeDef GPIOInitStruct;
	GPIOInitStruct.GPIO_Pin = GPIO_Pin_10;
	GPIOInitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIOInitStruct);
	//
	GPIOInitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIOInitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIOInitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIOInitStruct);
}

void UART_BaudRate(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    TIM_TimeBaseStructure.TIM_Period = 1000 -1;  
    TIM_TimeBaseStructure.TIM_Prescaler = 75-1;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
    
    TIM_Cmd(TIM2, ENABLE);
}
void delay(uint16_t divide)
{
    TIM_SetCounter(TIM2, 0); 
    while (TIM_GetCounter(TIM2) < (uint16_t)(999/divide)){
		}
}

void UART_init(){
	GPIO_SetBits(UART_GPIO, TX_Pin);
	delay(1);
}
void UART_Transmit(const char DataValue)
{
	GPIO_WriteBit(UART_GPIO, TX_Pin, Bit_RESET);
	delay(1);
	for ( unsigned char i = 0; i < 8; i++ ){
		if( ((DataValue>>i)&0x1) == 0x1 ){
			GPIO_WriteBit(UART_GPIO, TX_Pin, Bit_SET);
		} else{
			GPIO_WriteBit(UART_GPIO, TX_Pin, Bit_RESET);
		}
	delay(1);
	}
	GPIO_WriteBit(UART_GPIO, TX_Pin, Bit_SET);
	delay(1);
}

unsigned char UART_Receive(void){
	unsigned char DataValue = 0;
	while(GPIO_ReadInputDataBit(UART_GPIO, RX_Pin) == 1);
	delay(1);
	delay(2);
	for ( unsigned char i = 0; i < 8; i++ ){
		if ( GPIO_ReadInputDataBit(UART_GPIO, RX_Pin) == 1 ){
			DataValue += (1<<i);}
		delay(1);
		}
		if ( GPIO_ReadInputDataBit(UART_GPIO, RX_Pin) == 1 ){
		delay(2);
			return DataValue;
		} 
		return 0;
}
void USART_SendString( uint8_t *str) {
    while (*str) {
        UART_Transmit(*str++);
				Delay_Ms(1000);
    }
		UART_Transmit('\0');
}
void USART1_ReceiveString(uint8_t * str){
	while(1){
		*str = UART_Receive();
		if(*str == '\0') break;
		str++;
	}
}