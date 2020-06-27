// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:17)

#include "System/SystemExport.h"

#include "Thread.h"
#include "Flags/ThreadFlags.h"
#include "Flags/SemaphoreFlags.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Window/WindowSystem.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/Helper/EnumCast.h"

#ifdef SYSTEM_PLATFORM_WIN32
	#include <process.h>
#endif // SYSTEM_PLATFORM_WIN32

System::ThreadHandle System
	::CreateSystemThread(WindowSecurityAttributesPtr threadAttributes, WindowSize stackSize, ThreadStartRoutine startAddress, WindowVoidPtr parameter, ThreadCreation creationFlags, WindowDWordPtr threadID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CreateThread(threadAttributes, stackSize, startAddress, parameter, EnumCastUnderlying(creationFlags), threadID);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadAttributes);
	SYSTEM_UNUSED_ARG(stackSize);
	SYSTEM_UNUSED_ARG(startAddress);
	SYSTEM_UNUSED_ARG(parameter);
	SYSTEM_UNUSED_ARG(creationFlags);
	SYSTEM_UNUSED_ARG(threadID);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::ThreadHandle System
	::CreateSystemThread(WindowSize stackSize, ThreadStartRoutine startAddress, WindowVoidPtr parameter, WindowDWordPtr threadID) noexcept
{
	return CreateSystemThread(nullptr, stackSize, startAddress, parameter, ThreadCreation::Default, threadID);
}

bool System
	::CloseSystemThread(ThreadHandle thread) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CloseHandle(thread) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(thread);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::ResumeSystemThread(ThreadHandle thread) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::ResumeThread(thread);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(thread);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::SuspendSystemThread(ThreadHandle thread) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::SuspendThread(thread);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(thread);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::ThreadHandle System
	::GetCurrentSystemThread() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetCurrentThread();
#else // !SYSTEM_PLATFORM_WIN32
	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetCurrentSystemThreadID() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetCurrentThreadId();
#else // !SYSTEM_PLATFORM_WIN32
	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemThreadPriority(ThreadHandle thread, int priority) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetThreadPriority(thread, priority) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(thread);
	SYSTEM_UNUSED_ARG(priority);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

int System
	::GetSystemThreadPriority(ThreadHandle thread) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetThreadPriority(thread);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(thread);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WaitForSystemThread(ThreadHandle handle) noexcept
{
	return WaitForSystemThread(handle, EnumCastUnderlying(MutexWait::Infinite)) != MutexWaitReturn::Failed;
}

System::MutexWaitReturn System
	::WaitForSystemThread(ThreadHandle handle, WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObject(handle, milliseconds));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(milliseconds);

	return MutexWaitReturn::Failed;
#endif // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System
	::WaitForSystemThread(ThreadHandle handle, WindowDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObjectEx(handle, milliseconds, BoolConversion(alertable)));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(milliseconds);
	SYSTEM_UNUSED_ARG(alertable);

	return MutexWaitReturn::Failed;
#endif // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System
	::WaitForSystemThread(WindowDWord count, const ThreadHandle* handle, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjectsEx(count, handle, BoolConversion(waitAll), milliseconds, BoolConversion(alertable)));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(count);
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(waitAll);
	SYSTEM_UNUSED_ARG(milliseconds);
	SYSTEM_UNUSED_ARG(alertable);

	return MutexWaitReturn::Failed;
#endif // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System
	::WaitForSystemThread(WindowDWord count, const ThreadHandle* handle, bool waitAll, WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjects(count, handle, BoolConversion(waitAll), milliseconds));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(count);
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(waitAll);
	SYSTEM_UNUSED_ARG(milliseconds);

	return MutexWaitReturn::Failed;
#endif // SYSTEM_PLATFORM_WIN32
}

System::ThreadHandle System
	::BeginSystemThread(void* security, unsigned stacksize, StartAddress startAddress, void* argument, unsigned createFlag, unsigned* threadAddress) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26490) 
	#include SYSTEM_WARNING_DISABLE(26487)
	return  reinterpret_cast<ThreadHandle>(::_beginthreadex(security, stacksize, startAddress, argument, createFlag, threadAddress));
	#include STSTEM_WARNING_POP

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(security);
	SYSTEM_UNUSED_ARG(stacksize);
	SYSTEM_UNUSED_ARG(startAddress);
	SYSTEM_UNUSED_ARG(argument);
	SYSTEM_UNUSED_ARG(createFlag);
	SYSTEM_UNUSED_ARG(threadAddress);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::EndSystemThread(unsigned retCode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return  ::_endthreadex(retCode);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(retCode);
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::IsThreadHandleValid(ThreadHandle threadHandle) noexcept
{
	if (threadHandle != nullptr && threadHandle != g_InvalidHandleValue)
		return true;
	else
		return false;
}

System::WindowDWord System
	::ExitSystemThread(WindowDWord exitCode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::ExitThread(exitCode);
#else // !SYSTEM_PLATFORM_WIN32
	return exitCode;
#endif // SYSTEM_PLATFORM_WIN32
}

