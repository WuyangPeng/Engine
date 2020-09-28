//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 0:45)

#include "System/SystemExport.h"

#include "ConsoleColours.h"
#include "Flags/ConsoleColoursFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

#include <gsl/gsl_util>

bool System::SetSystemConsoleTextAttribute([[maybe_unused]] WindowHandle handle, [[maybe_unused]] TextColour textColour, [[maybe_unused]] BackgroundColour backgroundColour, [[maybe_unused]] ConsoleCommon consoleCommon) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    auto attribute = gsl::narrow_cast<WindowWord>(EnumCastUnderlying(textColour) | EnumCastUnderlying(backgroundColour) | EnumCastUnderlying(consoleCommon));

    if (::SetConsoleTextAttribute(handle, attribute) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemConsoleDefaultTextAttribute(WindowHandle handle) noexcept
{
    return SetSystemConsoleTextAttribute(handle, TextColour::White, BackgroundColour::Black, ConsoleCommon::Default);
}

bool System::ReadSystemConsoleOutputAttribute([[maybe_unused]] WindowHandle consolehandle, [[maybe_unused]] WindowWordPtr attribute, [[maybe_unused]] WindowDWord length, [[maybe_unused]] ConsoleCoord readCoord, [[maybe_unused]] WindowDWordPtr numberOfAttributesRead) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::ReadConsoleOutputAttribute(consolehandle, attribute, length, readCoord, numberOfAttributesRead) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WriteSystemConsoleOutputAttribute([[maybe_unused]] WindowHandle consolehandle, [[maybe_unused]] const WindowWord* attribute, [[maybe_unused]] WindowDWord length, [[maybe_unused]] ConsoleCoord writeCoord, [[maybe_unused]] WindowDWordPtr numberOfAttributesWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::WriteConsoleOutputAttribute(consolehandle, attribute, length, writeCoord, numberOfAttributesWritten) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FillSystemConsoleOutputAttribute([[maybe_unused]] WindowHandle consolehandle, [[maybe_unused]] WindowWord attribute, [[maybe_unused]] WindowDWord length, [[maybe_unused]] ConsoleCoord writeCoord, [[maybe_unused]] WindowDWordPtr numberOfAttributesWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::FillConsoleOutputAttribute(consolehandle, attribute, length, writeCoord, numberOfAttributesWritten) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
