///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/19 10:25)

#include "Network/NetworkExport.h"

#include "MessageManager.h"
#include "Detail/MessageManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::make_shared;
using std::make_unique;

SINGLETON_GET_PTR_DEFINE(CoreTools, EntityManager);

Network::MessageManager::MessageManagerUniquePtr Network::MessageManager::messageManager{};

void Network::MessageManager::Create()
{
    messageManager = make_unique<Network::MessageManager>(MessageManagerCreate::Init);
}

void Network::MessageManager::Destroy() noexcept
{
    messageManager.reset();
}

Network::MessageManager::MessageManager(MAYBE_UNUSED MessageManagerCreate messageManagerCreate)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageManager)

Network::MessageManager::FactoryFunction Network::MessageManager::Find(int64_t messageID, int version) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->Find(messageID, version);
}

void Network::MessageManager::Insert(int64_t messageID, const MessageTypeCondition& messageTypeCondition, FactoryFunction function)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_1;

    return impl->Insert(messageID, messageTypeCondition, function);
}

void Network::MessageManager::Remove(int64_t messageID, const MessageTypeCondition& messageTypeCondition)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_1;

    return impl->Remove(messageID, messageTypeCondition);
}

void Network::MessageManager::Remove(int64_t messageID)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_1;

    return impl->Remove(messageID);
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
