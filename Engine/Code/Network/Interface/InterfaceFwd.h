///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/20 16:43)

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