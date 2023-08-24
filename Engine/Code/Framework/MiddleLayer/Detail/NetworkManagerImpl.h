///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 14:37)

#ifndef FRAMEWORK_MIDDLE_LAYER_NETWORK_MANAGER_INTERFACE_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_NETWORK_MANAGER_INTERFACE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Network/Interface/InterfaceFwd.h"
#include "Network/NetworkMessage/NetworkMessageFwd.h"

#include <string>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE NetworkManagerImpl
    {
    public:
        using ClassType = NetworkManagerImpl;

        using SocketType = Network::SocketType;
        using MessageEventPriority = Network::MessageEventPriority;
        using MessageInterfaceSharedPtr = Network::MessageInterfaceSharedPtr;
        using NetworkMessageEventSharedPtr = Network::NetworkMessageEventSharedPtr;
        using SendSocketManager = Network::SendSocketManager;
        using SendSocketManagerSharedPtr = Network::SendSocketManagerSharedPtr;
        using ConstSendSocketManagerSharedPtr = Network::ConstSendSocketManagerSharedPtr;

    public:
        NetworkManagerImpl() noexcept;
        ~NetworkManagerImpl() noexcept = default;
        NetworkManagerImpl(const NetworkManagerImpl& rhs) noexcept = delete;
        NetworkManagerImpl& operator=(const NetworkManagerImpl& rhs) noexcept = delete;
        NetworkManagerImpl(NetworkManagerImpl&& rhs) noexcept;
        NetworkManagerImpl& operator=(NetworkManagerImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        void ResetSendSocketManager(const std::string& fileName);

        NODISCARD SendSocketManagerSharedPtr GetSendSocketManager() noexcept;
        NODISCARD ConstSendSocketManagerSharedPtr GetSendSocketManager() const noexcept;

        void Send(const Network::SocketData& socketData, int64_t socketId, const MessageInterfaceSharedPtr& message);

    private:
        SendSocketManagerSharedPtr sendSocketManager;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_NETWORK_MANAGER_INTERFACE_IMPL_H
