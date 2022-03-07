///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/10 18:32)

#ifndef CORE_TOOLS_CONTRACT_NOEXCEPT_H
#define CORE_TOOLS_CONTRACT_NOEXCEPT_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/CallTraits.h"
#include "System/SystemOutput/OutputDebugString.h"

namespace CoreTools
{
    void CORE_TOOLS_DEFAULT_DECLARE DisableNoexcept();

    /// 捕获成员函数所有异常，这些函数的目的是为了消除编译器警告，其目的并不是为了实现noexcept函数。
    /// 日志库也使用这些函数，所以出错时不打印日志。
    /// 只允许在以下情况下使用：
    /// 1. 析构函数调用的函数。
    /// 2. 函数抛出异常的概率很低（如内存不足），定义成noexcept，可以方便上层函数的调用。
    template <typename T, typename Function, typename... ParamType>
    void NoexceptNoReturn(const T& master, Function function, ParamType&&... parameter) noexcept
    {
        try
        {
            (master.*function)(std::forward<ParamType>(parameter)...);
        }
        catch (...)
        {
            System::OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept 抛出异常。"));
        }
    }

    template <typename Result, typename T, typename Function, typename... ParamType>
    NODISCARD typename boost::call_traits<Result>::value_type Noexcept(const T& master, Function function, typename boost::call_traits<Result>::param_type defaultResult, ParamType&&... parameter) noexcept
    {
        try
        {
            return (master.*function)(std::forward<ParamType>(parameter)...);
        }
        catch (...)
        {
            System::OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept 抛出异常。"));

            return defaultResult;
        }
    }

    template <typename T, typename Function, typename... ParamType>
    void NoexceptNoReturn(T& master, Function function, ParamType&&... parameter) noexcept
    {
        try
        {
            (master.*function)(std::forward<ParamType>(parameter)...);
        }
        catch (...)
        {
            System::OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept 抛出异常。"));
        }
    }

    template <typename Result, typename T, typename Function, typename... ParamType>
    NODISCARD typename boost::call_traits<Result>::value_type Noexcept(T& master, Function function, typename boost::call_traits<Result>::param_type defaultResult, ParamType&&... parameter) noexcept
    {
        try
        {
            return (master.*function)(std::forward<ParamType>(parameter)...);
        }
        catch (...)
        {
            System::OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept 抛出异常。"));

            return defaultResult;
        }
    }
}

#endif  // CORE_TOOLS_CONTRACT_NOEXCEPT_H
