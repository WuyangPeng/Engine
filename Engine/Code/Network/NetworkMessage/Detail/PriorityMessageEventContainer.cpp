///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 22:36)

#include "Network/NetworkExport.h"

#include "PriorityMessageEventContainer.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"

#include <algorithm>
#include <functional>

using std::bind;
using std::make_shared;
using std::placeholders::_1;

Network::PriorityMessageEventContainer::PriorityMessageEventContainer(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{}, multiMessageEventContainer(System::EnumCastUnderlying(MessageEventPriority::Count))
{
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

    for_each(multiMessageEventContainer.begin(),
             multiMessageEventContainer.end(),
             bind(&MultiMessageEventContainerImpl::Remove,
                  _1,
                  messageEvent));
}

void Network::PriorityMessageEventContainer::OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    for_each(multiMessageEventContainer.begin(),
             multiMessageEventContainer.end(),
             bind(&MultiMessageEventContainerImpl::OnEvent,
                  _1,
                  socketID,
                  message));
}

void Network::PriorityMessageEventContainer::Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
    NETWORK_CLASS_IS_VALID_9;

    multiMessageEventContainer.at(System::EnumCastUnderlying(priority)).Insert(messageEvent);
}

Network::PriorityMessageEventContainer::ImplPtr Network::PriorityMessageEventContainer::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return make_shared<ClassType>(*this);
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

bool Network::PriorityMessageEventContainer::IsPrioritySame(MAYBE_UNUSED MessageEventPriority priority) const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return true;
}
