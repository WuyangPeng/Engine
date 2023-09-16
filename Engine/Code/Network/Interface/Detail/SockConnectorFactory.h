///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 11:38)

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

        using ImplTypeSharedPtr = std::shared_ptr<ImplType>;

    public:
        SockConnectorFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static ImplTypeSharedPtr Create(const ConfigurationStrategy& configurationStrategy);
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_CONNECTOR_FACTORY_H
