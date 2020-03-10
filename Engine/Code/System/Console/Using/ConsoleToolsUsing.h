// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:35)

#ifndef SYSTEM_CONSOLE_CONSOLE_TOOLS_USING_H
#define SYSTEM_CONSOLE_CONSOLE_TOOLS_USING_H  

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	using ConsoleHandlerRoutine = PHANDLER_ROUTINE;
	using ConsoleReadConsoleControl = CONSOLE_READCONSOLE_CONTROL;
	using ConsoleReadConsoleControlPtr = PCONSOLE_READCONSOLE_CONTROL;

#else // !SYSTEM_PLATFORM_WIN32

	using ConsoleHandlerRoutine = int(*)(uint32_t ctrlType);

	struct ConsoleReadConsoleControl
	{
		unsigned long nLength;
		unsigned long nInitialChars;
		unsigned long dwCtrlWakeupMask;
		unsigned long dwControlKeyState;
	};

	using ConsoleReadConsoleControlPtr = ConsoleReadConsoleControl*;

#endif // SYSTEM_PLATFORM_WIN32   
}

#endif // SYSTEM_CONSOLE_CONSOLE_TOOLS_USING_H