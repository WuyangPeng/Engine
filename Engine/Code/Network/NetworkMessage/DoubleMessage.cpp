// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 16:33)

#include "Network/NetworkExport.h"

#include "DoubleMessage.h" 
#include "MessageManager.h"
#include "MessageSourceDetail.h"
#include "MessageTargetDetail.h"
#include "MessageTypeCondition.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
Network::DoubleMessage
	::DoubleMessage(int64_t messageID) noexcept
	:ParentType{ messageID }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, DoubleMessage);

CORE_TOOLS_RTTI_DEFINE(Network, DoubleMessage);
NETWORK_ABSTRACT_FACTORY_DEFINE(Network, DoubleMessage);
NETWORK_DEFAULT_STREAM_DEFINE(Network, DoubleMessage);

int Network::DoubleMessage
	::GetMessageID() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(GetFullMessageID() >> sm_MessageBytes);
}

int Network::DoubleMessage
	::GetSubMessageID() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(GetFullMessageID() & sm_MaxMessageID);
}
#include STSTEM_WARNING_POP