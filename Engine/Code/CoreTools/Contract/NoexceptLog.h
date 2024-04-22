/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 15:47)

#ifndef CORE_TOOLS_CONTRACT_NOEXCEPT_LOG_H
#define CORE_TOOLS_CONTRACT_NOEXCEPT_LOG_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/LogMacro.h"

namespace CoreTools
{
    /// 捕获成员函数所有异常，并打印日志，这些函数的目的是为了消除编译器警告，其目的并不是为了实现noexcept函数。
    /// 只允许在以下情况下使用：
    /// 1. 析构函数调用的函数。
    /// 2. 函数抛出异常的概率很低（如内存不足），定义成noexcept，可以方便上层函数的调用。
    template <typename T, typename Function, typename... ParamType>
    void NoexceptNoReturnUseLog(const T& master, Function function, ParamType&&... parameter) noexcept
    {
        try
        {
            (master.*function)(std::forward<ParamType>(parameter)...);
        }
        catch (...)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("Noexcept 抛出异常。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }

    template <typename Result, typename T, typename Function, typename... ParamType>
    NODISCARD typename boost::call_traits<Result>::value_type NoexceptUseLog(const T& master, Function function, typename boost::call_traits<Result>::param_type defaultResult, ParamType&&... parameter) noexcept
    {
        try
        {
            return (master.*function)(std::forward<ParamType>(parameter)...);
        }
        catch (...)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("Noexcept 抛出异常。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

            return defaultResult;
        }
    }

    template <typename T, typename Function, typename... ParamType>
    void NoexceptNoReturnUseLog(T& master, Function function, ParamType&&... parameter) noexcept
    {
        try
        {
            (master.*function)(std::forward<ParamType>(parameter)...);
        }
        catch (...)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("Noexcept 抛出异常。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }

    template <typename Result, typename T, typename Function, typename... ParamType>
    NODISCARD typename boost::call_traits<Result>::value_type NoexceptUseLog(T& master, Function function, typename boost::call_traits<Result>::param_type defaultResult, ParamType&&... parameter) noexcept
    {
        try
        {
            return (master.*function)(std::forward<ParamType>(parameter)...);
        }
        catch (...)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("Noexcept 抛出异常。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

            return defaultResult;
        }
    }

    template <typename Function, typename... T>
    void StaticNoexceptNoReturnUseLog(Function function, T&&... parameter) noexcept
    {
        try
        {
            function(std::forward<T>(parameter)...);
        }
        catch (...)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("Noexcept 抛出异常。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }

    template <typename Result, typename Function, typename... T>
    NODISCARD typename boost::call_traits<Result>::value_type StaticNoexceptUseLog(Function function, typename boost::call_traits<Result>::param_type defaultResult, T&&... parameter) noexcept
    {
        try
        {
            return function(std::forward<T>(parameter)...);
        }
        catch (...)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("Noexcept 抛出异常。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

            return defaultResult;
        }
    }
}

#endif  // CORE_TOOLS_CONTRACT_NOEXCEPT_LOG_H
