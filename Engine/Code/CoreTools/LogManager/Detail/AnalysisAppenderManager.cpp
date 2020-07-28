// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 09:55)

#include "CoreTools/CoreToolsExport.h"

#include "AnalysisAppenderManager.h"
#include "CoreTools/LogManager/Logger.h"
#include "CoreTools/LogManager/Appender.h"
#include "CoreTools/LogManager/AppenderManager.h"
#include "CoreTools/LogManager/LogFilterManager.h"
#include "System/Helper/PragmaWarning/PropertyTree.h" 
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

namespace CoreTools
{
	const System::String g_Logger{ SYSTEM_TEXT("Logger") };
	const System::String g_Appender{ SYSTEM_TEXT("Appender") };
	const System::String g_AppenderFlags{ SYSTEM_TEXT("Flags") };
	const System::String g_LogLevel{ SYSTEM_TEXT("Level") }; 
	const System::String g_AppenderFile{ SYSTEM_TEXT("File") };
	const System::String g_Directory{ SYSTEM_TEXT("Directory") };
	const System::String g_FileName{ SYSTEM_TEXT("FileName") }; 
	const System::String g_MaxFileSize{ SYSTEM_TEXT("MaxFileSize") };
	const System::String g_Backup{ SYSTEM_TEXT("Backup") }; 
	const System::String g_Extension{ SYSTEM_TEXT("Extension") }; 
}
#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26489)
CoreTools::AnalysisAppenderManager
	::AnalysisAppenderManager(const string& fileName)
	:m_AppenderManager{ make_shared<AppenderManager>() }, m_FileName{ fileName }, m_MainTree{}, m_AppenderTree{}
{
	Analysis();

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::AnalysisAppenderManager
	::Analysis()
{
	AnalysisJson();
	AnalysisLogger();
	AnalysisAppender();
}

// private
void CoreTools::AnalysisAppenderManager
	::AnalysisJson()
{
	read_json(m_FileName, m_MainTree);
}

// private
void CoreTools::AnalysisAppenderManager
	::AnalysisLogger()
{
	for (const auto& loggerPtree : m_MainTree.get_child(g_Logger))
	{
		const auto filterType = LogFilterManager::GetLogFilterType(loggerPtree.first);

		if (LogFilter::System <= filterType && filterType < LogFilter::MaxLogFilter)
		{
			InsertLogger(loggerPtree.second.get_value<LogLevel>(), filterType);
		}
	}
}

// private
void CoreTools::AnalysisAppenderManager
	::InsertLogger(LogLevel levelType, LogFilter filterType)
{
	if (levelType < LogLevel::Disabled || LogLevel::MaxLogLevels <= levelType || !m_AppenderManager->InsertLogger(Logger(filterType, levelType)))
	{
		LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
			<< SYSTEM_TEXT("≤Â»Îº«¬º∆˜ ß∞‹£°")
			<< LogAppenderIOManageSign::TriggerAssert;
	}
}

// private
void CoreTools::AnalysisAppenderManager
	::AnalysisAppender()
{
	m_AppenderTree = m_MainTree.get_child(g_Appender);

	if (!(AnalysisConsoleAppender() && AnalysisFileAppender() && AnalysisFileConfigurationAppender()))
	{
		LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
			<< SYSTEM_TEXT("≤Â»Î ‰≥ˆŒª÷√ ß∞‹£°")
			<< LogAppenderIOManageSign::TriggerAssert;
	}
}

// private
bool CoreTools::AnalysisAppenderManager
	::AnalysisConsoleAppender()
{
	auto consoleTree = m_AppenderTree.get_child(AppenderManager::GetConsoleAppenderName());

	auto appenderFlags = (consoleTree.get(g_AppenderFlags, AppenderPrint::None));
	auto logLevelType = (consoleTree.get(g_LogLevel, LogLevel::Disabled));

	if (LogLevel::Disabled <= logLevelType && logLevelType < LogLevel::MaxLogLevels)
	{
		Appender appender{ appenderFlags,logLevelType };

		return m_AppenderManager->InsertConsoleAppender(appender);
	}
	else
	{
		return false;
	}
}

// private
bool CoreTools::AnalysisAppenderManager
	::AnalysisFileAppender()
{
	bool result{ true };

	const auto assoc = m_AppenderTree.equal_range(g_AppenderFile);

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
bool CoreTools::AnalysisAppenderManager
	::InsertAppender(const BasicTree& fileTreeData)
{
	auto directory = fileTreeData.get(g_Directory, System::String{});
	auto fileName = fileTreeData.get(g_FileName, System::String{});
	auto flags = fileTreeData.get(g_AppenderFlags, AppenderPrint::None);
	auto level = fileTreeData.get(g_LogLevel, LogLevel::Disabled);
	auto maxFileSize = fileTreeData.get(g_MaxFileSize, 0);
	auto backup = fileTreeData.get(g_Backup, false);
	auto extension = fileTreeData.get(g_Extension, System::String{});

	if (!fileName.empty() && LogLevel::Disabled <= level && level < LogLevel::MaxLogLevels)
	{
		Appender appender{ directory,fileName,flags,level,maxFileSize,backup,extension };

		return m_AppenderManager->InsertAppender(fileName, appender);
	}
	else
	{
		return false;
	}
}

bool CoreTools::AnalysisAppenderManager
	::AnalysisFileConfigurationAppender()
{
	auto fileTreeData = m_AppenderTree.get_child(AppenderManager::GetDefaultAppenderName());

	auto directory = fileTreeData.get(g_Directory, System::String{});
	auto flags = fileTreeData.get(g_AppenderFlags, AppenderPrint::None);
	auto logLevelType = fileTreeData.get(g_LogLevel, LogLevel::Disabled);
	auto maxFileSize = fileTreeData.get(g_MaxFileSize, 0);
	auto backup = fileTreeData.get(g_Backup, false);
	auto extension = fileTreeData.get(g_Extension, System::String{});

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
bool CoreTools::AnalysisAppenderManager
	::IsValid() const noexcept
{
	if (m_AppenderManager != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

CoreTools::AnalysisAppenderManager::AppenderManagerPtr	CoreTools::AnalysisAppenderManager
	::GetAppenderManager() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_AppenderManager;
}



#include STSTEM_WARNING_POP