///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/21 17:03)

#include "Network/NetworkExport.h"

#include "SocketData.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::SocketData::SocketData(SocketType socketType, int serverID) noexcept
    : socketType{ socketType }, serverID{ serverID }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SocketData)

Network::SocketType Network::SocketData::GetSocketType() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return socketType;
}

int Network::SocketData::GetServerID() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return serverID;
}

bool Network::operator<(const SocketData& lhs, const SocketData& rhs) noexcept
{
    if (lhs.GetServerID() < rhs.GetServerID())
        return true;
    else if (rhs.GetServerID() < lhs.GetServerID())
        return false;
    else
        return lhs.GetSocketType() < rhs.GetSocketType();
}
