///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/30 18:18)

#ifndef SYSTEM_THREADING_EVENT_H
#define SYSTEM_THREADING_EVENT_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

// 事件对象
namespace System
{
    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE CreateSystemEvent(WindowSecurityAttributesPtr securityAttributes,
                                                                         const TChar* name,
                                                                         CreateEventType flag,
                                                                         MutexStandardAccess desiredAccess,
                                                                         EventSpecificAccess specificAccess) noexcept;
    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE CreateSystemEvent(WindowSecurityAttributesPtr securityAttributes,
                                                                         bool manualReset,
                                                                         bool initialState,
                                                                         const TChar* name) noexcept;
    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE CreateSystemEvent(bool manualReset, bool initialState) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE CloseSystemEvent(WindowsHandle handle) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemEvent(WindowsHandle handle) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE ResetSystemEvent(WindowsHandle handle) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE WaitForSystemEvent(WindowsHandle handle) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemEvent(WindowsHandle handle,
                                                                        WindowsDWord milliseconds) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemEvent(WindowsHandle handle,
                                                                        WindowsDWord milliseconds,
                                                                        bool alertable) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemEvent(WindowsDWord count,
                                                                        const WindowsHandle* handle,
                                                                        bool waitAll,
                                                                        WindowsDWord milliseconds,
                                                                        bool alertable) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemEvent(WindowsDWord count,
                                                                        const WindowsHandle* handle,
                                                                        bool waitAll,
                                                                        WindowsDWord milliseconds) noexcept;

    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE OpenSystemEvent(MutexStandardAccess desiredAccess,
                                                                       EventSpecificAccess specificAccess,
                                                                       bool inheritHandle,
                                                                       const TChar* name) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsSystemEventValid(WindowsHandle eventHandle) noexcept;
}

#endif  // SYSTEM_THREADING_EVENT_H