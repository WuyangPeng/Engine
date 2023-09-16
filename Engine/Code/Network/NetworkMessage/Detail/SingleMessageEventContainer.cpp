///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:35)

#include "Network/NetworkExport.h"

#include "MultiMessageEventContainer.h"
#include "PriorityMessageEventContainer.h"
#include "SingleMessageEventContainer.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::SingleMessageEventContainer::SingleMessageEventContainer() noexcept
    : ParentType{}, messageEvent{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, SingleMessageEventContainer)

void Network::SingleMessageEventContainer::Insert(const NetworkMessageEventSharedPtr& aMessageEvent)
{
    NETWORK_CLASS_IS_VALID_9;

    if (messageEvent.lock())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("消息事件已存在！"s))
    }

    messageEvent = aMessageEvent;
}

void Network::SingleMessageEventContainer::Remove(const NetworkMessageEventSharedPtr& aMessageEvent)
{
    NETWORK_CLASS_IS_VALID_9;

    if (messageEvent.lock() == aMessageEvent)
    {
        messageEvent.reset();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("消息事件不存在！"s))
    }
}

void Network::SingleMessageEventContainer::OnEvent(uint64_t socketId, const ConstMessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    if (const auto messageEventSharedPtr = messageEvent.lock();
        messageEventSharedPtr != nullptr)
    {
        messageEventSharedPtr->CallBackEvent(socketId, message);
    }
}

void Network::SingleMessageEventContainer::Insert(const NetworkMessageEventSharedPtr& aMessageEvent, MessageEventPriority priority)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(priority);

    if (messageEvent.lock())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("消息事件已存在！"s))
    }

    messageEvent = aMessageEvent;
}

Network::SingleMessageEventContainer::ImplPtr Network::SingleMessageEventContainer::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

Network::SingleMessageEventContainer::ImplPtr Network::SingleMessageEventContainer::CloneToMultiMessage() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    auto multiMessageEventContainer = std::make_shared<MultiMessageEventContainer>(CoreTools::DisableNotThrow::Disable);

    if (const auto messageEventSharedPtr = messageEvent.lock();
        messageEventSharedPtr != nullptr)
    {
        multiMessageEventContainer->Insert(messageEventSharedPtr);
    }

    return multiMessageEventContainer;
}

Network::SingleMessageEventContainer::ImplPtr Network::SingleMessageEventContainer::CloneToPriorityMessage() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    auto priorityMessageEventContainer = std::make_shared<PriorityMessageEventContainer>(CoreTools::DisableNotThrow::Disable);

    if (const auto messageEventSharedPtr = messageEvent.lock();
        messageEventSharedPtr != nullptr)
    {
        priorityMessageEventContainer->Insert(messageEventSharedPtr);
    }

    return priorityMessageEventContainer;
}

bool Network::SingleMessageEventContainer::IsCanInsert() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (!messageEvent.lock())
        return true;
    else
        return false;
}

bool Network::SingleMessageEventContainer::IsPrioritySame(MessageEventPriority priority) const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(priority);

    return false;
}
