// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 18:02)

#ifndef CORE_TOOLS_LOG_MANAGER_ANALYSIS_APPENDER_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_ANALYSIS_APPENDER_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/LogManager/LogManagerFwd.h"
#include "System/Helper/PragmaWarning/PropertyTree.h" 

#include <string>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE AnalysisAppenderManager
	{
	public:
		using ClassType = AnalysisAppenderManager;
		using AppenderManagerPtr = std::shared_ptr<AppenderManager>;

	public:
		explicit AnalysisAppenderManager(const std::string& fileName);

		CLASS_INVARIANT_DECLARE;

		AppenderManagerPtr GetAppenderManager() const noexcept;

	private:
		using String = System::String;
		using BasicTree = boost::property_tree::basic_ptree<String, String>;

	private:
		void Analysis();
		void AnalysisJson();
		void AnalysisLogger();
		void InsertLogger(LogLevel levelType, LogFilter filterType);
		void AnalysisAppender();
		bool AnalysisConsoleAppender();
		bool AnalysisFileAppender();
		bool AnalysisFileConfigurationAppender();
		bool InsertAppender(const BasicTree& fileTreeData);

	private:
		AppenderManagerPtr m_AppenderManager;
		std::string m_FileName;
		BasicTree m_MainTree;
		BasicTree m_AppenderTree;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_ANALYSIS_APPENDER_MANAGER_H


