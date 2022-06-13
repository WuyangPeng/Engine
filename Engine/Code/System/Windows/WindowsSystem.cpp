///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/12 13:30)

#include "System/SystemExport.h"

#include "WindowsSystem.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

void System::GetWindowSystemInfo(WindowsSystemInfo& systemInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::GetSystemInfo(&systemInfo);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(systemInfoy);

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

int System::SystemCommand(const char* command) noexcept
{
    return std::system(command);
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

System::WindowsBool System::BoolConversion(bool value) noexcept
{
    if (value)
        return gTrue;
    else
        return gFalse;
}

void System::BoolConversion(WindowsBool value, bool* result) noexcept
{
    if (result != nullptr)
    {
        *result = ((value != gFalse) ? true : false);
    }
}
