/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 17:19)

#include "System/SystemExport.h"

#include "Thread.h"
#include "Flags/SemaphoreFlags.h"
#include "Flags/ThreadFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "System/Windows/WindowsSystem.h"

#include <gsl/util>

#ifdef SYSTEM_PLATFORM_WIN32

    #include <process.h>

#endif  // SYSTEM_PLATFORM_WIN32

System::ThreadHandle System::CreateSystemThread(WindowSecurityAttributesPtr threadAttributes, WindowsSize stackSize, ThreadStartRoutine startAddress, WindowsVoidPtr parameter, ThreadCreation creationFlags, WindowsDWordPtr threadId) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CreateThread(threadAttributes, stackSize, startAddress, parameter, EnumCastUnderlying(creationFlags), threadId);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(threadAttributes, stackSize, startAddress, parameter, creationFlags, threadId);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ThreadHandle System::CreateSystemThread(WindowsSize stackSize, ThreadStartRoutine startAddress, WindowsVoidPtr parameter, WindowsDWordPtr threadId) noexcept
{
    return CreateSystemThread(nullptr, stackSize, startAddress, parameter, ThreadCreation::Default, threadId);
}

bool System::CloseSystemThread(ThreadHandle thread) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CloseHandle(thread) != gFalse;

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

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::GetCurrentSystemThreadId() noexcept
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

    return ::SetThreadPriority(thread, priority) != gFalse;

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

    return UnderlyingCastEnum<MutexWaitReturn>(gsl::narrow_cast<int>(::WaitForSingleObject(handle, milliseconds)));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle, milliseconds);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemThread(ThreadHandle handle, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(gsl::narrow_cast<int>(::WaitForSingleObjectEx(handle, milliseconds, BoolConversion(alertable))));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle, milliseconds, alertable);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemThread(WindowsDWord count, const ThreadHandle* handle, bool waitAll, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(gsl::narrow_cast<int>(::WaitForMultipleObjectsEx(count, handle, BoolConversion(waitAll), milliseconds, BoolConversion(alertable))));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(count, handle, waitAll, milliseconds, alertable);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemThread(WindowsDWord count, const ThreadHandle* handle, bool waitAll, WindowsDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(gsl::narrow_cast<int>(::WaitForMultipleObjects(count, handle, BoolConversion(waitAll), milliseconds)));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(count, handle, waitAll, milliseconds);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ThreadHandle System::BeginSystemThread(void* security, unsigned int stackSize, StartAddress startAddress, void* argument, unsigned int createFlag, unsigned int* threadAddress) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include SYSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<ThreadHandle>(::_beginthreadex(security, stackSize, startAddress, argument, createFlag, threadAddress));

    #include SYSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(security, stackSize, startAddress, argument, createFlag, threadAddress);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::EndSystemThread(unsigned int retCode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::_endthreadex(retCode);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(retCode);

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsThreadHandleValid(ThreadHandle threadHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return threadHandle != nullptr && threadHandle != invalidHandleValue;

#else  // !SYSTEM_PLATFORM_WIN32

    return threadHandle != 0;

#endif  // SYSTEM_PLATFORM_WIN32
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