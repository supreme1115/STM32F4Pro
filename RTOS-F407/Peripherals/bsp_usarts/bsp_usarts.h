#ifndef __BSP_USARTS_H_
#define	__BSP_USARTS_H_

#include "stm32f4xx.h"
#include <stdio.h>
#include "ymodem.h"

#include "parameters.h"

#define 	DEBUG_USART									USART1
#define 	DEBUG_USART_CLK							RCC_APB2Periph_USART1

#define 	DEBUG_USART_RX_GPIO_PORT		GPIOA
#define 	DEBUG_USART_RX_GPIO_CLK			RCC_AHB1Periph_GPIOA
#define 	DEBUG_USART_RX_PIN					GPIO_Pin_10
#define 	DEBUG_USART_RX_AF						GPIO_AF_USART1
#define 	DEBUG_USART_RX_SOURCE				GPIO_PinSource10

#define 	DEBUG_USART_TX_GPIO_PORT		GPIOA
#define 	DEBUG_USART_TX_GPIO_CLK			RCC_AHB1Periph_GPIOA
#define 	DEBUG_USART_TX_PIN					GPIO_Pin_9
#define 	DEBUG_USART_TX_AF						GPIO_AF_USART1
#define 	DEBUG_USART_TX_SOURCE				GPIO_PinSource9
 
#define 	DEBUG_USART_BAUDRATE				115200
 
void usart1_config(void);

void USART_Send_Bytes(USART_TypeDef* USARTx, u8* Data,u8 size);
void DEBUG_USART_Send_Bytes(uint8_t* pData, uint16_t DataLen);

#endif /* __USART1_H */
