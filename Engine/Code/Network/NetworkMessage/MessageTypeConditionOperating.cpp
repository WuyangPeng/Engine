///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/19 11:07)

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