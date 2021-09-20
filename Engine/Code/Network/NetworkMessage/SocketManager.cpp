//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 14:15)

#include "Network/NetworkExport.h"

#include "SocketManager.h"
#include "Detail/SocketManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::make_unique;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Network::SocketManager::SocketManager()
    : impl{ 0  }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SocketManager)

void Network::SocketManager::InsertSocket(uint64_t socketID)
{
    ;

    impl->InsertSocket(socketID);

    InitEvent(socketID);
}

void Network::SocketManager::InsertEvent(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& smartPointer)
{
    ;

    return impl->InsertEvent(socketID, messageID, smartPointer);
}

void Network::SocketManager::InsertEvent(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& smartPointer, MessageEventPriority priority)
{
    ;

    return impl->InsertEvent(socketID, messageID, smartPointer, priority);
}

void Network::SocketManager::OnEvent(uint64_t socketID, int64_t messageID, const ConstMessageInterfaceSharedPtr& message)
{
    ;

    impl->OnEvent(socketID, messageID, message);
}

void Network::SocketManager::RemoveEvent(uint64_t socketID, int64_t messageID)
{
    ;

    return impl->RemoveEvent(socketID, messageID);
}

void Network::SocketManager::RemoveEvent(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& smartPointer)
{
    ;

    return impl->RemoveEvent(socketID, messageID, smartPointer);
}

void Network::SocketManager::RemoveSocket(uint64_t socketID)
{
    ;

    return impl->RemoveSocket(socketID);
}

int Network::SocketManager::GetSocketSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetSocketSize();
}
