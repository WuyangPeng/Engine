/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 17:22)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_TCP_CLIENT_SERVICE_CONSUMER_H
#define NETWORK_BOOST_WRAPPERS_BOOST_TCP_CLIENT_SERVICE_CONSUMER_H

#include "Network/NetworkDll.h"

#include "Network/ServiceWrappers/Detail/ClientServiceConsumer.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostTcpClientServiceConsumer final : public ClientServiceConsumer
    {
    public:
        using ClassType = BoostTcpClientServiceConsumer;
        using ParentType = ClientServiceConsumer;

    public:
        explicit BoostTcpClientServiceConsumer(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD std::string Response(ServiceSession& serviceSession) override;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_TCP_CLIENT_SERVICE_CONSUMER_H
