///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 22:25)

#include "System/SystemExport.h"

#include "ConsoleColours.h"
#include "Flags/ConsoleColoursFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

#include <gsl/util>

bool System::SetSystemConsoleTextAttribute(WindowsHandle handle, TextColour textColour, BackgroundColour backgroundColour, ConsoleCommon consoleCommon) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    const auto attribute = gsl::narrow_cast<WindowsWord>(EnumCastUnderlying(textColour) | EnumCastUnderlying(backgroundColour) | EnumCastUnderlying(consoleCommon));

    if (::SetConsoleTextAttribute(handle, attribute) != gFalse)
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

bool System::ReadSystemConsoleOutputAttribute(WindowsHandle consolehandle, WindowsWordPtr attribute, WindowsDWord length, const ConsoleCoord& readCoord, WindowsDWordPtr numberOfAttributesRead) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::ReadConsoleOutputAttribute(consolehandle, attribute, length, readCoord, numberOfAttributesRead) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consolehandle, attribute, length, readCoord, numberOfAttributesRead);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WriteSystemConsoleOutputAttribute(WindowsHandle consolehandle, const WindowsWord* attribute, WindowsDWord length, const ConsoleCoord& writeCoord, WindowsDWordPtr numberOfAttributesWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::WriteConsoleOutputAttribute(consolehandle, attribute, length, writeCoord, numberOfAttributesWritten) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consolehandle, attribute, length, writeCoord, numberOfAttributesWritten);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FillSystemConsoleOutputAttribute(WindowsHandle consolehandle, WindowsWord attribute, WindowsDWord length, const ConsoleCoord& writeCoord, WindowsDWordPtr numberOfAttributesWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::FillConsoleOutputAttribute(consolehandle, attribute, length, writeCoord, numberOfAttributesWritten) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consolehandle, attribute, length, writeCoord, numberOfAttributesWritten);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
