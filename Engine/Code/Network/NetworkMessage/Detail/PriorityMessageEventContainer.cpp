///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/08 10:22)

#include "Network/NetworkExport.h"

#include "PriorityMessageEventContainer.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"

#include <algorithm>
#include <functional>

Network::PriorityMessageEventContainer::PriorityMessageEventContainer(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{}, multiMessageEventContainer(System::EnumCastUnderlying(MessageEventPriority::Count))
{
    System::UnusedFunction(disableNotThrow);

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, PriorityMessageEventContainer)

void Network::PriorityMessageEventContainer::Insert(const NetworkMessageEventSharedPtr& messageEvent)
{
    NETWORK_CLASS_IS_VALID_9;

    multiMessageEventContainer.at(System::EnumCastUnderlying(MessageEventPriority::Middle)).Insert(messageEvent);
}

void Network::PriorityMessageEventContainer::Remove(const NetworkMessageEventSharedPtr& messageEvent)
{
    NETWORK_CLASS_IS_VALID_9;

    std::ranges::for_each(multiMessageEventContainer,
                          [messageEvent](auto& value) noexcept {
                              value.Remove(messageEvent);
                          });
}

void Network::PriorityMessageEventContainer::OnEvent(uint64_t socketId, const ConstMessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    std::ranges::for_each(multiMessageEventContainer,
                          [socketId, message](auto& value) {
                              value.OnEvent(socketId, message);
                          });
}

void Network::PriorityMessageEventContainer::Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
    NETWORK_CLASS_IS_VALID_9;

    multiMessageEventContainer.at(System::EnumCastUnderlying(priority)).Insert(messageEvent);
}

Network::PriorityMessageEventContainer::ImplPtr Network::PriorityMessageEventContainer::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

Network::PriorityMessageEventContainer::ImplPtr Network::PriorityMessageEventContainer::CloneToMultiMessage() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return Clone();
}

Network::PriorityMessageEventContainer::ImplPtr Network::PriorityMessageEventContainer::CloneToPriorityMessage() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return Clone();
}

bool Network::PriorityMessageEventContainer::IsCanInsert() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return true;
}

bool Network::PriorityMessageEventContainer::IsPrioritySame(MessageEventPriority priority) const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(priority);

    return true;
}
