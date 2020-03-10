// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:36)

#ifndef SYSTEM_WINDOW_WINDOW_PROCESS_FWD_H 
#define SYSTEM_WINDOW_WINDOW_PROCESS_FWD_H 

#include "WindowFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	bool GetSystemMessage(WindowMsg* msg, WindowHWnd hwnd = nullptr) noexcept;
	bool TranslateSystemMessage(const WindowMsg* msg) noexcept;
	bool DispatchSystemMessage(const WindowMsg* msg) noexcept;
	bool PeekSystemMessage(WindowMsg* msg, WindowHWnd hWnd = nullptr) noexcept;
	bool SystemTranslateAccelerator(WindowHWnd hwnd, WindowHAccel accel, WindowMsg* msg) noexcept;
	bool SystemValidateRect(WindowHWnd hwnd) noexcept;
	WindowLResult DefSystemWindowProc(WindowHWnd hwnd, WindowMessages msg, WindowWParam wParam, WindowLParam lParam) noexcept;
	int PostSystemQuitMessage() noexcept;

	bool MessageBox(WindowHWnd hwnd, const String& information, const String& title) noexcept;
	bool DestroySystemWindow(WindowHWnd hwnd) noexcept;

	bool SendSystemMessage(WindowHWnd hWnd, WindowMessages msg, WindowWParam wParam, WindowLParam lParam) noexcept;

	void GetCursorClientPos(WindowHWnd hwnd, WindowPoint& point) noexcept;
	void SetCursorClientPos(WindowHWnd hwnd, const WindowPoint& point) noexcept;
	bool SystemBeginPaint(WindowHWnd hwnd, WindowPaintStruct* ps) noexcept;
	bool SystemEndPaint(WindowHWnd hwnd, const WindowPaintStruct* ps) noexcept;

	String GetSystemCommandLine();

	bool PostSystemMessage(WindowHWnd hwnd, WindowMessages msg, WindowWParam wParam, WindowLParam lParam) noexcept;

	bool GetSystemCursorPos(WindowPoint& point) noexcept;
	bool SetSystemCursorPos(const WindowPoint& point) noexcept;
	bool SystemClientToScreen(WindowHWnd hwnd, WindowPoint& point) noexcept;
	bool SystemScreenToClient(WindowHWnd hwnd, WindowPoint& point) noexcept;
}

#endif // SYSTEM_WINDOW_WINDOW_PROCESS_FWD_H