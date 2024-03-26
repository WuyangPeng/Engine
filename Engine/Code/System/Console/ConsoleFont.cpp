/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:01)

#include "System/SystemExport.h"

#include "ConsoleFont.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

bool System::GetCurrentSystemConsoleFont(WindowsHandle consoleOutput, bool maximumWindow, ConsoleFontInfoPtr consoleCurrentFont) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetCurrentConsoleFont(consoleOutput, BoolConversion(maximumWindow), consoleCurrentFont) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleOutput, maximumWindow, consoleCurrentFont);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetCurrentSystemConsoleFont(WindowsHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetCurrentConsoleFontEx(consoleOutput, BoolConversion(maximumWindow), consoleCurrentFontEx) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleOutput, maximumWindow, consoleCurrentFontEx);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetCurrentSystemConsoleFont(WindowsHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetCurrentConsoleFontEx(consoleOutput, BoolConversion(maximumWindow), consoleCurrentFontEx) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleOutput, maximumWindow, consoleCurrentFontEx);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ConsoleCoord System::GetSystemConsoleFontSize(WindowsHandle consoleOutput, WindowsDWord font) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetConsoleFontSize(consoleOutput, font);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleOutput, font);

    return ConsoleCoord{};

#endif  // SYSTEM_PLATFORM_WIN32
}
