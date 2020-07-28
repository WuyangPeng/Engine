// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 10:27)

#include "CoreTools/CoreToolsExport.h"

#include "LogImpl.h"
#include "AnalysisAppenderManager.h"
#include "CoreTools/LogManager/Logger.h"
#include "CoreTools/LogManager/Appender.h"
#include "CoreTools/LogManager/LogFilterManager.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::make_shared;
using boost::property_tree::ptree_error;

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::LogImpl
	::LogImpl()
	:m_AppenderManager{ make_shared<AppenderManager>() }, m_LogAppenderIOManagerContainer{}, m_ErrorLogAppenderIOManager{}
{
	InitIOManager();

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26487)
// private
void CoreTools::LogImpl
	::InitIOManager()
{
	for (auto logLevelType = LogLevel::Trace; logLevelType < LogLevel::MaxLogLevels; ++logLevelType)
	{
		m_LogAppenderIOManagerContainer.insert({ logLevelType, make_shared<LogAppenderIOManager>(logLevelType, m_AppenderManager) });
	}
}

void CoreTools::LogImpl
	::ResetIOManager()
{
	for (auto& value : m_LogAppenderIOManagerContainer)
	{
		value.second->SetAppenderManager(m_AppenderManager);
	}
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::LogImpl
	::IsValid() const noexcept
{
	try
	{
 
#include STSTEM_WARNING_PUSH
		#include SYSTEM_WARNING_DISABLE(26447)
		if (m_AppenderManager != nullptr &&	m_LogAppenderIOManagerContainer.find(LogLevel::Disabled) == m_LogAppenderIOManagerContainer.cend())
		{
			return true;
		}
		else
		{
			return false;
		}
		#include STSTEM_WARNING_POP
	}
	catch (...)
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

void CoreTools::LogImpl
	::InsertAppender(const String& name, const Appender& appender)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_AppenderManager->InsertAppender(name, appender);
}

void CoreTools::LogImpl
	::RemoveAppender(const String& name)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_AppenderManager->RemoveAppender(name);
}

void CoreTools::LogImpl
	::LoadConfiguration(const string& fileName)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	try
	{
		AnalysisAppenderManager analysis{ fileName };

		m_AppenderManager = analysis.GetAppenderManager();

		ResetIOManager();
	}
	catch (const ptree_error& error)
	{
		LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
			<< error.what()
			<< LogAppenderIOManageSign::TriggerAssert;
	}
}

CoreTools::LogAppenderIOManager& CoreTools::LogImpl
	::OutTrace() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return Find(LogLevel::Trace);
}

CoreTools::LogAppenderIOManager& CoreTools::LogImpl
	::OutDebug() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return Find(LogLevel::Debug);
}

CoreTools::LogAppenderIOManager& CoreTools::LogImpl
	::OutInfo() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return Find(LogLevel::Info);
}

CoreTools::LogAppenderIOManager& CoreTools::LogImpl
	::OutWarn() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return Find(LogLevel::Warn);
}

CoreTools::LogAppenderIOManager& CoreTools::LogImpl
	::OutError() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return Find(LogLevel::Error);
}

CoreTools::LogAppenderIOManager& CoreTools::LogImpl
	::OutFatal() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return Find(LogLevel::Fatal);
}

// private
CoreTools::LogAppenderIOManager& CoreTools::LogImpl
	::Find(LogLevel type) noexcept
{
	try
	{
		const auto iter = m_LogAppenderIOManagerContainer.find(type);

		if (iter != m_LogAppenderIOManagerContainer.cend())
		{
			return *iter->second;
		}
		else
		{			 	
			CORE_TOOLS_ASSERTION_2(false,"日志库出现了错误,找不到对应的Appender。");		 			
		}
	}
	catch (...)
	{
		 
	}

	return m_ErrorLogAppenderIOManager;
}

void CoreTools::LogImpl
	::ReloadAppenderFile()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_AppenderManager->ReloadAppenderFile();
}

#include STSTEM_WARNING_POP