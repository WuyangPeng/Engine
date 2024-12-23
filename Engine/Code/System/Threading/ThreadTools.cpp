/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 17:20)

#include "System/SystemExport.h"

#include "ThreadTools.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

System::ThreadHandle System::OpenSystemThread(ThreadStandardAccess standardDesiredAccess, ThreadSpecificAccess specificDesiredAccess, bool inheritHandle, WindowsDWord threadId) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::OpenThread(EnumCastUnderlying(standardDesiredAccess) | EnumCastUnderlying(specificDesiredAccess), BoolConversion(inheritHandle), threadId);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(standardDesiredAccess, specificDesiredAccess, inheritHandle, threadId);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetThreadExitCode(ThreadHandle thread, WindowsDWordPtr exitCode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetExitCodeThread(thread, exitCode) != gFalse;

#else  // SYSTEM_PLATFORM_WIN32

    UnusedFunction(thread, exitCode);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::GetSystemThreadId(ThreadHandle thread) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetThreadId(thread);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(thread);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemThreadPriorityBoost(ThreadHandle thread, bool disablePriorityBoost) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetThreadPriorityBoost(thread, disablePriorityBoost) != gFalse;

#else  // SYSTEM_PLATFORM_WIN32

    UnusedFunction(thread, disablePriorityBoost);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemThreadPriorityBoost(ThreadHandle thread, bool* disablePriorityBoost) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    WindowsBool result{ gFalse };
    if (::GetThreadPriorityBoost(thread, &result) != gFalse)
    {
        BoolConversion(result, disablePriorityBoost);

        return true;
    }
    else
    {
        return false;
    }

#else  // SYSTEM_PLATFORM_WIN32

    UnusedFunction(thread, disablePriorityBoost);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::OpenSystemThreadToken(ThreadHandle thread, TokenStandardAccess standardAccess, TokenSpecificAccess specificAccess, bool openAsSelf, WindowsHandlePtr tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::OpenThreadToken(thread, EnumCastUnderlying(standardAccess) | EnumCastUnderlying(specificAccess), BoolConversion(openAsSelf), tokenHandle) != gFalse;

#else  // SYSTEM_PLATFORM_WIN32

    UnusedFunction(thread, standardAccess, specificAccess, openAsSelf, tokenHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemThreadToken(ThreadHandlePtr thread, WindowsHandle tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetThreadToken(thread, tokenHandle) != gFalse;

#else  // SYSTEM_PLATFORM_WIN32

    UnusedFunction(thread, tokenHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemThreadTimes(ThreadHandle thread, FileTimePtr creationTime, FileTimePtr exitTime, FileTimePtr kernelTime, FileTimePtr userTime) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetThreadTimes(thread, creationTime, exitTime, kernelTime, userTime) != gFalse;

#else  // SYSTEM_PLATFORM_WIN32

    UnusedFunction(thread, creationTime, exitTime, kernelTime, userTime);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseTokenHandle(WindowsHandle tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CloseHandle(tokenHandle) != gFalse;

#else  // SYSTEM_PLATFORM_WIN32

    UnusedFunction(tokenHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ImpersonateThreadSelf(SecurityImpersonationLevel securityImpersonationLevel) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::ImpersonateSelf(securityImpersonationLevel) != gFalse;

#else  // SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityImpersonationLevel);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}