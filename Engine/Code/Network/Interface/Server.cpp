//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 13:11)

#include "Network/NetworkExport.h"

#include "Server.h"
#include "Detail/ServerFactory.h"
#include "Detail/ServerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Network::Server::Server(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy)
    : ParentType{}, m_Impl{ ServerFactory::Create(socketManager, configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, Server)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, Server, RunServer, bool)

void Network::Server::Send(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Send(socketID, message);
}

void Network::Server::AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->AsyncSend(socketID, message);
}
