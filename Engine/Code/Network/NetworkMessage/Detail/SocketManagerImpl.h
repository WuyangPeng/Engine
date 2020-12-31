//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/26 20:45)

#ifndef NETWORK_NETWORK_MESSAGE_SOCKET_MANAGER_IMPL_H
#define NETWORK_NETWORK_MESSAGE_SOCKET_MANAGER_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Interface/SendSocket.h"
#include "Network/NetworkMessage/MessageEventManager.h"

#include <map>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE SocketManagerImpl final
    {
    public:
        using ClassType = SocketManagerImpl;

    public:
        SocketManagerImpl();
        ~SocketManagerImpl() noexcept = default;

        SocketManagerImpl(const SocketManagerImpl& rhs);
        SocketManagerImpl& operator=(const SocketManagerImpl& rhs);
        SocketManagerImpl(SocketManagerImpl&& rhs) noexcept;
        SocketManagerImpl& operator=(SocketManagerImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

    public:
        void InsertSocket(uint64_t socketID);
        void RemoveSocket(uint64_t socketID);

        void InsertEvent(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);
        void InsertEvent(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority);
        void RemoveEvent(uint64_t socketID, int64_t messageID);
        void RemoveEvent(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);

        void OnEvent(uint64_t socketID, int64_t messageID, const ConstMessageInterfaceSharedPtr& message);

        [[nodiscard]] int GetSocketSize() const;

    private:
        using MessageEventManagerContainer = std::map<uint64_t, MessageEventManager>;
        using MutexUniquePtr = std::unique_ptr<CoreTools::Mutex>;

    private:
        MessageEventManagerContainer m_MessageEventManagerContainer;
        MutexUniquePtr m_Mutex;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_IMPL_H
