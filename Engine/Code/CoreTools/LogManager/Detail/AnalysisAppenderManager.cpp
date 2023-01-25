///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 21:45)

#include "CoreTools/CoreToolsExport.h"

#include "AnalysisAppenderManager.h"
#include "System/Helper/EnumOperator.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/LogManager/Appender.h"
#include "CoreTools/LogManager/AppenderManager.h"
#include "CoreTools/LogManager/LogFilterManager.h"
#include "CoreTools/LogManager/Logger.h"

using std::make_shared;
using std::string;
using namespace std::literals;

namespace CoreTools
{
    constexpr auto g_Logger = SYSTEM_TEXT("Logger"sv);
    constexpr auto g_Appender = SYSTEM_TEXT("Appender"sv);
    constexpr auto g_Flags = SYSTEM_TEXT("Flags"sv);
    constexpr auto g_LogLevel = SYSTEM_TEXT("Level"sv);
    constexpr auto g_AppenderFile = SYSTEM_TEXT("File"sv);
    constexpr auto g_Directory = SYSTEM_TEXT("Directory"sv);
    constexpr auto g_FileName = SYSTEM_TEXT("FileName"sv);
    constexpr auto g_MaxFileSize = SYSTEM_TEXT("MaxFileSize"sv);
    constexpr auto g_Backup = SYSTEM_TEXT("Backup"sv);
    constexpr auto g_Extension = SYSTEM_TEXT("Extension"sv);
}

CoreTools::AnalysisAppenderManager::AnalysisAppenderManager(const string& fileName)
    : appenderManager{ AppenderManager::Create() }, fileName{ fileName }, mainTree{}, appenderTree{}
{
    Analysis();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::AnalysisAppenderManager::Analysis()
{
    AnalysisJson();
    AnalysisLogger();
    AnalysisAppender();
}

// private
void CoreTools::AnalysisAppenderManager::AnalysisJson()
{
    read_json(fileName, mainTree);
}

// private
void CoreTools::AnalysisAppenderManager::AnalysisLogger()
{
    using UnderlyingType = std::underlying_type_t<LogLevel>;

    for (const auto& loggerPtree : mainTree.get_child(g_Logger.data()))
    {
        const auto filterType = LogFilterManager::GetLogFilterType(loggerPtree.first);

        if (LogFilter::System <= filterType && filterType < LogFilter::MaxLogFilter)
        {
            InsertLogger(System::UnderlyingCastEnum<LogLevel>(loggerPtree.second.get_value<UnderlyingType>()), filterType);
        }
    }
}

// private
void CoreTools::AnalysisAppenderManager::InsertLogger(LogLevel levelType, LogFilter filterType)
{
    if (levelType < LogLevel::Disabled || LogLevel::MaxLogLevels <= levelType || !appenderManager->InsertLogger(Logger(filterType, levelType)))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << SYSTEM_TEXT("插入记录器失败！")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

// private
void CoreTools::AnalysisAppenderManager::AnalysisAppender()
{
    appenderTree = mainTree.get_child(g_Appender.data());

    if (!(AnalysisConsoleAppender() && AnalysisFileAppender() && AnalysisFileConfigurationAppender()))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << SYSTEM_TEXT("插入输出位置失败！")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

// private
bool CoreTools::AnalysisAppenderManager::AnalysisConsoleAppender()
{
    const auto consoleTree = appenderTree.get_child(AppenderManager::GetConsoleAppenderName());

    const auto appenderFlags = System::UnderlyingCastEnum<AppenderPrint>(consoleTree.get(g_Flags.data(), 0));
    const auto logLevelType = System::UnderlyingCastEnum<LogLevel>(consoleTree.get(g_LogLevel.data(), 0));

    if (LogLevel::Disabled <= logLevelType && logLevelType < LogLevel::MaxLogLevels)
    {
        const Appender appender{ appenderFlags, logLevelType };

        return appenderManager->InsertConsoleAppender(appender);
    }
    else
    {
        return false;
    }
}

// private
bool CoreTools::AnalysisAppenderManager::AnalysisFileAppender()
{
    auto result = true;

    const auto assoc = appenderTree.equal_range(g_AppenderFile.data());

    for (auto assocIter = assoc.first, endIter = assoc.second; assocIter != endIter; ++assocIter)
    {
        if (!InsertAppender(assocIter->second))
        {
            result = false;
        }
    }

    return result;
}

// private
bool CoreTools::AnalysisAppenderManager::InsertAppender(const BasicTree& fileTreeData)
{
    const auto directory = fileTreeData.get(g_Directory.data(), System::String{});
    const auto appenderfileName = fileTreeData.get(g_FileName.data(), System::String{});
    const auto flags = System::UnderlyingCastEnum<AppenderPrint>(fileTreeData.get(g_Flags.data(), 0));
    const auto level = System::UnderlyingCastEnum<LogLevel>(fileTreeData.get(g_LogLevel.data(), 0));
    const auto maxFileSize = fileTreeData.get(g_MaxFileSize.data(), 0);
    const auto backup = fileTreeData.get(g_Backup.data(), false);
    const auto extension = fileTreeData.get(g_Extension.data(), System::String{});

    if (!appenderfileName.empty() && LogLevel::Disabled <= level && level < LogLevel::MaxLogLevels)
    {
        const Appender appender{ directory, appenderfileName, flags, level, maxFileSize, backup, extension };

        return appenderManager->InsertAppender(appenderfileName, appender);
    }
    else
    {
        return false;
    }
}

bool CoreTools::AnalysisAppenderManager::AnalysisFileConfigurationAppender()
{
    const auto fileTreeData = appenderTree.get_child(AppenderManager::GetDefaultAppenderName());

    const auto directory = fileTreeData.get(g_Directory.data(), System::String{});
    const auto flags = System::UnderlyingCastEnum<AppenderPrint>(fileTreeData.get(g_Flags.data(), 0));
    const auto logLevelType = System::UnderlyingCastEnum<LogLevel>(fileTreeData.get(g_LogLevel.data(), 0));
    const auto maxFileSize = fileTreeData.get(g_MaxFileSize.data(), 0);
    const auto backup = fileTreeData.get(g_Backup.data(), false);
    const auto extension = fileTreeData.get(g_Extension.data(), System::String{});

    if (LogLevel::Disabled <= logLevelType && logLevelType < LogLevel::MaxLogLevels)
    {
        const Appender appender{ directory, flags, logLevelType, maxFileSize, backup, extension };

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
