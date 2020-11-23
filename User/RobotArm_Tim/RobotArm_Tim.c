#include "RobotArm_Tim.h"

extern u16 RobotArm_1;
extern u16 RobotArm_2;
extern u16 RobotArm_3;
extern u16 RobotArm_4;

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

static void RobotArm_TIM_Mode_Config(void)
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
	TIM_OC1Init(RobotArm_TIM, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(RobotArm_TIM, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC2Init(RobotArm_TIM, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(RobotArm_TIM, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC3Init(RobotArm_TIM, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(RobotArm_TIM, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC4Init(RobotArm_TIM, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(RobotArm_TIM, TIM_OCPreload_Enable);
	
	// 使能计数器
	TIM_Cmd(RobotArm_TIM, ENABLE);
}

void PWM_ArmRobot_1(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OCInitStructure.TIM_Pulse = RobotArm_1;
	
	TIM_OC1Init(RobotArm_TIM, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(RobotArm_TIM, TIM_OCPreload_Enable);
}

void PWM_ArmRobot_2(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OCInitStructure.TIM_Pulse = RobotArm_2;
	
	TIM_OC2Init(RobotArm_TIM, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(RobotArm_TIM, TIM_OCPreload_Enable);
}

void PWM_ArmRobot_3(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OCInitStructure.TIM_Pulse = RobotArm_3;
	
	TIM_OC3Init(RobotArm_TIM, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(RobotArm_TIM, TIM_OCPreload_Enable);
}

void PWM_ArmRobot_4(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OCInitStructure.TIM_Pulse = RobotArm_4;
	
	TIM_OC4Init(RobotArm_TIM, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(RobotArm_TIM, TIM_OCPreload_Enable);
}


void RobotArm_Enable(void)
{
	PWM_ArmRobot_1();
	PWM_ArmRobot_2();
	PWM_ArmRobot_3();
	PWM_ArmRobot_4();
}

void RobotArm_TIM_Init(void)
{
	RobotArm_TIM_GPIO_Config();
	RobotArm_TIM_Mode_Config();
}
