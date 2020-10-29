//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 14:02)

#include "Network/NetworkExport.h"

#include "MessageEventManager.h"
#include "Detail/MessageEventManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

DELAY_COPY_CONSTRUCTION_DEFINE(Network, MessageEventManager)

Network::MessageEventManager::MessageEventManager(CoreTools::DisableNotThrow disableNotThrow)
    : m_Impl{ make_shared<ImplType>(disableNotThrow) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, MessageEventManager)

void Network::MessageEventManager::Insert(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Insert(messageID, messageEvent);
}

void Network::MessageEventManager::Insert(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Insert(messageID, messageEvent, priority);
}

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Network, MessageEventManager, Remove, int64_t, void)

void Network::MessageEventManager::Remove(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Remove(messageID, messageEvent);
}

void Network::MessageEventManager::OnEvent(int64_t messageID, uint64_t socketID, const ConstMessageInterfaceSharedPtr& message)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->OnEvent(messageID, socketID, message);
}
