//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 17:58)

#include "System/SystemExport.h"

#include "ThreadTools.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

System::ThreadHandle System::CreateSystemRemoteThread([[maybe_unused]] WindowHandle process, [[maybe_unused]] WindowSecurityAttributesPtr threadAttributes, [[maybe_unused]] WindowSize stackSize, [[maybe_unused]] ThreadStartRoutine startAddress,
                                                      [[maybe_unused]] WindowVoidPtr parameter, [[maybe_unused]] ThreadCreation creationFlags, [[maybe_unused]] WindowDWordPtr threadID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateRemoteThread(process, threadAttributes, stackSize, startAddress, parameter, EnumCastUnderlying(creationFlags), threadID);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::ThreadHandle System::CreateSystemRemoteThread([[maybe_unused]] WindowHandle process, [[maybe_unused]] WindowSecurityAttributesPtr threadAttributes, [[maybe_unused]] WindowSize stackSize, [[maybe_unused]] ThreadStartRoutine startAddress,
                                                      [[maybe_unused]] WindowVoidPtr parameter, [[maybe_unused]] ThreadCreation creationFlags, [[maybe_unused]] ProcThreadAttributeListPtr attributeList, [[maybe_unused]] WindowDWordPtr threadID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateRemoteThreadEx(process, threadAttributes, stackSize, startAddress, parameter, EnumCastUnderlying(creationFlags), attributeList, threadID);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::ThreadHandle System::OpenSystemThread([[maybe_unused]] ThreadStandardAccess standardDesiredAccess, [[maybe_unused]] ThreadSpecificAccess specificDesiredAccess, [[maybe_unused]] bool inheritHandle, [[maybe_unused]] WindowDWord threadID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::OpenThread(EnumCastUnderlying(standardDesiredAccess) | EnumCastUnderlying(specificDesiredAccess), BoolConversion(inheritHandle), threadID);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetThreadExitCode([[maybe_unused]] ThreadHandle thread, [[maybe_unused]] WindowDWordPtr exitCode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetExitCodeThread(thread, exitCode) != g_False)
        return true;
    else
        return false;
#else  // SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetSystemThreadID([[maybe_unused]] ThreadHandle thread) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetThreadId(thread);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemThreadPriorityBoost([[maybe_unused]] ThreadHandle thread, [[maybe_unused]] bool disablePriorityBoost) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetThreadPriorityBoost(thread, disablePriorityBoost) != g_False)
        return true;
    else
        return false;
#else  // SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemThreadPriorityBoost([[maybe_unused]] ThreadHandle thread, [[maybe_unused]] WindowBoolPtr disablePriorityBoost) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetThreadPriorityBoost(thread, disablePriorityBoost) != g_False)
        return true;
    else
        return false;
#else  // SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SwitchToSystemThread() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SwitchToThread() != g_False)
        return true;
    else
        return false;
#else  // SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::OpenSystemThreadToken([[maybe_unused]] ThreadHandle thread, [[maybe_unused]] TokenStandardAccess standardAccess, [[maybe_unused]] TokenSpecificAccess specificAccess, [[maybe_unused]] bool openAsSelf, [[maybe_unused]] WindowHandlePtr tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::OpenThreadToken(thread, EnumCastUnderlying(standardAccess) | EnumCastUnderlying(specificAccess), BoolConversion(openAsSelf), tokenHandle) != g_False)
        return true;
    else
        return false;
#else  // SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemThreadToken([[maybe_unused]] ThreadHandlePtr thread, [[maybe_unused]] WindowHandle tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetThreadToken(thread, tokenHandle) != g_False)
        return true;
    else
        return false;
#else  // SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemThreadContext([[maybe_unused]] ThreadHandle thread, [[maybe_unused]] WindowContextPtr context) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetThreadContext(thread, context) != g_False)
        return true;
    else
        return false;
#else  // SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemThreadContext([[maybe_unused]] ThreadHandle thread, [[maybe_unused]] const WindowContext* context) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetThreadContext(thread, context) != g_False)
        return true;
    else
        return false;
#else  // SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemThreadTimes([[maybe_unused]] ThreadHandle thread, [[maybe_unused]] FileTimePtr creationTime, [[maybe_unused]] FileTimePtr exitTime, [[maybe_unused]] FileTimePtr kernelTime, [[maybe_unused]] FileTimePtr userTime) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetThreadTimes(thread, creationTime, exitTime, kernelTime, userTime) != g_False)
        return true;
    else
        return false;
#else  // SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseTokenHandle([[maybe_unused]] WindowHandle tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::CloseHandle(tokenHandle) != g_False)
        return true;
    else
        return false;
#else  // SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ImpersonateThreadSelf([[maybe_unused]] SecurityImpersonationLevel securityImpersonationLevel) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::ImpersonateSelf(securityImpersonationLevel) != g_False)
        return true;
    else
        return false;
#else  // SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::InitThreadContextFlags(WindowContext& context, ThreadContextState flags) noexcept
{
    context.ContextFlags = EnumCastUnderlying(flags);
}
