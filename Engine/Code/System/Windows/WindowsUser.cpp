/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 15:28)

#include "System/SystemExport.h"

#include "WindowsUser.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

bool System::PostSystemThreadMessage(WindowsDWord threadId, WindowsMessages message, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::PostThreadMessage(threadId, EnumCastUnderlying(message), wParam, lParam) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(threadId, message, wParam, lParam);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemInvalidateRect(WindowsHWnd hWnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::InvalidateRect(hWnd, nullptr, gTrue) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::UpdateSystemWindows(WindowsHWnd hWnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::UpdateWindow(hWnd) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
