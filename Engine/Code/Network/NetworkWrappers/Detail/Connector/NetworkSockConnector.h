///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/09 14:49)

#ifndef NETWORK_BOOST_WRAPPERS_NETWORK_SOCK_CONNECTOR_H
#define NETWORK_BOOST_WRAPPERS_NETWORK_SOCK_CONNECTOR_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockConnectorImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NetworkSockConnector : public SockConnectorImpl
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
