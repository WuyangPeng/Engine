// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/10 16:30)

#include "Network/NetworkExport.h"

#include "SingleMessageEventContainer.h"
#include "MultiMessageEventContainer.h"
#include "PriorityMessageEventContainer.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

using std::make_shared;

Network::SingleMessageEventContainer
	::SingleMessageEventContainer()
	:ParentType{}, m_MessageEvent{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::SingleMessageEventContainer
	::SingleMessageEventContainer(const SingleMessageEventContainer& rhs)
	:ParentType{}, m_MessageEvent{ rhs.m_MessageEvent }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::SingleMessageEventContainer
	::SingleMessageEventContainer(SingleMessageEventContainer&& rhs) noexcept
	:ParentType{}, m_MessageEvent{ move(rhs.m_MessageEvent) }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::SingleMessageEventContainer& Network::SingleMessageEventContainer
	::operator=(const SingleMessageEventContainer& rhs)
{
	NETWORK_CLASS_IS_VALID_9;

	ParentType::operator=(rhs);

	m_MessageEvent = rhs.m_MessageEvent;

	return *this;
}

Network::SingleMessageEventContainer& Network::SingleMessageEventContainer
	::operator=(SingleMessageEventContainer&& rhs) noexcept
{
	NETWORK_CLASS_IS_VALID_9;

	ParentType::operator=(rhs);

	m_MessageEvent = move(rhs.m_MessageEvent);

	return *this;
}

Network::SingleMessageEventContainer
	::~SingleMessageEventContainer()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, SingleMessageEventContainer)

void Network::SingleMessageEventContainer
	::Insert(const NetworkMessageEventSharedPtr& messageEvent)
{
	NETWORK_CLASS_IS_VALID_9;

	if (m_MessageEvent.lock())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("消息事件已存在！"));
	}

	m_MessageEvent = messageEvent;
}

void Network::SingleMessageEventContainer
	::Remove(const NetworkMessageEventSharedPtr& messageEvent)
{
	NETWORK_CLASS_IS_VALID_9;

	if (m_MessageEvent.lock() == messageEvent)
	{
		m_MessageEvent.reset();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("消息事件不存在！"));
	}
}

void Network::SingleMessageEventContainer
	::OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message)
{
	NETWORK_CLASS_IS_VALID_9;

	auto messageEvent = m_MessageEvent.lock();

	if (messageEvent)
	{
		messageEvent->CallBackEvent(socketID, message);
	}
}

void Network::SingleMessageEventContainer
	::Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(priority);

	if (m_MessageEvent.lock())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("消息事件已存在！"));
	}

	m_MessageEvent = messageEvent;
}

Network::SingleMessageEventContainer::ImplPtr Network::SingleMessageEventContainer
	::Clone() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return make_shared<ClassType>(*this);
}

Network::SingleMessageEventContainer::ImplPtr Network::SingleMessageEventContainer
	::CloneToMultiMessage() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	auto messageEvent = m_MessageEvent.lock();
	auto multiMessageEventContainer = make_shared<MultiMessageEventContainer>();

	if (messageEvent)
	{
		multiMessageEventContainer->Insert(messageEvent);
	}

	return multiMessageEventContainer;
}

Network::SingleMessageEventContainer::ImplPtr Network::SingleMessageEventContainer
	::CloneToPriorityMessage() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	auto messageEvent = m_MessageEvent.lock();
	auto priorityMessageEventContainer = make_shared<PriorityMessageEventContainer>();

	if (messageEvent)
	{
		priorityMessageEventContainer->Insert(messageEvent);
	}

	return priorityMessageEventContainer;
}

bool Network::SingleMessageEventContainer
	::IsCanInsert() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	if (!m_MessageEvent.lock())
		return true;
	else
		return false;
}

bool Network::SingleMessageEventContainer
	::IsPrioritySame(MessageEventPriority priority) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(priority);

	return false;
}



