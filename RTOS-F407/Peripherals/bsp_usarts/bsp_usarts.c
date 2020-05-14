#include "bsp_usarts.h"


static void Debug_USART_Config(void){
	
  GPIO_InitTypeDef   GPIO_InitStructure;
  USART_InitTypeDef  USART_InitStructure;
		
  RCC_AHB1PeriphClockCmd( DEBUG_USART_RX_GPIO_CLK |DEBUG_USART_TX_GPIO_CLK, ENABLE);
 
  RCC_APB2PeriphClockCmd(DEBUG_USART_CLK, ENABLE);																			/* ʹ�� UART ʱ�� */
 
  GPIO_PinAFConfig(DEBUG_USART_RX_GPIO_PORT,DEBUG_USART_RX_SOURCE, DEBUG_USART_RX_AF);	/* ���� PXx �� USARTx_Tx*/
 
  GPIO_PinAFConfig(DEBUG_USART_TX_GPIO_PORT,DEBUG_USART_TX_SOURCE, DEBUG_USART_TX_AF);	/* ���� PXx �� USARTx__Rx*/
 
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;  																			/* ����Tx����Ϊ���ù���  */
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;

  GPIO_InitStructure.GPIO_Pin   = DEBUG_USART_TX_PIN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(DEBUG_USART_TX_GPIO_PORT, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;   																			/* ����Rx����Ϊ���ù��� */
  GPIO_InitStructure.GPIO_Pin   = DEBUG_USART_RX_PIN;
  GPIO_Init(DEBUG_USART_RX_GPIO_PORT, &GPIO_InitStructure);
  
  USART_InitStructure.USART_BaudRate   = DEBUG_USART_BAUDRATE; 													/* ���ô�DEBUG_USART ģʽ */
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits   = USART_StopBits_1;
  USART_InitStructure.USART_Parity     = USART_Parity_No ;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode       = USART_Mode_Rx | USART_Mode_Tx;
  USART_Init(DEBUG_USART, &USART_InitStructure); 
  
	USART_Cmd(DEBUG_USART, ENABLE);
	
}


static void NVIC_Configuration(void){
	
  NVIC_InitTypeDef NVIC_InitStructure;
  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);											/* Ƕ�������жϿ�������ѡ�� */
  
  NVIC_InitStructure.NVIC_IRQChannel 									 = USART1_IRQn;	/* ����USARTΪ�ж�Դ */
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;					 	/* �������ȼ�Ϊ1 */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority 			 = 1;						/* �����ȼ�Ϊ1 */
  NVIC_InitStructure.NVIC_IRQChannelCmd								 = ENABLE;			/* ʹ���ж� */
  
  NVIC_Init(&NVIC_InitStructure);																			/* ��ʼ������NVIC */

}


void usart1_config(void){
	
	Debug_USART_Config();
	NVIC_Configuration();
	
}


void USART_Send_Bytes(USART_TypeDef* USARTx, u8* Data,u8 size){
  u8 i=0;
  for(i=0;i<size;i++){
    USART_SendData(USARTx,*Data++);
    while(USART_GetFlagStatus(USARTx,USART_FLAG_TXE) == RESET);
  }
}


void DEBUG_USART_Send_Bytes(uint8_t* pData, uint16_t DataLen){
 
	vTaskSuspendAll();
	USART_Send_Bytes(DEBUG_USART,pData,DataLen);
	xTaskResumeAll ();
	
}

void  USART1_IRQHandler(void){
	
  uint8_t ucTemp;

	if(USART_GetITStatus(DEBUG_USART,USART_IT_RXNE) != RESET){		
		ucTemp = USART_ReceiveData( DEBUG_USART );
    //USART_SendData(DEBUG_USART,ucTemp);    
	}

}	
 

///�ض���c�⺯��printf������DEBUG_USART���ض�����ʹ��printf����
int fputc(int ch, FILE *f){
	
	/* ����һ���ֽ����ݵ�����DEBUG_USART */
	USART_SendData(DEBUG_USART, (uint8_t) ch);
	
	/* �ȴ�������� */
	while (USART_GetFlagStatus(DEBUG_USART, USART_FLAG_TXE) == RESET);		

	return (ch);
	
}

///�ض���c�⺯��scanf������DEBUG_USART����д����ʹ��scanf��getchar�Ⱥ���
int fgetc(FILE *f){
	
	/* �ȴ������������� */
	while (USART_GetFlagStatus(DEBUG_USART, USART_FLAG_RXNE) == RESET);

	return (int)USART_ReceiveData(DEBUG_USART);
	
}

/*********************************************END OF FILE**********************/
