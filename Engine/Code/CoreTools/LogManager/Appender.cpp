//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/15 18:47)

#include "CoreTools/CoreToolsExport.h"

#include "Appender.h"
#include "Detail/AppenderFactory.h"
#include "Detail/AppenderImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "../Contract/Flags/ImplFlags.h"
COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(CoreTools, Appender)
CoreTools::Appender::Appender(AppenderPrint appenderFlags, LogLevel logLevel)
    : impl{ ImplCreateUseFactory::Default, appenderFlags, logLevel }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::Appender::Appender(const String& directory, const String& fileName, AppenderPrint appenderFlags, LogLevel logLevel,
                              int maxFileSize, bool backup, const String& extensionName)
    : impl{ ImplCreateUseFactory::Default, directory, fileName, appenderFlags, logLevel, maxFileSize, backup, extensionName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::Appender::Appender(const String& directory, AppenderPrint appenderFlags, LogLevel logLevel, int maxFileSize, bool backup, const String& extensionName)
    : impl{ ImplCreateUseFactory::Default, directory, appenderFlags, logLevel, maxFileSize, backup, extensionName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Appender)

 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Appender, GetLogLevel, CoreTools::LogLevel)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Appender, GetFlags, CoreTools::AppenderPrint)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Appender, GetAppenderType, CoreTools::AppenderType)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, Appender, SetLogLevel, LogLevel, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, Appender, Write, LogMessage, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Appender, Reload, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Appender, GetDirectory, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Appender, GetExtensionName, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Appender, GetMaxFileSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Appender, IsBackup, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Appender, IsDefault, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, Appender, SetIsDefault, bool, void)
