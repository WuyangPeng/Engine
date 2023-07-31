///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/19 13:47)

#ifndef SYSTEM_WINDOWS_WINDOWS_FONT_INFORMATION_H
#define SYSTEM_WINDOWS_WINDOWS_FONT_INFORMATION_H

#include "System/SystemDll.h"

#include "Using/WindowsUsing.h"
#include "System/Helper/UnicodeUsing.h"

// 字体信息函数。
namespace System
{
    NODISCARD int SYSTEM_DEFAULT_DECLARE GetStringWidth(WindowsHWnd hWnd, const String& text);
    NODISCARD int SYSTEM_DEFAULT_DECLARE GetCharacterWidth(WindowsHWnd hWnd, TChar character);
    NODISCARD int SYSTEM_DEFAULT_DECLARE GetFontHeight(WindowsHWnd hWnd) noexcept;

    NODISCARD WindowsHDC SYSTEM_DEFAULT_DECLARE GetSystemDC(WindowsHWnd hWnd) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE ReleaseSystemDC(WindowsHWnd hWnd, WindowsHDC hdc) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemTextExtentPoint32(WindowsHDC hdc,
                                                                     const TChar* text,
                                                                     int character,
                                                                     WindowsPointSize* pointSize) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemTextMetrics(WindowsHDC hdc, WindowsTextMetric* metric) noexcept;
}

#endif  // SYSTEM_WINDOWS_WINDOWS_FONT_INFORMATION_H
