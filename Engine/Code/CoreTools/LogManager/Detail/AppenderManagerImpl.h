// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 18:05)

// 输出位置管理器类内部接口
#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

#include <boost/noncopyable.hpp>
#include <map>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE AppenderManagerImpl : private boost::noncopyable
	{
	public:
		using ClassType = AppenderManagerImpl;
		using String = System::String;

	public:
		AppenderManagerImpl();

		CLASS_INVARIANT_DECLARE;

		bool IsAppenderExist(const String& name) const;

		bool InsertLogger(const Logger& logger);
		bool RemoveLogger(LogFilter logFilter);
		bool InsertAppender(const String& name, const Appender& appender);
		bool InsertConsoleAppender(const Appender& appender);
		bool RemoveAppender(const String& name);
		void Clear();

		void Write(const LogMessage& message);
		void Write(const String& name, const LogMessage& message);
		void WriteToConsole(const LogMessage& message);

		void ReloadAppenderFile();

		static const String GetConsoleAppenderName();
		static const String GetDefaultAppenderName();

	private:
		using LoggerContainer = std::map<LogFilter, Logger>;
		using AppenderContainer = std::map<String, Appender>;

	private:
		LogLevel GetLogLevelType(const LogMessage& message) const;
		void DoWrite(const LogMessage& message);
		void DoWrite(const String& name, const LogMessage& message);
		bool CreateFileAppender(const String& fileName);

	private:
		static const String sm_ConsoleAppenderName;
		static const String sm_DefaultAppenderName;

	private:
		LoggerContainer m_Loggers;
		AppenderContainer m_Appenders;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_IMPL_H
