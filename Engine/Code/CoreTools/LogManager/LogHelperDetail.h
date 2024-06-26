/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 13:09)

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
        if (LogMessage logMessage{ logLevel, logFilter, functionDescribed };
            !logMessage.IsDisabled())
        {
            Process(logMessage, std::forward<Types>(arguments)...);
        }
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("日志写入错误"));
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename... Types>
CoreTools::LogHelper::LogHelper(const LogFileName& fileName, LogLevel logLevel, LogFilter logFilter, const FunctionDescribed& functionDescribed, Types&&... arguments) noexcept
{
    try
    {
        if (LogMessage logMessage{ fileName, logLevel, logFilter, functionDescribed };
            !logMessage.IsDisabled())
        {
            Process(logMessage, std::forward<Types>(arguments)...);
        }
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("日志写入错误"));
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
