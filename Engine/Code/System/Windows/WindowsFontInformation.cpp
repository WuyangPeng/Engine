///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/19 13:48)

#include "System/SystemExport.h"

#include "WindowsFontInformation.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

#include <gsl/util>

int System::GetStringWidth(WindowsHWnd hWnd, const String& text)
{
    if (text.empty())
    {
        return 0;
    }

    const auto context = GetSystemDC(hWnd);
    WindowsPointSize size{ 0, 0 };
    if (GetSystemTextExtentPoint32(context, text.c_str(), boost::numeric_cast<int>(text.size()), &size) &&
        ReleaseSystemDC(hWnd, context))
    {
        return gsl::narrow_cast<int>(size.cx);
    }
    else
    {
        return 0;
    }
}

int System::GetCharacterWidth(WindowsHWnd hWnd, TChar character)
{
    return GetStringWidth(hWnd, String{ 1, character });
}

int System::GetFontHeight(WindowsHWnd hWnd) noexcept
{
    const auto context = GetSystemDC(hWnd);
    WindowsTextMetric metric{};
    if (GetSystemTextMetrics(context, &metric) && ReleaseSystemDC(hWnd, context))
    {
        return gsl::narrow_cast<int>(metric.tmHeight);
    }
    else
    {
        return 0;
    }
}

System::WindowsHdc System::GetSystemDC(WindowsHWnd hWnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetDC(hWnd);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ReleaseSystemDC(WindowsHWnd hWnd, WindowsHdc hdc) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::ReleaseDC(hWnd, hdc) != 0)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd, hdc);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemTextExtentPoint32(WindowsHdc hdc, const TChar* text, int character, WindowsPointSize* pointSize) noexcept
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

bool System::GetSystemTextMetrics(WindowsHdc hdc, WindowsTextMetric* metric) noexcept
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
