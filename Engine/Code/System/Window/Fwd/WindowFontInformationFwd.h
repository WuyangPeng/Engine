// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:36)

#ifndef SYSTEM_WINDOW_FONT_INFORMATION_FWD_H 
#define SYSTEM_WINDOW_FONT_INFORMATION_FWD_H  

#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	int GetStringWidth(WindowHWnd hwnd, const String& text) noexcept;
	int GetCharacterWidth(WindowHWnd hwnd, const TChar character);
	int GetFontHeight(WindowHWnd hwnd) noexcept;

	WindowHdc GetSystemDC(WindowHWnd hwnd) noexcept;
	bool ReleaseSystemDC(WindowHWnd hwnd, WindowHdc hdc) noexcept;
	bool GetSystemTextExtentPoint32(WindowHdc hdc, const TChar* text, int c, WindowPointSize* pointSize) noexcept;
	bool GetSystemTextMetrics(WindowHdc hdc, WindowTextMetric* metric) noexcept;
}

#endif // SYSTEM_WINDOW_FONT_INFORMATION_FWD_H