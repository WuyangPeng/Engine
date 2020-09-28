//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 11:36)

#ifndef SYSTEM_WINDOW_WINDOW_FONT_INFORMATION_H
#define SYSTEM_WINDOW_WINDOW_FONT_INFORMATION_H

#include "System/SystemDll.h"

#include "Using/WindowUsing.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace System
{
    // 字体信息函数。

    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE GetStringWidth(WindowHWnd hwnd, const String& text) noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE GetCharacterWidth(WindowHWnd hwnd, const TChar character);
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE GetFontHeight(WindowHWnd hwnd) noexcept;

    [[nodiscard]] WindowHdc SYSTEM_DEFAULT_DECLARE GetSystemDC(WindowHWnd hwnd) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ReleaseSystemDC(WindowHWnd hwnd, WindowHdc hdc) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemTextExtentPoint32(WindowHdc hdc, const TChar* text, int c, WindowPointSize* pointSize) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemTextMetrics(WindowHdc hdc, WindowTextMetric* metric) noexcept;
}

#endif  // SYSTEM_WINDOW_WINDOW_FONT_INFORMATION_H
