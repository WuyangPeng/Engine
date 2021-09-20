///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.3 (2021/04/26 19:39)

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

    NullFunction<ThreadStandardAccess, ThreadSpecificAccess, bool, WindowsDWord>(standardDesiredAccess, specificDesiredAccess, inheritHandle, threadID);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetThreadExitCode(ThreadHandle thread, WindowsDWordPtr exitCode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetExitCodeThread(thread, exitCode) != g_False)
        return true;
    else
        return false;

#else  // SYSTEM_PLATFORM_WIN32

    NullFunction<ThreadHandle, WindowsDWordPtr>(thread, exitCode);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::GetSystemThreadID(ThreadHandle thread) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetThreadId(thread);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<ThreadHandle>(thread);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemThreadPriorityBoost(ThreadHandle thread, bool disablePriorityBoost) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetThreadPriorityBoost(thread, disablePriorityBoost) != g_False)
        return true;
    else
        return false;

#else  // SYSTEM_PLATFORM_WIN32

    NullFunction<ThreadHandle, bool>(thread, disablePriorityBoost);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemThreadPriorityBoost(ThreadHandle thread, bool* disablePriorityBoost) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    WindowsBool result{ g_False };
    if (::GetThreadPriorityBoost(thread, &result) != g_False)
    {
        BoolConversion(result, disablePriorityBoost);

        return true;
    }
    else
    {
        return false;
    }

#else  // SYSTEM_PLATFORM_WIN32

    NullFunction<ThreadHandle, WindowsBoolPtr>(thread, disablePriorityBoost);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::OpenSystemThreadToken(ThreadHandle thread, TokenStandardAccess standardAccess, TokenSpecificAccess specificAccess, bool openAsSelf, WindowsHandlePtr tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::OpenThreadToken(thread, EnumCastUnderlying(standardAccess) | EnumCastUnderlying(specificAccess), BoolConversion(openAsSelf), tokenHandle) != g_False)
        return true;
    else
        return false;

#else  // SYSTEM_PLATFORM_WIN32

    NullFunction<ThreadHandle, TokenStandardAccess, TokenSpecificAccess, bool, WindowsHandlePtr>(thread, standardAccess, specificAccess, openAsSelf, tokenHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemThreadToken(ThreadHandlePtr thread, WindowsHandle tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetThreadToken(thread, tokenHandle) != g_False)
        return true;
    else
        return false;

#else  // SYSTEM_PLATFORM_WIN32

    NullFunction<ThreadHandlePtr, WindowsHandle>(thread, tokenHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemThreadTimes(ThreadHandle thread, FileTimePtr creationTime, FileTimePtr exitTime, FileTimePtr kernelTime, FileTimePtr userTime) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetThreadTimes(thread, creationTime, exitTime, kernelTime, userTime) != g_False)
        return true;
    else
        return false;

#else  // SYSTEM_PLATFORM_WIN32

    NullFunction<ThreadHandle, FileTimePtr, FileTimePtr, FileTimePtr, FileTimePtr>(thread, creationTime, exitTime, kernelTime, userTime);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseTokenHandle(WindowsHandle tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CloseHandle(tokenHandle) != g_False)
        return true;
    else
        return false;

#else  // SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle>(tokenHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
bool System::ImpersonateThreadSelf(SecurityImpersonationLevel securityImpersonationLevel) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::ImpersonateSelf(securityImpersonationLevel) != g_False)
        return true;
    else
        return false;

#else  // SYSTEM_PLATFORM_WIN32

    NullFunction<SecurityImpersonationLevel>(securityImpersonationLevel);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
