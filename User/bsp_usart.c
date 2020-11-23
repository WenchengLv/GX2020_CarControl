#include "bsp_usart.h"

static void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  /* ???????????? */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  
  /* ??USART???? */
  NVIC_InitStructure.NVIC_IRQChannel = DEBUG_USART_IRQ;
  /* ?????*/
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  /* ???? */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  /* ???? */
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  /* ?????NVIC */
  NVIC_Init(&NVIC_InitStructure);
}

void USART_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	// ????GPIO???
	DEBUG_USART_GPIO_APBxClkCmd(DEBUG_USART_GPIO_CLK, ENABLE);
	
	// ?????????
	DEBUG_USART_APBxClkCmd(DEBUG_USART_CLK, ENABLE);

	// ?USART Tx?GPIO?????????
	GPIO_InitStructure.GPIO_Pin = DEBUG_USART_TX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEBUG_USART_TX_GPIO_PORT, &GPIO_InitStructure);

  // ?USART Rx?GPIO?????????
	GPIO_InitStructure.GPIO_Pin = DEBUG_USART_RX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(DEBUG_USART_RX_GPIO_PORT, &GPIO_InitStructure);
	
	// ?????????
	// ?????
	USART_InitStructure.USART_BaudRate = DEBUG_USART_BAUDRATE;
	// ?? ?????
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	// ?????
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	// ?????
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	// ???????
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	// ??????,????
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	// ??????????
	USART_Init(DEBUG_USARTx, &USART_InitStructure);
	
	// ?????????
	NVIC_Configuration();
	
	// ????????
	USART_ITConfig(DEBUG_USARTx, USART_IT_RXNE, ENABLE);	
	
	// ????
	USART_Cmd(DEBUG_USARTx, ENABLE);	    
}

/* ?????? */
void Usart_SendByte(USART_TypeDef* pUSARTx, uint8_t data)
{
	USART_SendData(pUSARTx, data);
	while( USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET );
}

/* ????????? */
void Usart_SendHalfWord(USART_TypeDef* pUSARTx, uint16_t data)
{
	uint8_t temp_h,temp_l;
	
	temp_h = (data&0xff00) >> 8 ;
	temp_l = data&0xff;
	
	USART_SendData(pUSARTx, temp_h);
	while( USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET );
	
	USART_SendData(pUSARTx, temp_l);
	while( USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET );
}

/* ??8?????? */
void Usart_SendArray(USART_TypeDef* pUSARTx, uint8_t *array,uint8_t num)
{
	uint8_t i;
	for( i=0; i<num; i++ )
  {
		Usart_SendByte(pUSARTx, array[i]);
	}
	while( USART_GetFlagStatus(pUSARTx, USART_FLAG_TC) == RESET );
}

/* ????? */
void Usart_SendStr(USART_TypeDef* pUSARTx, uint8_t *str)
{
	uint8_t i=0;
	do
  {
		Usart_SendByte(pUSARTx, *(str+i));
		i++;
	}while(*(str+i) != '\0');
	while( USART_GetFlagStatus(pUSARTx, USART_FLAG_TC) == RESET );
}

///???c???printf???,???????printf??
int fputc(int ch, FILE *f)
{
		/* ??????????? */
		USART_SendData(DEBUG_USARTx, (uint8_t) ch);
		
		/* ?????? */
		while (USART_GetFlagStatus(DEBUG_USARTx, USART_FLAG_TXE) == RESET);		
	
		return (ch);
}

///???c???scanf???,???????scanf?getchar???
int fgetc(FILE *f)
{
		/* ???????? */
		while (USART_GetFlagStatus(DEBUG_USARTx, USART_FLAG_RXNE) == RESET);

		return (int)USART_ReceiveData(DEBUG_USARTx);
}
