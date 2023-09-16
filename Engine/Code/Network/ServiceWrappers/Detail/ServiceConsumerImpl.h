///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/11 16:53)

#ifndef NETWORK_SERVICE_WRAPPERS_SERVICE_CONSUMER_IMPL_H
#define NETWORK_SERVICE_WRAPPERS_SERVICE_CONSUMER_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/NetworkMessage/MessageInterface.h"
#include "Network/ServiceWrappers/ServiceWrappersInternalFwd.h"

#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ServiceConsumerImpl
    {
    public:
        using ClassType = ServiceConsumerImpl;
        using FactoryType = ServiceConsumerFactory;

        using ConsumerSharedPtr = std::shared_ptr<ClassType>;
        using String = System::String;

    public:
        explicit ServiceConsumerImpl(ConfigurationStrategy configurationStrategy) noexcept;
        virtual ~ServiceConsumerImpl() noexcept = 0;
        ServiceConsumerImpl(const ServiceConsumerImpl& rhs) noexcept = delete;
        ServiceConsumerImpl& operator=(const ServiceConsumerImpl& rhs) noexcept = delete;
        ServiceConsumerImpl(ServiceConsumerImpl&& rhs) noexcept;
        ServiceConsumerImpl& operator=(ServiceConsumerImpl&& rhs) noexcept;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    private:
        ConfigurationStrategy configurationStrategy;
    };
}

#endif  // NETWORK_SERVICE_WRAPPERS_SERVICE_CONSUMER_IMPL_H
