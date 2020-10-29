//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 20:12)

#ifndef NETWORK_NETWORK_INTERFACE_SERVER_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_SERVER_FACTORY_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkMessage/SocketManager.h"

#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ServerFactory final
    {
    public:
        using ClassType = ServerFactory;
        using ImplType = ServerImpl;
        using ImplTypePtr = std::shared_ptr<ImplType>;

    public:
        ServerFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] static const ImplTypePtr Create(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy);
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SERVER_FACTORY_H
