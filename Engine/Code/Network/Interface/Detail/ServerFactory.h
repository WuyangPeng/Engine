///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/09 11:32)

#ifndef NETWORK_NETWORK_INTERFACE_SERVER_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_SERVER_FACTORY_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkMessage/MessageEventManager.h"

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

        NODISCARD static ImplTypeSharedPtr Create(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& messageEventManager);
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SERVER_FACTORY_H
