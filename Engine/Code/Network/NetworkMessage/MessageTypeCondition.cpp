///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/08 10:00)

#include "Network/NetworkExport.h"

#include "MessageTypeCondition.h"
#include "Detail/MessageTypeConditionAll.h"
#include "Detail/MessageTypeConditionCompare.h"
#include "Detail/MessageTypeConditionImpl.h"
#include "Detail/MessageTypeConditionRange.h"
#include "Detail/MessageTypeConditionSpecific.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Network::MessageTypeCondition Network::MessageTypeCondition::CreateNullCondition()
{
    return MessageTypeCondition{ CoreTools::DisableNotThrow::Disable };
}

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

Network::MessageTypeCondition::MessageTypeCondition(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseFactory::Default }
{
    System::UnusedFunction(disableNotThrow);

    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageTypeCondition)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, MessageTypeCondition, IsVersionsConform, int, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, MessageTypeCondition, GetMinVersion, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, MessageTypeCondition, GetMaxVersion, int);

bool Network::MessageTypeCondition::operator<(const MessageTypeCondition& rhs) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return *impl < *rhs.impl;
}
