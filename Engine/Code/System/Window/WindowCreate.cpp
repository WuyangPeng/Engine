//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 14:36)

#include "System/SystemExport.h"

#include "WindowCreate.h"
#include "Flags/WindowCreateFlags.h"
#include "System/Helper/EnumCast.h"

#include <array>

using std::array;

bool System::AdjustSystemWindowRect([[maybe_unused]] WindowRect* rect, [[maybe_unused]] WindowStyles styles) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::AdjustWindowRect(rect, EnumCastUnderlying(styles), g_False) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHWnd System::CreateSystemWindow([[maybe_unused]] const String& className, [[maybe_unused]] const String& windowsName, [[maybe_unused]] WindowStyles styles, [[maybe_unused]] int x, [[maybe_unused]] int y,
                                              [[maybe_unused]] WindowRect rect, [[maybe_unused]] WindowHWnd parent, [[maybe_unused]] WindowHMenu menu, [[maybe_unused]] WindowHInstance instance) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateWindow(className.c_str(), windowsName.c_str(), EnumCastUnderlying(styles), x, y, rect.right - rect.left + 1, rect.bottom - rect.top + 1, parent, menu, instance, nullptr);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemClassName([[maybe_unused]] WindowHWnd hwnd, String& className)
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
    className.clear();

    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetWindowTextString([[maybe_unused]] WindowHWnd hwnd, String& windowText)
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
    windowText.clear();

    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHInstance System::GetHInstance() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetModuleHandle(nullptr);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::RemoveMenuCloseButton([[maybe_unused]] WindowHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    auto hmenu = GetWindowSystemMenu(hwnd);
    if (hmenu != nullptr && RemoveSystemMenu(hmenu, SystemMenuCommand::Close, MenuItem::ByCommand))
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHMenu System::GetWindowSystemMenu([[maybe_unused]] WindowHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetSystemMenu(hwnd, g_False);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::RemoveSystemMenu([[maybe_unused]] WindowHMenu menu, [[maybe_unused]] SystemMenuCommand position, [[maybe_unused]] MenuItem flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::RemoveMenu(menu, EnumCastUnderlying(position), EnumCastUnderlying(flags)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
