///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 15:52)

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
        using ImplTypeSharedPtr = std::shared_ptr<ImplType>;

    public:
        ServerFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static ImplTypeSharedPtr Create(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy);
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SERVER_FACTORY_H
