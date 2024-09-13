/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 17:22)

#ifndef NETWORK_BOOST_WRAPPERS_ACE_TCP_CLIENT_SERVICE_SESSION_H
#define NETWORK_BOOST_WRAPPERS_ACE_TCP_CLIENT_SERVICE_SESSION_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/ServiceWrappers/Detail/ClientServiceSession.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostTcpClientServiceSession final : public ClientServiceSession
    {
    public:
        using ClassType = BoostTcpClientServiceSession;
        using ParentType = ClientServiceSession;

    public:
        explicit BoostTcpClientServiceSession(const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void SendTextMessage(const std::string& message) override;

    private:
        void Connect();

    private:
        BoostSockStreamType socket;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_ACE_TCP_CLIENT_SERVICE_SESSION_H
