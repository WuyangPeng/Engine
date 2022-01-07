///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 22:24)

#ifndef SYSTEM_CONSOLE_CONSOLE_HANDLE_H
#define SYSTEM_CONSOLE_CONSOLE_HANDLE_H

#include "System/SystemDll.h"

#include "Fwd/ConsoleFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // 控制台句柄的获取和设置。

    NODISCARD WindowsHandle SYSTEM_DEFAULT_DECLARE GetStandardHandle(StandardHandle standardhandle) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsHandleValid(WindowsHandle handle) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetStandardHandle(StandardHandle standardhandle, WindowsHandle handle) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetStandardHandle(StandardHandle standardhandle, WindowsHandle handle, WindowsHandlePtr previousHandle) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_HANDLE_H