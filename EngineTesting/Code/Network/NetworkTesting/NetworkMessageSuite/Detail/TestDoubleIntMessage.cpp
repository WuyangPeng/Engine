///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/11 11:34)

#include "TestDoubleIntMessage.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Helper/StreamMacro.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"

Network::TestDoubleIntMessage::TestDoubleIntMessage(int64_t messageId) noexcept
    : ParentType{ MessageHeadStrategy::UseSubId, messageId }, intValue{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestDoubleIntMessage);

CORE_TOOLS_RTTI_DEFINE(Network, TestDoubleIntMessage);
NETWORK_FACTORY_DEFINE(Network, TestDoubleIntMessage);

Network::TestDoubleIntMessage::TestDoubleIntMessage(LoadConstructor value, MessageHeadStrategy messageHeadStrategy, int64_t messageID) noexcept
    : ParentType{ value, messageHeadStrategy, messageID }, intValue{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

void Network::TestDoubleIntMessage::Load(MessageSource& source)
{
    NETWORK_CLASS_IS_VALID_9;

    NETWORK_BEGIN_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(intValue);

    NETWORK_END_STREAM_LOAD(source);
}

void Network::TestDoubleIntMessage::Save(MessageTarget& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    NETWORK_BEGIN_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(intValue);

    NETWORK_END_STREAM_SAVE(target);
}

int Network::TestDoubleIntMessage::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize() + CoreTools::GetStreamSize(intValue);
}

int Network::TestDoubleIntMessage::GetIntValue() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return intValue;
}

void Network::TestDoubleIntMessage::SetIntValue(int aIntValue) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    intValue = aIntValue;
}
