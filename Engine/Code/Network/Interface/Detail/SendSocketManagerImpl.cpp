//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 12:45)

#include "Network/NetworkExport.h"

#include "SendSocketManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Network/NetworkMessage/SocketManager.h"

using std::make_shared;
using std::string;

Network::SendSocketManagerImpl::SendSocketManagerImpl([[maybe_unused]] const string& fileName)
    : m_SendSocket{}, m_SocketManager{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SendSocketManagerImpl)

void Network::SendSocketManagerImpl::Send(const SocketData& socketData, uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    const auto iter = m_SendSocket.find(socketData);
    if (iter != m_SendSocket.cend())
    {
        iter->second->Send(socketID, message);
    }
}

Network::SendSocketSharedPtr Network::SendSocketManagerImpl::GetSendSocket(const SocketData& socketData)
{
    NETWORK_CLASS_IS_VALID_9;

    const auto iter = m_SendSocket.find(socketData);
    if (iter != m_SendSocket.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到SendSocket。"s));
    }
}

Network::SocketManagerSharedPtr Network::SendSocketManagerImpl::GetSocketManager() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return m_SocketManager;
}
