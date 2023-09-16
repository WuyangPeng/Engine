///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/28 16:21)

#ifndef SYSTEM_CONSOLE_CONSOLE_HANDLE_H
#define SYSTEM_CONSOLE_CONSOLE_HANDLE_H

#include "System/SystemDll.h"

#include "Fwd/ConsoleFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"

// 控制台句柄的获取和设置。
namespace System
{
    NODISCARD WindowsHandle SYSTEM_DEFAULT_DECLARE GetStandardHandle(StandardHandle standardHandle) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsHandleValid(WindowsHandle handle) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetStandardHandle(StandardHandle standardHandle, WindowsHandle handle) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetStandardHandle(StandardHandle standardHandle, WindowsHandle handle, WindowsHandlePtr previousHandle) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_HANDLE_H