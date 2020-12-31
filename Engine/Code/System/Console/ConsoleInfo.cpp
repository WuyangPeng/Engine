//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 0:49)

#include "System/SystemExport.h"

#include "ConsoleInfo.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

System::ConsoleCoord System::GetLargestSystemConsoleWindowSize([[maybe_unused]] WindowHandle consoleOutput) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetLargestConsoleWindowSize(consoleOutput);
#else  // !SYSTEM_PLATFORM_WIN32 
    return ConsoleCoord{};
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemConsoleHistoryInfo([[maybe_unused]] ConsoleHistoryInfoPtr consoleHistoryInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetConsoleHistoryInfo(consoleHistoryInfo) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemConsoleHistoryInfo([[maybe_unused]] ConsoleHistoryInfoPtr consoleHistoryInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetConsoleHistoryInfo(consoleHistoryInfo) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemConsoleSelectionInfo([[maybe_unused]] ConsoleSelectionInfoPtr consoleSelectionInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetConsoleSelectionInfo(consoleSelectionInfo) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetNumberOfSystemConsoleMouseButtons([[maybe_unused]] WindowDWordPtr numberOfMouseButtons) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetNumberOfConsoleMouseButtons(numberOfMouseButtons) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemConsoleWindowInfo([[maybe_unused]] WindowHandle consoleOutput, [[maybe_unused]] bool absolute, [[maybe_unused]] const ConsoleSmallRect* consoleWindow) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetConsoleWindowInfo(consoleOutput, BoolConversion(absolute), consoleWindow) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
