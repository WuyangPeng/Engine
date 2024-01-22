/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 00:41)

#include "CoreTools/CoreToolsExport.h"

#include "LogAppenderIOManagerImpl.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/SystemOutput/OutputDebugString.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/LogManager/AppenderManager.h"
#include "CoreTools/LogManager/LogAsynchronous.h"
#include "CoreTools/LogManager/LogMessage.h"

using namespace std::literals;

CoreTools::LogAppenderIOManagerImpl::LogAppenderIOManagerImpl(LogLevel logLevel, AppenderManagerSharedPtr appenderManager) noexcept
    : logLevel{ logLevel },
      currentAppenderManager{ std::move(appenderManager) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::LogAppenderIOManagerImpl::LogAppenderIOManagerImpl() noexcept
    : logLevel{ LogLevel::Disabled },
      currentAppenderManager{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::LogAppenderIOManagerImpl::IsValid() const noexcept
{
    if (logLevel != LogLevel::MaxLogLevels)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

CoreTools::LogAppenderIOManagerImpl& CoreTools::LogAppenderIOManagerImpl::operator<<(const LogMessage& message)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (!message.IsDisabled())
    {
        if (Write(message))
        {
            TriggerAssert(message);
        }
    }

    return *this;
}

bool CoreTools::LogAppenderIOManagerImpl::Write(const LogMessage& message)
{
    if (logLevel != LogLevel::Disabled && message.GetLogLevel() != LogLevel::Disabled && message.GetLogLevel() >= logLevel && currentAppenderManager != nullptr)
    {
        if (const auto fileName = message.GetFileName(); !fileName.empty())
        {
            LOG_ASYNCHRONOUS_SINGLETON.Registered(fileName, message, currentAppenderManager);

            if (message.HasAlwaysConsole() && fileName != AppenderManager::GetConsoleAppenderName())
            {
                LOG_ASYNCHRONOUS_SINGLETON.Registered(AppenderManager::GetConsoleAppenderName(), message, currentAppenderManager);
            }
        }
        else
        {
            LOG_ASYNCHRONOUS_SINGLETON.Registered(message, currentAppenderManager);
        }

        return true;
    }

    return false;
}

void CoreTools::LogAppenderIOManagerImpl::TriggerAssert(const LogMessage& message)
{
    if (message.HasTriggerAssert())
    {
        const auto assertMessage = StringConversion::StandardConversionMultiByte(message.GetMessageDescribe());

        CORE_TOOLS_ASSERTION_USE_FUNCTION_DESCRIBED_1(false, message.GetFunctionDescribed(), assertMessage.c_str());
    }
}

void CoreTools::LogAppenderIOManagerImpl::SetAppenderManager(const AppenderManagerSharedPtr& appenderManager) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    currentAppenderManager = appenderManager;
}
