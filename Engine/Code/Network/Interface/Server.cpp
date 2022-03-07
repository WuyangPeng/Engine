///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/21 17:02)

#include "Network/NetworkExport.h"

#include "Server.h"
#include "Detail/ServerFactory.h"
#include "Detail/ServerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Network::Server::Server(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy)
    : ParentType{}, impl{ CoreTools::ImplCreateUseFactory::Default, socketManager, configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, Server)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, Server, RunServer, bool)

void Network::Server::Send(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Send(socketID, message);
}

void Network::Server::AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->AsyncSend(socketID, message);
}
