// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 18:06)

#ifndef CORE_TOOLS_LOG_MANAGER_OUTPUT_CONSOLE_TEXT_COLOR_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_OUTPUT_CONSOLE_TEXT_COLOR_MANAGER_H

#include "LogConsoleTextColorsManagerImpl.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "CoreTools/Console/ConsoleTextColorsManager.h"

namespace CoreTools
{
	class OutputConsoleTextColorsManager : public LogConsoleTextColorsManagerImpl
	{
	public:
		using ClassType = OutputConsoleTextColorsManager;
		using ParentType = LogConsoleTextColorsManagerImpl;

	public:
		explicit OutputConsoleTextColorsManager(LogLevel logLevel);
	 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		using OutputManager = ConsoleTextColorsManager<System::StandardHandle::Output>;

	private:
		OutputManager m_ConsoleTextColorsManager;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_OUTPUT_CONSOLE_TEXT_COLOR_MANAGER_H
