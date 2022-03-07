///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 22:34)

#include "Network/NetworkExport.h"

#include "MultiMessageEventContainer.h"
#include "MultiMessageEventContainerImpl.h"
#include "PriorityMessageEventContainer.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Network, MultiMessageEventContainer)

Network::MultiMessageEventContainer::MultiMessageEventContainer(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{}, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }, m_Priority{ MessageEventPriority::Count }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MultiMessageEventContainer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Network, MultiMessageEventContainer, Remove, NetworkMessageEventSharedPtr, void)

void Network::MultiMessageEventContainer::Insert(const NetworkMessageEventSharedPtr& smartPointer)
{
    NETWORK_CLASS_IS_VALID_1;

    m_Priority = MessageEventPriority::Middle;

    return impl->Insert(smartPointer);
}

void Network::MultiMessageEventContainer::Insert(const NetworkMessageEventSharedPtr& smartPointer, MessageEventPriority priority)
{
    NETWORK_CLASS_IS_VALID_1;

    m_Priority = priority;

    return impl->Insert(smartPointer);
}

Network::MultiMessageEventContainer::ImplPtr Network::MultiMessageEventContainer::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

Network::MultiMessageEventContainer::ImplPtr Network::MultiMessageEventContainer::CloneToMultiMessage() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return Clone();
}

Network::MultiMessageEventContainer::ImplPtr Network::MultiMessageEventContainer::CloneToPriorityMessage() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->CloneToPriorityMessage(m_Priority);
}

bool Network::MultiMessageEventContainer::IsCanInsert() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return true;
}

bool Network::MultiMessageEventContainer::IsPrioritySame(MessageEventPriority priority) const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    if (m_Priority == priority)
        return true;
    else
        return false;
}

void Network::MultiMessageEventContainer::OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->OnEvent(socketID, message);
}
