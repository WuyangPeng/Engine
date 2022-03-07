///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 22:29)

#include "Network/NetworkExport.h"

#include "MessageEventManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::make_unique;

#define MUTEX_ENTER_MEMBER const CoreTools::ScopedMutex holder{ *mutex };

Network::MessageEventManagerImpl::MessageEventManagerImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : eventContainer{}, mutex{ make_unique<CoreTools::Mutex>(CoreTools::MutexCreate::UseStdRecursive) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageEventManagerImpl::MessageEventManagerImpl(const MessageEventManagerImpl& rhs)
    : eventContainer{ rhs.eventContainer }, mutex{ make_unique<CoreTools::Mutex>(CoreTools::MutexCreate::UseStdRecursive) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageEventManagerImpl& Network::MessageEventManagerImpl::operator=(const MessageEventManagerImpl& rhs)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    if (this != &rhs)
    {
        eventContainer = rhs.eventContainer;
    }

    return *this;
}

Network::MessageEventManagerImpl::MessageEventManagerImpl(MessageEventManagerImpl&& rhs) noexcept
    : eventContainer{ std::move(rhs.eventContainer) }, mutex{ std::move(rhs.mutex) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageEventManagerImpl& Network::MessageEventManagerImpl::operator=(MessageEventManagerImpl&& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    if (this != &rhs)
    {
        eventContainer = std::move(rhs.eventContainer);
    }

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageEventManagerImpl)

void Network::MessageEventManagerImpl::Insert(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    auto iter = eventContainer.find(messageID);

    if (iter == eventContainer.cend())
    {
        iter = eventContainer.insert({ messageID, MessageEventContainer::Create() }).first;
    }

    if (iter != eventContainer.cend())
    {
        iter->second.Insert(messageEvent);
    }
}

void Network::MessageEventManagerImpl::Insert(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    auto iter = eventContainer.find(messageID);

    if (iter == eventContainer.cend())
    {
        iter = eventContainer.insert({ messageID, MessageEventContainer::Create() }).first;
    }

    if (iter != eventContainer.cend())
    {
        iter->second.Insert(messageEvent, priority);
    }
}

void Network::MessageEventManagerImpl::Remove(int64_t messageID)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    eventContainer.erase(messageID);
}

void Network::MessageEventManagerImpl::Remove(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    const auto iter = eventContainer.find(messageID);

    if (iter != eventContainer.cend())
    {
        iter->second.Remove(messageEvent);
    }
}

void Network::MessageEventManagerImpl::OnEvent(int64_t messageID, uint64_t socketID, const ConstMessageInterfaceSharedPtr& message)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    const auto iter = eventContainer.find(messageID);

    if (iter != eventContainer.cend())
    {
        iter->second.OnEvent(socketID, message);
    }
}
