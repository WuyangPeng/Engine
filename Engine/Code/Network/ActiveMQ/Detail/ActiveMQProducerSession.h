/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:27)

#ifndef NETWORK_MESSAGE_ACTIVE_MQ_ACTIVE_MQ_SESSION_H
#define NETWORK_MESSAGE_ACTIVE_MQ_ACTIVE_MQ_SESSION_H

#include "Network/NetworkDll.h"

#include "System/Helper/PragmaWarning/ActiveMQ.h"
#include "Network/ActiveMQ/ActiveMQInternalFwd.h"
#include "Network/Configuration/ConfigurationStrategy.h"

#ifdef NETWORK_USE_ACTIVE_MQ

namespace Network
{

    class NETWORK_HIDDEN_DECLARE ActiveMQProducerSession final
    {
    public:
        using ClassType = ActiveMQProducerSession;

        using ConnectionSharedPtr = std::shared_ptr<cms::Connection>;
        using ConnectionWeakPtr = std::weak_ptr<cms::Connection>;
        using BytesMessage = cms::BytesMessage;
        using BytesMessageUniquePtr = std::unique_ptr<BytesMessage>;

    public:
        ActiveMQProducerSession(ActiveMQService& activeMQService, const std::string& address);
        ~ActiveMQProducerSession() noexcept;
        ActiveMQProducerSession(const ActiveMQProducerSession& rhs) = delete;
        ActiveMQProducerSession& operator=(const ActiveMQProducerSession& rhs) = delete;
        ActiveMQProducerSession(ActiveMQProducerSession&& rhs) noexcept = delete;
        ActiveMQProducerSession& operator=(ActiveMQProducerSession&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD BytesMessageUniquePtr CreateBytesMessage();
        void SendBytesMessage(BytesMessage& bytesMessage);

    private:
        using SessionUniquePtr = std::unique_ptr<cms::Session>;
        using DestinationUniquePtr = std::unique_ptr<cms::Destination>;
        using MessageProducerUniquePtr = std::unique_ptr<cms::MessageProducer>;

        void Create();

    private:
        ConfigurationStrategy configurationStrategy;
        std::string address;
        ConnectionWeakPtr connection;
        SessionUniquePtr session;
        DestinationUniquePtr destination;
        MessageProducerUniquePtr producer;
    };
}

#endif  // NETWORK_USE_ACTIVE_MQ

#endif  // NETWORK_MESSAGE_ACTIVE_MQ_ACTIVE_MQ_SESSION_H
