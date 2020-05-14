#ifndef __LOG_H
#define __LOG_H     

#if DEBUG
  #define LOGGING_LEVEL_VERBOSE 0
  #define LOGGING_LEVEL_DEBUG   1
  #define LOGGING_LEVEL_INFO    1
  #define LOGGING_LEVEL_WARN    1
  #define LOGGING_LEVEL_ERROR   1
#else
  #define LOGGING_LEVEL_VERBOSE 0
  #define LOGGING_LEVEL_DEBUG   0
  #define LOGGING_LEVEL_INFO    1
  #define LOGGING_LEVEL_WARN    1
  #define LOGGING_LEVEL_ERROR   1
#endif


#if LOGGING_LEVEL_VERBOSE
	#define LogVerbose(tag, fmt, ...)  BLE_log(  BLE_LOG_VERBOSE, tag, fmt, ##__VA_ARGS__)
#else
	#define LogVerbose(...)
#endif


#if LOGGING_LEVEL_DEBUG
	#define LogDebug(tag, fmt, ...)  BLE_log(  BLE_LOG_DEBUG, tag, fmt, ##__VA_ARGS__)
#else
	#define LogDebug(...)
#endif


#if LOGGING_LEVEL_INFO
	#define LogInfo(tag, fmt, ...)  BLE_log(  BLE_LOG_INFO, tag, fmt, ##__VA_ARGS__)
#else
	#define LogInfo(...)
#endif


#if LOGGING_LEVEL_WARN
	#define LogWarn(tag, fmt, ...)  BLE_log(  BLE_LOG_WARN, tag, fmt, ##__VA_ARGS__)
#else
	#define LogWarn(...)
#endif


#if LOGGING_LEVEL_ERROR
	#define LogError(tag, fmt, ...)  BLE_log(  BLE_LOG_ERROR, tag, fmt, ##__VA_ARGS__)
#else
	#define LogError(...)
#endif



// don't use these directly
typedef enum {
  BLE_LOG_VERBOSE = 1, 
  BLE_LOG_DEBUG, 
  BLE_LOG_INFO,
  BLE_LOG_WARN,
  BLE_LOG_ERROR
} BLE_loglevel_t;

void BLE_log(const BLE_loglevel_t aLevel, const char* aTag, const char* aFormat, ...);

#endif
