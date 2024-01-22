/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:21)

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
