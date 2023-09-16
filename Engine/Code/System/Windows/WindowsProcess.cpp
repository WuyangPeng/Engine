///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 09:26)

#include "System/SystemExport.h"

#include "WindowsProcess.h"
#include "Flags/WindowsProcessFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemOutput/Data/MessageBoxFlagsData.h"
#include "System/SystemOutput/Flags/DialogBoxCommandFlags.h"
#include "System/SystemOutput/Flags/MessageBoxFlags.h"
#include "System/SystemOutput/MessageBoxSelection.h"

bool System::GetSystemMessage(WindowsMessage* message, WindowsHWnd hWnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (const auto result = ::GetMessage(message, hWnd, 0, 0);
        result != 0 && result != -1)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(message, hWnd);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::TranslateSystemMessage(const WindowsMessage* message) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::TranslateMessage(message) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(message);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::DispatchSystemMessage(const WindowsMessage* message) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::DispatchMessage(message) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(message);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::PeekSystemMessage(WindowsMessage* message, WindowsHWnd hWnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::PeekMessage(message, hWnd, 0, 0, EnumCastUnderlying(PeekMessageOptions::Remove)) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(message, hWnd);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemTranslateAccelerator(WindowsHWnd hWnd, WindowsHAccelerator accelerator, WindowsMessage* message) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::TranslateAccelerator(hWnd, accelerator, message) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd, accelerator, msg);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemValidateRect(WindowsHWnd hWnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::ValidateRect(hWnd, nullptr) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsLResult System::DefaultSystemWindowProcess(WindowsHWnd hWnd, WindowsMessages message, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::DefWindowProc(hWnd, EnumCastUnderlying(message), wParam, lParam);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd, message, wParam, lParam);

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

bool System::DefaultMessageBox(WindowsHWnd hWnd, const String& information, const String& title) noexcept
{
    if (constexpr MessageBoxFlagsData flagsData{ MessageBoxType::YesNo,
                                                 MessageBoxIcon::Exclamation,
                                                 MessageBoxDefault::Button2,
                                                 MessageBoxMode::ApplModal,
                                                 MessageBoxMisc::NoMisc };
        MessageBoxSelection(hWnd, information.c_str(), title.c_str(), flagsData) == DialogBoxCommand::IdYes)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool System::DestroySystemWindow(WindowsHWnd hWnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::DestroyWindow(hWnd) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SendSystemMessage(WindowsHWnd hWnd, WindowsMessages message, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SendMessage(hWnd, EnumCastUnderlying(message), wParam, lParam) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd, message, wParam, lParam);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetCursorClientPos(WindowsHWnd hWnd, WindowsPoint& point) noexcept
{
    return GetSystemCursorPos(point) && SystemScreenToClient(hWnd, point);
}

bool System::SetCursorClientPos(WindowsHWnd hWnd, const WindowsPoint& point) noexcept
{
    WindowsPoint clientPoint{ point };

    return SystemClientToScreen(hWnd, clientPoint) && SetSystemCursorPos(clientPoint);
}

bool System::SystemBeginPaint(WindowsHWnd hWnd, WindowsPaintStruct* paintStruct) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::BeginPaint(hWnd, paintStruct) != nullptr)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd, paintStruct);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemEndPaint(WindowsHWnd hWnd, const WindowsPaintStruct* paintStruct) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::EndPaint(hWnd, paintStruct) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd, paintStruct);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::String System::GetSystemCommandLine()
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (const auto* commandLine = ::GetCommandLine();
        commandLine != nullptr)
    {
        return commandLine;
    }
    else
    {
        return String{};
    }

#else  // !SYSTEM_PLATFORM_WIN32

    return String{};

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::PostSystemMessage(WindowsHWnd hWnd, WindowsMessages message, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::PostMessage(hWnd, EnumCastUnderlying(message), wParam, lParam) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd, message, wParam, lParam);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemCursorPos(WindowsPoint& point) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetCursorPos(&point) != gFalse)
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

    if (::SetCursorPos(point.x, point.y) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(point);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemClientToScreen(WindowsHWnd hWnd, WindowsPoint& point) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::ClientToScreen(hWnd, &point) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd, point);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemScreenToClient(WindowsHWnd hWnd, WindowsPoint& point) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::ScreenToClient(hWnd, &point) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd, point);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
