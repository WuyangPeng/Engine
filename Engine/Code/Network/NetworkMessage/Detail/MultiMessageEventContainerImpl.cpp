// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.4 (2020/03/10 16:28)

#include "Network/NetworkExport.h"

#include "MultiMessageEventContainerImpl.h"
#include "PriorityMessageEventContainer.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"  

using std::make_shared;

Network::MultiMessageEventContainerImpl
	::MultiMessageEventContainerImpl()
	:m_MessageEventContainer{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MultiMessageEventContainerImpl
	::MultiMessageEventContainerImpl(const NetworkMessageEventSharedPtr& messageEvent)
	:m_MessageEventContainer{ messageEvent }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MultiMessageEventContainerImpl)

void Network::MultiMessageEventContainerImpl
	::Insert(const NetworkMessageEventSharedPtr& messageEvent)
{
	NETWORK_CLASS_IS_VALID_9;

	m_MessageEventContainer.insert(messageEvent);
}

void Network::MultiMessageEventContainerImpl
	::Remove(const NetworkMessageEventSharedPtr& messageEvent)
{
	NETWORK_CLASS_IS_VALID_9;

	m_MessageEventContainer.erase(messageEvent);
}

void Network::MultiMessageEventContainerImpl
	::OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message)
{
	NETWORK_CLASS_IS_VALID_9;

	for (const auto& messageEventWeakPtr : m_MessageEventContainer)
	{
		auto messageEventSharedPtr = messageEventWeakPtr.lock();
		if (messageEventSharedPtr)
		{
			messageEventSharedPtr->CallBackEvent(socketID, message);
		}
	}
}

Network::MultiMessageEventContainerImpl::ImplPtr Network::MultiMessageEventContainerImpl
	::CloneToPriorityMessage(MessageEventPriority priority) const
{
	CLASS_IS_VALID_CONST_9;

	auto priorityMessageEventContainer = make_shared<PriorityMessageEventContainer>();

	for (const auto& messageEventWeakPtr : m_MessageEventContainer)
	{
		auto messageEventSharedPtr = messageEventWeakPtr.lock();
		if (messageEventSharedPtr)
		{
			priorityMessageEventContainer->Insert(messageEventSharedPtr, priority);
		}
	}

	return priorityMessageEventContainer;
}


