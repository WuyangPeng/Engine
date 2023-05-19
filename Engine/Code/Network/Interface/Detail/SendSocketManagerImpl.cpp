///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/09 10:02)

#include "Network/NetworkExport.h"

#include "SendSocketManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Network/NetworkMessage/MessageEventManager.h"

Network::SendSocketManagerImpl::SendSocketManagerImpl(const std::string& fileName)
    : sendSocket{}, messageEventManager{}
{
    System::UnusedFunction(fileName);

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SendSocketManagerImpl)

void Network::SendSocketManagerImpl::Send(const SocketData& socketData, int64_t socketId, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    if (const auto iter = sendSocket.find(socketData);
        iter != sendSocket.cend())
    {
        iter->second->Send(socketId, message);
    }
}

Network::SendSocketSharedPtr Network::SendSocketManagerImpl::GetSendSocket(const SocketData& socketData)
{
    NETWORK_CLASS_IS_VALID_9;

    if (const auto iter = sendSocket.find(socketData);
        iter != sendSocket.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("δ�ҵ�SendSocket��"s))
    }
}

Network::MessageEventManagerSharedPtr Network::SendSocketManagerImpl::GetMessageEventManager() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return messageEventManager;
}
