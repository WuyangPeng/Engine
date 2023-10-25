///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:54)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/Appender.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/LogManager/Logger.h"

using namespace std::literals;

CoreTools::AppenderManagerImpl::AppenderManagerImpl() noexcept
    : loggers{}, appenders{}, minLogLevel{ LogLevel::MaxLogLevels }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, AppenderManagerImpl)

bool CoreTools::AppenderManagerImpl::InsertLogger(const Logger& logger)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return loggers.emplace(logger.GetLogFilterType(), logger).second;
}

bool CoreTools::AppenderManagerImpl::RemoveLogger(LogFilter logFilter)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return loggers.erase(logFilter) != 0;
}

bool CoreTools::AppenderManagerImpl::InsertAppender(const String& name, const Appender& appender)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (appender.GetLogLevel() != LogLevel::Disabled)
    {
        minLogLevel = std::min(minLogLevel, appender.GetLogLevel());
    }

    return appenders.emplace(name, appender).second;
}

bool CoreTools::AppenderManagerImpl::InsertConsoleAppender(const Appender& appender)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return InsertAppender(GetConsoleAppenderName(), appender);
}

bool CoreTools::AppenderManagerImpl::RemoveAppender(const String& name)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return (appenders.erase(name) != 0);
}

void CoreTools::AppenderManagerImpl::Clear() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    loggers.clear();
    appenders.clear();
}

void CoreTools::AppenderManagerImpl::Write(const LogMessage& message) const
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (const auto level = GetLogLevelType(message); level != LogLevel::Disabled && level <= message.GetLogLevel() && !message.GetMessageDescribe().empty())
    {
        DoWrite(message);
    }
}

void CoreTools::AppenderManagerImpl::Write(const String& name, const LogMessage& message)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (const auto level = GetLogLevelType(message); level != LogLevel::Disabled && level <= message.GetLogLevel() && !message.GetMessageDescribe().empty() && GetDefaultAppenderName() != name)
    {
        DoWrite(name, message);
    }
}

CoreTools::LogLevel CoreTools::AppenderManagerImpl::GetLogLevelType(const LogMessage& message) const
{
    if (const auto iter = loggers.find(message.GetLogFilterType()); iter != loggers.cend())
        return iter->second.GetLogLevel();
    else
        return LogLevel::Disabled;
}

CoreTools::LogLevel CoreTools::AppenderManagerImpl::GetMinLogLevelType(LogFilter logFilter) const
{
    if (const auto iter = loggers.find(logFilter); iter != loggers.cend())
        return std::min(minLogLevel, iter->second.GetLogLevel());
    else
        return LogLevel::Disabled;
}

void CoreTools::AppenderManagerImpl::DoWrite(const LogMessage& message) const
{
    for (auto& element : appenders)
    {
        if (element.second.IsDefault())
        {
            element.second.Write(message);
        }
    }
}

void CoreTools::AppenderManagerImpl::DoWrite(const System::String& name, const LogMessage& message)
{
    if (const auto iter = appenders.find(name); iter != appenders.cend())
    {
        iter->second.Write(message);
    }
    else if (IsAppenderExist(GetDefaultAppenderName()) && CreateFileAppender(name))
    {
        DoWrite(name, message);
    }
}

System::String CoreTools::AppenderManagerImpl::GetConsoleAppenderName()
{
    static const auto console = SYSTEM_TEXT("Console"s);

    return console;
}

System::String CoreTools::AppenderManagerImpl::GetDefaultAppenderName()
{
    static const auto defaultAppender = SYSTEM_TEXT("Default"s);

    return defaultAppender;
}

bool CoreTools::AppenderManagerImpl::IsAppenderExist(const String& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (const auto iter = appenders.find(name); iter != appenders.cend())
        return true;
    else
        return false;
}

bool CoreTools::AppenderManagerImpl::CreateFileAppender(const String& fileName)
{
    if (const auto iter = appenders.find(GetDefaultAppenderName()); iter != appenders.cend())
    {
        const auto& appender = iter->second;

        const auto directory = appender.GetDirectory();
        const auto flags = appender.GetFlags();
        const auto level = appender.GetLogLevel();
        const auto maxFileSize = appender.GetMaxFileSize();
        const auto backup = appender.IsBackup();
        const auto extension = appender.GetExtensionName();

        if (!fileName.empty() && LogLevel::Disabled <= level && level < LogLevel::MaxLogLevels)
        {
            Appender newAppender{ directory, fileName, flags, level, maxFileSize, backup, extension };
            newAppender.SetIsDefault(false);

            return InsertAppender(fileName, newAppender);
        }
    }

    return false;
}
