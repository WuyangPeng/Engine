// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.1.0 (2019/11/25 18:10)


#include "Network/NetworkExport.h"

#include "MessageEventManager.h"
#include "Detail/MessageEventManagerImpl.h" 
#include "CoreTools/Helper/MemberFunctionMacro.h" 
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::make_shared;

DELAY_COPY_CONSTRUCTION_DEFINE(Network, MessageEventManager)
DELAY_COPY_CONSTRUCTION_SHALLOW_COPY_DEFINE(Network, MessageEventManager)

Network::MessageEventManager
	::MessageEventManager()
	:m_Impl{ make_shared<ImplType>() }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

IMPL_MOVE_OPERATOR_COMPLETE_DEFINE(Network, MessageEventManager)

void Network::MessageEventManager
	::Insert(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Insert(messageID, messageEvent);
}

void Network::MessageEventManager
	::Insert(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Insert(messageID, messageEvent, priority);
}

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Network, MessageEventManager, Remove, int64_t, void)

void Network::MessageEventManager
	::Remove(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Remove(messageID, messageEvent);
}

void Network::MessageEventManager
	::OnEvent(int64_t messageID, uint64_t socketID, const ConstMessageInterfaceSharedPtr& message)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->OnEvent(messageID, socketID, message);
}






