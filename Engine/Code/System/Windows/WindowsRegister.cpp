///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 09:26)

#include "System/SystemExport.h"

#include "WindowsRegister.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"

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

    UnusedFunction(instance, cursor);

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

System::WindowsAtom System::RegisterSystemClass(const WindowsClassEx* windowClassEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::RegisterClassEx(windowClassEx);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(windowClassEx);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsUInt System::RegisterSystemWindowMessage(const TChar* message) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::RegisterWindowMessage(message);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(message);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}
