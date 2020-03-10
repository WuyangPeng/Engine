// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 18:05)

#ifndef CORE_TOOLS_LOG_MANAGER_ERROR_CONSOLE_TEXT_COLOR_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_ERROR_CONSOLE_TEXT_COLOR_MANAGER_H

#include "LogConsoleTextColorsManagerImpl.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "CoreTools/Console/ConsoleTextColorsManager.h" 

namespace CoreTools
{
	class ErrorConsoleTextColorsManager : public LogConsoleTextColorsManagerImpl
	{
	public:
		using ClassType = ErrorConsoleTextColorsManager;
		using ParentType = LogConsoleTextColorsManagerImpl;

	public:
		explicit ErrorConsoleTextColorsManager(LogLevel logLevel);
		virtual ~ErrorConsoleTextColorsManager();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

	private:
		using ErrorManager = ConsoleTextColorsManager<System::StandardHandle::Error>;

	private:
		ErrorManager m_ConsoleTextColorsManager;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_ERROR_CONSOLE_TEXT_COLOR_MANAGER_H
