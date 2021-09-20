///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.6 (2021/07/03 21:53)

#ifndef SYSTEM_WINDOWS_WINDOWS_PROCESS_H
#define SYSTEM_WINDOWS_WINDOWS_PROCESS_H

#include "System/SystemDll.h"

#include "Fwd/WindowsFlagsFwd.h"
#include "Using/WindowsUsing.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace System
{
    // Windows������غ������á�

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemMessage(WindowsMsg* msg, WindowsHWnd hwnd = nullptr) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE TranslateSystemMessage(const WindowsMsg* msg) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE DispatchSystemMessage(const WindowsMsg* msg) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE PeekSystemMessage(WindowsMsg* msg, WindowsHWnd hWnd = nullptr) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SystemTranslateAccelerator(WindowsHWnd hwnd, WindowsHAccel accel, WindowsMsg* msg) noexcept;

    NODISCARD WindowsLResult SYSTEM_DEFAULT_DECLARE DefSystemWindowProc(WindowsHWnd hwnd, WindowsMessages msg, WindowsWParam wParam, WindowsLParam lParam) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE PostSystemQuitMessage() noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SystemValidateRect(WindowsHWnd hwnd) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE MessageBox(WindowsHWnd hwnd, const String& information, const String& title) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE DestroySystemWindow(WindowsHWnd hwnd) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SendSystemMessage(WindowsHWnd hWnd, WindowsMessages msg, WindowsWParam wParam, WindowsLParam lParam) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE PostSystemMessage(WindowsHWnd hwnd, WindowsMessages msg, WindowsWParam wParam, WindowsLParam lParam) noexcept;

    NODISCARD String SYSTEM_DEFAULT_DECLARE GetSystemCommandLine();

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetCursorClientPos(WindowsHWnd hwnd, WindowsPoint& point) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetCursorClientPos(WindowsHWnd hwnd, const WindowsPoint& point) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SystemBeginPaint(WindowsHWnd hwnd, WindowsPaintStruct* ps) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SystemEndPaint(WindowsHWnd hwnd, const WindowsPaintStruct* ps) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemCursorPos(WindowsPoint& point) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemCursorPos(const WindowsPoint& point) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SystemClientToScreen(WindowsHWnd hwnd, WindowsPoint& point) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SystemScreenToClient(WindowsHWnd hwnd, WindowsPoint& point) noexcept;
}

#endif  // SYSTEM_WINDOWS_WINDOWS_PROCESS_H