//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 20:37)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_CONTAINER_IMPL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_CONTAINER_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE MessageEventContainerImpl
    {
    public:
        using ClassType = MessageEventContainerImpl;
        using ImplPtr = std::shared_ptr<ClassType>;

    public:
        MessageEventContainerImpl() noexcept;
        virtual ~MessageEventContainerImpl() noexcept = default;
        MessageEventContainerImpl(const MessageEventContainerImpl&) = default;
        virtual MessageEventContainerImpl& operator=(const MessageEventContainerImpl&) = default;
        MessageEventContainerImpl(MessageEventContainerImpl&&) noexcept = default;
        virtual MessageEventContainerImpl& operator=(MessageEventContainerImpl&&) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void Insert(const NetworkMessageEventSharedPtr& messageEvent) = 0;
        virtual void Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority) = 0;
        virtual void Remove(const NetworkMessageEventSharedPtr& messageEvent) = 0;

        virtual void OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message) = 0;

        [[nodiscard]] virtual ImplPtr Clone() const = 0;
        [[nodiscard]] virtual ImplPtr CloneToMultiMessage() const = 0;
        [[nodiscard]] virtual ImplPtr CloneToPriorityMessage() const = 0;

        [[nodiscard]] virtual bool IsCanInsert() const = 0;
        [[nodiscard]] virtual bool IsPrioritySame(MessageEventPriority priority) const = 0;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_IMPL_H
