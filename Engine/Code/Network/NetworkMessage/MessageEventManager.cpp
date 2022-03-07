///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/19 10:16)

#include "Network/NetworkExport.h"

#include "MessageEventManager.h"
#include "Detail/MessageEventManagerImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

COPY_UNSHARED_CLONE_SELF_DEFINE(Network, MessageEventManager)

Network::MessageEventManager Network::MessageEventManager::Create()
{
    return MessageEventManager{ CoreTools::DisableNotThrow::Disable };
}

Network::MessageEventManager::MessageEventManager(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ disableNotThrow }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageEventManager)

void Network::MessageEventManager::Insert(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Insert(messageID, messageEvent);
}

void Network::MessageEventManager::Insert(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Insert(messageID, messageEvent, priority);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, MessageEventManager, Remove, int64_t, void)

void Network::MessageEventManager::Remove(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Remove(messageID, messageEvent);
}

void Network::MessageEventManager::OnEvent(int64_t messageID, uint64_t socketID, const ConstMessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->OnEvent(messageID, socketID, message);
}
