///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:22)

#ifndef NETWORK_NETWORK_MESSAGE_MULTI_MESSAGE_EVENT_CONTAINER_IMPL_H
#define NETWORK_NETWORK_MESSAGE_MULTI_MESSAGE_EVENT_CONTAINER_IMPL_H

#include "Network/NetworkDll.h"

#include "NetworkMessageEventLess.h"
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

        void OnEvent(uint64_t socketId, const ConstMessageInterfaceSharedPtr& message);

        NODISCARD ImplPtr CloneToPriorityMessage(MessageEventPriority priority) const;

    private:
        using PointerContainer = std::set<NetworkMessageEventWeakPtr, NetworkMessageEventLess>;

    private:
        PointerContainer messageEventContainer;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTI_MESSAGE_EVENT_CONTAINER_H
