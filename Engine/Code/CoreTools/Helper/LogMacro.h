///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.1 (2021/07/29 16:08)

// ��־������Ҫ�ĺ�
#ifndef CORE_TOOLS_HELPER_LOG_MACRO_H
#define CORE_TOOLS_HELPER_LOG_MACRO_H

#include "CoreTools/Contract/FunctionDescribed.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/LogManager/Log.h"
#include "CoreTools/LogManager/LogAppenderIOManager.h"
#include "CoreTools/LogManager/LogFileName.h"

#define LOG_SINGLETON_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, functionDescribed) \
    SYSTEM_CONCATENATOR(LOG_SINGLETON.Out, appender()) << SYSTEM_CONCATENATOR(CoreTools::LogFilter::, filterType) << functionDescribed

#define LOG_SINGLETON_APPENDER(appender, filterType) \
    LOG_SINGLETON_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, (CORE_TOOLS_FUNCTION_DESCRIBED))

#define LOG_SINGLETON_FILE_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, functionDescribed, fileName) \
    LOG_SINGLETON_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, functionDescribed) << CoreTools::LogFileName(fileName)

#define LOG_SINGLETON_FILE_APPENDER(appender, filterType, fileName) \
    LOG_SINGLETON_FILE_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, (CORE_TOOLS_FUNCTION_DESCRIBED), fileName)

#define LOG_SINGLETON_CONSOLE_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, functionDescribed) \
    LOG_SINGLETON_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, functionDescribed) << CoreTools::LogFileName(SYSTEM_TEXT("Console"))

#define LOG_SINGLETON_CONSOLE_APPENDER(appender, filterType) \
    LOG_SINGLETON_CONSOLE_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, (CORE_TOOLS_FUNCTION_DESCRIBED))

#define LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(appender, filterType, fileName) \
    LOG_SINGLETON_FILE_APPENDER(appender, filterType, fileName) << CoreTools::LogAppenderIOManageSign::AlwaysConsole

#define LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, functionDescribed, fileName) \
    LOG_SINGLETON_FILE_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, functionDescribed, fileName)                 \
        << CoreTools::LogAppenderIOManageSign::AlwaysConsole

#define LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, functionDescribed) \
    LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, functionDescribed, SYSTEM_TEXT(#filterType))

#define LOG_SINGLETON_ENGINE_APPENDER(appender, filterType) \
    LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(appender, filterType, (CORE_TOOLS_FUNCTION_DESCRIBED))

#define LOG_SINGLETON_TRIGGER_ASSERT \
    CoreTools::LogAppenderIOManageSign::TriggerAssert << CoreTools::LogAppenderIOManageSign::Refresh

#endif  // CORE_TOOLS_HELPER_LOG_MACRO_H
