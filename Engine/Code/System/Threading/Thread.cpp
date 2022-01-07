///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/12 19:18)

#include "System/SystemExport.h"

#include "Thread.h"
#include "Flags/SemaphoreFlags.h"
#include "Flags/ThreadFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "System/Windows/WindowsSystem.h"

#ifdef SYSTEM_PLATFORM_WIN32
    #include <process.h>
#endif  // SYSTEM_PLATFORM_WIN32

System::ThreadHandle System::CreateSystemThread(WindowSecurityAttributesPtr threadAttributes, WindowsSize stackSize, ThreadStartRoutine startAddress, WindowsVoidPtr parameter, ThreadCreation creationFlags, WindowsDWordPtr threadID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CreateThread(threadAttributes, stackSize, startAddress, parameter, EnumCastUnderlying(creationFlags), threadID);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(threadAttributes, stackSize, startAddress, parameter, creationFlags, threadID);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ThreadHandle System::CreateSystemThread(WindowsSize stackSize, ThreadStartRoutine startAddress, WindowsVoidPtr parameter, WindowsDWordPtr threadID) noexcept
{
    return CreateSystemThread(nullptr, stackSize, startAddress, parameter, ThreadCreation::Default, threadID);
}

bool System::CloseSystemThread(ThreadHandle thread) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CloseHandle(thread) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(thread);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::ResumeSystemThread(ThreadHandle thread) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::ResumeThread(thread);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(thread);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::SuspendSystemThread(ThreadHandle thread) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SuspendThread(thread);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(thread);

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

System::WindowsDWord System::GetCurrentSystemThreadID() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetCurrentThreadId();

#else  // !SYSTEM_PLATFORM_WIN32

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemThreadPriority(ThreadHandle thread, int priority) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetThreadPriority(thread, priority) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(thread, priority);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::GetSystemThreadPriority(ThreadHandle thread) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetThreadPriority(thread);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(thread);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WaitForSystemThread(ThreadHandle handle) noexcept
{
    return WaitForSystemThread(handle, EnumCastUnderlying(MutexWait::Infinite)) != MutexWaitReturn::Failed;
}

System::MutexWaitReturn System::WaitForSystemThread(ThreadHandle handle, WindowsDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObject(handle, milliseconds));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(thread, milliseconds);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemThread(ThreadHandle handle, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObjectEx(handle, milliseconds, BoolConversion(alertable)));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(thread, milliseconds, alertable);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemThread(WindowsDWord count, const ThreadHandle* handle, bool waitAll, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjectsEx(count, handle, BoolConversion(waitAll), milliseconds, BoolConversion(alertable)));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(count, handle, waitAll, milliseconds, alertable);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemThread(WindowsDWord count, const ThreadHandle* handle, bool waitAll, WindowsDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjects(count, handle, BoolConversion(waitAll), milliseconds));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(count, handle, waitAll, milliseconds);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ThreadHandle System::BeginSystemThread(void* security, unsigned stacksize, StartAddress startAddress, void* argument, unsigned createFlag, unsigned* threadAddress) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<ThreadHandle>(::_beginthreadex(security, stacksize, startAddress, argument, createFlag, threadAddress));

    #include STSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(security, stacksize, startAddress, argument, createFlag, threadAddress);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::EndSystemThread(unsigned retCode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::_endthreadex(retCode);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(retCode);

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsThreadHandleValid(ThreadHandle threadHandle) noexcept
{
    if (threadHandle != nullptr && threadHandle != g_InvalidHandleValue)
        return true;
    else
        return false;
}

System::WindowsDWord System::ExitSystemThread(WindowsDWord exitCode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::ExitThread(exitCode);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(exitCode);

    return exitCode;

#endif  // SYSTEM_PLATFORM_WIN32
}
