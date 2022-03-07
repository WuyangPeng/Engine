///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/18 22:35)

#include "Network/NetworkExport.h"

#include "NetworkMessageEventLess.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::NetworkMessageEventLess::NetworkMessageEventLess() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

bool Network::NetworkMessageEventLess::operator()(const NetworkMessageEventWeakPtr& lhs, const NetworkMessageEventWeakPtr& rhs) const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return lhs.lock() < rhs.lock();
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkMessageEventLess);
