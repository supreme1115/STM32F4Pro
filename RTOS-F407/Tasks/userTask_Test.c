#include "userTask_Test.h"

static void  userTest_func(void *pvParameters);

TaskHandle_t userTestHandle = NULL;

void create_userTest_Task(void){

	xTaskCreate(	userTest_func,    			/* 任务函数  */
								"vTaskBLELoad",  			/* 任务名    */
								BLE_UPLOAD_STK_SIZE,  /* stack大小，单位word，也就是4字节 */
								NULL,        					/* 任务参数  */
								BLE_UPLOAD_TASK_PRIO, /* 任务优先级*/
								&userTestHandle );/* 任务句柄  */	

}


static void  userTest_func(void *pvParameters){

	LED_GPIO_Config();
	
	for(;;){//"vTaskBLELoad"
		
		LED1(ON);
		LED2(ON);
		vTaskDelay( pdMS_TO_TICKS(500));
		LED1(OFF);
		LED2(OFF);
		vTaskDelay( pdMS_TO_TICKS(500));
		
		printf("Hello World.");
		
	}
	
}
