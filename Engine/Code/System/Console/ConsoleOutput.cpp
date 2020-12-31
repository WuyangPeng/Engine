//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 0:51)

#include "System/SystemExport.h"

#include "ConsoleOutput.h"
#include "System/Helper/WindowsMacro.h"

bool System::ReadSystemConsoleOutput([[maybe_unused]] WindowHandle handle, [[maybe_unused]] ConsoleCharInfoPtr buffer, [[maybe_unused]] ConsoleCoord bufferSize,
                                     [[maybe_unused]] ConsoleCoord bufferCoord, [[maybe_unused]] ConsoleSmallRectPtr readRegion) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::ReadConsoleOutput(handle, buffer, bufferSize, bufferCoord, readRegion) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WriteSystemConsoleOutput([[maybe_unused]] WindowHandle handle, [[maybe_unused]] const ConsoleCharInfo* buffer, [[maybe_unused]] ConsoleCoord bufferSize,
                                      [[maybe_unused]] ConsoleCoord bufferCoord, [[maybe_unused]] ConsoleSmallRectPtr writeRegion) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::WriteConsoleOutput(handle, buffer, bufferSize, bufferCoord, writeRegion) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ReadSystemConsoleOutputCharacter([[maybe_unused]] WindowHandle handle, [[maybe_unused]] TChar* character, [[maybe_unused]] WindowDWord length,
                                              [[maybe_unused]] ConsoleCoord readCoord, [[maybe_unused]] WindowDWordPtr numberOfCharsRead) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::ReadConsoleOutputCharacter(handle, character, length, readCoord, numberOfCharsRead) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WriteSystemConsoleOutputCharacter([[maybe_unused]] WindowHandle handle, [[maybe_unused]] const TChar* character, [[maybe_unused]] WindowDWord length,
                                               [[maybe_unused]] ConsoleCoord readCoord, [[maybe_unused]] WindowDWordPtr numberOfCharsWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::WriteConsoleOutputCharacter(handle, character, length, readCoord, numberOfCharsWritten) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FillSystemConsoleOutputCharacter([[maybe_unused]] WindowHandle handle, [[maybe_unused]] TChar character, [[maybe_unused]] WindowDWord length,
                                              [[maybe_unused]] ConsoleCoord readCoord, [[maybe_unused]] WindowDWordPtr numberOfCharsWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::FillConsoleOutputCharacter(handle, character, length, readCoord, numberOfCharsWritten) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
