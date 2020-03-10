// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:33)

#ifndef SYSTEM_CONSOLE_CONSOLE_INFO_FWD_H
#define SYSTEM_CONSOLE_CONSOLE_INFO_FWD_H

#include "System/Console/Using/ConsoleInfoUsing.h"

namespace System
{
	ConsoleCoord GetLargestSystemConsoleWindowSize(WindowHandle consoleOutput) noexcept;
	bool GetSystemConsoleHistoryInfo(ConsoleHistoryInfoPtr consoleHistoryInfo) noexcept;
	bool SetSystemConsoleHistoryInfo(ConsoleHistoryInfoPtr consoleHistoryInfo) noexcept;
	bool GetSystemConsoleSelectionInfo(ConsoleSelectionInfoPtr consoleSelectionInfo) noexcept;
	bool GetNumberOfSystemConsoleMouseButtons(WindowDWordPtr numberOfMouseButtons) noexcept;
	bool SetSystemConsoleWindowInfo(WindowHandle consoleOutput, bool absolute, const ConsoleSmallRect* consoleWindow) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_INFO_FWD_H