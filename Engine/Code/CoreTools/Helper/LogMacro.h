///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/22 11:08)

// ��־������Ҫ�ĺ�
#ifndef CORE_TOOLS_HELPER_LOG_MACRO_H
#define CORE_TOOLS_HELPER_LOG_MACRO_H

#include "CoreTools/Contract/FunctionDescribed.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/LogManager/Log.h"
#include "CoreTools/LogManager/LogAppenderIOManager.h"
#include "CoreTools/LogManager/LogFileName.h"
#include "CoreTools/LogManager/LogHelperDetail.h"

#define LOG_SINGLETON_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, functionDescribed, ...) \
    const CoreTools::LogHelper SYSTEM_CONCATENATOR(logHelper, __LINE__)                             \
    {                                                                                               \
        SYSTEM_CONCATENATOR(CoreTools::LogLevel::, appender),                                       \
            SYSTEM_CONCATENATOR(CoreTools::LogFilter::, filterType),                                \
            functionDescribed,                                                                      \
            __VA_ARGS__                                                                             \
    }

#define LOG_SINGLETON_APPENDER(appender, filterType, ...) \
    LOG_SINGLETON_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, (CORE_TOOLS_FUNCTION_DESCRIBED), __VA_ARGS__)

#define LOG_SINGLETON_FILE_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, functionDescribed, fileName, ...) \
    const CoreTools::LogHelper SYSTEM_CONCATENATOR(logHelper, __LINE__)                                            \
    {                                                                                                              \
        CoreTools::LogFileName{ fileName },                                                                        \
            SYSTEM_CONCATENATOR(CoreTools::LogLevel::, appender),                                                  \
            SYSTEM_CONCATENATOR(CoreTools::LogFilter::, filterType),                                               \
            functionDescribed,                                                                                     \
            __VA_ARGS__                                                                                            \
    }

#define LOG_SINGLETON_FILE_APPENDER(appender, filterType, fileName, ...) \
    LOG_SINGLETON_FILE_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, (CORE_TOOLS_FUNCTION_DESCRIBED), fileName, __VA_ARGS__)

#define LOG_SINGLETON_CONSOLE_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, functionDescribed, ...) \
    LOG_SINGLETON_FILE_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, functionDescribed, SYSTEM_TEXT("Console"), __VA_ARGS__)

#define LOG_SINGLETON_CONSOLE_APPENDER(appender, filterType, ...) \
    LOG_SINGLETON_CONSOLE_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, (CORE_TOOLS_FUNCTION_DESCRIBED), __VA_ARGS__)

#define LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(appender, filterType, fileName, ...) \
    LOG_SINGLETON_FILE_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, (CORE_TOOLS_FUNCTION_DESCRIBED), fileName, CoreTools::LogAppenderIOManageSign::AlwaysConsole, __VA_ARGS__)

#define LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, functionDescribed, fileName, ...) \
    LOG_SINGLETON_FILE_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, functionDescribed, fileName, CoreTools::LogAppenderIOManageSign::AlwaysConsole, __VA_ARGS__)

#define LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, functionDescribed, ...) \
    LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, functionDescribed, SYSTEM_TEXT(#filterType), __VA_ARGS__)

#define LOG_SINGLETON_ENGINE_APPENDER(appender, filterType, ...) \
    LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, (CORE_TOOLS_FUNCTION_DESCRIBED), __VA_ARGS__)

#endif  // CORE_TOOLS_HELPER_LOG_MACRO_H
