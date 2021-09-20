///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.6 (2021/07/03 22:01)

#include "System/SystemExport.h"

#include "WindowsCreate.h"
#include "Flags/WindowsCreateFlags.h"
#include "System/Helper/EnumCast.h"

#include <array>

using std::array;

bool System::AdjustSystemWindowRect(WindowsRect* rect, WindowsStyles styles) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::AdjustWindowRect(rect, EnumCastUnderlying(styles), g_False) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsRect, WindowsStyles>(rect, styles);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHWnd System::CreateSystemWindow(const String& className,
                                               const String& windowsName,
                                               WindowsStyles styles,
                                               int x,
                                               int y,
                                               WindowsRect rect,
                                               WindowsHWnd parent,
                                               WindowsHMenu menu,
                                               WindowsHInstance instance) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CreateWindow(className.c_str(), windowsName.c_str(), EnumCastUnderlying(styles), x, y, rect.right - rect.left + 1, rect.bottom - rect.top + 1, parent, menu, instance, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<String,
                 String,
                 WindowsStyles,
                 int,
                 int,
                 WindowsRect,
                 WindowsHWnd,
                 WindowsHMenu,
                 WindowsHInstance>(className,
                                   windowsName,
                                   styles,
                                   x,
                                   y,
                                   rect,
                                   parent,
                                   menu,
                                   instance);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemClassName(WindowsHWnd hwnd, String& className)
{
#ifdef SYSTEM_PLATFORM_WIN32

    constexpr auto maxCount = 256;
    array<TChar, maxCount> name{};

    if (::GetClassName(hwnd, name.data(), maxCount) == 0)
    {
        className.clear();
        return false;
    }
    else
    {
        className = name.data();
        return true;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHWnd>(hwnd);

    className.clear();

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetWindowTextString(WindowsHWnd hwnd, String& windowText)
{
#ifdef SYSTEM_PLATFORM_WIN32

    constexpr auto maxCount = 256;
    array<TChar, maxCount> name{};

    if (::GetWindowText(hwnd, name.data(), maxCount) == 0)
    {
        windowText.clear();
        return false;
    }
    else
    {
        windowText = name.data();
        return true;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHWnd>(hwnd);

    windowText.clear();

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHInstance System::GetHInstance() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetModuleHandle(nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::RemoveMenuCloseButton(WindowsHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    auto hmenu = GetWindowSystemMenu(hwnd);
    if (hmenu != nullptr && RemoveSystemMenu(hmenu, SystemMenuCommand::Close, MenuItem::ByCommand))
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHWnd>(hwnd);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHMenu System::GetWindowSystemMenu(WindowsHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetSystemMenu(hwnd, g_False);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHWnd>(hwnd);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::RemoveSystemMenu(WindowsHMenu menu, SystemMenuCommand position, MenuItem flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::RemoveMenu(menu, EnumCastUnderlying(position), EnumCastUnderlying(flags)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHMenu, SystemMenuCommand, MenuItem>(menu, position, flags);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
