/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 17:31)

#ifndef NETWORK_ACE_WRAPPERS_ACE_TCP_SERVER_SESSION_H
#define NETWORK_ACE_WRAPPERS_ACE_TCP_SERVER_SESSION_H

#include "Network/NetworkDll.h"

#include "Network/ServiceWrappers/Detail/ServerSession.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE AceTcpServerSession final : public ServerSession
    {
    public:
        using ClassType = AceTcpServerSession;
        using ParentType = ServerSession;

    public:
        explicit AceTcpServerSession(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // NETWORK_ACE_WRAPPERS_ACE_TCP_SERVER_SESSION_H
