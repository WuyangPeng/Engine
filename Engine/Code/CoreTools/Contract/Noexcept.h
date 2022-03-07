///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/10 18:32)

#ifndef CORE_TOOLS_CONTRACT_NOEXCEPT_H
#define CORE_TOOLS_CONTRACT_NOEXCEPT_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/CallTraits.h"
#include "System/SystemOutput/OutputDebugString.h"

namespace CoreTools
{
    void CORE_TOOLS_DEFAULT_DECLARE DisableNoexcept();

    /// �����Ա���������쳣����Щ������Ŀ����Ϊ���������������棬��Ŀ�Ĳ�����Ϊ��ʵ��noexcept������
    /// ��־��Ҳʹ����Щ���������Գ���ʱ����ӡ��־��
    /// ֻ���������������ʹ�ã�
    /// 1. �����������õĺ�����
    /// 2. �����׳��쳣�ĸ��ʺܵͣ����ڴ治�㣩�������noexcept�����Է����ϲ㺯���ĵ��á�
    template <typename T, typename Function, typename... ParamType>
    void NoexceptNoReturn(const T& master, Function function, ParamType&&... parameter) noexcept
    {
        try
        {
            (master.*function)(std::forward<ParamType>(parameter)...);
        }
        catch (...)
        {
            System::OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));
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
            System::OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));

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
            System::OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));
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
            System::OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept �׳��쳣��"));

            return defaultResult;
        }
    }
}

#endif  // CORE_TOOLS_CONTRACT_NOEXCEPT_H
