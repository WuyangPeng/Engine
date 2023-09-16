///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 09:25)

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
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemClassName(WindowsHWnd hWnd, String& className);
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetWindowTextString(WindowsHWnd hWnd, String& windowText);

    NODISCARD WindowsHInstance SYSTEM_DEFAULT_DECLARE GetHInstance() noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE RemoveMenuCloseButton(WindowsHWnd hWnd) noexcept;

    NODISCARD WindowsHMenu SYSTEM_DEFAULT_DECLARE GetWindowSystemMenu(WindowsHWnd hWnd) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE RemoveSystemMenu(WindowsHMenu menu, SystemMenuCommand position, MenuItem flags) noexcept;
}

#endif  // SYSTEM_WINDOWS_WINDOWS_CREATE_H
