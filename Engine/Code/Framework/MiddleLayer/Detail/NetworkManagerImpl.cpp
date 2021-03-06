// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 14:53)

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

void Framework::NetworkManagerImpl ::Send(const Network::SocketData& socketData, uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_SendSocketManager != nullptr)
	{
            m_SendSocketManager->Send(socketData, socketID, message);
	}
}
 