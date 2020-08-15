// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 16:37)

#include "Network/NetworkExport.h"

#include "MessageTypeConditionOperating.h" 
#include "MessageTypeCondition.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

Network::MessageTypeConditionOperating ::MessageTypeConditionOperating() noexcept
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageTypeConditionOperating)

bool Network::MessageTypeConditionOperating
	::operator()(const MessageTypeCondition& lhs, const MessageTypeCondition& rhs) const
{
	NETWORK_CLASS_IS_VALID_CONST_1;

	return lhs < rhs;
}