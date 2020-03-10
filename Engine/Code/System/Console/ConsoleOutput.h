// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 13:36)

#ifndef SYSTEM_CONSOLE_CONSOLE_OUTPUT_H
#define SYSTEM_CONSOLE_CONSOLE_OUTPUT_H

#include "System/SystemDll.h"  

#include "Using/ConsoleOutputUsing.h"
#include "Using/ConsoleColoursUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// 控制台输出管理。

	bool SYSTEM_DEFAULT_DECLARE ReadSystemConsoleOutput(WindowHandle handle, ConsoleCharInfoPtr buffer, ConsoleCoord bufferSize,
														ConsoleCoord bufferCoord, ConsoleSmallRectPtr readRegion) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WriteSystemConsoleOutput(WindowHandle handle, const ConsoleCharInfo* buffer, ConsoleCoord bufferSize,
														 ConsoleCoord bufferCoord, ConsoleSmallRectPtr writeRegion) noexcept;

	bool SYSTEM_DEFAULT_DECLARE ReadSystemConsoleOutputCharacter(WindowHandle handle, TChar* character, WindowDWord length,
																 ConsoleCoord readCoord, WindowDWordPtr numberOfCharsRead) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WriteSystemConsoleOutputCharacter(WindowHandle handle, const TChar* character, WindowDWord length,
																  ConsoleCoord readCoord, WindowDWordPtr numberOfCharsWritten) noexcept;
	bool SYSTEM_DEFAULT_DECLARE FillSystemConsoleOutputCharacter(WindowHandle handle, TChar character, WindowDWord length, ConsoleCoord readCoord, WindowDWordPtr numberOfCharsWritten) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_OUTPUT_H