///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/10 14:49)

#ifndef NETWORK_MESSAGE_ACTIVE_MQ_ACTIVE_MQ_CONSUMER_SESSION_H
#define NETWORK_MESSAGE_ACTIVE_MQ_ACTIVE_MQ_CONSUMER_SESSION_H

#include "Network/NetworkDll.h"

#include "System/Helper/PragmaWarning/ActiveMQ.h"
#include "Network/ActiveMQ/ActiveMQInternalFwd.h"
#include "Network/Configuration/ConfigurationStrategy.h"

#ifdef NETWORK_USE_ACTIVE_MQ

namespace Network
{

    class NETWORK_HIDDEN_DECLARE ActiveMQConsumerSession final
    {
    public:
        using ClassType = ActiveMQConsumerSession;
        using ConnectionSharedPtr = std::shared_ptr<cms::Connection>;
        using ConnectionWeakPtr = std::weak_ptr<cms::Connection>;
        using BytesMessage = cms::BytesMessage;
        using BytesMessageUniquePtr = std::unique_ptr<BytesMessage>;

    public:
        ActiveMQConsumerSession(ActiveMQService& activeMQService, std::string address);
        ~ActiveMQConsumerSession() noexcept;
        ActiveMQConsumerSession(const ActiveMQConsumerSession& rhs) = delete;
        ActiveMQConsumerSession& operator=(const ActiveMQConsumerSession& rhs) = delete;
        ActiveMQConsumerSession(ActiveMQConsumerSession&& rhs) noexcept = delete;
        ActiveMQConsumerSession& operator=(ActiveMQConsumerSession&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void Create();

        void SetMessageListener(cms::MessageListener* messageListener);

    private:
        using SessionUniquePtr = std::unique_ptr<cms::Session>;
        using DestinationUniquePtr = std::unique_ptr<cms::Destination>;
        using MessageConsumerUniquePtr = std::unique_ptr<cms::MessageConsumer>;

    private:
        void Close();

    private:
        ConfigurationStrategy configurationStrategy;
        std::string address;
        ConnectionWeakPtr connection;
        SessionUniquePtr session;
        DestinationUniquePtr destination;
        MessageConsumerUniquePtr consumer;
    };
}

#endif  // NETWORK_USE_ACTIVE_MQ

#endif  // NETWORK_MESSAGE_ACTIVE_MQ_ACTIVE_MQ_CONSUMER_SESSION_H
