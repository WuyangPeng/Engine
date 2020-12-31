//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 13:50)

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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Network::PriorityMessageEventContainer::PriorityMessageEventContainer()
    : ParentType{}, m_MultiMessageEventContainer(System::EnumCastUnderlying(MessageEventPriority::Count))
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}
#include STSTEM_WARNING_POP

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, PriorityMessageEventContainer)

void Network::PriorityMessageEventContainer::Insert(const NetworkMessageEventSharedPtr& messageEvent)
{
    NETWORK_CLASS_IS_VALID_9;

    m_MultiMessageEventContainer.at(System::EnumCastUnderlying(MessageEventPriority::Middle)).Insert(messageEvent);
}

void Network::PriorityMessageEventContainer::Remove(const NetworkMessageEventSharedPtr& messageEvent)
{
    NETWORK_CLASS_IS_VALID_9;

    for_each(m_MultiMessageEventContainer.begin(), m_MultiMessageEventContainer.end(),
             bind(&MultiMessageEventContainerImpl::Remove, _1, messageEvent));
}

void Network::PriorityMessageEventContainer::OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    for_each(m_MultiMessageEventContainer.begin(), m_MultiMessageEventContainer.end(),
             bind(&MultiMessageEventContainerImpl::OnEvent, _1, socketID, message));
}

void Network::PriorityMessageEventContainer::Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
    NETWORK_CLASS_IS_VALID_9;

    m_MultiMessageEventContainer.at(System::EnumCastUnderlying(priority)).Insert(messageEvent);
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

bool Network::PriorityMessageEventContainer::IsPrioritySame([[maybe_unused]] MessageEventPriority priority) const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return true;
}
