///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 10:01)

#include "Network/NetworkExport.h"

#include "SendSocketManager.h"
#include "Detail/SendSocketManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Network::SendSocketManager::SendSocketManager(const std::string& fileName)
    : impl{ fileName }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SendSocketManager)

void Network::SendSocketManager::Send(const SocketData& socketData, int64_t socketId, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Send(socketData, socketId, message);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Network, SendSocketManager, GetSendSocket, SocketData, Network::SendSocketSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, SendSocketManager, GetMessageEventManager, Network::MessageEventManagerSharedPtr)
