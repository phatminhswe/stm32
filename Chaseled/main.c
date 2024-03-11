#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x.h"

void RRC_Config();
 
void GPIO_config();

void chaseled(uint8_t loop);

int main(){
RRC_Config();
GPIO_config();

while(1){		
chaseled(3);	
	

}
return 0;
}
 void RRC_Config(){
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
}
void GPIO_config(){
GPIO_InitTypeDef GPIO_InitStructure;
	
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2| GPIO_Pin_3| GPIO_Pin_4 | GPIO_Pin_0;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(GPIOA,&GPIO_InitStructure);
	
}
void delay_ms(uint32_t ms) {
    for (int i = 0; i < ms; i++) {
       
    }
}
void chaseled(uint8_t loop){
	uint8_t i,j,status=1;
	for(j=1;j<=loop;j++){
		for (i=0;i<=4;i++){
		GPIO_Write(GPIOA,status<<i);
		delay_ms(1000000);
}
}
	
}
	
