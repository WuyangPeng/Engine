// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 18:02)

#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_FACTORY_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

#include <string> 

namespace CoreTools
{
	class AppenderImpl;

	class CORE_TOOLS_HIDDEN_DECLARE AppenderFactory
	{
	public:
		using ClassType = AppenderFactory;
		using AppenderImplPtr = std::shared_ptr<AppenderImpl>;
		using String = System::String;

	public:
		static AppenderImplPtr CreateAppenderConsole(AppenderPrint appenderFlags, LogLevel logLevel);

		static AppenderImplPtr CreateAppenderFile(const String& directory, const String& fileName, AppenderPrint appenderFlags, LogLevel logLevel,
												  int maxFileSize, bool backup, const String& extensionName);

		static AppenderImplPtr CreateAppenderFile(const String& directory, AppenderPrint appenderFlags, LogLevel logLevel,
												  int maxFileSize, bool backup, const String& extensionName);
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_APPENDER_FACTORY_H
