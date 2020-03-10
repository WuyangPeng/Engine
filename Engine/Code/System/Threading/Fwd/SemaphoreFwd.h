// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:10)

#ifndef SYSTEM_THREADING_SEMAPHORE_FWD_H
#define SYSTEM_THREADING_SEMAPHORE_FWD_H  

#include "ThreadingFlagsFwd.h"

namespace System
{
	WindowHandle CreateSystemSemaphore(WindowLong initialCount, WindowLong maximumCount) noexcept;
	WindowHandle CreateSystemSemaphore(WindowSecurityAttributesPtr semaphoreAttributes, WindowLong initialCount, WindowLong maximumCount, const TChar* name) noexcept;
	bool WaitForSystemSemaphore(WindowHandle handle) noexcept;
	bool ReleaseSystemSemaphore(WindowHandle handle, WindowLong releaseCount, WindowLongPtr previousCount) noexcept;
	bool CloseSystemSemaphore(WindowHandle handle) noexcept;
	MutexWaitReturn WaitForSystemSemaphore(WindowHandle handle, WindowDWord milliseconds) noexcept;
	MutexWaitReturn WaitForSystemSemaphore(WindowHandle handle, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn WaitForSystemSemaphore(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn WaitForSystemSemaphore(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds) noexcept;
	WindowHandle OpenSystemSemaphore(MutexStandardAccess desiredAccess, SemaphoreSpecificAccess specificAccess, bool inheritHandle, const TChar* name) noexcept;

	bool IsSystemSemaphoreValid(WindowHandle handle) noexcept;
}

#endif // SYSTEM_THREADING_SEMAPHORE_FWD_H