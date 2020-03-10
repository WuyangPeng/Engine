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

using std::string;
using std::make_shared;

SINGLETON_MUTEX_DEFINE(Network, MessageManager);

#define MUTEX_ENTER_GLOBAL CoreTools::ScopedMutex holder{ g_NetworkMutex }

#define MUTEX_ENTER_MEMBER CoreTools::ScopedMutex holder{ *sm_MessageManagerMutex }

SINGLETON_INITIALIZE_DEFINE(Network, MessageManager)

Network::MessageManager
	::MessageManager()
	:m_Impl{ make_shared<ImplType>() }
{
	MUTEX_ENTER_MEMBER;

	NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MessageManager
	::~MessageManager()
{
	MUTEX_ENTER_MEMBER;

	NETWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Network::MessageManager
	::IsValid() const noexcept
{
	MUTEX_ENTER_MEMBER;

	if (m_Impl != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

Network::MessageManager::FactoryFunction Network::MessageManager
	::Find(int64_t messageID, int version) const
{
	MUTEX_ENTER_MEMBER;

	NETWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->Find(messageID, version);
}

void Network::MessageManager
	::Insert(int64_t messageID, const MessageTypeCondition& messageTypeCondition, FactoryFunction function)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Insert(messageID, messageTypeCondition, function);
}

void Network::MessageManager
	::Remove(int64_t messageID, const MessageTypeCondition& messageTypeCondition)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Remove(messageID, messageTypeCondition);
}

void Network::MessageManager
	::Remove(int64_t messageID)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Remove(messageID);
}

void Network::MessageManager
	::SetFullVersion(int fullVersion)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetFullVersion(fullVersion);
}

int Network::MessageManager
	::GetFullVersion() const
{
	MUTEX_ENTER_MEMBER;

	NETWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetFullVersion();
}

