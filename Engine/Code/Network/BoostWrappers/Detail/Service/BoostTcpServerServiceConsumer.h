/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:22)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_TCP_SERVER_SERVICE_CONSUMER_H
#define NETWORK_BOOST_WRAPPERS_BOOST_TCP_SERVER_SERVICE_CONSUMER_H

#include "Network/NetworkDll.h"

#include "Network/ServiceWrappers/Detail/ServerServiceConsumer.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostTcpServerServiceConsumer final : public ServerServiceConsumer
    {
    public:
        using ClassType = BoostTcpServerServiceConsumer;
        using ParentType = ServerServiceConsumer;

    public:
        explicit BoostTcpServerServiceConsumer(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_TCP_SERVER_SERVICE_CONSUMER_H
