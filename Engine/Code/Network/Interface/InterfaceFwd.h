/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:34)

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
    class SocketData;

    enum class StreamReceive;
    enum class SocketType;
}

#endif  // NETWORK_NETWORK_INTERFACE_FWD_H