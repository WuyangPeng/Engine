// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 18:06)

// 日志类外部接口
#ifndef CORE_TOOLS_LOG_MANAGER_LOG_H
#define CORE_TOOLS_LOG_MANAGER_LOG_H

#include "CoreTools/CoreToolsDll.h"

#include "LogManagerFwd.h"
#include "System/Helper/UnicodeUsing.h"
 
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

CORE_TOOLS_EXPORT_SHARED_PTR(LogImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE Log : public CoreTools::Singleton<Log>
	{
		SINGLETON_INITIALIZE_DECLARE(Log);
		using String = System::String;

	public:
		CLASS_INVARIANT_DECLARE;

		void InsertAppender(const String& name, const Appender& appenderPtr);
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
		SINGLETON_MEMBER_DECLARE(Log);
	};
}

#define LOG_SINGLETON CoreTools::Log::GetSingleton()

#endif // CORE_TOOLS_LOG_MANAGER_LOG_H


