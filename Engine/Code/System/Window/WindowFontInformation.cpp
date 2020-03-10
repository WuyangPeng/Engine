// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:39)

#include "System/SystemExport.h"

#include "WindowFontInformation.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"

#include <gsl/gsl_util>

int System
	::GetStringWidth(WindowHWnd hwnd, const String& text) noexcept
{
	if (text.empty())
		return 0;

	auto context = GetSystemDC(hwnd);
	WindowPointSize size{ 0,0 };
	GetSystemTextExtentPoint32(context, text.c_str(), gsl::narrow_cast<int>(text.size()), &size);
	ReleaseSystemDC(hwnd, context);

	return gsl::narrow_cast<int>(size.cx);
}

int System
	::GetCharacterWidth(WindowHWnd hwnd, const TChar character)
{
	return GetStringWidth(hwnd, String{ 1,character });
}

int System
	::GetFontHeight(WindowHWnd hwnd) noexcept
{
	auto context = GetSystemDC(hwnd);
	WindowTextMetric metric{};
	GetSystemTextMetrics(context, &metric);
	ReleaseSystemDC(hwnd, context);

	return gsl::narrow_cast<int>(metric.tmHeight);
}

System::WindowHdc System
	::GetSystemDC(WindowHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetDC(hwnd);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(hwnd);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::ReleaseSystemDC(WindowHWnd hwnd, WindowHdc hdc) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::ReleaseDC(hwnd, hdc) != 0)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(hwnd);
	SYSTEM_UNUSED_ARG(hdc);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemTextExtentPoint32(WindowHdc hdc, const TChar* text, int c, WindowPointSize* pointSize) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetTextExtentPoint32(hdc, text, c, pointSize) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(hdc);
	SYSTEM_UNUSED_ARG(text);
	SYSTEM_UNUSED_ARG(c);
	SYSTEM_UNUSED_ARG(pointSize);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemTextMetrics(WindowHdc hdc, WindowTextMetric* metric) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetTextMetrics(hdc, metric) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(hdc);
	SYSTEM_UNUSED_ARG(metric);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

