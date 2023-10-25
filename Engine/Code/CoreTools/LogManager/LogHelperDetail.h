///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/21 09:44)

#ifndef CORE_TOOLS_LOG_HELPER_LOG_DETAIL_H
#define CORE_TOOLS_LOG_HELPER_LOG_DETAIL_H

#include "LogHelper.h"
#include "System/SystemOutput/OutputDebugString.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/LogMessage.h"

template <typename... Types>
CoreTools::LogHelper::LogHelper(LogLevel logLevel, LogFilter logFilter, const FunctionDescribed& functionDescribed, Types&&... arguments) noexcept
{
    try
    {
        if (LogMessage logMessage{ logLevel, logFilter, functionDescribed }; !logMessage.IsDisabled())
        {
            Process(logMessage, std::forward<Types>(arguments)...);
        }
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("��־д�����"));
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename... Types>
CoreTools::LogHelper::LogHelper(const LogFileName& fileName, LogLevel logLevel, LogFilter logFilter, const FunctionDescribed& functionDescribed, Types&&... arguments) noexcept
{
    try
    {
        if (LogMessage logMessage{ fileName, logLevel, logFilter, functionDescribed }; !logMessage.IsDisabled())
        {
            Process(logMessage, std::forward<Types>(arguments)...);
        }
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("��־д�����"));
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Type, typename... Types>
void CoreTools::LogHelper::Process(LogMessage& logMessage, Type&& argument, Types&&... arguments)
{
    logMessage << argument;

    Process(logMessage, std::forward<Types>(arguments)...);
}

#endif  // CORE_TOOLS_LOG_HELPER_LOG_DETAIL_H
