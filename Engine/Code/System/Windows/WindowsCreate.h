///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 09:25)

#ifndef SYSTEM_WINDOWS_WINDOWS_CREATE_H
#define SYSTEM_WINDOWS_WINDOWS_CREATE_H

#include "System/SystemDll.h"

#include "Fwd/WindowsFlagsFwd.h"
#include "Using/WindowsUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Helper/WindowsMacro.h"

// ���ڴ�������غ�����
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
