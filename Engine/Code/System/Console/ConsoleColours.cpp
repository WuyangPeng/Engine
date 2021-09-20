///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.2 (2021/04/07 11:20)

#include "System/SystemExport.h"

#include "ConsoleColours.h"
#include "Flags/ConsoleColoursFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

#include <gsl/util>

bool System::SetSystemConsoleTextAttribute(WindowsHandle handle, TextColour textColour, BackgroundColour backgroundColour, ConsoleCommon consoleCommon) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    auto attribute = gsl::narrow_cast<WindowsWord>(EnumCastUnderlying(textColour) | EnumCastUnderlying(backgroundColour) | EnumCastUnderlying(consoleCommon));

    if (::SetConsoleTextAttribute(handle, attribute) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, TextColour, BackgroundColour, ConsoleCommon>(handle, textColour, backgroundColour, consoleCommon);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemConsoleDefaultTextAttribute(WindowsHandle handle) noexcept
{
    return SetSystemConsoleTextAttribute(handle, TextColour::White, BackgroundColour::Black, ConsoleCommon::Default);
}

bool System::ReadSystemConsoleOutputAttribute(WindowsHandle consolehandle, WindowsWordPtr attribute, WindowsDWord length, const ConsoleCoord& readCoord, WindowsDWordPtr numberOfAttributesRead) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::ReadConsoleOutputAttribute(consolehandle, attribute, length, readCoord, numberOfAttributesRead) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, WindowsWordPtr, WindowsDWord, ConsoleCoord, WindowsDWordPtr>(consolehandle, attribute, length, readCoord, numberOfAttributesRead);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WriteSystemConsoleOutputAttribute(WindowsHandle consolehandle, const WindowsWord* attribute, WindowsDWord length, const ConsoleCoord& writeCoord, WindowsDWordPtr numberOfAttributesWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::WriteConsoleOutputAttribute(consolehandle, attribute, length, writeCoord, numberOfAttributesWritten) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, const WindowsWord*, WindowsDWord, ConsoleCoord, WindowsDWordPtr>(consolehandle, attribute, length, writeCoord, numberOfAttributesWritten);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FillSystemConsoleOutputAttribute(WindowsHandle consolehandle, WindowsWord attribute, WindowsDWord length, const ConsoleCoord& writeCoord, WindowsDWordPtr numberOfAttributesWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::FillConsoleOutputAttribute(consolehandle, attribute, length, writeCoord, numberOfAttributesWritten) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, WindowsWord, WindowsDWord, ConsoleCoord, WindowsDWordPtr>(consolehandle, attribute, length, writeCoord, numberOfAttributesWritten);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
