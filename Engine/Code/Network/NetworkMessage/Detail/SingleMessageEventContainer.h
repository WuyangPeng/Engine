//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 20:44)

#ifndef NETWORK_NETWORK_MESSAGE_SINGLE_MESSAGE_EVENT_CONTAINER_H
#define NETWORK_NETWORK_MESSAGE_SINGLE_MESSAGE_EVENT_CONTAINER_H

#include "Network/NetworkDll.h"

#include "MessageEventContainerImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE SingleMessageEventContainer final : public MessageEventContainerImpl
    {
    public:
        using ClassType = SingleMessageEventContainer;
        using ParentType = MessageEventContainerImpl;

    public:
        SingleMessageEventContainer() noexcept; 

        CLASS_INVARIANT_FINAL_DECLARE;

        void Insert(const NetworkMessageEventSharedPtr& messageEvent) final;
        void Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority) final;
        void Remove(const NetworkMessageEventSharedPtr& messageEvent) final;

        void OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message) final;

        [[nodiscard]] ImplPtr Clone() const final;
        [[nodiscard]] ImplPtr CloneToMultiMessage() const final;
        [[nodiscard]] ImplPtr CloneToPriorityMessage() const final;

        [[nodiscard]] bool IsCanInsert() const noexcept final;
        [[nodiscard]] bool IsPrioritySame(MessageEventPriority priority) const noexcept final;

    private:
        NetworkMessageEventWeakPtr m_MessageEvent;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_SINGLE_MESSAGE_EVENT_CONTAINER_H
