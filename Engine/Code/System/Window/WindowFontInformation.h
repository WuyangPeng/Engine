// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 16:37)

#ifndef SYSTEM_WINDOW_WINDOW_FONT_INFORMATION_H
#define SYSTEM_WINDOW_WINDOW_FONT_INFORMATION_H

#include "System/SystemDll.h"

#include "Using/WindowUsing.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace System
{
	// ������Ϣ������

	int SYSTEM_DEFAULT_DECLARE GetStringWidth(WindowHWnd hwnd, const String& text) noexcept;
	int SYSTEM_DEFAULT_DECLARE GetCharacterWidth(WindowHWnd hwnd, const TChar character);
	int SYSTEM_DEFAULT_DECLARE GetFontHeight(WindowHWnd hwnd) noexcept;

	WindowHdc SYSTEM_DEFAULT_DECLARE GetSystemDC(WindowHWnd hwnd) noexcept;
	bool SYSTEM_DEFAULT_DECLARE ReleaseSystemDC(WindowHWnd hwnd, WindowHdc hdc) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetSystemTextExtentPoint32(WindowHdc hdc, const TChar* text, int c, WindowPointSize* pointSize) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetSystemTextMetrics(WindowHdc hdc, WindowTextMetric* metric) noexcept;
}

#endif // SYSTEM_WINDOW_WINDOW_FONT_INFORMATION_H
