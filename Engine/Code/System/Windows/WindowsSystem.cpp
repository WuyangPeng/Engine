///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.6 (2021/07/05 23:31)

#include "System/SystemExport.h"

#include "WindowsSystem.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

#ifdef SYSTEM_PLATFORM_WIN32
    #include <ImageHlp.h>
    #include <WindowsX.h>
#endif  // SYSTEM_PLATFORM_WIN32

#include <cstdlib>

using std::system;

void System::GetWindowSystemInfo(WindowsSystemInfo& systemInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::GetSystemInfo(&systemInfo);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsSystemInfo&>(systemInfoy);

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

    if (::GetNumaProcessorNode(processor, nodeNumber) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsUChar, WindowsUCharPtr>(processor, nodeNumber);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::SystemCommand(const char* command) noexcept
{
    return system(command);
}

bool System::SetSystemCurrentDirectory(const TChar* pathName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetCurrentDirectory(pathName) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<const TChar*>(pathName);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemUserName(TChar* buffer, WindowsDWord* bufferCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetUserName(buffer, bufferCount) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<TChar*, WindowsDWord*>(buffer, bufferCount);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::GetSystemCurrentDirectory(WindowsDWord bufferLength, TChar* buffer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetCurrentDirectory(bufferLength, buffer);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsDWord, TChar*>(bufferLength, buffer);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::BoolConversion(bool value) noexcept
{
    if (value)
        return g_True;
    else
        return g_False;
}

void System::BoolConversion(WindowsBool value, bool* result) noexcept
{
    if (result != nullptr)
    {
        *result = ((value != g_False) ? true : false);
    }
}
