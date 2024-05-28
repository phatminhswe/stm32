#include "millis.h"
#include "delay.h"
int main(){
			uint16_t time = millis(); time = 120;
			GPIO_ResetBits(GPIOA,GPIO_Pin_0); 
			// hàm j dó   
			while((millis() - 120) < 1000);
			//Delay_Ms(1000);
			GPIO_SetBits(GPIOA,GPIO_Pin_0);
			Delay_Ms(1000);
}

44:00

45:56

