///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/15 17:14)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_TCP_SERVER_SERVICE_PRODUCER_H
#define NETWORK_BOOST_WRAPPERS_BOOST_TCP_SERVER_SERVICE_PRODUCER_H

#include "Network/NetworkDll.h"

#include "Network/ServiceWrappers/Detail/ServerServiceProducer.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostTcpServerServiceProducer final : public ServerServiceProducer
    {
    public:
        using ClassType = BoostTcpServerServiceProducer;
        using ParentType = ServerServiceProducer;

    public:
        explicit BoostTcpServerServiceProducer(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_TCP_SERVER_SERVICE_PRODUCER_H
