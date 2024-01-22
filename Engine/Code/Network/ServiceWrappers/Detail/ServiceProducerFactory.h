/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:03)

#ifndef NETWORK_SERVICE_WRAPPERS_SERVICE_PRODUCER_FACTORY_H
#define NETWORK_SERVICE_WRAPPERS_SERVICE_PRODUCER_FACTORY_H

#include "Network/NetworkDll.h"

#include "Network/Configuration/ConfigurationFwd.h"
#include "Network/ServiceWrappers/ServiceWrappersInternalFwd.h"

#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ServiceProducerFactory
    {
    public:
        using ClassType = ServiceProducerFactory;

        using ProducerSharedPtr = std::shared_ptr<ServiceProducerImpl>;

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD static ProducerSharedPtr Create(const ConfigurationStrategy& configurationStrategy);

    private:
        NODISCARD static ProducerSharedPtr CreateClient(const ConfigurationStrategy& configurationStrategy);
        NODISCARD static ProducerSharedPtr CreateServer(const ConfigurationStrategy& configurationStrategy);

        NODISCARD static ProducerSharedPtr CreateAceClient(const ConfigurationStrategy& configurationStrategy);
        NODISCARD static ProducerSharedPtr CreateAceServer(const ConfigurationStrategy& configurationStrategy);

        NODISCARD static ProducerSharedPtr CreateBoostClient(const ConfigurationStrategy& configurationStrategy);
        NODISCARD static ProducerSharedPtr CreateBoostServer(const ConfigurationStrategy& configurationStrategy);
    };

}

#endif  // NETWORK_SERVICE_WRAPPERS_SERVICE_PRODUCER_FACTORY_H
