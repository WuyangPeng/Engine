//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 13:44)

#include "Network/NetworkExport.h"

#include "MultiMessageEventContainer.h"
#include "MultiMessageEventContainerImpl.h"
#include "PriorityMessageEventContainer.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"

using std::make_shared;

Network::MultiMessageEventContainer::MultiMessageEventContainer([[maybe_unused]] CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{}, m_Impl{ make_shared<ImplType>() }, m_Priority{ MessageEventPriority::Count }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MultiMessageEventContainer::MultiMessageEventContainer(const MultiMessageEventContainer& rhs)
    : ParentType{}, m_Impl{ make_shared<ImplType>(*rhs.m_Impl) }, m_Priority{ rhs.m_Priority }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MultiMessageEventContainer& Network::MultiMessageEventContainer::operator=(const MultiMessageEventContainer& rhs)
{
    NETWORK_CLASS_IS_VALID_1;

    m_Impl = make_shared<ImplType>(*rhs.m_Impl);
    m_Priority = rhs.m_Priority;

    return *this;
}

Network::MultiMessageEventContainer::MultiMessageEventContainer(MultiMessageEventContainer&& rhs) noexcept
    : ParentType{ std::move(rhs) }, m_Impl{ std::move(rhs.m_Impl) }, m_Priority{ rhs.m_Priority }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MultiMessageEventContainer& Network::MultiMessageEventContainer::operator=(MultiMessageEventContainer&& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    ParentType::operator=(std::move(rhs));
    m_Impl = std::move(rhs.m_Impl);
    m_Priority = rhs.m_Priority;

    return *this;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Network, MultiMessageEventContainer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Network, MultiMessageEventContainer, Remove, NetworkMessageEventSharedPtr, void)

void Network::MultiMessageEventContainer::Insert(const NetworkMessageEventSharedPtr& smartPointer)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    m_Priority = MessageEventPriority::Middle;

    return m_Impl->Insert(smartPointer);
}

void Network::MultiMessageEventContainer::Insert(const NetworkMessageEventSharedPtr& smartPointer, MessageEventPriority priority)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    m_Priority = priority;

    return m_Impl->Insert(smartPointer);
}

Network::MultiMessageEventContainer::ImplPtr Network::MultiMessageEventContainer::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return make_shared<ClassType>(*this);
}

Network::MultiMessageEventContainer::ImplPtr Network::MultiMessageEventContainer::CloneToMultiMessage() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return Clone();
}

Network::MultiMessageEventContainer::ImplPtr Network::MultiMessageEventContainer::CloneToPriorityMessage() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return m_Impl->CloneToPriorityMessage(m_Priority);
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
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->OnEvent(socketID, message);
}
