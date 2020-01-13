// Copyright (c) 2020 Lv Decai, Shenzhen, China.
// LogI: A C++ log interface, easy-to-use log macros
// Version: 1.0
// Release date: 2020-01-13
// License: MIT (http://opensource.org/licenses/MIT)

#ifndef LOGI_H_INCLUDED
#define LOGI_H_INCLUDED

namespace Reesoft::LogI
{
	enum LOG_LEVEL_ENUM
	{
		// Debugging level, recording the value of variables, function execution process tracking, etc.
		LOG_LEVEL_DEBUGGING = 0,

		// Message level, recording the completion of key steps, or messages sent to each other between modules.
		LOG_LEVEL_INFORMATION,

		// Notification level, recording exceptions during function execution, such as invalid input parameters,
		// exception flow, etc.
		LOG_LEVEL_NOTIFICATION,

		// Warning level, recording exceptions that may cause errors during program execution.
		LOG_LEVEL_WARNING,

		// Error level, recording errors that occur in the process of calling library functions and system functions.
		LOG_LEVEL_ERROR,

		// Critical error level, which records the information that an error has caused a major feature to be unavailable.
		LOG_LEVEL_CRITICAL,

		// Alarm error level, record serious errors and send alarms (trigger acousto-optic alarms, etc.).
		LOG_LEVEL_ALERT,

		// Emergency error level, recording information about program failure, system crash, etc.
		LOG_LEVEL_EMERGENCY
	};

	// The actual logging function that the developer should implement
	extern void Log(int iModuleId, int iLevel, const char* sFunction, int iLine, const char* sFormat, ...);
	extern void Log(int iModuleId, int iLevel, const char* sFunction, int iLine, const wchar_t* sFormat, ...);

} // namespace Reesoft::LogI

// Developer should define the logging module ID before including this header file,
// otherwise the default module ID will be used
#ifndef LOG_MODULE_ID
# define LOG_MODULE_ID 0
#endif

// The location name of the log record (function or file name, selected according to the actual situation
// of the platform and developer's needs, detailed enough to locate, but not too redundant)
#ifdef FUNCTION_MACRO_SUPPORTED
# define LOG_POSITION_NAME __FUNCTION__
#else
# define LOG_POSITION_NAME __FILE__
#endif

// Easy-to-use log macros

#define LOG(LEVEL, FORMAT, ...) \
	Reesoft::LogI::Log(LOG_MODULE_ID, LEVEL, LOG_POSITION_NAME, __LINE__, FORMAT, ## __VA_ARGS__)

#define LOG_DEBUGGING(FORMAT, ...) \
	LOG(Reesoft::LogI::LOG_LEVEL_DEBUGGING, FORMAT, ## __VA_ARGS__)

#define LOG_INFORMATION(FORMAT, ...) \
	LOG(Reesoft::LogI::LOG_LEVEL_INFORMATION, FORMAT, ## __VA_ARGS__)

#define LOG_NOTIFICATION(FORMAT, ...) \
	LOG(Reesoft::LogI::LOG_LEVEL_NOTIFICATION, FORMAT, ## __VA_ARGS__)

#define LOG_WARNING(FORMAT, ...) \
	LOG(Reesoft::LogI::LOG_LEVEL_WARNING, FORMAT, ## __VA_ARGS__)

#define LOG_ERROR(FORMAT, ...) \
	LOG(Reesoft::LogI::LOG_LEVEL_ERROR, FORMAT, ## __VA_ARGS__)

#define LOG_CRITICAL(FORMAT, ...) \
	LOG(Reesoft::LogI::LOG_LEVEL_CRITICAL, FORMAT, ## __VA_ARGS__)

#define LOG_ALERT(FORMAT, ...) \
	LOG(Reesoft::LogI::LOG_LEVEL_ALERT, FORMAT, ## __VA_ARGS__)

#define LOG_EMERGENCY(FORMAT, ...) \
	LOG(Reesoft::LogI::LOG_LEVEL_EMERGENCY, FORMAT, ## __VA_ARGS__)

#endif // #ifndef LOGI_H_INCLUDED
