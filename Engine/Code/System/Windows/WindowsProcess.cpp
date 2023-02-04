///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.1 (2023/02/02 14:42)

#include "System/SystemExport.h"

#include "WindowsProcess.h"
#include "Flags/WindowsProcessFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemOutput/Data/MessageBoxFlagsData.h"
#include "System/SystemOutput/Flags/DialogBoxCommandFlags.h"
#include "System/SystemOutput/Flags/MessageBoxFlags.h"
#include "System/SystemOutput/MessageBoxSelection.h"

using namespace std::literals;

bool System::GetSystemMessage(WindowsMsg* msg, WindowsHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    const auto gotMessage = ::GetMessage(msg, hwnd, 0, 0);

    if (gotMessage != 0 && gotMessage != -1)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(msg, hwnd);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::TranslateSystemMessage(const WindowsMsg* msg) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::TranslateMessage(msg) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(msg);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::DispatchSystemMessage(const WindowsMsg* msg) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::DispatchMessage(msg) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(msg);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::PeekSystemMessage(WindowsMsg* msg, WindowsHWnd hWnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::PeekMessage(msg, hWnd, 0, 0, EnumCastUnderlying(PeekMessageOptions::Remove)) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(msg, hwnd);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemTranslateAccelerator(WindowsHWnd hwnd, WindowsHAccel accel, WindowsMsg* msg) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::TranslateAccelerator(hwnd, accel, msg) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hwnd, accel, msg);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemValidateRect(WindowsHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::ValidateRect(hwnd, nullptr) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hwnd);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsLResult System::DefaultSystemWindowProcess(WindowsHWnd hwnd, WindowsMessages msg, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::DefWindowProc(hwnd, EnumCastUnderlying(msg), wParam, lParam);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hwnd, msg, wParam, lParam);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::PostSystemQuitMessage() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::PostQuitMessage(0);

    return 0;

#else  // !SYSTEM_PLATFORM_WIN32

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::DefaultMessageBox(WindowsHWnd hwnd, const String& information, const String& title) noexcept
{
    constexpr MessageBoxFlagsData flagsData{ MessageBoxType::YesNo,
                                             MessageBoxIcon::Exclamation,
                                             MessageBoxDefault::Button2,
                                             MessageBoxMode::ApplModal,
                                             MessageBoxMisc::NoMisc };

    if (MessageBoxSelection(hwnd, information.c_str(), title.c_str(), flagsData) == DialogBoxCommand::IDYes)
        return true;
    else
        return false;
}

bool System::DestroySystemWindow(WindowsHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::DestroyWindow(hwnd) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hwnd);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SendSystemMessage(WindowsHWnd hwnd, WindowsMessages msg, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SendMessage(hwnd, EnumCastUnderlying(msg), wParam, lParam) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hwnd, msg, wParam, lParam);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetCursorClientPos(WindowsHWnd hwnd, WindowsPoint& point) noexcept
{
    return GetSystemCursorPos(point) && SystemScreenToClient(hwnd, point);
}

bool System::SetCursorClientPos(WindowsHWnd hWnd, const WindowsPoint& point) noexcept
{
    WindowsPoint clientPoint{ point };

    return SystemClientToScreen(hWnd, clientPoint) && SetSystemCursorPos(clientPoint);
}

bool System::SystemBeginPaint(WindowsHWnd hwnd, WindowsPaintStruct* paintStruct) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::BeginPaint(hwnd, paintStruct) != nullptr)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hwnd, paintStruct);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemEndPaint(WindowsHWnd hwnd, const WindowsPaintStruct* paintStruct) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::EndPaint(hwnd, paintStruct) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hwnd, paintStruct);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::String System::GetSystemCommandLine()
{
#ifdef SYSTEM_PLATFORM_WIN32

    const TChar* commandLine{ ::GetCommandLine() };
    if (commandLine != nullptr)
        return commandLine;
    else
        return SYSTEM_TEXT(""s);

#else  // !SYSTEM_PLATFORM_WIN32

    return SYSTEM_TEXT(""s);

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::PostSystemMessage(WindowsHWnd hwnd, WindowsMessages msg, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::PostMessage(hwnd, EnumCastUnderlying(msg), wParam, lParam)) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hwnd, msg, wParam, lParam);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemCursorPos(WindowsPoint& point) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::GetCursorPos(&point)) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(point);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemCursorPos(const WindowsPoint& point) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::SetCursorPos(point.x, point.y)) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(point);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemClientToScreen(WindowsHWnd hwnd, WindowsPoint& point) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::ClientToScreen(hwnd, &point)) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hwnd, point);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemScreenToClient(WindowsHWnd hwnd, WindowsPoint& point) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::ScreenToClient(hwnd, &point)) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hwnd, point);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
