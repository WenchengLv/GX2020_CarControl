#ifndef __RobotArm_TIME_H
#define __RobotArm_TIME_H


#include "stm32f10x.h"


#define            RobotArm_TIM                   TIM1
#define            RobotArm_TIM_APBxClock_FUN     RCC_APB2PeriphClockCmd
#define            RobotArm_TIM_CLK               RCC_APB2Periph_TIM1
#define            RobotArm_TIM_Period            60000
#define            RobotArm_TIM_Prescaler         35
// TIM3 输出比较通道1
#define            RobotArm_TIM_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            RobotArm_TIM_CH1_PORT          GPIOA
#define            RobotArm_TIM_CH1_PIN           GPIO_Pin_8

// TIM3 输出比较通道2
#define            RobotArm_TIM_CH2_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            RobotArm_TIM_CH2_PORT          GPIOA
#define            RobotArm_TIM_CH2_PIN           GPIO_Pin_9

// TIM3 输出比较通道3
#define            RobotArm_TIM_CH3_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            RobotArm_TIM_CH3_PORT          GPIOA
#define            RobotArm_TIM_CH3_PIN           GPIO_Pin_10

// TIM3 输出比较通道4
#define            RobotArm_TIM_CH4_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            RobotArm_TIM_CH4_PORT          GPIOA
#define            RobotArm_TIM_CH4_PIN           GPIO_Pin_11

void RobotArm_TIM_Init(void);
void RobotArm_Enable(void);

#endif
