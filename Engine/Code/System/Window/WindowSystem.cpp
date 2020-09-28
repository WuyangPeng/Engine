//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 15:44)

#include "System/SystemExport.h"

#include "WindowSystem.h"

#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

#ifdef SYSTEM_PLATFORM_WIN32
    #include <ImageHlp.h>
    #include <WindowsX.h>
#endif  // SYSTEM_PLATFORM_WIN32

#include <cstdlib>

using std::system;

void System::GetWindowSystemInfo([[maybe_unused]] WindowSystemInfo& systemInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::GetSystemInfo(&systemInfo);
#else  // !SYSTEM_PLATFORM_WIN32

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

bool System::GetNumaProcessorNodeNumber([[maybe_unused]] WindowUChar processor, [[maybe_unused]] WindowUCharPtr nodeNumber) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetNumaProcessorNode(processor, nodeNumber) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

int System::SystemCommand(const char* command) noexcept
{
    return system(command);
}

bool System::SetSystemCurrentDirectory([[maybe_unused]] const TChar* pathName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetCurrentDirectory(pathName) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemUserName([[maybe_unused]] TChar* buffer, [[maybe_unused]] WindowDWord* bufferCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetUserName(buffer, bufferCount) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetSystemCurrentDirectory([[maybe_unused]] WindowDWord bufferLength, [[maybe_unused]] TChar* buffer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetCurrentDirectory(bufferLength, buffer);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowBool System::BoolConversion(bool value) noexcept
{
    if (value)
        return g_True;
    else
        return g_False;
}

void System::BoolConversion(WindowBool value, bool* result) noexcept
{
    if (result != nullptr)
    {
        *result = ((value != g_False) ? true : false);
    }
}
