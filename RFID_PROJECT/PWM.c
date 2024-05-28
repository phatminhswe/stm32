#include "PWM.h"

void PWM_angle(uint8_t angle) {
    float slope = (float)(MAX_PULSE_WIDTH - MIN_PULSE_WIDTH) / (MAX_ANGLE - MIN_ANGLE);
    uint16_t comparel = (uint16_t)(slope * (angle - MIN_ANGLE) + MIN_PULSE_WIDTH);
		TIM_SetCompare1(TIM2,comparel);
}

void PWM_Init(void) {
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;
	 NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);

    // Time base configuration
    TIM_TimeBaseStructure.TIM_Period = 19999;  
    TIM_TimeBaseStructure.TIM_Prescaler = 71;  
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

    // PWM configuration
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 500;  // Initial pulse width for servo center position
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

    TIM_OC1Init(TIM2, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);
	 TIM_Cmd(TIM2, ENABLE);

    // GPIO configuration
    GPIO_InitTypeDef GPIO_InitStructure;

    // Configure PA0 as alternate function push-pull
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
		
		// Enable Timer 2 interrupt
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    // Enable Timer 2 and its interrupt
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
}
