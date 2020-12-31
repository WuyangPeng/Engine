//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/15 14:05)

#include "CoreTools/CoreToolsExport.h"

#include "AnalysisAppenderManager.h"
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
    const System::String GetLogger()
    {
        static auto Logger = SYSTEM_TEXT("Logger"s);

        return Logger;
    }

    const System::String GetAppender()
    {
        static auto appender = SYSTEM_TEXT("Appender"s);

        return appender;
    }

    const System::String GetAppenderFlags()
    {
        static auto flags = SYSTEM_TEXT("Flags"s);

        return flags;
    }

    const System::String GetLogLevel()
    {
        static auto level = SYSTEM_TEXT("Level"s);

        return level;
    }

    const System::String GetAppenderFile()
    {
        static auto file = SYSTEM_TEXT("File"s);

        return file;
    }

    const System::String GetDirectory()
    {
        static auto directory = SYSTEM_TEXT("Directory"s);

        return directory;
    }

    const System::String GetFileName()
    {
        static auto fileName = SYSTEM_TEXT("FileName"s);

        return fileName;
    }

    const System::String GetMaxFileSize()
    {
        static auto maxFileSize = SYSTEM_TEXT("MaxFileSize"s);

        return maxFileSize;
    }

    const System::String GetBackup()
    {
        static auto backup = SYSTEM_TEXT("Backup"s);

        return backup;
    }

    const System::String GetExtension()
    {
        static auto extension = SYSTEM_TEXT("Extension"s);

        return extension;
    }
}

CoreTools::AnalysisAppenderManager::AnalysisAppenderManager(const string& fileName)
    : m_AppenderManager{ make_shared<AppenderManager>(DisableNotThrow::Disable) }, m_FileName{ fileName }, m_MainTree{}, m_AppenderTree{}
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
    read_json(m_FileName, m_MainTree);
}

// private
void CoreTools::AnalysisAppenderManager::AnalysisLogger()
{
    for (const auto& loggerPtree : m_MainTree.get_child(GetLogger()))
    {
        const auto filterType = LogFilterManager::GetLogFilterType(loggerPtree.first);

        if (LogFilter::System <= filterType && filterType < LogFilter::MaxLogFilter)
        {
            InsertLogger(loggerPtree.second.get_value<LogLevel>(), filterType);
        }
    }
}

// private
void CoreTools::AnalysisAppenderManager::InsertLogger(LogLevel levelType, LogFilter filterType)
{
    if (levelType < LogLevel::Disabled || LogLevel::MaxLogLevels <= levelType || !m_AppenderManager->InsertLogger(Logger(filterType, levelType)))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << SYSTEM_TEXT("插入记录器失败！")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

// private
void CoreTools::AnalysisAppenderManager::AnalysisAppender()
{
    m_AppenderTree = m_MainTree.get_child(GetAppender());

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
    auto consoleTree = m_AppenderTree.get_child(AppenderManager::GetConsoleAppenderName());

    auto appenderFlags = (consoleTree.get(GetAppenderFlags(), AppenderPrint::None));
    auto logLevelType = (consoleTree.get(GetLogLevel(), LogLevel::Disabled));

    if (LogLevel::Disabled <= logLevelType && logLevelType < LogLevel::MaxLogLevels)
    {
        Appender appender{ appenderFlags, logLevelType };

        return m_AppenderManager->InsertConsoleAppender(appender);
    }
    else
    {
        return false;
    }
}

// private
bool CoreTools::AnalysisAppenderManager::AnalysisFileAppender()
{
    bool result{ true };

    const auto assoc = m_AppenderTree.equal_range(GetAppenderFile());

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
    auto directory = fileTreeData.get(GetDirectory(), System::String{});
    auto fileName = fileTreeData.get(GetFileName(), System::String{});
    auto flags = fileTreeData.get(GetAppenderFlags(), AppenderPrint::None);
    auto level = fileTreeData.get(GetLogLevel(), LogLevel::Disabled);
    auto maxFileSize = fileTreeData.get(GetMaxFileSize(), 0);
    auto backup = fileTreeData.get(GetBackup(), false);
    auto extension = fileTreeData.get(GetExtension(), System::String{});

    if (!fileName.empty() && LogLevel::Disabled <= level && level < LogLevel::MaxLogLevels)
    {
        Appender appender{ directory, fileName, flags, level, maxFileSize, backup, extension };

        return m_AppenderManager->InsertAppender(fileName, appender);
    }
    else
    {
        return false;
    }
}

bool CoreTools::AnalysisAppenderManager::AnalysisFileConfigurationAppender()
{
    auto fileTreeData = m_AppenderTree.get_child(AppenderManager::GetDefaultAppenderName());

    auto directory = fileTreeData.get(GetDirectory(), System::String{});
    auto flags = fileTreeData.get(GetAppenderFlags(), AppenderPrint::None);
    auto logLevelType = fileTreeData.get(GetLogLevel(), LogLevel::Disabled);
    auto maxFileSize = fileTreeData.get(GetMaxFileSize(), 0);
    auto backup = fileTreeData.get(GetBackup(), false);
    auto extension = fileTreeData.get(GetExtension(), System::String{});

    if (LogLevel::Disabled <= logLevelType && logLevelType < LogLevel::MaxLogLevels)
    {
        Appender appender{ directory, flags, logLevelType, maxFileSize, backup, extension };

        return m_AppenderManager->InsertAppender(AppenderManager::GetDefaultAppenderName(), appender);
    }
    else
    {
        return false;
    }
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::AnalysisAppenderManager::IsValid() const noexcept
{
    if (m_AppenderManager != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

CoreTools::AnalysisAppenderManager::AppenderManagerPtr CoreTools::AnalysisAppenderManager::GetAppenderManager() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_AppenderManager;
}
