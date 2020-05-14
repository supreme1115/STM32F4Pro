#include "userTask_Test.h"
#include "log.h"
#include "sdio_test.h"

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
	
	usart1_config();
	
	for(;;){//"vTaskBLELoad"
		
		LED1(ON);
		LED2(ON);
		vTaskDelay( pdMS_TO_TICKS(500));
		LED1(OFF);
		LED2(OFF);
		vTaskDelay( pdMS_TO_TICKS(500));
		
		LogInfo("Error!!!","Os Stack overflowll");
//		printf("\r\n��ʼ����SD����дʵ��\r\n");	
		SD_Test();		
	}
	
}
