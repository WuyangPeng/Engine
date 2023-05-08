///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/20 23:46)

#include "Network/NetworkExport.h"

#include "SendSocketManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Network/NetworkMessage/MessageEventManager.h"

using std::make_shared;
using std::string;

Network::SendSocketManagerImpl::SendSocketManagerImpl(MAYBE_UNUSED const string& fileName)
    : sendSocket{}, socketManager{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SendSocketManagerImpl)

void Network::SendSocketManagerImpl::Send(const SocketData& socketData, uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    const auto iter = sendSocket.find(socketData);
    if (iter != sendSocket.cend())
    {
        iter->second->Send(socketID, message);
    }
}

Network::SendSocketSharedPtr Network::SendSocketManagerImpl::GetSendSocket(const SocketData& socketData)
{
    NETWORK_CLASS_IS_VALID_9;

    const auto iter = sendSocket.find(socketData);
    if (iter != sendSocket.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("δ�ҵ�SendSocket��"s));
    }
}

Network::MessageEventManagerSharedPtr Network::SendSocketManagerImpl::GetSocketManager() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return socketManager;
}
