///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/13 19:24)

#ifndef NETWORK_SERVICE_WRAPPERS_SERVICE_CLIENT_SERVICE_PRODUCER_H
#define NETWORK_SERVICE_WRAPPERS_SERVICE_CLIENT_SERVICE_PRODUCER_H

#include "Network/NetworkDll.h"

#include "ServiceProducerImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ClientServiceProducer : public ServiceProducerImpl
    {
    public:
        using ClassType = ClientServiceProducer;
        using ParentType = ServiceProducerImpl;

    public:
        explicit ClientServiceProducer(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // NETWORK_SERVICE_WRAPPERS_SERVICE_CLIENT_SERVICE_PRODUCER_H
