// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 16:34)

#include "Network/NetworkExport.h"

#include "MessageEventContainer.h"
#include "Detail/MessageEventContainerImpl.h"
#include "Detail/SingleMessageEventContainer.h"
#include "Detail/MultiMessageEventContainer.h"
#include "Detail/PriorityMessageEventContainer.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::make_shared;

DELAY_COPY_CONSTRUCTION_CLONE_DEFINE(Network, MessageEventContainer) 

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26486)
Network::MessageEventContainer
	::MessageEventContainer()
	:m_Impl{ make_shared<SingleMessageEventContainer>() }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, MessageEventContainer)

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Network, MessageEventContainer, Remove, NetworkMessageEventSharedPtr, void)

void Network::MessageEventContainer
	::Insert(const NetworkMessageEventSharedPtr& messageEvent)
{
	static_assert(std::is_same_v<ClassShareType::NonConstCopyMember, CoreTools::TrueType>, "Non-const copy member functions are forbidden");

	NETWORK_CLASS_IS_VALID_1;

	if (m_Impl->IsCanInsert())
	{
		Copy();

		m_Impl->Insert(messageEvent);
	}
	else
	{
		m_Impl = m_Impl->CloneToMultiMessage();
		m_Impl->Insert(messageEvent);
	}
}

void Network::MessageEventContainer
	::Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
	static_assert(std::is_same_v<ClassShareType::NonConstCopyMember, CoreTools::TrueType>, "Non-const copy member functions are forbidden");

	NETWORK_CLASS_IS_VALID_1;

	if (m_Impl->IsPrioritySame(priority))
	{
		Copy();

		m_Impl->Insert(messageEvent, priority);
	}
	else
	{
		m_Impl = m_Impl->CloneToPriorityMessage();
		m_Impl->Insert(messageEvent, priority);
	}
}

void Network::MessageEventContainer
	::OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->OnEvent(socketID, message);
}
#include STSTEM_WARNING_POP