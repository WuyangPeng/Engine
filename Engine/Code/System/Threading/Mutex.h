///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/12 18:08)

#ifndef SYSTEM_THREADING_MUTEX_H
#define SYSTEM_THREADING_MUTEX_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/MutexUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
    // 互斥锁的创建和销毁。

    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE CreateSystemMutex(WindowSecurityAttributesPtr mutexAttributes,
                                                                         bool initialOwner,
                                                                         const TChar* name) noexcept;
    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE CreateSystemMutex(WindowSecurityAttributesPtr mutexAttributes,
                                                                         const TChar* name,
                                                                         MutexCreate flag,
                                                                         MutexStandardAccess desiredAccess,
                                                                         MutexSpecificAccess specificAccess) noexcept;
    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE CreateSystemMutex() noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE CloseSystemMutex(WindowsHandle handle) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE ReleaseSystemMutex(WindowsHandle handle) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE WaitForSystemMutex(WindowsHandle handle) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemMutex(WindowsHandle handle, WindowsDWord milliseconds) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemMutex(WindowsHandle handle, WindowsDWord milliseconds, bool alertable) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemMutex(WindowsDWord count, const WindowsHandle* handle, bool waitAll, WindowsDWord milliseconds, bool alertable) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemMutex(WindowsDWord count, const WindowsHandle* handle, bool waitAll, WindowsDWord milliseconds) noexcept;

    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE OpenThreadingMutex(MutexStandardAccess desiredAccess, MutexSpecificAccess specificAccess, bool inheritHandle, const TChar* name) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsSystemMutexValid(WindowsHandle handle) noexcept;

    NODISCARD PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexAttributeInit(PthreadMutexattrT* attribute) noexcept;
    NODISCARD PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexAttributeSetType(PthreadMutexattrT* attribute) noexcept;
    NODISCARD PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexInit(PthreadMutexattrT* attribute, PthreadMutexT* mutex) noexcept;
    NODISCARD PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexDestroy(PthreadMutexT* mutex) noexcept;
    NODISCARD PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexAttributeDestroy(PthreadMutexattrT* attribute) noexcept;
    NODISCARD PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexLock(PthreadMutexT* mutex) noexcept;
    NODISCARD PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexUnlock(PthreadMutexT* mutex) noexcept;
    NODISCARD PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexTrylock(PthreadMutexT* mutex) noexcept;
}

#endif  // SYSTEM_THREADING_MUTEX_H