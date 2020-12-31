//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/10 13:06)

#ifndef CORE_TOOLS_CONTRACT_NOEXCEPT_H
#define CORE_TOOLS_CONTRACT_NOEXCEPT_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/CallTraits.h"
#include "System/SystemOutput/OutputDebugString.h"

namespace CoreTools
{
    void CORE_TOOLS_DEFAULT_DECLARE DisableNoexcept();

    template <typename T, typename Function>
    void NoexceptNoReturn(const T& master, Function function) noexcept
    {
        try
        {
            (master.*function)();
        }
        catch (...)
        {
            System::OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));
        }
    }

    template <typename ParamType, typename T, typename Function>
    void NoexceptNoReturn(const T& master, Function function, typename boost::call_traits<ParamType>::param_type parameter1) noexcept
    {
        try
        {
            (master.*function)(parameter1);
        }
        catch (...)
        {
            System::OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));
        }
    }

    template <typename Result, typename T, typename Function>
    [[nodiscard]] typename boost::call_traits<Result>::value_type Noexcept(const T& master, Function function, typename boost::call_traits<Result>::param_type defaultResult) noexcept
    {
        try
        {
            return (master.*function)();
        }
        catch (...)
        {
            System::OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));

            return defaultResult;
        }
    }

    template <typename Result, typename ParamType, typename T, typename Function>
    [[nodiscard]] typename boost::call_traits<Result>::value_type Noexcept(const T& master, Function function, typename boost::call_traits<ParamType>::param_type parameter1, typename boost::call_traits<Result>::param_type defaultResult) noexcept
    {
        try
        {
            return (master.*function)(parameter1);
        }
        catch (...)
        {
            System::OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));

            return defaultResult;
        }
    }

    template <typename T, typename Function>
    void NoexceptNoReturn(T& master, Function function) noexcept
    {
        try
        {
            (master.*function)();
        }
        catch (...)
        {
            System::OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));
        }
    }

    template <typename ParamType, typename T, typename Function>
    void NoexceptNoReturn(T& master, Function function, typename boost::call_traits<ParamType>::param_type parameter1) noexcept
    {
        try
        {
            (master.*function)(parameter1);
        }
        catch (...)
        {
            System::OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));
        }
    }

    template <typename Result, typename T, typename Function>
    [[nodiscard]] typename boost::call_traits<Result>::value_type Noexcept(T& master, Function function, typename boost::call_traits<Result>::param_type defaultResult) noexcept
    {
        try
        {
            return (master.*function)();
        }
        catch (...)
        {
            System::OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));

            return defaultResult;
        }
    }

    template <typename Result, typename ParamType, typename T, typename Function>
    [[nodiscard]] typename boost::call_traits<Result>::value_type Noexcept(T& master, Function function, typename boost::call_traits<ParamType>::param_type parameter1, typename boost::call_traits<Result>::param_type defaultResult) noexcept
    {
        try
        {
            return (master.*function)(parameter1);
        }
        catch (...)
        {
            System::OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));

            return defaultResult;
        }
    }
}

#endif  // CORE_TOOLS_CONTRACT_NOEXCEPT_H
