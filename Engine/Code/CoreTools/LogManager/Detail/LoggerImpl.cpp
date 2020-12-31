//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/15 18:36)

#include "CoreTools/CoreToolsExport.h"

#include "LoggerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::LoggerImpl::LoggerImpl(LogFilter logFilter, LogLevel logLevel) noexcept
    : m_LogFilter{ logFilter }, m_Level{ logLevel }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LoggerImpl)

CoreTools::LogFilter CoreTools::LoggerImpl::GetLogFilterType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_LogFilter;
}

CoreTools::LogLevel CoreTools::LoggerImpl::GetLogLevel() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Level;
}

void CoreTools::LoggerImpl::SetLogLevel(LogLevel level) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Level = level;
}
