/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/28 15:47)

#ifndef CORE_TOOLS_CONTRACT_NOEXCEPT_LOG_H
#define CORE_TOOLS_CONTRACT_NOEXCEPT_LOG_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/LogMacro.h"

namespace CoreTools
{
    /// �����Ա���������쳣������ӡ��־����Щ������Ŀ����Ϊ���������������棬��Ŀ�Ĳ�����Ϊ��ʵ��noexcept������
    /// ֻ���������������ʹ�ã�
    /// 1. �����������õĺ�����
    /// 2. �����׳��쳣�ĸ��ʺܵͣ����ڴ治�㣩�������noexcept�����Է����ϲ㺯���ĵ��á�
    template <typename T, typename Function, typename... ParamType>
    void NoexceptNoReturnUseLog(const T& master, Function function, ParamType&&... parameter) noexcept
    {
        try
        {
            (master.*function)(std::forward<ParamType>(parameter)...);
        }
        catch (...)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("Noexcept �׳��쳣��"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
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
            LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("Noexcept �׳��쳣��"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

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
            LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("Noexcept �׳��쳣��"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
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
            LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("Noexcept �׳��쳣��"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

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
            LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("Noexcept �׳��쳣��"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
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
            LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("Noexcept �׳��쳣��"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

            return defaultResult;
        }
    }
}

#endif  // CORE_TOOLS_CONTRACT_NOEXCEPT_LOG_H
