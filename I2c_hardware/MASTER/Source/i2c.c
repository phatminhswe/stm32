#include "i2c.h"

void I2C_write_byte(char data,char index){
    I2C_GenerateSTART(I2C_Chanel, ENABLE);
    while (!I2C_CheckEvent(I2C_Chanel, I2C_EVENT_MASTER_MODE_SELECT));
    
    I2C_Send7bitAddress(I2C_Chanel, Address, I2C_Direction_Transmitter);
    while (!I2C_CheckEvent(I2C_Chanel, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
    
		I2C_SendData(I2C_Chanel, index);
    while (!I2C_CheckEvent(I2C_Chanel, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
    I2C_SendData(I2C_Chanel, data);    
    while (!I2C_CheckEvent(I2C_Chanel, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
    I2C_GenerateSTOP(I2C_Chanel, ENABLE);	
}
uint8_t I2C_read_byte(){
uint8_t dataread;
  	I2C_AcknowledgeConfig(I2C1,ENABLE);
	I2C_GenerateSTART(I2C_Chanel, ENABLE);
	while (!I2C_CheckEvent(I2C_Chanel, I2C_EVENT_MASTER_MODE_SELECT));
	
	I2C_Send7bitAddress(I2C_Chanel, Address, I2C_Direction_Receiver);
	while (!I2C_CheckEvent(I2C_Chanel, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
	
			
	while (!I2C_CheckEvent(I2C_Chanel, I2C_EVENT_MASTER_BYTE_RECEIVED))
	;
	dataread = I2C_ReceiveData(I2C_Chanel);
			
	I2C_GenerateSTOP(I2C_Chanel,ENABLE);
			
       I2C_AcknowledgeConfig(I2C_Chanel,DISABLE);
	return dataread;
}
void I2C_config (void){
		
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2, ENABLE);							
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		GPIO_InitTypeDef 	GPIO_InitStructure;
	   I2C_InitTypeDef	I2C_InitStructure;
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;	//PB10 - SCL, PB11 - SDA
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    
    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
    I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
    I2C_InitStructure.I2C_OwnAddress1 = 0; // 
    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;       
    I2C_InitStructure.I2C_ClockSpeed = 100000;										
    I2C_Init(I2C2, &I2C_InitStructure);
    
    I2C_Cmd(I2C2, ENABLE);
}
void I2C_write_string(char *str){
	uint8_t i=0;
	while(*str){
		I2C_write_byte(*str,i);
		i++;
		str++;
	}
}
