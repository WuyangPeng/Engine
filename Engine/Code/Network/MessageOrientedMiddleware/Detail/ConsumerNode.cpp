/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:26)

#include "Network/NetworkExport.h"

#include "ConsumerNode.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::ConsumerNode::ConsumerNode(SocketType serverType, int serverId, const String& consumer)
    : serverType{ serverType }, serverId{ serverId }, consumer{ consumer }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConsumerNode)

Network::SocketType Network::ConsumerNode::GetServerType() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return serverType;
}

int Network::ConsumerNode::GetServerId() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return serverId;
}

Network::ConsumerNode::String Network::ConsumerNode::GetConsumer() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return consumer;
}
