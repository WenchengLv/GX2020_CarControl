#include "car.h"

extern u16 Left_Forward;
extern u16 Left_Backward;
extern u16 Right_Forward;
extern u16 Right_Backward;


// ADC1????????MDA????SRAM
extern __IO uint16_t ADC_ConvertedValue[NOFCHANEL];
extern __IO uint16_t ADC_ConvertedValue_1[NOFCHANEL1];

// ????,????????????? 	 
float ADC_ConvertedValueLocal[NOFCHANEL];        
float ADC_ConvertedValueLocal1[NOFCHANEL1];  
// ????
void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 


static void CAR_DOWN(void)
{	
	Left_Forward=init_pwm;
	Left_Backward=init_pwm;
	Right_Forward=init_pwm;
	Right_Backward=init_pwm;
		PWM_PA0();
		PWM_PA1();
		PWM_PA2();
		PWM_PA3();
	TIM_Cmd(TIM4,ENABLE);
	TIM_ClearFlag(TIM6,TIM_FLAG_Update);
	TIM_SetCounter(TIM6,0x00);
	
	while(1){
			ADC_ConvertedValueLocal[0] =(float) ADC_ConvertedValue[0]/4096*3.3;
			ADC_ConvertedValueLocal[1] =(float) ADC_ConvertedValue[1]/4096*3.3;
			ADC_ConvertedValueLocal[2] =(float) ADC_ConvertedValue[2]/4096*3.3;
			ADC_ConvertedValueLocal[3] =(float) ADC_ConvertedValue[3]/4096*3.3;
		
			ADC_ConvertedValueLocal1[0] =(float) ADC_ConvertedValue_1[0]/4096*3.3;
			ADC_ConvertedValueLocal1[1] =(float) ADC_ConvertedValue_1[1]/4096*3.3;
			ADC_ConvertedValueLocal1[2] =(float) ADC_ConvertedValue_1[2]/4096*3.3;
			ADC_ConvertedValueLocal1[3] =(float) ADC_ConvertedValue_1[3]/4096*3.3;
			ADC_ConvertedValueLocal1[4] =(float) ADC_ConvertedValue_1[4]/4096*3.3;
			ADC_ConvertedValueLocal1[5] =(float) ADC_ConvertedValue_1[5]/4096*3.3;
			ADC_ConvertedValueLocal1[6] =(float) ADC_ConvertedValue_1[6]/4096*3.3;
			ADC_ConvertedValueLocal1[7] =(float) ADC_ConvertedValue_1[7]/4096*3.3;
		
			
			

		PWM_PA0();
		PWM_PA1();
		PWM_PA2();
		PWM_PA3();
		if(ADC_ConvertedValueLocal1[3]>Detect_Threshold)
		{	
			if(ADC_ConvertedValueLocal1[2]<Detect_Threshold)
				{
					Left_Forward=Desired_Number;
					Left_Backward=Desired_Number;
				}
				if(ADC_ConvertedValueLocal1[4]<Detect_Threshold)
				{
					
					Right_Forward=Desired_Number;
					Right_Backward=Desired_Number;
				}
		}
		if(TIM_GetFlagStatus(TIM6,TIM_FLAG_Update)&&ADC_ConvertedValueLocal1[0]<Detect_Threshold)
		{
			break;
		}
	}
	TIM_Cmd(TIM4,DISABLE);
	PWM_Init();
}

static void CAR_GO(void)
{
	Left_Forward=init_pwm;
	Left_Backward=init_pwm;
	Right_Forward=init_pwm;
	Right_Backward=init_pwm;
		PWM_PA4();
		PWM_PA5();
		PWM_PA6();
		PWM_PA7();
	TIM_Cmd(TIM4,ENABLE);
	TIM_ClearFlag(TIM6,TIM_FLAG_Update);
	TIM_SetCounter(TIM6,0x00);
	
	while(1){
		
			ADC_ConvertedValueLocal[0] =(float) ADC_ConvertedValue[0]/4096*3.3;
			ADC_ConvertedValueLocal[1] =(float) ADC_ConvertedValue[1]/4096*3.3;
			ADC_ConvertedValueLocal[2] =(float) ADC_ConvertedValue[2]/4096*3.3;
			ADC_ConvertedValueLocal[3] =(float) ADC_ConvertedValue[3]/4096*3.3;
		
			ADC_ConvertedValueLocal1[0] =(float) ADC_ConvertedValue_1[0]/4096*3.3;
			ADC_ConvertedValueLocal1[1] =(float) ADC_ConvertedValue_1[1]/4096*3.3;
			ADC_ConvertedValueLocal1[2] =(float) ADC_ConvertedValue_1[2]/4096*3.3;
			ADC_ConvertedValueLocal1[3] =(float) ADC_ConvertedValue_1[3]/4096*3.3;
			ADC_ConvertedValueLocal1[4] =(float) ADC_ConvertedValue_1[4]/4096*3.3;
			ADC_ConvertedValueLocal1[5] =(float) ADC_ConvertedValue_1[5]/4096*3.3;
			ADC_ConvertedValueLocal1[6] =(float) ADC_ConvertedValue_1[6]/4096*3.3;
			ADC_ConvertedValueLocal1[7] =(float) ADC_ConvertedValue_1[7]/4096*3.3;
		
//  			printf("\r\n CH0 = %f V \r\n",ADC_ConvertedValueLocal[0]);
//  			printf("\r\n CH1 = %f V \r\n",ADC_ConvertedValueLocal[1]);
//  			printf("\r\n CH2 = %f  \r\n",ADC_ConvertedValueLocal[2]);
// 			printf("\r\n CH3 = %f  \r\n",ADC_ConvertedValueLocal[3]);
// 			
// 			printf("\r\n CH4 = %f V \r\n",ADC_ConvertedValueLocal1[0]);
// 			printf("\r\n CH5 = %f V \r\n",ADC_ConvertedValueLocal1[1]);
// 			printf("\r\n CH6 = %f V \r\n",ADC_ConvertedValueLocal1[2]);
// 			printf("\r\n CH7 = %f V \r\n",ADC_ConvertedValueLocal1[3]);
// 			printf("\r\n CH8 = %f V \r\n",ADC_ConvertedValueLocal1[4]);
// 			printf("\r\n CH9 = %f V \r\n",ADC_ConvertedValueLocal1[5]);
// 			printf("\r\n CH10= %f V \r\n",ADC_ConvertedValueLocal1[6]);
// 			printf("\r\n CH11= %f V \r\n",ADC_ConvertedValueLocal1[7]);
		
		
// // 			printf("\r\n ×óÇ°ÂÖ = %d V \r\n",Left_Forward);
// // 			printf("\r\n ÓÒÇ°ÂÖ = %d V \r\n",Right_Forward);
// // 			printf("\r\n ×óºóÂÖ= %d V \r\n",Left_Backward);
// // 			printf("\r\n ÓÒºóÂÖ= %d V \r\n",Right_Backward);

		PWM_PA4();
		PWM_PA5();
		PWM_PA6();
		PWM_PA7();
 		if(ADC_ConvertedValueLocal[1]>Detect_Threshold)
 		{	
			if(ADC_ConvertedValueLocal[0]<Detect_Threshold)
				{
					Right_Forward=Desired_Number;
					Right_Backward=Desired_Number;
				}
				if(ADC_ConvertedValueLocal[2]<Detect_Threshold)
				{
					
					Left_Forward=Desired_Number;
					Left_Backward=Desired_Number;
				}
 		}
					
		
		if(TIM_GetFlagStatus(TIM6,TIM_FLAG_Update)&&ADC_ConvertedValueLocal1[0]<Detect_Threshold)
		{
			break;
		}
	
	}
	TIM_Cmd(TIM4,DISABLE);
	PWM_Init();
}

static void CAR_LEFT(void)
{
	Left_Forward=init_pwm;
	Left_Backward=init_pwm;
	Right_Forward=init_pwm;
	Right_Backward=init_pwm;
		PWM_PA0();
		PWM_PA5();
		PWM_PA6();
		PWM_PA3();
	TIM_Cmd(TIM4,ENABLE);
	TIM_ClearFlag(TIM6,TIM_FLAG_Update);
	TIM_SetCounter(TIM6,0x00);
	while(1){
			ADC_ConvertedValueLocal[0] =(float) ADC_ConvertedValue[0]/4096*3.3;
			ADC_ConvertedValueLocal[1] =(float) ADC_ConvertedValue[1]/4096*3.3;
			ADC_ConvertedValueLocal[2] =(float) ADC_ConvertedValue[2]/4096*3.3;
			ADC_ConvertedValueLocal[3] =(float) ADC_ConvertedValue[3]/4096*3.3;
		
			ADC_ConvertedValueLocal1[0] =(float) ADC_ConvertedValue_1[0]/4096*3.3;
			ADC_ConvertedValueLocal1[1] =(float) ADC_ConvertedValue_1[1]/4096*3.3;
			ADC_ConvertedValueLocal1[2] =(float) ADC_ConvertedValue_1[2]/4096*3.3;
			ADC_ConvertedValueLocal1[3] =(float) ADC_ConvertedValue_1[3]/4096*3.3;
			ADC_ConvertedValueLocal1[4] =(float) ADC_ConvertedValue_1[4]/4096*3.3;
			ADC_ConvertedValueLocal1[5] =(float) ADC_ConvertedValue_1[5]/4096*3.3;
			ADC_ConvertedValueLocal1[6] =(float) ADC_ConvertedValue_1[6]/4096*3.3;
			ADC_ConvertedValueLocal1[7] =(float) ADC_ConvertedValue_1[7]/4096*3.3;
		PWM_PA0();
		PWM_PA5();
		PWM_PA6();
		PWM_PA3();
		if(ADC_ConvertedValueLocal1[6]>Detect_Threshold)
		{
			if(ADC_ConvertedValueLocal1[7]<Detect_Threshold)
			{
				Left_Backward=Desired_Number;
				Right_Backward=Desired_Number;
			}
			if(ADC_ConvertedValueLocal1[5]<Detect_Threshold)
			{
				Left_Forward=Desired_Number;
				Right_Forward=Desired_Number;
			}
		}
		
		if(TIM_GetFlagStatus(TIM6,TIM_FLAG_Update)&&ADC_ConvertedValueLocal[1]<Detect_Threshold)
		{
			break;
		}
	}
	TIM_Cmd(TIM4,DISABLE);
	PWM_Init();
}

static void CAR_RIGHT(void)
{
	Left_Forward=init_pwm;
	Left_Backward=init_pwm;
	Right_Forward=init_pwm;
	Right_Backward=init_pwm;
		PWM_PA4();
		PWM_PA1();
		PWM_PA2();
		PWM_PA7();
	TIM_Cmd(TIM4,ENABLE);
	TIM_ClearFlag(TIM6,TIM_FLAG_Update);
	TIM_SetCounter(TIM6,0x00);
	while(1){
			ADC_ConvertedValueLocal[0] =(float) ADC_ConvertedValue[0]/4096*3.3;
			ADC_ConvertedValueLocal[1] =(float) ADC_ConvertedValue[1]/4096*3.3;
			ADC_ConvertedValueLocal[2] =(float) ADC_ConvertedValue[2]/4096*3.3;
			ADC_ConvertedValueLocal[3] =(float) ADC_ConvertedValue[3]/4096*3.3;
		
			ADC_ConvertedValueLocal1[0] =(float) ADC_ConvertedValue_1[0]/4096*3.3;
			ADC_ConvertedValueLocal1[1] =(float) ADC_ConvertedValue_1[1]/4096*3.3;
			ADC_ConvertedValueLocal1[2] =(float) ADC_ConvertedValue_1[2]/4096*3.3;
			ADC_ConvertedValueLocal1[3] =(float) ADC_ConvertedValue_1[3]/4096*3.3;
			ADC_ConvertedValueLocal1[4] =(float) ADC_ConvertedValue_1[4]/4096*3.3;
			ADC_ConvertedValueLocal1[5] =(float) ADC_ConvertedValue_1[5]/4096*3.3;
			ADC_ConvertedValueLocal1[6] =(float) ADC_ConvertedValue_1[6]/4096*3.3;
			ADC_ConvertedValueLocal1[7] =(float) ADC_ConvertedValue_1[7]/4096*3.3;
		PWM_PA4();
		PWM_PA1();
		PWM_PA2();
		PWM_PA7();
		if(ADC_ConvertedValueLocal1[0]>Detect_Threshold)
		{
			if(ADC_ConvertedValueLocal[3]<Detect_Threshold)
			{
				Left_Backward=Desired_Number;
				Right_Backward=Desired_Number;
			}
			if(ADC_ConvertedValueLocal1[1]<Detect_Threshold)
			{
				Left_Forward=Desired_Number;
				Right_Forward=Desired_Number;
			}
		}
		
		if(TIM_GetFlagStatus(TIM6,TIM_FLAG_Update)&&ADC_ConvertedValueLocal[1]<Detect_Threshold)
		{
			break;
		}
	}
	TIM_Cmd(TIM4,DISABLE);
	PWM_Init();
}

void CAR_Go(u8 step)
{
	u8 i=0;
	for(;i<step;i++)
	{
		CAR_GO();
	}
}

void CAR_Down(u8 step)
{
	u8 i=0;
	for(;i<step;i++)
	{
		CAR_DOWN();
	}
}

void CAR_Left(u8 step)
{
	u8 i=0;
	for(;i<step;i++)
	{
		CAR_LEFT();
	}
}

void CAR_Right(u8 step)
{
	u8 i=0;
	for(;i<step;i++)
	{
		CAR_RIGHT();
	}
}

