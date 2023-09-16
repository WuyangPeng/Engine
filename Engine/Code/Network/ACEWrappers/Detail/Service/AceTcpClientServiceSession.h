///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/15 15:38)

#ifndef NETWORK_ACE_WRAPPERS_ACE_TCP_CLIENT_SERVICE_SESSION_H
#define NETWORK_ACE_WRAPPERS_ACE_TCP_CLIENT_SERVICE_SESSION_H

#include "Network/NetworkDll.h"

#include "Network/ServiceWrappers/Detail/ClientServiceSession.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE AceTcpClientServiceSession final : public ClientServiceSession
    {
    public:
        using ClassType = AceTcpClientServiceSession;
        using ParentType = ClientServiceSession;

    public:
        explicit AceTcpClientServiceSession(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // NETWORK_ACE_WRAPPERS_ACE_TCP_CLIENT_SERVICE_SESSION_H