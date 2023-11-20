///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 09:26)

#include "System/SystemExport.h"

#include "WindowsSystem.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

void System::GetWindowSystemInfo(WindowsSystemInfo& systemInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::GetSystemInfo(&systemInfo);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(systemInfo);

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetNumaProcessorNodeNumber(WindowsUChar processor, WindowsUCharPtr nodeNumber) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetNumaProcessorNode(processor, nodeNumber) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(processor, nodeNumber);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemCurrentDirectory(const TChar* pathName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetCurrentDirectory(pathName) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(pathName);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemUserName(TChar* buffer, WindowsDWord* bufferCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetUserName(buffer, bufferCount) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(buffer, bufferCount);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::GetSystemCurrentDirectory(WindowsDWord bufferLength, TChar* buffer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetCurrentDirectory(bufferLength, buffer);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(bufferLength, buffer);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::BoolConversion(bool input) noexcept
{
    if (input)
        return gTrue;
    else
        return gFalse;
}

void System::BoolConversion(WindowsBool input, bool* result) noexcept
{
    if (result != nullptr)
    {
        *result = ((input != gFalse) ? true : false);
    }
}

System::WindowsHWnd System::GetActiveWindow() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetActiveWindow();

#else  // !SYSTEM_PLATFORM_WIN32

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemClientRect(WindowsHWnd hWnd, WindowsRect& windowsRect) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetClientRect(hWnd, &windowsRect) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd, windowsRect);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::DebugBreak() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::__debugbreak();

#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::Exit() noexcept
{
    ::exit(0);
}

int System::SystemCommand(const char* command) noexcept
{
    return std::system(command);
}
