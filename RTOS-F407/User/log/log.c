#include "log.h"

#include "bsp_usarts.h"
#include "common.h"
#include "parameters.h"

#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#define LOG_FORMAT_BUFSIZE 512
#define LOG_PRINTF_BUFSIZE (2*LOG_FORMAT_BUFSIZE)

static char LOG_FORMAT_BUFFER[LOG_PRINTF_BUFSIZE];
static char LOG_PRINTF_BUFFER[LOG_PRINTF_BUFSIZE];


void replace_char(char *str, const char search, const char replace){
  char *charToReplace = strchr(str, search);
  while ( (charToReplace = strchr(str, search)) != NULL ){
    *charToReplace = replace;
  }
}


void BLE_log(const BLE_loglevel_t aLevel, const char* aTag, const char* aFormat, ...){

//  if(log_enable_flag){
    char *level_prefix = "";
    va_list args;
    va_start(args, aFormat);
    
    if (aLevel == BLE_LOG_WARN)
			level_prefix = "WARN: ";
    else if (aLevel == BLE_LOG_ERROR)
			level_prefix = "FAIL: ";
 
		vTaskSuspendAll();

    memset(LOG_FORMAT_BUFFER, 0, LOG_FORMAT_BUFSIZE);
    memset(LOG_PRINTF_BUFFER, 0, LOG_PRINTF_BUFSIZE);

    snprintf(LOG_FORMAT_BUFFER, LOG_FORMAT_BUFSIZE - 1, "%s[%.4s] %s", level_prefix, aTag, aFormat);

    vsnprintf(LOG_PRINTF_BUFFER, LOG_PRINTF_BUFSIZE - 3, LOG_FORMAT_BUFFER, args);
    replace_char(LOG_PRINTF_BUFFER, '\r', ' ');
    replace_char(LOG_PRINTF_BUFFER, '\n', ' ');
    strcat(LOG_PRINTF_BUFFER, "\r\n");
		
		DEBUG_USART_Send_Bytes((u8*)LOG_PRINTF_BUFFER, strlen(LOG_PRINTF_BUFFER));

    va_end(args);

		xTaskResumeAll();
//  }
	
}

