// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 16:29)

#include "Network/NetworkExport.h"

#include "PriorityMessageEventContainer.h"

#include "System/Helper/EnumCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"  
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"

#include <algorithm>
#include <functional> 
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26446)
using std::bind;
using std::make_shared;
using std::placeholders::_1;

Network::PriorityMessageEventContainer
	::PriorityMessageEventContainer()
	:ParentType{}, m_MultiMessageEventContainer(System::EnumCastUnderlying(MessageEventPriority::Count))
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, PriorityMessageEventContainer)

void Network::PriorityMessageEventContainer
	::Insert(const NetworkMessageEventSharedPtr& messageEvent)
{
	NETWORK_CLASS_IS_VALID_9;

	m_MultiMessageEventContainer[System::EnumCastUnderlying(MessageEventPriority::Middle)].Insert(messageEvent);
}

void Network::PriorityMessageEventContainer
	::Remove(const NetworkMessageEventSharedPtr& messageEvent)
{
	NETWORK_CLASS_IS_VALID_9;

	for_each(m_MultiMessageEventContainer.begin(), m_MultiMessageEventContainer.end(),
			 bind(&MultiMessageEventContainerImpl::Remove, _1, messageEvent));
}

void Network::PriorityMessageEventContainer
	::OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message)
{
	NETWORK_CLASS_IS_VALID_9;

	for_each(m_MultiMessageEventContainer.begin(), m_MultiMessageEventContainer.end(),
			 bind(&MultiMessageEventContainerImpl::OnEvent, _1, socketID, message));
}

void Network::PriorityMessageEventContainer
	::Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
	NETWORK_CLASS_IS_VALID_9;

	m_MultiMessageEventContainer[System::EnumCastUnderlying(priority)].Insert(messageEvent);
}

Network::PriorityMessageEventContainer::ImplPtr Network::PriorityMessageEventContainer
	::Clone() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return make_shared<ClassType>(*this);
}

Network::PriorityMessageEventContainer::ImplPtr Network::PriorityMessageEventContainer
	::CloneToMultiMessage() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return Clone();
}

Network::PriorityMessageEventContainer::ImplPtr Network::PriorityMessageEventContainer
	::CloneToPriorityMessage() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return Clone();
}

bool Network::PriorityMessageEventContainer
	::IsCanInsert() const noexcept
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return true;
}

bool Network::PriorityMessageEventContainer ::IsPrioritySame([[maybe_unused]] MessageEventPriority priority) const noexcept
{
	NETWORK_CLASS_IS_VALID_CONST_9;

 

	return true;
}

#include STSTEM_WARNING_POP
