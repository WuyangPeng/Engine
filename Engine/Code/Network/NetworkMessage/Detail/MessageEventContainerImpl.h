// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:23)

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
        virtual ~MessageEventContainerImpl();
        MessageEventContainerImpl(const MessageEventContainerImpl&) = default;
        MessageEventContainerImpl& operator=(const MessageEventContainerImpl&) = default;
        MessageEventContainerImpl(MessageEventContainerImpl&&) noexcept = default;
        MessageEventContainerImpl& operator=(MessageEventContainerImpl&&) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void Insert(const NetworkMessageEventSharedPtr& messageEvent) = 0;
        virtual void Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority) = 0;
        virtual void Remove(const NetworkMessageEventSharedPtr& messageEvent) = 0;

        virtual void OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message) = 0;

        virtual ImplPtr Clone() const = 0;
        virtual ImplPtr CloneToMultiMessage() const = 0;
        virtual ImplPtr CloneToPriorityMessage() const = 0;

        virtual bool IsCanInsert() const = 0;
        virtual bool IsPrioritySame(MessageEventPriority priority) const = 0;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_IMPL_H
