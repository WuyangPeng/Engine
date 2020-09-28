//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 11:37)

#ifndef SYSTEM_WINDOW_WINDOW_PROCESS_H
#define SYSTEM_WINDOW_WINDOW_PROCESS_H

#include "System/SystemDll.h"

#include "Fwd/WindowFlagsFwd.h"
#include "Using/WindowUsing.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace System
{
    // Windows进程相关函数调用。

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemMessage(WindowMsg* msg, WindowHWnd hwnd = nullptr) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE TranslateSystemMessage(const WindowMsg* msg) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE DispatchSystemMessage(const WindowMsg* msg) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE PeekSystemMessage(WindowMsg* msg, WindowHWnd hWnd = nullptr) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SystemTranslateAccelerator(WindowHWnd hwnd, WindowHAccel accel, WindowMsg* msg) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SystemValidateRect(WindowHWnd hwnd) noexcept;
    [[nodiscard]] WindowLResult SYSTEM_DEFAULT_DECLARE DefSystemWindowProc(WindowHWnd hwnd, WindowMessages msg, WindowWParam wParam, WindowLParam lParam) noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE PostSystemQuitMessage() noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE MessageBox(WindowHWnd hwnd, const String& information, const String& title) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE DestroySystemWindow(WindowHWnd hwnd) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SendSystemMessage(WindowHWnd hWnd, WindowMessages msg, WindowWParam wParam, WindowLParam lParam) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetCursorClientPos(WindowHWnd hwnd, WindowPoint& point) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetCursorClientPos(WindowHWnd hwnd, const WindowPoint& point) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SystemBeginPaint(WindowHWnd hwnd, WindowPaintStruct* ps) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SystemEndPaint(WindowHWnd hwnd, const WindowPaintStruct* ps) noexcept;

    [[nodiscard]] String SYSTEM_DEFAULT_DECLARE GetSystemCommandLine();

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE PostSystemMessage(WindowHWnd hwnd, WindowMessages msg, WindowWParam wParam, WindowLParam lParam) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemCursorPos(WindowPoint& point) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemCursorPos(const WindowPoint& point) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SystemClientToScreen(WindowHWnd hwnd, WindowPoint& point) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SystemScreenToClient(WindowHWnd hwnd, WindowPoint& point) noexcept;
}

#endif  // SYSTEM_WINDOW_WINDOW_PROCESS_H