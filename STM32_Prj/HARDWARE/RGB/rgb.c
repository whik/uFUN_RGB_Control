#include "rgb.h"

//2-R, 3-G, 1-B
//TIM5_CH1/CH2/CH3 PWM配置输出
void RGB_LED_Init(void)
{
	GPIO_InitTypeDef IO_Init;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef OC_Init;
		
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
	
	IO_Init.GPIO_Mode = GPIO_Mode_AF_PP;
	IO_Init.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2;
	IO_Init.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &IO_Init);
	
	TIM_DeInit(TIM5);
	
	TIM_TimeBaseStructure.TIM_Period = 256-1; 
    TIM_TimeBaseStructure.TIM_Prescaler = 71;		
    TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
    TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure); 
	
//	OC_Init.TIM_OCMode = TIM_OCMode_PWM2;//输出模式
	OC_Init.TIM_OCMode = TIM_OCMode_PWM1;//输出模式
	OC_Init.TIM_OutputState = ENABLE;				//输出使能
	OC_Init.TIM_OCPolarity = TIM_OCPolarity_High;	//输出极性
//	OC_Init.TIM_Pulse = 50;
	
	TIM_OC1Init(TIM5, &OC_Init);		
	TIM_OC2Init(TIM5, &OC_Init);		
	TIM_OC3Init(TIM5, &OC_Init);	
	
	TIM_OC1PreloadConfig(TIM5, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM5, TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM5, TIM_OCPreload_Enable);
	
	TIM_Cmd(TIM5, ENABLE); 
}
//设置LED占空比
void SetDutyCycle(LEDtype LEDn, int dty)
{
    switch(LEDn)
    {
        case R_LED:
            TIM_SetCompare3(TIM5, dty);
        break;
        case G_LED:
            TIM_SetCompare1(TIM5, dty);
        break;		
        case B_LED:
            TIM_SetCompare2(TIM5, dty);
        break;
        default:
            TIM_SetCompare1(TIM5, 0);
            TIM_SetCompare2(TIM5, 0);
            TIM_SetCompare2(TIM5, 0);
        break;			
    }    
}












