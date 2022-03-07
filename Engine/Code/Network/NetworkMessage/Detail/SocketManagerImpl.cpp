///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 22:39)

#include "Network/NetworkExport.h"

#include "SocketManagerImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Base/UniqueIDManagerDetail.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "CoreTools/Threading/ScopedMutex.h"

#define MUTEX_ENTER_MEMBER CoreTools::ScopedMutex holder{ *mutex };

using std::make_unique;

Network::SocketManagerImpl::SocketManagerImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : messageEventManagerContainer{}, mutex{ make_unique<CoreTools::Mutex>(CoreTools::MutexCreate::UseStdRecursive) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::SocketManagerImpl::SocketManagerImpl(const SocketManagerImpl& rhs)
    : messageEventManagerContainer{ rhs.messageEventManagerContainer }, mutex{ make_unique<CoreTools::Mutex>(CoreTools::MutexCreate::UseStdRecursive) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::SocketManagerImpl& Network::SocketManagerImpl::operator=(const SocketManagerImpl& rhs)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    messageEventManagerContainer = rhs.messageEventManagerContainer;

    return *this;
}

Network::SocketManagerImpl::SocketManagerImpl(SocketManagerImpl&& rhs) noexcept
    : messageEventManagerContainer{ std::move(rhs.messageEventManagerContainer) }, mutex{ std::move(rhs.mutex) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::SocketManagerImpl& Network::SocketManagerImpl::operator=(SocketManagerImpl&& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    if (this != &rhs)
    {
        messageEventManagerContainer = std::move(rhs.messageEventManagerContainer);
    }

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SocketManagerImpl)

void Network::SocketManagerImpl::InsertEvent(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    const auto iter = messageEventManagerContainer.find(socketID);

    if (iter != messageEventManagerContainer.cend())
    {
        iter->second.Insert(messageID, messageEvent);
    }
}

void Network::SocketManagerImpl::InsertEvent(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    const auto iter = messageEventManagerContainer.find(socketID);

    if (iter != messageEventManagerContainer.cend())
    {
        iter->second.Insert(messageID, messageEvent, priority);
    }
}

void Network::SocketManagerImpl::InsertSocket(uint64_t socketID)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    messageEventManagerContainer.insert({ socketID, MessageEventManager::Create() });
}

void Network::SocketManagerImpl::RemoveEvent(uint64_t socketID, int64_t messageID)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    const auto iter = messageEventManagerContainer.find(socketID);

    if (iter != messageEventManagerContainer.cend())
    {
        iter->second.Remove(messageID);
    }
}

void Network::SocketManagerImpl::RemoveEvent(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    const auto iter = messageEventManagerContainer.find(socketID);

    if (iter != messageEventManagerContainer.cend())
    {
        iter->second.Remove(messageID, messageEvent);
    }
}

void Network::SocketManagerImpl::RemoveSocket(uint64_t socketID)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    messageEventManagerContainer.erase(socketID);
}

void Network::SocketManagerImpl::OnEvent(uint64_t socketID, int64_t messageID, const ConstMessageInterfaceSharedPtr& message)
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_9;

    const auto iter = messageEventManagerContainer.find(socketID);

    if (iter != messageEventManagerContainer.cend())
    {
        iter->second.OnEvent(messageID, socketID, message);
    }
}

int Network::SocketManagerImpl::GetSocketSize() const
{
    MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(messageEventManagerContainer.size());
}
