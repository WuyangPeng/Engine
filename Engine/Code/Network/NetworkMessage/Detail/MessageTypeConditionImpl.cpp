// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 16:26)

#include "Network/NetworkExport.h"

#include "MessageTypeConditionImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::MessageTypeConditionImpl
	::MessageTypeConditionImpl() noexcept
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageTypeConditionImpl
	::~MessageTypeConditionImpl()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageTypeConditionImpl)

bool Network
	::operator<(const MessageTypeConditionImpl& lhs, const MessageTypeConditionImpl& rhs)
{
	if (lhs.GetMinVersion() < rhs.GetMinVersion())
		return true;
	else if (rhs.GetMinVersion() < lhs.GetMinVersion())
		return false;
	else
		return lhs.GetMaxVersion() < rhs.GetMaxVersion();
}

