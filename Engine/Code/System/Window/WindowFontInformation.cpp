//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 14:38)

#include "System/SystemExport.h"

#include "WindowFontInformation.h"
#include "System/Helper/WindowsMacro.h"

#include <gsl/gsl_util>

int System::GetStringWidth([[maybe_unused]] WindowHWnd hwnd, [[maybe_unused]] const String& text) noexcept
{
    if (text.empty())
    {
        return 0;
    }

    auto context = GetSystemDC(hwnd);
    WindowPointSize size{ 0, 0 };
    if (GetSystemTextExtentPoint32(context, text.c_str(), gsl::narrow_cast<int>(text.size()), &size) && ReleaseSystemDC(hwnd, context))
    {
        return gsl::narrow_cast<int>(size.cx);
    }        
    else
    {
        return 0;
    }
}

int System::GetCharacterWidth(WindowHWnd hwnd, const TChar character)
{
    return GetStringWidth(hwnd, String{ 1, character });
}

int System::GetFontHeight([[maybe_unused]] WindowHWnd hwnd) noexcept
{
    auto context = GetSystemDC(hwnd);
    WindowTextMetric metric{};
    if(GetSystemTextMetrics(context, &metric) && ReleaseSystemDC(hwnd, context))
    {
        return gsl::narrow_cast<int>(metric.tmHeight);
    }
    else
    {
        return 0;
    }   
}

System::WindowHdc System::GetSystemDC([[maybe_unused]] WindowHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetDC(hwnd);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ReleaseSystemDC([[maybe_unused]] WindowHWnd hwnd, [[maybe_unused]] WindowHdc hdc) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::ReleaseDC(hwnd, hdc) != 0)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemTextExtentPoint32([[maybe_unused]] WindowHdc hdc, [[maybe_unused]] const TChar* text, [[maybe_unused]] int c, [[maybe_unused]] WindowPointSize* pointSize) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetTextExtentPoint32(hdc, text, c, pointSize) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemTextMetrics([[maybe_unused]] WindowHdc hdc, [[maybe_unused]] WindowTextMetric* metric) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetTextMetrics(hdc, metric) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
