#include "stm32f10x.h"
#include "bsp_usart.h"
#include "bsp_adc.h"
#include "bsp_GeneralTim.h"
#include "MeasureTim.h"
#include "car.h"

u16 Left_Forward=4000;
u16 Left_Backward=4000;
u16 Right_Forward=4000;
u16 Right_Backward=4000;

int main(void)
{
	GENERAL_TIM_Init();
	USART_Config();
	ADCx_Init();
	TIM_Init();
	while(1){ 
	}
}
