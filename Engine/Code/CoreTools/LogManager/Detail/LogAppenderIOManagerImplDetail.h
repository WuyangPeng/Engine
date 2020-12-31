//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/15 9:42)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_IMPL_DETAIL_H
#define CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_IMPL_DETAIL_H

#include "LogAppenderIOManagerImpl.h"
#include "System/SystemOutput/OutputDebugString.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
CoreTools::LogAppenderIOManagerImpl& CoreTools::LogAppenderIOManagerImpl::operator<<(T value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    try
    {
        m_Message += System::ToString(value);
    }
    catch (...)
    {
        // 忽略所有异常
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManagerImpl operator<< 抛出异常。"));
    }

    return *this;
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_IMPL_DETAIL_H
