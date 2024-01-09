/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 19:21)

#include "System/SystemExport.h"

#include "ConsoleFont.h"
#include "System/Helper/Tools.h"
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

    return ConsoleCoord{};

#endif  // SYSTEM_PLATFORM_WIN32
}
