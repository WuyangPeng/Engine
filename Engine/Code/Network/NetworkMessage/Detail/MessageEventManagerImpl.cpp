///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:33)

#include "Network/NetworkExport.h"

#include "MessageEventManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Threading/ScopedMutex.h"

#define MUTEX_ENTER_MEMBER              \
    const CoreTools::ScopedMutex holder \
    {                                   \
        *mutex                          \
    }

Network::MessageEventManagerImpl::MessageEventManagerImpl(CoreTools::DisableNotThrow disableNotThrow)
    : idEventContainer{}, describeEventContainer{}, mutex{ std::make_unique<CoreTools::Mutex>(CoreTools::MutexCreate::UseStdRecursive) }, event{}
{
    System::UnusedFunction(disableNotThrow);

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageEventManagerImpl::MessageEventManagerImpl(const MessageEventManagerImpl& rhs)
    : idEventContainer{ rhs.idEventContainer }, describeEventContainer{ rhs.describeEventContainer }, mutex{ std::make_unique<CoreTools::Mutex>(CoreTools::MutexCreate::UseStdRecursive) }, event{ rhs.event }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageEventManagerImpl& Network::MessageEventManagerImpl::operator=(const MessageEventManagerImpl& rhs)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    if (this != &rhs)
    {
        idEventContainer = rhs.idEventContainer;
        describeEventContainer = rhs.describeEventContainer;
        event = rhs.event;
    }

    return *this;
}

Network::MessageEventManagerImpl::MessageEventManagerImpl(MessageEventManagerImpl&& rhs) noexcept
    : idEventContainer{ std::move(rhs.idEventContainer) }, describeEventContainer{ std::move(rhs.describeEventContainer) }, mutex{ std::move(rhs.mutex) }, event{ std::move(rhs.event) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageEventManagerImpl& Network::MessageEventManagerImpl::operator=(MessageEventManagerImpl&& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    if (this != &rhs)
    {
        idEventContainer = std::move(rhs.idEventContainer);
        describeEventContainer = std::move(rhs.describeEventContainer);
        event = std::move(event);
    }

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageEventManagerImpl)

void Network::MessageEventManagerImpl::Insert(int64_t messageId, const NetworkMessageEventSharedPtr& messageEvent)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    auto iter = idEventContainer.find(messageId);

    if (iter == idEventContainer.cend())
    {
        iter = idEventContainer.emplace(messageId, MessageEventContainer::Create()).first;
    }

    if (iter != idEventContainer.cend())
    {
        iter->second.Insert(messageEvent);
    }
}

void Network::MessageEventManagerImpl::Insert(int64_t messageId, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    auto iter = idEventContainer.find(messageId);

    if (iter == idEventContainer.cend())
    {
        iter = idEventContainer.emplace(messageId, MessageEventContainer::Create()).first;
    }

    if (iter != idEventContainer.cend())
    {
        iter->second.Insert(messageEvent, priority);
    }
}

void Network::MessageEventManagerImpl::Remove(int64_t messageId)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    idEventContainer.erase(messageId);
}

void Network::MessageEventManagerImpl::Remove(int64_t messageId, const NetworkMessageEventSharedPtr& messageEvent)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    if (const auto iter = idEventContainer.find(messageId);
        iter != idEventContainer.cend())
    {
        iter->second.Remove(messageEvent);
    }
}

void Network::MessageEventManagerImpl::Insert(const std::string& messageDescribe, const NetworkMessageEventSharedPtr& messageEvent)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    auto iter = describeEventContainer.find(messageDescribe);

    if (iter == describeEventContainer.cend())
    {
        iter = describeEventContainer.emplace(messageDescribe, MessageEventContainer::Create()).first;
    }

    if (iter != describeEventContainer.cend())
    {
        iter->second.Insert(messageEvent);
    }
}

void Network::MessageEventManagerImpl::Insert(const std::string& messageDescribe, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    auto iter = describeEventContainer.find(messageDescribe);

    if (iter == describeEventContainer.cend())
    {
        iter = describeEventContainer.emplace(messageDescribe, MessageEventContainer::Create()).first;
    }

    if (iter != describeEventContainer.cend())
    {
        iter->second.Insert(messageEvent, priority);
    }
}

void Network::MessageEventManagerImpl::OnEvent(int64_t socketId, int64_t messageId, const ConstMessageInterfaceSharedPtr& message)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    if (const auto iter = idEventContainer.find(messageId);
        iter != idEventContainer.cend())
    {
        iter->second.OnEvent(socketId, message);
    }
}

void Network::MessageEventManagerImpl::OnEvent(int64_t socketId, const std::string& messageDescribe, const ConstMessageInterfaceSharedPtr& message)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    if (const auto iter = describeEventContainer.find(messageDescribe);
        iter != describeEventContainer.cend())
    {
        iter->second.OnEvent(socketId, message);
    }
}

void Network::MessageEventManagerImpl::SetCallbackEvent(const EventInterfaceSharedPtr& aEvent)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    event = aEvent;
}

Network::MessageEventManagerImpl ::EventInterfaceSharedPtr Network::MessageEventManagerImpl::GetCallbackEvent()
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    return event.lock();
}