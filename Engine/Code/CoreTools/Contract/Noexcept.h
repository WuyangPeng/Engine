/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/10 20:37)

#ifndef CORE_TOOLS_CONTRACT_NOEXCEPT_H
#define CORE_TOOLS_CONTRACT_NOEXCEPT_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning.h"
#include "System/Helper/PragmaWarning/CallTraits.h"
#include "System/SystemOutput/OutputDebugString.h"

namespace CoreTools
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)

    // ���������Ϊ���������������棬����û���������ġ�
    inline void DisableNoexcept()
    {
    }

#include SYSTEM_WARNING_POP

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
