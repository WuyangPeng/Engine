// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.4 (2020/03/10 16:35)

#include "Network/NetworkExport.h"

#include "MessageManager.h"
#include "Detail/MessageManagerImpl.h" 
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MainFunctionMacro.h" 
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::make_shared;
using std::make_unique;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26487)
SINGLETON_GET_PTR_DEFINE(CoreTools, EntityManager);

Network::MessageManager::MessageManagerUniquePtr Network::MessageManager
::sm_MessageManager{ };

void Network::MessageManager
::Create()
{
	sm_MessageManager = make_unique<Network::MessageManager>(MessageManagerCreate::Init);
}

void Network::MessageManager
::Destroy() noexcept
{
	sm_MessageManager.reset();
}

Network::MessageManager ::MessageManager([[maybe_unused]] MessageManagerCreate messageManagerCreate)
    : m_Impl{ make_shared<ImplType>() }
{
 

	NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, MessageManager)

Network::MessageManager::FactoryFunction Network::MessageManager
	::Find(int64_t messageID, int version) const
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	NETWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->Find(messageID, version);
}

void Network::MessageManager
	::Insert(int64_t messageID, const MessageTypeCondition& messageTypeCondition, FactoryFunction function)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Insert(messageID, messageTypeCondition, function);
}

void Network::MessageManager
	::Remove(int64_t messageID, const MessageTypeCondition& messageTypeCondition)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Remove(messageID, messageTypeCondition);
}

void Network::MessageManager
	::Remove(int64_t messageID)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Remove(messageID);
}

void Network::MessageManager
	::SetFullVersion(int fullVersion)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetFullVersion(fullVersion);
}

int Network::MessageManager
	::GetFullVersion() const
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	NETWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetFullVersion();
}

#include STSTEM_WARNING_POP