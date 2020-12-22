#include "RobotArm_Tim.h"

extern u16 RobotArm_1;
extern u16 RobotArm_2;
extern u16 RobotArm_3;
extern u16 RobotArm_4;

// static void ADVANCE_TIM_NVIC_Config(void)
// {
//     NVIC_InitTypeDef NVIC_InitStructure; 
//     // ??????0
//     NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);		
// 		// ??????
//     NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn ;	
// 		// ??????? 0
//     NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	 
// 	  // ????????3
//     NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
//     NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//     NVIC_Init(&NVIC_InitStructure);
// }

static void RobotArm_TIM_GPIO_Config(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE | RCC_APB2Periph_AFIO,ENABLE);
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM1 ,ENABLE);


	RCC_APB2PeriphClockCmd(RobotArm_TIM_CH1_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  RobotArm_TIM_CH1_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(RobotArm_TIM_CH1_PORT, &GPIO_InitStructure);

	RCC_APB2PeriphClockCmd(RobotArm_TIM_CH2_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  RobotArm_TIM_CH2_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(RobotArm_TIM_CH2_PORT, &GPIO_InitStructure);

	RCC_APB2PeriphClockCmd(RobotArm_TIM_CH3_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  RobotArm_TIM_CH3_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(RobotArm_TIM_CH3_PORT, &GPIO_InitStructure);

	RCC_APB2PeriphClockCmd(RobotArm_TIM_CH4_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  RobotArm_TIM_CH4_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(RobotArm_TIM_CH4_PORT, &GPIO_InitStructure);
}

static void RobotArm_TIM_Mode_Config(void)
{
	 TIM_BDTRInitTypeDef TIM_BDTRInitStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	RobotArm_TIM_APBxClock_FUN(RobotArm_TIM_CLK,ENABLE);
	TIM_TimeBaseStructure.TIM_Period=RobotArm_TIM_Period;	
	TIM_TimeBaseStructure.TIM_Prescaler= RobotArm_TIM_Prescaler;	
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	

	  TIM_TimeBaseInit(RobotArm_TIM, &TIM_TimeBaseStructure);
	
    TIM_ClearFlag(RobotArm_TIM, TIM_FLAG_Update);
    TIM_ITConfig(RobotArm_TIM,TIM_IT_Update,ENABLE);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OCInitStructure.TIM_Pulse = 3000;
	TIM_OC1Init(RobotArm_TIM, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(RobotArm_TIM, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = 4000;
	TIM_OC2Init(RobotArm_TIM, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(RobotArm_TIM, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = 4000;
	TIM_OC3Init(RobotArm_TIM, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(RobotArm_TIM, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = 2000;
	TIM_OC4Init(RobotArm_TIM, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(RobotArm_TIM, TIM_OCPreload_Enable);
	
				TIM_BDTRInitStructure.TIM_OSSRState = TIM_OSSRState_Disable;//????????? 
        TIM_BDTRInitStructure.TIM_OSSIState = TIM_OSSIState_Disable;//????????? 
        TIM_BDTRInitStructure.TIM_LOCKLevel = TIM_LOCKLevel_OFF;         //????
        TIM_BDTRInitStructure.TIM_DeadTime = 0x90;                                         //??????
        TIM_BDTRInitStructure.TIM_Break = TIM_Break_Disable;                 //??????
        TIM_BDTRInitStructure.TIM_BreakPolarity = TIM_BreakPolarity_High;//??????
        TIM_BDTRInitStructure.TIM_AutomaticOutput = TIM_AutomaticOutput_Enable;//?????? 
        TIM_BDTRConfig(TIM1,&TIM_BDTRInitStructure);        
	
	
	
	TIM_ARRPreloadConfig(TIM1, ENABLE);    
	// 使能计数器
	TIM_Cmd(RobotArm_TIM, ENABLE);
	TIM_CtrlPWMOutputs(TIM1, ENABLE); 
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
	
	TIM_ARRPreloadConfig(TIM1, ENABLE);    
	TIM_CtrlPWMOutputs(TIM1, ENABLE); 
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
 	//ADVANCE_TIM_NVIC_Config();
 	RobotArm_TIM_GPIO_Config();
 	RobotArm_TIM_Mode_Config();
}
