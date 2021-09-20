// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 13:12)

#include "TestSocketManager.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"  
#include "CoreTools/MessageEvent/CallbackParameters.h"
 

using std::make_shared;

Network::TestSocketManager
	::TestSocketManager(uint32_t messageID)
	:ParentType{}, m_MessageID{ messageID }, m_TestMessageEvent(make_shared<TestMessageEvent>()),
	 m_AsyncConnectCount{ 0 }, m_AsyncAcceptorCount{ 0 }, m_AsyncReceiveCount{ 0 }, m_AsyncSendCount{ 0 }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::TestSocketManager
	::~TestSocketManager()
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestSocketManager);

void Network::TestSocketManager
	::InitEvent(uint64_t socketID)
{
    InsertEvent(socketID, m_MessageID, m_TestMessageEvent);
}

uint64_t Network::TestSocketManager
	::GetCallBackTime() const
{
	NETWORK_CLASS_IS_VALID_9;

	return m_TestMessageEvent->GetCallBackTime();
}

bool Network::TestSocketManager
	::EventFunction(const CoreTools::CallbackParameters& callbackParameters)
{
	NETWORK_CLASS_IS_VALID_9;

	auto eventType = System::UnderlyingCastEnum<SocketManagerEvent>(callbackParameters.GetInt32Value(System::EnumCastUnderlying(SocketManagerPoisition::Event)));

	switch (eventType)
	{
	case Network::SocketManagerEvent::AsyncConnect:
	{
		++m_AsyncConnectCount;
		return true;
	}
	case Network::SocketManagerEvent::AsyncAcceptor:
	{
		++m_AsyncAcceptorCount;
		return true;
	}
	break;
	case Network::SocketManagerEvent::AsyncReceive:
	{
		++m_AsyncReceiveCount;
		return true;
	}
	break;
	case  Network::SocketManagerEvent::AsyncSend:
	{
		++m_AsyncSendCount;
		return true;
	}
	default:
		break;
	}

	return false;
}

int Network::TestSocketManager
	::GetAsyncConnectCount() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_AsyncConnectCount;
}

void Network::TestSocketManager
	::SetServerWeakPtr(const ServerSharedPtr& ptr)
{
	NETWORK_CLASS_IS_VALID_9;

	m_TestMessageEvent->SetServerWeakPtr(ptr);
}

int Network::TestSocketManager
	::GetAsyncReceiveCount() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_AsyncReceiveCount;
}

int Network::TestSocketManager
	::GetAsyncAcceptorCount() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_AsyncAcceptorCount;
}

int Network::TestSocketManager
	::GetAsyncSendCount() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_AsyncSendCount;
}

