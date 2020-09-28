//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 15:18)

#ifndef SYSTEM_THREADING_EVENT_H
#define SYSTEM_THREADING_EVENT_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // 事件对象

    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemEvent(WindowSecurityAttributesPtr securityAttributes, const TChar* name, CreateEventType flag,
                                                                        MutexStandardAccess desiredAccess, EventSpecificAccess specificAccess) noexcept;

    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemEvent(WindowSecurityAttributesPtr securityAttributes, bool manualReset, bool initialState, const TChar* name) noexcept;
    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemEvent(bool manualReset, bool initialState) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CloseSystemEvent(WindowHandle handle) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemEvent(WindowHandle handle) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ResetSystemEvent(WindowHandle handle) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WaitForSystemEvent(WindowHandle handle) noexcept;

    [[nodiscard]] MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemEvent(WindowHandle handle, WindowDWord milliseconds) noexcept;
    [[nodiscard]] MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemEvent(WindowHandle handle, WindowDWord milliseconds, bool alertable) noexcept;
    [[nodiscard]] MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemEvent(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept;
    [[nodiscard]] MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemEvent(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds) noexcept;
    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE OpenSystemEvent(MutexStandardAccess desiredAccess, EventSpecificAccess specificAccess, bool inheritHandle, const TChar* name) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsSystemEventValid(WindowHandle eventHandle) noexcept;
}

#endif  // SYSTEM_THREADING_EVENT_H