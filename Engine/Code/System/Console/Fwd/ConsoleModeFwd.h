// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:34)

#ifndef SYSTEM_CONSOLE_CONSOLE_MODE_FWD_H
#define SYSTEM_CONSOLE_CONSOLE_MODE_FWD_H  

#include "ConsoleFlagsFwd.h"

namespace System
{
	bool GetSystemConsoleMode(WindowHandle consoleHandle, WindowDWordPtr mode) noexcept;
	bool SetSystemConsoleMode(WindowHandle consoleHandle, ConsoleInputMode mode) noexcept;
	bool SetSystemConsoleMode(WindowHandle consoleHandle, ConsoleOutputMode mode) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_MODE_FWD_H