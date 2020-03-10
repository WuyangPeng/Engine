// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:32)

#ifndef SYSTEM_CONSOLE_CONSOLE_COLORS_FWD_H
#define SYSTEM_CONSOLE_CONSOLE_COLORS_FWD_H 

#include "ConsoleFlagsFwd.h"
#include "System/Console/Using/ConsoleColoursUsing.h" 

namespace System
{
	bool SetSystemConsoleTextAttribute(WindowHandle handle, TextColour textColour, BackgroundColour backgroundColour, ConsoleCommon consoleCommon) noexcept;
	bool ReadSystemConsoleOutputAttribute(WindowHandle consolehandle, WindowWordPtr attribute, WindowDWord length, ConsoleCoord readCoord, WindowDWordPtr numberOfAttributesRead) noexcept;

	bool WriteSystemConsoleOutputAttribute(WindowHandle consolehandle, const WindowWord* attribute, WindowDWord length, ConsoleCoord writeCoord, WindowDWordPtr numberOfAttributesWritten) noexcept;

	bool FillSystemConsoleOutputAttribute(WindowHandle consolehandle, WindowWord attribute, WindowDWord length, ConsoleCoord writeCoord, WindowDWordPtr numberOfAttributesWritten) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_COLORS_FWD_H