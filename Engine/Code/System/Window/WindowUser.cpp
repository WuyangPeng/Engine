//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 15:44)

#include "System/SystemExport.h"

#include "WindowUser.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

bool System::PostSystemThreadMessage([[maybe_unused]] WindowDWord threadID, [[maybe_unused]] WindowMessages msg, [[maybe_unused]] WindowWParam wParam, [[maybe_unused]] WindowLParam lParam) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::PostThreadMessage(threadID, EnumCastUnderlying(msg), wParam, lParam) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemInvalidateRect([[maybe_unused]] WindowHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::InvalidateRect(hwnd, nullptr, g_True) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::UpdateSystemWindows([[maybe_unused]] WindowHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::UpdateWindow(hwnd) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
