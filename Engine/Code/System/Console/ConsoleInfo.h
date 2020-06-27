// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/09 21:14)

#ifndef SYSTEM_CONSOLE_CONSOLE_INFO_H
#define SYSTEM_CONSOLE_CONSOLE_INFO_H

#include "System/SystemDll.h"   

#include "Using/ConsoleInfoUsing.h"
#include "Using/ConsoleOutputUsing.h"
#include "Using/ConsoleColoursUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// 控制台信息的获取和设置。

	ConsoleCoord SYSTEM_DEFAULT_DECLARE GetLargestSystemConsoleWindowSize(WindowHandle consoleOutput) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleHistoryInfo(ConsoleHistoryInfoPtr consoleHistoryInfo) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleHistoryInfo(ConsoleHistoryInfoPtr consoleHistoryInfo) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleSelectionInfo(ConsoleSelectionInfoPtr consoleSelectionInfo) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetNumberOfSystemConsoleMouseButtons(WindowDWordPtr numberOfMouseButtons) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleWindowInfo(WindowHandle consoleOutput, bool absolute, const ConsoleSmallRect* consoleWindow) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_INFO_H