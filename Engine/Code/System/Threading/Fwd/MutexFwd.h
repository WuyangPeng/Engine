// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:10)

#ifndef SYSTEM_THREADING_MUTEX_FWD_H
#define SYSTEM_THREADING_MUTEX_FWD_H  

#include "ThreadingFlagsFwd.h"
#include "System/Threading/Using/MutexUsing.h"

namespace System
{
	WindowHandle CreateSystemMutex(WindowSecurityAttributesPtr mutexAttributes, bool initialOwner, const TChar* name) noexcept;
	WindowHandle CreateSystemMutex(WindowSecurityAttributesPtr mutexAttributes, const TChar* name, MutexCreate flag,
								   MutexStandardAccess desiredAccess, MutexSpecificAccess specificAccess) noexcept;
	WindowHandle CreateSystemMutex() noexcept;
	bool CloseSystemMutex(WindowHandle handle) noexcept;
	bool ReleaseSystemMutex(WindowHandle handle) noexcept;
	bool WaitForSystemMutex(WindowHandle handle) noexcept;
	MutexWaitReturn WaitForSystemMutex(WindowHandle handle, WindowDWord milliseconds) noexcept;
	MutexWaitReturn WaitForSystemMutex(WindowHandle handle, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn WaitForSystemMutex(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn WaitForSystemMutex(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds) noexcept;
	WindowHandle OpenThreadingMutex(MutexStandardAccess desiredAccess, MutexSpecificAccess specificAccess, bool inheritHandle, const TChar* name) noexcept;
	bool IsSystemMutexValid(WindowHandle handle) noexcept;
	PthreadResult PthreadMutexAttributeInit(PthreadMutexattrT* attribute) noexcept;
	PthreadResult PthreadMutexAttributeSetType(PthreadMutexattrT* attribute) noexcept;
	PthreadResult PthreadMutexInit(PthreadMutexattrT* attribute, PthreadMutexT* mutex) noexcept;
	PthreadResult PthreadMutexDestroy(PthreadMutexT* mutex) noexcept;
	PthreadResult PthreadMutexAttributeDestroy(PthreadMutexattrT* attribute) noexcept;
	PthreadResult PthreadMutexLock(PthreadMutexT* mutex) noexcept;
	PthreadResult PthreadMutexUnlock(PthreadMutexT* mutex) noexcept;
	PthreadResult PthreadMutexTrylock(PthreadMutexT* mutex) noexcept;
}

#endif // SYSTEM_THREADING_MUTEX_FWD_H