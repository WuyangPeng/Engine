///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/10 09:43)

#ifndef NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_NULL_CONSUMER_H
#define NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_NULL_CONSUMER_H

#include "Network/NetworkDll.h"

#include "ConsumerImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NullConsumer final : public ConsumerImpl
    {
    public:
        using ClassType = NullConsumer;
        using ParentType = ConsumerImpl;

    public:
        explicit NullConsumer(const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_CONSUMER_NODE_H
