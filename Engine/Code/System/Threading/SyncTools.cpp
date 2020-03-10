// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:17)

#include "System/SystemExport.h"

#include "SyncTools.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"
#include "System/EnumOperator/EnumCastDetail.h"

void System
	::SystemSleep(WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::Sleep(milliseconds);
#else // !SYSTEM_PLATFORM_WIN32
	usleep(milliseconds);
#endif // SYSTEM_PLATFORM_WIN32
}

System::SleepReturn System
	::SystemSleep(WindowDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<SleepReturn>(SleepEx(milliseconds, BoolConversion(alertable)));
#else // !SYSTEM_PLATFORM_WIN32
	usleep(milliseconds);

	SYSTEM_UNUSED_ARG(alertable);

	return SleepReturn::Succeed;
#endif // SYSTEM_PLATFORM_WIN32 
}

System::MutexWaitReturn System
	::SystemSignalObjectAndWait(ThreadHandle objectToSignal, ThreadHandle objectToWaitOn, WindowDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<MutexWaitReturn>(SignalObjectAndWait(objectToSignal, objectToWaitOn, milliseconds, BoolConversion(alertable)));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(objectToSignal);
	SYSTEM_UNUSED_ARG(objectToWaitOn);
	SYSTEM_UNUSED_ARG(milliseconds);
	SYSTEM_UNUSED_ARG(alertable);

	return false;
#endif // SYSTEM_PLATFORM_WIN32 
}
