

#include "i2c_slave.h"
uint8_t data_transmit[10] = "PHAT";
uint8_t data_receive[30];
uint8_t Recei_count=0;
uint8_t Trans_count=0;
void I2C1_Slave_init(void) {
    GPIO_InitTypeDef  GPIO_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    I2C_InitTypeDef  I2C_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

    
    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    
    NVIC_InitStructure.NVIC_IRQChannel                   = I2C1_EV_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    
    NVIC_InitStructure.NVIC_IRQChannel = I2C1_ER_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
    I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
    I2C_InitStructure.I2C_OwnAddress1 = I2CSLAVE_ADDR;
    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    I2C_InitStructure.I2C_ClockSpeed = I2C1_CLOCK_FRQ;

    
    I2C_Cmd(I2C1, ENABLE);
    
    I2C_Init(I2C1, &I2C_InitStructure);
    I2C_ITConfig(I2C1, I2C_IT_EVT, ENABLE); 
    I2C_ITConfig(I2C1, I2C_IT_BUF, ENABLE);
    I2C_ITConfig(I2C1, I2C_IT_ERR, ENABLE); 
}

void I2C1_ClearFlag(void) {
  while((I2C1->SR1 & I2C_SR1_ADDR) == I2C_SR1_ADDR) {
    I2C1->SR1;
    I2C1->SR2;
  }
  while((I2C1->SR1&I2C_SR1_STOPF) == I2C_SR1_STOPF) {
    I2C1->SR1;
    I2C1->CR1 |= 0x1;
  }

}

void I2C1_EV_IRQHandler(void) {
  uint32_t event;

  event=I2C_GetLastEvent(I2C1);

  if(event==I2C_EVENT_SLAVE_RECEIVER_ADDRESS_MATCHED) {
    
  }
  else if(event==I2C_EVENT_SLAVE_BYTE_RECEIVED) {
   
    data_receive[Recei_count]=I2C_ReceiveData(I2C1);
		Recei_count++;
    
  }
  else if(event==I2C_EVENT_SLAVE_TRANSMITTER_ADDRESS_MATCHED) {
    I2C_SendData(I2C1, data_transmit[Trans_count]);
		Trans_count ++;

  }
  else if(event==I2C_EVENT_SLAVE_BYTE_TRANSMITTED) {
		I2C_SendData(I2C1, data_transmit[Trans_count]);
		
	}
  else if(event==I2C_EVENT_SLAVE_STOP_DETECTED) {
    
	  I2C1_ClearFlag();
  }
}


void I2C1_ER_IRQHandler(void) {
  if (I2C_GetITStatus(I2C1, I2C_IT_AF)) {
    I2C_ClearITPendingBit(I2C1, I2C_IT_AF);
  }
}

