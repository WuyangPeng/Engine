// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 10:27)

#include "CoreTools/CoreToolsExport.h"

#include "LoggerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::LoggerImpl
	::LoggerImpl(LogFilter logFilter, LogLevel logLevel) noexcept
	:m_LogFilter{ logFilter }, m_Level{ logLevel }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LoggerImpl)

CoreTools::LogFilter CoreTools::LoggerImpl
	::GetLogFilterType() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_LogFilter;
}

CoreTools::LogLevel CoreTools::LoggerImpl
	::GetLogLevel() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Level;
}

void CoreTools::LoggerImpl
	::SetLogLevel(LogLevel level) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Level = level;
}

