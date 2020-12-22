#include "stm32f10x.h"
#include "bsp_usart.h"
#include "bsp_adc.h"
#include "bsp_GeneralTim.h"
#include "MeasureTim.h"
#include "car.h"
#include "RobotArm_Tim.h"
void Delay111(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 

u16 Left_Forward=2000;
u16 Left_Backward=2000;
u16 Right_Forward=2000;
u16 Right_Backward=2000;

u16 RobotArm_1=1500;
u16 RobotArm_2=0;
u16 RobotArm_3=0;
u16 RobotArm_4=0;


int main(void)
{
	GENERAL_TIM_Init();
	USART_Config();
	ADCx_Init();
	TIM_Init();
	RobotArm_TIM_Init();
	
	while(1){ 
}
}

