///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/09 11:39)

#include "Network/NetworkExport.h"

#include "Server.h"
#include "Detail/ServerFactory.h"
#include "Detail/ServerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Network::Server::Server(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& messageEventManager)
    : ParentType{}, impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy, messageEventManager }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, Server)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, Server, RunServer, bool)

void Network::Server::Send(int64_t socketId, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Send(socketId, message);
}

void Network::Server::AsyncSend(int64_t socketId, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->AsyncSend(socketId, message);
}
