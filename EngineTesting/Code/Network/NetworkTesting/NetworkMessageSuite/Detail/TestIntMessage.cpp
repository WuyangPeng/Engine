///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/11 11:35)

#include "TestIntMessage.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Helper/StreamMacro.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"

Network::TestIntMessage::TestIntMessage(int64_t messageId) noexcept
    : ParentType{ MessageHeadStrategy::Default, messageId }, intValue{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestIntMessage);

CORE_TOOLS_RTTI_DEFINE(Network, TestIntMessage);
NETWORK_FACTORY_DEFINE(Network, TestIntMessage);

Network::TestIntMessage::TestIntMessage(LoadConstructor value, MessageHeadStrategy messageHeadStrategy, int64_t messageID) noexcept
    : ParentType{ value, messageHeadStrategy, messageID }, intValue{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

void Network::TestIntMessage::Load(MessageSource& source)
{
    NETWORK_CLASS_IS_VALID_9;

    NETWORK_BEGIN_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(intValue);

    NETWORK_END_STREAM_LOAD(source);
}

void Network::TestIntMessage::Save(Network::MessageTarget& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    NETWORK_BEGIN_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(intValue);

    NETWORK_END_STREAM_SAVE(target);
}

int Network::TestIntMessage::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize() + CoreTools::GetStreamSize(intValue);
}

int Network::TestIntMessage::GetIntValue() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return intValue;
}

void Network::TestIntMessage::SetIntValue(int aIntValue) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    intValue = aIntValue;
}
