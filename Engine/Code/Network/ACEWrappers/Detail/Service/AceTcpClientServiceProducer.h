///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/15 15:38)

#ifndef NETWORK_ACE_WRAPPERS_ACE_TCP_CLIENT_SERVICE_PRODUCER_H
#define NETWORK_ACE_WRAPPERS_ACE_TCP_CLIENT_SERVICE_PRODUCER_H

#include "Network/NetworkDll.h"

#include "Network/ServiceWrappers/Detail/ClientServiceProducer.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE AceTcpClientServiceProducer final : public ClientServiceProducer
    {
    public:
        using ClassType = AceTcpClientServiceProducer;
        using ParentType = ClientServiceProducer;

    public:
        explicit AceTcpClientServiceProducer(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // NETWORK_ACE_WRAPPERS_ACE_TCP_CLIENT_SERVICE_PRODUCER_H
