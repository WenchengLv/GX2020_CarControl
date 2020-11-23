#include "MeasureTim.h"

// 中断优先级配置
static void GENERAL_TIM_NVIC_Config(void)
{
    NVIC_InitTypeDef NVIC_InitStructure; 
    // 设置中断组为0
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);		
		// 设置中断来源
    NVIC_InitStructure.NVIC_IRQChannel = GENERAL_TIM_IRQ ;	
		// 设置主优先级为 0
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	 
	  // 设置抢占优先级为3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

static void GENERAL_TIM_GPIO_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

	//通道一GPIO初始化
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH1_GPIO_CLK4, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH1_PIN4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GENERAL_TIM_CH1_PORT4, &GPIO_InitStructure);	
	
	//通道二GPIO初始化
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH2_GPIO_CLK4, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH2_PIN4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GENERAL_TIM_CH2_PORT4, &GPIO_InitStructure);
	
	//通道三GPIO初始化
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH3_GPIO_CLK4, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH3_PIN4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GENERAL_TIM_CH3_PORT4, &GPIO_InitStructure);
	
	//通道四GPIO初始化
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH4_GPIO_CLK4, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH4_PIN4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GENERAL_TIM_CH4_PORT4, &GPIO_InitStructure);
}


static void GENERAL_TIM_Mode_Config(void)
{
	 TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_ICInitTypeDef TIM_ICInitStructure;
	
	  // 开启定时器时钟,即内部时钟CK_INT=72M
	GENERAL_TIM_APBxClock_FUN(GENERAL_TIM_CLK4,ENABLE);

/*--------------------时基结构体初始化-------------------------*/	
 
	// 自动重装载寄存器的值，累计TIM_Period+1个频率后产生一个更新或者中断
	TIM_TimeBaseStructure.TIM_Period=GENERAL_TIM_PERIOD;	
	// 驱动CNT计数器的时钟 = Fck_int/(psc+1)
	TIM_TimeBaseStructure.TIM_Prescaler= GENERAL_TIM_PSC;	
	// 时钟分频因子 ，配置死区时间时需要用到
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// 计数器计数模式，设置为向上计数
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	// 重复计数器的值，没用到不用管
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	// 初始化定时器
	TIM_TimeBaseInit(GENERAL_TIM4, &TIM_TimeBaseStructure);

	/*--------------------输入捕获结构体初始化-------------------*/	
	
	//通道一
	// 配置输入捕获的通道，需要根据具体的GPIO来配置
	TIM_ICInitStructure.TIM_Channel = GENERAL_TIM_CHANNEL_x;
	// 输入捕获信号的极性配置
	TIM_ICInitStructure.TIM_ICPolarity = GENERAL_TIM_STRAT_ICPolarity;
	// 输入通道和捕获通道的映射关系，有直连和非直连两种
	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
	// 输入的需要被捕获的信号的分频系数
	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	// 输入的需要被捕获的信号的滤波系数
	TIM_ICInitStructure.TIM_ICFilter = 0;
	// 定时器输入捕获初始化
	TIM_ICInit(GENERAL_TIM4, &TIM_ICInitStructure);
	
	//通道二
	TIM_ICInitStructure.TIM_Channel = GENERAL_TIM_CHANNEL_x2;
	// 输入捕获信号的极性配置
	TIM_ICInitStructure.TIM_ICPolarity = GENERAL_TIM_STRAT_ICPolarity;
	// 输入通道和捕获通道的映射关系，有直连和非直连两种
	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
	// 输入的需要被捕获的信号的分频系数
	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	// 输入的需要被捕获的信号的滤波系数
	TIM_ICInitStructure.TIM_ICFilter = 0;
	// 定时器输入捕获初始化
	TIM_ICInit(GENERAL_TIM4, &TIM_ICInitStructure);
	
	//通道三
	TIM_ICInitStructure.TIM_Channel = GENERAL_TIM_CHANNEL_x3;
	// 输入捕获信号的极性配置
	TIM_ICInitStructure.TIM_ICPolarity = GENERAL_TIM_STRAT_ICPolarity;
	// 输入通道和捕获通道的映射关系，有直连和非直连两种
	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
	// 输入的需要被捕获的信号的分频系数
	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	// 输入的需要被捕获的信号的滤波系数
	TIM_ICInitStructure.TIM_ICFilter = 0;
	// 定时器输入捕获初始化
	TIM_ICInit(GENERAL_TIM4, &TIM_ICInitStructure);
	
	//通道四
	TIM_ICInitStructure.TIM_Channel = GENERAL_TIM_CHANNEL_x4;
	// 输入捕获信号的极性配置
	TIM_ICInitStructure.TIM_ICPolarity = GENERAL_TIM_STRAT_ICPolarity;
	// 输入通道和捕获通道的映射关系，有直连和非直连两种
	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
	// 输入的需要被捕获的信号的分频系数
	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	// 输入的需要被捕获的信号的滤波系数
	TIM_ICInitStructure.TIM_ICFilter = 0;
	// 定时器输入捕获初始化
	TIM_ICInit(GENERAL_TIM4, &TIM_ICInitStructure);
	
	// 清除更新和捕获中断标志位
  TIM_ClearFlag(GENERAL_TIM4, TIM_FLAG_Update|TIM_FLAG_CC1 | TIM_FLAG_CC2 | TIM_FLAG_CC3 |TIM_FLAG_CC4);	
  // 开启更新和捕获中断  
	TIM_ITConfig (GENERAL_TIM4, TIM_IT_Update | TIM_IT_CC1 | TIM_IT_CC2 | TIM_IT_CC3 | TIM_IT_CC4, ENABLE );
	
	// 使能计数器
	TIM_Cmd(GENERAL_TIM4, ENABLE);
}


static void TIM6_Config(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);
	TIM_TimeBaseStructure.TIM_Period=40000;	
	TIM_TimeBaseStructure.TIM_Prescaler=7199;	

	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);
   TIM_Cmd(TIM6, ENABLE);
}

void TIM_Init(void)
{
	TIM6_Config();
	GENERAL_TIM_NVIC_Config();
	GENERAL_TIM_GPIO_Config();
	GENERAL_TIM_Mode_Config();
}
