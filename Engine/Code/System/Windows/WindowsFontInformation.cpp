///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 23:15)

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

    UnusedFunction(hwnd);

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

    UnusedFunction(hwnd, hdc);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemTextExtentPoint32(WindowsHDC hdc, const TChar* text, int character, WindowsPointSize* pointSize) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetTextExtentPoint32(hdc, text, character, pointSize) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, text, character, pointSize);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemTextMetrics(WindowsHDC hdc, WindowsTextMetric* metric) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetTextMetrics(hdc, metric) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, metric);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
