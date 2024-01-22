/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:51)

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
        using FactoryType = SockConnectorFactory;

        using SockConnectorSharedPtr = std::shared_ptr<ClassType>;

    public:
        SockConnectorImpl() noexcept = default;
        virtual ~SockConnectorImpl() noexcept = default;
        SockConnectorImpl(const SockConnectorImpl& rhs) = default;
        SockConnectorImpl& operator=(const SockConnectorImpl& rhs) = default;
        SockConnectorImpl(SockConnectorImpl&& rhs) noexcept = default;
        SockConnectorImpl& operator=(SockConnectorImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual bool Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) = 0;
        NODISCARD virtual void AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) = 0;

        NODISCARD virtual SockConnectorSharedPtr Clone() const = 0;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_CONNECTOR_IMPL_H
