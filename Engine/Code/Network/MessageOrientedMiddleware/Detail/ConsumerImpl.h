///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/15 17:35)

#ifndef NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_CONSUMER_IMPL_H
#define NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_CONSUMER_IMPL_H

#include "Network/NetworkDll.h"

#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/MessageOrientedMiddleware/MessageOrientedMiddlewareInternalFwd.h"
#include "Network/NetworkMessage/MessageEventManager.h"

#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ConsumerImpl
    {
    public:
        using ClassType = ConsumerImpl;
        using FactoryType = ConsumerFactory;

        using ConsumerSharedPtr = std::shared_ptr<ClassType>;

    public:
        explicit ConsumerImpl(ConfigurationStrategy configurationStrategy);
        virtual ~ConsumerImpl() noexcept = 0;
        ConsumerImpl(const ConsumerImpl& rhs) noexcept = delete;
        ConsumerImpl& operator=(const ConsumerImpl& rhs) noexcept = delete;
        ConsumerImpl(ConsumerImpl&& rhs) noexcept;
        ConsumerImpl& operator=(ConsumerImpl&& rhs) noexcept;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD ConfigurationStrategy GetConfigurationStrategy() const noexcept;
        NODISCARD MessageEventManager& GetMessageEventManager() noexcept;

        void Insert(int64_t messageId, const NetworkMessageEventSharedPtr& messageEvent);

    private:
        using EventInterfaceWeakPtr = std::weak_ptr<CoreTools::EventInterface>;

    private:
        ConfigurationStrategy configurationStrategy;
        MessageEventManager messageEventManager;
    };
}

#endif  // NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_CONSUMER_IMPL_H
