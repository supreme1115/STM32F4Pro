#include "stm32f4xx.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "croutine.h"

#include "parameters.h"

#include "userTask_Test.h"

#include "bsp_usarts.h"
#include "bsp_spi_x.h"

uint8_t FileName[FILE_NAME_LENGTH];

int main(void){

	create_userTest_Task();

	/* 启动任务调度器，运行FreeRTOS系统 */
  vTaskStartScheduler();

}

 
