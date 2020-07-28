// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 18:06)

// 输出位置管理器类外部接口
#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "LogManagerFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(AppenderManagerImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE AppenderManager : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(AppenderManager);
		using String = System::String;

	public:
		AppenderManager();

		CLASS_INVARIANT_DECLARE;

		bool IsAppenderExist(const String& name) const;

		bool InsertLogger(const Logger& logger);
		bool RemoveLogger(LogFilter logFilter);
		bool InsertAppender(const String& name, const Appender& appender);
		bool InsertConsoleAppender(const Appender& appender);
		bool RemoveAppender(const String& name);
		void Clear() noexcept;

		void Write(const LogMessage& message);
		void Write(const String& name, const LogMessage& message);
		void WriteToConsole(const LogMessage& message);

		void ReloadAppenderFile();

		static const String GetConsoleAppenderName();
		static const String GetDefaultAppenderName();

	private:
		IMPL_TYPE_DECLARE(AppenderManager);
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_H
