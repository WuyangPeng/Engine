///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.1 (2021/03/10 11:09)

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

    template <typename Function>
    void NoexceptNoReturn(Function function) noexcept
    {
        try
        {
            function();
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn 抛出异常。"));
        }
    }

    template <typename T0, typename Function>
    void NoexceptNoReturn(Function function, typename boost::call_traits<T0>::param_type parameter0) noexcept
    {
        try
        {
            function(parameter0);
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn 抛出异常。"));
        }
    }

    template <typename T0, typename T1, typename Function>
    void NoexceptNoReturn(Function function,
                          typename boost::call_traits<T0>::param_type parameter0,
                          typename boost::call_traits<T1>::param_type parameter1) noexcept
    {
        try
        {
            function(parameter0, parameter1);
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn 抛出异常。"));
        }
    }

    template <typename T0, typename T1, typename T2, typename Function>
    void NoexceptNoReturn(Function function,
                          typename boost::call_traits<T0>::param_type parameter0,
                          typename boost::call_traits<T1>::param_type parameter1,
                          typename boost::call_traits<T2>::param_type parameter2) noexcept
    {
        try
        {
            function(parameter0, parameter1, parameter2);
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn 抛出异常。"));
        }
    }

    template <typename T0, typename T1, typename T2, typename T3, typename Function>
    void NoexceptNoReturn(Function function,
                          typename boost::call_traits<T0>::param_type parameter0,
                          typename boost::call_traits<T1>::param_type parameter1,
                          typename boost::call_traits<T2>::param_type parameter2,
                          typename boost::call_traits<T3>::param_type parameter3) noexcept
    {
        try
        {
            function(parameter0, parameter1, parameter2, parameter3);
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn 抛出异常。"));
        }
    }

    template <typename Result, typename Function>
    NODISCARD typename boost::call_traits<Result>::value_type Noexcept(Function function, typename boost::call_traits<Result>::param_type defaultResult) noexcept
    {
        try
        {
            return function();
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept 抛出异常。"));

            return defaultResult;
        }
    }

    template <typename Result, typename T0, typename Function>
    NODISCARD typename boost::call_traits<Result>::value_type Noexcept(Function function, typename boost::call_traits<T0>::param_type parameter0, typename boost::call_traits<Result>::param_type defaultResult) noexcept
    {
        try
        {
            return function(parameter0);
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept 抛出异常。"));

            return defaultResult;
        }
    }

    template <typename Result, typename T0, typename T1, typename Function>
    NODISCARD typename boost::call_traits<Result>::value_type Noexcept(Function function,
                                                                       typename boost::call_traits<T0>::param_type parameter0,
                                                                       typename boost::call_traits<T1>::param_type parameter1,
                                                                       typename boost::call_traits<Result>::param_type defaultResult) noexcept
    {
        try
        {
            return function(parameter0, parameter1);
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept 抛出异常。"));

            return defaultResult;
        }
    }

    template <typename Result, typename T0, typename T1, typename T2, typename Function>
    NODISCARD typename boost::call_traits<Result>::value_type Noexcept(Function function,
                                                                       typename boost::call_traits<T0>::param_type parameter0,
                                                                       typename boost::call_traits<T1>::param_type parameter1,
                                                                       typename boost::call_traits<T2>::param_type parameter2,
                                                                       typename boost::call_traits<Result>::param_type defaultResult) noexcept
    {
        try
        {
            return function(parameter0, parameter1, parameter2);
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept 抛出异常。"));

            return defaultResult;
        }
    }

    template <typename Result, typename T0, typename T1, typename T2, typename T3, typename Function>
    NODISCARD typename boost::call_traits<Result>::value_type Noexcept(Function function,
                                                                       typename boost::call_traits<T0>::param_type parameter0,
                                                                       typename boost::call_traits<T1>::param_type parameter1,
                                                                       typename boost::call_traits<T2>::param_type parameter2,
                                                                       typename boost::call_traits<T3>::param_type parameter3,
                                                                       typename boost::call_traits<Result>::param_type defaultResult) noexcept
    {
        try
        {
            return function(parameter0, parameter1, parameter2, parameter3);
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept 抛出异常。"));

            return defaultResult;
        }
    }
}

#endif  // SYSTEM_HELPER_NOEXCEPT_H
