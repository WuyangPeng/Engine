//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 20:16)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_CONNECTOR_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_SOCK_CONNECTOR_FACTORY_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE SockConnectorFactory final
    {
    public:
        using ClassType = SockConnectorFactory;
        using ImplType = SockConnectorImpl;
        using ImplTypePtr = std::shared_ptr<ImplType>;

    public:
        SockConnectorFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] static const ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy);
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_CONNECTOR_FACTORY_H
