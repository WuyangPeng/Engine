/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 16:59)

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

    const auto attribute = gsl::narrow_cast<WindowsWord>(EnumCastUnderlying(textColour) | EnumCastUnderlying(backgroundColour) | EnumCastUnderlying(consoleCommon));

    return ::SetConsoleTextAttribute(handle, attribute) != gFalse;

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

    return ::ReadConsoleOutputAttribute(consoleHandle, attribute, length, readCoord, numberOfAttributesRead) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleHandle, attribute, length, readCoord, numberOfAttributesRead);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WriteSystemConsoleOutputAttribute(WindowsHandle consoleHandle, const WindowsWord* attribute, WindowsDWord length, const ConsoleCoord& writeCoord, WindowsDWordPtr numberOfAttributesWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::WriteConsoleOutputAttribute(consoleHandle, attribute, length, writeCoord, numberOfAttributesWritten) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleHandle, attribute, length, writeCoord, numberOfAttributesWritten);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FillSystemConsoleOutputAttribute(WindowsHandle consoleHandle, WindowsWord attribute, WindowsDWord length, const ConsoleCoord& writeCoord, WindowsDWordPtr numberOfAttributesWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::FillConsoleOutputAttribute(consoleHandle, attribute, length, writeCoord, numberOfAttributesWritten) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleHandle, attribute, length, writeCoord, numberOfAttributesWritten);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
