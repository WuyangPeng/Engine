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

#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
using std::make_shared;
COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Network, MessageEventContainer)
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Network::MessageEventContainer::MessageEventContainer()
    : impl{ CoreTools::ImplCreateUseFactory::Default }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

CLASS_INVARIANT_STUB_DEFINE(Network, MessageEventContainer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Network, MessageEventContainer, Remove, NetworkMessageEventSharedPtr, void)

void Network::MessageEventContainer::Insert(const NetworkMessageEventSharedPtr& messageEvent)
{
     NETWORK_CLASS_IS_VALID_1;

    if (impl.GetConstImpl()->IsCanInsert())
    {
        impl->Insert(messageEvent);
    }
    else
    {
        // impl = impl->CloneToMultiMessage();
        impl->Insert(messageEvent);
    }
}

void Network::MessageEventContainer::Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
    
    NETWORK_CLASS_IS_VALID_1;

    if (impl->IsPrioritySame(priority))
    {
        impl->Insert(messageEvent, priority);
    }
    else
    {
        // impl = impl->CloneToPriorityMessage();
        impl->Insert(messageEvent, priority);
    }
}

void Network::MessageEventContainer::OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->OnEvent(socketID, message);
}
