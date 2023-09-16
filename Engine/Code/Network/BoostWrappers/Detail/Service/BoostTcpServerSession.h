///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/15 17:15)

#ifndef NETWORK_BOOST_WRAPPERS_ACE_TCP_SERVER_SESSION_H
#define NETWORK_BOOST_WRAPPERS_ACE_TCP_SERVER_SESSION_H

#include "Network/NetworkDll.h"

#include "Network/ServiceWrappers/Detail/ServerSession.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostTcpServerSession final : public ServerSession
    {
    public:
        using ClassType = BoostTcpServerSession;
        using ParentType = ServerSession;

    public:
        explicit BoostTcpServerSession(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_ACE_TCP_SERVER_SESSION_H
