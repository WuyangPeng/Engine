///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.7 (2023/05/08 10:55)

#include "Network/NetworkExport.h"

#include "MessageEventManager.h"
#include "Detail/MessageEventManagerImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

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

void Network::MessageEventManager::Insert(int64_t messageId, const NetworkMessageEventSharedPtr& messageEvent)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Insert(messageId, messageEvent);
}

void Network::MessageEventManager::Insert(int64_t messageId, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Insert(messageId, messageEvent, priority);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, MessageEventManager, Remove, int64_t, void)

void Network::MessageEventManager::Remove(int64_t messageId, const NetworkMessageEventSharedPtr& messageEvent)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Remove(messageId, messageEvent);
}

void Network::MessageEventManager::Insert(const std::string& messageDescribe, const NetworkMessageEventSharedPtr& messageEvent)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Insert(messageDescribe, messageEvent);
}

void Network::MessageEventManager::Insert(const std::string& messageDescribe, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Insert(messageDescribe, messageEvent, priority);
}

void Network::MessageEventManager::OnEvent(int64_t socketId, int64_t messageId, const ConstMessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->OnEvent(socketId, messageId, message);
}

void Network::MessageEventManager::OnEvent(int64_t socketId, const std::string& messageDescribe, const ConstMessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->OnEvent(socketId, messageDescribe, message);
}
