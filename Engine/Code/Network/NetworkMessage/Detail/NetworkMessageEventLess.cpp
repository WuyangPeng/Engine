//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 13:50)

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
