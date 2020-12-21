#ifndef __ADC_H
#define	__ADC_H


#include "stm32f10x.h"

// ??:??ADC???IO??????,??????????
/********************ADC1????(??)??**************************/
#define    ADC_APBxClock_FUN             RCC_APB2PeriphClockCmd
#define    ADC_CLK                       RCC_APB2Periph_ADC3

#define    ADC_1_APBxClock_FUN             RCC_APB2PeriphClockCmd
#define    ADC_1_CLK                       RCC_APB2Periph_ADC1


#define    ADC_GPIO_APBxClock_FUN        RCC_APB2PeriphClockCmd
#define    ADC_GPIO_CLK                  RCC_APB2Periph_GPIOA  
#define    ADC_PORT                      GPIOF

#define    ADC_GPIO_APBxClock_FUN         RCC_APB2PeriphClockCmd
#define    ADC_1_GPIO_CLK                  RCC_APB2Periph_GPIOC  
#define    ADC_1_PORT                      GPIOC

#define    ADC_GPIO_APBxClock_FUN         RCC_APB2PeriphClockCmd
#define    ADC_1_2_GPIO_CLK                  RCC_APB2Periph_GPIOC  
#define    ADC_1_2_PORT                      GPIOA
// ??
// 1-PC0 ????????????,?????
// 2-PC0 ?????????SPI FLASH? ??,?????
// ?? PC0 ? ADC ???????,????????

// ??????
#define    NOFCHANEL										 4
#define    NOFCHANEL1										 8

#define    ADC_PIN0                      GPIO_Pin_6
#define    ADC_CHANNEL1                  ADC_Channel_4

#define    ADC_PIN1                      GPIO_Pin_7
#define    ADC_CHANNEL2                  ADC_Channel_5 //PC1

#define    ADC_PIN2                      GPIO_Pin_8
#define    ADC_CHANNEL3                  ADC_Channel_6 //PC2

#define    ADC_PIN3                      GPIO_Pin_9
#define    ADC_CHANNEL4                  ADC_Channel_7 //PC3

#define    ADC_1_PIN0                     GPIO_Pin_0
#define    ADC_1_PIN1                     GPIO_Pin_1
#define    ADC_1_PIN2                     GPIO_Pin_2
#define    ADC_1_PIN3                     GPIO_Pin_3
#define    ADC_1_PIN4                     GPIO_Pin_4
#define    ADC_1_PIN5                     GPIO_Pin_5
#define    ADC_1_PIN6                     GPIO_Pin_4
#define    ADC_1_PIN7                     GPIO_Pin_5

#define    ADC_1_CHANNEL1                  ADC_Channel_10
#define    ADC_1_CHANNEL2                  ADC_Channel_11
#define    ADC_1_CHANNEL3                  ADC_Channel_12
#define    ADC_1_CHANNEL4                  ADC_Channel_13
#define    ADC_1_CHANNEL5                  ADC_Channel_14
#define    ADC_1_CHANNEL6                  ADC_Channel_15
#define    ADC_1_CHANNEL7                  ADC_Channel_4
#define    ADC_1_CHANNEL8                  ADC_Channel_5


//#define    ADC_PIN4                      GPIO_Pin_4
//#define    ADC_CHANNEL5                  ADC_Channel_14 //PC4
// 
//#define    ADC_PIN5                      GPIO_Pin_5
//#define    ADC_CHANNEL6                  ADC_Channel_15 //PC5


//#define    ADC_CHANNEL7                  ADC_Channel_4 //PA4


//#define    ADC_CHANNEL8                  ADC_Channel_5 //PA5



#define    ADC_x                          ADC3
#define    ADC_DMA_CHANNEL                DMA2_Channel5
#define    ADC_DMA_CLK                    RCC_AHBPeriph_DMA2

#define    ADC_1_x                         ADC1
#define    ADC_1_DMA_CHANNEL               DMA1_Channel1
#define    ADC_1_DMA_CLK                   RCC_AHBPeriph_DMA1


/**************************????********************************/
void               ADCx_Init                               (void);


#endif /* __ADC_H */

