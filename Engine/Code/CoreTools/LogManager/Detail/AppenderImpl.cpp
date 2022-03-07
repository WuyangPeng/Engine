///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 22:31)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderImpl.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/LogManager/LogMessagePostfix.h"
#include "CoreTools/LogManager/LogMessagePrefix.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::make_shared;
using namespace std::literals;

CoreTools::AppenderImpl::AppenderImpl(AppenderPrint appenderFlags, LogLevel logLevel) noexcept
    : appenderFlags{ appenderFlags }, logLevel{ logLevel }, isDefaultAppender{ true }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, AppenderImpl)

CoreTools::LogLevel CoreTools::AppenderImpl::GetLogLevel() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return logLevel;
}

CoreTools::AppenderPrint CoreTools::AppenderImpl::GetFlags() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return appenderFlags;
}

void CoreTools::AppenderImpl::SetLogLevel(LogLevel level) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    logLevel = level;
}

void CoreTools::AppenderImpl::Write(const LogMessage& message)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (logLevel != LogLevel::Disabled && logLevel <= message.GetLogLevel())
    {
        const LogMessagePrefix prefix{ appenderFlags, message.GetLogLevel(), message.GetLogFilterType() };
        const LogMessagePostfix postfix{ appenderFlags, message.GetLogLevel(), message.GetFunctionDescribed() };

        DoWrite(message, prefix, postfix);
    }
}

void CoreTools::AppenderImpl::Reload()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

System::String CoreTools::AppenderImpl::GetDirectory() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return SYSTEM_TEXT(""s);
}

System::String CoreTools::AppenderImpl::GetExtensionName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return SYSTEM_TEXT(""s);
}

int CoreTools::AppenderImpl::GetMaxFileSize() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return 0;
}

bool CoreTools::AppenderImpl::IsBackup() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return false;
}

bool CoreTools::AppenderImpl::IsDefault() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return isDefaultAppender;
}

void CoreTools::AppenderImpl::SetIsDefault(bool isDefault) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    isDefaultAppender = isDefault;
}
