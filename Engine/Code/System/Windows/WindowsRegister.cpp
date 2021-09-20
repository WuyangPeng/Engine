///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.6 (2021/07/05 23:26)

#include "System/SystemExport.h"

#include "WindowsRegister.h"
#include "System/Helper/EnumCast.h"

System::WindowsHGdiObj System::GetSystemStockObject(WindowsBrushTypes background) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetStockObject(EnumCastUnderlying(background));

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsBrushTypes>(background);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHCursor System::LoadSystemCursor(WindowsHInstance instance, const TChar* cursor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::LoadCursor(instance, cursor);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHInstance, const TChar>(instance, background);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHIcon System::LoadSystemIcon(WindowsHInstance instance, const TChar* icon) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::LoadIcon(instance, icon);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHInstance, const TChar>(instance, icon);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsAtom System::RegisterSystemClass(const WindowsClassEx* wndClassEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::RegisterClassEx(wndClassEx);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<const WindowsClassEx*>(wndClassEx);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsUInt System::RegisterSystemWindowMessage(const TChar* string) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::RegisterWindowMessage(string);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<const TChar*>(string);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}
