#ifndef __BSP_GPIO_H_
#define	__BSP_GPIO_H_

#include "stm32f4xx.h"


#define 	LED1_PIN					GPIO_Pin_9                
#define 	LED1_GPIO_PORT		GPIOF                      
#define 	LED1_GPIO_CLK			RCC_AHB1Periph_GPIOF
 
#define 	LED2_PIN					GPIO_Pin_10                
#define 	LED2_GPIO_PORT		GPIOF                      
#define 	LED2_GPIO_CLK			RCC_AHB1Periph_GPIOF
 
#define 	LED3_PIN					GPIO_Pin_8                 
#define 	LED3_GPIO_PORT		GPIOF                       
#define 	LED3_GPIO_CLK			RCC_AHB1Periph_GPIOF
 
#define 	ON  	0
#define 	OFF 	1


#define LED1(a)	if (a)	\
					GPIO_SetBits(LED1_GPIO_PORT,LED1_PIN);\
					else		\
					GPIO_ResetBits(LED1_GPIO_PORT,LED1_PIN)

#define LED2(a)	if (a)	\
					GPIO_SetBits(LED2_GPIO_PORT,LED2_PIN);\
					else		\
					GPIO_ResetBits(LED2_GPIO_PORT,LED2_PIN)

#define LED3(a)	if (a)	\
					GPIO_SetBits(LED3_GPIO_PORT,LED3_PIN);\
					else		\
					GPIO_ResetBits(LED3_GPIO_PORT,LED3_PIN)
 
void LED_GPIO_Config(void);

#endif
