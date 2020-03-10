// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 16:38)

#ifndef SYSTEM_WINDOW_WINDOW_PROCESS_H
#define SYSTEM_WINDOW_WINDOW_PROCESS_H

#include "System/SystemDll.h"

#include "Using/WindowUsing.h"
#include "Fwd/WindowFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace System
{
	// Windows进程相关函数调用。

	bool SYSTEM_DEFAULT_DECLARE GetSystemMessage(WindowMsg* msg, WindowHWnd hwnd = nullptr) noexcept;
	bool SYSTEM_DEFAULT_DECLARE TranslateSystemMessage(const WindowMsg* msg) noexcept;
	bool SYSTEM_DEFAULT_DECLARE DispatchSystemMessage(const WindowMsg* msg) noexcept;
	bool SYSTEM_DEFAULT_DECLARE PeekSystemMessage(WindowMsg* msg, WindowHWnd hWnd = nullptr) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SystemTranslateAccelerator(WindowHWnd hwnd, WindowHAccel accel, WindowMsg* msg) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SystemValidateRect(WindowHWnd hwnd) noexcept;
	WindowLResult SYSTEM_DEFAULT_DECLARE DefSystemWindowProc(WindowHWnd hwnd, WindowMessages msg, WindowWParam wParam, WindowLParam lParam) noexcept;
	int SYSTEM_DEFAULT_DECLARE PostSystemQuitMessage() noexcept;

	bool SYSTEM_DEFAULT_DECLARE MessageBox(WindowHWnd hwnd, const String& information, const String& title) noexcept;
	bool SYSTEM_DEFAULT_DECLARE DestroySystemWindow(WindowHWnd hwnd) noexcept;

	bool SYSTEM_DEFAULT_DECLARE SendSystemMessage(WindowHWnd hWnd, WindowMessages msg, WindowWParam wParam, WindowLParam lParam) noexcept;

	void SYSTEM_DEFAULT_DECLARE GetCursorClientPos(WindowHWnd hwnd, WindowPoint& point) noexcept;
	void SYSTEM_DEFAULT_DECLARE SetCursorClientPos(WindowHWnd hwnd, const WindowPoint& point) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SystemBeginPaint(WindowHWnd hwnd, WindowPaintStruct* ps) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SystemEndPaint(WindowHWnd hwnd, const WindowPaintStruct* ps) noexcept;

	String SYSTEM_DEFAULT_DECLARE GetSystemCommandLine();

	bool SYSTEM_DEFAULT_DECLARE PostSystemMessage(WindowHWnd hwnd, WindowMessages msg, WindowWParam wParam, WindowLParam lParam) noexcept;

	bool SYSTEM_DEFAULT_DECLARE GetSystemCursorPos(WindowPoint& point) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemCursorPos(const WindowPoint& point) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SystemClientToScreen(WindowHWnd hwnd, WindowPoint& point) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SystemScreenToClient(WindowHWnd hwnd, WindowPoint& point) noexcept;
}

#endif // SYSTEM_WINDOW_WINDOW_PROCESS_H