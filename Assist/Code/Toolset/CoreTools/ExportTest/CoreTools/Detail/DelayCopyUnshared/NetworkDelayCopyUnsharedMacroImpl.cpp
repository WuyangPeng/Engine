///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 22:21)

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
