//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 0:55)

#include "System/SystemExport.h"

#include "ConsoleTools.h"
#include "System/Helper/WindowsMacro.h"

bool System::SetSystemConsoleActiveScreenBuffer([[maybe_unused]] WindowHandle consoleOutput) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetConsoleActiveScreenBuffer(consoleOutput) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddSystemConsoleCtrlHandler([[maybe_unused]] ConsoleHandlerRoutine handlerRoutine) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetConsoleCtrlHandler(handlerRoutine, g_True) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::DeleteSystemConsoleCtrlHandler([[maybe_unused]] ConsoleHandlerRoutine handlerRoutine) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetConsoleCtrlHandler(handlerRoutine, g_False) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHWnd System::GetSystemConsoleWindow() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetConsoleWindow();
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ReadSystemConsole([[maybe_unused]] WindowHandle consoleInput, [[maybe_unused]] WindowVoidPtr buffer, [[maybe_unused]] WindowDWord numberOfCharsToRead,
                               [[maybe_unused]] WindowDWordPtr numberOfCharsRead, [[maybe_unused]] ConsoleReadConsoleControlPtr inputControl) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::ReadConsole(consoleInput, buffer, numberOfCharsToRead, numberOfCharsRead, inputControl) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WriteSystemConsole([[maybe_unused]] WindowHandle consoleOutput, [[maybe_unused]] const void* buffer, [[maybe_unused]] WindowDWord numberOfCharsToWrite, [[maybe_unused]] WindowDWordPtr numberOfCharsWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::WriteConsole(consoleOutput, buffer, numberOfCharsToWrite, numberOfCharsWritten, nullptr) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
