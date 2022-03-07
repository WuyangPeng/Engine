// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 13:24)

#include "TestDoubleNullMessage.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Helper/StreamMacro.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"

Network::TestDoubleNullMessage ::TestDoubleNullMessage(int64_t messageID) noexcept
    : ParentType{ messageID }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestDoubleNullMessage);

CORE_TOOLS_RTTI_DEFINE(Network, TestDoubleNullMessage);
NETWORK_DEFAULT_STREAM_DEFINE(Network, TestDoubleNullMessage);
NETWORK_FACTORY_DEFINE(Network, TestDoubleNullMessage);

int Network::TestDoubleNullMessage ::GetValue() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return GetMessageID();
}