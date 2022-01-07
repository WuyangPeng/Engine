///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 17:52)

#ifndef SYSTEM_HELPER_NOEXCEPT_H
#define SYSTEM_HELPER_NOEXCEPT_H

#include "PragmaWarning/CallTraits.h"
#include "System/SystemOutput/OutputDebugString.h"

namespace System
{
    // 捕获所有异常，这些函数的目的是为了消除编译器警告，其目的并不是为了实现noexcept函数。
    // 只允许在以下情况下使用：
    // 1. 析构函数调用的函数。
    // 2. 函数抛出异常的概率很低（如内存不足），定义成noexcept，可以方便上层函数的调用。

    template <typename Function, typename... T>
    void NoexceptNoReturn(Function function, T&&... parameter) noexcept
    {
        try
        {
            function(std::forward<T>(parameter)...);
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn 抛出异常。"));
        }
    }

    template <typename Result, typename Function, typename... T>
    NODISCARD typename boost::call_traits<Result>::value_type Noexcept(Function function, typename boost::call_traits<Result>::param_type defaultResult, T&&... parameter) noexcept
    {
        try
        {
            return function(std::forward<T>(parameter)...);
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept 抛出异常。"));

            return defaultResult;
        }
    }
}

#endif  // SYSTEM_HELPER_NOEXCEPT_H
