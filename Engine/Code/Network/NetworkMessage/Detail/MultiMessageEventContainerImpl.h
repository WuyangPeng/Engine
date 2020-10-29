//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/26 20:43)

#ifndef NETWORK_NETWORK_MESSAGE_MULTI_MESSAGE_EVENT_CONTAINER_IMPL_H
#define NETWORK_NETWORK_MESSAGE_MULTI_MESSAGE_EVENT_CONTAINER_IMPL_H

#include "Network/NetworkDll.h"

#include "NetworkMessageEventLess.h"
#include "Network/NetworkMessage/NetworkMessageEvent.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

#include <set>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE MultiMessageEventContainerImpl final
    {
    public:
        using ClassType = MultiMessageEventContainerImpl;
        using ImplPtr = std::shared_ptr<MessageEventContainerImpl>;

    public:
        MultiMessageEventContainerImpl() noexcept;
        explicit MultiMessageEventContainerImpl(const NetworkMessageEventSharedPtr& messageEvent);

        CLASS_INVARIANT_DECLARE;

        void Insert(const NetworkMessageEventSharedPtr& messageEvent);
        void Remove(const NetworkMessageEventSharedPtr& messageEvent) noexcept;

        void OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message);

        [[nodiscard]] ImplPtr CloneToPriorityMessage(MessageEventPriority priority) const;

    private:
        using PointerContainer = std::set<NetworkMessageEventWeakPtr, NetworkMessageEventLess>;

    private:
        PointerContainer m_MessageEventContainer;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTI_MESSAGE_EVENT_CONTAINER_H
