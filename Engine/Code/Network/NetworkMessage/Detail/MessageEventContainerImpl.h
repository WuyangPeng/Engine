///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:21)

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
        using FactoryType = MessageEventContainerImpl;

    public:
        MessageEventContainerImpl() noexcept;
        virtual ~MessageEventContainerImpl() noexcept = default;
        MessageEventContainerImpl(const MessageEventContainerImpl& rhs) = default;
        MessageEventContainerImpl& operator=(const MessageEventContainerImpl& rhs) = default;
        MessageEventContainerImpl(MessageEventContainerImpl&& rhs) noexcept = default;
        MessageEventContainerImpl& operator=(MessageEventContainerImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void Insert(const NetworkMessageEventSharedPtr& messageEvent) = 0;
        virtual void Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority) = 0;
        virtual void Remove(const NetworkMessageEventSharedPtr& messageEvent) = 0;

        virtual void OnEvent(uint64_t socketId, const ConstMessageInterfaceSharedPtr& message) = 0;

        NODISCARD virtual ImplPtr Clone() const = 0;
        NODISCARD virtual ImplPtr CloneToMultiMessage() const = 0;
        NODISCARD virtual ImplPtr CloneToPriorityMessage() const = 0;

        NODISCARD virtual bool IsCanInsert() const = 0;
        NODISCARD virtual bool IsPrioritySame(MessageEventPriority priority) const = 0;

        NODISCARD static ImplPtr Create();
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_IMPL_H
