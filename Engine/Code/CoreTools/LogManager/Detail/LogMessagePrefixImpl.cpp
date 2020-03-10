// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 10:38)

#include "CoreTools/CoreToolsExport.h"

#include "LogMessagePrefixImpl.h"
#include "AppenderPrintFlagsExist.h"
#include "System/Helper/PragmaWarning/PosixTime.h"
#include "CoreTools/LogManager/LogLevelManager.h"
#include "CoreTools/LogManager/LogFilterManager.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::LogMessagePrefixImpl
	::LogMessagePrefixImpl(AppenderPrint appenderFlags, LogLevel level, LogFilter filter)
	:m_Prefix{}, m_AppenderPrint{ appenderFlags }, m_Level{ level }, m_Filter{ filter }
{
	GeneratePrefix();

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

// private
void CoreTools::LogMessagePrefixImpl
	::GeneratePrefix()
{
	if (m_Level != LogLevel::Disabled)
	{
		GenerateTimestampPrefix();
		GenerateLogLevelPrefix();
		GenerateLogFilterPrefix();
	}
}

// private
void CoreTools::LogMessagePrefixImpl
	::GenerateTimestampPrefix()
{
	if (AppenderPrintFlagsExist::IsExist(m_AppenderPrint, AppenderPrint::PrefixTimestamp))
	{
		auto nowTime = boost::posix_time::second_clock::local_time();

		m_Prefix += (SYSTEM_TEXT("°æ") + boost::posix_time::to_simple_string_type<System::TChar>(nowTime) + SYSTEM_TEXT("°ø"));
	}
}

// private
void CoreTools::LogMessagePrefixImpl
	::GenerateLogLevelPrefix()
{
	if (AppenderPrintFlagsExist::IsExist(m_AppenderPrint, AppenderPrint::PrefixLogLevel))
	{
		m_Prefix += (SYSTEM_TEXT("°æ") + LogLevelManager::GetLogLevelDescribe(m_Level) + SYSTEM_TEXT("°ø"));
	}
}

// private
void CoreTools::LogMessagePrefixImpl
	::GenerateLogFilterPrefix()
{
	if (AppenderPrintFlagsExist::IsExist(m_AppenderPrint, AppenderPrint::PrefixLogFilterType))
	{
		m_Prefix += (SYSTEM_TEXT("°æ") + LogFilterManager::GetLogFilterDescribe(m_Filter) + SYSTEM_TEXT("°ø"));
	}
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogMessagePrefixImpl)

System::String CoreTools::LogMessagePrefixImpl
	::GetPrefix() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Prefix;
}

int CoreTools::LogMessagePrefixImpl
	::GetPrefixSize() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_Prefix.size());
}


