//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 14:46)

#ifndef NETWORK_NETWORK_INTERFACE_FWD_H
#define NETWORK_NETWORK_INTERFACE_FWD_H

#include "CoreTools/Helper/SharedPtrMacro.h"

#include <memory>

namespace Network
{
    class BaseMainManager;
    class SockAddress;
    class SockAcceptor;
    class SockConnector;
    class SockStream;
    class HandleSet;
    class HandleSetIterator;
    class SendSocket;
    class Client;
    class Server;
    class SendSocketManager;
    class SocketData;

    CORE_TOOLS_SHARED_PTR_DECLARE(SendSocketManager);

    enum class StreamReceive;
    enum class SocketType;
}

#endif  // NETWORK_NETWORK_INTERFACE_FWD_H