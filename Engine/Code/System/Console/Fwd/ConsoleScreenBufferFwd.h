// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:34)

#ifndef SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_FWD_H
#define SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_FWD_H  

#include "ConsoleFlagsFwd.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"
#include "System/Console/Using/ConsoleOutputUsing.h" 
#include "System/Console/Using/ConsoleScreenBufferUsing.h"

namespace System
{
	WindowHandle CreateSystemConsoleScreenBuffer(DesiredAccessGeneric desiredAccess, ConsoleScreenBufferShareMode shareMode, const WindowSecurityAttributes* securityAttributes) noexcept;
	bool CloseSystemConsole(WindowHandle consoleHandle) noexcept;
	void SetDefaultConsoleSecurityAttributes(WindowSecurityAttributes& securityAttributes, bool inheritHandle) noexcept;

	bool GetSystemConsoleScreenBufferInfo(WindowHandle consoleOutput, ConsoleScreenBufferInfoPtr consoleScreenBufferInfo) noexcept;
	bool GetSystemConsoleScreenBufferInfo(WindowHandle consoleOutput, ConsoleScreenBufferInfoExPtr consoleScreenBufferInfoEx) noexcept;
	bool SetConsoleHandleScreenBufferInfo(WindowHandle consoleOutput, ConsoleScreenBufferInfoExPtr consoleScreenBufferInfoEx) noexcept;
	bool SetSystemConsoleScreenBufferSize(WindowHandle consoleOutput, ConsoleCoord size) noexcept;
	bool ScrollSystemConsoleScreenBuffer(WindowHandle consoleOutput, const ConsoleSmallRect* scrollRectangle, const ConsoleSmallRect* clipRectangle,
										 ConsoleCoord destinationOrigin, const ConsoleCharInfo* fill) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_FWD_H