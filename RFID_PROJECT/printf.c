#include "printf.h"
#include "uart.h"
#include "stdio.h"
void print(uint8_t * string,Ascci ascci){
    
		
		uint8_t temp;
		if(ascci == DEC){
			uint8_t temp_string =*string;
			for(uint8_t i=100;i!=0;i=i/10){
						temp = ((temp_string)/i)+48;
						temp_string = (temp_string) % i;
				    UART_SendChar(temp);
			}
		}
		else if(ascci == HEX){
						temp = (*string) & 0xf0;
						temp = temp >> 4;
						if (temp < 10) temp = temp + 48;
						else temp = temp +55;
						UART_SendChar(temp);
						temp = (*string);
						temp = (*string) & 0x0f;
						if (temp < 10) temp = temp + 48;
						else temp = temp +55;
						UART_SendChar(temp);	
		}
		else{
			USART_SendString((uint8_t *)string);
		} 
}

void println(uint8_t * string,Ascci ascci){
    
		
		uint8_t temp;
		if(ascci == DEC){
			for(uint8_t i=100;i!=0;i=i/10){
						temp = ((*string)/i)+48;
						*string = (*string) % i;
				    UART_SendChar(temp);
			}
		}
		else if(ascci == HEX){
						temp = (*string) & 0xf0;
						temp = temp >> 4;
						if (temp < 10) temp = temp + 48;
						else temp = temp +55;
						UART_SendChar(temp);
						temp = (*string);
						temp = (*string) & 0x0f;
						if (temp < 10) temp = temp + 48;
						else temp = temp +55;
						UART_SendChar(temp);	
		}
		else{
			USART_SendString((uint8_t *)string);
		} 
		UART_SendChar('\n');
}