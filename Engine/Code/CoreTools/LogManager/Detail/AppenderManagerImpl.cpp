///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 22:31)

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

    return loggers.insert({ logger.GetLogFilterType(), logger }).second;
}

bool CoreTools::AppenderManagerImpl::RemoveLogger(LogFilter logFilter)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return (loggers.erase(logFilter) != 0);
}

bool CoreTools::AppenderManagerImpl::InsertAppender(const String& name, const Appender& appender)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (appender.GetLogLevel() != LogLevel::Disabled)
    {
        minLogLevel = std::min(minLogLevel, appender.GetLogLevel());
    }

    return appenders.insert({ name, appender }).second;
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

void CoreTools::AppenderManagerImpl::Write(const LogMessage& message)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto level = GetLogLevelType(message);

    if (level != LogLevel::Disabled && level <= message.GetLogLevel() && !message.GetMessageDescribe().empty())
    {
        DoWrite(message);
    }
}

void CoreTools::AppenderManagerImpl::Write(const String& name, const LogMessage& message)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto level = GetLogLevelType(message);

    if (level != LogLevel::Disabled && level <= message.GetLogLevel() && !message.GetMessageDescribe().empty() && GetDefaultAppenderName() != name)
    {
        DoWrite(name, message);
    }
}

void CoreTools::AppenderManagerImpl::WriteToConsole(const LogMessage& message)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    Write(GetConsoleAppenderName(), message);
}

// private
CoreTools::LogLevel CoreTools::AppenderManagerImpl::GetLogLevelType(const LogMessage& message) const
{
    const auto iter = loggers.find(message.GetLogFilterType());

    if (iter != loggers.cend())
        return iter->second.GetLogLevel();
    else
        return LogLevel::Disabled;
}

CoreTools::LogLevel CoreTools::AppenderManagerImpl::GetMinLogLevelType(LogFilter logFilter) const
{
    const auto iter = loggers.find(logFilter);

    if (iter != loggers.cend())
        return std::min(minLogLevel, iter->second.GetLogLevel());
    else
        return LogLevel::Disabled;
}

// private
void CoreTools::AppenderManagerImpl::DoWrite(const LogMessage& message)
{
    for (auto& value : appenders)
    {
        if (value.second.IsDefault())
        {
            value.second.Write(message);
        }
    }
}

void CoreTools::AppenderManagerImpl::DoWrite(const System::String& name, const LogMessage& message)
{
    const auto iter = appenders.find(name);

    if (iter != appenders.cend())
    {
        iter->second.Write(message);
    }
    else if (IsAppenderExist(GetDefaultAppenderName()) && CreateFileAppender(name))
    {
        DoWrite(name, message);
    }
}

void CoreTools::AppenderManagerImpl::ReloadAppenderFile()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    for (auto& value : appenders)
    {
        value.second.Reload();
    }
}

// static
const System::String CoreTools::AppenderManagerImpl::GetConsoleAppenderName()
{
    static const auto console = SYSTEM_TEXT("Console"s);

    return console;
}

// static
const System::String CoreTools::AppenderManagerImpl::GetDefaultAppenderName()
{
    static const auto defaultAppender = SYSTEM_TEXT("Default"s);

    return defaultAppender;
}

bool CoreTools::AppenderManagerImpl::IsAppenderExist(const String& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto iter = appenders.find(name);

    if (iter != appenders.cend())
        return true;
    else
        return false;
}

bool CoreTools::AppenderManagerImpl::CreateFileAppender(const String& fileName)
{
    const auto iter = appenders.find(GetDefaultAppenderName());

    if (iter != appenders.cend())
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
