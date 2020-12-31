//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/15 18:25)

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

CoreTools::AppenderImpl::AppenderImpl(AppenderPrint appenderFlags, LogLevel logLevel)
    : m_AppenderFlags{ appenderFlags }, m_LogLevel{ logLevel }, m_IsDefault{ true }, m_AppenderImplMutex{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::AppenderImpl::AppenderImpl(const AppenderImpl& rhs)
    : m_AppenderFlags{ rhs.m_AppenderFlags }, m_LogLevel{ rhs.m_LogLevel }, m_IsDefault{ rhs.m_IsDefault }, m_AppenderImplMutex{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::AppenderImpl& CoreTools::AppenderImpl::operator=(const AppenderImpl& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_AppenderFlags = rhs.m_AppenderFlags;
    m_LogLevel = rhs.m_LogLevel;
    m_IsDefault = rhs.m_IsDefault;

    return *this;
}

CoreTools::AppenderImpl::AppenderImpl(AppenderImpl&& rhs) noexcept
    : m_AppenderFlags{ rhs.m_AppenderFlags }, m_LogLevel{ rhs.m_LogLevel }, m_IsDefault{ rhs.m_IsDefault }, m_AppenderImplMutex{ std::move(rhs.m_AppenderImplMutex) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::AppenderImpl& CoreTools::AppenderImpl::operator=(AppenderImpl&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_AppenderFlags = rhs.m_AppenderFlags;
    m_LogLevel = rhs.m_LogLevel;
    m_IsDefault = rhs.m_IsDefault;
    m_AppenderImplMutex = std::move(rhs.m_AppenderImplMutex);

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, AppenderImpl)

CoreTools::LogLevel CoreTools::AppenderImpl::GetLogLevel() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_LogLevel;
}

CoreTools::AppenderPrint CoreTools::AppenderImpl::GetFlags() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_AppenderFlags;
}

void CoreTools::AppenderImpl::SetLogLevel(LogLevel level) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_LogLevel = level;
}

void CoreTools::AppenderImpl::Write(const LogMessage& message)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ScopedMutex scopedMutex{ m_AppenderImplMutex };

    if (m_LogLevel != LogLevel::Disabled && m_LogLevel <= message.GetLogLevel())
    {
        LogMessagePrefix prefix{ m_AppenderFlags, message.GetLogLevel(), message.GetLogFilterType() };
        LogMessagePostfix postfix{ m_AppenderFlags, message.GetLogLevel(), message.GetFunctionDescribed() };

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

    return m_IsDefault;
}

void CoreTools::AppenderImpl::SetIsDefault(bool isDefault) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_IsDefault = isDefault;
}
