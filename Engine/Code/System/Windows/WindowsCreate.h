///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.1 (2023/02/02 14:39)

#ifndef SYSTEM_WINDOWS_WINDOWS_CREATE_H
#define SYSTEM_WINDOWS_WINDOWS_CREATE_H

#include "System/SystemDll.h"

#include "Fwd/WindowsFlagsFwd.h"
#include "Using/WindowsUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Helper/WindowsMacro.h"

// 窗口创建和相关函数。
namespace System
{
    NODISCARD constexpr int GetLowWord(WindowsLParam param) noexcept
    {
        return LowWord(param);
    }

    NODISCARD constexpr int GetLowWord(WindowsWParam param) noexcept
    {
        return LowWord(param);
    }

    NODISCARD constexpr int GetHighWord(WindowsLParam param) noexcept
    {
        return HighWord(param);
    }

    NODISCARD constexpr int GetHighWord(WindowsWParam param) noexcept
    {
        return HighWord(param);
    }

    NODISCARD bool SYSTEM_DEFAULT_DECLARE AdjustSystemWindowRect(WindowsRect* rect, WindowsStyles styles) noexcept;
    NODISCARD WindowsHWnd SYSTEM_DEFAULT_DECLARE CreateSystemWindow(const String& className,
                                                                    const String& windowsName,
                                                                    WindowsStyles styles,
                                                                    int x,
                                                                    int y,
                                                                    WindowsRect rect,
                                                                    WindowsHWnd parent,
                                                                    WindowsHMenu menu,
                                                                    WindowsHInstance instance) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemClassName(WindowsHWnd hwnd, String& className);
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetWindowTextString(WindowsHWnd hwnd, String& windowText);

    NODISCARD WindowsHInstance SYSTEM_DEFAULT_DECLARE GetHInstance() noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE RemoveMenuCloseButton(WindowsHWnd hwnd) noexcept;

    NODISCARD WindowsHMenu SYSTEM_DEFAULT_DECLARE GetWindowSystemMenu(WindowsHWnd hwnd) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE RemoveSystemMenu(WindowsHMenu menu, SystemMenuCommand position, MenuItem flags) noexcept;
}

#endif  // SYSTEM_WINDOWS_WINDOWS_CREATE_H
