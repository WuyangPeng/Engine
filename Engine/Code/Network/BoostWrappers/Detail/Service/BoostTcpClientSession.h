/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:22)

#ifndef NETWORK_BOOST_WRAPPERS_ACE_TCP_CLIENT_SESSION_H
#define NETWORK_BOOST_WRAPPERS_ACE_TCP_CLIENT_SESSION_H

#include "Network/NetworkDll.h"

#include "Network/ServiceWrappers/Detail/ClientSession.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostTcpClientSession final : public ClientSession
    {
    public:
        using ClassType = BoostTcpClientSession;
        using ParentType = ClientSession;

    public:
        explicit BoostTcpClientSession(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_ACE_TCP_CLIENT_SESSION_H
