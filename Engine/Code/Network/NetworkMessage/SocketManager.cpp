// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.4 (2020/03/10 16:38)

#include "Network/NetworkExport.h"

#include "SocketManager.h"
#include "Detail/SocketManagerImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::make_shared;
using std::make_unique;

Network::SocketManager
	::SocketManager()
	:m_Impl{ make_shared<ImplType>() }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::SocketManager
	::~SocketManager()
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::SocketManager
	::SocketManager(SocketManager&& rhs) noexcept
	:m_Impl{ move(rhs.m_Impl) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::SocketManager& Network::SocketManager
	::operator =(SocketManager&& rhs) noexcept
{
	NETWORK_CLASS_IS_VALID_1;

	m_Impl = move(rhs.m_Impl);

	return *this;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, SocketManager)

void Network::SocketManager
	::Insert(uint64_t socketID)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Impl->Insert(socketID);

	InitEvent(socketID);
}

void Network::SocketManager
	::Insert(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& smartPointer)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Insert(socketID, messageID, smartPointer);
}

void Network::SocketManager
	::Insert(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& smartPointer, MessageEventPriority priority)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Insert(socketID, messageID, smartPointer, priority);
}

void Network::SocketManager
	::OnEvent(uint64_t socketID, int64_t messageID, const ConstMessageInterfaceSharedPtr& message)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Impl->OnEvent(socketID, messageID, message);
}

void Network::SocketManager
	::Remove(uint64_t socketID, int64_t messageID)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Remove(socketID, messageID);
}

void Network::SocketManager
	::Remove(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& smartPointer)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Remove(socketID, messageID, smartPointer);
}

void Network::SocketManager
	::Remove(uint64_t socketID)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Remove(socketID);
}

int Network::SocketManager
	::GetSocketSize() const
{
	NETWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetSocketSize();
}
