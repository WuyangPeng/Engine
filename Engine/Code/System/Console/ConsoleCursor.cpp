//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 0:47)

#include "System/SystemExport.h"

#include "ConsoleCursor.h"
#include "System/Helper/WindowsMacro.h"

bool System::GetSystemConsoleCursorInfo([[maybe_unused]] WindowHandle consoleOutput, [[maybe_unused]] ConsoleCursorInfoPtr consoleCursorInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetConsoleCursorInfo(consoleOutput, consoleCursorInfo) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemConsoleCursorPosition([[maybe_unused]] WindowHandle consoleOutput, [[maybe_unused]] const ConsoleCoord& cursorPosition) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetConsoleCursorPosition(consoleOutput, cursorPosition) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemConsoleCursorInfo([[maybe_unused]] WindowHandle consoleOutput, [[maybe_unused]] const ConsoleCursorInfo* consoleCursorInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetConsoleCursorInfo(consoleOutput, consoleCursorInfo) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
