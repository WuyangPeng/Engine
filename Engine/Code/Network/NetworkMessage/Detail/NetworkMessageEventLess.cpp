///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:34)

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
