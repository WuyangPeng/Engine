///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/28 14:53)

#include "CoreTools/CoreToolsExport.h"

#include "AnalysisAppenderManager.h"
#include "System/Helper/EnumOperator.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/LogManager/Appender.h"
#include "CoreTools/LogManager/AppenderManager.h"
#include "CoreTools/LogManager/LogFilterManager.h"
#include "CoreTools/LogManager/Logger.h"

using namespace std::literals;

namespace CoreTools
{
    constexpr auto gLogger = SYSTEM_TEXT("Logger"sv);
    constexpr auto gAppender = SYSTEM_TEXT("Appender"sv);
    constexpr auto gFlags = SYSTEM_TEXT("Flags"sv);
    constexpr auto gLogLevel = SYSTEM_TEXT("Level"sv);
    constexpr auto gAppenderFile = SYSTEM_TEXT("File"sv);
    constexpr auto gDirectory = SYSTEM_TEXT("Directory"sv);
    constexpr auto gFileName = SYSTEM_TEXT("FileName"sv);
    constexpr auto gMaxFileSize = SYSTEM_TEXT("MaxFileSize"sv);
    constexpr auto gBackup = SYSTEM_TEXT("Backup"sv);
    constexpr auto gExtension = SYSTEM_TEXT("Extension"sv);
}

CoreTools::AnalysisAppenderManager::AnalysisAppenderManager(std::string fileName)
    : appenderManager{ AppenderManager::Create() }, fileName{ std::move(fileName) }, mainTree{}, appenderTree{}
{
    Analysis();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

void CoreTools::AnalysisAppenderManager::Analysis()
{
    AnalysisJson();
    AnalysisLogger();
    AnalysisAppender();
}

void CoreTools::AnalysisAppenderManager::AnalysisJson()
{
    read_json(fileName, mainTree);
}

void CoreTools::AnalysisAppenderManager::AnalysisLogger()
{
    using UnderlyingType = std::underlying_type_t<LogLevel>;

    for (const auto& loggerTree : mainTree.get_child(gLogger.data()))
    {
        if (const auto filterType = LogFilterManager::GetLogFilterType(loggerTree.first);
            LogFilter::System <= filterType && filterType < LogFilter::MaxLogFilter)
        {
            InsertLogger(System::UnderlyingCastEnum<LogLevel>(loggerTree.second.get_value<UnderlyingType>()), filterType);
        }
    }
}

void CoreTools::AnalysisAppenderManager::InsertLogger(LogLevel levelType, LogFilter filterType)
{
    if (levelType < LogLevel::Disabled || LogLevel::MaxLogLevels <= levelType || !appenderManager->InsertLogger(Logger(filterType, levelType)))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("插入记录器失败！"))
    }
}

void CoreTools::AnalysisAppenderManager::AnalysisAppender()
{
    appenderTree = mainTree.get_child(gAppender.data());

    if (!(AnalysisConsoleAppender() && AnalysisFileAppender() && AnalysisFileConfigurationAppender()))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("插入输出位置失败！"))
    }
}

bool CoreTools::AnalysisAppenderManager::AnalysisConsoleAppender()
{
    const auto consoleTree = appenderTree.get_child(AppenderManager::GetConsoleAppenderName());

    const auto appenderFlags = System::UnderlyingCastEnum<AppenderPrint>(consoleTree.get(gFlags.data(), 0));

    if (const auto logLevelType = System::UnderlyingCastEnum<LogLevel>(consoleTree.get(gLogLevel.data(), 0));
        LogLevel::Disabled <= logLevelType && logLevelType < LogLevel::MaxLogLevels)
    {
        const Appender appender{ appenderFlags, logLevelType };

        return appenderManager->InsertConsoleAppender(appender);
    }
    else
    {
        return false;
    }
}

bool CoreTools::AnalysisAppenderManager::AnalysisFileAppender()
{
    auto result = true;

    const auto assoc = appenderTree.equal_range(gAppenderFile.data());

    for (auto assocIter = assoc.first, endIter = assoc.second; assocIter != endIter; ++assocIter)
    {
        if (!InsertAppender(assocIter->second))
        {
            result = false;
        }
    }

    return result;
}

bool CoreTools::AnalysisAppenderManager::InsertAppender(const BasicTree& fileTreeData)
{
    const auto directory = fileTreeData.get(gDirectory.data(), System::String{});
    const auto appenderFileName = fileTreeData.get(gFileName.data(), System::String{});
    const auto appenderPrint = System::UnderlyingCastEnum<AppenderPrint>(fileTreeData.get(gFlags.data(), 0));
    const auto level = System::UnderlyingCastEnum<LogLevel>(fileTreeData.get(gLogLevel.data(), 0));
    const auto maxFileSize = fileTreeData.get(gMaxFileSize.data(), 0);
    const auto backup = fileTreeData.get(gBackup.data(), false);
    const auto extension = fileTreeData.get(gExtension.data(), System::String{});

    if (!appenderFileName.empty() && LogLevel::Disabled <= level && level < LogLevel::MaxLogLevels)
    {
        const Appender appender{ directory, appenderFileName, appenderPrint, level, maxFileSize, backup, extension };

        return appenderManager->InsertAppender(appenderFileName, appender);
    }
    else
    {
        return false;
    }
}

bool CoreTools::AnalysisAppenderManager::AnalysisFileConfigurationAppender()
{
    const auto fileTreeData = appenderTree.get_child(AppenderManager::GetDefaultAppenderName());

    const auto directory = fileTreeData.get(gDirectory.data(), System::String{});
    const auto appenderPrint = System::UnderlyingCastEnum<AppenderPrint>(fileTreeData.get(gFlags.data(), 0));
    const auto logLevelType = System::UnderlyingCastEnum<LogLevel>(fileTreeData.get(gLogLevel.data(), 0));
    const auto maxFileSize = fileTreeData.get(gMaxFileSize.data(), 0);
    const auto backup = fileTreeData.get(gBackup.data(), false);
    const auto extension = fileTreeData.get(gExtension.data(), System::String{});

    if (LogLevel::Disabled <= logLevelType && logLevelType < LogLevel::MaxLogLevels)
    {
        const Appender appender{ directory, appenderPrint, logLevelType, maxFileSize, backup, extension };

        return appenderManager->InsertAppender(AppenderManager::GetDefaultAppenderName(), appender);
    }
    else
    {
        return false;
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::AnalysisAppenderManager::IsValid() const noexcept
{
    if (appenderManager != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

CoreTools::AnalysisAppenderManager::AppenderManagerSharedPtr CoreTools::AnalysisAppenderManager::GetAppenderManager() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return appenderManager;
}
