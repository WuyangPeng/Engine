///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/20 14:31)

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

        NODISCARD bool Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) noexcept final;
        void AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) final;

        NODISCARD SockConnectorSharedPtr Clone() const final;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_SOCK_CONNECTOR_H
