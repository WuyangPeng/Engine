//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 15:25)

#ifndef SYSTEM_THREADING_SEMAPHORE_H
#define SYSTEM_THREADING_SEMAPHORE_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // 信号量的创建和释放

    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemSemaphore(WindowLong initialCount, WindowLong maximumCount) noexcept;
    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemSemaphore(WindowSecurityAttributesPtr semaphoreAttributes, WindowLong initialCount, WindowLong maximumCount, const TChar* name) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WaitForSystemSemaphore(WindowHandle handle) noexcept;
    [[nodiscard]] MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemSemaphore(WindowHandle handle, WindowDWord milliseconds) noexcept;
    [[nodiscard]] MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemSemaphore(WindowHandle handle, WindowDWord milliseconds, bool alertable) noexcept;
    [[nodiscard]] MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemSemaphore(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept;
    [[nodiscard]] MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemSemaphore(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ReleaseSystemSemaphore(WindowHandle handle, WindowLong releaseCount, WindowLongPtr previousCount) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CloseSystemSemaphore(WindowHandle handle) noexcept;

    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE OpenSystemSemaphore(MutexStandardAccess desiredAccess, SemaphoreSpecificAccess specificAccess, bool inheritHandle, const TChar* name) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsSystemSemaphoreValid(WindowHandle handle) noexcept;
}

#endif  // SYSTEM_THREADING_SEMAPHORE_H