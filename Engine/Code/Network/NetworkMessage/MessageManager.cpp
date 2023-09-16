///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:53)

#include "Network/NetworkExport.h"

#include "MessageManager.h"
#include "Detail/MessageManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

SINGLETON_GET_PTR_DEFINE(CoreTools, EntityManager);

Network::MessageManager::MessageManagerUniquePtr Network::MessageManager::messageManager{};

void Network::MessageManager::Create()
{
    messageManager = std::make_unique<MessageManager>(MessageManagerCreate::Init);
}

void Network::MessageManager::Destroy() noexcept
{
    messageManager.reset();
}

Network::MessageManager::MessageManager(MessageManagerCreate messageManagerCreate)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(messageManagerCreate);

    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageManager)

Network::MessageManager::FactoryFunction Network::MessageManager::Find(int64_t messageId, int version) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->Find(messageId, version);
}

Network::MessageManager::FactoryFunction Network::MessageManager::Find(const std::string& messageDescribe, int version) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->Find(messageDescribe, version);
}

void Network::MessageManager::Insert(int64_t messageId, const MessageTypeCondition& messageTypeCondition, FactoryFunction function)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_1;

    return impl->Insert(messageId, messageTypeCondition, function);
}

void Network::MessageManager::Insert(const std::string& messageDescribe, const MessageTypeCondition& messageTypeCondition, FactoryFunction function)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_1;

    return impl->Insert(messageDescribe, messageTypeCondition, function);
}

void Network::MessageManager::Remove(int64_t messageId, const MessageTypeCondition& messageTypeCondition)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_1;

    return impl->Remove(messageId, messageTypeCondition);
}

void Network::MessageManager::Remove(int64_t messageId)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_1;

    return impl->Remove(messageId);
}

void Network::MessageManager::SetFullVersion(int fullVersion)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_1;

    return impl->SetFullVersion(fullVersion);
}

int Network::MessageManager::GetFullVersion() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetFullVersion();
}
