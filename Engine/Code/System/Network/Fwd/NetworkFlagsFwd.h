/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/03 21:04)

#ifndef SYSTEM_NETWORK_NETWORK_FLAGS_FWD_H
#define SYSTEM_NETWORK_NETWORK_FLAGS_FWD_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
    /// SocketPrototypes
    enum class AddressFamilies;
    enum class ProtocolFamilies;
    enum class SocketTypes;
    enum class SocketProtocols;
    enum class SocketReceive;
    enum class SocketSend;
    enum class SocketLevelOption;
    enum class SocketRetrievedOption;
    enum class ShutdownHow;
    enum class IoctlSocketCmd : uint32_t;

    /// WindowsExtensionPrototypes
    enum class WinSockStartUpReturn;
    enum class WinSockCleanupReturn;
    enum class WinSockLastError;
    enum class WinSockSelectEvent;
}

#endif  // SYSTEM_NETWORK_NETWORK_FLAGS_FWD_H