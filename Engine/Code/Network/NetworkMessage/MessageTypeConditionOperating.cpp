/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:23)

#include "Network/NetworkExport.h"

#include "MessageTypeCondition.h"
#include "MessageTypeConditionOperating.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::MessageTypeConditionOperating::MessageTypeConditionOperating() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageTypeConditionOperating)

bool Network::MessageTypeConditionOperating::operator()(const MessageTypeCondition& lhs, const MessageTypeCondition& rhs) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return lhs < rhs;
}