// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 18:05)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLORS_MANAGER_FACTORY_H
#define CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLORS_MANAGER_FACTORY_H

#include "CoreTools/LogManager/LogManagerFwd.h"

#include <iosfwd>
#include <memory>

namespace CoreTools
{
	class LogConsoleTextColorsManagerImpl;

	class LogConsoleTextColorsManagerFactory
	{
	public:
		using ClassType = LogConsoleTextColorsManagerFactory;
		using LogConsoleTextColorsManagerPtr = std::shared_ptr<LogConsoleTextColorsManagerImpl>;

	public:
		static LogConsoleTextColorsManagerPtr Create(LogLevel logLevel);
		static LogConsoleTextColorsManagerPtr Create(std::ostream* osPtr, LogLevel logLevel);
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLORS_MANAGER_FACTORY_H
