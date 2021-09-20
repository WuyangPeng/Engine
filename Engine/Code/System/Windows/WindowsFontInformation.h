///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.6 (2021/07/03 21:52)

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
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemTextExtentPoint32(WindowsHDC hdc, const TChar* text, int c, WindowsPointSize* pointSize) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemTextMetrics(WindowsHDC hdc, WindowsTextMetric* metric) noexcept;
}

#endif  // SYSTEM_WINDOWS_WINDOWS_FONT_INFORMATION_H
