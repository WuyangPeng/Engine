// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 13:24)

#include "TestIntMessage.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Helper/StreamMacro.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"

#include <atomic>

Network::TestIntMessage ::TestIntMessage(int64_t messageID) noexcept
    : ParentType{ messageID }, m_IntValue{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestIntMessage);

CORE_TOOLS_RTTI_DEFINE(Network, TestIntMessage);
NETWORK_FACTORY_DEFINE(Network, TestIntMessage);

Network::TestIntMessage ::TestIntMessage(LoadConstructor value, int64_t messageID) noexcept
    : ParentType{ value, messageID }, m_IntValue{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

void Network::TestIntMessage ::Load(MessageSource& source)
{
    NETWORK_CLASS_IS_VALID_9;

    NETWORK_BEGIN_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(m_IntValue);

    NETWORK_END_STREAM_LOAD(source);
}

void Network::TestIntMessage ::Save(Network::MessageTarget& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    NETWORK_BEGIN_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(m_IntValue);

    NETWORK_END_STREAM_SAVE(target);
}

int Network::TestIntMessage ::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize() + CORE_TOOLS_STREAM_SIZE(m_IntValue);
}

int Network::TestIntMessage ::GetIntValue() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_IntValue;
}

void Network::TestIntMessage ::SetIntValue(int intValue) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    m_IntValue = intValue;
}
