///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 15:29)

#include "TestAbstractMessage.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"

Network::TestAbstractMessage::TestAbstractMessage() noexcept
    : ParentType{ 0 }
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

Network::TestAbstractMessage::TestAbstractMessage(LoadConstructor value, int64_t messageID) noexcept
    : ParentType{ value, messageID }
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
