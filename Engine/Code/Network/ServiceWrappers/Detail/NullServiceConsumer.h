///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/11 17:03)

#ifndef NETWORK_SERVICE_WRAPPERS_SERVICE_NULL_SERVICE_CONSUMER_H
#define NETWORK_SERVICE_WRAPPERS_SERVICE_NULL_SERVICE_CONSUMER_H

#include "Network/NetworkDll.h"

#include "ServiceConsumerImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NullServiceConsumer final : public ServiceConsumerImpl
    {
    public:
        using ClassType = NullServiceConsumer;
        using ParentType = ServiceConsumerImpl;

    public:
        explicit NullServiceConsumer(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // NETWORK_SERVICE_WRAPPERS_SERVICE_NULL_SERVICE_CONSUMER_H
