///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 15:38)

#ifndef NETWORK_ACE_WRAPPERS_ACE_TCP_SERVER_SERVICE_CONSUMER_H
#define NETWORK_ACE_WRAPPERS_ACE_TCP_SERVER_SERVICE_CONSUMER_H

#include "Network/NetworkDll.h"

#include "Network/ServiceWrappers/Detail/ServerServiceConsumer.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE AceTcpServerServiceConsumer final : public ServerServiceConsumer
    {
    public:
        using ClassType = AceTcpServerServiceConsumer;
        using ParentType = ServerServiceConsumer;

    public:
        explicit AceTcpServerServiceConsumer(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // NETWORK_ACE_WRAPPERS_ACE_TCP_SERVER_SERVICE_CONSUMER_H
