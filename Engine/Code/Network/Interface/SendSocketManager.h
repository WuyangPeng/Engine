//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 20:23)

#ifndef NETWORK_NETWORK_INTERFACE_SEND_SOCKET_MANAGER_H
#define NETWORK_NETWORK_INTERFACE_SEND_SOCKET_MANAGER_H

#include "Network/NetworkDll.h"

#include "SendSocket.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/InterfaceFwd.h"
#include "Network/NetworkMessage/MessageInterface.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <boost/noncopyable.hpp>
#include <map>

 
NETWORK_NON_COPY_EXPORT_IMPL(SendSocketManagerImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE SendSocketManager 
    {
    public:
        NON_COPY_TYPE_DECLARE(SendSocketManager);

    public:
        explicit SendSocketManager(const std::string& fileName);
        ~SendSocketManager() noexcept = default;
        SendSocketManager(const SendSocketManager& rhs) noexcept = delete;
        SendSocketManager& operator=(const SendSocketManager& rhs) noexcept = delete;
        SendSocketManager(SendSocketManager&& rhs) noexcept = delete;
        SendSocketManager& operator=(SendSocketManager&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        // ����������Ϣ
        void Send(const SocketData& socketData, uint64_t socketID, const MessageInterfaceSharedPtr& message);

        [[nodiscard]] SendSocketSharedPtr GetSendSocket(const SocketData& socketData);
        [[nodiscard]] SocketManagerSharedPtr GetSocketManager() noexcept;

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SEND_SOCKET_MANAGER_H
