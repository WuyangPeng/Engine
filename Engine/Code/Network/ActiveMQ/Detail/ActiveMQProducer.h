///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 16:25)

#ifndef NETWORK_MESSAGE_ACTIVE_MQ_ACTIVE_MQ_PRODUCER_H
#define NETWORK_MESSAGE_ACTIVE_MQ_ACTIVE_MQ_PRODUCER_H

#include "Network/NetworkDll.h"

#include "ActiveMQProducerSession.h"
#include "ActiveMQService.h"
#include "Network/MessageOrientedMiddleware/Detail/ProducerImpl.h"
#include "Network/NetworkMessage/BufferSendStream.h"

#include <map>

#ifdef NETWORK_USE_ACTIVE_MQ

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ActiveMQProducer final : public ProducerImpl
    {
    public:
        using ClassType = ActiveMQProducer;
        using ParentType = ProducerImpl;

    public:
        explicit ActiveMQProducer(const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void SendServerMessage(const String& address, const MessageInterfaceSharedPtr& message) override;

    private:
        using ActiveMQSessionSharedPtr = std::shared_ptr<ActiveMQProducerSession>;
        using SessionContainer = std::map<String, ActiveMQSessionSharedPtr>;

    private:
        ActiveMQService activeMQService;
        SessionContainer sessionContainer;
        BufferSendStream bufferSendStream;
        MessageBufferSharedPtr sendBuffer;
    };
}

#endif  // NETWORK_USE_ACTIVE_MQ

#endif  // NETWORK_MESSAGE_ACTIVE_MQ_ACTIVE_MQ_PRODUCER_H
