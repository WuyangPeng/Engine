/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:27)

#ifndef NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_PRODUCER_IMPL_H
#define NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_PRODUCER_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/MessageOrientedMiddleware/MessageOrientedMiddlewareInternalFwd.h"
#include "Network/NetworkMessage/MessageInterface.h"

#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ProducerImpl
    {
    public:
        using ClassType = ProducerImpl;
        using FactoryType = ProducerFactory;

        using ProducerSharedPtr = std::shared_ptr<ClassType>;
        using String = System::String;

    public:
        explicit ProducerImpl(ConfigurationStrategy configurationStrategy) noexcept;
        virtual ~ProducerImpl() noexcept = 0;
        ProducerImpl(const ProducerImpl& rhs) noexcept = delete;
        ProducerImpl& operator=(const ProducerImpl& rhs) noexcept = delete;
        ProducerImpl(ProducerImpl&& rhs) noexcept;
        ProducerImpl& operator=(ProducerImpl&& rhs) noexcept;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void SendServerMessage(const String& address, const MessageInterfaceSharedPtr& message) = 0;

    private:
        ConfigurationStrategy configurationStrategy;
    };
}

#endif  // NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_PRODUCER_IMPL_H
