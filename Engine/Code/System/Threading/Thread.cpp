//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 17:38)

#include "System/SystemExport.h"

#include "Thread.h"
#include "Flags/SemaphoreFlags.h"
#include "Flags/ThreadFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/Window/WindowSystem.h"

#ifdef SYSTEM_PLATFORM_WIN32
    #include <process.h>
#endif  // SYSTEM_PLATFORM_WIN32

System::ThreadHandle System::CreateSystemThread([[maybe_unused]] WindowSecurityAttributesPtr threadAttributes, [[maybe_unused]] WindowSize stackSize, [[maybe_unused]] ThreadStartRoutine startAddress, [[maybe_unused]] WindowVoidPtr parameter, [[maybe_unused]] ThreadCreation creationFlags, [[maybe_unused]] WindowDWordPtr threadID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateThread(threadAttributes, stackSize, startAddress, parameter, EnumCastUnderlying(creationFlags), threadID);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::ThreadHandle System::CreateSystemThread(WindowSize stackSize, ThreadStartRoutine startAddress, WindowVoidPtr parameter, WindowDWordPtr threadID) noexcept
{
    return CreateSystemThread(nullptr, stackSize, startAddress, parameter, ThreadCreation::Default, threadID);
}

bool System::CloseSystemThread([[maybe_unused]] ThreadHandle thread) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::CloseHandle(thread) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::ResumeSystemThread([[maybe_unused]] ThreadHandle thread) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::ResumeThread(thread);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::SuspendSystemThread([[maybe_unused]] ThreadHandle thread) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::SuspendThread(thread);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::ThreadHandle System::GetCurrentSystemThread() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetCurrentThread();
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetCurrentSystemThreadID() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetCurrentThreadId();
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemThreadPriority([[maybe_unused]] ThreadHandle thread, [[maybe_unused]] int priority) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetThreadPriority(thread, priority) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

int System::GetSystemThreadPriority([[maybe_unused]] ThreadHandle thread) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetThreadPriority(thread);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WaitForSystemThread(ThreadHandle handle) noexcept
{
    return WaitForSystemThread(handle, EnumCastUnderlying(MutexWait::Infinite)) != MutexWaitReturn::Failed;
}

System::MutexWaitReturn System::WaitForSystemThread([[maybe_unused]] ThreadHandle handle, [[maybe_unused]] WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObject(handle, milliseconds));
#else  // !SYSTEM_PLATFORM_WIN32
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemThread([[maybe_unused]] ThreadHandle handle, [[maybe_unused]] WindowDWord milliseconds, [[maybe_unused]] bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObjectEx(handle, milliseconds, BoolConversion(alertable)));
#else  // !SYSTEM_PLATFORM_WIN32
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemThread([[maybe_unused]] WindowDWord count, [[maybe_unused]] const ThreadHandle* handle, [[maybe_unused]] bool waitAll, [[maybe_unused]] WindowDWord milliseconds, [[maybe_unused]] bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjectsEx(count, handle, BoolConversion(waitAll), milliseconds, BoolConversion(alertable)));
#else  // !SYSTEM_PLATFORM_WIN32
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemThread([[maybe_unused]] WindowDWord count, [[maybe_unused]] const ThreadHandle* handle, [[maybe_unused]] bool waitAll, [[maybe_unused]] WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjects(count, handle, BoolConversion(waitAll), milliseconds));
#else  // !SYSTEM_PLATFORM_WIN32
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::ThreadHandle System::BeginSystemThread([[maybe_unused]] void* security, [[maybe_unused]] unsigned stacksize, [[maybe_unused]] StartAddress startAddress, [[maybe_unused]] void* argument, [[maybe_unused]] unsigned createFlag, [[maybe_unused]] unsigned* threadAddress) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26490)
    return reinterpret_cast<ThreadHandle>(::_beginthreadex(security, stacksize, startAddress, argument, createFlag, threadAddress));
    #include STSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::EndSystemThread([[maybe_unused]] unsigned retCode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::_endthreadex(retCode);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsThreadHandleValid(ThreadHandle threadHandle) noexcept
{
    if (threadHandle != nullptr && threadHandle != g_InvalidHandleValue)
        return true;
    else
        return false;
}

System::WindowDWord System::ExitSystemThread(WindowDWord exitCode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::ExitThread(exitCode);
#else  // !SYSTEM_PLATFORM_WIN32
    return exitCode;
#endif  // SYSTEM_PLATFORM_WIN32
}
