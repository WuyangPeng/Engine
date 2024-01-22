/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:05)

#ifndef NETWORK_SERVICE_WRAPPERS_SERVICE_CLIENT_SERVICE_CONSUMER_H
#define NETWORK_SERVICE_WRAPPERS_SERVICE_CLIENT_SERVICE_CONSUMER_H

#include "Network/NetworkDll.h"

#include "ServiceConsumerImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ClientServiceConsumer : public ServiceConsumerImpl
    {
    public:
        using ClassType = ClientServiceConsumer;
        using ParentType = ServiceConsumerImpl;

    public:
        explicit ClientServiceConsumer(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // NETWORK_SERVICE_WRAPPERS_SERVICE_CLIENT_SERVICE_CONSUMER_H
