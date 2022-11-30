///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 23:16)

#include "System/SystemExport.h"

#include "WindowsUser.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

bool System::PostSystemThreadMessage(WindowsDWord threadID, WindowsMessages msg, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::PostThreadMessage(threadID, EnumCastUnderlying(msg), wParam, lParam) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(threadID, msg, wParam, lParam);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemInvalidateRect(WindowsHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::InvalidateRect(hwnd, nullptr, gTrue) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hwnd);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::UpdateSystemWindows(WindowsHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::UpdateWindow(hwnd) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hwnd);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
