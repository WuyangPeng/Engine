///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.0 (2023/01/06 23:50)

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