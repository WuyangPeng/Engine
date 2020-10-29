//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 13:11)

#include "Network/NetworkExport.h"

#include "SendSocketManager.h"
#include "Detail/SendSocketManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::string;

Network::SendSocketManager::SendSocketManager(const string& fileName)
    : m_Impl{ make_shared<ImplType>(fileName) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, SendSocketManager)

void Network::SendSocketManager::Send(const SocketData& socketData, uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Send(socketData, socketID, message);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Network, SendSocketManager, GetSendSocket, SocketData, Network::SendSocketSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, SendSocketManager, GetSocketManager, Network::SocketManagerSharedPtr)
