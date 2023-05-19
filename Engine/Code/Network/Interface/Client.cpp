///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 11:37)

#include "Network/NetworkExport.h"

#include "Client.h"
#include "Detail/ClientFactory.h"
#include "Detail/ClientImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Network::Client::Client(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& messageEventManager)
    : ParentType{}, impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy, messageEventManager }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, Client)

void Network::Client::Send(int64_t socketId, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Send(socketId, message);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, Client, Receive, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, Client, ImmediatelySend, int64_t, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, Client, AsyncReceive, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, Client, Connect, int64_t)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, Client, AsyncConnect, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, Client, GetSocketId, int64_t)

void Network::Client::AsyncSend(int64_t socketId, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->AsyncSend(socketId, message);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, Client, ImmediatelyAsyncSend, int64_t, void)
