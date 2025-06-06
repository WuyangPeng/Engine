/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 17:14)

#ifndef SYSTEM_THREADING_SEMAPHORE_H
#define SYSTEM_THREADING_SEMAPHORE_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

/// 信号量的创建和释放
namespace System
{
    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE CreateSystemSemaphore(WindowsLong initialCount, WindowsLong maximumCount) noexcept;
    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE CreateSystemSemaphore(WindowSecurityAttributesPtr semaphoreAttributes,
                                                                             WindowsLong initialCount,
                                                                             WindowsLong maximumCount,
                                                                             const TChar* name) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE WaitForSystemSemaphore(WindowsHandle handle) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemSemaphore(WindowsHandle handle,
                                                                            WindowsDWord milliseconds) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemSemaphore(WindowsHandle handle,
                                                                            WindowsDWord milliseconds,
                                                                            bool alertable) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemSemaphore(WindowsDWord count,
                                                                            const WindowsHandle* handle,
                                                                            bool waitAll,
                                                                            WindowsDWord milliseconds,
                                                                            bool alertable) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemSemaphore(WindowsDWord count,
                                                                            const WindowsHandle* handle,
                                                                            bool waitAll,
                                                                            WindowsDWord milliseconds) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE ReleaseSystemSemaphore(WindowsHandle handle,
                                                                 WindowsLong releaseCount,
                                                                 WindowsLongPtr previousCount) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE CloseSystemSemaphore(WindowsHandle handle) noexcept;

    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE OpenSystemSemaphore(MutexStandardAccess desiredAccess,
                                                                           SemaphoreSpecificAccess specificAccess,
                                                                           bool inheritHandle,
                                                                           const TChar* name) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsSystemSemaphoreValid(WindowsHandle handle) noexcept;
}

#endif  // SYSTEM_THREADING_SEMAPHORE_H