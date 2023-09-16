///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 17:41)

#ifndef NETWORK_BOOST_WRAPPERS_NETWORK_SOCK_CONNECTOR_H
#define NETWORK_BOOST_WRAPPERS_NETWORK_SOCK_CONNECTOR_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockConnectorImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NetworkSockConnector final : public SockConnectorImpl
    {
    public:
        using ClassType = NetworkSockConnector;
        using ParentType = SockConnectorImpl;

    public:
        NetworkSockConnector() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;
        void AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

        NODISCARD SockConnectorSharedPtr Clone() const override;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_NETWORK_SOCK_CONNECTOR_H
