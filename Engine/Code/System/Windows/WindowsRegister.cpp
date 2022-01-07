///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/12 13:30)

#include "System/SystemExport.h"

#include "WindowsRegister.h"
#include "System/Helper/EnumCast.h"

System::WindowsHGdiObj System::GetSystemStockObject(WindowsBrushTypes background) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetStockObject(EnumCastUnderlying(background));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(background);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHCursor System::LoadSystemCursor(WindowsHInstance instance, const TChar* cursor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::LoadCursor(instance, cursor);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(instance, background);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHIcon System::LoadSystemIcon(WindowsHInstance instance, const TChar* icon) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::LoadIcon(instance, icon);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(instance, icon);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsAtom System::RegisterSystemClass(const WindowsClassEx* wndClassEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::RegisterClassEx(wndClassEx);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(wndClassEx);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsUInt System::RegisterSystemWindowMessage(const TChar* string) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::RegisterWindowMessage(string);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(string);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}
