// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 16:30)

#include "Network/NetworkExport.h"

#include "SocketManagerImpl.h"
#include "CoreTools/Base/UniqueIDManagerDetail.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/MessageEvent/CallbackParameters.h" 
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

#define MUTEX_ENTER_MEMBER CoreTools::ScopedMutex holder{ *m_Mutex }

using std::make_unique;

Network::SocketManagerImpl
	::SocketManagerImpl()
	:m_MessageEventManagerContainer{}, m_Mutex{ make_unique<CoreTools::Mutex>() }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::SocketManagerImpl
	::SocketManagerImpl(const SocketManagerImpl& rhs)
	:m_MessageEventManagerContainer{ rhs.m_MessageEventManagerContainer }, m_Mutex{ make_unique<CoreTools::Mutex>() }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::SocketManagerImpl& Network::SocketManagerImpl
	::operator=(const SocketManagerImpl& rhs)
{
	NETWORK_CLASS_IS_VALID_9;

	m_MessageEventManagerContainer = rhs.m_MessageEventManagerContainer;
	m_Mutex = make_unique<CoreTools::Mutex>();

	return *this;
}

Network::SocketManagerImpl
	::SocketManagerImpl(SocketManagerImpl&& rhs) noexcept
	:m_MessageEventManagerContainer{ move(rhs.m_MessageEventManagerContainer) }, m_Mutex{ move(rhs.m_Mutex) }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::SocketManagerImpl& Network::SocketManagerImpl
	::operator=(SocketManagerImpl&& rhs) noexcept
{
	NETWORK_CLASS_IS_VALID_9;

	m_MessageEventManagerContainer = move(rhs.m_MessageEventManagerContainer);
	m_Mutex = move(rhs.m_Mutex);

	return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SocketManagerImpl)

void Network::SocketManagerImpl
	::Insert(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
	MUTEX_ENTER_MEMBER;

	NETWORK_CLASS_IS_VALID_9;

	auto iter = m_MessageEventManagerContainer.find(socketID);

	if (iter != m_MessageEventManagerContainer.cend())
	{
		iter->second.Insert(messageID, messageEvent);
	}
}

void Network::SocketManagerImpl
	::Insert(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
	MUTEX_ENTER_MEMBER;

	NETWORK_CLASS_IS_VALID_9;

	auto iter = m_MessageEventManagerContainer.find(socketID);

	if (iter != m_MessageEventManagerContainer.cend())
	{
		iter->second.Insert(messageID, messageEvent, priority);
	}
}

void Network::SocketManagerImpl
	::Insert(uint64_t socketID)
{
	MUTEX_ENTER_MEMBER;

	NETWORK_CLASS_IS_VALID_9;

	m_MessageEventManagerContainer.insert({ socketID, MessageEventManager{} });
}

void Network::SocketManagerImpl
	::Remove(uint64_t socketID, int64_t messageID)
{
	MUTEX_ENTER_MEMBER;

	NETWORK_CLASS_IS_VALID_9;

	auto iter = m_MessageEventManagerContainer.find(socketID);

	if (iter != m_MessageEventManagerContainer.cend())
	{
		iter->second.Remove(messageID);
	}
}

void Network::SocketManagerImpl
	::Remove(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
	MUTEX_ENTER_MEMBER;

	NETWORK_CLASS_IS_VALID_9;

	auto iter = m_MessageEventManagerContainer.find(socketID);

	if (iter != m_MessageEventManagerContainer.cend())
	{
		iter->second.Remove(messageID, messageEvent);
	}
}

void Network::SocketManagerImpl
	::Remove(uint64_t socketID)
{
	MUTEX_ENTER_MEMBER;

	NETWORK_CLASS_IS_VALID_9;

	m_MessageEventManagerContainer.erase(socketID);
}

void Network::SocketManagerImpl
	::OnEvent(uint64_t socketID, int64_t messageID, const ConstMessageInterfaceSharedPtr& message)
{
	MUTEX_ENTER_MEMBER;

	NETWORK_CLASS_IS_VALID_9;

	auto iter = m_MessageEventManagerContainer.find(socketID);

	if (iter != m_MessageEventManagerContainer.cend())
	{
		iter->second.OnEvent(messageID, socketID, message);
	}
}

int Network::SocketManagerImpl
	::GetSocketSize() const
{
	MUTEX_ENTER_MEMBER;

	NETWORK_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_MessageEventManagerContainer.size());
}
