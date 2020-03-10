// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 16:37)

#ifndef SYSTEM_WINDOW_WINDOW_CREATE_H
#define SYSTEM_WINDOW_WINDOW_CREATE_H

#include "System/SystemDll.h"

#include "Using/WindowUsing.h"
#include "Fwd/WindowFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Helper/WindowsMacro.h" 

#include <string>

namespace System
{
	// 窗口创建和相关函数。

	constexpr int GetLowWord(WindowLParam param) noexcept
	{
		return LowWord(param);
	}

	constexpr int GetLowWord(WindowWParam param) noexcept
	{
		return LowWord(param);
	}

	constexpr int GetHighWord(WindowLParam param) noexcept
	{
		return HighWord(param);
	}

	constexpr int GetHighWord(WindowWParam param) noexcept
	{
		return HighWord(param);
	}

	bool SYSTEM_DEFAULT_DECLARE AdjustSystemWindowRect(WindowRect* rect, WindowStyles styles) noexcept;
	WindowHWnd SYSTEM_DEFAULT_DECLARE CreateSystemWindow(const String& className, const String& windowsName, WindowStyles styles, int x, int y,
														 WindowRect rect, WindowHWnd parent, WindowHMenu menu, WindowHInstance instance) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetSystemClassName(WindowHWnd hwnd, String& className);
	bool SYSTEM_DEFAULT_DECLARE GetWindowTextString(WindowHWnd hwnd, String& windowText);

	WindowHInstance SYSTEM_DEFAULT_DECLARE GetHInstance() noexcept;

	bool SYSTEM_DEFAULT_DECLARE RemoveMenuCloseButton(WindowHWnd hwnd) noexcept;

	WindowHMenu SYSTEM_DEFAULT_DECLARE GetWindowSystemMenu(WindowHWnd hwnd) noexcept;

	bool SYSTEM_DEFAULT_DECLARE RemoveSystemMenu(WindowHMenu menu, SystemMenuCommand position, MenuItem flags) noexcept;
}

#endif // SYSTEM_WINDOW_WINDOW_CREATE_H
