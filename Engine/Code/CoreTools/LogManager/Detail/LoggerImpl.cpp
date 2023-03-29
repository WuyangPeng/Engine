///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/28 15:24)

#include "CoreTools/CoreToolsExport.h"

#include "LoggerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::LoggerImpl::LoggerImpl(LogFilter logFilter, LogLevel logLevel) noexcept
    : logFilter{ logFilter }, logLevel{ logLevel }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LoggerImpl)

CoreTools::LogFilter CoreTools::LoggerImpl::GetLogFilterType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return logFilter;
}

CoreTools::LogLevel CoreTools::LoggerImpl::GetLogLevel() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return logLevel;
}

void CoreTools::LoggerImpl::SetLogLevel(LogLevel level) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    logLevel = level;
}
