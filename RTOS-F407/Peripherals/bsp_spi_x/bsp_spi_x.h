#ifndef __BSP_SPI_X_H_
#define __BSP_SPI_X_H_

#include "stm32f4xx.h"
#include <stdio.h>

#define  	sFLASH_ID								0XEF4018     

#define 	x1_SPI									SPI1
#define 	x1_SPI_CLK							RCC_APB2Periph_SPI1
#define 	FLASH_SPI_CLK_INIT			RCC_APB2PeriphClockCmd

#define 	x1_SPI_SCK_PIN					GPIO_Pin_3                  
#define 	x1_SPI_SCK_GPIO_PORT		GPIOB                       
#define 	x1_SPI_SCK_GPIO_CLK			RCC_AHB1Periph_GPIOB
#define 	x1_SPI_SCK_PINSOURCE		GPIO_PinSource3
#define 	x1_SPI_SCK_AF						GPIO_AF_SPI1

#define 	x1_SPI_MISO_PIN					GPIO_Pin_4                
#define 	x1_SPI_MISO_GPIO_PORT		GPIOB                   
#define 	x1_SPI_MISO_GPIO_CLK		RCC_AHB1Periph_GPIOB
#define 	x1_SPI_MISO_PINSOURCE		GPIO_PinSource4
#define 	x1_SPI_MISO_AF					GPIO_AF_SPI1

#define 	x1_SPI_MOSI_PIN					GPIO_Pin_5                
#define 	x1_SPI_MOSI_GPIO_PORT		GPIOB                     
#define 	x1_SPI_MOSI_GPIO_CLK		RCC_AHB1Periph_GPIOB
#define 	x1_SPI_MOSI_PINSOURCE		GPIO_PinSource5
#define 	x1_SPI_MOSI_AF					GPIO_AF_SPI1

#define 	x1_CS_PIN								GPIO_Pin_6               
#define 	x1_CS_GPIO_PORT					GPIOG                     
#define 	x1_CS_GPIO_CLK					RCC_AHB1Periph_GPIOG

#define 	SPI_FLASH_CS_LOW()			{x1_CS_GPIO_PORT->BSRRH=x1_CS_PIN;}
#define 	SPI_FLASH_CS_HIGH()     {x1_CS_GPIO_PORT->BSRRL=x1_CS_PIN;}
 

#define 	FLASH_DEBUG_ON         	1

#define 	FLASH_INFO(fmt,arg...)			printf("<<-FLASH-INFO->> "fmt"\n",##arg)
#define 	FLASH_ERROR(fmt,arg...)			printf("<<-FLASH-ERROR->> "fmt"\n",##arg)
#define 	FLASH_DEBUG(fmt,arg...)			do{\
																				if(FLASH_DEBUG_ON)\
                                          printf("<<-FLASH-DEBUG->> [%d]"fmt"\n",__LINE__, ##arg);\
																			}while(0)

void SPI_FLASH_Init(void);

#endif

