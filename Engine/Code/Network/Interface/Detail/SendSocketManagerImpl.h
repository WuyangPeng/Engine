//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 20:23)

#ifndef NETWORK_NETWORK_INTERFACE_SEND_SOCKET_MANAGER_IMPL_H
#define NETWORK_NETWORK_INTERFACE_SEND_SOCKET_MANAGER_IMPL_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/SendSocket.h"
#include "Network/Interface/SocketData.h"
#include "Network/NetworkMessage/MessageInterface.h"

#include <boost/noncopyable.hpp>
#include <map>



namespace Network
{
    class NETWORK_HIDDEN_DECLARE SendSocketManagerImpl final 
    {
    public:
        using ClassType = SendSocketManagerImpl;

    public:
        explicit SendSocketManagerImpl(const std::string& fileName);
        ~SendSocketManagerImpl() noexcept = default;
        SendSocketManagerImpl(const SendSocketManagerImpl& rhs) noexcept = delete;
        SendSocketManagerImpl& operator=(const SendSocketManagerImpl& rhs) noexcept = delete;
        SendSocketManagerImpl(SendSocketManagerImpl&& rhs) noexcept = delete;
        SendSocketManagerImpl& operator=(SendSocketManagerImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        // ����������Ϣ
        void Send(const SocketData& socketData, uint64_t socketID, const MessageInterfaceSharedPtr& message);

        [[nodiscard]] SendSocketSharedPtr GetSendSocket(const SocketData& socketData);
        [[nodiscard]] SocketManagerSharedPtr GetSocketManager() noexcept;

    private:
        std::map<SocketData, SendSocketSharedPtr> m_SendSocket;
        SocketManagerSharedPtr m_SocketManager;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SEND_SOCKET_MANAGER_IMPL_H
