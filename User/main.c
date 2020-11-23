#include "stm32f10x.h"
#include "bsp_usart.h"
#include "bsp_adc.h"
#include "bsp_GeneralTim.h"
#include "MeasureTim.h"
#include "car.h"
// ADC1????????MDA????SRAM

u16 Left_Forward=4000;
u16 Left_Backward=4000;
u16 Right_Forward=4000;
u16 Right_Backward=4000;

u16 RobotArm_1=0;
u16 RobotArm_2=0;
u16 RobotArm_3=0;
u16 RobotArm_4=0;


int main(void)
{
	GENERAL_TIM_Init();
	USART_Config();
	ADCx_Init();
	TIM_Init();
	//CAR_Down(2);
	while(1){ 
		
	}
}
