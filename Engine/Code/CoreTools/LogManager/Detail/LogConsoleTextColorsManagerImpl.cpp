// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 10:26)

#include "CoreTools/CoreToolsExport.h"

#include "LogConsoleTextColorsManagerImpl.h"
#include "ErrorConsoleTextColorsManager.h"
#include "OutputConsoleTextColorsManager.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::LogConsoleTextColorsManagerImpl
	::LogConsoleTextColorsManagerImpl(LogLevel logLevel) noexcept
	:m_LogLevel{ logLevel }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::LogConsoleTextColorsManagerImpl
	::~LogConsoleTextColorsManagerImpl() noexcept
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogConsoleTextColorsManagerImpl)

CoreTools::LogLevel CoreTools::LogConsoleTextColorsManagerImpl
	::GetLogLevel() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_LogLevel;
}

// static
CoreTools::TextColour CoreTools::LogConsoleTextColorsManagerImpl
	::GetTextColor(LogLevel logLevel) noexcept
{
	switch (logLevel)
	{
		case LogLevel::Trace:
			return System::TextColour::White;
		case LogLevel::Debug:
			return System::TextColour::Cyan;
		case LogLevel::Info:
			return System::TextColour::Green;
		case LogLevel::Warn:
			return System::TextColour::Yellow;
		case LogLevel::Error:
			return System::TextColour::Red;
		case LogLevel::Fatal:
			return System::TextColour::Red;
		default:
			return System::TextColour::White;
	}
}

// static
bool CoreTools::LogConsoleTextColorsManagerImpl
	::GetIntensified(LogLevel logLevel) noexcept
{
	if (logLevel == LogLevel::Fatal)
		return true;
	else
		return false;
}





