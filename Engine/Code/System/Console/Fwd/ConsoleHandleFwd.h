// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:33)

#ifndef SYSTEM_CONSOLE_CONSOLE_HANDLE_FWD_H
#define SYSTEM_CONSOLE_CONSOLE_HANDLE_FWD_H 

#include "ConsoleFlagsFwd.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	WindowHandle GetStandardHandle(StandardHandle standardhandle) noexcept;
	bool IsHandleValid(WindowHandle handle) noexcept;
	bool SetStandardHandle(StandardHandle standardhandle, WindowHandle handle) noexcept;
	bool SetStandardHandle(StandardHandle standardhandle, WindowHandle handle, WindowHandlePtr previousHandle) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_HANDLE_FWD_H