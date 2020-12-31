//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 17:59)

#ifndef SYSTEM_NETWORK_NETWORK_FLAGS_FWD_H
#define SYSTEM_NETWORK_NETWORK_FLAGS_FWD_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
    // SocketPrototypes
    enum class AddressFamilies;
    enum class ProtocolFamilies;
    enum class SocketTypes;
    enum class SocketProtocols;
    enum class SocketRecv;
    enum class SocketSend;
    enum class IoctlSocketCmd : uint32_t;
    enum class SocketLevelOption;
    enum class SocketRetrievedOption;
    enum class ShutdownHow;

    // WindowsExtensionPrototypes
    enum class WinSockStartUpReturn;
    enum class WinSockCleanupReturn;
    enum class WinSockLastError;
    enum class WinSockSelectEvent;

    // WindowsInternet
    enum class InternetOpenType;
    enum class InternetType : uint32_t;
    enum class QueryInfo;

    // WindowsSockEx
    enum class WaitForMultipleEventsReturn : uint32_t;
    enum class ProtocolInfoService;
    enum class ProtocolInfoProvider;
}

#endif  // SYSTEM_NETWORK_NETWORK_FLAGS_FWD_H