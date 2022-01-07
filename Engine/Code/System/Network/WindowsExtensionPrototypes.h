///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 14:35)

#ifndef SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_H
#define SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_H

#include "System/SystemDll.h"

#include "Fwd/NetworkFlagsFwd.h"
#include "Using/WindowsExtensionPrototypesUsing.h"

namespace System
{
    NODISCARD WinSockStartUpReturn SYSTEM_DEFAULT_DECLARE WinSockStartUp(WindowsWord versionRequired, WinSockDataPtr wSAData) noexcept;
    NODISCARD WinSockCleanupReturn SYSTEM_DEFAULT_DECLARE WinSockCleanup() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetWinSockLastError(WinSockLastError error) noexcept;
    NODISCARD WinSockLastError SYSTEM_DEFAULT_DECLARE GetWinSockLastError() noexcept;
}

#endif  // SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_H
