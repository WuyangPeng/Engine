// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 16:13)

#ifndef SYSTEM_THREADING_SEMAPHORE_H
#define SYSTEM_THREADING_SEMAPHORE_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
	// 信号量的创建和释放

	WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemSemaphore(WindowLong initialCount, WindowLong maximumCount) noexcept;
	WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemSemaphore(WindowSecurityAttributesPtr semaphoreAttributes, WindowLong initialCount, WindowLong maximumCount, const TChar* name) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WaitForSystemSemaphore(WindowHandle handle) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemSemaphore(WindowHandle handle, WindowDWord milliseconds) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemSemaphore(WindowHandle handle, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemSemaphore(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemSemaphore(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds) noexcept;
	bool SYSTEM_DEFAULT_DECLARE ReleaseSystemSemaphore(WindowHandle handle, WindowLong releaseCount, WindowLongPtr previousCount) noexcept;
	bool SYSTEM_DEFAULT_DECLARE CloseSystemSemaphore(WindowHandle handle) noexcept;

	WindowHandle SYSTEM_DEFAULT_DECLARE OpenSystemSemaphore(MutexStandardAccess desiredAccess, SemaphoreSpecificAccess specificAccess, bool inheritHandle, const TChar* name) noexcept;
	bool SYSTEM_DEFAULT_DECLARE IsSystemSemaphoreValid(WindowHandle handle) noexcept;
}

#endif // SYSTEM_THREADING_SEMAPHORE_H