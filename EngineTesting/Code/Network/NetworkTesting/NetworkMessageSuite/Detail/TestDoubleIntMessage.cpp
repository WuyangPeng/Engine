///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/23 15:45)

#include "TestDoubleIntMessage.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Helper/StreamMacro.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"

Network::TestDoubleIntMessage::TestDoubleIntMessage(int64_t messageID) noexcept
    : ParentType{ messageID }, mIntValue{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestDoubleIntMessage);

CORE_TOOLS_RTTI_DEFINE(Network, TestDoubleIntMessage);
NETWORK_FACTORY_DEFINE(Network, TestDoubleIntMessage);

Network::TestDoubleIntMessage::TestDoubleIntMessage(LoadConstructor value, int64_t messageID) noexcept
    : ParentType{ value, messageID }, mIntValue{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

void Network::TestDoubleIntMessage::Load(MessageSource& source)
{
    NETWORK_CLASS_IS_VALID_9;

    NETWORK_BEGIN_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(mIntValue);

    NETWORK_END_STREAM_LOAD(source);
}

void Network::TestDoubleIntMessage::Save(MessageTarget& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    NETWORK_BEGIN_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(mIntValue);

    NETWORK_END_STREAM_SAVE(target);
}

int Network::TestDoubleIntMessage::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize() + CORE_TOOLS_STREAM_SIZE(mIntValue);
}

int Network::TestDoubleIntMessage::GetIntValue() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return mIntValue;
}

void Network::TestDoubleIntMessage::SetIntValue(int intValue) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    mIntValue = intValue;
}
