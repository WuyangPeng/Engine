/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 17:29)

#ifndef SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_H
#define SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_H

#include "System/SystemDll.h"

#include "Fwd/NetworkFlagsFwd.h"
#include "Using/WindowsExtensionPrototypesUsing.h"

namespace System
{
    NODISCARD WinSockStartUpReturn SYSTEM_DEFAULT_DECLARE WinSockStartUp(WindowsWord versionRequired, WinSockDataPtr wsaData) noexcept;
    NODISCARD WinSockCleanupReturn SYSTEM_DEFAULT_DECLARE WinSockCleanup() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetWinSockLastError(WinSockLastError error) noexcept;
    NODISCARD WinSockLastError SYSTEM_DEFAULT_DECLARE GetWinSockLastError() noexcept;
}

#endif  // SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_H
