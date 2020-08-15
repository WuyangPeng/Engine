// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 16:22)

#include "Network/NetworkExport.h"

#include "MessageEventManagerImpl.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

using std::make_unique;

#define MUTEX_ENTER_MEMBER CoreTools::ScopedMutex holder{ *m_Mutex }
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26486)
Network::MessageEventManagerImpl
	::MessageEventManagerImpl()
	:m_EventContainer{}, m_Mutex{ make_unique<CoreTools::Mutex>() }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}


Network::MessageEventManagerImpl
	::MessageEventManagerImpl(const MessageEventManagerImpl& rhs)
	:m_EventContainer{ rhs.m_EventContainer }, m_Mutex{ make_unique<CoreTools::Mutex>() }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageEventManagerImpl& Network::MessageEventManagerImpl
	::operator=(const MessageEventManagerImpl& rhs)
{
	NETWORK_CLASS_IS_VALID_9;

	m_EventContainer = rhs.m_EventContainer;
	m_Mutex = make_unique<CoreTools::Mutex>();

	return *this;
}

Network::MessageEventManagerImpl
	::MessageEventManagerImpl(MessageEventManagerImpl&& rhs) noexcept
	:m_EventContainer{ move(rhs.m_EventContainer) }, m_Mutex{ move(rhs.m_Mutex) }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageEventManagerImpl& Network::MessageEventManagerImpl
	::operator=(MessageEventManagerImpl&& rhs) noexcept
{
	NETWORK_CLASS_IS_VALID_9;

	m_EventContainer = move(rhs.m_EventContainer);
	m_Mutex = move(rhs.m_Mutex);

	return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageEventManagerImpl)

void Network::MessageEventManagerImpl
	::Insert(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
	MUTEX_ENTER_MEMBER;

	NETWORK_CLASS_IS_VALID_9;

	m_EventContainer[messageID].Insert(messageEvent);
}

void Network::MessageEventManagerImpl
	::Insert(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
	MUTEX_ENTER_MEMBER;

	NETWORK_CLASS_IS_VALID_9;

	m_EventContainer[messageID].Insert(messageEvent, priority);
}

void Network::MessageEventManagerImpl
	::Remove(int64_t messageID)
{
	MUTEX_ENTER_MEMBER;

	NETWORK_CLASS_IS_VALID_9;

	m_EventContainer.erase(messageID);
}

void Network::MessageEventManagerImpl
	::Remove(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
	MUTEX_ENTER_MEMBER;

	NETWORK_CLASS_IS_VALID_9;

	m_EventContainer[messageID].Remove(messageEvent);
}

void Network::MessageEventManagerImpl
	::OnEvent(int64_t messageID, uint64_t socketID, const ConstMessageInterfaceSharedPtr& message)
{
	MUTEX_ENTER_MEMBER;

	NETWORK_CLASS_IS_VALID_9;

	m_EventContainer[messageID].OnEvent(socketID, message);
}

#include STSTEM_WARNING_POP