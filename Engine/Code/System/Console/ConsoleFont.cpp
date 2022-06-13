///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 22:26)

#include "System/SystemExport.h"

#include "ConsoleFont.h"

#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

bool System::GetCurrentSystemConsoleFont(WindowsHandle consoleOutput, bool maximumWindow, ConsoleFontInfoPtr consoleCurrentFont) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetCurrentConsoleFont(consoleOutput, BoolConversion(maximumWindow), consoleCurrentFont) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleOutput, maximumWindow, consoleCurrentFont);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetCurrentSystemConsoleFont(WindowsHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetCurrentConsoleFontEx(consoleOutput, BoolConversion(maximumWindow), consoleCurrentFontEx) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleOutput, maximumWindow, consoleCurrentFontEx);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetCurrentSystemConsoleFont(WindowsHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetCurrentConsoleFontEx(consoleOutput, BoolConversion(maximumWindow), consoleCurrentFontEx) != gFalse)
        return true;
    else
        return false;

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

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
