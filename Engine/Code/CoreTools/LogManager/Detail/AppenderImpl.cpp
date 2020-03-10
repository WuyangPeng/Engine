// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 10:17)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderImpl.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/LogManager/LogMessagePrefix.h"
#include "CoreTools/LogManager/LogMessagePostfix.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::AppenderImpl
	::AppenderImpl(AppenderPrint appenderFlags, LogLevel logLevel)
	:m_AppenderFlags{ appenderFlags }, m_LogLevel{ logLevel }, m_IsDefault{ true }, m_AppenderImplMutex{ }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::AppenderImpl
	::AppenderImpl(const AppenderImpl& rhs)
	:m_AppenderFlags{ rhs.m_AppenderFlags }, m_LogLevel{ rhs.m_LogLevel }, m_IsDefault{ rhs.m_IsDefault }, m_AppenderImplMutex{ }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::AppenderImpl& CoreTools::AppenderImpl
	::operator=(const AppenderImpl& rhs)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_AppenderFlags = rhs.m_AppenderFlags;
	m_LogLevel = rhs.m_LogLevel;
	m_IsDefault = rhs.m_IsDefault;

	return *this;
}

CoreTools::AppenderImpl
	::~AppenderImpl()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, AppenderImpl)

CoreTools::LogLevel CoreTools::AppenderImpl
	::GetLogLevel() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_LogLevel;
}

CoreTools::AppenderPrint CoreTools::AppenderImpl
	::GetFlags() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_AppenderFlags;
}

void CoreTools::AppenderImpl
	::SetLogLevel(LogLevel level) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_LogLevel = level;
}

void CoreTools::AppenderImpl
	::Write(const LogMessage& message)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	ScopedMutex scopedMutex{ m_AppenderImplMutex };

	if (m_LogLevel != LogLevel::Disabled && m_LogLevel <= message.GetLogLevel())
	{
		LogMessagePrefix prefix{ m_AppenderFlags, message.GetLogLevel(), message.GetLogFilterType() };
		LogMessagePostfix postfix{ m_AppenderFlags,message.GetLogLevel(),message.GetFunctionDescribed() };

		DoWrite(message, prefix, postfix);
	}
}

void CoreTools::AppenderImpl
	::Reload()
{
	CORE_TOOLS_CLASS_IS_VALID_9;
}

System::String CoreTools::AppenderImpl
	::GetDirectory() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return SYSTEM_TEXT("");
}

System::String CoreTools::AppenderImpl
	::GetExtensionName() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return SYSTEM_TEXT("");
}

int CoreTools::AppenderImpl
	::GetMaxFileSize() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return 0;
}

bool CoreTools::AppenderImpl
	::IsBackup() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return false;
}

bool CoreTools::AppenderImpl
	::IsDefault() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_IsDefault;
}

void CoreTools::AppenderImpl
	::SetIsDefault(bool isDefault) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_IsDefault = isDefault;
}

