#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x.h"
#include "stdbool.h"

volatile bool staTe;
void RRC_Config();
 
void GPIO_config();

void readbutton();

int main(){
RRC_Config();
GPIO_config();

while(1){		

readbutton();

}
return 0;
}


void RRC_Config(){
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
}
void GPIO_config(){
GPIO_InitTypeDef GPIO_InitStructure;
	
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(GPIOC,&GPIO_InitStructure);
	
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(GPIOA,&GPIO_InitStructure);

	
}
void readbutton(){
if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)){
while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1));
int i;
if(staTe == 0){
GPIO_ResetBits(GPIOC, GPIO_Pin_13);
	staTe=  1;
} 
else {
GPIO_SetBits(GPIOC, GPIO_Pin_13);
	staTe=  0;
}

}
	
}