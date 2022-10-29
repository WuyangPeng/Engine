///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/21 0:16)

#include "System/SystemExport.h"

#include "ThreadTools.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

System::ThreadHandle System::OpenSystemThread(ThreadStandardAccess standardDesiredAccess, ThreadSpecificAccess specificDesiredAccess, bool inheritHandle, WindowsDWord threadID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::OpenThread(EnumCastUnderlying(standardDesiredAccess) | EnumCastUnderlying(specificDesiredAccess), BoolConversion(inheritHandle), threadID);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(standardDesiredAccess, specificDesiredAccess, inheritHandle, threadID);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetThreadExitCode(ThreadHandle thread, WindowsDWordPtr exitCode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetExitCodeThread(thread, exitCode) != gFalse)
        return true;
    else
        return false;

#else  // SYSTEM_PLATFORM_WIN32

    UnusedFunction(thread, exitCode);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::GetSystemThreadID(ThreadHandle thread) noexcept
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

    if (::SetThreadPriorityBoost(thread, disablePriorityBoost) != gFalse)
        return true;
    else
        return false;

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

    if (::OpenThreadToken(thread, EnumCastUnderlying(standardAccess) | EnumCastUnderlying(specificAccess), BoolConversion(openAsSelf), tokenHandle) != gFalse)
        return true;
    else
        return false;

#else  // SYSTEM_PLATFORM_WIN32

    UnusedFunction(thread, standardAccess, specificAccess, openAsSelf, tokenHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemThreadToken(ThreadHandlePtr thread, WindowsHandle tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetThreadToken(thread, tokenHandle) != gFalse)
        return true;
    else
        return false;

#else  // SYSTEM_PLATFORM_WIN32

    UnusedFunction(thread, tokenHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemThreadTimes(ThreadHandle thread, FileTimePtr creationTime, FileTimePtr exitTime, FileTimePtr kernelTime, FileTimePtr userTime) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetThreadTimes(thread, creationTime, exitTime, kernelTime, userTime) != gFalse)
        return true;
    else
        return false;

#else  // SYSTEM_PLATFORM_WIN32

    UnusedFunction(thread, creationTime, exitTime, kernelTime, userTime);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseTokenHandle(WindowsHandle tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CloseHandle(tokenHandle) != gFalse)
        return true;
    else
        return false;

#else  // SYSTEM_PLATFORM_WIN32

    UnusedFunction(tokenHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ImpersonateThreadSelf(SecurityImpersonationLevel securityImpersonationLevel) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::ImpersonateSelf(securityImpersonationLevel) != gFalse)
        return true;
    else
        return false;

#else  // SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityImpersonationLevel);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
