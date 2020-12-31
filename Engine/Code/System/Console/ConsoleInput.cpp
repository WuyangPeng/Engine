//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 0:50)

#include "System/SystemExport.h"

#include "ConsoleInput.h"
#include "System/Helper/WindowsMacro.h"

bool System::PeekSystemConsoleInput([[maybe_unused]] WindowHandle handle, [[maybe_unused]] ConsoleInputRecordPtr buffer, [[maybe_unused]] WindowDWord length, [[maybe_unused]] WindowDWordPtr numberOfEventsRead) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::PeekConsoleInput(handle, buffer, length, numberOfEventsRead) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ReadSystemConsoleInput([[maybe_unused]] WindowHandle handle, [[maybe_unused]] ConsoleInputRecordPtr buffer, [[maybe_unused]] WindowDWord length, [[maybe_unused]] WindowDWordPtr numberOfEventsRead) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::ReadConsoleInput(handle, buffer, length, numberOfEventsRead) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WriteSystemConsoleInput([[maybe_unused]] WindowHandle handle, [[maybe_unused]] const ConsoleInputRecord* buffer, [[maybe_unused]] WindowDWord length, [[maybe_unused]] WindowDWordPtr numberOfEventsWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::WriteConsoleInput(handle, buffer, length, numberOfEventsWritten) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32  
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetNumberOfSystemConsoleInputEvents([[maybe_unused]] WindowHandle handle, [[maybe_unused]] WindowDWordPtr numberOfEvents) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetNumberOfConsoleInputEvents(handle, numberOfEvents) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FlushSystemConsoleInputBuffer([[maybe_unused]] WindowHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::FlushConsoleInputBuffer(handle) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
