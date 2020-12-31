//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 0:48)

#include "System/SystemExport.h"

#include "ConsoleFont.h"

#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

bool System::GetCurrentSystemConsoleFont([[maybe_unused]] WindowHandle consoleOutput, [[maybe_unused]] bool maximumWindow, [[maybe_unused]] ConsoleFontInfoPtr consoleCurrentFont) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetCurrentConsoleFont(consoleOutput, BoolConversion(maximumWindow), consoleCurrentFont) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetCurrentSystemConsoleFont([[maybe_unused]] WindowHandle consoleOutput, [[maybe_unused]] bool maximumWindow, [[maybe_unused]] ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetCurrentConsoleFontEx(consoleOutput, BoolConversion(maximumWindow), consoleCurrentFontEx) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetCurrentSystemConsoleFont([[maybe_unused]] WindowHandle consoleOutput, [[maybe_unused]] bool maximumWindow, [[maybe_unused]] ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetCurrentConsoleFontEx(consoleOutput, BoolConversion(maximumWindow), consoleCurrentFontEx) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::ConsoleCoord System::GetSystemConsoleFontSize([[maybe_unused]] WindowHandle consoleOutput, [[maybe_unused]] WindowDWord font) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetConsoleFontSize(consoleOutput, font);
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
