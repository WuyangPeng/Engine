//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 23:14)

#ifndef SYSTEM_HELPER_NOEXCEPT_H
#define SYSTEM_HELPER_NOEXCEPT_H

#include "PragmaWarning/CallTraits.h"
#include "System/SystemOutput/OutputDebugString.h"

namespace System
{
    // 捕获所有异常，这些函数的目的是为了消除编译器警告，但实现noexcept函数不是目的。
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

    template <typename T1, typename Function>
    void NoexceptNoReturn(Function function, typename boost::call_traits<T1>::param_type parameter1) noexcept
    {
        try
        {
            function(parameter1);
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn 抛出异常。"));
        }
    }

    template <typename T1, typename T2, typename Function>
    void NoexceptNoReturn(Function function, typename boost::call_traits<T1>::param_type parameter1,
                          typename boost::call_traits<T2>::param_type parameter2) noexcept
    {
        try
        {
            function(parameter1, parameter2);
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn 抛出异常。"));
        }
    }

    template <typename T1, typename T2, typename T3, typename Function>
    void NoexceptNoReturn(Function function, typename boost::call_traits<T1>::param_type parameter1,
                          typename boost::call_traits<T2>::param_type parameter2,
                          typename boost::call_traits<T3>::param_type parameter3) noexcept
    {
        try
        {
            function(parameter1, parameter2, parameter3);
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn 抛出异常。"));
        }
    }

    template <typename T1, typename T2, typename T3, typename T4, typename Function>
    void NoexceptNoReturn(Function function, typename boost::call_traits<T1>::param_type parameter1,
                          typename boost::call_traits<T2>::param_type parameter2,
                          typename boost::call_traits<T3>::param_type parameter3,
                          typename boost::call_traits<T4>::param_type parameter4) noexcept
    {
        try
        {
            function(parameter1, parameter2, parameter3, parameter4);
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn 抛出异常。"));
        }
    }

    template <typename Result, typename Function>
    [[nodiscard]] typename boost::call_traits<Result>::value_type Noexcept(Function function, typename boost::call_traits<Result>::param_type defaultResult) noexcept
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

    template <typename Result, typename T1, typename Function>
    [[nodiscard]] typename boost::call_traits<Result>::value_type Noexcept(Function function, typename boost::call_traits<T1>::param_type parameter1, typename boost::call_traits<Result>::param_type defaultResult) noexcept
    {
        try
        {
            return function(parameter1);
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept 抛出异常。"));

            return defaultResult;
        }
    }

    template <typename Result, typename T1, typename T2, typename Function>
    [[nodiscard]] typename boost::call_traits<Result>::value_type Noexcept(Function function, typename boost::call_traits<T1>::param_type parameter1,
                                                                           typename boost::call_traits<T2>::param_type parameter2,
                                                                           typename boost::call_traits<Result>::param_type defaultResult) noexcept
    {
        try
        {
            return function(parameter1, parameter2);
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept 抛出异常。"));

            return defaultResult;
        }
    }

    template <typename Result, typename T1, typename T2, typename T3, typename Function>
    [[nodiscard]] typename boost::call_traits<Result>::value_type Noexcept(Function function, typename boost::call_traits<T1>::param_type parameter1,
                                                                           typename boost::call_traits<T2>::param_type parameter2,
                                                                           typename boost::call_traits<T3>::param_type parameter3,
                                                                           typename boost::call_traits<Result>::param_type defaultResult) noexcept
    {
        try
        {
            return function(parameter1, parameter2, parameter3);
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept 抛出异常。"));

            return defaultResult;
        }
    }

    template <typename Result, typename T1, typename T2, typename T3, typename T4, typename Function>
    [[nodiscard]] typename boost::call_traits<Result>::value_type Noexcept(Function function, typename boost::call_traits<T1>::param_type parameter1,
                                                                           typename boost::call_traits<T2>::param_type parameter2,
                                                                           typename boost::call_traits<T3>::param_type parameter3,
                                                                           typename boost::call_traits<T3>::param_type parameter4,
                                                                           typename boost::call_traits<Result>::param_type defaultResult) noexcept
    {
        try
        {
            return function(parameter1, parameter2, parameter3, parameter4);
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept 抛出异常。"));

            return defaultResult;
        }
    }
}

#endif  // SYSTEM_HELPER_NOEXCEPT_H
