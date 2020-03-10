// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 16:37)

#include "Network/NetworkExport.h"

#include "NullMessage.h"
#include "MessageManager.h"
#include "MessageSourceDetail.h"
#include "MessageTargetDetail.h"
#include "MessageTypeCondition.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

Network::NullMessage
	::NullMessage(int64_t messageID)
	:ParentType{ messageID }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NullMessage
	::~NullMessage()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullMessage);

CORE_TOOLS_RTTI_DEFINE(Network, NullMessage);
NETWORK_DEFAULT_STREAM_DEFINE(Network, NullMessage);
NETWORK_FACTORY_DEFINE(Network, NullMessage);