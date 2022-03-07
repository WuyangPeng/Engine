///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/20 16:23)

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
        using SockConnectorSharedPtr = std::shared_ptr<ClassType>;
        using FactoryType = SockConnectorFactory;

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
