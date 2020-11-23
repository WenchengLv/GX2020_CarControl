
#include "bsp_GeneralTim.h" 

extern u16 Left_Forward;
extern u16 Left_Backward;
extern u16 Right_Forward;
extern u16 Right_Backward;

static void GENERAL_TIM_GPIO_Config(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // 输出比较通道1 GPIO 初始化
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH1_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH1_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH1_PORT, &GPIO_InitStructure);
	
	// 输出比较通道2 GPIO 初始化
	//RCC_APB2PeriphClockCmd(GENERAL_TIM_CH2_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH2_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH2_PORT, &GPIO_InitStructure);
	
	// 输出比较通道3 GPIO 初始化
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH3_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH3_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH3_PORT, &GPIO_InitStructure);
	
	// 输出比较通道4 GPIO 初始化
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH3_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH4_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH4_PORT, &GPIO_InitStructure);
}


static void GENERAL_TIM_GPIO_Config_Tim5(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // 输出比较通道1 GPIO 初始化
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH1_GPIO_CLK5, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH1_PIN5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH1_PORT5, &GPIO_InitStructure);
	
	// 输出比较通道2 GPIO 初始化
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH2_GPIO_CLK5, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH2_PIN5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH2_PORT5, &GPIO_InitStructure);
	
	// 输出比较通道3 GPIO 初始化
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH3_GPIO_CLK5, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH3_PIN5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH3_PORT5, &GPIO_InitStructure);
	
	// 输出比较通道4 GPIO 初始化
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH4_GPIO_CLK5, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH4_PIN5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH4_PORT5, &GPIO_InitStructure);
}


static void GENERAL_TIM_Mode_Config(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	GENERAL_TIM_APBxClock_FUN(GENERAL_TIM_CLK,ENABLE);
	TIM_TimeBaseStructure.TIM_Period=GENERAL_TIM_Period;	
	TIM_TimeBaseStructure.TIM_Prescaler= GENERAL_TIM_Prescaler;	
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// 计数器计数模式，设置为向上计数
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	
	// 初始化定时器
	TIM_TimeBaseInit(GENERAL_TIM, &TIM_TimeBaseStructure);

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
	TIM_Cmd(GENERAL_TIM, ENABLE);
}


static void GENERAL_TIM_Mode_Config_Tim5()
{
		TIM_OCInitTypeDef  TIM_OCInitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
  // 开启定时器时钟,即内部时钟CK_INT=72M
	GENERAL_TIM_APBxClock_FUN5(GENERAL_TIM_CLK5,ENABLE);

/*--------------------时基结构体初始化-------------------------*/
	// 配置周期，这里配置为100K
	
 
	// 自动重装载寄存器的值，累计TIM_Period+1个频率后产生一个更新或者中断
	TIM_TimeBaseStructure.TIM_Period=GENERAL_TIM_Period5;	
	// 驱动CNT计数器的时钟 = Fck_int/(psc+1)
	TIM_TimeBaseStructure.TIM_Prescaler= GENERAL_TIM_Prescaler5;	
	// 时钟分频因子 ，配置死区时间时需要用到
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// 计数器计数模式，设置为向上计数
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	// 重复计数器的值，没用到不用管
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	// 初始化定时器
	TIM_TimeBaseInit(GENERAL_TIM5, &TIM_TimeBaseStructure);
	
	

	// 配置为PWM模式1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// 输出使能
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// 输出通道电平极性配置	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	// 输出比较通道 1
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC1Init(GENERAL_TIM5, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC2Init(GENERAL_TIM5, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC3Init(GENERAL_TIM5, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC4Init(GENERAL_TIM5, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);

	// 使能计数器
	TIM_Cmd(GENERAL_TIM5, ENABLE);
	
}

//前进 
// PWM_PA0() 左前轮  PA0
// PWM_PA1() 右前轮  PA1
// PWM_PA2() 左后轮  PA2
// PWM_PA3() 右后轮  PA3
void PWM_PA0(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OCInitStructure.TIM_Pulse = Left_Forward;
	
	TIM_OC1Init(GENERAL_TIM5, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
}

void PWM_PA1(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OCInitStructure.TIM_Pulse = Right_Forward;
	
	TIM_OC2Init(GENERAL_TIM5, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
}

void PWM_PA2(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OCInitStructure.TIM_Pulse = Left_Backward;
	
	TIM_OC3Init(GENERAL_TIM5, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
}

void PWM_PA3(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OCInitStructure.TIM_Pulse = Right_Backward;
	
	TIM_OC4Init(GENERAL_TIM5, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
}



// 后退 
// PWM_PA4() 左前轮  PA6
// PWM_PA5() 右前轮  PA7
// PWM_PA6() 左后轮  PB0
// PWM_PA7() 右后轮  PB1
void PWM_PA4(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OCInitStructure.TIM_Pulse = Left_Forward;
	
	TIM_OC1Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
}

void PWM_PA5(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OCInitStructure.TIM_Pulse = Right_Forward;
	
	TIM_OC2Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
}

void PWM_PA6(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OCInitStructure.TIM_Pulse = Left_Backward;
	
	TIM_OC3Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
}

void PWM_PA7(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OCInitStructure.TIM_Pulse = Right_Backward;
	
	TIM_OC4Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
}

void PWM_Init(void)
{
	GENERAL_TIM_Mode_Config();	
	GENERAL_TIM_Mode_Config_Tim5();
}

void GENERAL_TIM_Init(void)
{
	GENERAL_TIM_GPIO_Config();
	GENERAL_TIM_GPIO_Config_Tim5();
	GENERAL_TIM_Mode_Config();	
	GENERAL_TIM_Mode_Config_Tim5();	
}

/*********************************************END OF FILE**********************/
