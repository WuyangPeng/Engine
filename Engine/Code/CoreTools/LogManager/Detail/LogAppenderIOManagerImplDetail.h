///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/06 0:08)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_IMPL_DETAIL_H
#define CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_IMPL_DETAIL_H

#include "LogAppenderIOManagerImpl.h"
#include "System/SystemOutput/OutputDebugString.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
CoreTools::LogAppenderIOManagerImpl& CoreTools::LogAppenderIOManagerImpl::operator<<(T value) noexcept
{
    static_assert(std::is_arithmetic_v<T>);

    CORE_TOOLS_CLASS_IS_VALID_1;

    try
    {
        AddMessage(value);
    }
    catch (...)
    {
        // ���������쳣
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManagerImpl operator<< �׳��쳣��"));
    }

    return *this;
}

template <typename T>
void CoreTools::LogAppenderIOManagerImpl::AddMessage(T value)
{
    if (!IsDisabled())
    {
        logMessage += System::ToString(value);
    }
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_IMPL_DETAIL_H
