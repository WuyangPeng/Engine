//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 14:33)

#ifndef NETWORK_ACE_WRAPPERS_ACE_SOCK_CONNECTOR_H
#define NETWORK_ACE_WRAPPERS_ACE_SOCK_CONNECTOR_H

#include "Network/NetworkDll.h"

#ifdef NETWORK_USE_ACE

    #include "System/Helper/PragmaWarning/ACE.h"
    #include "Network/Interface/Detail/SockConnectorImpl.h"

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

        [[nodiscard]] bool Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;
        void AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

        [[nodiscard]] const SockConnectorPtr Clone() const override;

    private:
        ACE_SOCK_Connector m_ACESockConnector;
    };
}

#endif  // NETWORK_USE_ACE

#endif  // NETWORK_ACE_WRAPPERS_ACE_SOCK_CONNECTOR_H
