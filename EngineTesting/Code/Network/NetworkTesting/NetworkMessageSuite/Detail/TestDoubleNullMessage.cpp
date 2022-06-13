///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/23 15:45)

#include "TestDoubleNullMessage.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Helper/StreamMacro.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"

Network::TestDoubleNullMessage::TestDoubleNullMessage(int64_t messageID) noexcept
    : ParentType{ messageID }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestDoubleNullMessage);

CORE_TOOLS_RTTI_DEFINE(Network, TestDoubleNullMessage);
NETWORK_DEFAULT_STREAM_DEFINE(Network, TestDoubleNullMessage);
NETWORK_FACTORY_DEFINE(Network, TestDoubleNullMessage);

int Network::TestDoubleNullMessage::GetValue() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return GetMessageID();
}