#include "bsp_adc.h"

__IO uint16_t ADC_ConvertedValue[NOFCHANEL]={0};
__IO uint16_t ADC_ConvertedValue_1[NOFCHANEL1]={0};


static void ADCx_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// ?? ADC IO????
	ADC_GPIO_APBxClock_FUN ( ADC_GPIO_CLK, ENABLE );
	
	// ?? ADC IO ????
	GPIO_InitStructure.GPIO_Pin = 	  ADC_PIN0|
	                                  ADC_PIN1|
																		ADC_PIN2|
																		ADC_PIN3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	
	// ??? ADC IO
	GPIO_Init(ADC_PORT, &GPIO_InitStructure);				
}

static void ADCx_1_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// ?? ADC IO????
	ADC_GPIO_APBxClock_FUN (ADC_1_GPIO_CLK, ENABLE);
	
	// ?? ADC IO ????
	GPIO_InitStructure.GPIO_Pin = 	ADC_1_PIN0|
	                                ADC_1_PIN1|
																	ADC_1_PIN2|
		                              ADC_1_PIN3|
		                              ADC_1_PIN4|
		                              ADC_1_PIN5;

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	
	// ??? ADC IO
	GPIO_Init(ADC_1_PORT, &GPIO_InitStructure);				
}

static void ADCx_1_2_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// ?? ADC IO????
	ADC_GPIO_APBxClock_FUN (ADC_1_GPIO_CLK, ENABLE);
	
	// ?? ADC IO ????
	GPIO_InitStructure.GPIO_Pin = 	ADC_1_PIN6|
	                                ADC_1_PIN7;

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	
	// ??? ADC IO
	GPIO_Init(ADC_1_2_PORT, &GPIO_InitStructure);				
}

static void ADCx_Mode_Config(void)
{
	DMA_InitTypeDef DMA_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	
	// ??DMA??
	RCC_AHBPeriphClockCmd(ADC_DMA_CLK, ENABLE);
	// ??ADC??
	ADC_APBxClock_FUN (ADC_CLK, ENABLE );
	
	// ??DMA???
	DMA_DeInit(ADC_DMA_CHANNEL);
	
	// ?? DMA ??????
	// ?????:ADC ???????
	DMA_InitStructure.DMA_PeripheralBaseAddr = ( u32 ) ( & ( ADC_x->DR ) );
	
	// ?????
	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)ADC_ConvertedValue;
	
	// ???????
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	
	// ?????,????????????
	DMA_InitStructure.DMA_BufferSize = NOFCHANEL;
	
	// ?????????,??????
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;

	// ???????
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable; 
	
	// ?????????,?????
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	
	// ??????????,?????????
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	
	// ??????
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;	

	// DMA ?????????,?????DMA???,????????
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	
	// ???????????,??????????
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	
	// ???DMA
	DMA_Init(ADC_DMA_CHANNEL, &DMA_InitStructure);
	
	// ?? DMA ??
	DMA_Cmd(ADC_DMA_CHANNEL , ENABLE);
	
	// ADC ????
	// ?????ADC,?????
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	
	// ????
	ADC_InitStructure.ADC_ScanConvMode = ENABLE ; 

	// ??????
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;

	// ????????,??????
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;

	// ???????
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	
	// ??????
	ADC_InitStructure.ADC_NbrOfChannel = NOFCHANEL;	
		
	// ???ADC
	ADC_Init(ADC_x, &ADC_InitStructure);
	
	// ??ADC??N?CLK2?8??,?9MHz
	RCC_ADCCLKConfig(RCC_PCLK2_Div8); 
	
	// ??ADC ????????????
	ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL1, 1, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL2, 2, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL3, 3, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL4, 4, ADC_SampleTime_55Cycles5);
//	ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL5, 5, ADC_SampleTime_55Cycles5);
//	ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL6, 6, ADC_SampleTime_55Cycles5);
//	ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL7, 7, ADC_SampleTime_55Cycles5);
//	ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL8, 8, ADC_SampleTime_55Cycles5);
	
	// ??ADC DMA ??
	ADC_DMACmd(ADC_x, ENABLE);
	
	// ??ADC ,?????
	ADC_Cmd(ADC_x, ENABLE);
	
	// ???ADC ?????  
	ADC_ResetCalibration(ADC_x);
	// ????????????
	while(ADC_GetResetCalibrationStatus(ADC_x));
	
	// ADC????
	ADC_StartCalibration(ADC_x);
	// ??????
	while(ADC_GetCalibrationStatus(ADC_x));
	
	// ??????????,????????ADC?? 
	ADC_SoftwareStartConvCmd(ADC_x, ENABLE);
}

static void ADCx_1_Mode_Config(void)
{
	DMA_InitTypeDef DMA_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	
	// ??DMA??
	RCC_AHBPeriphClockCmd(ADC_1_DMA_CLK, ENABLE);
	// ??ADC??
	ADC_APBxClock_FUN ( ADC_1_CLK, ENABLE );
	
	// ??DMA???
	DMA_DeInit(ADC_1_DMA_CHANNEL);
	
	// ?? DMA ??????
	// ?????:ADC ???????
	DMA_InitStructure.DMA_PeripheralBaseAddr = ( u32 ) ( & ( ADC_1_x->DR ) );
	
	// ?????
	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)ADC_ConvertedValue_1;
	
	// ???????
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	
	// ?????,????????????
	DMA_InitStructure.DMA_BufferSize = NOFCHANEL1;
	
	// ?????????,??????
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;

	// ???????
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable; 
	
	// ?????????,?????
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	
	// ??????????,?????????
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	
	// ??????
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;	

	// DMA ?????????,?????DMA???,????????
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	
	// ???????????,??????????
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	
	// ???DMA
	DMA_Init(ADC_1_DMA_CHANNEL, &DMA_InitStructure);
	
	// ?? DMA ??
	DMA_Cmd(ADC_1_DMA_CHANNEL , ENABLE);
	
	// ADC ????
	// ?????ADC,?????
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	
	// ????
	ADC_InitStructure.ADC_ScanConvMode = ENABLE ; 

	// ??????
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;

	// ????????,??????
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;

	// ???????
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	
	// ??????
	ADC_InitStructure.ADC_NbrOfChannel = NOFCHANEL1;	
		
	// ???ADC
	ADC_Init(ADC_1_x, &ADC_InitStructure);
	
	// ??ADC??N?CLK2?8??,?9MHz
	RCC_ADCCLKConfig(RCC_PCLK2_Div8); 
	
	// ??ADC ????????????
	ADC_RegularChannelConfig(ADC_1_x, ADC_1_CHANNEL1, 1, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC_1_x, ADC_1_CHANNEL2, 2, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC_1_x, ADC_1_CHANNEL3, 3, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC_1_x, ADC_1_CHANNEL4, 4, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC_1_x, ADC_1_CHANNEL5, 5, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC_1_x, ADC_1_CHANNEL6, 6, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC_1_x, ADC_1_CHANNEL7, 7, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC_1_x, ADC_1_CHANNEL8, 8, ADC_SampleTime_55Cycles5);

	
	// ??ADC DMA ??
	ADC_DMACmd(ADC_1_x, ENABLE);
	
	// ??ADC ,?????
	ADC_Cmd(ADC_1_x, ENABLE);
	
	// ???ADC ?????  
	ADC_ResetCalibration(ADC_1_x);
	// ????????????
	while(ADC_GetResetCalibrationStatus(ADC_1_x));
	
	// ADC????
	ADC_StartCalibration(ADC_1_x);
	// ??????
	while(ADC_GetCalibrationStatus(ADC_1_x));
	
	// ??????????,????????ADC?? 
	ADC_SoftwareStartConvCmd(ADC_1_x, ENABLE);
}

/**
  * @brief  ADC???
  */
void ADCx_Init(void)
{
	ADCx_GPIO_Config();
	ADCx_Mode_Config();
	ADCx_1_GPIO_Config();
	ADCx_1_2_GPIO_Config();
	ADCx_1_Mode_Config();
}

/*********************************************END OF FILE**********************/
