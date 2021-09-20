///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.6 (2021/07/05 16:39)

#include "System/SystemExport.h"

#include "WindowsFontInformation.h"
#include "System/Helper/WindowsMacro.h"

#include <gsl/util>

int System::GetStringWidth(WindowsHWnd hwnd, const String& text) noexcept
{
    if (text.empty())
    {
        return 0;
    }

    auto context = GetSystemDC(hwnd);
    WindowsPointSize size{ 0, 0 };
    if (GetSystemTextExtentPoint32(context, text.c_str(), gsl::narrow_cast<int>(text.size()), &size) && ReleaseSystemDC(hwnd, context))
    {
        return gsl::narrow_cast<int>(size.cx);
    }
    else
    {
        return 0;
    }
}

int System::GetCharacterWidth(WindowsHWnd hwnd, const TChar character)
{
    return GetStringWidth(hwnd, String{ 1, character });
}

int System::GetFontHeight(WindowsHWnd hwnd) noexcept
{
    auto context = GetSystemDC(hwnd);
    WindowsTextMetric metric{};
    if (GetSystemTextMetrics(context, &metric) && ReleaseSystemDC(hwnd, context))
    {
        return gsl::narrow_cast<int>(metric.tmHeight);
    }
    else
    {
        return 0;
    }
}

System::WindowsHDC System::GetSystemDC(WindowsHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetDC(hwnd);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHWnd>(hwnd);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ReleaseSystemDC(WindowsHWnd hwnd, WindowsHDC hdc) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::ReleaseDC(hwnd, hdc) != 0)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHWnd, WindowsHDC>(hwnd, hdc);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemTextExtentPoint32(WindowsHDC hdc, const TChar* text, int c, WindowsPointSize* pointSize) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetTextExtentPoint32(hdc, text, c, pointSize) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHDC, const TChar*, int, WindowsPointSize*>(hdc, text, c, pointSize);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemTextMetrics(WindowsHDC hdc, WindowsTextMetric* metric) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetTextMetrics(hdc, metric) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHDC, WindowsTextMetric*>(hdc, metric);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
