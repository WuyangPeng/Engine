// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 16:38)

#ifndef SYSTEM_WINDOW_WINDOW_USER_H
#define SYSTEM_WINDOW_WINDOW_USER_H

#include "System/SystemDll.h"

#include "Using/WindowUsing.h"
#include "Fwd/WindowFlagsFwd.h"

namespace System
{
	// Window用户辅助函数。

	bool SYSTEM_DEFAULT_DECLARE PostSystemThreadMessage(WindowDWord threadID, WindowMessages msg, WindowWParam wParam, WindowLParam lParam) noexcept;

	bool SYSTEM_DEFAULT_DECLARE SystemInvalidateRect(WindowHWnd hwnd) noexcept;
	bool SYSTEM_DEFAULT_DECLARE UpdateSystemWindows(WindowHWnd hwnd) noexcept;
}

#endif // SYSTEM_WINDOW_WINDOW_REGISTER_H