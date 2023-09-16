///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 17:35)

#ifndef NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_NULL_PRODUCER_H
#define NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_NULL_PRODUCER_H

#include "Network/NetworkDll.h"

#include "ProducerImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NullProducer final : public ProducerImpl
    {
    public:
        using ClassType = NullProducer;

        using ParentType = ProducerImpl;

    public:
        explicit NullProducer(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void SendServerMessage(const String& address, const MessageInterfaceSharedPtr& message) noexcept override;
    };
}

#endif  // NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_NULL_PRODUCER_H
