///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.2 (2021/04/07 11:36)

#include "System/SystemExport.h"

#include "ConsoleFont.h"

#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

bool System::GetCurrentSystemConsoleFont(WindowsHandle consoleOutput, bool maximumWindow, ConsoleFontInfoPtr consoleCurrentFont) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetCurrentConsoleFont(consoleOutput, BoolConversion(maximumWindow), consoleCurrentFont) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, bool, ConsoleFontInfoPtr>(consoleOutput, maximumWindow, consoleCurrentFont);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetCurrentSystemConsoleFont(WindowsHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetCurrentConsoleFontEx(consoleOutput, BoolConversion(maximumWindow), consoleCurrentFontEx) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, bool, ConsoleFontInfoExPtr>(consoleOutput, maximumWindow, consoleCurrentFontEx);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetCurrentSystemConsoleFont(WindowsHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetCurrentConsoleFontEx(consoleOutput, BoolConversion(maximumWindow), consoleCurrentFontEx) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, bool, ConsoleFontInfoExPtr>(consoleOutput, maximumWindow, consoleCurrentFontEx);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ConsoleCoord System::GetSystemConsoleFontSize(WindowsHandle consoleOutput, WindowsDWord font) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetConsoleFontSize(consoleOutput, font);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, WindowsDWord>(consoleOutput, font);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
