/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "bsp_usart.h"
#include "bsp_GeneralTim.h" 
#include "car.h"

extern u16 Left_Forward;
extern u16 Left_Backward;
extern u16 Right_Forward;
extern u16 Right_Backward;

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}



void DEBUG_USART_IRQHandler(void)
{
	u8 dir=0;
	u8 d=0;
	u8 d1=0;
	u8 d2=0;
  dir = getchar();
     d=getchar();		
     printf("dir=%c\n",dir);
     
     d1=chartonumber(d);
	d2=getchar();	
		 printf("d1=%d\n",d1);
		switch(dir)
   {
			case 'A': CAR_Go(d1);break;
      case 'B': CAR_Down(d1);break;
		  case 'C': CAR_Left(d1);break;
		  case 'D': CAR_Right(d1);break;
	 }

}

u8 state_A=0;
u8 state_B=0;
u8 state_C=0;
u8 state_D=0;
u16  timecount=0;
u16  timecount1=0;
u16  test=0;
u16  timecount_B=0;
u16  timecount1_B=0;
u16  test_B=0;

u16  timecount_C=0;
u16  timecount1_C=0;
u16  test_C=0;

u16  timecount_D=0;
u16  timecount1_D=0;
u16  test_D=0;

u16 desired_v=3000;    //11250
u16  PID_P=10;

void Delay_it(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 

void TIM4_IRQHandler(void)
{
	TIM_ClearFlag(TIM4,TIM_FLAG_Update);
	if ( TIM_GetITStatus (TIM4, TIM_IT_CC1 ) != RESET)
	{
       TIM_ClearITPendingBit(TIM4, TIM_IT_CC1);    //???????
       if(state_A==0)    //????????
       {
           state_A=1;
           timecount=TIM_GetCapture1(TIM4);        //?????????CNT?
       }
       else if(state_A==1)//????????
       {
				 u16 error=0;
				 u16 fix_bug;
           state_A=0;
           timecount1=TIM_GetCapture1(TIM4);   //?????????CNT?
           if(timecount<timecount1)
           {
                 test=timecount1-timecount;           //????????
           }
           else
           {
                 test=(0xffff-timecount)+timecount1;  //????????
           }
								 
						if(test>desired_v)
						{
							error=test-desired_v;

							fix_bug = Left_Forward+error/PID_P;
						}else
						{
							error=desired_v-test;
							//Left_Forward = Left_Forward-error/PID_P;
							fix_bug = Left_Forward-error/PID_P;
						}
						if(fix_bug>5000)
						{
							Left_Forward=5000;
						}else
						{
							Left_Forward=fix_bug;
						}
						
						//printf("\r\nA=%d\r\n",test);
						//printf("\r\nA_PWM=%d\r\n",Left_Forward);
						
       }
   }
	 if ( TIM_GetITStatus (TIM4, TIM_IT_CC2 ) != RESET)
	{
       TIM_ClearITPendingBit(TIM4, TIM_IT_CC2);    //???????
       if(state_B==0)    //????????
       {
           state_B=1;
           timecount_B=TIM_GetCapture2(TIM4);        //?????????CNT?
       }
       else if(state_B==1)//????????
       {
					u16 fix_bug=0;
				 u16 error=0;
           state_B=0;
				 
           timecount1_B=TIM_GetCapture2(TIM4);   //?????????CNT?
           if(timecount_B<timecount1_B)
           {
                 test_B=timecount1_B-timecount_B;           //????????
           }
           else
           {
                 test_B=(0xffff-timecount_B)+timecount1_B;  //????????
           }
								 
						if(test_B>desired_v)
						{
							error=test_B-desired_v;
							fix_bug=Right_Forward+error/PID_P;
						}else
						{
							error=desired_v-test_B;
							fix_bug=Right_Forward-error/PID_P;
						}
	
						if(fix_bug>5000)
						{
							Right_Forward=5000;
						}else
						{
							Right_Forward=fix_bug;
						}
							
						//printf("\r\nB =%d\r\n",test_B);
						//printf("\r\nB =%d\r\n",Right_Forward);
      
       }
   }
	 
	 if ( TIM_GetITStatus (TIM4, TIM_IT_CC3 ) != RESET)
	{
		
       TIM_ClearITPendingBit(TIM4, TIM_IT_CC3);    //???????
       if(state_C==0)    //????????
       {
           state_C=1;
           timecount_C=TIM_GetCapture3(TIM4);        //?????????CNT?
       }
       else if(state_C==1)//????????
       {
				 u16 error=0;
           state_C=0;
           timecount1_C=TIM_GetCapture3(TIM4);   //?????????CNT?
           if(timecount_C<timecount1_C)
           {
                 test_C=timecount1_C-timecount_C;           //????????
           }
           else
           {
                 test_C=(0xffff-timecount_C)+timecount1_C;  //????????
           }
					 		 
						if(test_C>desired_v)
						{
							error=test_C-desired_v;
							Left_Backward=Left_Backward+error/PID_P;
						}else
						{
							error=desired_v-test_C;
							Left_Backward=Left_Backward-error/PID_P;
						}  
						//printf("\r\nC= %d\r\n",test_C);
						//printf("\r\n PWM_A = %d V \r\n",Left_Backward);
       }
   }
	 
	 if ( TIM_GetITStatus (TIM4, TIM_IT_CC4 ) != RESET)
	{
       TIM_ClearITPendingBit(TIM4, TIM_IT_CC4);    //???????
       if(state_D==0)    //????????
       {
           state_D=1;
           timecount_D=TIM_GetCapture4(TIM4);        //?????????CNT?
       }
       else if(state_D==1)//????????
       {
				 u16 error=0;	
           state_D=0;
           timecount1_D=TIM_GetCapture4(TIM4);   //?????????CNT?
           if(timecount_D<timecount1_D)
           {
                 test_D=timecount1_D-timecount_D;           //????????
           }
           else
           {
                 test_D=(0xffff-timecount_D)+timecount1_D;  //????????
           }
           	 
						if(test_D>desired_v)
						{
							error=test_D-desired_v;
							Right_Backward=Right_Backward+error/PID_P;
						}else
						{
							error=desired_v-test_D;
							Right_Backward=Right_Backward-error/PID_P;
						}  
					//printf("\r\nD =%d\r\n",test_D);
       }
   }
   
}


/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
