//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/27 11:35)

#ifndef SYSTEM_WINDOW_WINDOW_CREATE_H
#define SYSTEM_WINDOW_WINDOW_CREATE_H

#include "System/SystemDll.h"

#include "Fwd/WindowFlagsFwd.h"
#include "Using/WindowUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Helper/WindowsMacro.h"

#include <string>

namespace System
{
    // ���ڴ�������غ�����

    [[nodiscard]] constexpr int GetLowWord(WindowLParam param) noexcept
    {
        return LowWord(param);
    }

    [[nodiscard]] constexpr int GetLowWord(WindowWParam param) noexcept
    {
        return LowWord(param);
    }

    [[nodiscard]] constexpr int GetHighWord(WindowLParam param) noexcept
    {
        return HighWord(param);
    }

    [[nodiscard]] constexpr int GetHighWord(WindowWParam param) noexcept
    {
        return HighWord(param);
    }

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE AdjustSystemWindowRect(WindowRect* rect, WindowStyles styles) noexcept;
    [[nodiscard]] WindowHWnd SYSTEM_DEFAULT_DECLARE CreateSystemWindow(const String& className, const String& windowsName, WindowStyles styles, int x, int y,
                                                                       WindowRect rect, WindowHWnd parent, WindowHMenu menu, WindowHInstance instance) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemClassName(WindowHWnd hwnd, String& className);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetWindowTextString(WindowHWnd hwnd, String& windowText);

    [[nodiscard]] WindowHInstance SYSTEM_DEFAULT_DECLARE GetHInstance() noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE RemoveMenuCloseButton(WindowHWnd hwnd) noexcept;

    [[nodiscard]] WindowHMenu SYSTEM_DEFAULT_DECLARE GetWindowSystemMenu(WindowHWnd hwnd) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE RemoveSystemMenu(WindowHMenu menu, SystemMenuCommand position, MenuItem flags) noexcept;
}

#endif  // SYSTEM_WINDOW_WINDOW_CREATE_H
