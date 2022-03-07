///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/19 11:15)

#include "Network/NetworkExport.h"

#include "SocketManager.h"
#include "Detail/SocketManagerImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Network::SocketManager::SocketManager(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ disableNotThrow }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SocketManager)

void Network::SocketManager::InsertSocket(uint64_t socketID)
{
    NETWORK_CLASS_IS_VALID_1;

    impl->InsertSocket(socketID);

    InitEvent(socketID);
}

void Network::SocketManager::InsertEvent(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& smartPointer)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->InsertEvent(socketID, messageID, smartPointer);
}

void Network::SocketManager::InsertEvent(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& smartPointer, MessageEventPriority priority)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->InsertEvent(socketID, messageID, smartPointer, priority);
}

void Network::SocketManager::OnEvent(uint64_t socketID, int64_t messageID, const ConstMessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_1;

    impl->OnEvent(socketID, messageID, message);
}

void Network::SocketManager::RemoveEvent(uint64_t socketID, int64_t messageID)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->RemoveEvent(socketID, messageID);
}

void Network::SocketManager::RemoveEvent(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& smartPointer)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->RemoveEvent(socketID, messageID, smartPointer);
}

void Network::SocketManager::RemoveSocket(uint64_t socketID)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->RemoveSocket(socketID);
}

int Network::SocketManager::GetSocketSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetSocketSize();
}
