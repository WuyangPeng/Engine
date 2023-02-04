///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.1 (2023/02/02 14:41)

#include "System/SystemExport.h"

#include "WindowsCreate.h"
#include "Flags/WindowsCreateFlags.h"
#include "System/Helper/EnumCast.h"

#include <array>

namespace System
{
    bool GetWindowsInformation(WindowsHWnd hwnd, String& result, GetWindowsInformationFunction getWindowsInformationFunction)
    {
        std::array<TChar, gMaxPath> name{};

        if (getWindowsInformationFunction != nullptr && getWindowsInformationFunction(hwnd, name.data(), gMaxPath) == 0)
        {
            result.clear();
            return false;
        }
        else
        {
            result = name.data();
            return true;
        }
    }
}

bool System::AdjustSystemWindowRect(WindowsRect* rect, WindowsStyles styles) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::AdjustWindowRect(rect, EnumCastUnderlying(styles), gFalse) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(rect, styles);

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

    return ::CreateWindow(className.c_str(),
                          windowsName.c_str(),
                          EnumCastUnderlying(styles),
                          x,
                          y,
                          rect.right - rect.left + 1,
                          rect.bottom - rect.top + 1,
                          parent,
                          menu,
                          instance,
                          nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(className,
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

    return GetWindowsInformation(hwnd, className, ::GetClassName);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hwnd);

    className.clear();

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetWindowTextString(WindowsHWnd hwnd, String& windowText)
{
#ifdef SYSTEM_PLATFORM_WIN32

    return GetWindowsInformation(hwnd, windowText, ::GetWindowText);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hwnd);

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

    const auto hmenu = GetWindowSystemMenu(hwnd);
    if (hmenu != nullptr && RemoveSystemMenu(hmenu, SystemMenuCommand::Close, MenuItem::ByCommand))
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hwnd);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHMenu System::GetWindowSystemMenu(WindowsHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetSystemMenu(hwnd, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hwnd);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::RemoveSystemMenu(WindowsHMenu menu, SystemMenuCommand position, MenuItem flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::RemoveMenu(menu, EnumCastUnderlying(position), EnumCastUnderlying(flags)) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(menu, position, flags);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
