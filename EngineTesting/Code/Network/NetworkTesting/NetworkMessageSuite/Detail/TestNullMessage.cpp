///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/23 15:48)

#include "TestNullMessage.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Helper/StreamMacro.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"

Network::TestNullMessage::TestNullMessage(int64_t messageID) noexcept
    : ParentType{ MessageHeadStrategy::Default, messageID }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestNullMessage);

CORE_TOOLS_RTTI_DEFINE(Network, TestNullMessage);
NETWORK_DEFAULT_STREAM_DEFINE(Network, TestNullMessage);
NETWORK_FACTORY_DEFINE(Network, TestNullMessage);

int Network::TestNullMessage::GetValue() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return GetMessageId();
}