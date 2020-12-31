//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 14:01)

#include "Network/NetworkExport.h"

#include "MessageEventContainer.h"
#include "Detail/MessageEventContainerImpl.h"
#include "Detail/MultiMessageEventContainer.h"
#include "Detail/PriorityMessageEventContainer.h"
#include "Detail/SingleMessageEventContainer.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

DELAY_COPY_CONSTRUCTION_CLONE_DEFINE(Network, MessageEventContainer)

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Network::MessageEventContainer::MessageEventContainer()
    : m_Impl{ make_shared<SingleMessageEventContainer>() }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, MessageEventContainer)

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Network, MessageEventContainer, Remove, NetworkMessageEventSharedPtr, void)

void Network::MessageEventContainer::Insert(const NetworkMessageEventSharedPtr& messageEvent)
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

void Network::MessageEventContainer::Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
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

void Network::MessageEventContainer::OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->OnEvent(socketID, message);
}
