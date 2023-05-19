///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/10 09:43)

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
