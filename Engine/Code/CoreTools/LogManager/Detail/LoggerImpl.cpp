/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 14:03)

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
