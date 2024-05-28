
#include "spi.h"
#include "MFRC522.h"
#include "delay.h"
#include "uart.h"
#include "PWM.h"
extern Uid uid; 
volatile int timeLED =0;
volatile uint8_t stateLED = HIGH;
StatusCode status= STATUS_ERROR;
void My_GPIO_Init(void);

void TIM2_IRQHandler() {
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
			if( status == STATUS_OK){
				timeLED++;
				if(timeLED * 20 >= 300){
					stateLED = ~ stateLED;
					if(stateLED == 1){
					digitalWrite(PC13,HIGH);
					}else{
					digitalWrite(PC13,LOW);
					}
					timeLED =0;
				}
			}else{
				digitalWrite(PC13,HIGH);
				timeLED =0;
			}
    }
}
int main(){
	
		My_GPIO_Init();
		SPI_init(SPI_CHANNEL_SP2);
		Delay_Init();
		UART_init();
		pinMode(PC13,OUTPUT);
		digitalWrite(PC13,HIGH);
		
		PCD_Init();
		PWM_Init();
		
    while(1)
    {
      if (!PICC_IsNewCardPresent()) {
        continue;
     }
      if (!PICC_ReadCardSerial()) {
        continue;
      }
			
			//PICC_DumpToSerial(&uid);
			
			status = STATUS_OK;
			uint8_t angle=0;
			while(angle <= 90){
				PWM_angle(angle++);
				Delay_Ms(20);
			}

			while(angle != 0){
					PWM_angle(angle--);
					Delay_Ms(20);
			}
			status = STATUS_ERROR;

			PICC_HaltA();
			PCD_StopCrypto1();
    }
}
/*---------------------------------------------------------------------------*/
void My_GPIO_Init(void) {
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
}