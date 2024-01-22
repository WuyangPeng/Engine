/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:20)

#include "Network/NetworkExport.h"

#include "MessageTypeConditionAll.h"
#include "MessageTypeConditionCompare.h"
#include "MessageTypeConditionImpl.h"
#include "MessageTypeConditionRange.h"
#include "MessageTypeConditionSpecific.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::MessageTypeConditionImpl::MessageTypeConditionImpl() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageTypeConditionImpl)

Network::MessageTypeConditionImpl::ImplSharedPtr Network::MessageTypeConditionImpl::Create(const VersionType& version)
{
    return std::make_shared<MessageTypeConditionSpecific>(version);
}

Network::MessageTypeConditionImpl::ImplSharedPtr Network::MessageTypeConditionImpl::Create()
{
    return std::make_shared<MessageTypeConditionAll>();
}

Network::MessageTypeConditionImpl::ImplSharedPtr Network::MessageTypeConditionImpl::Create(VersionsCondition condition, int version)
{
    return std::make_shared<MessageTypeConditionCompare>(condition, version);
}

Network::MessageTypeConditionImpl::ImplSharedPtr Network::MessageTypeConditionImpl::Create(int beginVersion, int endVersion)
{
    return std::make_shared<MessageTypeConditionRange>(beginVersion, endVersion);
}

bool Network::operator<(const MessageTypeConditionImpl& lhs, const MessageTypeConditionImpl& rhs)
{
    if (lhs.GetMinVersion() < rhs.GetMinVersion())
        return true;
    else if (rhs.GetMinVersion() < lhs.GetMinVersion())
        return false;
    else
        return lhs.GetMaxVersion() < rhs.GetMaxVersion();
}
