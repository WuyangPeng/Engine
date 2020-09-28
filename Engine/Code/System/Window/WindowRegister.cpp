//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 15:41)

#include "System/SystemExport.h"

#include "WindowRegister.h"
#include "System/Helper/EnumCast.h"

System::WindowHGdiObj System::GetSystemStockObject([[maybe_unused]] WindowBrushTypes background) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetStockObject(EnumCastUnderlying(background));
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHCursor System::LoadSystemCursor([[maybe_unused]] WindowHInstance instance, [[maybe_unused]] const TChar* cursor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::LoadCursor(instance, cursor);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHIcon System::LoadSystemIcon([[maybe_unused]] WindowHInstance instance, [[maybe_unused]] const TChar* icon) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::LoadIcon(instance, icon);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowAtom System::RegisterSystemClass([[maybe_unused]] const WindowClassEx* wndClassEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::RegisterClassEx(wndClassEx);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowUInt System::RegisterSystemWindowMessage([[maybe_unused]] const TChar* string) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::RegisterWindowMessage(string);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}
