// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 18:06)

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
		explicit LogConsoleTextColorsManagerImpl(LogLevel logLevel);
		virtual ~LogConsoleTextColorsManagerImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		LogLevel GetLogLevel() const noexcept;

	protected:
		static TextColour GetTextColor(LogLevel logLevel);
		static bool GetIntensified(LogLevel logLevel);

	private:
		LogLevel m_LogLevel;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLOR_MANAGER_IMPL_H
