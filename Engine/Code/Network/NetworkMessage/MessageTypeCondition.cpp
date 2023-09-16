///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:54)

#include "Network/NetworkExport.h"

#include "MessageTypeCondition.h"
#include "Detail/MessageTypeConditionAll.h"
#include "Detail/MessageTypeConditionCompare.h"
#include "Detail/MessageTypeConditionImpl.h"
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

bool Network::MessageTypeCondition::operator<(const MessageTypeCondition& rhs) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return *impl < *rhs.impl;
}

bool Network::MessageTypeCondition::IsVersionsConform(int version) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->IsVersionsConform(version);
}

int Network::MessageTypeCondition::GetMinVersion() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetMinVersion();
}

int Network::MessageTypeCondition::GetMaxVersion() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetMaxVersion();
}