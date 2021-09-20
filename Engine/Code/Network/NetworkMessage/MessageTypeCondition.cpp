//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 14:13)

#include "Network/NetworkExport.h"

#include "MessageTypeCondition.h"
#include "Detail/MessageTypeConditionAll.h"
#include "Detail/MessageTypeConditionCompare.h"
#include "Detail/MessageTypeConditionImpl.h"
#include "Detail/MessageTypeConditionRange.h"
#include "Detail/MessageTypeConditionSpecific.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Network::MessageTypeCondition::MessageTypeCondition(const VersionType& version)
    : impl{ CoreTools::ImplCreateUseFactory::Default, version }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MessageTypeCondition::MessageTypeCondition(int beginVersion, int endVersion)
    : impl{ CoreTools::ImplCreateUseFactory::Default, beginVersion, endVersion }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MessageTypeCondition::MessageTypeCondition(VersionsCondition condition, int version)
    : impl{ CoreTools::ImplCreateUseFactory::Default, condition, version }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Network::MessageTypeCondition::MessageTypeCondition()
    : impl{ CoreTools::ImplCreateUseFactory::Default }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

CLASS_INVARIANT_STUB_DEFINE(Network, MessageTypeCondition)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, MessageTypeCondition, IsVersionsConform, int, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, MessageTypeCondition, GetMinVersion, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, MessageTypeCondition, GetMaxVersion, int);

bool Network::MessageTypeCondition::operator<(const MessageTypeCondition& rhs) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return *impl < *rhs.impl;
}
