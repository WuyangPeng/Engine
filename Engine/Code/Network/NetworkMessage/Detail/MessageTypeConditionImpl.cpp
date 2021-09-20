//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 13:43)

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

std::shared_ptr<Network::MessageTypeConditionImpl> Network::MessageTypeConditionImpl::Create(const VersionType& version)
{
    return std::make_shared<Network::MessageTypeConditionSpecific>(version);
}

std::shared_ptr<Network::MessageTypeConditionImpl> Network::MessageTypeConditionImpl::Create()
{
    return std::make_shared<Network::MessageTypeConditionAll>();
}

std::shared_ptr<Network::MessageTypeConditionImpl> Network::MessageTypeConditionImpl::Create(VersionsCondition condition, int version)
{
    return std::make_shared<Network::MessageTypeConditionCompare>(condition, version);
}

std::shared_ptr<Network::MessageTypeConditionImpl> Network::MessageTypeConditionImpl::Create(int beginVersion, int endVersion)
{
    return std::make_shared<Network::MessageTypeConditionRange>(beginVersion, endVersion);
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
