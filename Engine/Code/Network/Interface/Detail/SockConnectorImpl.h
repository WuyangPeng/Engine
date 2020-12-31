//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 20:18)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_CONNECTOR_IMPL_H
#define NETWORK_NETWORK_INTERFACE_SOCK_CONNECTOR_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE SockConnectorImpl
    {
    public:
        using ClassType = SockConnectorImpl;
        using SockConnectorPtr = std::shared_ptr<ClassType>;

    public:
        SockConnectorImpl() noexcept = default;
        virtual ~SockConnectorImpl() noexcept = default;
        SockConnectorImpl(const SockConnectorImpl& rhs) = default;
        SockConnectorImpl& operator=(const SockConnectorImpl& rhs) = default;
        SockConnectorImpl(SockConnectorImpl&& rhs) noexcept = default;
        SockConnectorImpl& operator=(SockConnectorImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] virtual bool Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) = 0;
        [[nodiscard]] virtual void AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) = 0;

        [[nodiscard]] virtual const SockConnectorPtr Clone() const = 0;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_CONNECTOR_IMPL_H
