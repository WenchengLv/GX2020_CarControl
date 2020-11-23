#ifndef __BSP_GENERALTIME_H
#define __BSP_GENERALTIME_H


#include "stm32f10x.h"


/************通用定时器TIM参数定义，只限TIM2、3、4、5************/
// 当使用不同的定时器的时候，对应的GPIO是不一样的，这点要注意
// 我们这里默认使用TIM3

#define            GENERAL_TIM                   TIM3
#define            GENERAL_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM_CLK               RCC_APB1Periph_TIM3
#define            GENERAL_TIM_Period            10000
#define            GENERAL_TIM_Prescaler         10
// TIM3 输出比较通道1
#define            GENERAL_TIM_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH1_PORT          GPIOA
#define            GENERAL_TIM_CH1_PIN           GPIO_Pin_6

// TIM3 输出比较通道2
#define            GENERAL_TIM_CH2_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH2_PORT          GPIOA
#define            GENERAL_TIM_CH2_PIN           GPIO_Pin_7

// TIM3 输出比较通道3
#define            GENERAL_TIM_CH3_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM_CH3_PORT          GPIOB
#define            GENERAL_TIM_CH3_PIN           GPIO_Pin_0

// TIM3 输出比较通道4
#define            GENERAL_TIM_CH4_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM_CH4_PORT          GPIOB
#define            GENERAL_TIM_CH4_PIN           GPIO_Pin_1


#define            GENERAL_TIM5                   TIM5
#define            GENERAL_TIM_APBxClock_FUN5     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM_CLK5               RCC_APB1Periph_TIM5
#define            GENERAL_TIM_Period5            10000
#define            GENERAL_TIM_Prescaler5         10
// TIM3 输出比较通道1
#define            GENERAL_TIM_CH1_GPIO_CLK5      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH1_PORT5          GPIOA
#define            GENERAL_TIM_CH1_PIN5           GPIO_Pin_0

// TIM3 输出比较通道2
#define            GENERAL_TIM_CH2_GPIO_CLK5      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH2_PORT5          GPIOA
#define            GENERAL_TIM_CH2_PIN5           GPIO_Pin_1

// TIM3 输出比较通道3
#define            GENERAL_TIM_CH3_GPIO_CLK5      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH3_PORT5          GPIOA
#define            GENERAL_TIM_CH3_PIN5           GPIO_Pin_2

// TIM3 输出比较通道4
#define            GENERAL_TIM_CH4_GPIO_CLK5      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH4_PORT5          GPIOA
#define            GENERAL_TIM_CH4_PIN5           GPIO_Pin_3

/**************************函数声明********************************/
void PWM_Init(void);
void GENERAL_TIM_Init(void);
void PWM_PA0(void);
void PWM_PA1(void);
void PWM_PA2(void);
void PWM_PA3(void);
void PWM_PA4(void);
void PWM_PA5(void);
void PWM_PA6(void);
void PWM_PA7(void);
#endif	/* __BSP_GENERALTIME_H */


