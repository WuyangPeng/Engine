// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 10:02)

#include "TestMessage.h" 
#include "CoreTools/ObjectSystems/InitTerm.h" 
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"

Network::TestMessage
	::TestMessage()
	:ParentType{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::TestMessage
	::~TestMessage()
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestMessage);

CORE_TOOLS_RTTI_DEFINE(Network, TestMessage);
NETWORK_DEFAULT_STREAM_DEFINE(Network, TestMessage);
NETWORK_FACTORY_DEFINE(Network, TestMessage);
