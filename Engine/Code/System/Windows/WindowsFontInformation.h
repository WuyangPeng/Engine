/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.6 (2024/02/24 19:56)

#ifndef SYSTEM_WINDOWS_WINDOWS_FONT_INFORMATION_H
#define SYSTEM_WINDOWS_WINDOWS_FONT_INFORMATION_H

#include "System/SystemDll.h"

#include "Using/WindowsUsing.h"
#include "System/Helper/UnicodeUsing.h"

/// ������Ϣ������
namespace System
{
    NODISCARD int SYSTEM_DEFAULT_DECLARE GetStringWidth(WindowsHWnd hWnd, const String& text);
    NODISCARD int SYSTEM_DEFAULT_DECLARE GetCharacterWidth(WindowsHWnd hWnd, TChar character);
    NODISCARD int SYSTEM_DEFAULT_DECLARE GetFontHeight(WindowsHWnd hWnd) noexcept;

    NODISCARD WindowsHdc SYSTEM_DEFAULT_DECLARE GetSystemDC(WindowsHWnd hWnd) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE ReleaseSystemDC(WindowsHWnd hWnd, WindowsHdc hdc) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemTextExtentPoint32(WindowsHdc hdc,
                                                                     const TChar* text,
                                                                     int character,
                                                                     WindowsPointSize* pointSize) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemTextMetrics(WindowsHdc hdc, WindowsTextMetric* metric) noexcept;
}

#endif  // SYSTEM_WINDOWS_WINDOWS_FONT_INFORMATION_H
