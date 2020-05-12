#include "userTask_Test.h"

static void  userTest_func(void *pvParameters);

TaskHandle_t userTestHandle = NULL;

void create_userTest_Task(void){

	xTaskCreate(	userTest_func,    			/* ������  */
								"vTaskBLELoad",  			/* ������    */
								BLE_UPLOAD_STK_SIZE,  /* stack��С����λword��Ҳ����4�ֽ� */
								NULL,        					/* �������  */
								BLE_UPLOAD_TASK_PRIO, /* �������ȼ�*/
								&userTestHandle );/* ������  */	

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
