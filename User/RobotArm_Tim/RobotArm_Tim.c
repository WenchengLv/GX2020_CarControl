#include "RobotArm_Tim.h"

static void RobotArm_TIM_GPIO_Config(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RobotArm_TIM_CH1_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  RobotArm_TIM_CH1_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(RobotArm_TIM_CH1_PORT, &GPIO_InitStructure);
	
	// 输出比较通道2 GPIO 初始化
	RCC_APB2PeriphClockCmd(RobotArm_TIM_CH2_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  RobotArm_TIM_CH2_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(RobotArm_TIM_CH2_PORT, &GPIO_InitStructure);
	
	// 输出比较通道3 GPIO 初始化
	RCC_APB2PeriphClockCmd(RobotArm_TIM_CH3_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  RobotArm_TIM_CH3_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(RobotArm_TIM_CH3_PORT, &GPIO_InitStructure);
	
	// 输出比较通道4 GPIO 初始化
	RCC_APB2PeriphClockCmd(RobotArm_TIM_CH3_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  RobotArm_TIM_CH4_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(RobotArm_TIM_CH4_PORT, &GPIO_InitStructure);
}

static void GENERAL_TIM_Mode_Config(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	RobotArm_TIM_APBxClock_FUN(RobotArm_TIM_CLK,ENABLE);
	TIM_TimeBaseStructure.TIM_Period=RobotArm_TIM_Period;	
	TIM_TimeBaseStructure.TIM_Prescaler= RobotArm_TIM_Prescaler;	
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	

	TIM_TimeBaseInit(RobotArm_TIM, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC1Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC2Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC3Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC4Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
	
	// 使能计数器
	TIM_Cmd(RobotArm_TIM, ENABLE);
}