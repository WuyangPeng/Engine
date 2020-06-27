// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 13:14)

#include "System/SystemExport.h"

#include "WaitableTimer.h"
#include "Flags/SemaphoreFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

System::WindowHandle System
	::CreateSystemWaitableTimer(WindowSecurityAttributesPtr timerAttributes, bool manualReset, const TChar* timerName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CreateWaitableTimer(timerAttributes, BoolConversion(manualReset), timerName);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(timerAttributes);
	SYSTEM_UNUSED_ARG(manualReset);
	SYSTEM_UNUSED_ARG(timerName);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System
	::CreateSystemWaitableTimer(WindowSecurityAttributesPtr timerAttributes, const TChar* timerName, CreateWaitableTimerReset flag,
								MutexStandardAccess desiredAccess, WaitableTimerSpecificAccess specificAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CreateWaitableTimerEx(timerAttributes, timerName, EnumCastUnderlying(flag), EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(timerAttributes);
	SYSTEM_UNUSED_ARG(timerName);
	SYSTEM_UNUSED_ARG(flag);
	SYSTEM_UNUSED_ARG(desiredAccess);
	SYSTEM_UNUSED_ARG(specificAccess);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CancelSystemWaitableTimer(WindowHandle timer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CancelWaitableTimer(timer) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(timer);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CloseSystemWaitableTimer(WindowHandle timer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CloseHandle(timer) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(timer);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WaitForSystemWaitableTimer(WindowHandle timer) noexcept
{
	return WaitForSystemWaitableTimer(timer, EnumCastUnderlying(MutexWait::Infinite)) != MutexWaitReturn::Failed;
}

System::MutexWaitReturn System
	::WaitForSystemWaitableTimer(WindowHandle timer, WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObject(timer, milliseconds));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(timer);
	SYSTEM_UNUSED_ARG(milliseconds);

	return MutexWaitReturn::Failed;
#endif // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System
	::WaitForSystemWaitableTimer(WindowHandle timer, WindowDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObjectEx(timer, milliseconds, BoolConversion(alertable)));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(timer);
	SYSTEM_UNUSED_ARG(milliseconds);
	SYSTEM_UNUSED_ARG(alertable);

	return MutexWaitReturn::Failed;
#endif // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System
	::WaitForSystemWaitableTimer(WindowDWord count, const WindowHandle* timer, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjectsEx(count, timer, BoolConversion(waitAll), milliseconds, BoolConversion(alertable)));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(count);
	SYSTEM_UNUSED_ARG(timer);
	SYSTEM_UNUSED_ARG(waitAll);
	SYSTEM_UNUSED_ARG(milliseconds);
	SYSTEM_UNUSED_ARG(alertable);

	return MutexWaitReturn::Failed;
#endif // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System
	::WaitForSystemWaitableTimer(WindowDWord count, const WindowHandle* timer, bool waitAll, WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjects(count, timer, BoolConversion(waitAll), milliseconds));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(count);
	SYSTEM_UNUSED_ARG(timer);
	SYSTEM_UNUSED_ARG(waitAll);
	SYSTEM_UNUSED_ARG(milliseconds);

	return MutexWaitReturn::Failed;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemWaitableTimer(WindowHandle timer, const WindowLargeInteger* dueTime, WindowLong period, TimerApcRoutine completionRoutine,
							 WindowVoidPtr argToCompletionRoutine, WaitableTimerReasonContextPtr wakeContext, WindowULong tolerableDelay) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetWaitableTimerEx(timer, dueTime, period, completionRoutine, argToCompletionRoutine, wakeContext, tolerableDelay) != g_False)
		return true;
	else
		return false;
#else // SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(timer);
	SYSTEM_UNUSED_ARG(dueTime);
	SYSTEM_UNUSED_ARG(period);
	SYSTEM_UNUSED_ARG(completionRoutine);
	SYSTEM_UNUSED_ARG(argToCompletionRoutine);
	SYSTEM_UNUSED_ARG(wakeContext);
	SYSTEM_UNUSED_ARG(tolerableDelay);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemWaitableTimer(WindowHandle timer, const WindowLargeInteger* dueTime, WindowLong period,
							 TimerApcRoutine completionRoutine, WindowVoidPtr argToCompletionRoutine, bool resume) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetWaitableTimer(timer, dueTime, period, completionRoutine, argToCompletionRoutine, BoolConversion(resume)) != g_False)
		return true;
	else
		return false;
#else // SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(timer);
	SYSTEM_UNUSED_ARG(dueTime);
	SYSTEM_UNUSED_ARG(period);
	SYSTEM_UNUSED_ARG(completionRoutine);
	SYSTEM_UNUSED_ARG(argToCompletionRoutine);
	SYSTEM_UNUSED_ARG(resume);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System
	::OpenSystemWaitableTimer(MutexStandardAccess desiredAccess, WaitableTimerSpecificAccess specificAccess, bool inheritHandle, const TChar* timerName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::OpenWaitableTimer(EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess), BoolConversion(inheritHandle), timerName);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(desiredAccess);
	SYSTEM_UNUSED_ARG(specificAccess);
	SYSTEM_UNUSED_ARG(inheritHandle);
	SYSTEM_UNUSED_ARG(timerName);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::IsWaitableTimerValid(WindowHandle handle) noexcept
{
	if (handle != nullptr && handle != g_InvalidHandleValue)
		return true;
	else
		return false;
}
