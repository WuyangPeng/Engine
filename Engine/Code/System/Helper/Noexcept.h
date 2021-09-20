///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.1 (2021/03/10 11:09)

#ifndef SYSTEM_HELPER_NOEXCEPT_H
#define SYSTEM_HELPER_NOEXCEPT_H

#include "PragmaWarning/CallTraits.h"
#include "System/SystemOutput/OutputDebugString.h"

namespace System
{
    // ���������쳣����Щ������Ŀ����Ϊ���������������棬��Ŀ�Ĳ�����Ϊ��ʵ��noexcept������
    // ֻ���������������ʹ�ã�
    // 1. �����������õĺ�����
    // 2. �����׳��쳣�ĸ��ʺܵͣ����ڴ治�㣩�������noexcept�����Է����ϲ㺯���ĵ��á�

    template <typename Function>
    void NoexceptNoReturn(Function function) noexcept
    {
        try
        {
            function();
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn �׳��쳣��"));
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
            OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn �׳��쳣��"));
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
            OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn �׳��쳣��"));
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
            OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn �׳��쳣��"));
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
            OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn �׳��쳣��"));
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
            OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));

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
            OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));

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
            OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));

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
            OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));

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
            OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));

            return defaultResult;
        }
    }
}

#endif  // SYSTEM_HELPER_NOEXCEPT_H
