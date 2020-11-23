#ifndef __ADC_H
#define	__ADC_H


#include "stm32f10x.h"



// ????,ADC1?ADC2?????????ADC1??????,
// ADC1??????,ADC2??????
// ?ADC??????ADC,???ADC1
#define    ADCx_1                           ADC1
#define    ADCx_1_APBxClock_FUN             RCC_APB2PeriphClockCmd
#define    ADCx_1_CLK                       RCC_APB2Periph_ADC1

#define    ADCx_1_GPIO_APBxClock_FUN        RCC_APB2PeriphClockCmd
#define    ADCx_1_GPIO_CLK1                 RCC_APB2Periph_GPIOC 
#define    ADCx_1_GPIO_CLK2                 RCC_APB2Periph_GPIOC  
#define    ADCx_1_PORT1                     GPIOA
#define    ADCx_1_PORT2                     GPIOC
//#define    ADCx_1_PIN                       GPIO_Pin_1
//#define    ADCx_1_CHANNEL                   ADC_Channel_11




// ?ADC??????ADC,???ADC2
#define    ADCx_3                           ADC3
#define    ADCx_3_APBxClock_FUN             RCC_APB2PeriphClockCmd
#define    ADCx_3_CLK                       RCC_APB2Periph_ADC3

#define    ADCx_3_GPIO_APBxClock_FUN        RCC_APB2PeriphClockCmd
#define    ADCx_3_GPIO_CLK                  RCC_APB2Periph_GPIOF  
#define    ADCx_3_PORT                      GPIOF
//#define    ADCx_3_PIN                       GPIO_Pin_4
//#define    ADCx_3_CHANNEL                 ADC_Channel_14

#define    ADCx_1_PIN0                       GPIO_Pin_0
#define    ADCx_1_PIN1                       GPIO_Pin_1
#define    ADCx_1_PIN2                       GPIO_Pin_2
#define    ADCx_1_PIN3                       GPIO_Pin_3
#define    ADCx_1_PIN4                       GPIO_Pin_4
#define    ADCx_1_PIN5                       GPIO_Pin_5

#define    ADCx_3_PIN6                       GPIO_Pin_6
#define    ADCx_3_PIN7                       GPIO_Pin_7
#define    ADCx_3_PIN8                       GPIO_Pin_8
#define    ADCx_3_PIN9                       GPIO_Pin_9
#define    ADCx_3_PIN10                      GPIO_Pin_10

#define    NOFCHANEL1                        8
#define    NOFCHANEL3                        4

// ADC1 ?? DMA1??1,ADC3??DMA2??5,ADC2??DMA??
#define    ADC_DMA_CHANNEL                 DMA1_Channel1
#define    ADC_3_DMA_CHANNEL               DMA2_Channel5

void ADCx_Init(void);


#endif /* __ADC_H */
