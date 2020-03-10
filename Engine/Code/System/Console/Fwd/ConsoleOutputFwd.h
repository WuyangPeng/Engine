// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:34)

#ifndef SYSTEM_CONSOLE_CONSOLE_OUTPUT_FWD_H
#define SYSTEM_CONSOLE_CONSOLE_OUTPUT_FWD_H 

#include "System/Helper/UnicodeUsing.h"
#include "System/Console/Using/ConsoleOutputUsing.h"
#include "System/Console/Using/ConsoleColoursUsing.h"

namespace System
{
	bool ReadSystemConsoleOutput(WindowHandle handle, ConsoleCharInfoPtr buffer, ConsoleCoord bufferSize, ConsoleCoord bufferCoord, ConsoleSmallRectPtr readRegion) noexcept;
	bool WriteSystemConsoleOutput(WindowHandle handle, const ConsoleCharInfo* buffer, ConsoleCoord bufferSize, ConsoleCoord bufferCoord, ConsoleSmallRectPtr writeRegion) noexcept;

	bool ReadSystemConsoleOutputCharacter(WindowHandle handle, TChar* character, WindowDWord length, ConsoleCoord readCoord, WindowDWordPtr numberOfCharsRead) noexcept;
	bool WriteSystemConsoleOutputCharacter(WindowHandle handle, const TChar* character, WindowDWord length, ConsoleCoord readCoord, WindowDWordPtr numberOfCharsWritten) noexcept;
	bool FillSystemConsoleOutputCharacter(WindowHandle handle, TChar character, WindowDWord length, ConsoleCoord readCoord, WindowDWordPtr numberOfCharsWritten) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_OUTPUT_FWD_H