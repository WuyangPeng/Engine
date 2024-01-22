/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:22)

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

Network::MessageEventManager::MessageEventManagerSharedPtr Network::MessageEventManager::CreateSharedPtr()
{
    return std::make_shared<ClassType>(Create());
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

void Network::MessageEventManager::Remove(int64_t messageId)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Remove(messageId);
}

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

void Network::MessageEventManager::SetCallbackEvent(const EventInterfaceSharedPtr& eventInterface)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->SetCallbackEvent(eventInterface);
}

Network::MessageEventManager::EventInterfaceSharedPtr Network::MessageEventManager::GetCallbackEvent()
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->GetCallbackEvent();
}
