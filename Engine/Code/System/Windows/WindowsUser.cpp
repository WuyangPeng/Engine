///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/12 13:32)

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
