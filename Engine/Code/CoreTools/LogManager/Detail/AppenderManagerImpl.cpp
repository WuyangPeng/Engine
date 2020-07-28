// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 10:19)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderManagerImpl.h"
#include "CoreTools/LogManager/Logger.h"
#include "CoreTools/LogManager/Appender.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
const System::String CoreTools::AppenderManagerImpl
	::sm_ConsoleAppenderName{ SYSTEM_TEXT("Console") };

const System::String CoreTools::AppenderManagerImpl
	::sm_DefaultAppenderName{ SYSTEM_TEXT("Default") };
#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::AppenderManagerImpl
	::AppenderManagerImpl()
	:m_Loggers{}, m_Appenders{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP
CLASS_INVARIANT_STUB_DEFINE(CoreTools, AppenderManagerImpl)

bool CoreTools::AppenderManagerImpl
	::InsertLogger(const Logger& logger)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return m_Loggers.insert({ logger.GetLogFilterType(), logger }).second;
}

bool CoreTools::AppenderManagerImpl
	::RemoveLogger(LogFilter logFilter)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return (m_Loggers.erase(logFilter) != 0);
}

bool CoreTools::AppenderManagerImpl
	::InsertAppender(const String& name, const Appender& appender)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return m_Appenders.insert({ name, appender }).second;
}

bool CoreTools::AppenderManagerImpl
	::InsertConsoleAppender(const Appender& appender)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return InsertAppender(sm_ConsoleAppenderName, appender);
}

bool CoreTools::AppenderManagerImpl
	::RemoveAppender(const String& name)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return (m_Appenders.erase(name) != 0);
}

void CoreTools::AppenderManagerImpl
	::Clear() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_Loggers.clear();
	m_Appenders.clear();
}

void CoreTools::AppenderManagerImpl
	::Write(const LogMessage& message)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	const auto level = GetLogLevelType(message);

	if (level != LogLevel::Disabled && level <= message.GetLogLevel() && !message.GetMessageDescribe().empty())
	{
		DoWrite(message);
	}
}

void CoreTools::AppenderManagerImpl
	::Write(const String& name, const LogMessage& message)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	const auto level = GetLogLevelType(message);

	if (level != LogLevel::Disabled && level <= message.GetLogLevel() && !message.GetMessageDescribe().empty() && sm_DefaultAppenderName != name)
	{
		DoWrite(name, message);
	}
}

void CoreTools::AppenderManagerImpl
	::WriteToConsole(const LogMessage& message)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	Write(GetConsoleAppenderName(), message);
}

// private
CoreTools::LogLevel CoreTools::AppenderManagerImpl
	::GetLogLevelType(const LogMessage& message) const
{
	const auto iter = m_Loggers.find(message.GetLogFilterType());

	if (iter != m_Loggers.cend())
		return iter->second.GetLogLevel();
	else
		return LogLevel::Disabled;
}

// private
void CoreTools::AppenderManagerImpl
	::DoWrite(const LogMessage& message)
{
	for (auto& value : m_Appenders)
	{
		if (value.second.IsDefault())
		{
			value.second.Write(message);
		}
	}
}

void CoreTools::AppenderManagerImpl
	::DoWrite(const System::String& name, const LogMessage& message)
{
	const auto iter = m_Appenders.find(name);

	if (iter != m_Appenders.cend())
	{
		iter->second.Write(message);
	}
	else if (IsAppenderExist(sm_DefaultAppenderName) && CreateFileAppender(name))
	{
		DoWrite(name, message);
	}
}

void CoreTools::AppenderManagerImpl
::ReloadAppenderFile()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	for (auto& value : m_Appenders)
	{
		value.second.Reload();
	}
}

// static
const System::String CoreTools::AppenderManagerImpl
	::GetConsoleAppenderName()
{
	return sm_ConsoleAppenderName;
}

// static
const System::String CoreTools::AppenderManagerImpl
	::GetDefaultAppenderName()
{
	return sm_DefaultAppenderName;
}

bool CoreTools::AppenderManagerImpl
	::IsAppenderExist(const String& name) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	const auto iter = m_Appenders.find(name);

	if (iter != m_Appenders.cend())
		return true;
	else
		return false;
}

bool CoreTools::AppenderManagerImpl
	::CreateFileAppender(const String& fileName)
{
	const auto iter = m_Appenders.find(sm_DefaultAppenderName);

	if (iter != m_Appenders.cend())
	{
		const auto& appender = iter->second;

		auto directory = appender.GetDirectory();
		const auto flags = appender.GetFlags();
		const auto level = appender.GetLogLevel();
		const auto maxFileSize = appender.GetMaxFileSize();
		const auto backup = appender.IsBackup();
		auto extension = appender.GetExtensionName();

		if (!fileName.empty() && LogLevel::Disabled <= level && level < LogLevel::MaxLogLevels)
		{
			Appender appenderValue{ directory, fileName, flags, level, maxFileSize, backup, extension };
			appenderValue.SetIsDefault(false);

			return InsertAppender(fileName, appenderValue);
		}
	}

	return false;
}





