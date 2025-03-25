/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:31)

#ifndef NETWORK_ACE_WRAPPERS_ACE_TCP_CLIENT_SERVICE_CONSUMER_H
#define NETWORK_ACE_WRAPPERS_ACE_TCP_CLIENT_SERVICE_CONSUMER_H

#include "Network/NetworkDll.h"

#include "Network/ServiceWrappers/Detail/ClientServiceConsumer.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE AceTcpClientServiceConsumer final : public ClientServiceConsumer
    {
    public:
        using ClassType = AceTcpClientServiceConsumer;
        using ParentType = ClientServiceConsumer;

    public:
        explicit AceTcpClientServiceConsumer(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // NETWORK_ACE_WRAPPERS_ACE_TCP_CLIENT_SERVICE_CONSUMER_H
