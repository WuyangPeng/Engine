// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 16:13)

#ifndef SYSTEM_THREADING_MUTEX_H
#define SYSTEM_THREADING_MUTEX_H

#include "System/SystemDll.h"

#include "Using/MutexUsing.h"
#include "Fwd/ThreadingFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
	// 互斥锁的创建和销毁。

	WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemMutex(WindowSecurityAttributesPtr mutexAttributes, bool initialOwner, const TChar* name) noexcept;
	WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemMutex(WindowSecurityAttributesPtr mutexAttributes, const TChar* name, MutexCreate flag,
														  MutexStandardAccess desiredAccess, MutexSpecificAccess specificAccess) noexcept;
	WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemMutex() noexcept;
	bool SYSTEM_DEFAULT_DECLARE CloseSystemMutex(WindowHandle handle) noexcept;
	bool SYSTEM_DEFAULT_DECLARE ReleaseSystemMutex(WindowHandle handle) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WaitForSystemMutex(WindowHandle handle) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemMutex(WindowHandle handle, WindowDWord milliseconds) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemMutex(WindowHandle handle, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemMutex(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemMutex(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds) noexcept;
	WindowHandle SYSTEM_DEFAULT_DECLARE OpenThreadingMutex(MutexStandardAccess desiredAccess, MutexSpecificAccess specificAccess, bool inheritHandle, const TChar* name) noexcept;
	bool SYSTEM_DEFAULT_DECLARE IsSystemMutexValid(WindowHandle handle) noexcept;
	PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexAttributeInit(PthreadMutexattrT* attribute) noexcept;
	PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexAttributeSetType(PthreadMutexattrT* attribute) noexcept;
	PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexInit(PthreadMutexattrT* attribute, PthreadMutexT* mutex) noexcept;
	PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexDestroy(PthreadMutexT* mutex) noexcept;
	PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexAttributeDestroy(PthreadMutexattrT* attribute) noexcept;
	PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexLock(PthreadMutexT* mutex) noexcept;
	PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexUnlock(PthreadMutexT* mutex) noexcept;
	PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexTrylock(PthreadMutexT* mutex) noexcept;
}

#endif // SYSTEM_THREADING_MUTEX_H