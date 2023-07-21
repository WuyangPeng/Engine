///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/18 18:22)

#include "System/SystemExport.h"

#include "WindowsUser.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

bool System::PostSystemThreadMessage(WindowsDWord threadId, WindowsMessages message, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::PostThreadMessage(threadId, EnumCastUnderlying(message), wParam, lParam) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(threadId, message, wParam, lParam);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemInvalidateRect(WindowsHWnd hWnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::InvalidateRect(hWnd, nullptr, gTrue) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::UpdateSystemWindows(WindowsHWnd hWnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::UpdateWindow(hWnd) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
