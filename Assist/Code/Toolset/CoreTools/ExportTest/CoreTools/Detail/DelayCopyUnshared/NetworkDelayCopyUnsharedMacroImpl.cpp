/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:08)

#include "Network/NetworkExport.h"

#include "NetworkDelayCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::NetworkDelayCopyUnsharedMacroImpl::NetworkDelayCopyUnsharedMacroImpl(int count) noexcept
    : count{ count }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkDelayCopyUnsharedMacroImpl)

int Network::NetworkDelayCopyUnsharedMacroImpl::GetCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return count;
}

void Network::NetworkDelayCopyUnsharedMacroImpl::SetCount(int aCount) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    count = aCount;
}
