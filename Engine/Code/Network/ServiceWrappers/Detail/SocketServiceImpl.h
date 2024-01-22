/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:02)

#ifndef NETWORK_SERVICE_WRAPPERS_SOCKET_SERVICE_IMPL_H
#define NETWORK_SERVICE_WRAPPERS_SOCKET_SERVICE_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/ServiceWrappers/ServiceConsumer.h"
#include "Network/ServiceWrappers/ServiceProducer.h"
#include "Network/ServiceWrappers/ServiceSession.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE SocketServiceImpl
    {
    public:
        using ClassType = SocketServiceImpl;

    public:
        explicit SocketServiceImpl(ConfigurationStrategy configurationStrategy);

        CLASS_INVARIANT_DECLARE;

    private:
        ServiceSession serviceSession;
        ServiceConsumer consumer;
        ServiceProducer producer;
        ConfigurationStrategy configurationStrategy;
    };
}

#endif  // NETWORK_SERVICE_WRAPPERS_SOCKET_SERVICE_IMPL_H
