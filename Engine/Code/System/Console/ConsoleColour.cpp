///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/28 16:21)

#include "System/SystemExport.h"

#include "ConsoleColour.h"
#include "Flags/ConsoleColoursFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

#include <gsl/util>

bool System::SetSystemConsoleTextAttribute(WindowsHandle handle, TextColour textColour, BackgroundColour backgroundColour, ConsoleCommon consoleCommon) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (const auto attribute = gsl::narrow_cast<WindowsWord>(EnumCastUnderlying(textColour) | EnumCastUnderlying(backgroundColour) | EnumCastUnderlying(consoleCommon));
        ::SetConsoleTextAttribute(handle, attribute) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle, textColour, backgroundColour, consoleCommon);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemConsoleDefaultTextAttribute(WindowsHandle handle) noexcept
{
    return SetSystemConsoleTextAttribute(handle, TextColour::White, BackgroundColour::Black, ConsoleCommon::Default);
}

bool System::ReadSystemConsoleOutputAttribute(WindowsHandle consoleHandle, WindowsWordPtr attribute, WindowsDWord length, const ConsoleCoord& readCoord, WindowsDWordPtr numberOfAttributesRead) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::ReadConsoleOutputAttribute(consoleHandle, attribute, length, readCoord, numberOfAttributesRead) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleHandle, attribute, length, readCoord, numberOfAttributesRead);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WriteSystemConsoleOutputAttribute(WindowsHandle consoleHandle, const WindowsWord* attribute, WindowsDWord length, const ConsoleCoord& writeCoord, WindowsDWordPtr numberOfAttributesWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::WriteConsoleOutputAttribute(consoleHandle, attribute, length, writeCoord, numberOfAttributesWritten) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleHandle, attribute, length, writeCoord, numberOfAttributesWritten);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FillSystemConsoleOutputAttribute(WindowsHandle consoleHandle, WindowsWord attribute, WindowsDWord length, const ConsoleCoord& writeCoord, WindowsDWordPtr numberOfAttributesWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::FillConsoleOutputAttribute(consoleHandle, attribute, length, writeCoord, numberOfAttributesWritten) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleHandle, attribute, length, writeCoord, numberOfAttributesWritten);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
