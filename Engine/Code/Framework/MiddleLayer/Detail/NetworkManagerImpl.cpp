// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:53)

#include "Framework/FrameworkExport.h"

#include "NetworkManagerImpl.h"  
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 
#include "Network/Interface/SendSocketManager.h"

using std::move;  
using std::string;
using std::make_shared;
using std::const_pointer_cast;

Framework::NetworkManagerImpl
	::NetworkManagerImpl() noexcept
	:m_SendSocketManager{ }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::NetworkManagerImpl
	::NetworkManagerImpl(NetworkManagerImpl&& rhs) noexcept
	:m_SendSocketManager{ move(rhs.m_SendSocketManager) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::NetworkManagerImpl& Framework::NetworkManagerImpl
	::operator=(NetworkManagerImpl&& rhs) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_SendSocketManager = move(rhs.m_SendSocketManager);

	return *this;
} 

CLASS_INVARIANT_STUB_DEFINE(Framework, NetworkManagerImpl)

void Framework::NetworkManagerImpl
	::ResetSendSocketManager(const string& fileName)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_SendSocketManager = make_shared<SendSocketManager>(fileName);
}

Framework::NetworkManagerImpl::SendSocketManagerSharedPtr Framework::NetworkManagerImpl
	::GetSendSocketManager() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)   
	return const_pointer_cast<SendSocketManager>(static_cast<const ClassType*>(this)->GetSendSocketManager());
#include STSTEM_WARNING_POP
}

Framework::NetworkManagerImpl::ConstSendSocketManagerSharedPtr Framework::NetworkManagerImpl
	::GetSendSocketManager() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_SendSocketManager;
}

void Framework::NetworkManagerImpl
	::Send(SocketType socketType, int serverID, uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_SendSocketManager != nullptr)
	{
		m_SendSocketManager->Send(socketType, serverID, socketID, message);
	}
}

void Framework::NetworkManagerImpl
	::Insert(SocketType socketType, int serverID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_SendSocketManager != nullptr)
	{
		m_SendSocketManager->Insert(socketType, serverID, messageID, messageEvent);
	}
}

void Framework::NetworkManagerImpl
	::Insert(SocketType socketType, int serverID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_SendSocketManager != nullptr)
	{
		m_SendSocketManager->Insert(socketType, serverID, messageID, messageEvent, priority);
	}
}

void Framework::NetworkManagerImpl
	::Remove(SocketType socketType, int serverID, int64_t messageID)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_SendSocketManager != nullptr)
	{
		m_SendSocketManager->Remove(socketType, serverID, messageID);
	}
}

void Framework::NetworkManagerImpl
	::Remove(SocketType socketType, int serverID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_SendSocketManager != nullptr)
	{
		m_SendSocketManager->Remove(socketType, serverID, messageID, messageEvent);
	}
}

void Framework::NetworkManagerImpl
	::HandlingMessages()
{
	if (m_SendSocketManager != nullptr)
	{
		m_SendSocketManager->HandlingMessages();
	}
}

void Framework::NetworkManagerImpl
	::Destroy()
{
	if (m_SendSocketManager != nullptr)
	{
		m_SendSocketManager->Destroy();
	}
}
