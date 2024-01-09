/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 15:41)

#ifndef SYSTEM_WINDOWS_WINDOWS_PROCESS_H
#define SYSTEM_WINDOWS_WINDOWS_PROCESS_H

#include "System/SystemDll.h"

#include "Fwd/WindowsFlagsFwd.h"
#include "Using/WindowsUsing.h"
#include "System/Helper/UnicodeUsing.h"

// Windows进程相关函数调用。
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemMessage(WindowsMessage* message, WindowsHWnd hWnd = nullptr) noexcept;
    bool SYSTEM_DEFAULT_DECLARE TranslateSystemMessage(const WindowsMessage* message) noexcept;
    bool SYSTEM_DEFAULT_DECLARE DispatchSystemMessage(const WindowsMessage* message) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE PeekSystemMessage(WindowsMessage* message, WindowsHWnd hWnd = nullptr) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SystemTranslateAccelerator(WindowsHWnd hWnd, WindowsHAccelerator accelerator, WindowsMessage* message) noexcept;

    NODISCARD WindowsLResult SYSTEM_DEFAULT_DECLARE DefaultSystemWindowProcess(WindowsHWnd hWnd, WindowsMessages message, WindowsWParam wParam, WindowsLParam lParam) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE PostSystemQuitMessage() noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SystemValidateRect(WindowsHWnd hWnd) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE DefaultMessageBox(WindowsHWnd hWnd, const String& information, const String& title) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE DestroySystemWindow(WindowsHWnd hWnd) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SendSystemMessage(WindowsHWnd hWnd, WindowsMessages message, WindowsWParam wParam, WindowsLParam lParam) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE PostSystemMessage(WindowsHWnd hWnd, WindowsMessages message, WindowsWParam wParam, WindowsLParam lParam) noexcept;

    NODISCARD String SYSTEM_DEFAULT_DECLARE GetSystemCommandLine();

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetCursorClientPos(WindowsHWnd hWnd, WindowsPoint& point) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetCursorClientPos(WindowsHWnd hWnd, const WindowsPoint& point) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SystemBeginPaint(WindowsHWnd hWnd, WindowsPaintStruct* paintStruct) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SystemEndPaint(WindowsHWnd hWnd, const WindowsPaintStruct* paintStruct) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemCursorPos(WindowsPoint& point) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemCursorPos(const WindowsPoint& point) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SystemClientToScreen(WindowsHWnd hWnd, WindowsPoint& point) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SystemScreenToClient(WindowsHWnd hWnd, WindowsPoint& point) noexcept;
}

#endif  // SYSTEM_WINDOWS_WINDOWS_PROCESS_H