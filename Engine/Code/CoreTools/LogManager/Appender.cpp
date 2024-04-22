/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 14:05)

#include "CoreTools/CoreToolsExport.h"

#include "Appender.h"
#include "Detail/AppenderFactory.h"
#include "Detail/AppenderImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(CoreTools, Appender)

CoreTools::Appender::Appender(AppenderPrint appenderFlags, LogLevel logLevel)
    : impl{ ImplCreateUseFactory::Default, appenderFlags, logLevel }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::Appender::Appender(const String& directory,
                              const String& fileName,
                              AppenderPrint appenderFlags,
                              LogLevel logLevel,
                              int maxFileSize,
                              bool backup,
                              const String& extensionName)
    : impl{ ImplCreateUseFactory::Default, directory, fileName, appenderFlags, logLevel, maxFileSize, backup, extensionName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::Appender::Appender(const String& directory, AppenderPrint appenderFlags, LogLevel logLevel, int maxFileSize, bool backup, const String& extensionName)
    : impl{ ImplCreateUseFactory::Default, directory, appenderFlags, logLevel, maxFileSize, backup, extensionName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Appender)

CoreTools::LogLevel CoreTools::Appender::GetLogLevel() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetLogLevel();
}

CoreTools::AppenderPrint CoreTools::Appender::GetFlags() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFlags();
}

CoreTools::AppenderType CoreTools::Appender::GetAppenderType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetAppenderType();
}

void CoreTools::Appender::SetLogLevel(LogLevel level)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetLogLevel(level);
}

void CoreTools::Appender::Write(const LogMessage& message) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->Write(message);
}

CoreTools::Appender::String CoreTools::Appender::GetDirectory() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetDirectory();
}

CoreTools::Appender::String CoreTools::Appender::GetExtensionName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetExtensionName();
}

int CoreTools::Appender::GetMaxFileSize() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetMaxFileSize();
}

bool CoreTools::Appender::IsBackup() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsBackup();
}

bool CoreTools::Appender::IsDefault() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsDefault();
}

void CoreTools::Appender::SetIsDefault(bool isDefault)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetIsDefault(isDefault);
}
