///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/21 17:01)

#include "Network/NetworkExport.h"

#include "Client.h"
#include "Detail/ClientFactory.h"
#include "Detail/ClientImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

Network::Client::Client(const ConfigurationStrategy& configurationStrategy, const SocketManagerSharedPtr& socketManager)
    : ParentType{}, impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy, socketManager }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, Client)

void Network::Client::Send(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Send(socketID, message);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, Client, Receive, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, Client, ImmediatelySend, uint64_t, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, Client, AsyncReceive, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, Client, Connect, uint64_t)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, Client, AsyncConnect, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, Client, GetSocketID, uint64_t)

void Network::Client::AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->AsyncSend(socketID, message);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, Client, ImmediatelyAsyncSend, uint64_t, void)
