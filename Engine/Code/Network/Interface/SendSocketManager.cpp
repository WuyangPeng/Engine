///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/21 17:02)

#include "Network/NetworkExport.h"

#include "SendSocketManager.h"
#include "Detail/SendSocketManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::string;

Network::SendSocketManager::SendSocketManager(const string& fileName)
    : impl{ fileName }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SendSocketManager)

void Network::SendSocketManager::Send(const SocketData& socketData, uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Send(socketData, socketID, message);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Network, SendSocketManager, GetSendSocket, SocketData, Network::SendSocketSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, SendSocketManager, GetSocketManager, Network::SocketManagerSharedPtr)
