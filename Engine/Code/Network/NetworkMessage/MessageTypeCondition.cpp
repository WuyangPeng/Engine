// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 16:37)

#include "Network/NetworkExport.h"

#include "MessageTypeCondition.h"
#include "Detail/MessageTypeConditionImpl.h"
#include "Detail/MessageTypeConditionCompare.h"
#include "Detail/MessageTypeConditionRange.h"
#include "Detail/MessageTypeConditionSpecific.h"
#include "Detail/MessageTypeConditionAll.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::make_shared;

Network::MessageTypeCondition
	::MessageTypeCondition(const VersionType& version)
	:m_Impl{ make_shared<MessageTypeConditionSpecific>(version) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MessageTypeCondition
	::MessageTypeCondition(int beginVersion, int endVersion)
	:m_Impl{ make_shared<MessageTypeConditionRange>(beginVersion,endVersion) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MessageTypeCondition
	::MessageTypeCondition(VersionsCondition condition, int version)
	:m_Impl{ make_shared<MessageTypeConditionCompare>(condition, version) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Network::MessageTypeCondition
	::MessageTypeCondition()
	:m_Impl{ make_shared<MessageTypeConditionAll>() }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP
 
CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, MessageTypeCondition)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, MessageTypeCondition, IsVersionsConform, int, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, MessageTypeCondition, GetMinVersion, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, MessageTypeCondition, GetMaxVersion, int);

bool Network::MessageTypeCondition
	::operator<(const MessageTypeCondition& rhs) const
{
	NETWORK_CLASS_IS_VALID_CONST_1;

	return *m_Impl < *rhs.m_Impl;
}

