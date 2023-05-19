///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/09 14:02)

#ifndef NETWORK_ACE_WRAPPERS_ACE_SOCK_CONNECTOR_H
#define NETWORK_ACE_WRAPPERS_ACE_SOCK_CONNECTOR_H

#include "Network/NetworkDll.h"

#include "System/Helper/PragmaWarning/ACE.h"
#include "Network/Interface/Detail/SockConnectorImpl.h"

#ifdef NETWORK_USE_ACE

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ACESockConnector : public SockConnectorImpl
    {
    public:
        using ClassType = ACESockConnector;
        using ParentType = SockConnectorImpl;

    public:
        ACESockConnector() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;
        void AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

        NODISCARD SockConnectorSharedPtr Clone() const override;

    private:
        ACE_SOCK_Connector aceSockConnector;
    };
}

#endif  // NETWORK_USE_ACE

#endif  // NETWORK_ACE_WRAPPERS_ACE_SOCK_CONNECTOR_H
