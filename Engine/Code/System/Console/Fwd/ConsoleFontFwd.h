// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:33)

#ifndef SYSTEM_CONSOLE_CONSOLE_FONT_FWD_H
#define SYSTEM_CONSOLE_CONSOLE_FONT_FWD_H  

#include "System/Console/Using/ConsoleFontUsing.h"

namespace System
{
	bool GetCurrentSystemConsoleFont(WindowHandle consoleOutput, bool maximumWindow, ConsoleFontInfoPtr consoleCurrentFont) noexcept;
	bool GetCurrentSystemConsoleFont(WindowHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept;
	bool SetCurrentSystemConsoleFont(WindowHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept;
	ConsoleCoord GetSystemConsoleFontSize(WindowHandle consoleOutput, WindowDWord font) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_FONT_FWD_H