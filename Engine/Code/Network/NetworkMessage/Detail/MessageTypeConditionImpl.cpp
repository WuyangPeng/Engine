///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/18 22:34)

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
    return std::make_shared<Network::MessageTypeConditionSpecific>(version);
}

Network::MessageTypeConditionImpl::ImplSharedPtr Network::MessageTypeConditionImpl::Create()
{
    return std::make_shared<Network::MessageTypeConditionAll>();
}

Network::MessageTypeConditionImpl::ImplSharedPtr Network::MessageTypeConditionImpl::Create(VersionsCondition condition, int version)
{
    return std::make_shared<Network::MessageTypeConditionCompare>(condition, version);
}

Network::MessageTypeConditionImpl::ImplSharedPtr Network::MessageTypeConditionImpl::Create(int beginVersion, int endVersion)
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
