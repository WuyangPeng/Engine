// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 18:06)

// ��־���ڲ��ӿ�
#ifndef CORE_TOOLS_LOG_MANAGER_LOG_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_LOG_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/LogManager/AppenderManager.h"
#include "CoreTools/LogManager/LogAppenderIOManager.h"

#include <map>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE LogImpl
	{
	public:
		using ClassType = LogImpl;
		using String = System::String;

	public:
		LogImpl();

		CLASS_INVARIANT_DECLARE;

		void InsertAppender(const String& name, const Appender& appender);
		void RemoveAppender(const String& name);
		void LoadConfiguration(const std::string& fileName);
		void ReloadAppenderFile();

		LogAppenderIOManager& OutTrace() noexcept;
		LogAppenderIOManager& OutDebug() noexcept;
		LogAppenderIOManager& OutInfo() noexcept;
		LogAppenderIOManager& OutWarn() noexcept;
		LogAppenderIOManager& OutError() noexcept;
		LogAppenderIOManager& OutFatal() noexcept;

	private:
		using LogAppenderIOManagerPtr = std::shared_ptr<LogAppenderIOManager>;
		using AppenderManagerPtr = std::shared_ptr<AppenderManager>;
		using LogAppenderIOManagerContainer = std::map<LogLevel, LogAppenderIOManagerPtr>;

	private:
		void InitIOManager();
		void ResetIOManager();
		LogAppenderIOManager& Find(LogLevel type) noexcept;

	private:
		AppenderManagerPtr m_AppenderManager;
		LogAppenderIOManagerContainer m_LogAppenderIOManagerContainer;
		LogAppenderIOManager m_ErrorLogAppenderIOManager;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_LOG_IMPL_H


