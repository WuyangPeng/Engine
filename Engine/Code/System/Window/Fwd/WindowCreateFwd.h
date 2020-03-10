// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:36)

#ifndef SYSTEM_WINDOW_WINDOW_CREATE_FWD_H 
#define SYSTEM_WINDOW_WINDOW_CREATE_FWD_H  

#include "WindowFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h" 

namespace System
{
	bool AdjustSystemWindowRect(WindowRect* rect, WindowStyles styles) noexcept;
	WindowHWnd CreateSystemWindow(const String& className, const String& windowsName, WindowStyles styles, int x, int y,
								  WindowRect rect, WindowHWnd parent, WindowHMenu menu, WindowHInstance instance) noexcept;
	bool GetSystemClassName(WindowHWnd hwnd, String& className);
	bool GetWindowTextString(WindowHWnd hwnd, String& windowText);

	WindowHInstance GetHInstance() noexcept;

	bool RemoveMenuCloseButton(WindowHWnd hwnd) noexcept;

	WindowHMenu GetWindowSystemMenu(WindowHWnd hwnd) noexcept;

	bool RemoveSystemMenu(WindowHMenu menu, SystemMenuCommand position, MenuItem flags) noexcept;
}

#endif // SYSTEM_WINDOW_WINDOW_CREATE_FWD_H