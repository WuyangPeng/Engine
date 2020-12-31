//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 20:08)

#ifndef NETWORK_NETWORK_INTERFACE_NULL_SOCK_CONNECTOR_H
#define NETWORK_NETWORK_INTERFACE_NULL_SOCK_CONNECTOR_H

#include "Network/NetworkDll.h"

#include "SockConnectorImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NullSockConnector final : public SockConnectorImpl
    {
    public:
        using ClassType = NullSockConnector;
        using ParentType = SockConnectorImpl;

    public:
        NullSockConnector() noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        [[nodiscard]] bool Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) noexcept final;
        void AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) final;

        [[nodiscard]] const SockConnectorPtr Clone() const final;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_SOCK_CONNECTOR_H
