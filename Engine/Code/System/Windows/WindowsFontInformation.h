///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 23:14)

#ifndef SYSTEM_WINDOWS_WINDOWS_FONT_INFORMATION_H
#define SYSTEM_WINDOWS_WINDOWS_FONT_INFORMATION_H

#include "System/SystemDll.h"

#include "Using/WindowsUsing.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace System
{
    // 字体信息函数。

    NODISCARD int SYSTEM_DEFAULT_DECLARE GetStringWidth(WindowsHWnd hwnd, const String& text) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE GetCharacterWidth(WindowsHWnd hwnd, const TChar character);
    NODISCARD int SYSTEM_DEFAULT_DECLARE GetFontHeight(WindowsHWnd hwnd) noexcept;

    NODISCARD WindowsHDC SYSTEM_DEFAULT_DECLARE GetSystemDC(WindowsHWnd hwnd) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE ReleaseSystemDC(WindowsHWnd hwnd, WindowsHDC hdc) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemTextExtentPoint32(WindowsHDC hdc,
                                                                     const TChar* text,
                                                                     int character,
                                                                     WindowsPointSize* pointSize) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemTextMetrics(WindowsHDC hdc, WindowsTextMetric* metric) noexcept;
}

#endif  // SYSTEM_WINDOWS_WINDOWS_FONT_INFORMATION_H
