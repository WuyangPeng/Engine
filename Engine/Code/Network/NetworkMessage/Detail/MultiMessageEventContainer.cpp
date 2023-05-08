///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/08 10:28)

#include "Network/NetworkExport.h"

#include "MultiMessageEventContainer.h"
#include "MultiMessageEventContainerImpl.h"
#include "PriorityMessageEventContainer.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Network, MultiMessageEventContainer)

Network::MultiMessageEventContainer::MultiMessageEventContainer(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{}, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }, priority{ MessageEventPriority::Count }
{
    System::UnusedFunction(disableNotThrow);

    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MultiMessageEventContainer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Network, MultiMessageEventContainer, Remove, NetworkMessageEventSharedPtr, void)

void Network::MultiMessageEventContainer::Insert(const NetworkMessageEventSharedPtr& messageEvent)
{
    NETWORK_CLASS_IS_VALID_1;

    priority = MessageEventPriority::Middle;

    return impl->Insert(messageEvent);
}

void Network::MultiMessageEventContainer::Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority aPriority)
{
    NETWORK_CLASS_IS_VALID_1;

    priority = aPriority;

    return impl->Insert(messageEvent);
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

    return impl->CloneToPriorityMessage(priority);
}

bool Network::MultiMessageEventContainer::IsCanInsert() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return true;
}

bool Network::MultiMessageEventContainer::IsPrioritySame(MessageEventPriority aPriority) const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    if (priority == aPriority)
        return true;
    else
        return false;
}

void Network::MultiMessageEventContainer::OnEvent(uint64_t socketId, const ConstMessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->OnEvent(socketId, message);
}
