/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 14:57)

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

    public:
        NetworkManagerImpl() noexcept;
        ~NetworkManagerImpl() noexcept = default;
        NetworkManagerImpl(const NetworkManagerImpl& rhs) noexcept = delete;
        NetworkManagerImpl& operator=(const NetworkManagerImpl& rhs) noexcept = delete;
        NetworkManagerImpl(NetworkManagerImpl&& rhs) noexcept;
        NetworkManagerImpl& operator=(NetworkManagerImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        void ResetSendSocketManager(const std::string& fileName) noexcept;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_NETWORK_MANAGER_INTERFACE_IMPL_H
