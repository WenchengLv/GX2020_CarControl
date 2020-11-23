#include "bsp_adc.h"

__IO uint32_t ADC_ConvertedValue[NOFCHANEL1] = {0};
__IO uint32_t ADC_ConvertedValue3[NOFCHANEL3] = {0};
/**
  * @brief  ADC GPIO ???
  * @param  ?
  * @retval ?
  */
static void ADCx_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// ADCx_1 GPIO ???
	ADCx_1_GPIO_APBxClock_FUN ( ADCx_1_GPIO_CLK1, ENABLE );
	ADCx_1_GPIO_APBxClock_FUN ( ADCx_1_GPIO_CLK2, ENABLE );
	GPIO_InitStructure.GPIO_Pin = ADCx_1_PIN0|
	                              ADCx_1_PIN1|
	                              ADCx_1_PIN2|
	                              ADCx_1_PIN3|
	                              ADCx_1_PIN4|
	                              ADCx_1_PIN5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(ADCx_1_PORT1, &GPIO_InitStructure);
	
	ADCx_1_GPIO_APBxClock_FUN ( ADCx_1_GPIO_CLK1, ENABLE );
	ADCx_1_GPIO_APBxClock_FUN ( ADCx_1_GPIO_CLK2, ENABLE );
	GPIO_InitStructure.GPIO_Pin = ADCx_1_PIN4|
	                              ADCx_1_PIN5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(ADCx_1_PORT2, &GPIO_InitStructure);

	// ADCx_2 GPIO ???
	ADCx_1_GPIO_APBxClock_FUN ( ADCx_1_GPIO_CLK2, ENABLE );
	GPIO_InitStructure.GPIO_Pin = ADCx_3_PIN6|
	                              ADCx_3_PIN7|
		                            ADCx_3_PIN8|
		                            ADCx_3_PIN9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(ADCx_3_PORT, &GPIO_InitStructure);	
}

/**
  * @brief  ??ADC????
  * @param  ?
  * @retval ?
  */
static void ADCx_Mode_Config(void)
{
	DMA_InitTypeDef DMA_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	
	// ??DMA??
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	// ??ADC??
	ADCx_1_APBxClock_FUN ( ADCx_1_CLK, ENABLE );
	ADCx_3_APBxClock_FUN ( ADCx_3_CLK, ENABLE );
	
  /* ------------------DMA????---------------- */	
	// ??DMA???
	DMA_DeInit(ADC_DMA_CHANNEL);	
	// ?? DMA ??????
	// ?????:ADC ???????
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&( ADCx_1->DR ));	
	// ?????
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)ADC_ConvertedValue;	
	// ???????
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;	
	// ?????,????????????
	DMA_InitStructure.DMA_BufferSize = NOFCHANEL1;	
	// ?????????,??????
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	// ???????
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable; 	
	// ??????
	DMA_InitStructure.DMA_PeripheralDataSize = 
	                                  DMA_PeripheralDataSize_Word;	
	// ??????,?????????
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;	
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
	
	  /* ------------------DMA3????---------------- */	
	// ??DMA???
	DMA_DeInit(ADC_3_DMA_CHANNEL);	
	// ?? DMA ??????
	// ?????:ADC ???????
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&( ADCx_3->DR ));	
	// ?????
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)ADC_ConvertedValue3;	
	// ???????
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;	
	// ?????,????????????
	DMA_InitStructure.DMA_BufferSize = NOFCHANEL3;	
	// ?????????,??????
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	// ???????
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable; 	
	// ??????
	DMA_InitStructure.DMA_PeripheralDataSize = 
	                                  DMA_PeripheralDataSize_Word;	
	// ??????,?????????
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;	
	// ??????
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;	
	// DMA ?????????,?????DMA???,????????
	DMA_InitStructure.DMA_Priority = DMA_Priority_Low;	
	// ???????????,??????????
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;	
	// ???DMA
	DMA_Init(ADC_3_DMA_CHANNEL, &DMA_InitStructure);	
	// ?? DMA ??
	DMA_Cmd(ADC_3_DMA_CHANNEL , ENABLE);
	
	
	
	/* ----------------ADCx_1 ????--------------------- */
	// ?ADC?????
	ADC_InitStructure.ADC_Mode = ADC_Mode_RegSimult;	
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
	ADC_Init(ADCx_1, &ADC_InitStructure);	
	// ??ADC??N?CLK2?8??,?9MHz
	RCC_ADCCLKConfig(RCC_PCLK2_Div8); 	
	// ??ADC ????????????
	ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 1, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 2, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 3, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 4, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_12, 5, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 6, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_14, 7, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_15, 7, ADC_SampleTime_55Cycles5);
	// ??ADC DMA ??
	ADC_DMACmd(ADCx_1, ENABLE);
	
	
		/* ----------------ADCx_2 ????--------------------- */
	// ?ADC?????
	ADC_InitStructure.ADC_Mode = ADC_Mode_RegSimult;	
	// ????
	ADC_InitStructure.ADC_ScanConvMode = ENABLE ; 
	// ??????
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	// ????????,??????
	ADC_InitStructure.ADC_ExternalTrigConv = 
	                           ADC_ExternalTrigConv_None;
	// ???????
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	
	// ??????
	ADC_InitStructure.ADC_NbrOfChannel = NOFCHANEL3;			
	// ???ADC
	ADC_Init(ADCx_3, &ADC_InitStructure);	
	// ??ADC???PCLK2?8??,?9MHz
	RCC_ADCCLKConfig(RCC_PCLK2_Div8); 	
	// ??ADC ????????????
	ADC_RegularChannelConfig(ADC3, ADC_Channel_4, 1, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC3, ADC_Channel_5, 2, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC3, ADC_Channel_6, 3, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC3, ADC_Channel_7, 4, ADC_SampleTime_55Cycles5);

	/* ??ADCx_2??????? */
  ADC_ExternalTrigConvCmd(ADC2, ENABLE);
	
	/* ----------------ADCx_1 ??--------------------- */
	// ??ADC ,?????
	ADC_Cmd(ADCx_1, ENABLE);	
	// ???ADC ?????  
	ADC_ResetCalibration(ADCx_1);
	// ????????????
	while(ADC_GetResetCalibrationStatus(ADCx_1));	
	// ADC????
	ADC_StartCalibration(ADCx_1);
	// ??????
	while(ADC_GetCalibrationStatus(ADCx_1));
	
  /* ----------------ADCx_2 ??--------------------- */
		// ??ADC ,?????
	ADC_Cmd(ADCx_3, ENABLE);	
	// ???ADC ?????  
	ADC_ResetCalibration(ADCx_3);
	// ????????????
	while(ADC_GetResetCalibrationStatus(ADCx_3));	
	// ADC????
	ADC_StartCalibration(ADCx_3);
	// ??????
	while(ADC_GetCalibrationStatus(ADCx_3));

	// ??????????,????????ADC?? 
	ADC_SoftwareStartConvCmd(ADCx_1, ENABLE);
	ADC_SoftwareStartConvCmd(ADCx_3, ENABLE);
}

/**
  * @brief  ADC???
  * @param  ?
  * @retval ?
  */
void ADCx_Init(void)
{
	ADCx_GPIO_Config();
	ADCx_Mode_Config();
}
/*********************************************END OF FILE**********************/
