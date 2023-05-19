///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 10:46)

#ifndef NETWORK_NETWORK_INTERFACE_CLIENT_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_CLIENT_FACTORY_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkMessage/MessageEventManager.h"

#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ClientFactory final
    {
    public:
        using ClassType = ClientFactory;
        using ImplType = ClientImpl;
        using ImplTypeSharedPtr = std::shared_ptr<ImplType>;

    public:
        ClientFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static ImplTypeSharedPtr Create(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& socketManager);
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_CLIENT_FACTORY_H
