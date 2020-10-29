//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 19:50)

#ifndef NETWORK_NETWORK_INTERFACE_CLIENT_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_CLIENT_FACTORY_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkMessage/SocketManager.h"

#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ClientFactory final
    {
    public:
        using ClassType = ClientFactory;
        using ImplType = ClientImpl;
        using ImplTypePtr = std::shared_ptr<ImplType>;

    public:
        ClientFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] static const ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy, const SocketManagerSharedPtr& socketManager);
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_CLIENT_FACTORY_H
