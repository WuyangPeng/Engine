// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 11:00)

#include "CoreTools/CoreToolsExport.h"

#include "Appender.h"
#include "Detail/AppenderImpl.h"
#include "Detail/AppenderFactory.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Appender
	::Appender(AppenderPrint appenderFlags, LogLevel logLevel)
	:m_Impl{ AppenderFactory::CreateAppenderConsole(appenderFlags,logLevel) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::Appender
	::Appender(const String& directory, const String& fileName, AppenderPrint appenderFlags, LogLevel logLevel,
			   int maxFileSize, bool backup, const String& extensionName)
	:m_Impl{ AppenderFactory::CreateAppenderFile(directory,fileName,appenderFlags,logLevel,maxFileSize,backup,extensionName) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::Appender
	::Appender(const String& directory, AppenderPrint appenderFlags, LogLevel logLevel, int maxFileSize, bool backup, const String& extensionName)
	:m_Impl{ AppenderFactory::CreateAppenderFile(directory,appenderFlags, logLevel,maxFileSize, backup, extensionName) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, Appender)

DELAY_COPY_CONSTRUCTION_CLONE_DEFINE(CoreTools, Appender)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Appender, GetLogLevel, CoreTools::LogLevel)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Appender, GetFlags, CoreTools::AppenderPrint)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Appender, GetAppenderType, CoreTools::AppenderType)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, Appender, SetLogLevel, LogLevel, void)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, Appender, Write, LogMessage, void)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_0(CoreTools, Appender, Reload, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Appender, GetDirectory, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Appender, GetExtensionName, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Appender, GetMaxFileSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Appender, IsBackup, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Appender, IsDefault, bool)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, Appender, SetIsDefault, bool, void)
