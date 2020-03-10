// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:34)

#ifndef SYSTEM_CONSOLE_CONSOLE_TITLE_FWD_H
#define SYSTEM_CONSOLE_CONSOLE_TITLE_FWD_H

#include "System/Helper/UnicodeUsing.h"

namespace System
{
	WindowDWord GetSystemConsoleTitle(TChar* consoleTitle, WindowDWord size) noexcept;
	WindowDWord GetSystemConsoleOriginalTitle(TChar* consoleTitle, WindowDWord size) noexcept;
	bool SetSystemConsoleTitle(const TChar* consoleTitle) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_TITLE_FWD_H