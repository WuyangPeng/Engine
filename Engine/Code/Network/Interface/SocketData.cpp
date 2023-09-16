///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 13:44)

#include "Network/NetworkExport.h"

#include "SocketData.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::SocketData::SocketData(SocketType socketType, int serverId) noexcept
    : socketType{ socketType }, serverId{ serverId }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SocketData)

Network::SocketType Network::SocketData::GetSocketType() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return socketType;
}

int Network::SocketData::GetServerId() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return serverId;
}

bool Network::operator<(const SocketData& lhs, const SocketData& rhs) noexcept
{
    if (lhs.GetServerId() < rhs.GetServerId())
        return true;
    else if (rhs.GetServerId() < lhs.GetServerId())
        return false;
    else
        return lhs.GetSocketType() < rhs.GetSocketType();
}
