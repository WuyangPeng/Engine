// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 13:25)

#include "TestNullMessage.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/StreamMacro.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"

Network::TestNullMessage
	::TestNullMessage(int64_t messageID)
	:ParentType{ messageID }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::TestNullMessage
	::~TestNullMessage()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestNullMessage);

CORE_TOOLS_RTTI_DEFINE(Network, TestNullMessage);
NETWORK_DEFAULT_STREAM_DEFINE(Network, TestNullMessage);
NETWORK_FACTORY_DEFINE(Network, TestNullMessage);

int Network::TestNullMessage
	::GetValue() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return GetMessageID();
}