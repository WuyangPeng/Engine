/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:02)

#ifndef NETWORK_SERVICE_WRAPPERS_SERVICE_PRODUCER_IMPL_H
#define NETWORK_SERVICE_WRAPPERS_SERVICE_PRODUCER_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/NetworkMessage/MessageInterface.h"
#include "Network/ServiceWrappers/ServiceWrappersInternalFwd.h"

#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ServiceProducerImpl
    {
    public:
        using ClassType = ServiceProducerImpl;
        using FactoryType = ServiceProducerFactory;

        using ProducerSharedPtr = std::shared_ptr<ClassType>;
        using String = System::String;

    public:
        explicit ServiceProducerImpl(ConfigurationStrategy configurationStrategy) noexcept;
        virtual ~ServiceProducerImpl() noexcept = 0;
        ServiceProducerImpl(const ServiceProducerImpl& rhs) noexcept = delete;
        ServiceProducerImpl& operator=(const ServiceProducerImpl& rhs) noexcept = delete;
        ServiceProducerImpl(ServiceProducerImpl&& rhs) noexcept;
        ServiceProducerImpl& operator=(ServiceProducerImpl&& rhs) noexcept;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void SendTextMessage(const std::string& message);

    private:
        ConfigurationStrategy configurationStrategy;
    };
}

#endif  // NETWORK_SERVICE_WRAPPERS_SERVICE_PRODUCER_IMPL_H
