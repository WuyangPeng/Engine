//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 18:03)

#ifndef SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_H
#define SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_H

#include "System/SystemDll.h"

#include "Fwd/NetworkFlagsFwd.h"
#include "Using/WindowsExtensionPrototypesUsing.h"

namespace System
{
    [[nodiscard]] WinSockStartUpReturn SYSTEM_DEFAULT_DECLARE WinSockStartUp(WindowWord versionRequired, WinSockDataPtr wSAData) noexcept;
    [[nodiscard]] WinSockCleanupReturn SYSTEM_DEFAULT_DECLARE WinSockCleanup() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetWinSockLastError(WinSockLastError error) noexcept;
    [[nodiscard]] WinSockLastError SYSTEM_DEFAULT_DECLARE GetWinSockLastError() noexcept;
}

#endif  // SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_H
