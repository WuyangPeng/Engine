///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:23)

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

        void Insert(const NetworkMessageEventSharedPtr& aMessageEvent) override;
        void Insert(const NetworkMessageEventSharedPtr& aMessageEvent, MessageEventPriority priority) override;
        void Remove(const NetworkMessageEventSharedPtr& aMessageEvent) override;

        void OnEvent(uint64_t socketId, const ConstMessageInterfaceSharedPtr& message) override;

        NODISCARD ImplPtr Clone() const override;
        NODISCARD ImplPtr CloneToMultiMessage() const override;
        NODISCARD ImplPtr CloneToPriorityMessage() const override;

        NODISCARD bool IsCanInsert() const noexcept override;
        NODISCARD bool IsPrioritySame(MessageEventPriority priority) const noexcept override;

    private:
        NetworkMessageEventWeakPtr messageEvent;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_SINGLE_MESSAGE_EVENT_CONTAINER_H
