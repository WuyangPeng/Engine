///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:34)

#include "Network/NetworkExport.h"

#include "MultiMessageEventContainerImpl.h"
#include "PriorityMessageEventContainer.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::MultiMessageEventContainerImpl::MultiMessageEventContainerImpl() noexcept
    : messageEventContainer{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MultiMessageEventContainerImpl::MultiMessageEventContainerImpl(const NetworkMessageEventSharedPtr& messageEvent)
    : messageEventContainer{ messageEvent }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MultiMessageEventContainerImpl)

void Network::MultiMessageEventContainerImpl::Insert(const NetworkMessageEventSharedPtr& messageEvent)
{
    NETWORK_CLASS_IS_VALID_9;

    messageEventContainer.insert(messageEvent);
}

void Network::MultiMessageEventContainerImpl::Remove(const NetworkMessageEventSharedPtr& messageEvent) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    messageEventContainer.erase(messageEvent);
}

void Network::MultiMessageEventContainerImpl::OnEvent(uint64_t socketId, const ConstMessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    for (const auto& messageEventWeakPtr : messageEventContainer)
    {
        if (const auto messageEventSharedPtr = messageEventWeakPtr.lock();
            messageEventSharedPtr != nullptr)
        {
            messageEventSharedPtr->CallBackEvent(socketId, message);
        }
    }
}

Network::MultiMessageEventContainerImpl::ImplPtr Network::MultiMessageEventContainerImpl::CloneToPriorityMessage(MessageEventPriority priority) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    auto priorityMessageEventContainer = std::make_shared<PriorityMessageEventContainer>(CoreTools::DisableNotThrow::Disable);

    for (const auto& messageEventWeakPtr : messageEventContainer)
    {
        if (auto messageEventSharedPtr = messageEventWeakPtr.lock();
            messageEventSharedPtr != nullptr)
        {
            priorityMessageEventContainer->Insert(messageEventSharedPtr, priority);
        }
    }

    return priorityMessageEventContainer;
}
