//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/21 23:14)

#ifndef SYSTEM_HELPER_NOEXCEPT_H
#define SYSTEM_HELPER_NOEXCEPT_H

#include "PragmaWarning/CallTraits.h"
#include "System/SystemOutput/OutputDebugString.h"

namespace System
{
    // ���������쳣����Щ������Ŀ����Ϊ���������������棬��ʵ��noexcept��������Ŀ�ġ�
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

    template <typename T1, typename Function>
    void NoexceptNoReturn(Function function, typename boost::call_traits<T1>::param_type parameter1) noexcept
    {
        try
        {
            function(parameter1);
        }
        catch (...)
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn �׳��쳣��"));
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
            OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn �׳��쳣��"));
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
            OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn �׳��쳣��"));
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
            OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn �׳��쳣��"));
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
            OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));

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
            OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));

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
            OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));

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
            OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));

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
            OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));

            return defaultResult;
        }
    }
}

#endif  // SYSTEM_HELPER_NOEXCEPT_H
