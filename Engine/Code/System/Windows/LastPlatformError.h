///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.1 (2023/02/02 14:39)

#ifndef SYSTEM_WINDOWS_LAST_PLATFORM_ERROR_H
#define SYSTEM_WINDOWS_LAST_PLATFORM_ERROR_H

#include "System/SystemDll.h"

#include "Fwd/WindowsFlagsFwd.h"

// 获取和设置系统错误码。
namespace System
{
    NODISCARD WindowError SYSTEM_DEFAULT_DECLARE GetPlatformLastError() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetPlatformLastError(WindowError error) noexcept;
    NODISCARD ErrorMode SYSTEM_DEFAULT_DECLARE GetPlatformErrorMode() noexcept;
    NODISCARD ErrorMode SYSTEM_DEFAULT_DECLARE SetPlatformErrorMode(ErrorMode flag) noexcept;
}

#endif  // SYSTEM_WINDOWS_LAST_PLATFORM_ERROR_H
