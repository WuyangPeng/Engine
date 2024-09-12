/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 17:22)

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

        void SendTextMessage(ServiceSession& serviceSession, const std::string& message) override;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_TCP_SERVER_SERVICE_PRODUCER_H
