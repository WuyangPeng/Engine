/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:58)

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

        NODISCARD bool Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) noexcept override;
        void AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

        NODISCARD SockConnectorSharedPtr Clone() const override;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_SOCK_CONNECTOR_H
