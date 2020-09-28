//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 14:44)

#include "System/SystemExport.h"

#include "WindowProcess.h"
#include "Flags/WindowProcessFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemOutput/Data/MessageBoxFlagsData.h"
#include "System/SystemOutput/Flags/DialogBoxCommandFlags.h"
#include "System/SystemOutput/Flags/MessageBoxFlags.h"
#include "System/SystemOutput/MessageBoxSelection.h"

using namespace std::literals;

bool System::GetSystemMessage([[maybe_unused]] WindowMsg* msg, [[maybe_unused]] WindowHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    const auto gotMessage = ::GetMessage(msg, hwnd, 0, 0);

    if (gotMessage != 0 && gotMessage != -1)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::TranslateSystemMessage([[maybe_unused]] const WindowMsg* msg) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::TranslateMessage(msg) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::DispatchSystemMessage([[maybe_unused]] const WindowMsg* msg) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::DispatchMessage(msg) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::PeekSystemMessage([[maybe_unused]] WindowMsg* msg, [[maybe_unused]] WindowHWnd hWnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::PeekMessage(msg, hWnd, 0, 0, EnumCastUnderlying(PeekMessageOptions::Remove)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemTranslateAccelerator([[maybe_unused]] WindowHWnd hwnd, [[maybe_unused]] WindowHAccel accel, [[maybe_unused]] WindowMsg* msg) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::TranslateAccelerator(hwnd, accel, msg) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemValidateRect([[maybe_unused]] WindowHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::ValidateRect(hwnd, nullptr) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowLResult System::DefSystemWindowProc([[maybe_unused]] WindowHWnd hwnd, [[maybe_unused]] WindowMessages msg, [[maybe_unused]] WindowWParam wParam, [[maybe_unused]] WindowLParam lParam) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::DefWindowProc(hwnd, EnumCastUnderlying(msg), wParam, lParam);
#else  // !SYSTEM_PLATFORM_WIN32
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

bool System::MessageBox(WindowHWnd hwnd, const String& information, const String& title) noexcept
{
    constexpr MessageBoxFlagsData flagsData{ MessageBoxType::YesNo, MessageBoxIcon::Exclamation, MessageBoxDefault::Button2,
                                             MessageBoxMode::ApplModal, MessageBoxMisc::NoMisc };

    if (MessageBoxSelection(hwnd, information.c_str(), title.c_str(), flagsData) == DialogBoxCommand::IDYes)
        return true;
    else
        return false;
}

bool System::DestroySystemWindow([[maybe_unused]] WindowHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::DestroyWindow(hwnd) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SendSystemMessage([[maybe_unused]] WindowHWnd hwnd, [[maybe_unused]] WindowMessages msg, [[maybe_unused]] WindowWParam wParam, [[maybe_unused]] WindowLParam lParam) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SendMessage(hwnd, EnumCastUnderlying(msg), wParam, lParam) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetCursorClientPos(WindowHWnd hwnd, WindowPoint& point) noexcept
{
    return GetSystemCursorPos(point) && SystemScreenToClient(hwnd, point);
}

bool System::SetCursorClientPos(WindowHWnd hWnd, const WindowPoint& point) noexcept
{
    WindowPoint clientPoint{ point };

    return SystemClientToScreen(hWnd, clientPoint) && SetSystemCursorPos(clientPoint);
}

bool System::SystemBeginPaint([[maybe_unused]] WindowHWnd hwnd, [[maybe_unused]] WindowPaintStruct* ps) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::BeginPaint(hwnd, ps) != nullptr)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemEndPaint([[maybe_unused]] WindowHWnd hwnd, [[maybe_unused]] const WindowPaintStruct* ps) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::EndPaint(hwnd, ps) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
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
    return SYSTEM_TEXT("");
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::PostSystemMessage([[maybe_unused]] WindowHWnd hwnd, [[maybe_unused]] WindowMessages msg, [[maybe_unused]] WindowWParam wParam, [[maybe_unused]] WindowLParam lParam) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if ((::PostMessage(hwnd, EnumCastUnderlying(msg), wParam, lParam)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemCursorPos([[maybe_unused]] WindowPoint& point) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if ((::GetCursorPos(&point)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemCursorPos([[maybe_unused]] const WindowPoint& point) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if ((::SetCursorPos(point.x, point.y)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemClientToScreen([[maybe_unused]] WindowHWnd hwnd, [[maybe_unused]] WindowPoint& point) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if ((::ClientToScreen(hwnd, &point)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemScreenToClient([[maybe_unused]] WindowHWnd hwnd, [[maybe_unused]] WindowPoint& point) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if ((::ScreenToClient(hwnd, &point)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
