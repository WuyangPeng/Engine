// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 18:06)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLOR_MANAGER_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLOR_MANAGER_IMPL_H

#include "CoreTools/LogManager/LogManagerFwd.h"
#include "CoreTools/Console/Flags/ConsoleColorsFlags.h"

#include <boost/noncopyable.hpp>

namespace CoreTools
{
	class LogConsoleTextColorsManagerImpl : protected boost::noncopyable
	{
	public:
		using ClassType = LogConsoleTextColorsManagerImpl;

	public:
		explicit LogConsoleTextColorsManagerImpl(LogLevel logLevel) noexcept;
		virtual ~LogConsoleTextColorsManagerImpl() noexcept;

		LogConsoleTextColorsManagerImpl(const LogConsoleTextColorsManagerImpl&) = delete;
		LogConsoleTextColorsManagerImpl& operator=(const LogConsoleTextColorsManagerImpl&) = delete;
		LogConsoleTextColorsManagerImpl(LogConsoleTextColorsManagerImpl&&) noexcept = delete;
		LogConsoleTextColorsManagerImpl& operator=(LogConsoleTextColorsManagerImpl&&) noexcept = delete;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		LogLevel GetLogLevel() const noexcept;

	protected:
		static TextColour GetTextColor(LogLevel logLevel) noexcept;
		static bool GetIntensified(LogLevel logLevel) noexcept;

	private:
		LogLevel m_LogLevel;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLOR_MANAGER_IMPL_H
