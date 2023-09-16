///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:36)

#include "TestDoubleNullMessage.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Helper/StreamMacro.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"

Network::TestDoubleNullMessage::TestDoubleNullMessage(int64_t messageId) noexcept
    : ParentType{ MessageHeadStrategy::UseSubId, messageId }
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

    return GetMessageId();
}