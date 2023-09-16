///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 10:10)

#include "TestAbstractMessage.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"

Network::TestAbstractMessage::TestAbstractMessage() noexcept
    : ParentType{ MessageHeadStrategy::Default, 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::TestAbstractMessage::~TestAbstractMessage() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestAbstractMessage);

CORE_TOOLS_RTTI_DEFINE(Network, TestAbstractMessage);
NETWORK_ABSTRACT_FACTORY_DEFINE(Network, TestAbstractMessage);

Network::TestAbstractMessage::TestAbstractMessage(LoadConstructor value, MessageHeadStrategy messageHeadStrategy, int64_t messageID) noexcept
    : ParentType{ value, messageHeadStrategy, messageID }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

void Network::TestAbstractMessage::Load(Network::MessageSource& source)
{
    NETWORK_CLASS_IS_VALID_9;

    NETWORK_BEGIN_STREAM_LOAD(source);

    ParentType::Load(source);

    NETWORK_END_STREAM_LOAD(source);
}

void Network::TestAbstractMessage::Save(Network::MessageTarget& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    NETWORK_BEGIN_STREAM_SAVE(target);

    ParentType::Save(target);

    NETWORK_END_STREAM_SAVE(target);
}

int Network::TestAbstractMessage::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize();
}
