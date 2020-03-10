// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:37)

#ifndef SYSTEM_WINDOW_WINDOW_USER_FWD_H 
#define SYSTEM_WINDOW_WINDOW_USER_FWD_H  

#include "WindowFlagsFwd.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	bool PostSystemThreadMessage(WindowDWord threadID, WindowMessages msg, WindowWParam wParam, WindowLParam lParam) noexcept;

	bool SystemInvalidateRect(WindowHWnd hwnd) noexcept;
	bool UpdateSystemWindows(WindowHWnd hwnd) noexcept;
}

#endif // SYSTEM_WINDOW_WINDOW_USER_FWD_H