///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/11 17:04)

#ifndef NETWORK_SERVICE_WRAPPERS_SERVICE_CONSUMER_FACTORY_H
#define NETWORK_SERVICE_WRAPPERS_SERVICE_CONSUMER_FACTORY_H

#include "Network/NetworkDll.h"

#include "Network/Configuration/ConfigurationFwd.h"
#include "Network/ServiceWrappers/ServiceWrappersInternalFwd.h"

#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ServiceConsumerFactory
    {
    public:
        using ClassType = ServiceConsumerFactory;

        using ConsumerSharedPtr = std::shared_ptr<ServiceConsumerImpl>;

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD static ConsumerSharedPtr Create(const ConfigurationStrategy& configurationStrategy);

    private:
        NODISCARD static ConsumerSharedPtr CreateClient(const ConfigurationStrategy& configurationStrategy);
        NODISCARD static ConsumerSharedPtr CreateServer(const ConfigurationStrategy& configurationStrategy);

        NODISCARD static ConsumerSharedPtr CreateAceClient(const ConfigurationStrategy& configurationStrategy);
        NODISCARD static ConsumerSharedPtr CreateAceServer(const ConfigurationStrategy& configurationStrategy);

        NODISCARD static ConsumerSharedPtr CreateBoostClient(const ConfigurationStrategy& configurationStrategy);
        NODISCARD static ConsumerSharedPtr CreateBoostServer(const ConfigurationStrategy& configurationStrategy);
    };
}

#endif  // NETWORK_SERVICE_WRAPPERS_SERVICE_CONSUMER_FACTORY_H
