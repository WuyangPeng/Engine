///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/11 17:04)

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
